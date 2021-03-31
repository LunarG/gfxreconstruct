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
    IDXGIFactory2*                                                 replay_object,
    HRESULT                                                        original_result,
    IUnknown*                                                      device,
    uint64_t                                                       hwnd,
    StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC1>*           desc,
    StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_FULLSCREEN_DESC>* full_screen_desc,
    IDXGIOutput*                                                   restrict_to_output,
    HandlePointerDecoder<IDXGISwapChain1*>*                        swapchain)
{
    return CreateSwapChainForHwnd(replay_object,
                                  original_result,
                                  device,
                                  hwnd,
                                  desc->GetPointer(),
                                  full_screen_desc->GetPointer(),
                                  restrict_to_output,
                                  swapchain);
}

HRESULT
Dx12ReplayConsumerBase::OverrideCreateSwapChain(IDXGIFactory*                                       replay_object,
                                                HRESULT                                             original_result,
                                                IUnknown*                                           device,
                                                StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC>* desc,
                                                HandlePointerDecoder<IDXGISwapChain*>*              swapchain)
{
    HRESULT  result = E_FAIL;
    uint64_t hwnd   = 0;
    Window*  window = window_factory_->Create(kDefaultWindowPositionX,
                                             kDefaultWindowPositionY,
                                             desc->GetPointer()->BufferDesc.Width,
                                             desc->GetPointer()->BufferDesc.Height);

    if (window != nullptr)
    {
        if (window->GetNativeHandle(Window::kWin32HWnd, reinterpret_cast<void**>(&hwnd)))
        {
            result = replay_object->CreateSwapChain(device, desc->GetPointer(), swapchain->GetHandlePointer());

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

HRESULT Dx12ReplayConsumerBase::OverrideCreateSwapChain(IDXGIFactory2*                          replay_object,
                                                        HRESULT                                 original_result,
                                                        IUnknown*                               device,
                                                        DXGI_SWAP_CHAIN_DESC1*                  desc,
                                                        HandlePointerDecoder<IDXGISwapChain1*>* swapchain)
{
    uint64_t hwnd = 0;
    return CreateSwapChainForHwnd(replay_object, original_result, device, hwnd, desc, nullptr, nullptr, swapchain);
}

HRESULT
Dx12ReplayConsumerBase::OverrideCreateSwapChainForCoreWindow(IDXGIFactory2* replay_object,
                                                             HRESULT        original_result,
                                                             IUnknown*      device,
                                                             IUnknown*      window,
                                                             StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC1>* desc,
                                                             IDXGIOutput*                            restrict_to_output,
                                                             HandlePointerDecoder<IDXGISwapChain1*>* swapchain)
{
    uint64_t hwnd = 0;
    return CreateSwapChainForHwnd(
        replay_object, original_result, device, hwnd, desc->GetPointer(), nullptr, restrict_to_output, swapchain);
}

HRESULT
Dx12ReplayConsumerBase::OverrideCreateSwapChainForComposition(IDXGIFactory2* replay_object,
                                                              HRESULT        original_result,
                                                              IUnknown*      device,
                                                              StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC1>* desc,
                                                              IDXGIOutput* restrict_to_output,
                                                              HandlePointerDecoder<IDXGISwapChain1*>* swapchain)
{
    uint64_t hwnd = 0;
    return CreateSwapChainForHwnd(
        replay_object, original_result, device, hwnd, desc->GetPointer(), nullptr, restrict_to_output, swapchain);
}

void Dx12ReplayConsumerBase::DestroyWindowHandles()
{
    for (auto& entry : swapchain_windows_)
    {
        window_factory_->Destroy(entry.second);
    }
    swapchain_windows_.clear();
}

HRESULT Dx12ReplayConsumerBase::CreateSwapChainForHwnd(IDXGIFactory2*                          replay_object,
                                                       HRESULT                                 original_result,
                                                       IUnknown*                               device,
                                                       uint64_t                                hwnd,
                                                       const DXGI_SWAP_CHAIN_DESC1*            desc,
                                                       const DXGI_SWAP_CHAIN_FULLSCREEN_DESC*  full_screen_desc,
                                                       IDXGIOutput*                            restrict_to_output,
                                                       HandlePointerDecoder<IDXGISwapChain1*>* swapchain)
{
    HRESULT result = E_FAIL;
    Window* window =
        window_factory_->Create(kDefaultWindowPositionX, kDefaultWindowPositionY, desc->Width, desc->Height);

    if (window != nullptr)
    {
        if (window->GetNativeHandle(Window::kWin32HWnd, reinterpret_cast<void**>(&hwnd)))
        {
            result = replay_object->CreateSwapChainForHwnd(device,
                                                           *reinterpret_cast<HWND*>(&hwnd),
                                                           desc,
                                                           full_screen_desc,
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
