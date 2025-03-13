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

#include "graphics/vulkan_struct_get_pnext.h"
#include "generated/generated_vulkan_struct_decoders.h"
#include "util/logging.h"

#include "vulkan_check_buffer_references.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

template <typename T>
void populate_shader_stages(const decode::StructPointerDecoder<T>*    pCreateInfos,
                            decode::HandlePointerDecoder<VkPipeline>* pPipelines,
                            const decode::CommonObjectInfoTable&      object_info_table)
{
    uint32_t pipeline_count = pPipelines->GetLength();

    for (uint32_t i = 0; i < pipeline_count; ++i)
    {
        auto* pipeline_info = reinterpret_cast<decode::VulkanPipelineInfo*>(pPipelines->GetConsumerData(i));
        GFXRECON_ASSERT(pipeline_info);

        // copy shader stage information
        const T* pipeline_infos_meta = pCreateInfos->GetMetaStructPointer();
        const decode::Decoded_VkPipelineShaderStageCreateInfo* stages_info_meta =
            pipeline_infos_meta[i].pStages->GetMetaStructPointer();
        const size_t stages_count = pipeline_infos_meta->pStages->GetLength();

        if (stages_info_meta != nullptr)
        {
            for (size_t s = 0; s < stages_count; ++s)
            {
                if (stages_info_meta[s].module != format::kNullHandleId)
                {
                    const decode::VulkanShaderModuleInfo* module_info =
                        object_info_table.GetVkShaderModuleInfo(stages_info_meta[s].module);

                    if (pipeline_info != nullptr && module_info != nullptr)
                    {
                        // extract information about buffer-references, present in shadermodule-info structs
                        pipeline_info->buffer_reference_infos.insert(pipeline_info->buffer_reference_infos.end(),
                                                                     module_info->buffer_reference_infos.begin(),
                                                                     module_info->buffer_reference_infos.end());
                    }

                    // check potentially inlined spirv
                    if (auto module_create_info =
                            vulkan_struct_get_pnext<VkShaderModuleCreateInfo>(pCreateInfos->GetPointer()->pStages + s))
                    {
                        graphics::vulkan_check_buffer_references(
                            module_create_info->pCode, module_create_info->codeSize, pipeline_info);
                    }
                }
            }
        }
    }
}

template void
populate_shader_stages(const decode::StructPointerDecoder<decode::Decoded_VkGraphicsPipelineCreateInfo>* pCreateInfos,
                       decode::HandlePointerDecoder<VkPipeline>*                                         pPipelines,
                       const decode::CommonObjectInfoTable& object_info_table);

template void populate_shader_stages(
    const decode::StructPointerDecoder<decode::Decoded_VkRayTracingPipelineCreateInfoKHR>* pCreateInfos,
    decode::HandlePointerDecoder<VkPipeline>*                                              pPipelines,
    const decode::CommonObjectInfoTable&                                                   object_info_table);

template <>
void populate_shader_stages(
    const decode::StructPointerDecoder<decode::Decoded_VkComputePipelineCreateInfo>* pCreateInfos,
    decode::HandlePointerDecoder<VkPipeline>*                                        pPipelines,
    const decode::CommonObjectInfoTable&                                             object_info_table)
{
    uint32_t pipeline_count = pPipelines->GetLength();

    for (uint32_t i = 0; i < pipeline_count; ++i)
    {
        auto* pipeline_info = reinterpret_cast<decode::VulkanPipelineInfo*>(pPipelines->GetConsumerData(i));

        // copy shader stage information
        const decode::Decoded_VkComputePipelineCreateInfo* pipeline_infos_meta = pCreateInfos->GetMetaStructPointer();
        const decode::Decoded_VkPipelineShaderStageCreateInfo* stage_info_meta = pipeline_infos_meta[i].stage;

        if (stage_info_meta != nullptr && stage_info_meta->module != format::kNullHandleId)
        {
            const decode::VulkanShaderModuleInfo* module_info =
                object_info_table.GetVkShaderModuleInfo(stage_info_meta->module);
            GFXRECON_ASSERT(pipeline_info);

            if (module_info != nullptr)
            {
                // extract information about buffer-references, present in shadermodule-info structs
                pipeline_info->buffer_reference_infos.insert(pipeline_info->buffer_reference_infos.end(),
                                                             module_info->buffer_reference_infos.begin(),
                                                             module_info->buffer_reference_infos.end());
            }

            // check potentially inlined spirv
            auto module_create_info =
                vulkan_struct_get_pnext<VkShaderModuleCreateInfo>(&pCreateInfos->GetPointer()->stage);
            if (module_create_info != nullptr)
            {
                graphics::vulkan_check_buffer_references(
                    module_create_info->pCode, module_create_info->codeSize, pipeline_info);
            }

            if (module_info == nullptr && module_create_info == nullptr)
            {
                GFXRECON_LOG_WARNING("No spirv available");
            }
        }
    }
}

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)