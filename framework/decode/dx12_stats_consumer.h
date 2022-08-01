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
        swapchain_width_(0), swapchain_height_(0), swapchain_id_(0), swapchain_info_found_(false), dxr_workload_(false)
    {}

    bool IsComplete(uint64_t current_block_index) override { return false; }

    const std::vector<format::DxgiAdapterDesc> GetAdapters() { return hardware_adapters_; }

    bool FoundSwapchainInfo() { return swapchain_info_found_; }

    bool ContainsDxrWorkload() { return dxr_workload_; }

    template <typename DescT>
    void CopyAdapterDesc(format::DxgiAdapterDesc& dest, DescT& src)
    {
        util::platform::MemoryCopy(&dest.Description,
                                   format::kAdapterDescriptionSize,
                                   src->GetPointer()->Description,
                                   format::kAdapterDescriptionSize);

        dest.VendorId              = src->GetPointer()->VendorId;
        dest.DeviceId              = src->GetPointer()->DeviceId;
        dest.SubSysId              = src->GetPointer()->SubSysId;
        dest.DedicatedVideoMemory  = src->GetPointer()->DedicatedVideoMemory;
        dest.DedicatedSystemMemory = src->GetPointer()->DedicatedSystemMemory;
        dest.SharedSystemMemory    = src->GetPointer()->SharedSystemMemory;
        dest.LuidLowPart           = src->GetPointer()->AdapterLuid.LowPart;
        dest.LuidHighPart          = src->GetPointer()->AdapterLuid.HighPart;
    }

    void InsertAdapter(const format::DxgiAdapterDesc& new_adapter)
    {
        bool insert = true;

        for (const auto& adapter : hardware_adapters_)
        {
            if ((adapter.LuidHighPart == new_adapter.LuidHighPart) && (adapter.LuidLowPart == new_adapter.LuidLowPart))
            {
                insert = false;
                break;
            }
        }

        if (insert)
        {
            hardware_adapters_.push_back(new_adapter);
        }
    }

    virtual void
    Process_IDXGIAdapter2_GetDesc2(const gfxrecon::decode::ApiCallInfo&                                call_info,
                                   gfxrecon::format::HandleId                                          object_id,
                                   HRESULT                                                             return_value,
                                   gfxrecon::decode::StructPointerDecoder<Decoded_DXGI_ADAPTER_DESC2>* pDesc)
    {
        format::DxgiAdapterDesc new_adapter = {};
        CopyAdapterDesc(new_adapter, pDesc);
        InsertAdapter(new_adapter);
    }

    virtual void
    Process_IDXGIAdapter1_GetDesc1(const gfxrecon::decode::ApiCallInfo&                                call_info,
                                   gfxrecon::format::HandleId                                          object_id,
                                   HRESULT                                                             return_value,
                                   gfxrecon::decode::StructPointerDecoder<Decoded_DXGI_ADAPTER_DESC1>* pDesc)
    {
        format::DxgiAdapterDesc new_adapter = {};
        CopyAdapterDesc(new_adapter, pDesc);
        InsertAdapter(new_adapter);
    }

    virtual void Process_IDXGIAdapter_GetDesc(const gfxrecon::decode::ApiCallInfo& call_info,
                                              gfxrecon::format::HandleId           object_id,
                                              HRESULT                              return_value,
                                              gfxrecon::decode::StructPointerDecoder<Decoded_DXGI_ADAPTER_DESC>* pDesc)
    {
        format::DxgiAdapterDesc new_adapter = {};
        CopyAdapterDesc(new_adapter, pDesc);
        InsertAdapter(new_adapter);
    }

    std::string GetSwapchainDimensions()
    {
        return std::to_string(swapchain_width_) + 'x' + std::to_string(swapchain_height_);
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

                swapchain_info_found_ = true;
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

                swapchain_info_found_ = true;
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

            swapchain_info_found_ = true;
        }
    }

    virtual void Process_ID3D12GraphicsCommandList4_BuildRaytracingAccelerationStructure(
        const ApiCallInfo&                                                                call_info,
        format::HandleId                                                                  object_id,
        StructPointerDecoder<Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC>* pDesc,
        UINT                                                                              NumPostbuildInfoDescs,
        StructPointerDecoder<Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC>* pPostbuildInfoDescs)
    {
        dxr_workload_ = true;
    }

  private:
    std::vector<format::DxgiAdapterDesc> hardware_adapters_;

    UINT             swapchain_width_;
    UINT             swapchain_height_;
    format::HandleId swapchain_id_;
    bool             swapchain_info_found_;

    bool dxr_workload_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_DX12_STAT_CONSUMER_H
