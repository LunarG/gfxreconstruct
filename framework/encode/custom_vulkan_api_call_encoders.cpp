/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2020 LunarG, Inc.
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

#include "encode/custom_vulkan_api_call_encoders.h"

#include "encode/custom_encoder_commands.h"
#include "encode/custom_vulkan_struct_encoders.h"
#include "encode/custom_vulkan_struct_handle_wrappers.h"
#include "encode/descriptor_update_template_info.h"
#include "encode/parameter_encoder.h"
#include "encode/struct_pointer_encoder.h"
#include "encode/trace_manager.h"
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

                *unwrapped_entry = GetWrappedHandle<VkBufferView>(*entry);
            }
        }

        return unwrapped_data;
    }

    return data;
}

static void EncodeDescriptorUpdateTemplateInfo(TraceManager*             manager,
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
        // VkDescriptorBufferInfo, and VkBufferView types.  There will be one array per descriptor update entry.  We
        // will write the total number of entries of each type before we write the entries, so that the decoder will
        // know up front how much memory it needs to allocate for decoding.
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
                encoder->EncodeHandleValue(*entry);
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
    TraceManager* manager = TraceManager::Get();
    assert(manager != nullptr);

    const UpdateTemplateInfo* info = nullptr;
    if (!manager->GetDescriptorUpdateTemplateInfo(descriptorUpdateTemplate, &info))
    {
        GFXRECON_LOG_DEBUG("Descriptor update template info not found");
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplate>::Dispatch(
        manager, device, descriptorSet, descriptorUpdateTemplate, pData);

    auto encoder = manager->BeginApiCallTrace(format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplate);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(descriptorSet);
        encoder->EncodeHandleValue(descriptorUpdateTemplate);

        EncodeDescriptorUpdateTemplateInfo(manager, encoder, info, pData);

        manager->EndApiCallTrace(encoder);
    }

    auto handle_unwrap_memory               = TraceManager::Get()->GetHandleUnwrapMemory();
    auto device_unwrapped                   = GetWrappedHandle<VkDevice>(device);
    auto descriptorSet_unwrapped            = GetWrappedHandle<VkDescriptorSet>(descriptorSet);
    auto descriptorUpdateTemplate_unwrapped = GetWrappedHandle<VkDescriptorUpdateTemplate>(descriptorUpdateTemplate);
    auto pData_unwrapped = UnwrapDescriptorUpdateTemplateInfoHandles(info, pData, handle_unwrap_memory);

    GetDeviceTable(device)->UpdateDescriptorSetWithTemplate(
        device_unwrapped, descriptorSet_unwrapped, descriptorUpdateTemplate_unwrapped, pData_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplate>::Dispatch(
        manager, device, descriptorSet, descriptorUpdateTemplate, pData);
}

VKAPI_ATTR void VKAPI_CALL CmdPushDescriptorSetWithTemplateKHR(VkCommandBuffer            commandBuffer,
                                                               VkDescriptorUpdateTemplate descriptorUpdateTemplate,
                                                               VkPipelineLayout           layout,
                                                               uint32_t                   set,
                                                               const void*                pData)
{
    TraceManager* manager = TraceManager::Get();
    assert(manager != nullptr);

    const UpdateTemplateInfo* info = nullptr;
    if (!manager->GetDescriptorUpdateTemplateInfo(descriptorUpdateTemplate, &info))
    {
        GFXRECON_LOG_DEBUG("Descriptor update template info not found");
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdPushDescriptorSetWithTemplateKHR>::Dispatch(
        manager, commandBuffer, descriptorUpdateTemplate, layout, set, pData);

    auto encoder = manager->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdPushDescriptorSetWithTemplateKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(descriptorUpdateTemplate);
        encoder->EncodeHandleValue(layout);
        encoder->EncodeUInt32Value(set);

        EncodeDescriptorUpdateTemplateInfo(manager, encoder, info, pData);

        manager->EndApiCallTrace(encoder);
    }

    auto handle_unwrap_memory               = TraceManager::Get()->GetHandleUnwrapMemory();
    auto commandBuffer_unwrapped            = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    auto descriptorUpdateTemplate_unwrapped = GetWrappedHandle<VkDescriptorUpdateTemplate>(descriptorUpdateTemplate);
    auto layout_unwrapped                   = GetWrappedHandle<VkPipelineLayout>(layout);
    auto pData_unwrapped = UnwrapDescriptorUpdateTemplateInfoHandles(info, pData, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)
        ->CmdPushDescriptorSetWithTemplateKHR(
            commandBuffer_unwrapped, descriptorUpdateTemplate_unwrapped, layout_unwrapped, set, pData_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPushDescriptorSetWithTemplateKHR>::Dispatch(
        manager, commandBuffer, descriptorUpdateTemplate, layout, set, pData);
}

VKAPI_ATTR void VKAPI_CALL UpdateDescriptorSetWithTemplateKHR(VkDevice                   device,
                                                              VkDescriptorSet            descriptorSet,
                                                              VkDescriptorUpdateTemplate descriptorUpdateTemplate,
                                                              const void*                pData)
{
    TraceManager* manager = TraceManager::Get();
    assert(manager != nullptr);

    const UpdateTemplateInfo* info = nullptr;
    if (!manager->GetDescriptorUpdateTemplateInfo(descriptorUpdateTemplate, &info))
    {
        GFXRECON_LOG_DEBUG("Descriptor update template info not found");
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplateKHR>::Dispatch(
        manager, device, descriptorSet, descriptorUpdateTemplate, pData);

    auto encoder = manager->BeginApiCallTrace(format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplateKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(descriptorSet);
        encoder->EncodeHandleValue(descriptorUpdateTemplate);

        EncodeDescriptorUpdateTemplateInfo(manager, encoder, info, pData);

        manager->EndApiCallTrace(encoder);
    }

    auto handle_unwrap_memory               = TraceManager::Get()->GetHandleUnwrapMemory();
    auto device_unwrapped                   = GetWrappedHandle<VkDevice>(device);
    auto descriptorSet_unwrapped            = GetWrappedHandle<VkDescriptorSet>(descriptorSet);
    auto descriptorUpdateTemplate_unwrapped = GetWrappedHandle<VkDescriptorUpdateTemplate>(descriptorUpdateTemplate);
    auto pData_unwrapped = UnwrapDescriptorUpdateTemplateInfoHandles(info, pData, handle_unwrap_memory);

    GetDeviceTable(device)->UpdateDescriptorSetWithTemplateKHR(
        device_unwrapped, descriptorSet_unwrapped, descriptorUpdateTemplate_unwrapped, pData_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplateKHR>::Dispatch(
        manager, device, descriptorSet, descriptorUpdateTemplate, pData);
}

VKAPI_ATTR void VKAPI_CALL
                CmdBuildAccelerationStructureKHR(VkCommandBuffer                                         commandBuffer,
                                                 uint32_t                                                infoCount,
                                                 const VkAccelerationStructureBuildGeometryInfoKHR*      pInfos,
                                                 const VkAccelerationStructureBuildOffsetInfoKHR* const* ppOffsetInfos)
{
    // TODO
    GFXRECON_LOG_ERROR("CmdBuildAccelerationStructureKHR encoding is not supported");
    GetDeviceTable(commandBuffer)->CmdBuildAccelerationStructureKHR(commandBuffer, infoCount, pInfos, ppOffsetInfos);
}

VKAPI_ATTR VkResult VKAPI_CALL
                    BuildAccelerationStructureKHR(VkDevice                                                device,
                                                  uint32_t                                                infoCount,
                                                  const VkAccelerationStructureBuildGeometryInfoKHR*      pInfos,
                                                  const VkAccelerationStructureBuildOffsetInfoKHR* const* ppOffsetInfos)
{
    // TODO
    GFXRECON_LOG_ERROR("BuildAccelerationStructureKHR encoding is not supported");
    return GetDeviceTable(device)->BuildAccelerationStructureKHR(device, infoCount, pInfos, ppOffsetInfos);
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
