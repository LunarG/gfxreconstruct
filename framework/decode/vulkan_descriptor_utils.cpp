/*
** Copyright (c) 2026 Valve Corporation
** Copyright (c) 2026 LunarG, Inc.
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

#include "generated/generated_vulkan_enum_to_string.h"
#include "generated/generated_vulkan_struct_decoders.h"
#include "graphics/vulkan_struct_get_pnext.h"
#include "vulkan_descriptor_utils.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void HandleDescriptorUpdate(CommonObjectInfoTable&                                    object_info_table,
                            uint32_t                                                  descriptor_write_count,
                            const StructPointerDecoder<Decoded_VkWriteDescriptorSet>* p_descriptor_writes,
                            VulkanDescriptorSetInfo::VulkanDescriptorBindingsInfo*    descriptor_bindings,
                            VkShaderStageFlags                                        stage_flags)
{
    const auto* writes_meta = p_descriptor_writes->GetMetaStructPointer();
    for (uint32_t w = 0; w < descriptor_write_count; ++w)
    {
        const auto& write_meta    = writes_meta[w];
        const auto* write         = write_meta.decoded_value;
        uint32_t    binding_index = write->dstBinding;

        VulkanDescriptorSetInfo::VulkanDescriptorBindingsInfo& descriptor_bindings_info =
            (descriptor_bindings != nullptr) ? (*descriptor_bindings)
                                             : object_info_table.GetVkDescriptorSetInfo(write_meta.dstSet)->descriptors;
        auto  binding_it                  = descriptor_bindings_info.try_emplace(binding_index).first;
        auto& descriptor_set_binding_info = binding_it->second;

        descriptor_set_binding_info.desc_type = write->descriptorType;
        if (stage_flags != VK_SHADER_STAGE_FLAG_BITS_MAX_ENUM)
        {
            descriptor_set_binding_info.stage_flags = stage_flags;
        }

        if (auto* inline_uniform_block_write =
                graphics::vulkan_struct_get_pnext<VkWriteDescriptorSetInlineUniformBlock>(write);
            inline_uniform_block_write != nullptr && write->descriptorType == VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK)
        {
            const uint32_t offset = write->dstArrayElement;
            const uint32_t size   = write->descriptorCount;
            GFXRECON_ASSERT(descriptor_set_binding_info.inline_uniform_block.size() >= offset + size);
            util::platform::MemoryCopy(descriptor_set_binding_info.inline_uniform_block.data() + offset,
                                       size,
                                       inline_uniform_block_write->pData,
                                       size);

            // skip iterating individual bytes in below loop
            continue;
        }

        uint32_t arr_idx = write->dstArrayElement;

        for (uint32_t i = 0; i < write_meta.decoded_value->descriptorCount; ++i)
        {
            if (binding_it != descriptor_bindings_info.end() && binding_it->second.count != 0 &&
                arr_idx >= binding_it->second.count)
            {
                // Advance to next non zero count binding
                do
                {
                    ++binding_it;
                } while (binding_it != descriptor_bindings_info.end() && binding_it->second.count == 0);

                if (binding_it == descriptor_bindings_info.end())
                {
                    break;
                }
                arr_idx = 0;
            }

            auto& descriptor_set_binding_info = binding_it->second;

            descriptor_set_binding_info.desc_type = write->descriptorType;
            if (stage_flags != VK_SHADER_STAGE_FLAG_BITS_MAX_ENUM)
            {
                descriptor_set_binding_info.stage_flags = stage_flags;
            }

            switch (write->descriptorType)
            {
                case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
                case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
                case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
                case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
                {
                    auto& desc_image_info           = descriptor_set_binding_info.image_info[arr_idx];
                    desc_image_info.image_layout    = write->pImageInfo[i].imageLayout;
                    desc_image_info.image_view_info = object_info_table.GetVkImageViewInfo(
                        write_meta.pImageInfo->GetMetaStructPointer()[i].imageView);
                }
                break;

                case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
                case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
                {
                    descriptor_set_binding_info.texel_buffer_view_info[arr_idx] =
                        object_info_table.GetVkBufferViewInfo(write_meta.pTexelBufferView.GetPointer()[i]);
                }
                break;

                case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
                case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
                case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
                case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
                {
                    auto& desc_buffer_info = descriptor_set_binding_info.buffer_info[arr_idx];
                    desc_buffer_info.buffer_info =
                        object_info_table.GetVkBufferInfo(write_meta.pBufferInfo->GetMetaStructPointer()[i].buffer);
                    desc_buffer_info.offset = write->pBufferInfo[i].offset;
                    desc_buffer_info.range  = write->pBufferInfo[i].range;
                }
                break;

                case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR:
                {
                    const auto* as_descriptors_meta =
                        GetPNextMetaStruct<Decoded_VkWriteDescriptorSetAccelerationStructureKHR>(write_meta.pNext);
                    if (as_descriptors_meta != nullptr)
                    {
                        const auto* as_ids = as_descriptors_meta->pAccelerationStructures.GetPointer();
                        for (uint32_t as = 0; as < as_descriptors_meta->decoded_value->accelerationStructureCount; ++as)
                        {
                            const auto* as_info = object_info_table.GetVkAccelerationStructureKHRInfo(as_ids[as]);
                            if (as_info != nullptr)
                            {
                                descriptor_set_binding_info.acceleration_structs_khr_info[arr_idx] = as_info;
                            }
                        }
                    }
                }
                break;

                default:
                    break;
            }

            ++arr_idx;
        }
    }
}

VkShaderStageFlags PipelineBindPointToShaderStageFlags(VkPipelineBindPoint bind_point)
{
    switch (bind_point)
    {
        case VK_PIPELINE_BIND_POINT_GRAPHICS:
            return VK_SHADER_STAGE_ALL_GRAPHICS | VK_SHADER_STAGE_TASK_BIT_EXT | VK_SHADER_STAGE_MESH_BIT_EXT;

        case VK_PIPELINE_BIND_POINT_COMPUTE:
            return VK_SHADER_STAGE_COMPUTE_BIT;

        case VK_PIPELINE_BIND_POINT_RAY_TRACING_KHR:
            return VK_SHADER_STAGE_RAYGEN_BIT_KHR | VK_SHADER_STAGE_ANY_HIT_BIT_KHR |
                   VK_SHADER_STAGE_CLOSEST_HIT_BIT_KHR | VK_SHADER_STAGE_MISS_BIT_KHR |
                   VK_SHADER_STAGE_INTERSECTION_BIT_KHR | VK_SHADER_STAGE_CALLABLE_BIT_KHR;

        default:
            GFXRECON_LOG_WARNING("VkPipelineBindPoint %s is not handled", util::ToString(bind_point).c_str());
            return 0;
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)