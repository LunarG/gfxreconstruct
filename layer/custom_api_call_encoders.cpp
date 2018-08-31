/*
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

#include <cassert>

#include "format/api_call_id.h"
#include "format/custom_encoder_commands.h"
#include "format/parameter_encoder.h"
#include "format/struct_pointer_encoder.h"
#include "format/trace_manager.h"
#include "layer/custom_api_call_encoders.h"
#include "layer/trace_layer.h"
#include "util/defines.h"

#include "generated/generated_struct_encoder_declarations.inc"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)

static size_t EncodeDescriptorUpdateTemplateInfo(format::TraceManager*      manager,
                                                 format::ParameterEncoder*  encoder,
                                                 VkDescriptorUpdateTemplate update_template,
                                                 const void*                data)
{
    assert((manager != nullptr) && (encoder != nullptr));

    size_t                                          bytes_written = 0;
    bool                                            found         = false;
    const format::TraceManager::UpdateTemplateInfo* info          = nullptr;

    if (data != nullptr)
    {
        found = manager->GetDescriptorUpdateTemplateInfo(update_template, &info);
    }

    if (found && (info != nullptr))
    {
        // Write pointer attributes as if we were processing a struct pointer.
        bytes_written += encoder->EncodeStructPtrPreamble(data);

        // The update template data will be written as tightly packed sets of arrays of VkDescriptorImageInfo,
        // VkDescriptorBufferInfo, and VkBufferView types.  There will be one array per descriptor update entry.  We
        // will write the total number of entries of each type before we write the entries, so that the decoder will
        // know up front how much memory it needs to allocate for decoding.
        bytes_written += encoder->EncodeSizeTValue(info->image_info_count);
        bytes_written += encoder->EncodeSizeTValue(info->buffer_info_count);
        bytes_written += encoder->EncodeSizeTValue(info->texel_buffer_view_count);

        // Write the individual template update entries, sorted by type, as tightly packed arrays.
        const uint8_t* bytes = reinterpret_cast<const uint8_t*>(data);
        // Process VkDescriptorImageInfo
        for (const auto& entry_info : info->image_info)
        {
            for (size_t i = 0; i < entry_info.count; ++i)
            {
                size_t                       offset = entry_info.offset + (entry_info.stride * i);
                const VkDescriptorImageInfo* entry = reinterpret_cast<const VkDescriptorImageInfo*>(bytes + offset);
                bytes_written += encode_struct(encoder, (*entry));
            }
        }

        // Process VkDescriptorBufferInfo
        bytes_written += encoder->EncodeStructArrayPreamble(data, info->buffer_info.size());
        for (const auto& entry_info : info->buffer_info)
        {
            for (size_t i = 0; i < entry_info.count; ++i)
            {
                size_t                        offset = entry_info.offset + (entry_info.stride * i);
                const VkDescriptorBufferInfo* entry =
                    reinterpret_cast<const VkDescriptorBufferInfo*>(bytes + offset);
                bytes_written += encode_struct(encoder, (*entry));
            }
        }

        // Process VkBufferView
        for (const auto& entry_info : info->texel_buffer_view)
        {
            for (size_t i = 0; i < entry_info.count; ++i)
            {
                size_t              offset = entry_info.offset + (entry_info.stride * i);
                const VkBufferView* entry  = reinterpret_cast<const VkBufferView*>(bytes + offset);
                bytes_written += encoder->EncodeHandleIdValue((*entry));
            }
        }
    }
    else
    {
        bytes_written += encoder->EncodeStructArrayPreamble(data, 0);
    }

    return bytes_written;
}

VKAPI_ATTR void VKAPI_CALL UpdateDescriptorSetWithTemplate(VkDevice                   device,
                                                           VkDescriptorSet            descriptorSet,
                                                           VkDescriptorUpdateTemplate descriptorUpdateTemplate,
                                                           const void*                pData)
{
    format::TraceManager* trace_manager = get_trace_manager();

    format::CustomEncoderPreCall<format::ApiCallId_vkUpdateDescriptorSetWithTemplate>::Dispatch(
        trace_manager, device, descriptorSet, descriptorUpdateTemplate, pData);

    get_device_table(device)->UpdateDescriptorSetWithTemplate(device, descriptorSet, descriptorUpdateTemplate, pData);

    auto encoder = trace_manager->BeginApiCallTrace(format::ApiCallId_vkUpdateDescriptorSetWithTemplate);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(descriptorSet);
        encoder->EncodeHandleIdValue(descriptorUpdateTemplate);

        EncodeDescriptorUpdateTemplateInfo(trace_manager, encoder, descriptorUpdateTemplate, pData);

        trace_manager->EndApiCallTrace(encoder);
    }

    format::CustomEncoderPostCall<format::ApiCallId_vkUpdateDescriptorSetWithTemplate>::Dispatch(
        trace_manager, device, descriptorSet, descriptorUpdateTemplate, pData);
}

VKAPI_ATTR void VKAPI_CALL CmdPushDescriptorSetWithTemplateKHR(VkCommandBuffer            commandBuffer,
                                                               VkDescriptorUpdateTemplate descriptorUpdateTemplate,
                                                               VkPipelineLayout           layout,
                                                               uint32_t                   set,
                                                               const void*                pData)
{
    format::TraceManager* trace_manager = get_trace_manager();

    format::CustomEncoderPreCall<format::ApiCallId_vkCmdPushDescriptorSetWithTemplateKHR>::Dispatch(
        trace_manager, commandBuffer, descriptorUpdateTemplate, layout, set, pData);

    get_device_table(commandBuffer)
        ->CmdPushDescriptorSetWithTemplateKHR(commandBuffer, descriptorUpdateTemplate, layout, set, pData);

    auto encoder = trace_manager->BeginApiCallTrace(format::ApiCallId_vkCmdPushDescriptorSetWithTemplateKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(descriptorUpdateTemplate);
        encoder->EncodeHandleIdValue(layout);
        encoder->EncodeUInt32Value(set);

        EncodeDescriptorUpdateTemplateInfo(trace_manager, encoder, descriptorUpdateTemplate, pData);

        trace_manager->EndApiCallTrace(encoder);
    }

    format::CustomEncoderPostCall<format::ApiCallId_vkCmdPushDescriptorSetWithTemplateKHR>::Dispatch(
        trace_manager, commandBuffer, descriptorUpdateTemplate, layout, set, pData);
}

VKAPI_ATTR void VKAPI_CALL UpdateDescriptorSetWithTemplateKHR(VkDevice                   device,
                                                              VkDescriptorSet            descriptorSet,
                                                              VkDescriptorUpdateTemplate descriptorUpdateTemplate,
                                                              const void*                pData)
{
    format::TraceManager* trace_manager = get_trace_manager();

    format::CustomEncoderPreCall<format::ApiCallId_vkUpdateDescriptorSetWithTemplateKHR>::Dispatch(
        trace_manager, device, descriptorSet, descriptorUpdateTemplate, pData);

    get_device_table(device)->UpdateDescriptorSetWithTemplateKHR(
        device, descriptorSet, descriptorUpdateTemplate, pData);

    auto encoder = trace_manager->BeginApiCallTrace(format::ApiCallId_vkUpdateDescriptorSetWithTemplateKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(descriptorSet);
        encoder->EncodeHandleIdValue(descriptorUpdateTemplate);

        EncodeDescriptorUpdateTemplateInfo(trace_manager, encoder, descriptorUpdateTemplate, pData);

        trace_manager->EndApiCallTrace(encoder);
    }

    format::CustomEncoderPostCall<format::ApiCallId_vkUpdateDescriptorSetWithTemplateKHR>::Dispatch(
        trace_manager, device, descriptorSet, descriptorUpdateTemplate, pData);
}

BRIMSTONE_END_NAMESPACE(brimstone)
