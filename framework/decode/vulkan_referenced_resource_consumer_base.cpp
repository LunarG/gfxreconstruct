/*
** Copyright (c) 2020 LunarG, Inc.
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

#include "decode/vulkan_referenced_resource_consumer_base.h"

#include <cassert>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

VulkanReferencedResourceConsumerBase::VulkanReferencedResourceConsumerBase() : loading_state_(false) {}

void VulkanReferencedResourceConsumerBase::Process_vkQueueSubmit(VkResult         returnValue,
                                                                 format::HandleId queue,
                                                                 uint32_t         submitCount,
                                                                 StructPointerDecoder<Decoded_VkSubmitInfo>* pSubmits,
                                                                 format::HandleId                            fence)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);
    GFXRECON_UNREFERENCED_PARAMETER(queue);
    GFXRECON_UNREFERENCED_PARAMETER(submitCount);
    GFXRECON_UNREFERENCED_PARAMETER(fence);

    assert(pSubmits != nullptr);

    if (!pSubmits->IsNull() && pSubmits->HasData())
    {
        size_t     submit_count = pSubmits->GetLength();
        const auto submits      = pSubmits->GetMetaStructPointer();

        for (size_t i = 0; i < submit_count; ++i)
        {
            size_t     command_buffer_count = submits[i].pCommandBuffers.GetLength();
            const auto command_buffer_ids   = submits[i].pCommandBuffers.GetPointer();

            for (size_t j = 0; j < command_buffer_count; ++j)
            {
                table_.ProcessUserSubmission(command_buffer_ids[j]);
            }
        }
    }
}

void VulkanReferencedResourceConsumerBase::Process_vkCreateBuffer(
    VkResult                                             returnValue,
    format::HandleId                                     device,
    StructPointerDecoder<Decoded_VkBufferCreateInfo>*    pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkBuffer>*                      pBuffer)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(pCreateInfo);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);

    assert(pBuffer != nullptr);

    // Only track buffers that were created by the trimmed file state snapshot.
    if (IsStateLoading() && !pBuffer->IsNull() && pBuffer->HasData())
    {
        table_.AddResource(*pBuffer->GetPointer());
    }
}

void VulkanReferencedResourceConsumerBase::Process_vkCreateBufferView(
    VkResult                                              returnValue,
    format::HandleId                                      device,
    StructPointerDecoder<Decoded_VkBufferViewCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*  pAllocator,
    HandlePointerDecoder<VkBufferView>*                   pView)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);

    assert((pCreateInfo != nullptr) && (pView != nullptr));

    if (!pCreateInfo->IsNull() && pCreateInfo->HasData() && !pView->IsNull() && pView->HasData())
    {
        const auto create_info = pCreateInfo->GetMetaStructPointer();
        table_.AddResource(create_info->buffer, *pView->GetPointer());
    }
}

void VulkanReferencedResourceConsumerBase::Process_vkCreateImage(
    VkResult                                             returnValue,
    format::HandleId                                     device,
    StructPointerDecoder<Decoded_VkImageCreateInfo>*     pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkImage>*                       pImage)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(pCreateInfo);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);

    assert(pImage != nullptr);

    // Only track images that were created by the trimmed file state snapshot.
    if (IsStateLoading() && !pImage->IsNull() && pImage->HasData())
    {
        table_.AddResource(*pImage->GetPointer());
    }
}

void VulkanReferencedResourceConsumerBase::Process_vkCreateImageView(
    VkResult                                             returnValue,
    format::HandleId                                     device,
    StructPointerDecoder<Decoded_VkImageViewCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkImageView>*                   pView)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);

    assert((pCreateInfo != nullptr) && (pView != nullptr));

    if (!pCreateInfo->IsNull() && pCreateInfo->HasData() && !pView->IsNull() && pView->HasData())
    {
        const auto create_info = pCreateInfo->GetMetaStructPointer();
        table_.AddResource(create_info->image, *pView->GetPointer());
    }
}

void VulkanReferencedResourceConsumerBase::Process_vkCreateFramebuffer(
    VkResult                                               returnValue,
    format::HandleId                                       device,
    StructPointerDecoder<Decoded_VkFramebufferCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*   pAllocator,
    HandlePointerDecoder<VkFramebuffer>*                   pFramebuffer)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);

    assert((pCreateInfo != nullptr) && (pFramebuffer != nullptr));

    if (!pCreateInfo->IsNull() && pCreateInfo->HasData() && !pFramebuffer->IsNull() && pFramebuffer->HasData())
    {
        const auto create_info = pCreateInfo->GetMetaStructPointer();
        auto       view_count  = create_info->pAttachments.GetLength();
        const auto views       = create_info->pAttachments.GetPointer();

        table_.AddResource(view_count, views, *pFramebuffer->GetPointer());
    }
}

void VulkanReferencedResourceConsumerBase::Process_vkDestroyDescriptorPool(
    format::HandleId                                     device,
    format::HandleId                                     descriptorPool,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);

    table_.ClearContainers(descriptorPool);
}

void VulkanReferencedResourceConsumerBase::Process_vkResetDescriptorPool(VkResult                   returnValue,
                                                                         format::HandleId           device,
                                                                         format::HandleId           descriptorPool,
                                                                         VkDescriptorPoolResetFlags flags)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(flags);

    table_.ClearContainers(descriptorPool);
}

void VulkanReferencedResourceConsumerBase::Process_vkAllocateDescriptorSets(
    VkResult                                                   returnValue,
    format::HandleId                                           device,
    StructPointerDecoder<Decoded_VkDescriptorSetAllocateInfo>* pAllocateInfo,
    HandlePointerDecoder<VkDescriptorSet>*                     pDescriptorSets)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);
    GFXRECON_UNREFERENCED_PARAMETER(device);

    assert((pAllocateInfo != nullptr) && (pDescriptorSets != nullptr));

    if (!pAllocateInfo->IsNull() && pAllocateInfo->HasData() && !pDescriptorSets->IsNull() &&
        pDescriptorSets->HasData())
    {
        const auto alloc_info      = pAllocateInfo->GetPointer();
        const auto alloc_meta_info = pAllocateInfo->GetMetaStructPointer();
        const auto sets            = pDescriptorSets->GetPointer();
        auto       pool            = alloc_meta_info->descriptorPool;
        auto       count           = alloc_info->descriptorSetCount;

        for (uint32_t i = 0; i < count; ++i)
        {
            table_.AddContainer(pool, sets[i]);
        }
    }
}

void VulkanReferencedResourceConsumerBase::Process_vkFreeDescriptorSets(
    VkResult                               returnValue,
    format::HandleId                       device,
    format::HandleId                       descriptorPool,
    uint32_t                               descriptorSetCount,
    HandlePointerDecoder<VkDescriptorSet>* pDescriptorSets)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(descriptorPool);

    assert(pDescriptorSets != nullptr);

    if (!pDescriptorSets->IsNull() && pDescriptorSets->HasData())
    {
        const auto sets = pDescriptorSets->GetPointer();

        for (uint32_t i = 0; i < descriptorSetCount; ++i)
        {
            table_.RemoveContainer(sets[i]);
        }
    }
}

void VulkanReferencedResourceConsumerBase::Process_vkUpdateDescriptorSets(
    format::HandleId                                    device,
    uint32_t                                            descriptorWriteCount,
    StructPointerDecoder<Decoded_VkWriteDescriptorSet>* pDescriptorWrites,
    uint32_t                                            descriptorCopyCount,
    StructPointerDecoder<Decoded_VkCopyDescriptorSet>*  pDescriptorCopies)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);

    assert((pDescriptorWrites != nullptr) && (pDescriptorCopies != nullptr));

    if (!pDescriptorWrites->IsNull() && pDescriptorWrites->HasData())
    {
        const auto writes      = pDescriptorWrites->GetPointer();
        const auto meta_writes = pDescriptorWrites->GetMetaStructPointer();

        for (uint32_t i = 0; i < descriptorWriteCount; ++i)
        {
            switch (writes[i].descriptorType)
            {
                case VK_DESCRIPTOR_TYPE_SAMPLER:
                case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK_EXT:
                case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR:
                    // Descriptor types that do not need to be tracked.
                    break;
                case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
                case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
                case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
                case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
                {
                    const auto image_info = meta_writes->pImageInfo.get();
                    assert(image_info != nullptr);

                    if (!image_info->IsNull() && image_info->HasData())
                    {
                        AddImagesToContainer(
                            meta_writes[i].dstSet, writes[i].descriptorCount, image_info->GetMetaStructPointer());
                    }

                    break;
                }
                case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
                case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
                case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
                case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
                {
                    const auto buffer_info = meta_writes->pBufferInfo.get();
                    assert(buffer_info != nullptr);

                    if (!buffer_info->IsNull() && buffer_info->HasData())
                    {
                        AddBuffersToContainer(
                            meta_writes[i].dstSet, writes[i].descriptorCount, buffer_info->GetMetaStructPointer());
                    }

                    break;
                }
                case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
                case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
                {
                    const auto& views = meta_writes->pTexelBufferView;

                    if (!views.IsNull() && views.HasData())
                    {
                        AddTexelBufferViewsToContainer(
                            meta_writes[i].dstSet, writes[i].descriptorCount, views.GetPointer());
                    }

                    break;
                }
                default:
                    GFXRECON_LOG_WARNING("Ingoring unrecognized descriptor type %d", writes[i].descriptorType);
                    break;
            }
        }
    }

    if (!pDescriptorCopies->IsNull() && pDescriptorCopies->HasData())
    {
        // TODO: Containers need to support indexes for copies.
    }
}

void VulkanReferencedResourceConsumerBase::Process_vkUpdateDescriptorSetWithTemplate(
    format::HandleId                 device,
    format::HandleId                 descriptorSet,
    format::HandleId                 descriptorUpdateTemplate,
    DescriptorUpdateTemplateDecoder* pData)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(descriptorUpdateTemplate);

    UpdateDescriptorSetWithTemplate(descriptorSet, pData);
}

void VulkanReferencedResourceConsumerBase::Process_vkCmdPushDescriptorSetWithTemplateKHR(
    format::HandleId                 commandBuffer,
    format::HandleId                 descriptorUpdateTemplate,
    format::HandleId                 layout,
    uint32_t                         set,
    DescriptorUpdateTemplateDecoder* pData)
{
    GFXRECON_UNREFERENCED_PARAMETER(descriptorUpdateTemplate);
    GFXRECON_UNREFERENCED_PARAMETER(layout);
    GFXRECON_UNREFERENCED_PARAMETER(set);

    PushDescriptorSetWithTemplate(commandBuffer, pData);
}

void VulkanReferencedResourceConsumerBase::Process_vkUpdateDescriptorSetWithTemplateKHR(
    format::HandleId                 device,
    format::HandleId                 descriptorSet,
    format::HandleId                 descriptorUpdateTemplate,
    DescriptorUpdateTemplateDecoder* pData)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(descriptorUpdateTemplate);

    UpdateDescriptorSetWithTemplate(descriptorSet, pData);
}

void VulkanReferencedResourceConsumerBase::Process_vkDestroyCommandPool(
    format::HandleId                                     device,
    format::HandleId                                     commandPool,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);

    table_.ClearUsers(commandPool);
}

void VulkanReferencedResourceConsumerBase::Process_vkResetCommandPool(VkResult                returnValue,
                                                                      format::HandleId        device,
                                                                      format::HandleId        commandPool,
                                                                      VkCommandPoolResetFlags flags)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(flags);

    table_.ResetUsers(commandPool);
}

void VulkanReferencedResourceConsumerBase::Process_vkAllocateCommandBuffers(
    VkResult                                                   returnValue,
    format::HandleId                                           device,
    StructPointerDecoder<Decoded_VkCommandBufferAllocateInfo>* pAllocateInfo,
    HandlePointerDecoder<VkCommandBuffer>*                     pCommandBuffers)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);
    GFXRECON_UNREFERENCED_PARAMETER(device);

    assert((pAllocateInfo != nullptr) && (pCommandBuffers != nullptr));

    if (!pAllocateInfo->IsNull() && pAllocateInfo->HasData() && !pCommandBuffers->IsNull() &&
        pCommandBuffers->HasData())
    {
        const auto alloc_info      = pAllocateInfo->GetPointer();
        const auto alloc_meta_info = pAllocateInfo->GetMetaStructPointer();
        const auto command_buffers = pCommandBuffers->GetPointer();
        auto       pool            = alloc_meta_info->commandPool;
        auto       count           = alloc_info->commandBufferCount;

        for (uint32_t i = 0; i < count; ++i)
        {
            table_.AddUser(pool, command_buffers[i]);
        }
    }
}

void VulkanReferencedResourceConsumerBase::Process_vkFreeCommandBuffers(
    format::HandleId                       device,
    format::HandleId                       commandPool,
    uint32_t                               commandBufferCount,
    HandlePointerDecoder<VkCommandBuffer>* pCommandBuffers)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(commandPool);

    assert(pCommandBuffers != nullptr);

    if (!pCommandBuffers->IsNull() && pCommandBuffers->HasData())
    {
        const auto command_buffers = pCommandBuffers->GetPointer();

        for (uint32_t i = 0; i < commandBufferCount; ++i)
        {
            table_.RemoveUser(command_buffers[i]);
        }
    }
}

void VulkanReferencedResourceConsumerBase::Process_vkBeginCommandBuffer(
    VkResult                                                returnValue,
    format::HandleId                                        commandBuffer,
    StructPointerDecoder<Decoded_VkCommandBufferBeginInfo>* pBeginInfo)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);
    GFXRECON_UNREFERENCED_PARAMETER(pBeginInfo);

    table_.ResetUser(commandBuffer);
}

void VulkanReferencedResourceConsumerBase::Process_vkResetCommandBuffer(VkResult                  returnValue,
                                                                        format::HandleId          commandBuffer,
                                                                        VkCommandBufferResetFlags flags)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);
    GFXRECON_UNREFERENCED_PARAMETER(flags);

    table_.ResetUser(commandBuffer);
}

void VulkanReferencedResourceConsumerBase::AddImagesToContainer(format::HandleId                     container_id,
                                                                size_t                               count,
                                                                const Decoded_VkDescriptorImageInfo* image_info)
{
    assert(image_info != nullptr);

    for (size_t i = 0; i < count; ++i)
    {
        table_.AddResourceToContainer(container_id, image_info[i].imageView);
    }
}

void VulkanReferencedResourceConsumerBase::AddBuffersToContainer(format::HandleId                      container_id,
                                                                 size_t                                count,
                                                                 const Decoded_VkDescriptorBufferInfo* buffer_info)
{
    assert(buffer_info != nullptr);

    for (size_t i = 0; i < count; ++i)
    {
        table_.AddResourceToContainer(container_id, buffer_info[i].buffer);
    }
}

void VulkanReferencedResourceConsumerBase::AddTexelBufferViewsToContainer(format::HandleId        container_id,
                                                                          size_t                  count,
                                                                          const format::HandleId* view_ids)
{
    assert(view_ids != nullptr);

    for (size_t i = 0; i < count; ++i)
    {
        table_.AddResourceToContainer(container_id, view_ids[i]);
    }
}

void VulkanReferencedResourceConsumerBase::UpdateDescriptorSetWithTemplate(
    format::HandleId container_id, const DescriptorUpdateTemplateDecoder* decoder)
{
    assert(decoder != nullptr);

    size_t image_info_count        = decoder->GetImageInfoCount();
    size_t buffer_info_count       = decoder->GetBufferInfoCount();
    size_t texel_buffer_view_count = decoder->GetTexelBufferViewCount();

    if (image_info_count > 0)
    {
        // TODO: Get descriptor type from template creation so that sampler only writes can be ignored. Worst case is a
        // handle with an uninitialized value, which will never be referenced, is added to the tracker.
        const auto image_info = decoder->GetImageInfoMetaStructPointer();
        assert(image_info != nullptr);

        AddImagesToContainer(container_id, image_info_count, image_info);
    }

    if (buffer_info_count > 0)
    {
        const auto buffer_info = decoder->GetBufferInfoMetaStructPointer();
        assert(buffer_info != nullptr);

        AddBuffersToContainer(container_id, buffer_info_count, buffer_info);
    }

    if (texel_buffer_view_count > 0)
    {
        auto view_ids = decoder->GetTexelBufferViewHandleIdsPointer();
        assert(view_ids != nullptr);

        AddTexelBufferViewsToContainer(container_id, texel_buffer_view_count, view_ids);
    }
}

void VulkanReferencedResourceConsumerBase::AddImagesToUser(format::HandleId                     user_id,
                                                           size_t                               count,
                                                           const Decoded_VkDescriptorImageInfo* image_info)
{
    assert(image_info != nullptr);

    for (size_t i = 0; i < count; ++i)
    {
        table_.AddResourceToUser(user_id, image_info[i].imageView);
    }
}

void VulkanReferencedResourceConsumerBase::AddBuffersToUser(format::HandleId                      user_id,
                                                            size_t                                count,
                                                            const Decoded_VkDescriptorBufferInfo* buffer_info)
{
    assert(buffer_info != nullptr);

    for (size_t i = 0; i < count; ++i)
    {
        table_.AddResourceToUser(user_id, buffer_info[i].buffer);
    }
}

void VulkanReferencedResourceConsumerBase::AddTexelBufferViewsToUser(format::HandleId        user_id,
                                                                     size_t                  count,
                                                                     const format::HandleId* view_ids)
{
    assert(view_ids != nullptr);

    for (size_t i = 0; i < count; ++i)
    {
        table_.AddResourceToUser(user_id, view_ids[i]);
    }
}

void VulkanReferencedResourceConsumerBase::PushDescriptorSetWithTemplate(format::HandleId                       user_id,
                                                                         const DescriptorUpdateTemplateDecoder* decoder)
{
    assert(decoder != nullptr);

    size_t image_info_count        = decoder->GetImageInfoCount();
    size_t buffer_info_count       = decoder->GetBufferInfoCount();
    size_t texel_buffer_view_count = decoder->GetTexelBufferViewCount();

    if (image_info_count > 0)
    {
        // TODO: Get descriptor type from template creation so that sampler only writes can be ignored. Worst case is a
        // handle with an uninitialized value, which will never be referenced, is added to the tracker.
        const auto image_info = decoder->GetImageInfoMetaStructPointer();
        assert(image_info != nullptr);

        AddImagesToUser(user_id, image_info_count, image_info);
    }

    if (buffer_info_count > 0)
    {
        const auto buffer_info = decoder->GetBufferInfoMetaStructPointer();
        assert(buffer_info != nullptr);

        AddBuffersToUser(user_id, buffer_info_count, buffer_info);
    }

    if (texel_buffer_view_count > 0)
    {
        auto view_ids = decoder->GetTexelBufferViewHandleIdsPointer();
        assert(view_ids != nullptr);

        AddTexelBufferViewsToUser(user_id, texel_buffer_view_count, view_ids);
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
