/*
** Copyright (c) 2021 LunarG, Inc.
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
#include "util/platform.h"

#include <cassert>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

constexpr int32_t  kDefaultWindowPositionX = 0;
constexpr int32_t  kDefaultWindowPositionY = 0;
constexpr uint32_t kDefaultWaitTimeout     = 256;

constexpr uint64_t kInternalEventId = static_cast<uint64_t>(~0);

Dx12ReplayConsumerBase::Dx12ReplayConsumerBase(WindowFactory* window_factory, const DxReplayOptions& options) :
    window_factory_(window_factory), options_(options)
{
    if (options_.enable_validation_layer)
    {
        ID3D12Debug* dx12_debug = nullptr;
        if (SUCCEEDED(D3D12GetDebugInterface(IID_PPV_ARGS(&dx12_debug))))
        {
            dx12_debug->EnableDebugLayer();
            dx12_debug->Release();
        }
        else
        {
            GFXRECON_LOG_WARNING("Failed to enable D3D12 debug layer for replay option '--validate'.");
            options_.enable_validation_layer = false;
        }
    }
}

Dx12ReplayConsumerBase::~Dx12ReplayConsumerBase()
{
    DestroyActiveObjects();
    DestroyActiveWindows();
    DestroyActiveEvents();
    DestroyHeapAllocations();
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
        auto mapped_pointer = reinterpret_cast<uint8_t*>(entry->second) + offset;

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

void Dx12ReplayConsumerBase::MapCpuDescriptorHandle(D3D12_CPU_DESCRIPTOR_HANDLE& handle)
{
    object_mapping::MapCpuDescriptorHandle(handle, descriptor_map_);
}

void Dx12ReplayConsumerBase::MapCpuDescriptorHandles(D3D12_CPU_DESCRIPTOR_HANDLE* handles, size_t handles_len)
{
    object_mapping::MapCpuDescriptorHandles(handles, handles_len, descriptor_map_);
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

    auto    desc_pointer = desc->GetPointer();
    HRESULT result       = E_FAIL;
    Window* window       = nullptr;

    if (desc_pointer != nullptr)
    {
        window = window_factory_->Create(kDefaultWindowPositionX,
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
                auto     object_info = reinterpret_cast<DxObjectInfo*>(swapchain->GetConsumerData(0));
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
                window_factory_->Destroy(window);
            }
        }
        else
        {
            GFXRECON_LOG_FATAL("Failed to retrieve handle from window");
            window_factory_->Destroy(window);
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
        auto object_info = reinterpret_cast<DxObjectInfo*>(device->GetConsumerData(0));
        assert(object_info != nullptr);

        object_info->extra_info_type = DxObjectInfoType::kID3D12DeviceInfo;
        object_info->extra_info      = new D3D12DeviceInfo;
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

    auto                    replay_object     = static_cast<ID3D12Device*>(replay_object_info->object);
    auto                    replay_result =
        replay_object->CreateCommandQueue(desc->GetPointer(), *riid.decoded_value, command_queue->GetHandlePointer());

    if (SUCCEEDED(replay_result))
    {
        auto command_queue_info = new D3D12CommandQueueInfo;

        // Create the fence for the replay --sync option.
        if (options_.sync_queue_submissions)
        {
            auto fence_result =
                replay_object->CreateFence(0, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&command_queue_info->sync_fence));

            if (FAILED(fence_result))
            {
                GFXRECON_LOG_ERROR("Failed to create ID3D12Fence object for the replay --sync option");
            }
        }

        auto object_info = reinterpret_cast<DxObjectInfo*>(command_queue->GetConsumerData(0));
        assert(object_info != nullptr);

        object_info->extra_info_type = DxObjectInfoType::kID3D12CommandQueueInfo;
        object_info->extra_info      = command_queue_info;
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

    assert((replay_object_info != nullptr) && (replay_object_info->object != nullptr) && (desc != nullptr) &&
           (heap != nullptr));

    auto replay_object = static_cast<ID3D12Device*>(replay_object_info->object);
    auto desc_pointer  = desc->GetPointer();

    auto replay_result =
        replay_object->CreateDescriptorHeap(desc_pointer, *riid.decoded_value, heap->GetHandlePointer());

    if (SUCCEEDED(replay_result) && (desc_pointer != nullptr))
    {
        auto heap_info              = new D3D12DescriptorHeapInfo;
        heap_info->descriptor_type  = desc_pointer->Type;
        heap_info->descriptor_count = desc_pointer->NumDescriptors;

        if ((replay_object_info->extra_info != nullptr) &&
            (replay_object_info->extra_info_type == DxObjectInfoType::kID3D12DeviceInfo))
        {
            auto device_info              = reinterpret_cast<D3D12DeviceInfo*>(replay_object_info->extra_info);
            heap_info->capture_increments = device_info->capture_increments;
            heap_info->replay_increments  = device_info->replay_increments;
        }
        else
        {
            GFXRECON_LOG_FATAL("ID3D12Device object does not have an associated info structure");
        }

        auto object_info = reinterpret_cast<DxObjectInfo*>(heap->GetConsumerData(0));
        assert(object_info != nullptr);

        object_info->extra_info_type = DxObjectInfoType::kID3D12DescriptorHeapInfo;
        object_info->extra_info      = heap_info;
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
        auto object_info = reinterpret_cast<DxObjectInfo*>(fence->GetConsumerData(0));
        assert(object_info != nullptr);

        object_info->extra_info_type = DxObjectInfoType::kID3D12FenceInfo;
        object_info->extra_info      = new D3D12FenceInfo;
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

    if ((replay_object_info->extra_info != nullptr) &&
        (replay_object_info->extra_info_type == DxObjectInfoType::kID3D12DeviceInfo))
    {
        auto device_info = reinterpret_cast<D3D12DeviceInfo*>(replay_object_info->extra_info);
        (*device_info->capture_increments)[descriptor_heap_type] = original_result;
        (*device_info->replay_increments)[descriptor_heap_type]  = replay_result;
    }
    else
    {
        GFXRECON_LOG_FATAL("ID3D12Device object does not have an associated info structure");
    }

    return replay_result;
}

D3D12_CPU_DESCRIPTOR_HANDLE
Dx12ReplayConsumerBase::OverrideGetCPUDescriptorHandleForHeapStart(
    DxObjectInfo* replay_object_info, const Decoded_D3D12_CPU_DESCRIPTOR_HANDLE& original_result)
{
    assert((replay_object_info != nullptr) && (replay_object_info->object != nullptr));

    auto replay_object = static_cast<ID3D12DescriptorHeap*>(replay_object_info->object);

    auto replay_result = replay_object->GetCPUDescriptorHandleForHeapStart();

    if ((replay_object_info->extra_info != nullptr) &&
        (replay_object_info->extra_info_type == DxObjectInfoType::kID3D12DescriptorHeapInfo))
    {
        auto heap_info = reinterpret_cast<D3D12DescriptorHeapInfo*>(replay_object_info->extra_info);

        // Only initialize on the first call.
        if (heap_info->capture_cpu_addr_begin == 0)
        {
            heap_info->capture_cpu_addr_begin = original_result.decoded_value->ptr;

            descriptor_map_.AddCpuDescriptorHeap(*original_result.decoded_value,
                                                 replay_result,
                                                 heap_info->descriptor_type,
                                                 heap_info->descriptor_count,
                                                 heap_info->capture_increments,
                                                 heap_info->replay_increments);
        }
    }
    else
    {
        GFXRECON_LOG_FATAL("ID3D12DescriptorHeap object does not have an associated info structure");
    }

    return replay_result;
}

D3D12_GPU_DESCRIPTOR_HANDLE
Dx12ReplayConsumerBase::OverrideGetGPUDescriptorHandleForHeapStart(
    DxObjectInfo* replay_object_info, const Decoded_D3D12_GPU_DESCRIPTOR_HANDLE& original_result)
{
    assert((replay_object_info != nullptr) && (replay_object_info->object != nullptr));

    auto replay_object = static_cast<ID3D12DescriptorHeap*>(replay_object_info->object);

    auto replay_result = replay_object->GetGPUDescriptorHandleForHeapStart();

    if ((replay_object_info->extra_info != nullptr) &&
        (replay_object_info->extra_info_type == DxObjectInfoType::kID3D12DescriptorHeapInfo))
    {
        auto heap_info = reinterpret_cast<D3D12DescriptorHeapInfo*>(replay_object_info->extra_info);

        // Only initialize on the first call.
        if (heap_info->capture_gpu_addr_begin == 0)
        {
            heap_info->capture_gpu_addr_begin = original_result.decoded_value->ptr;

            descriptor_map_.AddGpuDescriptorHeap(*original_result.decoded_value,
                                                 replay_result,
                                                 heap_info->descriptor_type,
                                                 heap_info->descriptor_count,
                                                 heap_info->capture_increments,
                                                 heap_info->replay_increments);
        }
    }
    else
    {
        GFXRECON_LOG_FATAL("ID3D12DescriptorHeap object does not have an associated info structure");
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
        auto resource_info = reinterpret_cast<D3D12ResourceInfo*>(replay_object_info->extra_info);

        if (resource_info == nullptr)
        {
            resource_info = new D3D12ResourceInfo;

            replay_object_info->extra_info_type = DxObjectInfoType::kID3D12ResourceInfo;
            replay_object_info->extra_info      = resource_info;
        }

        assert(replay_object_info->extra_info_type == DxObjectInfoType::kID3D12ResourceInfo);

        // Only initialize on the first call.
        if (resource_info->capture_address_ == 0)
        {
            resource_info->capture_address_ = original_result;
            resource_info->replay_address_  = replay_result;

            auto desc = replay_object->GetDesc();
            gpu_va_map_.Add(replay_object, original_result, replay_result, &desc);
        }
    }

    return replay_result;
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
            auto heap_info                 = new D3D12HeapInfo;
            heap_info->external_allocation = entry->second;

            auto object_info = reinterpret_cast<DxObjectInfo*>(heap->GetConsumerData(0));
            assert(object_info != nullptr);

            object_info->extra_info_type = DxObjectInfoType::kID3D12HeapInfo;
            object_info->extra_info      = heap_info;
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
        auto resource_info = reinterpret_cast<D3D12ResourceInfo*>(replay_object_info->extra_info);

        if (resource_info == nullptr)
        {
            resource_info = new D3D12ResourceInfo;

            replay_object_info->extra_info_type = DxObjectInfoType::kID3D12ResourceInfo;
            replay_object_info->extra_info      = resource_info;
        }

        assert(replay_object_info->extra_info_type == DxObjectInfoType::kID3D12ResourceInfo);

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
    auto resource_info = reinterpret_cast<D3D12ResourceInfo*>(replay_object_info->extra_info);

    if (resource_info != nullptr)
    {
        assert(replay_object_info->extra_info_type == DxObjectInfoType::kID3D12ResourceInfo);

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
        if ((replay_object_info->extra_info != nullptr) &&
            (replay_object_info->extra_info_type == DxObjectInfoType::kID3D12CommandQueueInfo))
        {
            auto command_queue_info = reinterpret_cast<D3D12CommandQueueInfo*>(replay_object_info->extra_info);
            auto sync_event         = GetEventObject(kInternalEventId, true);

            if (sync_event != nullptr)
            {
                auto& sync_fence = command_queue_info->sync_fence;

                replay_object->Signal(sync_fence, ++command_queue_info->sync_value);
                sync_fence->SetEventOnCompletion(command_queue_info->sync_value, sync_event);
                WaitForSingleObject(sync_event, INFINITE);
            }
            else
            {
                GFXRECON_LOG_ERROR("Failed to create synchronization event object for the replay --sync option");
            }
        }
        else
        {
            GFXRECON_LOG_FATAL("ID3D12CommandList object %" PRId64 " does not have an associated info structure",
                               replay_object_info->capture_id);
        }
    }
}

HRESULT Dx12ReplayConsumerBase::OverrideCommandQueueSignal(DxObjectInfo* replay_object_info,
                                                           HRESULT       original_result,
                                                           DxObjectInfo* fence_info,
                                                           UINT64        value)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

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
        ProcessFenceSignal(fence_info, value);
    }

    return replay_result;
}

UINT64 Dx12ReplayConsumerBase::OverrideGetCompletedValue(DxObjectInfo* replay_object_info, UINT64 original_result)
{
    assert((replay_object_info != nullptr) && (replay_object_info->object != nullptr));

    auto replay_object = static_cast<ID3D12Fence*>(replay_object_info->object);
    auto replay_result = replay_object->GetCompletedValue();

    if (original_result > replay_result)
    {
        if ((replay_object_info->extra_info != nullptr) &&
            (replay_object_info->extra_info_type == DxObjectInfoType::kID3D12FenceInfo))
        {
            // Replay is ahead of capture, so wait on the fence value to avoid performing any new work that may
            // invalidate work in progress.
            auto fence_info   = reinterpret_cast<D3D12FenceInfo*>(replay_object_info->extra_info);
            auto event_handle = fence_info->completion_event;

            if (event_handle != nullptr)
            {
                ResetEvent(event_handle);
            }
            else
            {
                event_handle                 = CreateEventA(nullptr, TRUE, FALSE, nullptr);
                fence_info->completion_event = event_handle;
            }

            if (event_handle != nullptr)
            {
                replay_object->SetEventOnCompletion(original_result, event_handle);
                auto wait_result = WaitForSingleObject(event_handle, kDefaultWaitTimeout);

                if (wait_result == WAIT_TIMEOUT)
                {
                    GFXRECON_LOG_DEBUG("Wait operation timed out for ID3D12Fence object %" PRId64 " synchronization",
                                       replay_object_info->capture_id);
                }
            }
            else
            {
                GFXRECON_LOG_FATAL("Failed to create event for ID3D12Fence object %" PRId64 " synchronization",
                                   replay_object_info->capture_id);
            }

            // Clear pending wait/signal entries for values that have completed, which may not have been waited on
            // by the application.
            auto& signaled_values = fence_info->signaled_values;
            auto  signaled_entry  = signaled_values.lower_bound(original_result);
            if (signaled_entry != signaled_values.end())
            {
                signaled_values.erase(signaled_values.begin(), signaled_entry);
            }

            auto& event_objects = fence_info->event_objects;
            auto  event_entry   = event_objects.lower_bound(original_result);
            if (event_entry != event_objects.end())
            {
                event_objects.erase(event_objects.begin(), event_entry);
            }
        }
        else
        {
            GFXRECON_LOG_FATAL("ID3D12Fence object %" PRId64 " does not have an associated info structure",
                               replay_object_info->capture_id);
        }
    }

    return replay_result;
}

HRESULT Dx12ReplayConsumerBase::OverrideSetEventOnCompletion(DxObjectInfo* replay_object_info,
                                                             HRESULT       original_result,
                                                             UINT64        value,
                                                             uint64_t      event_id)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((replay_object_info != nullptr) && (replay_object_info->object != nullptr));

    auto   replay_object = static_cast<ID3D12Fence*>(replay_object_info->object);
    HANDLE event_object  = GetEventObject(event_id, true);

    auto replay_result = replay_object->SetEventOnCompletion(value, event_object);

    if (SUCCEEDED(replay_result) && (event_object != nullptr))
    {
        if ((replay_object_info->extra_info != nullptr) &&
            (replay_object_info->extra_info_type == DxObjectInfoType::kID3D12FenceInfo))
        {
            auto fence_info    = reinterpret_cast<D3D12FenceInfo*>(replay_object_info->extra_info);
            auto pending_entry = fence_info->signaled_values.find(value);

            if (pending_entry != fence_info->signaled_values.end())
            {
                // The value has already been signaled, so it can be waited on immediately.
                auto wait_result = WaitForSingleObject(event_object, kDefaultWaitTimeout);

                if (wait_result == WAIT_TIMEOUT)
                {
                    GFXRECON_LOG_DEBUG("Wait operation timed out for ID3D12Fence object %" PRId64 " synchronization",
                                       replay_object_info->capture_id);
                }

                fence_info->signaled_values.erase(pending_entry);
            }
            else
            {
                // Store the event handle so that it can be waited on after the fence is signaled.
                fence_info->event_objects[value] = event_object;
            }
        }
        else
        {
            GFXRECON_LOG_FATAL("ID3D12Fence object %" PRId64 " does not have an associated info structure",
                               replay_object_info->capture_id);
        }
    }

    return replay_result;
}

HRESULT
Dx12ReplayConsumerBase::OverrideFenceSignal(DxObjectInfo* replay_object_info, HRESULT original_result, UINT64 value)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

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
        if ((replay_object_info->extra_info != nullptr) &&
            (replay_object_info->extra_info_type == DxObjectInfoType::kIDxgiSwapchainInfo))
        {
            auto swapchain_info = reinterpret_cast<DxgiSwapchainInfo*>(replay_object_info->extra_info);

            if (swapchain_info->images[buffer] == nullptr)
            {
                auto object_info = reinterpret_cast<DxObjectInfo*>(surface->GetConsumerData(0));

                // Increment the replay reference to prevent the swapchain image info entry from being removed from the
                // object info table while the swapchain is active.
                ++object_info->extra_ref;
                swapchain_info->images[buffer] = object_info;
            }
        }
        else
        {
            GFXRECON_LOG_FATAL("IDXGISwapChain object %" PRId64 " does not have an associated info structure",
                               replay_object_info->capture_id);
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

    auto replay_object = static_cast<IDXGISwapChain3*>(replay_object_info->object);
    auto replay_result = replay_object->ResizeBuffers1(
        buffer_count, width, height, new_format, flags, node_mask->GetPointer(), present_queue->GetHandlePointer());

    if (SUCCEEDED(replay_result))
    {
        ResetSwapchainImages(replay_object_info, buffer_count, width, height);
    }

    return replay_result;
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

    auto    desc_pointer = desc->GetPointer();
    HRESULT result       = E_FAIL;
    Window* window       = nullptr;

    if (desc_pointer != nullptr)
    {
        window = window_factory_->Create(
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

            result = replay_object->CreateSwapChainForHwnd(device,
                                                           hwnd,
                                                           desc_pointer,
                                                           full_screen_desc->GetPointer(),
                                                           restrict_to_output,
                                                           swapchain->GetHandlePointer());

            if (SUCCEEDED(result))
            {
                auto object_info = reinterpret_cast<DxObjectInfo*>(swapchain->GetConsumerData(0));
                SetSwapchainInfo(object_info, window, hwnd_id, hwnd, desc_pointer->BufferCount);
            }
            else
            {
                window_factory_->Destroy(window);
            }
        }
        else
        {
            GFXRECON_LOG_FATAL("Failed to retrieve handle from window");
            window_factory_->Destroy(window);
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

            auto swapchain_info         = new DxgiSwapchainInfo;
            swapchain_info->window      = window;
            swapchain_info->hwnd_id     = hwnd_id;
            swapchain_info->image_count = image_count;
            swapchain_info->images      = std::make_unique<DxObjectInfo*[]>(image_count);

            info->extra_info_type = DxObjectInfoType::kIDxgiSwapchainInfo;
            info->extra_info      = swapchain_info;

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
    if ((info != nullptr) && (info->extra_info != nullptr) &&
        (info->extra_info_type == DxObjectInfoType::kIDxgiSwapchainInfo))
    {
        auto swapchain_info = reinterpret_cast<DxgiSwapchainInfo*>(info->extra_info);

        // Clear the old info entries from the object info table and reset the swapchain info's image count.
        ReleaseSwapchainImages(swapchain_info);

        swapchain_info->image_count = buffer_count;
        swapchain_info->images      = std::make_unique<DxObjectInfo*[]>(buffer_count);

        // Resize the swapchain's window.
        swapchain_info->window->SetSize(width, height);
    }
    else
    {
        GFXRECON_LOG_FATAL("IDXGISwapChain object %" PRId64 " does not have an associated info structure",
                           info->capture_id);
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

void Dx12ReplayConsumerBase::DestroyObjectExtraInfo(DxObjectInfo* info, bool release_extra_refs)
{
    if (info->extra_info != nullptr)
    {
        if (info->extra_info_type == DxObjectInfoType::kID3D12ResourceInfo)
        {
            auto resource_info = reinterpret_cast<D3D12ResourceInfo*>(info->extra_info);

            if (resource_info->capture_address_ != 0)
            {
                gpu_va_map_.Remove(static_cast<ID3D12Resource*>(info->object));
            }

            for (const auto& entry : resource_info->mapped_memory_info)
            {
                auto& mapped_info = entry.second;
                mapped_memory_.erase(mapped_info.memory_id);
            }

            delete resource_info;
        }
        else if (info->extra_info_type == DxObjectInfoType::kID3D12FenceInfo)
        {
            auto fence_info = reinterpret_cast<D3D12FenceInfo*>(info->extra_info);

            if (fence_info->completion_event != nullptr)
            {
                CloseHandle(fence_info->completion_event);
            }

            delete fence_info;
        }
        else if (info->extra_info_type == DxObjectInfoType::kID3D12DescriptorHeapInfo)
        {
            auto heap_info = reinterpret_cast<D3D12DescriptorHeapInfo*>(info->extra_info);
            descriptor_map_.RemoveCpuDescriptorHeap(heap_info->capture_cpu_addr_begin);
            descriptor_map_.RemoveGpuDescriptorHeap(heap_info->capture_gpu_addr_begin);
            delete heap_info;
        }
        else if (info->extra_info_type == DxObjectInfoType::kID3D12HeapInfo)
        {
            auto heap_info = reinterpret_cast<D3D12HeapInfo*>(info->extra_info);

            if (heap_info->external_allocation != nullptr)
            {
                VirtualFree(heap_info->external_allocation, 0, MEM_RELEASE);
            }

            delete heap_info;
        }
        else if (info->extra_info_type == DxObjectInfoType::kID3D12CommandQueueInfo)
        {
            auto command_list_info = reinterpret_cast<D3D12CommandQueueInfo*>(info->extra_info);
            delete command_list_info;
        }
        else if (info->extra_info_type == DxObjectInfoType::kID3D12DeviceInfo)
        {
            auto device_info = reinterpret_cast<D3D12DeviceInfo*>(info->extra_info);
            delete device_info;
        }
        else if (info->extra_info_type == DxObjectInfoType::kIDxgiSwapchainInfo)
        {
            auto swapchain_info = reinterpret_cast<DxgiSwapchainInfo*>(info->extra_info);

            if (release_extra_refs)
            {
                ReleaseSwapchainImages(swapchain_info);
            }

            window_factory_->Destroy(swapchain_info->window);
            active_windows_.erase(swapchain_info->window);

            if (swapchain_info->hwnd_id != 0)
            {
                window_handles_.erase(swapchain_info->hwnd_id);
            }

            delete swapchain_info;
        }
        else
        {
            GFXRECON_LOG_ERROR("Failed to destroy extra object info for unrecognized object info type %d",
                               info->extra_info_type);
        }

        info->extra_info_type = DxObjectInfoType::kUnused;
        info->extra_info      = nullptr;
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
    for (auto window : active_windows_)
    {
        window_factory_->Destroy(window);
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

void Dx12ReplayConsumerBase::ProcessFenceSignal(DxObjectInfo* info, uint64_t value)
{
    if (info != nullptr)
    {
        if ((info->extra_info != nullptr) && (info->extra_info_type == DxObjectInfoType::kID3D12FenceInfo))
        {
            auto fence_info  = reinterpret_cast<D3D12FenceInfo*>(info->extra_info);
            auto event_entry = fence_info->event_objects.find(value);

            if (event_entry != fence_info->event_objects.end())
            {
                // An event is already waiting to be signaled, so it can be waited on immediately.
                auto wait_result = WaitForSingleObject(event_entry->second, kDefaultWaitTimeout);

                if (wait_result == WAIT_TIMEOUT)
                {
                    GFXRECON_LOG_DEBUG("Wait operation timed out for ID3D12Fence object %" PRId64 " synchronization",
                                       info->capture_id);
                }

                fence_info->event_objects.erase(event_entry);
            }
            else
            {
                // Store the value so that a wait can be performed when an event is associated with it.
                fence_info->signaled_values.insert(value);
            }
        }
        else
        {
            GFXRECON_LOG_FATAL("ID3D12Fence object %" PRId64 " does not have an associated info structure",
                               info->capture_id);
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

void Dx12ReplayConsumerBase::RaiseFatalError(const char* message) const
{
    // TODO: Should there be a default action if no error handler has been provided?
    if (fatal_error_handler_ != nullptr)
    {
        fatal_error_handler_(message);
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
