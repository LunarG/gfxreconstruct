/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2021 LunarG, Inc.
** Copyright (c) 2021-2025 Advanced Micro Devices, Inc. All rights reserved.
** Copyright (c) 2023 Qualcomm Technologies, Inc. and/or its subsidiaries.
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
#include "generated/generated_dx12_struct_unwrappers.h"
#include "generated/generated_dx12_api_call_encoders.h"
#include "decode/dx12_enum_util.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

static constexpr char kDx12RuntimeName[] = "D3D12Core.dll";

D3D12CaptureManager*  D3D12CaptureManager::singleton_  = nullptr;
thread_local uint32_t D3D12CaptureManager::call_scope_ = 0;

D3D12CaptureManager::D3D12CaptureManager() :
    ApiCaptureManager(format::ApiFamilyId::ApiFamily_D3D12), dxgi_dispatch_table_{}, d3d12_dispatch_table_{},
    debug_layer_enabled_(false), debug_device_lost_enabled_(false),
    track_enable_debug_layer_object_id_(format::kNullHandleId), frame_buffer_renderer_(nullptr)
{}

bool D3D12CaptureManager::CreateInstance()
{
    bool ret = CommonCaptureManager::CreateInstance<D3D12CaptureManager>();

    GFXRECON_ASSERT(singleton_);

    if (singleton_->IsAnnotated() == true && singleton_->resource_value_annotator_ == nullptr)
    {
        singleton_->resource_value_annotator_ = std::make_unique<Dx12ResourceValueAnnotator>();
    }
    return ret;
}

D3D12CaptureManager* D3D12CaptureManager::InitSingleton()
{
    if (!singleton_)
    {
        singleton_ = new D3D12CaptureManager();
    }
    return singleton_;
}

void D3D12CaptureManager::DestroySingleton()
{
    if (singleton_)
    {
        delete singleton_;
        singleton_ = nullptr;
    }
}

void D3D12CaptureManager::DestroyInstance()
{
    GFXRECON_ASSERT(singleton_ && singleton_->common_manager_);
    singleton_->common_manager_->DestroyInstance(singleton_);
}

void D3D12CaptureManager::EndCreateApiCallCapture(HRESULT result, REFIID riid, void** handle)
{
    if (IsCaptureModeTrack() && SUCCEEDED(result))
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

#ifdef GFXRECON_AGS_SUPPORT
void D3D12CaptureManager::EndAgsApiCallCapture(HRESULT result, void* object_ptr)
{
    if (IsCaptureModeTrack())
    {
        if (SUCCEEDED(result))
        {
            GFXRECON_ASSERT(state_tracker_ != nullptr);

            auto thread_data = GetThreadData();
            GFXRECON_ASSERT(thread_data != nullptr);

            state_tracker_->TrackAgsCalls(object_ptr, thread_data->call_id_, thread_data->parameter_buffer_.get());
        }
    }

    EndApiCallCapture();
}

void D3D12CaptureManager::EndAgsApiCallCapture(ID3D12GraphicsCommandList_Wrapper* list_wrapper)
{
    if (IsCaptureModeTrack())
    {
        assert(state_tracker_ != nullptr);

        auto thread_data = GetThreadData();
        assert(thread_data != nullptr);

        state_tracker_->TrackCommand(list_wrapper, thread_data->call_id_, thread_data->parameter_buffer_.get());
    }
    else
    {
        EndApiCallCapture();
    }
}
#endif // GFXRECON_AGS_SUPPORT

void D3D12CaptureManager::EndCreateDescriptorMethodCallCapture(D3D12_CPU_DESCRIPTOR_HANDLE dest_descriptor,
                                                               ID3D12Device_Wrapper*       create_object_wrapper)
{
    if (IsCaptureModeTrack() && (dest_descriptor.ptr != 0))
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

void D3D12CaptureManager::EndCommandListMethodCallCapture(ID3D12CommandList_Wrapper* list_wrapper)
{
    if (IsCaptureModeTrack())
    {
        assert(state_tracker_ != nullptr);

        auto thread_data = GetThreadData();
        assert(thread_data != nullptr);

        state_tracker_->TrackCommand(list_wrapper, thread_data->call_id_, thread_data->parameter_buffer_.get());
    }

    EndMethodCallCapture();
}

void D3D12CaptureManager::WriteTrackedState(util::FileOutputStream* file_stream, util::ThreadData* thread_data)
{
    Dx12StateWriter state_writer(file_stream, GetCompressor(), thread_data->thread_id_);
    state_tracker_->WriteState(&state_writer, GetCurrentFrame());
}

void D3D12CaptureManager::InitializeSwapChainInfo(IDXGISwapChain_Wrapper* wrapper,
                                                  IUnknown*               unknown,
                                                  uint32_t                buffer_count,
                                                  DXGI_SWAP_EFFECT        swap_effect)
{
    GFXRECON_ASSERT(wrapper != nullptr);

    auto info = wrapper->GetObjectInfo();
    GFXRECON_ASSERT(info != nullptr);

    info->buffer_count = buffer_count;
    info->swap_effect  = swap_effect;

    if (unknown != nullptr)
    {
        // Attempt to retrieve an ID3D12CommandQueue interface from the IUnknown interface.
        HRESULT hr = unknown->QueryInterface(IID_PPV_ARGS(&info->command_queue));
        if (SUCCEEDED(hr))
        {
            info->command_queue_id = GetDx12WrappedId<IUnknown>(unknown);
        }
        else
        {
            // Attempt to retrieve an ID3D11Device interface from the IUnknown interface.
            hr = unknown->QueryInterface(IID_PPV_ARGS(&info->device));
            if (SUCCEEDED(hr))
            {
                info->device_id = GetDx12WrappedId<IUnknown>(unknown);
            }
        }
    }

    AcquireSwapChainImages(wrapper, info.get(), buffer_count);
}

void D3D12CaptureManager::AcquireSwapChainImages(IDXGISwapChain_Wrapper* wrapper,
                                                 IDXGISwapChainInfo*     info,
                                                 uint32_t                image_count)
{
    GFXRECON_ASSERT((wrapper != nullptr) && (info != nullptr));

    if (info->child_images.empty())
    {
        auto acquirable_image_count = image_count;

        // Only the image at index 0 can be retrieved when using DXGI_SWAP_EFFECT_DISCARD. With D3D11,
        // DXGI_SWAP_EFFECT_FLIP_DISCARD has the same index 0 limitation as DXGI_SWAP_EFFECT_DISCARD. For this case, the
        // image only needs to be acquired once after swap chain creation or buffer resize.
        if ((info->swap_effect == DXGI_SWAP_EFFECT_DISCARD) ||
            ((info->device_id != format::kNullHandleId) && (info->swap_effect == DXGI_SWAP_EFFECT_FLIP_DISCARD)))
        {
            acquirable_image_count = 1;
        }

        info->child_images.resize(acquirable_image_count);

        if (IsCaptureModeTrack())
        {
            // TODO: In VK version, this thing is done in InitializeGroupObjectState,
            //       This might need to be removed to InitializeGroupObjectState when it's ready.
            info->image_acquired_info.resize(acquirable_image_count);
        }

        auto swap_chain = wrapper->GetWrappedObjectAs<IDXGISwapChain>();
        GFXRECON_ASSERT(swap_chain != nullptr);

        for (uint32_t i = 0; i < acquirable_image_count; ++i)
        {
            auto result = E_FAIL;

            if (info->command_queue_id != format::kNullHandleId)
            {
                ID3D12Resource* resource = nullptr;
                result                   = swap_chain->GetBuffer(i, IID_PPV_ARGS(&resource));
                if (SUCCEEDED(result))
                {
                    WrapID3D12Resource(IID_PPV_ARGS(&resource), nullptr);

                    // Convert the application reference to an internal-only reference to avoid altering the application
                    // reference count by only holding an internal reference to the wrapped resource.
                    ID3D12Resource_Wrapper* resource_wrapper = reinterpret_cast<ID3D12Resource_Wrapper*>(resource);
                    resource_wrapper->MakeRefInternal();
                    info->child_images[i] = resource_wrapper;

                    // Initialize members of ID3D12ResourceInfo for resource_wrapper in order to track swap chain buffer
                    // state.
                    InitializeSwapChainBufferResourceInfo(wrapper, resource_wrapper, D3D12_RESOURCE_STATE_PRESENT);
                }
            }
            else if (info->device_id != format::kNullHandleId)
            {
                ID3D11Texture2D* texture2d = nullptr;
                result                     = swap_chain->GetBuffer(i, IID_PPV_ARGS(&texture2d));
                if (SUCCEEDED(result))
                {
                    // Retrieve the desc struct from the unwrapped object so that the API call is not recorded.
                    auto desc = D3D11_TEXTURE2D_DESC{};
                    texture2d->GetDesc(&desc);

                    WrapID3D11Texture2D(IID_PPV_ARGS(&texture2d), nullptr);

                    // Convert the application reference to an internal-only reference to avoid altering the
                    // application reference count by only holding an internal reference to the wrapped texture.
                    ID3D11Texture2D_Wrapper* texture2d_wrapper = reinterpret_cast<ID3D11Texture2D_Wrapper*>(texture2d);
                    texture2d_wrapper->MakeRefInternal();
                    info->child_images[i] = texture2d_wrapper;

                    // Initialize members of ID3D11Texture2DInfo for texture2d_wrapper in order to track swap chain
                    // buffer state and assist with capturing mapped memory writes.
                    InitializeID3D11Texture2DInfo(texture2d_wrapper, &desc);
                }
            }

            if (FAILED(result))
            {
                if (result == E_NOINTERFACE)
                {
                    GFXRECON_LOG_WARNING("IDXGISwapChain::GetBuffer() returned E_NOINTERFACE when called with "
                                         "IID_ID3D12Resource and IID_ID3D11Texture2D, ensure that the captured "
                                         "application is using the Direct3D API");
                }
                else
                {
                    GFXRECON_LOG_WARNING(
                        "IDXGISwapChain::GetBuffer() failed when attempting to pre-acquire swap chain images");
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

void D3D12CaptureManager::ResizeSwapChainImages(IDXGISwapChain_Wrapper* wrapper, HRESULT result, UINT buffer_count)
{
    if (SUCCEEDED(result) && (wrapper != nullptr))
    {
        auto info = wrapper->GetObjectInfo();
        GFXRECON_ASSERT(info != nullptr);

        // If ResizeBuffers is called with buffer_count == 0, the number of swap chain buffers doesn't change, so use
        // the value stored at swap chain creation.
        UINT final_buffer_count = buffer_count;
        if (final_buffer_count == 0)
        {
            final_buffer_count = info->buffer_count;
        }

        AcquireSwapChainImages(wrapper, info.get(), final_buffer_count);

        if (IsCaptureModeTrack())
        {
            state_tracker_->TrackResizeBuffers(
                wrapper, format::ApiCall_IDXGISwapChain_ResizeBuffers, GetThreadData()->parameter_buffer_.get());
        }
    }
}

void D3D12CaptureManager::InitializeID3D12ResourceInfo(ID3D12Device_Wrapper*    device_wrapper,
                                                       ID3D12Resource_Wrapper*  resource_wrapper,
                                                       D3D12_RESOURCE_DIMENSION dimension,
                                                       D3D12_TEXTURE_LAYOUT     layout,
                                                       UINT64                   width,
                                                       D3D12_HEAP_TYPE          heap_type,
                                                       D3D12_CPU_PAGE_PROPERTY  page_property,
                                                       D3D12_MEMORY_POOL        memory_pool,
                                                       D3D12_RESOURCE_STATES    initial_state,
                                                       bool                     has_write_watch,
                                                       ID3D12Heap_Wrapper*      heap_wrapper,
                                                       uint64_t                 heap_offset)
{
    assert(resource_wrapper != nullptr);

    auto info = resource_wrapper->GetObjectInfo();
    assert((info != nullptr) && (device_wrapper != nullptr));

    info->device_wrapper  = device_wrapper;
    info->heap_type       = heap_type;
    info->page_property   = page_property;
    info->memory_pool     = memory_pool;
    info->has_write_watch = has_write_watch;
    info->dimension       = dimension;
    info->layout          = layout;
    info->heap_offset     = heap_offset;
    info->heap_wrapper    = heap_wrapper;
    if (heap_wrapper != nullptr)
    {
        info->heap_id = heap_wrapper->GetCaptureId();
    }

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

        graphics::dx12::RobustGetCopyableFootprint(
            device, resource, &full_desc, 0, num_subresources, 0, layouts.get(), nullptr, nullptr, nullptr);

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
    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackResourceCreation(resource_wrapper, initial_state, false);
    }
}

void D3D12CaptureManager::InitializeSwapChainBufferResourceInfo(IDXGISwapChain_Wrapper* wrapper,
                                                                ID3D12Resource_Wrapper* resource_wrapper,
                                                                D3D12_RESOURCE_STATES   initial_state)
{
    GFXRECON_ASSERT(resource_wrapper != nullptr);
    GFXRECON_ASSERT(resource_wrapper->GetObjectInfo() != nullptr);

    auto info = resource_wrapper->GetObjectInfo();
    GFXRECON_ASSERT(info);

    info->swapchain_wrapper = wrapper;

    // Get the swapchain's native ID3D12Device
    graphics::dx12::ID3D12DeviceComPtr device;
    wrapper->GetDevice(IID_PPV_ARGS(&device));

    // Get the ID3D12Device_Wrapper
    ID3D12Device_Wrapper* device_wrapper = ID3D12Device_Wrapper::GetExistingWrapper(device);

    // Not all fields of ID3D12ResourceInfo are used for swap chain buffers.
    info->num_subresources     = 1;
    info->mapped_subresources  = std::make_unique<MappedSubresource[]>(info->num_subresources);
    info->subresource_sizes    = std::make_unique<uint64_t[]>(info->num_subresources);
    info->subresource_sizes[0] = 0;
    info->device_wrapper       = device_wrapper;

    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackResourceCreation(resource_wrapper, initial_state, true);
    }
}

void D3D12CaptureManager::InitializeID3D12DeviceInfo(IUnknown* adapter, void** device)
{
    GFXRECON_ASSERT(device != nullptr);
    GFXRECON_ASSERT(*device != nullptr);

    if ((device != nullptr) && (*device != nullptr))
    {
        auto device_wrapper = reinterpret_cast<ID3D12Device_Wrapper*>(*device);
        auto info           = device_wrapper->GetObjectInfo();

        if (info != nullptr)
        {
            graphics::dx12::GetAdapterAndIndexbyDevice(
                reinterpret_cast<ID3D12Device*>(*device), info->adapter3, info->adapter_node_index, adapters_);

            // Cache info on device features:
            auto wrapped_device = device_wrapper->GetWrappedObjectAs<ID3D12Device>();
            info->is_uma        = graphics::dx12::IsUma(wrapped_device);
        }
    }
}

bool D3D12CaptureManager::IsAccelerationStructureResource(format::HandleId id)
{
    return state_tracker_->IsAccelerationStructureResource(id);
}

void D3D12CaptureManager::CheckWriteWatchIgnored(D3D12_HEAP_FLAGS flags, format::HandleId id)
{
    // Report that write watch was ignored because the application enabled it.
    if (IsPageGuardMemoryModeExternal() &&
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
    if (IsPageGuardMemoryModeExternal() &&
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

uint64_t D3D12CaptureManager::GetResourceSizeInBytes(ID3D12Device_Wrapper*      device_wrapper,
                                                     const D3D12_RESOURCE_DESC* desc)
{
    auto device = device_wrapper->GetWrappedObjectAs<ID3D12Device>();
    return graphics::dx12::GetResourceSizeInBytes(device, desc);
}

uint64_t D3D12CaptureManager::GetResourceSizeInBytes(ID3D12Device8_Wrapper*      device_wrapper,
                                                     const D3D12_RESOURCE_DESC1* desc)
{
    auto device = device_wrapper->GetWrappedObjectAs<ID3D12Device8>();
    return graphics::dx12::GetResourceSizeInBytes(device, desc);
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

        InitializeSwapChainInfo(swap_chain_wrapper, device, desc->BufferCount, desc->SwapEffect);
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

        InitializeSwapChainInfo(swap_chain_wrapper, device, desc->BufferCount, desc->SwapEffect);
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

        InitializeSwapChainInfo(swap_chain_wrapper, device, desc->BufferCount, desc->SwapEffect);
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

        InitializeSwapChainInfo(swap_chain_wrapper, device, desc->BufferCount, desc->SwapEffect);
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

void D3D12CaptureManager::PrePresent(IDXGISwapChain_Wrapper* swapchain_wrapper)
{
    if (ShouldTriggerScreenshot())
    {
        auto swapchain_info = swapchain_wrapper->GetObjectInfo();
        GFXRECON_ASSERT(swapchain_info != nullptr);
        if (swapchain_info->command_queue)
        {
            auto swapchain = swapchain_wrapper->GetWrappedObjectAs<IDXGISwapChain>();

            gfxrecon::graphics::dx12::TakeScreenshot(frame_buffer_renderer_,
                                                     swapchain_info->command_queue,
                                                     swapchain,
                                                     GetCurrentFrame(),
                                                     common_manager_->GetScreenshotPrefix(),
                                                     common_manager_->GetScreenshotFormat());
        }
        else
        {
            GFXRECON_LOG_ERROR("Failed to get the ID3D12CommandQueue associated with the presented swap chain. "
                               "GFXReconstruct is unable to take a screenshot.");
        }
    }
}

void D3D12CaptureManager::PostPresent(std::shared_lock<CommonCaptureManager::ApiCallMutexT>& current_lock,
                                      IDXGISwapChain_Wrapper*                                swapchain_wrapper,
                                      UINT                                                   flags)
{
    if ((flags & DXGI_PRESENT_TEST) == 0)
    {
        EndFrame(current_lock);
    }
}

void D3D12CaptureManager::PreProcess_IDXGISwapChain_Present(IDXGISwapChain_Wrapper* wrapper,
                                                            UINT                    sync_interval,
                                                            UINT                    flags)
{
    GFXRECON_UNREFERENCED_PARAMETER(sync_interval);
    GFXRECON_UNREFERENCED_PARAMETER(flags);

    PrePresent(wrapper);
}

void D3D12CaptureManager::PreProcess_IDXGISwapChain1_Present1(IDXGISwapChain_Wrapper*        wrapper,
                                                              UINT                           sync_interval,
                                                              UINT                           present_flags,
                                                              const DXGI_PRESENT_PARAMETERS* present_parameters)
{
    GFXRECON_UNREFERENCED_PARAMETER(sync_interval);
    GFXRECON_UNREFERENCED_PARAMETER(present_flags);
    GFXRECON_UNREFERENCED_PARAMETER(present_parameters);

    PrePresent(wrapper);
}

void D3D12CaptureManager::PostProcess_IDXGISwapChain_Present(
    std::shared_lock<CommonCaptureManager::ApiCallMutexT>& current_lock,
    IDXGISwapChain_Wrapper*                                wrapper,
    HRESULT                                                result,
    UINT                                                   sync_interval,
    UINT                                                   flags)
{
    GFXRECON_UNREFERENCED_PARAMETER(result);
    GFXRECON_UNREFERENCED_PARAMETER(sync_interval);

    PostPresent(current_lock, wrapper, flags);
}

void D3D12CaptureManager::PostProcess_IDXGISwapChain1_Present1(
    std::shared_lock<CommonCaptureManager::ApiCallMutexT>& current_lock,
    IDXGISwapChain_Wrapper*                                wrapper,
    HRESULT                                                result,
    UINT                                                   sync_interval,
    UINT                                                   present_flags,
    const DXGI_PRESENT_PARAMETERS*                         present_parameters)
{
    GFXRECON_UNREFERENCED_PARAMETER(result);
    GFXRECON_UNREFERENCED_PARAMETER(sync_interval);
    GFXRECON_UNREFERENCED_PARAMETER(present_parameters);

    PostPresent(current_lock, wrapper, present_flags);
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

    ResizeSwapChainImages(wrapper, result, buffer_count);
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

    ResizeSwapChainImages(wrapper, result, buffer_count);
}

void D3D12CaptureManager::PreProcess_IDXGISwapChain_ResizeTarget(IDXGISwapChain_Wrapper* wrapper,
                                                                 const DXGI_MODE_DESC*   pNewTargetParameters)
{
    GFXRECON_UNREFERENCED_PARAMETER(wrapper);
    GFXRECON_UNREFERENCED_PARAMETER(pNewTargetParameters);

    // ResizeTarget will resize the window associated with the swapchain. If the window has an event callback, it will
    // be invoked for a resize event before ResizeTarget returns. Any API calls made by the callback will not be
    // processed for capture due to the current scope count, resulting in a capture file that will not replay correctly
    // due to missing API calls. The scope count needs to be temporarily decremented to ensure that API calls made by
    // the callback are captured.
    DecrementCallScope();
}

void D3D12CaptureManager::PostProcess_IDXGISwapChain_ResizeTarget(IDXGISwapChain_Wrapper* wrapper,
                                                                  HRESULT                 result,
                                                                  const DXGI_MODE_DESC*   pNewTargetParameters)
{
    GFXRECON_UNREFERENCED_PARAMETER(wrapper);
    GFXRECON_UNREFERENCED_PARAMETER(result);
    GFXRECON_UNREFERENCED_PARAMETER(pNewTargetParameters);

    // Restore the scope count that was decremented by the pre call.
    IncrementCallScope();
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

        info->descriptor_memory    = std::make_unique<uint8_t[]>(static_cast<size_t>(num_descriptors) * increment);
        info->descriptor_info      = std::make_unique<DxDescriptorInfo[]>(num_descriptors);
        info->descriptor_increment = increment;

        size_t                      offset    = 0;
        auto                        cpu_start = descriptor_heap->GetCPUDescriptorHandleForHeapStart();
        D3D12_GPU_DESCRIPTOR_HANDLE gpu_start{ 0 };

        // D3D12 validation layer states GetGPUDescriptorHandleForHeapStart() should only be used for heaps
        // with D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE flag set.
        if (desc->Flags & D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE)
        {
            gpu_start = descriptor_heap->GetGPUDescriptorHandleForHeapStart();
        }

        for (uint32_t i = 0; i < num_descriptors; ++i)
        {
            auto current = &info->descriptor_info[i];

            current->heap_id     = heap_wrapper->GetCaptureId();
            current->index       = i;
            current->cpu_address = cpu_start.ptr + offset;
            if (gpu_start.ptr != 0)
            {
                current->gpu_address = gpu_start.ptr + offset;
            }

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
        info->heap_size       = desc->SizeInBytes;

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

        InitializeID3D12ResourceInfo(wrapper,
                                     resource_wrapper,
                                     desc->Dimension,
                                     desc->Layout,
                                     desc->Width,
                                     heap_properties->Type,
                                     heap_properties->CPUPageProperty,
                                     heap_properties->MemoryPoolPreference,
                                     initial_resource_state,
                                     UseWriteWatch(heap_properties->Type, heap_flags, heap_properties->CPUPageProperty),
                                     nullptr,
                                     0);

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
                                     desc->Layout,
                                     desc->Width,
                                     heap_info->heap_type,
                                     heap_info->page_property,
                                     heap_info->memory_pool,
                                     initial_state,
                                     heap_info->has_write_watch,
                                     heap_wrapper,
                                     heap_offset);
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
                                     desc->Layout,
                                     desc->Width,
                                     D3D12_HEAP_TYPE_DEFAULT,
                                     D3D12_CPU_PAGE_PROPERTY_UNKNOWN,
                                     D3D12_MEMORY_POOL_UNKNOWN,
                                     initial_state,
                                     false,
                                     nullptr,
                                     0);
    }
}

void D3D12CaptureManager::PostProcess_ID3D12Device4_CreateReservedResource1(
    ID3D12Device4_Wrapper*          wrapper,
    HRESULT                         result,
    const D3D12_RESOURCE_DESC*      desc,
    D3D12_RESOURCE_STATES           initial_state,
    const D3D12_CLEAR_VALUE*        optimized_clear_value,
    ID3D12ProtectedResourceSession* protected_session,
    REFIID                          riid,
    void**                          resource)
{
    GFXRECON_UNREFERENCED_PARAMETER(optimized_clear_value);
    GFXRECON_UNREFERENCED_PARAMETER(protected_session);
    GFXRECON_UNREFERENCED_PARAMETER(riid);

    if (SUCCEEDED(result) && (wrapper != nullptr) && (desc != nullptr) && (resource != nullptr) &&
        ((*resource) != nullptr))
    {
        auto resource_wrapper = reinterpret_cast<ID3D12Resource_Wrapper*>(*resource);

        InitializeID3D12ResourceInfo(wrapper,
                                     resource_wrapper,
                                     desc->Dimension,
                                     desc->Layout,
                                     desc->Width,
                                     D3D12_HEAP_TYPE_DEFAULT,
                                     D3D12_CPU_PAGE_PROPERTY_UNKNOWN,
                                     D3D12_MEMORY_POOL_UNKNOWN,
                                     initial_state,
                                     false,
                                     nullptr,
                                     0);
    }
}

void D3D12CaptureManager::PostProcess_ID3D12Device10_CreateReservedResource2(
    ID3D12Device10_Wrapper*         wrapper,
    HRESULT                         result,
    const D3D12_RESOURCE_DESC*      desc,
    D3D12_BARRIER_LAYOUT            initial_layout,
    const D3D12_CLEAR_VALUE*        optimized_clear_value,
    ID3D12ProtectedResourceSession* protected_session,
    UINT32                          num_castable_formats,
    const DXGI_FORMAT*              castable_formats,
    REFIID                          riid,
    void**                          resource)
{
    GFXRECON_UNREFERENCED_PARAMETER(initial_layout);
    GFXRECON_UNREFERENCED_PARAMETER(optimized_clear_value);
    GFXRECON_UNREFERENCED_PARAMETER(protected_session);
    GFXRECON_UNREFERENCED_PARAMETER(num_castable_formats);
    GFXRECON_UNREFERENCED_PARAMETER(riid);

    if (SUCCEEDED(result) && (wrapper != nullptr) && (desc != nullptr) && (resource != nullptr) &&
        ((*resource) != nullptr))
    {
        auto resource_wrapper = reinterpret_cast<ID3D12Resource_Wrapper*>(*resource);

        InitializeID3D12ResourceInfo(wrapper,
                                     resource_wrapper,
                                     desc->Dimension,
                                     desc->Layout,
                                     desc->Width,
                                     D3D12_HEAP_TYPE_DEFAULT,
                                     D3D12_CPU_PAGE_PROPERTY_UNKNOWN,
                                     D3D12_MEMORY_POOL_UNKNOWN,
                                     D3D12_RESOURCE_STATE_COMMON,
                                     false,
                                     nullptr,
                                     0);
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

    if (IsCaptureModeWrite())
    {
        MEMORY_BASIC_INFORMATION info{};

        auto result = VirtualQuery(address, &info, sizeof(info));
        if (result > 0)
        {
            common_manager_->WriteCreateHeapAllocationCmd(
                api_family_, reinterpret_cast<uint64_t>(address), info.RegionSize);
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

    if (IsCaptureModeTrack())
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

        InitializeID3D12ResourceInfo(wrapper,
                                     resource_wrapper,
                                     desc->Dimension,
                                     desc->Layout,
                                     desc->Width,
                                     heap_properties->Type,
                                     heap_properties->CPUPageProperty,
                                     heap_properties->MemoryPoolPreference,
                                     initial_resource_state,
                                     UseWriteWatch(heap_properties->Type, heap_flags, heap_properties->CPUPageProperty),
                                     nullptr,
                                     0);

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

        InitializeID3D12ResourceInfo(wrapper,
                                     resource_wrapper,
                                     desc->Dimension,
                                     desc->Layout,
                                     desc->Width,
                                     heap_properties->Type,
                                     heap_properties->CPUPageProperty,
                                     heap_properties->MemoryPoolPreference,
                                     initial_resource_state,
                                     UseWriteWatch(heap_properties->Type, heap_flags, heap_properties->CPUPageProperty),
                                     nullptr,
                                     0);

        CheckWriteWatchIgnored(heap_flags, resource_wrapper->GetCaptureId());
    }
}

void D3D12CaptureManager::PostProcess_ID3D12Device10_CreateCommittedResource3(
    ID3D12Device10_Wrapper*         wrapper,
    HRESULT                         result,
    const D3D12_HEAP_PROPERTIES*    heap_properties,
    D3D12_HEAP_FLAGS                heap_flags,
    const D3D12_RESOURCE_DESC1*     desc,
    D3D12_BARRIER_LAYOUT            initial_layout,
    const D3D12_CLEAR_VALUE*        optimized_clear_value,
    ID3D12ProtectedResourceSession* protected_session,
    UINT32                          num_castable_formats,
    const DXGI_FORMAT*              castable_formats,
    REFIID                          riid,
    void**                          resource)
{
    GFXRECON_UNREFERENCED_PARAMETER(optimized_clear_value);
    GFXRECON_UNREFERENCED_PARAMETER(initial_layout);
    GFXRECON_UNREFERENCED_PARAMETER(optimized_clear_value);
    GFXRECON_UNREFERENCED_PARAMETER(num_castable_formats);
    GFXRECON_UNREFERENCED_PARAMETER(castable_formats);
    GFXRECON_UNREFERENCED_PARAMETER(riid);

    if (SUCCEEDED(result) && (wrapper != nullptr) && (heap_properties != nullptr) && (desc != nullptr) &&
        (resource != nullptr) && ((*resource) != nullptr))
    {
        auto resource_wrapper = reinterpret_cast<ID3D12Resource_Wrapper*>(*resource);

        InitializeID3D12ResourceInfo(wrapper,
                                     resource_wrapper,
                                     desc->Dimension,
                                     desc->Layout,
                                     desc->Width,
                                     heap_properties->Type,
                                     heap_properties->CPUPageProperty,
                                     heap_properties->MemoryPoolPreference,
                                     D3D12_RESOURCE_STATE_COMMON,
                                     UseWriteWatch(heap_properties->Type, heap_flags, heap_properties->CPUPageProperty),
                                     nullptr,
                                     0);

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
                                     desc->Layout,
                                     desc->Width,
                                     heap_info->heap_type,
                                     heap_info->page_property,
                                     heap_info->memory_pool,
                                     initial_state,
                                     heap_info->has_write_watch,
                                     heap_wrapper,
                                     heap_offset);
    }
}

void D3D12CaptureManager::PostProcess_ID3D12Device10_CreatePlacedResource2(
    ID3D12Device10_Wrapper*     wrapper,
    HRESULT                     result,
    ID3D12Heap*                 heap,
    UINT64                      heap_offset,
    const D3D12_RESOURCE_DESC1* desc,
    D3D12_BARRIER_LAYOUT        initial_layout,
    const D3D12_CLEAR_VALUE*    optimized_clear_value,
    UINT32                      num_castable_formats,
    const DXGI_FORMAT*          castable_formats,
    REFIID                      riid,
    void**                      resource)
{
    GFXRECON_UNREFERENCED_PARAMETER(heap_offset);
    GFXRECON_UNREFERENCED_PARAMETER(initial_layout);
    GFXRECON_UNREFERENCED_PARAMETER(optimized_clear_value);
    GFXRECON_UNREFERENCED_PARAMETER(num_castable_formats);
    GFXRECON_UNREFERENCED_PARAMETER(castable_formats);
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
                                     desc->Layout,
                                     desc->Width,
                                     heap_info->heap_type,
                                     heap_info->page_property,
                                     heap_info->memory_pool,
                                     D3D12_RESOURCE_STATE_COMMON,
                                     heap_info->has_write_watch,
                                     heap_wrapper,
                                     heap_offset);
    }
}

void D3D12CaptureManager::PostProcess_ID3D12Resource_Map(
    ID3D12Resource_Wrapper* wrapper, HRESULT result, UINT subresource, const D3D12_RANGE* read_range, void** data)
{
    // This function contains handling for two cases:
    // 1. data != null
    // 2. data == null
    GFXRECON_UNREFERENCED_PARAMETER(read_range);
    if (data != nullptr)
    {
        // Handle first case, when data != null (like we've always done):
        if (SUCCEEDED(result) && (wrapper != nullptr))
        {
            auto info = wrapper->GetObjectInfo();
            assert((info != nullptr) && (subresource < info->num_subresources));

            if (IsUploadResource(info->heap_type, info->page_property))
            {
                auto& mapped_subresource = info->mapped_subresources[subresource];

                std::lock_guard<std::mutex> lock(GetMappedMemoryLock());
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
                        else if (IsPageGuardMemoryModeShadowPersistent() &&
                                 (mapped_subresource.shadow_allocation == util::PageGuardManager::kNullShadowHandle))
                        {
                            mapped_subresource.shadow_allocation =
                                manager->AllocatePersistentShadowMemory(static_cast<size_t>(size));
                        }

                        // Return the pointer provided by the pageguard manager, which may be a pointer to shadow
                        // memory, not the mapped memory.
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

                        auto found =
                            manager->GetTrackedMemory(reinterpret_cast<uint64_t>(mapped_subresource.data), data);
                        if (!found)
                        {
                            GFXRECON_LOG_ERROR("Failed to find tracked memory object for a previously mapped resource.")
                        }
                    }
                }
            }
        }
    }
    else
    {
        // Handle second case, when data == null
        //
        // Quote: "A null pointer is valid and is useful to cache a CPU virtual address range for methods like
        // WriteToSubresource."
        //
        // Source: https://docs.microsoft.com/en-us/windows/win32/api/d3d12/nf-d3d12-id3d12resource-map
        //
        //    1. Make sure we add a MappedSubresource struct into mapped_subresources array
        //
        //    2. Skip tracking memory since no mapped memory or shadow memory need to be tracked. Target application
        //       cannot write to the mapped memory directly. The only way to update the memory is through API
        //       ID3D12Resource::WriteToSubresource()
        if (SUCCEEDED(result) && (wrapper != nullptr))
        {
            auto info = wrapper->GetObjectInfo();
            assert((info != nullptr) && (subresource < info->num_subresources));

            if (IsUploadResource(info->heap_type, info->page_property))
            {
                auto& mapped_subresource = info->mapped_subresources[subresource];

                std::lock_guard<std::mutex> lock(GetMappedMemoryLock());
                if (++mapped_subresource.map_count == 1)
                {
                    if (GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kUnassisted)
                    {
                        // Need to keep track of mapped memory objects so memory content can be written at queue submit.
                        mapped_resources_.insert(wrapper);
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
    // This function contains handling for two cases:
    // 1. mapped_subresource.data != null
    // 2. mapped_subresource.data == null
    if (wrapper != nullptr)
    {
        auto info = wrapper->GetObjectInfo();
        assert((info != nullptr) && (subresource < info->num_subresources));

        if (IsUploadResource(info->heap_type, info->page_property))
        {
            auto& mapped_subresource = info->mapped_subresources[subresource];
            if (mapped_subresource.data != nullptr)
            {
                // Handle first case, when mapped_subresource.data != null (like we've always done):
                std::lock_guard<std::mutex> lock(GetMappedMemoryLock());
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
                                    if (RvAnnotationActive() == true)
                                    {
                                        resource_value_annotator_->ScanForGPUVA(
                                            memory_id,
                                            reinterpret_cast<uint8_t*>(start_address) + offset,
                                            size,
                                            offset);
                                    }
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
                            if (RvAnnotationActive() == true)
                            {
                                resource_value_annotator_->ScanForGPUVA(
                                    reinterpret_cast<uint64_t>(mapped_subresource.data),
                                    reinterpret_cast<uint8_t*>(mapped_subresource.data) + offset,
                                    size,
                                    offset);
                            }
                            WriteFillMemoryCmd(reinterpret_cast<uint64_t>(mapped_subresource.data),
                                               offset,
                                               size,
                                               mapped_subresource.data);

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
            else
            {
                // Handle second case, when mapped_subresource.data == null
                //
                // Quote: "A null pointer is valid and is useful to cache a CPU virtual address range for methods like
                // WriteToSubresource."
                //
                // Source: https://docs.microsoft.com/en-us/windows/win32/api/d3d12/nf-d3d12-id3d12resource-map
                std::lock_guard<std::mutex> lock(GetMappedMemoryLock());
                if (mapped_subresource.map_count > 0)
                {
                    if (--mapped_subresource.map_count == 0)
                    {
                        if (GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kUnassisted)
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
}

void D3D12CaptureManager::PostProcess_ID3D12Resource_GetHeapProperties(ID3D12Resource_Wrapper* wrapper,
                                                                       HRESULT                 result,
                                                                       D3D12_HEAP_PROPERTIES*  heap_properties,
                                                                       D3D12_HEAP_FLAGS*       heap_flags)
{
    GFXRECON_UNREFERENCED_PARAMETER(wrapper);
    GFXRECON_UNREFERENCED_PARAMETER(heap_properties);

    if (SUCCEEDED(result) && (heap_flags != nullptr) && (IsPageGuardMemoryModeExternal()))
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

void D3D12CaptureManager::PostProcess_ID3D12Resource_GetGPUVirtualAddress(ID3D12Resource_Wrapper*   wrapper,
                                                                          D3D12_GPU_VIRTUAL_ADDRESS result)
{
    if (IsCaptureModeTrack() && (result != 0))
    {
        state_tracker_->TrackResourceGpuVa(wrapper, result);
    }

    if (RvAnnotationActive() == true)
    {
        resource_value_annotator_->PostProcessGetGPUVirtualAddress(wrapper, result);
    }
}

bool D3D12CaptureManager::AddFillMemoryResourceValueCommand(
    const std::map<uint64_t, Dx12ResourceValueAnnotator::Dx12FillCommandResourceValue>& resource_values)
{
    bool success = true;
    if (IsCaptureModeWrite())
    {
        std::vector<uint8_t>                         write_buffer;
        format::FillMemoryResourceValueCommandHeader rv_header;
        rv_header.meta_header.block_header.type = format::BlockType::kMetaDataBlock;
        rv_header.meta_header.meta_data_id      = format::MakeMetaDataId(
            format::ApiFamilyId::ApiFamily_D3D12, format::MetaDataType::kFillMemoryResourceValueCommand);
        rv_header.thread_id            = 0;
        rv_header.resource_value_count = resource_values.size();

        size_t       header_size = sizeof(format::FillMemoryResourceValueCommandHeader);
        const size_t uncompressed_size =
            resource_values.size() * (sizeof(format::ResourceValueType) + sizeof(uint64_t));

        write_buffer.clear();
        write_buffer.resize(uncompressed_size);

        // Write resource value data to uncompressed buffer.
        auto type_data_pos = write_buffer.data();
        auto offset_data_pos =
            write_buffer.data() + (rv_header.resource_value_count * sizeof(format::ResourceValueType));
        for (const auto& resource_value_pair : resource_values)
        {
            auto type   = resource_value_pair.second.type;
            auto offset = resource_value_pair.second.offset;

            util::platform::MemoryCopy(type_data_pos, sizeof(type), &type, sizeof(type));
            util::platform::MemoryCopy(offset_data_pos, sizeof(offset), &offset, sizeof(offset));

            type_data_pos += sizeof(resource_value_pair.second.type);
            offset_data_pos += sizeof(resource_value_pair.second.offset);
        }
        GFXRECON_ASSERT(type_data_pos ==
                        (write_buffer.data() + (rv_header.resource_value_count * sizeof(format::ResourceValueType))));
        GFXRECON_ASSERT(offset_data_pos == (write_buffer.data() + uncompressed_size));

        bool not_compressed = true;

        std::vector<uint8_t> compressed_write_buffer;

        if (GetCompressor() != nullptr)
        {
            size_t compressed_size =
                GetCompressor()->Compress(write_buffer.size(), write_buffer.data(), &compressed_write_buffer, 0);

            if ((compressed_size > 0) && (compressed_size < uncompressed_size))
            {
                not_compressed = false;

                // Calculate size of packet with compressed data size.
                rv_header.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(rv_header) + compressed_size;
                rv_header.meta_header.block_header.type = format::BlockType::kCompressedMetaDataBlock;

                CombineAndWriteToFile(
                    { { &rv_header, header_size }, { compressed_write_buffer.data(), compressed_size } });
            }
        }

        // If the data was not compressed, write the uncompressed data here.
        if (not_compressed)
        {
            // Calculate size of packet with uncompressed data size.
            rv_header.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(rv_header) + uncompressed_size;

            CombineAndWriteToFile({ { &rv_header, header_size }, { write_buffer.data(), uncompressed_size } });
        }
    }
    return success;
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
                if (mapped_subresource.data != nullptr)
                {
                    // we only need to handle mapped_subresource.data != nullptr case because no mapped memory
                    // and shadow memory be tracked for mapped_subresource.data == nullptr case.
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
                std::lock_guard<std::mutex> lock(GetMappedMemoryLock());
                mapped_resources_.erase(wrapper);
            }
        }
    }
}

void D3D12CaptureManager::PostProcess_ID3D12Heap_GetDesc(ID3D12Heap_Wrapper* wrapper, D3D12_HEAP_DESC& desc)
{
    GFXRECON_UNREFERENCED_PARAMETER(wrapper);

    if (IsPageGuardMemoryModeExternal())
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

void D3D12CaptureManager::PreProcess_ID3D12CommandQueue_ExecuteCommandLists(
    std::shared_lock<CommonCaptureManager::ApiCallMutexT>& current_lock,
    ID3D12CommandQueue_Wrapper*                            wrapper,
    UINT                                                   num_lists,
    ID3D12CommandList* const*                              lists)
{
    GFXRECON_UNREFERENCED_PARAMETER(wrapper);
    GFXRECON_UNREFERENCED_PARAMETER(num_lists);
    GFXRECON_UNREFERENCED_PARAMETER(lists);

    if (GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kPageGuard)
    {
        util::PageGuardManager* manager = util::PageGuardManager::Get();
        assert(manager != nullptr);

        manager->ProcessMemoryEntries([this](uint64_t memory_id, void* start_address, size_t offset, size_t size) {
            if (RvAnnotationActive() == true)
            {
                resource_value_annotator_->ScanForGPUVA(
                    memory_id, reinterpret_cast<uint8_t*>(start_address) + offset, size, offset);
            }
            WriteFillMemoryCmd(memory_id, offset, size, start_address);
        });
    }
    else if (GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kUnassisted)
    {
        std::lock_guard<std::mutex> lock(GetMappedMemoryLock());
        for (auto resource_wrapper : mapped_resources_)
        {
            auto info = resource_wrapper->GetObjectInfo();

            for (size_t i = 0; i < info->num_subresources; ++i)
            {
                // If the memory is mapped, write the entire mapped region.
                auto        size               = info->subresource_sizes[i];
                const auto& mapped_subresource = info->mapped_subresources[i];
                if (mapped_subresource.data != nullptr)
                {
                    // we only need to handle data != nullptr case because no mapped memory and shadow memory
                    // be tracked for data == nullptr, also no corresponding memory data for WriteFillMemoryCmd
                    // writing to trace file.
                    if (RvAnnotationActive() == true)
                    {
                        resource_value_annotator_->ScanForGPUVA(reinterpret_cast<uint64_t>(mapped_subresource.data),
                                                                reinterpret_cast<uint8_t*>(mapped_subresource.data),
                                                                size,
                                                                0);
                    }
                    WriteFillMemoryCmd(
                        reinterpret_cast<uint64_t>(mapped_subresource.data), 0, size, mapped_subresource.data);
                }
            }
        }
    }

    // Split commandlist is for trim drawcalls. It means that this is a extra ExecuteCommandLists. It shouldn't count
    // queue_submit_count_.
    if (!(IsTrimEnabled() && GetTrimBoundary() == CaptureSettings::TrimBoundary::kDrawCalls &&
          HasSplitCommandLists(num_lists, lists)))
    {
        PreQueueSubmit(current_lock);
    }
}

void D3D12CaptureManager::OverrideID3D12CommandQueue_ExecuteCommandLists(
    std::shared_lock<CommonCaptureManager::ApiCallMutexT>& current_lock,
    ID3D12CommandQueue_Wrapper*                            wrapper,
    UINT                                                   num_lists,
    ID3D12CommandList* const*                              lists)
{
    bool is_complete = false;
    if (IsTrimEnabled() && GetTrimBoundary() == CaptureSettings::TrimBoundary::kDrawCalls &&
        !HasSplitCommandLists(num_lists, lists))
    {
        is_complete = TrimDrawCalls_ID3D12CommandQueue_ExecuteCommandLists(current_lock, wrapper, num_lists, lists);
    }

    if (!is_complete)
    {
        auto queue         = wrapper->GetWrappedObjectAs<ID3D12CommandQueue>();
        auto unwrap_memory = GetHandleUnwrapMemory();
        queue->ExecuteCommandLists(num_lists, UnwrapObjects<ID3D12CommandList>(lists, num_lists, unwrap_memory));
    }
}

void D3D12CaptureManager::PostProcess_ID3D12CommandQueue_ExecuteCommandLists(
    std::shared_lock<CommonCaptureManager::ApiCallMutexT>& current_lock,
    ID3D12CommandQueue_Wrapper*                            wrapper,
    UINT                                                   num_lists,
    ID3D12CommandList* const*                              lists)
{
    // Split commandlists are for trim drawcalls. It means that this is a extra ExecuteCommandLists. It shouldn't count
    // queue_submit_count_.
    if (!(IsTrimEnabled() && GetTrimBoundary() == CaptureSettings::TrimBoundary::kDrawCalls &&
          HasSplitCommandLists(num_lists, lists)))
    {
        PostQueueSubmit(current_lock);
    }

    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackExecuteCommandLists(wrapper, num_lists, lists);
    }
}

HRESULT
D3D12CaptureManager::OverrideD3D12SerializeVersionedRootSignature(
    const D3D12_VERSIONED_ROOT_SIGNATURE_DESC* pRootSignature, ID3DBlob** ppBlob, ID3DBlob** ppErrorBlob)
{
    if (IsTrimEnabled() && GetTrimBoundary() == CaptureSettings::TrimBoundary::kDrawCalls)
    {
        TrimDrawCalls_D3D12SerializeVersionedRootSignature(pRootSignature, ppBlob, ppErrorBlob);
    }
    return GetD3D12DispatchTable().D3D12SerializeVersionedRootSignature(pRootSignature, ppBlob, ppErrorBlob);
}

D3D12_CPU_DESCRIPTOR_HANDLE D3D12CaptureManager::OverrideID3D12DescriptorHeap_GetCPUDescriptorHandleForHeapStart(
    ID3D12DescriptorHeap_Wrapper* wrapper)
{
    auto heap = wrapper->GetWrappedObjectAs<ID3D12DescriptorHeap>();
    auto info = wrapper->GetObjectInfo();
    assert(info != nullptr);

    auto result = heap->GetCPUDescriptorHandleForHeapStart();

    result.ptr = reinterpret_cast<size_t>(info->descriptor_memory.get());

    if (IsCaptureModeTrack())
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

    if (IsCaptureModeTrack())
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

        return device->CreateCommittedResource2(
            &properties_copy,
            heap_flags,
            desc,
            initial_resource_state,
            optimized_clear_value,
            encode::GetWrappedObject<ID3D12ProtectedResourceSession>(protected_session),
            riid_resource,
            ppv_resource);
    }

    return device->CreateCommittedResource2(heap_properties,
                                            heap_flags,
                                            desc,
                                            initial_resource_state,
                                            optimized_clear_value,
                                            encode::GetWrappedObject<ID3D12ProtectedResourceSession>(protected_session),
                                            riid_resource,
                                            ppv_resource);
}

HRESULT
D3D12CaptureManager::OverrideID3D12Device10_CreateCommittedResource3(ID3D12Device10_Wrapper*      wrapper,
                                                                     const D3D12_HEAP_PROPERTIES* heap_properties,
                                                                     D3D12_HEAP_FLAGS             heap_flags,
                                                                     const D3D12_RESOURCE_DESC1*  desc,
                                                                     D3D12_BARRIER_LAYOUT         initial_layout,
                                                                     const D3D12_CLEAR_VALUE*     optimized_clear_value,
                                                                     ID3D12ProtectedResourceSession* protected_session,
                                                                     UINT32             num_castable_formats,
                                                                     const DXGI_FORMAT* castable_formats,
                                                                     REFIID             riid_resource,
                                                                     void**             ppv_resource)
{
    auto device = wrapper->GetWrappedObjectAs<ID3D12Device10>();

    if ((desc == nullptr) || (heap_properties == nullptr))
    {
        return E_INVALIDARG;
    }
    else if (UseWriteWatch(heap_properties->Type, heap_flags, heap_properties->CPUPageProperty))
    {
        auto properties_copy = *heap_properties;
        EnableWriteWatch(heap_flags, properties_copy);

        return device->CreateCommittedResource3(&properties_copy,
                                                heap_flags,
                                                desc,
                                                initial_layout,
                                                optimized_clear_value,
                                                protected_session,
                                                num_castable_formats,
                                                castable_formats,
                                                riid_resource,
                                                ppv_resource);
    }

    return device->CreateCommittedResource3(heap_properties,
                                            heap_flags,
                                            desc,
                                            initial_layout,
                                            optimized_clear_value,
                                            protected_session,
                                            num_castable_formats,
                                            castable_formats,
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

        return device->CreateHeap1(
            &desc_copy, encode::GetWrappedObject<ID3D12ProtectedResourceSession>(protected_session), riid, heap);
    }
    else
    {
        return device->CreateHeap1(
            desc, encode::GetWrappedObject<ID3D12ProtectedResourceSession>(protected_session), riid, heap);
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

HRESULT D3D12CaptureManager::OverrideIDXGIFactory2_CreateSwapChainForHwnd(
    IDXGIFactory2_Wrapper*                 factory2_wrapper,
    IUnknown*                              pDevice,
    HWND                                   hWnd,
    const DXGI_SWAP_CHAIN_DESC1*           pDesc,
    const DXGI_SWAP_CHAIN_FULLSCREEN_DESC* pFullscreenDesc,
    IDXGIOutput*                           pRestrictToOutput,
    IDXGISwapChain1**                      ppSwapChain)
{
    auto factory2 = factory2_wrapper->GetWrappedObjectAs<IDXGIFactory2>();
    if (factory2 == nullptr)
    {
        return E_INVALIDARG;
    }
    HRESULT result = factory2->CreateSwapChainForHwnd(encode::GetWrappedObject<IUnknown>(pDevice),
                                                      hWnd,
                                                      pDesc,
                                                      pFullscreenDesc,
                                                      encode::GetWrappedObject<IDXGIOutput>(pRestrictToOutput),
                                                      ppSwapChain);
    UpdateSwapChainSize(pDesc->Width, pDesc->Height, *ppSwapChain);
    return result;
}

HRESULT
D3D12CaptureManager::OverrideIDXGIFactory2_CreateSwapChainForCoreWindow(IDXGIFactory2_Wrapper*       factory2_wrapper,
                                                                        IUnknown*                    pDevice,
                                                                        IUnknown*                    pWindow,
                                                                        const DXGI_SWAP_CHAIN_DESC1* pDesc,
                                                                        IDXGIOutput*                 pRestrictToOutput,
                                                                        IDXGISwapChain1**            ppSwapChain)
{
    auto factory2 = factory2_wrapper->GetWrappedObjectAs<IDXGIFactory2>();
    if (factory2 == nullptr)
    {
        return E_INVALIDARG;
    }
    HRESULT result = factory2->CreateSwapChainForCoreWindow(encode::GetWrappedObject<IUnknown>(pDevice),
                                                            encode::GetWrappedObject<IUnknown>(pWindow),
                                                            pDesc,
                                                            encode::GetWrappedObject<IDXGIOutput>(pRestrictToOutput),
                                                            ppSwapChain);
    UpdateSwapChainSize(pDesc->Width, pDesc->Height, *ppSwapChain);
    return result;
}

HRESULT
D3D12CaptureManager::OverrideIDXGIFactory2_CreateSwapChainForComposition(IDXGIFactory2_Wrapper*       factory2_wrapper,
                                                                         IUnknown*                    pDevice,
                                                                         const DXGI_SWAP_CHAIN_DESC1* pDesc,
                                                                         IDXGIOutput*                 pRestrictToOutput,
                                                                         IDXGISwapChain1**            ppSwapChain)
{
    auto factory2 = factory2_wrapper->GetWrappedObjectAs<IDXGIFactory2>();
    if (factory2 == nullptr)
    {
        return E_INVALIDARG;
    }
    HRESULT result = factory2->CreateSwapChainForComposition(encode::GetWrappedObject<IUnknown>(pDevice),
                                                             pDesc,
                                                             encode::GetWrappedObject<IDXGIOutput>(pRestrictToOutput),
                                                             ppSwapChain);
    UpdateSwapChainSize(pDesc->Width, pDesc->Height, *ppSwapChain);
    return result;
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

bool D3D12CaptureManager::RvAnnotationActive()
{
    return (IsAnnotated() == true) && (resource_value_annotator_ != nullptr);
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

HRESULT D3D12CaptureManager::OverrideID3D12Device_CheckFeatureSupport(ID3D12Device_Wrapper* device_wrapper,
                                                                      D3D12_FEATURE         feature,
                                                                      void*                 feature_support_data,
                                                                      UINT                  feature_support_data_size)
{
    auto device = device_wrapper->GetWrappedObjectAs<ID3D12Device>();

    if (GetDisableDxrSetting() && (feature == D3D12_FEATURE_D3D12_OPTIONS5))
    {
        auto    features         = reinterpret_cast<D3D12_FEATURE_DATA_D3D12_OPTIONS5*>(feature_support_data);
        HRESULT result           = device->CheckFeatureSupport(feature, features, feature_support_data_size);
        features->RaytracingTier = D3D12_RAYTRACING_TIER_NOT_SUPPORTED;
        return result;
    }
    else
    {
        return device->CheckFeatureSupport(feature, feature_support_data, feature_support_data_size);
    }
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

void D3D12CaptureManager::PostProcess_D3D12CreateDevice(
    HRESULT result, IUnknown* pAdapter, D3D_FEATURE_LEVEL MinimumFeatureLevel, REFIID riid, void** ppDevice)
{
    if (result == S_OK)
    {
        if (ppDevice != nullptr)
        {
            InitializeID3D12DeviceInfo(pAdapter, ppDevice);

            auto device = reinterpret_cast<ID3D12Device*>(*ppDevice);

            if (device != nullptr)
            {
                format::DxgiAdapterDesc* active_adapter = graphics::dx12::MarkActiveAdapter(device, adapters_);

                // Write adapter desc to file if it was marked active, and has not already been seen
                auto adapter_id = GetDx12WrappedId<IUnknown>(pAdapter);
                if (active_adapter != nullptr)
                {
                    graphics::dx12::InjectAdapterCaptureId(active_adapter->extra_info, adapter_id);
                    WriteDxgiAdapterInfoCommand(*active_adapter);
                }
                else
                {
                    // we have to write adapter if it is already marked active and as a result active_adapter is null
                    // this is essential for marking active adapter for system with multiple GPUs
                    auto parent_adapter = graphics::dx12::GetAdapterDescByLUID(device->GetAdapterLuid(), adapters_);
                    if (parent_adapter != nullptr)
                    {
                        graphics::dx12::InjectAdapterCaptureId(parent_adapter->extra_info, adapter_id);
                        WriteDxgiAdapterInfoCommand(*parent_adapter);
                    }
                }
            }
        }

        WriteDx12DriverInfo();

        WriteDx12RuntimeInfo();
    }
}

void D3D12CaptureManager::PostProcess_ID3D12Fence_SetEventOnCompletion(ID3D12Fence_Wrapper* wrapper,
                                                                       HRESULT              result,
                                                                       UINT64               value,
                                                                       HANDLE               event)
{
    assert(wrapper != nullptr);

    if (IsCaptureModeTrack() && SUCCEEDED(result))
    {
        state_tracker_->TrackFenceSetEventOnCompletion(wrapper, value, event);
    }
}

void D3D12CaptureManager::PostProcess_ID3D12Fence_Signal(ID3D12Fence_Wrapper* wrapper, HRESULT result, UINT64 value)
{
    assert(wrapper != nullptr);

    if (IsCaptureModeTrack() && SUCCEEDED(result))
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

    if (IsCaptureModeTrack() && SUCCEEDED(result))
    {
        auto fence_wrapper = reinterpret_cast<ID3D12Fence_Wrapper*>(fence);
        state_tracker_->TrackFenceSignal(fence_wrapper, value);
    }
}

void D3D12CaptureManager::PostProcess_ID3D12GraphicsCommandList_ResourceBarrier(ID3D12CommandList_Wrapper* list_wrapper,
                                                                                UINT                       num_barriers,
                                                                                const D3D12_RESOURCE_BARRIER* barriers)
{
    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackResourceBarriers(list_wrapper, num_barriers, barriers);
    }
}

void D3D12CaptureManager::PostProcess_ID3D12GraphicsCommandList_Reset(ID3D12CommandList_Wrapper* list_wrapper,
                                                                      HRESULT                    result,
                                                                      ID3D12CommandAllocator*    pAllocator,
                                                                      ID3D12PipelineState*       pInitialState)
{
    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackCommandList_Reset(list_wrapper, pAllocator, pInitialState);
    }
}

void D3D12CaptureManager::PostProcess_ID3D12GraphicsCommandList4_BuildRaytracingAccelerationStructure(
    ID3D12GraphicsCommandList4_Wrapper*                                list_wrapper,
    const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC*          desc,
    UINT                                                               num_postbuild_info_descs,
    const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC* postbuild_info_descs)
{
    GFXRECON_UNREFERENCED_PARAMETER(num_postbuild_info_descs);
    GFXRECON_UNREFERENCED_PARAMETER(postbuild_info_descs);

    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackBuildRaytracingAccelerationStructure(list_wrapper, desc);
    }
}

void D3D12CaptureManager::PostProcess_ID3D12GraphicsCommandList4_CopyRaytracingAccelerationStructure(
    ID3D12GraphicsCommandList4_Wrapper*               list_wrapper,
    D3D12_GPU_VIRTUAL_ADDRESS                         dest_acceleration_structure_data,
    D3D12_GPU_VIRTUAL_ADDRESS                         source_acceleration_structure_data,
    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE mode)
{
    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackCopyRaytracingAccelerationStructure(
            list_wrapper, dest_acceleration_structure_data, source_acceleration_structure_data, mode);
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
    if (IsCaptureModeTrack())
    {
        auto list_wrapper = reinterpret_cast<ID3D12CommandList_Wrapper*>(*ppCommandList);
        state_tracker_->TrackCommandListCreation(list_wrapper, false, type, pCommandAllocator);
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
    if (IsCaptureModeTrack())
    {
        auto list_wrapper = reinterpret_cast<ID3D12CommandList_Wrapper*>(*ppCommandList);
        state_tracker_->TrackCommandListCreation(list_wrapper, true, type, nullptr);
    }
}

CaptureSettings::TraceSettings D3D12CaptureManager::GetDefaultTraceSettings()
{
    CaptureSettings::TraceSettings d3d12_trace_settings = {};

    // Return different trace setting defaults for D3D12.
    d3d12_trace_settings.page_guard_external_memory = true;

    return d3d12_trace_settings;
}

void D3D12CaptureManager::PostProcess_ID3D12DescriptorHeap_GetGPUDescriptorHandleForHeapStart(
    ID3D12DescriptorHeap_Wrapper* wrapper, D3D12_GPU_DESCRIPTOR_HANDLE result)
{
    if (RvAnnotationActive() == true)
    {
        resource_value_annotator_->AddDescriptorHandleStart(wrapper, result);
    }
}

void D3D12CaptureManager::PostProcess_ID3D12Device_GetDescriptorHandleIncrementSize(
    ID3D12Device_Wrapper* wrapper, UINT result, D3D12_DESCRIPTOR_HEAP_TYPE heap_type)
{
    if (RvAnnotationActive() == true)
    {
        resource_value_annotator_->SetDescriptorHandleIncrementSize(heap_type, result);
    }
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
    if (IsCaptureModeTrack())
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
    if (IsCaptureModeTrack() && (num_descriptors > 0))
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
    if (IsCaptureModeTrack())
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
    // TODO: Implement tracking for CopyTileMappings.
    if (IsCaptureModeTrack())
    {
        GFXRECON_LOG_ERROR("ID3D12CommandQueue::CopyTileMappings support is not implemented for trimmed capture.");
    }
}

void D3D12CaptureManager::PostProcess_ID3D12Device_CreateShaderResourceView(
    ID3D12Device_Wrapper*                  device_wrapper,
    ID3D12Resource*                        pResource,
    const D3D12_SHADER_RESOURCE_VIEW_DESC* pDesc,
    D3D12_CPU_DESCRIPTOR_HANDLE            DestDescriptor)
{
    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackDescriptorResources(DestDescriptor.ptr, pResource);

        if ((pDesc != nullptr) && (pDesc->ViewDimension == D3D12_SRV_DIMENSION_RAYTRACING_ACCELERATION_STRUCTURE))
        {
            state_tracker_->TrackDescriptorGpuVa(DestDescriptor.ptr, pDesc->RaytracingAccelerationStructure.Location);
        }
    }
}

void D3D12CaptureManager::PostProcess_ID3D12Device_CreateUnorderedAccessView(
    ID3D12Device_Wrapper*                   device_wrapper,
    ID3D12Resource*                         pResource,
    ID3D12Resource*                         pCounterResource,
    const D3D12_UNORDERED_ACCESS_VIEW_DESC* pDesc,
    D3D12_CPU_DESCRIPTOR_HANDLE             DestDescriptor)
{
    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackDescriptorResources(DestDescriptor.ptr, pResource, pCounterResource);
    }
}

void D3D12CaptureManager::PostProcess_ID3D12Device_CreateRenderTargetView(ID3D12Device_Wrapper* device_wrapper,
                                                                          ID3D12Resource*       pResource,
                                                                          const D3D12_RENDER_TARGET_VIEW_DESC* pDesc,
                                                                          D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackDescriptorResources(DestDescriptor.ptr, pResource);
    }
}

void D3D12CaptureManager::PostProcess_ID3D12Device_CreateDepthStencilView(ID3D12Device_Wrapper* device_wrapper,
                                                                          ID3D12Resource*       pResource,
                                                                          const D3D12_DEPTH_STENCIL_VIEW_DESC* pDesc,
                                                                          D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackDescriptorResources(DestDescriptor.ptr, pResource);
    }
}

void D3D12CaptureManager::PostProcess_ID3D12Device_CreateConstantBufferView(
    ID3D12Device_Wrapper*                  device_wrapper,
    const D3D12_CONSTANT_BUFFER_VIEW_DESC* pDesc,
    D3D12_CPU_DESCRIPTOR_HANDLE            DestDescriptor)
{
    if (IsCaptureModeTrack())
    {
        D3D12_GPU_VIRTUAL_ADDRESS address = 0;

        if (pDesc != nullptr)
        {
            address = pDesc->BufferLocation;
        }

        state_tracker_->TrackDescriptorGpuVa(DestDescriptor.ptr, address);
    }
}

void D3D12CaptureManager::PostProcess_ID3D12Device8_CreateSamplerFeedbackUnorderedAccessView(
    ID3D12Device_Wrapper*       device_wrapper,
    ID3D12Resource*             pTargetedResource,
    ID3D12Resource*             pFeedbackResource,
    D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackDescriptorResources(DestDescriptor.ptr, pTargetedResource, pFeedbackResource);
    }
}

void D3D12CaptureManager::PostProcess_ID3D12Debug_EnableDebugLayer(ID3D12Debug_Wrapper* debug_wrapper)
{
    if (IsCaptureModeTrack())
    {
        // Track object id since ID3D12Debug could be released very soon.
        track_enable_debug_layer_object_id_ = debug_wrapper->GetCaptureId();
    }
}

void D3D12CaptureManager::PostProcess_ID3D12Debug1_EnableDebugLayer(ID3D12Debug1_Wrapper* debug1_wrapper)
{
    if (IsCaptureModeTrack())
    {
        // Track object id since ID3D12Debug1 could be released very soon.
        track_enable_debug_layer_object_id_ = debug1_wrapper->GetCaptureId();
    }
}

void D3D12CaptureManager::PostProcess_ID3D12DeviceRemovedExtendedDataSettings_SetAutoBreadcrumbsEnablement(
    ID3D12DeviceRemovedExtendedDataSettings_Wrapper* dred_wrapper, D3D12_DRED_ENABLEMENT enablement)
{
    if (IsCaptureModeTrack())
    {
        track_enable_dred_info_.dred_settings1_object_id         = dred_wrapper->GetCaptureId();
        track_enable_dred_info_.set_auto_breadcrumbs_enablement_ = enablement;
    }
}

void D3D12CaptureManager::PostProcess_ID3D12DeviceRemovedExtendedDataSettings1_SetBreadcrumbContextEnablement(
    ID3D12DeviceRemovedExtendedDataSettings1_Wrapper* dred1_wrapper, D3D12_DRED_ENABLEMENT enablement)
{
    if (IsCaptureModeTrack())
    {
        track_enable_dred_info_.dred_settings1_object_id           = dred1_wrapper->GetCaptureId();
        track_enable_dred_info_.set_breadcrumb_context_enablement_ = enablement;
    }
}

void D3D12CaptureManager::PostProcess_ID3D12DeviceRemovedExtendedDataSettings_SetPageFaultEnablement(
    ID3D12DeviceRemovedExtendedDataSettings_Wrapper* dred_wrapper, D3D12_DRED_ENABLEMENT enablement)
{
    if (IsCaptureModeTrack())
    {
        track_enable_dred_info_.dred_settings1_object_id   = dred_wrapper->GetCaptureId();
        track_enable_dred_info_.set_page_fault_enablement_ = enablement;
    }
}

void D3D12CaptureManager::PostProcess_SetPrivateData(
    IUnknown_Wrapper* wrapper, HRESULT result, REFGUID Name, UINT DataSize, const void* pData)
{
    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackPrivateData(wrapper, Name, DataSize, pData);
    }
}

void D3D12CaptureManager::PostProcess_ID3D12Device1_SetResidencyPriority(ID3D12Device1_Wrapper*          device_wrapper,
                                                                         HRESULT                         result,
                                                                         UINT                            NumObjects,
                                                                         ID3D12Pageable* const*          ppObjects,
                                                                         const D3D12_RESIDENCY_PRIORITY* pPriorities)
{
    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackResidencyPriority(device_wrapper, NumObjects, ppObjects, pPriorities);
    }
}

void D3D12CaptureManager::OverrideGetRaytracingAccelerationStructurePrebuildInfo(
    ID3D12Device5_Wrapper*                                      device5_wrapper,
    const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS* pDesc,
    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO*      pInfo)
{
    auto device5 = device5_wrapper->GetWrappedObjectAs<ID3D12Device5>();

    device5->GetRaytracingAccelerationStructurePrebuildInfo(pDesc, pInfo);

    auto padding_percent = GetAccelStructPaddingSetting();
    if (padding_percent > 0)
    {
        double size_scale               = 1.0 + padding_percent / 100.0;
        pInfo->ResultDataMaxSizeInBytes = static_cast<UINT64>(std::ceil(pInfo->ResultDataMaxSizeInBytes * size_scale));
        pInfo->ScratchDataSizeInBytes   = static_cast<UINT64>(std::ceil(pInfo->ScratchDataSizeInBytes * size_scale));
        pInfo->UpdateScratchDataSizeInBytes =
            static_cast<UINT64>(std::ceil(pInfo->UpdateScratchDataSizeInBytes * size_scale));
    }
}

HRESULT D3D12CaptureManager::OverrideID3D12GraphicsCommandList_Reset(ID3D12GraphicsCommandList_Wrapper* wrapper,
                                                                     ID3D12CommandAllocator*            pAllocator,
                                                                     ID3D12PipelineState*               pInitialState)
{
    auto cmd_list = wrapper->GetWrappedObjectAs<ID3D12GraphicsCommandList>();
    auto result   = cmd_list->Reset(encode::GetWrappedObject<ID3D12CommandAllocator>(pAllocator),
                                  encode::GetWrappedObject<ID3D12PipelineState>(pInitialState));

    if (GetTrimBoundary() == CaptureSettings::TrimBoundary::kDrawCalls)
    {
        TrimDrawCalls_ID3D12GraphicsCommandList_Reset(result, wrapper, pAllocator, pInitialState);
    }
    return result;
}

void D3D12CaptureManager::OverrideID3D12GraphicsCommandList_ExecuteBundle(ID3D12GraphicsCommandList_Wrapper* wrapper,
                                                                          ID3D12GraphicsCommandList* pCommandList)
{
    auto cmd_list = wrapper->GetWrappedObjectAs<ID3D12GraphicsCommandList>();
    cmd_list->ExecuteBundle(encode::GetWrappedObject<ID3D12GraphicsCommandList>(pCommandList));

    if (GetTrimBoundary() == CaptureSettings::TrimBoundary::kDrawCalls)
    {
        TrimDrawCalls_ID3D12GraphicsCommandList_ExecuteBundle(wrapper, pCommandList);
    }
}

void D3D12CaptureManager::OverrideID3D12GraphicsCommandList4_BeginRenderPass(
    ID3D12GraphicsCommandList4_Wrapper*         wrapper,
    UINT                                        NumRenderTargets,
    const D3D12_RENDER_PASS_RENDER_TARGET_DESC* pRenderTargets,
    const D3D12_RENDER_PASS_DEPTH_STENCIL_DESC* pDepthStencil,
    D3D12_RENDER_PASS_FLAGS                     Flags)
{
    auto cmd_list4     = wrapper->GetWrappedObjectAs<ID3D12GraphicsCommandList4>();
    auto unwrap_memory = GetHandleUnwrapMemory();
    cmd_list4->BeginRenderPass(NumRenderTargets,
                               UnwrapStructArrayObjects(pRenderTargets, NumRenderTargets, unwrap_memory),
                               UnwrapStructPtrObjects(pDepthStencil, unwrap_memory),
                               Flags);

    if (GetTrimBoundary() == CaptureSettings::TrimBoundary::kDrawCalls)
    {
        TrimDrawCalls_ID3D12GraphicsCommandList4_BeginRenderPass(
            wrapper, NumRenderTargets, pRenderTargets, pDepthStencil, Flags);
    }
}

HRESULT D3D12CaptureManager::OverrideD3D12CreateVersionedRootSignatureDeserializerFromSubobjectInLibrary(
    LPCVOID pSrcData,
    SIZE_T  SrcDataSizeInBytes,
    LPCWSTR RootSignatureSubobjectName,
    REFIID  pRootSignatureDeserializerInterface,
    void**  ppRootSignatureDeserializer)
{
    GFXRECON_LOG_FATAL(
        "Calling unsupported function D3D12CreateVersionedRootSignatureDeserializerFromSubobjectInLibrary");
    return E_NOTIMPL;
}

void D3D12CaptureManager::OverrideID3D12GraphicsCommandList10_SetProgram(ID3D12GraphicsCommandList10_Wrapper* wrapper,
                                                                         const D3D12_SET_PROGRAM_DESC*        pDesc)
{
    GFXRECON_LOG_FATAL("Calling unsupported function ID3D12GraphicsCommandList10::SetProgram");
}

void D3D12CaptureManager::OverrideID3D12GraphicsCommandList10_DispatchGraph(
    ID3D12GraphicsCommandList10_Wrapper* wrapper, const D3D12_DISPATCH_GRAPH_DESC* pDesc)
{
    GFXRECON_LOG_FATAL("Calling unsupported function ID3D12GraphicsCommandList10::DispatchGraph");
}

void D3D12CaptureManager::PostProcess_ID3D12Device5_CreateStateObject(ID3D12Device5_Wrapper*         device5_wrapper,
                                                                      HRESULT                        result,
                                                                      const D3D12_STATE_OBJECT_DESC* desc,
                                                                      REFIID                         riid,
                                                                      void**                         state_object)
{
    if (IsCaptureModeTrack() && SUCCEEDED(result) && (state_object != nullptr) && (*state_object != nullptr))
    {
        state_tracker_->TrackCreateStateObject(device5_wrapper, desc, state_object);
    }
}

void D3D12CaptureManager::PostProcess_ID3D12Device7_AddToStateObject(ID3D12Device7_Wrapper*         device7_wrapper,
                                                                     HRESULT                        result,
                                                                     const D3D12_STATE_OBJECT_DESC* addition,
                                                                     ID3D12StateObject* state_object_to_grow_from,
                                                                     REFIID             riid,
                                                                     void**             new_state_object)
{
    if (IsCaptureModeTrack() && SUCCEEDED(result) && (new_state_object != nullptr) && (*new_state_object != nullptr))
    {
        state_tracker_->TrackAddToStateObject(device7_wrapper, addition, state_object_to_grow_from, new_state_object);
    }
}

void D3D12CaptureManager::PostProcess_ID3D12StateObjectProperties_GetShaderIdentifier(
    ID3D12StateObjectProperties_Wrapper* properties_wrapper, void* result, LPCWSTR export_name)
{
    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackGetShaderIdentifier(
            properties_wrapper, result, export_name, GetThreadData()->parameter_buffer_.get());
    }
    if (result != nullptr && RvAnnotationActive() == true)
    {
        auto shader_id = graphics::PackDx12ShaderIdentifier(static_cast<uint8_t*>(result));
        resource_value_annotator_->AddShaderID(shader_id);
    }
}

void D3D12CaptureManager::WriteDxgiAdapterInfoCommand(const format::DxgiAdapterDesc& adapter_desc)
{
    if ((IsCaptureModeWrite()))
    {
        format::DxgiAdapterInfoCommandHeader adapter_info_header;
        memset(&adapter_info_header, 0, sizeof(adapter_info_header));

        auto thread_data = GetThreadData();
        GFXRECON_ASSERT(thread_data != nullptr);

        adapter_info_header.meta_header.block_header.type = format::BlockType::kMetaDataBlock;
        adapter_info_header.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(adapter_info_header);
        adapter_info_header.meta_header.meta_data_id =
            format::MakeMetaDataId(format::ApiFamilyId::ApiFamily_D3D12, format::MetaDataType::kDxgiAdapterInfoCommand);
        adapter_info_header.thread_id = thread_data->thread_id_;

        util::platform::MemoryCopy(&adapter_info_header.adapter_desc,
                                   sizeof(adapter_info_header.adapter_desc),
                                   &adapter_desc,
                                   sizeof(adapter_desc));

        WriteToFile(&adapter_info_header, sizeof(adapter_info_header));
    }
}

void D3D12CaptureManager::WriteDxgiAdapterInfo()
{
    for (const auto& adapter : adapters_)
    {
        const format::DxgiAdapterDesc& replay_adapter_desc = adapter.second.internal_desc;

        // Write adapter desc to file if it was marked active
        if (adapter.second.active == true)
        {
            WriteDxgiAdapterInfoCommand(replay_adapter_desc);
        }
    }
}

void D3D12CaptureManager::PostProcess_CreateDXGIFactory(HRESULT result, REFIID riid, void** ppFactory)
{
    graphics::dx12::TrackAdapters(result, ppFactory, adapters_);
}

void D3D12CaptureManager::PostProcess_CreateDXGIFactory1(HRESULT result, REFIID riid, void** ppFactory)
{
    graphics::dx12::TrackAdapters(result, ppFactory, adapters_);
}

void D3D12CaptureManager::PostProcess_CreateDXGIFactory2(HRESULT result, UINT Flags, REFIID riid, void** ppFactory)
{
    graphics::dx12::TrackAdapters(result, ppFactory, adapters_);
}

std::shared_ptr<ID3D11ResourceInfo> D3D12CaptureManager::GetResourceInfo(ID3D11Resource_Wrapper* wrapper)
{
    auto info           = std::shared_ptr<ID3D11ResourceInfo>{};
    auto dimension      = D3D11_RESOURCE_DIMENSION{};
    auto wrapped_object = wrapper->GetWrappedObjectAs<ID3D11Resource>();

    wrapped_object->GetType(&dimension);

    switch (dimension)
    {
        case D3D11_RESOURCE_DIMENSION_BUFFER:
            info = static_cast<ID3D11Buffer_Wrapper*>(wrapper)->GetObjectInfo();
            break;
        case D3D11_RESOURCE_DIMENSION_TEXTURE1D:
            info = static_cast<ID3D11Texture1D_Wrapper*>(wrapper)->GetObjectInfo();
            break;
        case D3D11_RESOURCE_DIMENSION_TEXTURE2D:
            info = static_cast<ID3D11Texture2D_Wrapper*>(wrapper)->GetObjectInfo();
            break;
        case D3D11_RESOURCE_DIMENSION_TEXTURE3D:
            info = static_cast<ID3D11Texture3D_Wrapper*>(wrapper)->GetObjectInfo();
            break;
        default:
            GFXRECON_LOG_ERROR("Mapped ID3D11Resource object with capture ID = %" PRIx64
                               " has type of D3D11_RESOURCE_DIMENSION_UNKNOWN ",
                               wrapper->GetCaptureId());
            break;
    }

    return info;
}

void D3D12CaptureManager::FreeMappedResourceMemory(ID3D11Resource_Wrapper* wrapper)
{
    if ((wrapper != nullptr) && (GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kPageGuard))
    {
        auto info = GetResourceInfo(wrapper);
        if (info != nullptr)
        {
            util::PageGuardManager* manager = util::PageGuardManager::Get();
            assert(manager != nullptr);

            for (auto& context_entry : info->mapped_subresources)
            {
                for (auto i = 0u; i < info->num_subresources; ++i)
                {
                    auto& mapped_subresource = context_entry.second[i];

                    if (mapped_subresource.data != nullptr)
                    {
                        manager->RemoveTrackedMemory(reinterpret_cast<uint64_t>(mapped_subresource.data));
                    }

                    if (mapped_subresource.shadow_allocation != util::PageGuardManager::kNullShadowHandle)
                    {
                        manager->FreePersistentShadowMemory(mapped_subresource.shadow_allocation);
                    }
                }
            }
        }
    }
}

void D3D12CaptureManager::InitializeID3D11Texture2DInfo(ID3D11Texture2D_Wrapper*    wrapper,
                                                        const D3D11_TEXTURE2D_DESC* desc)
{
    GFXRECON_ASSERT((wrapper != nullptr) && (desc != nullptr));
    auto info                 = wrapper->GetObjectInfo();
    info->dimension           = D3D11_RESOURCE_DIMENSION_TEXTURE2D;
    info->format              = desc->Format;
    info->width               = desc->Width;
    info->height              = desc->Height;
    info->depth_or_array_size = desc->ArraySize;
    info->mip_levels          = desc->MipLevels;
    info->num_subresources    = graphics::dx12::GetNumSubresources(desc);
}

void D3D12CaptureManager::PostProcess_ID3D11Device_CreateBuffer(ID3D11Device_Wrapper*         wrapper,
                                                                HRESULT                       result,
                                                                const D3D11_BUFFER_DESC*      desc,
                                                                const D3D11_SUBRESOURCE_DATA* initial_data,
                                                                ID3D11Buffer**                buffer)
{
    GFXRECON_UNREFERENCED_PARAMETER(wrapper);
    GFXRECON_UNREFERENCED_PARAMETER(initial_data);
    GFXRECON_ASSERT(desc != nullptr);

    if (SUCCEEDED(result) && (buffer != nullptr) && (*buffer != nullptr))
    {
        auto info              = reinterpret_cast<ID3D11Buffer_Wrapper*>(*buffer)->GetObjectInfo();
        info->dimension        = D3D11_RESOURCE_DIMENSION_BUFFER;
        info->width            = desc->ByteWidth;
        info->num_subresources = 1;
    }
}

void D3D12CaptureManager::PostProcess_ID3D11Device_CreateTexture1D(ID3D11Device_Wrapper*         wrapper,
                                                                   HRESULT                       result,
                                                                   const D3D11_TEXTURE1D_DESC*   desc,
                                                                   const D3D11_SUBRESOURCE_DATA* initial_data,
                                                                   ID3D11Texture1D**             texture1D)
{
    GFXRECON_UNREFERENCED_PARAMETER(wrapper);
    GFXRECON_UNREFERENCED_PARAMETER(initial_data);
    GFXRECON_ASSERT(desc != nullptr);

    if (SUCCEEDED(result) && (texture1D != nullptr) && (*texture1D != nullptr))
    {
        auto info                 = reinterpret_cast<ID3D11Texture1D_Wrapper*>(*texture1D)->GetObjectInfo();
        info->dimension           = D3D11_RESOURCE_DIMENSION_TEXTURE1D;
        info->format              = desc->Format;
        info->width               = desc->Width;
        info->depth_or_array_size = desc->ArraySize;
        info->mip_levels          = desc->MipLevels;
        info->num_subresources    = graphics::dx12::GetNumSubresources(desc);
    }
}

void D3D12CaptureManager::PostProcess_ID3D11Device_CreateTexture2D(ID3D11Device_Wrapper*         wrapper,
                                                                   HRESULT                       result,
                                                                   const D3D11_TEXTURE2D_DESC*   desc,
                                                                   const D3D11_SUBRESOURCE_DATA* initial_data,
                                                                   ID3D11Texture2D**             texture2D)
{
    GFXRECON_UNREFERENCED_PARAMETER(wrapper);
    GFXRECON_UNREFERENCED_PARAMETER(initial_data);
    GFXRECON_ASSERT(desc != nullptr);

    if (SUCCEEDED(result) && (texture2D != nullptr) && (*texture2D != nullptr))
    {
        InitializeID3D11Texture2DInfo(reinterpret_cast<ID3D11Texture2D_Wrapper*>(*texture2D), desc);
    }
}

void D3D12CaptureManager::PostProcess_ID3D11Device3_CreateTexture2D1(ID3D11Device_Wrapper*         wrapper,
                                                                     HRESULT                       result,
                                                                     const D3D11_TEXTURE2D_DESC1*  desc1,
                                                                     const D3D11_SUBRESOURCE_DATA* initial_data,
                                                                     ID3D11Texture2D1**            texture2D)
{
    GFXRECON_UNREFERENCED_PARAMETER(wrapper);
    GFXRECON_UNREFERENCED_PARAMETER(initial_data);
    GFXRECON_ASSERT(desc1 != nullptr);

    if (SUCCEEDED(result) && (texture2D != nullptr) && (*texture2D != nullptr))
    {
        auto info                 = reinterpret_cast<ID3D11Texture2D_Wrapper*>(*texture2D)->GetObjectInfo();
        info->dimension           = D3D11_RESOURCE_DIMENSION_TEXTURE2D;
        info->format              = desc1->Format;
        info->width               = desc1->Width;
        info->height              = desc1->Height;
        info->depth_or_array_size = desc1->ArraySize;
        info->mip_levels          = desc1->MipLevels;
        info->num_subresources    = graphics::dx12::GetNumSubresources(desc1);
    }
}

void D3D12CaptureManager::PostProcess_ID3D11Device_CreateTexture3D(ID3D11Device_Wrapper*         wrapper,
                                                                   HRESULT                       result,
                                                                   const D3D11_TEXTURE3D_DESC*   desc,
                                                                   const D3D11_SUBRESOURCE_DATA* initial_data,
                                                                   ID3D11Texture3D**             texture3D)
{
    GFXRECON_UNREFERENCED_PARAMETER(wrapper);
    GFXRECON_UNREFERENCED_PARAMETER(initial_data);
    GFXRECON_ASSERT(desc != nullptr);

    if (SUCCEEDED(result) && (texture3D != nullptr) && (*texture3D != nullptr))
    {
        auto info                 = reinterpret_cast<ID3D11Texture3D_Wrapper*>(*texture3D)->GetObjectInfo();
        info->dimension           = D3D11_RESOURCE_DIMENSION_TEXTURE3D;
        info->format              = desc->Format;
        info->width               = desc->Width;
        info->height              = desc->Height;
        info->depth_or_array_size = desc->Depth;
        info->mip_levels          = desc->MipLevels;
        info->num_subresources    = graphics::dx12::GetNumSubresources(desc);
    }
}

void D3D12CaptureManager::PostProcess_ID3D11Device3_CreateTexture3D1(ID3D11Device_Wrapper*         wrapper,
                                                                     HRESULT                       result,
                                                                     const D3D11_TEXTURE3D_DESC1*  desc1,
                                                                     const D3D11_SUBRESOURCE_DATA* initial_data,
                                                                     ID3D11Texture3D1**            texture3D)
{
    GFXRECON_UNREFERENCED_PARAMETER(wrapper);
    GFXRECON_UNREFERENCED_PARAMETER(initial_data);
    GFXRECON_ASSERT(desc1 != nullptr);

    if (SUCCEEDED(result) && (texture3D != nullptr) && (*texture3D != nullptr))
    {
        auto info                 = reinterpret_cast<ID3D11Texture3D_Wrapper*>(*texture3D)->GetObjectInfo();
        info->dimension           = D3D11_RESOURCE_DIMENSION_TEXTURE3D;
        info->format              = desc1->Format;
        info->width               = desc1->Width;
        info->height              = desc1->Height;
        info->depth_or_array_size = desc1->Depth;
        info->mip_levels          = desc1->MipLevels;
        info->num_subresources    = graphics::dx12::GetNumSubresources(desc1);
    }
}

void D3D12CaptureManager::Destroy_ID3D11Buffer(ID3D11Buffer_Wrapper* wrapper)
{
    FreeMappedResourceMemory(wrapper);
}

void D3D12CaptureManager::Destroy_ID3D11Texture1D(ID3D11Texture1D_Wrapper* wrapper)
{
    FreeMappedResourceMemory(wrapper);
}

void D3D12CaptureManager::Destroy_ID3D11Texture2D(ID3D11Texture2D_Wrapper* wrapper)
{
    FreeMappedResourceMemory(wrapper);
}

void D3D12CaptureManager::Destroy_ID3D11Texture3D(ID3D11Texture3D_Wrapper* wrapper)
{
    FreeMappedResourceMemory(wrapper);
}

void D3D12CaptureManager::PostProcess_ID3D11DeviceContext_Map(ID3D11DeviceContext_Wrapper* wrapper,
                                                              HRESULT                      result,
                                                              ID3D11Resource*              resource,
                                                              UINT                         subresource,
                                                              D3D11_MAP                    map_type,
                                                              UINT                         map_flags,
                                                              D3D11_MAPPED_SUBRESOURCE*    mapped_subresource_data)
{
    GFXRECON_UNREFERENCED_PARAMETER(wrapper);

    if (SUCCEEDED(result) && (resource != nullptr))
    {
        auto resource_wrapper = reinterpret_cast<ID3D11Resource_Wrapper*>(resource);
        auto info             = GetResourceInfo(resource_wrapper);
        if (info != nullptr)
        {
            assert((subresource < info->num_subresources));

            std::lock_guard<std::mutex> lock(GetMappedMemoryLock());

            // Get or initialize the per-context mapped memory info entry.
            auto entry = info->mapped_subresources.find(wrapper->GetCaptureId());
            if (entry == info->mapped_subresources.end())
            {
                if (info->subresource_sizes == nullptr)
                {
                    info->subresource_sizes = std::make_unique<uint64_t[]>(info->num_subresources);
                }

                auto& pair = info->mapped_subresources.emplace(
                    wrapper->GetCaptureId(),
                    std::make_unique<gfxrecon::encode::MappedSubresource[]>(info->num_subresources));
                entry = pair.first;
            }

            auto& mapped_subresource = entry->second[subresource];

            if ((mapped_subresource_data != nullptr) && (mapped_subresource_data->pData != nullptr) &&
                (map_type != D3D11_MAP_READ))
            {
                mapped_subresource.data = mapped_subresource_data->pData;

                if (++mapped_subresource.map_count == 1)
                {
                    // Calculate and store the subresource size on first use. This size is used with kPageGuard when
                    // adding an entry to PageGuardManager on Map or with kUnassisted when writing memory to the file on
                    // Unmap.
                    auto& subresource_size = info->subresource_sizes[subresource];
                    if (subresource_size == 0)
                    {
                        subresource_size = graphics::dx12::GetSubresourceSize(info->dimension,
                                                                              info->format,
                                                                              info->width,
                                                                              info->height,
                                                                              info->depth_or_array_size,
                                                                              info->mip_levels,
                                                                              mapped_subresource_data->RowPitch,
                                                                              mapped_subresource_data->DepthPitch,
                                                                              subresource);
                    }

                    if (GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kPageGuard)
                    {
                        util::PageGuardManager* manager = util::PageGuardManager::Get();
                        assert(manager != nullptr);

                        GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, subresource_size);
                        auto size = static_cast<size_t>(subresource_size);

                        if (((map_type == D3D11_MAP_WRITE_DISCARD) || (map_type == D3D11_MAP_WRITE_NO_OVERWRITE)) &&
                            (mapped_subresource.shadow_allocation == util::PageGuardManager::kNullShadowHandle))
                        {
                            // When mapped for discard, the previous content of the memory does not need to be preserved
                            // and a persistent allocation can be created to skip allocating and copying each time the
                            // discarded memory is mapped.
                            mapped_subresource.shadow_allocation = manager->AllocatePersistentShadowMemory(size);
                        }

                        // Return the pointer provided by the pageguard manager, which may be a pointer to shadow
                        // memory, not the mapped memory.
                        mapped_subresource_data->pData =
                            manager->AddTrackedMemory(reinterpret_cast<uint64_t>(mapped_subresource.data),
                                                      mapped_subresource.data,
                                                      0,
                                                      size,
                                                      mapped_subresource.shadow_allocation,
                                                      true,
                                                      false);
                    }
                }
                else
                {
                    // The application has mapped the same ID3D11Resource object more than once and the pageguard
                    // manager is already tracking it, so we will return the pointer obtained from the pageguard manager
                    // on the first map call. Note that the D3D11 runtime will report an error for this case, while also
                    // returning S_OK, and the resource will be fully unmapped by the first Unmap() call regardless of
                    // the number of times it has been mapped.
                    if (GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kPageGuard)
                    {
                        // Return the shadow memory that was allocated for the previous map operation.
                        util::PageGuardManager* manager = util::PageGuardManager::Get();
                        assert(manager != nullptr);

                        auto found = manager->GetTrackedMemory(reinterpret_cast<uint64_t>(mapped_subresource.data),
                                                               &mapped_subresource_data->pData);
                        if (!found)
                        {
                            GFXRECON_LOG_ERROR("Failed to find tracked memory object for a previously mapped resource.")
                        }
                    }
                }
            }
        }
    }
}

void D3D12CaptureManager::PreProcess_ID3D11DeviceContext_Unmap(ID3D11DeviceContext_Wrapper* wrapper,
                                                               ID3D11Resource*              resource,
                                                               UINT                         subresource)
{
    GFXRECON_UNREFERENCED_PARAMETER(wrapper);

    if (resource != nullptr)
    {
        auto resource_wrapper = reinterpret_cast<ID3D11Resource_Wrapper*>(resource);

        auto info = GetResourceInfo(resource_wrapper);
        if (info != nullptr)
        {
            assert((subresource < info->num_subresources));

            std::lock_guard<std::mutex> lock(GetMappedMemoryLock());

            auto entry = info->mapped_subresources.find(wrapper->GetCaptureId());
            if (entry != info->mapped_subresources.end())
            {
                auto& mapped_subresource = entry->second[subresource];

                // Note that memory tracking ignores the case where a resource was mapped for use with
                // WriteToSubresoruce, where the Map D3D11_MAPPED_SUBRESOURCE parameter was NULL.
                if (mapped_subresource.data != nullptr)
                {
                    if (mapped_subresource.map_count > 0)
                    {
                        // The D3D11 runtime will report an error when a subresource is mapped more than once, but may
                        // also return S_OK. The resource will be fully unmapped by the first Unmap() call regardless of
                        // the number of times it has been mapped.
                        mapped_subresource.map_count = 0;

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

                            WriteFillMemoryCmd(reinterpret_cast<uint64_t>(mapped_subresource.data),
                                               offset,
                                               size,
                                               mapped_subresource.data);
                        }

                        mapped_subresource.data = nullptr;
                    }
                    else
                    {
                        GFXRECON_LOG_WARNING("Attempting to unmap ID3D11Resource object with capture ID = %" PRIx64
                                             " that is not currently mapped",
                                             resource_wrapper->GetCaptureId());
                    }
                }
            }
            else
            {
                GFXRECON_LOG_WARNING(
                    "Attempting to unmap ID3D11Resource object with capture ID = %" PRIx64
                    " that has not been mapped by ID3D11DeviceContext object with capture ID = %" PRIx64,
                    resource_wrapper->GetCaptureId(),
                    wrapper->GetCaptureId());
            }
        }
    }
}

void D3D12CaptureManager::AddViewResourceRef(ID3D11ViewInfo* info, ID3D11Resource* resource)
{
    GFXRECON_ASSERT((info != nullptr) && (resource != nullptr));
    auto resource_wrapper = reinterpret_cast<ID3D11Resource_Wrapper*>(resource);
    resource_wrapper->AddRefInternal();
    info->resource = resource_wrapper;
}

void D3D12CaptureManager::ReleaseViewResourceRef(ID3D11ViewInfo* info)
{
    GFXRECON_ASSERT((info != nullptr) && (info->resource != nullptr));
    info->resource->ReleaseRefInternal();
}

void D3D12CaptureManager::PostProcess_ID3D11Device_CreateShaderResourceView(ID3D11Device_Wrapper* wrapper,
                                                                            HRESULT               result,
                                                                            ID3D11Resource*       resource,
                                                                            const D3D11_SHADER_RESOURCE_VIEW_DESC* desc,
                                                                            ID3D11ShaderResourceView** srview)
{
    GFXRECON_UNREFERENCED_PARAMETER(wrapper);
    GFXRECON_UNREFERENCED_PARAMETER(desc);

    if (SUCCEEDED(result) && (srview != nullptr) && (*srview != nullptr))
    {
        auto info = reinterpret_cast<ID3D11ShaderResourceView_Wrapper*>(*srview)->GetObjectInfo();
        AddViewResourceRef(info.get(), resource);
    }
}

void D3D12CaptureManager::PostProcess_ID3D11Device_CreateShaderResourceView1(
    ID3D11Device3_Wrapper*                  wrapper,
    HRESULT                                 result,
    ID3D11Resource*                         resource,
    const D3D11_SHADER_RESOURCE_VIEW_DESC1* desc1,
    ID3D11ShaderResourceView1**             srview1)
{
    GFXRECON_UNREFERENCED_PARAMETER(wrapper);
    GFXRECON_UNREFERENCED_PARAMETER(desc1);

    if (SUCCEEDED(result) && (srview1 != nullptr) && (*srview1 != nullptr))
    {
        auto info = reinterpret_cast<ID3D11ShaderResourceView1_Wrapper*>(*srview1)->GetObjectInfo();
        AddViewResourceRef(info.get(), resource);
    }
}

void D3D12CaptureManager::PostProcess_ID3D11Device_CreateUnorderedAccessView(
    ID3D11Device_Wrapper*                   wrapper,
    HRESULT                                 result,
    ID3D11Resource*                         resource,
    const D3D11_UNORDERED_ACCESS_VIEW_DESC* desc,
    ID3D11UnorderedAccessView**             uaview)
{
    GFXRECON_UNREFERENCED_PARAMETER(wrapper);
    GFXRECON_UNREFERENCED_PARAMETER(desc);

    if (SUCCEEDED(result) && (uaview != nullptr) && (*uaview != nullptr))
    {
        auto info = reinterpret_cast<ID3D11UnorderedAccessView_Wrapper*>(*uaview)->GetObjectInfo();
        AddViewResourceRef(info.get(), resource);
    }
}

void D3D12CaptureManager::PostProcess_ID3D11Device_CreateUnorderedAccessView1(
    ID3D11Device3_Wrapper*                   wrapper,
    HRESULT                                  result,
    ID3D11Resource*                          resource,
    const D3D11_UNORDERED_ACCESS_VIEW_DESC1* desc1,
    ID3D11UnorderedAccessView1**             uaview1)
{
    GFXRECON_UNREFERENCED_PARAMETER(wrapper);
    GFXRECON_UNREFERENCED_PARAMETER(desc1);

    if (SUCCEEDED(result) && (uaview1 != nullptr) && (*uaview1 != nullptr))
    {
        auto info = reinterpret_cast<ID3D11UnorderedAccessView1_Wrapper*>(*uaview1)->GetObjectInfo();
        AddViewResourceRef(info.get(), resource);
    }
}

void D3D12CaptureManager::PostProcess_ID3D11Device_CreateRenderTargetView(ID3D11Device_Wrapper*                wrapper,
                                                                          HRESULT                              result,
                                                                          ID3D11Resource*                      resource,
                                                                          const D3D11_RENDER_TARGET_VIEW_DESC* desc,
                                                                          ID3D11RenderTargetView**             rtview)
{
    GFXRECON_UNREFERENCED_PARAMETER(wrapper);
    GFXRECON_UNREFERENCED_PARAMETER(desc);

    if (SUCCEEDED(result) && (rtview != nullptr) && (*rtview != nullptr))
    {
        auto info = reinterpret_cast<ID3D11RenderTargetView_Wrapper*>(*rtview)->GetObjectInfo();
        AddViewResourceRef(info.get(), resource);
    }
}

void D3D12CaptureManager::PostProcess_ID3D11Device_CreateRenderTargetView1(ID3D11Device3_Wrapper* wrapper,
                                                                           HRESULT                result,
                                                                           ID3D11Resource*        resource,
                                                                           const D3D11_RENDER_TARGET_VIEW_DESC1* desc1,
                                                                           ID3D11RenderTargetView1** rtview1)
{
    GFXRECON_UNREFERENCED_PARAMETER(wrapper);
    GFXRECON_UNREFERENCED_PARAMETER(desc1);

    if (SUCCEEDED(result) && (rtview1 != nullptr) && (*rtview1 != nullptr))
    {
        auto info = reinterpret_cast<ID3D11RenderTargetView1_Wrapper*>(*rtview1)->GetObjectInfo();
        AddViewResourceRef(info.get(), resource);
    }
}

void D3D12CaptureManager::PostProcess_ID3D11Device_CreateDepthStencilView(ID3D11Device_Wrapper*                wrapper,
                                                                          HRESULT                              result,
                                                                          ID3D11Resource*                      resource,
                                                                          const D3D11_DEPTH_STENCIL_VIEW_DESC* desc,
                                                                          ID3D11DepthStencilView** depth_stencil_view)
{
    GFXRECON_UNREFERENCED_PARAMETER(wrapper);
    GFXRECON_UNREFERENCED_PARAMETER(desc);

    if (SUCCEEDED(result) && (depth_stencil_view != nullptr) && (*depth_stencil_view != nullptr))
    {
        auto info = reinterpret_cast<ID3D11DepthStencilView_Wrapper*>(*depth_stencil_view)->GetObjectInfo();
        AddViewResourceRef(info.get(), resource);
    }
}

void D3D12CaptureManager::Destroy_ID3D11ShaderResourceView(ID3D11ShaderResourceView_Wrapper* wrapper)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    ReleaseViewResourceRef(info.get());
}

void D3D12CaptureManager::Destroy_ID3D11RenderTargetView(ID3D11RenderTargetView_Wrapper* wrapper)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    ReleaseViewResourceRef(info.get());
}

void D3D12CaptureManager::Destroy_ID3D11UnorderedAccessView(ID3D11UnorderedAccessView_Wrapper* wrapper)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    ReleaseViewResourceRef(info.get());
}

void D3D12CaptureManager::Destroy_ID3D11DepthStencilView(ID3D11DepthStencilView_Wrapper* wrapper)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    ReleaseViewResourceRef(info.get());
}

void D3D12CaptureManager::WriteDx12DriverInfo()
{
    if (IsCaptureModeWrite())
    {
        std::string       driverinfo = "";
        std::vector<LUID> adapter_luids;

        gfxrecon::graphics::dx12::GetActiveAdapterLuids(adapters_, adapter_luids);

        if (util::driverinfo::GetDriverInfo(driverinfo, format::ApiFamilyId::ApiFamily_D3D12, adapter_luids) == true)
        {
            WriteDriverInfoCommand(driverinfo);
        }
    }
}

void D3D12CaptureManager::WriteDriverInfoCommand(const std::string& info)
{
    if ((IsCaptureModeWrite()))
    {
        format::DriverInfoBlock driver_info_header = {};

        strncpy_s(driver_info_header.driver_record,
                  util::filepath::kMaxDriverInfoSize,
                  info.c_str(),
                  util::filepath::kMaxDriverInfoSize);

        driver_info_header.meta_header.block_header.type = format::BlockType::kMetaDataBlock;
        driver_info_header.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(driver_info_header);
        driver_info_header.meta_header.meta_data_id =
            format::MakeMetaDataId(format::ApiFamilyId::ApiFamily_D3D12, format::MetaDataType::kDriverInfoCommand);
        driver_info_header.thread_id = GetThreadData()->thread_id_;

        WriteToFile(&driver_info_header, sizeof(driver_info_header));
    }
}

void D3D12CaptureManager::WriteDx12RuntimeInfo()
{
    if (IsCaptureModeWrite())
    {
        static bool wrote_dx12_runtime_info = false;

        if (wrote_dx12_runtime_info == false)
        {
            std::string runtime_path = util::filepath::FindModulePath(kDx12RuntimeName, false);

            if (runtime_path.empty() == false)
            {
                char working_dir[MAX_PATH] = {};
                if (GetCurrentDirectory(MAX_PATH, working_dir))
                {
                    // Assume it is the in-box runtime
                    std::string runtime_desc = "System";

                    // If D3D12Core is found within app folder, it should be from Agility SDK
                    if (runtime_path.find(working_dir) != std::string::npos)
                    {
                        runtime_desc = "Agility SDK";
                    }

                    util::filepath::FileInfo file_info = {};
                    GetFileInfo(file_info, runtime_path);

                    format::Dx12RuntimeInfo runtime_info = {};

                    util::platform::MemoryCopy(runtime_info.version,
                                               sizeof(runtime_info.version),
                                               file_info.AppVersion,
                                               sizeof(runtime_info.version));

                    strncpy_s(runtime_info.src,
                              util::filepath::kMaxFilePropertySize,
                              runtime_desc.c_str(),
                              util::filepath::kMaxFilePropertySize);

                    WriteDx2RuntimeInfoCommand(runtime_info);

                    wrote_dx12_runtime_info = true;
                }
            }
        }
    }
}

void D3D12CaptureManager::WriteDx2RuntimeInfoCommand(const format::Dx12RuntimeInfo& runtime_info)
{
    if ((IsCaptureModeWrite()))
    {
        format::Dx12RuntimeInfoCommandHeader dx12_runtime_info_header;
        memset(&dx12_runtime_info_header, 0, sizeof(dx12_runtime_info_header));

        auto thread_data = GetThreadData();
        GFXRECON_ASSERT(thread_data != nullptr);

        dx12_runtime_info_header.meta_header.block_header.type = format::BlockType::kMetaDataBlock;
        dx12_runtime_info_header.meta_header.block_header.size =
            format::GetMetaDataBlockBaseSize(dx12_runtime_info_header);
        dx12_runtime_info_header.meta_header.meta_data_id =
            format::MakeMetaDataId(format::ApiFamilyId::ApiFamily_D3D12, format::MetaDataType::kDx12RuntimeInfoCommand);
        dx12_runtime_info_header.thread_id = thread_data->thread_id_;

        util::platform::MemoryCopy(&dx12_runtime_info_header.runtime_info,
                                   sizeof(dx12_runtime_info_header.runtime_info),
                                   &runtime_info,
                                   sizeof(runtime_info));

        WriteToFile(&dx12_runtime_info_header, sizeof(dx12_runtime_info_header));
    }
}

void D3D12CaptureManager::UpdateSwapChainSize(uint32_t width, uint32_t height, IDXGISwapChain1* swapchain)
{
    if (width == 0 || height == 0)
    {
        DXGI_SWAP_CHAIN_DESC1 swapchain_desc;
        if (swapchain != NULL)
        {
            swapchain->GetDesc1(&swapchain_desc);
            WriteResizeWindowCmd(0, swapchain_desc.Width, swapchain_desc.Height);
        }
    }
}

void D3D12CaptureManager::TrimDrawCalls_D3D12SerializeVersionedRootSignature(
    const D3D12_VERSIONED_ROOT_SIGNATURE_DESC* pRootSignature, ID3DBlob** ppBlob, ID3DBlob** ppErrorBlob)
{
    uint32_t                     param_size = 0;
    const D3D12_ROOT_PARAMETER1* params     = nullptr;

    if (pRootSignature->Version == D3D_ROOT_SIGNATURE_VERSION_1_1)
    {
        param_size = pRootSignature->Desc_1_1.NumParameters;
        params     = pRootSignature->Desc_1_1.pParameters;
    }
    else if (pRootSignature->Version == D3D_ROOT_SIGNATURE_VERSION_1_2)
    {
        param_size = pRootSignature->Desc_1_2.NumParameters;
        params     = pRootSignature->Desc_1_2.pParameters;
    }

    if (params)
    {
        for (uint32_t i = 0; i < param_size; ++i)
        {
            switch (params[i].ParameterType)
            {
                case D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE:
                {
                    auto range_size = params[i].DescriptorTable.NumDescriptorRanges;
                    for (uint32_t j = 0; j < range_size; ++j)
                    {
                        auto& range = params[i].DescriptorTable.pDescriptorRanges[j];

                        // DATA_STATIC could cause error for splitted commandlists.
                        // Error log is like: Resource is bound as DATA_STATIC on Command List. Its state was changed by
                        // a previous command list execution which indicates a change to its data (or possibly resource
                        // metadata), but it is invalid to change it until this command list has finished executing for
                        // the last time.
                        if (range.Flags & D3D12_DESCRIPTOR_RANGE_FLAG_DATA_STATIC)
                        {
                            GFXRECON_LOG_WARNING(
                                "D3D12_DESCRIPTOR_RANGE_FLAG_DATA_STATIC could cause error for trim draw calls. "
                                "Recommend using D3D12_DESCRIPTOR_RANGE_FLAG_DATA_STATIC_WHILE_SET_AT_EXECUTE.");
                            break;
                        }
                    }
                    break;
                }
                default:
                    break;
            }
        }
    }
}

void D3D12CaptureManager::TrimDrawCalls_ID3D12GraphicsCommandList_Reset(HRESULT replay_result,
                                                                        ID3D12GraphicsCommandList_Wrapper* wrapper,
                                                                        ID3D12CommandAllocator*            pAllocator,
                                                                        ID3D12PipelineState* pInitialState)
{
    DecrementCallScope();

    auto trim_draw_calls_command_sets =
        GetCommandListsForTrimDrawCalls(wrapper, format::ApiCall_ID3D12GraphicsCommandList_Reset);
    for (auto& command_set : trim_draw_calls_command_sets)
    {
        auto list_wrapper = reinterpret_cast<ID3D12GraphicsCommandList_Wrapper*>(command_set.list.GetInterfacePtr());
        GFXRECON_ASSERT(list_wrapper);
        auto result_trim_draw_calls = list_wrapper->Reset(command_set.allocator, pInitialState);

        if (replay_result != result_trim_draw_calls)
        {
            GFXRECON_LOG_WARNING(
                "Splitting commandlists of ID3D12GraphicsCommandList::Reset get different results: %s and %s",
                decode::enumutil::GetResultValueString(replay_result).c_str(),
                decode::enumutil::GetResultValueString(result_trim_draw_calls).c_str());
        }
    }
    IncrementCallScope();
}

void D3D12CaptureManager::TrimDrawCalls_ID3D12GraphicsCommandList_ExecuteBundle(
    ID3D12GraphicsCommandList_Wrapper* wrapper, ID3D12GraphicsCommandList* pCommandList)
{
    DecrementCallScope();

    auto trim_draw_calls_command_sets =
        GetCommandListsForTrimDrawCalls(wrapper, format::ApiCall_ID3D12GraphicsCommandList_ExecuteBundle);

    if (trim_draw_calls_command_sets.size() == 3)
    {
        // Here is the target draw call for trim draw calls.
        auto bunlde_wrapper = reinterpret_cast<ID3D12GraphicsCommandList_Wrapper*>(pCommandList);
        GFXRECON_ASSERT(bunlde_wrapper);

        auto bundle_info = bunlde_wrapper->GetObjectInfo();
        GFXRECON_ASSERT(bundle_info);

        auto cmd_info = wrapper->GetObjectInfo();
        GFXRECON_ASSERT(cmd_info);
        cmd_info->target_bundle_commandlist_info = bundle_info;

        uint32_t i = 0;
        for (auto& command_set : trim_draw_calls_command_sets)
        {
            GFXRECON_ASSERT(bundle_info->split_command_sets[i].list);

            auto list_wrapper =
                reinterpret_cast<ID3D12GraphicsCommandList_Wrapper*>(command_set.list.GetInterfacePtr());
            GFXRECON_ASSERT(list_wrapper);

            list_wrapper->ExecuteBundle(bundle_info->split_command_sets[i].list);
            ++i;
        }
    }
    else if (trim_draw_calls_command_sets.size() == 1)
    {
        auto list_wrapper = reinterpret_cast<ID3D12GraphicsCommandList_Wrapper*>(
            trim_draw_calls_command_sets[0].list.GetInterfacePtr());
        GFXRECON_ASSERT(list_wrapper);
        list_wrapper->ExecuteBundle(pCommandList);
    }
    IncrementCallScope();
}

void D3D12CaptureManager::TrimDrawCalls_ID3D12GraphicsCommandList4_BeginRenderPass(
    ID3D12GraphicsCommandList4_Wrapper*         wrapper,
    UINT                                        NumRenderTargets,
    const D3D12_RENDER_PASS_RENDER_TARGET_DESC* pRenderTargets,
    const D3D12_RENDER_PASS_DEPTH_STENCIL_DESC* pDepthStencil,
    D3D12_RENDER_PASS_FLAGS                     Flags)
{
    DecrementCallScope();

    auto trim_draw_calls_command_sets =
        GetCommandListsForTrimDrawCalls(wrapper, format::ApiCall_ID3D12GraphicsCommandList4_BeginRenderPass);
    if (trim_draw_calls_command_sets.size() == 3)
    {
        // before
        std::vector<D3D12_RENDER_PASS_RENDER_TARGET_DESC> before_rt_descs;
        for (uint32_t i = 0; i < NumRenderTargets; ++i)
        {
            D3D12_RENDER_PASS_RENDER_TARGET_DESC desc = pRenderTargets[i];
            desc.EndingAccess.Type                    = D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_PRESERVE;
            before_rt_descs.emplace_back(std::move(desc));
        }

        D3D12_RENDER_PASS_DEPTH_STENCIL_DESC  before_ds_desc   = {};
        D3D12_RENDER_PASS_DEPTH_STENCIL_DESC* p_before_ds_desc = nullptr;
        if (pDepthStencil)
        {
            before_ds_desc                          = *pDepthStencil;
            before_ds_desc.DepthEndingAccess.Type   = D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_PRESERVE;
            before_ds_desc.StencilEndingAccess.Type = D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_PRESERVE;
            p_before_ds_desc                        = &before_ds_desc;
        }

        auto* before_wrappr = reinterpret_cast<ID3D12GraphicsCommandList_Wrapper*>(
            trim_draw_calls_command_sets[graphics::dx12::kBeforeDrawCallArrayIndex].list.GetInterfacePtr());
        auto* before4_wrappr = static_cast<ID3D12GraphicsCommandList4_Wrapper*>(before_wrappr);
        GFXRECON_ASSERT(before4_wrappr);

        before4_wrappr->BeginRenderPass(NumRenderTargets, before_rt_descs.data(), p_before_ds_desc, Flags);

        // target
        std::vector<D3D12_RENDER_PASS_RENDER_TARGET_DESC> target_rt_descs;
        for (uint32_t i = 0; i < NumRenderTargets; ++i)
        {
            D3D12_RENDER_PASS_RENDER_TARGET_DESC desc = pRenderTargets[i];
            desc.BeginningAccess.Type                 = D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_PRESERVE;
            desc.EndingAccess.Type                    = D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_PRESERVE;
            target_rt_descs.emplace_back(std::move(desc));
        }

        D3D12_RENDER_PASS_DEPTH_STENCIL_DESC  target_ds_desc   = {};
        D3D12_RENDER_PASS_DEPTH_STENCIL_DESC* p_target_ds_desc = nullptr;
        if (pDepthStencil)
        {
            target_ds_desc                             = *pDepthStencil;
            target_ds_desc.DepthBeginningAccess.Type   = D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_PRESERVE;
            target_ds_desc.StencilBeginningAccess.Type = D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_PRESERVE;
            target_ds_desc.DepthEndingAccess.Type      = D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_PRESERVE;
            target_ds_desc.StencilEndingAccess.Type    = D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_PRESERVE;
            p_target_ds_desc                           = &target_ds_desc;
        }

        auto* target_wrappr = reinterpret_cast<ID3D12GraphicsCommandList_Wrapper*>(
            trim_draw_calls_command_sets[graphics::dx12::kDrawCallArrayIndex].list.GetInterfacePtr());
        auto* target4_wrapper = static_cast<ID3D12GraphicsCommandList4_Wrapper*>(target_wrappr);
        GFXRECON_ASSERT(target4_wrapper);

        target4_wrapper->BeginRenderPass(NumRenderTargets, target_rt_descs.data(), p_target_ds_desc, Flags);

        // after
        std::vector<D3D12_RENDER_PASS_RENDER_TARGET_DESC> after_rt_descs;
        for (uint32_t i = 0; i < NumRenderTargets; ++i)
        {
            D3D12_RENDER_PASS_RENDER_TARGET_DESC desc = pRenderTargets[i];
            desc.BeginningAccess.Type                 = D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_PRESERVE;
            after_rt_descs.emplace_back(std::move(desc));
        }

        D3D12_RENDER_PASS_DEPTH_STENCIL_DESC  after_ds_desc   = {};
        D3D12_RENDER_PASS_DEPTH_STENCIL_DESC* p_after_ds_desc = nullptr;
        if (pDepthStencil)
        {
            after_ds_desc                             = *pDepthStencil;
            after_ds_desc.DepthBeginningAccess.Type   = D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_PRESERVE;
            after_ds_desc.StencilBeginningAccess.Type = D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_PRESERVE;
            p_after_ds_desc                           = &after_ds_desc;
        }

        auto* after_wrapper = reinterpret_cast<ID3D12GraphicsCommandList_Wrapper*>(
            trim_draw_calls_command_sets[graphics::dx12::kAfterDrawCallArrayIndex].list.GetInterfacePtr());
        auto* after4_wrapper = static_cast<ID3D12GraphicsCommandList4_Wrapper*>(after_wrapper);
        GFXRECON_ASSERT(after4_wrapper);

        after4_wrapper->BeginRenderPass(NumRenderTargets, after_rt_descs.data(), p_after_ds_desc, Flags);
    }
    else if (trim_draw_calls_command_sets.size() == 1)
    {
        auto* list_wrapper = reinterpret_cast<ID3D12GraphicsCommandList_Wrapper*>(
            trim_draw_calls_command_sets[0].list.GetInterfacePtr());
        auto* list4_wrapper = static_cast<ID3D12GraphicsCommandList4_Wrapper*>(list_wrapper);
        GFXRECON_ASSERT(list4_wrapper);

        list4_wrapper->BeginRenderPass(NumRenderTargets, pRenderTargets, pDepthStencil, Flags);
    }
    IncrementCallScope();
}

bool D3D12CaptureManager::TrimDrawCalls_ID3D12CommandQueue_ExecuteCommandLists(
    std::shared_lock<CommonCaptureManager::ApiCallMutexT>& current_lock,
    ID3D12CommandQueue_Wrapper*                            wrapper,
    UINT                                                   num_lists,
    ID3D12CommandList* const*                              lists)
{
    auto trim_draw_calls = GetTrimDrawCalls();

    if (common_manager_->GetQueueSubmitCount() == trim_draw_calls.submit_index)
    {
        if (num_lists <= trim_draw_calls.command_index)
        {
            GFXRECON_LOG_FATAL("CAPTURE_DRAW_CALLS can't find the commandlist index(%d). It might be out of range(%d).",
                               trim_draw_calls.command_index,
                               num_lists);
            GFXRECON_ASSERT(num_lists > trim_draw_calls.command_index);
        }

        auto target_cmdlist = lists[trim_draw_calls.command_index];
        auto target_wrapper = reinterpret_cast<ID3D12CommandList_Wrapper*>(target_cmdlist);
        GFXRECON_ASSERT(target_wrapper);

        auto target_info = target_wrapper->GetObjectInfo();
        GFXRECON_ASSERT(target_info);

        if (target_info->find_target_draw_call_count == 0)
        {
            GFXRECON_LOG_FATAL("CAPTURE_DRAW_CALLS can't find the draw call indices(%d-%d). It might be out of range.",
                               trim_draw_calls.draw_call_indices.first,
                               trim_draw_calls.draw_call_indices.last);
            GFXRECON_ASSERT(target_info->find_target_draw_call_count != 0);
        }

        if (target_info->find_target_draw_call_count !=
            (trim_draw_calls.draw_call_indices.last - trim_draw_calls.draw_call_indices.first + 1))
        {
            GFXRECON_LOG_WARNING("CAPTURE_DRAW_CALLS didn't find the enough draw call count(%d). The indices(%d-%d) "
                                 "might be out of range.",
                                 target_info->find_target_draw_call_count,
                                 trim_draw_calls.draw_call_indices.first,
                                 trim_draw_calls.draw_call_indices.last);
        }

        if (target_info->target_bundle_commandlist_info)
        {
            if (target_info->target_bundle_commandlist_info->find_target_draw_call_count == 0)
            {

                GFXRECON_LOG_FATAL(
                    "CAPTURE_DRAW_CALLS can't find the bundle draw call indices(%d-%d). It might be out of range.",
                    trim_draw_calls.bundle_draw_call_indices.first,
                    trim_draw_calls.bundle_draw_call_indices.last);
                GFXRECON_ASSERT(target_info->target_bundle_commandlist_info->find_target_draw_call_count != 0);
            }

            if (target_info->target_bundle_commandlist_info->find_target_draw_call_count !=
                (trim_draw_calls.bundle_draw_call_indices.last - trim_draw_calls.bundle_draw_call_indices.first + 1))
            {
                GFXRECON_LOG_WARNING("CAPTURE_DRAW_CALLS didn't find the enough bundle draw call count(%d). The "
                                     "indices(%d-%d) might be out of range.",
                                     target_info->target_bundle_commandlist_info->find_target_draw_call_count,
                                     trim_draw_calls.bundle_draw_call_indices.first,
                                     trim_draw_calls.bundle_draw_call_indices.last);
            }
        }

        std::vector<ID3D12CommandList*> cmdlists;

        // before of lists and before of splitted
        for (uint32_t i = 0; i < trim_draw_calls.command_index; ++i)
        {
            cmdlists.emplace_back(lists[i]);
        }

        auto before_draw_call_cmd = target_info->split_command_sets[graphics::dx12::kBeforeDrawCallArrayIndex].list;
        GFXRECON_ASSERT(before_draw_call_cmd);
        cmdlists.emplace_back(before_draw_call_cmd);

        // Here has to use the wrapped queue since this ExecuteCommandLists needs to be tracked.
        DecrementCallScope();
        wrapper->ExecuteCommandLists(cmdlists.size(), cmdlists.data());
        IncrementCallScope();

        auto queue = reinterpret_cast<ID3D12CommandQueue*>(wrapper->GetWrappedObject());
        graphics::dx12::WaitForQueue(queue);
        cmdlists.clear();

        // target of splitted
        common_manager_->ActivateTrimmingDrawCalls(format::ApiFamilyId::ApiFamily_D3D12, current_lock);

        auto target_draw_call_cmd = target_info->split_command_sets[graphics::dx12::kDrawCallArrayIndex].list;
        GFXRECON_ASSERT(target_draw_call_cmd);
        cmdlists.emplace_back(target_draw_call_cmd);

        auto unwrap_memory = GetHandleUnwrapMemory();
        queue->ExecuteCommandLists(cmdlists.size(),
                                   UnwrapObjects<ID3D12CommandList>(cmdlists.data(), cmdlists.size(), unwrap_memory));

        Encode_ID3D12CommandQueue_ExecuteCommandLists(wrapper, cmdlists.size(), cmdlists.data());
        cmdlists.clear();

        common_manager_->DeactivateTrimmingDrawCalls(current_lock);

        // after of splitted and after of lists
        auto after_draw_call_cmd = target_info->split_command_sets[graphics::dx12::kAfterDrawCallArrayIndex].list;
        GFXRECON_ASSERT(after_draw_call_cmd);
        cmdlists.emplace_back(after_draw_call_cmd);

        for (uint32_t i = (trim_draw_calls.command_index + 1); i < num_lists; ++i)
        {
            cmdlists.emplace_back(lists[i]);
        }

        queue->ExecuteCommandLists(cmdlists.size(),
                                   UnwrapObjects<ID3D12CommandList>(cmdlists.data(), cmdlists.size(), unwrap_memory));
        return true;
    }
    return false;
}

bool D3D12CaptureManager::HasSplitCommandLists(UINT num_lists, ID3D12CommandList* const* lists)
{
    for (uint32_t i = 0; i < num_lists; ++i)
    {
        auto cmd_wrapper = reinterpret_cast<ID3D12CommandList_Wrapper*>(lists[i]);
        GFXRECON_ASSERT(cmd_wrapper);

        auto cmd_info = cmd_wrapper->GetObjectInfo();
        GFXRECON_ASSERT(cmd_info);

        if (cmd_info->is_split_commandlist)
        {
            return true;
        }
    }
    return false;
}

// It does something similar to Dx12DumpResources::GetCommandListsForDumpResources, but a bit different.
// Trimming draw calls is not like dump resources that could browse the captured file to find target commandlist and
// draw call before replay.
//
// For trimming draw calls, it doesn't know the target commandlist until running the target ExecuteCommandLists.
// In this case, it assumes every commandlist could be the target commandlist.
// Every commandlist has three splitted commandlists and add command to the splitted commandlists.
//
// It also can't know which draw call is the target in advance, commandlist has a draw_call_count to count it.
// Splitted commandlists will add some redundant commands since it couldn't know the target draw call in advance,
// But it shouldn't affect the result and performance.
//
// Another different with Dx12DumpResources::GetCommandListsForDumpResources is that the draw calls could be a range.
// It needs to take care of more about kDrawCall.
std::vector<graphics::dx12::CommandSet>
D3D12CaptureManager::GetCommandListsForTrimDrawCalls(ID3D12CommandList_Wrapper* wrapper, format::ApiCallId api_call_id)
{
    std::vector<graphics::dx12::CommandSet> cmd_sets;
    auto                                    cmd_list_info = wrapper->GetObjectInfo();

    // Splitted commandlists don't be splitted again.
    if (!IsTrimEnabled() || cmd_list_info->is_split_commandlist)
    {
        return cmd_sets;
    }

    auto                               trim_boundary   = GetTrimBoundary();
    CaptureSettings::TrimDrawCalls     trim_draw_calls = GetTrimDrawCalls();
    graphics::dx12::ID3D12DeviceComPtr device          = nullptr;
    HRESULT                            ret             = wrapper->GetDevice(IID_PPV_ARGS(&device));
    GFXRECON_ASSERT(SUCCEEDED(ret));

    auto device_wrapper = reinterpret_cast<ID3D12Device_Wrapper*>(device.GetInterfacePtr());
    GFXRECON_ASSERT(device_wrapper);

    for (auto& command_set : cmd_list_info->split_command_sets)
    {
        if (command_set.allocator == nullptr)
        {
            device_wrapper->CreateCommandAllocator(cmd_list_info->command_list_type,
                                                   IID_PPV_ARGS(&command_set.allocator));
            device_wrapper->CreateCommandList(
                0, cmd_list_info->command_list_type, command_set.allocator, nullptr, IID_PPV_ARGS(&command_set.list));

            auto split_list_wrapper = reinterpret_cast<ID3D12CommandList_Wrapper*>(command_set.list.GetInterfacePtr());
            GFXRECON_ASSERT(split_list_wrapper);
            auto split_list_info                  = split_list_wrapper->GetObjectInfo();
            split_list_info->is_split_commandlist = true;
        }
    }

    bool is_draw_call = false;
    switch (api_call_id)
    {
        case format::ApiCall_ID3D12GraphicsCommandList_ExecuteBundle:
        case format::ApiCall_ID3D12GraphicsCommandList_DrawInstanced:
        case format::ApiCall_ID3D12GraphicsCommandList_DrawIndexedInstanced:
        case format::ApiCall_ID3D12GraphicsCommandList_Dispatch:
        case format::ApiCall_ID3D12GraphicsCommandList_ExecuteIndirect:
        {
            is_draw_call = true;
            break;
        }
        default:
            break;
    };

    graphics::dx12::Dx12DumpResourcePos split_type = graphics::dx12::Dx12DumpResourcePos::kDrawCall;

    // draw_call_count is counted at TrackCommandExecution, and TrackCommandExecution is after this function.
    // It means that draw_call_count is counted after this function.
    // Ex: if target draw_call index is 1,
    // kBeforeDrawCall: the draw_call_count is 0 and 1(and is_draw_call is false)
    // kDrawCall: the draw_call_count is 1(is_draw_call is true)
    // kAfterDrawCall: the draw_call_count is larger than 1.
    //
    // If target draw call index is a range: 1-2,
    // kBeforeDrawCall: the draw_call_count is 0 and 1(and is_draw_call is false)
    // kDrawCall:  the draw_call_count is 1(and is_draw_call is true) and 2.
    // kAfterDrawCall: the draw_call_count is larger than 2.
    if (cmd_list_info->command_list_type == D3D12_COMMAND_LIST_TYPE_BUNDLE)
    {
        if (cmd_list_info->draw_call_count < trim_draw_calls.bundle_draw_call_indices.first ||
            (cmd_list_info->draw_call_count == trim_draw_calls.bundle_draw_call_indices.first && !is_draw_call))
        {
            split_type = graphics::dx12::Dx12DumpResourcePos::kBeforeDrawCall;
        }
        else if (cmd_list_info->draw_call_count > trim_draw_calls.bundle_draw_call_indices.last)
        {
            split_type = graphics::dx12::Dx12DumpResourcePos::kAfterDrawCall;
        }
    }
    else
    {
        if (cmd_list_info->draw_call_count < trim_draw_calls.draw_call_indices.first ||
            (cmd_list_info->draw_call_count == trim_draw_calls.draw_call_indices.first && !is_draw_call))
        {
            split_type = graphics::dx12::Dx12DumpResourcePos::kBeforeDrawCall;
        }
        else if (cmd_list_info->draw_call_count > trim_draw_calls.draw_call_indices.last)
        {
            split_type = graphics::dx12::Dx12DumpResourcePos::kAfterDrawCall;
        }
    }
    auto split_type_array_index = graphics::dx12::Dx12DumpResourcePosToArrayIndex(split_type);

    // Here is to split command lists.
    switch (api_call_id)
    {
        case format::ApiCall_ID3D12GraphicsCommandList_Reset:
        {
            for (auto& command_set : cmd_list_info->split_command_sets)
            {
                auto list_wrapper =
                    reinterpret_cast<ID3D12GraphicsCommandList_Wrapper*>(command_set.list.GetInterfacePtr());
                GFXRECON_ASSERT(list_wrapper);

                auto list_info = list_wrapper->GetObjectInfo();
                if (!list_info->is_closed)
                {
                    list_wrapper->Close();
                }

                auto alc_wrapper =
                    reinterpret_cast<ID3D12CommandAllocator_Wrapper*>(command_set.allocator.GetInterfacePtr());
                GFXRECON_ASSERT(alc_wrapper);

                alc_wrapper->Reset();
                cmd_sets.emplace_back(command_set);
            }
            break;
        }
        // It has to ensure that every splited commandlist has a pair of Queries, Events, RenderPasses.
        // It can't know which RenderPass is the target in advance, so every RenderPass is added in every commandlist.
        case format::ApiCall_ID3D12GraphicsCommandList_BeginQuery:
        case format::ApiCall_ID3D12GraphicsCommandList_EndQuery:
        case format::ApiCall_ID3D12GraphicsCommandList_BeginEvent:
        case format::ApiCall_ID3D12GraphicsCommandList_EndEvent:
        case format::ApiCall_ID3D12GraphicsCommandList4_BeginRenderPass:
        case format::ApiCall_ID3D12GraphicsCommandList4_EndRenderPass:
        case format::ApiCall_ID3D12GraphicsCommandList_Close:
        {
            cmd_sets.insert(
                cmd_sets.end(), cmd_list_info->split_command_sets.begin(), cmd_list_info->split_command_sets.end());
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
                case graphics::dx12::Dx12DumpResourcePos::kBeforeDrawCall:
                    cmd_sets.insert(cmd_sets.end(),
                                    cmd_list_info->split_command_sets.begin(),
                                    cmd_list_info->split_command_sets.end());
                    break;
                case graphics::dx12::Dx12DumpResourcePos::kDrawCall:
                    cmd_sets.emplace_back(cmd_list_info->split_command_sets[graphics::dx12::kDrawCallArrayIndex]);
                    cmd_sets.emplace_back(cmd_list_info->split_command_sets[graphics::dx12::kAfterDrawCallArrayIndex]);
                    break;
                case graphics::dx12::Dx12DumpResourcePos::kAfterDrawCall:
                    cmd_sets.emplace_back(cmd_list_info->split_command_sets[graphics::dx12::kAfterDrawCallArrayIndex]);
                    break;
                default:
                    break;
            }
            break;
        }
        case format::ApiCall_ID3D12GraphicsCommandList_ExecuteBundle:
        {
            switch (split_type)
            {
                case graphics::dx12::Dx12DumpResourcePos::kDrawCall:
                    if (trim_draw_calls.draw_call_indices.first != trim_draw_calls.draw_call_indices.last)
                    {
                        GFXRECON_LOG_FATAL("The target draw call is a ExecuteBundle. The draw call indices must be not "
                                           "a range(%d-%d).",
                                           trim_draw_calls.draw_call_indices.first,
                                           trim_draw_calls.draw_call_indices.last);
                        GFXRECON_ASSERT(trim_draw_calls.draw_call_indices.first ==
                                        trim_draw_calls.draw_call_indices.last);
                    }
                    cmd_sets.insert(cmd_sets.end(),
                                    cmd_list_info->split_command_sets.begin(),
                                    cmd_list_info->split_command_sets.end());
                    ++cmd_list_info->find_target_draw_call_count;
                    break;
                default:
                    cmd_sets.emplace_back(cmd_list_info->split_command_sets[split_type_array_index]);
                    break;
            }
            break;
        }
        case format::ApiCall_ID3D12GraphicsCommandList_DrawInstanced:
        case format::ApiCall_ID3D12GraphicsCommandList_DrawIndexedInstanced:
        case format::ApiCall_ID3D12GraphicsCommandList_Dispatch:
        case format::ApiCall_ID3D12GraphicsCommandList_ExecuteIndirect:
        {
            switch (split_type)
            {
                case graphics::dx12::Dx12DumpResourcePos::kDrawCall:
                    ++cmd_list_info->find_target_draw_call_count;
                default:
                    cmd_sets.emplace_back(cmd_list_info->split_command_sets[split_type_array_index]);
                    break;
            }
            break;
        }
        default: // command could change data, like clear and copy.
        {
            cmd_sets.emplace_back(cmd_list_info->split_command_sets[split_type_array_index]);
            break;
        }
    }
    return cmd_sets;
}

void D3D12CaptureManager::PostProcess_IDXGISwapChain3_SetColorSpace1(IDXGISwapChain_Wrapper* wrapper,
                                                                     HRESULT                 result,
                                                                     DXGI_COLOR_SPACE_TYPE   ColorSpace)
{
    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackSetColorSpace1(wrapper, result, ColorSpace);
    }
}

void D3D12CaptureManager::PostProcess_IDXGISwapChain4_SetHDRMetaData(
    IDXGISwapChain_Wrapper* wrapper, HRESULT result, DXGI_HDR_METADATA_TYPE Type, UINT Size, void* pMetaData)
{
    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackSetHDRMetaData(wrapper, result, Type, Size, pMetaData);
    }
}

void D3D12CaptureManager::PostProcess_SetName(IUnknown_Wrapper* wrapper, HRESULT result, LPCWSTR Name)
{
    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackSetName(wrapper, result, Name);
    }
}

void D3D12CaptureManager::PostProcess_InitializeMetaCommand(ID3D12GraphicsCommandList4_Wrapper* wrapper,
                                                            ID3D12MetaCommand*                  pMetaCommand,
                                                            const void* pInitializationParametersData,
                                                            SIZE_T      InitializationParametersDataSizeInBytes)
{
    if (IsCaptureModeTrack())
    {
        auto metacommand_info = reinterpret_cast<ID3D12MetaCommand_Wrapper*>(pMetaCommand)->GetObjectInfo();
        metacommand_info->was_initialized = true;
        metacommand_info->initialize_parameters = std::make_unique<util::MemoryOutputStream>(
            pInitializationParametersData, InitializationParametersDataSizeInBytes);
    }
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
