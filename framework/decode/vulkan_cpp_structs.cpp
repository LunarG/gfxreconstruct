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
        case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK:
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

// At replay time, there will be no external semaphores, so remove any external
// semaphores that have been imported from the list during replay.
void StripImportedSemaphores(std::ostream&                        out,
                             uint32_t&                            count,
                             const format::HandleId*              semaphore_array,
                             const VkPipelineStageFlags*          wait_flags,
                             const std::vector<format::HandleId>& imported_semaphores,
                             VulkanCppConsumerBase&               consumer,
                             std::string&                         semaphore_array_name,
                             std::string*                         wait_flags_array_name)
{
    // Start by setting the arrays to NULL.  This is the fallback in case there are either
    // no semaphores passed in, or they are all imported.
    semaphore_array_name = "NULL";
    if (wait_flags_array_name != nullptr)
    {
        *wait_flags_array_name = "NULL";
    }

    if (semaphore_array != nullptr && count > 0)
    {
        uint32_t new_count         = 0;
        bool     update_wait_flags = (wait_flags != nullptr && wait_flags_array_name != nullptr);

        std::stringstream semaphore_handle_stream;
        std::string       wait_dst_flags_values;
        for (uint32_t sem = 0; sem < count; ++sem)
        {
            // Check each semaphore, if it is not found in the imported array, add it to the list
            // of final semaphores.
            const format::HandleId current = semaphore_array[sem];
            auto                   it      = std::find(imported_semaphores.begin(), imported_semaphores.end(), current);
            if (it == imported_semaphores.end())
            {
                semaphore_handle_stream << consumer.GetHandle(current) << ", ";
                new_count++;

                // Add the Wait Destination target flags if present for this semaphore as well.
                if (update_wait_flags)
                {
                    wait_dst_flags_values += util::ToString<VkPipelineStageFlags>(wait_flags[sem]) + ", ";
                }
            }
        }

        // Create the array of semaphores for use by the code following this removal call.
        if (new_count > 0)
        {
            semaphore_array_name = "semaphores_array_" + std::to_string(consumer.GetNextId(VK_OBJECT_TYPE_SEMAPHORE));
            out << "\t\t"
                << "VkSemaphore " << semaphore_array_name << "[] = {" << semaphore_handle_stream.str() << "};"
                << std::endl;
            if (update_wait_flags)
            {
                *wait_flags_array_name = "dst_stg_masks_" + std::to_string(consumer.GetNextId());
                out << "\t\t"
                    << "VkPipelineStageFlags " << *wait_flags_array_name << "[] = {" << wait_dst_flags_values << "};"
                    << std::endl;
            }
        }
        count = new_count;
    }
}

// At replay time, there will be no external semaphores, so remove any external
// SemaphoreInfo for semaphores that have been imported from the list during replay.
void StripImportedSemaphoreInfos(std::ostream&                        out,
                                 uint32_t&                            count,
                                 const VkSemaphoreSubmitInfo*         semaphore_info_array,
                                 Decoded_VkSemaphoreSubmitInfo*       semaphore_info_meta,
                                 const std::vector<format::HandleId>& imported_semaphores,
                                 VulkanCppConsumerBase&               consumer,
                                 std::string&                         semaphore_info_array_name)
{
    // Start by setting the array to NULL.  This is the fallback in case there are either
    // no semaphores passed in, or they are all imported.
    semaphore_info_array_name = "NULL";

    if (count > 0 && semaphore_info_array != nullptr && semaphore_info_meta != nullptr)
    {
        uint32_t    new_count = 0;
        std::string variable_name_array_values;

        for (uint32_t sem = 0; sem < count; ++sem)
        {
            // Check each semaphore, if it is not found in the imported array, add it to the list
            // of final semaphores.
            std::string            variable_name = "NULL";
            const format::HandleId current       = semaphore_info_meta[sem].semaphore;
            auto                   it = std::find(imported_semaphores.begin(), imported_semaphores.end(), current);
            if (it == imported_semaphores.end())
            {
                variable_name = GenerateStruct_VkSemaphoreSubmitInfo(
                    out, semaphore_info_array + sem, semaphore_info_meta + sem, consumer);
                variable_name_array_values += variable_name + ", ";
                new_count++;
            }
        }

        // Create the array of semaphores for use by the code following this removal call.
        if (new_count > 0)
        {
            semaphore_info_array_name =
                "semaphores_array_" + std::to_string(consumer.GetNextId(VK_OBJECT_TYPE_SEMAPHORE));

            out << "\t\t"
                << "VkSemaphoreSubmitInfo " << semaphore_info_array_name << "[] = {" << variable_name_array_values
                << "};" << std::endl;
        }
        count = new_count;
    }
}

std::string GenerateStruct_VkSubmitInfo(std::ostream&                        out,
                                        const VkSubmitInfo*                  structInfo,
                                        Decoded_VkSubmitInfo*                metaInfo,
                                        const std::vector<format::HandleId>& imported_semaphores,
                                        VulkanCppConsumerBase&               consumer)
{
    std::stringstream struct_body;
    std::string       pnext_name = GenerateExtension(out, structInfo->pNext, metaInfo->pNext, consumer);

    std::string wait_semaphores_array_name     = "NULL";
    std::string wait_dst_stage_mask_array_name = "NULL";
    std::string signal_semaphores_array_name   = "NULL";
    uint32_t    wait_semaphores_count          = structInfo->waitSemaphoreCount;
    uint32_t    signal_semaphores_count        = structInfo->signalSemaphoreCount;
    if (metaInfo->pWaitSemaphores.GetPointer() != NULL && structInfo->waitSemaphoreCount > 0)
    {
        StripImportedSemaphores(out,
                                wait_semaphores_count,
                                metaInfo->pWaitSemaphores.GetPointer(),
                                structInfo->pWaitDstStageMask,
                                imported_semaphores,
                                consumer,
                                wait_semaphores_array_name,
                                &wait_dst_stage_mask_array_name);
    }
    if (metaInfo->pSignalSemaphores.GetPointer() != NULL && structInfo->signalSemaphoreCount > 0)
    {
        StripImportedSemaphores(out,
                                signal_semaphores_count,
                                metaInfo->pSignalSemaphores.GetPointer(),
                                nullptr,
                                imported_semaphores,
                                consumer,
                                signal_semaphores_array_name,
                                nullptr);
    }

    std::string command_buffers_array = "NULL";
    if (metaInfo->pCommandBuffers.GetPointer() != NULL && structInfo->commandBufferCount > 0)
    {
        command_buffers_array =
            "command_buffers_array_" + std::to_string(consumer.GetNextId(VK_OBJECT_TYPE_COMMAND_BUFFER));
        std::string command_buffers_values = toStringJoin(
            metaInfo->pCommandBuffers.GetPointer(),
            metaInfo->pCommandBuffers.GetPointer() + structInfo->commandBufferCount,
            [&](const format::HandleId current) { return consumer.GetHandle(current); },
            ", ");
        if (structInfo->commandBufferCount > 0)
        {
            out << "\t\t"
                << "VkCommandBuffer " << command_buffers_array << "[] = {" << command_buffers_values << "};"
                << std::endl;
        }
    }
    // sType
    struct_body << "\t"
                << "VkStructureType(" << structInfo->sType << ")"
                << "," << std::endl;
    // pNext
    struct_body << "\t\t\t" << pnext_name << "," << std::endl;
    // waitSemaphoreCount
    struct_body << "\t\t\t" << wait_semaphores_count << "," << std::endl;
    // pWaitSemaphores
    struct_body << "\t\t\t" << wait_semaphores_array_name << "," << std::endl;
    // pWaitDstStageMask
    struct_body << "\t\t\t" << wait_dst_stage_mask_array_name << "," << std::endl;
    // commandBufferCount
    struct_body << "\t\t\t" << structInfo->commandBufferCount << "," << std::endl;
    // pCommandBuffers
    struct_body << "\t\t\t" << command_buffers_array << "," << std::endl;
    // signalSemaphoreCount
    struct_body << "\t\t\t" << signal_semaphores_count << "," << std::endl;
    // pSignalSemaphores
    struct_body << "\t\t\t" << signal_semaphores_array_name << ",";
    std::string variable_name = consumer.AddStruct(struct_body, "submitInfo");
    out << "\t\t"
        << "VkSubmitInfo " << variable_name << " {" << std::endl;
    out << "\t\t" << struct_body.str() << std::endl;
    out << "\t\t"
        << "};" << std::endl;
    return variable_name;
}

std::string GenerateStruct_VkSubmitInfo2(std::ostream&                        out,
                                         const VkSubmitInfo2*                 structInfo,
                                         Decoded_VkSubmitInfo2*               metaInfo,
                                         const std::vector<format::HandleId>& imported_semaphores,
                                         VulkanCppConsumerBase&               consumer)
{
    std::stringstream struct_body;
    std::string       pnext_name = GenerateExtension(out, structInfo->pNext, metaInfo->pNext, consumer);
    std::string       wait_semaphore_infos_array_name   = "NULL";
    std::string       signal_semaphore_infos_array_name = "NULL";
    uint32_t          wait_semaphore_infos_count        = structInfo->waitSemaphoreInfoCount;
    uint32_t          signal_semaphore_infos_count      = structInfo->signalSemaphoreInfoCount;
    if (structInfo->pWaitSemaphoreInfos != NULL)
    {
        StripImportedSemaphoreInfos(out,
                                    wait_semaphore_infos_count,
                                    structInfo->pWaitSemaphoreInfos,
                                    metaInfo->pWaitSemaphoreInfos->GetMetaStructPointer(),
                                    imported_semaphores,
                                    consumer,
                                    wait_semaphore_infos_array_name);
    }
    if (structInfo->pSignalSemaphoreInfos != NULL)
    {
        StripImportedSemaphoreInfos(out,
                                    signal_semaphore_infos_count,
                                    structInfo->pSignalSemaphoreInfos,
                                    metaInfo->pSignalSemaphoreInfos->GetMetaStructPointer(),
                                    imported_semaphores,
                                    consumer,
                                    signal_semaphore_infos_array_name);
    }

    std::string command_buffer_infos_array = "NULL";
    if (structInfo->pCommandBufferInfos != NULL)
    {
        command_buffer_infos_array = "cmd_buffer_infos_" + std::to_string(consumer.GetNextId());
        std::string command_buffer_infos_names;
        for (uint32_t idx = 0; idx < structInfo->commandBufferInfoCount; idx++)
        {
            std::string variable_name = "NULL";
            if (structInfo->pCommandBufferInfos + idx != NULL)
            {
                variable_name = GenerateStruct_VkCommandBufferSubmitInfo(
                    out,
                    structInfo->pCommandBufferInfos + idx,
                    metaInfo->pCommandBufferInfos->GetMetaStructPointer() + idx,
                    consumer);
            }
            command_buffer_infos_names += variable_name + ", ";
        }
        out << "\t\t"
            << "VkCommandBufferSubmitInfo " << command_buffer_infos_array << "[] = {" << command_buffer_infos_names
            << "};" << std::endl;
    }

    // sType
    struct_body << "\t"
                << "VkStructureType(" << structInfo->sType << ")"
                << "," << std::endl;
    // pNext
    struct_body << "\t\t\t" << pnext_name << "," << std::endl;
    // flags
    struct_body << "\t\t\t"
                << "VkSubmitFlags(" << structInfo->flags << ")"
                << "," << std::endl;
    // waitSemaphoreInfoCount
    struct_body << "\t\t\t" << structInfo->waitSemaphoreInfoCount << "," << std::endl;
    // pWaitSemaphoreInfos
    struct_body << "\t\t\t" << wait_semaphore_infos_array_name << "," << std::endl;
    // commandBufferInfoCount
    struct_body << "\t\t\t" << wait_semaphore_infos_count << "," << std::endl;
    // pCommandBufferInfos
    struct_body << "\t\t\t" << command_buffer_infos_array << "," << std::endl;
    // signalSemaphoreInfoCount
    struct_body << "\t\t\t" << structInfo->signalSemaphoreInfoCount << "," << std::endl;
    // pSignalSemaphoreInfos
    struct_body << "\t\t\t" << signal_semaphore_infos_array_name << ",";
    std::string variable_name = consumer.AddStruct(struct_body, "submitInfo2");
    out << "\t\t"
        << "VkSubmitInfo2 " << variable_name << " {" << std::endl;
    out << "\t\t" << struct_body.str() << std::endl;
    out << "\t\t"
        << "};" << std::endl;
    return variable_name;
}

std::string GenerateStruct_VkBindSparseInfo(std::ostream&                        out,
                                            const VkBindSparseInfo*              structInfo,
                                            Decoded_VkBindSparseInfo*            metaInfo,
                                            const std::vector<format::HandleId>& imported_semaphores,
                                            VulkanCppConsumerBase&               consumer)
{
    std::stringstream struct_body;
    std::string       pnext_name = GenerateExtension(out, structInfo->pNext, metaInfo->pNext, consumer);

    std::string wait_semaphores_array_name   = "NULL";
    uint32_t    wait_semaphores_count        = structInfo->waitSemaphoreCount;
    std::string signal_semaphores_array_name = "NULL";
    uint32_t    signal_semaphores_count      = structInfo->signalSemaphoreCount;
    if (metaInfo->pWaitSemaphores.GetPointer() != NULL && structInfo->waitSemaphoreCount > 0)
    {
        StripImportedSemaphores(out,
                                wait_semaphores_count,
                                metaInfo->pWaitSemaphores.GetPointer(),
                                nullptr,
                                imported_semaphores,
                                consumer,
                                wait_semaphores_array_name,
                                nullptr);
    }
    if (metaInfo->pSignalSemaphores.GetPointer() != NULL && structInfo->signalSemaphoreCount > 0)
    {
        StripImportedSemaphores(out,
                                signal_semaphores_count,
                                metaInfo->pSignalSemaphores.GetPointer(),
                                nullptr,
                                imported_semaphores,
                                consumer,
                                signal_semaphores_array_name,
                                nullptr);
    }

    std::string buffer_binds_array = "NULL";
    if (structInfo->pBufferBinds != NULL)
    {
        buffer_binds_array = "buffer_binds_" + std::to_string(consumer.GetNextId());
        std::string buffer_binds_names;
        for (uint32_t idx = 0; idx < structInfo->bufferBindCount; idx++)
        {
            std::string variable_name = "NULL";
            if (structInfo->pBufferBinds + idx != NULL)
            {
                variable_name =
                    GenerateStruct_VkSparseBufferMemoryBindInfo(out,
                                                                structInfo->pBufferBinds + idx,
                                                                metaInfo->pBufferBinds->GetMetaStructPointer() + idx,
                                                                consumer);
            }
            buffer_binds_names += variable_name + ", ";
        }
        out << "\t\t"
            << "VkSparseBufferMemoryBindInfo " << buffer_binds_array << "[] = {" << buffer_binds_names << "};"
            << std::endl;
    }
    std::string image_opaque_binds_array = "NULL";
    if (structInfo->pImageOpaqueBinds != NULL)
    {
        image_opaque_binds_array = "image_opaque_binds_" + std::to_string(consumer.GetNextId());
        std::string image_opaque_binds_names;
        for (uint32_t idx = 0; idx < structInfo->imageOpaqueBindCount; idx++)
        {
            std::string variable_name = "NULL";
            if (structInfo->pImageOpaqueBinds + idx != NULL)
            {
                variable_name = GenerateStruct_VkSparseImageOpaqueMemoryBindInfo(
                    out,
                    structInfo->pImageOpaqueBinds + idx,
                    metaInfo->pImageOpaqueBinds->GetMetaStructPointer() + idx,
                    consumer);
            }
            image_opaque_binds_names += variable_name + ", ";
        }
        out << "\t\t"
            << "VkSparseImageOpaqueMemoryBindInfo " << image_opaque_binds_array << "[] = {" << image_opaque_binds_names
            << "};" << std::endl;
    }
    std::string image_binds_array = "NULL";
    if (structInfo->pImageBinds != NULL)
    {
        image_binds_array = "pImageBinds_" + std::to_string(consumer.GetNextId());
        std::string image_binds_names;
        for (uint32_t idx = 0; idx < structInfo->imageBindCount; idx++)
        {
            std::string variable_name = "NULL";
            if (structInfo->pImageBinds + idx != NULL)
            {
                variable_name = GenerateStruct_VkSparseImageMemoryBindInfo(
                    out, structInfo->pImageBinds + idx, metaInfo->pImageBinds->GetMetaStructPointer() + idx, consumer);
            }
            image_binds_names += variable_name + ", ";
        }
        out << "\t\t"
            << "VkSparseImageMemoryBindInfo " << image_binds_array << "[] = {" << image_binds_names << "};"
            << std::endl;
    }

    // sType
    struct_body << "\t"
                << "VkStructureType(" << structInfo->sType << ")"
                << "," << std::endl;
    // pNext
    struct_body << "\t\t\t" << pnext_name << "," << std::endl;
    // waitSemaphoreCount
    struct_body << "\t\t\t" << wait_semaphores_count << "," << std::endl;
    // pWaitSemaphores
    struct_body << "\t\t\t" << wait_semaphores_array_name << "," << std::endl;
    // bufferBindCount
    struct_body << "\t\t\t" << structInfo->bufferBindCount << "," << std::endl;
    // pBufferBinds
    struct_body << "\t\t\t" << buffer_binds_array << "," << std::endl;
    // imageOpaqueBindCount
    struct_body << "\t\t\t" << structInfo->imageOpaqueBindCount << "," << std::endl;
    // pImageOpaqueBinds
    struct_body << "\t\t\t" << image_opaque_binds_array << "," << std::endl;
    // imageBindCount
    struct_body << "\t\t\t" << structInfo->imageBindCount << "," << std::endl;
    // pImageBinds
    struct_body << "\t\t\t" << image_binds_array << "," << std::endl;
    // signalSemaphoreCount
    struct_body << "\t\t\t" << signal_semaphores_count << "," << std::endl;
    // pSignalSemaphores
    struct_body << "\t\t\t" << signal_semaphores_array_name << ",";
    std::string variable_name = consumer.AddStruct(struct_body, "bindSparseInfo");
    out << "\t\t"
        << "VkBindSparseInfo " << variable_name << " {" << std::endl;
    out << "\t\t" << struct_body.str() << std::endl;
    out << "\t\t"
        << "};" << std::endl;
    return variable_name;
}

std::string GenerateStruct_VkSwapchainCreateInfoKHR(std::ostream&                     out,
                                                    const VkSwapchainCreateInfoKHR*   structInfo,
                                                    Decoded_VkSwapchainCreateInfoKHR* metaInfo,
                                                    VulkanCppConsumerBase&            consumer)
{
    std::stringstream struct_body;
    std::string       pnext_name = GenerateExtension(out, structInfo->pNext, metaInfo->pNext, consumer);
    std::string       image_extent_info_var =
        GenerateStruct_VkExtent2D(out, &structInfo->imageExtent, metaInfo->imageExtent, consumer);
    std::string pqueue_family_indices_array = "NULL";
    if (structInfo->pQueueFamilyIndices != NULL)
    {
        pqueue_family_indices_array = "pQueueFamilyIndices_" + std::to_string(consumer.GetNextId());
        out << "\t\t"
            << "uint32_t " << pqueue_family_indices_array << "[] = "
            << VulkanCppConsumerBase::BuildValue(structInfo->pQueueFamilyIndices, structInfo->queueFamilyIndexCount)
            << ";" << std::endl;
    }
    // sType
    struct_body << "\t"
                << "VkStructureType(" << structInfo->sType << ")"
                << "," << std::endl;
    // pNext
    struct_body << "\t\t\t" << pnext_name << "," << std::endl;
    // flags
    struct_body << "\t\t\t"
                << "VkSwapchainCreateFlagsKHR(" << structInfo->flags << ")"
                << "," << std::endl;
    // surface
    struct_body << "\t\t\t" << consumer.GetHandle(metaInfo->surface) << "," << std::endl;
    // minImageCount
    struct_body << "\t\t\t" << structInfo->minImageCount << "," << std::endl;
    // imageFormat
    struct_body << "\t\t\t"
                << "VkFormat(" << structInfo->imageFormat << ")"
                << "," << std::endl;
    // imageColorSpace
    struct_body << "\t\t\t"
                << "VkColorSpaceKHR(" << structInfo->imageColorSpace << ")"
                << "," << std::endl;
    // imageExtent
    struct_body << "\t\t\t" << image_extent_info_var << "," << std::endl;
    // imageArrayLayers
    struct_body << "\t\t\t" << structInfo->imageArrayLayers << "," << std::endl;
    // imageUsage
    struct_body << "\t\t\t"
                << "VkImageUsageFlags(" << structInfo->imageUsage << ")"
                << "," << std::endl;
    // imageSharingMode
    struct_body << "\t\t\t"
                << "VkSharingMode(" << structInfo->imageSharingMode << ")"
                << "," << std::endl;
    // queueFamilyIndexCount
    struct_body << "\t\t\t" << structInfo->queueFamilyIndexCount << "," << std::endl;
    // pQueueFamilyIndices
    struct_body << "\t\t\t" << pqueue_family_indices_array << "," << std::endl;
    // preTransform
    struct_body << "\t\t\t"
                << "VkSurfaceTransformFlagBitsKHR(" << structInfo->preTransform << ")"
                << "," << std::endl;
    // compositeAlpha
    struct_body << "\t\t\t"
                << "VkCompositeAlphaFlagBitsKHR(" << structInfo->compositeAlpha << ")"
                << "," << std::endl;
    // presentMode
    struct_body << "\t\t\t"
                << "VkPresentModeKHR(" << structInfo->presentMode << ")"
                << "," << std::endl;
    // clipped
    struct_body << "\t\t\t" << structInfo->clipped << "," << std::endl;
    // oldSwapchain
    struct_body << "\t\t\t" << consumer.GetHandle(metaInfo->oldSwapchain) << ",";
    std::string variable_name = consumer.AddStruct(struct_body, "swapchainCreateInfoKHR");
    out << "\t\t"
        << "VkSwapchainCreateInfoKHR " << variable_name << " {" << std::endl;
    out << "\t\t" << struct_body.str() << std::endl;
    out << "\t\t"
        << "};" << std::endl;
    return variable_name;
}

std::string GenerateStruct_VkPresentInfoKHR(std::ostream&                        out,
                                            const VkPresentInfoKHR*              structInfo,
                                            Decoded_VkPresentInfoKHR*            metaInfo,
                                            const std::vector<format::HandleId>& imported_semaphores,
                                            VulkanCppConsumerBase&               consumer)
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
            image_array_indices = "image_indices_" + std::to_string(consumer.GetNextId());
            swapchains_array    = "swapchains_array_" + std::to_string(consumer.GetNextId());

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
    uint32_t    wait_semaphores_count       = structInfo->waitSemaphoreCount;
    if (metaInfo->pWaitSemaphores.GetPointer() != NULL && structInfo->waitSemaphoreCount > 0)
    {
        StripImportedSemaphores(out,
                                wait_semaphores_count,
                                metaInfo->pWaitSemaphores.GetPointer(),
                                nullptr,
                                imported_semaphores,
                                consumer,
                                wait_semaphore_array_string,
                                nullptr);
    }

    std::stringstream struct_body;
    struct_body << "\t\t\t"
                << "VkStructureType(" << structInfo->sType << ")"
                << "," << std::endl;
    // pNext
    std::string pnext_name = GenerateExtension(out, structInfo->pNext, metaInfo->pNext, consumer);
    struct_body << "\t\t\t" << pnext_name << "," << std::endl;
    struct_body << "\t\t\t" << wait_semaphores_count << "," << std::endl;
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

std::string GenerateStruct_VkMemoryAllocateFlagsInfo(std::ostream&                      out,
                                                     const VkMemoryAllocateFlagsInfo*   structInfo,
                                                     Decoded_VkMemoryAllocateFlagsInfo* metaInfo,
                                                     VulkanCppConsumerBase&             consumer)
{
    std::stringstream struct_body;
    std::string       pnext_name = GenerateExtension(out, structInfo->pNext, metaInfo->pNext, consumer);
    // sType
    struct_body << "\t"
                << "VkStructureType(" << structInfo->sType << ")"
                << "," << std::endl;
    // pNext
    struct_body << "\t\t\t" << pnext_name << "," << std::endl;
    // flags
    struct_body << "\t\t\t"
                << "VkMemoryAllocateFlags(" << structInfo->flags << ")"
                << "," << std::endl;
    // deviceMask
    struct_body << "\t\t\t" << structInfo->deviceMask << ",";
    std::string variable_name = consumer.AddStruct(struct_body, "memoryAllocateFlagsInfo");
    out << "\t\t"
        << "VkMemoryAllocateFlagsInfo " << variable_name << " {" << std::endl;
    out << "\t\t" << struct_body.str() << std::endl;
    out << "\t\t"
        << "};" << std::endl;

    // If we're using opaque addresses and this memory allocation we're on right now is
    // using an opaque address, we need to add a flag to indicate we're using one.
    out << "\t\tif (can_use_opaque_address) {" << std::endl;
    out << "\t\t\tuses_opaque_address = true;" << std::endl;
    out << "\t\t\t" << variable_name << ".flags |= VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT;" << std::endl;
    out << "\t\t}" << std::endl;

    return variable_name;
}

std::string GenerateStruct_VkImportMemoryHostPointerInfoEXT(std::ostream&                             out,
                                                            const VkImportMemoryHostPointerInfoEXT*   structInfo,
                                                            Decoded_VkImportMemoryHostPointerInfoEXT* metaInfo,
                                                            VulkanCppConsumerBase&                    consumer)
{
    std::stringstream struct_body;
    std::string       pnext_name = GenerateExtension(out, structInfo->pNext, metaInfo->pNext, consumer);
    // sType
    struct_body << "\t"
                << "VkStructureType(" << structInfo->sType << ")"
                << "," << std::endl;
    // pNext
    struct_body << "\t\t\t" << pnext_name << "," << std::endl;
    // handleType
    struct_body << "\t\t\t"
                << "VkExternalMemoryHandleTypeFlagBits(" << structInfo->handleType << ")"
                << "," << std::endl;
    // pHostPointer
    out << "\t\t"
        << "// TODO: Support pHostPointer (output?) argument." << std::endl;
    std::string variable_name = consumer.AddStruct(struct_body, "importMemoryHostPointerInfoEXT");
    out << "\t\t"
        << "VkImportMemoryHostPointerInfoEXT " << variable_name << " {" << std::endl;
    out << "\t\t" << struct_body.str() << std::endl;
    out << "\t\t"
        << "};" << std::endl;

    // If we're using opaque addresses and this memory allocation we're on right now is
    // using an opaque address, we need to flag this as importing memory as well so we
    // set the proper address.
    out << "\t\tif (can_use_opaque_address) {" << std::endl;
    out << "\t\t\timports_memory = true;" << std::endl;
    out << "\t\t}" << std::endl;

    return variable_name;
}

std::string GenerateStruct_VkIndirectExecutionSetCreateInfoEXT(std::ostream&                                out,
                                                               const VkIndirectExecutionSetCreateInfoEXT*   structInfo,
                                                               Decoded_VkIndirectExecutionSetCreateInfoEXT* metaInfo,
                                                               VulkanCppConsumerBase&                       consumer)
{
    std::stringstream struct_body;
    std::string       pnext_name = GenerateExtension(out, structInfo->pNext, metaInfo->pNext, consumer);
    // sType
    struct_body << "\t" << "VkStructureType(" << structInfo->sType << ")" << std::endl;
    // pNext
    struct_body << "\t\t\t" << pnext_name << "," << std::endl;
    // type
    struct_body << "\t\t\t" << "VkIndirectExecutionSetInfoTypeEXT(" << structInfo->type << ")" << std::endl;
    // info
    switch (metaInfo->decoded_type)
    {
        case VK_INDIRECT_EXECUTION_SET_INFO_TYPE_PIPELINES_EXT:
            struct_body << "\t\t\t" << "VkIndirectExecutionSetInfoEXT(" << structInfo->info.pPipelineInfo << ")"
                        << std::endl;
            break;
        case VK_INDIRECT_EXECUTION_SET_INFO_TYPE_SHADER_OBJECTS_EXT:
            struct_body << "\t\t\t" << "VkIndirectExecutionSetInfoEXT(" << structInfo->info.pShaderInfo << ")"
                        << std::endl;
            break;
    }

    out << "\t";
    std::string variable_name = consumer.AddStruct(struct_body, "type");
    out << "VkIndirectExecutionSetInfoTypeEXT " << variable_name << " {" << std::endl;

    return variable_name;
}

std::string GenerateStruct_VkIndirectCommandsLayoutTokenEXT(std::ostream&                             out,
                                                            const VkIndirectCommandsLayoutTokenEXT*   structInfo,
                                                            Decoded_VkIndirectCommandsLayoutTokenEXT* metaInfo,
                                                            VulkanCppConsumerBase&                    consumer)
{
    std::stringstream struct_body;
    std::string       pnext_name = GenerateExtension(out, structInfo->pNext, metaInfo->pNext, consumer);
    // sType
    struct_body << "\t" << "VkStructureType(" << structInfo->sType << ")" << std::endl;
    // pNext
    struct_body << "\t\t\t" << pnext_name << "," << std::endl;
    // type
    struct_body << "\t\t\t" << "VkIndirectCommandsTokenTypeEXT(" << structInfo->type << ")" << std::endl;
    // data
    switch (metaInfo->decoded_type)
    {
        case VK_INDIRECT_COMMANDS_TOKEN_TYPE_PUSH_CONSTANT_EXT:
            struct_body << "\t\t\t" << "VkIndirectCommandsTokenDataEXT(" << structInfo->data.pPushConstant << ")"
                        << std::endl;
            break;
        case VK_INDIRECT_COMMANDS_TOKEN_TYPE_VERTEX_BUFFER_EXT:
            struct_body << "\t\t\t" << "VkIndirectCommandsTokenDataEXT(" << structInfo->data.pVertexBuffer << ")"
                        << std::endl;
            break;
        case VK_INDIRECT_COMMANDS_TOKEN_TYPE_INDEX_BUFFER_EXT:
            struct_body << "\t\t\t" << "VkIndirectCommandsTokenDataEXT(" << structInfo->data.pIndexBuffer << ")"
                        << std::endl;
            break;
        case VK_INDIRECT_COMMANDS_TOKEN_TYPE_EXECUTION_SET_EXT:
            struct_body << "\t\t\t" << "VkIndirectCommandsTokenDataEXT(" << structInfo->data.pExecutionSet << ")"
                        << std::endl;
            break;
    }
    // offset
    struct_body << "\t\t\t" << "uint32_t(" << structInfo->offset << ")" << std::endl;

    out << "\t";
    std::string variable_name = consumer.AddStruct(struct_body, "type");
    out << "VkIndirectExecutionSetInfoTypeEXT " << variable_name << " {" << std::endl;

    return variable_name;
}

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)
