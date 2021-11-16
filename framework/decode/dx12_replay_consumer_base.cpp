/*
** Copyright (c) 2021 LunarG, Inc.
** Copyright (c) 2021 Advanced Micro Devices, Inc. All rights reserved.
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
#include "graphics/dx12_util.h"
#include "graphics/dx12_image_renderer.h"
#include "util/gpu_va_range.h"
#include "util/platform.h"
#include "util/file_path.h"
#include "util/image_writer.h"

#include <dxgidebug.h>

#include <cassert>

#include <wrl/client.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

constexpr int32_t  kDefaultWindowPositionX = 0;
constexpr int32_t  kDefaultWindowPositionY = 0;
constexpr uint32_t kDefaultWaitTimeout     = INFINITE;

constexpr uint64_t kInternalEventId = static_cast<uint64_t>(~0);

template <typename T>
T* GetExtraInfo(DxObjectInfo* info)
{
    if ((info != nullptr) && (info->extra_info != nullptr) && (info->extra_info->extra_info_type == T::kType))
    {
        return static_cast<T*>(info->extra_info.get());
    }

    GFXRECON_LOG_FATAL("%s object does not have an associated info structure", T::kObjectType);

    return nullptr;
}

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
    WaitIdle();
    DestroyActiveObjects();
    DestroyActiveWindows();
    DestroyActiveEvents();
    DestroyHeapAllocations();
    if (info_queue_ != nullptr)
    {
        info_queue_->Release();
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
        auto mapped_pointer = static_cast<uint8_t*>(entry->second) + offset;

        util::platform::MemoryCopy(mapped_pointer, copy_size, data, copy_size);
    }
    else
    {
        GFXRECON_LOG_WARNING("Skipping memory fill for unrecognized mapped memory object (ID = %" PRIu64 ")",
                             memory_id);
    }
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

void Dx12ReplayConsumerBase::ApplyResourceInitInfo()
{
    if (resource_init_info_.resource != nullptr)
    {
        resource_data_util_->WriteToResource(resource_init_info_.resource,
                                             resource_init_info_.try_map_and_copy,
                                             resource_init_info_.before_states,
                                             resource_init_info_.after_states,
                                             resource_init_info_.data,
                                             resource_init_info_.subresource_offsets,
                                             resource_init_info_.subresource_sizes);
    }
    resource_init_info_.Reset();
}

void Dx12ReplayConsumerBase::ProcessBeginResourceInitCommand(format::HandleId device_id,
                                                             uint64_t         max_resource_size,
                                                             uint64_t         max_copy_size)
{
    GFXRECON_UNREFERENCED_PARAMETER(max_copy_size);
    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, max_resource_size);

    auto device = MapObject<ID3D12Device>(device_id);

    resource_init_info_ = {};
    resource_init_info_.data.reserve(static_cast<size_t>(max_resource_size));
    resource_data_util_ = std::make_unique<graphics::Dx12ResourceDataUtil>(device, max_resource_size);
}

void Dx12ReplayConsumerBase::ProcessEndResourceInitCommand(format::HandleId device_id)
{
    ApplyResourceInitInfo();
    resource_data_util_ = nullptr;
}

void Dx12ReplayConsumerBase::ProcessInitSubresourceCommand(const format::InitSubresourceCommandHeader& command_header,
                                                           const uint8_t*                              data)
{
    HRESULT result = E_FAIL;

    auto device        = MapObject<ID3D12Device>(command_header.device_id);
    auto resource_info = GetObjectInfo(command_header.resource_id);
    auto resource      = static_cast<ID3D12Resource*>(resource_info->object);

    GFXRECON_ASSERT(MapObject<ID3D12Resource>(command_header.resource_id) == resource);

    // If a new resource is encountered, write the current resource and track the new resource init info.
    if (resource_init_info_.resource != resource)
    {
        ApplyResourceInitInfo();
        resource_init_info_.resource = resource;

        bool is_reserved_resource = false;
        if (resource_info->extra_info != nullptr)
        {
            is_reserved_resource = GetExtraInfo<D3D12ResourceInfo>(resource_info)->is_reserved_resource;
        }
        resource_init_info_.try_map_and_copy = !is_reserved_resource;
    }

    resource_init_info_.before_states.push_back(
        { static_cast<D3D12_RESOURCE_STATES>(command_header.initial_state), D3D12_RESOURCE_BARRIER_FLAG_NONE });
    resource_init_info_.after_states.push_back(
        { static_cast<D3D12_RESOURCE_STATES>(command_header.resource_state),
          static_cast<D3D12_RESOURCE_BARRIER_FLAGS>(command_header.barrier_flags) });
    resource_init_info_.subresource_offsets.push_back(resource_init_info_.data.size());
    resource_init_info_.subresource_sizes.push_back(command_header.data_size);
    resource_init_info_.data.insert(resource_init_info_.data.end(), data, data + command_header.data_size);
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

void Dx12ReplayConsumerBase::MapGpuDescriptorHandles(D3D12_GPU_DESCRIPTOR_HANDLE* handles, size_t handles_len)
{
    object_mapping::MapGpuDescriptorHandles(handles, handles_len, descriptor_map_);
}

void Dx12ReplayConsumerBase::MapGpuVirtualAddress(D3D12_GPU_VIRTUAL_ADDRESS& address)
{
    object_mapping::MapGpuVirtualAddress(address, gpu_va_map_);
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
        if (replay_result == DXGI_ERROR_DEVICE_REMOVED)
        {
            GFXRECON_LOG_FATAL(
                "%s returned %s, which does not match the value returned at capture %s.  Replay cannot continue.",
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

void Dx12ReplayConsumerBase::PostPresent(IDXGISwapChain* swapchain)
{
    ReadDebugMessages();

    if (screenshot_handler_ != nullptr)
    {
        if (screenshot_handler_->IsScreenshotFrame())
        {
            if (!direct_queues_.empty())
            {
                graphics::dx12::TakeScreenshot(frame_buffer_renderer_,
                                               direct_queues_.back(),
                                               swapchain,
                                               screenshot_handler_->GetCurrentFrame(),
                                               screenshot_file_prefix_);
            }
        }

        screenshot_handler_->EndFrame();
    }
}

HRESULT Dx12ReplayConsumerBase::OverridePresent(DxObjectInfo* replay_object_info,
                                                HRESULT       original_result,
                                                UINT          sync_interval,
                                                UINT          flags)
{
    auto replay_object = static_cast<IDXGISwapChain*>(replay_object_info->object);
    auto result        = replay_object->Present(sync_interval, flags);

    PostPresent(replay_object);

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
    auto result        = replay_object->Present1(sync_interval, flags, present_parameters->GetPointer());

    PostPresent(replay_object);

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
    auto    wsi_context    = application_ ? application_->GetWsiContext() : nullptr;
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

                SetSwapchainInfo(object_info, window, hwnd_id, hwnd, desc_pointer->BufferCount);
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

    assert(device != nullptr);

    IUnknown* adapter = nullptr;
    if (adapter_info != nullptr)
    {
        adapter = adapter_info->object;
    }

    auto replay_result =
        D3D12CreateDevice(adapter, minimum_feature_level, *riid.decoded_value, device->GetHandlePointer());

    if (SUCCEEDED(replay_result) && !device->IsNull())
    {
        SetExtraInfo(device, std::make_unique<D3D12DeviceInfo>());
    }

    return replay_result;
}

HRESULT Dx12ReplayConsumerBase::OverrideCreateCommandQueue(DxObjectInfo* replay_object_info,
                                                           HRESULT       original_result,
                                                           StructPointerDecoder<Decoded_D3D12_COMMAND_QUEUE_DESC>* desc,
                                                           Decoded_GUID                                            riid,
                                                           HandlePointerDecoder<void*>* command_queue)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((replay_object_info != nullptr) && (replay_object_info->object != nullptr) && (desc != nullptr) &&
           (command_queue != nullptr));

    auto replay_object = static_cast<ID3D12Device*>(replay_object_info->object);
    auto replay_result =
        replay_object->CreateCommandQueue(desc->GetPointer(), *riid.decoded_value, command_queue->GetHandlePointer());

    if (SUCCEEDED(replay_result))
    {
        if (desc->GetPointer()->Type == D3D12_COMMAND_LIST_TYPE_DIRECT)
        {
            graphics::dx12::ID3D12CommandQueueComPtr direct_queue =
                static_cast<ID3D12CommandQueue*>(*command_queue->GetHandlePointer());

            direct_queues_.push_back(direct_queue);
        }

        auto command_queue_info = std::make_unique<D3D12CommandQueueInfo>();

        // Create the fence for the replay --sync option.
        if (options_.sync_queue_submissions)
        {
            auto fence_result =
                replay_object->CreateFence(0, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&command_queue_info->sync_fence));

            if (SUCCEEDED(fence_result))
            {
                command_queue_info->sync_event = CreateEventA(nullptr, TRUE, FALSE, nullptr);

                // Initialize the fence info object that will be added to D3D12CommandQueueInfo::pending_events when the
                // queue has outstanding wait operations.
                command_queue_info->sync_fence_info.object     = command_queue_info->sync_fence;
                command_queue_info->sync_fence_info.extra_info = std::make_unique<D3D12FenceInfo>();
            }
            else
            {
                GFXRECON_LOG_ERROR("Failed to create ID3D12Fence object for the replay --sync option");
            }
        }

        SetExtraInfo(command_queue, std::move(command_queue_info));
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

HRESULT
Dx12ReplayConsumerBase::OverrideCreateCommittedResource(
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
    assert((replay_object_info != nullptr) && (replay_object_info->object != nullptr) && (read_range != nullptr) &&
           (data != nullptr));

    auto id_pointer    = data->GetPointer();
    auto data_pointer  = data->GetOutputPointer();
    auto replay_object = static_cast<ID3D12Resource*>(replay_object_info->object);

    auto result = replay_object->Map(subresource, read_range->GetPointer(), data_pointer);

    if (SUCCEEDED(result) && (id_pointer != nullptr) && (data_pointer != nullptr) && (*data_pointer != nullptr))
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

        mapped_memory_[*id_pointer] = *data_pointer;
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
                                                   uint64_t                                 src_data,
                                                   UINT                                     src_row_pitch,
                                                   UINT                                     src_depth_pitch)
{
    GFXRECON_UNREFERENCED_PARAMETER(replay_object_info);
    GFXRECON_UNREFERENCED_PARAMETER(original_result);
    GFXRECON_UNREFERENCED_PARAMETER(dst_subresource);
    GFXRECON_UNREFERENCED_PARAMETER(dst_box);
    GFXRECON_UNREFERENCED_PARAMETER(src_data);
    GFXRECON_UNREFERENCED_PARAMETER(src_row_pitch);
    GFXRECON_UNREFERENCED_PARAMETER(src_depth_pitch);

    // TODO(GH-71): Implement function
    return E_FAIL;
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

    // TODO(GH-71): Implement function
    return E_FAIL;
}

void Dx12ReplayConsumerBase::OverrideExecuteCommandLists(DxObjectInfo*                             replay_object_info,
                                                         UINT                                      num_command_lists,
                                                         HandlePointerDecoder<ID3D12CommandList*>* command_lists)
{
    assert((replay_object_info != nullptr) && (replay_object_info->object != nullptr) && (command_lists != nullptr));

    auto replay_object = static_cast<ID3D12CommandQueue*>(replay_object_info->object);

    replay_object->ExecuteCommandLists(num_command_lists, command_lists->GetHandlePointer());

    if (options_.sync_queue_submissions && !command_lists->IsNull())
    {
        auto command_queue_info = GetExtraInfo<D3D12CommandQueueInfo>(replay_object_info);
        if (command_queue_info != nullptr)
        {
            auto sync_event = command_queue_info->sync_event;
            if (sync_event != nullptr)
            {
                auto& sync_fence = command_queue_info->sync_fence;

                replay_object->Signal(sync_fence, ++command_queue_info->sync_value);

                ResetEvent(sync_event);
                sync_fence->SetEventOnCompletion(command_queue_info->sync_value, sync_event);

                if (command_queue_info->pending_events.empty())
                {
                    // There are no outstanding waits on the queue, so the event can be waited on immediately.
                    WaitForSingleObject(sync_event, INFINITE);
                }
                else
                {
                    // There are outstanding waits on the queue.  The sync signal won't be processed until the
                    // outstanding waits are signaled, so the sync signal will be added to the pending operation queue.
                    auto fence_info = GetExtraInfo<D3D12FenceInfo>(&command_queue_info->sync_fence_info);
                    if (fence_info != nullptr)
                    {
                        auto& waiting_objects = fence_info->waiting_objects[command_queue_info->sync_value];
                        waiting_objects.wait_events.push_back(sync_event);
                    }

                    command_queue_info->pending_events.emplace_back(QueueSyncEventInfo{
                        false, false, &command_queue_info->sync_fence_info, command_queue_info->sync_value });
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
            if (swapchain_info->images[buffer] == nullptr)
            {
                auto object_info = static_cast<DxObjectInfo*>(surface->GetConsumerData(0));

                // Increment the replay reference to prevent the swapchain image info entry from being removed from the
                // object info table while the swapchain is active.
                ++object_info->extra_ref;
                swapchain_info->images[buffer] = object_info;
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
        if (options_.discard_cached_psos)
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
        if (options_.discard_cached_psos)
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

    if ((original_result != 0) && (new_shader_identifier_ptr != 0))
    {
        shader_id_map_.Add(replay_object_info->capture_id, original_result->GetPointer(), new_shader_identifier_ptr);
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
    auto    wsi_context    = application_ ? application_->GetWsiContext() : nullptr;
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

            auto desc = full_screen_desc->GetPointer();
            if (options_.force_windowed)
            {
                desc = nullptr;
            }
            result = replay_object->CreateSwapChainForHwnd(
                device, hwnd, desc_pointer, desc, restrict_to_output, swapchain->GetHandlePointer());

            if (SUCCEEDED(result))
            {
                auto object_info = static_cast<DxObjectInfo*>(swapchain->GetConsumerData(0));
                SetSwapchainInfo(object_info, window, hwnd_id, hwnd, desc_pointer->BufferCount);
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

void Dx12ReplayConsumerBase::SetSwapchainInfo(
    DxObjectInfo* info, Window* window, uint64_t hwnd_id, HWND hwnd, uint32_t image_count)
{
    if (window != nullptr)
    {
        if (info != nullptr)
        {
            assert(info->extra_info == nullptr);

            auto swapchain_info         = std::make_unique<DxgiSwapchainInfo>();
            swapchain_info->window      = window;
            swapchain_info->hwnd_id     = hwnd_id;
            swapchain_info->image_count = image_count;
            swapchain_info->images      = std::make_unique<DxObjectInfo*[]>(image_count);

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
        // Clear the old info entries from the object info table and reset the swapchain info's image count.
        ReleaseSwapchainImages(swapchain_info);

        swapchain_info->image_count = buffer_count;
        swapchain_info->images      = std::make_unique<DxObjectInfo*[]>(buffer_count);

        // Resize the swapchain's window.
        swapchain_info->window->SetSize(width, height);
    }
}

void Dx12ReplayConsumerBase::ReleaseSwapchainImages(DxgiSwapchainInfo* info)
{
    if ((info != nullptr) && (info->images != nullptr))
    {
        for (uint32_t i = 0; i < info->image_count; ++i)
        {
            auto image_info = info->images[i];
            if ((image_info != nullptr) && (image_info->extra_ref > 0))
            {
                --(image_info->extra_ref);
                if ((image_info->ref_count == 0) && (image_info->extra_ref == 0))
                {
                    RemoveObject(image_info);
                }
            }
        }

        info->images.reset();
    }
}

void Dx12ReplayConsumerBase::WaitIdle()
{
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
                                WaitForSingleObject(sync_event, INFINITE);
                            }
                        }
                    }
                    else
                    {
                        // The --sync option was specified, so the queue already has a fence for synchronization.
                        auto& sync_fence = queue_info->sync_fence;
                        queue->Signal(sync_fence, ++queue_info->sync_value);
                        sync_fence->SetEventOnCompletion(queue_info->sync_value, sync_event);
                        WaitForSingleObject(sync_event, INFINITE);
                    }
                }
            }
        }
    }
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
                gpu_va_map_.Remove(info->capture_id, resource_info->capture_address_);
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

            if (release_extra_refs)
            {
                ReleaseSwapchainImages(swapchain_info);
            }
            auto wsi_context    = application_ ? application_->GetWsiContext() : nullptr;
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
    auto wsi_context    = application_ ? application_->GetWsiContext() : nullptr;
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
            queue_extra_info->pending_events.emplace_back(QueueSyncEventInfo{ false, false, fence_info, value });
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
            queue_extra_info->pending_events.emplace_back(QueueSyncEventInfo{ true, false, fence_info, value });

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
        auto range_begin = fence_info->waiting_objects.begin();
        auto range_end   = fence_info->waiting_objects.upper_bound(value);
        if (range_begin != range_end)
        {
            for (auto iter = range_begin; iter != range_end; ++iter)
            {
                auto& waiting_objects = iter->second;

                for (auto event_object : waiting_objects.wait_events)
                {
                    WaitForFenceEvent(info->capture_id, event_object);
                }

                for (auto queue_info : waiting_objects.wait_queues)
                {
                    SignalWaitingQueue(queue_info, info, value);
                }
            }

            fence_info->waiting_objects.erase(range_begin, range_end);
        }

        fence_info->last_signaled_value = value;
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
                // If this is a signal operation, we can schedule the signal with the fence.
                auto signal_fence_info = front.fence_info;
                auto signal_value      = front.value;

                event_queue.pop_front();

                ProcessFenceSignal(front.fence_info, front.value);
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
    if (options_.discard_cached_psos)
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
    if (options_.discard_cached_psos)
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

    auto    swapchain     = static_cast<IDXGISwapChain*>(swapchain_info->object);
    HRESULT replay_result = S_OK;
    if (options_.force_windowed)
    {
        replay_result = swapchain->SetFullscreenState(FALSE, nullptr);
    }
    else
    {
        IDXGIOutput* in_pTarget = nullptr;
        if (pTarget && pTarget->object)
        {
            in_pTarget = static_cast<IDXGIOutput*>(pTarget->object);
        }
        replay_result = swapchain->SetFullscreenState(Fullscreen, in_pTarget);
        CheckReplayResult("IDXGISwapChain::SetFullscreenState", original_result, replay_result);
    }
    return replay_result;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
