/*
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

// Catch must come before the Vulkan headers because Xlib defines None and Always as macros.
#include <catch2/catch.hpp>

#include "graphics/vulkan_struct_deep_copy.h"
#include "vulkan/vulkan.h"

#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

namespace
{

template <typename T>
std::vector<uint8_t> DeepCopy(const T& value)
{
    std::vector<uint8_t> data(vulkan_struct_deep_copy(&value, 1, nullptr));
    vulkan_struct_deep_copy(&value, 1, data.data());
    return data;
}

bool IsInside(const std::vector<uint8_t>& data, const void* pointer)
{
    auto* address = static_cast<const uint8_t*>(pointer);
    return address >= data.data() && address < data.data() + data.size();
}

} // namespace

TEST_CASE("Deep copy follows the selected member of VkDescriptorMappingSourceDataEXT", "[deep_copy]")
{
    VkSamplerCreateInfo samplers[2] = { { VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO },
                                        { VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO } };
    samplers[0].maxLod              = 1.0f;
    samplers[1].maxLod              = 2.0f;

    VkDescriptorSetAndBindingMappingEXT mappings[2] = { { VK_STRUCTURE_TYPE_DESCRIPTOR_SET_AND_BINDING_MAPPING_EXT },
                                                        { VK_STRUCTURE_TYPE_DESCRIPTOR_SET_AND_BINDING_MAPPING_EXT } };
    mappings[0].source                              = VK_DESCRIPTOR_MAPPING_SOURCE_HEAP_WITH_CONSTANT_OFFSET_EXT;
    mappings[0].sourceData.constantOffset.pEmbeddedSampler = &samplers[0];
    mappings[1].source                                     = VK_DESCRIPTOR_MAPPING_SOURCE_HEAP_WITH_PUSH_INDEX_EXT;
    mappings[1].sourceData.pushIndex.pEmbeddedSampler      = &samplers[1];

    VkShaderDescriptorSetAndBindingMappingInfoEXT mapping_info = {
        VK_STRUCTURE_TYPE_SHADER_DESCRIPTOR_SET_AND_BINDING_MAPPING_INFO_EXT
    };
    mapping_info.mappingCount = 2;
    mapping_info.pMappings    = mappings;

    const std::vector<uint8_t> data = DeepCopy(mapping_info);
    const auto* copy = reinterpret_cast<const VkShaderDescriptorSetAndBindingMappingInfoEXT*>(data.data());

    const VkSamplerCreateInfo* copied_samplers[2] = { copy->pMappings[0].sourceData.constantOffset.pEmbeddedSampler,
                                                      copy->pMappings[1].sourceData.pushIndex.pEmbeddedSampler };
    for (uint32_t i = 0; i < 2; ++i)
    {
        REQUIRE(IsInside(data, copied_samplers[i]));
        REQUIRE(copied_samplers[i]->maxLod == samplers[i].maxLod);
    }
}

TEST_CASE("Deep copy follows the selected member of VkResourceDescriptorDataEXT", "[deep_copy]")
{
    VkImageViewCreateInfo view_info = { VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO };
    view_info.format                = VK_FORMAT_R8G8B8A8_UNORM;

    VkImageDescriptorInfoEXT image_info = { VK_STRUCTURE_TYPE_IMAGE_DESCRIPTOR_INFO_EXT };
    image_info.pView                    = &view_info;
    image_info.layout                   = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;

    VkResourceDescriptorInfoEXT descriptor_info = { VK_STRUCTURE_TYPE_RESOURCE_DESCRIPTOR_INFO_EXT };
    descriptor_info.type                        = VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE;
    descriptor_info.data.pImage                 = &image_info;

    const std::vector<uint8_t> data = DeepCopy(descriptor_info);
    const auto*                copy = reinterpret_cast<const VkResourceDescriptorInfoEXT*>(data.data());

    REQUIRE(IsInside(data, copy->data.pImage));
    REQUIRE(copy->data.pImage->layout == image_info.layout);
    REQUIRE(IsInside(data, copy->data.pImage->pView));
    REQUIRE(copy->data.pImage->pView->format == view_info.format);
}

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)
