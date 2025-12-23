/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2020 LunarG, Inc.
** Copyright (c) 2023 Advanced Micro Devices, Inc. All rights reserved.
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

#include "encode/custom_vulkan_api_call_encoders.h"

#include "encode/custom_vulkan_encoder_commands.h"
#include "encode/custom_vulkan_struct_encoders.h"
#include "encode/custom_vulkan_struct_handle_wrappers.h"
#include "encode/descriptor_update_template_info.h"
#include "encode/parameter_encoder.h"
#include "encode/struct_pointer_encoder.h"
#include "encode/vulkan_capture_manager.h"
#include "encode/vulkan_handle_wrapper_util.h"
#include "format/api_call_id.h"
#include "generated/generated_vulkan_struct_encoders.h"
#include "generated/generated_vulkan_struct_handle_wrappers.h"
#include "util/defines.h"

#include <cassert>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

static const void* UnwrapDescriptorUpdateTemplateInfoHandles(const UpdateTemplateInfo* info,
                                                             const void*               data,
                                                             HandleUnwrapMemory*       unwrap_memory)
{
    if (info != nullptr)
    {
        uint8_t* unwrapped_data = unwrap_memory->GetBuffer(info->max_size);
        auto     bytes          = reinterpret_cast<const uint8_t*>(data);

        assert((unwrapped_data != nullptr) && (bytes != nullptr));

        // Process VkDescriptorImageInfo
        for (const auto& entry_info : info->image_info)
        {
            for (size_t i = 0; i < entry_info.count; ++i)
            {
                size_t offset          = entry_info.offset + (entry_info.stride * i);
                auto   unwrapped_entry = reinterpret_cast<VkDescriptorImageInfo*>(unwrapped_data + offset);

                memcpy(unwrapped_entry, bytes + offset, sizeof(VkDescriptorImageInfo));
                vulkan_wrappers::UnwrapStructHandles(entry_info.type, unwrapped_entry, unwrap_memory);
            }
        }

        // Process VkDescriptorBufferInfo
        for (const auto& entry_info : info->buffer_info)
        {
            for (size_t i = 0; i < entry_info.count; ++i)
            {
                size_t offset          = entry_info.offset + (entry_info.stride * i);
                auto   unwrapped_entry = reinterpret_cast<VkDescriptorBufferInfo*>(unwrapped_data + offset);

                memcpy(unwrapped_entry, bytes + offset, sizeof(VkDescriptorBufferInfo));
                vulkan_wrappers::UnwrapStructHandles(unwrapped_entry, unwrap_memory);
            }
        }

        // Process VkBufferView
        for (const auto& entry_info : info->texel_buffer_view)
        {
            for (size_t i = 0; i < entry_info.count; ++i)
            {
                size_t offset          = entry_info.offset + (entry_info.stride * i);
                auto   unwrapped_entry = reinterpret_cast<VkBufferView*>(unwrapped_data + offset);
                auto   entry           = reinterpret_cast<const VkBufferView*>(bytes + offset);

                *unwrapped_entry = (*entry);
            }
        }

        // Process VkAccelerationStructureKHR
        for (const auto& entry_info : info->acceleration_structure_khr)
        {
            for (size_t i = 0; i < entry_info.count; ++i)
            {
                size_t offset          = entry_info.offset + (entry_info.stride * i);
                auto   unwrapped_entry = reinterpret_cast<VkAccelerationStructureKHR*>(unwrapped_data + offset);
                auto   entry           = reinterpret_cast<const VkAccelerationStructureKHR*>(bytes + offset);

                *unwrapped_entry = (*entry);
            }
        }

        // Process VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK data
        for (const auto& entry_info : info->inline_uniform_block)
        {
            memcpy(unwrapped_data + entry_info.offset, bytes + entry_info.offset, entry_info.count);
        }
        return unwrapped_data;
    }

    return data;
}

static void EncodeDescriptorUpdateTemplateInfo(VulkanCaptureManager*     manager,
                                               ParameterEncoder*         encoder,
                                               const UpdateTemplateInfo* info,
                                               const void*               data)
{
    assert((manager != nullptr) && (encoder != nullptr));

    if (info != nullptr)
    {
        // Write pointer attributes as if we were processing a struct pointer.
        encoder->EncodeStructPtrPreamble(data);

        // The update template data will be written as tightly packed arrays of VkDescriptorImageInfo,
        // VkDescriptorBufferInfo, VkBufferView, and VkAccelerationStructureKHR types.  There will be one array per
        // descriptor update entry.  For the required entries, we will write the total number of entries of each type
        // before we write the entries, so that the decoder will know up front how much memory it needs to allocate for
        // decoding. Optional entries must be encoded after the required entries, and must encode the number of elements
        // in the array as well as VkDescriptorType.
        encoder->EncodeSizeTValue(info->image_info_count);
        encoder->EncodeSizeTValue(info->buffer_info_count);
        encoder->EncodeSizeTValue(info->texel_buffer_view_count);

        // Write the individual template update entries, sorted by type, as tightly packed arrays.
        const uint8_t* bytes = reinterpret_cast<const uint8_t*>(data);
        // Process VkDescriptorImageInfo
        for (const auto& entry_info : info->image_info)
        {
            for (size_t i = 0; i < entry_info.count; ++i)
            {
                size_t                       offset = entry_info.offset + (entry_info.stride * i);
                const VkDescriptorImageInfo* entry  = reinterpret_cast<const VkDescriptorImageInfo*>(bytes + offset);
                EncodeStruct(encoder, entry_info.type, (*entry));
            }
        }

        // Process VkDescriptorBufferInfo
        for (const auto& entry_info : info->buffer_info)
        {
            for (size_t i = 0; i < entry_info.count; ++i)
            {
                size_t                        offset = entry_info.offset + (entry_info.stride * i);
                const VkDescriptorBufferInfo* entry  = reinterpret_cast<const VkDescriptorBufferInfo*>(bytes + offset);
                EncodeStruct(encoder, (*entry));
            }
        }

        // Process VkBufferView
        for (const auto& entry_info : info->texel_buffer_view)
        {
            for (size_t i = 0; i < entry_info.count; ++i)
            {
                size_t              offset = entry_info.offset + (entry_info.stride * i);
                const VkBufferView* entry  = reinterpret_cast<const VkBufferView*>(bytes + offset);
                encoder->EncodeVulkanHandleValue<vulkan_wrappers::BufferViewWrapper>(*entry);
            }
        }

        // Process VkAccelerationStructureKHR. This data is optional in the capture file, and must come after the
        // required entries. Data is only written to the capture file if info->acceleration_structure_khr_count > 0.
        if (info->acceleration_structure_khr_count > 0)
        {
            encoder->EncodeSizeTValue(info->acceleration_structure_khr_count);
            encoder->EncodeEnumValue(VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR);
            for (const auto& entry_info : info->acceleration_structure_khr)
            {
                for (size_t i = 0; i < entry_info.count; ++i)
                {
                    size_t                            offset = entry_info.offset + (entry_info.stride * i);
                    const VkAccelerationStructureKHR* entry =
                        reinterpret_cast<const VkAccelerationStructureKHR*>(bytes + offset);
                    encoder->EncodeVulkanHandleValue<vulkan_wrappers::AccelerationStructureKHRWrapper>(*entry);
                }
            }
        }

        // Process raw byte-arrays for VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK
        if (info->inline_uniform_block_count > 0)
        {
            encoder->EncodeSizeTValue(info->inline_uniform_block_count);
            encoder->EncodeEnumValue(VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK);

            for (const auto& entry_info : info->inline_uniform_block)
            {
                encoder->EncodeRawBytes(bytes + entry_info.offset, entry_info.count);
            }
        }
    }
    else
    {
        encoder->EncodeStructArrayPreamble(data, 0);
    }
}

VKAPI_ATTR void VKAPI_CALL vkUpdateDescriptorSetWithTemplate(VkDevice                   device,
                                                             VkDescriptorSet            descriptorSet,
                                                             VkDescriptorUpdateTemplate descriptorUpdateTemplate,
                                                             const void*                pData)
{
    VulkanCaptureManager* manager = VulkanCaptureManager::Get();
    assert(manager != nullptr);

    auto api_call_lock = VulkanCaptureManager::AcquireSharedApiCallLock();

    const UpdateTemplateInfo* info = nullptr;
    if (!manager->GetDescriptorUpdateTemplateInfo(descriptorUpdateTemplate, &info))
    {
        GFXRECON_LOG_DEBUG("Descriptor update template info not found");
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplate>::Dispatch(
        manager, device, descriptorSet, descriptorUpdateTemplate, pData);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplate);
    if (encoder)
    {
        encoder->EncodeVulkanHandleValue<vulkan_wrappers::DeviceWrapper>(device);
        encoder->EncodeVulkanHandleValue<vulkan_wrappers::DescriptorSetWrapper>(descriptorSet);
        encoder->EncodeVulkanHandleValue<vulkan_wrappers::DescriptorUpdateTemplateWrapper>(descriptorUpdateTemplate);

        EncodeDescriptorUpdateTemplateInfo(manager, encoder, info, pData);

        manager->EndApiCallCapture();
    }

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    auto pData_unwrapped      = UnwrapDescriptorUpdateTemplateInfoHandles(info, pData, handle_unwrap_memory);

    vulkan_wrappers::GetDeviceTable(device)->UpdateDescriptorSetWithTemplate(
        device, descriptorSet, descriptorUpdateTemplate, pData_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplate>::Dispatch(
        manager, device, descriptorSet, descriptorUpdateTemplate, pData);
}

VKAPI_ATTR void VKAPI_CALL vkCmdPushDescriptorSetWithTemplate(VkCommandBuffer            commandBuffer,
                                                              VkDescriptorUpdateTemplate descriptorUpdateTemplate,
                                                              VkPipelineLayout           layout,
                                                              uint32_t                   set,
                                                              const void*                pData)
{
    VulkanCaptureManager* manager = VulkanCaptureManager::Get();
    assert(manager != nullptr);

    auto api_call_lock = VulkanCaptureManager::AcquireSharedApiCallLock();

    const UpdateTemplateInfo* info = nullptr;
    if (!manager->GetDescriptorUpdateTemplateInfo(descriptorUpdateTemplate, &info))
    {
        GFXRECON_LOG_DEBUG("Descriptor update template info not found");
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdPushDescriptorSetWithTemplate>::Dispatch(
        manager, commandBuffer, descriptorUpdateTemplate, layout, set, pData);

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdPushDescriptorSetWithTemplate);
    if (encoder)
    {
        encoder->EncodeVulkanHandleValue<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
        encoder->EncodeVulkanHandleValue<vulkan_wrappers::DescriptorUpdateTemplateWrapper>(descriptorUpdateTemplate);
        encoder->EncodeVulkanHandleValue<vulkan_wrappers::PipelineLayoutWrapper>(layout);
        encoder->EncodeUInt32Value(set);

        EncodeDescriptorUpdateTemplateInfo(manager, encoder, info, pData);

        manager->EndCommandApiCallCapture(commandBuffer);
    }

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    auto pData_unwrapped      = UnwrapDescriptorUpdateTemplateInfoHandles(info, pData, handle_unwrap_memory);

    vulkan_wrappers::GetDeviceTable(commandBuffer)
        ->CmdPushDescriptorSetWithTemplate(commandBuffer, descriptorUpdateTemplate, layout, set, pData_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPushDescriptorSetWithTemplate>::Dispatch(
        manager, commandBuffer, descriptorUpdateTemplate, layout, set, pData);
}

VKAPI_ATTR void VKAPI_CALL vkCmdPushDescriptorSetWithTemplateKHR(VkCommandBuffer            commandBuffer,
                                                                 VkDescriptorUpdateTemplate descriptorUpdateTemplate,
                                                                 VkPipelineLayout           layout,
                                                                 uint32_t                   set,
                                                                 const void*                pData)
{
    VulkanCaptureManager* manager = VulkanCaptureManager::Get();
    assert(manager != nullptr);

    auto api_call_lock = VulkanCaptureManager::AcquireSharedApiCallLock();

    const UpdateTemplateInfo* info = nullptr;
    if (!manager->GetDescriptorUpdateTemplateInfo(descriptorUpdateTemplate, &info))
    {
        GFXRECON_LOG_DEBUG("Descriptor update template info not found");
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdPushDescriptorSetWithTemplateKHR>::Dispatch(
        manager, commandBuffer, descriptorUpdateTemplate, layout, set, pData);

    auto encoder =
        manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdPushDescriptorSetWithTemplateKHR);
    if (encoder)
    {
        encoder->EncodeVulkanHandleValue<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
        encoder->EncodeVulkanHandleValue<vulkan_wrappers::DescriptorUpdateTemplateWrapper>(descriptorUpdateTemplate);
        encoder->EncodeVulkanHandleValue<vulkan_wrappers::PipelineLayoutWrapper>(layout);
        encoder->EncodeUInt32Value(set);

        EncodeDescriptorUpdateTemplateInfo(manager, encoder, info, pData);

        manager->EndCommandApiCallCapture(commandBuffer);
    }

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    auto pData_unwrapped      = UnwrapDescriptorUpdateTemplateInfoHandles(info, pData, handle_unwrap_memory);

    vulkan_wrappers::GetDeviceTable(commandBuffer)
        ->CmdPushDescriptorSetWithTemplateKHR(commandBuffer, descriptorUpdateTemplate, layout, set, pData_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPushDescriptorSetWithTemplateKHR>::Dispatch(
        manager, commandBuffer, descriptorUpdateTemplate, layout, set, pData);
}

VKAPI_ATTR void VKAPI_CALL vkCmdPushDescriptorSetWithTemplate2(
    VkCommandBuffer commandBuffer, const VkPushDescriptorSetWithTemplateInfo* pPushDescriptorSetWithTemplateInfo)
{
    VulkanCaptureManager* manager = VulkanCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);

    auto api_call_lock = VulkanCaptureManager::AcquireSharedApiCallLock();

    const UpdateTemplateInfo* info = nullptr;
    if (!manager->GetDescriptorUpdateTemplateInfo(pPushDescriptorSetWithTemplateInfo->descriptorUpdateTemplate, &info))
    {
        GFXRECON_LOG_DEBUG("Descriptor update template info not found");
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdPushDescriptorSetWithTemplate2>::Dispatch(
        manager, commandBuffer, pPushDescriptorSetWithTemplateInfo);

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdPushDescriptorSetWithTemplate2);
    if (encoder)
    {
        encoder->EncodeVulkanHandleValue<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
        EncodeStructPtr(encoder, pPushDescriptorSetWithTemplateInfo);

        EncodeDescriptorUpdateTemplateInfo(manager, encoder, info, pPushDescriptorSetWithTemplateInfo->pData);

        manager->EndCommandApiCallCapture(commandBuffer);
    }

    auto handle_unwrap_memory = manager->GetHandleUnwrapMemory();
    auto pData_unwrapped      = UnwrapDescriptorUpdateTemplateInfoHandles(
        info, pPushDescriptorSetWithTemplateInfo->pData, handle_unwrap_memory);

    vulkan_wrappers::GetDeviceTable(commandBuffer)
        ->CmdPushDescriptorSetWithTemplate2(commandBuffer, pPushDescriptorSetWithTemplateInfo);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPushDescriptorSetWithTemplate2>::Dispatch(
        manager, commandBuffer, pPushDescriptorSetWithTemplateInfo);
}

VKAPI_ATTR void VKAPI_CALL vkCmdPushDescriptorSetWithTemplate2KHR(
    VkCommandBuffer commandBuffer, const VkPushDescriptorSetWithTemplateInfoKHR* pPushDescriptorSetWithTemplateInfo)
{
    VulkanCaptureManager* manager = VulkanCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);

    auto api_call_lock = VulkanCaptureManager::AcquireSharedApiCallLock();

    const UpdateTemplateInfo* info = nullptr;
    if (!manager->GetDescriptorUpdateTemplateInfo(pPushDescriptorSetWithTemplateInfo->descriptorUpdateTemplate, &info))
    {
        GFXRECON_LOG_DEBUG("Descriptor update template info not found");
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdPushDescriptorSetWithTemplate2KHR>::Dispatch(
        manager, commandBuffer, pPushDescriptorSetWithTemplateInfo);

    auto encoder =
        manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdPushDescriptorSetWithTemplate2KHR);
    if (encoder)
    {
        encoder->EncodeVulkanHandleValue<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
        EncodeStructPtr(encoder, pPushDescriptorSetWithTemplateInfo);

        EncodeDescriptorUpdateTemplateInfo(manager, encoder, info, pPushDescriptorSetWithTemplateInfo->pData);

        manager->EndCommandApiCallCapture(commandBuffer);
    }

    auto handle_unwrap_memory = manager->GetHandleUnwrapMemory();
    auto pData_unwrapped      = UnwrapDescriptorUpdateTemplateInfoHandles(
        info, pPushDescriptorSetWithTemplateInfo->pData, handle_unwrap_memory);

    vulkan_wrappers::GetDeviceTable(commandBuffer)
        ->CmdPushDescriptorSetWithTemplate2KHR(commandBuffer, pPushDescriptorSetWithTemplateInfo);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPushDescriptorSetWithTemplate2KHR>::Dispatch(
        manager, commandBuffer, pPushDescriptorSetWithTemplateInfo);
}

VKAPI_ATTR void VKAPI_CALL vkUpdateDescriptorSetWithTemplateKHR(VkDevice                   device,
                                                                VkDescriptorSet            descriptorSet,
                                                                VkDescriptorUpdateTemplate descriptorUpdateTemplate,
                                                                const void*                pData)
{
    VulkanCaptureManager* manager = VulkanCaptureManager::Get();
    assert(manager != nullptr);

    auto api_call_lock = VulkanCaptureManager::AcquireSharedApiCallLock();

    const UpdateTemplateInfo* info = nullptr;
    if (!manager->GetDescriptorUpdateTemplateInfo(descriptorUpdateTemplate, &info))
    {
        GFXRECON_LOG_DEBUG("Descriptor update template info not found");
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplateKHR>::Dispatch(
        manager, device, descriptorSet, descriptorUpdateTemplate, pData);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplateKHR);
    if (encoder)
    {
        encoder->EncodeVulkanHandleValue<vulkan_wrappers::DeviceWrapper>(device);
        encoder->EncodeVulkanHandleValue<vulkan_wrappers::DescriptorSetWrapper>(descriptorSet);
        encoder->EncodeVulkanHandleValue<vulkan_wrappers::DescriptorUpdateTemplateWrapper>(descriptorUpdateTemplate);

        EncodeDescriptorUpdateTemplateInfo(manager, encoder, info, pData);

        manager->EndApiCallCapture();
    }

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    auto pData_unwrapped      = UnwrapDescriptorUpdateTemplateInfoHandles(info, pData, handle_unwrap_memory);

    vulkan_wrappers::GetDeviceTable(device)->UpdateDescriptorSetWithTemplateKHR(
        device, descriptorSet, descriptorUpdateTemplate, pData_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplateKHR>::Dispatch(
        manager, device, descriptorSet, descriptorUpdateTemplate, pData);
}

VKAPI_ATTR VkResult VKAPI_CALL
vkBuildAccelerationStructuresKHR(VkDevice                                               device,
                                 VkDeferredOperationKHR                                 deferredOperation,
                                 uint32_t                                               infoCount,
                                 const VkAccelerationStructureBuildGeometryInfoKHR*     pInfos,
                                 const VkAccelerationStructureBuildRangeInfoKHR* const* ppRangeInfos)
{
    // TODO
    GFXRECON_LOG_ERROR("BuildAccelerationStructuresKHR encoding is not supported");
    return vulkan_wrappers::GetDeviceTable(device)->BuildAccelerationStructuresKHR(
        device, deferredOperation, infoCount, pInfos, ppRangeInfos);
}

VKAPI_ATTR VkResult VKAPI_CALL vkCopyAccelerationStructureKHR(VkDevice               device,
                                                              VkDeferredOperationKHR deferredOperation,
                                                              const VkCopyAccelerationStructureInfoKHR* pInfo)
{
    // TODO
    GFXRECON_LOG_ERROR("CopyAccelerationStructureKHR encoding is not supported");
    return vulkan_wrappers::GetDeviceTable(device)->CopyAccelerationStructureKHR(device, deferredOperation, pInfo);
}

VKAPI_ATTR uint64_t VKAPI_CALL vkGetBlockIndexGFXR()
{
    VulkanCaptureManager* manager = VulkanCaptureManager::Get();
    return manager->GetBlockIndex();
}

VKAPI_ATTR void VKAPI_CALL vkDumpAssetsGFXR()
{
    VulkanCaptureManager* manager = VulkanCaptureManager::Get();
    manager->SetWriteAssets();
}

VKAPI_ATTR VkResult VKAPI_CALL vkCreateGraphicsPipelines(VkDevice                            device,
                                                         VkPipelineCache                     pipelineCache,
                                                         uint32_t                            createInfoCount,
                                                         const VkGraphicsPipelineCreateInfo* pCreateInfos,
                                                         const VkAllocationCallbacks*        pAllocator,
                                                         VkPipeline*                         pPipelines)
{
    if (!VulkanCaptureManager::Get()->GetAllowPipelineCompileRequired())
    {
        for (uint32_t i = 0; i < createInfoCount; ++i)
        {
            if (pCreateInfos[i].flags & VK_PIPELINE_CREATE_FAIL_ON_PIPELINE_COMPILE_REQUIRED_BIT)
            {
                for (uint32_t j = 0; j < createInfoCount; ++j)
                {
                    pPipelines[j] = VK_NULL_HANDLE;
                }
                VulkanCaptureManager::Get()->WriteAnnotation(
                    format::AnnotationType::kText, format::kAnnotationPipelineCreationAttempt, "");
                GFXRECON_LOG_WARNING_ONCE(
                    "VK_PIPELINE_CREATE_FAIL_ON_PIPELINE_COMPILE_REQUIRED_BIT isn't suppported. Skip dispatch "
                    "CreateGraphicsPipelines and not record the call. Force to return VK_PIPELINE_COMPILE_REQUIRED.");
                return VK_PIPELINE_COMPILE_REQUIRED;
            }
        }
    }

    auto force_command_serialization = VulkanCaptureManager::Get()->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = VulkanCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = VulkanCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateGraphicsPipelines>::Dispatch(
        VulkanCaptureManager::Get(), device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);

    auto                                handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    const VkGraphicsPipelineCreateInfo* pCreateInfos_unwrapped =
        vulkan_wrappers::UnwrapStructArrayHandles(pCreateInfos, createInfoCount, handle_unwrap_memory);

    VkResult result = vulkan_wrappers::GetDeviceTable(device)->CreateGraphicsPipelines(
        device, pipelineCache, createInfoCount, pCreateInfos_unwrapped, pAllocator, pPipelines);

    if (result >= 0)
    {
        vulkan_wrappers::CreateWrappedHandles<vulkan_wrappers::DeviceWrapper,
                                              vulkan_wrappers::PipelineCacheWrapper,
                                              vulkan_wrappers::PipelineWrapper>(
            device, pipelineCache, pPipelines, createInfoCount, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder =
        VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCreateGraphicsPipelines);
    if (encoder)
    {
        encoder->EncodeVulkanHandleValue<vulkan_wrappers::DeviceWrapper>(device);
        encoder->EncodeVulkanHandleValue<vulkan_wrappers::PipelineCacheWrapper>(pipelineCache);
        encoder->EncodeUInt32Value(createInfoCount);
        EncodeStructArray(encoder, pCreateInfos, createInfoCount);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeVulkanHandleArray<vulkan_wrappers::PipelineWrapper>(
            pPipelines, createInfoCount, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()
            ->EndGroupCreateApiCallCapture<VkDevice,
                                           VkPipelineCache,
                                           vulkan_wrappers::PipelineWrapper,
                                           VkGraphicsPipelineCreateInfo>(
                result, device, pipelineCache, createInfoCount, pPipelines, pCreateInfos);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateGraphicsPipelines>::Dispatch(VulkanCaptureManager::Get(),
                                                                                          result,
                                                                                          device,
                                                                                          pipelineCache,
                                                                                          createInfoCount,
                                                                                          pCreateInfos,
                                                                                          pAllocator,
                                                                                          pPipelines);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL vkCreateComputePipelines(VkDevice                           device,
                                                        VkPipelineCache                    pipelineCache,
                                                        uint32_t                           createInfoCount,
                                                        const VkComputePipelineCreateInfo* pCreateInfos,
                                                        const VkAllocationCallbacks*       pAllocator,
                                                        VkPipeline*                        pPipelines)
{
    if (!VulkanCaptureManager::Get()->GetAllowPipelineCompileRequired())
    {
        for (uint32_t i = 0; i < createInfoCount; ++i)
        {
            if (pCreateInfos[i].flags & VK_PIPELINE_CREATE_FAIL_ON_PIPELINE_COMPILE_REQUIRED_BIT)
            {
                for (uint32_t j = 0; j < createInfoCount; ++j)
                {
                    pPipelines[j] = VK_NULL_HANDLE;
                }
                VulkanCaptureManager::Get()->WriteAnnotation(
                    format::AnnotationType::kText, format::kAnnotationPipelineCreationAttempt, "");
                GFXRECON_LOG_WARNING_ONCE(
                    "VK_PIPELINE_CREATE_FAIL_ON_PIPELINE_COMPILE_REQUIRED_BIT isn't suppported. Skip dispatch "
                    "CreateComputePipelines and not record the call. Force to return VK_PIPELINE_COMPILE_REQUIRED.");
                return VK_PIPELINE_COMPILE_REQUIRED;
            }
        }
    }

    auto force_command_serialization = VulkanCaptureManager::Get()->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = VulkanCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = VulkanCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateComputePipelines>::Dispatch(
        VulkanCaptureManager::Get(), device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);

    auto                               handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    const VkComputePipelineCreateInfo* pCreateInfos_unwrapped =
        vulkan_wrappers::UnwrapStructArrayHandles(pCreateInfos, createInfoCount, handle_unwrap_memory);

    VkResult result = vulkan_wrappers::GetDeviceTable(device)->CreateComputePipelines(
        device, pipelineCache, createInfoCount, pCreateInfos_unwrapped, pAllocator, pPipelines);

    if (result >= 0)
    {
        vulkan_wrappers::CreateWrappedHandles<vulkan_wrappers::DeviceWrapper,
                                              vulkan_wrappers::PipelineCacheWrapper,
                                              vulkan_wrappers::PipelineWrapper>(
            device, pipelineCache, pPipelines, createInfoCount, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder =
        VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCreateComputePipelines);
    if (encoder)
    {
        encoder->EncodeVulkanHandleValue<vulkan_wrappers::DeviceWrapper>(device);
        encoder->EncodeVulkanHandleValue<vulkan_wrappers::PipelineCacheWrapper>(pipelineCache);
        encoder->EncodeUInt32Value(createInfoCount);
        EncodeStructArray(encoder, pCreateInfos, createInfoCount);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeVulkanHandleArray<vulkan_wrappers::PipelineWrapper>(
            pPipelines, createInfoCount, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()
            ->EndGroupCreateApiCallCapture<VkDevice,
                                           VkPipelineCache,
                                           vulkan_wrappers::PipelineWrapper,
                                           VkComputePipelineCreateInfo>(
                result, device, pipelineCache, createInfoCount, pPipelines, pCreateInfos);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateComputePipelines>::Dispatch(VulkanCaptureManager::Get(),
                                                                                         result,
                                                                                         device,
                                                                                         pipelineCache,
                                                                                         createInfoCount,
                                                                                         pCreateInfos,
                                                                                         pAllocator,
                                                                                         pPipelines);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL vkCreateRayTracingPipelinesNV(VkDevice                                device,
                                                             VkPipelineCache                         pipelineCache,
                                                             uint32_t                                createInfoCount,
                                                             const VkRayTracingPipelineCreateInfoNV* pCreateInfos,
                                                             const VkAllocationCallbacks*            pAllocator,
                                                             VkPipeline*                             pPipelines)
{
    if (!VulkanCaptureManager::Get()->GetAllowPipelineCompileRequired())
    {
        for (uint32_t i = 0; i < createInfoCount; ++i)
        {
            if (pCreateInfos[i].flags & VK_PIPELINE_CREATE_FAIL_ON_PIPELINE_COMPILE_REQUIRED_BIT)
            {
                for (uint32_t j = 0; j < createInfoCount; ++j)
                {
                    pPipelines[j] = VK_NULL_HANDLE;
                }
                VulkanCaptureManager::Get()->WriteAnnotation(
                    format::AnnotationType::kText, format::kAnnotationPipelineCreationAttempt, "");
                GFXRECON_LOG_WARNING_ONCE(
                    "VK_PIPELINE_CREATE_FAIL_ON_PIPELINE_COMPILE_REQUIRED_BIT isn't suppported. Skip dispatch "
                    "CreateRayTracingPipelinesNV and not record the call. Force to return "
                    "VK_PIPELINE_COMPILE_REQUIRED.");
                return VK_PIPELINE_COMPILE_REQUIRED;
            }
        }
    }

    auto force_command_serialization = VulkanCaptureManager::Get()->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = VulkanCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = VulkanCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesNV>::Dispatch(
        VulkanCaptureManager::Get(), device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);

    auto                                    handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    const VkRayTracingPipelineCreateInfoNV* pCreateInfos_unwrapped =
        vulkan_wrappers::UnwrapStructArrayHandles(pCreateInfos, createInfoCount, handle_unwrap_memory);

    VkResult result = vulkan_wrappers::GetDeviceTable(device)->CreateRayTracingPipelinesNV(
        device, pipelineCache, createInfoCount, pCreateInfos_unwrapped, pAllocator, pPipelines);

    if (result >= 0)
    {
        vulkan_wrappers::CreateWrappedHandles<vulkan_wrappers::DeviceWrapper,
                                              vulkan_wrappers::PipelineCacheWrapper,
                                              vulkan_wrappers::PipelineWrapper>(
            device, pipelineCache, pPipelines, createInfoCount, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(
        format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesNV);
    if (encoder)
    {
        encoder->EncodeVulkanHandleValue<vulkan_wrappers::DeviceWrapper>(device);
        encoder->EncodeVulkanHandleValue<vulkan_wrappers::PipelineCacheWrapper>(pipelineCache);
        encoder->EncodeUInt32Value(createInfoCount);
        EncodeStructArray(encoder, pCreateInfos, createInfoCount);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeVulkanHandleArray<vulkan_wrappers::PipelineWrapper>(
            pPipelines, createInfoCount, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()
            ->EndGroupCreateApiCallCapture<VkDevice,
                                           VkPipelineCache,
                                           vulkan_wrappers::PipelineWrapper,
                                           VkRayTracingPipelineCreateInfoNV>(
                result, device, pipelineCache, createInfoCount, pPipelines, pCreateInfos);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesNV>::Dispatch(
        VulkanCaptureManager::Get(),
        result,
        device,
        pipelineCache,
        createInfoCount,
        pCreateInfos,
        pAllocator,
        pPipelines);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL vkCreateRayTracingPipelinesKHR(VkDevice               device,
                                                              VkDeferredOperationKHR deferredOperation,
                                                              VkPipelineCache        pipelineCache,
                                                              uint32_t               createInfoCount,
                                                              const VkRayTracingPipelineCreateInfoKHR* pCreateInfos,
                                                              const VkAllocationCallbacks*             pAllocator,
                                                              VkPipeline*                              pPipelines)
{
    if (!VulkanCaptureManager::Get()->GetAllowPipelineCompileRequired())
    {
        for (uint32_t i = 0; i < createInfoCount; ++i)
        {
            if (pCreateInfos[i].flags & VK_PIPELINE_CREATE_FAIL_ON_PIPELINE_COMPILE_REQUIRED_BIT)
            {
                for (uint32_t j = 0; j < createInfoCount; ++j)
                {
                    pPipelines[j] = VK_NULL_HANDLE;
                }
                VulkanCaptureManager::Get()->WriteAnnotation(
                    format::AnnotationType::kText, format::kAnnotationPipelineCreationAttempt, "");
                GFXRECON_LOG_WARNING_ONCE(
                    "VK_PIPELINE_CREATE_FAIL_ON_PIPELINE_COMPILE_REQUIRED_BIT isn't suppported. Skip dispatch "
                    "CreateRayTracingPipelinesKHR and not record the call. Force to return "
                    "VK_PIPELINE_COMPILE_REQUIRED.");
                return VK_PIPELINE_COMPILE_REQUIRED;
            }
        }
    }

    auto force_command_serialization = VulkanCaptureManager::Get()->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = VulkanCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = VulkanCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesKHR>::Dispatch(
        VulkanCaptureManager::Get(),
        device,
        deferredOperation,
        pipelineCache,
        createInfoCount,
        pCreateInfos,
        pAllocator,
        pPipelines);

    VkResult result = VulkanCaptureManager::Get()->OverrideCreateRayTracingPipelinesKHR(
        device, deferredOperation, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto device_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceWrapper>(device);
    if (result != VK_OPERATION_DEFERRED_KHR)
    {
        // If the operation is not deferred by driver. or the system doesn't support
        // rayTracingPipelineShaderGroupHandleCaptureReplay, we don't need to delay writing the block of
        // vkCreateRayTracingPipelinesKHR to the capture file.
        //
        // If the operation is deferred by driver and the system supports
        // rayTracingPipelineShaderGroupHandleCaptureReplay, we will need to make sure opaque capture replay data for
        // pipeline shader group handles are ready when calling vkCreateRayTracingPipelinesKHR during replay. However,
        // opaque capture replay data for pipeline shader group handles needs pipeline creation to be finished so that
        // vkGetRayTracingCaptureReplayShaderGroupHandlesKHR may be used. For this reason, we will delay the writing of
        // vkCreateRayTracingPipelinesKHR block to capture file until the deferred operation is finished.

        auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(
            format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesKHR);
        if (encoder)
        {
            encoder->EncodeVulkanHandleValue<vulkan_wrappers::DeviceWrapper>(device);
            encoder->EncodeVulkanHandleValue<vulkan_wrappers::DeferredOperationKHRWrapper>(deferredOperation);
            encoder->EncodeVulkanHandleValue<vulkan_wrappers::PipelineCacheWrapper>(pipelineCache);
            encoder->EncodeUInt32Value(createInfoCount);
            EncodeStructArray(encoder, pCreateInfos, createInfoCount);
            EncodeStructPtr(encoder, pAllocator);
            encoder->EncodeVulkanHandleArray<vulkan_wrappers::PipelineWrapper>(
                pPipelines, createInfoCount, omit_output_data);
            encoder->EncodeEnumValue(result);
            VulkanCaptureManager::Get()
                ->EndGroupCreateApiCallCapture<VkDevice,
                                               VkDeferredOperationKHR,
                                               vulkan_wrappers::PipelineWrapper,
                                               VkRayTracingPipelineCreateInfoKHR>(
                    result, device, deferredOperation, createInfoCount, pPipelines, pCreateInfos);
        }
    }
    else
    {
        GFXRECON_LOG_WARNING("The operation of vkCreateRayTracingPipelinesKHR call is deferred, so the writing of "
                             "vkCreateRayTracingPipelinesKHR block to capture file will be delayed until the deferred "
                             "operation (handle = 0x%" PRIx64 ") is finished.",
                             deferredOperation);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesKHR>::Dispatch(
        VulkanCaptureManager::Get(),
        result,
        device,
        deferredOperation,
        pipelineCache,
        createInfoCount,
        pCreateInfos,
        pAllocator,
        pPipelines);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT(
    VkDevice device, const VkAccelerationStructureCaptureDescriptorDataInfoEXT* pInfo, void* pData)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(pInfo);
    GFXRECON_UNREFERENCED_PARAMETER(pData);
    GFXRECON_LOG_WARNING_ONCE(
        "%s: VkPhysicalDeviceDescriptorBufferFeaturesEXT::descriptorBufferCaptureReplay is currently not supported");
    return VK_SUCCESS;
}

VKAPI_ATTR VkResult VKAPI_CALL vkGetBufferOpaqueCaptureDescriptorDataEXT(
    VkDevice device, const VkBufferCaptureDescriptorDataInfoEXT* pInfo, void* pData)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(pInfo);
    GFXRECON_UNREFERENCED_PARAMETER(pData);
    GFXRECON_LOG_WARNING_ONCE(
        "%s: VkPhysicalDeviceDescriptorBufferFeaturesEXT::descriptorBufferCaptureReplay is currently not supported");
    return VK_SUCCESS;
}

VKAPI_ATTR VkResult VKAPI_CALL
vkGetImageOpaqueCaptureDescriptorDataEXT(VkDevice device, const VkImageCaptureDescriptorDataInfoEXT* pInfo, void* pData)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(pInfo);
    GFXRECON_UNREFERENCED_PARAMETER(pData);
    GFXRECON_LOG_WARNING_ONCE(
        "%s: VkPhysicalDeviceDescriptorBufferFeaturesEXT::descriptorBufferCaptureReplay is currently not supported");
    return VK_SUCCESS;
}

VKAPI_ATTR VkResult VKAPI_CALL vkGetSamplerOpaqueCaptureDescriptorDataEXT(
    VkDevice device, const VkSamplerCaptureDescriptorDataInfoEXT* pInfo, void* pData)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(pInfo);
    GFXRECON_UNREFERENCED_PARAMETER(pData);
    GFXRECON_LOG_WARNING_ONCE(
        "%s: VkPhysicalDeviceDescriptorBufferFeaturesEXT::descriptorBufferCaptureReplay is currently not supported");
    return VK_SUCCESS;
}

VKAPI_ATTR VkResult VKAPI_CALL vkGetImageViewOpaqueCaptureDescriptorDataEXT(
    VkDevice device, const VkImageViewCaptureDescriptorDataInfoEXT* pInfo, void* pData)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(pInfo);
    GFXRECON_UNREFERENCED_PARAMETER(pData);
    GFXRECON_LOG_WARNING_ONCE(
        "%s: VkPhysicalDeviceDescriptorBufferFeaturesEXT::descriptorBufferCaptureReplay is currently not supported");
    return VK_SUCCESS;
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
