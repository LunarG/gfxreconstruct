/*
** Copyright (c) 2020 LunarG, Inc.
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

#include "decode/vulkan_referenced_resource_consumer_base.h"

#include "util/logging.h"

#include <cassert>
#include <stdexcept>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

VulkanReferencedResourceConsumerBase::VulkanReferencedResourceConsumerBase() :
    loading_state_(false), loaded_state_(false), not_optimizable_(false)
{}

void VulkanReferencedResourceConsumerBase::Process_vkQueueSubmit(const ApiCallInfo& call_info,
                                                                 VkResult           returnValue,
                                                                 format::HandleId   queue,
                                                                 uint32_t           submitCount,
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

void VulkanReferencedResourceConsumerBase::Process_vkQueueSubmit2(const ApiCallInfo& call_info,
                                                                  VkResult           returnValue,
                                                                  format::HandleId   queue,
                                                                  uint32_t           submitCount,
                                                                  StructPointerDecoder<Decoded_VkSubmitInfo2>* pSubmits,
                                                                  format::HandleId                             fence)
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
            size_t     command_buffer_count = submits[i].pCommandBufferInfos->GetLength();
            const auto command_buffers      = submits[i].pCommandBufferInfos->GetMetaStructPointer();

            for (size_t j = 0; j < command_buffer_count; ++j)
            {
                table_.ProcessUserSubmission(command_buffers[j].commandBuffer);
            }
        }
    }
}

void VulkanReferencedResourceConsumerBase::Process_vkCreateBuffer(
    const ApiCallInfo&                                   call_info,
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
            GFXRECON_LOG_INFO("File does not contain a state block to optimize");
            not_optimizable_ = true;
        }
    }
}

void VulkanReferencedResourceConsumerBase::Process_vkCreateBufferView(
    const ApiCallInfo&                                    call_info,
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
    const ApiCallInfo&                                   call_info,
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
            GFXRECON_LOG_INFO("File does not contain a state block to optimize");
            not_optimizable_ = true;
        }
    }
}

void VulkanReferencedResourceConsumerBase::Process_vkCreateImageView(
    const ApiCallInfo&                                   call_info,
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
    const ApiCallInfo&                                     call_info,
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
    const ApiCallInfo&                                             call_info,
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
    const ApiCallInfo&                                                  call_info,
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
    const ApiCallInfo&                                                  call_info,
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

void VulkanReferencedResourceConsumerBase::Process_vkCreateAccelerationStructureKHR(
    const ApiCallInfo&                                                  call_info,
    VkResult                                                            returnValue,
    format::HandleId                                                    device,
    StructPointerDecoder<Decoded_VkAccelerationStructureCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*                pAllocator,
    HandlePointerDecoder<VkAccelerationStructureKHR>*                   pAccelerationStructure)
{
    GFXRECON_UNREFERENCED_PARAMETER(call_info);
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);

    if (!pCreateInfo->IsNull() && pCreateInfo->HasData())
    {
        const auto meta_create_info = pCreateInfo->GetMetaStructPointer();

        table_.AddResource(*pAccelerationStructure->GetPointer());
        table_.AddResource(*pAccelerationStructure->GetPointer(), meta_create_info->buffer, true);
    }
}

void VulkanReferencedResourceConsumerBase::ProcessSetOpaqueAddressCommand(format::HandleId device_id,
                                                                          format::HandleId object_id,
                                                                          uint64_t         address)
{
    GFXRECON_UNREFERENCED_PARAMETER(device_id);

    dev_address_to_resource_map[object_id] = address;
}

void VulkanReferencedResourceConsumerBase::Process_vkBindBufferMemory(const ApiCallInfo& call_info,
                                                                      VkResult           returnValue,
                                                                      format::HandleId   device,
                                                                      format::HandleId   buffer,
                                                                      format::HandleId   memory,
                                                                      VkDeviceSize       memoryOffset)
{
    GFXRECON_UNREFERENCED_PARAMETER(call_info);
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);
    GFXRECON_UNREFERENCED_PARAMETER(device);

    const auto dev_mem_dev_addr = dev_address_to_resource_map.find(memory);
    if (dev_mem_dev_addr != dev_address_to_resource_map.end())
    {
        const VkDeviceAddress address       = dev_mem_dev_addr->second + memoryOffset;
        dev_address_to_buffers_map[address] = buffer;
    }
}

void VulkanReferencedResourceConsumerBase::Process_vkCmdTraceRaysKHR(
    const ApiCallInfo&                                             call_info,
    format::HandleId                                               commandBuffer,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pRaygenShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pMissShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pHitShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pCallableShaderBindingTable,
    uint32_t                                                       width,
    uint32_t                                                       height,
    uint32_t                                                       depth)
{
    GFXRECON_UNREFERENCED_PARAMETER(call_info);
    GFXRECON_UNREFERENCED_PARAMETER(width);
    GFXRECON_UNREFERENCED_PARAMETER(height);
    GFXRECON_UNREFERENCED_PARAMETER(depth);

    if (!pRaygenShaderBindingTable->IsNull() && pRaygenShaderBindingTable->HasData())
    {
        const Decoded_VkStridedDeviceAddressRegionKHR* meta = pRaygenShaderBindingTable->GetMetaStructPointer();
        const auto buffer = dev_address_to_buffers_map.find(meta->decoded_value->deviceAddress);
        if (buffer != dev_address_to_buffers_map.end())
        {
            table_.AddResourceToUser(commandBuffer, buffer->second);
        }
    }

    if (!pMissShaderBindingTable->IsNull() && pMissShaderBindingTable->HasData())
    {
        const Decoded_VkStridedDeviceAddressRegionKHR* meta = pMissShaderBindingTable->GetMetaStructPointer();
        const auto buffer = dev_address_to_buffers_map.find(meta->decoded_value->deviceAddress);
        if (buffer != dev_address_to_buffers_map.end())
        {
            table_.AddResourceToUser(commandBuffer, buffer->second);
        }
    }

    if (!pHitShaderBindingTable->IsNull() && pHitShaderBindingTable->HasData())
    {
        const Decoded_VkStridedDeviceAddressRegionKHR* meta = pHitShaderBindingTable->GetMetaStructPointer();
        const auto buffer = dev_address_to_buffers_map.find(meta->decoded_value->deviceAddress);
        if (buffer != dev_address_to_buffers_map.end())
        {
            table_.AddResourceToUser(commandBuffer, buffer->second);
        }
    }

    if (!pCallableShaderBindingTable->IsNull() && pCallableShaderBindingTable->HasData())
    {
        const Decoded_VkStridedDeviceAddressRegionKHR* meta = pCallableShaderBindingTable->GetMetaStructPointer();
        const auto buffer = dev_address_to_buffers_map.find(meta->decoded_value->deviceAddress);
        if (buffer != dev_address_to_buffers_map.end())
        {
            table_.AddResourceToUser(commandBuffer, buffer->second);
        }
    }
}

void VulkanReferencedResourceConsumerBase::Process_vkDestroyDescriptorPool(
    const ApiCallInfo&                                   call_info,
    format::HandleId                                     device,
    format::HandleId                                     descriptorPool,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);

    table_.ClearContainers(descriptorPool);
}

void VulkanReferencedResourceConsumerBase::Process_vkResetDescriptorPool(const ApiCallInfo&         call_info,
                                                                         VkResult                   returnValue,
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
    const ApiCallInfo&                                         call_info,
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
    const ApiCallInfo&                     call_info,
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
    const ApiCallInfo&                                  call_info,
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
                case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK:
                    // Descriptor types that do not need to be tracked.
                    break;
                case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
                case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
                case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
                case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
                {
                    const auto image_info = meta_writes[i].pImageInfo;
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
                    const auto buffer_info = meta_writes[i].pBufferInfo;
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
                    const auto& views = meta_writes[i].pTexelBufferView;

                    if (!views.IsNull() && views.HasData())
                    {
                        AddResourcesToContainer(meta_writes[i].dstSet,
                                                writes[i].dstBinding,
                                                writes[i].dstArrayElement,
                                                writes[i].descriptorCount,
                                                views.GetPointer());
                    }

                    break;
                }
                case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR:
                {
                    const auto* accel_struct_writes =
                        GetPNextMetaStruct<Decoded_VkWriteDescriptorSetAccelerationStructureKHR>(meta_writes[i].pNext);
                    if (accel_struct_writes != nullptr)
                    {
                        const auto& accel_structs = accel_struct_writes->pAccelerationStructures;
                        if (!accel_structs.IsNull() && accel_structs.HasData())
                        {
                            AddResourcesToContainer(meta_writes[i].dstSet,
                                                    writes[i].dstBinding,
                                                    writes[i].dstArrayElement,
                                                    writes[i].descriptorCount,
                                                    accel_structs.GetPointer());
                        }
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
    const ApiCallInfo&               call_info,
    format::HandleId                 device,
    format::HandleId                 descriptorSet,
    format::HandleId                 descriptorUpdateTemplate,
    DescriptorUpdateTemplateDecoder* pData)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);

    UpdateDescriptorSetWithTemplate(descriptorSet, descriptorUpdateTemplate, pData);
}

void VulkanReferencedResourceConsumerBase::Process_vkCmdPushDescriptorSetWithTemplateKHR(
    const ApiCallInfo&               call_info,
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

void VulkanReferencedResourceConsumerBase::Process_vkCmdPushDescriptorSetWithTemplate2KHR(
    const ApiCallInfo&                                                 call_info,
    format::HandleId                                                   commandBuffer,
    StructPointerDecoder<Decoded_VkPushDescriptorSetWithTemplateInfo>* pPushDescriptorSetWithTemplateInfo)
{
    Decoded_VkPushDescriptorSetWithTemplateInfo* info = pPushDescriptorSetWithTemplateInfo->GetMetaStructPointer();
    format::HandleId                             descriptorUpdateTemplate = info->descriptorUpdateTemplate;
    DescriptorUpdateTemplateDecoder              pData                    = info->pData;

    PushDescriptorSetWithTemplate(commandBuffer, descriptorUpdateTemplate, &pData);
}

void VulkanReferencedResourceConsumerBase::Process_vkUpdateDescriptorSetWithTemplateKHR(
    const ApiCallInfo&               call_info,
    format::HandleId                 device,
    format::HandleId                 descriptorSet,
    format::HandleId                 descriptorUpdateTemplate,
    DescriptorUpdateTemplateDecoder* pData)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);

    UpdateDescriptorSetWithTemplate(descriptorSet, descriptorUpdateTemplate, pData);
}

void VulkanReferencedResourceConsumerBase::Process_vkDestroyCommandPool(
    const ApiCallInfo&                                   call_info,
    format::HandleId                                     device,
    format::HandleId                                     commandPool,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);

    table_.ClearUsers(commandPool);
}

void VulkanReferencedResourceConsumerBase::Process_vkResetCommandPool(const ApiCallInfo&      call_info,
                                                                      VkResult                returnValue,
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
    const ApiCallInfo&                                         call_info,
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
    const ApiCallInfo&                     call_info,
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
    const ApiCallInfo&                                      call_info,
    VkResult                                                returnValue,
    format::HandleId                                        commandBuffer,
    StructPointerDecoder<Decoded_VkCommandBufferBeginInfo>* pBeginInfo)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);
    GFXRECON_UNREFERENCED_PARAMETER(pBeginInfo);

    table_.ResetUser(commandBuffer);
}

void VulkanReferencedResourceConsumerBase::Process_vkResetCommandBuffer(const ApiCallInfo&        call_info,
                                                                        VkResult                  returnValue,
                                                                        format::HandleId          commandBuffer,
                                                                        VkCommandBufferResetFlags flags)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);
    GFXRECON_UNREFERENCED_PARAMETER(flags);

    table_.ResetUser(commandBuffer);
}

void VulkanReferencedResourceConsumerBase::ProcessSetTlasToBlasRelationCommand(
    format::HandleId tlas, const std::vector<format::HandleId>& blases)
{
    if (blases.size())
    {
        for (const auto& blas : blases)
        {
            table_.AddResource(tlas, blas, true);
        }
    }
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

void VulkanReferencedResourceConsumerBase::AddResourcesToContainer(format::HandleId        container_id,
                                                                   int32_t                 binding,
                                                                   uint32_t                element,
                                                                   uint32_t                count,
                                                                   const format::HandleId* resource_ids)
{
    assert(resource_ids != nullptr);

    AddDescriptorToContainer(
        container_id, binding, element, count, [&](uint32_t index, int32_t current_binding, uint32_t current_element) {
            table_.AddResourceToContainer(container_id, resource_ids[index], current_binding, current_element);
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
            else if (entry_info.type == VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR)
            {
                template_info.acceleration_structure_infos.emplace_back(std::move(entry_info));
            }
        }

        template_infos_.emplace(template_id, std::move(template_info));
    }
}

void VulkanReferencedResourceConsumerBase::UpdateDescriptorSetWithTemplate(
    format::HandleId container_id, format::HandleId template_id, const DescriptorUpdateTemplateDecoder* decoder)
{
    assert(decoder != nullptr);

    auto image_info_count             = static_cast<uint32_t>(decoder->GetImageInfoCount());
    auto buffer_info_count            = static_cast<uint32_t>(decoder->GetBufferInfoCount());
    auto texel_buffer_view_count      = static_cast<uint32_t>(decoder->GetTexelBufferViewCount());
    auto acceleration_structure_count = static_cast<uint32_t>(decoder->GetAccelerationStructureKHRCount());

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

                AddResourcesToContainer(container_id, info.binding, info.array_element, info.count, &view_ids[offset]);

                offset += info.count;
            }
        }

        if (acceleration_structure_count > 0)
        {
            uint32_t offset = 0;
            auto     as_ids = decoder->GetAccelerationStructureKHRHandleIdsPointer();
            assert(as_ids != nullptr);

            for (const auto& info : template_info.acceleration_structure_infos)
            {
                assert((offset + info.count) <= acceleration_structure_count);

                if ((offset + info.count) > acceleration_structure_count)
                {
                    GFXRECON_LOG_ERROR("Descriptor update template entry count exceeds the total number of entries in"
                                       " the update template data.");
                    break;
                }

                AddResourcesToContainer(container_id, info.binding, info.array_element, info.count, &as_ids[offset]);

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
