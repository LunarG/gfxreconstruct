/*
** Copyright (c) 2021 Samsung
**
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

#include "vulkan_cpp_pre_process_consumer_base.h"

#include <iostream>
#include <unordered_set>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

VulkanCppPreProcessConsumerBase::VulkanCppPreProcessConsumerBase() : m_captureWindowWidth(0), m_captureWindowHeight(0)
{}

VulkanCppPreProcessConsumerBase::~VulkanCppPreProcessConsumerBase() {}

bool VulkanCppPreProcessConsumerBase::Initialize()
{
    m_frameNumber      = 0;
    m_frameSplitNumber = 0;
    m_apiCallNumber    = 0;

    return true;
}

void VulkanCppPreProcessConsumerBase::Post_APICall(format::ApiCallId callId)
{
    // Replicate FileProcessor's frame counter increment process
    if (callId == format::ApiCallId::ApiCall_vkQueuePresentKHR)
    {
        m_frameSplitNumber = 0;
        m_frameNumber++;
    }
    else if (m_apiCallNumber % MAX_FRAME_CAPACITY == 0)
    {
        m_frameSplitNumber++;
    }

    if (callId != format::ApiCallId::ApiCall_vkAcquireNextImageKHR)
    {
        m_apiCallNumber++;
    }
}

void VulkanCppPreProcessConsumerBase::Intercept_vkCreateSwapchainKHR(
    VkResult                                                returnValue,
    format::HandleId                                        device,
    StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*    pAllocator,
    HandlePointerDecoder<VkSwapchainKHR>*                   pSwapchain)
{
    if (m_captureWindowWidth == 0 && m_captureWindowHeight == 0)
    {
        VkExtent2D imageExtent = pCreateInfo->GetPointer()->imageExtent;
        m_captureWindowWidth   = imageExtent.width;
        m_captureWindowHeight  = imageExtent.height;
    }
}

void VulkanCppPreProcessConsumerBase::Intercept_vkBindImageMemory(VkResult         returnValue,
                                                                  format::HandleId device,
                                                                  format::HandleId image,
                                                                  format::HandleId memory,
                                                                  VkDeviceSize     memoryOffset)
{
    m_memoryResourceMap[memory].emplace(std::make_pair(image, memoryOffset));
}

void VulkanCppPreProcessConsumerBase::Intercept_vkBindBufferMemory(VkResult         returnValue,
                                                                   format::HandleId device,
                                                                   format::HandleId buffer,
                                                                   format::HandleId memory,
                                                                   VkDeviceSize     memoryOffset)
{
    m_memoryResourceMap[memory].emplace(std::make_pair(buffer, memoryOffset));
}

void VulkanCppPreProcessConsumerBase::AddHandles_vkUpdateDescriptorSets(
    format::HandleId                                    device,
    uint32_t                                            descriptorWriteCount,
    StructPointerDecoder<Decoded_VkWriteDescriptorSet>* pDescriptorWrites,
    uint32_t                                            descriptorCopyCount,
    StructPointerDecoder<Decoded_VkCopyDescriptorSet>*  pDescriptorCopies)
{
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(), GetCurrentFrameSplitNumber(), device);

    Decoded_VkWriteDescriptorSet* descWrites = pDescriptorWrites->GetMetaStructPointer();
    for (uint32_t idx = 0; idx < descriptorWriteCount; idx++)
    {
        m_resourceTracker->AddHandleUsage(
            GetCurrentFrameNumber(), GetCurrentFrameSplitNumber(), descWrites[idx].dstSet);

        const VkWriteDescriptorSet* structInfo = pDescriptorWrites->GetPointer() + idx;
        uint32_t                    descCount  = pDescriptorWrites->GetPointer()[idx].descriptorCount;

        switch (structInfo->descriptorType)
        {
            case VK_DESCRIPTOR_TYPE_SAMPLER:
            case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
            case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
            case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
            case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
            {
                Decoded_VkDescriptorImageInfo* imageInfo = descWrites[idx].pImageInfo->GetMetaStructPointer();
                for (uint32_t jdx = 0; jdx < descCount; jdx++)
                {
                    if ((structInfo->descriptorType == VK_DESCRIPTOR_TYPE_SAMPLER) ||
                        (structInfo->descriptorType == VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER))
                    {
                        m_resourceTracker->AddHandleUsage(
                            GetCurrentFrameNumber(), GetCurrentFrameSplitNumber(), imageInfo[jdx].sampler);
                    }
                    m_resourceTracker->AddHandleUsage(
                        GetCurrentFrameNumber(), GetCurrentFrameSplitNumber(), imageInfo[jdx].imageView);
                }
                break;
            }
            case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
            case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
            case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
            case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
            {
                Decoded_VkDescriptorBufferInfo* bufferInfo = descWrites[idx].pBufferInfo->GetMetaStructPointer();
                for (uint32_t jdx = 0; jdx < descCount; jdx++)
                {
                    m_resourceTracker->AddHandleUsage(
                        GetCurrentFrameNumber(), GetCurrentFrameSplitNumber(), bufferInfo[jdx].buffer);
                }
                break;
            }
            case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
            case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
            {
                for (uint32_t jdx = 0; jdx < structInfo->descriptorCount; jdx++)
                {
                    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                                      GetCurrentFrameSplitNumber(),
                                                      descWrites[idx].pTexelBufferView.GetPointer()[jdx]);
                }
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
                assert(false);
            }
        }
    }
}

void VulkanCppPreProcessConsumerBase::AddHandles_vkUpdateDescriptorSetWithTemplate(
    format::HandleId                 device,
    format::HandleId                 descriptorSet,
    format::HandleId                 descriptorUpdateTemplate,
    DescriptorUpdateTemplateDecoder* pData)
{
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(), GetCurrentFrameSplitNumber(), device);
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(), GetCurrentFrameSplitNumber(), descriptorSet);
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(), GetCurrentFrameSplitNumber(), descriptorUpdateTemplate);

    for (uint32_t idx = 0; idx < pData->GetImageInfoCount(); idx++)
    {
        Decoded_VkDescriptorImageInfo* imageInfo = pData->GetImageInfoMetaStructPointer() + idx;

        m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(), GetCurrentFrameSplitNumber(), imageInfo->imageView);
        m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(), GetCurrentFrameSplitNumber(), imageInfo->sampler);
    }

    for (uint32_t idx = 0; idx < pData->GetBufferInfoCount(); idx++)
    {
        Decoded_VkDescriptorBufferInfo* bufferInfo = pData->GetBufferInfoMetaStructPointer() + idx;

        m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(), GetCurrentFrameSplitNumber(), bufferInfo->buffer);
    }

    for (uint32_t idx = 0; idx < pData->GetTexelBufferViewCount(); idx++)
    {
        m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          *(pData->GetTexelBufferViewHandleIdsPointer() + idx));
    }
}

void VulkanCppPreProcessConsumerBase::Process_vkUpdateDescriptorSetWithTemplate(
    const ApiCallInfo&               call_info,
    format::HandleId                 device,
    format::HandleId                 descriptorSet,
    format::HandleId                 descriptorUpdateTemplate,
    DescriptorUpdateTemplateDecoder* pData)
{
    AddHandles_vkUpdateDescriptorSetWithTemplate(device, descriptorSet, descriptorUpdateTemplate, pData);
    Post_APICall(format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplate);
}

void VulkanCppPreProcessConsumerBase::Process_vkUpdateDescriptorSetWithTemplateKHR(
    const ApiCallInfo&               call_info,
    format::HandleId                 device,
    format::HandleId                 descriptorSet,
    format::HandleId                 descriptorUpdateTemplate,
    DescriptorUpdateTemplateDecoder* pData)
{
    AddHandles_vkUpdateDescriptorSetWithTemplate(device, descriptorSet, descriptorUpdateTemplate, pData);
    Post_APICall(format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplate);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
