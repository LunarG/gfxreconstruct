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

#include "util/logging.h"

#include <cassert>
#include <stdexcept>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

VulkanReferencedResourceConsumerBase::VulkanReferencedResourceConsumerBase() :
    loading_state_(false), loaded_state_(false)
{}

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
    if (IsStateLoading())
    {
        if (!pBuffer->IsNull() && pBuffer->HasData())
        {
            table_.AddResource(*pBuffer->GetPointer());
        }
    }
    else
    {
        // Stop processing if file did not start with a state block.
        if (!loaded_state_)
        {
            // There is currently no way for a consumer to indicate that file processing should terminate early, except
            // by throwing an exception.
            throw std::runtime_error("File does not contain a state block to optimize");
        }
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
    if (IsStateLoading())
    {
        if (!pImage->IsNull() && pImage->HasData())
        {
            table_.AddResource(*pImage->GetPointer());
        }
    }
    else
    {
        // Stop processing the file if it did not start with a state block.
        if (!loaded_state_)
        {
            // There is currently no way for a consumer to indicate that file processing should terminate early, except
            // by throwing an exception.
            throw std::runtime_error("File does not contain a state block to optimize");
        }
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

void VulkanReferencedResourceConsumerBase::Process_vkCreateDescriptorSetLayout(
    VkResult                                                       returnValue,
    format::HandleId                                               device,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*           pAllocator,
    HandlePointerDecoder<VkDescriptorSetLayout>*                   pSetLayout)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);

    assert((pCreateInfo != nullptr) && (pSetLayout != nullptr));

    if (!pCreateInfo->IsNull() && pCreateInfo->HasData() && !pSetLayout->IsNull() && pSetLayout->HasData())
    {
        const auto  create_info = pCreateInfo->GetPointer();
        const auto& bindings    = create_info->pBindings;
        auto        layout_id   = (*pSetLayout->GetPointer());

        for (uint32_t i = 0; i < create_info->bindingCount; ++i)
        {
            const auto& binding = bindings[i];
            layout_binding_counts_[layout_id].emplace(binding.binding, binding.descriptorCount);
        }
    }
}

void VulkanReferencedResourceConsumerBase::Process_vkCreateDescriptorUpdateTemplate(
    VkResult                                                            returnValue,
    format::HandleId                                                    device,
    StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*                pAllocator,
    HandlePointerDecoder<VkDescriptorUpdateTemplate>*                   pDescriptorUpdateTemplate)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);

    CreateDescriptorUpdateTemplate(pCreateInfo, pDescriptorUpdateTemplate);
}

void VulkanReferencedResourceConsumerBase::Process_vkCreateDescriptorUpdateTemplateKHR(
    VkResult                                                            returnValue,
    format::HandleId                                                    device,
    StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*                pAllocator,
    HandlePointerDecoder<VkDescriptorUpdateTemplate>*                   pDescriptorUpdateTemplate)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);

    CreateDescriptorUpdateTemplate(pCreateInfo, pDescriptorUpdateTemplate);
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
        const auto layouts         = alloc_meta_info->pSetLayouts.GetPointer();
        auto       pool            = alloc_meta_info->descriptorPool;
        auto       count           = alloc_info->descriptorSetCount;

        assert((pDescriptorSets->GetLength() == count) && (alloc_meta_info->pSetLayouts.GetLength() == count));

        for (uint32_t i = 0; i < count; ++i)
        {
            auto set_id          = sets[i];
            set_layouts_[set_id] = layouts[i];
            table_.AddContainer(pool, set_id);
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
                        AddImagesToContainer(meta_writes[i].dstSet,
                                             writes[i].dstBinding,
                                             writes[i].dstArrayElement,
                                             writes[i].descriptorCount,
                                             image_info->GetMetaStructPointer());
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
                        AddBuffersToContainer(meta_writes[i].dstSet,
                                              writes[i].dstBinding,
                                              writes[i].dstArrayElement,
                                              writes[i].descriptorCount,
                                              buffer_info->GetMetaStructPointer());
                    }

                    break;
                }
                case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
                case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
                {
                    const auto& views = meta_writes->pTexelBufferView;

                    if (!views.IsNull() && views.HasData())
                    {
                        AddTexelBufferViewsToContainer(meta_writes[i].dstSet,
                                                       writes[i].dstBinding,
                                                       writes[i].dstArrayElement,
                                                       writes[i].descriptorCount,
                                                       views.GetPointer());
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
        const auto copies      = pDescriptorCopies->GetPointer();
        const auto meta_copies = pDescriptorCopies->GetMetaStructPointer();

        for (uint32_t i = 0; i < descriptorCopyCount; ++i)
        {
            const auto& copy      = copies[i];
            const auto& meta_copy = meta_copies[i];

            auto src_element       = copy.srcArrayElement;
            auto dst_element       = copy.dstArrayElement;
            auto src_binding       = copy.srcBinding;
            auto dst_binding       = copy.dstBinding;
            auto src_binding_count = GetBindingCount(meta_copy.srcSet, copy.srcBinding);
            auto dst_binding_count = GetBindingCount(meta_copy.dstSet, copy.dstBinding);
            assert((src_element < src_binding_count) && (dst_element < dst_binding_count));

            for (uint32_t j = 0; j < copy.descriptorCount; ++j)
            {
                if (src_element >= src_binding_count)
                {
                    // If the element has advanced past the end of the current binding's descriptor count, advance to
                    // the next binding.
                    ++src_binding;
                    src_element       = 0;
                    src_binding_count = GetBindingCount(meta_copy.srcSet, copy.srcBinding);
                }

                if (dst_element >= dst_binding_count)
                {
                    // If the element has advanced past the end of the current binding's descriptor count, advance to
                    // the next binding.
                    ++dst_binding;
                    dst_element       = 0;
                    dst_binding_count = GetBindingCount(meta_copy.dstSet, copy.dstBinding);
                }

                table_.CopyContainerEntry(
                    meta_copy.srcSet, src_binding, src_element, meta_copy.dstSet, dst_binding, dst_element);

                // Advance to the next array element for the current bindings.
                ++src_element;
                ++dst_element;
            }
        }
    }
}

void VulkanReferencedResourceConsumerBase::Process_vkUpdateDescriptorSetWithTemplate(
    format::HandleId                 device,
    format::HandleId                 descriptorSet,
    format::HandleId                 descriptorUpdateTemplate,
    DescriptorUpdateTemplateDecoder* pData)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);

    UpdateDescriptorSetWithTemplate(descriptorSet, descriptorUpdateTemplate, pData);
}

void VulkanReferencedResourceConsumerBase::Process_vkCmdPushDescriptorSetWithTemplateKHR(
    format::HandleId                 commandBuffer,
    format::HandleId                 descriptorUpdateTemplate,
    format::HandleId                 layout,
    uint32_t                         set,
    DescriptorUpdateTemplateDecoder* pData)
{
    GFXRECON_UNREFERENCED_PARAMETER(layout);
    GFXRECON_UNREFERENCED_PARAMETER(set);

    PushDescriptorSetWithTemplate(commandBuffer, descriptorUpdateTemplate, pData);
}

void VulkanReferencedResourceConsumerBase::Process_vkUpdateDescriptorSetWithTemplateKHR(
    format::HandleId                 device,
    format::HandleId                 descriptorSet,
    format::HandleId                 descriptorUpdateTemplate,
    DescriptorUpdateTemplateDecoder* pData)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);

    UpdateDescriptorSetWithTemplate(descriptorSet, descriptorUpdateTemplate, pData);
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

uint32_t VulkanReferencedResourceConsumerBase::GetBindingCount(format::HandleId container_id, uint32_t binding) const
{
    const auto layout_entry = set_layouts_.find(container_id);
    if (layout_entry != set_layouts_.end())
    {
        auto       layout_id     = layout_entry->second;
        const auto binding_entry = layout_binding_counts_.find(layout_id);
        if (binding_entry != layout_binding_counts_.end())
        {
            const auto& binding_counts = binding_entry->second;
            const auto  count_entry    = binding_counts.find(binding);
            if (count_entry != binding_counts.end())
            {
                return count_entry->second;
            }
        }
    }

    return std::numeric_limits<uint32_t>::max();
}

void VulkanReferencedResourceConsumerBase::AddDescriptorToContainer(
    format::HandleId                                 container_id,
    int32_t                                          binding,
    uint32_t                                         element,
    uint32_t                                         count,
    std::function<void(uint32_t, int32_t, uint32_t)> add_descriptor)
{
    auto binding_count = GetBindingCount(container_id, binding);
    assert(element < binding_count);

    for (uint32_t i = 0; i < count; ++i)
    {
        if (element >= binding_count)
        {
            // If the element has advanced past the end of the current binding's descriptor count, advance to the
            // next binding.
            ++binding;
            element       = 0;
            binding_count = GetBindingCount(container_id, binding);
        }

        add_descriptor(i, binding, element);

        // Advance to next array element for the current binding.
        ++element;
    }
}

void VulkanReferencedResourceConsumerBase::AddImagesToContainer(format::HandleId                     container_id,
                                                                int32_t                              binding,
                                                                uint32_t                             element,
                                                                uint32_t                             count,
                                                                const Decoded_VkDescriptorImageInfo* image_infos)
{
    assert(image_infos != nullptr);

    AddDescriptorToContainer(
        container_id, binding, element, count, [&](uint32_t index, int32_t current_binding, uint32_t current_element) {
            table_.AddResourceToContainer(container_id, image_infos[index].imageView, current_binding, current_element);
        });
}

void VulkanReferencedResourceConsumerBase::AddBuffersToContainer(format::HandleId                      container_id,
                                                                 int32_t                               binding,
                                                                 uint32_t                              element,
                                                                 uint32_t                              count,
                                                                 const Decoded_VkDescriptorBufferInfo* buffer_infos)
{
    assert(buffer_infos != nullptr);

    AddDescriptorToContainer(
        container_id, binding, element, count, [&](uint32_t index, int32_t current_binding, uint32_t current_element) {
            table_.AddResourceToContainer(container_id, buffer_infos[index].buffer, current_binding, current_element);
        });
}

void VulkanReferencedResourceConsumerBase::AddTexelBufferViewsToContainer(
    format::HandleId container_id, int32_t binding, uint32_t element, uint32_t count, const format::HandleId* view_ids)
{
    assert(view_ids != nullptr);

    AddDescriptorToContainer(
        container_id, binding, element, count, [&](uint32_t index, int32_t current_binding, uint32_t current_element) {
            table_.AddResourceToContainer(container_id, view_ids[index], current_binding, current_element);
        });
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

void VulkanReferencedResourceConsumerBase::CreateDescriptorUpdateTemplate(
    const StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>* create_info,
    const HandlePointerDecoder<VkDescriptorUpdateTemplate>*                   descriptor_update_template)
{
    assert((create_info != nullptr) && (descriptor_update_template != nullptr));

    if (!create_info->IsNull() && create_info->HasData() && !descriptor_update_template->IsNull() &&
        descriptor_update_template->HasData())
    {
        UpdateTemplateInfo template_info;

        auto       template_id          = (*descriptor_update_template->GetPointer());
        const auto template_create_info = create_info->GetPointer();
        auto       update_entry_count   = template_create_info->descriptorUpdateEntryCount;
        const auto update_entries       = template_create_info->pDescriptorUpdateEntries;

        // Capture file encoding converts the update template data to tightly packed arrays of descriptor info
        // structures in the order of images, buffes, texel buffer views.  For the update template info tracking, we
        // build arrays of update template entry info with the same ordering.
        for (uint32_t i = 0; i < update_entry_count; ++i)
        {
            UpdateTemplateEntryInfo entry_info;
            entry_info.binding       = update_entries[i].dstBinding;
            entry_info.array_element = update_entries[i].dstArrayElement;
            entry_info.count         = update_entries[i].descriptorCount;
            entry_info.type          = update_entries[i].descriptorType;

            if ((entry_info.type == VK_DESCRIPTOR_TYPE_SAMPLER) ||
                (entry_info.type == VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER) ||
                (entry_info.type == VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE) ||
                (entry_info.type == VK_DESCRIPTOR_TYPE_STORAGE_IMAGE) ||
                (entry_info.type == VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT))
            {
                template_info.image_infos.emplace_back(std::move(entry_info));
            }
            else if ((entry_info.type == VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER) ||
                     (entry_info.type == VK_DESCRIPTOR_TYPE_STORAGE_BUFFER) ||
                     (entry_info.type == VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC) ||
                     (entry_info.type == VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC))
            {
                template_info.buffer_infos.emplace_back(std::move(entry_info));
            }
            else if ((entry_info.type == VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER) ||
                     (entry_info.type == VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER))
            {
                template_info.texel_buffer_view_infos.emplace_back(std::move(entry_info));
            }
        }

        template_infos_.emplace(template_id, std::move(template_info));
    }
}

void VulkanReferencedResourceConsumerBase::UpdateDescriptorSetWithTemplate(
    format::HandleId container_id, format::HandleId template_id, const DescriptorUpdateTemplateDecoder* decoder)
{
    assert(decoder != nullptr);

    auto image_info_count        = static_cast<uint32_t>(decoder->GetImageInfoCount());
    auto buffer_info_count       = static_cast<uint32_t>(decoder->GetBufferInfoCount());
    auto texel_buffer_view_count = static_cast<uint32_t>(decoder->GetTexelBufferViewCount());

    const auto template_info_entry = template_infos_.find(template_id);
    if (template_info_entry != template_infos_.end())
    {
        // Update template data is stored as tightly packed arrays of image, buffer, and texel buffer view descriptor
        // info structures.  Each update template entry references a subrange of info structures, organized in
        // consecutive order.  Descriptor update template data will be processed by entry/subrange.
        const auto& template_info = template_info_entry->second;

        if (image_info_count > 0)
        {
            uint32_t   offset     = 0;
            const auto image_info = decoder->GetImageInfoMetaStructPointer();
            assert(image_info != nullptr);

            for (const auto& info : template_info.image_infos)
            {
                assert((offset + info.count) <= image_info_count);

                if ((offset + info.count) > image_info_count)
                {
                    GFXRECON_LOG_ERROR("Descriptor update template entry count exceeds the total number of entries in "
                                       "the update template data.");
                    break;
                }

                // Sample only descriptor types can be ignored as we only need to track image view handles.
                if (info.type != VK_DESCRIPTOR_TYPE_SAMPLER)
                {
                    AddImagesToContainer(
                        container_id, info.binding, info.array_element, info.count, &image_info[offset]);
                }

                offset += info.count;
            }
        }

        if (buffer_info_count > 0)
        {
            uint32_t   offset      = 0;
            const auto buffer_info = decoder->GetBufferInfoMetaStructPointer();
            assert(buffer_info != nullptr);

            for (const auto& info : template_info.buffer_infos)
            {
                assert((offset + info.count) <= buffer_info_count);

                if ((offset + info.count) > buffer_info_count)
                {
                    GFXRECON_LOG_ERROR("Descriptor update template entry count exceeds the total number of entries in "
                                       "the update template data.");
                    break;
                }

                AddBuffersToContainer(container_id, info.binding, info.array_element, info.count, &buffer_info[offset]);

                offset += info.count;
            }
        }

        if (texel_buffer_view_count > 0)
        {
            uint32_t offset   = 0;
            auto     view_ids = decoder->GetTexelBufferViewHandleIdsPointer();
            assert(view_ids != nullptr);

            for (const auto& info : template_info.texel_buffer_view_infos)
            {
                assert((offset + info.count) <= texel_buffer_view_count);

                if ((offset + info.count) > texel_buffer_view_count)
                {
                    GFXRECON_LOG_ERROR("Descriptor update template entry count exceeds the total number of entries in "
                                       "the update template data.");
                    break;
                }

                AddTexelBufferViewsToContainer(
                    container_id, info.binding, info.array_element, info.count, &view_ids[offset]);

                offset += info.count;
            }
        }
    }
}

void VulkanReferencedResourceConsumerBase::PushDescriptorSetWithTemplate(format::HandleId user_id,
                                                                         format::HandleId template_id,
                                                                         const DescriptorUpdateTemplateDecoder* decoder)
{
    assert(decoder != nullptr);

    size_t image_info_count        = decoder->GetImageInfoCount();
    size_t buffer_info_count       = decoder->GetBufferInfoCount();
    size_t texel_buffer_view_count = decoder->GetTexelBufferViewCount();

    if (image_info_count > 0)
    {
        const auto template_info_entry = template_infos_.find(template_id);
        if (template_info_entry != template_infos_.end())
        {
            // Update template data is stored as tightly packed arrays of image, buffer, and texel buffer view
            // descriptor info structures.  Each update template entry references a subrange of info structures,
            // organized in consecutive order.  Descriptor update template data for images will be processed by
            // entry/subrange so that descriptors with a sampler type can be ignored.
            const auto& template_info = template_info_entry->second;
            const auto  image_info    = decoder->GetImageInfoMetaStructPointer();
            size_t      offset        = 0;
            assert(image_info != nullptr);

            for (const auto& info : template_info.image_infos)
            {
                assert((offset + info.count) <= image_info_count);

                if ((offset + info.count) > image_info_count)
                {
                    GFXRECON_LOG_ERROR("Descriptor update template entry count exceeds the total number of entries in "
                                       "the update template data.");
                    break;
                }

                // Sample only descriptor types can be ignored as we only need to track image view handles.
                if (info.type != VK_DESCRIPTOR_TYPE_SAMPLER)
                {
                    AddImagesToUser(user_id, info.count, &image_info[offset]);
                }

                offset += info.count;
            }
        }
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
