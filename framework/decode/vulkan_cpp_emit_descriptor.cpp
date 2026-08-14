//
// Copyright (c) 2020 Samsung
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

// Descriptor update templates.
// This file holds part of VulkanCppConsumerBase.  See vulkan_cpp_consumer_base.h.

#include "decode/vulkan_cpp_consumer_base.h"
#include "decode/vulkan_cpp_template_strings.h"

#include PROJECT_VERSION_HEADER_FILE
#include "util/file_path.h"
#include "util/platform.h"
#include <util/hash.h>
#include "decode/vulkan_cpp_structs.h"
#include <generated/generated_vulkan_cpp_structs.h>
#include "generated/generated_vulkan_cpp_consumer_extension.h"
#include "generated/generated_vulkan_enum_to_string.h"

#include <algorithm>
#include <cmath>
#include <iomanip>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)
void VulkanCppConsumerBase::Generate_vkCreateDescriptorUpdateTemplate(args::CreateDescriptorUpdateTemplate& args,
                                                                      const char*                           extension)
{
    FILE*             file = GetFrameFile();
    std::string       create_info_struct_var_name;
    std::stringstream stream_create_info;
    std::string       desc_update_template_var_name = "pDescriptorUpdateTemplate_" + std::to_string(this->GetNextId());
    AddKnownVariables("VkDescriptorUpdateTemplate", desc_update_template_var_name);
    std::string method_name = "vkCreateDescriptorUpdateTemplate";
    method_name += extension;

    fprintf(file, "\t{\n");
    VkDescriptorUpdateTemplateCreateInfo* tocpp_create_info = args.pCreateInfo.GetPointer();
    if (tocpp_create_info != nullptr)
    {
        // Modify the layout of the update template entries to match the tight packing performed by the trace encoding.
        // The trace encoding wrote the update template entries as a tightly packed array of VkDescriptorImageInfo
        // values, followed by an array of VkDescriptorBufferInfo values, followed by an array of VkBufferView values.
        VkDescriptorUpdateTemplateCreateInfo override_create_info = (*tocpp_create_info);

        std::vector<VkDescriptorUpdateTemplateEntry> entries(
            override_create_info.pDescriptorUpdateEntries,
            (override_create_info.pDescriptorUpdateEntries + override_create_info.descriptorUpdateEntryCount));

        auto template_handle_id = *args.pDescriptorUpdateTemplate.GetPointer();

        // Count the number of values of each type.
        size_t image_info_count             = 0;
        size_t buffer_info_count            = 0;
        size_t texel_buffer_view_count      = 0;
        size_t acceleration_structure_count = 0;
        size_t inline_uniform_block_count   = 0;

        for (auto entry = entries.begin(); entry != entries.end(); ++entry)
        {
            VkDescriptorType type = entry->descriptorType;

            if ((type == VK_DESCRIPTOR_TYPE_SAMPLER) || (type == VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER) ||
                (type == VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE) || (type == VK_DESCRIPTOR_TYPE_STORAGE_IMAGE) ||
                (type == VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT))
            {
                image_info_count += entry->descriptorCount;
            }
            else if ((type == VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER) || (type == VK_DESCRIPTOR_TYPE_STORAGE_BUFFER) ||
                     (type == VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC) ||
                     (type == VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC))
            {
                buffer_info_count += entry->descriptorCount;
            }
            else if ((type == VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER) ||
                     (type == VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER))
            {
                texel_buffer_view_count += entry->descriptorCount;
            }
            else if (type == VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR)
            {
                acceleration_structure_count += entry->descriptorCount;
            }
            else if (type == VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK)
            {
                inline_uniform_block_count += entry->descriptorCount;
            }
            else
            {
                assert(false);
            }
        }

        // Compute start offsets for each type.
        size_t image_info_offset        = 0;
        size_t buffer_info_offset       = image_info_count * sizeof(VkDescriptorImageInfo);
        size_t texel_buffer_view_offset = buffer_info_offset + (buffer_info_count * sizeof(VkDescriptorBufferInfo));
        size_t accel_struct_offset      = texel_buffer_view_offset + (texel_buffer_view_count * sizeof(VkBufferView));
        size_t inline_uniform_block_offset =
            accel_struct_offset + (acceleration_structure_count * sizeof(VkAccelerationStructureKHR));

        // Track descriptor image type.
        std::vector<VkDescriptorType> image_types;

        for (auto entry = entries.begin(); entry != entries.end(); ++entry)
        {
            VkDescriptorType type = entry->descriptorType;

            descriptor_update_template_entry_map_[template_handle_id].data.emplace_back(*entry);

            if ((type == VK_DESCRIPTOR_TYPE_SAMPLER) || (type == VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER) ||
                (type == VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE) || (type == VK_DESCRIPTOR_TYPE_STORAGE_IMAGE) ||
                (type == VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT))
            {
                image_types.insert(image_types.end(), entry->descriptorCount, entry->descriptorType);

                entry->stride = sizeof(VkDescriptorImageInfo);
                entry->offset = image_info_offset;
                image_info_offset += entry->descriptorCount * sizeof(VkDescriptorImageInfo);

                descriptor_update_template_entry_map_[template_handle_id].images.emplace_back(*entry);
            }
            else if ((type == VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER) || (type == VK_DESCRIPTOR_TYPE_STORAGE_BUFFER) ||
                     (type == VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC) ||
                     (type == VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC))
            {
                entry->stride = sizeof(VkDescriptorBufferInfo);
                entry->offset = buffer_info_offset;
                buffer_info_offset += entry->descriptorCount * sizeof(VkDescriptorBufferInfo);

                descriptor_update_template_entry_map_[template_handle_id].buffers.emplace_back(*entry);
            }
            else if ((type == VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER) ||
                     (type == VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER))
            {
                entry->stride = sizeof(VkBufferView);
                entry->offset = texel_buffer_view_offset;
                texel_buffer_view_offset += entry->descriptorCount * sizeof(VkBufferView);

                descriptor_update_template_entry_map_[template_handle_id].texels.emplace_back(*entry);
            }
            else if (type == VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR)
            {
                entry->stride = sizeof(VkAccelerationStructureKHR);
                entry->offset = accel_struct_offset;
                accel_struct_offset += entry->descriptorCount * sizeof(VkAccelerationStructureKHR);

                descriptor_update_template_entry_map_[template_handle_id].accelerations.emplace_back(*entry);
            }
            else if (type == VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK)
            {
                constexpr size_t byte_stride = 1;
                entry->stride                = byte_stride;
                entry->offset                = inline_uniform_block_offset;
                inline_uniform_block_offset += entry->descriptorCount * byte_stride;

                descriptor_update_template_entry_map_[template_handle_id].inline_uniform_blocks.emplace_back(*entry);
            }
            else
            {
                assert(false);
            }
        }

        override_create_info.pDescriptorUpdateEntries = entries.data();

        create_info_struct_var_name = GenerateStruct_VkDescriptorUpdateTemplateCreateInfo(
            stream_create_info, &override_create_info, args.pCreateInfo.GetMetaStructPointer(), *this);
    }
    else
    {
        create_info_struct_var_name = GenerateStruct_VkDescriptorUpdateTemplateCreateInfo(
            stream_create_info, args.pCreateInfo.GetPointer(), args.pCreateInfo.GetMetaStructPointer(), *this);

        auto template_handle_id = *args.pDescriptorUpdateTemplate.GetPointer();
        for (uint32_t idx = 0; idx < tocpp_create_info->descriptorUpdateEntryCount; idx++)
        {
            auto create_info_entry = tocpp_create_info->pDescriptorUpdateEntries[idx];
            descriptor_update_template_entry_map_[template_handle_id].data.emplace_back(create_info_entry);
            switch (GetDescriptorBaseType(create_info_entry.descriptorType))
            {
                case DESCRIPTOR_BASE_TYPE_SAMPLER:
                case DESCRIPTOR_BASE_TYPE_IMAGE:
                case DESCRIPTOR_BASE_TYPE_COMBINED_IMAGE_SAMPLER:
                {
                    descriptor_update_template_entry_map_[template_handle_id].images.emplace_back(create_info_entry);
                    break;
                }
                case DESCRIPTOR_BASE_TYPE_BUFFER:
                {
                    descriptor_update_template_entry_map_[template_handle_id].buffers.emplace_back(create_info_entry);
                    break;
                }
                case DESCRIPTOR_BASE_TYPE_TEXEL:
                {
                    descriptor_update_template_entry_map_[template_handle_id].texels.emplace_back(create_info_entry);
                    break;
                }
                default:
                {
                    assert(false); // This should never happen
                }
            }
        }
    }

    if (args.result == VK_SUCCESS)
    {
        this->AddHandles(desc_update_template_var_name, args.pDescriptorUpdateTemplate.GetPointer());
    }

    fprintf(file, "%s", stream_create_info.str().c_str());
    pfn_loader_.AddMethodName(method_name);
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_%s(%s, &%s, NULL, &%s), %s);\n",
            method_name.c_str(),
            this->GetHandle(args.device).c_str(),
            create_info_struct_var_name.c_str(),
            desc_update_template_var_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
}

struct VariableOffset
{
    std::string      name;
    VkDescriptorType type;
    uint32_t         count;
    uint64_t         offset;
};

bool VariableOffsetCompare(VariableOffset& a, VariableOffset& b)
{
    return a.offset < b.offset;
}

void VulkanCppConsumerBase::GenerateDescriptorUpdateTemplateData(DescriptorUpdateTemplateDecoder* decoder,
                                                                 format::HandleId descriptor_update_template,
                                                                 FILE*            frame_file,
                                                                 std::string&     template_data_var_name)
{
    std::vector<VariableOffset> variables;
    std::stringstream           struct_define_stream;
    std::stringstream           struct_implement_stream;
    std::vector<std::string>    image_desc_info_variables;
    std::vector<std::string>    buffer_desc_info_variables;
    std::vector<std::string>    texel_desc_info_variables;
    std::vector<std::string>    accel_desc_info_variables;
    std::vector<std::string>    inline_uniform_block_info_variables;

    uint32_t image_info_count           = static_cast<uint32_t>(decoder->GetImageInfoCount());
    uint32_t buffer_info_count          = static_cast<uint32_t>(decoder->GetBufferInfoCount());
    uint32_t texel_buffer_view_count    = static_cast<uint32_t>(decoder->GetTexelBufferViewCount());
    uint32_t accel_struct_count         = static_cast<uint32_t>(decoder->GetAccelerationStructureKHRCount());
    uint32_t inline_uniform_block_count = static_cast<uint32_t>(decoder->GetInlineUniformBlockCount());

    assert(descriptor_update_template_entry_map_.find(descriptor_update_template) !=
           descriptor_update_template_entry_map_.end());

    const DescriptorUpdateTemplateEntries& template_entries =
        descriptor_update_template_entry_map_[descriptor_update_template];

    // Generate the appropriate info structure based on the descriptor type

    // Image info structures
    if (decoder->GetImageInfoPointer() != nullptr && image_info_count > 0)
    {
        std::stringstream              desc_image_info_stream;
        VkDescriptorImageInfo*         infos                = decoder->GetImageInfoPointer();
        Decoded_VkDescriptorImageInfo* meta_structs         = decoder->GetImageInfoMetaStructPointer();
        uint32_t                       image_template_index = 0;
        uint32_t                       cur_desc_count       = template_entries.images[0].descriptorCount;

        for (uint32_t idx = 0; idx < image_info_count; idx++)
        {
            // Only use the next template if every descriptor has been generated for the current template
            if (idx == cur_desc_count)
            {
                image_template_index++;
                cur_desc_count += template_entries.images[image_template_index].descriptorCount;
            }

            std::string varName = GenerateStruct_VkDescriptorImageInfo(desc_image_info_stream,
                                                                       template_entries.images[image_template_index],
                                                                       &infos[idx],
                                                                       &meta_structs[idx],
                                                                       *this);
            image_desc_info_variables.emplace_back(varName);
        }
        fprintf(frame_file, "%s", desc_image_info_stream.str().c_str());
    }

    // Buffer info structures
    if (decoder->GetBufferInfoPointer() != nullptr && buffer_info_count > 0)
    {
        std::stringstream               desc_buffer_info_stream;
        VkDescriptorBufferInfo*         infos        = decoder->GetBufferInfoPointer();
        Decoded_VkDescriptorBufferInfo* meta_structs = decoder->GetBufferInfoMetaStructPointer();

        for (uint32_t idx = 0; idx < buffer_info_count; idx++)
        {
            std::string varName =
                GenerateStruct_VkDescriptorBufferInfo(desc_buffer_info_stream, &infos[idx], &meta_structs[idx], *this);
            buffer_desc_info_variables.emplace_back(varName);
        }
        fprintf(frame_file, "%s", desc_buffer_info_stream.str().c_str());
    }

    // Texel Handle info structures
    // TODO: Due to a lack of test examples using texel buffer views, this part requires more testing
    if (decoder->GetTexelBufferViewPointer() != nullptr && texel_buffer_view_count > 0)
    {
        format::HandleId* handles = decoder->GetTexelBufferViewHandleIdsPointer();
        for (uint32_t idx = 0; idx < texel_buffer_view_count; idx++)
        {
            std::string cur_handle = GetHandle(handles[idx]);
            texel_desc_info_variables.emplace_back(cur_handle);
        }
    }

    // Acceleration Handle info structures
    // TODO: Due to a lack of test examples using acceleration structures, this part requires more testing
    if (decoder->GetAccelerationStructureKHRPointer() != nullptr && accel_struct_count > 0)
    {
        format::HandleId* handles = decoder->GetAccelerationStructureKHRHandleIdsPointer();
        for (uint32_t idx = 0; idx < accel_struct_count; idx++)
        {
            std::string cur_handle = GetHandle(handles[idx]);
            accel_desc_info_variables.emplace_back(cur_handle);
        }
    }

    std::string struct_type_name      = "StructDefine_" + std::to_string(GetNextId());
    std::string struct_implement_name = "pData_" + std::to_string(GetNextId());

    struct_define_stream << "\t\tstruct " << struct_type_name << " {\n";
    struct_implement_stream << "\t\t" << struct_type_name << " " << struct_implement_name << " {\n";
    uint32_t cur_count = 0;

    // Now loop through the descriptor template entry list and find each item and it's
    // offset into the template structure.  This is then used to sort the names of the
    // corresponding variables based on the offset so they are defined in the template
    // definition correctly.
    uint32_t template_descriptor_count = 0;
    for (auto const& entry : template_entries.data)
    {
        template_descriptor_count += entry.descriptorCount;
        switch (entry.descriptorType)
        {
            case VK_DESCRIPTOR_TYPE_SAMPLER:
            case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
            case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
            case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
            case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
            {
                VariableOffset offset = {
                    image_desc_info_variables[0], entry.descriptorType, entry.descriptorCount, entry.offset
                };
                image_desc_info_variables.erase(image_desc_info_variables.begin());
                variables.push_back(std::move(offset));
                break;
            }
            case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
            case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
            case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
            case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
            {
                VariableOffset offset = {
                    buffer_desc_info_variables[0], entry.descriptorType, entry.descriptorCount, entry.offset
                };
                buffer_desc_info_variables.erase(buffer_desc_info_variables.begin());
                variables.push_back(std::move(offset));
                break;
            }
            case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
            case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
            {
                VariableOffset offset = {
                    texel_desc_info_variables[0], entry.descriptorType, entry.descriptorCount, entry.offset
                };
                texel_desc_info_variables.erase(texel_desc_info_variables.begin());
                variables.push_back(std::move(offset));
                break;
            }
            case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR:
            {
                VariableOffset offset = {
                    accel_desc_info_variables[0], entry.descriptorType, entry.descriptorCount, entry.offset
                };
                accel_desc_info_variables.erase(accel_desc_info_variables.begin());
                variables.push_back(std::move(offset));
                break;
            }
            case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK:
            {
                // TODO: needs testing, unsure when/how we'll use this
                assert(false);

                VariableOffset offset = {
                    inline_uniform_block_info_variables[0], entry.descriptorType, entry.descriptorCount, entry.offset
                };
                inline_uniform_block_info_variables.erase(inline_uniform_block_info_variables.begin());
                variables.push_back(std::move(offset));
                break;
            }
            default:
                break;
        }
    }

    // Check if the number of descriptors in pData equal the number of descriptors in the template
    const auto expected_data_count = decoder->GetImageInfoCount() + decoder->GetBufferInfoCount() +
                                     decoder->GetTexelBufferViewCount() + decoder->GetAccelerationStructureKHRCount();
    assert(template_descriptor_count == expected_data_count);

    // Sort the variables based on the offset
    std::sort(variables.begin(), variables.end(), VariableOffsetCompare);

    // Now that they are sorted, write out the template definition and implementation.
    for (auto const& var : variables)
    {
        struct_implement_stream << "\t\t\t{ ";
        for (uint32_t jdx = 0; jdx < var.count; jdx++)
        {
            if (jdx == 0)
            {
                switch (var.type)
                {
                    case VK_DESCRIPTOR_TYPE_SAMPLER:
                    case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
                    case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
                    case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
                    case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
                        struct_define_stream << "\t\t\tVkDescriptorImageInfo descImageInfo" << cur_count++ << "["
                                             << var.count << "];\n";
                        break;
                    case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
                    case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
                    case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
                    case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
                        struct_define_stream << "\t\t\tVkDescriptorBufferInfo descBufferInfo" << cur_count++ << "["
                                             << var.count << "];\n";
                        break;
                    case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
                    case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
                        struct_define_stream << "\t\t\tVkBufferView descTexelInfo" << cur_count++ << "[" << var.count
                                             << "];\n";
                        break;
                    case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR:
                        struct_define_stream << "\t\t\tVkAccelerationStructureKHR descAccelInfo" << cur_count++ << "["
                                             << var.count << "];\n";
                        break;
                    case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK:
                        struct_define_stream << "\t\t\tInlineUniformBlock descInlineUniformInfo" << cur_count++ << "["
                                             << var.count << "];\n";
                        break;
                    default:
                        assert(false);
                        struct_define_stream << "UNKNOWN DESCRIPTOR_TYPE, ";
                        break;
                }
            }
            struct_implement_stream << var.name << ", ";
        }
        struct_implement_stream << "},\n";
    }

    struct_define_stream << "\t\t};\n";
    struct_implement_stream << "\t\t};\n";
    fprintf(frame_file, "%s", struct_define_stream.str().c_str());
    fprintf(frame_file, "%s", struct_implement_stream.str().c_str());

    template_data_var_name = struct_implement_name;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
