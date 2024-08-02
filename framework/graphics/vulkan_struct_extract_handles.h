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

#ifndef GFXRECON_GRAPHICS_VULKAN_STRUCT_EXTRACT_HANDLES_H
#define GFXRECON_GRAPHICS_VULKAN_STRUCT_EXTRACT_HANDLES_H

#include "util/defines.h"
#include "decode/struct_pointer_decoder.h"
#include "generated/generated_vulkan_struct_decoders_forward.h"
#include "vulkan/vulkan.h"
#include <unordered_set>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

/**
 * @brief   vulkan_struct_extract_handle_ids can be used to extract the handle-ids for all referenced handles.
 *
 * @param   create_infos    a decoder-object, wrapping create-infos structs.
 * @return  a set containing all referenced handles
 */
std::unordered_set<format::HandleId> vulkan_struct_extract_handle_ids(
    const decode::StructPointerDecoder<decode::Decoded_VkGraphicsPipelineCreateInfo>* create_infos);

/**
 * @brief   vulkan_struct_extract_handle_ids can be used to extract the handle-ids for all referenced handles.
 *
 * @param   create_infos    a decoder-object, wrapping create-infos structs.
 * @return  a set containing all referenced handles
 */
std::unordered_set<format::HandleId> vulkan_struct_extract_handle_ids(
    const decode::StructPointerDecoder<decode::Decoded_VkComputePipelineCreateInfo>* create_infos);

/**
 * @brief   vulkan_struct_extract_handle_ids can be used to extract the handle-ids for all referenced handles.
 *
 * @param   create_infos    a decoder-object, wrapping create-infos structs.
 * @return  a set containing all referenced handles
 */
std::unordered_set<format::HandleId> vulkan_struct_extract_handle_ids(
    const decode::StructPointerDecoder<decode::Decoded_VkShaderCreateInfoEXT>* create_infos);

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_GRAPHICS_VULKAN_STRUCT_EXTRACT_HANDLES_H