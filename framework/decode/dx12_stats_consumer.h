/*
** Copyright (c) 2022 Advanced Micro Devices, Inc. All rights reserved.
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

#ifndef GFXRECON_DECODE_DX12_STAT_CONSUMER_H
#define GFXRECON_DECODE_DX12_STAT_CONSUMER_H

#include "generated/generated_dx12_consumer.h"
#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class Dx12StatsConsumer : public Dx12Consumer
{
  public:
    Dx12StatsConsumer() :
        device_ID_(0), vendor_ID_(0), subsys_id_(0), revision_(0), dedicated_video_memory_(0),
        dedicated_system_memory_(0), shared_system_memory_(0), swapchain_width_(0), swapchain_height_(0),
        swapchain_id_(0)
    {
        memset(&adapter_luid_, sizeof(adapter_luid_), 0);
    }

    WCHAR*   GetAdapterDescription() { return description_; }
    uint32_t GetVendorID() { return vendor_ID_; }
    uint32_t GetDeviceID() { return device_ID_; }
    uint32_t GetSubsysID() { return subsys_id_; }
    uint32_t GetRevision() { return revision_; }
    uint64_t GetDedicatedVideoMemory() { return dedicated_video_memory_; }
    uint64_t GetDedicatedSystemMemory() { return dedicated_system_memory_; }
    uint64_t GetSharedSystemMemory() { return shared_system_memory_; }
    DWORD    GetAdapterLUIDLowPart() { return adapter_luid_.LowPart; };
    LONG     GetAdapterLUIDHighPart() { return adapter_luid_.HighPart; };

    bool IsComplete(uint64_t current_block_index) override { return false; }

    std::string GetSwapchainDimensions()
    {
        return std::to_string(swapchain_width_) + 'x' + std::to_string(swapchain_height_);
    }

    virtual void
    Process_IDXGIAdapter1_GetDesc1(const gfxrecon::decode::ApiCallInfo&                                call_info,
                                   gfxrecon::format::HandleId                                          object_id,
                                   HRESULT                                                             return_value,
                                   gfxrecon::decode::StructPointerDecoder<Decoded_DXGI_ADAPTER_DESC1>* pDesc)
    {
        wcscpy_s(description_, pDesc->GetPointer()->Description);
        vendor_ID_               = pDesc->GetPointer()->VendorId;
        device_ID_               = pDesc->GetPointer()->DeviceId;
        subsys_id_               = pDesc->GetPointer()->SubSysId;
        revision_                = pDesc->GetPointer()->Revision;
        dedicated_video_memory_  = pDesc->GetPointer()->DedicatedVideoMemory;
        dedicated_system_memory_ = pDesc->GetPointer()->DedicatedSystemMemory;
        shared_system_memory_    = pDesc->GetPointer()->SharedSystemMemory;
        adapter_luid_            = pDesc->GetPointer()->AdapterLuid;
    }

    virtual void Process_IDXGIAdapter_GetDesc(const gfxrecon::decode::ApiCallInfo& call_info,
                                              gfxrecon::format::HandleId           object_id,
                                              HRESULT                              return_value,
                                              gfxrecon::decode::StructPointerDecoder<Decoded_DXGI_ADAPTER_DESC>* pDesc)
    {
        wcscpy_s(description_, pDesc->GetPointer()->Description);
        vendor_ID_               = pDesc->GetPointer()->VendorId;
        device_ID_               = pDesc->GetPointer()->DeviceId;
        subsys_id_               = pDesc->GetPointer()->SubSysId;
        revision_                = pDesc->GetPointer()->Revision;
        dedicated_video_memory_  = pDesc->GetPointer()->DedicatedVideoMemory;
        dedicated_system_memory_ = pDesc->GetPointer()->DedicatedSystemMemory;
        shared_system_memory_    = pDesc->GetPointer()->SharedSystemMemory;
        adapter_luid_            = pDesc->GetPointer()->AdapterLuid;
    }

    virtual void Process_IDXGIFactory_CreateSwapChain(const ApiCallInfo&                                  call_info,
                                                      format::HandleId                                    object_id,
                                                      HRESULT                                             return_value,
                                                      format::HandleId                                    pDevice,
                                                      StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC>* pDesc,
                                                      HandlePointerDecoder<IDXGISwapChain*>*              ppSwapChain)
    {
        if (!ppSwapChain->IsNull())
        {
            swapchain_id_ = *ppSwapChain->GetPointer();

            auto desc_pointer = pDesc->GetPointer();
            if (desc_pointer != nullptr)
            {
                swapchain_width_  = desc_pointer->BufferDesc.Width;
                swapchain_height_ = desc_pointer->BufferDesc.Height;
            }
        }
    }

    virtual void Process_IDXGIFactory2_CreateSwapChainForHwnd(
        const ApiCallInfo&                                             call_info,
        format::HandleId                                               object_id,
        HRESULT                                                        return_value,
        format::HandleId                                               pDevice,
        uint64_t                                                       hWnd,
        StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC1>*           pDesc,
        StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_FULLSCREEN_DESC>* pFullscreenDesc,
        format::HandleId                                               pRestrictToOutput,
        HandlePointerDecoder<IDXGISwapChain1*>*                        ppSwapChain)
    {
        if (!ppSwapChain->IsNull())
        {
            swapchain_id_     = *ppSwapChain->GetPointer();
            auto desc_pointer = pDesc->GetPointer();
            if (desc_pointer != nullptr)
            {
                swapchain_width_  = desc_pointer->Width;
                swapchain_height_ = desc_pointer->Height;
            }
        }
    }

    virtual void Process_IDXGISwapChain_ResizeBuffers(const ApiCallInfo& call_info,
                                                      format::HandleId   object_id,
                                                      HRESULT            return_value,
                                                      UINT               BufferCount,
                                                      UINT               Width,
                                                      UINT               Height,
                                                      DXGI_FORMAT        NewFormat,
                                                      UINT               SwapChainFlags)
    {
        if (swapchain_id_ == object_id)
        {
            swapchain_width_  = Width;
            swapchain_height_ = Height;
        }
    }

  private:
    WCHAR            description_[128] = {};
    uint32_t         vendor_ID_;
    uint32_t         device_ID_;
    uint32_t         subsys_id_;
    uint32_t         revision_;
    uint64_t         dedicated_video_memory_;
    uint64_t         dedicated_system_memory_;
    uint64_t         shared_system_memory_;
    LUID             adapter_luid_;
    UINT             swapchain_width_;
    UINT             swapchain_height_;
    format::HandleId swapchain_id_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_DX12_STAT_CONSUMER_H
