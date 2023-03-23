/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2020 LunarG, Inc.
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
                UnwrapStructHandles(entry_info.type, unwrapped_entry, unwrap_memory);
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
                UnwrapStructHandles(unwrapped_entry, unwrap_memory);
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
                encoder->EncodeHandleValue<BufferViewWrapper>(*entry);
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
                    encoder->EncodeHandleValue<AccelerationStructureKHRWrapper>(*entry);
                }
            }
        }
    }
    else
    {
        encoder->EncodeStructArrayPreamble(data, 0);
    }
}

VKAPI_ATTR void VKAPI_CALL UpdateDescriptorSetWithTemplate(VkDevice                   device,
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
        encoder->EncodeHandleValue<DeviceWrapper>(device);
        encoder->EncodeHandleValue<DescriptorSetWrapper>(descriptorSet);
        encoder->EncodeHandleValue<DescriptorUpdateTemplateWrapper>(descriptorUpdateTemplate);

        EncodeDescriptorUpdateTemplateInfo(manager, encoder, info, pData);

        manager->EndApiCallCapture();
    }

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    auto pData_unwrapped      = UnwrapDescriptorUpdateTemplateInfoHandles(info, pData, handle_unwrap_memory);

    GetDeviceTable(device)->UpdateDescriptorSetWithTemplate(
        device, descriptorSet, descriptorUpdateTemplate, pData_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplate>::Dispatch(
        manager, device, descriptorSet, descriptorUpdateTemplate, pData);
}

VKAPI_ATTR void VKAPI_CALL CmdPushDescriptorSetWithTemplateKHR(VkCommandBuffer            commandBuffer,
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

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_vkCmdPushDescriptorSetWithTemplateKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue<CommandBufferWrapper>(commandBuffer);
        encoder->EncodeHandleValue<DescriptorUpdateTemplateWrapper>(descriptorUpdateTemplate);
        encoder->EncodeHandleValue<PipelineLayoutWrapper>(layout);
        encoder->EncodeUInt32Value(set);

        EncodeDescriptorUpdateTemplateInfo(manager, encoder, info, pData);

        manager->EndApiCallCapture();
    }

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    auto pData_unwrapped      = UnwrapDescriptorUpdateTemplateInfoHandles(info, pData, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)
        ->CmdPushDescriptorSetWithTemplateKHR(commandBuffer, descriptorUpdateTemplate, layout, set, pData_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPushDescriptorSetWithTemplateKHR>::Dispatch(
        manager, commandBuffer, descriptorUpdateTemplate, layout, set, pData);
}

VKAPI_ATTR void VKAPI_CALL UpdateDescriptorSetWithTemplateKHR(VkDevice                   device,
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
        encoder->EncodeHandleValue<DeviceWrapper>(device);
        encoder->EncodeHandleValue<DescriptorSetWrapper>(descriptorSet);
        encoder->EncodeHandleValue<DescriptorUpdateTemplateWrapper>(descriptorUpdateTemplate);

        EncodeDescriptorUpdateTemplateInfo(manager, encoder, info, pData);

        manager->EndApiCallCapture();
    }

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    auto pData_unwrapped      = UnwrapDescriptorUpdateTemplateInfoHandles(info, pData, handle_unwrap_memory);

    GetDeviceTable(device)->UpdateDescriptorSetWithTemplateKHR(
        device, descriptorSet, descriptorUpdateTemplate, pData_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplateKHR>::Dispatch(
        manager, device, descriptorSet, descriptorUpdateTemplate, pData);
}

VKAPI_ATTR VkResult VKAPI_CALL
BuildAccelerationStructuresKHR(VkDevice                                               device,
                               VkDeferredOperationKHR                                 deferredOperation,
                               uint32_t                                               infoCount,
                               const VkAccelerationStructureBuildGeometryInfoKHR*     pInfos,
                               const VkAccelerationStructureBuildRangeInfoKHR* const* ppRangeInfos)
{
    // TODO
    GFXRECON_LOG_ERROR("BuildAccelerationStructuresKHR encoding is not supported");
    return GetDeviceTable(device)->BuildAccelerationStructuresKHR(
        device, deferredOperation, infoCount, pInfos, ppRangeInfos);
}

VKAPI_ATTR VkResult VKAPI_CALL CopyAccelerationStructureKHR(VkDevice                                  device,
                                                            VkDeferredOperationKHR                    deferredOperation,
                                                            const VkCopyAccelerationStructureInfoKHR* pInfo)
{
    // TODO
    GFXRECON_LOG_ERROR("CopyAccelerationStructureKHR encoding is not supported");
    return GetDeviceTable(device)->CopyAccelerationStructureKHR(device, deferredOperation, pInfo);
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
