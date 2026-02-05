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
 * @brief   Populate all VulkanPipelineInfo structs, retrieved via pPipelines->GetConsumerData(i),
 *          with information related to shader-modules.
 *
 * @param   pCreateInfos
 * @param   pPipelines
 * @param   object_info_table
 */
template <typename T>
void populate_shader_stages(const decode::StructPointerDecoder<T>*    pCreateInfos,
                            decode::HandlePointerDecoder<VkPipeline>* pPipelines,
                            const decode::CommonObjectInfoTable&      object_info_table);

/**
 * @brief   vulkan_check_buffer_references can be used to check provided SPIRV-bytecode for usage of buffer-references.
 *          Retrieved buffer-references will be assigned to a provided wrapper-struct.
 *
 * @param   spirv_code      SPIRV-bytecode
 * @param   num_bytes       number of bytes
 * @param   out_info_struct a wrapper-struct
 */
template <typename T>
static void vulkan_check_buffer_references(const uint32_t* const spirv_code, size_t num_bytes, T* out_info_struct)
{
    static_assert(std::is_same_v<T, decode::VulkanShaderModuleInfo> || std::is_same_v<T, decode::VulkanPipelineInfo> ||
                  std::is_same_v<T, decode::VulkanShaderEXTInfo>);
    GFXRECON_ASSERT(out_info_struct != nullptr);

    // check for buffer-references
    gfxrecon::util::SpirVParsingUtil spirv_util;

    if (spirv_util.ParseBufferReferences(spirv_code, num_bytes))
    {
        if (out_info_struct != nullptr)
        {
            const auto& refs                        = spirv_util.GetBufferReferenceInfos();
            out_info_struct->buffer_reference_infos = { refs.begin(), refs.end() };
        }
    }
}

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_GRAPHICS_CHECK_BUFFER_REFERENCES_H
