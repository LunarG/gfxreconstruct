/*
** Copyright (c) 2018 Valve Corporation
** Copyright (c) 2018 LunarG, Inc.
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
#include "encode/parameter_encoder.h"
#include "encode/struct_pointer_encoder.h"
#include "encode/trace_manager.h"
#include "format/api_call_id.h"
#include "generated/generated_vulkan_struct_encoders.h"
#include "util/defines.h"

#include <cassert>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

static void EncodeDescriptorUpdateTemplateInfo(TraceManager*              manager,
                                               ParameterEncoder*          encoder,
                                               VkDescriptorUpdateTemplate update_template,
                                               const void*                data)
{
    assert((manager != nullptr) && (encoder != nullptr));

    bool                                    found = false;
    const TraceManager::UpdateTemplateInfo* info  = nullptr;

    if (data != nullptr)
    {
        found = manager->GetDescriptorUpdateTemplateInfo(update_template, &info);
    }

    if (found && (info != nullptr))
    {
        // Write pointer attributes as if we were processing a struct pointer.
        encoder->EncodeStructPtrPreamble(data);

        // The update template data will be written as tightly packed sets of arrays of VkDescriptorImageInfo,
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
                EncodeStruct(encoder, (*entry));
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
                encoder->EncodeHandleIdValue((*entry));
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

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplate>::Dispatch(
        manager, device, descriptorSet, descriptorUpdateTemplate, pData);

    auto encoder = manager->BeginApiCallTrace(format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplate);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(descriptorSet);
        encoder->EncodeHandleIdValue(descriptorUpdateTemplate);

        EncodeDescriptorUpdateTemplateInfo(manager, encoder, descriptorUpdateTemplate, pData);

        manager->EndApiCallTrace(encoder);
    }

    manager->GetDeviceTable(device)->UpdateDescriptorSetWithTemplate(
        device, descriptorSet, descriptorUpdateTemplate, pData);

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

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdPushDescriptorSetWithTemplateKHR>::Dispatch(
        manager, commandBuffer, descriptorUpdateTemplate, layout, set, pData);

    auto encoder = manager->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdPushDescriptorSetWithTemplateKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(descriptorUpdateTemplate);
        encoder->EncodeHandleIdValue(layout);
        encoder->EncodeUInt32Value(set);

        EncodeDescriptorUpdateTemplateInfo(manager, encoder, descriptorUpdateTemplate, pData);

        manager->EndApiCallTrace(encoder);
    }

    manager->GetDeviceTable(commandBuffer)
        ->CmdPushDescriptorSetWithTemplateKHR(commandBuffer, descriptorUpdateTemplate, layout, set, pData);

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

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplateKHR>::Dispatch(
        manager, device, descriptorSet, descriptorUpdateTemplate, pData);

    auto encoder = manager->BeginApiCallTrace(format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplateKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(descriptorSet);
        encoder->EncodeHandleIdValue(descriptorUpdateTemplate);

        EncodeDescriptorUpdateTemplateInfo(manager, encoder, descriptorUpdateTemplate, pData);

        manager->EndApiCallTrace(encoder);
    }

    manager->GetDeviceTable(device)->UpdateDescriptorSetWithTemplateKHR(
        device, descriptorSet, descriptorUpdateTemplate, pData);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplateKHR>::Dispatch(
        manager, device, descriptorSet, descriptorUpdateTemplate, pData);
}

VKAPI_ATTR VkResult VKAPI_CALL RegisterObjectsNVX(VkDevice                            device,
                                                  VkObjectTableNVX                    objectTable,
                                                  uint32_t                            objectCount,
                                                  const VkObjectTableEntryNVX* const* ppObjectTableEntries,
                                                  const uint32_t*                     pObjectIndices)
{
    TraceManager* manager = TraceManager::Get();
    assert(manager != nullptr);

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkRegisterObjectsNVX>::Dispatch(
        manager, device, objectTable, objectCount, ppObjectTableEntries, pObjectIndices);

    VkResult result = manager->GetDeviceTable(device)->RegisterObjectsNVX(
        device, objectTable, objectCount, ppObjectTableEntries, pObjectIndices);

    auto encoder = manager->BeginApiCallTrace(format::ApiCallId::ApiCall_vkRegisterObjectsNVX);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(objectTable);
        encoder->EncodeUInt32Value(objectCount);
        EncodeStructArray(encoder, ppObjectTableEntries, objectCount);
        encoder->EncodeUInt32Array(pObjectIndices, objectCount);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkRegisterObjectsNVX>::Dispatch(
        manager, result, device, objectTable, objectCount, ppObjectTableEntries, pObjectIndices);

    return result;
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
