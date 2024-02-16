/*
** Copyright (c) 2021-2023 LunarG, Inc.
** Copyright (c) 2021-2023 Advanced Micro Devices, Inc. All rights reserved.
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

#include "decode/dx12_replay_consumer_base.h"

#include "decode/dx12_enum_util.h"
#include "decode/custom_dx12_struct_object_mappers.h"
#include "generated/generated_dx12_call_id_to_string.h"
#include "graphics/dx12_util.h"
#include "graphics/dx12_image_renderer.h"
#include "util/gpu_va_range.h"
#include "util/platform.h"
#include "util/file_path.h"
#include "util/image_writer.h"
#include "util/to_string.h"

#include <dxgidebug.h>

#include <cassert>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

constexpr int32_t  kDefaultWindowPositionX = 0;
constexpr int32_t  kDefaultWindowPositionY = 0;
constexpr uint32_t kDefaultWaitTimeout     = INFINITE;

constexpr uint64_t kInternalEventId = static_cast<uint64_t>(~0);

constexpr bool TEST_SHADER_RES = true;

template <typename T, typename U>
void SetExtraInfo(HandlePointerDecoder<T>* decoder, std::unique_ptr<U>&& extra_info)
{
    auto object_info = static_cast<DxObjectInfo*>(decoder->GetConsumerData(0));
    assert(object_info != nullptr);

    object_info->extra_info = std::move(extra_info);
}

Dx12ReplayConsumerBase::Dx12ReplayConsumerBase(std::shared_ptr<application::Application> application,
                                               const DxReplayOptions&                    options) :
    application_(application),
    options_(options), current_message_length_(0), info_queue_(nullptr), resource_data_util_(nullptr),
    frame_buffer_renderer_(nullptr), debug_layer_enabled_(false), set_auto_breadcrumbs_enablement_(false),
    set_breadcrumb_context_enablement_(false), set_page_fault_enablement_(false), loading_trim_state_(false),
    fps_info_(nullptr)
{
    if (options_.enable_validation_layer)
    {
        gfxrecon::graphics::dx12::ID3D12DebugComPtr dx12_debug = nullptr;
        if (SUCCEEDED(D3D12GetDebugInterface(IID_PPV_ARGS(&dx12_debug))))
        {
            EnableDebugLayer(dx12_debug);
        }
        else
        {
            GFXRECON_LOG_WARNING("Failed to enable D3D12 debug layer for replay option '--validate'.");
            options_.enable_validation_layer = false;
        }
    }

    if (options_.enable_debug_device_lost)
    {
        gfxrecon::graphics::dx12::ID3D12DeviceRemovedExtendedDataSettings1ComPtr dred_settings = nullptr;

        if (SUCCEEDED(D3D12GetDebugInterface(IID_PPV_ARGS(&dred_settings))))
        {
            SetAutoBreadcrumbsEnablement(dred_settings, D3D12_DRED_ENABLEMENT_FORCED_ON);
            SetBreadcrumbContextEnablement(dred_settings, D3D12_DRED_ENABLEMENT_FORCED_ON);
            SetPageFaultEnablement(dred_settings, D3D12_DRED_ENABLEMENT_FORCED_ON);
        }
        else
        {
            GFXRECON_LOG_WARNING(
                "Failed to enable ID3D12DeviceRemovedExtendedDataSettings1 for replay option '--debug-device-lost'.");
            options_.enable_debug_device_lost = false;
        }
    }

    if (!options.screenshot_ranges.empty())
    {
        InitializeScreenshotHandler();
    }

    DetectAdapters();

    auto get_object_func = std::bind(&Dx12ReplayConsumerBase::GetObjectInfo, this, std::placeholders::_1);
    resource_value_mapper_ =
        std::make_unique<Dx12ResourceValueMapper>(get_object_func, shader_id_map_, gpu_va_map_, descriptor_map_);
}

void Dx12ReplayConsumerBase::EnableDebugLayer(ID3D12Debug* dx12_debug)
{
    if (!debug_layer_enabled_)
    {
        debug_layer_enabled_ = true;
        dx12_debug->EnableDebugLayer();
        if (FAILED(DXGIGetDebugInterface1(0, IID_PPV_ARGS(&info_queue_))))
        {
            GFXRECON_LOG_WARNING(
                "Failed to retrieve IDXGIInfoQueue for replay option '--validate' or trimming EnableDebugLayer.");
        }
        else
        {
            SetDebugMsgFilter(options_.DeniedDebugMessages, options_.AllowedDebugMessages);
        }
    }
}

void Dx12ReplayConsumerBase::OverrideSetAutoBreadcrumbsEnablement(DxObjectInfo*         replay_object_info,
                                                                  D3D12_DRED_ENABLEMENT enablement)
{
    auto replay_object = static_cast<ID3D12DeviceRemovedExtendedDataSettings1*>(replay_object_info->object);
    SetAutoBreadcrumbsEnablement(replay_object, enablement);
}

void Dx12ReplayConsumerBase::SetAutoBreadcrumbsEnablement(ID3D12DeviceRemovedExtendedDataSettings1* dred_settings,
                                                          D3D12_DRED_ENABLEMENT                     enablement)
{
    if (!set_auto_breadcrumbs_enablement_)
    {
        set_auto_breadcrumbs_enablement_ = true;
        dred_settings->SetAutoBreadcrumbsEnablement(enablement);
    }
}

void Dx12ReplayConsumerBase::OverrideSetBreadcrumbContextEnablement(DxObjectInfo*         replay_object_info,
                                                                    D3D12_DRED_ENABLEMENT enablement)
{
    auto replay_object = static_cast<ID3D12DeviceRemovedExtendedDataSettings1*>(replay_object_info->object);
    SetBreadcrumbContextEnablement(replay_object, enablement);
}

void Dx12ReplayConsumerBase::SetBreadcrumbContextEnablement(ID3D12DeviceRemovedExtendedDataSettings1* dred_settings,
                                                            D3D12_DRED_ENABLEMENT                     enablement)
{
    if (!set_breadcrumb_context_enablement_)
    {
        set_breadcrumb_context_enablement_ = true;
        dred_settings->SetBreadcrumbContextEnablement(enablement);
    }
}

void Dx12ReplayConsumerBase::OverrideSetPageFaultEnablement(DxObjectInfo*         replay_object_info,
                                                            D3D12_DRED_ENABLEMENT enablement)
{
    auto replay_object = static_cast<ID3D12DeviceRemovedExtendedDataSettings1*>(replay_object_info->object);
    SetPageFaultEnablement(replay_object, enablement);
}

void Dx12ReplayConsumerBase::SetPageFaultEnablement(ID3D12DeviceRemovedExtendedDataSettings1* dred_settings,
                                                    D3D12_DRED_ENABLEMENT                     enablement)
{
    if (!set_page_fault_enablement_)
    {
        set_page_fault_enablement_ = true;
        dred_settings->SetPageFaultEnablement(enablement);
    }
}

void Dx12ReplayConsumerBase::OverrideEnableDebugLayer(DxObjectInfo* replay_object_info)
{
    auto replay_object = static_cast<ID3D12Debug*>(replay_object_info->object);
    EnableDebugLayer(replay_object);
}

Dx12ReplayConsumerBase::~Dx12ReplayConsumerBase()
{
    // Wait for pending work to complete before destroying resources.
    const DWORD kWaitMilliseconds = 2000;
    if (WaitIdle(kWaitMilliseconds))
    {
        DestroyActiveObjects();
        DestroyActiveWindows();
        DestroyActiveEvents();
        DestroyHeapAllocations();
        if (info_queue_ != nullptr)
        {
            info_queue_->Release();
        }
    }
    else
    {
        GFXRECON_LOG_WARNING(
            "Failed to wait for all command queues to idle before exiting, so GFXReconstruct cannot manually release "
            "DX12 resources prior to exit. This could be caused by a command queue waiting for the signal of a fence "
            "value that was either not captured or not replayed before exit.");
    }
}

void Dx12ReplayConsumerBase::ProcessStateBeginMarker(uint64_t frame_number)
{
    GFXRECON_UNREFERENCED_PARAMETER(frame_number);
    loading_trim_state_ = true;
}

void Dx12ReplayConsumerBase::ProcessStateEndMarker(uint64_t frame_number)
{
    GFXRECON_UNREFERENCED_PARAMETER(frame_number);
    loading_trim_state_ = false;
    if (fps_info_ != nullptr)
    {
        fps_info_->ProcessStateEndMarker(frame_number);
    }

    // The accel_struct_builder_ is no longer needed after the trim state load is complete.
    accel_struct_builder_ = nullptr;
}

void Dx12ReplayConsumerBase::ProcessFillMemoryCommand(uint64_t       memory_id,
                                                      uint64_t       offset,
                                                      uint64_t       size,
                                                      const uint8_t* data)
{
    auto entry = mapped_memory_.find(memory_id);

    if (entry != mapped_memory_.end())
    {
        GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, size);

        auto copy_size      = static_cast<size_t>(size);
        auto mapped_pointer = static_cast<uint8_t*>(entry->second.data_pointer) + offset;

        util::platform::MemoryCopy(mapped_pointer, copy_size, data, copy_size);

        ApplyFillMemoryResourceValueCommand(offset, size, data, static_cast<uint8_t*>(entry->second.data_pointer));

        if (resource_value_mapper_ != nullptr)
        {
            resource_value_mapper_->PostProcessFillMemoryCommand(entry->second.resource_id, offset, size, data);
        }
    }
    else
    {
        GFXRECON_LOG_WARNING("Skipping memory fill for unrecognized mapped memory object (ID = %" PRIu64 ")",
                             memory_id);
    }
}

void Dx12ReplayConsumerBase::ProcessFillMemoryResourceValueCommand(
    const format::FillMemoryResourceValueCommandHeader& command_header, const uint8_t* data)
{
    // FillMemoryResourceValueCommands should always be followed by a FillMemoryCommand, and the FillMemoryCommand
    // should use and clear fill_memory_resource_value_info_.
    GFXRECON_ASSERT(fill_memory_resource_value_info_.expected_block_index == 0);

    // The next block should be the FillMemoryCommand the resource data is associated with.
    fill_memory_resource_value_info_.expected_block_index = GetCurrentBlockIndex() + 1;

    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, command_header.resource_value_count);
    size_t resource_value_count = static_cast<size_t>(command_header.resource_value_count);

    auto types_bytes   = resource_value_count * sizeof(format::ResourceValueType);
    auto offsets_bytes = resource_value_count * sizeof(uint64_t);

    fill_memory_resource_value_info_.types.resize(resource_value_count);
    util::platform::MemoryCopy(fill_memory_resource_value_info_.types.data(),
                               fill_memory_resource_value_info_.types.size() * sizeof(format::ResourceValueType),
                               data,
                               types_bytes);

    fill_memory_resource_value_info_.offsets.resize(resource_value_count);
    util::platform::MemoryCopy(fill_memory_resource_value_info_.offsets.data(),
                               fill_memory_resource_value_info_.offsets.size() * sizeof(uint64_t),
                               data + types_bytes,
                               offsets_bytes);

    // If a FillMemoryResourceValueCommand is encountered, the file has been optimized for DXR and the
    // resource_value_mapper_ is not needed.
    if (resource_value_mapper_ != nullptr)
    {
        resource_value_mapper_ = nullptr;
        if (resource_value_count > 0)
        {
            GFXRECON_LOG_DEBUG("Found data to enable optimized playback of DXR and/or ExecuteIndirect commands.");
        }
        else
        {
            GFXRECON_LOG_DEBUG("This file was processed by the DXR/EI optimizer. It did not contain any DXR/EI "
                               "commands that require additional replay processing.");
        }
    }

    opt_fillmem_ = true;
}

void Dx12ReplayConsumerBase::ProcessCreateHeapAllocationCommand(uint64_t allocation_id, uint64_t allocation_size)
{
    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, allocation_size);

    auto heap_allocation =
        VirtualAlloc(nullptr, static_cast<size_t>(allocation_size), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

    if (heap_allocation != nullptr)
    {
        assert(heap_allocations_.find(allocation_id) == heap_allocations_.end());

        heap_allocations_[allocation_id] = heap_allocation;
    }
    else
    {
        GFXRECON_LOG_FATAL("Failed to create extertnal heap allocation (ID = %" PRIu64 ") of size %" PRIu64,
                           allocation_id,
                           allocation_size);
    }
}

void Dx12ReplayConsumerBase::SetResourceInitInfoState(ResourceInitInfo&                           resource_info,
                                                      const format::InitSubresourceCommandHeader& command_header,
                                                      const uint8_t*                              data)
{
    resource_info.before_states.push_back(
        { static_cast<D3D12_RESOURCE_STATES>(command_header.initial_state), D3D12_RESOURCE_BARRIER_FLAG_NONE });
    resource_info.after_states.push_back({ static_cast<D3D12_RESOURCE_STATES>(command_header.resource_state),
                                           static_cast<D3D12_RESOURCE_BARRIER_FLAGS>(command_header.barrier_flags) });
    resource_info.subresource_offsets.push_back(resource_info.data.size());
    resource_info.subresource_sizes.push_back(command_header.data_size);
    resource_info.data.insert(resource_info.data.end(), data, data + command_header.data_size);
}

void Dx12ReplayConsumerBase::ApplyBatchedResourceInitInfo(
    std::unordered_map<ID3D12Resource*, ResourceInitInfo>& resource_infos)
{
    GFXRECON_ASSERT(resource_data_util_);
    if (resource_infos.size() > 0)
    {
        resource_data_util_->ResetCommandList();
        for (auto resource_info : resource_infos)
        {
            if (resource_info.first != nullptr)
            {
                resource_data_util_->WriteToResource(resource_info.second.resource,
                                                     resource_info.second.try_map_and_copy,
                                                     resource_info.second.before_states,
                                                     resource_info.second.after_states,
                                                     resource_info.second.data,
                                                     resource_info.second.subresource_offsets,
                                                     resource_info.second.subresource_sizes,
                                                     resource_info.second.staging_resource);
            }
            auto object_info = GetObjectInfo(resource_info.second.resource_id);
            if (object_info->extra_info != nullptr)
            {
                auto extra_info                  = GetExtraInfo<D3D12ResourceInfo>(object_info);
                extra_info->resource_state_infos = resource_info.second.after_states;
            }
        }
        resource_data_util_->CloseCommandList();
        resource_data_util_->ExecuteAndWaitForCommandList();
        resource_infos.clear();
    }
}

void Dx12ReplayConsumerBase::ProcessBeginResourceInitCommand(format::HandleId device_id,
                                                             uint64_t         max_resource_size,
                                                             uint64_t         max_copy_size)
{
    GFXRECON_UNREFERENCED_PARAMETER(max_copy_size);
    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, max_resource_size);

    auto device         = MapObject<ID3D12Device>(device_id);
    resource_data_util_ = std::make_unique<graphics::Dx12ResourceDataUtil>(device, max_resource_size);
}

void Dx12ReplayConsumerBase::ProcessEndResourceInitCommand(format::HandleId device_id)
{
    ApplyBatchedResourceInitInfo(resource_init_infos_);
    resource_data_util_ = nullptr;
}

void Dx12ReplayConsumerBase::ProcessInitSubresourceCommand(const format::InitSubresourceCommandHeader& command_header,
                                                           const uint8_t*                              data)
{
    HRESULT result = E_FAIL;

    auto device            = MapObject<ID3D12Device>(command_header.device_id);
    auto device_info       = GetObjectInfo(command_header.device_id);
    auto extra_device_info = GetExtraInfo<D3D12DeviceInfo>(device_info);
    auto resource_info     = GetObjectInfo(command_header.resource_id);
    auto resource          = static_cast<ID3D12Resource*>(resource_info->object);

    GFXRECON_ASSERT(MapObject<ID3D12Resource>(command_header.resource_id) == resource);

    // System has enough memory to batch the next Copy()
    ResourceInitInfo resource_init_info = {};
    resource_init_info.resource_id      = command_header.resource_id;
    resource_init_info.resource         = resource;
    bool is_reserved_resource           = false;
    bool is_texture_with_unknown_layout = false;
    if (resource_info->extra_info != nullptr)
    {
        // Reserved resource has to be uploaded via staging buffer
        auto resource_extra_info       = GetExtraInfo<D3D12ResourceInfo>(resource_info);
        is_reserved_resource           = resource_extra_info->is_reserved_resource;
        is_texture_with_unknown_layout = graphics::dx12::IsTextureWithUnknownLayout(resource_extra_info->desc.Dimension,
                                                                                    resource_extra_info->desc.Layout);
    }

    resource_init_info.try_map_and_copy = !is_reserved_resource && !is_texture_with_unknown_layout;

    auto find_resource_info = resource_init_infos_.find(resource);
    if (find_resource_info == resource_init_infos_.end())
    {
        // If no entry exists in resource_init_infos_, this is the first subresource of a new resource.
        GFXRECON_ASSERT(command_header.subresource == 0);

        // Query staging buffer size info.
        size_t                                          subresource_count;
        uint64_t                                        required_data_size;
        std::vector<uint64_t>                           subresource_offsets;
        std::vector<uint64_t>                           subresource_sizes;
        std::vector<D3D12_PLACED_SUBRESOURCE_FOOTPRINT> temp_subresource_layouts;
        resource_data_util_->GetResourceCopyInfo(resource,
                                                 subresource_count,
                                                 subresource_offsets,
                                                 subresource_sizes,
                                                 temp_subresource_layouts,
                                                 required_data_size);

        const double max_mem_usage = static_cast<double>(options_.memory_usage) / 100.0;
        if (!graphics::dx12::IsMemoryAvailable(
                required_data_size, extra_device_info->adapter3, max_mem_usage, extra_device_info->is_uma))
        {
            // If neither system memory or GPU memory are able to accommodate next resource,
            // execute the Copy() calls and release temp buffer to free memory
            ApplyBatchedResourceInitInfo(resource_init_infos_);
        }

        // Prepare Staging buffer for next resource
        resource_init_info.staging_resource = resource_data_util_->CreateStagingBuffer(
            graphics::Dx12ResourceDataUtil::CopyType::kCopyTypeWrite, required_data_size);
        SetResourceInitInfoState(resource_init_info, command_header, data);

        // Only for buffer resources (which contain 1 subresource), map any resource values contained in the data.
        if (command_header.subresource == 0)
        {
            ApplyFillMemoryResourceValueCommand(
                0, resource_init_info.subresource_sizes[0], data, resource_init_info.data.data());
        }

        resource_init_infos_.insert(std::make_pair(resource, resource_init_info));
    }
    else
    {
        // If the resource already has an entry in resource_init_infos_, add the next subresource data.
        GFXRECON_ASSERT(command_header.subresource != 0);
        SetResourceInitInfoState(find_resource_info->second, command_header, data);
    }

    if ((resource_value_mapper_ != nullptr) && (resource_init_info.resource != nullptr))
    {
        resource_value_mapper_->PostProcessInitSubresourceCommand(resource_init_info.resource, command_header, data);
    }
}

void Dx12ReplayConsumerBase::ProcessInitDx12AccelerationStructureCommand(
    const format::InitDx12AccelerationStructureCommandHeader&       command_header,
    std::vector<format::InitDx12AccelerationStructureGeometryDesc>& geometry_descs,
    const uint8_t*                                                  build_inputs_data)
{
    if (!accel_struct_builder_)
    {
        format::HandleId dest_resource_id = format::kNullHandleId;
        gpu_va_map_.Map(command_header.dest_acceleration_structure_data, &dest_resource_id);
        GFXRECON_ASSERT(dest_resource_id != format::kNullHandleId);

        auto* dest_resource = MapObject<ID3D12Resource>(dest_resource_id);
        GFXRECON_ASSERT(dest_resource);

        auto device5          = graphics::dx12::GetDeviceComPtrFromChild<ID3D12Device5>(dest_resource);
        accel_struct_builder_ = std::make_unique<Dx12AccelerationStructureBuilder>(device5);
    }

    accel_struct_builder_->Build(gpu_va_map_, command_header, geometry_descs, build_inputs_data);

    dxr_workload_ = true;
}

void Dx12ReplayConsumerBase::ProcessSetSwapchainImageStateQueueSubmit(ID3D12CommandQueue* command_queue,
                                                                      DxObjectInfo*       swapchain_info,
                                                                      uint32_t            current_buffer_index)
{
    GFXRECON_ASSERT((current_buffer_index != std::numeric_limits<uint32_t>::max()));

    graphics::dx12::ID3D12DeviceComPtr device = nullptr;
    HRESULT                            ret    = command_queue->GetDevice(IID_PPV_ARGS(&device));
    GFXRECON_ASSERT(SUCCEEDED(ret));

    auto                 swapchain = static_cast<IDXGISwapChain3*>(swapchain_info->object);
    DXGI_SWAP_CHAIN_DESC swap_chain_desc;
    swapchain->GetDesc(&swap_chain_desc);
    auto buffer_count = swap_chain_desc.BufferCount;

    for (uint32_t n = 0; n < buffer_count; ++n)
    {
        // When the index buffer matches the buffer during capture, exit the loop.
        if (n == current_buffer_index)
        {
            break;
        }

        // Validate the assumption that the swapchain buffer index increases by 1 after each swapchain->Present.
        GFXRECON_ASSERT(n == swapchain->GetCurrentBackBufferIndex());

        ret = swapchain->Present(0, 0);
        GFXRECON_ASSERT(SUCCEEDED(ret));

        ret = graphics::dx12::WaitForQueue(command_queue);
        GFXRECON_ASSERT(SUCCEEDED(ret));
    }
    GFXRECON_ASSERT(swapchain->GetCurrentBackBufferIndex() == current_buffer_index);
}

void Dx12ReplayConsumerBase::ProcessSetSwapchainImageStateCommand(
    format::HandleId                                    device_id,
    format::HandleId                                    swapchain_id,
    uint32_t                                            current_buffer_index,
    const std::vector<format::SwapchainImageStateInfo>& image_state)
{
    auto* command_queue  = MapObject<ID3D12CommandQueue>(device_id);
    auto  swapchain_info = GetObjectInfo(swapchain_id);

    if (swapchain_info != nullptr && swapchain_info->object != nullptr && command_queue != nullptr)
    {
        ProcessSetSwapchainImageStateQueueSubmit(command_queue, swapchain_info, current_buffer_index);
    }
    else
    {
        if (command_queue == nullptr)
        {
            GFXRECON_LOG_WARNING("Skipping image acquire for unrecognized ID3D12CommandQueue object (ID = %" PRIu64 ")",
                                 device_id);
        }
        else
        {
            GFXRECON_LOG_WARNING("Skipping image acquire for unrecognized IDXGISwapChain object (ID = %" PRIu64 ")",
                                 swapchain_id);
        }
    }
}

void Dx12ReplayConsumerBase::MapGpuDescriptorHandle(D3D12_GPU_DESCRIPTOR_HANDLE& handle)
{
    object_mapping::MapGpuDescriptorHandle(handle, descriptor_map_);
}

void Dx12ReplayConsumerBase::MapGpuDescriptorHandle(uint8_t* dst_handle_ptr, const uint8_t* src_handle_ptr)
{
    D3D12_GPU_DESCRIPTOR_HANDLE handle;
    util::platform::MemoryCopy(&handle.ptr,
                               sizeof(D3D12_GPU_DESCRIPTOR_HANDLE::ptr),
                               src_handle_ptr,
                               sizeof(D3D12_GPU_DESCRIPTOR_HANDLE::ptr));
    MapGpuDescriptorHandle(handle);
    util::platform::MemoryCopy(dst_handle_ptr,
                               sizeof(D3D12_GPU_DESCRIPTOR_HANDLE::ptr),
                               &handle.ptr,
                               sizeof(D3D12_GPU_DESCRIPTOR_HANDLE::ptr));
}

void Dx12ReplayConsumerBase::MapGpuDescriptorHandles(D3D12_GPU_DESCRIPTOR_HANDLE* handles, size_t handles_len)
{
    object_mapping::MapGpuDescriptorHandles(handles, handles_len, descriptor_map_);
}

void Dx12ReplayConsumerBase::MapGpuVirtualAddress(D3D12_GPU_VIRTUAL_ADDRESS& address)
{
    object_mapping::MapGpuVirtualAddress(address, gpu_va_map_);
}

void Dx12ReplayConsumerBase::MapGpuVirtualAddress(uint8_t* dst_address_ptr, const uint8_t* src_address_ptr)
{
    D3D12_GPU_VIRTUAL_ADDRESS address;
    util::platform::MemoryCopy(
        &address, sizeof(D3D12_GPU_VIRTUAL_ADDRESS), src_address_ptr, sizeof(D3D12_GPU_VIRTUAL_ADDRESS));
    MapGpuVirtualAddress(address);
    util::platform::MemoryCopy(
        dst_address_ptr, sizeof(D3D12_GPU_VIRTUAL_ADDRESS), &address, sizeof(D3D12_GPU_VIRTUAL_ADDRESS));
}

void Dx12ReplayConsumerBase::MapGpuVirtualAddresses(D3D12_GPU_VIRTUAL_ADDRESS* addresses, size_t addresses_len)
{
    object_mapping::MapGpuVirtualAddresses(addresses, addresses_len, gpu_va_map_);
}

void Dx12ReplayConsumerBase::RemoveObject(DxObjectInfo* info)
{
    if (info != nullptr)
    {
        DestroyObjectExtraInfo(info, true);
        object_mapping::RemoveObject(info->capture_id, &object_info_table_);
    }
}

void Dx12ReplayConsumerBase::CheckReplayResult(const char* call_name, HRESULT capture_result, HRESULT replay_result)
{
    if (capture_result != replay_result)
    {
        if ((replay_result == DXGI_ERROR_DEVICE_REMOVED) || (replay_result == D3D12_ERROR_INVALID_REDIST))
        {
            GFXRECON_LOG_FATAL(
                "%s returned %s, which does not match the value returned at capture %s. Replay cannot continue.",
                call_name,
                enumutil::GetResultValueString(replay_result).c_str(),
                enumutil::GetResultValueString(capture_result).c_str());
            RaiseFatalError(enumutil::GetResultDescription(replay_result));
        }
        else
        {
            GFXRECON_LOG_WARNING("%s returned %s, which does not match the value returned at capture %s.",
                                 call_name,
                                 enumutil::GetResultValueString(replay_result).c_str(),
                                 enumutil::GetResultValueString(capture_result).c_str());
        }
    }
}

void* Dx12ReplayConsumerBase::PreProcessExternalObject(uint64_t          object_id,
                                                       format::ApiCallId call_id,
                                                       const char*       call_name)
{
    void* object = nullptr;
    switch (call_id)
    {
        case format::ApiCallId::ApiCall_IDXGIAdapter3_RegisterVideoMemoryBudgetChangeNotificationEvent:
            object = GetEventObject(object_id, false);
            break;
        case format::ApiCallId::ApiCall_IDXGIFactory_MakeWindowAssociation:
        {
            auto entry = window_handles_.find(object_id);
            if (entry != window_handles_.end())
            {
                object = entry->second;
            }
            break;
        }
        default:
            GFXRECON_LOG_WARNING("Skipping object handle mapping for unsupported external object type processed by %s",
                                 call_name);
            break;
    }
    return object;
}

void Dx12ReplayConsumerBase::PostProcessExternalObject(
    HRESULT replay_result, void* object, uint64_t* object_id, format::ApiCallId call_id, const char* call_name)
{
    GFXRECON_UNREFERENCED_PARAMETER(replay_result);
    GFXRECON_UNREFERENCED_PARAMETER(object_id);
    GFXRECON_UNREFERENCED_PARAMETER(object);

    switch (call_id)
    {
        case format::ApiCallId::ApiCall_IDXGISurface1_GetDC:
        case format::ApiCallId::ApiCall_IDXGIFactory_GetWindowAssociation:
        case format::ApiCallId::ApiCall_IDXGISwapChain1_GetHwnd:
            break;

        default:
            GFXRECON_LOG_WARNING("Skipping object handle mapping for unsupported external object type processed by %s",
                                 call_name);
            break;
    }
}

ULONG Dx12ReplayConsumerBase::OverrideAddRef(DxObjectInfo* replay_object_info, ULONG original_result)
{
    assert((replay_object_info != nullptr) && (replay_object_info->object != nullptr));

    auto object = replay_object_info->object;

    ++(replay_object_info->ref_count);

    return object->AddRef();
}

ULONG Dx12ReplayConsumerBase::OverrideRelease(DxObjectInfo* replay_object_info, ULONG original_result)
{
    assert((replay_object_info != nullptr) && (replay_object_info->object != nullptr) &&
           (replay_object_info->ref_count > 0));

    auto object = replay_object_info->object;

    --(replay_object_info->ref_count);
    if ((replay_object_info->ref_count == 0) && (replay_object_info->extra_ref == 0))
    {
        RemoveObject(replay_object_info);
    }

    return object->Release();
}

void Dx12ReplayConsumerBase::PrePresent(DxObjectInfo* swapchain_object_info)
{
    if (screenshot_handler_ != nullptr)
    {
        if (screenshot_handler_->IsScreenshotFrame())
        {
            auto swapchain            = static_cast<IDXGISwapChain*>(swapchain_object_info->object);
            auto swapchain_extra_info = GetExtraInfo<DxgiSwapchainInfo>(swapchain_object_info);

            if (swapchain_extra_info && swapchain_extra_info->command_queue)
            {
                graphics::dx12::TakeScreenshot(frame_buffer_renderer_,
                                               swapchain_extra_info->command_queue,
                                               swapchain,
                                               screenshot_handler_->GetCurrentFrame(),
                                               screenshot_file_prefix_,
                                               screenshot_format_);
            }
            else
            {
                GFXRECON_LOG_ERROR("Failed to get the ID3D12CommandQueue associated with the presented swap chain. "
                                   "GFXReconstruct is unable to take a screenshot.");
            }
        }
        screenshot_handler_->EndFrame();
    }
}

void Dx12ReplayConsumerBase::PostPresent()
{
    ReadDebugMessages();
}

HRESULT Dx12ReplayConsumerBase::OverridePresent(DxObjectInfo* replay_object_info,
                                                HRESULT       original_result,
                                                UINT          sync_interval,
                                                UINT          flags)
{
    auto replay_object = static_cast<IDXGISwapChain*>(replay_object_info->object);
    PrePresent(replay_object_info);
    auto result = replay_object->Present(sync_interval, flags);
    PostPresent();

    return result;
}

HRESULT
Dx12ReplayConsumerBase::OverridePresent1(DxObjectInfo*                                          replay_object_info,
                                         HRESULT                                                original_result,
                                         UINT                                                   sync_interval,
                                         UINT                                                   flags,
                                         StructPointerDecoder<Decoded_DXGI_PRESENT_PARAMETERS>* present_parameters)
{
    auto replay_object = static_cast<IDXGISwapChain1*>(replay_object_info->object);
    PrePresent(replay_object_info);
    auto result = replay_object->Present1(sync_interval, flags, present_parameters->GetPointer());
    PostPresent();

    return result;
}

HRESULT Dx12ReplayConsumerBase::OverrideCreateSwapChainForHwnd(
    DxObjectInfo*                                                  replay_object_info,
    HRESULT                                                        original_result,
    DxObjectInfo*                                                  device_info,
    uint64_t                                                       hwnd_id,
    StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC1>*           desc,
    StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_FULLSCREEN_DESC>* full_screen_desc,
    DxObjectInfo*                                                  restrict_to_output_info,
    HandlePointerDecoder<IDXGISwapChain1*>*                        swapchain)
{
    return CreateSwapChainForHwnd(replay_object_info,
                                  original_result,
                                  device_info,
                                  hwnd_id,
                                  desc,
                                  full_screen_desc,
                                  restrict_to_output_info,
                                  swapchain);
}

HRESULT
Dx12ReplayConsumerBase::OverrideCreateSwapChain(DxObjectInfo*                                       replay_object_info,
                                                HRESULT                                             original_result,
                                                DxObjectInfo*                                       device_info,
                                                StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC>* desc,
                                                HandlePointerDecoder<IDXGISwapChain*>*              swapchain)
{
    assert(desc != nullptr);

    auto    desc_pointer   = desc->GetPointer();
    HRESULT result         = E_FAIL;
    Window* window         = nullptr;
    auto    wsi_context    = application_ ? application_->GetWsiContext("", true) : nullptr;
    auto    window_factory = wsi_context ? wsi_context->GetWindowFactory() : nullptr;

    if (window_factory != nullptr && desc_pointer != nullptr)
    {
        ReplaceWindowedResolution(desc_pointer->BufferDesc.Width, desc_pointer->BufferDesc.Height);
        window = window_factory->Create(kDefaultWindowPositionX,
                                        kDefaultWindowPositionY,
                                        desc_pointer->BufferDesc.Width,
                                        desc_pointer->BufferDesc.Height);
    }

    if (window != nullptr)
    {
        HWND hwnd{};
        if (window->GetNativeHandle(Window::kWin32HWnd, reinterpret_cast<void**>(&hwnd)))
        {
            assert((replay_object_info != nullptr) && (replay_object_info->object != nullptr) &&
                   (swapchain != nullptr));

            auto      replay_object = static_cast<IDXGIFactory*>(replay_object_info->object);
            IUnknown* device        = nullptr;

            if (device_info != nullptr)
            {
                device = device_info->object;
            }

            desc_pointer->OutputWindow = hwnd;

            result = replay_object->CreateSwapChain(device, desc_pointer, swapchain->GetHandlePointer());

            if (SUCCEEDED(result))
            {
                auto     object_info = static_cast<DxObjectInfo*>(swapchain->GetConsumerData(0));
                auto     meta_info   = desc->GetMetaStructPointer();
                uint64_t hwnd_id     = 0;

                if (meta_info != nullptr)
                {
                    hwnd_id = meta_info->OutputWindow;
                }

                SetSwapchainInfo(
                    object_info, window, hwnd_id, hwnd, desc_pointer->BufferCount, device, desc_pointer->Windowed);
            }
            else
            {
                window_factory->Destroy(window);
            }
        }
        else
        {
            GFXRECON_LOG_FATAL("Failed to retrieve handle from window");
            window_factory->Destroy(window);
        }
    }
    else
    {
        GFXRECON_LOG_FATAL("Failed to create a window.  Replay cannot continue.");
    }

    return result;
}

HRESULT
Dx12ReplayConsumerBase::OverrideCreateSwapChainForCoreWindow(DxObjectInfo* replay_object_info,
                                                             HRESULT       original_result,
                                                             DxObjectInfo* device_info,
                                                             DxObjectInfo* window_info,
                                                             StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC1>* desc,
                                                             DxObjectInfo* restrict_to_output_info,
                                                             HandlePointerDecoder<IDXGISwapChain1*>* swapchain)
{
    GFXRECON_UNREFERENCED_PARAMETER(window_info);

    return CreateSwapChainForHwnd(
        replay_object_info, original_result, device_info, 0, desc, nullptr, restrict_to_output_info, swapchain);
}

HRESULT
Dx12ReplayConsumerBase::OverrideCreateSwapChainForComposition(DxObjectInfo* replay_object_info,
                                                              HRESULT       original_result,
                                                              DxObjectInfo* device_info,
                                                              StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC1>* desc,
                                                              DxObjectInfo* restrict_to_output_info,
                                                              HandlePointerDecoder<IDXGISwapChain1*>* swapchain)
{
    return CreateSwapChainForHwnd(
        replay_object_info, original_result, device_info, 0, desc, nullptr, restrict_to_output_info, swapchain);
}

HRESULT Dx12ReplayConsumerBase::OverrideCreateDXGIFactory2(HRESULT                      original_result,
                                                           UINT                         flags,
                                                           Decoded_GUID                 riid,
                                                           HandlePointerDecoder<void*>* factory)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert(factory != nullptr);

    if (options_.enable_validation_layer)
    {
        flags |= DXGI_CREATE_FACTORY_DEBUG;
    }
    auto replay_result = CreateDXGIFactory2(flags, *riid.decoded_value, factory->GetHandlePointer());

    return replay_result;
}

HRESULT Dx12ReplayConsumerBase::OverrideD3D12CreateDevice(HRESULT                      original_result,
                                                          DxObjectInfo*                adapter_info,
                                                          D3D_FEATURE_LEVEL            minimum_feature_level,
                                                          Decoded_GUID                 riid,
                                                          HandlePointerDecoder<void*>* device)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    GFXRECON_ASSERT(device != nullptr);

    IUnknown* adapter = nullptr;
    if (render_adapter_ == nullptr)
    {
        if (adapter_info != nullptr)
        {
            adapter = adapter_info->object;
        }
    }
    else
    {
        adapter = render_adapter_;
    }

    auto replay_result =
        D3D12CreateDevice(adapter, minimum_feature_level, *riid.decoded_value, device->GetHandlePointer());

    if (SUCCEEDED(replay_result) && !device->IsNull())
    {
        auto device_info = std::make_unique<D3D12DeviceInfo>();
        auto device_ptr  = reinterpret_cast<ID3D12Device*>(*device->GetHandlePointer());

        graphics::dx12::GetAdapterAndIndexbyDevice(reinterpret_cast<ID3D12Device*>(device_ptr),
                                                   device_info->adapter3,
                                                   device_info->adapter_node_index,
                                                   adapters_);
        device_info->is_uma = graphics::dx12::IsUma(device_ptr);

        SetExtraInfo(device, std::move(device_info));

        graphics::dx12::MarkActiveAdapter(device_ptr, adapters_);
    }

    return replay_result;
}

void Dx12ReplayConsumerBase::ProcessDxgiAdapterInfo(const format::DxgiAdapterInfoCommandHeader& adapter_info_header)
{
    // Only check this if the block is not of a software adapter
    if (graphics::dx12::IsSoftwareAdapter(adapter_info_header.adapter_desc) == false)
    {
        // Only do this check if replay-time adapters have been tracked
        if (adapters_.empty() == false)
        {
            bool found_matching_active_adapter = false;

            // Iterate through all available hardware adapters (during replay)
            for (const auto& adapter : adapters_)
            {
                const format::DxgiAdapterDesc& replay_adapter_desc = adapter.second.internal_desc;

                // If this adapter was marked as active by CreateDevice (during replay)
                if (adapter.second.active == true)
                {
                    // Check if this adapter was marked active (during capture)
                    if ((adapter_info_header.adapter_desc.VendorId == replay_adapter_desc.VendorId) &&
                        (adapter_info_header.adapter_desc.DeviceId == replay_adapter_desc.DeviceId))
                    {
                        found_matching_active_adapter = true;
                        break;
                    }
                }
            }

            if (found_matching_active_adapter == false)
            {
                GFXRECON_LOG_WARNING("Mismatch:");

                std::string capture_adapter_str =
                    gfxrecon::util::WCharArrayToString(adapter_info_header.adapter_desc.Description);

                GFXRECON_LOG_WARNING("Capture-time adapter: [%s] [DeviceID 0x%x] [VendorId 0x%x]",
                                     capture_adapter_str.c_str(),
                                     adapter_info_header.adapter_desc.DeviceId,
                                     adapter_info_header.adapter_desc.VendorId);

                // Only found one adapter for replay
                if (adapters_.size() == 1)
                {
                    format::DxgiAdapterDesc replay_adapter_desc = adapters_.begin()->second.internal_desc;

                    std::string replay_adapter_str =
                        gfxrecon::util::WCharArrayToString(replay_adapter_desc.Description);

                    GFXRECON_LOG_WARNING("Replay-time adapter: [%s] [DeviceID 0x%x] [VendorId 0x%x]",
                                         replay_adapter_str.c_str(),
                                         replay_adapter_desc.DeviceId,
                                         replay_adapter_desc.VendorId);
                }

                // Multiple adapters available during replay
                else if (adapters_.size() > 1)
                {
                    GFXRECON_LOG_WARNING("Available replay-time adapters:");
                    for (const auto& adapter : adapters_)
                    {
                        format::DxgiAdapterDesc replay_adapter_desc = adapter.second.internal_desc;

                        std::string replay_adapter_str =
                            gfxrecon::util::WCharArrayToString(replay_adapter_desc.Description);

                        GFXRECON_LOG_WARNING("[%s] [DeviceID 0x%x] [VendorId 0x%x]",
                                             replay_adapter_str.c_str(),
                                             replay_adapter_desc.DeviceId,
                                             replay_adapter_desc.VendorId);
                    }
                }

                GFXRECON_LOG_WARNING(
                    "Recorded instructions contain data aimed for the capture-time GPU. Replay may fail.")

                if (options_.enable_d3d12_two_pass_replay)
                {
                    GFXRECON_LOG_INFO("The \"-m realign\" option has been deprecated.");
                }
            }
            else
            {
                GFXRECON_LOG_DEBUG("Match: replay-time GPU vs capture-time GPU");
            }
        }
    }
}

void Dx12ReplayConsumerBase::DetectAdapters()
{
    IDXGIFactory1* factory1 = nullptr;

    HRESULT result = CreateDXGIFactory1(IID_IDXGIFactory1, reinterpret_cast<void**>(&factory1));

    if (SUCCEEDED(result))
    {
        graphics::dx12::TrackAdapters(result, reinterpret_cast<void**>(&factory1), adapters_);
        render_adapter_ = graphics::dx12::GetAdapterbyIndex(adapters_, options_.override_gpu_index);

        factory1->Release();
    }
}

void Dx12ReplayConsumerBase::InitCommandQueueExtraInfo(ID3D12Device*                device,
                                                       HandlePointerDecoder<void*>* command_queue_decoder)
{
    auto command_queue_info = std::make_unique<D3D12CommandQueueInfo>();

    // Create the fence used for when command queues require sync after command list execution.
    // Note that this fence is used only for waiting on command list execution. When needed, it will be signalled by
    // the command queue in OverrideExecuteCommandLists and wait on in WaitForCommandListExecution.
    auto fence_result = device->CreateFence(0, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&command_queue_info->sync_fence));

    if (SUCCEEDED(fence_result))
    {
        command_queue_info->sync_event = CreateEventA(nullptr, TRUE, FALSE, nullptr);
    }
    else
    {
        GFXRECON_LOG_ERROR("Failed to create ID3D12Fence object used to sync after command list execution.");
    }

    SetExtraInfo(command_queue_decoder, std::move(command_queue_info));
}

HRESULT Dx12ReplayConsumerBase::OverrideCreateCommandQueue(DxObjectInfo* replay_object_info,
                                                           HRESULT       original_result,
                                                           StructPointerDecoder<Decoded_D3D12_COMMAND_QUEUE_DESC>* desc,
                                                           Decoded_GUID                                            riid,
                                                           HandlePointerDecoder<void*>* command_queue)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    GFXRECON_ASSERT((replay_object_info != nullptr) && (replay_object_info->object != nullptr) && (desc != nullptr) &&
                    (command_queue != nullptr));

    auto replay_object = static_cast<ID3D12Device*>(replay_object_info->object);
    auto replay_result =
        replay_object->CreateCommandQueue(desc->GetPointer(), *riid.decoded_value, command_queue->GetHandlePointer());

    if (SUCCEEDED(replay_result))
    {
        InitCommandQueueExtraInfo(replay_object, command_queue);
    }

    return replay_result;
}

HRESULT
Dx12ReplayConsumerBase::OverrideCreateCommandQueue1(DxObjectInfo* device9_object_info,
                                                    HRESULT       original_result,
                                                    StructPointerDecoder<Decoded_D3D12_COMMAND_QUEUE_DESC>* desc,
                                                    Decoded_GUID                                            creator_id,
                                                    Decoded_GUID                                            riid,
                                                    HandlePointerDecoder<void*>* command_queue_decoder)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    GFXRECON_ASSERT((device9_object_info != nullptr) && (device9_object_info->object != nullptr) && (desc != nullptr) &&
                    (command_queue_decoder != nullptr));

    auto device9       = static_cast<ID3D12Device9*>(device9_object_info->object);
    auto replay_result = device9->CreateCommandQueue1(
        desc->GetPointer(), *creator_id.decoded_value, *riid.decoded_value, command_queue_decoder->GetHandlePointer());

    if (SUCCEEDED(replay_result))
    {
        InitCommandQueueExtraInfo(device9, command_queue_decoder);
    }

    return replay_result;
}

HRESULT
Dx12ReplayConsumerBase::OverrideCreateDescriptorHeap(DxObjectInfo* replay_object_info,
                                                     HRESULT       original_result,
                                                     StructPointerDecoder<Decoded_D3D12_DESCRIPTOR_HEAP_DESC>* desc,
                                                     Decoded_GUID                                              riid,
                                                     HandlePointerDecoder<void*>*                              heap)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    GFXRECON_ASSERT((replay_object_info != nullptr) && (replay_object_info->object != nullptr) && (desc != nullptr) &&
                    (heap != nullptr));

    auto replay_object = static_cast<ID3D12Device*>(replay_object_info->object);
    auto desc_pointer  = desc->GetPointer();

    // Create an equivalent but temporary dummy heap
    // This allows us to further validate GFXR, since playback will now use a heap located at a different address
    HRESULT               dummy_result = E_FAIL;
    ID3D12DescriptorHeap* dummy_heap   = nullptr;
    if (options_.create_dummy_allocations)
    {
        dummy_result = replay_object->CreateDescriptorHeap(desc_pointer, IID_PPV_ARGS(&dummy_heap));

        if (!SUCCEEDED(dummy_result))
        {
            GFXRECON_LOG_WARNING("Failed to create dummy descriptor heap");
        }
    }

    // Playback will use this heap
    auto replay_result =
        replay_object->CreateDescriptorHeap(desc_pointer, *riid.decoded_value, heap->GetHandlePointer());

    // Release the temporary dummy heap
    if (options_.create_dummy_allocations)
    {
        if (SUCCEEDED(dummy_result))
        {
            dummy_heap->Release();
        }
    }

    if (SUCCEEDED(replay_result) && (desc_pointer != nullptr))
    {
        auto heap_info              = std::make_unique<D3D12DescriptorHeapInfo>();
        heap_info->descriptor_type  = desc_pointer->Type;
        heap_info->descriptor_count = desc_pointer->NumDescriptors;

        auto device_info = GetExtraInfo<D3D12DeviceInfo>(replay_object_info);
        if (device_info != nullptr)
        {
            heap_info->capture_increments = device_info->capture_increments;
            heap_info->replay_increments  = device_info->replay_increments;
        }

        SetExtraInfo(heap, std::move(heap_info));
    }

    return replay_result;
}

HRESULT Dx12ReplayConsumerBase::OverrideCreateCommittedResource(
    DxObjectInfo*                                        replay_object_info,
    HRESULT                                              original_result,
    StructPointerDecoder<Decoded_D3D12_HEAP_PROPERTIES>* pHeapProperties,
    D3D12_HEAP_FLAGS                                     HeapFlags,
    StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>*   pDesc,
    D3D12_RESOURCE_STATES                                InitialResourceState,
    StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE>*     pOptimizedClearValue,
    Decoded_GUID                                         riid,
    HandlePointerDecoder<void*>*                         resource)
{
    GFXRECON_ASSERT((replay_object_info != nullptr) && (replay_object_info->object != nullptr) && (pDesc != nullptr));

    auto replay_object           = static_cast<ID3D12Device*>(replay_object_info->object);
    auto heap_properties_pointer = pHeapProperties->GetPointer();

    auto desc_pointer = pDesc->GetPointer();

    auto clear_value_pointer = pOptimizedClearValue->GetPointer();

    // Create an equivalent but temporary dummy resource
    // This allows us to further validate GFXR, since playback will now use a resource located at a different address
    HRESULT         dummy_result   = E_FAIL;
    ID3D12Resource* dummy_resource = nullptr;
    if (options_.create_dummy_allocations)
    {
        dummy_result = replay_object->CreateCommittedResource(heap_properties_pointer,
                                                              HeapFlags,
                                                              desc_pointer,
                                                              InitialResourceState,
                                                              clear_value_pointer,
                                                              IID_PPV_ARGS(&dummy_resource));

        if (!SUCCEEDED(dummy_result))
        {
            GFXRECON_LOG_WARNING("Failed to create dummy committed resource");
        }
    }

    // Playback will use this resource
    auto replay_result = replay_object->CreateCommittedResource(heap_properties_pointer,
                                                                HeapFlags,
                                                                desc_pointer,
                                                                InitialResourceState,
                                                                clear_value_pointer,
                                                                *riid.decoded_value,
                                                                resource->GetHandlePointer());

    // Release the temporary dummy resource
    if (options_.create_dummy_allocations)
    {
        if (SUCCEEDED(dummy_result))
        {
            dummy_resource->Release();
        }
    }
    if (SUCCEEDED(replay_result))
    {
        auto res        = static_cast<ID3D12Resource*>(*resource->GetHandlePointer());
        auto res_desc   = res->GetDesc();
        auto extra_info = std::make_unique<D3D12ResourceInfo>();

        extra_info->subresource_count = graphics::Dx12ResourceDataUtil::GetSubresourceCount(res);
        extra_info->resource_state_infos.resize(extra_info->subresource_count);
        for (auto& info : extra_info->resource_state_infos)
        {
            info.states        = InitialResourceState;
            info.barrier_flags = D3D12_RESOURCE_BARRIER_FLAG_NONE;
        }
        SetExtraInfo(resource, std::move(extra_info));
    }
    return replay_result;
}

HRESULT Dx12ReplayConsumerBase::OverrideCreateHeap(DxObjectInfo*                                  replay_object_info,
                                                   HRESULT                                        original_result,
                                                   StructPointerDecoder<Decoded_D3D12_HEAP_DESC>* pDesc,
                                                   Decoded_GUID                                   riid,
                                                   HandlePointerDecoder<void*>*                   ppvHeap)
{
    GFXRECON_ASSERT((replay_object_info != nullptr) && (replay_object_info->object != nullptr) &&
                    (ppvHeap != nullptr) && (pDesc != nullptr));

    auto replay_object = static_cast<ID3D12Device*>(replay_object_info->object);
    auto heap_desc     = pDesc->GetPointer();

    HRESULT     dummy_result = E_FAIL;
    ID3D12Heap* dummy_heap   = nullptr;
    if (options_.create_dummy_allocations)
    {
        dummy_result = replay_object->CreateHeap(heap_desc, IID_PPV_ARGS(&dummy_heap));

        if (!SUCCEEDED(dummy_result))
        {
            GFXRECON_LOG_WARNING("Failed to create dummy heap");
        }
    }

    auto replay_result = replay_object->CreateHeap(heap_desc, *riid.decoded_value, ppvHeap->GetHandlePointer());

    if (options_.create_dummy_allocations)
    {
        if (SUCCEEDED(dummy_result))
        {
            dummy_heap->Release();
        }
    }

    return replay_result;
}

HRESULT Dx12ReplayConsumerBase::OverrideCreateHeap1(DxObjectInfo*                                  replay_object_info,
                                                    HRESULT                                        return_value,
                                                    StructPointerDecoder<Decoded_D3D12_HEAP_DESC>* pDesc,
                                                    DxObjectInfo*                                  pProtectedSession,
                                                    Decoded_GUID                                   riid,
                                                    HandlePointerDecoder<void*>*                   ppvHeap)
{
    GFXRECON_ASSERT((replay_object_info != nullptr) && (replay_object_info->object != nullptr) && (pDesc != nullptr) &&
                    (ppvHeap != nullptr));

    auto                            replay_object        = static_cast<ID3D12Device4*>(replay_object_info->object);
    auto                            heap_desc            = pDesc->GetPointer();
    ID3D12ProtectedResourceSession* in_pProtectedSession = nullptr;
    if (pProtectedSession != nullptr)
    {
        in_pProtectedSession = static_cast<ID3D12ProtectedResourceSession*>(pProtectedSession->object);
    }

    HRESULT      dummy_result = E_FAIL;
    ID3D12Heap1* dummy_heap   = nullptr;
    if (options_.create_dummy_allocations)
    {
        dummy_result = replay_object->CreateHeap1(heap_desc, in_pProtectedSession, IID_PPV_ARGS(&dummy_heap));

        if (!SUCCEEDED(dummy_result))
        {
            GFXRECON_LOG_WARNING("Failed to create dummy heap");
        }
    }

    auto replay_result =
        replay_object->CreateHeap1(heap_desc, in_pProtectedSession, *riid.decoded_value, ppvHeap->GetHandlePointer());

    if (options_.create_dummy_allocations)
    {
        if (SUCCEEDED(dummy_result))
        {
            dummy_heap->Release();
        }
    }

    return replay_result;
}

HRESULT Dx12ReplayConsumerBase::OverrideCreateCommittedResource1(
    DxObjectInfo*                                        replay_object_info,
    HRESULT                                              original_result,
    StructPointerDecoder<Decoded_D3D12_HEAP_PROPERTIES>* pHeapProperties,
    D3D12_HEAP_FLAGS                                     HeapFlags,
    StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>*   pDesc,
    D3D12_RESOURCE_STATES                                InitialResourceState,
    StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE>*     pOptimizedClearValue,
    DxObjectInfo*                                        protected_session_object_info,
    Decoded_GUID                                         riid,
    HandlePointerDecoder<void*>*                         resource)
{
    GFXRECON_ASSERT((replay_object_info != nullptr) && (replay_object_info->object != nullptr) && (pDesc != nullptr));

    auto replay_object = static_cast<ID3D12Device4*>(replay_object_info->object);

    ID3D12ProtectedResourceSession* protected_session = nullptr;
    if (protected_session_object_info != nullptr)
    {
        protected_session = static_cast<ID3D12ProtectedResourceSession*>(protected_session_object_info->object);
    }

    auto heap_properties_pointer = pHeapProperties->GetPointer();

    auto desc_pointer = pDesc->GetPointer();

    auto clear_value_pointer = pOptimizedClearValue->GetPointer();

    // Create an equivalent but temporary dummy resource
    // This allows us to further validate GFXR, since playback will now use a resource located at a different address
    HRESULT         dummy_result   = E_FAIL;
    ID3D12Resource* dummy_resource = nullptr;
    if (options_.create_dummy_allocations)
    {
        dummy_result = replay_object->CreateCommittedResource1(heap_properties_pointer,
                                                               HeapFlags,
                                                               desc_pointer,
                                                               InitialResourceState,
                                                               clear_value_pointer,
                                                               protected_session,
                                                               IID_PPV_ARGS(&dummy_resource));

        if (!SUCCEEDED(dummy_result))
        {
            GFXRECON_LOG_WARNING("Failed to create dummy committed resource");
        }
    }

    // Playback will use this resource
    auto replay_result = replay_object->CreateCommittedResource1(heap_properties_pointer,
                                                                 HeapFlags,
                                                                 desc_pointer,
                                                                 InitialResourceState,
                                                                 clear_value_pointer,
                                                                 protected_session,
                                                                 *riid.decoded_value,
                                                                 resource->GetHandlePointer());

    // Release the temporary dummy resource
    if (options_.create_dummy_allocations)
    {
        if (SUCCEEDED(dummy_result))
        {
            dummy_resource->Release();
        }
    }
    if (SUCCEEDED(replay_result))
    {
        auto res        = static_cast<ID3D12Resource*>(*resource->GetHandlePointer());
        auto res_desc   = res->GetDesc();
        auto extra_info = std::make_unique<D3D12ResourceInfo>();

        extra_info->subresource_count = graphics::Dx12ResourceDataUtil::GetSubresourceCount(res);
        extra_info->resource_state_infos.resize(extra_info->subresource_count);
        for (auto& info : extra_info->resource_state_infos)
        {
            info.states        = InitialResourceState;
            info.barrier_flags = D3D12_RESOURCE_BARRIER_FLAG_NONE;
        }
        SetExtraInfo(resource, std::move(extra_info));
    }
    return replay_result;
}

HRESULT Dx12ReplayConsumerBase::OverrideCreateCommittedResource2(
    DxObjectInfo*                                        replay_object_info,
    HRESULT                                              original_result,
    StructPointerDecoder<Decoded_D3D12_HEAP_PROPERTIES>* pHeapProperties,
    D3D12_HEAP_FLAGS                                     HeapFlags,
    StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC1>*  pDesc,
    D3D12_RESOURCE_STATES                                InitialResourceState,
    StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE>*     pOptimizedClearValue,
    DxObjectInfo*                                        protected_session_object_info,
    Decoded_GUID                                         riid,
    HandlePointerDecoder<void*>*                         resource)
{
    GFXRECON_ASSERT((replay_object_info != nullptr) && (replay_object_info->object != nullptr) && (pDesc != nullptr));

    auto replay_object = static_cast<ID3D12Device8*>(replay_object_info->object);

    ID3D12ProtectedResourceSession* protected_session = nullptr;
    if (protected_session_object_info != nullptr)
    {
        protected_session = static_cast<ID3D12ProtectedResourceSession*>(protected_session_object_info->object);
    }

    auto heap_properties_pointer = pHeapProperties->GetPointer();

    auto desc_pointer = pDesc->GetPointer();

    auto clear_value_pointer = pOptimizedClearValue->GetPointer();

    // Create an equivalent but temporary dummy resource
    // This allows us to further validate GFXR, since playback will now use a resource located at a different address
    HRESULT         dummy_result   = E_FAIL;
    ID3D12Resource* dummy_resource = nullptr;
    if (options_.create_dummy_allocations)
    {
        dummy_result = replay_object->CreateCommittedResource2(heap_properties_pointer,
                                                               HeapFlags,
                                                               desc_pointer,
                                                               InitialResourceState,
                                                               clear_value_pointer,
                                                               protected_session,
                                                               IID_PPV_ARGS(&dummy_resource));

        if (!SUCCEEDED(dummy_result))
        {
            GFXRECON_LOG_WARNING("Failed to create dummy committed resource");
        }
    }

    // Playback will use this resource
    auto replay_result = replay_object->CreateCommittedResource2(heap_properties_pointer,
                                                                 HeapFlags,
                                                                 desc_pointer,
                                                                 InitialResourceState,
                                                                 clear_value_pointer,
                                                                 protected_session,
                                                                 *riid.decoded_value,
                                                                 resource->GetHandlePointer());

    // Release the temporary dummy resource
    if (options_.create_dummy_allocations)
    {
        if (SUCCEEDED(dummy_result))
        {
            dummy_resource->Release();
        }
    }
    if (SUCCEEDED(replay_result))
    {
        auto res        = static_cast<ID3D12Resource*>(*resource->GetHandlePointer());
        auto res_desc   = res->GetDesc();
        auto extra_info = std::make_unique<D3D12ResourceInfo>();

        extra_info->subresource_count = graphics::Dx12ResourceDataUtil::GetSubresourceCount(res);
        extra_info->resource_state_infos.resize(extra_info->subresource_count);
        for (auto& info : extra_info->resource_state_infos)
        {
            info.states        = InitialResourceState;
            info.barrier_flags = D3D12_RESOURCE_BARRIER_FLAG_NONE;
        }
        SetExtraInfo(resource, std::move(extra_info));
    }
    return replay_result;
}

HRESULT Dx12ReplayConsumerBase::OverrideCreateCommittedResource3(
    DxObjectInfo*                                        replay_object_info,
    HRESULT                                              original_result,
    StructPointerDecoder<Decoded_D3D12_HEAP_PROPERTIES>* pHeapProperties,
    D3D12_HEAP_FLAGS                                     HeapFlags,
    StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC1>*  pDesc,
    D3D12_BARRIER_LAYOUT                                 InitialLayout,
    StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE>*     pOptimizedClearValue,
    DxObjectInfo*                                        protected_session_object_info,
    UINT32                                               NumCastableFormats,
    PointerDecoder<DXGI_FORMAT>*                         pCastableFormats,
    Decoded_GUID                                         riid,
    HandlePointerDecoder<void*>*                         resource)
{
    GFXRECON_ASSERT((replay_object_info != nullptr) && (replay_object_info->object != nullptr) && (pDesc != nullptr));

    auto replay_object = static_cast<ID3D12Device10*>(replay_object_info->object);

    ID3D12ProtectedResourceSession* protected_session = nullptr;
    if (protected_session_object_info != nullptr)
    {
        protected_session = static_cast<ID3D12ProtectedResourceSession*>(protected_session_object_info->object);
    }

    auto heap_properties_pointer = pHeapProperties->GetPointer();

    auto desc_pointer = pDesc->GetPointer();

    auto clear_value_pointer = pOptimizedClearValue->GetPointer();

    // Create an equivalent but temporary dummy resource
    // This allows us to further validate GFXR, since playback will now use a resource located at a different address
    HRESULT         dummy_result   = E_FAIL;
    ID3D12Resource* dummy_resource = nullptr;
    if (options_.create_dummy_allocations)
    {
        dummy_result = replay_object->CreateCommittedResource3(heap_properties_pointer,
                                                               HeapFlags,
                                                               desc_pointer,
                                                               InitialLayout,
                                                               clear_value_pointer,
                                                               protected_session,
                                                               NumCastableFormats,
                                                               pCastableFormats->GetPointer(),
                                                               IID_PPV_ARGS(&dummy_resource));

        if (!SUCCEEDED(dummy_result))
        {
            GFXRECON_LOG_WARNING("Failed to create dummy committed resource");
        }
    }

    // Playback will use this resource
    auto replay_result = replay_object->CreateCommittedResource3(heap_properties_pointer,
                                                                 HeapFlags,
                                                                 desc_pointer,
                                                                 InitialLayout,
                                                                 clear_value_pointer,
                                                                 protected_session,
                                                                 NumCastableFormats,
                                                                 pCastableFormats->GetPointer(),
                                                                 *riid.decoded_value,
                                                                 resource->GetHandlePointer());

    // Release the temporary dummy resource
    if (options_.create_dummy_allocations)
    {
        if (SUCCEEDED(dummy_result))
        {
            dummy_resource->Release();
        }
    }

    return replay_result;
}

HRESULT Dx12ReplayConsumerBase::OverrideCreateFence(DxObjectInfo*                replay_object_info,
                                                    HRESULT                      original_result,
                                                    UINT64                       initial_value,
                                                    D3D12_FENCE_FLAGS            flags,
                                                    Decoded_GUID                 riid,
                                                    HandlePointerDecoder<void*>* fence)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((replay_object_info != nullptr) && (replay_object_info->object != nullptr) && (fence != nullptr));

    auto replay_object = static_cast<ID3D12Device*>(replay_object_info->object);

    auto replay_result =
        replay_object->CreateFence(initial_value, flags, *riid.decoded_value, fence->GetHandlePointer());

    if (SUCCEEDED(replay_result))
    {
        auto fence_info                 = std::make_unique<D3D12FenceInfo>();
        fence_info->last_signaled_value = initial_value;

        SetExtraInfo(fence, std::move(fence_info));
    }

    return replay_result;
}

UINT Dx12ReplayConsumerBase::OverrideGetDescriptorHandleIncrementSize(DxObjectInfo*              replay_object_info,
                                                                      UINT                       original_result,
                                                                      D3D12_DESCRIPTOR_HEAP_TYPE descriptor_heap_type)
{
    assert((replay_object_info != nullptr) && (replay_object_info->object != nullptr));

    auto replay_object = static_cast<ID3D12Device*>(replay_object_info->object);
    auto replay_result = replay_object->GetDescriptorHandleIncrementSize(descriptor_heap_type);

    auto device_info = GetExtraInfo<D3D12DeviceInfo>(replay_object_info);
    if (device_info != nullptr)
    {
        (*device_info->capture_increments)[descriptor_heap_type] = original_result;
        (*device_info->replay_increments)[descriptor_heap_type]  = replay_result;
    }

    return replay_result;
}

D3D12_CPU_DESCRIPTOR_HANDLE
Dx12ReplayConsumerBase::OverrideGetCPUDescriptorHandleForHeapStart(
    DxObjectInfo* replay_object_info, const Decoded_D3D12_CPU_DESCRIPTOR_HANDLE& original_result)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((replay_object_info != nullptr) && (replay_object_info->object != nullptr));

    auto replay_object = static_cast<ID3D12DescriptorHeap*>(replay_object_info->object);

    auto replay_result = replay_object->GetCPUDescriptorHandleForHeapStart();

    auto heap_info = GetExtraInfo<D3D12DescriptorHeapInfo>(replay_object_info);
    if (heap_info != nullptr)
    {
        // Only initialize on the first call.
        if (heap_info->replay_cpu_addr_begin == kNullCpuAddress)
        {
            heap_info->replay_cpu_addr_begin = replay_result.ptr;
        }
    }

    return replay_result;
}

D3D12_GPU_DESCRIPTOR_HANDLE
Dx12ReplayConsumerBase::OverrideGetGPUDescriptorHandleForHeapStart(
    DxObjectInfo* replay_object_info, const Decoded_D3D12_GPU_DESCRIPTOR_HANDLE& original_result)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((replay_object_info != nullptr) && (replay_object_info->object != nullptr));

    auto replay_object = static_cast<ID3D12DescriptorHeap*>(replay_object_info->object);

    auto replay_result = replay_object->GetGPUDescriptorHandleForHeapStart();

    auto heap_info = GetExtraInfo<D3D12DescriptorHeapInfo>(replay_object_info);
    if (heap_info != nullptr)
    {
        // Only initialize on the first call.
        if (heap_info->replay_gpu_addr_begin == kNullGpuAddress)
        {
            heap_info->capture_gpu_addr_begin = original_result.decoded_value->ptr;

            descriptor_map_.AddGpuDescriptorHeap(*original_result.decoded_value,
                                                 replay_result,
                                                 heap_info->descriptor_type,
                                                 heap_info->descriptor_count,
                                                 heap_info->capture_increments,
                                                 heap_info->replay_increments);

            if (resource_value_mapper_ != nullptr)
            {
                resource_value_mapper_->AddGpuDescriptorHeap(*original_result.decoded_value,
                                                             replay_result,
                                                             heap_info->descriptor_type,
                                                             heap_info->descriptor_count,
                                                             heap_info->capture_increments,
                                                             heap_info->replay_increments);
            }

            heap_info->replay_gpu_addr_begin = replay_result.ptr;
        }
    }

    return replay_result;
}

D3D12_GPU_VIRTUAL_ADDRESS
Dx12ReplayConsumerBase::OverrideGetGpuVirtualAddress(DxObjectInfo*             replay_object_info,
                                                     D3D12_GPU_VIRTUAL_ADDRESS original_result)
{
    assert((replay_object_info != nullptr) && (replay_object_info->object != nullptr));

    auto replay_object = static_cast<ID3D12Resource*>(replay_object_info->object);

    auto replay_result = replay_object->GetGPUVirtualAddress();

    if ((original_result != 0) && (replay_result != 0))
    {
        if (replay_object_info->extra_info == nullptr)
        {
            // Create resource info record on first use.
            replay_object_info->extra_info = std::make_unique<D3D12ResourceInfo>();
        }

        auto resource_info = GetExtraInfo<D3D12ResourceInfo>(replay_object_info);

        // Only initialize on the first call.
        if (resource_info->capture_address_ == 0)
        {
            resource_info->capture_address_ = original_result;
            resource_info->replay_address_  = replay_result;

            auto desc = replay_object->GetDesc();

            gpu_va_map_.Add(replay_object_info->capture_id, original_result, desc.Width, replay_result);

            if (resource_value_mapper_ != nullptr)
            {
                resource_value_mapper_->AddResourceGpuVa(
                    replay_object_info->capture_id, replay_result, desc.Width, original_result);
            }
        }
    }

    return replay_result;
}

HRESULT Dx12ReplayConsumerBase::OverrideCreatePipelineLibrary(DxObjectInfo*                replay_object_info,
                                                              HRESULT                      original_result,
                                                              PointerDecoder<uint8_t>*     library_blob,
                                                              SIZE_T                       blob_length,
                                                              Decoded_GUID                 riid,
                                                              HandlePointerDecoder<void*>* library)
{
    // The capture layer can skip this call and return an error code to make the application think that the library is
    // invalid and must be recreated.  Replay will also skip the call if it was intentionally failed by the capture
    // layer.
    if (original_result == D3D12_ERROR_DRIVER_VERSION_MISMATCH)
    {
        return original_result;
    }
    else
    {
        assert((replay_object_info != nullptr) && (replay_object_info->object != nullptr) &&
               (library_blob != nullptr) && (library != nullptr));

        auto replay_object = static_cast<ID3D12Device1*>(replay_object_info->object);
        return replay_object->CreatePipelineLibrary(
            library_blob->GetPointer(), blob_length, *riid.decoded_value, library->GetHandlePointer());
    }
}

HRESULT Dx12ReplayConsumerBase::OverrideEnqueueMakeResident(DxObjectInfo*                          replay_object_info,
                                                            HRESULT                                original_result,
                                                            D3D12_RESIDENCY_FLAGS                  flags,
                                                            UINT                                   num_objects,
                                                            HandlePointerDecoder<ID3D12Pageable*>* objects,
                                                            DxObjectInfo*                          fence_info,
                                                            UINT64                                 fence_value)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((replay_object_info != nullptr) && (replay_object_info->object != nullptr) && (objects != nullptr));

    auto         replay_object = static_cast<ID3D12Device3*>(replay_object_info->object);
    ID3D12Fence* fence         = nullptr;

    if (fence_info != nullptr)
    {
        fence = static_cast<ID3D12Fence*>(fence_info->object);
    }

    auto replay_result =
        replay_object->EnqueueMakeResident(flags, num_objects, objects->GetHandlePointer(), fence, fence_value);

    if (SUCCEEDED(replay_result))
    {
        ProcessFenceSignal(fence_info, fence_value);
    }

    return replay_result;
}

HRESULT
Dx12ReplayConsumerBase::Dx12ReplayConsumerBase::OverrideOpenExistingHeapFromAddress(DxObjectInfo* replay_object_info,
                                                                                    HRESULT       original_result,
                                                                                    uint64_t      allocation_id,
                                                                                    Decoded_GUID  riid,
                                                                                    HandlePointerDecoder<void*>* heap)
{
    assert((replay_object_info != nullptr) && (replay_object_info->object != nullptr) && (heap != nullptr));

    HRESULT result        = E_FAIL;
    auto    replay_object = static_cast<ID3D12Device3*>(replay_object_info->object);

    const auto& entry = heap_allocations_.find(allocation_id);
    if (entry != heap_allocations_.end())
    {
        assert(entry->second != nullptr);

        result =
            replay_object->OpenExistingHeapFromAddress(entry->second, *riid.decoded_value, heap->GetHandlePointer());

        if (SUCCEEDED(result))
        {
            // Transfer the allocation to the heap info record.
            auto heap_info                 = std::make_unique<D3D12HeapInfo>();
            heap_info->external_allocation = entry->second;

            SetExtraInfo(heap, std::move(heap_info));
        }
        else
        {
            // The allocation won't be used.
            VirtualFree(entry->second, 0, MEM_RELEASE);
        }

        heap_allocations_.erase(entry);
    }
    else
    {
        GFXRECON_LOG_FATAL("No heap allocation has been created for ID3D12Device3::OpenExistingHeapFromAddress "
                           "allocation ID = %" PRIu64,
                           allocation_id);
    }

    return result;
}

HRESULT Dx12ReplayConsumerBase::OverrideResourceMap(DxObjectInfo*                              replay_object_info,
                                                    HRESULT                                    original_result,
                                                    UINT                                       subresource,
                                                    StructPointerDecoder<Decoded_D3D12_RANGE>* read_range,
                                                    PointerDecoder<uint64_t, void*>*           data)
{
    // This function contains handling for two cases:
    // 1. data->GetOutputPointer() != null
    // 2. data->GetOutputPointer() == null
    assert((replay_object_info != nullptr) && (replay_object_info->object != nullptr) && (read_range != nullptr) &&
           (data != nullptr));

    auto id_pointer    = data->GetPointer();
    auto data_pointer  = data->GetOutputPointer();
    auto replay_object = static_cast<ID3D12Resource*>(replay_object_info->object);

    auto result = replay_object->Map(subresource, read_range->GetPointer(), data_pointer);
    if (data_pointer != nullptr)
    {
        // Handle first case, when data_pointer != null (like we've always done):
        if (SUCCEEDED(result) && (id_pointer != nullptr) && (*data_pointer != nullptr))
        {
            if (replay_object_info->extra_info == nullptr)
            {
                // Create resource info record on first use.
                replay_object_info->extra_info = std::make_unique<D3D12ResourceInfo>();
            }

            auto  resource_info   = GetExtraInfo<D3D12ResourceInfo>(replay_object_info);
            auto& memory_info     = resource_info->mapped_memory_info[subresource];
            memory_info.memory_id = *id_pointer;
            ++(memory_info.count);

            mapped_memory_[*id_pointer] = { *data_pointer, replay_object_info->capture_id };
        }
    }
    else
    {
        // Handle second case, when data_pointer == null
        //
        // Quote: "A null pointer is valid and is useful to cache a CPU virtual address range for methods like
        // WriteToSubresource."
        //
        // Source: https://docs.microsoft.com/en-us/windows/win32/api/d3d12/nf-d3d12-id3d12resource-map
        if (SUCCEEDED(result) && (id_pointer == nullptr))
        {
            if (replay_object_info->extra_info == nullptr)
            {
                // Create resource info record on first use.
                replay_object_info->extra_info = std::make_unique<D3D12ResourceInfo>();
            }
        }
    }

    return result;
}

void Dx12ReplayConsumerBase::OverrideResourceUnmap(DxObjectInfo*                              replay_object_info,
                                                   UINT                                       subresource,
                                                   StructPointerDecoder<Decoded_D3D12_RANGE>* written_range)
{
    assert((replay_object_info != nullptr) && (replay_object_info->object != nullptr) && (written_range != nullptr));

    auto replay_object = static_cast<ID3D12Resource*>(replay_object_info->object);

    auto resource_info = GetExtraInfo<D3D12ResourceInfo>(replay_object_info);
    if (resource_info != nullptr)
    {
        auto entry = resource_info->mapped_memory_info.find(subresource);
        if (entry != resource_info->mapped_memory_info.end())
        {
            auto& memory_info = entry->second;

            assert(memory_info.count > 0);

            --(memory_info.count);
            if (memory_info.count == 0)
            {
                mapped_memory_.erase(memory_info.memory_id);
                resource_info->mapped_memory_info.erase(entry);
            }
        }
    }

    replay_object->Unmap(subresource, written_range->GetPointer());
}

HRESULT
Dx12ReplayConsumerBase::OverrideWriteToSubresource(DxObjectInfo*                            replay_object_info,
                                                   HRESULT                                  original_result,
                                                   UINT                                     dst_subresource,
                                                   StructPointerDecoder<Decoded_D3D12_BOX>* dst_box,
                                                   void*                                    src_data,
                                                   UINT                                     src_row_pitch,
                                                   UINT                                     src_depth_pitch)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    GFXRECON_ASSERT((replay_object_info != nullptr) && (replay_object_info->object != nullptr));

    auto replay_object = static_cast<ID3D12Resource*>(replay_object_info->object);

    HRESULT result = E_FAIL;
    if (dst_box != nullptr)
    {
        result = replay_object->WriteToSubresource(
            dst_subresource, dst_box->GetPointer(), src_data, src_row_pitch, src_depth_pitch);
    }

    return result;
}

HRESULT
Dx12ReplayConsumerBase::OverrideReadFromSubresource(DxObjectInfo*                            replay_object_info,
                                                    HRESULT                                  original_result,
                                                    uint64_t                                 dst_data,
                                                    UINT                                     dst_row_pitch,
                                                    UINT                                     dst_depth_pitch,
                                                    UINT                                     src_subresource,
                                                    StructPointerDecoder<Decoded_D3D12_BOX>* src_box)
{
    GFXRECON_UNREFERENCED_PARAMETER(replay_object_info);
    GFXRECON_UNREFERENCED_PARAMETER(original_result);
    GFXRECON_UNREFERENCED_PARAMETER(dst_data);
    GFXRECON_UNREFERENCED_PARAMETER(dst_row_pitch);
    GFXRECON_UNREFERENCED_PARAMETER(dst_depth_pitch);
    GFXRECON_UNREFERENCED_PARAMETER(src_subresource);
    GFXRECON_UNREFERENCED_PARAMETER(src_box);

    // TODO: Implement function
    return E_FAIL;
}

void Dx12ReplayConsumerBase::OverrideExecuteCommandLists(DxObjectInfo*                             replay_object_info,
                                                         UINT                                      num_command_lists,
                                                         HandlePointerDecoder<ID3D12CommandList*>* command_lists)
{
    assert((replay_object_info != nullptr) && (replay_object_info->object != nullptr) && (command_lists != nullptr));

    auto replay_object = static_cast<ID3D12CommandQueue*>(replay_object_info->object);

    bool needs_mapping = false;
    if (resource_value_mapper_ != nullptr)
    {
        resource_value_mapper_->PreProcessExecuteCommandLists(
            replay_object_info, num_command_lists, command_lists, needs_mapping);
    }

    // Add a command queue signal and CPU wait after command list execution.
    bool do_sync_after_execute = options_.sync_queue_submissions && !command_lists->IsNull() && !needs_mapping;

    // TODO: Determine why a sync is required after executing commands lists that contain DispatchRays or
    // BuildRayTracingAccelerationStructures.
    // Check if the command list requires sync after mapping.
    // If resource value mapping is needed, it will sync after command lists execution, so we don't need to add an
    // extra sync here.
    if (!needs_mapping)
    {
        for (UINT i = 0; (i < num_command_lists) && !do_sync_after_execute; ++i)
        {
            auto command_list_extra_info =
                GetExtraInfo<D3D12CommandListInfo>(GetObjectInfo(command_lists->GetPointer()[i]));
            do_sync_after_execute = do_sync_after_execute || command_list_extra_info->requires_sync_after_execute;
        }
    }

    bool is_complete = false;
    if (options_.enable_dump_resources)
    {
        if (track_dump_resources_.target.execute_code_index == GetCurrentBlockIndex())
        {
            auto                            captured_command_lists = command_lists->GetHandlePointer();
            auto                            command_list_ids       = command_lists->GetPointer();
            std::vector<format::HandleId>   front_command_list_ids;
            std::vector<ID3D12CommandList*> modified_command_lists;

            for (uint32_t i = 0; i < num_command_lists; ++i)
            {
                front_command_list_ids.emplace_back(command_list_ids[i]);
                if (i == track_dump_resources_.target.dump_resources_target.command_index)
                {
                    is_complete = true;
                    modified_command_lists.emplace_back(track_dump_resources_.split_command_sets[0].list);

                    auto modified_num_command_lists = modified_command_lists.size();
                    replay_object->ExecuteCommandLists(modified_num_command_lists, modified_command_lists.data());
                    modified_command_lists.clear();

                    CopyResourcesForBeforeDrawcall(replay_object_info, front_command_list_ids);

                    ID3D12CommandList* ppCommandLists[] = { track_dump_resources_.split_command_sets[1].list };
                    replay_object->ExecuteCommandLists(1, ppCommandLists);

                    CopyResourcesForAfterDrawcall(replay_object_info, front_command_list_ids);

                    WriteDumpResources(replay_object_info);

                    modified_command_lists.emplace_back(track_dump_resources_.split_command_sets[2].list);
                }
                else
                {
                    modified_command_lists.emplace_back(captured_command_lists[i]);
                }
            }
            if (is_complete && !modified_command_lists.empty())
            {
                auto modified_num_command_lists = modified_command_lists.size();
                replay_object->ExecuteCommandLists(modified_num_command_lists, modified_command_lists.data());
            }
        }
    }
    if (!is_complete)
    {
        replay_object->ExecuteCommandLists(num_command_lists, command_lists->GetHandlePointer());
    }

    if (resource_value_mapper_ != nullptr)
    {
        resource_value_mapper_->PostProcessExecuteCommandLists(
            replay_object_info, num_command_lists, command_lists, needs_mapping);
    }

    if (do_sync_after_execute)
    {
        auto command_queue_info = GetExtraInfo<D3D12CommandQueueInfo>(replay_object_info);
        if (command_queue_info != nullptr)
        {
            auto sync_event = command_queue_info->sync_event;
            if (sync_event != nullptr)
            {
                auto& sync_fence = command_queue_info->sync_fence;

                replay_object->Signal(sync_fence, ++command_queue_info->sync_value);

                if (command_queue_info->pending_events.empty())
                {
                    // There are no outstanding waits on the queue, so the event can be waited on immediately.
                    WaitForCommandListExecution(command_queue_info, command_queue_info->sync_value);
                }
                else
                {
                    // There are outstanding waits on the queue.  The sync signal won't be processed until the
                    // outstanding waits are signaled, so the sync signal will be added to the pending operation queue.
                    command_queue_info->pending_events.push_back(CreateWaitForCommandListExecutionQueueSyncEvent(
                        command_queue_info, command_queue_info->sync_value));
                }
            }
            else
            {
                GFXRECON_LOG_ERROR("Failed to create synchronization event object for the replay --sync option");
            }
        }
    }
}

HRESULT Dx12ReplayConsumerBase::OverrideCommandQueueSignal(DxObjectInfo* replay_object_info,
                                                           HRESULT       original_result,
                                                           DxObjectInfo* fence_info,
                                                           UINT64        value)
{
    if (FAILED(original_result))
    {
        // Skip fence operations that failed at capture, in case they succeed on replay.
        GFXRECON_LOG_WARNING("Ignoring ID3D12CommandQueue::Signal operation that failed at capture with result %s",
                             enumutil::GetResultValueString(original_result).c_str());
        return original_result;
    }

    assert((replay_object_info != nullptr) && (replay_object_info->object != nullptr));

    auto         replay_object = static_cast<ID3D12CommandQueue*>(replay_object_info->object);
    ID3D12Fence* fence         = nullptr;

    if (fence_info != nullptr)
    {
        fence = static_cast<ID3D12Fence*>(fence_info->object);
    }

    auto replay_result = replay_object->Signal(fence, value);

    if (SUCCEEDED(replay_result))
    {
        ProcessQueueSignal(replay_object_info, fence_info, value);
    }

    return replay_result;
}

HRESULT Dx12ReplayConsumerBase::OverrideCommandQueueWait(DxObjectInfo* replay_object_info,
                                                         HRESULT       original_result,
                                                         DxObjectInfo* fence_info,
                                                         UINT64        value)
{
    if (FAILED(original_result))
    {
        // Skip fence operations that failed at capture, in case they succeed on replay.
        GFXRECON_LOG_WARNING("Ignoring ID3D12CommandQueue::Wait operation that failed at capture with result %s",
                             enumutil::GetResultValueString(original_result).c_str());
        return original_result;
    }

    assert((replay_object_info != nullptr) && (replay_object_info->object != nullptr));

    auto         replay_object = static_cast<ID3D12CommandQueue*>(replay_object_info->object);
    ID3D12Fence* fence         = nullptr;

    if (fence_info != nullptr)
    {
        fence = static_cast<ID3D12Fence*>(fence_info->object);
    }

    auto replay_result = replay_object->Wait(fence, value);

    if (SUCCEEDED(replay_result))
    {
        ProcessQueueWait(replay_object_info, fence_info, value);
    }

    return replay_result;
}

UINT64 Dx12ReplayConsumerBase::OverrideGetCompletedValue(DxObjectInfo* replay_object_info, UINT64 original_result)
{
    assert((replay_object_info != nullptr) && (replay_object_info->object != nullptr));

    auto replay_object = static_cast<ID3D12Fence*>(replay_object_info->object);
    auto replay_result = replay_object->GetCompletedValue();

    auto fence_info = GetExtraInfo<D3D12FenceInfo>(replay_object_info);
    if (fence_info != nullptr)
    {
        if (original_result > replay_result)
        {
            auto event_handle = GetEventObject(kInternalEventId, true);
            if (event_handle != nullptr)
            {
                replay_object->SetEventOnCompletion(original_result, event_handle);
                if (original_result <= fence_info->last_signaled_value)
                {
                    // The value has already been signaled, so wait operations can be processed immediately.
                    WaitForFenceEvent(replay_object_info->capture_id, event_handle);
                }
                else
                {
                    // The value has not been signaled, so process the wait operation when the value is signaled.
                    auto& waiting_objects = fence_info->waiting_objects[original_result];
                    waiting_objects.wait_events.push_back(event_handle);
                }
            }
        }
    }

    return original_result;
}

HRESULT Dx12ReplayConsumerBase::OverrideSetEventOnCompletion(DxObjectInfo* replay_object_info,
                                                             HRESULT       original_result,
                                                             UINT64        value,
                                                             uint64_t      event_id)
{
    if (FAILED(original_result))
    {
        // Skip fence operations that failed at capture, in case they succeed on replay.
        GFXRECON_LOG_WARNING(
            "Ignoring ID3D12Fence::SetEventOnCompletion operation that failed at capture with result %s",
            enumutil::GetResultValueString(original_result).c_str());
        return original_result;
    }

    assert((replay_object_info != nullptr) && (replay_object_info->object != nullptr));

    auto   replay_object = static_cast<ID3D12Fence*>(replay_object_info->object);
    HANDLE event_object  = GetEventObject(event_id, true);

    auto replay_result = replay_object->SetEventOnCompletion(value, event_object);

    if (SUCCEEDED(replay_result) && (event_object != nullptr))
    {
        auto fence_info = GetExtraInfo<D3D12FenceInfo>(replay_object_info);
        if (fence_info != nullptr)
        {
            if (value <= fence_info->last_signaled_value)
            {
                // The value has already been signaled, so wait operations can be processed immediately.
                WaitForFenceEvent(replay_object_info->capture_id, event_object);
            }
            else
            {
                // The value has not been signaled, so process the wait operation when the value is signaled.
                auto& waiting_objects = fence_info->waiting_objects[value];
                waiting_objects.wait_events.push_back(event_object);
            }
        }
    }

    return replay_result;
}

HRESULT
Dx12ReplayConsumerBase::OverrideFenceSignal(DxObjectInfo* replay_object_info, HRESULT original_result, UINT64 value)
{
    if (FAILED(original_result))
    {
        // Skip fence operations that failed at capture, in case they succeed on replay.
        GFXRECON_LOG_WARNING("Ignoring ID3D12Fence::Signal operation that failed at capture with result %s",
                             enumutil::GetResultValueString(original_result).c_str());
        return original_result;
    }

    assert((replay_object_info != nullptr) && (replay_object_info->object != nullptr));

    auto replay_object = static_cast<ID3D12Fence*>(replay_object_info->object);
    auto replay_result = replay_object->Signal(value);

    if (SUCCEEDED(replay_result))
    {
        ProcessFenceSignal(replay_object_info, value);
    }

    return replay_result;
}

HRESULT Dx12ReplayConsumerBase::OverrideGetBuffer(DxObjectInfo*                replay_object_info,
                                                  HRESULT                      original_result,
                                                  UINT                         buffer,
                                                  Decoded_GUID                 riid,
                                                  HandlePointerDecoder<void*>* surface)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((replay_object_info != nullptr) && (replay_object_info->object != nullptr) && (surface != nullptr));

    auto replay_object = static_cast<IDXGISwapChain*>(replay_object_info->object);
    auto replay_result = replay_object->GetBuffer(buffer, *riid.decoded_value, surface->GetHandlePointer());

    if (SUCCEEDED(replay_result) && !surface->IsNull())
    {
        auto swapchain_info = GetExtraInfo<DxgiSwapchainInfo>(replay_object_info);
        if (swapchain_info != nullptr)
        {
            GFXRECON_ASSERT(buffer < swapchain_info->image_ids.size());
            if (swapchain_info->image_ids[buffer] == format::kNullHandleId)
            {
                auto object_info              = static_cast<DxObjectInfo*>(surface->GetConsumerData(0));
                auto res                      = static_cast<ID3D12Resource*>(*surface->GetHandlePointer());
                auto extra_info               = std::make_unique<D3D12ResourceInfo>();
                extra_info->subresource_count = graphics::Dx12ResourceDataUtil::GetSubresourceCount(res);
                extra_info->resource_state_infos.resize(extra_info->subresource_count);
                for (auto& info : extra_info->resource_state_infos)
                {
                    info.states        = D3D12_RESOURCE_STATE_PRESENT;
                    info.barrier_flags = D3D12_RESOURCE_BARRIER_FLAG_NONE;
                }
                extra_info->swap_chain_id = replay_object_info->capture_id;
                SetExtraInfo(surface, std::move(extra_info));

                // Increment the replay reference to prevent the swapchain image info entry from being removed from the
                // object info table while the swapchain is active.
                ++object_info->extra_ref;

                // Store the surface's HandleId so the reference can be released later.
                swapchain_info->image_ids[buffer] = *surface->GetPointer();
            }
        }
    }

    return replay_result;
}

HRESULT Dx12ReplayConsumerBase::OverrideResizeBuffers(DxObjectInfo* replay_object_info,
                                                      HRESULT       original_result,
                                                      UINT          buffer_count,
                                                      UINT          width,
                                                      UINT          height,
                                                      DXGI_FORMAT   new_format,
                                                      UINT          flags)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((replay_object_info != nullptr) && (replay_object_info->object != nullptr));

    ReplaceWindowedResolution(width, height);

    auto replay_object = static_cast<IDXGISwapChain*>(replay_object_info->object);
    auto replay_result = replay_object->ResizeBuffers(buffer_count, width, height, new_format, flags);

    if (SUCCEEDED(replay_result))
    {
        ResetSwapchainImages(replay_object_info, buffer_count, width, height);
    }

    return replay_result;
}

HRESULT Dx12ReplayConsumerBase::OverrideResizeBuffers1(DxObjectInfo*                    replay_object_info,
                                                       HRESULT                          original_result,
                                                       UINT                             buffer_count,
                                                       UINT                             width,
                                                       UINT                             height,
                                                       DXGI_FORMAT                      new_format,
                                                       UINT                             flags,
                                                       PointerDecoder<UINT>*            node_mask,
                                                       HandlePointerDecoder<IUnknown*>* present_queue)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((replay_object_info != nullptr) && (replay_object_info->object != nullptr));

    ReplaceWindowedResolution(width, height);

    auto replay_object = static_cast<IDXGISwapChain3*>(replay_object_info->object);
    auto replay_result = replay_object->ResizeBuffers1(
        buffer_count, width, height, new_format, flags, node_mask->GetPointer(), present_queue->GetHandlePointer());

    if (SUCCEEDED(replay_result))
    {
        ResetSwapchainImages(replay_object_info, buffer_count, width, height);
    }

    return replay_result;
}

HRESULT Dx12ReplayConsumerBase::OverrideLoadGraphicsPipeline(
    DxObjectInfo*                                                     replay_object_info,
    HRESULT                                                           original_result,
    WStringDecoder*                                                   name,
    StructPointerDecoder<Decoded_D3D12_GRAPHICS_PIPELINE_STATE_DESC>* desc,
    Decoded_GUID                                                      riid,
    HandlePointerDecoder<void*>*                                      state)
{
    // The capture layer can skip this call and return an error code to make the application think that the library is
    // invalid and must be recreated.  Replay will also skip the call if it was intentionally failed by the capture
    // layer.
    if (original_result == E_INVALIDARG)
    {
        return original_result;
    }
    else
    {
        assert((replay_object_info != nullptr) && (replay_object_info->object != nullptr) && (name != nullptr) &&
               (desc != nullptr) && (desc->GetPointer() != nullptr) && (state != nullptr));

        auto desc2 = desc->GetPointer();
        if (!options_.use_cached_psos)
        {
            desc2->CachedPSO.pCachedBlob           = nullptr;
            desc2->CachedPSO.CachedBlobSizeInBytes = 0;
        }

        auto replay_object = static_cast<ID3D12PipelineLibrary*>(replay_object_info->object);
        return replay_object->LoadGraphicsPipeline(
            name->GetPointer(), desc2, *riid.decoded_value, state->GetHandlePointer());
    }
}

HRESULT Dx12ReplayConsumerBase::OverrideLoadComputePipeline(
    DxObjectInfo*                                                    replay_object_info,
    HRESULT                                                          original_result,
    WStringDecoder*                                                  name,
    StructPointerDecoder<Decoded_D3D12_COMPUTE_PIPELINE_STATE_DESC>* desc,
    Decoded_GUID                                                     riid,
    HandlePointerDecoder<void*>*                                     state)
{
    // The capture layer can skip this call and return an error code to make the application think that the library is
    // invalid and must be recreated.  Replay will also skip the call if it was intentionally failed by the capture
    // layer.
    if (original_result == E_INVALIDARG)
    {
        return original_result;
    }
    else
    {
        assert((replay_object_info != nullptr) && (replay_object_info->object != nullptr) && (name != nullptr) &&
               (desc != nullptr) && (desc->GetPointer() != nullptr) && (state != nullptr));

        auto desc2 = desc->GetPointer();
        if (!options_.use_cached_psos)
        {
            desc2->CachedPSO.pCachedBlob           = nullptr;
            desc2->CachedPSO.CachedBlobSizeInBytes = 0;
        }

        auto replay_object = static_cast<ID3D12PipelineLibrary*>(replay_object_info->object);
        return replay_object->LoadComputePipeline(
            name->GetPointer(), desc2, *riid.decoded_value, state->GetHandlePointer());
    }
}

HRESULT
Dx12ReplayConsumerBase::OverrideLoadPipeline(DxObjectInfo*   replay_object_info,
                                             HRESULT         original_result,
                                             WStringDecoder* name,
                                             StructPointerDecoder<Decoded_D3D12_PIPELINE_STATE_STREAM_DESC>* desc,
                                             Decoded_GUID                                                    riid,
                                             HandlePointerDecoder<void*>*                                    state)
{
    // The capture layer can skip this call and return an error code to make the application think that the library is
    // invalid and must be recreated.  Replay will also skip the call if it was intentionally failed by the capture
    // layer.
    if (original_result == E_INVALIDARG)
    {
        return original_result;
    }
    else
    {
        assert((replay_object_info != nullptr) && (replay_object_info->object != nullptr) && (name != nullptr) &&
               (desc != nullptr) && (desc->GetPointer() != nullptr) && (state != nullptr));

        auto replay_object = static_cast<ID3D12PipelineLibrary1*>(replay_object_info->object);
        return replay_object->LoadPipeline(
            name->GetPointer(), desc->GetPointer(), *riid.decoded_value, state->GetHandlePointer());
    }
}

void* Dx12ReplayConsumerBase::OverrideGetShaderIdentifier(DxObjectInfo*            replay_object_info,
                                                          PointerDecoder<uint8_t>* original_result,
                                                          WStringDecoder*          pExportName)
{
    assert((replay_object_info != nullptr) && (replay_object_info->object != nullptr));
    auto replay_object = static_cast<ID3D12StateObjectProperties*>(replay_object_info->object);
    auto new_shader_identifier_ptr =
        static_cast<uint8_t*>(replay_object->GetShaderIdentifier(pExportName->GetPointer()));

    if ((original_result != nullptr) && !original_result->IsNull() && (new_shader_identifier_ptr != nullptr))
    {
        shader_id_map_.Add(original_result->GetPointer(), new_shader_identifier_ptr);
    }

    return new_shader_identifier_ptr;
}

HRESULT Dx12ReplayConsumerBase::CreateSwapChainForHwnd(
    DxObjectInfo*                                                  replay_object_info,
    HRESULT                                                        original_result,
    DxObjectInfo*                                                  device_info,
    uint64_t                                                       hwnd_id,
    StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC1>*           desc,
    StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_FULLSCREEN_DESC>* full_screen_desc,
    DxObjectInfo*                                                  restrict_to_output_info,
    HandlePointerDecoder<IDXGISwapChain1*>*                        swapchain)
{
    assert(desc != nullptr);

    auto    desc_pointer   = desc->GetPointer();
    HRESULT result         = E_FAIL;
    Window* window         = nullptr;
    auto    wsi_context    = application_ ? application_->GetWsiContext("", true) : nullptr;
    auto    window_factory = wsi_context ? wsi_context->GetWindowFactory() : nullptr;

    if (window_factory != nullptr && desc_pointer != nullptr)
    {
        ReplaceWindowedResolution(desc_pointer->Width, desc_pointer->Height);
        window = window_factory->Create(
            kDefaultWindowPositionX, kDefaultWindowPositionY, desc_pointer->Width, desc_pointer->Height);
    }

    if (window != nullptr)
    {
        HWND hwnd{};
        if (window->GetNativeHandle(Window::kWin32HWnd, reinterpret_cast<void**>(&hwnd)))
        {
            assert((replay_object_info != nullptr) && (replay_object_info->object != nullptr) &&
                   (full_screen_desc != nullptr) && (swapchain != nullptr));

            auto         replay_object      = static_cast<IDXGIFactory2*>(replay_object_info->object);
            IUnknown*    device             = nullptr;
            IDXGIOutput* restrict_to_output = nullptr;

            if (device_info != nullptr)
            {
                device = device_info->object;
            }

            if (restrict_to_output_info != nullptr)
            {
                restrict_to_output = static_cast<IDXGIOutput*>(restrict_to_output_info->object);
            }

            auto full_screen_desc_ptr = full_screen_desc->GetPointer();
            if (options_.force_windowed)
            {
                full_screen_desc_ptr = nullptr;
            }
            result = replay_object->CreateSwapChainForHwnd(
                device, hwnd, desc_pointer, full_screen_desc_ptr, restrict_to_output, swapchain->GetHandlePointer());

            if (SUCCEEDED(result))
            {
                auto object_info = static_cast<DxObjectInfo*>(swapchain->GetConsumerData(0));
                SetSwapchainInfo(object_info,
                                 window,
                                 hwnd_id,
                                 hwnd,
                                 desc_pointer->BufferCount,
                                 device,
                                 (full_screen_desc_ptr == nullptr));
            }
            else
            {
                window_factory->Destroy(window);
            }
        }
        else
        {
            GFXRECON_LOG_FATAL("Failed to retrieve handle from window");
            window_factory->Destroy(window);
        }
    }
    else
    {
        GFXRECON_LOG_FATAL("Failed to create a window.  Replay cannot continue.");
    }

    return result;
}

void Dx12ReplayConsumerBase::SetSwapchainInfo(DxObjectInfo* info,
                                              Window*       window,
                                              uint64_t      hwnd_id,
                                              HWND          hwnd,
                                              uint32_t      image_count,
                                              IUnknown*     queue_iunknown,
                                              bool          windowed)
{
    if (window != nullptr)
    {
        if (info != nullptr)
        {
            assert(info->extra_info == nullptr);

            auto swapchain_info     = std::make_unique<DxgiSwapchainInfo>();
            swapchain_info->window  = window;
            swapchain_info->hwnd_id = hwnd_id;
            swapchain_info->image_ids.resize(image_count);
            std::fill(swapchain_info->image_ids.begin(), swapchain_info->image_ids.end(), format::kNullHandleId);

            // Get the ID3D12CommandQueue from the IUnknown queue object.
            HRESULT hr = queue_iunknown->QueryInterface(IID_PPV_ARGS(&swapchain_info->command_queue));
            if (FAILED(hr))
            {
                GFXRECON_LOG_WARNING("Failed to get the ID3D12CommandQueue interface from the IUnknown* device "
                                     "argument to CreateSwapChain.");
            }

            info->extra_info = std::move(swapchain_info);

            // Functions such as CreateSwapChainForCoreWindow and CreateSwapchainForComposition, which are mapped to
            // CreateSwapChainForHwnd for replay, won't have HWND IDs because they don't use HWND handles.
            if (hwnd_id != 0)
            {
                assert(hwnd != nullptr);
                window_handles_[hwnd_id] = hwnd;
            }
        }

        active_windows_.insert(window);
    }
}

void Dx12ReplayConsumerBase::ResetSwapchainImages(DxObjectInfo* info,
                                                  uint32_t      buffer_count,
                                                  uint32_t      width,
                                                  uint32_t      height)
{
    auto swapchain_info = GetExtraInfo<DxgiSwapchainInfo>(info);
    if (swapchain_info != nullptr)
    {
        // If ResizeBuffers is called with buffer_count == 0, the number of swapchain buffers doesn't change
        if (buffer_count == 0)
        {
            buffer_count = static_cast<uint32_t>(swapchain_info->image_ids.size());
        }

        // Clear the old info entries from the object info table and reset the swapchain info's image count.
        ReleaseSwapchainImages(swapchain_info);

        swapchain_info->image_ids.resize(buffer_count);
        std::fill(swapchain_info->image_ids.begin(), swapchain_info->image_ids.end(), format::kNullHandleId);

        // Resize the swapchain's window.
        swapchain_info->window->SetSize(width, height);
    }
}

void Dx12ReplayConsumerBase::ReleaseSwapchainImages(DxgiSwapchainInfo* info)
{
    if (info != nullptr)
    {
        for (auto image_id : info->image_ids)
        {
            auto image_info = GetObjectInfo(image_id);
            if ((image_info != nullptr) && (image_info->extra_ref > 0))
            {
                --(image_info->extra_ref);
                if ((image_info->ref_count == 0) && (image_info->extra_ref == 0))
                {
                    RemoveObject(image_info);
                }
            }
        }

        info->image_ids.clear();
    }
}

bool Dx12ReplayConsumerBase::WaitIdle(DWORD milliseconds)
{
    bool success = true;
    for (auto& entry : object_info_table_)
    {
        auto& info = entry.second;
        if (info.extra_info != nullptr)
        {
            auto extra_info = info.extra_info.get();
            if (extra_info->extra_info_type == DxObjectInfoType::kID3D12CommandQueueInfo)
            {
                auto queue_info = static_cast<D3D12CommandQueueInfo*>(extra_info);
                auto queue      = static_cast<ID3D12CommandQueue*>(info.object);
                auto sync_event = GetEventObject(kInternalEventId, true);

                if (sync_event != nullptr)
                {
                    if (queue_info->sync_fence == nullptr)
                    {
                        // Create a temporary fence to wait on the object.
                        // Get the parent device, create a fence, and wait on queue operations to complete.
                        graphics::dx12::ID3D12DeviceComPtr device;
                        if (SUCCEEDED(queue->GetDevice(IID_PPV_ARGS(&device))))
                        {
                            graphics::dx12::ID3D12FenceComPtr fence;
                            if (SUCCEEDED(device->CreateFence(0, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&fence))))
                            {
                                queue->Signal(fence, 1);
                                fence->SetEventOnCompletion(1, sync_event);
                                if (WaitForSingleObject(sync_event, milliseconds) != WAIT_OBJECT_0)
                                {
                                    success = false;
                                }
                            }
                        }
                    }
                    else
                    {
                        // The --sync option was specified, so the queue already has a fence for synchronization.
                        auto& sync_fence = queue_info->sync_fence;
                        queue->Signal(sync_fence, ++queue_info->sync_value);
                        sync_fence->SetEventOnCompletion(queue_info->sync_value, sync_event);
                        if (WaitForSingleObject(sync_event, milliseconds) != WAIT_OBJECT_0)
                        {
                            success = false;
                        }
                    }
                }
            }
        }
    }
    return success;
}

void Dx12ReplayConsumerBase::DestroyObjectExtraInfo(DxObjectInfo* info, bool release_extra_refs)
{
    if (info->extra_info != nullptr)
    {
        auto extra_info = info->extra_info.get();
        if (extra_info->extra_info_type == DxObjectInfoType::kID3D12ResourceInfo)
        {
            auto resource_info = static_cast<D3D12ResourceInfo*>(extra_info);

            if (resource_info->capture_address_ != 0)
            {
                GFXRECON_ASSERT(resource_info->replay_address_ != 0);

                gpu_va_map_.Remove(info->capture_id, resource_info->capture_address_);

                if (resource_value_mapper_ != nullptr)
                {
                    resource_value_mapper_->RemoveResourceGpuVa(
                        info->capture_id, resource_info->replay_address_, resource_info->capture_address_);
                }
            }

            for (const auto& entry : resource_info->mapped_memory_info)
            {
                auto& mapped_info = entry.second;
                mapped_memory_.erase(mapped_info.memory_id);
            }
        }
        else if (extra_info->extra_info_type == DxObjectInfoType::kID3D12CommandQueueInfo)
        {
            auto command_queue_info = static_cast<D3D12CommandQueueInfo*>(extra_info);
            if (command_queue_info->sync_event != nullptr)
            {
                CloseHandle(command_queue_info->sync_event);
            }
        }
        else if (extra_info->extra_info_type == DxObjectInfoType::kID3D12DescriptorHeapInfo)
        {
            auto heap_info = static_cast<D3D12DescriptorHeapInfo*>(extra_info);
            descriptor_map_.RemoveGpuDescriptorHeap(heap_info->capture_gpu_addr_begin);

            if (resource_value_mapper_ != nullptr)
            {
                resource_value_mapper_->RemoveGpuDescriptorHeap(heap_info->capture_gpu_addr_begin);
            }
        }
        else if (extra_info->extra_info_type == DxObjectInfoType::kID3D12HeapInfo)
        {
            auto heap_info = static_cast<D3D12HeapInfo*>(extra_info);

            if (heap_info->external_allocation != nullptr)
            {
                VirtualFree(heap_info->external_allocation, 0, MEM_RELEASE);
            }
        }
        else if (extra_info->extra_info_type == DxObjectInfoType::kIDxgiSwapchainInfo)
        {
            auto swapchain_info = static_cast<DxgiSwapchainInfo*>(extra_info);
            if (swapchain_info->is_fullscreen == true)
            {
                static_cast<IDXGISwapChain*>(info->object)->SetFullscreenState(false, nullptr);
            }

            if (release_extra_refs)
            {
                ReleaseSwapchainImages(swapchain_info);
            }
            auto wsi_context    = application_ ? application_->GetWsiContext("", true) : nullptr;
            auto window_factory = wsi_context ? wsi_context->GetWindowFactory() : nullptr;
            if (window_factory)
            {
                window_factory->Destroy(swapchain_info->window);
            }
            active_windows_.erase(swapchain_info->window);

            if (swapchain_info->hwnd_id != 0)
            {
                window_handles_.erase(swapchain_info->hwnd_id);
            }
        }

        info->extra_info.reset();
    }
}

void Dx12ReplayConsumerBase::DestroyActiveObjects()
{
    for (auto& entry : object_info_table_)
    {
        auto& info = entry.second;

        DestroyObjectExtraInfo(&info, false);

        // Release all of the replay tool's references to the object.
        for (uint32_t i = 0; i < info.ref_count; ++i)
        {
            info.object->Release();
        }
    }

    object_info_table_.clear();
}

void Dx12ReplayConsumerBase::DestroyActiveWindows()
{
    auto wsi_context    = application_ ? application_->GetWsiContext("", true) : nullptr;
    auto window_factory = wsi_context ? wsi_context->GetWindowFactory() : nullptr;
    if (window_factory)
    {
        for (auto window : active_windows_)
        {
            window_factory->Destroy(window);
        }
    }
    active_windows_.clear();
    window_handles_.clear();
}

void Dx12ReplayConsumerBase::DestroyActiveEvents()
{
    for (const auto& entry : event_objects_)
    {
        CloseHandle(entry.second);
    }

    event_objects_.clear();
}

void Dx12ReplayConsumerBase::DestroyHeapAllocations()
{
    for (const auto& entry : heap_allocations_)
    {
        VirtualFree(entry.second, 0, MEM_RELEASE);
    }

    heap_allocations_.clear();
}

void Dx12ReplayConsumerBase::ProcessQueueSignal(DxObjectInfo* queue_info, DxObjectInfo* fence_info, uint64_t value)
{
    auto queue_extra_info = GetExtraInfo<D3D12CommandQueueInfo>(queue_info);
    if (queue_extra_info != nullptr)
    {
        // If the queue is empty, there are no pending wait operations and the fence signal operation can be
        // processed immediately.
        if (queue_extra_info->pending_events.empty())
        {
            ProcessFenceSignal(fence_info, value);
        }
        else
        {
            // Add an entry for the signal operation to the queue, to be processed after any pending wait operations
            // complete.
            queue_extra_info->pending_events.push_back(CreateSignalQueueSyncEvent(fence_info, value));
        }
    }
}

void Dx12ReplayConsumerBase::ProcessQueueWait(DxObjectInfo* queue_info, DxObjectInfo* fence_info, uint64_t value)
{
    auto queue_extra_info = GetExtraInfo<D3D12CommandQueueInfo>(queue_info);
    auto fence_extra_info = GetExtraInfo<D3D12FenceInfo>(fence_info);
    if ((queue_extra_info != nullptr) && (fence_extra_info != nullptr))
    {
        // If the value has not already been signaled, a pending wait operation needs to be added to the queue.
        if (value > fence_extra_info->last_signaled_value)
        {
            // Add the an entry to the operation queue for the wait.  Signal operations that are added to the queue
            // after the wait entry will not be processed until after the wait is processed.
            queue_extra_info->pending_events.push_back(CreateWaitQueueSyncEvent(fence_info, value));

            // Add the pointer to the queue info structure to the fence's pending signal list so that the queue can
            // be notified when the fence receives a signal operation for the current value.
            auto& waiting_objects = fence_extra_info->waiting_objects[value];
            waiting_objects.wait_queues.push_back(queue_info);
        }
    }
}

void Dx12ReplayConsumerBase::ProcessFenceSignal(DxObjectInfo* info, uint64_t value)
{
    auto fence_info = GetExtraInfo<D3D12FenceInfo>(info);
    if (fence_info != nullptr)
    {
        // Process objects waiting for the fence's value up through the new value.
        fence_info->last_signaled_value = value;
        auto range_begin                = fence_info->waiting_objects.begin();
        auto range_end                  = fence_info->waiting_objects.upper_bound(value);
        if (range_begin != range_end)
        {
            while (range_begin != range_end)
            {
                auto waiting_objects = std::move(range_begin->second);
                fence_info->waiting_objects.erase(range_begin);
                for (auto event_object : waiting_objects.wait_events)
                {
                    WaitForFenceEvent(info->capture_id, event_object);
                }

                for (auto queue_info : waiting_objects.wait_queues)
                {
                    SignalWaitingQueue(queue_info, info, value);
                }
                range_begin = fence_info->waiting_objects.begin();
                range_end   = fence_info->waiting_objects.upper_bound(value);
            }
        }
    }
}

void Dx12ReplayConsumerBase::SignalWaitingQueue(DxObjectInfo* queue_info, DxObjectInfo* fence_info, uint64_t value)
{
    auto fence_extra_info = static_cast<D3D12FenceInfo*>(fence_info->extra_info.get());
    auto queue_extra_info = static_cast<D3D12CommandQueueInfo*>(queue_info->extra_info.get());
    if ((queue_extra_info != nullptr) && (fence_extra_info != nullptr))
    {
        // Process any pending entries in the wait queue until reaching a wait event with a value that is greater
        // than the specified value.
        auto& event_queue = queue_extra_info->pending_events;

        // Do a first pass of the queue entries, setting the outstanding wait entries for the current fence and
        // value to signaled.
        for (auto& entry : event_queue)
        {
            if (entry.is_wait && (entry.fence_info == fence_info) && (entry.value <= value))
            {
                entry.is_signaled = true;
            }
        }

        // Process entries in the queue until we encounter a wait operation that is not yet signaled.
        while (!event_queue.empty())
        {
            auto& front = event_queue.front();

            if (front.is_wait)
            {
                if (!front.is_signaled)
                {
                    break;
                }

                event_queue.pop_front();
            }
            else
            {
                auto event_function = std::move(front.event_function);
                event_queue.pop_front();
                event_function();
            }
        }
    }
}

HANDLE Dx12ReplayConsumerBase::GetEventObject(uint64_t event_id, bool reset)
{
    HANDLE event_object = nullptr;

    auto event_entry = event_objects_.find(event_id);
    if (event_entry != event_objects_.end())
    {
        event_object = event_entry->second;
        if (reset)
        {
            ResetEvent(event_object);
        }
    }
    else
    {
        event_object = CreateEventA(nullptr, TRUE, FALSE, nullptr);
        if (event_object != nullptr)
        {
            event_objects_[event_id] = event_object;
        }
        else
        {
            GFXRECON_LOG_FATAL("Event creation failed for ID3D12Fence::SetEventOnCompletion");
        }
    }

    return event_object;
}

void Dx12ReplayConsumerBase::WaitForFenceEvent(format::HandleId fence_id, HANDLE event_object)
{
    auto wait_result = WaitForSingleObject(event_object, kDefaultWaitTimeout);

    if (wait_result == WAIT_TIMEOUT)
    {
        GFXRECON_LOG_WARNING("Wait operation timed out for ID3D12Fence object %" PRId64 " synchronization", fence_id);
    }
    else if (FAILED(wait_result))
    {
        GFXRECON_LOG_WARNING("Wait operation failed with error 0x%x for ID3D12Fence object %" PRId64 " synchronization",
                             wait_result,
                             fence_id);
    }
}

void Dx12ReplayConsumerBase::SetDebugMsgFilter(std::vector<DXGI_INFO_QUEUE_MESSAGE_ID> denied_msgs,
                                               std::vector<DXGI_INFO_QUEUE_MESSAGE_ID> allowed_msgs)
{
    HRESULT                ok;
    UINT                   denied_filter_size  = static_cast<UINT>(denied_msgs.size());
    UINT                   allowed_filter_size = static_cast<UINT>(allowed_msgs.size());
    DXGI_INFO_QUEUE_FILTER filter              = {};
    if (denied_filter_size > 0)
    {
        filter.DenyList.NumIDs  = denied_filter_size;
        filter.DenyList.pIDList = &denied_msgs[0];
    }

    if (allowed_filter_size > 0)
    {
        filter.AllowList.NumIDs  = allowed_filter_size;
        filter.AllowList.pIDList = &allowed_msgs[0];
    }
    ok = info_queue_->AddRetrievalFilterEntries(DXGI_DEBUG_ALL, &filter);
    if (ok != S_OK)
    {
        GFXRECON_LOG_WARNING("Adding denied storage filter was not successful");
    }
}

void Dx12ReplayConsumerBase::ReadDebugMessages()
{
    if (info_queue_ == nullptr)
    {
        return;
    }

    auto   message_number = info_queue_->GetNumStoredMessagesAllowedByRetrievalFilters(DXGI_DEBUG_ALL);
    SIZE_T message_length = 0;

    for (auto i = 0; i < message_number; ++i)
    {
        info_queue_->GetMessage(DXGI_DEBUG_ALL, i, NULL, &message_length);
        if (message_length > current_message_length_)
        {
            debug_message_.reset();
            debug_message_          = std::make_unique<uint8_t[]>(message_length);
            current_message_length_ = message_length;
        }
        auto message = reinterpret_cast<DXGI_INFO_QUEUE_MESSAGE*>(debug_message_.get());
        auto hr      = info_queue_->GetMessage(DXGI_DEBUG_ALL, i, message, &message_length);

        switch (message->Severity)
        {
            case DXGI_INFO_QUEUE_MESSAGE_SEVERITY_CORRUPTION:
                GFXRECON_LOG_ERROR("D3D12 CORRUPTION: [ID %d] %s\n", message->ID, message->pDescription);
                break;
            case DXGI_INFO_QUEUE_MESSAGE_SEVERITY_ERROR:
                GFXRECON_LOG_ERROR("D3D12 ERROR: [ID %d] %s\n", message->ID, message->pDescription);
                break;
            case DXGI_INFO_QUEUE_MESSAGE_SEVERITY_WARNING:
                GFXRECON_LOG_WARNING("D3D12 WARNING: [ID %d] %s\n", message->ID, message->pDescription);
                break;
            case DXGI_INFO_QUEUE_MESSAGE_SEVERITY_INFO:
                GFXRECON_LOG_INFO("D3D12 INFO: [ID %d] %s\n", message->ID, message->pDescription);
                break;
            case DXGI_INFO_QUEUE_MESSAGE_SEVERITY_MESSAGE:
                GFXRECON_LOG_INFO("D3D12 MESSAGE: [ID %d] %s\n", message->ID, message->pDescription);
                break;
            default:
                break;
        }
    }
    info_queue_->ClearStoredMessages(DXGI_DEBUG_ALL);
}

void Dx12ReplayConsumerBase::InitializeScreenshotHandler()
{
    screenshot_file_prefix_ = options_.screenshot_file_prefix;
    if (screenshot_file_prefix_.empty())
    {
        screenshot_file_prefix_ = kDefaultScreenshotFilePrefix;
    }

    screenshot_format_ = options_.screenshot_format;

    if (!options_.screenshot_dir.empty())
    {
        screenshot_file_prefix_ = util::filepath::Join(options_.screenshot_dir, screenshot_file_prefix_);
    }
    screenshot_handler_ =
        std::make_unique<ScreenshotHandlerBase>(options_.screenshot_format, options_.screenshot_ranges);
}

void Dx12ReplayConsumerBase::Process_ID3D12Device_CheckFeatureSupport(format::HandleId object_id,
                                                                      HRESULT          original_result,
                                                                      D3D12_FEATURE    feature,
                                                                      const void*      capture_feature_data,
                                                                      void*            replay_feature_data,
                                                                      UINT             feature_data_size)
{
    GFXRECON_UNREFERENCED_PARAMETER(capture_feature_data);

    auto replay_object = MapObject<ID3D12Device>(object_id);

    if ((replay_object != nullptr) && (replay_feature_data != nullptr))
    {
        auto replay_result = replay_object->CheckFeatureSupport(feature, replay_feature_data, feature_data_size);
        CheckReplayResult("ID3D12Device::CheckFeatureSupport", original_result, replay_result);
    }
}

void Dx12ReplayConsumerBase::Process_IDXGIFactory5_CheckFeatureSupport(format::HandleId object_id,
                                                                       HRESULT          original_result,
                                                                       DXGI_FEATURE     feature,
                                                                       const void*      capture_feature_data,
                                                                       void*            replay_feature_data,
                                                                       UINT             feature_data_size)
{
    GFXRECON_UNREFERENCED_PARAMETER(capture_feature_data);

    auto replay_object = MapObject<IDXGIFactory5>(object_id);

    if ((replay_object != nullptr) && (replay_feature_data != nullptr))
    {
        auto replay_result = replay_object->CheckFeatureSupport(feature, replay_feature_data, feature_data_size);
        CheckReplayResult("IDXGIFactory5::CheckFeatureSupport", original_result, replay_result);
    }
}

void Dx12ReplayConsumerBase::Process_ID3D12Resource_WriteToSubresource(format::HandleId object_id,
                                                                       HRESULT          return_value,
                                                                       UINT             dst_subresource,
                                                                       StructPointerDecoder<Decoded_D3D12_BOX>* dst_box,
                                                                       void* src_data,
                                                                       UINT  src_row_pitch,
                                                                       UINT  src_depth_pitch)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        auto replay_result = OverrideWriteToSubresource(
            replay_object, return_value, dst_subresource, dst_box, src_data, src_row_pitch, src_depth_pitch);
        CheckReplayResult("ID3D12Resource_WriteToSubresource", return_value, replay_result);
    }
}

IDXGIAdapter* Dx12ReplayConsumerBase::GetAdapter()
{
    IDXGIAdapter* adapter_found = render_adapter_;

    if (options_.override_gpu_index >= 0)
    {
        for (const auto& adapter : adapters_)
        {
            if (adapter.second.adapter == adapter_found)
            {
                if (graphics::dx12::IsSoftwareAdapter(adapter.second.internal_desc) == true)
                {
                    GFXRECON_LOG_WARNING("The selected adapter is a software adapter. The replay may fail.")
                }
                break;
            }
        }
    }
    else
    {
        // User did not request a specific adapter, so try to find a HW one
        for (const auto& adapter : adapters_)
        {
            if (graphics::dx12::IsSoftwareAdapter(adapter.second.internal_desc) == false)
            {
                adapter_found = adapter.second.adapter;
                break;
            }
        }
        if (adapter_found == nullptr)
        {
            GFXRECON_LOG_WARNING("Could not find suitable HW adapter. The replay may fail.")
        }
    }

    return adapter_found;
}

void Dx12ReplayConsumerBase::RaiseFatalError(const char* message) const
{
    // TODO: Should there be a default action if no error handler has been provided?
    if (fatal_error_handler_ != nullptr)
    {
        fatal_error_handler_(message);
    }
}

// Helper to initialize the resource's D3D12ResourceInfo and set its is_reserved_resource = true.
static void SetIsReservedResource(HandlePointerDecoder<void*>* resource)
{
    auto resource_object_info = static_cast<DxObjectInfo*>(resource->GetConsumerData(0));

    GFXRECON_ASSERT(resource_object_info != nullptr);

    // This function is called from reserved resource creation, so extra_info should not exist yet.
    GFXRECON_ASSERT(resource_object_info->extra_info == nullptr);

    auto resource_info                  = std::make_unique<D3D12ResourceInfo>();
    resource_info->is_reserved_resource = true;
    resource_object_info->extra_info    = std::move(resource_info);
}

HRESULT Dx12ReplayConsumerBase::OverrideCreateReservedResource(
    DxObjectInfo*                                      device_object_info,
    HRESULT                                            original_result,
    StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>* desc,
    D3D12_RESOURCE_STATES                              initial_state,
    StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE>*   optimized_clear_value,
    Decoded_GUID                                       riid,
    HandlePointerDecoder<void*>*                       resource)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    GFXRECON_ASSERT(device_object_info != nullptr);
    GFXRECON_ASSERT(device_object_info->object != nullptr);

    auto    device        = static_cast<ID3D12Device*>(device_object_info->object);
    HRESULT replay_result = device->CreateReservedResource(desc->GetPointer(),
                                                           initial_state,
                                                           optimized_clear_value->GetPointer(),
                                                           *riid.decoded_value,
                                                           resource->GetHandlePointer());

    if (SUCCEEDED(replay_result))
    {
        SetIsReservedResource(resource);
    }

    return replay_result;
}

HRESULT Dx12ReplayConsumerBase::OverrideCreateReservedResource1(
    DxObjectInfo*                                      device_object_info,
    HRESULT                                            original_result,
    StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>* desc,
    D3D12_RESOURCE_STATES                              initial_state,
    StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE>*   optimized_clear_value,
    DxObjectInfo*                                      protected_session_object_info,
    Decoded_GUID                                       riid,
    HandlePointerDecoder<void*>*                       resource)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    GFXRECON_ASSERT(device_object_info != nullptr);
    GFXRECON_ASSERT(device_object_info->object != nullptr);

    auto                            device4           = static_cast<ID3D12Device4*>(device_object_info->object);
    ID3D12ProtectedResourceSession* protected_session = nullptr;
    if (protected_session_object_info != nullptr)
    {
        protected_session = static_cast<ID3D12ProtectedResourceSession*>(protected_session_object_info->object);
    }

    HRESULT replay_result = device4->CreateReservedResource1(desc->GetPointer(),
                                                             initial_state,
                                                             optimized_clear_value->GetPointer(),
                                                             protected_session,
                                                             *riid.decoded_value,
                                                             resource->GetHandlePointer());

    if (SUCCEEDED(replay_result))
    {
        SetIsReservedResource(resource);
    }

    return replay_result;
}

HRESULT Dx12ReplayConsumerBase::OverrideCreateReservedResource2(
    DxObjectInfo*                                      device_object_info,
    HRESULT                                            original_result,
    StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>* desc,
    D3D12_BARRIER_LAYOUT                               initial_layout,
    StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE>*   optimized_clear_value,
    DxObjectInfo*                                      protected_session_object_info,
    UINT32                                             num_castable_formats,
    PointerDecoder<DXGI_FORMAT>*                       castable_formats,
    Decoded_GUID                                       riid,
    HandlePointerDecoder<void*>*                       resource)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    GFXRECON_ASSERT(device_object_info != nullptr);
    GFXRECON_ASSERT(device_object_info->object != nullptr);

    auto                            device10          = static_cast<ID3D12Device10*>(device_object_info->object);
    ID3D12ProtectedResourceSession* protected_session = nullptr;
    if (protected_session_object_info != nullptr)
    {
        protected_session = static_cast<ID3D12ProtectedResourceSession*>(protected_session_object_info->object);
    }

    HRESULT replay_result = device10->CreateReservedResource2(desc->GetPointer(),
                                                              initial_layout,
                                                              optimized_clear_value->GetPointer(),
                                                              protected_session,
                                                              num_castable_formats,
                                                              castable_formats->GetPointer(),
                                                              *riid.decoded_value,
                                                              resource->GetHandlePointer());

    if (SUCCEEDED(replay_result))
    {
        SetIsReservedResource(resource);
    }

    return replay_result;
}

HRESULT Dx12ReplayConsumerBase::OverrideCreateGraphicsPipelineState(
    DxObjectInfo*                                                     device_object_info,
    HRESULT                                                           original_result,
    StructPointerDecoder<Decoded_D3D12_GRAPHICS_PIPELINE_STATE_DESC>* pDesc,
    Decoded_GUID                                                      riid,
    HandlePointerDecoder<void*>*                                      pipelineState)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    GFXRECON_ASSERT(device_object_info != nullptr);
    GFXRECON_ASSERT(device_object_info->object != nullptr);

    auto device = static_cast<ID3D12Device*>(device_object_info->object);

    auto pDesc2 = pDesc->GetPointer();
    if (!options_.use_cached_psos)
    {
        pDesc2->CachedPSO.pCachedBlob           = nullptr;
        pDesc2->CachedPSO.CachedBlobSizeInBytes = 0;
    }

    HRESULT replay_result =
        device->CreateGraphicsPipelineState(pDesc2, *riid.decoded_value, pipelineState->GetHandlePointer());

    return replay_result;
}

HRESULT Dx12ReplayConsumerBase::OverrideCreateComputePipelineState(
    DxObjectInfo*                                                    device_object_info,
    HRESULT                                                          original_result,
    StructPointerDecoder<Decoded_D3D12_COMPUTE_PIPELINE_STATE_DESC>* pDesc,
    Decoded_GUID                                                     riid,
    HandlePointerDecoder<void*>*                                     pipelineState)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    GFXRECON_ASSERT(device_object_info != nullptr);
    GFXRECON_ASSERT(device_object_info->object != nullptr);

    auto device = static_cast<ID3D12Device*>(device_object_info->object);

    auto pDesc2 = pDesc->GetPointer();
    if (!options_.use_cached_psos)
    {
        pDesc2->CachedPSO.pCachedBlob           = nullptr;
        pDesc2->CachedPSO.CachedBlobSizeInBytes = 0;
    }

    HRESULT replay_result =
        device->CreateComputePipelineState(pDesc2, *riid.decoded_value, pipelineState->GetHandlePointer());

    return replay_result;
}

HRESULT
Dx12ReplayConsumerBase::OverrideSetFullscreenState(DxObjectInfo* swapchain_info,
                                                   HRESULT       original_result,
                                                   BOOL          Fullscreen,
                                                   DxObjectInfo* pTarget)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);
    GFXRECON_ASSERT(swapchain_info != nullptr);
    GFXRECON_ASSERT(swapchain_info->object != nullptr);

    auto swapchain            = static_cast<IDXGISwapChain*>(swapchain_info->object);
    auto swapchain_extra_info = GetExtraInfo<DxgiSwapchainInfo>(swapchain_info);

    HRESULT replay_result = S_OK;
    if (options_.force_windowed)
    {
        replay_result                       = swapchain->SetFullscreenState(FALSE, nullptr);
        swapchain_extra_info->is_fullscreen = false;
    }
    else
    {
        IDXGIOutput* in_pTarget = nullptr;
        if (pTarget && pTarget->object)
        {
            in_pTarget = static_cast<IDXGIOutput*>(pTarget->object);
        }
        replay_result                       = swapchain->SetFullscreenState(Fullscreen, in_pTarget);
        swapchain_extra_info->is_fullscreen = Fullscreen;
        CheckReplayResult("IDXGISwapChain::SetFullscreenState", original_result, replay_result);
    }
    return replay_result;
}

HRESULT Dx12ReplayConsumerBase::OverrideCreateCommandList(DxObjectInfo*                device_object_info,
                                                          HRESULT                      original_result,
                                                          UINT                         node_mask,
                                                          D3D12_COMMAND_LIST_TYPE      type,
                                                          DxObjectInfo*                command_allocator_object_info,
                                                          DxObjectInfo*                initial_state_object_info,
                                                          Decoded_GUID                 riid,
                                                          HandlePointerDecoder<void*>* command_list_decoder)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    auto device            = static_cast<ID3D12Device*>(device_object_info->object);
    auto command_allocator = static_cast<ID3D12CommandAllocator*>(command_allocator_object_info->object);

    ID3D12PipelineState* initial_state = nullptr;
    if (initial_state_object_info != nullptr)
    {
        initial_state = static_cast<ID3D12PipelineState*>(initial_state_object_info->object);
    }

    auto replay_result = device->CreateCommandList(node_mask,
                                                   type,
                                                   command_allocator,
                                                   initial_state,
                                                   *riid.decoded_value,
                                                   command_list_decoder->GetHandlePointer());

    if (SUCCEEDED(replay_result) && !command_list_decoder->IsNull())
    {
        auto cmd_list_info              = std::make_unique<D3D12CommandListInfo>();
        cmd_list_info->create_list_type = type;
        SetExtraInfo(command_list_decoder, std::move(cmd_list_info));
    }
    return replay_result;
}

HRESULT Dx12ReplayConsumerBase::OverrideCreateCommandList1(DxObjectInfo*                device4_object_info,
                                                           HRESULT                      original_result,
                                                           UINT                         node_mask,
                                                           D3D12_COMMAND_LIST_TYPE      type,
                                                           D3D12_COMMAND_LIST_FLAGS     flags,
                                                           Decoded_GUID                 riid,
                                                           HandlePointerDecoder<void*>* command_list1_decoder)
{
    auto device4 = static_cast<ID3D12Device4*>(device4_object_info->object);

    auto replay_result = device4->CreateCommandList1(
        node_mask, type, flags, *riid.decoded_value, command_list1_decoder->GetHandlePointer());

    if (SUCCEEDED(replay_result) && !command_list1_decoder->IsNull())
    {
        auto cmd_list_info              = std::make_unique<D3D12CommandListInfo>();
        cmd_list_info->create_list_type = type;
        SetExtraInfo(command_list1_decoder, std::move(cmd_list_info));
    }
    return replay_result;
}

HRESULT Dx12ReplayConsumerBase::OverrideCommandListReset(DxObjectInfo* command_list_object_info,
                                                         HRESULT       original_result,
                                                         DxObjectInfo* allocator_object_info,
                                                         DxObjectInfo* initial_state_object_info)
{
    auto command_list = static_cast<ID3D12GraphicsCommandList*>(command_list_object_info->object);
    auto allocator    = static_cast<ID3D12CommandAllocator*>(allocator_object_info->object);

    ID3D12PipelineState* initial_state = nullptr;
    if (initial_state_object_info != nullptr)
    {
        initial_state = static_cast<ID3D12PipelineState*>(initial_state_object_info->object);
    }

    HRESULT replay_result = command_list->Reset(allocator, initial_state);

    auto dump_command_sets = GetCommandListsForDumpResources(command_list_object_info);
    for (auto& command_set : dump_command_sets)
    {
        command_set.list->Reset(command_set.allocator, initial_state);
    }

    auto command_list_extra_info                         = GetExtraInfo<D3D12CommandListInfo>(command_list_object_info);
    command_list_extra_info->requires_sync_after_execute = false;
    command_list_extra_info->pending_resource_states.clear();

    if (resource_value_mapper_ != nullptr)
    {
        resource_value_mapper_->PostProcessCommandListReset(command_list_object_info);
    }

    return replay_result;
}

void Dx12ReplayConsumerBase::OverrideCopyResource(DxObjectInfo* command_list_object_info,
                                                  DxObjectInfo* dst_resource_object_info,
                                                  DxObjectInfo* src_resource_object_info)
{
    auto command_list = static_cast<ID3D12GraphicsCommandList*>(command_list_object_info->object);
    auto dst_resource = static_cast<ID3D12Resource*>(dst_resource_object_info->object);
    auto src_resource = static_cast<ID3D12Resource*>(src_resource_object_info->object);
    command_list->CopyResource(dst_resource, src_resource);

    auto dump_command_sets = GetCommandListsForDumpResources(command_list_object_info);
    for (auto& command_set : dump_command_sets)
    {
        command_set.list->CopyResource(dst_resource, src_resource);
    }

    if (resource_value_mapper_ != nullptr)
    {
        resource_value_mapper_->PostProcessCopyResource(
            command_list_object_info, dst_resource_object_info, src_resource_object_info);
    }
}

void Dx12ReplayConsumerBase::OverrideCopyBufferRegion(DxObjectInfo* command_list_object_info,
                                                      DxObjectInfo* dst_buffer_object_info,
                                                      UINT64        dst_offset,
                                                      DxObjectInfo* src_buffer_object_info,
                                                      UINT64        src_offset,
                                                      UINT64        num_bytes)
{
    auto command_list = static_cast<ID3D12GraphicsCommandList*>(command_list_object_info->object);
    auto dst_buffer   = static_cast<ID3D12Resource*>(dst_buffer_object_info->object);
    auto src_buffer   = static_cast<ID3D12Resource*>(src_buffer_object_info->object);
    command_list->CopyBufferRegion(dst_buffer, dst_offset, src_buffer, src_offset, num_bytes);

    auto dump_command_sets = GetCommandListsForDumpResources(command_list_object_info);
    for (auto& command_set : dump_command_sets)
    {
        command_set.list->CopyBufferRegion(dst_buffer, dst_offset, src_buffer, src_offset, num_bytes);
    }

    if (resource_value_mapper_ != nullptr)
    {
        resource_value_mapper_->PostProcessCopyBufferRegion(command_list_object_info,
                                                            dst_buffer_object_info,
                                                            dst_offset,
                                                            src_buffer_object_info,
                                                            src_offset,
                                                            num_bytes);
    }
}

HRESULT
Dx12ReplayConsumerBase::OverrideCreateCommandSignature(
    DxObjectInfo*                                               device_object_info,
    HRESULT                                                     original_result,
    StructPointerDecoder<Decoded_D3D12_COMMAND_SIGNATURE_DESC>* desc_decoder,
    DxObjectInfo*                                               root_signature_object_info,
    Decoded_GUID                                                riid,
    HandlePointerDecoder<void*>*                                command_signature_decoder)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    auto        device = static_cast<ID3D12Device*>(device_object_info->object);
    const auto* desc   = desc_decoder->GetPointer();

    ID3D12RootSignature* root_signature = nullptr;
    if (root_signature_object_info != nullptr)
    {
        root_signature = static_cast<ID3D12RootSignature*>(root_signature_object_info->object);
    }

    auto replay_result = device->CreateCommandSignature(
        desc, root_signature, *riid.decoded_value, command_signature_decoder->GetHandlePointer());

    if (SUCCEEDED(replay_result) && !command_signature_decoder->IsNull())
    {
        SetExtraInfo(command_signature_decoder, std::make_unique<D3D12CommandSignatureInfo>());

        if (resource_value_mapper_ != nullptr)
        {
            resource_value_mapper_->PostProcessCreateCommandSignature(command_signature_decoder, desc);
        }
    }

    return replay_result;
}

void Dx12ReplayConsumerBase::OverrideExecuteIndirect(DxObjectInfo* command_list_object_info,
                                                     DxObjectInfo* command_signature_object_info,
                                                     UINT          max_command_count,
                                                     DxObjectInfo* argument_buffer_object_info,
                                                     UINT64        argument_buffer_offset,
                                                     DxObjectInfo* count_buffer_object_info,
                                                     UINT64        count_buffer_offset)
{
    auto command_list      = static_cast<ID3D12GraphicsCommandList*>(command_list_object_info->object);
    auto command_signature = static_cast<ID3D12CommandSignature*>(command_signature_object_info->object);
    auto argument_buffer   = static_cast<ID3D12Resource*>(argument_buffer_object_info->object);

    ID3D12Resource* count_buffer = nullptr;
    if (count_buffer_object_info != nullptr)
    {
        count_buffer = static_cast<ID3D12Resource*>(count_buffer_object_info->object);
    }

    command_list->ExecuteIndirect(command_signature,
                                  max_command_count,
                                  argument_buffer,
                                  argument_buffer_offset,
                                  count_buffer,
                                  count_buffer_offset);

    auto dump_command_sets = GetCommandListsForDumpResources(command_list_object_info);
    for (auto& command_set : dump_command_sets)
    {
        command_set.list->ExecuteIndirect(command_signature,
                                          max_command_count,
                                          argument_buffer,
                                          argument_buffer_offset,
                                          count_buffer,
                                          count_buffer_offset);
    }

    auto command_list_extra_info                         = GetExtraInfo<D3D12CommandListInfo>(command_list_object_info);
    command_list_extra_info->requires_sync_after_execute = true;

    if (resource_value_mapper_ != nullptr)
    {
        resource_value_mapper_->PostProcessExecuteIndirect(command_list_object_info,
                                                           command_signature_object_info,
                                                           max_command_count,
                                                           argument_buffer_object_info,
                                                           argument_buffer_offset,
                                                           count_buffer_object_info,
                                                           count_buffer_offset);
    }

    ei_workload_ = true;
}

void Dx12ReplayConsumerBase::OverrideBuildRaytracingAccelerationStructure(
    DxObjectInfo*                                                                     command_list4_object_info,
    StructPointerDecoder<Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC>* desc,
    UINT                                                                              num_post_build_info_descs,
    StructPointerDecoder<Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC>* post_build_info_descs)
{
    GFXRECON_ASSERT(command_list4_object_info != nullptr);
    GFXRECON_ASSERT(command_list4_object_info->object != nullptr);

    auto command_list4 = static_cast<ID3D12GraphicsCommandList4*>(command_list4_object_info->object);

    command_list4->BuildRaytracingAccelerationStructure(
        desc->GetPointer(), num_post_build_info_descs, post_build_info_descs->GetPointer());

    auto dump_command_sets = GetCommandListsForDumpResources(command_list4_object_info);
    for (auto& command_set : dump_command_sets)
    {
        ID3D12GraphicsCommandList4* command_list4;
        command_set.list->QueryInterface(IID_PPV_ARGS(&command_list4));
        command_list4->BuildRaytracingAccelerationStructure(
            desc->GetPointer(), num_post_build_info_descs, post_build_info_descs->GetPointer());
    }

    auto command_list_extra_info = GetExtraInfo<D3D12CommandListInfo>(command_list4_object_info);
    command_list_extra_info->requires_sync_after_execute = true;

    if (resource_value_mapper_ != nullptr)
    {
        resource_value_mapper_->PostProcessBuildRaytracingAccelerationStructure(command_list4_object_info, desc);
    }

    dxr_workload_ = true;
}

void Dx12ReplayConsumerBase::OverrideGetRaytracingAccelerationStructurePrebuildInfo(
    DxObjectInfo*                                                                        device5_object_info,
    StructPointerDecoder<Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS>*  desc_decoder,
    StructPointerDecoder<Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO>* info_decoder)
{
    auto device5 = static_cast<ID3D12Device5*>(device5_object_info->object);

    auto desc = desc_decoder->GetPointer();
    auto info = info_decoder->GetPointer();

    const UINT64 capture_result_data_max_size     = info->ResultDataMaxSizeInBytes;
    const UINT64 capture_scratch_data_size        = info->ScratchDataSizeInBytes;
    const UINT64 capture_update_scratch_data_size = info->UpdateScratchDataSizeInBytes;

    device5->GetRaytracingAccelerationStructurePrebuildInfo(desc, info);

    if (capture_result_data_max_size < info->ResultDataMaxSizeInBytes)
    {
        GFXRECON_LOG_WARNING_ONCE(
            "Detected different Acceleration Structure size requirements (ResultDataMaxSizeInBytes) "
            "between capture (%" PRIu64 ") and replay (%" PRIu64
            "). Please capture on the same driver; replay may fail.",
            capture_result_data_max_size,
            info->ResultDataMaxSizeInBytes);
    }

    if (capture_scratch_data_size < info->ScratchDataSizeInBytes)
    {
        GFXRECON_LOG_WARNING_ONCE(
            "Detected different Acceleration Structure size requirements (ScratchDataSizeInBytes) "
            "between capture (%" PRIu64 ") and replay (%" PRIu64
            "). Please capture on the same driver; replay may fail.",
            capture_scratch_data_size,
            info->ScratchDataSizeInBytes);
    }

    if (capture_update_scratch_data_size < info->UpdateScratchDataSizeInBytes)
    {
        GFXRECON_LOG_WARNING_ONCE("Detected different Acceleration Structure size requirements "
                                  "(UpdateScratchDataSizeInBytes) between capture (%" PRIu64 ") and replay (%" PRIu64
                                  "). Please capture on the same driver; replay may fail.",
                                  capture_update_scratch_data_size,
                                  info->UpdateScratchDataSizeInBytes);
    }
}

HRESULT Dx12ReplayConsumerBase::OverrideCreateRootSignature(DxObjectInfo*            device_object_info,
                                                            HRESULT                  original_result,
                                                            UINT                     node_mask,
                                                            PointerDecoder<uint8_t>* blob_with_root_signature_decoder,
                                                            SIZE_T                   blob_length_in_bytes,
                                                            Decoded_GUID             riid,
                                                            HandlePointerDecoder<void*>* root_signature_decoder)
{
    auto    device             = static_cast<ID3D12Device*>(device_object_info->object);
    auto    captured_signature = blob_with_root_signature_decoder->GetPointer();
    HRESULT replay_result      = E_UNEXPECTED;
    bool    is_complete        = false;
    if (options_.enable_dump_resources)
    {
        auto handld_id = *root_signature_decoder->GetPointer();
        if (track_dump_resources_.target.root_signature_handle_id == handld_id)
        {
            // DATA_STATIC causes error for ResourceBarrier. Change it to NONE.
            graphics::dx12::ID3D12VersionedRootSignatureDeserializerComPtr root_sig_deserializer{ nullptr };
            HRESULT result = D3D12CreateVersionedRootSignatureDeserializer(
                captured_signature, blob_length_in_bytes, IID_PPV_ARGS(&root_sig_deserializer));
            auto versioned_root_sig = root_sig_deserializer->GetUnconvertedRootSignatureDesc();

            D3D12_VERSIONED_ROOT_SIGNATURE_DESC modified_root_sig = *versioned_root_sig;
            if (modified_root_sig.Version == D3D_ROOT_SIGNATURE_VERSION_1_1 ||
                modified_root_sig.Version == D3D_ROOT_SIGNATURE_VERSION_1_2)
            {
                bool                                              is_modified = false;
                std::vector<D3D12_ROOT_PARAMETER1>                params;
                std::vector<std::vector<D3D12_DESCRIPTOR_RANGE1>> ranges;
                uint32_t                                          param_size = 0;
                if (modified_root_sig.Version == D3D_ROOT_SIGNATURE_VERSION_1_1)
                {
                    param_size = modified_root_sig.Desc_1_1.NumParameters;
                    params.resize(param_size);
                    std::memcpy(params.data(),
                                modified_root_sig.Desc_1_1.pParameters,
                                param_size * sizeof(D3D12_ROOT_PARAMETER1));
                }
                else if (modified_root_sig.Version == D3D_ROOT_SIGNATURE_VERSION_1_2)
                {
                    param_size = modified_root_sig.Desc_1_2.NumParameters;
                    params.resize(param_size);
                    std::memcpy(params.data(),
                                modified_root_sig.Desc_1_2.pParameters,
                                param_size * sizeof(D3D12_ROOT_PARAMETER1));
                }
                ranges.resize(param_size);

                for (uint32_t i = 0; i < param_size; ++i)
                {
                    switch (params[i].ParameterType)
                    {
                        case D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE:
                        {
                            auto range_size = params[i].DescriptorTable.NumDescriptorRanges;
                            ranges[i].resize(range_size);
                            std::memcpy(ranges[i].data(),
                                        params[i].DescriptorTable.pDescriptorRanges,
                                        range_size * sizeof(D3D12_DESCRIPTOR_RANGE1));
                            for (uint32_t j = 0; j < range_size; ++j)
                            {
                                if (ranges[i][j].Flags == D3D12_DESCRIPTOR_RANGE_FLAG_DATA_STATIC)
                                {
                                    ranges[i][j].Flags = D3D12_DESCRIPTOR_RANGE_FLAG_NONE;
                                    is_modified        = true;
                                }
                            }
                            params[i].DescriptorTable.pDescriptorRanges = ranges[i].data();
                            break;
                        }
                        default:
                            break;
                    }
                }
                if (is_modified)
                {
                    if (modified_root_sig.Version == D3D_ROOT_SIGNATURE_VERSION_1_1)
                    {
                        modified_root_sig.Desc_1_1.pParameters = params.data();
                    }
                    else if (modified_root_sig.Version == D3D_ROOT_SIGNATURE_VERSION_1_2)
                    {
                        modified_root_sig.Desc_1_2.pParameters = params.data();
                    }

                    ID3D10Blob* p_modified_blob       = nullptr;
                    ID3D10Blob* p_modified_error_blob = nullptr;
                    replay_result                     = D3D12SerializeVersionedRootSignature(
                        &modified_root_sig, &p_modified_blob, &p_modified_error_blob);

                    GFXRECON_ASSERT(SUCCEEDED(replay_result));

                    auto modified_size   = p_modified_blob->GetBufferSize();
                    auto modified_buffer = p_modified_blob->GetBufferPointer();

                    // TODO: This new signautre use NONE, instead of DATA_STATIC.
                    //       DATA_STATIC is optimization, so new signature might impact the performance.
                    //       It could create two root signatures. Keep original one and create new one.
                    //       The only target command llist use the new one. The others use the original one.
                    //       But if it has two root signatures, it also needs to have two PipeStates.
                    //       The target command list needs to use the new PipeStates for Create and Reset.
                    replay_result = device->CreateRootSignature(node_mask,
                                                                modified_buffer,
                                                                modified_size,
                                                                *riid.decoded_value,
                                                                root_signature_decoder->GetHandlePointer());
                    GFXRECON_ASSERT(SUCCEEDED(replay_result));
                    is_complete = true;
                }
            }
        }
    }

    if (!is_complete)
    {
        replay_result = device->CreateRootSignature(node_mask,
                                                    captured_signature,
                                                    blob_length_in_bytes,
                                                    *riid.decoded_value,
                                                    root_signature_decoder->GetHandlePointer());
    }

    if (SUCCEEDED(replay_result) && !root_signature_decoder->IsNull())
    {
        SetExtraInfo(root_signature_decoder, std::make_unique<D3D12RootSignatureInfo>());

        if (resource_value_mapper_ != nullptr)
        {
            // TODO: modified signature
            resource_value_mapper_->PostProcessCreateRootSignature(
                blob_with_root_signature_decoder, blob_length_in_bytes, root_signature_decoder);
        }
    }

    return replay_result;
}

HRESULT
Dx12ReplayConsumerBase::OverrideCreateStateObject(DxObjectInfo* device5_object_info,
                                                  HRESULT       original_result,
                                                  StructPointerDecoder<Decoded_D3D12_STATE_OBJECT_DESC>* desc_decoder,
                                                  Decoded_GUID                                           riid_decoder,
                                                  HandlePointerDecoder<void*>* state_object_decoder)
{
    auto device5 = static_cast<ID3D12Device5*>(device5_object_info->object);

    auto replay_result = device5->CreateStateObject(
        desc_decoder->GetPointer(), *riid_decoder.decoded_value, state_object_decoder->GetHandlePointer());

    if (SUCCEEDED(replay_result) && !state_object_decoder->IsNull())
    {
        SetExtraInfo(state_object_decoder, std::make_unique<D3D12StateObjectInfo>());

        if (resource_value_mapper_ != nullptr)
        {
            resource_value_mapper_->PostProcessCreateStateObject(state_object_decoder, desc_decoder, {});
        }
    }

    return replay_result;
}

HRESULT
Dx12ReplayConsumerBase::OverrideAddToStateObject(
    DxObjectInfo*                                          device7_object_info,
    HRESULT                                                original_result,
    StructPointerDecoder<Decoded_D3D12_STATE_OBJECT_DESC>* addition_decoder,
    DxObjectInfo*                                          state_object_to_grow_from_object_info,
    Decoded_GUID                                           riid_decoder,
    HandlePointerDecoder<void*>*                           new_state_object_decoder)
{
    GFXRECON_ASSERT(state_object_to_grow_from_object_info != nullptr);

    auto device7                   = static_cast<ID3D12Device7*>(device7_object_info->object);
    auto state_object_to_grow_from = static_cast<ID3D12StateObject*>(state_object_to_grow_from_object_info->object);

    auto replay_result = device7->AddToStateObject(addition_decoder->GetPointer(),
                                                   state_object_to_grow_from,
                                                   *riid_decoder.decoded_value,
                                                   new_state_object_decoder->GetHandlePointer());

    if (SUCCEEDED(replay_result) && !new_state_object_decoder->IsNull())
    {
        SetExtraInfo(new_state_object_decoder, std::make_unique<D3D12StateObjectInfo>());

        if (resource_value_mapper_ != nullptr)
        {
            auto state_object_to_grow_from_extra_info =
                GetExtraInfo<D3D12StateObjectInfo>(state_object_to_grow_from_object_info);
            resource_value_mapper_->PostProcessCreateStateObject(
                new_state_object_decoder, addition_decoder, state_object_to_grow_from_extra_info->export_name_lrs_map);
        }
    }

    return replay_result;
}

void Dx12ReplayConsumerBase::OverrideDispatchRays(DxObjectInfo* command_list4_object_info,
                                                  StructPointerDecoder<Decoded_D3D12_DISPATCH_RAYS_DESC>* desc_decoder)
{
    auto command_list4 = static_cast<ID3D12GraphicsCommandList4*>(command_list4_object_info->object);
    command_list4->DispatchRays(desc_decoder->GetPointer());

    auto dump_command_sets = GetCommandListsForDumpResources(command_list4_object_info);
    for (auto& command_set : dump_command_sets)
    {
        ID3D12GraphicsCommandList4* command_list4;
        command_set.list->QueryInterface(IID_PPV_ARGS(&command_list4));
        command_list4->DispatchRays(desc_decoder->GetPointer());
    }

    auto command_list_extra_info = GetExtraInfo<D3D12CommandListInfo>(command_list4_object_info);
    command_list_extra_info->requires_sync_after_execute = true;

    if (resource_value_mapper_ != nullptr)
    {
        resource_value_mapper_->PostProcessDispatchRays(command_list4_object_info, desc_decoder);
    }
}

void Dx12ReplayConsumerBase::OverrideSetPipelineState1(DxObjectInfo* command_list4_object_info,
                                                       DxObjectInfo* state_object_object_info)
{
    GFXRECON_ASSERT(state_object_object_info != nullptr);

    auto command_list4 = static_cast<ID3D12GraphicsCommandList4*>(command_list4_object_info->object);
    auto state_object  = static_cast<ID3D12StateObject*>(state_object_object_info->object);
    command_list4->SetPipelineState1(state_object);

    auto dump_command_sets = GetCommandListsForDumpResources(command_list4_object_info);
    for (auto& command_set : dump_command_sets)
    {
        ID3D12GraphicsCommandList4* command_list4;
        command_set.list->QueryInterface(IID_PPV_ARGS(&command_list4));
        command_list4->SetPipelineState1(state_object);
    }

    if (resource_value_mapper_ != nullptr)
    {
        resource_value_mapper_->PostProcessSetPipelineState1(command_list4_object_info, state_object_object_info);
    }
}

void Dx12ReplayConsumerBase::OverrideCopyTextureRegion(
    DxObjectInfo*                                              command_list_object_info,
    StructPointerDecoder<Decoded_D3D12_TEXTURE_COPY_LOCATION>* dst_decoder,
    UINT                                                       dst_x,
    UINT                                                       dst_y,
    UINT                                                       dst_z,
    StructPointerDecoder<Decoded_D3D12_TEXTURE_COPY_LOCATION>* src_decoder,
    StructPointerDecoder<Decoded_D3D12_BOX>*                   src_box_decoder)
{
    GFXRECON_ASSERT(command_list_object_info != nullptr);
    GFXRECON_ASSERT(command_list_object_info->object != nullptr);
    auto command_list = reinterpret_cast<ID3D12GraphicsCommandList*>(command_list_object_info->object);

    command_list->CopyTextureRegion(
        dst_decoder->GetPointer(), dst_x, dst_y, dst_z, src_decoder->GetPointer(), src_box_decoder->GetPointer());

    auto dump_command_sets = GetCommandListsForDumpResources(command_list_object_info);
    for (auto& command_set : dump_command_sets)
    {
        command_set.list->CopyTextureRegion(
            dst_decoder->GetPointer(), dst_x, dst_y, dst_z, src_decoder->GetPointer(), src_box_decoder->GetPointer());
    }

    if (resource_value_mapper_ != nullptr)
    {
        resource_value_mapper_->PostProcessCopyTextureRegion(
            command_list_object_info, dst_decoder, dst_x, dst_y, dst_z, src_decoder, src_box_decoder);
    }
}

void Dx12ReplayConsumerBase::OverrideIASetIndexBuffer(
    DxObjectInfo* command_list_object_info, StructPointerDecoder<Decoded_D3D12_INDEX_BUFFER_VIEW>* views_decoder)
{
    GFXRECON_ASSERT(command_list_object_info != nullptr);
    GFXRECON_ASSERT(command_list_object_info->object != nullptr);
    auto command_list = reinterpret_cast<ID3D12GraphicsCommandList*>(command_list_object_info->object);

    command_list->IASetIndexBuffer(views_decoder->GetPointer());

    auto dump_command_sets = GetCommandListsForDumpResources(command_list_object_info);
    for (auto& command_set : dump_command_sets)
    {
        command_set.list->IASetIndexBuffer(views_decoder->GetPointer());
    }

    if (resource_value_mapper_ != nullptr)
    {
        resource_value_mapper_->PostProcessIASetIndexBuffer(command_list_object_info, views_decoder);
    }
}

void Dx12ReplayConsumerBase::OverrideIASetVertexBuffers(
    DxObjectInfo*                                           command_list_object_info,
    UINT                                                    start_slot,
    UINT                                                    num_views,
    StructPointerDecoder<Decoded_D3D12_VERTEX_BUFFER_VIEW>* views_decoder)
{
    GFXRECON_ASSERT(command_list_object_info != nullptr);
    GFXRECON_ASSERT(command_list_object_info->object != nullptr);
    auto command_list = reinterpret_cast<ID3D12GraphicsCommandList*>(command_list_object_info->object);

    command_list->IASetVertexBuffers(start_slot, num_views, views_decoder->GetPointer());

    auto dump_command_sets = GetCommandListsForDumpResources(command_list_object_info);
    for (auto& command_set : dump_command_sets)
    {
        command_set.list->IASetVertexBuffers(start_slot, num_views, views_decoder->GetPointer());
    }

    if (resource_value_mapper_ != nullptr)
    {
        resource_value_mapper_->PostProcessIASetVertexBuffers(
            command_list_object_info, start_slot, num_views, views_decoder);
    }
}

void Dx12ReplayConsumerBase::WaitForCommandListExecution(D3D12CommandQueueInfo* queue_info, uint64_t value)
{
    GFXRECON_ASSERT(queue_info->sync_fence != nullptr);

    if (queue_info->sync_fence->GetCompletedValue() < value)
    {
        ResetEvent(queue_info->sync_event);
        queue_info->sync_fence->SetEventOnCompletion(value, queue_info->sync_event);
        WaitForSingleObject(queue_info->sync_event, INFINITE);
    }
}

QueueSyncEventInfo Dx12ReplayConsumerBase::CreateWaitQueueSyncEvent(DxObjectInfo* fence_info, uint64_t value)
{
    return QueueSyncEventInfo{ true, false, fence_info, value, []() {} };
}

QueueSyncEventInfo Dx12ReplayConsumerBase::CreateSignalQueueSyncEvent(DxObjectInfo* fence_info, uint64_t value)
{
    return QueueSyncEventInfo{ false, false, nullptr, 0, [this, fence_info, value]() {
                                  ProcessFenceSignal(fence_info, value);
                              } };
}

QueueSyncEventInfo
Dx12ReplayConsumerBase::CreateWaitForCommandListExecutionQueueSyncEvent(D3D12CommandQueueInfo* queue_info,
                                                                        uint64_t               value)
{
    return QueueSyncEventInfo{ false, false, nullptr, 0, [this, queue_info, value]() {
                                  WaitForCommandListExecution(queue_info, value);
                              } };
}

void Dx12ReplayConsumerBase::ApplyFillMemoryResourceValueCommand(uint64_t       offset,
                                                                 uint64_t       size,
                                                                 const uint8_t* data,
                                                                 uint8_t*       dst_resource_data_ptr)
{
    if (fill_memory_resource_value_info_.expected_block_index != 0)
    {
        if (fill_memory_resource_value_info_.expected_block_index == GetCurrentBlockIndex())
        {
            GFXRECON_ASSERT(fill_memory_resource_value_info_.types.size() ==
                            fill_memory_resource_value_info_.offsets.size())

            for (size_t i = 0; i < fill_memory_resource_value_info_.types.size(); ++i)
            {
                auto value_type   = fill_memory_resource_value_info_.types[i];
                auto value_offset = fill_memory_resource_value_info_.offsets[i];

                uint8_t*       dst_value_ptr = dst_resource_data_ptr + value_offset;
                const uint8_t* src_value_ptr = nullptr;

                if ((value_offset >= offset) && (value_offset + GetResourceValueSize(value_type) <= (offset + size)))
                {
                    // Use the incoming data as the source for mapping the value. This avoids possibly reading data
                    // from an upload buffer.
                    src_value_ptr = data + (value_offset - offset);
                }
                else
                {
                    // If the value was written by multiple fill memory commands (this fill memory command and
                    // any previous commands), then it needs to be read from the resource data.
                    src_value_ptr = dst_value_ptr;
                }

                switch (static_cast<uint8_t>(value_type))
                {
                    case 1:
                    {
                        MapGpuVirtualAddress(dst_value_ptr, src_value_ptr);
                        break;
                    }
                    case 2:
                    {
                        MapGpuDescriptorHandle(dst_value_ptr, src_value_ptr);
                        break;
                    }
                    case 3:
                    {
                        if (!shader_id_map_.Map(dst_value_ptr, src_value_ptr))
                        {
                            GFXRECON_LOG_WARNING_ONCE(
                                "Failed to map shader identifier for optimized DXR replay. Replay may fail.");
                        }
                        break;
                    }
                }
            }

            fill_memory_resource_value_info_.Clear();
        }
        else
        {
            GFXRECON_LOG_ERROR("Unexpected state found for the data required for optimized replay of DXR and/or "
                               "ExecuteIndirect commands. Replay may fail.");
        }
    }
}

void Dx12ReplayConsumerBase::PostReplay()
{
    if (ContainsDxrWorkload() || ContainsEiWorkload())
    {
        if (ContainsOptFillMem() == false)
        {
            GFXRECON_LOG_INFO_ONCE(
                "This capture contains DXR and/or ExecuteIndirect workloads, but has not been optimized.");
            GFXRECON_LOG_INFO_ONCE(
                "Use gfxrecon-optimize to obtain an optimized capture with improved playback performance.");
        }
    }
}

HRESULT
Dx12ReplayConsumerBase::OverrideSetName(DxObjectInfo* replay_object_info, HRESULT original_result, WStringDecoder* Name)
{
    GFXRECON_ASSERT(replay_object_info != nullptr);
    GFXRECON_ASSERT(replay_object_info->object != nullptr);

    HRESULT result = original_result;

    if (options_.override_object_names == false)
    {
        auto object = static_cast<ID3D12Device*>(replay_object_info->object);

        if (object != nullptr)
        {
            result = object->SetName(Name->GetPointer());
        }
    }

    return result;
}

std::wstring Dx12ReplayConsumerBase::ConstructObjectName(format::HandleId capture_id, format::ApiCallId call_id)
{
    std::wstring object_creator = util::GetDx12CallIdString(call_id);

    std::wstring constructed_name = L"gfxr_obj_";
    constructed_name.append(std::to_wstring(capture_id));
    constructed_name.append(L" (" + object_creator + L")");

    return constructed_name;
}

void Dx12ReplayConsumerBase::PreCall_ID3D12GraphicsCommandList_ResourceBarrier(
    const ApiCallInfo&                                    call_info,
    DxObjectInfo*                                         object_info,
    UINT                                                  NumBarriers,
    StructPointerDecoder<Decoded_D3D12_RESOURCE_BARRIER>* pBarriers)
{
    const auto command_list_id = object_info->capture_id;
    auto       extra_info      = GetExtraInfo<D3D12CommandListInfo>(GetObjectInfo(command_list_id));

    auto barriers = pBarriers->GetMetaStructPointer();
    for (uint32_t i = 0; i < NumBarriers; ++i)
    {
        if (barriers[i].decoded_value->Type == D3D12_RESOURCE_BARRIER_TYPE_TRANSITION)
        {
            // It shouldn't change the state here. It should save the AfterState until ExecuteCommandList to change
            // it. It needs to record the code index. The reason is that it needs to know if this ResourceBarrier is
            // before or after the target drawcall. For dump resources to set the correct state,
            // it only cares before the target drawcall.
            ResourceStatesOrder state;
            state.code_index    = call_info.index;
            state.transition    = *barriers[i].Transition->decoded_value;
            state.barrier_flags = barriers[i].decoded_value->Flags;

            auto it = extra_info->pending_resource_states.find(barriers[i].Transition->pResource);
            if (it == extra_info->pending_resource_states.end())
            {
                std::vector<ResourceStatesOrder> states;
                states.emplace_back(std::move(state));
                extra_info->pending_resource_states.insert(
                    std::pair(barriers[i].Transition->pResource, std::move(states)));
            }
            else
            {
                it->second.emplace_back(std::move(state));
            }
        }
    }
}

void Dx12ReplayConsumerBase::PreCall_ID3D12Device_CreateConstantBufferView(
    const ApiCallInfo&                                             call_info,
    DxObjectInfo*                                                  object_info,
    StructPointerDecoder<Decoded_D3D12_CONSTANT_BUFFER_VIEW_DESC>* pDesc,
    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE                            DestDescriptor)
{
    auto heap_object_info = GetObjectInfo(DestDescriptor.heap_id);
    auto heap_extra_info  = GetExtraInfo<D3D12DescriptorHeapInfo>(heap_object_info);
    auto desc             = pDesc->GetMetaStructPointer();

    ConstantBufferInfo info;
    info.captured_view = *(desc->decoded_value);

    heap_extra_info->constant_buffer_infos[DestDescriptor.index] = std::move(info);
}

void Dx12ReplayConsumerBase::PostCall_ID3D12Device_CreateConstantBufferView(
    const ApiCallInfo&                                             call_info,
    DxObjectInfo*                                                  object_info,
    StructPointerDecoder<Decoded_D3D12_CONSTANT_BUFFER_VIEW_DESC>* pDesc,
    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE                            DestDescriptor)
{
    auto heap_object_info = GetObjectInfo(DestDescriptor.heap_id);
    auto heap_extra_info  = GetExtraInfo<D3D12DescriptorHeapInfo>(heap_object_info);

    heap_extra_info->constant_buffer_infos[DestDescriptor.index].replay_handle = (*DestDescriptor.decoded_value);
}

std::vector<uint32_t> GetDescriptorSubresourceIndices(uint32_t first_mip_slice,
                                                      uint32_t mip_size,
                                                      uint32_t total_mip_count,
                                                      uint32_t first_array_slice,
                                                      uint32_t array_size,
                                                      uint32_t total_array_count,
                                                      uint32_t plane_slice)
{
    std::vector<uint32_t> result;
    for (UINT array_index = first_array_slice; array_index < (first_array_slice + array_size); ++array_index)
    {
        for (UINT mip_index = first_mip_slice; mip_index < (first_mip_slice + mip_size); ++mip_index)
        {
            result.push_back(mip_index + (array_index * total_mip_count) +
                             (plane_slice * total_mip_count * total_array_count));
        }
    }
    return result;
}

void Dx12ReplayConsumerBase::PostCall_ID3D12Device_CreateShaderResourceView(
    const ApiCallInfo&                                             call_info,
    DxObjectInfo*                                                  object_info,
    format::HandleId                                               pResource,
    StructPointerDecoder<Decoded_D3D12_SHADER_RESOURCE_VIEW_DESC>* pDesc,
    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE                            DestDescriptor)
{
    auto heap_object_info = GetObjectInfo(DestDescriptor.heap_id);
    auto heap_extra_info  = GetExtraInfo<D3D12DescriptorHeapInfo>(heap_object_info);

    ShaderResourceInfo info;
    info.resource_id   = pResource;
    info.replay_handle = *DestDescriptor.decoded_value;
    if (pDesc->IsNull())
    {
        info.is_view_null = true;
        info.subresource_indices.emplace_back(0);
    }
    else
    {
        info.view         = *(pDesc->GetMetaStructPointer()->decoded_value);
        info.is_view_null = false;

        if (pResource != format::kNullHandleId)
        {
            auto desc        = reinterpret_cast<ID3D12Resource*>(GetObjectInfo(pResource)->object)->GetDesc();
            auto mip_count   = desc.MipLevels;
            auto array_count = desc.DepthOrArraySize;
            switch (info.view.ViewDimension)
            {
                case D3D12_SRV_DIMENSION_BUFFER:
                    info.subresource_indices.emplace_back(0);
                    break;
                case D3D12_SRV_DIMENSION_TEXTURE1D:
                {
                    auto view     = info.view.Texture1D;
                    auto mip_size = view.MipLevels;
                    if (mip_size == -1)
                    {
                        mip_size = mip_count;
                    }
                    if (view.MostDetailedMip != 0)
                    {
                        if (mip_size == -1)
                        {
                            mip_size -= view.MostDetailedMip;
                        }
                        info.subresource_indices = GetDescriptorSubresourceIndices(
                            view.MostDetailedMip, mip_size, mip_count, 0, 1, array_count, 0);
                    }
                    else
                    {
                        mip_size -= view.MostDetailedMip;
                        info.subresource_indices = GetDescriptorSubresourceIndices(
                            view.ResourceMinLODClamp, mip_size, mip_count, 0, 1, array_count, 0);
                    }
                    break;
                }
                case D3D12_SRV_DIMENSION_TEXTURE1DARRAY:
                {
                    auto view     = info.view.Texture1DArray;
                    auto mip_size = view.MipLevels;
                    if (mip_size == -1)
                    {
                        mip_size = mip_count;
                    }
                    if (view.MostDetailedMip != 0)
                    {
                        if (mip_size == -1)
                        {
                            mip_size -= view.MostDetailedMip;
                        }
                        info.subresource_indices = GetDescriptorSubresourceIndices(view.MostDetailedMip,
                                                                                   mip_size,
                                                                                   mip_count,
                                                                                   view.FirstArraySlice,
                                                                                   view.ArraySize,
                                                                                   array_count,
                                                                                   0);
                    }
                    else
                    {
                        mip_size -= view.MostDetailedMip;
                        info.subresource_indices = GetDescriptorSubresourceIndices(view.ResourceMinLODClamp,
                                                                                   mip_size,
                                                                                   mip_count,
                                                                                   view.FirstArraySlice,
                                                                                   view.ArraySize,
                                                                                   array_count,
                                                                                   0);
                    }
                    break;
                }
                case D3D12_SRV_DIMENSION_TEXTURE2D:
                {
                    auto view     = info.view.Texture2D;
                    auto mip_size = view.MipLevels;
                    if (mip_size == -1)
                    {
                        mip_size = mip_count;
                    }
                    if (view.MostDetailedMip != 0)
                    {
                        if (mip_size == -1)
                        {
                            mip_size -= view.MostDetailedMip;
                        }
                        info.subresource_indices = GetDescriptorSubresourceIndices(
                            view.MostDetailedMip, mip_size, mip_count, 0, 1, array_count, view.PlaneSlice);
                    }
                    else
                    {
                        mip_size -= view.MostDetailedMip;
                        info.subresource_indices = GetDescriptorSubresourceIndices(
                            view.ResourceMinLODClamp, mip_size, mip_count, 0, 1, array_count, view.PlaneSlice);
                    }
                    break;
                }
                case D3D12_SRV_DIMENSION_TEXTURE2DARRAY:
                {
                    auto view     = info.view.Texture2DArray;
                    auto mip_size = view.MipLevels;
                    if (mip_size == -1)
                    {
                        mip_size = mip_count;
                    }
                    if (view.MostDetailedMip != 0)
                    {
                        if (mip_size == -1)
                        {
                            mip_size -= view.MostDetailedMip;
                        }
                        info.subresource_indices = GetDescriptorSubresourceIndices(view.MostDetailedMip,
                                                                                   mip_size,
                                                                                   mip_count,
                                                                                   view.FirstArraySlice,
                                                                                   view.ArraySize,
                                                                                   array_count,
                                                                                   view.PlaneSlice);
                    }
                    else
                    {
                        mip_size -= view.MostDetailedMip;
                        info.subresource_indices = GetDescriptorSubresourceIndices(view.ResourceMinLODClamp,
                                                                                   mip_size,
                                                                                   mip_count,
                                                                                   view.FirstArraySlice,
                                                                                   view.ArraySize,
                                                                                   array_count,
                                                                                   view.PlaneSlice);
                    }
                    break;
                }
                case D3D12_SRV_DIMENSION_TEXTURE2DMS:
                {
                    info.subresource_indices = GetDescriptorSubresourceIndices(0, 1, mip_count, 0, 1, array_count, 0);
                    break;
                }
                case D3D12_SRV_DIMENSION_TEXTURE2DMSARRAY:
                {
                    auto view                = info.view.Texture2DMSArray;
                    info.subresource_indices = GetDescriptorSubresourceIndices(
                        0, 1, mip_count, view.FirstArraySlice, view.ArraySize, array_count, 0);
                    break;
                }
                case D3D12_SRV_DIMENSION_TEXTURE3D:
                {
                    array_count   = 1;
                    auto view     = info.view.Texture3D;
                    auto mip_size = view.MipLevels;
                    if (mip_size == -1)
                    {
                        mip_size = mip_count;
                    }
                    if (view.MostDetailedMip != 0)
                    {
                        if (mip_size == -1)
                        {
                            mip_size -= view.MostDetailedMip;
                        }
                        info.subresource_indices = GetDescriptorSubresourceIndices(
                            view.MostDetailedMip, mip_size, mip_count, 0, 1, array_count, 0);
                    }
                    else
                    {
                        info.subresource_indices = GetDescriptorSubresourceIndices(
                            view.ResourceMinLODClamp, mip_size, mip_count, 0, 1, array_count, 0);
                    }
                    break;
                }
                case D3D12_SRV_DIMENSION_TEXTURECUBE:
                {
                    auto view     = info.view.TextureCube;
                    auto mip_size = view.MipLevels;
                    if (mip_size == -1)
                    {
                        mip_size = mip_count;
                    }
                    if (view.MostDetailedMip != 0)
                    {
                        if (mip_size == -1)
                        {
                            mip_size -= view.MostDetailedMip;
                        }
                        info.subresource_indices = GetDescriptorSubresourceIndices(
                            view.MostDetailedMip, mip_size, mip_count, 0, 1, array_count, 0);
                    }
                    else
                    {
                        info.subresource_indices = GetDescriptorSubresourceIndices(
                            view.ResourceMinLODClamp, mip_size, mip_count, 0, 1, array_count, 0);
                    }
                    break;
                }
                case D3D12_SRV_DIMENSION_TEXTURECUBEARRAY:
                {
                    auto view     = info.view.TextureCubeArray;
                    auto mip_size = view.MipLevels;
                    if (mip_size == -1)
                    {
                        mip_size = mip_count;
                    }
                    if (view.MostDetailedMip != 0)
                    {
                        if (mip_size == -1)
                        {
                            mip_size -= view.MostDetailedMip;
                        }
                        info.subresource_indices = GetDescriptorSubresourceIndices(view.MostDetailedMip,
                                                                                   mip_size,
                                                                                   mip_count,
                                                                                   view.First2DArrayFace,
                                                                                   view.NumCubes,
                                                                                   array_count,
                                                                                   0);
                    }
                    else
                    {
                        info.subresource_indices = GetDescriptorSubresourceIndices(view.ResourceMinLODClamp,
                                                                                   mip_size,
                                                                                   mip_count,
                                                                                   view.First2DArrayFace,
                                                                                   view.NumCubes,
                                                                                   array_count,
                                                                                   0);
                    }
                    break;
                }
                case D3D12_SRV_DIMENSION_UNKNOWN:
                default:
                    GFXRECON_LOG_ERROR("Unknown D3D12_SRV_DIMENSION_UNKNOWN.");
                    break;
            }
        }
    }
    heap_extra_info->shader_resource_infos[DestDescriptor.index] = std::move(info);
}

void Dx12ReplayConsumerBase::PostCall_ID3D12Device_CreateUnorderedAccessView(
    const ApiCallInfo&                                              call_info,
    DxObjectInfo*                                                   object_info,
    format::HandleId                                                pResource,
    format::HandleId                                                pCounterResource,
    StructPointerDecoder<Decoded_D3D12_UNORDERED_ACCESS_VIEW_DESC>* pDesc,
    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE                             DestDescriptor)
{
    auto heap_object_info = GetObjectInfo(DestDescriptor.heap_id);
    auto heap_extra_info  = GetExtraInfo<D3D12DescriptorHeapInfo>(heap_object_info);

    UnorderedAccessInfo info;
    info.resource_id         = pResource;
    info.counter_resource_id = pCounterResource;
    info.replay_handle       = *DestDescriptor.decoded_value;
    if (pDesc->IsNull())
    {
        info.is_view_null = true;
        info.subresource_indices.emplace_back(0);
    }
    else
    {
        info.view         = *(pDesc->GetMetaStructPointer()->decoded_value);
        info.is_view_null = false;

        if (pResource != format::kNullHandleId)
        {
            auto desc        = reinterpret_cast<ID3D12Resource*>(GetObjectInfo(pResource)->object)->GetDesc();
            auto mip_count   = desc.MipLevels;
            auto array_count = desc.DepthOrArraySize;
            switch (info.view.ViewDimension)
            {
                case D3D12_UAV_DIMENSION_BUFFER:
                    info.subresource_indices.emplace_back(0);
                    break;
                case D3D12_UAV_DIMENSION_TEXTURE1D:
                    info.subresource_indices = GetDescriptorSubresourceIndices(
                        info.view.Texture1D.MipSlice, 1, mip_count, 0, 1, array_count, 0);
                    break;
                case D3D12_UAV_DIMENSION_TEXTURE1DARRAY:
                    info.subresource_indices = GetDescriptorSubresourceIndices(info.view.Texture1DArray.MipSlice,
                                                                               1,
                                                                               mip_count,
                                                                               info.view.Texture1DArray.FirstArraySlice,
                                                                               info.view.Texture1DArray.ArraySize,
                                                                               array_count,
                                                                               0);
                    break;
                case D3D12_UAV_DIMENSION_TEXTURE2D:
                    info.subresource_indices = GetDescriptorSubresourceIndices(
                        info.view.Texture2D.MipSlice, 1, mip_count, 0, 1, array_count, info.view.Texture2D.PlaneSlice);
                    break;
                case D3D12_UAV_DIMENSION_TEXTURE2DARRAY:
                    info.subresource_indices = GetDescriptorSubresourceIndices(info.view.Texture2DArray.MipSlice,
                                                                               1,
                                                                               mip_count,
                                                                               info.view.Texture2DArray.FirstArraySlice,
                                                                               info.view.Texture2DArray.ArraySize,
                                                                               array_count,
                                                                               info.view.Texture2DArray.PlaneSlice);
                    break;
                case D3D12_UAV_DIMENSION_TEXTURE2DMS:
                    info.subresource_indices = GetDescriptorSubresourceIndices(0, 1, mip_count, 0, 1, array_count, 0);
                    break;
                case D3D12_UAV_DIMENSION_TEXTURE2DMSARRAY:
                    info.subresource_indices =
                        GetDescriptorSubresourceIndices(0,
                                                        1,
                                                        mip_count,
                                                        info.view.Texture2DMSArray.FirstArraySlice,
                                                        info.view.Texture2DMSArray.ArraySize,
                                                        array_count,
                                                        0);
                    break;
                case D3D12_UAV_DIMENSION_TEXTURE3D:
                {
                    // DUMPTODO: handle FirstWSlice and WSize
                    info.subresource_indices =
                        GetDescriptorSubresourceIndices(info.view.Texture3D.MipSlice, 1, mip_count, 0, 1, 1, 0);
                    break;
                }
                case D3D12_UAV_DIMENSION_UNKNOWN:
                default:
                    GFXRECON_LOG_ERROR("Unknown D3D12_UAV_DIMENSION_UNKNOWN.");
                    break;
            }
        }
    }
    heap_extra_info->unordered_access_infos[DestDescriptor.index] = std::move(info);
}

void Dx12ReplayConsumerBase::PostCall_ID3D12Device_CreateRenderTargetView(
    const ApiCallInfo&                                           call_info,
    DxObjectInfo*                                                object_info,
    format::HandleId                                             pResource,
    StructPointerDecoder<Decoded_D3D12_RENDER_TARGET_VIEW_DESC>* pDesc,
    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE                          DestDescriptor)
{
    auto heap_object_info = GetObjectInfo(DestDescriptor.heap_id);
    auto heap_extra_info  = GetExtraInfo<D3D12DescriptorHeapInfo>(heap_object_info);

    RenderTargetInfo info;
    info.resource_id   = pResource;
    info.replay_handle = *DestDescriptor.decoded_value;
    if (pDesc->IsNull())
    {
        info.is_view_null = true;
        info.subresource_indices.emplace_back(0);
    }
    else
    {
        info.view         = *(pDesc->GetMetaStructPointer()->decoded_value);
        info.is_view_null = false;

        if (pResource != format::kNullHandleId)
        {
            auto desc        = reinterpret_cast<ID3D12Resource*>(GetObjectInfo(pResource)->object)->GetDesc();
            auto mip_count   = desc.MipLevels;
            auto array_count = desc.DepthOrArraySize;
            switch (info.view.ViewDimension)
            {
                case D3D12_RTV_DIMENSION_BUFFER:
                    info.subresource_indices.emplace_back(0);
                    break;
                case D3D12_RTV_DIMENSION_TEXTURE1D:
                    info.subresource_indices = GetDescriptorSubresourceIndices(
                        info.view.Texture1D.MipSlice, 1, mip_count, 0, 1, array_count, 0);
                    break;
                case D3D12_RTV_DIMENSION_TEXTURE1DARRAY:
                    info.subresource_indices = GetDescriptorSubresourceIndices(info.view.Texture1DArray.MipSlice,
                                                                               1,
                                                                               mip_count,
                                                                               info.view.Texture1DArray.FirstArraySlice,
                                                                               info.view.Texture1DArray.ArraySize,
                                                                               array_count,
                                                                               0);
                    break;
                case D3D12_RTV_DIMENSION_TEXTURE2D:
                    info.subresource_indices = GetDescriptorSubresourceIndices(
                        info.view.Texture2D.MipSlice, 1, mip_count, 0, 1, array_count, info.view.Texture2D.PlaneSlice);
                    break;
                case D3D12_RTV_DIMENSION_TEXTURE2DARRAY:
                    info.subresource_indices = GetDescriptorSubresourceIndices(info.view.Texture2DArray.MipSlice,
                                                                               1,
                                                                               mip_count,
                                                                               info.view.Texture2DArray.FirstArraySlice,
                                                                               info.view.Texture2DArray.ArraySize,
                                                                               array_count,
                                                                               info.view.Texture2DArray.PlaneSlice);
                    break;
                case D3D12_RTV_DIMENSION_TEXTURE2DMS:
                    info.subresource_indices = GetDescriptorSubresourceIndices(0, 1, mip_count, 0, 1, array_count, 0);
                    break;
                case D3D12_RTV_DIMENSION_TEXTURE2DMSARRAY:
                    info.subresource_indices =
                        GetDescriptorSubresourceIndices(0,
                                                        1,
                                                        mip_count,
                                                        info.view.Texture2DMSArray.FirstArraySlice,
                                                        info.view.Texture2DMSArray.ArraySize,
                                                        array_count,
                                                        0);
                    break;
                case D3D12_RTV_DIMENSION_TEXTURE3D:
                {
                    // DUMPTODO: Handle FirstWSlice and WSize
                    info.subresource_indices =
                        GetDescriptorSubresourceIndices(info.view.Texture3D.MipSlice, 1, mip_count, 0, 1, 1, 0);
                    break;
                }
                case D3D12_RTV_DIMENSION_UNKNOWN:
                default:
                    GFXRECON_LOG_ERROR("Unknown D3D12_RTV_DIMENSION_UNKNOWN.");
                    break;
            }
        }
    }
    heap_extra_info->render_target_infos[DestDescriptor.index] = std::move(info);
}

void Dx12ReplayConsumerBase::PostCall_ID3D12Device_CreateDepthStencilView(
    const ApiCallInfo&                                           call_info,
    DxObjectInfo*                                                object_info,
    format::HandleId                                             pResource,
    StructPointerDecoder<Decoded_D3D12_DEPTH_STENCIL_VIEW_DESC>* pDesc,
    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE                          DestDescriptor)
{
    auto heap_object_info = GetObjectInfo(DestDescriptor.heap_id);
    auto heap_extra_info  = GetExtraInfo<D3D12DescriptorHeapInfo>(heap_object_info);

    DepthStencilInfo info;
    info.resource_id   = pResource;
    info.replay_handle = *DestDescriptor.decoded_value;
    if (pDesc->IsNull())
    {
        info.is_view_null = true;
        info.subresource_indices.emplace_back(0);
    }
    else
    {
        info.view         = *(pDesc->GetMetaStructPointer()->decoded_value);
        info.is_view_null = false;

        if (pResource != format::kNullHandleId)
        {
            auto desc        = reinterpret_cast<ID3D12Resource*>(GetObjectInfo(pResource)->object)->GetDesc();
            auto mip_count   = desc.MipLevels;
            auto array_count = desc.DepthOrArraySize;
            switch (info.view.ViewDimension)
            {
                case D3D12_DSV_DIMENSION_TEXTURE1D:
                    info.subresource_indices = GetDescriptorSubresourceIndices(
                        info.view.Texture1D.MipSlice, 1, mip_count, 0, 1, array_count, 0);
                    break;
                case D3D12_DSV_DIMENSION_TEXTURE1DARRAY:
                    info.subresource_indices = GetDescriptorSubresourceIndices(info.view.Texture1DArray.MipSlice,
                                                                               1,
                                                                               mip_count,
                                                                               info.view.Texture1DArray.FirstArraySlice,
                                                                               info.view.Texture1DArray.ArraySize,
                                                                               array_count,
                                                                               0);
                    break;
                case D3D12_DSV_DIMENSION_TEXTURE2D:
                    info.subresource_indices = GetDescriptorSubresourceIndices(
                        info.view.Texture2D.MipSlice, 1, mip_count, 0, 1, array_count, 0);
                    break;
                case D3D12_DSV_DIMENSION_TEXTURE2DARRAY:
                    info.subresource_indices = GetDescriptorSubresourceIndices(info.view.Texture2DArray.MipSlice,
                                                                               1,
                                                                               mip_count,
                                                                               info.view.Texture2DArray.FirstArraySlice,
                                                                               info.view.Texture2DArray.ArraySize,
                                                                               array_count,
                                                                               0);
                    break;
                case D3D12_DSV_DIMENSION_TEXTURE2DMS:
                    info.subresource_indices = GetDescriptorSubresourceIndices(0, 1, mip_count, 0, 1, array_count, 0);
                    break;
                case D3D12_DSV_DIMENSION_TEXTURE2DMSARRAY:
                    info.subresource_indices =
                        GetDescriptorSubresourceIndices(0,
                                                        1,
                                                        mip_count,
                                                        info.view.Texture2DMSArray.FirstArraySlice,
                                                        info.view.Texture2DMSArray.ArraySize,
                                                        array_count,
                                                        0);
                    break;
                case D3D12_DSV_DIMENSION_UNKNOWN:
                default:
                    GFXRECON_LOG_ERROR("Unknown D3D12_DSV_DIMENSION.");
                    break;
            }
        }
    }
    heap_extra_info->depth_stencil_infos[DestDescriptor.index] = std::move(info);
}

void Dx12ReplayConsumerBase::PostCall_ID3D12GraphicsCommandList_OMSetRenderTargets(
    const ApiCallInfo&                                         call_info,
    DxObjectInfo*                                              object_info,
    UINT                                                       NumRenderTargetDescriptors,
    StructPointerDecoder<Decoded_D3D12_CPU_DESCRIPTOR_HANDLE>* pRenderTargetDescriptors,
    BOOL                                                       RTsSingleHandleToDescriptorRange,
    StructPointerDecoder<Decoded_D3D12_CPU_DESCRIPTOR_HANDLE>* pDepthStencilDescriptor)
{
    if (call_info.index == track_dump_resources_.target.set_render_targets_code_index)
    {
        auto descriptor_increment = 0;
        if (RTsSingleHandleToDescriptorRange)
        {
            // Determine descriptor increment for contiguous render target descriptors.
            auto cmd_list = reinterpret_cast<ID3D12GraphicsCommandList*>(object_info->object);
            auto device   = graphics::dx12::GetDeviceComPtrFromChild<ID3D12Device>(cmd_list);
            if (device != nullptr)
            {
                descriptor_increment = device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);
            }
            else
            {
                GFXRECON_LOG_ERROR("Failed to get Device for GetDescriptorHandleIncrementSize in OMSetRenderTargets.");
            }
        }

        auto rt_handles = pRenderTargetDescriptors->GetMetaStructPointer();
        track_dump_resources_.render_target_heap_ids.resize(NumRenderTargetDescriptors);
        track_dump_resources_.replay_render_target_handles.resize(NumRenderTargetDescriptors);
        for (uint32_t i = 0; i < NumRenderTargetDescriptors; ++i)
        {
            if (RTsSingleHandleToDescriptorRange)
            {
                // All render target descriptors are contiguous in the same descriptor heap.
                track_dump_resources_.render_target_heap_ids[i] = rt_handles[0].heap_id;
                track_dump_resources_.replay_render_target_handles[i] =
                    D3D12_CPU_DESCRIPTOR_HANDLE{ (*rt_handles[0].decoded_value).ptr + descriptor_increment * i };
            }
            else
            {
                track_dump_resources_.render_target_heap_ids[i]       = rt_handles[i].heap_id;
                track_dump_resources_.replay_render_target_handles[i] = *rt_handles[i].decoded_value;
            }
        }
        auto ds_handle = pDepthStencilDescriptor->GetMetaStructPointer();
        if (ds_handle)
        {
            track_dump_resources_.depth_stencil_heap_id       = ds_handle->heap_id;
            track_dump_resources_.replay_depth_stencil_handle = *ds_handle->decoded_value;
        }
    }
}

void Dx12ReplayConsumerBase::OverrideBeginRenderPass(
    DxObjectInfo*                                                       replay_object_info,
    UINT                                                                NumRenderTargets,
    StructPointerDecoder<Decoded_D3D12_RENDER_PASS_RENDER_TARGET_DESC>* pRenderTargets,
    StructPointerDecoder<Decoded_D3D12_RENDER_PASS_DEPTH_STENCIL_DESC>* pDepthStencil,
    D3D12_RENDER_PASS_FLAGS                                             Flags)
{
    reinterpret_cast<ID3D12GraphicsCommandList4*>(replay_object_info->object)
        ->BeginRenderPass(NumRenderTargets, pRenderTargets->GetPointer(), pDepthStencil->GetPointer(), Flags);

    auto dump_command_sets = GetCommandListsForDumpResources(replay_object_info);
    if (!dump_command_sets.empty())
    {
        GFXRECON_ASSERT(dump_command_sets.size() == 3);

        auto captured_rt_descs = pRenderTargets->GetMetaStructPointer();
        track_dump_resources_.render_target_heap_ids.resize(NumRenderTargets);
        track_dump_resources_.replay_render_target_handles.resize(NumRenderTargets);
        for (uint32_t i = 0; i < NumRenderTargets; ++i)
        {
            track_dump_resources_.render_target_heap_ids[i]       = captured_rt_descs[i].cpuDescriptor->heap_id;
            track_dump_resources_.replay_render_target_handles[i] = *captured_rt_descs[i].cpuDescriptor->decoded_value;
        }

        auto captured_ds_desc = pDepthStencil->GetMetaStructPointer();
        if (!pDepthStencil->IsNull())
        {
            track_dump_resources_.depth_stencil_heap_id       = captured_ds_desc->cpuDescriptor->heap_id;
            track_dump_resources_.replay_depth_stencil_handle = *captured_ds_desc->cpuDescriptor->decoded_value;
        }

        // before
        ID3D12GraphicsCommandList4* command_list4_before;
        dump_command_sets[graphics::TrackDumpResources::SplitCommandType::kBeforeDrawCall].list->QueryInterface(
            IID_PPV_ARGS(&command_list4_before));

        std::vector<D3D12_RENDER_PASS_RENDER_TARGET_DESC> before_rt_descs;
        for (uint32_t i = 0; i < NumRenderTargets; ++i)
        {
            D3D12_RENDER_PASS_RENDER_TARGET_DESC desc = *captured_rt_descs[i].decoded_value;
            desc.EndingAccess.Type                    = D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_PRESERVE;
            before_rt_descs.emplace_back(std::move(desc));
        }

        D3D12_RENDER_PASS_DEPTH_STENCIL_DESC  before_ds_desc   = {};
        D3D12_RENDER_PASS_DEPTH_STENCIL_DESC* p_before_ds_desc = nullptr;
        if (!pDepthStencil->IsNull())
        {
            before_ds_desc                          = *captured_ds_desc->decoded_value;
            before_ds_desc.DepthEndingAccess.Type   = D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_PRESERVE;
            before_ds_desc.StencilEndingAccess.Type = D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_PRESERVE;
            p_before_ds_desc                        = &before_ds_desc;
        }
        command_list4_before->BeginRenderPass(NumRenderTargets, before_rt_descs.data(), p_before_ds_desc, Flags);

        // drawcall
        ID3D12GraphicsCommandList4* command_list4_draw_call;
        dump_command_sets[graphics::TrackDumpResources::SplitCommandType::kDrawCall].list->QueryInterface(
            IID_PPV_ARGS(&command_list4_draw_call));

        std::vector<D3D12_RENDER_PASS_RENDER_TARGET_DESC> draw_call_rt_descs;
        for (uint32_t i = 0; i < NumRenderTargets; ++i)
        {
            D3D12_RENDER_PASS_RENDER_TARGET_DESC desc = *captured_rt_descs[i].decoded_value;
            desc.BeginningAccess.Type                 = D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_PRESERVE;
            desc.EndingAccess.Type                    = D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_PRESERVE;
            draw_call_rt_descs.emplace_back(std::move(desc));
        }

        D3D12_RENDER_PASS_DEPTH_STENCIL_DESC  draw_call_ds_desc   = {};
        D3D12_RENDER_PASS_DEPTH_STENCIL_DESC* p_draw_call_ds_desc = nullptr;
        if (!pDepthStencil->IsNull())
        {
            draw_call_ds_desc                             = *captured_ds_desc->decoded_value;
            draw_call_ds_desc.DepthBeginningAccess.Type   = D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_PRESERVE;
            draw_call_ds_desc.StencilBeginningAccess.Type = D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_PRESERVE;
            draw_call_ds_desc.DepthEndingAccess.Type      = D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_PRESERVE;
            draw_call_ds_desc.StencilEndingAccess.Type    = D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_PRESERVE;
            p_draw_call_ds_desc                           = &draw_call_ds_desc;
        }
        command_list4_draw_call->BeginRenderPass(
            NumRenderTargets, draw_call_rt_descs.data(), p_draw_call_ds_desc, Flags);

        // after
        ID3D12GraphicsCommandList4* command_list4_after;
        dump_command_sets[graphics::TrackDumpResources::SplitCommandType::kAfterDrawCall].list->QueryInterface(
            IID_PPV_ARGS(&command_list4_after));

        std::vector<D3D12_RENDER_PASS_RENDER_TARGET_DESC> after_rt_descs;
        for (uint32_t i = 0; i < NumRenderTargets; ++i)
        {
            D3D12_RENDER_PASS_RENDER_TARGET_DESC desc = *captured_rt_descs[i].decoded_value;
            desc.BeginningAccess.Type                 = D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_PRESERVE;
            after_rt_descs.emplace_back(std::move(desc));
        }

        D3D12_RENDER_PASS_DEPTH_STENCIL_DESC  after_ds_desc   = {};
        D3D12_RENDER_PASS_DEPTH_STENCIL_DESC* p_after_ds_desc = nullptr;
        if (!pDepthStencil->IsNull())
        {
            after_ds_desc                             = *captured_ds_desc->decoded_value;
            after_ds_desc.DepthBeginningAccess.Type   = D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_PRESERVE;
            after_ds_desc.StencilBeginningAccess.Type = D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_PRESERVE;
            p_after_ds_desc                           = &after_ds_desc;
        }
        command_list4_after->BeginRenderPass(NumRenderTargets, after_rt_descs.data(), p_after_ds_desc, Flags);
    }
}

std::vector<graphics::CommandSet>
Dx12ReplayConsumerBase::GetCommandListsForDumpResources(DxObjectInfo* command_list_object_info)
{
    std::vector<graphics::CommandSet> cmd_sets;
    if (options_.enable_dump_resources)
    {
        auto code_index  = GetCurrentBlockIndex();
        auto api_call_id = GetCurrentApiCallId();
        if (track_dump_resources_.target.begin_code_index == code_index)
        {
            auto cmd_list_extra_info = GetExtraInfo<D3D12CommandListInfo>(command_list_object_info);
            auto cmd_list            = static_cast<ID3D12GraphicsCommandList*>(command_list_object_info->object);
            auto device              = graphics::dx12::GetDeviceComPtrFromChild<ID3D12Device>(cmd_list);

            for (auto& command_set : track_dump_resources_.split_command_sets)
            {
                device->CreateCommandAllocator(cmd_list_extra_info->create_list_type,
                                               IID_PPV_ARGS(&command_set.allocator));
                device->CreateCommandList(0,
                                          cmd_list_extra_info->create_list_type,
                                          command_set.allocator,
                                          nullptr,
                                          IID_PPV_ARGS(&command_set.list));
            }
            device->CreateFence(0, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&track_dump_resources_.fence));
            track_dump_resources_.fence_event = CreateEventA(nullptr, TRUE, FALSE, nullptr);
        }

        if ((command_list_object_info->capture_id == track_dump_resources_.target.command_list_id) &&
            (track_dump_resources_.target.begin_code_index <= code_index) &&
            (track_dump_resources_.target.close_code_index >= code_index))
        {
            graphics::TrackDumpResources::SplitCommandType split_type =
                graphics::TrackDumpResources::SplitCommandType::kBeforeDrawCall;

            if (code_index == track_dump_resources_.target.drawcall_code_index)
            {
                split_type = graphics::TrackDumpResources::SplitCommandType::kDrawCall;
            }
            else if (code_index >= track_dump_resources_.target.drawcall_code_index)
            {
                split_type = graphics::TrackDumpResources::SplitCommandType::kAfterDrawCall;
            }

            // Here is to split command lists.
            switch (api_call_id)
            {
                case format::ApiCall_ID3D12GraphicsCommandList_Reset:
                {
                    for (auto& command_set : track_dump_resources_.split_command_sets)
                    {
                        command_set.list->Close();
                        command_set.allocator->Reset();
                        cmd_sets.emplace_back(command_set);
                    }
                    break;
                }
                case format::ApiCall_ID3D12GraphicsCommandList_Close:
                {
                    if (track_dump_resources_.target.begin_renderpass_code_index != 0)
                    {
                        ID3D12GraphicsCommandList4* command_list4_before;
                        track_dump_resources_
                            .split_command_sets[graphics::TrackDumpResources::SplitCommandType::kBeforeDrawCall]
                            .list->QueryInterface(IID_PPV_ARGS(&command_list4_before));
                        command_list4_before->EndRenderPass();

                        ID3D12GraphicsCommandList4* command_list4_draw_call;
                        track_dump_resources_
                            .split_command_sets[graphics::TrackDumpResources::SplitCommandType::kDrawCall]
                            .list->QueryInterface(IID_PPV_ARGS(&command_list4_draw_call));
                        command_list4_draw_call->EndRenderPass();
                    }
                    cmd_sets.insert(cmd_sets.end(),
                                    track_dump_resources_.split_command_sets.begin(),
                                    track_dump_resources_.split_command_sets.end());
                    break;
                }
                // binding and Set. These commands are the three command lists need.
                case format::ApiCall_ID3D12GraphicsCommandList_IASetIndexBuffer:
                case format::ApiCall_ID3D12GraphicsCommandList_IASetPrimitiveTopology:
                case format::ApiCall_ID3D12GraphicsCommandList_IASetVertexBuffers:
                case format::ApiCall_ID3D12GraphicsCommandList_OMSetBlendFactor:
                case format::ApiCall_ID3D12GraphicsCommandList1_OMSetDepthBounds:
                case format::ApiCall_ID3D12GraphicsCommandList_OMSetRenderTargets:
                case format::ApiCall_ID3D12GraphicsCommandList_OMSetStencilRef:
                case format::ApiCall_ID3D12GraphicsCommandList_RSSetScissorRects:
                case format::ApiCall_ID3D12GraphicsCommandList5_RSSetShadingRate:
                case format::ApiCall_ID3D12GraphicsCommandList5_RSSetShadingRateImage:
                case format::ApiCall_ID3D12GraphicsCommandList_RSSetViewports:
                case format::ApiCall_ID3D12GraphicsCommandList_SetComputeRoot32BitConstant:
                case format::ApiCall_ID3D12GraphicsCommandList_SetComputeRoot32BitConstants:
                case format::ApiCall_ID3D12GraphicsCommandList_SetComputeRootConstantBufferView:
                case format::ApiCall_ID3D12GraphicsCommandList_SetComputeRootDescriptorTable:
                case format::ApiCall_ID3D12GraphicsCommandList_SetComputeRootShaderResourceView:
                case format::ApiCall_ID3D12GraphicsCommandList_SetComputeRootSignature:
                case format::ApiCall_ID3D12GraphicsCommandList_SetComputeRootUnorderedAccessView:
                case format::ApiCall_ID3D12GraphicsCommandList_SetDescriptorHeaps:
                case format::ApiCall_ID3D12GraphicsCommandList_SetGraphicsRoot32BitConstant:
                case format::ApiCall_ID3D12GraphicsCommandList_SetGraphicsRoot32BitConstants:
                case format::ApiCall_ID3D12GraphicsCommandList_SetGraphicsRootConstantBufferView:
                case format::ApiCall_ID3D12GraphicsCommandList_SetGraphicsRootDescriptorTable:
                case format::ApiCall_ID3D12GraphicsCommandList_SetGraphicsRootShaderResourceView:
                case format::ApiCall_ID3D12GraphicsCommandList_SetGraphicsRootSignature:
                case format::ApiCall_ID3D12GraphicsCommandList_SetGraphicsRootUnorderedAccessView:
                case format::ApiCall_ID3D12GraphicsCommandList_SetPipelineState:
                case format::ApiCall_ID3D12GraphicsCommandList4_SetPipelineState1:
                case format::ApiCall_ID3D12GraphicsCommandList_SetPredication:
                case format::ApiCall_ID3D12GraphicsCommandList3_SetProtectedResourceSession:
                case format::ApiCall_ID3D12GraphicsCommandList1_SetSamplePositions:
                case format::ApiCall_ID3D12GraphicsCommandList1_SetViewInstanceMask:
                case format::ApiCall_ID3D12GraphicsCommandList_SOSetTargets:
                case format::ApiCall_ID3D12GraphicsCommandList2_WriteBufferImmediate:
                {
                    switch (split_type)
                    {
                        case graphics::TrackDumpResources::SplitCommandType::kBeforeDrawCall:
                            cmd_sets.insert(cmd_sets.end(),
                                            track_dump_resources_.split_command_sets.begin(),
                                            track_dump_resources_.split_command_sets.end());
                            break;
                        case graphics::TrackDumpResources::SplitCommandType::kAfterDrawCall:
                            cmd_sets.emplace_back(track_dump_resources_.split_command_sets
                                                      [graphics::TrackDumpResources::SplitCommandType::kAfterDrawCall]);
                            break;
                        default:
                            break;
                    }
                    break;
                }
                case format::ApiCall_ID3D12GraphicsCommandList4_BeginRenderPass:
                {
                    if (code_index == track_dump_resources_.target.begin_renderpass_code_index)
                    {
                        cmd_sets.insert(cmd_sets.end(),
                                        track_dump_resources_.split_command_sets.begin(),
                                        track_dump_resources_.split_command_sets.end());
                    }
                    break;
                }
                default:
                {
                    // command type could be changed data, drawcalls.
                    cmd_sets.emplace_back(track_dump_resources_.split_command_sets[split_type]);
                    break;
                }
            }
        }
    }
    return cmd_sets;
}

void Dx12ReplayConsumerBase::PostCall_ID3D12CommandQueue_ExecuteCommandLists(
    const ApiCallInfo&                        call_info,
    DxObjectInfo*                             object_info,
    UINT                                      NumCommandLists,
    HandlePointerDecoder<ID3D12CommandList*>* ppCommandLists)
{
    for (uint32_t i = 0; i < NumCommandLists; ++i)
    {
        auto commandlist_id          = ppCommandLists->GetPointer()[i];
        auto command_list_extra_info = GetExtraInfo<D3D12CommandListInfo>(GetObjectInfo(commandlist_id));

        for (const auto& pair : command_list_extra_info->pending_resource_states)
        {
            auto resource_object_info = GetObjectInfo(pair.first);
            if (resource_object_info == nullptr)
            {
                GFXRECON_LOG_WARNING("resource id %" PRIu64
                                     " can't found for update state in ExecuteCommandLists. It could be released",
                                     pair.first);
            }
            else
            {
                auto resource_extra_info = GetExtraInfo<D3D12ResourceInfo>(resource_object_info);
                for (auto& state : pair.second)
                {
                    if (state.transition.Subresource == D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES)
                    {
                        for (auto& info : resource_extra_info->resource_state_infos)
                        {
                            info.states        = state.transition.StateAfter;
                            info.barrier_flags = state.barrier_flags;
                        }
                    }
                    else
                    {
                        resource_extra_info->resource_state_infos[state.transition.Subresource].states =
                            state.transition.StateAfter;
                        resource_extra_info->resource_state_infos[state.transition.Subresource].barrier_flags =
                            state.barrier_flags;
                    }
                }
            }
        }
        command_list_extra_info->pending_resource_states.clear();
    }
}

void Dx12ReplayConsumerBase::PostCall_ID3D12Device_CopyDescriptors(
    const ApiCallInfo&                                         call_info,
    DxObjectInfo*                                              device_object_info,
    UINT                                                       NumDestDescriptorRanges,
    StructPointerDecoder<Decoded_D3D12_CPU_DESCRIPTOR_HANDLE>* pDestDescriptorRangeStarts,
    PointerDecoder<UINT>*                                      pDestDescriptorRangeSizes,
    UINT                                                       NumSrcDescriptorRanges,
    StructPointerDecoder<Decoded_D3D12_CPU_DESCRIPTOR_HANDLE>* pSrcDescriptorRangeStarts,
    PointerDecoder<UINT>*                                      pSrcDescriptorRangeSizes,
    D3D12_DESCRIPTOR_HEAP_TYPE                                 DescriptorHeapsType)
{
    UINT dest_range_i = 0;
    UINT src_range_i  = 0;
    UINT dest_i       = 0;
    UINT src_i        = 0;

    auto dest_range_sizes = pDestDescriptorRangeSizes->GetPointer();
    auto src_range_sizes  = pSrcDescriptorRangeSizes->GetPointer();

    auto dest_range_starts = pDestDescriptorRangeStarts->GetMetaStructPointer();
    auto src_range_starts  = pSrcDescriptorRangeStarts->GetMetaStructPointer();

    while (dest_range_i < NumDestDescriptorRanges && src_range_i < NumSrcDescriptorRanges)
    {
        auto dest_range_size = (dest_range_sizes != nullptr) ? dest_range_sizes[dest_range_i] : 1;
        auto src_range_size  = (src_range_sizes != nullptr) ? src_range_sizes[src_range_i] : 1;

        auto dest_size = dest_range_size - dest_i;
        auto src_size  = src_range_size - src_i;

        auto copy_size = std::min(dest_size, src_size);

        // DUMPTODO: Test, cleanup, and share with code from CopyDescriptorsSimple
        auto dest_descriptor_info  = dest_range_starts[dest_range_i];
        auto dest_heap_object_info = GetObjectInfo(dest_descriptor_info.heap_id);
        auto dest_heap_extra_info  = GetExtraInfo<D3D12DescriptorHeapInfo>(dest_heap_object_info);
        auto src_descriptor_info   = src_range_starts[src_range_i];
        auto src_heap_object_info  = GetObjectInfo(src_descriptor_info.heap_id);
        auto src_heap_extra_info   = GetExtraInfo<D3D12DescriptorHeapInfo>(src_heap_object_info);

        for (UINT i = 0; i < copy_size; ++i)
        {
            auto dest_idx = dest_descriptor_info.index + dest_i + i;
            auto src_idx  = src_descriptor_info.index + src_i + i;

            if (src_heap_extra_info->constant_buffer_infos.count(src_idx) > 0)
            {
                dest_heap_extra_info->constant_buffer_infos[dest_idx] =
                    src_heap_extra_info->constant_buffer_infos[src_idx];
            }
            if (src_heap_extra_info->shader_resource_infos.count(src_idx) > 0)
            {
                dest_heap_extra_info->shader_resource_infos[dest_idx] =
                    src_heap_extra_info->shader_resource_infos[src_idx];
            }
            if (src_heap_extra_info->unordered_access_infos.count(src_idx) > 0)
            {
                dest_heap_extra_info->unordered_access_infos[dest_idx] =
                    src_heap_extra_info->unordered_access_infos[src_idx];
            }
            if (src_heap_extra_info->render_target_infos.count(src_idx) > 0)
            {
                dest_heap_extra_info->render_target_infos[dest_idx] = src_heap_extra_info->render_target_infos[src_idx];
            }
            if (src_heap_extra_info->depth_stencil_infos.count(src_idx) > 0)
            {
                dest_heap_extra_info->depth_stencil_infos[dest_idx] = src_heap_extra_info->depth_stencil_infos[src_idx];
            }
        }

        dest_i += copy_size;
        src_i += copy_size;

        if (dest_i == dest_range_size)
        {
            dest_i = 0;
            ++dest_range_i;
        }
        if (src_i == src_range_size)
        {
            src_i = 0;
            ++src_range_i;
        }
    }
}

void Dx12ReplayConsumerBase::PostCall_ID3D12Device_CopyDescriptorsSimple(
    const ApiCallInfo&                  call_info,
    DxObjectInfo*                       device_object_info,
    UINT                                NumDescriptors,
    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptorRangeStart,
    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE SrcDescriptorRangeStart,
    D3D12_DESCRIPTOR_HEAP_TYPE          DescriptorHeapsType)
{
    auto dest_heap_object_info = GetObjectInfo(DestDescriptorRangeStart.heap_id);
    auto dest_heap_extra_info  = GetExtraInfo<D3D12DescriptorHeapInfo>(dest_heap_object_info);
    auto src_heap_object_info  = GetObjectInfo(SrcDescriptorRangeStart.heap_id);
    auto src_heap_extra_info   = GetExtraInfo<D3D12DescriptorHeapInfo>(src_heap_object_info);

    for (UINT i = 0; i < NumDescriptors; ++i)
    {
        auto dest_idx = DestDescriptorRangeStart.index + i;
        auto src_idx  = SrcDescriptorRangeStart.index + i;

        if (src_heap_extra_info->constant_buffer_infos.count(src_idx) > 0)
        {
            dest_heap_extra_info->constant_buffer_infos[dest_idx] = src_heap_extra_info->constant_buffer_infos[src_idx];
        }
        if (src_heap_extra_info->shader_resource_infos.count(src_idx) > 0)
        {
            dest_heap_extra_info->shader_resource_infos[dest_idx] = src_heap_extra_info->shader_resource_infos[src_idx];
        }
        if (src_heap_extra_info->unordered_access_infos.count(src_idx) > 0)
        {
            dest_heap_extra_info->unordered_access_infos[dest_idx] =
                src_heap_extra_info->unordered_access_infos[src_idx];
        }
        if (src_heap_extra_info->render_target_infos.count(src_idx) > 0)
        {
            dest_heap_extra_info->render_target_infos[dest_idx] = src_heap_extra_info->render_target_infos[src_idx];
        }
        if (src_heap_extra_info->depth_stencil_infos.count(src_idx) > 0)
        {
            dest_heap_extra_info->depth_stencil_infos[dest_idx] = src_heap_extra_info->depth_stencil_infos[src_idx];
        }
    }
}

bool MatchDescriptorCPUGPUHandle(size_t                                      replay_cpu_addr_begin,
                                 size_t                                      replay_target_cpu_addr,
                                 uint64_t                                    capture_gpu_addr_begin,
                                 std::map<UINT, D3D12_GPU_DESCRIPTOR_HANDLE> captured_gpu_addrs)
{
    for (auto gpu_addr : captured_gpu_addrs)
    {
        if ((gpu_addr.second.ptr >= capture_gpu_addr_begin) &&
            ((replay_target_cpu_addr - replay_cpu_addr_begin) == (gpu_addr.second.ptr - capture_gpu_addr_begin)))
        {
            return true;
        }
    }
    return false;
}

void Dx12ReplayConsumerBase::CopyResourcesForBeforeDrawcall(DxObjectInfo*                        queue_object_info,
                                                            const std::vector<format::HandleId>& front_command_list_ids)
{
    // vertex
    for (const auto& view : track_dump_resources_.target.captured_vertex_buffer_views)
    {
        graphics::CopyResourceData copy_resource_data;
        copy_resource_data.subresource_indices.emplace_back(0);
        CopyResourceForBeforeDrawcallByGPUVA(
            queue_object_info, front_command_list_ids, view.BufferLocation, view.SizeInBytes, copy_resource_data);

        track_dump_resources_.copy_vertex_resources.emplace_back(std::move(copy_resource_data));
    }

    // index
    track_dump_resources_.copy_index_resource.subresource_indices.emplace_back(0);
    CopyResourceForBeforeDrawcallByGPUVA(queue_object_info,
                                         front_command_list_ids,
                                         track_dump_resources_.target.captured_index_buffer_view.BufferLocation,
                                         track_dump_resources_.target.captured_index_buffer_view.SizeInBytes,
                                         track_dump_resources_.copy_index_resource);

    // descriptor
    auto heap_size = track_dump_resources_.target.descriptor_heap_ids.size();
    track_dump_resources_.descriptor_heap_datas.resize(heap_size);
    for (uint32_t heap_index = 0; heap_index < heap_size; ++heap_index)
    {
        auto heap_object_info = GetObjectInfo(track_dump_resources_.target.descriptor_heap_ids[heap_index]);
        auto heap_extra_info  = GetExtraInfo<D3D12DescriptorHeapInfo>(heap_object_info);

        // constant buffer
        for (const auto& info_pair : heap_extra_info->constant_buffer_infos)
        {
            const auto& info = info_pair.second;
            if (MatchDescriptorCPUGPUHandle(heap_extra_info->replay_cpu_addr_begin,
                                            info.replay_handle.ptr,
                                            heap_extra_info->capture_gpu_addr_begin,
                                            track_dump_resources_.target.captured_descriptor_gpu_handles))
            {
                graphics::CopyResourceData copy_resource_data;
                copy_resource_data.subresource_indices.emplace_back(0);
                CopyResourceForBeforeDrawcallByGPUVA(queue_object_info,
                                                     front_command_list_ids,
                                                     info.captured_view.BufferLocation,
                                                     info.captured_view.SizeInBytes,
                                                     copy_resource_data);

                track_dump_resources_.descriptor_heap_datas[heap_index].copy_constant_buffer_resources.emplace_back(
                    std::move(copy_resource_data));
            }
        }

        if (TEST_SHADER_RES)
        {
            // shader resource
            for (const auto& info_pair : heap_extra_info->shader_resource_infos)
            {
                const auto& info = info_pair.second;
                if (MatchDescriptorCPUGPUHandle(heap_extra_info->replay_cpu_addr_begin,
                                                info.replay_handle.ptr,
                                                heap_extra_info->capture_gpu_addr_begin,
                                                track_dump_resources_.target.captured_descriptor_gpu_handles))
                {
                    uint64_t offset = 0;
                    uint64_t size   = 0;
                    switch (info.view.ViewDimension)
                    {
                        case D3D12_SRV_DIMENSION_BUFFER:
                        {
                            auto size = info.view.Buffer.StructureByteStride;
                            if (size == 0)
                            {
                                size = graphics::dx12::GetSubresourcePixelByteSize(info.view.Format);
                            }
                            offset = info.view.Buffer.FirstElement * size;
                            size   = info.view.Buffer.NumElements * size;
                            break;
                        }
                        default:
                            break;
                    }

                    graphics::CopyResourceData copy_resource_data;
                    copy_resource_data.subresource_indices = info.subresource_indices;
                    CopyResourceForBeforeDrawcall(
                        queue_object_info, front_command_list_ids, info.resource_id, offset, size, copy_resource_data);

                    track_dump_resources_.descriptor_heap_datas[heap_index].copy_shader_resources.emplace_back(
                        std::move(copy_resource_data));
                }
            }

            // unordered access
            for (const auto& info_pair : heap_extra_info->unordered_access_infos)
            {
                const auto& info = info_pair.second;
                if (MatchDescriptorCPUGPUHandle(heap_extra_info->replay_cpu_addr_begin,
                                                info.replay_handle.ptr,
                                                heap_extra_info->capture_gpu_addr_begin,
                                                track_dump_resources_.target.captured_descriptor_gpu_handles))
                {
                    uint64_t offset = 0;
                    uint64_t size   = 0;
                    switch (info.view.ViewDimension)
                    {
                        case D3D12_UAV_DIMENSION_BUFFER:
                        {
                            auto size = info.view.Buffer.StructureByteStride;
                            if (size == 0)
                            {
                                size = graphics::dx12::GetSubresourcePixelByteSize(info.view.Format);
                            }
                            offset = info.view.Buffer.FirstElement * size;
                            size   = info.view.Buffer.NumElements * size;
                            break;
                        }
                        default:
                            break;
                    }
                    graphics::UnorderedAccess copy_resource_data;
                    copy_resource_data.resource.subresource_indices = info.subresource_indices;
                    CopyResourceForBeforeDrawcall(queue_object_info,
                                                  front_command_list_ids,
                                                  info.resource_id,
                                                  offset,
                                                  size,
                                                  copy_resource_data.resource);

                    if (info.counter_resource_id != format::kNullHandleId)
                    {
                        copy_resource_data.counter_resource.subresource_indices.emplace_back(0);
                        CopyResourceForBeforeDrawcall(queue_object_info,
                                                      front_command_list_ids,
                                                      info.counter_resource_id,
                                                      info.view.Buffer.CounterOffsetInBytes,
                                                      0,
                                                      copy_resource_data.resource);
                    }
                    track_dump_resources_.descriptor_heap_datas[heap_index].copy_unordered_accesses.emplace_back(
                        std::move(copy_resource_data));
                }
            }
        }
    }

    // render target
    auto rt_size = track_dump_resources_.replay_render_target_handles.size();
    track_dump_resources_.copy_render_target_resources.resize(rt_size);

    for (uint32_t i = 0; i < rt_size; ++i)
    {
        auto heap_object_info = GetObjectInfo(track_dump_resources_.render_target_heap_ids[i]);
        auto heap_extra_info  = GetExtraInfo<D3D12DescriptorHeapInfo>(heap_object_info);

        for (const auto& info_pair : heap_extra_info->render_target_infos)
        {
            const auto& info = info_pair.second;
            if (info.replay_handle.ptr == track_dump_resources_.replay_render_target_handles[i].ptr)
            {
                uint64_t offset = 0;
                uint64_t size   = 0;
                switch (info.view.ViewDimension)
                {
                    case D3D12_RTV_DIMENSION_BUFFER:
                    {
                        auto size = graphics::dx12::GetSubresourcePixelByteSize(info.view.Format);
                        offset    = info.view.Buffer.FirstElement * size;
                        size      = info.view.Buffer.NumElements * size;
                        break;
                    }
                    default:
                        break;
                }

                track_dump_resources_.copy_render_target_resources[i].subresource_indices = info.subresource_indices;
                CopyResourceForBeforeDrawcall(queue_object_info,
                                              front_command_list_ids,
                                              info.resource_id,
                                              0,
                                              0,
                                              track_dump_resources_.copy_render_target_resources[i]);
                break;
            }
        }
    }

    // depth stencil
    if (track_dump_resources_.replay_depth_stencil_handle.ptr != decode::kNullCpuAddress)
    {
        auto heap_object_info = GetObjectInfo(track_dump_resources_.depth_stencil_heap_id);
        auto heap_extra_info  = GetExtraInfo<D3D12DescriptorHeapInfo>(heap_object_info);

        for (const auto& info_pair : heap_extra_info->depth_stencil_infos)
        {
            const auto& info = info_pair.second;
            if (info.replay_handle.ptr == track_dump_resources_.replay_depth_stencil_handle.ptr)
            {
                track_dump_resources_.copy_depth_stencil_resource.subresource_indices = info.subresource_indices;
                CopyResourceForBeforeDrawcall(queue_object_info,
                                              front_command_list_ids,
                                              info.resource_id,
                                              0,
                                              0,
                                              track_dump_resources_.copy_depth_stencil_resource);
                break;
            }
        }
    }

    // ExecuteIndirect
    track_dump_resources_.copy_exe_indirect_argument.subresource_indices.emplace_back(0);
    CopyResourceForBeforeDrawcall(queue_object_info,
                                  front_command_list_ids,
                                  track_dump_resources_.target.exe_indirect_argument_id,
                                  track_dump_resources_.target.exe_indirect_argument_offset,
                                  0,
                                  track_dump_resources_.copy_exe_indirect_argument);

    track_dump_resources_.copy_exe_indirect_count.subresource_indices.emplace_back(0);
    CopyResourceForBeforeDrawcall(queue_object_info,
                                  front_command_list_ids,
                                  track_dump_resources_.target.exe_indirect_count_id,
                                  track_dump_resources_.target.exe_indirect_count_offset,
                                  0,
                                  track_dump_resources_.copy_exe_indirect_count);
}

void Dx12ReplayConsumerBase::CopyResourceForBeforeDrawcallByGPUVA(
    DxObjectInfo*                        queue_object_info,
    const std::vector<format::HandleId>& front_command_list_ids,
    D3D12_GPU_VIRTUAL_ADDRESS            captured_source_gpu_va,
    uint64_t                             source_size,
    graphics::CopyResourceData&          copy_resource_data)
{
    if (captured_source_gpu_va == 0)
    {
        return;
    }
    copy_resource_data.source_resource_id = object_mapping::FindResourceIDbyGpuVA(captured_source_gpu_va, gpu_va_map_);

    auto source_resource_object_info = GetObjectInfo(copy_resource_data.source_resource_id);
    auto source_resource_extra_info  = GetExtraInfo<D3D12ResourceInfo>(source_resource_object_info);

    CopyResourceForBeforeDrawcall(queue_object_info,
                                  front_command_list_ids,
                                  copy_resource_data.source_resource_id,
                                  (captured_source_gpu_va - source_resource_extra_info->capture_address_),
                                  source_size,
                                  copy_resource_data);
}

// If source_size = 0, the meaning is the whole after offset.
void Dx12ReplayConsumerBase::CopyResourceForBeforeDrawcall(DxObjectInfo*                        queue_object_info,
                                                           const std::vector<format::HandleId>& front_command_list_ids,
                                                           format::HandleId                     source_resource_id,
                                                           uint64_t                             source_offset,
                                                           uint64_t                             source_size,
                                                           graphics::CopyResourceData&          copy_resource_data)
{
    if (source_resource_id == 0)
    {
        return;
    }
    copy_resource_data.source_resource_id = source_resource_id;

    auto source_resource_object_info = GetObjectInfo(copy_resource_data.source_resource_id);
    auto source_resource             = reinterpret_cast<ID3D12Resource*>(source_resource_object_info->object);
    auto device                      = graphics::dx12::GetDeviceComPtrFromChild<ID3D12Device>(source_resource);
    copy_resource_data.desc          = source_resource->GetDesc();

    size_t subresource_count;
    copy_resource_data.subresource_footprint_offsets.clear();
    copy_resource_data.subresource_footprint_sizes.clear();
    copy_resource_data.footprints.clear();
    copy_resource_data.total_size = 0;
    graphics::Dx12ResourceDataUtil::GetResourceCopyInfo(source_resource,
                                                        subresource_count,
                                                        copy_resource_data.subresource_footprint_offsets,
                                                        copy_resource_data.subresource_footprint_sizes,
                                                        copy_resource_data.footprints,
                                                        copy_resource_data.total_size);

    copy_resource_data.before_datas.resize(subresource_count);
    copy_resource_data.after_datas.resize(subresource_count);

    copy_resource_data.is_cpu_accessible = graphics::Dx12ResourceDataUtil::IsResourceCpuAccessible(
        source_resource, graphics::Dx12ResourceDataUtil::kCopyTypeRead);

    if (!copy_resource_data.is_cpu_accessible)
    {
        HRESULT hr     = E_UNEXPECTED;
        auto    device = graphics::dx12::GetDeviceComPtrFromChild<ID3D12Device>(source_resource);
        if (device != nullptr)
        {
            // Get or create staging buffer.
            // DUMPTODO: Use a single staging buffer, pre compute max needed size.
            if (dump_resources_staging_buffers_.empty() ||
                (dump_resources_staging_buffer_sizes_.back() < copy_resource_data.total_size))
            {
                auto new_staging_buffer = graphics::Dx12ResourceDataUtil::CreateStagingBuffer(
                    device, graphics::Dx12ResourceDataUtil::CopyType::kCopyTypeRead, copy_resource_data.total_size);
                dump_resources_staging_buffers_.push_back(new_staging_buffer);
                dump_resources_staging_buffer_sizes_.push_back(copy_resource_data.total_size);
            }
            copy_resource_data.read_resource                   = dump_resources_staging_buffers_.back();
            copy_resource_data.read_resource_is_staging_buffer = true;

            hr = device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT,
                                                IID_PPV_ARGS(&copy_resource_data.cmd_allocator));
            if (SUCCEEDED(hr))
            {
                hr = device->CreateCommandList(0,
                                               D3D12_COMMAND_LIST_TYPE_DIRECT,
                                               copy_resource_data.cmd_allocator,
                                               nullptr,
                                               IID_PPV_ARGS(&copy_resource_data.cmd_list));
                if (SUCCEEDED(hr))
                {
                    hr = copy_resource_data.cmd_list->Close();
                }
            }
        }
        if (!SUCCEEDED(hr))
        {
            GFXRECON_LOG_ERROR("Failed to create command list for copying resource ID=%" PRIu64 ".",
                               source_resource_id);
        }
    }

    // Determine whether to read the full subresource or just part of it.
    copy_resource_data.subresource_offsets.resize(subresource_count, 0);
    copy_resource_data.subresource_sizes = copy_resource_data.subresource_footprint_sizes;
    if (copy_resource_data.desc.Dimension == D3D12_RESOURCE_DIMENSION_BUFFER)
    {
        // Buffer has its offset and size.
        if (source_size == 0)
        {
            source_size = copy_resource_data.total_size - source_offset;
        }
        copy_resource_data.subresource_offsets[0] = source_offset;
        copy_resource_data.subresource_sizes[0]   = source_size;
    }

    CopyResourceAsync(queue_object_info, front_command_list_ids, copy_resource_data, copy_resource_data.before_datas);
}

void Dx12ReplayConsumerBase::CopyResourcesForAfterDrawcall(DxObjectInfo*                        queue_object_info,
                                                           const std::vector<format::HandleId>& front_command_list_ids)
{
    // vertex
    CopyResourcesForAfterDrawcall(
        queue_object_info, front_command_list_ids, track_dump_resources_.copy_vertex_resources);

    // index
    CopyResourceForAfterDrawcall(queue_object_info, front_command_list_ids, track_dump_resources_.copy_index_resource);

    // descriptor
    for (auto& heap_data : track_dump_resources_.descriptor_heap_datas)
    {
        // constant buffer
        CopyResourcesForAfterDrawcall(
            queue_object_info, front_command_list_ids, heap_data.copy_constant_buffer_resources);

        if (TEST_SHADER_RES)
        {
            // shader resource
            CopyResourcesForAfterDrawcall(queue_object_info, front_command_list_ids, heap_data.copy_shader_resources);

            // unordered access
            for (auto& uav : heap_data.copy_unordered_accesses)
            {
                CopyResourceForAfterDrawcall(queue_object_info, front_command_list_ids, uav.resource);
                CopyResourceForAfterDrawcall(queue_object_info, front_command_list_ids, uav.counter_resource);
            }
        }
    }

    // render target
    CopyResourcesForAfterDrawcall(
        queue_object_info, front_command_list_ids, track_dump_resources_.copy_render_target_resources);
    CopyResourceForAfterDrawcall(
        queue_object_info, front_command_list_ids, track_dump_resources_.copy_depth_stencil_resource);

    // ExecuteIndirect
    CopyResourceForAfterDrawcall(
        queue_object_info, front_command_list_ids, track_dump_resources_.copy_exe_indirect_argument);
    CopyResourceForAfterDrawcall(
        queue_object_info, front_command_list_ids, track_dump_resources_.copy_exe_indirect_count);
}

void Dx12ReplayConsumerBase::CopyResourcesForAfterDrawcall(DxObjectInfo*                        queue_object_info,
                                                           const std::vector<format::HandleId>& front_command_list_ids,
                                                           std::vector<graphics::CopyResourceData>& copy_resource_datas)
{
    for (auto& copy_resource : copy_resource_datas)
    {
        CopyResourceForAfterDrawcall(queue_object_info, front_command_list_ids, copy_resource);
    }
}

void Dx12ReplayConsumerBase::CopyResourceForAfterDrawcall(DxObjectInfo*                        queue_object_info,
                                                          const std::vector<format::HandleId>& front_command_list_ids,
                                                          graphics::CopyResourceData&          copy_resource_data)
{
    if (copy_resource_data.source_resource_id == 0)
    {
        return;
    }
    CopyResourceAsync(queue_object_info, front_command_list_ids, copy_resource_data, copy_resource_data.after_datas);
}

bool Dx12ReplayConsumerBase::CopyResourceAsyncQueue(const std::vector<format::HandleId>& front_command_list_ids,
                                                    graphics::CopyResourceData&          copy_resource_data,
                                                    ID3D12CommandQueue*                  draw_call_queue,
                                                    ID3D12Fence*                         fence,
                                                    UINT64                               fence_signal_value,
                                                    UINT64                               fence_wait_value)
{

    auto source_resource_object_info = GetObjectInfo(copy_resource_data.source_resource_id);
    auto source_resource             = reinterpret_cast<ID3D12Resource*>(source_resource_object_info->object);
    auto source_resource_extra_info  = GetExtraInfo<D3D12ResourceInfo>(source_resource_object_info);

    graphics::dx12::ID3D12CommandQueueComPtr queue = nullptr;
    if (source_resource_extra_info->swap_chain_id != format::kNullHandleId)
    {
        auto swapchain_extra_info =
            GetExtraInfo<DxgiSwapchainInfo>(GetObjectInfo(source_resource_extra_info->swap_chain_id));
        if (draw_call_queue != swapchain_extra_info->command_queue)
        {
            // Can only read swapchain buffers from the swapchain's queue.
            GFXRECON_LOG_ERROR("TODO: Is the swapchain queue always the same as the draw call queue?");
        }
    }

    HRESULT hr = S_OK;
    if (copy_resource_data.is_cpu_accessible)
    {
        // If the source_resource is CPU accessible, it can be read from directly.
        copy_resource_data.read_resource                   = source_resource;
        copy_resource_data.read_resource_is_staging_buffer = false;
    }
    else
    {
        // If the source_resource is not CPU accessible, build and execute a command list to copy data from the
        // source_resource to a staging_buffer.

        // Determine subresource states in order to transition to D3D12_RESOURCE_STATE_COPY_SOURCE.
        std::vector<graphics::dx12::ResourceStateInfo> res_infos = source_resource_extra_info->resource_state_infos;
        auto                                           size      = front_command_list_ids.size();
        for (uint32_t i = 0; i < size; ++i)
        {
            auto cmd_list_extra_info = GetExtraInfo<D3D12CommandListInfo>(GetObjectInfo(front_command_list_ids[i]));
            auto pending_states_iter =
                cmd_list_extra_info->pending_resource_states.find(source_resource_object_info->capture_id);
            if (pending_states_iter != cmd_list_extra_info->pending_resource_states.end())
            {
                for (const auto& state : pending_states_iter->second)
                {
                    bool is_update = true;
                    if (i == (size - 1))
                    {
                        if (state.code_index > track_dump_resources_.target.drawcall_code_index)
                        {
                            is_update = false;
                        }
                    }
                    if (is_update)
                    {
                        if (state.transition.Subresource == D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES)
                        {
                            for (auto& info : res_infos)
                            {
                                info.states        = state.transition.StateAfter;
                                info.barrier_flags = state.barrier_flags;
                            }
                        }
                        else
                        {
                            res_infos[state.transition.Subresource].states        = state.transition.StateAfter;
                            res_infos[state.transition.Subresource].barrier_flags = state.barrier_flags;
                        }
                    }
                }
            }
        }

        // Build command list for copying to staging buffer.
        copy_resource_data.cmd_list->Reset(copy_resource_data.cmd_allocator, nullptr);
        hr = graphics::Dx12ResourceDataUtil::RecordCommandsToCopyResource(copy_resource_data.cmd_list,
                                                                          source_resource,
                                                                          graphics::Dx12ResourceDataUtil::kCopyTypeRead,
                                                                          copy_resource_data.total_size,
                                                                          copy_resource_data.footprints,
                                                                          res_infos,
                                                                          res_infos,
                                                                          copy_resource_data.read_resource);

        if (SUCCEEDED(hr))
        {
            // Execute the command list.
            hr                             = copy_resource_data.cmd_list->Close();
            ID3D12CommandList* cmd_lists[] = { copy_resource_data.cmd_list };
            draw_call_queue->ExecuteCommandLists(1, cmd_lists);
        }
        else
        {
            GFXRECON_LOG_ERROR("Failed to record commands to copy resource data for resource %" PRIu64,
                               copy_resource_data.source_resource_id);
        }
    }

    // Signal the fence to indicate that data has been copied to the staging resource.
    hr = draw_call_queue->Signal(fence, fence_signal_value);
    GFXRECON_ASSERT(SUCCEEDED(hr));

    // Wait for the next fence value indicating that staging data has been read and is safe to continue.
    hr = draw_call_queue->Wait(fence, fence_wait_value);
    GFXRECON_ASSERT(SUCCEEDED(hr));

    return true;
}

// Wait for the queued work to complete and then read the copied resource.
void Dx12ReplayConsumerBase::CopyResourceAsyncRead(ID3D12Fence*                       fence,
                                                   UINT64                             fence_wait_value,
                                                   UINT64                             fence_signal_value,
                                                   HANDLE                             fence_event,
                                                   graphics::CopyResourceData*        copy_resource_data,
                                                   std::vector<std::vector<uint8_t>>* subresource_datas)
{
    const auto& resource            = copy_resource_data->read_resource;
    const auto& subresource_indices = copy_resource_data->subresource_indices;
    const auto& subresource_sizes   = copy_resource_data->subresource_footprint_sizes;

    // Wait for the command queue before reading data.
    UINT64 completed_value = fence->GetCompletedValue();
    if (completed_value == UINT64_MAX)
    {
        GFXRECON_LOG_FATAL(
            "Invalid fence value (UINT64_MAX). Device may have been removed. GFXR is unable to continue.");
        return;
    }
    if (completed_value < fence_wait_value)
    {
        ResetEvent(fence_event);
        fence->SetEventOnCompletion(fence_wait_value, fence_event);
        WaitForSingleObject(fence_event, INFINITE);
    }

    if (copy_resource_data->read_resource_is_staging_buffer)
    {
        // Read staging buffer data.
        const auto&          subresource_offsets = copy_resource_data->subresource_footprint_offsets;
        std::vector<uint8_t> full_resource_data;
        full_resource_data.resize(copy_resource_data->total_size);
        graphics::Dx12ResourceDataUtil::MapSubresourceAndReadData(
            resource, 0, full_resource_data.size(), full_resource_data.data());
        for (auto i : subresource_indices)
        {
            (*subresource_datas)[i].resize(subresource_sizes[i]);
            util::platform::MemoryCopy((*subresource_datas)[i].data(),
                                       subresource_sizes[i],
                                       full_resource_data.data() + subresource_offsets[i],
                                       subresource_sizes[i]);
        }
    }
    else
    {
        // Read directly from resource.
        for (auto i : subresource_indices)
        {
            (*subresource_datas)[i].resize(subresource_sizes[i]);
            graphics::Dx12ResourceDataUtil::MapSubresourceAndReadData(
                resource, i, subresource_sizes[i], (*subresource_datas)[i].data());
        }
    }

    // DUMPTODO: Write data to disk immediately, freeing up memory.

    // Signal command queue to continue execution.
    fence->Signal(fence_signal_value);
}

void Dx12ReplayConsumerBase::CopyResourceAsync(DxObjectInfo*                        queue_object_info,
                                               const std::vector<format::HandleId>& front_command_list_ids,
                                               graphics::CopyResourceData&          copy_resource_data,
                                               std::vector<std::vector<uint8_t>>&   copy_datas)
{
    auto fence               = track_dump_resources_.fence;
    auto fence_current_value = fence->GetCompletedValue();
    auto fence_event         = track_dump_resources_.fence_event;
    auto queue_extra_info    = GetExtraInfo<D3D12CommandQueueInfo>(queue_object_info);
    auto queue               = static_cast<ID3D12CommandQueue*>(queue_object_info->object);

    bool queued_success = CopyResourceAsyncQueue(
        front_command_list_ids, copy_resource_data, queue, fence, fence_current_value + 1, fence_current_value + 2);

    if (queued_success)
    {
        if (queue_extra_info->pending_events.empty())
        {
            CopyResourceAsyncRead(
                fence, fence_current_value + 1, fence_current_value + 2, fence_event, &copy_resource_data, &copy_datas);
        }
        else
        {
            // Add CopyResourceAsyncRead to queue's pending_events to be processed later.
            queue_extra_info->pending_events.push_back(
                CreateCopyResourceAsyncReadQueueSyncEvent(fence,
                                                          fence_current_value + 1,
                                                          fence_current_value + 2,
                                                          fence_event,
                                                          &copy_resource_data,
                                                          &copy_datas));
        }
    }
}

QueueSyncEventInfo
Dx12ReplayConsumerBase::CreateCopyResourceAsyncReadQueueSyncEvent(ID3D12Fence*                       fence,
                                                                  UINT64                             fence_wait_value,
                                                                  UINT64                             fence_signal_value,
                                                                  HANDLE                             fence_event,
                                                                  graphics::CopyResourceData*        copy_resource_data,
                                                                  std::vector<std::vector<uint8_t>>* subresource_datas)
{
    return QueueSyncEventInfo{ false, false, nullptr, 0, [&]() {
                                  CopyResourceAsyncRead(fence,
                                                        fence_wait_value,
                                                        fence_signal_value,
                                                        fence_event,
                                                        copy_resource_data,
                                                        subresource_datas);
                              } };
}

void Dx12ReplayConsumerBase::WriteDumpResources(DxObjectInfo* queue_object_info)
{
    gfxrecon::graphics::Dx12DumpResourcesConfig config;
    config.captured_file_name                                   = options_.filename;
    config.dump_resources_target                                = options_.dump_resources_target;
    std::unique_ptr<graphics::Dx12DumpResources> dump_resources = gfxrecon::graphics::Dx12DumpResources::Create(config);

    auto queue_extra_info = GetExtraInfo<D3D12CommandQueueInfo>(queue_object_info);
    if (queue_extra_info->pending_events.empty())
    {
        dump_resources->WriteResources(track_dump_resources_);
        track_dump_resources_.Clear();
    }
    else
    {
        auto queue_sync_event = QueueSyncEventInfo{ false, false, nullptr, 0, [&]() {
                                                       dump_resources->WriteResources(track_dump_resources_);
                                                       track_dump_resources_.Clear();
                                                   } };

        queue_extra_info->pending_events.push_back(queue_sync_event);
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
