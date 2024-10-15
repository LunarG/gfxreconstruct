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

#include "decode/vulkan_preload_decoder_base.h"
#include "decode/vulkan_struct_packet.h"
#include "generated/generated_vulkan_struct_packet.h"

#include "decode/descriptor_update_template_decoder.h"
#include "decode/pointer_decoder.h"
#include "decode/value_decoder.h"
#include "format/format.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

template <typename T>
inline T* VulkanPreloadDecoderBase::SavePointer(void* buffer, size_t size)
{
    T* data_ = reinterpret_cast<T*>(PreloadDecodeAllocator::Allocate<char>(size));
    memcpy(data_, buffer, size);
    return data_;
}

void VulkanPreloadDecoderBase::WaitIdle()
{
    for (auto consumer : consumers_)
    {
        consumer->WaitDevicesIdle();
    }
}

void VulkanPreloadDecoderBase::DispatchStateBeginMarker(uint64_t frame_number)
{
    for (auto consumer : consumers_)
    {
        consumer->ProcessStateBeginMarker(frame_number);
    }
}

void VulkanPreloadDecoderBase::DispatchStateEndMarker(uint64_t frame_number)
{
    for (auto consumer : consumers_)
    {
        consumer->ProcessStateEndMarker(frame_number);
    }
}

void VulkanPreloadDecoderBase::DispatchFrameEndMarker(uint64_t frame_number)
{
    for (auto consumer : consumers_)
    {
        consumer->ProcessFrameEndMarker(frame_number);
    }
}

void VulkanPreloadDecoderBase::DispatchDisplayMessageCommand(format::ThreadId thread_id, const std::string& message)
{
    Packet_DispatchDisplayMessageCommand* packet =
        PreloadDecodeAllocator::Allocate<Packet_DispatchDisplayMessageCommand>();
    packet->packet_id = gfxrecon::format::PacketCall_DispatchDisplayMessageCommand;
    packet->thread_id = thread_id;

    AddPacket(reinterpret_cast<void*>(packet));
}

void VulkanPreloadDecoderBase::DispatchFillMemoryCommand(
    format::ThreadId thread_id, uint64_t memory_id, uint64_t offset, uint64_t size, const uint8_t* data)
{
    Packet_DispatchFillMemoryCommand* packet = PreloadDecodeAllocator::Allocate<Packet_DispatchFillMemoryCommand>();
    packet->packet_id                        = gfxrecon::format::PacketCall_DispatchFillMemoryCommand;
    packet->thread_id                        = thread_id;
    packet->memory_id                        = memory_id;
    packet->offset                           = offset;
    packet->size                             = size;

    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, size);
    packet->data = SavePointer<uint8_t>(const_cast<uint8_t*>(data), size);

    AddPacket(reinterpret_cast<void*>(packet));
}

void VulkanPreloadDecoderBase::DispatchFixDeviceAddresCommand(const format::FixDeviceAddressCommandHeader& header,
                                                              const format::AddressLocationInfo*           infos)
{
    Packet_DispatchFixDeviceAddresCommand* packet =
        PreloadDecodeAllocator::Allocate<Packet_DispatchFixDeviceAddresCommand>();
    packet->packet_id = gfxrecon::format::PacketCall_DispatchFixDeviceAddresCommand;
    packet->header    = header;
    packet->infos     = SavePointer<format::AddressLocationInfo>(
        const_cast<format::AddressLocationInfo*>(infos), header.num_of_locations * sizeof(format::AddressLocationInfo));

    AddPacket(reinterpret_cast<void*>(packet));
}

void VulkanPreloadDecoderBase::DispatchExeFileInfo(format::ThreadId thread_id, format::ExeFileInfoBlock& info)
{
    // DX
    GFXRECON_UNREFERENCED_PARAMETER(thread_id);
    GFXRECON_UNREFERENCED_PARAMETER(info);
}

void VulkanPreloadDecoderBase::DispatchFillMemoryResourceValueCommand(
    const format::FillMemoryResourceValueCommandHeader& command_header, const uint8_t* data)
{
    // DX
    GFXRECON_UNREFERENCED_PARAMETER(command_header);
    GFXRECON_UNREFERENCED_PARAMETER(data);
}

void VulkanPreloadDecoderBase::DispatchResizeWindowCommand(format::ThreadId thread_id,
                                                           format::HandleId surface_id,
                                                           uint32_t         width,
                                                           uint32_t         height)
{
    Packet_DispatchResizeWindowCommand* packet = PreloadDecodeAllocator::Allocate<Packet_DispatchResizeWindowCommand>();
    packet->packet_id                          = gfxrecon::format::PacketCall_DispatchResizeWindowCommand;
    packet->thread_id                          = thread_id;
    packet->surface_id                         = surface_id;
    packet->width                              = width;
    packet->height                             = height;

    AddPacket(reinterpret_cast<void*>(packet));
}

void VulkanPreloadDecoderBase::DispatchResizeWindowCommand2(
    format::ThreadId thread_id, format::HandleId surface_id, uint32_t width, uint32_t height, uint32_t pre_transform)
{
    Packet_DispatchResizeWindowCommand2* packet =
        PreloadDecodeAllocator::Allocate<Packet_DispatchResizeWindowCommand2>();
    packet->packet_id     = gfxrecon::format::PacketCall_DispatchResizeWindowCommand2;
    packet->thread_id     = thread_id;
    packet->surface_id    = surface_id;
    packet->width         = width;
    packet->height        = height;
    packet->pre_transform = pre_transform;

    AddPacket(reinterpret_cast<void*>(packet));
}

void VulkanPreloadDecoderBase::DispatchCreateHardwareBufferCommand(
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
    Packet_DispatchCreateHardwareBufferCommand* packet =
        PreloadDecodeAllocator::Allocate<Packet_DispatchCreateHardwareBufferCommand>();
    packet->packet_id  = gfxrecon::format::PacketCall_DispatchCreateHardwareBufferCommand;
    packet->thread_id  = thread_id;
    packet->memory_id  = memory_id;
    packet->buffer_id  = buffer_id;
    packet->format     = format;
    packet->width      = width;
    packet->height     = height;
    packet->stride     = stride;
    packet->usage      = usage;
    packet->layers     = layers;
    packet->plane_info = plane_info;

    AddPacket(reinterpret_cast<void*>(packet));
}

void VulkanPreloadDecoderBase::DispatchDestroyHardwareBufferCommand(format::ThreadId thread_id, uint64_t buffer_id)
{
    Packet_DispatchDestroyHardwareBufferCommand* packet =
        PreloadDecodeAllocator::Allocate<Packet_DispatchDestroyHardwareBufferCommand>();
    packet->packet_id = gfxrecon::format::PacketCall_DispatchDestroyHardwareBufferCommand;
    packet->thread_id = thread_id;
    packet->buffer_id = buffer_id;

    AddPacket(reinterpret_cast<void*>(packet));
}

void VulkanPreloadDecoderBase::DispatchCreateHeapAllocationCommand(format::ThreadId thread_id,
                                                                   uint64_t         allocation_id,
                                                                   uint64_t         allocation_size)
{
    // DX
    GFXRECON_UNREFERENCED_PARAMETER(thread_id);
    GFXRECON_UNREFERENCED_PARAMETER(allocation_id);
    GFXRECON_UNREFERENCED_PARAMETER(allocation_size);
}

void VulkanPreloadDecoderBase::DispatchSetDevicePropertiesCommand(format::ThreadId thread_id,
                                                                  format::HandleId physical_device_id,
                                                                  uint32_t         api_version,
                                                                  uint32_t         driver_version,
                                                                  uint32_t         vendor_id,
                                                                  uint32_t         device_id,
                                                                  uint32_t         device_type,
                                                                  const uint8_t pipeline_cache_uuid[format::kUuidSize],
                                                                  const std::string& device_name)
{
    Packet_DispatchSetDevicePropertiesCommand* packet =
        PreloadDecodeAllocator::Allocate<Packet_DispatchSetDevicePropertiesCommand>();
    packet->packet_id          = gfxrecon::format::PacketCall_DispatchSetDevicePropertiesCommand;
    packet->thread_id          = thread_id;
    packet->physical_device_id = physical_device_id;
    packet->api_version        = api_version;
    packet->driver_version     = driver_version;
    packet->vendor_id          = vendor_id;
    packet->device_id          = device_id;
    packet->device_type        = device_type;
    for (int i = 0; i < format::kUuidSize; i++)
    {
        packet->pipeline_cache_uuid[i] = pipeline_cache_uuid[i];
    }
    packet->device_name = device_name;

    AddPacket(reinterpret_cast<void*>(packet));
}

void VulkanPreloadDecoderBase::DispatchSetDeviceMemoryPropertiesCommand(
    format::ThreadId                             thread_id,
    format::HandleId                             physical_device_id,
    const std::vector<format::DeviceMemoryType>& memory_types,
    const std::vector<format::DeviceMemoryHeap>& memory_heaps)
{
    Packet_DispatchSetDeviceMemoryPropertiesCommand* packet =
        PreloadDecodeAllocator::Allocate<Packet_DispatchSetDeviceMemoryPropertiesCommand>();
    packet->packet_id          = gfxrecon::format::PacketCall_DispatchSetDeviceMemoryPropertiesCommand;
    packet->thread_id          = thread_id;
    packet->physical_device_id = physical_device_id;
    packet->memory_types       = memory_types;
    packet->memory_heaps       = memory_heaps;

    AddPacket(reinterpret_cast<void*>(packet));
}

void VulkanPreloadDecoderBase::DispatchSetOpaqueAddressCommand(format::ThreadId thread_id,
                                                               format::HandleId device_id,
                                                               format::HandleId object_id,
                                                               uint64_t         address)
{
    Packet_DispatchSetOpaqueAddressCommand* packet =
        PreloadDecodeAllocator::Allocate<Packet_DispatchSetOpaqueAddressCommand>();
    packet->packet_id = gfxrecon::format::PacketCall_DispatchSetOpaqueAddressCommand;
    packet->thread_id = thread_id;
    packet->device_id = device_id;
    packet->object_id = object_id;
    packet->address   = address;

    AddPacket(reinterpret_cast<void*>(packet));
}

void VulkanPreloadDecoderBase::DispatchSetRayTracingShaderGroupHandlesCommand(format::ThreadId thread_id,
                                                                              format::HandleId device_id,
                                                                              format::HandleId pipeline_id,
                                                                              size_t           data_size,
                                                                              const uint8_t*   data)
{
    Packet_DispatchSetRayTracingShaderGroupHandlesCommand* packet =
        PreloadDecodeAllocator::Allocate<Packet_DispatchSetRayTracingShaderGroupHandlesCommand>();
    packet->packet_id   = gfxrecon::format::PacketCall_DispatchSetRayTracingShaderGroupHandlesCommand;
    packet->thread_id   = thread_id;
    packet->device_id   = device_id;
    packet->pipeline_id = pipeline_id;
    packet->data_size   = data_size;

    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, data_size);
    packet->data = SavePointer<uint8_t>(const_cast<uint8_t*>(data), data_size);

    AddPacket(reinterpret_cast<void*>(packet));
}

void VulkanPreloadDecoderBase::DispatchSetSwapchainImageStateCommand(
    format::ThreadId                                    thread_id,
    format::HandleId                                    device_id,
    format::HandleId                                    swapchain_id,
    uint32_t                                            last_presented_image,
    const std::vector<format::SwapchainImageStateInfo>& image_state)
{
    Packet_DispatchSetSwapchainImageStateCommand* packet =
        PreloadDecodeAllocator::Allocate<Packet_DispatchSetSwapchainImageStateCommand>();
    packet->packet_id            = gfxrecon::format::PacketCall_DispatchSetSwapchainImageStateCommand;
    packet->thread_id            = thread_id;
    packet->device_id            = device_id;
    packet->swapchain_id         = swapchain_id;
    packet->last_presented_image = last_presented_image;
    packet->image_state          = image_state;

    AddPacket(reinterpret_cast<void*>(packet));
}

void VulkanPreloadDecoderBase::DispatchBeginResourceInitCommand(format::ThreadId thread_id,
                                                                format::HandleId device_id,
                                                                uint64_t         max_resource_size,
                                                                uint64_t         max_copy_size)
{
    Packet_DispatchBeginResourceInitCommand* packet =
        PreloadDecodeAllocator::Allocate<Packet_DispatchBeginResourceInitCommand>();
    packet->packet_id         = gfxrecon::format::PacketCall_DispatchBeginResourceInitCommand;
    packet->thread_id         = thread_id;
    packet->device_id         = device_id;
    packet->max_resource_size = max_resource_size;
    packet->max_copy_size     = max_copy_size;

    AddPacket(reinterpret_cast<void*>(packet));
}

void VulkanPreloadDecoderBase::DispatchEndResourceInitCommand(format::ThreadId thread_id, format::HandleId device_id)
{
    Packet_DispatchEndResourceInitCommand* packet =
        PreloadDecodeAllocator::Allocate<Packet_DispatchEndResourceInitCommand>();
    packet->packet_id = gfxrecon::format::PacketCall_DispatchEndResourceInitCommand;
    packet->thread_id = thread_id;
    packet->device_id = device_id;

    AddPacket(reinterpret_cast<void*>(packet));
}

void VulkanPreloadDecoderBase::DispatchInitBufferCommand(format::ThreadId thread_id,
                                                         format::HandleId device_id,
                                                         format::HandleId buffer_id,
                                                         uint64_t         data_size,
                                                         const uint8_t*   data)
{
    Packet_DispatchInitBufferCommand* packet = PreloadDecodeAllocator::Allocate<Packet_DispatchInitBufferCommand>();
    packet->packet_id                        = gfxrecon::format::PacketCall_DispatchInitBufferCommand;
    packet->thread_id                        = thread_id;
    packet->device_id                        = device_id;
    packet->buffer_id                        = buffer_id;
    packet->data_size                        = data_size;

    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, data_size);
    packet->data = SavePointer<uint8_t>(const_cast<uint8_t*>(data), data_size);

    AddPacket(reinterpret_cast<void*>(packet));
}

void VulkanPreloadDecoderBase::DispatchInitImageCommand(format::ThreadId             thread_id,
                                                        format::HandleId             device_id,
                                                        format::HandleId             image_id,
                                                        uint64_t                     data_size,
                                                        uint32_t                     aspect,
                                                        uint32_t                     layout,
                                                        const std::vector<uint64_t>& level_sizes,
                                                        const uint8_t*               data)
{
    Packet_DispatchInitImageCommand* packet = PreloadDecodeAllocator::Allocate<Packet_DispatchInitImageCommand>();
    packet->packet_id                       = gfxrecon::format::PacketCall_DispatchInitImageCommand;
    packet->thread_id                       = thread_id;
    packet->device_id                       = device_id;
    packet->image_id                        = image_id;
    packet->aspect                          = aspect;
    packet->layout                          = layout;
    packet->level_sizes                     = level_sizes;

    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, data_size);
    packet->data = SavePointer<uint8_t>(const_cast<uint8_t*>(data), data_size);

    AddPacket(reinterpret_cast<void*>(packet));
}

/// @note Dead code, never called.
/// @note The Vulkan Layer does not encode this and no Vulkan consumers process it. It is one of several DX12-specific
/// metablocks which could have stubbed ({}) versions of their dispatch functions in ApiDecoder.
void VulkanPreloadDecoderBase::DispatchInitSubresourceCommand(
    const format::InitSubresourceCommandHeader& command_header, const uint8_t* data)
{
    // DX
    GFXRECON_UNREFERENCED_PARAMETER(command_header);
    GFXRECON_UNREFERENCED_PARAMETER(data);
}

size_t VulkanPreloadDecoderBase::PreloadDecode_vkUpdateDescriptorSetWithTemplate(const ApiCallInfo& call_info,
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
    bytes_read += pData.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkUpdateDescriptorSetWithTemplate* packet = new Packet_vkUpdateDescriptorSetWithTemplate;
    packet->packet_id                                = gfxrecon::format::PacketCall_vkUpdateDescriptorSetWithTemplate;
    packet->call_info                                = call_info;
    packet->device                                   = device;
    packet->descriptorSet                            = descriptorSet;
    packet->descriptorUpdateTemplate                 = descriptorUpdateTemplate;
    packet->pData                                    = pData;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoderBase::PreloadDecode_vkCmdPushDescriptorSetWithTemplateKHR(const ApiCallInfo& call_info,
                                                                                     const uint8_t* parameter_buffer,
                                                                                     size_t         buffer_size)
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
    bytes_read += pData.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdPushDescriptorSetWithTemplateKHR* packet = new Packet_vkCmdPushDescriptorSetWithTemplateKHR;
    packet->packet_id                = gfxrecon::format::PacketCall_vkCmdPushDescriptorSetWithTemplateKHR;
    packet->call_info                = call_info;
    packet->commandBuffer            = commandBuffer;
    packet->descriptorUpdateTemplate = descriptorUpdateTemplate;
    packet->layout                   = layout;
    packet->set                      = set;
    packet->pData                    = pData;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoderBase::PreloadDecode_vkCmdPushDescriptorSetWithTemplate2KHR(const ApiCallInfo& call_info,
                                                                                      const uint8_t* parameter_buffer,
                                                                                      size_t         buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId                                                     commandBuffer;
    StructPointerDecoder<Decoded_VkPushDescriptorSetWithTemplateInfoKHR> pPushDescriptorSetWithTemplateInfo;

    bytes_read +=
        ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read +=
        pPushDescriptorSetWithTemplateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pPushDescriptorSetWithTemplateInfo.GetMetaStructPointer()->pData.PreloadDecode(
        (parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdPushDescriptorSetWithTemplate2KHR* packet = new Packet_vkCmdPushDescriptorSetWithTemplate2KHR;
    packet->packet_id                          = gfxrecon::format::PacketCall_vkCmdPushDescriptorSetWithTemplate2KHR;
    packet->call_info                          = call_info;
    packet->commandBuffer                      = commandBuffer;
    packet->pPushDescriptorSetWithTemplateInfo = pPushDescriptorSetWithTemplateInfo;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoderBase::PreloadDecode_vkUpdateDescriptorSetWithTemplateKHR(const ApiCallInfo& call_info,
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
    bytes_read += pData.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkUpdateDescriptorSetWithTemplateKHR* packet = new Packet_vkUpdateDescriptorSetWithTemplateKHR;
    packet->packet_id                = gfxrecon::format::PacketCall_vkUpdateDescriptorSetWithTemplateKHR;
    packet->call_info                = call_info;
    packet->device                   = device;
    packet->descriptorSet            = descriptorSet;
    packet->descriptorUpdateTemplate = descriptorUpdateTemplate;
    packet->pData                    = pData;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoderBase::PreloadDecode_vkCreateRayTracingPipelinesKHR(const ApiCallInfo& call_info,
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
    bytes_read += pCreateInfos.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pPipelines.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read +=
        ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCreateRayTracingPipelinesKHR* packet = new Packet_vkCreateRayTracingPipelinesKHR;
    packet->packet_id                             = gfxrecon::format::PacketCall_vkCreateRayTracingPipelinesKHR;
    packet->call_info                             = call_info;
    packet->returnValue                           = return_value;
    packet->device                                = device;
    packet->deferredOperation                     = deferredOperation;
    packet->pipelineCache                         = pipelineCache;
    packet->createInfoCount                       = createInfoCount;
    packet->pCreateInfos                          = pCreateInfos;
    packet->pAllocator                            = pAllocator;
    packet->pPipelines                            = pPipelines;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoderBase::PreloadDecode_vkDeferredOperationJoinKHR(const ApiCallInfo& call_info,
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

    Packet_vkDeferredOperationJoinKHR* packet = new Packet_vkDeferredOperationJoinKHR;
    packet->packet_id                         = gfxrecon::format::PacketCall_vkDeferredOperationJoinKHR;
    packet->call_info                         = call_info;
    packet->return_value                      = return_value;
    packet->device                            = device;
    packet->operation                         = operation;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

void VulkanPreloadDecoderBase::DecodeFunctionCall(format::ApiCallId  call_id,
                                                  const ApiCallInfo& call_info,
                                                  const uint8_t*     parameter_buffer,
                                                  size_t             buffer_size)
{
    GFXRECON_UNREFERENCED_PARAMETER(call_info);

    switch (call_id)
    {
        case format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplate:
            PreloadDecode_vkUpdateDescriptorSetWithTemplate(call_info, parameter_buffer, buffer_size);
            break;
        case format::ApiCallId::ApiCall_vkCmdPushDescriptorSetWithTemplateKHR:
            PreloadDecode_vkCmdPushDescriptorSetWithTemplateKHR(call_info, parameter_buffer, buffer_size);
            break;
        case format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplateKHR:
            PreloadDecode_vkUpdateDescriptorSetWithTemplateKHR(call_info, parameter_buffer, buffer_size);
            break;
        case format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesKHR:
            PreloadDecode_vkCreateRayTracingPipelinesKHR(call_info, parameter_buffer, buffer_size);
            break;
        case format::ApiCallId::ApiCall_vkCmdPushDescriptorSetWithTemplate2KHR:
            PreloadDecode_vkCmdPushDescriptorSetWithTemplate2KHR(call_info, parameter_buffer, buffer_size);
            break;
        case format::ApiCallId::ApiCall_vkDeferredOperationJoinKHR:
            PreloadDecode_vkDeferredOperationJoinKHR(call_info, parameter_buffer, buffer_size);
            break;
        default:
            break;
    }
}

void VulkanPreloadDecoderBase::DispatchSetTlasToBlasDependencyCommand(format::HandleId                     tlas,
                                                                      const std::vector<format::HandleId>& blases)
{
    Packet_DispatchSetTlasToBlasDependencyCommand* packet =
        PreloadDecodeAllocator::Allocate<Packet_DispatchSetTlasToBlasDependencyCommand>();
    packet->packet_id = gfxrecon::format::PacketCall_DispatchSetTlasToBlasDependencyCommand;
    packet->tlas      = tlas;
    packet->blases    = blases;

    AddPacket(reinterpret_cast<void*>(packet));
}

void VulkanPreloadDecoderBase::DispatchVulkanAccelerationStructuresBuildMetaCommand(const uint8_t* parameter_buffer,
                                                                                    size_t         buffer_size)
{

    format::HandleId                                                          device_id;
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR> pInfos;
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildRangeInfoKHR*>   ppRangeInfos;

    std::size_t bytes_read = ValueDecoder::DecodeHandleIdValue(parameter_buffer, buffer_size, &device_id);
    bytes_read += pInfos.PreloadDecode(parameter_buffer + bytes_read, buffer_size - bytes_read);
    bytes_read += ppRangeInfos.PreloadDecode(parameter_buffer + bytes_read, buffer_size - bytes_read);

    std::vector<std::vector<VkAccelerationStructureInstanceKHR>> instance_buffers;
    if (bytes_read < buffer_size)
    {
        for (uint32_t i = 0; i < pInfos.GetLength(); ++i)
        {
            if (pInfos.GetPointer()[i].type != VK_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL_KHR)
            {
                continue;
            }

            uint32_t geometry_count = pInfos.GetPointer()[i].geometryCount;
            for (uint32_t g = 0; g < geometry_count; ++g)
            {
                instance_buffers.emplace_back(
                    std::vector<VkAccelerationStructureInstanceKHR>(ppRangeInfos.GetPointer()[g]->primitiveCount));
                util::platform::MemoryCopy(instance_buffers.back().data(),
                                           instance_buffers.back().size() * sizeof(VkAccelerationStructureInstanceKHR),
                                           parameter_buffer + bytes_read,
                                           instance_buffers.back().size() * sizeof(VkAccelerationStructureInstanceKHR));
                bytes_read += instance_buffers.back().size() * sizeof(VkAccelerationStructureInstanceKHR);
            }
        }
    }

    Packet_DispatchVulkanAccelerationStructuresBuildMetaCommand* packet =
        PreloadDecodeAllocator::Allocate<Packet_DispatchVulkanAccelerationStructuresBuildMetaCommand>();
    packet->packet_id             = gfxrecon::format::PacketCall_DispatchVulkanAccelerationStructuresBuildMetaCommand;
    packet->device                = device_id;
    packet->info_count            = pInfos.GetLength();
    packet->pInfos                = pInfos;
    packet->ppRangeInfos          = ppRangeInfos;
    packet->instance_buffers_data = instance_buffers;

    AddPacket(reinterpret_cast<void*>(packet));
}

void VulkanPreloadDecoderBase::DispatchVulkanAccelerationStructuresCopyMetaCommand(const uint8_t* parameter_buffer,
                                                                                   size_t         buffer_size)
{
    format::HandleId                                                 device_id;
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureInfoKHR> pInfos;

    std::size_t bytes_read = ValueDecoder::DecodeHandleIdValue(parameter_buffer, buffer_size, &device_id);
    bytes_read += pInfos.PreloadDecode(parameter_buffer + bytes_read, buffer_size - bytes_read);

    Packet_DispatchVulkanAccelerationStructuresCopyMetaCommand* packet =
        PreloadDecodeAllocator::Allocate<Packet_DispatchVulkanAccelerationStructuresCopyMetaCommand>();
    packet->packet_id  = gfxrecon::format::PacketCall_DispatchVulkanAccelerationStructuresCopyMetaCommand;
    packet->device     = device_id;
    packet->copy_infos = pInfos;

    AddPacket(reinterpret_cast<void*>(packet));
}

void VulkanPreloadDecoderBase::DispatchVulkanAccelerationStructuresWritePropertiesMetaCommand(
    const uint8_t* parameter_buffer, size_t buffer_size)
{
    format::HandleId device_id;
    VkQueryType      query_type;
    format::HandleId acceleration_structure_id;

    std::size_t bytes_read = ValueDecoder::DecodeHandleIdValue(parameter_buffer, sizeof(format::HandleId), &device_id);
    bytes_read += ValueDecoder::DecodeEnumValue(parameter_buffer + bytes_read, sizeof(VkQueryType), &query_type);
    bytes_read += ValueDecoder::DecodeHandleIdValue(
        parameter_buffer + bytes_read, sizeof(format::HandleId), &acceleration_structure_id);

    Packet_DispatchVulkanAccelerationStructuresWritePropertiesMetaCommand* packet =
        PreloadDecodeAllocator::Allocate<Packet_DispatchVulkanAccelerationStructuresWritePropertiesMetaCommand>();
    packet->packet_id = gfxrecon::format::PacketCall_DispatchVulkanAccelerationStructuresWritePropertiesMetaCommand;
    packet->copy_query_typeinfos      = query_type;
    packet->acceleration_structure_id = acceleration_structure_id;

    AddPacket(reinterpret_cast<void*>(packet));
}

void VulkanPreloadDecoderBase::SetCurrentBlockIndex(uint64_t block_index)
{
    for (auto consumer : consumers_)
    {
        consumer->SetCurrentBlockIndex(block_index);
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
