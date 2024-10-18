/*
** Copyright (c) 2021 LunarG, Inc.
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

#include "decode/dx12_decoder_base.h"

#include "decode/custom_dx12_struct_decoders.h"
#include "generated/generated_dx12_struct_decoders.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void Dx12DecoderBase::DispatchStateBeginMarker(uint64_t frame_number)
{
    for (auto consumer : consumers_)
    {
        consumer->ProcessStateBeginMarker(frame_number);
    }
}

void Dx12DecoderBase::DispatchStateEndMarker(uint64_t frame_number)
{
    for (auto consumer : consumers_)
    {
        consumer->ProcessStateEndMarker(frame_number);
    }
}

void Dx12DecoderBase::DispatchFrameEndMarker(uint64_t frame_number)
{
    for (auto consumer : consumers_)
    {
        consumer->ProcessFrameEndMarker(frame_number);
    }
}

void Dx12DecoderBase::DispatchDisplayMessageCommand(format::ThreadId thread_id, const std::string& message)
{
    GFXRECON_UNREFERENCED_PARAMETER(thread_id);

    for (auto consumer : consumers_)
    {
        consumer->ProcessDisplayMessageCommand(message);
    }
}

void Dx12DecoderBase::DispatchFillMemoryCommand(
    format::ThreadId thread_id, uint64_t memory_id, uint64_t offset, uint64_t size, const uint8_t* data)
{
    GFXRECON_UNREFERENCED_PARAMETER(thread_id);

    for (auto consumer : consumers_)
    {
        consumer->ProcessFillMemoryCommand(memory_id, offset, size, data);
    }
}

void Dx12DecoderBase::DispatchFillMemoryResourceValueCommand(
    const format::FillMemoryResourceValueCommandHeader& command_header, const uint8_t* data)
{
    for (auto consumer : consumers_)
    {
        consumer->ProcessFillMemoryResourceValueCommand(command_header, data);
    }
}

void Dx12DecoderBase::DispatchResizeWindowCommand(format::ThreadId thread_id,
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

void Dx12DecoderBase::DispatchResizeWindowCommand2(
    format::ThreadId thread_id, format::HandleId surface_id, uint32_t width, uint32_t height, uint32_t pre_transform)
{
    GFXRECON_UNREFERENCED_PARAMETER(thread_id);

    for (auto consumer : consumers_)
    {
        consumer->ProcessResizeWindowCommand2(surface_id, width, height, pre_transform);
    }
}

void Dx12DecoderBase::DispatchCreateHardwareBufferCommand(
    format::ThreadId                                    thread_id,
    format::HandleId                                    device_id,
    format::HandleId                                    queue_id,
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
            device_id, queue_id, memory_id, buffer_id, format, width, height, stride, usage, layers, plane_info);
    }
}

void Dx12DecoderBase::DispatchDestroyHardwareBufferCommand(format::ThreadId thread_id, uint64_t buffer_id)
{
    GFXRECON_UNREFERENCED_PARAMETER(thread_id);

    for (auto consumer : consumers_)
    {
        consumer->ProcessDestroyHardwareBufferCommand(buffer_id);
    }
}

void Dx12DecoderBase::DispatchCreateHeapAllocationCommand(format::ThreadId thread_id,
                                                          uint64_t         allocation_id,
                                                          uint64_t         allocation_size)
{
    GFXRECON_UNREFERENCED_PARAMETER(thread_id);

    for (auto consumer : consumers_)
    {
        consumer->ProcessCreateHeapAllocationCommand(allocation_id, allocation_size);
    }
}

void Dx12DecoderBase::DispatchSetDevicePropertiesCommand(format::ThreadId   thread_id,
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

void Dx12DecoderBase::DispatchSetDeviceMemoryPropertiesCommand(
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

void Dx12DecoderBase::DispatchSetOpaqueAddressCommand(format::ThreadId thread_id,
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

void Dx12DecoderBase::DispatchSetRayTracingShaderGroupHandlesCommand(format::ThreadId thread_id,
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

void Dx12DecoderBase::DispatchSetSwapchainImageStateCommand(
    format::ThreadId                                    thread_id,
    format::HandleId                                    device_id,
    format::HandleId                                    swapchain_id,
    uint32_t                                            current_buffer_index,
    const std::vector<format::SwapchainImageStateInfo>& image_state)
{
    GFXRECON_UNREFERENCED_PARAMETER(thread_id);

    for (auto consumer : consumers_)
    {
        consumer->ProcessSetSwapchainImageStateCommand(device_id, swapchain_id, current_buffer_index, image_state);
    }
}

void Dx12DecoderBase::DispatchBeginResourceInitCommand(format::ThreadId thread_id,
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

void Dx12DecoderBase::DispatchEndResourceInitCommand(format::ThreadId thread_id, format::HandleId device_id)
{
    GFXRECON_UNREFERENCED_PARAMETER(thread_id);

    for (auto consumer : consumers_)
    {
        consumer->ProcessEndResourceInitCommand(device_id);
    }
}

void Dx12DecoderBase::DispatchInitBufferCommand(format::ThreadId thread_id,
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

void Dx12DecoderBase::DispatchInitImageCommand(format::ThreadId             thread_id,
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

void Dx12DecoderBase::DispatchInitSubresourceCommand(const format::InitSubresourceCommandHeader& command_header,
                                                     const uint8_t*                              data)
{
    for (auto consumer : consumers_)
    {
        consumer->ProcessInitSubresourceCommand(command_header, data);
    }
}

void Dx12DecoderBase::DispatchInitDx12AccelerationStructureCommand(
    const format::InitDx12AccelerationStructureCommandHeader&       command_header,
    std::vector<format::InitDx12AccelerationStructureGeometryDesc>& geometry_descs,
    const uint8_t*                                                  build_inputs_data)
{
    for (auto consumer : consumers_)
    {
        consumer->ProcessInitDx12AccelerationStructureCommand(command_header, geometry_descs, build_inputs_data);
    }
}

void Dx12DecoderBase::DispatchGetDxgiAdapterInfo(const format::DxgiAdapterInfoCommandHeader& dx12_adapter_info_header)
{
    for (auto consumer : consumers_)
    {
        consumer->ProcessDxgiAdapterInfo(dx12_adapter_info_header);
    }
}

void Dx12DecoderBase::DispatchGetDx12RuntimeInfo(const format::Dx12RuntimeInfoCommandHeader& dx12_runtime_info_header)
{
    for (auto consumer : consumers_)
    {
        consumer->ProcessDx12RuntimeInfo(dx12_runtime_info_header);
    }
}

void Dx12DecoderBase::DispatchSetEnvironmentVariablesCommand(format::SetEnvironmentVariablesCommand& header,
                                                             const char*                             env_string)
{
    for (auto consumer : consumers_)
    {
        consumer->ProcessSetEnvironmentVariablesCommand(header, env_string);
    }
}

void Dx12DecoderBase::SetCurrentBlockIndex(uint64_t block_index)
{
    for (auto consumer : consumers_)
    {
        consumer->SetCurrentBlockIndex(block_index);
    }
}

void Dx12DecoderBase::SetCurrentApiCallId(format::ApiCallId api_call_id)
{
    for (auto consumer : consumers_)
    {
        consumer->SetCurrentApiCallId(api_call_id);
    }
}

size_t Dx12DecoderBase::Decode_ID3D12Device_CheckFeatureSupport(format::HandleId object_id,
                                                                const uint8_t*   parameter_buffer,
                                                                size_t           buffer_size)
{
    size_t        bytes_read = 0;
    D3D12_FEATURE feature{};

    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &feature);

    switch (feature)
    {
        case D3D12_FEATURE_D3D12_OPTIONS:
            bytes_read += DecodeCheckD3D12FeatureSupport<Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS>(
                object_id, feature, (parameter_buffer + bytes_read), (buffer_size - bytes_read));
            break;
        case D3D12_FEATURE_ARCHITECTURE:
            bytes_read += DecodeCheckD3D12FeatureSupport<Decoded_D3D12_FEATURE_DATA_ARCHITECTURE>(
                object_id, feature, (parameter_buffer + bytes_read), (buffer_size - bytes_read));
            break;
        case D3D12_FEATURE_FEATURE_LEVELS:
            bytes_read += DecodeCheckD3D12FeatureSupport<Decoded_D3D12_FEATURE_DATA_FEATURE_LEVELS>(
                object_id, feature, (parameter_buffer + bytes_read), (buffer_size - bytes_read));
            break;
        case D3D12_FEATURE_FORMAT_SUPPORT:
            bytes_read += DecodeCheckD3D12FeatureSupport<Decoded_D3D12_FEATURE_DATA_FORMAT_SUPPORT>(
                object_id, feature, (parameter_buffer + bytes_read), (buffer_size - bytes_read));
            break;
        case D3D12_FEATURE_MULTISAMPLE_QUALITY_LEVELS:
            bytes_read += DecodeCheckD3D12FeatureSupport<Decoded_D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS>(
                object_id, feature, (parameter_buffer + bytes_read), (buffer_size - bytes_read));
            break;
        case D3D12_FEATURE_FORMAT_INFO:
            bytes_read += DecodeCheckD3D12FeatureSupport<Decoded_D3D12_FEATURE_DATA_FORMAT_INFO>(
                object_id, feature, (parameter_buffer + bytes_read), (buffer_size - bytes_read));
            break;
        case D3D12_FEATURE_GPU_VIRTUAL_ADDRESS_SUPPORT:
            bytes_read += DecodeCheckD3D12FeatureSupport<Decoded_D3D12_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT>(
                object_id, feature, (parameter_buffer + bytes_read), (buffer_size - bytes_read));
            break;
        case D3D12_FEATURE_SHADER_MODEL:
            bytes_read += DecodeCheckD3D12FeatureSupport<Decoded_D3D12_FEATURE_DATA_SHADER_MODEL>(
                object_id, feature, (parameter_buffer + bytes_read), (buffer_size - bytes_read));
            break;
        case D3D12_FEATURE_D3D12_OPTIONS1:
            bytes_read += DecodeCheckD3D12FeatureSupport<Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS1>(
                object_id, feature, (parameter_buffer + bytes_read), (buffer_size - bytes_read));
            break;
        case D3D12_FEATURE_PROTECTED_RESOURCE_SESSION_SUPPORT:
            bytes_read += DecodeCheckD3D12FeatureSupport<Decoded_D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_SUPPORT>(
                object_id, feature, (parameter_buffer + bytes_read), (buffer_size - bytes_read));
            break;
        case D3D12_FEATURE_ROOT_SIGNATURE:
            bytes_read += DecodeCheckD3D12FeatureSupport<Decoded_D3D12_FEATURE_DATA_ROOT_SIGNATURE>(
                object_id, feature, (parameter_buffer + bytes_read), (buffer_size - bytes_read));
            break;
        case D3D12_FEATURE_ARCHITECTURE1:
            bytes_read += DecodeCheckD3D12FeatureSupport<Decoded_D3D12_FEATURE_DATA_ARCHITECTURE1>(
                object_id, feature, (parameter_buffer + bytes_read), (buffer_size - bytes_read));
            break;
        case D3D12_FEATURE_D3D12_OPTIONS2:
            bytes_read += DecodeCheckD3D12FeatureSupport<Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS2>(
                object_id, feature, (parameter_buffer + bytes_read), (buffer_size - bytes_read));
            break;
        case D3D12_FEATURE_SHADER_CACHE:
            bytes_read += DecodeCheckD3D12FeatureSupport<Decoded_D3D12_FEATURE_DATA_SHADER_CACHE>(
                object_id, feature, (parameter_buffer + bytes_read), (buffer_size - bytes_read));
            break;
        case D3D12_FEATURE_COMMAND_QUEUE_PRIORITY:
            bytes_read += DecodeCheckD3D12FeatureSupport<Decoded_D3D12_FEATURE_DATA_COMMAND_QUEUE_PRIORITY>(
                object_id, feature, (parameter_buffer + bytes_read), (buffer_size - bytes_read));
            break;
        case D3D12_FEATURE_D3D12_OPTIONS3:
            bytes_read += DecodeCheckD3D12FeatureSupport<Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS3>(
                object_id, feature, (parameter_buffer + bytes_read), (buffer_size - bytes_read));
            break;
        case D3D12_FEATURE_EXISTING_HEAPS:
            bytes_read += DecodeCheckD3D12FeatureSupport<Decoded_D3D12_FEATURE_DATA_EXISTING_HEAPS>(
                object_id, feature, (parameter_buffer + bytes_read), (buffer_size - bytes_read));
            break;
        case D3D12_FEATURE_D3D12_OPTIONS4:
            bytes_read += DecodeCheckD3D12FeatureSupport<Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS4>(
                object_id, feature, (parameter_buffer + bytes_read), (buffer_size - bytes_read));
            break;
        case D3D12_FEATURE_SERIALIZATION:
            bytes_read += DecodeCheckD3D12FeatureSupport<Decoded_D3D12_FEATURE_DATA_SERIALIZATION>(
                object_id, feature, (parameter_buffer + bytes_read), (buffer_size - bytes_read));
            break;
        case D3D12_FEATURE_CROSS_NODE:
            bytes_read += DecodeCheckD3D12FeatureSupport<Decoded_D3D12_FEATURE_DATA_CROSS_NODE>(
                object_id, feature, (parameter_buffer + bytes_read), (buffer_size - bytes_read));
            break;
        case D3D12_FEATURE_D3D12_OPTIONS5:
            bytes_read += DecodeCheckD3D12FeatureSupport<Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS5>(
                object_id, feature, (parameter_buffer + bytes_read), (buffer_size - bytes_read));
            break;
        case D3D12_FEATURE_DISPLAYABLE:
            bytes_read += DecodeCheckD3D12FeatureSupport<Decoded_D3D12_FEATURE_DATA_DISPLAYABLE>(
                object_id, feature, (parameter_buffer + bytes_read), (buffer_size - bytes_read));
            break;
        case D3D12_FEATURE_D3D12_OPTIONS6:
            bytes_read += DecodeCheckD3D12FeatureSupport<Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS6>(
                object_id, feature, (parameter_buffer + bytes_read), (buffer_size - bytes_read));
            break;
        case D3D12_FEATURE_QUERY_META_COMMAND:
            bytes_read += DecodeCheckD3D12FeatureSupport<Decoded_D3D12_FEATURE_DATA_QUERY_META_COMMAND>(
                object_id, feature, (parameter_buffer + bytes_read), (buffer_size - bytes_read));
            break;
        case D3D12_FEATURE_D3D12_OPTIONS7:
            bytes_read += DecodeCheckD3D12FeatureSupport<Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS7>(
                object_id, feature, (parameter_buffer + bytes_read), (buffer_size - bytes_read));
            break;
        case D3D12_FEATURE_PROTECTED_RESOURCE_SESSION_TYPE_COUNT:
            bytes_read +=
                DecodeCheckD3D12FeatureSupport<Decoded_D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPE_COUNT>(
                    object_id, feature, (parameter_buffer + bytes_read), (buffer_size - bytes_read));
            break;
        case D3D12_FEATURE_PROTECTED_RESOURCE_SESSION_TYPES:
            bytes_read += DecodeCheckD3D12FeatureSupport<Decoded_D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPES>(
                object_id, feature, (parameter_buffer + bytes_read), (buffer_size - bytes_read));
            break;
        case D3D12_FEATURE_D3D12_OPTIONS8:
            bytes_read += DecodeCheckD3D12FeatureSupport<Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS8>(
                object_id, feature, (parameter_buffer + bytes_read), (buffer_size - bytes_read));
            break;
        case D3D12_FEATURE_D3D12_OPTIONS9:
            bytes_read += DecodeCheckD3D12FeatureSupport<Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS9>(
                object_id, feature, (parameter_buffer + bytes_read), (buffer_size - bytes_read));
            break;
        case D3D12_FEATURE_D3D12_OPTIONS10:
            bytes_read += DecodeCheckD3D12FeatureSupport<Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS10>(
                object_id, feature, (parameter_buffer + bytes_read), (buffer_size - bytes_read));
            break;
        case D3D12_FEATURE_D3D12_OPTIONS11:
            bytes_read += DecodeCheckD3D12FeatureSupport<Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS11>(
                object_id, feature, (parameter_buffer + bytes_read), (buffer_size - bytes_read));
            break;
        case D3D12_FEATURE_D3D12_OPTIONS12:
            bytes_read += DecodeCheckD3D12FeatureSupport<Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS12>(
                object_id, feature, (parameter_buffer + bytes_read), (buffer_size - bytes_read));
            break;
        case D3D12_FEATURE_D3D12_OPTIONS13:
            bytes_read += DecodeCheckD3D12FeatureSupport<Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS13>(
                object_id, feature, (parameter_buffer + bytes_read), (buffer_size - bytes_read));
            break;
        case D3D12_FEATURE_D3D12_OPTIONS14:
            bytes_read += DecodeCheckD3D12FeatureSupport<Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS14>(
                object_id, feature, (parameter_buffer + bytes_read), (buffer_size - bytes_read));
            break;
        case D3D12_FEATURE_D3D12_OPTIONS15:
            bytes_read += DecodeCheckD3D12FeatureSupport<Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS15>(
                object_id, feature, (parameter_buffer + bytes_read), (buffer_size - bytes_read));
            break;
        case D3D12_FEATURE_D3D12_OPTIONS16:
            bytes_read += DecodeCheckD3D12FeatureSupport<Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS16>(
                object_id, feature, (parameter_buffer + bytes_read), (buffer_size - bytes_read));
            break;
        case D3D12_FEATURE_D3D12_OPTIONS17:
            bytes_read += DecodeCheckD3D12FeatureSupport<Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS17>(
                object_id, feature, (parameter_buffer + bytes_read), (buffer_size - bytes_read));
            break;
        case D3D12_FEATURE_D3D12_OPTIONS18:
            bytes_read += DecodeCheckD3D12FeatureSupport<Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS18>(
                object_id, feature, (parameter_buffer + bytes_read), (buffer_size - bytes_read));
            break;
        case D3D12_FEATURE_D3D12_OPTIONS19:
            bytes_read += DecodeCheckD3D12FeatureSupport<Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS19>(
                object_id, feature, (parameter_buffer + bytes_read), (buffer_size - bytes_read));
            break;
        default:
            GFXRECON_LOG_FATAL("Failed to decode ID3D12Device::CheckFeatureSupport pFeatureData parameter with "
                               "unrecognized D3D12_FEATURE type %d",
                               feature);
            break;
    }

    return bytes_read;
}

size_t Dx12DecoderBase::Decode_IDXGIFactory5_CheckFeatureSupport(format::HandleId object_id,
                                                                 const uint8_t*   parameter_buffer,
                                                                 size_t           buffer_size)
{
    size_t       bytes_read = 0;
    DXGI_FEATURE feature{};
    UINT         feature_data_size = 0;
    HRESULT      return_value      = E_FAIL;

    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &feature);

    switch (feature)
    {
        case DXGI_FEATURE_PRESENT_ALLOW_TEARING:
        {
            BOOL allow_tearing = FALSE;
            bytes_read += ValueDecoder::DecodeInt32Value(
                (parameter_buffer + bytes_read), (buffer_size - bytes_read), &allow_tearing);
            bytes_read += ValueDecoder::DecodeUInt32Value(
                (parameter_buffer + bytes_read), (buffer_size - bytes_read), &feature_data_size);
            bytes_read += ValueDecoder::DecodeInt32Value(
                (parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

            for (auto consumer : GetConsumers())
            {
                consumer->Process_IDXGIFactory5_CheckFeatureSupport(object_id,
                                                                    return_value,
                                                                    feature,
                                                                    static_cast<void*>(&allow_tearing),
                                                                    static_cast<void*>(&allow_tearing),
                                                                    feature_data_size);
            }
        }
        break;
        default:
            GFXRECON_LOG_FATAL("Failed to decode IDXGIFactory5::CheckFeatureSupport pFeatureData parameter with "
                               "unrecognized DXGI_FEATURE type %d",
                               feature);
            break;
    }
    return bytes_read;
}

size_t Dx12DecoderBase::Decode_ID3D12Resource_WriteToSubresource(format::HandleId object_id,
                                                                 const uint8_t*   parameter_buffer,
                                                                 size_t           buffer_size)
{
    size_t bytes_read = 0;

    UINT                                    DstSubresource;
    StructPointerDecoder<Decoded_D3D12_BOX> pDstBox;
    PointerDecoder<uint8_t>                 pSrcData;
    UINT                                    SrcRowPitch;
    UINT                                    SrcDepthPitch;
    HRESULT                                 return_value;

    bytes_read +=
        ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &DstSubresource);
    bytes_read += pDstBox.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSrcData.DecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    bytes_read +=
        ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &SrcRowPitch);
    bytes_read +=
        ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &SrcDepthPitch);
    bytes_read +=
        ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Resource_WriteToSubresource(
            object_id, return_value, DstSubresource, &pDstBox, pSrcData.GetPointer(), SrcRowPitch, SrcDepthPitch);
    }
    return bytes_read;
}

void Dx12DecoderBase::DecodeMethodCall(format::ApiCallId  call_id,
                                       format::HandleId   object_id,
                                       const ApiCallInfo& call_options,
                                       const uint8_t*     parameter_buffer,
                                       size_t             buffer_size)
{
    GFXRECON_UNREFERENCED_PARAMETER(call_options);

    switch (call_id)
    {
        case format::ApiCallId::ApiCall_ID3D12Device_CheckFeatureSupport:
            Decode_ID3D12Device_CheckFeatureSupport(object_id, parameter_buffer, buffer_size);
            break;
        case format::ApiCallId::ApiCall_IDXGIFactory5_CheckFeatureSupport:
            Decode_IDXGIFactory5_CheckFeatureSupport(object_id, parameter_buffer, buffer_size);
            break;
        case format::ApiCallId::ApiCall_ID3D12Resource_WriteToSubresource:
            Decode_ID3D12Resource_WriteToSubresource(object_id, parameter_buffer, buffer_size);
            break;
        default:
            break;
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
