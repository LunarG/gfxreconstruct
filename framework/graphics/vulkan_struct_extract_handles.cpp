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

#include "vulkan_struct_extract_handles.h"
#include "decode/vulkan_pnext_node.h"
#include "decode/vulkan_pnext_typed_node.h"
#include "generated/generated_vulkan_struct_decoders.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

template <>
std::unordered_set<format::HandleId> vulkan_struct_extract_handle_ids(
    const decode::StructPointerDecoder<decode::Decoded_VkGraphicsPipelineCreateInfo>* create_infos)
{
    if (create_infos == nullptr)
    {
        return {};
    }
    size_t                               count = create_infos->GetLength();
    std::unordered_set<format::HandleId> handle_deps;

    // track dependencies on opaque vulkan-handles
    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& create_info_meta = create_infos->GetMetaStructPointer()[i];
        handle_deps.insert(create_info_meta.layout);
        handle_deps.insert(create_info_meta.renderPass);
        handle_deps.insert(create_info_meta.basePipelineHandle);
        const auto& stages_meta = create_info_meta.pStages->GetMetaStructPointer();

        for (uint32_t j = 0; j < create_info_meta.pStages->GetLength(); ++j)
        {
            handle_deps.insert(stages_meta[j].module);
        }
        auto lib_info_pnext =
            dynamic_cast<const decode::PNextTypedNode<decode::Decoded_VkPipelineLibraryCreateInfoKHR>*>(
                create_info_meta.pNext);
        if (lib_info_pnext != nullptr)
        {
            auto library_create_info_meta = reinterpret_cast<const decode::Decoded_VkPipelineLibraryCreateInfoKHR*>(
                lib_info_pnext->GetMetaStructPointer());
            for (uint32_t j = 0; j < library_create_info_meta->pLibraries.GetLength(); j++)
            {
                handle_deps.insert(library_create_info_meta->pLibraries.GetPointer()[j]);
            }
        }
    }
    return handle_deps;
}

template <>
std::unordered_set<format::HandleId> vulkan_struct_extract_handle_ids(
    const decode::StructPointerDecoder<decode::Decoded_VkComputePipelineCreateInfo>* create_infos)
{
    if (create_infos == nullptr)
    {
        return {};
    }
    size_t                               count = create_infos->GetLength();
    std::unordered_set<format::HandleId> handle_deps;

    // track dependencies on opaque vulkan-handles
    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& create_info_meta = create_infos->GetMetaStructPointer()[i];
        handle_deps.insert(create_info_meta.layout);
        handle_deps.insert(create_info_meta.basePipelineHandle);

        if (create_info_meta.stage != nullptr)
        {
            handle_deps.insert(create_info_meta.stage->module);
        }
        auto lib_info_pnext =
            dynamic_cast<const decode::PNextTypedNode<decode::Decoded_VkPipelineLibraryCreateInfoKHR>*>(
                create_info_meta.pNext);
        if (lib_info_pnext != nullptr)
        {
            auto library_create_info_meta = reinterpret_cast<const decode::Decoded_VkPipelineLibraryCreateInfoKHR*>(
                lib_info_pnext->GetMetaStructPointer());
            for (uint32_t j = 0; j < library_create_info_meta->pLibraries.GetLength(); j++)
            {
                handle_deps.insert(library_create_info_meta->pLibraries.GetPointer()[j]);
            }
        }
    }
    return handle_deps;
}

template <>
std::unordered_set<format::HandleId> vulkan_struct_extract_handle_ids(
    const decode::StructPointerDecoder<decode::Decoded_VkShaderCreateInfoEXT>* create_infos)
{
    GFXRECON_UNREFERENCED_PARAMETER(create_infos);
    return {};
}

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)