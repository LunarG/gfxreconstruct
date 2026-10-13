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
#include "decode/vulkan_resource_aliasing_groups.h"
#include "util/platform.h"

#include <algorithm>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void VulkanDecoderBase::WaitIdle()
{
    for (auto consumer : consumers_)
    {
        consumer->WaitDevicesIdle();
    }
}

void VulkanDecoderBase::StartLooping()
{
    for (auto consumer : consumers_)
    {
        consumer->StartLooping();
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

void VulkanDecoderBase::DispatchExeFileInfo(format::ThreadId thread_id, const format::ExeFileInfoBlock& info)
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
    format::HandleId                                    device_id,
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
            device_id, memory_id, buffer_id, format, width, height, stride, usage, layers, plane_info);
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

void VulkanDecoderBase::DispatchSetOpaqueDescriptorDataCommand(format::ThreadId thread_id,
                                                               format::HandleId device_id,
                                                               format::HandleId object_id,
                                                               uint32_t         data_size,
                                                               const uint8_t*   data)
{
    GFXRECON_UNREFERENCED_PARAMETER(thread_id);

    for (auto consumer : consumers_)
    {
        consumer->ProcessSetOpaqueDescriptorDataCommand(device_id, object_id, data_size, data);
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

void VulkanDecoderBase::DispatchInitTensorCommand(format::ThreadId thread_id,
                                                  format::HandleId device_id,
                                                  format::HandleId tensor_id,
                                                  uint64_t         data_size,
                                                  const uint8_t*   data)
{
    GFXRECON_UNREFERENCED_PARAMETER(thread_id);

    for (auto consumer : consumers_)
    {
        consumer->ProcessInitTensorCommand(device_id, tensor_id, data_size, data);
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

    args::UpdateDescriptorSetWithTemplate args;

    bytes_read +=
        ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &args.device);
    bytes_read += ValueDecoder::DecodeHandleIdValue(
        (parameter_buffer + bytes_read), (buffer_size - bytes_read), &args.descriptorSet);
    bytes_read += ValueDecoder::DecodeHandleIdValue(
        (parameter_buffer + bytes_read), (buffer_size - bytes_read), &args.descriptorUpdateTemplate);
    bytes_read += args.pData.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        consumer->Process_vkUpdateDescriptorSetWithTemplate(call_info, args);
    }

    return bytes_read;
}

size_t VulkanDecoderBase::Decode_vkCmdPushDescriptorSetWithTemplateKHR(const ApiCallInfo& call_info,
                                                                       const uint8_t*     parameter_buffer,
                                                                       size_t             buffer_size)
{
    size_t bytes_read = 0;

    args::CmdPushDescriptorSetWithTemplateKHR args;

    bytes_read += ValueDecoder::DecodeHandleIdValue(
        (parameter_buffer + bytes_read), (buffer_size - bytes_read), &args.commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue(
        (parameter_buffer + bytes_read), (buffer_size - bytes_read), &args.descriptorUpdateTemplate);
    bytes_read +=
        ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &args.layout);
    bytes_read +=
        ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &args.set);
    bytes_read += args.pData.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        consumer->Process_vkCmdPushDescriptorSetWithTemplateKHR(call_info, args);
    }

    return bytes_read;
}

size_t VulkanDecoderBase::Decode_vkCmdPushDescriptorSetWithTemplate2KHR(const ApiCallInfo& call_info,
                                                                        const uint8_t*     parameter_buffer,
                                                                        size_t             buffer_size)
{
    size_t bytes_read = 0;

    args::CmdPushDescriptorSetWithTemplate2KHR args;

    bytes_read += ValueDecoder::DecodeHandleIdValue(
        (parameter_buffer + bytes_read), (buffer_size - bytes_read), &args.commandBuffer);
    bytes_read +=
        args.pPushDescriptorSetWithTemplateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += args.pPushDescriptorSetWithTemplateInfo.GetMetaStructPointer()->pData.Decode(
        (parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        consumer->Process_vkCmdPushDescriptorSetWithTemplate2KHR(call_info, args);
    }

    return bytes_read;
}

size_t VulkanDecoderBase::Decode_vkUpdateDescriptorSetWithTemplateKHR(const ApiCallInfo& call_info,
                                                                      const uint8_t*     parameter_buffer,
                                                                      size_t             buffer_size)
{
    size_t bytes_read = 0;

    args::UpdateDescriptorSetWithTemplateKHR args;

    bytes_read +=
        ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &args.device);
    bytes_read += ValueDecoder::DecodeHandleIdValue(
        (parameter_buffer + bytes_read), (buffer_size - bytes_read), &args.descriptorSet);
    bytes_read += ValueDecoder::DecodeHandleIdValue(
        (parameter_buffer + bytes_read), (buffer_size - bytes_read), &args.descriptorUpdateTemplate);
    bytes_read += args.pData.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        consumer->Process_vkUpdateDescriptorSetWithTemplateKHR(call_info, args);
    }

    return bytes_read;
}

size_t VulkanDecoderBase::Decode_vkCreateRayTracingPipelinesKHR(const ApiCallInfo& call_info,
                                                                const uint8_t*     parameter_buffer,
                                                                size_t             buffer_size)
{
    size_t bytes_read = 0;

    args::CreateRayTracingPipelinesKHR args;

    bytes_read +=
        ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &args.device);
    bytes_read += ValueDecoder::DecodeHandleIdValue(
        (parameter_buffer + bytes_read), (buffer_size - bytes_read), &args.deferredOperation);
    bytes_read += ValueDecoder::DecodeHandleIdValue(
        (parameter_buffer + bytes_read), (buffer_size - bytes_read), &args.pipelineCache);
    bytes_read += ValueDecoder::DecodeUInt32Value(
        (parameter_buffer + bytes_read), (buffer_size - bytes_read), &args.createInfoCount);
    bytes_read += args.pCreateInfos.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += args.pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += args.pPipelines.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read +=
        ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &args.result);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateRayTracingPipelinesKHR(call_info, args);
    }

    if (args.deferredOperation)
    {
        DecodeAllocator::TurnOffEndCanClear();
        DeferredOperationFunctionCallData record;
        record.pCreateInfos                                             = std::move(args.pCreateInfos);
        record.pAllocator                                               = std::move(args.pAllocator);
        record.pPipelines                                               = std::move(args.pPipelines);
        record_deferred_operation_function_call[args.deferredOperation] = std::move(record);
    }
    return bytes_read;
}

size_t VulkanDecoderBase::Decode_vkDeferredOperationJoinKHR(const ApiCallInfo& call_info,
                                                            const uint8_t*     parameter_buffer,
                                                            size_t             buffer_size)
{
    size_t bytes_read = 0;

    args::DeferredOperationJoinKHR args;

    bytes_read +=
        ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &args.device);
    bytes_read +=
        ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &args.operation);
    bytes_read +=
        ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &args.result);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDeferredOperationJoinKHR(call_info, args);
    }

    DecodeAllocator::TurnOnEndCanClear();
    auto it = record_deferred_operation_function_call.find(args.operation);
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

void VulkanDecoderBase::DispatchSetEnvironmentVariablesCommand(const format::SetEnvironmentVariablesCommand& header,
                                                               const char*                                   env_string)
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

void VulkanDecoderBase::SetCurrentFrameNumber(uint64_t frame_number)
{
    for (auto consumer : consumers_)
    {
        consumer->SetCurrentFrameNumber(frame_number);
    }
}

void VulkanDecoderBase::DispatchVulkanAccelerationStructuresBuildMetaCommand(const uint8_t* parameter_buffer,
                                                                             size_t         buffer_size)
{

    format::HandleId                                                          device_id;
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR> pInfos;
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildRangeInfoKHR*>   ppRangeInfos;

    std::size_t bytes_read = ValueDecoder::DecodeHandleIdValue(parameter_buffer, buffer_size, &device_id);
    bytes_read += pInfos.Decode(parameter_buffer + bytes_read, buffer_size - bytes_read);
    ppRangeInfos.Decode(parameter_buffer + bytes_read, buffer_size - bytes_read);

    for (auto consumer : consumers_)
    {
        consumer->ProcessVulkanBuildAccelerationStructuresCommand(
            device_id, GFXRECON_NARROWING_CAST(uint32_t, pInfos.GetLength()), &pInfos, &ppRangeInfos);
    }
}

void VulkanDecoderBase::DispatchVulkanAccelerationStructuresCopyMetaCommand(const uint8_t* parameter_buffer,
                                                                            size_t         buffer_size)
{
    format::HandleId                                                 device_id;
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureInfoKHR> pInfos;

    std::size_t bytes_read = ValueDecoder::DecodeHandleIdValue(parameter_buffer, buffer_size, &device_id);
    bytes_read += pInfos.Decode(parameter_buffer + bytes_read, buffer_size - bytes_read);

    for (auto consumer : consumers_)
    {
        consumer->ProcessVulkanCopyAccelerationStructuresCommand(device_id, &pInfos);
    }
}

void VulkanDecoderBase::DispatchVulkanAccelerationStructuresWritePropertiesMetaCommand(const uint8_t* parameter_buffer,
                                                                                       size_t         buffer_size)
{
    format::HandleId device_id;
    VkQueryType      query_type;
    format::HandleId acceleration_structure_id;

    std::size_t bytes_read = ValueDecoder::DecodeHandleIdValue(parameter_buffer, sizeof(format::HandleId), &device_id);
    bytes_read += ValueDecoder::DecodeEnumValue(parameter_buffer + bytes_read, sizeof(VkQueryType), &query_type);
    bytes_read += ValueDecoder::DecodeHandleIdValue(
        parameter_buffer + bytes_read, sizeof(format::HandleId), &acceleration_structure_id);

    for (auto consumer : consumers_)
    {
        consumer->ProcessVulkanWriteAccelerationStructuresPropertiesCommand(
            device_id, query_type, acceleration_structure_id);
    }
}

void VulkanDecoderBase::DispatchResourceAliasingGroupsCommand(const uint8_t* parameter_buffer, size_t buffer_size)
{
    // A malformed block is dropped whole: replay then places the resources with the per-bind detection in
    // VulkanRebindAllocator, which is what a capture without this block gets.
    size_t offset = 0;

    auto read = [&](void* destination, size_t size) {
        if ((buffer_size - offset) < size)
        {
            return false;
        }
        util::platform::MemoryCopy(destination, size, parameter_buffer + offset, size);
        offset += size;
        return true;
    };

    format::ResourceAliasingGroupsCommandHeader header{};
    if (!read(&header.thread_id, sizeof(header.thread_id)) || !read(&header.device_id, sizeof(header.device_id)) ||
        !read(&header.layout_version, sizeof(header.layout_version)) ||
        !read(&header.group_count, sizeof(header.group_count)))
    {
        GFXRECON_LOG_WARNING("Ignoring a truncated resource aliasing groups meta-data block.");
        return;
    }

    if (header.layout_version != format::kResourceAliasingGroupsLayoutVersion)
    {
        GFXRECON_LOG_WARNING("Ignoring a resource aliasing groups meta-data block with layout version %u, this "
                             "build reads version %u.",
                             header.layout_version,
                             format::kResourceAliasingGroupsLayoutVersion);
        return;
    }

    // reserve from what the block can actually hold, not from a count a corrupt block controls
    std::vector<ResourceAliasingGroup> groups;
    groups.reserve(
        std::min<size_t>(header.group_count, (buffer_size - offset) / sizeof(format::ResourceAliasingGroupHeader)));

    for (uint32_t group_index = 0; group_index < header.group_count; ++group_index)
    {
        format::ResourceAliasingGroupHeader group_header{};
        if (!read(&group_header, sizeof(group_header)))
        {
            GFXRECON_LOG_WARNING("Ignoring a truncated resource aliasing groups meta-data block.");
            return;
        }

        ResourceAliasingGroup group;
        group.memory_id = group_header.memory_id;
        group.group_id  = group_header.group_id;
        group.members.reserve(std::min<size_t>(group_header.member_count,
                                               (buffer_size - offset) / sizeof(format::ResourceAliasingMemberHeader)));

        for (uint32_t member_index = 0; member_index < group_header.member_count; ++member_index)
        {
            format::ResourceAliasingMemberHeader member_header{};
            if (!read(&member_header, sizeof(member_header)))
            {
                GFXRECON_LOG_WARNING("Ignoring a truncated resource aliasing groups meta-data block.");
                return;
            }

            ResourceAliasingMember member;
            member.resource_id = member_header.resource_id;
            member.bind_offset = member_header.bind_offset;

            switch (static_cast<format::ResourceAliasingResourceType>(member_header.resource_type))
            {
                case format::ResourceAliasingResourceType::kBuffer:
                    member.create_info.emplace<StructPointerDecoder<Decoded_VkBufferCreateInfo>>();
                    break;
                case format::ResourceAliasingResourceType::kImage:
                    member.create_info.emplace<StructPointerDecoder<Decoded_VkImageCreateInfo>>();
                    break;
                case format::ResourceAliasingResourceType::kTensor:
                    member.create_info.emplace<StructPointerDecoder<Decoded_VkTensorCreateInfoARM>>();
                    break;
                default:
                    GFXRECON_LOG_WARNING("Ignoring a resource aliasing groups meta-data block with unknown resource "
                                         "type %u for resource %" PRIu64 ".",
                                         member_header.resource_type,
                                         member_header.resource_id);
                    return;
            }

            bool has_create_info = false;

            for (uint32_t property_index = 0; property_index < member_header.property_count; ++property_index)
            {
                format::ResourceAliasingPropertyHeader property_header{};
                if (!read(&property_header, sizeof(property_header)) ||
                    ((buffer_size - offset) < property_header.property_size))
                {
                    GFXRECON_LOG_WARNING("Ignoring a truncated resource aliasing groups meta-data block.");
                    return;
                }

                if (static_cast<format::ResourceAliasingPropertyId>(property_header.property_id) ==
                    format::ResourceAliasingPropertyId::kCreateInfo)
                {
                    const size_t decoded_size = std::visit(
                        [&](auto& create_info_decoder) {
                            return create_info_decoder.Decode(parameter_buffer + offset, property_header.property_size);
                        },
                        member.create_info);

                    if (decoded_size != property_header.property_size)
                    {
                        GFXRECON_LOG_WARNING("Ignoring a resource aliasing groups meta-data block whose create-info "
                                             "for resource %" PRIu64 " decoded %" PRIuPTR " of %u bytes.",
                                             member_header.resource_id,
                                             decoded_size,
                                             property_header.property_size);
                        return;
                    }
                    has_create_info = true;
                }
                // An unknown property is skipped by its length, which is what lets a reader of this layout
                // version read a block that carries properties added later.

                offset += property_header.property_size;
            }

            if (!has_create_info)
            {
                GFXRECON_LOG_WARNING("Ignoring a resource aliasing groups meta-data block with no create-info for "
                                     "resource %" PRIu64 ".",
                                     member_header.resource_id);
                return;
            }

            group.members.emplace_back(std::move(member));
        }

        groups.emplace_back(std::move(group));
    }

    for (auto consumer : consumers_)
    {
        consumer->ProcessResourceAliasingGroupsCommand(header.device_id, groups);
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
