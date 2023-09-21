/*
** Copyright (c) 2021 LunarG, Inc.
** Copyright (c) 2023 Qualcomm Innovation Center, Inc. All rights reserved.
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

#ifndef GFXRECON_DECODE_DX12_CONSUMER_BASE_H
#define GFXRECON_DECODE_DX12_CONSUMER_BASE_H

#include "decode/api_decoder.h"
#include "decode/handle_pointer_decoder.h"
#include "decode/struct_pointer_decoder.h"

#include <d3d12.h>
#include <d3d11.h>
#include <d3d11_3.h>
#include <dxgi1_5.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

// TODO: Dx12ConsumerBase is very similar to VulkanConsumerBase. It might be able to merge into a shared class.
class Dx12ConsumerBase
{
  public:
    Dx12ConsumerBase() {}
    virtual ~Dx12ConsumerBase() {}

    virtual void Process_DriverInfo(const char* info_record) {}

    virtual void Process_ExeFileInfo(util::filepath::FileInfo& info_record) {}

    virtual bool IsComplete(uint64_t block_index) { return false; }

    virtual void ProcessStateBeginMarker(uint64_t frame_number) {}

    virtual void ProcessStateEndMarker(uint64_t frame_number) {}

    virtual void ProcessFrameEndMarker(uint64_t frame_number) {}

    virtual void ProcessDisplayMessageCommand(const std::string& message) {}

    virtual void ProcessFillMemoryCommand(uint64_t memory_id, uint64_t offset, uint64_t size, const uint8_t* data) {}

    virtual void
    ProcessFillMemoryResourceValueCommand(const format::FillMemoryResourceValueCommandHeader& command_header,
                                          const uint8_t*                                      data)
    {}

    virtual void ProcessResizeWindowCommand(format::HandleId surface_id, uint32_t width, uint32_t height) {}

    virtual void
    ProcessResizeWindowCommand2(format::HandleId surface_id, uint32_t width, uint32_t height, uint32_t pre_transform)
    {}

    virtual void ProcessCreateHardwareBufferCommand(format::HandleId                                    memory_id,
                                                    uint64_t                                            buffer_id,
                                                    uint32_t                                            format,
                                                    uint32_t                                            width,
                                                    uint32_t                                            height,
                                                    uint32_t                                            stride,
                                                    uint64_t                                            usage,
                                                    uint32_t                                            layers,
                                                    const std::vector<format::HardwareBufferPlaneInfo>& plane_info)
    {}

    virtual void ProcessDestroyHardwareBufferCommand(uint64_t buffer_id) {}

    virtual void ProcessCreateHeapAllocationCommand(uint64_t allocation_id, uint64_t allocation_size) {}

    virtual void ProcessSetDevicePropertiesCommand(format::HandleId   physical_device_id,
                                                   uint32_t           api_version,
                                                   uint32_t           driver_version,
                                                   uint32_t           vendor_id,
                                                   uint32_t           device_id,
                                                   uint32_t           device_type,
                                                   const uint8_t      pipeline_cache_uuid[format::kUuidSize],
                                                   const std::string& device_name)
    {}

    virtual void ProcessSetDeviceMemoryPropertiesCommand(format::HandleId physical_device_id,
                                                         const std::vector<format::DeviceMemoryType>& memory_types,
                                                         const std::vector<format::DeviceMemoryHeap>& memory_heaps)
    {}

    virtual void
    ProcessSetOpaqueAddressCommand(format::HandleId device_id, format::HandleId object_id, uint64_t address)
    {}

    virtual void ProcessSetRayTracingShaderGroupHandlesCommand(format::HandleId device_id,
                                                               format::HandleId pipeline_id,
                                                               size_t           data_size,
                                                               const uint8_t*   data)
    {}

    virtual void ProcessSetSwapchainImageStateCommand(format::HandleId device_id,
                                                      format::HandleId swapchain_id,
                                                      uint32_t         current_buffer_index,
                                                      const std::vector<format::SwapchainImageStateInfo>& image_state)
    {}

    virtual void
    ProcessBeginResourceInitCommand(format::HandleId device_id, uint64_t max_resource_size, uint64_t max_copy_size)
    {}

    virtual void ProcessEndResourceInitCommand(format::HandleId device_id) {}

    virtual void ProcessInitBufferCommand(format::HandleId device_id,
                                          format::HandleId buffer_id,
                                          uint64_t         data_size,
                                          const uint8_t*   data)
    {}

    virtual void ProcessInitImageCommand(format::HandleId             device_id,
                                         format::HandleId             image_id,
                                         uint64_t                     data_size,
                                         uint32_t                     aspect,
                                         uint32_t                     layout,
                                         const std::vector<uint64_t>& level_sizes,
                                         const uint8_t*               data)
    {}

    virtual void ProcessInitSubresourceCommand(const format::InitSubresourceCommandHeader& command_header,
                                               const uint8_t*                              data)
    {}

    virtual void ProcessInitDx12AccelerationStructureCommand(
        const format::InitDx12AccelerationStructureCommandHeader&       command_header,
        std::vector<format::InitDx12AccelerationStructureGeometryDesc>& geometry_descs,
        const uint8_t*                                                  build_inputs_data)
    {}

    virtual void ProcessDxgiAdapterInfo(const format::DxgiAdapterInfoCommandHeader& adapter_info_header) {}

    virtual void ProcessDx12RuntimeInfo(const format::Dx12RuntimeInfoCommandHeader& runtime_info_header) {}

    virtual void Process_ID3D12Device_CheckFeatureSupport(format::HandleId object_id,
                                                          HRESULT          original_result,
                                                          D3D12_FEATURE    feature,
                                                          const void*      capture_feature_data,
                                                          void*            replay_feature_data,
                                                          UINT             feature_data_size)
    {}

    virtual void Process_IDXGIFactory5_CheckFeatureSupport(format::HandleId object_id,
                                                           HRESULT          original_result,
                                                           DXGI_FEATURE     feature,
                                                           const void*      capture_feature_data,
                                                           void*            replay_feature_data,
                                                           UINT             feature_data_size)
    {}

    virtual void Process_ID3D12Resource_WriteToSubresource(format::HandleId                         object_id,
                                                           HRESULT                                  original_result,
                                                           UINT                                     DstSubresource,
                                                           StructPointerDecoder<Decoded_D3D12_BOX>* pDstBox,
                                                           void*                                    pSrcData,
                                                           UINT                                     SrcRowPitch,
                                                           UINT                                     SrcDepthPitch)
    {}

    virtual void Process_ID3D11Device_CheckFeatureSupport(const ApiCallInfo& call_info,
                                                          format::HandleId   object_id,
                                                          HRESULT            return_value,
                                                          D3D11_FEATURE      feature,
                                                          const void*        capture_feature_data,
                                                          void*              replay_feature_data,
                                                          UINT               feature_data_size)
    {}

    virtual void Process_ID3D11Device_CreateBuffer(const ApiCallInfo&                                    call_info,
                                                   format::HandleId                                      object_id,
                                                   HRESULT                                               return_value,
                                                   StructPointerDecoder<Decoded_D3D11_BUFFER_DESC>*      pDesc,
                                                   StructPointerDecoder<Decoded_D3D11_SUBRESOURCE_DATA>* pInitialData,
                                                   HandlePointerDecoder<ID3D11Buffer*>*                  ppBuffer)
    {}

    virtual void
    Process_ID3D11Device_CreateTexture1D(const ApiCallInfo&                                    call_info,
                                         format::HandleId                                      object_id,
                                         HRESULT                                               return_value,
                                         StructPointerDecoder<Decoded_D3D11_TEXTURE1D_DESC>*   pDesc,
                                         StructPointerDecoder<Decoded_D3D11_SUBRESOURCE_DATA>* pInitialData,
                                         HandlePointerDecoder<ID3D11Texture1D*>*               ppTexture1D)
    {}

    virtual void
    Process_ID3D11Device_CreateTexture2D(const ApiCallInfo&                                    call_info,
                                         format::HandleId                                      object_id,
                                         HRESULT                                               return_value,
                                         StructPointerDecoder<Decoded_D3D11_TEXTURE2D_DESC>*   pDesc,
                                         StructPointerDecoder<Decoded_D3D11_SUBRESOURCE_DATA>* pInitialData,
                                         HandlePointerDecoder<ID3D11Texture2D*>*               ppTexture2D)
    {}

    virtual void
    Process_ID3D11Device_CreateTexture3D(const ApiCallInfo&                                    call_info,
                                         format::HandleId                                      object_id,
                                         HRESULT                                               return_value,
                                         StructPointerDecoder<Decoded_D3D11_TEXTURE3D_DESC>*   pDesc,
                                         StructPointerDecoder<Decoded_D3D11_SUBRESOURCE_DATA>* pInitialData,
                                         HandlePointerDecoder<ID3D11Texture3D*>*               ppTexture3D)
    {}

    virtual void Process_ID3D11DeviceContext_UpdateSubresource(const ApiCallInfo&                       call_info,
                                                               format::HandleId                         object_id,
                                                               format::HandleId                         pDstResource,
                                                               UINT                                     DstSubresource,
                                                               StructPointerDecoder<Decoded_D3D11_BOX>* pDstBox,
                                                               PointerDecoder<uint8_t>*                 pSrcData,
                                                               UINT                                     SrcRowPitch,
                                                               UINT                                     SrcDepthPitch)
    {}

    virtual void Process_ID3D11DeviceContext1_UpdateSubresource1(const ApiCallInfo& call_info,
                                                                 format::HandleId   object_id,
                                                                 format::HandleId   pDstResource,
                                                                 UINT               DstSubresource,
                                                                 StructPointerDecoder<Decoded_D3D11_BOX>* pDstBox,
                                                                 PointerDecoder<uint8_t>*                 pSrcData,
                                                                 UINT                                     SrcRowPitch,
                                                                 UINT                                     SrcDepthPitch,
                                                                 UINT                                     CopyFlags)
    {}

    virtual void
    Process_ID3D11Device3_CreateTexture2D1(const ApiCallInfo&                                    call_info,
                                           format::HandleId                                      object_id,
                                           HRESULT                                               return_value,
                                           StructPointerDecoder<Decoded_D3D11_TEXTURE2D_DESC1>*  pDesc,
                                           StructPointerDecoder<Decoded_D3D11_SUBRESOURCE_DATA>* pInitialData,
                                           HandlePointerDecoder<ID3D11Texture2D1*>*              ppTexture2D)
    {}

    virtual void
    Process_ID3D11Device3_CreateTexture3D1(const ApiCallInfo&                                    call_info,
                                           format::HandleId                                      object_id,
                                           HRESULT                                               return_value,
                                           StructPointerDecoder<Decoded_D3D11_TEXTURE3D_DESC1>*  pDesc,
                                           StructPointerDecoder<Decoded_D3D11_SUBRESOURCE_DATA>* pInitialData,
                                           HandlePointerDecoder<ID3D11Texture3D1*>*              ppTexture3D)
    {}

    virtual void Process_ID3D11Device3_WriteToSubresource(const ApiCallInfo&                       call_info,
                                                          format::HandleId                         object_id,
                                                          format::HandleId                         pDstResource,
                                                          UINT                                     DstSubresource,
                                                          StructPointerDecoder<Decoded_D3D11_BOX>* pDstBox,
                                                          PointerDecoder<uint8_t>*                 pSrcData,
                                                          UINT                                     SrcRowPitch,
                                                          UINT                                     SrcDepthPitch)
    {}

    void SetCurrentBlockIndex(uint64_t block_index) { current_block_index_ = block_index; };

    bool ContainsDxrWorkload() const { return dxr_workload_; }

    bool ContainsEiWorkload() const { return ei_workload_; }

    bool ContainsOptFillMem() const { return opt_fillmem_; }

  protected:
    auto GetCurrentBlockIndex() { return current_block_index_; }

    bool dxr_workload_{ false };
    bool ei_workload_{ false };
    bool opt_fillmem_{ false };

  private:
    uint64_t current_block_index_{ 0 };
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_DX12_CONSUMER_BASE_H
