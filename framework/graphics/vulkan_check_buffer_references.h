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

#ifndef GFXRECON_GRAPHICS_CHECK_BUFFER_REFERENCES_H
#define GFXRECON_GRAPHICS_CHECK_BUFFER_REFERENCES_H

#include "format/platform_types.h"
#include "decode/vulkan_object_info.h"
#include "generated/generated_vulkan_struct_decoders_forward.h"
#include "decode/common_object_info_table.h"
#include "util/spirv_parsing_util.h"
#include "util/logging.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

/**
 * @brief   Populate all VulkanPipelineInfo structs, in pPipelines's UserData,
 *          with information related to shader-modules.
 *
 * @param   pCreateInfos
 * @param   pPipelines
 * @param   object_info_table
 */
template <typename T>
void populate_shader_stages(const decode::StructPointerDecoder<T>*    pCreateInfos,
                            decode::HandlePointerDecoder<VkPipeline>* pPipelines,
                            const decode::CommonObjectInfoTable&      object_info_table) = delete;

template <>
void populate_shader_stages(
    const decode::StructPointerDecoder<decode::Decoded_VkGraphicsPipelineCreateInfo>* pCreateInfos,
    decode::HandlePointerDecoder<VkPipeline>*                                         pPipelines,
    const decode::CommonObjectInfoTable&                                              object_info_table);

template <>
void populate_shader_stages(
    const decode::StructPointerDecoder<decode::Decoded_VkComputePipelineCreateInfo>* pCreateInfos,
    decode::HandlePointerDecoder<VkPipeline>*                                        pPipelines,
    const decode::CommonObjectInfoTable&                                             object_info_table);

/**
 * @brief   vulkan_check_buffer_references can be used to check provided SPIRV-bytecode for usage of buffer-references.
 *          In case any buffer-references are actively used, a warning will be issued.
 *
 * @param   spirv_code  SPIRV-bytecode
 * @param   num_bytes   number of bytes
 */
template <typename T>
static void vulkan_check_buffer_references(const uint32_t* const spirv_code, size_t num_bytes, T* out_info_struct)
{
    GFXRECON_ASSERT(out_info_struct != nullptr);

    // check for buffer-references, issue warning
    gfxrecon::util::SpirVParsingUtil spirv_util;

    if (spirv_util.ParseBufferReferences(spirv_code, num_bytes))
    {
        auto buffer_reference_infos = spirv_util.GetBufferReferenceInfos();

        if (!buffer_reference_infos.empty())
        {
            out_info_struct->buffer_reference_infos = buffer_reference_infos;
            GFXRECON_LOG_WARNING_ONCE("A Shader is using the 'SPV_KHR_physical_storage_buffer' feature. "
                                      "Resource tracking for buffers accessed via references is currently "
                                      "unsupported, so replay may fail.");
        }
    }
}

/**
 * @brief   vulkan_check_buffer_references is a helper-function to search and check inlined SPIRV-bytecode
 *          in an array of create-infos.
 *
 * Inlined SPIRV: VkPipelineShaderStageCreateInfo 'can' provide a VkShaderModuleCreateInfo
 * This function will iterate all contained 'VkPipelineShaderStageCreateInfo' and descend their pNext-chains.
 * If any 'VkShaderModuleCreateInfo' are contained in the pNext-chains, the contained spirv-code will be checked using:
 * vulkan_check_buffer_references(spirv_code, num_bytes).
 *
 * @tparam  T                   structure-type
 * @param   create_infos        an array of pipeline/shader create-info structures.
 * @param   create_info_count   create-infos' array-count
 */
template <typename T>
void vulkan_check_buffer_references(const T*                     create_infos,
                                    uint32_t                     create_info_count,
                                    decode::VulkanPipelineInfo** out_info_structs) = delete;

template <>
void vulkan_check_buffer_references(const VkGraphicsPipelineCreateInfo* create_infos,
                                    uint32_t                            create_info_count,
                                    decode::VulkanPipelineInfo**        out_info_structs);

template <>
void vulkan_check_buffer_references(const VkComputePipelineCreateInfo* create_infos,
                                    uint32_t                           create_info_count,
                                    decode::VulkanPipelineInfo**       out_info_structs);

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_GRAPHICS_CHECK_BUFFER_REFERENCES_H
