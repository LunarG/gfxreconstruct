/*
** Copyright (c) 2022-2023 Advanced Micro Devices, Inc. All rights reserved.
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

#include "decode/dx12_object_info.h"
#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class Dx12StatsConsumer : public Dx12Consumer
{
  public:
    Dx12StatsConsumer() :
        swapchain_width_(0), swapchain_height_(0), swapchain_id_(0), swapchain_info_found_(false),
        dummy_trim_frame_count_(0)
    {}

    bool IsComplete(uint64_t current_block_index) override { return false; }

    format::Dx12RuntimeInfo GetDx12RuntimeInfo() { return runtime_info_; }

    const std::vector<format::DxgiAdapterDesc> GetAdapters()
    {
        // If a kDxgiAdapterInfoCommand block was detected, then return that info
        if (gfxr_cmd_adapters_.empty() == false)
        {
            return gfxr_cmd_adapters_;
        }
        else
        {
            return app_get_desc_adapters;
        }
    }

    bool FoundSwapchainInfo() { return swapchain_info_found_; }

    UINT GetDummyFrameCount() { return dummy_trim_frame_count_; }

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

    void InsertAdapter(const format::DxgiAdapterDesc& new_adapter, std::vector<format::DxgiAdapterDesc>& adapters)
    {
        bool insert = true;

        for (auto& adapter : adapters)
        {
            if ((adapter.LuidHighPart == new_adapter.LuidHighPart) && (adapter.LuidLowPart == new_adapter.LuidLowPart))
            {
                insert = false;
                if (!graphics::dx12::ExtractAdapterType(adapter.extra_info))
                {
                    format::AdapterType type = graphics::dx12::ExtractAdapterType(new_adapter.extra_info);
                    graphics::dx12::InjectAdapterType(adapter.extra_info, type);
                }
                break;
            }
        }

        if (insert)
        {
            adapters.push_back(new_adapter);
        }
    }

    virtual void ProcessDxgiAdapterInfo(const format::DxgiAdapterInfoCommandHeader& adapter_info_header)
    {
        format::DxgiAdapterDesc new_adapter = {};
        util::platform::MemoryCopy(&new_adapter.Description,
                                   format::kAdapterDescriptionSize,
                                   adapter_info_header.adapter_desc.Description,
                                   format::kAdapterDescriptionSize);

        new_adapter.VendorId              = adapter_info_header.adapter_desc.VendorId;
        new_adapter.DeviceId              = adapter_info_header.adapter_desc.DeviceId;
        new_adapter.SubSysId              = adapter_info_header.adapter_desc.SubSysId;
        new_adapter.DedicatedVideoMemory  = adapter_info_header.adapter_desc.DedicatedVideoMemory;
        new_adapter.DedicatedSystemMemory = adapter_info_header.adapter_desc.DedicatedSystemMemory;
        new_adapter.SharedSystemMemory    = adapter_info_header.adapter_desc.SharedSystemMemory;
        new_adapter.LuidLowPart           = adapter_info_header.adapter_desc.LuidLowPart;
        new_adapter.LuidHighPart          = adapter_info_header.adapter_desc.LuidHighPart;
        new_adapter.extra_info            = adapter_info_header.adapter_desc.extra_info;
        InsertAdapter(new_adapter, gfxr_cmd_adapters_);
        format::HandleId object_id = graphics::dx12::ExtractAdapterCaptureId(new_adapter.extra_info);

        const int64_t luid = pack_luid(new_adapter);
        adapter_submission_mapping_.adapter_to_luid_map[object_id] = luid;
    }

    virtual void Process_IDXGIAdapter4_GetDesc3(const ApiCallInfo&                                call_info,
                                                format::HandleId                                  object_id,
                                                HRESULT                                           return_value,
                                                StructPointerDecoder<Decoded_DXGI_ADAPTER_DESC3>* pDesc)
    {
        format::DxgiAdapterDesc new_adapter = {};
        CopyAdapterDesc(new_adapter, pDesc);
        InsertAdapter(new_adapter, app_get_desc_adapters);
    }

    virtual void
    Process_IDXGIAdapter2_GetDesc2(const gfxrecon::decode::ApiCallInfo&                                call_info,
                                   gfxrecon::format::HandleId                                          object_id,
                                   HRESULT                                                             return_value,
                                   gfxrecon::decode::StructPointerDecoder<Decoded_DXGI_ADAPTER_DESC2>* pDesc)
    {
        format::DxgiAdapterDesc new_adapter = {};
        CopyAdapterDesc(new_adapter, pDesc);
        InsertAdapter(new_adapter, app_get_desc_adapters);
    }

    virtual void
    Process_IDXGIAdapter1_GetDesc1(const gfxrecon::decode::ApiCallInfo&                                call_info,
                                   gfxrecon::format::HandleId                                          object_id,
                                   HRESULT                                                             return_value,
                                   gfxrecon::decode::StructPointerDecoder<Decoded_DXGI_ADAPTER_DESC1>* pDesc)
    {
        format::DxgiAdapterDesc new_adapter = {};
        CopyAdapterDesc(new_adapter, pDesc);
        InsertAdapter(new_adapter, app_get_desc_adapters);
    }

    virtual void Process_IDXGIAdapter_GetDesc(const gfxrecon::decode::ApiCallInfo& call_info,
                                              gfxrecon::format::HandleId           object_id,
                                              HRESULT                              return_value,
                                              gfxrecon::decode::StructPointerDecoder<Decoded_DXGI_ADAPTER_DESC>* pDesc)
    {
        format::DxgiAdapterDesc new_adapter = {};
        CopyAdapterDesc(new_adapter, pDesc);
        InsertAdapter(new_adapter, app_get_desc_adapters);
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

    virtual void
    ProcessFillMemoryResourceValueCommand(const format::FillMemoryResourceValueCommandHeader& command_header,
                                          const uint8_t*                                      data)
    {
        opt_fillmem_ = true;
    }

    virtual void ProcessInitDx12AccelerationStructureCommand(
        const format::InitDx12AccelerationStructureCommandHeader&             command_header,
        const std::vector<format::InitDx12AccelerationStructureGeometryDesc>& geometry_descs,
        const uint8_t*                                                        build_inputs_data)
    {
        dxr_workload_ = true;
    }

    void Process_ID3D12GraphicsCommandList_ExecuteIndirect(const ApiCallInfo& call_info,
                                                           format::HandleId   object_id,
                                                           format::HandleId   pCommandSignature,
                                                           UINT               MaxCommandCount,
                                                           format::HandleId   pArgumentBuffer,
                                                           UINT64             ArgumentBufferOffset,
                                                           format::HandleId   pCountBuffer,
                                                           UINT64             CountBufferOffset)
    {
        ei_workload_ = true;
    }

    void Process_IDXGISwapChain_Present(const ApiCallInfo& call_info,
                                        format::HandleId   object_id,
                                        HRESULT            return_value,
                                        UINT               SyncInterval,
                                        UINT               Flags)
    {
        if (Flags & DXGI_PRESENT_TEST)
        {
            dxgi_present_test_++;
        }        
    }

    virtual void ProcessDx12RuntimeInfo(const format::Dx12RuntimeInfoCommandHeader& runtime_info_header)
    {
        util::platform::MemoryCopy(&runtime_info_,
                                   sizeof(runtime_info_),
                                   &runtime_info_header.runtime_info,
                                   sizeof(runtime_info_header.runtime_info));
    }

    virtual void ProcessSetSwapchainImageStateCommand(format::HandleId                                    device_id,
                                                      format::HandleId                                    swapchain_id,
                                                      uint32_t                                            current_buffer_index,
                                                      const std::vector<format::SwapchainImageStateInfo>& image_state)
    {
        dummy_trim_frame_count_ = current_buffer_index;
    }

    virtual void Process_D3D12CreateDevice(const ApiCallInfo&           call_info,
                                           HRESULT                      return_value,
                                           format::HandleId             pAdapter,
                                           D3D_FEATURE_LEVEL            MinimumFeatureLevel,
                                           Decoded_GUID                 riid,
                                           HandlePointerDecoder<void*>* ppDevice)
    {
        GFXRECON_ASSERT(ppDevice != nullptr);

        if (ppDevice != nullptr && ppDevice->GetPointer() != nullptr)
        {
            format::HandleId device_id                                   = *(ppDevice->GetPointer());
            adapter_submission_mapping_.device_to_adapter_map[device_id] = pAdapter;
        }
    }

    virtual void Process_ID3D12Device_CreateCommandQueue(const ApiCallInfo& call_info,
                                                         format::HandleId   object_id,
                                                         HRESULT            return_value,
                                                         StructPointerDecoder<Decoded_D3D12_COMMAND_QUEUE_DESC>* pDesc,
                                                         Decoded_GUID                                            riid,
                                                         HandlePointerDecoder<void*>* ppCommandQueue)
    {
        GFXRECON_ASSERT(ppCommandQueue != nullptr);

        if (ppCommandQueue != nullptr && ppCommandQueue->GetPointer() != nullptr)
        {
            format::HandleId command_queue_id                                 = *ppCommandQueue->GetPointer();
            adapter_submission_mapping_.queue_to_device_map[command_queue_id] = object_id;
        }
    }

    virtual void
    Process_ID3D12CommandQueue_ExecuteCommandLists(const ApiCallInfo&                        call_info,
                                                   format::HandleId                          object_id,
                                                   UINT                                      NumCommandLists,
                                                   HandlePointerDecoder<ID3D12CommandList*>* ppCommandLists)
    {
        GFXRECON_ASSERT(object_id != format::kNullHandleId)
        adapter_submission_mapping_.adapter_submit_counts[object_id]++;
    }

    // validation of workload LUID exists in adapters luid
    bool ValidateAdapterWorkload(int64_t workload_luid, const std::vector<gfxrecon::format::DxgiAdapterDesc> adapters)
    {
        bool valid_adapter = false;
        for (const auto& adapter : adapters)
        {
            const int64_t adapter_luid = pack_luid(adapter);
            if (workload_luid == adapter_luid)
            {
                valid_adapter = true;
                break;
            }
        }
        return valid_adapter;
    }

    void CalcAdapterWorkload(std::unordered_map<int64_t, std::string>&            adapter_workload,
                             const std::vector<gfxrecon::format::DxgiAdapterDesc> adapters)
    {
        uint64_t total_adapter_submits = 0;

        // calculate total amount of ExecuteCommandLists calls
        for (const auto& curr_adapter_id : adapter_submission_mapping_.adapter_submit_counts)
        {
            total_adapter_submits += curr_adapter_id.second;
        }
        std::unordered_map<int64_t, uint64_t> adapter_count_map;

        // calculate total calls per LUIDs. We can have several queue IDs per adapter LUID
        for (const auto& queue_map : adapter_submission_mapping_.queue_to_device_map)
        {
            format::HandleId adapter_id         = adapter_submission_mapping_.device_to_adapter_map[queue_map.second];
            int64_t          adapter_luid       = adapter_submission_mapping_.adapter_to_luid_map[adapter_id];
            uint64_t         queue_submit_count = adapter_submission_mapping_.adapter_submit_counts[queue_map.first];
            if (adapter_count_map[adapter_luid])
            {
                adapter_count_map[adapter_luid] += queue_submit_count;
            }
            else
            {
                adapter_count_map[adapter_luid] = queue_submit_count;
            }
        }

        // calculate workload of adapter and convert it to string
        for (const auto& workload : adapter_count_map)
        {
            std::string workload_value = std::to_string(100.0 * workload.second / total_adapter_submits);
            auto        dot_pos        = workload_value.find('.');
            if (dot_pos != std::string::npos)
            {
                workload_value.erase(dot_pos + 2);
            }
            if (ValidateAdapterWorkload(workload.first, adapters))
            {
                adapter_workload[workload.first] = workload_value;
            }
        }
    }

  private:
    // Holds adapter descs that were obtained from the app calling GetDesc()
    // This list is only here to support older captures which do contain kDxgiAdapterInfoCommand
    std::vector<format::DxgiAdapterDesc> app_get_desc_adapters;

    // Holds adapter descs that were tracked via kDxgiAdapterInfoCommand
    std::vector<format::DxgiAdapterDesc> gfxr_cmd_adapters_;

    UINT             swapchain_width_;
    UINT             swapchain_height_;
    format::HandleId swapchain_id_;
    bool             swapchain_info_found_;

    UINT             dummy_trim_frame_count_;

    format::Dx12RuntimeInfo runtime_info_;

    graphics::dx12::AdapterSubmissionMapping adapter_submission_mapping_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_DX12_STAT_CONSUMER_H
