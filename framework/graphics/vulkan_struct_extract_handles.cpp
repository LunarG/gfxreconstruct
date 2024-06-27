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

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

std::unordered_set<uint64_t> vulkan_struct_extract_handles(const VkGraphicsPipelineCreateInfo* structs, uint32_t count)
{
    std::unordered_set<uint64_t> handle_deps;

    auto track_handle = [&handle_deps](const auto &handle) {
        if (handle != VK_NULL_HANDLE)
        {
            handle_deps.insert((uint64_t)handle);
        }
    };

    // track dependencies on opaque vulkan-handles
    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& create_info = structs[i];

        track_handle(create_info.layout);
        track_handle(create_info.renderPass);
        track_handle(create_info.basePipelineHandle);

        for (uint32_t j = 0; j < create_info.stageCount; ++j)
        {
            track_handle(create_info.pStages[j].module);
        }

        if (create_info.pNext != nullptr)
        {
            auto base = reinterpret_cast<const VkBaseInStructure*>(create_info.pNext);
            if (base->sType == VK_STRUCTURE_TYPE_PIPELINE_LIBRARY_CREATE_INFO_KHR)
            {
                auto library_create_info = reinterpret_cast<const VkPipelineLibraryCreateInfoKHR*>(base);
                for (uint32_t j = 0; j < library_create_info->libraryCount; j++)
                {
                    track_handle(library_create_info->pLibraries[j]);
                }
            }
        }
    }
    return handle_deps;
}

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)