/*
** Copyright (c) 2024 LunarG, Inc.
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

/// @file Base class for generated DX12 consumer which outputs JSON and associated utilities.

#ifndef GFXRECON_DECODE_DX12_JSON_CONSUMER_BASE_H
#define GFXRECON_DECODE_DX12_JSON_CONSUMER_BASE_H

#include "generated/generated_dx12_consumer.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class JsonWriter;

/// @file Base class for generated DX12 consumer which outputs a JSON representation of a captured stream.
class Dx12JsonConsumerBase : public Dx12Consumer
{
  public:
    Dx12JsonConsumerBase();
    virtual ~Dx12JsonConsumerBase() override;

    void Initialize(JsonWriter* writer);

    void Destroy();

    bool IsValid() const;

    /// @defGroup MetaBlocksUsedOnlyByDx12 Metablocks used by only DX12.
    /// @{
    virtual void ProcessCreateHeapAllocationCommand(uint64_t allocation_id, uint64_t allocation_size) override;
    virtual void ProcessInitSubresourceCommand(const format::InitSubresourceCommandHeader& command_header,
                                               const uint8_t*                              data) override;
    virtual void ProcessInitDx12AccelerationStructureCommand(
        const format::InitDx12AccelerationStructureCommandHeader&       command_header,
        std::vector<format::InitDx12AccelerationStructureGeometryDesc>& geometry_descs,
        const uint8_t*                                                  build_inputs_data) override;
    virtual void
    ProcessFillMemoryResourceValueCommand(const format::FillMemoryResourceValueCommandHeader& command_header,
                                          const uint8_t*                                      data) override;
    virtual void ProcessDxgiAdapterInfo(const format::DxgiAdapterInfoCommandHeader& adapter_info_header) override;
    virtual void Process_DriverInfo(const char* info_record) override;
    virtual void ProcessDx12RuntimeInfo(const format::Dx12RuntimeInfoCommandHeader& runtime_info_header) override;
    /// @}

    /// @defGroup CustomFunctions DX12 functions and methods which require fully custom handling.
    /// @{
    /// Data must be extracted from the void pointer depending on the value of feature.
    void Process_ID3D12Device_CheckFeatureSupport(format::HandleId object_id,
                                                  HRESULT          original_result,
                                                  D3D12_FEATURE    feature,
                                                  const void*      capture_feature_data,
                                                  void*            replay_feature_data,
                                                  UINT             feature_data_size) override;

    /// Data must be extracted from the void pointer depending on the value of feature.
    void Process_IDXGIFactory5_CheckFeatureSupport(format::HandleId object_id,
                                                   HRESULT          original_result,
                                                   DXGI_FEATURE     feature,
                                                   const void*      capture_feature_data,
                                                   void*            replay_feature_data,
                                                   UINT             feature_data_size) override;

    /// This is only custom because codegen gives pSrcData type uint64_t instead of void*.
    /// <https://github.com/LunarG/gfxreconstruct/issues/1369>
    virtual void Process_ID3D12Resource_WriteToSubresource(format::HandleId                         object_id,
                                                           HRESULT                                  original_result,
                                                           UINT                                     DstSubresource,
                                                           StructPointerDecoder<Decoded_D3D12_BOX>* pDstBox,
                                                           void*                                    pSrcData,
                                                           UINT                                     SrcRowPitch,
                                                           UINT SrcDepthPitch) override;
    /// @}
  protected:
    JsonWriter* writer_{ nullptr };
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_DX12_JSON_CONSUMER_BASE_H
