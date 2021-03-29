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

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

constexpr int32_t kDefaultWindowPositionX = 0;
constexpr int32_t kDefaultWindowPositionY = 0;

Dx12ReplayConsumerBase::Dx12ReplayConsumerBase(WindowFactory* window_factory) : window_factory_(window_factory) {}

Dx12ReplayConsumerBase::~Dx12ReplayConsumerBase()
{
    DestroyWindowHandles();
}

void Dx12ReplayConsumerBase::RemoveObject(format::HandleId id)
{
    object_mapping::RemoveObject(id, &object_info_table_);
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

HRESULT Dx12ReplayConsumerBase::OverrideCreateSwapChainForHwnd(
    DxObjectInfo*                                                  replay_object_info,
    HRESULT                                                        original_result,
    DxObjectInfo*                                                  device_info,
    uint64_t                                                       hwnd,
    StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC1>*           desc,
    StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_FULLSCREEN_DESC>* full_screen_desc,
    DxObjectInfo*                                                  restrict_to_output_info,
    HandlePointerDecoder<IDXGISwapChain1*>*                        swapchain)
{
    return CreateSwapChainForHwnd(replay_object_info,
                                  original_result,
                                  device_info,
                                  hwnd,
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

    auto     desc_pointer = desc->GetPointer();
    HRESULT  result       = E_FAIL;
    uint64_t hwnd         = 0;
    Window*  window       = nullptr;

    if (desc_pointer != nullptr)
    {
        window = window_factory_->Create(kDefaultWindowPositionX,
                                         kDefaultWindowPositionY,
                                         desc_pointer->BufferDesc.Width,
                                         desc_pointer->BufferDesc.Height);
    }

    if (window != nullptr)
    {
        if (window->GetNativeHandle(Window::kWin32HWnd, reinterpret_cast<void**>(&hwnd)))
        {
            assert((replay_object_info != nullptr) && (swapchain != nullptr));

            IDXGIFactory* replay_object = static_cast<IDXGIFactory*>(replay_object_info->object);
            IUnknown*     device        = nullptr;

            if (device_info != nullptr)
            {
                device = device_info->object;
            }

            result = replay_object->CreateSwapChain(device, desc_pointer, swapchain->GetHandlePointer());

            if (SUCCEEDED(result))
            {
                InsertWindowHandleToMap(hwnd, window);
            }
            else
            {
                GFXRECON_LOG_FATAL("Failed to retrieve handle from window");
            }
        }
        else
        {
            GFXRECON_LOG_FATAL("Failed to retrieve handle from window");
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

    uint64_t hwnd = 0;
    return CreateSwapChainForHwnd(
        replay_object_info, original_result, device_info, hwnd, desc, nullptr, restrict_to_output_info, swapchain);
}

HRESULT
Dx12ReplayConsumerBase::OverrideCreateSwapChainForComposition(DxObjectInfo* replay_object_info,
                                                              HRESULT       original_result,
                                                              DxObjectInfo* device_info,
                                                              StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC1>* desc,
                                                              DxObjectInfo* restrict_to_output_info,
                                                              HandlePointerDecoder<IDXGISwapChain1*>* swapchain)
{
    uint64_t hwnd = 0;
    return CreateSwapChainForHwnd(
        replay_object_info, original_result, device_info, hwnd, desc, nullptr, restrict_to_output_info, swapchain);
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

void Dx12ReplayConsumerBase::DestroyWindowHandles()
{
    for (auto& entry : swapchain_windows_)
    {
        window_factory_->Destroy(entry.second);
    }
    swapchain_windows_.clear();
}

HRESULT Dx12ReplayConsumerBase::CreateSwapChainForHwnd(
    DxObjectInfo*                                                  replay_object_info,
    HRESULT                                                        original_result,
    DxObjectInfo*                                                  device_info,
    uint64_t                                                       hwnd,
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
        if (window->GetNativeHandle(Window::kWin32HWnd, reinterpret_cast<void**>(&hwnd)))
        {
            assert((replay_object_info != nullptr) && (full_screen_desc != nullptr) && (swapchain != nullptr));

            IDXGIFactory2* replay_object      = static_cast<IDXGIFactory2*>(replay_object_info->object);
            IUnknown*      device             = nullptr;
            IDXGIOutput*   restrict_to_output = nullptr;

            if (device_info != nullptr)
            {
                device = device_info->object;
            }

            if (restrict_to_output_info != nullptr)
            {
                restrict_to_output = static_cast<IDXGIOutput*>(restrict_to_output_info->object);
            }

            result = replay_object->CreateSwapChainForHwnd(device,
                                                           *reinterpret_cast<HWND*>(&hwnd),
                                                           desc_pointer,
                                                           full_screen_desc->GetPointer(),
                                                           restrict_to_output,
                                                           swapchain->GetHandlePointer());

            if (SUCCEEDED(result))
            {
                InsertWindowHandleToMap(hwnd, window);
            }
        }
        else
        {
            GFXRECON_LOG_FATAL("Failed to retrieve handle from window");
        }
    }
    else
    {
        GFXRECON_LOG_FATAL("Failed to create a window.  Replay cannot continue.");
    }

    return result;
}

void Dx12ReplayConsumerBase::InsertWindowHandleToMap(uint64_t& hwnd, Window* window)
{
    if (swapchain_windows_.find(hwnd) == swapchain_windows_.end())
    {
        swapchain_windows_.insert({ hwnd, window });
    }
    else
    {
        GFXRECON_LOG_WARNING("Such swapchain handle already exists");
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
