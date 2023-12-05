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

#include "vulkan_cpp_structs.h"

#include "decode/vulkan_consumer_base.h"
#include "decode/vulkan_cpp_utilities.h"

#include "generated/generated_vulkan_cpp_consumer.h"
#include "generated/generated_vulkan_cpp_structs.h"
#include "generated/generated_vulkan_enum_to_string.h"
#include "generated/generated_vulkan_cpp_consumer_extension.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

std::string GenerateStruct_VkMemoryAllocateInfo(std::ostream&                 out,
                                                format::HandleId              memoryHandleId,
                                                const VkMemoryAllocateInfo*   structInfo,
                                                Decoded_VkMemoryAllocateInfo* metaInfo,
                                                VulkanCppConsumerBase&        consumer)
{

    std::string memory_reqs = "";
    bool        new_size    = consumer.GetResourceMemoryRequirements(memoryHandleId, memory_reqs);

    std::stringstream struct_body;
    // sType
    struct_body << "\t\t\t"
                << "VkStructureType(" << structInfo->sType << ")"
                << "," << std::endl;
    // pNext
    std::string pnext_name = GenerateExtension(out, structInfo->pNext, metaInfo->pNext, consumer);
    struct_body << "\t\t\t" << pnext_name << "," << std::endl;
    // allocationSize
    struct_body << "\t\t\t" << structInfo->allocationSize << "UL"
                << "," << std::endl;
    // memoryTypeIndex
    struct_body << "\t\t\t"
                << "RecalculateMemoryTypeIndex(" << structInfo->memoryTypeIndex << ")"
                << ",";

    std::string variable_name = consumer.AddStruct(struct_body, "memoryAllocateInfo");
    out << "\t\tVkMemoryAllocateInfo " << variable_name << " {" << std::endl;
    out << struct_body.str() << std::endl;
    out << "\t\t};" << std::endl;

    return variable_name;
}

std::string GenerateStruct_VkClearColorValue(std::ostream&              out,
                                             const VkClearColorValue*   structInfo,
                                             Decoded_VkClearColorValue* metaInfo,
                                             VulkanCppConsumerBase&     consumer)
{
    std::stringstream struct_body;
    struct_body << VulkanCppConsumerBase::BuildValue(*structInfo);

    std::string variable_name = consumer.AddStruct(struct_body, "clearColorValue");
    out << "\t\tVkClearColorValue " << variable_name << " = " << struct_body.str() << ";" << std::endl;

    return variable_name;
}

std::string GenerateStruct_VkWriteDescriptorSet(std::ostream&                 out,
                                                const VkWriteDescriptorSet*   structInfo,
                                                Decoded_VkWriteDescriptorSet* metaInfo,
                                                VulkanCppConsumerBase&        consumer)
{
    std::stringstream struct_body;
    std::stringstream struct_body_header;

    struct_body << "\t\t\tVkStructureType(" << structInfo->sType << ")"
                << "," << std::endl;
    struct_body << "\t\t\t" << GenerateExtension(out, structInfo->pNext, metaInfo->pNext, consumer) << "," << std::endl;
    struct_body << "\t\t\t" << consumer.GetHandle(metaInfo->dstSet) << "," << std::endl;
    struct_body << "\t\t\t" << structInfo->dstBinding << "," << std::endl;
    struct_body << "\t\t\t" << structInfo->dstArrayElement << "," << std::endl;
    struct_body << "\t\t\t" << structInfo->descriptorCount << "," << std::endl;
    struct_body << "\t\t\t"
                << "VkDescriptorType(" << structInfo->descriptorType << ")"
                << "," << std::endl;

    switch (structInfo->descriptorType)
    {
        case VK_DESCRIPTOR_TYPE_SAMPLER:
        case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
        case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
        case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
        case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
        {
            std::string                    info_values;
            Decoded_VkDescriptorImageInfo* image_meta_infos = metaInfo->pImageInfo->GetMetaStructPointer();
            VkDescriptorImageInfo*         image_infos      = metaInfo->pImageInfo->GetPointer();
            for (uint32_t idx = 0; idx < structInfo->descriptorCount; idx++)
            {
                std::string sampler_value = "VK_NULL_HANDLE";
                if ((structInfo->descriptorType == VK_DESCRIPTOR_TYPE_SAMPLER) ||
                    (structInfo->descriptorType == VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER))
                {
                    sampler_value = consumer.GetHandle(image_meta_infos[idx].sampler);
                    assert(sampler_value.length() > 0); // There should be a sampler in these cases
                }

                info_values += "{ " + sampler_value + ", " + consumer.GetHandle(image_meta_infos[idx].imageView) +
                               ", " + "VkImageLayout(" +
                               std::to_string(static_cast<int>(image_infos[idx].imageLayout)) + ")" + " }, ";
            }
            std::string info_array = "pImageInfoArray_" + std::to_string(consumer.GetNextId());
            struct_body_header << "\t\tVkDescriptorImageInfo " << info_array << "[] = { " << info_values << " };"
                               << std::endl;
            struct_body << "\t\t\t" << info_array << "," << std::endl;
            struct_body << "\t\t\tNULL," << std::endl;
            struct_body << "\t\t\tNULL,";
            break;
        }
        case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
        case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
        case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
        case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
        {
            std::string                     info_values;
            Decoded_VkDescriptorBufferInfo* buffer_meta_infos = metaInfo->pBufferInfo->GetMetaStructPointer();
            VkDescriptorBufferInfo*         buffer_infos      = metaInfo->pBufferInfo->GetPointer();
            for (uint32_t idx = 0; idx < structInfo->descriptorCount; idx++)
            {
                info_values += "{ " + consumer.GetHandle(buffer_meta_infos[idx].buffer) + ", " +
                               std::to_string(buffer_infos[idx].offset) + "UL, " +
                               std::to_string(buffer_infos[idx].range) + "UL " + " }, ";
            }

            std::string info_array = "pBufferInfoArray_" + std::to_string(consumer.GetNextId());

            struct_body_header << "\t\tVkDescriptorBufferInfo " << info_array << "[] = { " << info_values << " };"
                               << std::endl;
            struct_body << "\t\t\tNULL," << std::endl;
            struct_body << "\t\t\t" << info_array << "," << std::endl;
            struct_body << "\t\t\tNULL,";
            break;
        }
        case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
        case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
        {
            std::string info_values;
            for (uint32_t idx = 0; idx < structInfo->descriptorCount; idx++)
            {
                info_values += consumer.GetHandle(metaInfo->pTexelBufferView.GetPointer()[idx]) + ", ";
            }
            std::string info_array = "pTexelBufferViewArray_" + std::to_string(consumer.GetNextId());

            struct_body_header << "\t\tVkBufferView " << info_array << "[] = { " << info_values << " };" << std::endl;
            struct_body << "\t\t\tNULL," << std::endl;
            struct_body << "\t\t\tNULL," << std::endl;
            struct_body << "\t\t\t" << info_array << ",";
            break;
        }
        case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR:
        case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK_EXT:
        case VK_DESCRIPTOR_TYPE_MAX_ENUM:
        {
            // Nothing to do.
            break;
        }
        default:
        {
            GFXRECON_LOG_ERROR("ToCpp VkWriteDescriptorSet unknown type %d", structInfo->descriptorType);
            break;
        }
    }

    std::string variable_name = "vkWriteDescriptorSet_" + std::to_string(consumer.GetNextId());
    out << struct_body_header.str() << std::endl;
    out << "\t\tVkWriteDescriptorSet " << variable_name << " {" << std::endl;
    out << struct_body.str() << std::endl;
    out << "\t\t};" << std::endl;

    return variable_name;
}

std::string GenerateStruct_VkPresentInfoKHR(std::ostream&             out,
                                            const VkPresentInfoKHR*   structInfo,
                                            Decoded_VkPresentInfoKHR* metaInfo,
                                            VulkanCppConsumerBase&    consumer)
{
    std::string image_array_indices = "NULL";
    std::string swapchains_array    = "NULL";
    if (metaInfo->pSwapchains.GetPointer() != NULL)
    {
        const format::HandleId* swapchain_handles       = metaInfo->pSwapchains.GetPointer();
        std::string             swapchain_handle_values = toStringJoin(
            swapchain_handles,
            swapchain_handles + structInfo->swapchainCount,
            [&](const format::HandleId current) { return consumer.GetHandle(current); },
            ", ");
        std::string image_indices_values = toStringJoin(
            swapchain_handles,
            swapchain_handles + structInfo->swapchainCount,
            [&](const format::HandleId current) { return consumer.GetNextImage(current); },
            ", ");

        if (structInfo->swapchainCount == 1)
        {
            swapchains_array    = "&" + swapchain_handle_values;
            image_array_indices = "&" + image_indices_values;
        }
        else if (structInfo->swapchainCount > 1)
        {
            image_array_indices = "pImageIndices_" + std::to_string(consumer.GetNextId());
            swapchains_array    = "pSwapchainsArray_" + std::to_string(consumer.GetNextId());

            out << "\t\tVkSwapchainKHR " << swapchains_array << "[] = {" << swapchain_handle_values << "};"
                << std::endl;
            out << "\t\tuint32_t " << image_array_indices << "[] = {" << image_indices_values << "};" << std::endl;
        }
        else
        {
            // this should never happen
        }
    }

    std::string wait_semaphore_array_string = "NULL";
    if (metaInfo->pWaitSemaphores.GetPointer() != NULL)
    {
        const format::HandleId* wait_semaphore_array  = metaInfo->pWaitSemaphores.GetPointer();
        std::string             wait_semaphore_values = toStringJoin(
            wait_semaphore_array,
            wait_semaphore_array + structInfo->waitSemaphoreCount,
            [&](const format::HandleId current) { return consumer.GetHandle(current); },
            ", ");

        if (structInfo->waitSemaphoreCount == 1)
        {
            wait_semaphore_array_string = "&" + wait_semaphore_values;
        }
        else if (structInfo->waitSemaphoreCount > 1)
        {
            wait_semaphore_array_string = "pWaitSemaphoresArray_" + std::to_string(consumer.GetNextId());

            out << "\t\tVkSemaphore " << wait_semaphore_array_string << "[] = {" << wait_semaphore_values << "};"
                << std::endl;
        }
    }

    std::stringstream struct_body;
    struct_body << "\t\t\t"
                << "VkStructureType(" << structInfo->sType << ")"
                << "," << std::endl;
    // pNext
    std::string pnext_name = GenerateExtension(out, structInfo->pNext, metaInfo->pNext, consumer);
    struct_body << "\t\t\t" << pnext_name << "," << std::endl;
    struct_body << "\t\t\t" << structInfo->waitSemaphoreCount << "," << std::endl;
    struct_body << "\t\t\t" << wait_semaphore_array_string << "," << std::endl;
    struct_body << "\t\t\t" << structInfo->swapchainCount << "," << std::endl;
    struct_body << "\t\t\t" << swapchains_array << "," << std::endl;
    struct_body << "\t\t\t" << image_array_indices << "," << std::endl;
    struct_body << "\t\t\t"
                << "NULL";

    std::string variable_name = consumer.AddStruct(struct_body, "presentInfoKHR");
    out << "\t\tVkPresentInfoKHR " << variable_name << " {" << std::endl;
    out << struct_body.str() << std::endl;
    out << "\t\t};" << std::endl;

    return variable_name;
}

std::string
GenerateStruct_VkDescriptorUpdateTemplateCreateInfoKHR(std::ostream&                                 out,
                                                       const VkDescriptorUpdateTemplateCreateInfo*   structInfo,
                                                       Decoded_VkDescriptorUpdateTemplateCreateInfo* metaInfo,
                                                       VulkanCppConsumerBase&                        consumer,
                                                       const std::string&                            structTypeSuffix)
{
    std::string descriptor_update_entries_array_string = "NULL";
    if (structInfo->pDescriptorUpdateEntries != NULL)
    {
        descriptor_update_entries_array_string = "pDescriptorUpdateEntries_" + std::to_string(consumer.GetNextId());

        // Recalculate the offset and stride for each template entry.
        uint32_t image_info_count             = 0;
        uint32_t buffer_info_count            = 0;
        uint32_t texel_buffer_view_info_count = 0;
        uint32_t acceleration_info_count      = 0;

        const VkDescriptorUpdateTemplateEntry* entries = structInfo->pDescriptorUpdateEntries;

        for (uint32_t idx = 0; idx < structInfo->descriptorUpdateEntryCount; idx++)
        {
            switch (GetDescriptorBaseType(entries[idx].descriptorType))
            {
                case DESCRIPTOR_BASE_TYPE_IMAGE:
                case DESCRIPTOR_BASE_TYPE_SAMPLER:
                case DESCRIPTOR_BASE_TYPE_COMBINED_IMAGE_SAMPLER:
                {
                    image_info_count += entries[idx].descriptorCount;
                    break;
                }
                case DESCRIPTOR_BASE_TYPE_BUFFER:
                {
                    buffer_info_count += entries[idx].descriptorCount;
                    break;
                }
                case DESCRIPTOR_BASE_TYPE_TEXEL:
                {
                    texel_buffer_view_info_count += entries[idx].descriptorCount;
                    break;
                }
                case DESCRIPTOR_BASE_TYPE_ACCELERATION_STRUCTURE:
                {
                    acceleration_info_count += entries[idx].descriptorCount;
                    break;
                }
                default:
                {
                    assert(false);
                }
            }
        }

        uint32_t image_info_offset        = 0;
        uint32_t buffer_info_offset       = image_info_count * sizeof(VkDescriptorImageInfo);
        uint32_t texel_buffer_view_offset = buffer_info_offset + (buffer_info_count * sizeof(VkDescriptorBufferInfo));
        uint32_t acceleration_info_offset =
            texel_buffer_view_offset + (texel_buffer_view_info_count * sizeof(VkBufferView));

        std::string descriptor_update_entries_names;
        for (uint32_t idx = 0; idx < structInfo->descriptorUpdateEntryCount; idx++)
        {
            VkDescriptorUpdateTemplateEntry entry = structInfo->pDescriptorUpdateEntries[idx];

            size_t override_stride = 0;
            size_t override_offset = 0;

            switch (GetDescriptorBaseType(entry.descriptorType))
            {
                case DESCRIPTOR_BASE_TYPE_IMAGE:
                case DESCRIPTOR_BASE_TYPE_SAMPLER:
                case DESCRIPTOR_BASE_TYPE_COMBINED_IMAGE_SAMPLER:
                {
                    override_stride = sizeof(VkDescriptorImageInfo);
                    override_offset = image_info_offset;
                    image_info_offset += entry.descriptorCount * sizeof(VkDescriptorImageInfo);
                    break;
                }
                case DESCRIPTOR_BASE_TYPE_BUFFER:
                {
                    override_stride = sizeof(VkDescriptorBufferInfo);
                    override_offset = buffer_info_offset;
                    buffer_info_offset += entry.descriptorCount * sizeof(VkDescriptorBufferInfo);
                    break;
                }
                case DESCRIPTOR_BASE_TYPE_TEXEL:
                {
                    override_stride = sizeof(VkBufferView);
                    override_offset = texel_buffer_view_offset;
                    texel_buffer_view_offset += entry.descriptorCount * sizeof(VkBufferView);
                    break;
                }
                case DESCRIPTOR_BASE_TYPE_ACCELERATION_STRUCTURE:
                {
                    override_stride = sizeof(VkBufferView);
                    override_offset = acceleration_info_offset;
                    acceleration_info_offset += entry.descriptorCount * sizeof(VkAccelerationStructureKHR);
                    break;
                }
                default:
                {
                    assert(false);
                }
            }

            entry.offset = override_offset;
            entry.stride = override_stride;

            std::string decs_update_var_name = GenerateStruct_VkDescriptorUpdateTemplateEntry(
                out, &entry, metaInfo->pDescriptorUpdateEntries->GetMetaStructPointer() + idx, consumer);
            descriptor_update_entries_names += decs_update_var_name + ", ";
        }
        out << "VkDescriptorUpdateTemplateEntry" << structTypeSuffix << " " << descriptor_update_entries_array_string
            << "[] = {" << descriptor_update_entries_names << "};" << std::endl;
    }
    std::stringstream struct_body;
    // sType
    struct_body << "\t\t\t"
                << "VkStructureType(" << structInfo->sType << ")"
                << "," << std::endl;
    // pNext
    std::string pnext_name = GenerateExtension(out, structInfo->pNext, metaInfo->pNext, consumer);
    struct_body << "\t\t\t" << pnext_name << "," << std::endl;
    // flags
    struct_body << "\t\t\t"
                << "VkDescriptorUpdateTemplateCreateFlags>(" << structInfo->flags << ")"
                << "," << std::endl;
    // descriptorUpdateEntryCount
    struct_body << "\t\t\t" << structInfo->descriptorUpdateEntryCount << "," << std::endl;
    // pDescriptorUpdateEntries
    struct_body << "\t\t\t" << descriptor_update_entries_array_string << "," << std::endl;
    // templateType
    struct_body << "\t\t\t"
                << "VkDescriptorUpdateTemplateType(" << structInfo->templateType << ")"
                << "," << std::endl;
    // descriptorSetLayout
    struct_body << "\t\t\t" << consumer.GetHandle(metaInfo->descriptorSetLayout) << "," << std::endl;
    // pipelineBindPoint
    struct_body << "\t\t\t"
                << "VkPipelineBindPoint(" << structInfo->pipelineBindPoint << ")"
                << "," << std::endl;
    // pipelineLayout
    struct_body << "\t\t\t" << consumer.GetHandle(metaInfo->pipelineLayout) << "," << std::endl;
    // set
    struct_body << "\t\t\t" << structInfo->set << ",";

    std::string variable_name = consumer.AddStruct(struct_body, "descriptorUpdateTemplateCreateInfo");
    out << "\t\tVkDescriptorUpdateTemplateCreateInfo" << structTypeSuffix << " " << variable_name << " {" << std::endl;
    out << struct_body.str() << std::endl;
    out << "\t\t};" << std::endl;

    return variable_name;
}

std::string GenerateStruct_VkDescriptorImageInfo(std::ostream&                   out,
                                                 VkDescriptorUpdateTemplateEntry templateEntry,
                                                 const VkDescriptorImageInfo*    structInfo,
                                                 Decoded_VkDescriptorImageInfo*  metaInfo,
                                                 VulkanCppConsumerBase&          consumer)
{
    std::stringstream struct_body;

    DescriptorBaseType desc_base_type = GetDescriptorBaseType(templateEntry.descriptorType);
    if (desc_base_type == DESCRIPTOR_BASE_TYPE_SAMPLER || desc_base_type == DESCRIPTOR_BASE_TYPE_COMBINED_IMAGE_SAMPLER)
    {
        struct_body << "\t\t\t" << consumer.GetHandle(metaInfo->sampler) << ",";
    }
    else
    {
        struct_body << "\t\t\t"
                    << "VK_NULL_HANDLE"
                    << ",";
    }

    if (desc_base_type != DESCRIPTOR_BASE_TYPE_SAMPLER)
    {
        struct_body << std::endl;
        struct_body << "\t\t\t" << consumer.GetHandle(metaInfo->imageView) << "," << std::endl;
        struct_body << "\t\t\t"
                    << "VkImageLayout(" << structInfo->imageLayout << "),";
    }

    std::string variable_name = consumer.AddStruct(struct_body, "descriptorImageInfo");
    out << "\t\tVkDescriptorImageInfo " << variable_name << " {" << std::endl;
    out << struct_body.str() << std::endl;
    out << "\t\t};" << std::endl;

    return variable_name;
}

std::string GenerateStruct_VkDescriptorUpdateTemplateEntry(std::ostream&                            out,
                                                           const VkDescriptorUpdateTemplateEntry*   structInfo,
                                                           Decoded_VkDescriptorUpdateTemplateEntry* metaInfo,
                                                           VulkanCppConsumerBase&                   consumer)
{
    std::stringstream struct_body;
    // dstBinding
    struct_body << "\t\t\t" << structInfo->dstBinding << "," << std::endl;
    // dstArrayElement
    struct_body << "\t\t\t" << structInfo->dstArrayElement << "," << std::endl;
    // descriptorCount
    struct_body << "\t\t\t" << structInfo->descriptorCount << "," << std::endl;
    // descriptorType
    struct_body << "\t\t\t"
                << "VkDescriptorType(" << structInfo->descriptorType << ")"
                << "," << std::endl;
    // offset
    struct_body << "\t\t\t" << structInfo->offset << "," << std::endl;
    // stride
    struct_body << "\t\t\t" << structInfo->stride << ",";

    std::string variable_name = consumer.AddStruct(struct_body, "descriptorUpdateTemplateEntry");
    out << "\t\tVkDescriptorUpdateTemplateEntry " << variable_name << " {" << std::endl;
    out << struct_body.str() << std::endl;
    out << "\t\t};" << std::endl;

    return variable_name;
}

std::string
GenerateStruct_VkAccelerationStructureMotionInstanceNV(std::ostream&                                    out,
                                                       const VkAccelerationStructureMotionInstanceNV*   structInfo,
                                                       Decoded_VkAccelerationStructureMotionInstanceNV* metaInfo,
                                                       VulkanCppConsumerBase&                           consumer)
{
    std::stringstream struct_body;
    std::string       accel_struct_inst_variable = GenerateStruct_VkAccelerationStructureInstanceKHR(
        out, &structInfo->data.staticInstance, metaInfo->staticInstance, consumer);
    // type
    struct_body << "\t\t\t"
                << "VkAccelerationStructureMotionInstanceTypeNV(" << structInfo->type << ")"
                << "," << std::endl;
    // flags
    struct_body << "\t\t\t"
                << "VkAccelerationStructureMotionInstanceFlagsNV(" << structInfo->flags << ")"
                << "," << std::endl;
    // data
    struct_body << "\t\t\t" << accel_struct_inst_variable << ",";

    std::string variable_name = consumer.AddStruct(struct_body, "accelerationStructureMotionInstanceNV");
    out << "\t\tVkAccelerationStructureMotionInstanceNV " << variable_name << " {" << std::endl;
    out << struct_body.str() << std::endl;
    out << "\t\t};" << std::endl;

    return variable_name;
}

std::string GenerateStruct_VkAccelerationStructureGeometryKHR(std::ostream&                               out,
                                                              const VkAccelerationStructureGeometryKHR*   structInfo,
                                                              Decoded_VkAccelerationStructureGeometryKHR* metaInfo,
                                                              VulkanCppConsumerBase&                      consumer)
{
    std::stringstream struct_body;
    std::string       pnext_name        = GenerateExtension(out, structInfo->pNext, metaInfo->pNext, consumer);
    std::string       triangle_geometry = GenerateStruct_VkAccelerationStructureGeometryTrianglesDataKHR(
        out, &structInfo->geometry.triangles, metaInfo->geometry->triangles, consumer);
    // sType
    struct_body << "\t\t\t"
                << "VkStructureType(" << structInfo->sType << ")"
                << "," << std::endl;
    // pNext
    struct_body << "\t\t\t" << pnext_name << "," << std::endl;
    // geometryType
    struct_body << "\t\t\t"
                << "VkGeometryTypeKHR(" << structInfo->geometryType << ")"
                << "," << std::endl;
    // geometry
    struct_body << "\t\t\t" << triangle_geometry << "," << std::endl;
    // flags
    struct_body << "\t\t\t"
                << "VkGeometryFlagsKHR(" << structInfo->flags << ")"
                << ",";

    std::string variable_name = consumer.AddStruct(struct_body, "accelerationStructureGeometryKHR");
    out << "\t\t"
        << "VkAccelerationStructureGeometryKHR " << variable_name << " {" << std::endl;
    out << struct_body.str() << std::endl;
    out << "\t\t"
        << "};" << std::endl;

    return variable_name;
}

std::string GenerateStruct_VkDebugUtilsMessengerCreateInfoEXT(std::ostream&                               out,
                                                              const VkDebugUtilsMessengerCreateInfoEXT*   structInfo,
                                                              Decoded_VkDebugUtilsMessengerCreateInfoEXT* metaInfo,
                                                              VulkanCppConsumerBase&                      consumer)
{
    std::stringstream struct_body;
    std::string       pnext_name = GenerateExtension(out, structInfo->pNext, metaInfo->pNext, consumer);
    // sType
    struct_body << "\t\t\t"
                << "VkStructureType(" << structInfo->sType << ")"
                << "," << std::endl;
    // pNext
    struct_body << "\t\t\t" << pnext_name << "," << std::endl;
    // flags
    struct_body << "\t\t\t"
                << "VkDebugUtilsMessengerCreateFlagsEXT(" << structInfo->flags << ")"
                << "," << std::endl;
    // messageSeverity
    struct_body << "\t\t\t"
                << "VkDebugUtilsMessageSeverityFlagsEXT(" << structInfo->messageSeverity << ")"
                << "," << std::endl;
    // messageType
    struct_body << "\t\t\t"
                << "VkDebugUtilsMessageTypeFlagsEXT(" << structInfo->messageType << ")"
                << "," << std::endl;
    // pfnUserCallback
    struct_body << "\t\t\t&vulkanCppDebugUtilsCallback," << std::endl;
    consumer.SetNeedsDebugUtilsCallback(true);
    // pUserData
    struct_body << "\t\t\tnullptr,";

    std::string variable_name = consumer.AddStruct(struct_body, "debugUtilsMessengerCreateInfoEXT");
    out << "\t\tVkDebugUtilsMessengerCreateInfoEXT " << variable_name << " {" << std::endl;
    out << struct_body.str() << std::endl;
    out << "\t\t};" << std::endl;

    return variable_name;
}

std::string GenerateStruct_VkPerformanceValueINTEL(std::ostream&                    out,
                                                   const VkPerformanceValueINTEL*   structInfo,
                                                   Decoded_VkPerformanceValueINTEL* metaInfo,
                                                   VulkanCppConsumerBase&           consumer)
{
    std::stringstream struct_body;
    // type
    struct_body << "\t\t\t"
                << "VkPerformanceValueTypeINTEL(" << structInfo->type << ")"
                << "," << std::endl;
    // data
    struct_body << "\t\t\t" << structInfo->data.value32 << ",";

    std::string variable_name = consumer.AddStruct(struct_body, "performanceValueINTEL");
    out << "\t\tVkPerformanceValueINTEL " << variable_name << " {" << std::endl;
    out << struct_body.str() << std::endl;
    out << "\t\t};" << std::endl;

    return variable_name;
}

std::string
GenerateStruct_VkImportAndroidHardwareBufferInfoANDROID(std::ostream&                                     out,
                                                        const VkImportAndroidHardwareBufferInfoANDROID*   structInfo,
                                                        Decoded_VkImportAndroidHardwareBufferInfoANDROID* metaInfo,
                                                        VulkanCppConsumerBase&                            consumer)
{
    std::stringstream struct_body;
    std::string       pnext_name = GenerateExtension(out, structInfo->pNext, metaInfo->pNext, consumer);
    // sType
    struct_body << "\t"
                << "VkStructureType(" << structInfo->sType << ")"
                << "," << std::endl;
    // pNext
    struct_body << "\t\t\t" << pnext_name << "," << std::endl;
    // buffer
    struct_body << "\t\t\t" << consumer.GetAndroidHwBufferName(metaInfo->buffer) << ",";
    std::string variable_name = consumer.AddStruct(struct_body, "importAndroidHardwareBufferInfoANDROID");
    out << "\t\t"
        << "VkImportAndroidHardwareBufferInfoANDROID " << variable_name << " {" << std::endl;
    out << "\t\t" << struct_body.str() << std::endl;
    out << "\t\t"
        << "};" << std::endl;
    return variable_name;
}

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)
