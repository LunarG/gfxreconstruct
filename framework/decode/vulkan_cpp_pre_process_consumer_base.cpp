//
// Copyright (c) 2021 Samsung
// Copyright (c) 2023 Google
// Copyright (c) 2023 LunarG, Inc
//
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

#include "vulkan_cpp_pre_process_consumer_base.h"

#include <iostream>
#include <unordered_set>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

VulkanCppPreProcessConsumerBase::VulkanCppPreProcessConsumerBase() : capture_window_width_(0), capture_window_height_(0)
{}

VulkanCppPreProcessConsumerBase::~VulkanCppPreProcessConsumerBase() {}

bool VulkanCppPreProcessConsumerBase::Initialize()
{
    frame_number_          = 0;
    frame_split_number_    = 0;
    frame_api_call_number_ = 0;
    api_call_number_       = 0;

    return true;
}

void VulkanCppPreProcessConsumerBase::Post_APICall(format::ApiCallId callId)
{
    // Replicate FileProcessor's frame counter increment process
    if (callId == format::ApiCallId::ApiCall_vkQueuePresentKHR)
    {
        frame_api_call_number_ = 0;
        frame_split_number_    = 0;
        frame_number_++;
    }
    else if (frame_api_call_number_ != 0 && (frame_api_call_number_ % max_command_limit_ == 0))
    {
        frame_api_call_number_ = 0;
        frame_split_number_++;
    }

    if (callId != format::ApiCallId::ApiCall_vkAcquireNextImageKHR)
    {
        api_call_number_++;
        frame_api_call_number_++;
    }
}

void VulkanCppPreProcessConsumerBase::Intercept_vkCreateSwapchainKHR(
    VkResult                                                returnValue,
    format::HandleId                                        device,
    StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*    pAllocator,
    HandlePointerDecoder<VkSwapchainKHR>*                   pSwapchain)
{
    if (capture_window_width_ == 0 && capture_window_height_ == 0)
    {
        VkExtent2D imageExtent = pCreateInfo->GetPointer()->imageExtent;
        capture_window_width_  = imageExtent.width;
        capture_window_height_ = imageExtent.height;
    }
}

void VulkanCppPreProcessConsumerBase::Intercept_vkBindImageMemory(VkResult         returnValue,
                                                                  format::HandleId device,
                                                                  format::HandleId image,
                                                                  format::HandleId memory,
                                                                  VkDeviceSize     memoryOffset)
{
    memory_resource_map_[memory].emplace(std::make_pair(image, memoryOffset));
}

void VulkanCppPreProcessConsumerBase::Intercept_vkBindImageMemory2(
    VkResult                                             returnValue,
    format::HandleId                                     device,
    uint32_t                                             bindInfoCount,
    StructPointerDecoder<Decoded_VkBindImageMemoryInfo>* pBindInfos)
{
    for (uint32_t index = 0; index < bindInfoCount; ++index)
    {
        const VkBindImageMemoryInfo* cur_image_memory = pBindInfos->GetPointer() + index;
        memory_resource_map_[(format::HandleId)cur_image_memory->memory].emplace(
            std::make_pair((format::HandleId)cur_image_memory->image, cur_image_memory->memoryOffset));
    }
}

void VulkanCppPreProcessConsumerBase::Intercept_vkBindBufferMemory(VkResult         returnValue,
                                                                   format::HandleId device,
                                                                   format::HandleId buffer,
                                                                   format::HandleId memory,
                                                                   VkDeviceSize     memoryOffset)
{
    memory_resource_map_[memory].emplace(std::make_pair(buffer, memoryOffset));
}

void VulkanCppPreProcessConsumerBase::Intercept_vkBindBufferMemory2(
    VkResult                                              returnValue,
    format::HandleId                                      device,
    uint32_t                                              bindInfoCount,
    StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>* pBindInfos)
{
    for (uint32_t index = 0; index < bindInfoCount; ++index)
    {
        const VkBindBufferMemoryInfo* cur_buffer_memory = pBindInfos->GetPointer() + index;
        memory_resource_map_[(format::HandleId)cur_buffer_memory->memory].emplace(
            std::make_pair((format::HandleId)cur_buffer_memory->buffer, cur_buffer_memory->memoryOffset));
    }
}

void VulkanCppPreProcessConsumerBase::AddHandles_vkUpdateDescriptorSets(
    format::HandleId                                    device,
    uint32_t                                            descriptorWriteCount,
    StructPointerDecoder<Decoded_VkWriteDescriptorSet>* pDescriptorWrites,
    uint32_t                                            descriptorCopyCount,
    StructPointerDecoder<Decoded_VkCopyDescriptorSet>*  pDescriptorCopies)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(), GetCurrentFrameSplitNumber(), device);

    Decoded_VkWriteDescriptorSet* decoded_desc_writes = pDescriptorWrites->GetMetaStructPointer();
    for (uint32_t idx = 0; idx < descriptorWriteCount; idx++)
    {
        resource_tracker_->AddHandleUsage(
            GetCurrentFrameNumber(), GetCurrentFrameSplitNumber(), decoded_desc_writes[idx].dstSet);

        const VkWriteDescriptorSet* struct_info          = pDescriptorWrites->GetPointer() + idx;
        uint32_t                    cur_descriptor_count = pDescriptorWrites->GetPointer()[idx].descriptorCount;

        switch (struct_info->descriptorType)
        {
            case VK_DESCRIPTOR_TYPE_SAMPLER:
            case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
            case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
            case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
            case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
            {
                Decoded_VkDescriptorImageInfo* imageInfo = decoded_desc_writes[idx].pImageInfo->GetMetaStructPointer();
                for (uint32_t jdx = 0; jdx < cur_descriptor_count; jdx++)
                {
                    if ((struct_info->descriptorType == VK_DESCRIPTOR_TYPE_SAMPLER) ||
                        (struct_info->descriptorType == VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER))
                    {
                        resource_tracker_->AddHandleUsage(
                            GetCurrentFrameNumber(), GetCurrentFrameSplitNumber(), imageInfo[jdx].sampler);
                    }
                    resource_tracker_->AddHandleUsage(
                        GetCurrentFrameNumber(), GetCurrentFrameSplitNumber(), imageInfo[jdx].imageView);
                }
                break;
            }
            case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
            case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
            case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
            case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
            {
                Decoded_VkDescriptorBufferInfo* bufferInfo =
                    decoded_desc_writes[idx].pBufferInfo->GetMetaStructPointer();
                for (uint32_t jdx = 0; jdx < cur_descriptor_count; jdx++)
                {
                    resource_tracker_->AddHandleUsage(
                        GetCurrentFrameNumber(), GetCurrentFrameSplitNumber(), bufferInfo[jdx].buffer);
                }
                break;
            }
            case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
            case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
            {
                for (uint32_t jdx = 0; jdx < struct_info->descriptorCount; jdx++)
                {
                    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                                      GetCurrentFrameSplitNumber(),
                                                      decoded_desc_writes[idx].pTexelBufferView.GetPointer()[jdx]);
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
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(), GetCurrentFrameSplitNumber(), device);
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(), GetCurrentFrameSplitNumber(), descriptorSet);
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(), GetCurrentFrameSplitNumber(), descriptorUpdateTemplate);

    for (uint32_t idx = 0; idx < pData->GetImageInfoCount(); idx++)
    {
        Decoded_VkDescriptorImageInfo* imageInfo = pData->GetImageInfoMetaStructPointer() + idx;

        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(), GetCurrentFrameSplitNumber(), imageInfo->imageView);
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(), GetCurrentFrameSplitNumber(), imageInfo->sampler);
    }

    for (uint32_t idx = 0; idx < pData->GetBufferInfoCount(); idx++)
    {
        Decoded_VkDescriptorBufferInfo* bufferInfo = pData->GetBufferInfoMetaStructPointer() + idx;

        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(), GetCurrentFrameSplitNumber(), bufferInfo->buffer);
    }

    for (uint32_t idx = 0; idx < pData->GetTexelBufferViewCount(); idx++)
    {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
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

// Meta data commands

void VulkanCppPreProcessConsumerBase::ProcessDisplayMessageCommand(const std::string& message)
{
    GFXRECON_LOG_INFO("ProcessDisplayMessageCommand: %s", message.c_str());
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
