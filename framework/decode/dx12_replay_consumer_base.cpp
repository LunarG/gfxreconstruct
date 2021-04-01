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

#include "util/platform.h"

#include <cassert>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

constexpr int32_t kDefaultWindowPositionX = 0;
constexpr int32_t kDefaultWindowPositionY = 0;

Dx12ReplayConsumerBase::Dx12ReplayConsumerBase(WindowFactory* window_factory) : window_factory_(window_factory) {}

Dx12ReplayConsumerBase::~Dx12ReplayConsumerBase()
{
    DestroyActiveWindows();
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

void Dx12ReplayConsumerBase::RemoveObject(DxObjectInfo* info)
{
    if (info != nullptr)
    {
        if (info->extra_info != nullptr)
        {
            if (info->extra_info_type == DxObjectInfoType::kID3D12ResourceInfo)
            {
                auto resource_info = reinterpret_cast<D3D12ResourceInfo*>(info->extra_info);

                for (const auto& entry : resource_info->mapped_memory_info)
                {
                    auto& mapped_info = entry.second;
                    mapped_memory_.erase(mapped_info.memory_id);
                }

                delete resource_info;
            }
            else if (info->extra_info_type == DxObjectInfoType::kIDxgiSwapchainInfo)
            {
                auto swapchain_info = reinterpret_cast<DxgiSwapchainInfo*>(info->extra_info);
                window_factory_->Destroy(swapchain_info->window);
                active_windows_.erase(swapchain_info->window);
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

        object_mapping::RemoveObject(info->capture_id, &object_info_table_);
    }
}

void Dx12ReplayConsumerBase::CheckReplayResult(const char* call_name, HRESULT capture_result, HRESULT replay_result)
{
    if (capture_result != replay_result)
    {
        GFXRECON_LOG_ERROR("%s returned %d, which does not match the value returned at capture",
                           call_name,
                           replay_result,
                           capture_result);
    }
}

void* Dx12ReplayConsumerBase::PreProcessExternalObject(uint64_t          object_id,
                                                       format::ApiCallId call_id,
                                                       const char*       call_name)
{
    void* object = nullptr;
    switch (call_id)
    {
        case format::ApiCallId::ApiCall_IDXGIFactory2_CreateSwapChainForHwnd:
            break;

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
    if ((replay_object_info != nullptr) && (replay_object_info->object != nullptr))
    {
        auto object = replay_object_info->object;

        ++(replay_object_info->ref_count);

        return object->AddRef();
    }

    return 0;
}

ULONG Dx12ReplayConsumerBase::OverrideRelease(DxObjectInfo* replay_object_info, ULONG original_result)
{
    if ((replay_object_info != nullptr) && (replay_object_info->object != nullptr))
    {
        assert(replay_object_info->ref_count > 0);

        auto object = replay_object_info->object;

        --(replay_object_info->ref_count);
        if (replay_object_info->ref_count == 0)
        {
            RemoveObject(replay_object_info);
        }

        return object->Release();
    }

    return 0;
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
        if (window->GetNativeHandle(Window::kWin32HWnd, reinterpret_cast<void**>(&desc_pointer->OutputWindow)))
        {
            assert((replay_object_info != nullptr) && (replay_object_info->object != nullptr) &&
                   (swapchain != nullptr));

            auto      replay_object = static_cast<IDXGIFactory*>(replay_object_info->object);
            IUnknown* device        = nullptr;

            if (device_info != nullptr)
            {
                device = device_info->object;
            }

            result = replay_object->CreateSwapChain(device, desc_pointer, swapchain->GetHandlePointer());

            if (SUCCEEDED(result))
            {
                SetSwapchainInfoWindow(replay_object_info, window);
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
    GFXRECON_UNREFERENCED_PARAMETER(hwnd_id);

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
                SetSwapchainInfoWindow(replay_object_info, window);
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

void Dx12ReplayConsumerBase::SetSwapchainInfoWindow(DxObjectInfo* info, Window* window)
{
    if (window != nullptr)
    {
        if (info != nullptr)
        {
            assert(info->extra_info == nullptr);

            auto swapchain_info    = new DxgiSwapchainInfo;
            swapchain_info->window = window;

            info->extra_info_type = DxObjectInfoType::kIDxgiSwapchainInfo;
            info->extra_info      = swapchain_info;
        }

        active_windows_.insert(window);
    }
}

void Dx12ReplayConsumerBase::DestroyActiveWindows()
{
    for (auto window : active_windows_)
    {
        window_factory_->Destroy(window);
    }

    active_windows_.clear();
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
