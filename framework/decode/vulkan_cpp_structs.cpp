//
// Copyright (c) 2021 Samsung
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
                                                Decoded_VkMemoryAllocateInfo* metainfo,
                                                VulkanCppConsumerBase&        consumer)
{

    const std::string& memoryRequirements = consumer.GetResourceMemoryRequirements(memoryHandleId);

    std::stringstream structBody;
    /* sType */
    structBody << "\t"
               << "VkStructureType(" << structInfo->sType << ")"
               << "," << std::endl;
    /* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
    /* allocationSize */
    structBody << "\t"
               << "RecalculateAllocationSize(" << structInfo->allocationSize << "UL"
               << ", " << (memoryRequirements.size() ? memoryRequirements : "{}") << ")"
               << "," << std::endl;
    /* memoryTypeIndex */
    structBody << "\t"
               << "RecalculateMemoryTypeIndex(" << structInfo->memoryTypeIndex << ")"
               << ",";
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length())
    {
        varname = consumer.AddStruct(structBody, "memoryAllocateInfo");
        out << "VkMemoryAllocateInfo " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkClearColorValue(std::ostream&              out,
                                             const VkClearColorValue*   structInfo,
                                             Decoded_VkClearColorValue* metainfo,
                                             VulkanCppConsumerBase&     consumer)
{
    std::stringstream structBody;
    structBody << VulkanCppConsumerBase::BuildValue(*structInfo);

    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length())
    {
        varname = consumer.AddStruct(structBody, "clearColorValue");
        out << "VkClearColorValue " << varname << " = " << structBody.str() << ";" << std::endl;
    }

    return varname;
}

std::string GenerateStruct_VkWriteDescriptorSet(std::ostream&                 out,
                                                const VkWriteDescriptorSet*   structInfo,
                                                Decoded_VkWriteDescriptorSet* metainfo,
                                                VulkanCppConsumerBase&        consumer)
{
    std::stringstream structBody;
    std::stringstream structBodyHeader;

    structBody << "VkStructureType(" << structInfo->sType << ")"
               << "," << std::endl;
    structBody << GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer) << "," << std::endl;
    structBody << consumer.GetHandle(metainfo->dstSet) << "," << std::endl;
    structBody << structInfo->dstBinding << "," << std::endl;
    structBody << structInfo->dstArrayElement << "," << std::endl;
    structBody << structInfo->descriptorCount << "," << std::endl;
    structBody << "VkDescriptorType(" << structInfo->descriptorType << ")"
               << "," << std::endl;

    switch (structInfo->descriptorType)
    {
        case VK_DESCRIPTOR_TYPE_SAMPLER:
        case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
        case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
        case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
        case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
        {
            std::string                    infoValues;
            Decoded_VkDescriptorImageInfo* imageMetaInfos = metainfo->pImageInfo->GetMetaStructPointer();
            VkDescriptorImageInfo*         imageInfos     = metainfo->pImageInfo->GetPointer();
            for (uint32_t idx = 0; idx < structInfo->descriptorCount; idx++)
            {
                std::string samplerValue = "VK_NULL_HANDLE";
                if ((structInfo->descriptorType == VK_DESCRIPTOR_TYPE_SAMPLER) ||
                    (structInfo->descriptorType == VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER))
                {
                    samplerValue = consumer.GetHandle(imageMetaInfos[idx].sampler);
                    assert(samplerValue.length() > 0); /* There should be a sampler in these cases */
                }

                infoValues += "{ " + samplerValue + ", " + consumer.GetHandle(imageMetaInfos[idx].imageView) + ", " +
                              "VkImageLayout(" + std::to_string(static_cast<int>(imageInfos[idx].imageLayout)) + ")" +
                              " }, ";
            }
            std::string pInfoArray = "pImageInfoArray_" + std::to_string(consumer.getNextId());
            structBodyHeader << "VkDescriptorImageInfo " << pInfoArray << "[] = { " << infoValues << " };" << std::endl;
            structBody << pInfoArray << "," << std::endl;
            structBody << "NULL," << std::endl;
            structBody << "NULL," << std::endl;
            break;
        }
        case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
        case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
        case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
        case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
        {
            std::string                     infoValues;
            Decoded_VkDescriptorBufferInfo* bufferMetaInfos = metainfo->pBufferInfo->GetMetaStructPointer();
            VkDescriptorBufferInfo*         bufferInfos     = metainfo->pBufferInfo->GetPointer();
            for (uint32_t idx = 0; idx < structInfo->descriptorCount; idx++)
            {
                infoValues += "{ " + consumer.GetHandle(bufferMetaInfos[idx].buffer) + ", " +
                              std::to_string(bufferInfos[idx].offset) + "UL, " +
                              std::to_string(bufferInfos[idx].range) + "UL " + " }, ";
            }

            std::string pInfoArray = "pBufferInfoArray_" + std::to_string(consumer.getNextId());

            structBodyHeader << "VkDescriptorBufferInfo " << pInfoArray << "[] = { " << infoValues << " };"
                             << std::endl;
            structBody << "NULL," << std::endl;
            structBody << pInfoArray << "," << std::endl;
            structBody << "NULL," << std::endl;
            break;
        }
        case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
        case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
        {
            std::string infoValues;
            for (uint32_t idx = 0; idx < structInfo->descriptorCount; idx++)
            {
                infoValues += consumer.GetHandle(metainfo->pTexelBufferView.GetPointer()[idx]) + ", ";
            }
            std::string pInfoArray = "pTexelBufferViewArray_" + std::to_string(consumer.getNextId());

            structBodyHeader << "VkBufferView " << pInfoArray << "[] = { " << infoValues << " };" << std::endl;
            structBody << "NULL," << std::endl;
            structBody << "NULL," << std::endl;
            structBody << pInfoArray << "," << std::endl;
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

    std::string varname = "vkWriteDescriptorSet_" + std::to_string(consumer.getNextId());
    out << structBodyHeader.str() << std::endl;
    out << "VkWriteDescriptorSet " << varname << " {" << std::endl;
    out << structBody.str();
    out << "};" << std::endl;

    return varname;
}

std::string GenerateStruct_VkPresentInfoKHR(std::ostream&             out,
                                            const VkPresentInfoKHR*   structInfo,
                                            Decoded_VkPresentInfoKHR* metainfo,
                                            VulkanCppConsumerBase&    consumer)
{
    std::string pImageIndicesArray = "NULL";
    std::string pSwapchainsArray   = "NULL";
    if (metainfo->pSwapchains.GetPointer() != NULL)
    {
        const format::HandleId* swapchainArray    = metainfo->pSwapchains.GetPointer();
        std::string             pSwapchainsValues = toStringJoin(
            swapchainArray,
            swapchainArray + structInfo->swapchainCount,
            [&](const format::HandleId current) { return consumer.GetHandle(current); },
            ", ");
        std::string imageIndicesValues = toStringJoin(
            swapchainArray,
            swapchainArray + structInfo->swapchainCount,
            [&](const format::HandleId current) { return consumer.GetNextImage(current); },
            ", ");

        if (structInfo->swapchainCount == 1)
        {
            pSwapchainsArray   = "&" + pSwapchainsValues;
            pImageIndicesArray = "&" + imageIndicesValues;
        }
        else if (structInfo->swapchainCount > 1)
        {
            pImageIndicesArray = "pImageIndices_" + std::to_string(consumer.getNextId());
            pSwapchainsArray   = "pSwapchainsArray_" + std::to_string(consumer.getNextId());

            out << "VkSwapchainKHR " << pSwapchainsArray << "[] = {" << pSwapchainsValues << "};" << std::endl;
            out << "uint32_t " << pImageIndicesArray << "[] = {" << imageIndicesValues << "};" << std::endl;
        }
        else
        {
            /* this should never happen */
        }
    }

    std::string pWaitSemaphoresArray = "NULL";
    if (metainfo->pWaitSemaphores.GetPointer() != NULL)
    {
        const format::HandleId* waitSemaphoresArray   = metainfo->pWaitSemaphores.GetPointer();
        std::string             pWaitSemaphoresValues = toStringJoin(
            waitSemaphoresArray,
            waitSemaphoresArray + structInfo->waitSemaphoreCount,
            [&](const format::HandleId current) { return consumer.GetHandle(current); },
            ", ");

        if (structInfo->swapchainCount == 1)
        {
            pWaitSemaphoresArray = "&" + pWaitSemaphoresValues;
        }
        else if (structInfo->swapchainCount > 1)
        {
            pWaitSemaphoresArray = "pWaitSemaphoresArray_" + std::to_string(consumer.getNextId());

            out << "VkSemaphore " << pWaitSemaphoresArray << "[] = {" << pWaitSemaphoresValues << "};" << std::endl;
        }
    }

    std::stringstream structBody;
    structBody << "VkStructureType(" << structInfo->sType << ")"
               << "," << std::endl;
    /* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << pNextName << "," << std::endl;
    structBody << structInfo->waitSemaphoreCount << "," << std::endl;
    structBody << pWaitSemaphoresArray << "," << std::endl;
    structBody << structInfo->swapchainCount << "," << std::endl;
    structBody << pSwapchainsArray << "," << std::endl;
    structBody << pImageIndicesArray << "," << std::endl;
    structBody << "NULL"
               << "," << std::endl; // Ignore results array from capture

    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length())
    {
        varname = consumer.AddStruct(structBody, "presentInfoKHR");
        out << "VkPresentInfoKHR " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string
GenerateStruct_VkDescriptorUpdateTemplateCreateInfoKHR(std::ostream&                                 out,
                                                       const VkDescriptorUpdateTemplateCreateInfo*   structInfo,
                                                       Decoded_VkDescriptorUpdateTemplateCreateInfo* metainfo,
                                                       VulkanCppConsumerBase&                        consumer,
                                                       const std::string&                            structTypeSuffix)
{
    std::string pDescriptorUpdateEntriesArray = "NULL";
    if (structInfo->pDescriptorUpdateEntries != NULL)
    {
        pDescriptorUpdateEntriesArray = "pDescriptorUpdateEntries_" + std::to_string(consumer.getNextId());

        // Recalculate the offset and stride for each template entry.
        uint32_t imageInfoCount       = 0;
        uint32_t bufferInfoCount      = 0;
        uint32_t texelBufferViewCount = 0;

        const VkDescriptorUpdateTemplateEntry* entries = structInfo->pDescriptorUpdateEntries;

        for (uint32_t idx = 0; idx < structInfo->descriptorUpdateEntryCount; idx++)
        {
            switch (GetDescriptorBaseType(entries[idx].descriptorType))
            {
                case DESCRIPTOR_BASE_TYPE_IMAGE:
                case DESCRIPTOR_BASE_TYPE_SAMPLER:
                case DESCRIPTOR_BASE_TYPE_COMBINED_IMAGE_SAMPLER:
                {
                    imageInfoCount += entries[idx].descriptorCount;
                    break;
                }
                case DESCRIPTOR_BASE_TYPE_BUFFER:
                {
                    bufferInfoCount += entries[idx].descriptorCount;
                    break;
                }
                case DESCRIPTOR_BASE_TYPE_TEXEL:
                {
                    texelBufferViewCount += entries[idx].descriptorCount;
                    break;
                }
                default:
                {
                    assert(false);
                }
            }
        }

        uint32_t imageInfoOffset       = 0;
        uint32_t bufferInfoOffset      = imageInfoCount * sizeof(VkDescriptorImageInfo);
        uint32_t texelBufferViewOffset = bufferInfoOffset + (bufferInfoCount * sizeof(VkDescriptorBufferInfo));

        std::string pDescriptorUpdateEntriesNames;
        for (uint32_t idx = 0; idx < structInfo->descriptorUpdateEntryCount; idx++)
        {
            VkDescriptorUpdateTemplateEntry entry = structInfo->pDescriptorUpdateEntries[idx];

            size_t overrideStride = 0;
            size_t overrideOffset = 0;

            switch (GetDescriptorBaseType(entry.descriptorType))
            {
                case DESCRIPTOR_BASE_TYPE_IMAGE:
                case DESCRIPTOR_BASE_TYPE_SAMPLER:
                case DESCRIPTOR_BASE_TYPE_COMBINED_IMAGE_SAMPLER:
                {
                    overrideStride = sizeof(VkDescriptorImageInfo);
                    overrideOffset = imageInfoOffset;
                    imageInfoOffset += entry.descriptorCount * sizeof(VkDescriptorImageInfo);
                    break;
                }
                case DESCRIPTOR_BASE_TYPE_BUFFER:
                {
                    overrideStride = sizeof(VkDescriptorBufferInfo);
                    overrideOffset = bufferInfoOffset;
                    bufferInfoOffset += entry.descriptorCount * sizeof(VkDescriptorBufferInfo);
                    break;
                }
                case DESCRIPTOR_BASE_TYPE_TEXEL:
                {
                    overrideStride = sizeof(VkBufferView);
                    overrideOffset = texelBufferViewOffset;
                    texelBufferViewOffset += entry.descriptorCount * sizeof(VkBufferView);
                    break;
                }
                default:
                {
                    assert(false);
                }
            }

            entry.offset = overrideOffset;
            entry.stride = overrideStride;

            std::string varName = GenerateStruct_VkDescriptorUpdateTemplateEntry(
                out,
                &entry,
                metainfo->pDescriptorUpdateEntries->GetMetaStructPointer() + idx,
                consumer);
            pDescriptorUpdateEntriesNames += varName + ", ";
        }
        out << "VkDescriptorUpdateTemplateEntry" << structTypeSuffix << " " << pDescriptorUpdateEntriesArray << "[] = {"
            << pDescriptorUpdateEntriesNames << "};" << std::endl;
    }
    std::stringstream structBody;
    /* sType */
    structBody << "\t"
               << "VkStructureType(" << structInfo->sType << ")"
               << "," << std::endl;
    /* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
    /* flags */
    structBody << "\t"
               << "VkDescriptorUpdateTemplateCreateFlags>(" << structInfo->flags << ")"
               << "," << std::endl;
    /* descriptorUpdateEntryCount */
    structBody << "\t" << structInfo->descriptorUpdateEntryCount << "," << std::endl;
    /* pDescriptorUpdateEntries */
    structBody << "\t" << pDescriptorUpdateEntriesArray << "," << std::endl;
    /* templateType */
    structBody << "\t"
               << "VkDescriptorUpdateTemplateType(" << structInfo->templateType << ")"
               << "," << std::endl;
    /* descriptorSetLayout */
    structBody << "\t" << consumer.GetHandle(metainfo->descriptorSetLayout) << "," << std::endl;
    /* pipelineBindPoint */
    structBody << "\t"
               << "VkPipelineBindPoint(" << structInfo->pipelineBindPoint << ")"
               << "," << std::endl;
    /* pipelineLayout */
    structBody << "\t" << consumer.GetHandle(metainfo->pipelineLayout) << "," << std::endl;
    /* set */
    structBody << "\t" << structInfo->set << "," << std::endl;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length())
    {
        varname = consumer.AddStruct(structBody, "descriptorUpdateTemplateCreateInfo");
        out << "VkDescriptorUpdateTemplateCreateInfo" << structTypeSuffix << " " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkDescriptorImageInfo(std::ostream&                   out,
                                                 VkDescriptorUpdateTemplateEntry templateEntry,
                                                 const VkDescriptorImageInfo*    structInfo,
                                                 Decoded_VkDescriptorImageInfo*  metaInfo,
                                                 VulkanCppConsumerBase&          consumer)
{
    std::stringstream structBody;

    DescriptorBaseType descriptorBaseType = GetDescriptorBaseType(templateEntry.descriptorType);
    if (descriptorBaseType == DESCRIPTOR_BASE_TYPE_SAMPLER ||
        descriptorBaseType == DESCRIPTOR_BASE_TYPE_COMBINED_IMAGE_SAMPLER)
    {
        structBody << consumer.GetHandle(metaInfo->sampler) << "," << std::endl;
    }
    else
    {
        structBody << "VK_NULL_HANDLE"
                   << "," << std::endl;
    }

    if (descriptorBaseType != DESCRIPTOR_BASE_TYPE_SAMPLER)
    {
        structBody << consumer.GetHandle(metaInfo->imageView) << "," << std::endl;
        structBody << "VkImageLayout(" << structInfo->imageLayout << ")"
                   << "," << std::endl;
    }

    std::string varName = consumer.GetExistingStruct(structBody);
    if (!varName.length())
    {
        varName = consumer.AddStruct(structBody, "descriptorImageInfo");
        out << "VkDescriptorImageInfo " << varName << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varName;
}

std::string GenerateStruct_VkDescriptorUpdateTemplateEntry(std::ostream&                            out,
                                                           const VkDescriptorUpdateTemplateEntry*   structInfo,
                                                           Decoded_VkDescriptorUpdateTemplateEntry* metainfo,
                                                           VulkanCppConsumerBase&                   consumer)
{
    std::stringstream structBody;
    /* dstBinding */
    structBody << "\t" << structInfo->dstBinding << "," << std::endl;
    /* dstArrayElement */
    structBody << "\t" << structInfo->dstArrayElement << "," << std::endl;
    /* descriptorCount */
    structBody << "\t" << structInfo->descriptorCount << "," << std::endl;
    /* descriptorType */
    structBody << "\t"
               << "VkDescriptorType(" << structInfo->descriptorType << ")"
               << "," << std::endl;
    /* offset */
    structBody << "\t" << structInfo->offset << "," << std::endl;
    /* stride */
    structBody << "\t" << structInfo->stride << ",";
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length())
    {
        varname = consumer.AddStruct(structBody, "descriptorUpdateTemplateEntry");
        out << "VkDescriptorUpdateTemplateEntry " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string
GenerateStruct_VkAccelerationStructureMotionInstanceNV(std::ostream&                                    out,
                                                       const VkAccelerationStructureMotionInstanceNV*   structInfo,
                                                       Decoded_VkAccelerationStructureMotionInstanceNV* metainfo,
                                                       VulkanCppConsumerBase&                           consumer)
{
    std::stringstream structBody;
    std::string       staticInstanceInfoVar = GenerateStruct_VkAccelerationStructureInstanceKHR(
        out, &structInfo->data.staticInstance, metainfo->staticInstance, consumer);
    /* type */
    structBody << "\t"
               << "VkAccelerationStructureMotionInstanceTypeNV(" << structInfo->type << ")"
               << "," << std::endl;
    /* flags */
    structBody << "\t"
               << "VkAccelerationStructureMotionInstanceFlagsNV(" << structInfo->flags << ")"
               << "," << std::endl;
    /* data */
    structBody << "\t" << staticInstanceInfoVar << ",";
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length())
    {
        varname = consumer.AddStruct(structBody, "accelerationStructureMotionInstanceNV");
        out << "VkAccelerationStructureMotionInstanceNV " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkDebugUtilsMessengerCreateInfoEXT(std::ostream&                               out,
                                                              const VkDebugUtilsMessengerCreateInfoEXT*   structInfo,
                                                              Decoded_VkDebugUtilsMessengerCreateInfoEXT* metainfo,
                                                              VulkanCppConsumerBase&                      consumer)
{
    std::stringstream structBody;
    std::string       pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    /* sType */
    structBody << "\t"
               << "VkStructureType(" << structInfo->sType << ")"
               << "," << std::endl;
    /* pNext */
    structBody << "\t" << pNextName << "," << std::endl;
    /* flags */
    structBody << "\t"
               << "VkDebugUtilsMessengerCreateFlagsEXT(" << structInfo->flags << ")"
               << "," << std::endl;
    /* messageSeverity */
    structBody << "\t"
               << "VkDebugUtilsMessageSeverityFlagsEXT(" << structInfo->messageSeverity << ")"
               << "," << std::endl;
    /* messageType */
    structBody << "\t"
               << "VkDebugUtilsMessageTypeFlagsEXT(" << structInfo->messageType << ")"
               << "," << std::endl;
    /* pfnUserCallback */
    structBody << "\t&vulkanCppDebugUtilsCallback," << std::endl;
    consumer.SetNeedsDebugUtilsCallback(true);
    /* pUserData */
    structBody << "\tnullptr," << std::endl;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length())
    {
        varname = consumer.AddStruct(structBody, "debugUtilsMessengerCreateInfoEXT");
        out << "VkDebugUtilsMessengerCreateInfoEXT " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}
GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)
