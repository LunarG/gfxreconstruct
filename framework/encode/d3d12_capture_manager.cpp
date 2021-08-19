/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2021 LunarG, Inc.
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

#include "encode/d3d12_capture_manager.h"

#include "graphics/dx12_util.h"
#include "encode/custom_dx12_struct_unwrappers.h"
#include "encode/dx12_object_wrapper_info.h"
#include "encode/dx12_state_writer.h"
#include "generated/generated_dx12_wrapper_creators.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

D3D12CaptureManager*  D3D12CaptureManager::instance_   = nullptr;
thread_local uint32_t D3D12CaptureManager::call_scope_ = 0;

D3D12CaptureManager::D3D12CaptureManager() :
    CaptureManager(format::ApiFamilyId::ApiFamily_D3D12), dxgi_dispatch_table_{}, d3d12_dispatch_table_{},
    debug_layer_enabled_(false), debug_device_lost_enabled_(false)
{}

bool D3D12CaptureManager::CreateInstance()
{
    return CaptureManager::CreateInstance([]() -> CaptureManager* { return instance_; },
                                          []() {
                                              assert(instance_ == nullptr);
                                              instance_ = new D3D12CaptureManager();
                                          });
}

void D3D12CaptureManager::DestroyInstance()
{
    CaptureManager::DestroyInstance([]() -> const CaptureManager* { return instance_; },
                                    []() {
                                        assert(instance_ != nullptr);
                                        delete instance_;
                                        instance_ = nullptr;
                                    });
}

void D3D12CaptureManager::EndCreateApiCallCapture(HRESULT result, REFIID riid, void** handle)
{
    if (((GetCaptureMode() & kModeTrack) == kModeTrack) && SUCCEEDED(result))
    {
        if ((handle != nullptr) && (*handle != nullptr))
        {
            assert(state_tracker_ != nullptr);

            auto thread_data = GetThreadData();
            assert(thread_data != nullptr);

            state_tracker_->AddEntry(
                riid, handle, thread_data->call_id_, static_cast<void*>(nullptr), thread_data->parameter_buffer_.get());
        }
    }

    EndApiCallCapture();
}

void D3D12CaptureManager::EndCreateDescriptorMethodCallCapture(D3D12_CPU_DESCRIPTOR_HANDLE dest_descriptor,
                                                               ID3D12Device_Wrapper*       create_object_wrapper)
{
    if (((GetCaptureMode() & kModeTrack) == kModeTrack) && (dest_descriptor.ptr != 0))
    {
        auto thread_data = GetThreadData();
        assert(thread_data != nullptr);

        state_tracker_->TrackDescriptorCreation(create_object_wrapper,
                                                thread_data->call_id_,
                                                thread_data->parameter_buffer_.get(),
                                                GetDescriptorInfo(dest_descriptor.ptr));
    }

    EndMethodCallCapture();
}

void D3D12CaptureManager::EndCommandListMethodCallCapture(ID3D12GraphicsCommandList_Wrapper* list_wrapper)
{
    if ((GetCaptureMode() & kModeTrack) == kModeTrack)
    {
        assert(state_tracker_ != nullptr);

        auto thread_data = GetThreadData();
        assert(thread_data != nullptr);

        state_tracker_->TrackCommand(list_wrapper, thread_data->call_id_, thread_data->parameter_buffer_.get());
    }

    EndMethodCallCapture();
}

void D3D12CaptureManager::WriteTrackedState(util::FileOutputStream* file_stream, format::ThreadId thread_id)
{
    Dx12StateWriter state_writer(file_stream, compressor_.get(), thread_id);
    state_tracker_->WriteState(&state_writer, GetCurrentFrame());
}

void D3D12CaptureManager::PreAcquireSwapChainImages(IDXGISwapChain_Wrapper* wrapper,
                                                    IUnknown*               device,
                                                    uint32_t                image_count,
                                                    DXGI_SWAP_EFFECT        swap_effect)
{
    // We only expect to process the DXGI_SWAP_EFFECT_FLIP_* effects with DX12.
    if ((swap_effect != DXGI_SWAP_EFFECT_DISCARD) && (swap_effect != DXGI_SWAP_EFFECT_SEQUENTIAL))
    {
        assert(wrapper != nullptr);

        auto info = wrapper->GetObjectInfo();
        assert(info != nullptr);
        if (device != nullptr)
            info->device_id = GetWrappedId<IUnknown>(device);

        if (info->child_images.empty())
        {
            auto swap_chain = wrapper->GetWrappedObjectAs<IDXGISwapChain>();
            info->child_images.resize(image_count);
            info->swap_effect = swap_effect;

            if ((GetCaptureMode() & kModeTrack) == kModeTrack)
            {
                // TODO: In VK version, this thing is done in InitializeGroupObjectState,
                //       This might need to be removed to InitializeGroupObjectState when it's ready.
                info->image_acquired_info.resize(image_count);
            }

            for (uint32_t i = 0; i < image_count; ++i)
            {
                ID3D12Resource* resource = nullptr;
                auto            result   = swap_chain->GetBuffer(i, IID_PPV_ARGS(&resource));
                if (SUCCEEDED(result))
                {
                    WrapID3D12Resource(IID_PPV_ARGS(&resource), nullptr);

                    // Convert the application reference to an internal-only reference to avoid altering the application
                    // reference count by only holding an internal reference to the wrapped resource.
                    ID3D12Resource_Wrapper* resource_wrapper = reinterpret_cast<ID3D12Resource_Wrapper*>(resource);
                    resource_wrapper->MakeRefInternal();
                    info->child_images[i] = resource_wrapper;

                    // TODO (GH #261): Initialize members of ID3D12ResourceInfo for resource_wrapper in order to track
                    // frame buffer state.
                }
                else
                {
                    if (result == E_NOINTERFACE)
                    {
                        GFXRECON_LOG_WARNING(
                            "IDXGISwapChain::GetBuffer() returned E_NOINTERFACE when called with IID_ID3D12Resource, "
                            "ensure that the captured application is using the D3D12 API");
                    }
                    else
                    {
                        GFXRECON_LOG_WARNING(
                            "IDXGISwapChain::GetBuffer() failed when attempting to pre-acquire swapchain images");
                    }
                }
            }
        }
    }
}

void D3D12CaptureManager::ReleaseSwapChainImages(IDXGISwapChain_Wrapper* wrapper)
{
    if (wrapper != nullptr)
    {
        auto info = wrapper->GetObjectInfo();
        assert(info != nullptr);

        if (!info->child_images.empty())
        {
            for (auto& resource_wrapper : info->child_images)
            {
                resource_wrapper->ReleaseRefInternal();
            }

            info->child_images.clear();
        }
    }
}

void D3D12CaptureManager::InitializeID3D12ResourceInfo(ID3D12Device_Wrapper*    device_wrapper,
                                                       ID3D12Resource_Wrapper*  resource_wrapper,
                                                       D3D12_RESOURCE_DIMENSION dimension,
                                                       UINT64                   width,
                                                       D3D12_HEAP_TYPE          heap_type,
                                                       D3D12_CPU_PAGE_PROPERTY  page_property,
                                                       D3D12_MEMORY_POOL        memory_pool,
                                                       D3D12_RESOURCE_STATES    initial_state,
                                                       bool                     has_write_watch)
{
    assert(resource_wrapper != nullptr);

    auto info = resource_wrapper->GetObjectInfo();
    assert((info != nullptr) && (device_wrapper != nullptr));

    info->device_id       = device_wrapper->GetCaptureId();
    info->heap_type       = heap_type;
    info->page_property   = page_property;
    info->memory_pool     = memory_pool;
    info->has_write_watch = has_write_watch;

    if (dimension == D3D12_RESOURCE_DIMENSION_BUFFER)
    {
        info->num_subresources     = 1;
        info->mapped_subresources  = std::make_unique<MappedSubresource[]>(info->num_subresources);
        info->subresource_sizes    = std::make_unique<uint64_t[]>(info->num_subresources);
        info->subresource_sizes[0] = width;
    }
    else
    {
        assert((dimension == D3D12_RESOURCE_DIMENSION_TEXTURE1D) || (dimension == D3D12_RESOURCE_DIMENSION_TEXTURE2D) ||
               (dimension == D3D12_RESOURCE_DIMENSION_TEXTURE3D));

        uint32_t plane_count = 1;
        auto     device      = device_wrapper->GetWrappedObjectAs<ID3D12Device>();
        auto     resource    = resource_wrapper->GetWrappedObjectAs<ID3D12Resource>();

        // Retrieve the D3D12_RESOURCE_DESC from the resource, which has MipLevel set to the actual number of
        // miplevels computed by the implementation when the application set it to 0.
        auto full_desc = resource->GetDesc();

        // Get the plane count for the texture format.  With D3D12, each plane has its own subresource.
        D3D12_FEATURE_DATA_FORMAT_INFO format_info = { full_desc.Format, 0 };
        if (SUCCEEDED(device->CheckFeatureSupport(D3D12_FEATURE_FORMAT_INFO, &format_info, sizeof(format_info))))
        {
            plane_count = format_info.PlaneCount;
        }

        auto num_subresources = full_desc.MipLevels * plane_count;

        if ((dimension == D3D12_RESOURCE_DIMENSION_TEXTURE2D) || (dimension == D3D12_RESOURCE_DIMENSION_TEXTURE1D))
        {
            num_subresources *= full_desc.DepthOrArraySize;
        }

        auto layouts = std::make_unique<D3D12_PLACED_SUBRESOURCE_FOOTPRINT[]>(num_subresources);

        device->GetCopyableFootprints(&full_desc, 0, num_subresources, 0, layouts.get(), nullptr, nullptr, nullptr);

        info->num_subresources    = num_subresources;
        info->mapped_subresources = std::make_unique<MappedSubresource[]>(num_subresources);
        info->subresource_sizes   = std::make_unique<uint64_t[]>(num_subresources);

        for (size_t i = 0; i < num_subresources; ++i)
        {
            info->subresource_sizes[i] =
                (static_cast<uint64_t>(layouts[i].Footprint.RowPitch) * layouts[i].Footprint.Height) *
                layouts[i].Footprint.Depth;
        }
    }

    if ((GetCaptureMode() & kModeTrack) == kModeTrack)
    {
        state_tracker_->TrackResourceCreation(resource_wrapper, initial_state);
    }
}

void D3D12CaptureManager::CheckWriteWatchIgnored(D3D12_HEAP_FLAGS flags, format::HandleId id)
{
    // Report that write watch was ignored because the application enabled it.
    if ((GetPageGuardMemoryMode() == kMemoryModeExternal) &&
        ((flags & D3D12_HEAP_FLAG_ALLOW_WRITE_WATCH) == D3D12_HEAP_FLAG_ALLOW_WRITE_WATCH))
    {
        GFXRECON_LOG_WARNING(
            "Write watch memory tracking was disabled for object %" PRId64
            " because the application created the object with the D3D12_HEAP_FLAG_ALLOW_WRITE_WATCH flag",
            id);
    }
}

bool D3D12CaptureManager::UseWriteWatch(D3D12_HEAP_TYPE         type,
                                        D3D12_HEAP_FLAGS        flags,
                                        D3D12_CPU_PAGE_PROPERTY page_property)
{
    if ((GetPageGuardMemoryMode() == kMemoryModeExternal) &&
        ((flags & D3D12_HEAP_FLAG_ALLOW_WRITE_WATCH) != D3D12_HEAP_FLAG_ALLOW_WRITE_WATCH) &&
        IsUploadResource(type, page_property))
    {
        return true;
    }
    return false;
}

void D3D12CaptureManager::EnableWriteWatch(D3D12_HEAP_FLAGS& flags, D3D12_HEAP_PROPERTIES& properties)
{
    // Set the allow write watch flag to enable use of GetWriteWatch with the mapped heap/resource memory.
    flags |= D3D12_HEAP_FLAG_ALLOW_WRITE_WATCH;

    // Change the heap properties for a custom heap type whose memory will not have the PAGE_WRITECOMBINE property, to
    // allow efficent reads when copying modified mapped memory pages to the capture file.
    properties.Type                 = D3D12_HEAP_TYPE_CUSTOM;
    properties.CPUPageProperty      = D3D12_CPU_PAGE_PROPERTY_WRITE_BACK;
    properties.MemoryPoolPreference = D3D12_MEMORY_POOL_L0;
}

bool D3D12CaptureManager::IsUploadResource(D3D12_HEAP_TYPE type, D3D12_CPU_PAGE_PROPERTY page_property)
{
    if ((type == D3D12_HEAP_TYPE_UPLOAD) ||
        ((type == D3D12_HEAP_TYPE_CUSTOM) && (page_property != D3D12_CPU_PAGE_PROPERTY_NOT_AVAILABLE) &&
         (page_property != D3D12_CPU_PAGE_PROPERTY_UNKNOWN)))
    {
        return true;
    }
    return false;
}

void D3D12CaptureManager::PostProcess_IDXGIFactory_CreateSwapChain(IDXGIFactory_Wrapper* wrapper,
                                                                   HRESULT               result,
                                                                   IUnknown*             device,
                                                                   DXGI_SWAP_CHAIN_DESC* desc,
                                                                   IDXGISwapChain**      swap_chain)
{
    GFXRECON_UNREFERENCED_PARAMETER(wrapper);
    GFXRECON_UNREFERENCED_PARAMETER(device);

    if (SUCCEEDED(result) && (desc != nullptr) && (swap_chain != nullptr) && ((*swap_chain) != nullptr))
    {
        auto swap_chain_wrapper = reinterpret_cast<IDXGISwapChain_Wrapper*>(*swap_chain);

        PreAcquireSwapChainImages(swap_chain_wrapper, device, desc->BufferCount, desc->SwapEffect);
    }
}

void D3D12CaptureManager::PostProcess_IDXGIFactory2_CreateSwapChainForHwnd(
    IDXGIFactory2_Wrapper*                 wrapper,
    HRESULT                                result,
    IUnknown*                              device,
    HWND                                   hwnd,
    const DXGI_SWAP_CHAIN_DESC1*           desc,
    const DXGI_SWAP_CHAIN_FULLSCREEN_DESC* fullscreen_desc,
    IDXGIOutput*                           restrict_to_output,
    IDXGISwapChain1**                      swap_chain)
{
    GFXRECON_UNREFERENCED_PARAMETER(wrapper);
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(hwnd);
    GFXRECON_UNREFERENCED_PARAMETER(fullscreen_desc);
    GFXRECON_UNREFERENCED_PARAMETER(restrict_to_output);

    if (SUCCEEDED(result) && (desc != nullptr) && (swap_chain != nullptr) && ((*swap_chain) != nullptr))
    {
        auto swap_chain_wrapper = reinterpret_cast<IDXGISwapChain1_Wrapper*>(*swap_chain);

        PreAcquireSwapChainImages(swap_chain_wrapper, device, desc->BufferCount, desc->SwapEffect);
    }
}

void D3D12CaptureManager::PostProcess_IDXGIFactory2_CreateSwapChainForCoreWindow(IDXGIFactory2_Wrapper*       wrapper,
                                                                                 HRESULT                      result,
                                                                                 IUnknown*                    device,
                                                                                 IUnknown*                    window,
                                                                                 const DXGI_SWAP_CHAIN_DESC1* desc,
                                                                                 IDXGIOutput*      restrict_to_output,
                                                                                 IDXGISwapChain1** swap_chain)
{
    GFXRECON_UNREFERENCED_PARAMETER(wrapper);
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(window);
    GFXRECON_UNREFERENCED_PARAMETER(restrict_to_output);

    if (SUCCEEDED(result) && (desc != nullptr) && (swap_chain != nullptr) && ((*swap_chain) != nullptr))
    {
        auto swap_chain_wrapper = reinterpret_cast<IDXGISwapChain1_Wrapper*>(*swap_chain);

        PreAcquireSwapChainImages(swap_chain_wrapper, device, desc->BufferCount, desc->SwapEffect);
    }
}

void D3D12CaptureManager::PostProcess_IDXGIFactory2_CreateSwapChainForComposition(IDXGIFactory2_Wrapper*       wrapper,
                                                                                  HRESULT                      result,
                                                                                  IUnknown*                    device,
                                                                                  const DXGI_SWAP_CHAIN_DESC1* desc,
                                                                                  IDXGIOutput*      restrict_to_output,
                                                                                  IDXGISwapChain1** swap_chain)
{
    GFXRECON_UNREFERENCED_PARAMETER(wrapper);
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(restrict_to_output);

    if (SUCCEEDED(result) && (desc != nullptr) && (swap_chain != nullptr) && ((*swap_chain) != nullptr))
    {
        auto swap_chain_wrapper = reinterpret_cast<IDXGISwapChain1_Wrapper*>(*swap_chain);

        PreAcquireSwapChainImages(swap_chain_wrapper, device, desc->BufferCount, desc->SwapEffect);
    }
}

void D3D12CaptureManager::PreProcess_IDXGISwapChain_ResizeBuffers(
    IDXGISwapChain_Wrapper* wrapper, UINT buffer_count, UINT width, UINT height, DXGI_FORMAT new_format, UINT flags)
{
    GFXRECON_UNREFERENCED_PARAMETER(width);
    GFXRECON_UNREFERENCED_PARAMETER(height);
    GFXRECON_UNREFERENCED_PARAMETER(new_format);
    GFXRECON_UNREFERENCED_PARAMETER(flags);

    ReleaseSwapChainImages(wrapper);
}

void D3D12CaptureManager::PostProcess_IDXGISwapChain_Present(IDXGISwapChain_Wrapper* wrapper,
                                                             HRESULT                 result,
                                                             UINT                    sync_interval,
                                                             UINT                    flags)
{
    GFXRECON_UNREFERENCED_PARAMETER(wrapper);
    GFXRECON_UNREFERENCED_PARAMETER(result);
    GFXRECON_UNREFERENCED_PARAMETER(sync_interval);
    GFXRECON_UNREFERENCED_PARAMETER(flags);
    EndFrame();
}

void D3D12CaptureManager::PostProcess_IDXGISwapChain1_Present1(IDXGISwapChain_Wrapper*        wrapper,
                                                               HRESULT                        result,
                                                               UINT                           sync_interval,
                                                               UINT                           present_flags,
                                                               const DXGI_PRESENT_PARAMETERS* present_parameters)
{
    GFXRECON_UNREFERENCED_PARAMETER(wrapper);
    GFXRECON_UNREFERENCED_PARAMETER(result);
    GFXRECON_UNREFERENCED_PARAMETER(sync_interval);
    GFXRECON_UNREFERENCED_PARAMETER(present_flags);
    GFXRECON_UNREFERENCED_PARAMETER(present_parameters);
    EndFrame();
}

void D3D12CaptureManager::PostProcess_IDXGISwapChain_ResizeBuffers(IDXGISwapChain_Wrapper* wrapper,
                                                                   HRESULT                 result,
                                                                   UINT                    buffer_count,
                                                                   UINT                    width,
                                                                   UINT                    height,
                                                                   DXGI_FORMAT             new_format,
                                                                   UINT                    flags)
{
    GFXRECON_UNREFERENCED_PARAMETER(width);
    GFXRECON_UNREFERENCED_PARAMETER(height);
    GFXRECON_UNREFERENCED_PARAMETER(new_format);
    GFXRECON_UNREFERENCED_PARAMETER(flags);

    if (SUCCEEDED(result) && (wrapper != nullptr))
    {
        auto info = wrapper->GetObjectInfo();
        assert(info != nullptr);

        PreAcquireSwapChainImages(wrapper, nullptr, buffer_count, info->swap_effect);
    }
}

void D3D12CaptureManager::PreProcess_IDXGISwapChain3_ResizeBuffers1(IDXGISwapChain_Wrapper* wrapper,
                                                                    UINT                    buffer_count,
                                                                    UINT                    width,
                                                                    UINT                    height,
                                                                    DXGI_FORMAT             new_format,
                                                                    UINT                    flags,
                                                                    const UINT*             node_mask,
                                                                    IUnknown* const*        present_queue)
{
    GFXRECON_UNREFERENCED_PARAMETER(width);
    GFXRECON_UNREFERENCED_PARAMETER(height);
    GFXRECON_UNREFERENCED_PARAMETER(new_format);
    GFXRECON_UNREFERENCED_PARAMETER(flags);
    GFXRECON_UNREFERENCED_PARAMETER(node_mask);
    GFXRECON_UNREFERENCED_PARAMETER(present_queue);

    ReleaseSwapChainImages(wrapper);
}

void D3D12CaptureManager::PostProcess_IDXGISwapChain3_ResizeBuffers1(IDXGISwapChain_Wrapper* wrapper,
                                                                     HRESULT                 result,
                                                                     UINT                    buffer_count,
                                                                     UINT                    width,
                                                                     UINT                    height,
                                                                     DXGI_FORMAT             new_format,
                                                                     UINT                    flags,
                                                                     const UINT*             node_mask,
                                                                     IUnknown* const*        present_queue)
{
    GFXRECON_UNREFERENCED_PARAMETER(width);
    GFXRECON_UNREFERENCED_PARAMETER(height);
    GFXRECON_UNREFERENCED_PARAMETER(new_format);
    GFXRECON_UNREFERENCED_PARAMETER(flags);
    GFXRECON_UNREFERENCED_PARAMETER(node_mask);
    GFXRECON_UNREFERENCED_PARAMETER(present_queue);

    if (SUCCEEDED(result) && (wrapper != nullptr))
    {
        auto info = wrapper->GetObjectInfo();
        assert(info != nullptr);

        PreAcquireSwapChainImages(wrapper, nullptr, buffer_count, info->swap_effect);
    }
}

void D3D12CaptureManager::Destroy_IDXGISwapChain(IDXGISwapChain_Wrapper* wrapper)
{
    ReleaseSwapChainImages(wrapper);
}

void D3D12CaptureManager::PostProcess_ID3D12Device_CreateDescriptorHeap(
    ID3D12Device_Wrapper* wrapper, HRESULT result, const D3D12_DESCRIPTOR_HEAP_DESC* desc, REFIID riid, void** heap)
{
    GFXRECON_UNREFERENCED_PARAMETER(riid);

    if (SUCCEEDED(result) && (wrapper != nullptr) && (desc != nullptr) && (heap != nullptr) && ((*heap) != nullptr))
    {
        auto device    = wrapper->GetWrappedObjectAs<ID3D12Device>();
        auto increment = device->GetDescriptorHandleIncrementSize(desc->Type);

        if (increment < sizeof(void*))
        {
            // The actual descriptor size is too small to store the pointer to the descriptor wrapper.
            GFXRECON_LOG_FATAL("The descriptor increment size %u is too small to support descriptor wrapping",
                               increment);
        }

        auto heap_wrapper = reinterpret_cast<ID3D12DescriptorHeap_Wrapper*>(*heap);
        auto info         = heap_wrapper->GetObjectInfo();
        assert(info != nullptr);

        auto descriptor_heap = heap_wrapper->GetWrappedObjectAs<ID3D12DescriptorHeap>();
        auto num_descriptors = desc->NumDescriptors;

        info->descriptor_memory = std::make_unique<uint8_t[]>(static_cast<size_t>(num_descriptors) * increment);
        info->descriptor_info   = std::make_unique<DxDescriptorInfo[]>(num_descriptors);

        size_t offset    = 0;
        auto   cpu_start = descriptor_heap->GetCPUDescriptorHandleForHeapStart();
        auto   gpu_start = descriptor_heap->GetGPUDescriptorHandleForHeapStart();

        for (uint32_t i = 0; i < num_descriptors; ++i)
        {
            auto current = &info->descriptor_info[i];

            current->heap_id     = heap_wrapper->GetCaptureId();
            current->index       = i;
            current->cpu_address = cpu_start.ptr + offset;
            current->gpu_address = gpu_start.ptr + offset;

            // The increment isn't required to be a multiple of sizeof(void*), so copy the address of the current item
            // instead of dereferencing a potentially unaligned address for assignment.
            util::platform::MemoryCopy(&info->descriptor_memory[offset], sizeof(current), &current, sizeof(current));

            offset += increment;
        }
    }
}

void D3D12CaptureManager::PostProcess_ID3D12Device_CreateHeap(
    ID3D12Device_Wrapper* wrapper, HRESULT result, const D3D12_HEAP_DESC* desc, REFIID riid, void** heap)
{
    GFXRECON_UNREFERENCED_PARAMETER(riid);

    if (SUCCEEDED(result) && (wrapper != nullptr) && (desc != nullptr) && (heap != nullptr) && ((*heap) != nullptr))
    {
        auto heap_wrapper = reinterpret_cast<ID3D12Heap_Wrapper*>(*heap);
        auto info         = heap_wrapper->GetObjectInfo();
        assert(info != nullptr);

        info->heap_type       = desc->Properties.Type;
        info->page_property   = desc->Properties.CPUPageProperty;
        info->memory_pool     = desc->Properties.MemoryPoolPreference;
        info->has_write_watch = UseWriteWatch(info->heap_type, desc->Flags, info->page_property);

        CheckWriteWatchIgnored(desc->Flags, heap_wrapper->GetCaptureId());
    }
}

void D3D12CaptureManager::PostProcess_ID3D12Device_CreateCommittedResource(
    ID3D12Device_Wrapper*        wrapper,
    HRESULT                      result,
    const D3D12_HEAP_PROPERTIES* heap_properties,
    D3D12_HEAP_FLAGS             heap_flags,
    const D3D12_RESOURCE_DESC*   desc,
    D3D12_RESOURCE_STATES        initial_resource_state,
    const D3D12_CLEAR_VALUE*     optimized_clear_value,
    REFIID                       riid,
    void**                       resource)
{
    GFXRECON_UNREFERENCED_PARAMETER(optimized_clear_value);
    GFXRECON_UNREFERENCED_PARAMETER(riid);

    if (SUCCEEDED(result) && (wrapper != nullptr) && (heap_properties != nullptr) && (desc != nullptr) &&
        (resource != nullptr) && ((*resource) != nullptr))
    {
        auto resource_wrapper = reinterpret_cast<ID3D12Resource_Wrapper*>(*resource);

        InitializeID3D12ResourceInfo(
            wrapper,
            resource_wrapper,
            desc->Dimension,
            desc->Width,
            heap_properties->Type,
            heap_properties->CPUPageProperty,
            heap_properties->MemoryPoolPreference,
            initial_resource_state,
            UseWriteWatch(heap_properties->Type, heap_flags, heap_properties->CPUPageProperty));

        CheckWriteWatchIgnored(heap_flags, resource_wrapper->GetCaptureId());
    }
}

void D3D12CaptureManager::PostProcess_ID3D12Device_CreatePlacedResource(ID3D12Device_Wrapper*      wrapper,
                                                                        HRESULT                    result,
                                                                        ID3D12Heap*                heap,
                                                                        UINT64                     heap_offset,
                                                                        const D3D12_RESOURCE_DESC* desc,
                                                                        D3D12_RESOURCE_STATES      initial_state,
                                                                        const D3D12_CLEAR_VALUE* optimized_clear_value,
                                                                        REFIID                   riid,
                                                                        void**                   resource)
{
    GFXRECON_UNREFERENCED_PARAMETER(heap_offset);
    GFXRECON_UNREFERENCED_PARAMETER(optimized_clear_value);
    GFXRECON_UNREFERENCED_PARAMETER(riid);

    if (SUCCEEDED(result) && (wrapper != nullptr) && (heap != nullptr) && (desc != nullptr) && (resource != nullptr) &&
        ((*resource) != nullptr))
    {
        auto heap_wrapper     = reinterpret_cast<ID3D12Heap_Wrapper*>(heap);
        auto resource_wrapper = reinterpret_cast<ID3D12Resource_Wrapper*>(*resource);
        auto heap_info        = heap_wrapper->GetObjectInfo();
        assert(heap_info != nullptr);

        InitializeID3D12ResourceInfo(wrapper,
                                     resource_wrapper,
                                     desc->Dimension,
                                     desc->Width,
                                     heap_info->heap_type,
                                     heap_info->page_property,
                                     heap_info->memory_pool,
                                     initial_state,
                                     heap_info->has_write_watch);
    }
}

void D3D12CaptureManager::PostProcess_ID3D12Device_CreateReservedResource(
    ID3D12Device_Wrapper*      wrapper,
    HRESULT                    result,
    const D3D12_RESOURCE_DESC* desc,
    D3D12_RESOURCE_STATES      initial_state,
    const D3D12_CLEAR_VALUE*   optimized_clear_value,
    REFIID                     riid,
    void**                     resource)
{
    GFXRECON_UNREFERENCED_PARAMETER(optimized_clear_value);
    GFXRECON_UNREFERENCED_PARAMETER(riid);

    if (SUCCEEDED(result) && (wrapper != nullptr) && (desc != nullptr) && (resource != nullptr) &&
        ((*resource) != nullptr))
    {
        auto resource_wrapper = reinterpret_cast<ID3D12Resource_Wrapper*>(*resource);

        InitializeID3D12ResourceInfo(wrapper,
                                     resource_wrapper,
                                     desc->Dimension,
                                     desc->Width,
                                     D3D12_HEAP_TYPE_DEFAULT,
                                     D3D12_CPU_PAGE_PROPERTY_UNKNOWN,
                                     D3D12_MEMORY_POOL_UNKNOWN,
                                     initial_state,
                                     false);
    }
}

void D3D12CaptureManager::PreProcess_ID3D12Device3_OpenExistingHeapFromAddress(ID3D12Device3_Wrapper* wrapper,
                                                                               const void*            address,
                                                                               REFIID                 riid,
                                                                               void**                 heap)
{
    GFXRECON_UNREFERENCED_PARAMETER(wrapper);
    GFXRECON_UNREFERENCED_PARAMETER(riid);
    GFXRECON_UNREFERENCED_PARAMETER(heap);

    if ((GetCaptureMode() & kModeWrite) == kModeWrite)
    {
        MEMORY_BASIC_INFORMATION info{};

        auto result = VirtualQuery(address, &info, sizeof(info));
        if (result > 0)
        {
            WriteCreateHeapAllocationCmd(reinterpret_cast<uint64_t>(address), info.RegionSize);
        }
        else
        {
            GFXRECON_LOG_ERROR("Failed to retrieve memory information for address specified to "
                               "ID3D12Device3::OpenExistingHeapFromAddress (error = %d)",
                               GetLastError());
        }
    }
}

void D3D12CaptureManager::PostProcess_ID3D12Device3_OpenExistingHeapFromAddress(
    ID3D12Device3_Wrapper* wrapper, HRESULT result, const void* address, REFIID riid, void** heap)
{
    GFXRECON_UNREFERENCED_PARAMETER(wrapper);
    GFXRECON_UNREFERENCED_PARAMETER(riid);

    if ((GetCaptureMode() & kModeTrack) == kModeTrack)
    {
        if (SUCCEEDED(result) && (heap != nullptr) && ((*heap) != nullptr))
        {
            state_tracker_->TrackOpenExistingHeapFromAddress(heap, address);
        }
    }
}

void D3D12CaptureManager::PostProcess_ID3D12Device4_CreateHeap1(ID3D12Device4_Wrapper*          wrapper,
                                                                HRESULT                         result,
                                                                const D3D12_HEAP_DESC*          desc,
                                                                ID3D12ProtectedResourceSession* protected_session,
                                                                REFIID                          riid,
                                                                void**                          heap)
{
    GFXRECON_UNREFERENCED_PARAMETER(protected_session);
    GFXRECON_UNREFERENCED_PARAMETER(riid);

    if (SUCCEEDED(result) && (wrapper != nullptr) && (desc != nullptr) && (heap != nullptr) && ((*heap) != nullptr))
    {
        auto heap_wrapper = reinterpret_cast<ID3D12Heap_Wrapper*>(*heap);
        auto info         = heap_wrapper->GetObjectInfo();
        assert(info != nullptr);

        info->heap_type       = desc->Properties.Type;
        info->page_property   = desc->Properties.CPUPageProperty;
        info->memory_pool     = desc->Properties.MemoryPoolPreference;
        info->has_write_watch = UseWriteWatch(info->heap_type, desc->Flags, info->page_property);

        CheckWriteWatchIgnored(desc->Flags, heap_wrapper->GetCaptureId());
    }
}

void D3D12CaptureManager::PostProcess_ID3D12Device4_CreateCommittedResource1(
    ID3D12Device4_Wrapper*          wrapper,
    HRESULT                         result,
    const D3D12_HEAP_PROPERTIES*    heap_properties,
    D3D12_HEAP_FLAGS                heap_flags,
    const D3D12_RESOURCE_DESC*      desc,
    D3D12_RESOURCE_STATES           initial_resource_state,
    const D3D12_CLEAR_VALUE*        optimized_clear_value,
    ID3D12ProtectedResourceSession* protected_session,
    REFIID                          riid,
    void**                          resource)
{
    GFXRECON_UNREFERENCED_PARAMETER(optimized_clear_value);
    GFXRECON_UNREFERENCED_PARAMETER(protected_session);
    GFXRECON_UNREFERENCED_PARAMETER(riid);

    if (SUCCEEDED(result) && (wrapper != nullptr) && (heap_properties != nullptr) && (desc != nullptr) &&
        (resource != nullptr) && ((*resource) != nullptr))
    {
        auto resource_wrapper = reinterpret_cast<ID3D12Resource_Wrapper*>(*resource);

        InitializeID3D12ResourceInfo(
            wrapper,
            resource_wrapper,
            desc->Dimension,
            desc->Width,
            heap_properties->Type,
            heap_properties->CPUPageProperty,
            heap_properties->MemoryPoolPreference,
            initial_resource_state,
            UseWriteWatch(heap_properties->Type, heap_flags, heap_properties->CPUPageProperty));

        CheckWriteWatchIgnored(heap_flags, resource_wrapper->GetCaptureId());
    }
}

void D3D12CaptureManager::PostProcess_ID3D12Device8_CreateCommittedResource2(
    ID3D12Device8_Wrapper*          wrapper,
    HRESULT                         result,
    const D3D12_HEAP_PROPERTIES*    heap_properties,
    D3D12_HEAP_FLAGS                heap_flags,
    const D3D12_RESOURCE_DESC1*     desc,
    D3D12_RESOURCE_STATES           initial_resource_state,
    const D3D12_CLEAR_VALUE*        optimized_clear_value,
    ID3D12ProtectedResourceSession* protected_session,
    REFIID                          riid,
    void**                          resource)
{
    GFXRECON_UNREFERENCED_PARAMETER(optimized_clear_value);
    GFXRECON_UNREFERENCED_PARAMETER(protected_session);
    GFXRECON_UNREFERENCED_PARAMETER(riid);

    if (SUCCEEDED(result) && (wrapper != nullptr) && (heap_properties != nullptr) && (desc != nullptr) &&
        (resource != nullptr) && ((*resource) != nullptr))
    {
        auto resource_wrapper = reinterpret_cast<ID3D12Resource_Wrapper*>(*resource);

        InitializeID3D12ResourceInfo(
            wrapper,
            resource_wrapper,
            desc->Dimension,
            desc->Width,
            heap_properties->Type,
            heap_properties->CPUPageProperty,
            heap_properties->MemoryPoolPreference,
            initial_resource_state,
            UseWriteWatch(heap_properties->Type, heap_flags, heap_properties->CPUPageProperty));

        CheckWriteWatchIgnored(heap_flags, resource_wrapper->GetCaptureId());
    }
}

void D3D12CaptureManager::PostProcess_ID3D12Device8_CreatePlacedResource1(
    ID3D12Device8_Wrapper*      wrapper,
    HRESULT                     result,
    ID3D12Heap*                 heap,
    UINT64                      heap_offset,
    const D3D12_RESOURCE_DESC1* desc,
    D3D12_RESOURCE_STATES       initial_state,
    const D3D12_CLEAR_VALUE*    optimized_clear_value,
    REFIID                      riid,
    void**                      resource)
{
    GFXRECON_UNREFERENCED_PARAMETER(heap_offset);
    GFXRECON_UNREFERENCED_PARAMETER(optimized_clear_value);
    GFXRECON_UNREFERENCED_PARAMETER(riid);

    if (SUCCEEDED(result) && (wrapper != nullptr) && (heap != nullptr) && (desc != nullptr) && (resource != nullptr) &&
        ((*resource) != nullptr))
    {
        auto heap_wrapper     = reinterpret_cast<ID3D12Heap_Wrapper*>(heap);
        auto resource_wrapper = reinterpret_cast<ID3D12Resource_Wrapper*>(*resource);
        auto heap_info        = heap_wrapper->GetObjectInfo();
        assert(heap_info != nullptr);

        InitializeID3D12ResourceInfo(wrapper,
                                     resource_wrapper,
                                     desc->Dimension,
                                     desc->Width,
                                     heap_info->heap_type,
                                     heap_info->page_property,
                                     heap_info->memory_pool,
                                     initial_state,
                                     heap_info->has_write_watch);
    }
}

void D3D12CaptureManager::PostProcess_ID3D12Resource_Map(
    ID3D12Resource_Wrapper* wrapper, HRESULT result, UINT subresource, const D3D12_RANGE* read_range, void** data)
{
    GFXRECON_UNREFERENCED_PARAMETER(read_range);

    if (SUCCEEDED(result) && (wrapper != nullptr) && (data != nullptr))
    {
        auto info = wrapper->GetObjectInfo();
        assert((info != nullptr) && (subresource < info->num_subresources));

        if (IsUploadResource(info->heap_type, info->page_property))
        {
            auto& mapped_subresource = info->mapped_subresources[subresource];

            std::lock_guard<std::mutex> lock(mapped_memory_lock_);
            if (++mapped_subresource.map_count == 1)
            {
                mapped_subresource.data = (*data);

                if (GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kPageGuard)
                {
                    util::PageGuardManager* manager = util::PageGuardManager::Get();
                    assert(manager != nullptr);

                    uint64_t size = info->subresource_sizes[subresource];
                    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, size);

                    bool use_shadow_memory = true;
                    bool use_write_watch   = false;

                    if (info->has_write_watch)
                    {
                        use_shadow_memory = false;
                        use_write_watch   = true;
                    }
                    else if ((GetPageGuardMemoryMode() == kMemoryModeShadowPersistent) &&
                             (mapped_subresource.shadow_allocation == util::PageGuardManager::kNullShadowHandle))
                    {
                        mapped_subresource.shadow_allocation =
                            manager->AllocatePersistentShadowMemory(static_cast<size_t>(size));
                    }

                    // Return the pointer provided by the pageguard manager, which may be a pointer to shadow memory,
                    // not the mapped memory.
                    (*data) = manager->AddTrackedMemory(reinterpret_cast<uint64_t>(mapped_subresource.data),
                                                        mapped_subresource.data,
                                                        0,
                                                        static_cast<size_t>(size),
                                                        mapped_subresource.shadow_allocation,
                                                        use_shadow_memory,
                                                        use_write_watch);
                }
                else if (GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kUnassisted)
                {
                    // Need to keep track of mapped memory objects so memory content can be written at queue submit.
                    mapped_resources_.insert(wrapper);
                }
            }
            else
            {
                // The application has mapped the same ID3D12Resource object more than once and the pageguard
                // manager is already tracking it, so we will return the pointer obtained from the pageguard manager
                // on the first map call.
                if (GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kPageGuard)
                {
                    // Return the shadow memory that was allocated for the previous map operation.
                    util::PageGuardManager* manager = util::PageGuardManager::Get();
                    assert(manager != nullptr);

                    auto found = manager->GetTrackedMemory(reinterpret_cast<uint64_t>(mapped_subresource.data), data);
                    if (!found)
                    {
                        GFXRECON_LOG_ERROR("Failed to find tracked memory object for a previously mapped resource.")
                    }
                }
            }
        }
    }
}

void D3D12CaptureManager::PreProcess_ID3D12Resource_Unmap(ID3D12Resource_Wrapper* wrapper,
                                                          UINT                    subresource,
                                                          const D3D12_RANGE*      written_range)
{
    if (wrapper != nullptr)
    {
        auto info = wrapper->GetObjectInfo();
        assert((info != nullptr) && (subresource < info->num_subresources));

        if (IsUploadResource(info->heap_type, info->page_property))
        {
            auto& mapped_subresource = info->mapped_subresources[subresource];

            std::lock_guard<std::mutex> lock(mapped_memory_lock_);
            if (mapped_subresource.map_count > 0)
            {
                if ((--mapped_subresource.map_count == 0) && (mapped_subresource.data != nullptr))
                {
                    if (GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kPageGuard)
                    {
                        util::PageGuardManager* manager = util::PageGuardManager::Get();
                        assert(manager != nullptr);

                        auto memory_id = reinterpret_cast<uint64_t>(mapped_subresource.data);

                        manager->ProcessMemoryEntry(
                            memory_id, [this](uint64_t memory_id, void* start_address, size_t offset, size_t size) {
                                WriteFillMemoryCmd(memory_id, offset, size, start_address);
                            });

                        manager->RemoveTrackedMemory(memory_id);
                    }
                    else if (GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kUnassisted)
                    {
                        uint64_t offset = 0;
                        uint64_t size   = info->subresource_sizes[subresource];

                        if (written_range != nullptr)
                        {
                            offset = written_range->Begin;
                            size   = (written_range->End - written_range->Begin) + 1;
                        }

                        WriteFillMemoryCmd(
                            reinterpret_cast<uint64_t>(mapped_subresource.data), offset, size, mapped_subresource.data);

                        bool is_mapped = false;

                        for (size_t i = 0; i < info->num_subresources; ++i)
                        {
                            if (info->mapped_subresources[i].map_count > 0)
                            {
                                is_mapped = true;
                                break;
                            }
                        }

                        if (!is_mapped)
                        {
                            // All subresources have been unmapped.
                            mapped_resources_.erase(wrapper);
                        }
                    }

                    mapped_subresource.data = nullptr;
                }
            }
            else
            {
                GFXRECON_LOG_WARNING("Attempting to unmap ID3D12Resource object with capture ID = %" PRIx64
                                     " that has not been mapped",
                                     wrapper->GetCaptureId());
            }
        }
    }
}

void D3D12CaptureManager::PostProcess_ID3D12Resource_GetHeapProperties(ID3D12Resource_Wrapper* wrapper,
                                                                       HRESULT                 result,
                                                                       D3D12_HEAP_PROPERTIES*  heap_properties,
                                                                       D3D12_HEAP_FLAGS*       heap_flags)
{
    GFXRECON_UNREFERENCED_PARAMETER(wrapper);
    GFXRECON_UNREFERENCED_PARAMETER(heap_properties);

    if (SUCCEEDED(result) && (heap_flags != nullptr) && (GetPageGuardMemoryMode() == kMemoryModeExternal))
    {
        auto info = wrapper->GetObjectInfo();
        assert(info != nullptr);

        if (info->has_write_watch)
        {
            if (heap_flags != nullptr)
            {
                // Remove the D3D12_HEAP_FLAG_ALLOW_WRITE_WATCH flag that was added at resource creation.
                (*heap_flags) &= ~D3D12_HEAP_FLAG_ALLOW_WRITE_WATCH;
            }

            if (heap_properties != nullptr)
            {
                // Replace the custom heap properties that were set at resource creation.
                heap_properties->Type                 = info->heap_type;
                heap_properties->CPUPageProperty      = info->page_property;
                heap_properties->MemoryPoolPreference = info->memory_pool;
            }
        }
    }
}

void D3D12CaptureManager::Destroy_ID3D12Resource(ID3D12Resource_Wrapper* wrapper)
{
    if (wrapper != nullptr)
    {
        auto info = wrapper->GetObjectInfo();
        assert(info != nullptr);

        if (GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kPageGuard)
        {
            util::PageGuardManager* manager = util::PageGuardManager::Get();
            assert(manager != nullptr);

            // Remove memory tracking.
            for (size_t i = 0; i < info->num_subresources; ++i)
            {
                auto& mapped_subresource = info->mapped_subresources[i];

                auto memory_id = reinterpret_cast<uint64_t>(mapped_subresource.data);
                if (memory_id != 0)
                {
                    manager->RemoveTrackedMemory(memory_id);
                }

                if (mapped_subresource.shadow_allocation != util::PageGuardManager::kNullShadowHandle)
                {
                    manager->FreePersistentShadowMemory(mapped_subresource.shadow_allocation);
                }
            }
        }
        else if (GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kUnassisted)
        {
            bool is_mapped = false;

            for (size_t i = 0; i < info->num_subresources; ++i)
            {
                if (info->mapped_subresources[i].map_count > 0)
                {
                    is_mapped = true;
                    break;
                }
            }

            if (is_mapped)
            {
                // If any subresources were mapped, the resource wrapper needs to be removed from the mapped resource
                // table.
                std::lock_guard<std::mutex> lock(mapped_memory_lock_);
                mapped_resources_.erase(wrapper);
            }
        }
    }
}

void D3D12CaptureManager::PostProcess_ID3D12Heap_GetDesc(ID3D12Heap_Wrapper* wrapper, D3D12_HEAP_DESC& desc)
{
    GFXRECON_UNREFERENCED_PARAMETER(wrapper);

    if ((GetPageGuardMemoryMode() == kMemoryModeExternal))
    {
        auto info = wrapper->GetObjectInfo();
        assert(info != nullptr);

        if (info->has_write_watch)
        {
            // Remove the D3D12_HEAP_FLAG_ALLOW_WRITE_WATCH flag that was added at heap creation.
            desc.Flags &= ~D3D12_HEAP_FLAG_ALLOW_WRITE_WATCH;

            // Replace the custom heap properties that were set at heapcreation.
            desc.Properties.Type                 = info->heap_type;
            desc.Properties.CPUPageProperty      = info->page_property;
            desc.Properties.MemoryPoolPreference = info->memory_pool;
        }
    }
}

void D3D12CaptureManager::PreProcess_ID3D12CommandQueue_ExecuteCommandLists(ID3D12CommandQueue_Wrapper* wrapper,
                                                                            UINT                        num_lists,
                                                                            ID3D12CommandList* const*   lists)
{
    GFXRECON_UNREFERENCED_PARAMETER(wrapper);
    GFXRECON_UNREFERENCED_PARAMETER(num_lists);
    GFXRECON_UNREFERENCED_PARAMETER(lists);

    if (GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kPageGuard)
    {
        util::PageGuardManager* manager = util::PageGuardManager::Get();
        assert(manager != nullptr);

        manager->ProcessMemoryEntries([this](uint64_t memory_id, void* start_address, size_t offset, size_t size) {
            WriteFillMemoryCmd(memory_id, offset, size, start_address);
        });
    }
    else if (GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kUnassisted)
    {
        std::lock_guard<std::mutex> lock(mapped_memory_lock_);
        for (auto resource_wrapper : mapped_resources_)
        {
            auto info = resource_wrapper->GetObjectInfo();

            for (size_t i = 0; i < info->num_subresources; ++i)
            {
                // If the memory is mapped, write the entire mapped region.
                auto        size               = info->subresource_sizes[i];
                const auto& mapped_subresource = info->mapped_subresources[i];

                WriteFillMemoryCmd(
                    reinterpret_cast<uint64_t>(mapped_subresource.data), 0, size, mapped_subresource.data);
            }
        }
    }
}

void D3D12CaptureManager::PostProcess_ID3D12CommandQueue_ExecuteCommandLists(ID3D12CommandQueue_Wrapper* wrapper,
                                                                             UINT                        num_lists,
                                                                             ID3D12CommandList* const*   lists)
{
    if ((GetCaptureMode() & kModeTrack) == kModeTrack)
    {
        state_tracker_->TrackExecuteCommandLists(wrapper, num_lists, lists);
    }
}

D3D12_CPU_DESCRIPTOR_HANDLE D3D12CaptureManager::OverrideID3D12DescriptorHeap_GetCPUDescriptorHandleForHeapStart(
    ID3D12DescriptorHeap_Wrapper* wrapper)
{
    auto heap = wrapper->GetWrappedObjectAs<ID3D12DescriptorHeap>();
    auto info = wrapper->GetObjectInfo();
    assert(info != nullptr);

    auto result = heap->GetCPUDescriptorHandleForHeapStart();

    result.ptr = reinterpret_cast<size_t>(info->descriptor_memory.get());

    if ((GetCaptureMode() & kModeTrack) == kModeTrack)
    {
        info->cpu_start = result.ptr;
    }

    return result;
}

D3D12_GPU_DESCRIPTOR_HANDLE D3D12CaptureManager::OverrideID3D12DescriptorHeap_GetGPUDescriptorHandleForHeapStart(
    ID3D12DescriptorHeap_Wrapper* wrapper)
{
    auto heap = wrapper->GetWrappedObjectAs<ID3D12DescriptorHeap>();
    auto info = wrapper->GetObjectInfo();
    assert(info != nullptr);

    auto result = heap->GetGPUDescriptorHandleForHeapStart();

    result.ptr = reinterpret_cast<uint64_t>(info->descriptor_memory.get());

    if ((GetCaptureMode() & kModeTrack) == kModeTrack)
    {
        info->gpu_start = result.ptr;
    }

    return result;
}

HRESULT
D3D12CaptureManager::OverrideID3D12Device_CreateCommittedResource(ID3D12Device_Wrapper*        wrapper,
                                                                  const D3D12_HEAP_PROPERTIES* heap_properties,
                                                                  D3D12_HEAP_FLAGS             heap_flags,
                                                                  const D3D12_RESOURCE_DESC*   desc,
                                                                  D3D12_RESOURCE_STATES        initial_resource_state,
                                                                  const D3D12_CLEAR_VALUE*     optimized_clear_value,
                                                                  REFIID                       riid_resource,
                                                                  void**                       ppv_resource)
{
    auto device = wrapper->GetWrappedObjectAs<ID3D12Device>();

    if ((desc == nullptr) || (heap_properties == nullptr))
    {
        return E_INVALIDARG;
    }
    else if (UseWriteWatch(heap_properties->Type, heap_flags, heap_properties->CPUPageProperty))
    {
        auto properties_copy = *heap_properties;
        EnableWriteWatch(heap_flags, properties_copy);

        return device->CreateCommittedResource(&properties_copy,
                                               heap_flags,
                                               desc,
                                               initial_resource_state,
                                               optimized_clear_value,
                                               riid_resource,
                                               ppv_resource);
    }

    return device->CreateCommittedResource(
        heap_properties, heap_flags, desc, initial_resource_state, optimized_clear_value, riid_resource, ppv_resource);
}

HRESULT
D3D12CaptureManager::OverrideID3D12Device_CreateCommittedResource1(ID3D12Device4_Wrapper*       wrapper,
                                                                   const D3D12_HEAP_PROPERTIES* heap_properties,
                                                                   D3D12_HEAP_FLAGS             heap_flags,
                                                                   const D3D12_RESOURCE_DESC*   desc,
                                                                   D3D12_RESOURCE_STATES        initial_resource_state,
                                                                   const D3D12_CLEAR_VALUE*     optimized_clear_value,
                                                                   ID3D12ProtectedResourceSession* protected_session,
                                                                   REFIID                          riid_resource,
                                                                   void**                          ppv_resource)
{
    auto device = wrapper->GetWrappedObjectAs<ID3D12Device4>();

    if ((desc == nullptr) || (heap_properties == nullptr))
    {
        return E_INVALIDARG;
    }
    else if (UseWriteWatch(heap_properties->Type, heap_flags, heap_properties->CPUPageProperty))
    {
        auto properties_copy = *heap_properties;
        EnableWriteWatch(heap_flags, properties_copy);

        return device->CreateCommittedResource1(&properties_copy,
                                                heap_flags,
                                                desc,
                                                initial_resource_state,
                                                optimized_clear_value,
                                                protected_session,
                                                riid_resource,
                                                ppv_resource);
    }

    return device->CreateCommittedResource1(heap_properties,
                                            heap_flags,
                                            desc,
                                            initial_resource_state,
                                            optimized_clear_value,
                                            protected_session,
                                            riid_resource,
                                            ppv_resource);
}

HRESULT
D3D12CaptureManager::OverrideID3D12Device_CreateCommittedResource2(ID3D12Device8_Wrapper*       wrapper,
                                                                   const D3D12_HEAP_PROPERTIES* heap_properties,
                                                                   D3D12_HEAP_FLAGS             heap_flags,
                                                                   const D3D12_RESOURCE_DESC1*  desc,
                                                                   D3D12_RESOURCE_STATES        initial_resource_state,
                                                                   const D3D12_CLEAR_VALUE*     optimized_clear_value,
                                                                   ID3D12ProtectedResourceSession* protected_session,
                                                                   REFIID                          riid_resource,
                                                                   void**                          ppv_resource)
{
    auto device = wrapper->GetWrappedObjectAs<ID3D12Device8>();

    if ((desc == nullptr) || (heap_properties == nullptr))
    {
        return E_INVALIDARG;
    }
    else if (UseWriteWatch(heap_properties->Type, heap_flags, heap_properties->CPUPageProperty))
    {
        auto properties_copy = *heap_properties;
        EnableWriteWatch(heap_flags, properties_copy);

        return device->CreateCommittedResource2(&properties_copy,
                                                heap_flags,
                                                desc,
                                                initial_resource_state,
                                                optimized_clear_value,
                                                protected_session,
                                                riid_resource,
                                                ppv_resource);
    }

    return device->CreateCommittedResource2(heap_properties,
                                            heap_flags,
                                            desc,
                                            initial_resource_state,
                                            optimized_clear_value,
                                            protected_session,
                                            riid_resource,
                                            ppv_resource);
}

HRESULT D3D12CaptureManager::OverrideID3D12Device_CreateHeap(ID3D12Device_Wrapper*  wrapper,
                                                             const D3D12_HEAP_DESC* desc,
                                                             REFIID                 riid,
                                                             void**                 heap)
{
    auto device = wrapper->GetWrappedObjectAs<ID3D12Device>();

    if (desc == nullptr)
    {
        return E_INVALIDARG;
    }
    else if (UseWriteWatch(desc->Properties.Type, desc->Flags, desc->Properties.CPUPageProperty))
    {
        D3D12_HEAP_DESC desc_copy = *desc;
        EnableWriteWatch(desc_copy.Flags, desc_copy.Properties);

        return device->CreateHeap(&desc_copy, riid, heap);
    }
    else
    {
        return device->CreateHeap(desc, riid, heap);
    }
}

HRESULT D3D12CaptureManager::OverrideID3D12Device_CreateHeap1(ID3D12Device4_Wrapper*          wrapper,
                                                              const D3D12_HEAP_DESC*          desc,
                                                              ID3D12ProtectedResourceSession* protected_session,
                                                              REFIID                          riid,
                                                              void**                          heap)
{
    auto device = wrapper->GetWrappedObjectAs<ID3D12Device4>();

    if (desc == nullptr)
    {
        return E_INVALIDARG;
    }
    else if (UseWriteWatch(desc->Properties.Type, desc->Flags, desc->Properties.CPUPageProperty))
    {
        D3D12_HEAP_DESC desc_copy = *desc;
        EnableWriteWatch(desc_copy.Flags, desc_copy.Properties);

        return device->CreateHeap1(&desc_copy, protected_session, riid, heap);
    }
    else
    {
        return device->CreateHeap1(desc, protected_session, riid, heap);
    }
}

HRESULT D3D12CaptureManager::OverrideID3D12Device1_CreatePipelineLibrary(
    ID3D12Device1_Wrapper* wrapper, const void* library_blob, SIZE_T blob_length, REFIID riid, void** library)
{
    if ((library_blob != nullptr) && (blob_length > 0))
    {
        return D3D12_ERROR_DRIVER_VERSION_MISMATCH;
    }

    auto device1 = wrapper->GetWrappedObjectAs<ID3D12Device1>();
    return device1->CreatePipelineLibrary(library_blob, blob_length, riid, library);
}

HRESULT
D3D12CaptureManager::OverrideID3D12PipelineLibrary_LoadComputePipeline(ID3D12PipelineLibrary_Wrapper*           wrapper,
                                                                       LPCWSTR                                  name,
                                                                       const D3D12_COMPUTE_PIPELINE_STATE_DESC* desc,
                                                                       REFIID                                   riid,
                                                                       void** pipeline_state)
{
    GFXRECON_UNREFERENCED_PARAMETER(wrapper);
    GFXRECON_UNREFERENCED_PARAMETER(name);
    GFXRECON_UNREFERENCED_PARAMETER(desc);
    GFXRECON_UNREFERENCED_PARAMETER(riid);
    GFXRECON_UNREFERENCED_PARAMETER(pipeline_state);

    return E_INVALIDARG;
}

HRESULT
D3D12CaptureManager::OverrideID3D12PipelineLibrary_LoadGraphicsPipeline(ID3D12PipelineLibrary_Wrapper* wrapper,
                                                                        LPCWSTR                        name,
                                                                        const D3D12_GRAPHICS_PIPELINE_STATE_DESC* desc,
                                                                        REFIID                                    riid,
                                                                        void** pipeline_state)
{
    GFXRECON_UNREFERENCED_PARAMETER(wrapper);
    GFXRECON_UNREFERENCED_PARAMETER(name);
    GFXRECON_UNREFERENCED_PARAMETER(desc);
    GFXRECON_UNREFERENCED_PARAMETER(riid);
    GFXRECON_UNREFERENCED_PARAMETER(pipeline_state);

    return E_INVALIDARG;
}

HRESULT D3D12CaptureManager::OverrideID3D12PipelineLibrary1_LoadPipeline(ID3D12PipelineLibrary_Wrapper* wrapper,
                                                                         LPCWSTR                        name,
                                                                         const D3D12_PIPELINE_STATE_STREAM_DESC* desc,
                                                                         REFIID                                  riid,
                                                                         void** pipeline_state)
{
    GFXRECON_UNREFERENCED_PARAMETER(wrapper);
    GFXRECON_UNREFERENCED_PARAMETER(name);
    GFXRECON_UNREFERENCED_PARAMETER(desc);
    GFXRECON_UNREFERENCED_PARAMETER(riid);
    GFXRECON_UNREFERENCED_PARAMETER(pipeline_state);

    return E_INVALIDARG;
}

PFN_D3D12_GET_DEBUG_INTERFACE D3D12CaptureManager::GetDebugInterfacePtr()
{
    PFN_D3D12_GET_DEBUG_INTERFACE get_debug_interface = d3d12_dispatch_table_.D3D12GetDebugInterface;

    if (get_debug_interface == nullptr)
    {
        HMODULE d3d12_dll = LoadLibraryA("d3d12_ms.dll");

        if (d3d12_dll == nullptr)
        {
            d3d12_dll = LoadLibraryA("d3d12.dll");
        }

        if (d3d12_dll != nullptr)
        {
            get_debug_interface =
                reinterpret_cast<PFN_D3D12_GET_DEBUG_INTERFACE>(GetProcAddress(d3d12_dll, "D3D12GetDebugInterface"));
        }
    }

    return get_debug_interface;
}

void D3D12CaptureManager::EnableDebugLayer()
{
    if (debug_layer_enabled_ == false)
    {
        PFN_D3D12_GET_DEBUG_INTERFACE get_debug_interface = GetDebugInterfacePtr();

        if (get_debug_interface != nullptr)
        {
            gfxrecon::graphics::dx12::ID3D12DebugComPtr debug_controller = nullptr;
            HRESULT                                     result = get_debug_interface(IID_PPV_ARGS(&debug_controller));

            if (result == S_OK)
            {
                debug_controller->EnableDebugLayer();

                debug_layer_enabled_ = true;
            }
        }
    }
}

void D3D12CaptureManager::EnableDRED()
{
    if (debug_device_lost_enabled_ == false)
    {
        PFN_D3D12_GET_DEBUG_INTERFACE get_debug_interface = GetDebugInterfacePtr();

        if (get_debug_interface != nullptr)
        {
            gfxrecon::graphics::dx12::ID3D12DeviceRemovedExtendedDataSettings1ComPtr dred_settings = nullptr;
            HRESULT result = get_debug_interface(IID_PPV_ARGS(&dred_settings));

            if (result == S_OK)
            {
                dred_settings->SetAutoBreadcrumbsEnablement(D3D12_DRED_ENABLEMENT_FORCED_ON);
                dred_settings->SetBreadcrumbContextEnablement(D3D12_DRED_ENABLEMENT_FORCED_ON);
                dred_settings->SetPageFaultEnablement(D3D12_DRED_ENABLEMENT_FORCED_ON);

                debug_device_lost_enabled_ = true;
            }
        }
    }
}

HRESULT D3D12CaptureManager::OverrideCreateDXGIFactory2(UINT Flags, REFIID riid, void** ppFactory)
{
    HRESULT result = E_FAIL;

    if (GetDebugLayerSetting() == true)
    {
        EnableDebugLayer();
    }

    if (debug_layer_enabled_)
    {
        Flags |= DXGI_CREATE_FACTORY_DEBUG;
    }

    result = dxgi_dispatch_table_.CreateDXGIFactory2(Flags, riid, ppFactory);

    return result;
}

void D3D12CaptureManager::PreProcess_D3D12CreateDevice(IUnknown*         pAdapter,
                                                       D3D_FEATURE_LEVEL MinimumFeatureLevel,
                                                       REFIID            riid,
                                                       void**            ppDevice)
{
    GFXRECON_UNREFERENCED_PARAMETER(pAdapter);
    GFXRECON_UNREFERENCED_PARAMETER(MinimumFeatureLevel);
    GFXRECON_UNREFERENCED_PARAMETER(riid);
    GFXRECON_UNREFERENCED_PARAMETER(ppDevice);

    if (GetDebugLayerSetting() == true)
    {
        EnableDebugLayer();
    }

    if (GetDebugDeviceLostSetting() == true)
    {
        EnableDRED();
    }
}

void D3D12CaptureManager::PostProcess_ID3D12Fence_SetEventOnCompletion(ID3D12Fence_Wrapper* wrapper,
                                                                       HRESULT              result,
                                                                       UINT64               value,
                                                                       HANDLE               event)
{
    assert(wrapper != nullptr);

    if (((GetCaptureMode() & kModeTrack) == kModeTrack) && SUCCEEDED(result))
    {
        state_tracker_->TrackFenceSetEventOnCompletion(wrapper, value, event);
    }
}

void D3D12CaptureManager::PostProcess_ID3D12Fence_Signal(ID3D12Fence_Wrapper* wrapper, HRESULT result, UINT64 value)
{
    assert(wrapper != nullptr);

    if (((GetCaptureMode() & kModeTrack) == kModeTrack) && SUCCEEDED(result))
    {
        state_tracker_->TrackFenceSignal(wrapper, value);
    }
}

void D3D12CaptureManager::PostProcess_ID3D12CommandQueue_Signal(ID3D12CommandQueue_Wrapper* wrapper,
                                                                HRESULT                     result,
                                                                ID3D12Fence*                fence,
                                                                UINT64                      value)
{
    GFXRECON_UNREFERENCED_PARAMETER(wrapper);

    assert(fence != nullptr);

    if (((GetCaptureMode() & kModeTrack) == kModeTrack) && SUCCEEDED(result))
    {
        auto fence_wrapper = reinterpret_cast<ID3D12Fence_Wrapper*>(fence);
        state_tracker_->TrackFenceSignal(fence_wrapper, value);
    }
}

void D3D12CaptureManager::PostProcess_ID3D12GraphicsCommandList_ResourceBarrier(
    ID3D12GraphicsCommandList_Wrapper* list_wrapper, UINT num_barriers, const D3D12_RESOURCE_BARRIER* barriers)
{
    if ((GetCaptureMode() & kModeTrack) == kModeTrack)
    {
        state_tracker_->TrackResourceBarriers(list_wrapper, num_barriers, barriers);
    }
}

void D3D12CaptureManager::PostProcess_ID3D12Device_CreateCommandList(ID3D12Device_Wrapper*   device_wrapper,
                                                                     HRESULT                 result,
                                                                     UINT                    nodeMask,
                                                                     D3D12_COMMAND_LIST_TYPE type,
                                                                     ID3D12CommandAllocator* pCommandAllocator,
                                                                     ID3D12PipelineState*    pInitialState,
                                                                     REFIID                  riid,
                                                                     void**                  ppCommandList)
{
    if ((GetCaptureMode() & kModeTrack) == kModeTrack)
    {
        auto list_wrapper = reinterpret_cast<ID3D12GraphicsCommandList_Wrapper*>(*ppCommandList);
        state_tracker_->TrackCommandListCreation(list_wrapper, false);
    }
}

void D3D12CaptureManager::PostProcess_ID3D12Device4_CreateCommandList1(ID3D12Device_Wrapper*    device_wrapper,
                                                                       HRESULT                  result,
                                                                       UINT                     nodeMask,
                                                                       D3D12_COMMAND_LIST_TYPE  type,
                                                                       D3D12_COMMAND_LIST_FLAGS flags,
                                                                       REFIID                   riid,
                                                                       void**                   ppCommandList)
{
    if ((GetCaptureMode() & kModeTrack) == kModeTrack)
    {
        auto list_wrapper = reinterpret_cast<ID3D12GraphicsCommandList_Wrapper*>(*ppCommandList);
        state_tracker_->TrackCommandListCreation(list_wrapper, true);
    }
}

CaptureSettings::TraceSettings D3D12CaptureManager::GetDefaultTraceSettings()
{
    CaptureSettings::TraceSettings d3d12_trace_settings = {};

    // Return different trace setting defaults for D3D12.
    d3d12_trace_settings.page_guard_external_memory = true;

    return d3d12_trace_settings;
}

void D3D12CaptureManager::PostProcess_ID3D12Device_CopyDescriptors(ID3D12Device_Wrapper*              wrapper,
                                                                   UINT                               num_dest_ranges,
                                                                   const D3D12_CPU_DESCRIPTOR_HANDLE* dest_range_starts,
                                                                   const UINT*                        dest_range_sizes,
                                                                   UINT                               num_src_ranges,
                                                                   const D3D12_CPU_DESCRIPTOR_HANDLE* src_range_starts,
                                                                   const UINT*                        src_range_sizes,
                                                                   D3D12_DESCRIPTOR_HEAP_TYPE         heap_type)
{
    if ((GetCaptureMode() & kModeTrack) == kModeTrack)
    {
        UINT dest_range_i = 0;
        UINT src_range_i  = 0;
        UINT dest_i       = 0;
        UINT src_i        = 0;

        while (dest_range_i < num_dest_ranges && src_range_i < num_src_ranges)
        {
            auto dest_range_size = (dest_range_sizes != nullptr) ? dest_range_sizes[dest_range_i] : 1;
            auto src_range_size  = (src_range_sizes != nullptr) ? src_range_sizes[src_range_i] : 1;

            auto dest_size = dest_range_size - dest_i;
            auto src_size  = src_range_size - src_i;

            auto copy_size = std::min(dest_size, src_size);

            auto dest_descriptor_info = GetDescriptorInfo(dest_range_starts[dest_range_i].ptr);
            auto src_descriptor_info  = GetDescriptorInfo(src_range_starts[src_range_i].ptr);

            state_tracker_->TrackCopyDescriptors(copy_size, dest_descriptor_info + dest_i, src_descriptor_info + src_i);

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
}

void D3D12CaptureManager::PostProcess_ID3D12Device_CopyDescriptorsSimple(ID3D12Device_Wrapper*       wrapper,
                                                                         UINT                        num_descriptors,
                                                                         D3D12_CPU_DESCRIPTOR_HANDLE dest_start,
                                                                         D3D12_CPU_DESCRIPTOR_HANDLE src_start,
                                                                         D3D12_DESCRIPTOR_HEAP_TYPE  heap_type)
{
    if (((GetCaptureMode() & kModeTrack) == kModeTrack) && (num_descriptors > 0))
    {
        auto dest_descriptor_info = GetDescriptorInfo(dest_start.ptr);
        auto src_descriptor_info  = GetDescriptorInfo(src_start.ptr);
        state_tracker_->TrackCopyDescriptors(num_descriptors, dest_descriptor_info, src_descriptor_info);
    }
}

void D3D12CaptureManager::PostProcess_ID3D12CommandQueue_UpdateTileMappings(
    ID3D12CommandQueue_Wrapper*            queue_wrapper,
    ID3D12Resource*                        resource,
    UINT                                   num_resource_regions,
    const D3D12_TILED_RESOURCE_COORDINATE* resource_region_start_coordinates,
    const D3D12_TILE_REGION_SIZE*          resource_region_sizes,
    ID3D12Heap*                            heap,
    UINT                                   num_ranges,
    const D3D12_TILE_RANGE_FLAGS*          range_flags,
    const UINT*                            heap_range_start_offsets,
    const UINT*                            range_tile_counts,
    D3D12_TILE_MAPPING_FLAGS               flags)
{
    if ((GetCaptureMode() & kModeTrack) == kModeTrack)
    {
        auto resource_wrapper = reinterpret_cast<ID3D12Resource_Wrapper*>(resource);
        auto heap_wrapper     = reinterpret_cast<ID3D12Heap_Wrapper*>(heap);
        state_tracker_->TrackUpdateTileMappings(resource_wrapper,
                                                queue_wrapper->GetCaptureId(),
                                                (heap_wrapper != nullptr) ? heap_wrapper->GetCaptureId()
                                                                          : format::kNullHandleId,
                                                GetThreadData()->parameter_buffer_.get());
    }
}

void D3D12CaptureManager::PostProcess_ID3D12CommandQueue_CopyTileMappings(
    ID3D12CommandQueue_Wrapper*            queue_wrapper,
    ID3D12Resource*                        dst_resource,
    const D3D12_TILED_RESOURCE_COORDINATE* dst_region_start_coordinate,
    ID3D12Resource*                        src_resource,
    const D3D12_TILED_RESOURCE_COORDINATE* src_region_start_coordinate,
    const D3D12_TILE_REGION_SIZE*          region_size,
    D3D12_TILE_MAPPING_FLAGS               flags)
{
    // TODO (GH #297): Implement tracking for CopyTileMappings.
    if ((GetCaptureMode() & kModeTrack) == kModeTrack)
    {
        GFXRECON_LOG_ERROR("ID3D12CommandQueue::CopyTileMappings support is not implemented for trimmed capture.");
    }
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
