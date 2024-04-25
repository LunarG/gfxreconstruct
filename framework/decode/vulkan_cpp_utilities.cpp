//
// Copyright (c) 2021 Samsung
// Copyright (c) 2023 Google
// Copyright (c) 2023 LunarG, Inc
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "vulkan_cpp_utilities.h"

#include <algorithm>
#include <iterator>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

std::string GfxToCppVariable::GenerateString() const
{
    std::string var_string = type + " " + name;
    if (count > 0)
    {
        return var_string + " [" + std::to_string(count) + "]";
    }
    return var_string;
}

std::vector<std::string> GfxToCppVariable::GenerateStringVec(const std::vector<GfxToCppVariable>& variables)
{
    std::vector<std::string> var_strings;
    var_strings.reserve(variables.size());
    std::transform(variables.begin(),
                   variables.end(),
                   std::back_inserter(var_strings),
                   [](const GfxToCppVariable& variable) { return variable.GenerateString(); });
    return var_strings;
}

void PrintToFile(FILE* file, const std::string& format, const std::vector<std::string>& data)
{
    for (const std::string& string : data)
    {
        fprintf(file, format.c_str(), string.c_str());
    }
}

std::string DescriptorCreateInfoTypeToString(VkDescriptorType descriptorType)
{
    switch (descriptorType)
    {
        case VK_DESCRIPTOR_TYPE_SAMPLER:
        case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
        case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
        case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
        case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
            return "VkDescriptorImageInfo";
        case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
        case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
        case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
        case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
            return "VkDescriptorBufferInfo";
        case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
        case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
            return "VkBufferView";
        case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK:
            return "VkWriteDescriptorSetInlineUniformBlock";
        case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR:
            return "VkWriteDescriptorSetAccelerationStructureKHR";
        default:
            return "";
    }
}

DescriptorBaseType GetDescriptorBaseType(VkDescriptorType descriptorType)
{
    switch (descriptorType)
    {
        case VK_DESCRIPTOR_TYPE_SAMPLER:
            return DESCRIPTOR_BASE_TYPE_SAMPLER;
        case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
        case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
        case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
            return DESCRIPTOR_BASE_TYPE_IMAGE;
        case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
            return DESCRIPTOR_BASE_TYPE_COMBINED_IMAGE_SAMPLER;
        case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
        case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
        case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
        case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
            return DESCRIPTOR_BASE_TYPE_BUFFER;
        case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
        case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
            return DESCRIPTOR_BASE_TYPE_TEXEL;
        case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK:
            return DESCRIPTOR_BASE_TYPE_INLINE_UNIFORM_BLOCK;
        case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR:
            return DESCRIPTOR_BASE_TYPE_ACCELERATION_STRUCTURE;
        default:
            return DESCRIPTOR_BASE_TYPE_NONE;
    }
}

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)
