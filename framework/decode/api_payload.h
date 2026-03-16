/*
** Copyright (c) 2025 LunarG, Inc.
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

#ifndef GFXRECON_API_PAYLOAD_H
#define GFXRECON_API_PAYLOAD_H

#include "api_decoder.h" // for ApiDecoder method pointers
#include "util/type_traits_extras.h"

#include <array>
#include <memory>
#include <string>
#include <tuple>
#include <variant>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

template <typename Command, typename Dummy = void>
struct DispatchHasCallId : std::false_type
{};

template <typename Command>
struct DispatchHasCallId<Command, std::void_t<decltype(std::declval<Command>().call_id)>> : std::true_type
{};

template <typename Command, typename Dummy = void>
struct DispatchHasMetaDataId : std::false_type
{};

template <typename Command>
struct DispatchHasMetaDataId<Command, std::void_t<decltype(std::declval<Command>().meta_data_id)>> : std::true_type
{};

template <typename Command, typename Dummy = void>
struct DispatchHasData : std::false_type
{};

template <typename Command>
struct DispatchHasData<Command, std::void_t<decltype(std::declval<Command>().data)>> : std::true_type
{};

template <typename Command, typename Dummy = void>
struct DispatchHasDataSize : std::false_type
{};

template <typename Command>
struct DispatchHasDataSize<Command, std::void_t<decltype(std::declval<Command>().data_size)>> : std::true_type
{};

template <typename Command, typename Dummy = void>
struct DispatchHasCommandHeader : std::false_type
{};

template <typename Command>
struct DispatchHasCommandHeader<Command, std::void_t<decltype(std::declval<Command>().command_header)>> : std::true_type
{};

template <typename Command>
struct DispatchHasAllocGuard : std::false_type
{};

// ---- Flags base (one place for size and per-command booleans) ----------------
//
// The flag traits class is a base class for each of the DispatchTraits specializations
// defined below.  The flags control the storage and dispatch characteristics of the
// Command type.
template <typename Command>
struct DispatchFlagTraits
{
    static constexpr bool kHasCallId        = DispatchHasCallId<Command>::value;
    static constexpr bool kHasMetaDataId    = DispatchHasMetaDataId<Command>::value;
    static constexpr bool kHasAllocGuard    = DispatchHasAllocGuard<Command>::value;
    static constexpr bool kHasData          = DispatchHasData<Command>::value;
    static constexpr bool kHasDataSize      = DispatchHasDataSize<Command>::value;
    static constexpr bool kHasCommandHeader = DispatchHasCommandHeader<Command>::value;
};

// --- Payload structs (argument order preserved) ---
//
// Each of the Info structures match the type and order of an ApiDecoder dispatch call.
// std::apply is used to pass references to the Info contents to the kDecoderMethod defined
// in the DispatchTraits object defined for the each of the Info structs.
struct FunctionCallArgs
{
    format::ApiCallId call_id;
    ApiCallInfo       call_info;
    const uint8_t*    data;
    size_t            data_size;

    auto GetTuple() const { return std::tie(call_id, call_info, data, data_size); }
};
template <>
struct DispatchHasAllocGuard<FunctionCallArgs> : std::true_type
{};

struct MethodCallArgs
{
    format::ApiCallId call_id;
    format::HandleId  object_id;
    ApiCallInfo       call_info;
    const uint8_t*    data;
    size_t            data_size;

    auto GetTuple() const { return std::tie(call_id, object_id, call_info, data, data_size); }
};
template <>
struct DispatchHasAllocGuard<MethodCallArgs> : std::true_type
{};

struct StateBeginMarkerArgs
{
    uint64_t frame_number;

    auto GetTuple() const { return std::tie(frame_number); }
};
struct StateEndMarkerArgs
{
    uint64_t frame_number;

    auto GetTuple() const { return std::tie(frame_number); }
};
struct FrameEndMarkerArgs
{
    uint64_t frame_number;

    auto GetTuple() const { return std::tie(frame_number); }
};
struct DisplayMessageArgs
{
    format::MetaDataId meta_data_id; // Needed by DispatchVisitor, but not ApiDecoder

    format::ThreadId thread_id;
    std::string      message;

    auto GetTuple() const { return std::tie(thread_id, message); }
};
struct DriverArgs
{
    format::MetaDataId meta_data_id; // Needed by DispatchVisitor, but not ApiDecoder

    format::ThreadId        thread_id;
    format::DriverInfoBlock info;

    auto GetTuple() const { return std::tie(thread_id, info); }
};
struct ExeFileArgs
{
    format::MetaDataId meta_data_id; // Needed by DispatchVisitor, but not ApiDecoder

    format::ThreadId         thread_id;
    format::ExeFileInfoBlock info;

    auto GetTuple() const { return std::tie(thread_id, info); }
};
struct FillMemoryArgs
{
    format::MetaDataId meta_data_id; // Needed by DispatchVisitor, but not ApiDecoder

    format::ThreadId thread_id;
    uint64_t         memory_id;
    uint64_t         offset;
    uint64_t         data_size;
    const uint8_t*   data;

    auto GetTuple() const { return std::tie(thread_id, memory_id, offset, data_size, data); }
};
struct FillMemoryResourceValueArgs
{
    format::MetaDataId meta_data_id; // Needed by DispatchVisitor, but not ApiDecoder
    size_t             data_size;    // Needed for deferred decompression, but not ApiDecoder

    format::FillMemoryResourceValueCommandHeader command_header;
    const uint8_t*                               data;

    auto GetTuple() const { return std::tie(command_header, data); }
};
struct ResizeWindowArgs
{
    format::MetaDataId meta_data_id; // Needed by DispatchVisitor, but not ApiDecoder

    format::ThreadId thread_id;
    format::HandleId surface_id;
    uint32_t         width;
    uint32_t         height;

    auto GetTuple() const { return std::tie(thread_id, surface_id, width, height); }
};
struct ResizeWindow2Args
{
    format::MetaDataId meta_data_id; // Needed by DispatchVisitor, but not ApiDecoder

    format::ThreadId thread_id;
    format::HandleId surface_id;
    uint32_t         width;
    uint32_t         height;
    uint32_t         pre_transform;

    auto GetTuple() const { return std::tie(thread_id, surface_id, width, height, pre_transform); }
};
struct CreateHardwareBufferArgs
{
    format::MetaDataId meta_data_id; // Needed by DispatchVisitor, but not ApiDecoder

    format::ThreadId                             thread_id;
    format::HandleId                             device_id;
    format::HandleId                             memory_id;
    uint64_t                                     buffer_id;
    uint32_t                                     format;
    uint32_t                                     width;
    uint32_t                                     height;
    uint32_t                                     stride;
    uint64_t                                     usage;
    uint32_t                                     layers;
    std::vector<format::HardwareBufferPlaneInfo> plane_info;

    auto GetTuple() const
    {
        return std::tie(
            thread_id, device_id, memory_id, buffer_id, format, width, height, stride, usage, layers, plane_info);
    }
};
struct DestroyHardwareBufferArgs
{
    format::MetaDataId meta_data_id; // Needed by DispatchVisitor, but not ApiDecoder

    format::ThreadId thread_id;
    uint64_t         buffer_id;

    auto GetTuple() const { return std::tie(thread_id, buffer_id); }
};
struct CreateHeapAllocationArgs
{
    format::MetaDataId meta_data_id; // Needed by DispatchVisitor, but not ApiDecoder

    format::ThreadId thread_id;
    uint64_t         allocation_id;
    uint64_t         allocation_size;

    auto GetTuple() const { return std::tie(thread_id, allocation_id, allocation_size); }
};
struct SetDevicePropertiesArgs
{
    format::MetaDataId meta_data_id; // Needed by DispatchVisitor, but not ApiDecoder

    format::ThreadId thread_id;
    format::HandleId physical_device_id;
    uint32_t         api_version;
    uint32_t         driver_version;
    uint32_t         vendor_id;
    uint32_t         device_id;
    uint32_t         device_type;
    uint8_t          pipeline_cache_uuid[format::kUuidSize];
    std::string      device_name;

    auto GetTuple() const
    {
        return std::tie(thread_id,
                        physical_device_id,
                        api_version,
                        driver_version,
                        vendor_id,
                        device_id,
                        device_type,
                        pipeline_cache_uuid,
                        device_name);
    }

    // This Info struct requires a constructor because it contains, is passed, and later provides
    // a C array (pipeline_cache_uuid). When passed, the array decays to a uint8_t *, causing aggregate
    // initialization to fail.  The constructor accepts the C array by const reference and
    // performs a memory copy of the contents.
    SetDevicePropertiesArgs(format::MetaDataId                        meta_data_id_,
                            const format::SetDevicePropertiesCommand& header,
                            const std::string&                        device_name_) :
        meta_data_id(meta_data_id_),
        thread_id(header.thread_id), physical_device_id(header.physical_device_id), api_version(header.api_version),
        driver_version(header.driver_version), vendor_id(header.vendor_id), device_id(header.device_id),
        device_type(header.device_type), device_name(device_name_)
    {
        // Need to copy the c-style array contents
        util::platform::MemoryCopy(
            pipeline_cache_uuid, format::kUuidSize, header.pipeline_cache_uuid, format::kUuidSize);
    }
};
struct SetDeviceMemoryPropertiesArgs
{
    format::MetaDataId meta_data_id; // Needed by DispatchVisitor, but not ApiDecoder

    format::ThreadId                      thread_id;
    format::HandleId                      physical_device_id;
    std::vector<format::DeviceMemoryType> memory_types;
    std::vector<format::DeviceMemoryHeap> memory_heaps;

    auto GetTuple() const { return std::tie(thread_id, physical_device_id, memory_types, memory_heaps); }
};
struct SetOpaqueAddressArgs
{
    format::MetaDataId meta_data_id; // Needed by DispatchVisitor, but not ApiDecoder

    format::ThreadId thread_id;
    format::HandleId device_id;
    format::HandleId object_id;
    uint64_t         address;

    auto GetTuple() const { return std::tie(thread_id, device_id, object_id, address); }
};
struct SetRayTracingShaderGroupHandlesArgs
{
    format::MetaDataId meta_data_id; // Needed by DispatchVisitor, but not ApiDecoder

    format::ThreadId thread_id;
    format::HandleId device_id;
    format::HandleId buffer_id;
    size_t           data_size;
    const uint8_t*   data;

    auto GetTuple() const { return std::tie(thread_id, device_id, buffer_id, data_size, data); }
};
struct SetSwapchainImageStateArgs
{
    format::MetaDataId meta_data_id; // Needed by DispatchVisitor, but not ApiDecoder

    format::ThreadId                             thread_id;
    format::HandleId                             device_id;
    format::HandleId                             swapchain_id;
    uint32_t                                     last_presented_image;
    std::vector<format::SwapchainImageStateInfo> image_state;

    auto GetTuple() const { return std::tie(thread_id, device_id, swapchain_id, last_presented_image, image_state); }
};
struct BeginResourceInitArgs
{
    format::MetaDataId meta_data_id; // Needed by DispatchVisitor, but not ApiDecoder

    format::ThreadId thread_id;
    format::HandleId device_id;
    uint64_t         max_resource_size;
    uint64_t         max_copy_size;

    auto GetTuple() const { return std::tie(thread_id, device_id, max_resource_size, max_copy_size); }
};
struct EndResourceInitArgs
{
    format::MetaDataId meta_data_id; // Needed by DispatchVisitor, but not ApiDecoder

    format::ThreadId thread_id;
    format::HandleId device_id;

    auto GetTuple() const { return std::tie(thread_id, device_id); }
};
struct InitBufferArgs
{
    format::MetaDataId meta_data_id; // Needed by DispatchVisitor, but not ApiDecoder

    format::ThreadId thread_id;
    format::HandleId device_id;
    format::HandleId buffer_id;
    uint64_t         data_size;
    const uint8_t*   data;

    auto GetTuple() const { return std::tie(thread_id, device_id, buffer_id, data_size, data); }
};
struct InitImageArgs
{
    format::MetaDataId meta_data_id; // Needed by DispatchVisitor, but not ApiDecoder

    format::ThreadId      thread_id;
    format::HandleId      device_id;
    format::HandleId      image_id;
    uint64_t              data_size;
    uint32_t              aspect;
    uint32_t              layout;
    std::vector<uint64_t> level_sizes;
    const uint8_t*        data;

    auto GetTuple() const
    {
        return std::tie(thread_id, device_id, image_id, data_size, aspect, layout, level_sizes, data);
    }
};
struct InitSubresourceArgs
{
    format::MetaDataId meta_data_id; // Needed by DispatchVisitor, but not ApiDecoder

    format::InitSubresourceCommandHeader command_header;
    const uint8_t*                       data;

    auto GetTuple() const { return std::tie(command_header, data); }
};
struct InitDx12AccelerationStructureArgs
{
    format::MetaDataId meta_data_id; // Needed by DispatchVisitor, but not ApiDecoder
    // Note: the command header has uniquely named size field... so duplicate this info for visitor use
    size_t data_size; // Needed for deferred decompression, but not ApiDecoder

    format::InitDx12AccelerationStructureCommandHeader             command_header;
    std::vector<format::InitDx12AccelerationStructureGeometryDesc> geometry_descs;
    const uint8_t*                                                 data;

    auto GetTuple() const { return std::tie(command_header, geometry_descs, data); }
};
struct GetDxgiAdapterArgs
{
    format::MetaDataId meta_data_id; // Needed by DispatchVisitor, but not ApiDecoder

    format::DxgiAdapterInfoCommandHeader adapter_info_header;

    auto GetTuple() const { return std::tie(adapter_info_header); }
};
struct GetDx12RuntimeArgs
{
    format::MetaDataId meta_data_id; // Needed by DispatchVisitor, but not ApiDecoder

    format::Dx12RuntimeInfoCommandHeader runtime_info_header;

    auto GetTuple() const { return std::tie(runtime_info_header); }
};
struct ExecuteBlocksFromFileArgs
{
    format::MetaDataId meta_data_id; // Needed by DispatchVisitor, but not ApiDecoder

    format::ThreadId thread_id;
    uint32_t         n_blocks;
    int64_t          offset;
    std::string      filename;

    auto GetTuple() const { return std::tie(thread_id, n_blocks, offset, filename); }
};
struct SetTlasToBlasDependencyArgs
{
    format::MetaDataId meta_data_id; // Needed by DispatchVisitor, but not ApiDecoder

    format::HandleId              tlas;
    std::vector<format::HandleId> blases;

    auto GetTuple() const { return std::tie(tlas, blases); }
};
struct SetEnvironmentVariablesArgs
{
    format::MetaDataId meta_data_id; // Needed by DispatchVisitor, but not ApiDecoder

    format::SetEnvironmentVariablesCommand header;
    const char*                            env_string;

    auto GetTuple() const { return std::tie(header, env_string); }
};
struct VulkanAccelerationStructuresBuildMetaArgs
{
    format::MetaDataId meta_data_id; // Needed by DispatchVisitor, but not ApiDecoder

    const uint8_t* parameter_buffer;
    size_t         buffer_size;

    auto GetTuple() const { return std::tie(parameter_buffer, buffer_size); }
};
template <>
struct DispatchHasAllocGuard<VulkanAccelerationStructuresBuildMetaArgs> : std::true_type
{};

struct VulkanAccelerationStructuresCopyMetaArgs
{
    format::MetaDataId meta_data_id; // Needed by DispatchVisitor, but not ApiDecoder

    const uint8_t* parameter_buffer;
    size_t         buffer_size;

    auto GetTuple() const { return std::tie(parameter_buffer, buffer_size); }
};
template <>
struct DispatchHasAllocGuard<VulkanAccelerationStructuresCopyMetaArgs> : std::true_type
{};

struct VulkanAccelerationStructuresWritePropertiesMetaArgs
{
    format::MetaDataId meta_data_id; // Needed by DispatchVisitor, but not ApiDecoder

    const uint8_t* parameter_buffer;
    size_t         buffer_size;

    auto GetTuple() const { return std::tie(parameter_buffer, buffer_size); }
};
template <>
struct DispatchHasAllocGuard<VulkanAccelerationStructuresWritePropertiesMetaArgs> : std::true_type
{};

struct ViewRelativeLocationArgs
{
    format::MetaDataId meta_data_id; // Needed by DispatchVisitor, but not ApiDecoder

    format::ThreadId             thread_id;
    format::ViewRelativeLocation location;

    auto GetTuple() const { return std::tie(thread_id, location); }
};
struct InitializeMetaArgs
{
    format::MetaDataId meta_data_id; // Needed by DispatchVisitor, but not ApiDecoder

    format::InitializeMetaCommand command_header;
    const uint8_t*                data;

    auto GetTuple() const { return std::tie(command_header, data); }
};
struct AnnotationArgs
{
    uint64_t               block_index;
    format::AnnotationType type;
    std::string            label;

    // NOTE: The string name is intentionally *not* data to differ from the "data" fields that are uint8_t *
    // parameter data for the next level Decode operations, simplifying DispatchHasData logic
    std::string annotation_data;

    auto GetTuple() const { return std::tie(block_index, type, label, annotation_data); }
};
struct SetOpaqueDescriptorDataArgs
{
    format::MetaDataId meta_data_id; // Needed by DispatchVisitor, but not ApiDecoder

    format::ThreadId thread_id;
    format::HandleId device_id;
    format::HandleId object_id;
    uint32_t         size;
    const uint8_t*   data;

    auto GetTuple() const { return std::tie(thread_id, device_id, object_id, size, data); }
};

// --- DispatchTraits specializations  ---
template <typename T>
struct DispatchTraits;

// ---- DispatchTraits specializations (inherit common flags) ----
template <>
struct DispatchTraits<FunctionCallArgs> : DispatchFlagTraits<FunctionCallArgs>
{
    static constexpr auto kDecoderMethod = &ApiDecoder::DecodeFunctionCall;
};

template <>
struct DispatchTraits<MethodCallArgs> : DispatchFlagTraits<MethodCallArgs>
{
    static constexpr auto kDecoderMethod = &ApiDecoder::DecodeMethodCall;
};

template <>
struct DispatchTraits<StateBeginMarkerArgs> : DispatchFlagTraits<StateBeginMarkerArgs>
{
    static constexpr auto kDecoderMethod = &ApiDecoder::DispatchStateBeginMarker;
};

template <>
struct DispatchTraits<StateEndMarkerArgs> : DispatchFlagTraits<StateEndMarkerArgs>
{
    static constexpr auto kDecoderMethod = &ApiDecoder::DispatchStateEndMarker;
};

template <>
struct DispatchTraits<FrameEndMarkerArgs> : DispatchFlagTraits<FrameEndMarkerArgs>
{
    static constexpr auto kDecoderMethod = &ApiDecoder::DispatchFrameEndMarker;
};

template <>
struct DispatchTraits<DisplayMessageArgs> : DispatchFlagTraits<DisplayMessageArgs>
{
    static constexpr auto kDecoderMethod = &ApiDecoder::DispatchDisplayMessageCommand;
};

template <>
struct DispatchTraits<DriverArgs> : DispatchFlagTraits<DriverArgs>
{
    static constexpr auto kDecoderMethod = &ApiDecoder::DispatchDriverInfo;
};

template <>
struct DispatchTraits<ExeFileArgs> : DispatchFlagTraits<ExeFileArgs>
{
    static constexpr auto kDecoderMethod = &ApiDecoder::DispatchExeFileInfo;
};

template <>
struct DispatchTraits<FillMemoryArgs> : DispatchFlagTraits<FillMemoryArgs>
{
    static constexpr auto kDecoderMethod = &ApiDecoder::DispatchFillMemoryCommand;
};

template <>
struct DispatchTraits<FillMemoryResourceValueArgs> : DispatchFlagTraits<FillMemoryResourceValueArgs>
{
    static constexpr auto kDecoderMethod = &ApiDecoder::DispatchFillMemoryResourceValueCommand;
};

template <>
struct DispatchTraits<ResizeWindowArgs> : DispatchFlagTraits<ResizeWindowArgs>
{
    static constexpr auto kDecoderMethod = &ApiDecoder::DispatchResizeWindowCommand;
};

template <>
struct DispatchTraits<ResizeWindow2Args> : DispatchFlagTraits<ResizeWindow2Args>
{
    static constexpr auto kDecoderMethod = &ApiDecoder::DispatchResizeWindowCommand2;
};

template <>
struct DispatchTraits<CreateHardwareBufferArgs> : DispatchFlagTraits<CreateHardwareBufferArgs>
{
    static constexpr auto kDecoderMethod = &ApiDecoder::DispatchCreateHardwareBufferCommand;
};

template <>
struct DispatchTraits<DestroyHardwareBufferArgs> : DispatchFlagTraits<DestroyHardwareBufferArgs>
{
    static constexpr auto kDecoderMethod = &ApiDecoder::DispatchDestroyHardwareBufferCommand;
};

template <>
struct DispatchTraits<CreateHeapAllocationArgs> : DispatchFlagTraits<CreateHeapAllocationArgs>
{
    static constexpr auto kDecoderMethod = &ApiDecoder::DispatchCreateHeapAllocationCommand;
};

template <>
struct DispatchTraits<SetDevicePropertiesArgs> : DispatchFlagTraits<SetDevicePropertiesArgs>
{
    static constexpr auto kDecoderMethod = &ApiDecoder::DispatchSetDevicePropertiesCommand;
};

template <>
struct DispatchTraits<SetDeviceMemoryPropertiesArgs> : DispatchFlagTraits<SetDeviceMemoryPropertiesArgs>
{
    static constexpr auto kDecoderMethod = &ApiDecoder::DispatchSetDeviceMemoryPropertiesCommand;
};

template <>
struct DispatchTraits<SetOpaqueAddressArgs> : DispatchFlagTraits<SetOpaqueAddressArgs>
{
    static constexpr auto kDecoderMethod = &ApiDecoder::DispatchSetOpaqueAddressCommand;
};

template <>
struct DispatchTraits<SetRayTracingShaderGroupHandlesArgs> : DispatchFlagTraits<SetRayTracingShaderGroupHandlesArgs>
{
    static constexpr auto kDecoderMethod = &ApiDecoder::DispatchSetRayTracingShaderGroupHandlesCommand;
};

template <>
struct DispatchTraits<SetSwapchainImageStateArgs> : DispatchFlagTraits<SetSwapchainImageStateArgs>
{
    static constexpr auto kDecoderMethod = &ApiDecoder::DispatchSetSwapchainImageStateCommand;
};

template <>
struct DispatchTraits<BeginResourceInitArgs> : DispatchFlagTraits<BeginResourceInitArgs>
{
    static constexpr auto kDecoderMethod = &ApiDecoder::DispatchBeginResourceInitCommand;
};

template <>
struct DispatchTraits<EndResourceInitArgs> : DispatchFlagTraits<EndResourceInitArgs>
{
    static constexpr auto kDecoderMethod = &ApiDecoder::DispatchEndResourceInitCommand;
};

template <>
struct DispatchTraits<InitBufferArgs> : DispatchFlagTraits<InitBufferArgs>
{
    static constexpr auto kDecoderMethod = &ApiDecoder::DispatchInitBufferCommand;
};

template <>
struct DispatchTraits<InitImageArgs> : DispatchFlagTraits<InitImageArgs>
{
    static constexpr auto kDecoderMethod = &ApiDecoder::DispatchInitImageCommand;
};

template <>
struct DispatchTraits<InitSubresourceArgs> : DispatchFlagTraits<InitSubresourceArgs>
{
    static constexpr auto kDecoderMethod = &ApiDecoder::DispatchInitSubresourceCommand;
};

template <>
struct DispatchTraits<InitDx12AccelerationStructureArgs> : DispatchFlagTraits<InitDx12AccelerationStructureArgs>
{
    static constexpr auto kDecoderMethod = &ApiDecoder::DispatchInitDx12AccelerationStructureCommand;
};

template <>
struct DispatchTraits<GetDxgiAdapterArgs> : DispatchFlagTraits<GetDxgiAdapterArgs>
{
    static constexpr auto kDecoderMethod = &ApiDecoder::DispatchGetDxgiAdapterInfo;
};

template <>
struct DispatchTraits<GetDx12RuntimeArgs> : DispatchFlagTraits<GetDx12RuntimeArgs>
{
    static constexpr auto kDecoderMethod = &ApiDecoder::DispatchGetDx12RuntimeInfo;
};

template <>
struct DispatchTraits<ExecuteBlocksFromFileArgs> : DispatchFlagTraits<ExecuteBlocksFromFileArgs>
{
    static constexpr auto kDecoderMethod = &ApiDecoder::DispatchExecuteBlocksFromFile;
};

template <>
struct DispatchTraits<SetTlasToBlasDependencyArgs> : DispatchFlagTraits<SetTlasToBlasDependencyArgs>
{
    static constexpr auto kDecoderMethod = &ApiDecoder::DispatchSetTlasToBlasDependencyCommand;
};

template <>
struct DispatchTraits<SetEnvironmentVariablesArgs> : DispatchFlagTraits<SetEnvironmentVariablesArgs>
{
    static constexpr auto kDecoderMethod = &ApiDecoder::DispatchSetEnvironmentVariablesCommand;
};

template <>
struct DispatchTraits<VulkanAccelerationStructuresBuildMetaArgs>
    : DispatchFlagTraits<VulkanAccelerationStructuresBuildMetaArgs>
{
    static constexpr auto kDecoderMethod = &ApiDecoder::DispatchVulkanAccelerationStructuresBuildMetaCommand;
};

template <>
struct DispatchTraits<VulkanAccelerationStructuresCopyMetaArgs>
    : DispatchFlagTraits<VulkanAccelerationStructuresCopyMetaArgs>
{
    static constexpr auto kDecoderMethod = &ApiDecoder::DispatchVulkanAccelerationStructuresCopyMetaCommand;
};

template <>
struct DispatchTraits<VulkanAccelerationStructuresWritePropertiesMetaArgs>
    : DispatchFlagTraits<VulkanAccelerationStructuresWritePropertiesMetaArgs>
{
    static constexpr auto kDecoderMethod = &ApiDecoder::DispatchVulkanAccelerationStructuresWritePropertiesMetaCommand;
};

template <>
struct DispatchTraits<ViewRelativeLocationArgs> : DispatchFlagTraits<ViewRelativeLocationArgs>
{
    static constexpr auto kDecoderMethod = &ApiDecoder::DispatchViewRelativeLocation;
};

template <>
struct DispatchTraits<InitializeMetaArgs> : DispatchFlagTraits<InitializeMetaArgs>
{
    static constexpr auto kDecoderMethod = &ApiDecoder::DispatchInitializeMetaCommand;
};

template <>
struct DispatchTraits<SetOpaqueDescriptorDataArgs> : DispatchFlagTraits<SetOpaqueDescriptorDataArgs>
{
    static constexpr auto kDecoderMethod = &ApiDecoder::DispatchSetOpaqueDescriptorDataCommand;
};

template <>
struct DispatchTraits<AnnotationArgs> : DispatchFlagTraits<AnnotationArgs>
{
    // Is not dispatched to decoders, and thus requires a custom DispatchVisitor::VisitCommand overload
};

// --- Variant of all payloads by reference, storage in allocator
using DispatchArgs = std::variant<std::monostate,
                                  FunctionCallArgs*,
                                  MethodCallArgs*,
                                  StateBeginMarkerArgs*,
                                  StateEndMarkerArgs*,
                                  FrameEndMarkerArgs*,
                                  DisplayMessageArgs*,
                                  DriverArgs*,
                                  ExeFileArgs*,
                                  FillMemoryArgs*,
                                  FillMemoryResourceValueArgs*,
                                  ResizeWindowArgs*,
                                  ResizeWindow2Args*,
                                  CreateHardwareBufferArgs*,
                                  DestroyHardwareBufferArgs*,
                                  CreateHeapAllocationArgs*,
                                  SetDevicePropertiesArgs*,
                                  SetDeviceMemoryPropertiesArgs*,
                                  SetOpaqueAddressArgs*,
                                  SetRayTracingShaderGroupHandlesArgs*,
                                  SetSwapchainImageStateArgs*,
                                  BeginResourceInitArgs*,
                                  EndResourceInitArgs*,
                                  InitBufferArgs*,
                                  InitImageArgs*,
                                  InitSubresourceArgs*,
                                  InitDx12AccelerationStructureArgs*,
                                  GetDxgiAdapterArgs*,
                                  GetDx12RuntimeArgs*,
                                  ExecuteBlocksFromFileArgs*,
                                  SetTlasToBlasDependencyArgs*,
                                  SetEnvironmentVariablesArgs*,
                                  VulkanAccelerationStructuresBuildMetaArgs*,
                                  VulkanAccelerationStructuresCopyMetaArgs*,
                                  VulkanAccelerationStructuresWritePropertiesMetaArgs*,
                                  ViewRelativeLocationArgs*,
                                  InitializeMetaArgs*,
                                  AnnotationArgs*,
                                  SetOpaqueDescriptorDataArgs*>;

template <typename Args>
inline size_t GetDispatchArgsDataSize(Args& args)
{
    if constexpr (DispatchTraits<Args>::kHasDataSize)
    {
        return args.data_size;
    }
    else if constexpr (DispatchTraits<Args>::kHasCommandHeader)
    {
        return args.command_header.data_size;
    }
    return 0;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GXFRECON_API_PAYLOAD_H
