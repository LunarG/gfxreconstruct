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

#include "decode/vulkan_decoder_base.h"

#include "decode/descriptor_update_template_decoder.h"
#include "decode/pointer_decoder.h"
#include "decode/value_decoder.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void VulkanDecoderBase::WaitIdle()
{
    for (auto consumer : consumers_)
    {
        consumer->WaitDevicesIdle();
    }
}

void VulkanDecoderBase::DispatchStateBeginMarker(uint64_t frame_number)
{
    for (auto consumer : consumers_)
    {
        consumer->ProcessStateBeginMarker(frame_number);
    }
}

void VulkanDecoderBase::DispatchStateEndMarker(uint64_t frame_number)
{
    for (auto consumer : consumers_)
    {
        consumer->ProcessStateEndMarker(frame_number);
    }
}

void VulkanDecoderBase::DispatchFrameBeginMarker(uint64_t frame_number)
{
    for (auto consumer : consumers_)
    {
        consumer->ProcessFrameBeginMarker(frame_number);
    }
}

void VulkanDecoderBase::DispatchFrameEndMarker(uint64_t frame_number)
{
    for (auto consumer : consumers_)
    {
        consumer->ProcessFrameEndMarker(frame_number);
    }
}

void VulkanDecoderBase::DispatchDisplayMessageCommand(format::ThreadId thread_id, const std::string& message)
{
    GFXRECON_UNREFERENCED_PARAMETER(thread_id);

    for (auto consumer : consumers_)
    {
        consumer->ProcessDisplayMessageCommand(message);
    }
}

void VulkanDecoderBase::DispatchFillMemoryCommand(
    format::ThreadId thread_id, uint64_t memory_id, uint64_t offset, uint64_t size, const uint8_t* data)
{
    GFXRECON_UNREFERENCED_PARAMETER(thread_id);

    for (auto consumer : consumers_)
    {
        consumer->ProcessFillMemoryCommand(memory_id, offset, size, data);
    }
}

void VulkanDecoderBase::DispatchExeFileInfo(format::ThreadId thread_id, format::ExeFileInfoBlock& info)
{
    for (auto consumer : consumers_)
    {
        consumer->Process_ExeFileInfo(info.info_record);
    }
}

void VulkanDecoderBase::DispatchFillMemoryResourceValueCommand(
    const format::FillMemoryResourceValueCommandHeader& command_header, const uint8_t* data)
{
    for (auto consumer : consumers_)
    {
        consumer->ProcessFillMemoryResourceValueCommand(command_header, data);
    }
}

void VulkanDecoderBase::DispatchResizeWindowCommand(format::ThreadId thread_id,
                                                    format::HandleId surface_id,
                                                    uint32_t         width,
                                                    uint32_t         height)
{
    GFXRECON_UNREFERENCED_PARAMETER(thread_id);

    for (auto consumer : consumers_)
    {
        consumer->ProcessResizeWindowCommand(surface_id, width, height);
    }
}

void VulkanDecoderBase::DispatchResizeWindowCommand2(
    format::ThreadId thread_id, format::HandleId surface_id, uint32_t width, uint32_t height, uint32_t pre_transform)
{
    GFXRECON_UNREFERENCED_PARAMETER(thread_id);

    for (auto consumer : consumers_)
    {
        consumer->ProcessResizeWindowCommand2(surface_id, width, height, pre_transform);
    }
}

void VulkanDecoderBase::DispatchCreateHardwareBufferCommand(
    format::ThreadId                                    thread_id,
    format::HandleId                                    memory_id,
    uint64_t                                            buffer_id,
    uint32_t                                            format,
    uint32_t                                            width,
    uint32_t                                            height,
    uint32_t                                            stride,
    uint64_t                                            usage,
    uint32_t                                            layers,
    const std::vector<format::HardwareBufferPlaneInfo>& plane_info)
{
    GFXRECON_UNREFERENCED_PARAMETER(thread_id);

    for (auto consumer : consumers_)
    {
        consumer->ProcessCreateHardwareBufferCommand(
            memory_id, buffer_id, format, width, height, stride, usage, layers, plane_info);
    }
}

void VulkanDecoderBase::DispatchDestroyHardwareBufferCommand(format::ThreadId thread_id, uint64_t buffer_id)
{
    GFXRECON_UNREFERENCED_PARAMETER(thread_id);

    for (auto consumer : consumers_)
    {
        consumer->ProcessDestroyHardwareBufferCommand(buffer_id);
    }
}

void VulkanDecoderBase::DispatchCreateHeapAllocationCommand(format::ThreadId thread_id,
                                                            uint64_t         allocation_id,
                                                            uint64_t         allocation_size)
{
    GFXRECON_UNREFERENCED_PARAMETER(thread_id);

    for (auto consumer : consumers_)
    {
        consumer->ProcessCreateHeapAllocationCommand(allocation_id, allocation_size);
    }
}

void VulkanDecoderBase::DispatchSetDevicePropertiesCommand(format::ThreadId   thread_id,
                                                           format::HandleId   physical_device_id,
                                                           uint32_t           api_version,
                                                           uint32_t           driver_version,
                                                           uint32_t           vendor_id,
                                                           uint32_t           device_id,
                                                           uint32_t           device_type,
                                                           const uint8_t      pipeline_cache_uuid[format::kUuidSize],
                                                           const std::string& device_name)
{
    GFXRECON_UNREFERENCED_PARAMETER(thread_id);

    for (auto consumer : consumers_)
    {
        consumer->ProcessSetDevicePropertiesCommand(physical_device_id,
                                                    api_version,
                                                    driver_version,
                                                    vendor_id,
                                                    device_id,
                                                    device_type,
                                                    pipeline_cache_uuid,
                                                    device_name);
    }
}

void VulkanDecoderBase::DispatchSetDeviceMemoryPropertiesCommand(
    format::ThreadId                             thread_id,
    format::HandleId                             physical_device_id,
    const std::vector<format::DeviceMemoryType>& memory_types,
    const std::vector<format::DeviceMemoryHeap>& memory_heaps)
{
    GFXRECON_UNREFERENCED_PARAMETER(thread_id);

    for (auto consumer : consumers_)
    {
        consumer->ProcessSetDeviceMemoryPropertiesCommand(physical_device_id, memory_types, memory_heaps);
    }
}

void VulkanDecoderBase::DispatchSetOpaqueAddressCommand(format::ThreadId thread_id,
                                                        format::HandleId device_id,
                                                        format::HandleId object_id,
                                                        uint64_t         address)
{
    GFXRECON_UNREFERENCED_PARAMETER(thread_id);

    for (auto consumer : consumers_)
    {
        consumer->ProcessSetOpaqueAddressCommand(device_id, object_id, address);
    }
}

void VulkanDecoderBase::DispatchSetRayTracingShaderGroupHandlesCommand(format::ThreadId thread_id,
                                                                       format::HandleId device_id,
                                                                       format::HandleId pipeline_id,
                                                                       size_t           data_size,
                                                                       const uint8_t*   data)
{
    GFXRECON_UNREFERENCED_PARAMETER(thread_id);

    for (auto consumer : consumers_)
    {
        consumer->ProcessSetRayTracingShaderGroupHandlesCommand(device_id, pipeline_id, data_size, data);
    }
}

void VulkanDecoderBase::DispatchSetSwapchainImageStateCommand(
    format::ThreadId                                    thread_id,
    format::HandleId                                    device_id,
    format::HandleId                                    swapchain_id,
    uint32_t                                            last_presented_image,
    const std::vector<format::SwapchainImageStateInfo>& image_state)
{
    GFXRECON_UNREFERENCED_PARAMETER(thread_id);

    for (auto consumer : consumers_)
    {
        consumer->ProcessSetSwapchainImageStateCommand(device_id, swapchain_id, last_presented_image, image_state);
    }
}

void VulkanDecoderBase::DispatchBeginResourceInitCommand(format::ThreadId thread_id,
                                                         format::HandleId device_id,
                                                         uint64_t         max_resource_size,
                                                         uint64_t         max_copy_size)
{
    GFXRECON_UNREFERENCED_PARAMETER(thread_id);

    for (auto consumer : consumers_)
    {
        consumer->ProcessBeginResourceInitCommand(device_id, max_resource_size, max_copy_size);
    }
}

void VulkanDecoderBase::DispatchEndResourceInitCommand(format::ThreadId thread_id, format::HandleId device_id)
{
    GFXRECON_UNREFERENCED_PARAMETER(thread_id);

    for (auto consumer : consumers_)
    {
        consumer->ProcessEndResourceInitCommand(device_id);
    }
}

void VulkanDecoderBase::DispatchInitBufferCommand(format::ThreadId thread_id,
                                                  format::HandleId device_id,
                                                  format::HandleId buffer_id,
                                                  uint64_t         data_size,
                                                  const uint8_t*   data)
{
    GFXRECON_UNREFERENCED_PARAMETER(thread_id);

    for (auto consumer : consumers_)
    {
        consumer->ProcessInitBufferCommand(device_id, buffer_id, data_size, data);
    }
}

void VulkanDecoderBase::DispatchInitImageCommand(format::ThreadId             thread_id,
                                                 format::HandleId             device_id,
                                                 format::HandleId             image_id,
                                                 uint64_t                     data_size,
                                                 uint32_t                     aspect,
                                                 uint32_t                     layout,
                                                 const std::vector<uint64_t>& level_sizes,
                                                 const uint8_t*               data)
{
    GFXRECON_UNREFERENCED_PARAMETER(thread_id);

    for (auto consumer : consumers_)
    {
        consumer->ProcessInitImageCommand(device_id, image_id, data_size, aspect, layout, level_sizes, data);
    }
}

/// @note Dead code, never called.
/// @note The Vulkan Layer does not encode this and no Vulkan consumers process it. It is one of several DX12-specific
/// metablocks which could have stubbed ({}) versions of their dispatch functions in ApiDecoder.
void VulkanDecoderBase::DispatchInitSubresourceCommand(const format::InitSubresourceCommandHeader& command_header,
                                                       const uint8_t*                              data)
{
    for (auto consumer : consumers_)
    {
        consumer->ProcessInitSubresourceCommand(command_header, data);
    }
}

size_t VulkanDecoderBase::Decode_vkUpdateDescriptorSetWithTemplate(const ApiCallInfo& call_info,
                                                                   const uint8_t*     parameter_buffer,
                                                                   size_t             buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId                device;
    format::HandleId                descriptorSet;
    format::HandleId                descriptorUpdateTemplate;
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
        consumer->Process_vkUpdateDescriptorSetWithTemplate(
            call_info, device, descriptorSet, descriptorUpdateTemplate, &pData);
    }

    return bytes_read;
}

size_t VulkanDecoderBase::Decode_vkCmdPushDescriptorSetWithTemplateKHR(const ApiCallInfo& call_info,
                                                                       const uint8_t*     parameter_buffer,
                                                                       size_t             buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId                commandBuffer;
    format::HandleId                descriptorUpdateTemplate;
    format::HandleId                layout;
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
            call_info, commandBuffer, descriptorUpdateTemplate, layout, set, &pData);
    }

    return bytes_read;
}

size_t VulkanDecoderBase::Decode_vkCmdPushDescriptorSetWithTemplate2KHR(const ApiCallInfo& call_info,
                                                                        const uint8_t*     parameter_buffer,
                                                                        size_t             buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId                                                     commandBuffer;
    StructPointerDecoder<Decoded_VkPushDescriptorSetWithTemplateInfoKHR> pPushDescriptorSetWithTemplateInfo;

    bytes_read +=
        ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read +=
        pPushDescriptorSetWithTemplateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pPushDescriptorSetWithTemplateInfo.GetMetaStructPointer()->pData.Decode(
        (parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        consumer->Process_vkCmdPushDescriptorSetWithTemplate2KHR(
            call_info, commandBuffer, &pPushDescriptorSetWithTemplateInfo);
    }

    return bytes_read;
}

size_t VulkanDecoderBase::Decode_vkUpdateDescriptorSetWithTemplateKHR(const ApiCallInfo& call_info,
                                                                      const uint8_t*     parameter_buffer,
                                                                      size_t             buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId                device;
    format::HandleId                descriptorSet;
    format::HandleId                descriptorUpdateTemplate;
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
        consumer->Process_vkUpdateDescriptorSetWithTemplateKHR(
            call_info, device, descriptorSet, descriptorUpdateTemplate, &pData);
    }

    return bytes_read;
}

size_t VulkanDecoderBase::Decode_vkCreateRayTracingPipelinesKHR(const ApiCallInfo& call_info,
                                                                const uint8_t*     parameter_buffer,
                                                                size_t             buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId                                                device;
    format::HandleId                                                deferredOperation;
    format::HandleId                                                pipelineCache;
    uint32_t                                                        createInfoCount;
    StructPointerDecoder<Decoded_VkRayTracingPipelineCreateInfoKHR> pCreateInfos;
    StructPointerDecoder<Decoded_VkAllocationCallbacks>             pAllocator;
    HandlePointerDecoder<VkPipeline>                                pPipelines;
    VkResult                                                        return_value;

    bytes_read +=
        ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue(
        (parameter_buffer + bytes_read), (buffer_size - bytes_read), &deferredOperation);
    bytes_read +=
        ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pipelineCache);
    bytes_read +=
        ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &createInfoCount);
    bytes_read += pCreateInfos.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pPipelines.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read +=
        ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateRayTracingPipelinesKHR(call_info,
                                                         return_value,
                                                         device,
                                                         deferredOperation,
                                                         pipelineCache,
                                                         createInfoCount,
                                                         &pCreateInfos,
                                                         &pAllocator,
                                                         &pPipelines);
    }

    if (deferredOperation)
    {
        DecodeAllocator::TurnOffEndCanClear();
        DeferredOperationFunctionCallData record;
        record.pCreateInfos                                        = std::move(pCreateInfos);
        record.pAllocator                                          = std::move(pAllocator);
        record.pPipelines                                          = std::move(pPipelines);
        record_deferred_operation_function_call[deferredOperation] = std::move(record);
    }
    return bytes_read;
}

size_t VulkanDecoderBase::Decode_vkDeferredOperationJoinKHR(const ApiCallInfo& call_info,
                                                            const uint8_t*     parameter_buffer,
                                                            size_t             buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId operation;
    VkResult         return_value;

    bytes_read +=
        ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read +=
        ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &operation);
    bytes_read +=
        ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDeferredOperationJoinKHR(call_info, return_value, device, operation);
    }

    DecodeAllocator::TurnOnEndCanClear();
    auto it = record_deferred_operation_function_call.find(operation);
    if (it != record_deferred_operation_function_call.end())
    {
        record_deferred_operation_function_call.erase(it);
    }
    return bytes_read;
}

void VulkanDecoderBase::DecodeFunctionCall(format::ApiCallId  call_id,
                                           const ApiCallInfo& call_info,
                                           const uint8_t*     parameter_buffer,
                                           size_t             buffer_size)
{
    GFXRECON_UNREFERENCED_PARAMETER(call_info);

    switch (call_id)
    {
        case format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplate:
            Decode_vkUpdateDescriptorSetWithTemplate(call_info, parameter_buffer, buffer_size);
            break;
        case format::ApiCallId::ApiCall_vkCmdPushDescriptorSetWithTemplateKHR:
            Decode_vkCmdPushDescriptorSetWithTemplateKHR(call_info, parameter_buffer, buffer_size);
            break;
        case format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplateKHR:
            Decode_vkUpdateDescriptorSetWithTemplateKHR(call_info, parameter_buffer, buffer_size);
            break;
        case format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesKHR:
            Decode_vkCreateRayTracingPipelinesKHR(call_info, parameter_buffer, buffer_size);
            break;
        case format::ApiCallId::ApiCall_vkCmdPushDescriptorSetWithTemplate2KHR:
            Decode_vkCmdPushDescriptorSetWithTemplate2KHR(call_info, parameter_buffer, buffer_size);
            break;
        case format::ApiCallId::ApiCall_vkDeferredOperationJoinKHR:
            Decode_vkDeferredOperationJoinKHR(call_info, parameter_buffer, buffer_size);
            break;
        default:
            break;
    }
}

void VulkanDecoderBase::DispatchSetTlasToBlasDependencyCommand(format::HandleId                     tlas,
                                                               const std::vector<format::HandleId>& blases)
{
    for (auto consumer : consumers_)
    {
        consumer->ProcessSetTlasToBlasRelationCommand(tlas, blases);
    }
}

void VulkanDecoderBase::DispatchSetEnvironmentVariablesCommand(format::SetEnvironmentVariablesCommand& header,
                                                               const char*                             env_string)
{
    for (auto consumer : consumers_)
    {
        consumer->ProcessSetEnvironmentVariablesCommand(header, env_string);
    }
}

void VulkanDecoderBase::SetCurrentBlockIndex(uint64_t block_index)
{
    for (auto consumer : consumers_)
    {
        consumer->SetCurrentBlockIndex(block_index);
    }
}

void VulkanDecoderBase::SetCurrentFileOffset(int64_t offset)
{
    for (auto consumer : consumers_)
    {
        consumer->SetCurrentFileOffset(offset);
    }
}

void VulkanDecoderBase::DispatchExecuteBlocksFromFile(format::ThreadId   thread_id,
                                                      uint32_t           n_blocks,
                                                      int64_t            offset,
                                                      const std::string& filename)
{
    GFXRECON_UNREFERENCED_PARAMETER(thread_id);

    for (auto consumer : consumers_)
    {
        consumer->ProcessExecuteBlocksFromFile(n_blocks, offset, filename);
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
