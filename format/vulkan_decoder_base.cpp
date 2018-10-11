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

#include "format/descriptor_update_template_decoder.h"
#include "format/pointer_decoder.h"
#include "format/value_decoder.h"
#include "format/vulkan_consumer.h"
#include "format/vulkan_decoder_base.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(format)

void VulkanDecoderBase::DispatchDisplayMessageCommand(const std::string& message)
{
    for (auto consumer : consumers_)
    {
        consumer->ProcessDisplayMessageCommand(message);
    }
}

void VulkanDecoderBase::DispatchFillMemoryCommand(uint64_t       memory_id,
                                                  uint64_t       offset,
                                                  uint64_t       size,
                                                  const uint8_t* data)
{
    for (auto consumer : consumers_)
    {
        consumer->ProcessFillMemoryCommand(memory_id, offset, size, data);
    }
}

void VulkanDecoderBase::DispatchResizeWindowCommand(HandleId surface_id, uint32_t width, uint32_t height)
{
    for (auto consumer : consumers_)
    {
        consumer->ProcessResizeWindowCommand(surface_id, width, height);
    }
}

size_t VulkanDecoderBase::Decode_vkUpdateDescriptorSetWithTemplate(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    HandleId                        device;
    HandleId                        descriptorSet;
    HandleId                        descriptorUpdateTemplate;
    DescriptorUpdateTemplateDecoder pData;

    bytes_read +=
        ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read +=
        ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &descriptorSet);
    bytes_read += ValueDecoder::DecodeHandleIdValue(
        (parameter_buffer + bytes_read), (buffer_size - bytes_read), &descriptorUpdateTemplate);
    bytes_read += pData.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        consumer->Process_vkUpdateDescriptorSetWithTemplate(device, descriptorSet, descriptorUpdateTemplate, pData);
    }

    return bytes_read;
}

size_t VulkanDecoderBase::Decode_vkCmdPushDescriptorSetWithTemplateKHR(const uint8_t* parameter_buffer,
                                                                       size_t         buffer_size)
{
    size_t bytes_read = 0;

    HandleId                        commandBuffer;
    HandleId                        descriptorUpdateTemplate;
    HandleId                        layout;
    uint32_t                        set;
    DescriptorUpdateTemplateDecoder pData;

    bytes_read +=
        ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue(
        (parameter_buffer + bytes_read), (buffer_size - bytes_read), &descriptorUpdateTemplate);
    bytes_read +=
        ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &layout);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &set);
    bytes_read += pData.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        consumer->Process_vkCmdPushDescriptorSetWithTemplateKHR(
            commandBuffer, descriptorUpdateTemplate, layout, set, pData);
    }

    return bytes_read;
}

size_t VulkanDecoderBase::Decode_vkUpdateDescriptorSetWithTemplateKHR(const uint8_t* parameter_buffer,
                                                                      size_t         buffer_size)
{
    size_t bytes_read = 0;

    HandleId                        device;
    HandleId                        descriptorSet;
    HandleId                        descriptorUpdateTemplate;
    DescriptorUpdateTemplateDecoder pData;

    bytes_read +=
        ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read +=
        ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &descriptorSet);
    bytes_read += ValueDecoder::DecodeHandleIdValue(
        (parameter_buffer + bytes_read), (buffer_size - bytes_read), &descriptorUpdateTemplate);
    bytes_read += pData.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        consumer->Process_vkUpdateDescriptorSetWithTemplateKHR(device, descriptorSet, descriptorUpdateTemplate, pData);
    }

    return bytes_read;
}

size_t VulkanDecoderBase::Decode_vkRegisterObjectsNVX(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    HandleId                                            device;
    HandleId                                            objectTable;
    uint32_t                                            objectCount;
    StructPointerDecoder<Decoded_VkObjectTableEntryNVX> ppObjectTableEntries;
    PointerDecoder<uint32_t>                            pObjectIndices;
    VkResult                                            return_value;

    bytes_read +=
        ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read +=
        ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &objectTable);
    bytes_read +=
        ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &objectCount);
    bytes_read += ppObjectTableEntries.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pObjectIndices.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read +=
        ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        consumer->Process_vkRegisterObjectsNVX(
            return_value, device, objectTable, objectCount, ppObjectTableEntries, pObjectIndices);
    }

    return bytes_read;
}

void VulkanDecoderBase::DecodeFunctionCall(ApiCallId             call_id,
                                           const ApiCallOptions& call_options,
                                           const uint8_t*        parameter_buffer,
                                           size_t                buffer_size)
{
    BRIMSTONE_UNREFERENCED_PARAMETER(call_options);

    switch (call_id)
    {
        case ApiCallId_vkUpdateDescriptorSetWithTemplate:
            Decode_vkUpdateDescriptorSetWithTemplate(parameter_buffer, buffer_size);
            break;
        case ApiCallId_vkCmdPushDescriptorSetWithTemplateKHR:
            Decode_vkCmdPushDescriptorSetWithTemplateKHR(parameter_buffer, buffer_size);
            break;
        case ApiCallId_vkUpdateDescriptorSetWithTemplateKHR:
            Decode_vkUpdateDescriptorSetWithTemplateKHR(parameter_buffer, buffer_size);
            break;
        case ApiCallId_vkRegisterObjectsNVX:
            Decode_vkRegisterObjectsNVX(parameter_buffer, buffer_size);
            break;
        default:
            break;
    }
}

BRIMSTONE_END_NAMESPACE(format)
BRIMSTONE_END_NAMESPACE(brimstone)
