/*
** Copyright (c) 2023 LunarG, Inc.
** Copyright (c) 2023 Advanced Micro Devices, Inc. All rights reserved.
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

#ifndef GFXRECON_ENCODE_DX12_RV_ANNOTATOR_H
#define GFXRECON_ENCODE_DX12_RV_ANNOTATOR_H

#include "util/defines.h"
#include "generated/generated_dx12_wrappers.h"

#include "graphics/dx12_shader_id_map.h"

#include <d3d12.h>
#include <map>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

class Dx12ResourceValueAnnotator
{
  public:
    void RemoveObjectGPUVA(IUnknown_Wrapper* resource_wrapper);
    void AddNewRangeofGPUVA(uint64_t start_address, uint64_t end_address);
    void AddDescriptorHandleStart(ID3D12DescriptorHeap_Wrapper* wrapper, D3D12_GPU_DESCRIPTOR_HANDLE result);
    void SetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE type, uint8_t increment_size);
    void AddShaderID(graphics::Dx12ShaderIdentifier shader_id);
    void RemoveGPUVA(D3D12_GPU_VIRTUAL_ADDRESS start_address);
    bool IsValidGpuVa(D3D12_GPU_VIRTUAL_ADDRESS address);
    bool IsValidGPUDescriptorHandle(D3D12_GPU_DESCRIPTOR_HANDLE handle);
    bool MatchShaderIdentifier(const uint8_t* data);

    void PostProcessGetGPUVirtualAddress(ID3D12Resource_Wrapper* wrapper, D3D12_GPU_VIRTUAL_ADDRESS result);

    void ScanForGPUVA(uint64_t memory_id, uint8_t* data, uint64_t size, uint64_t offset);

    bool RestoreForGPUVA(uint64_t memory_id, uint8_t* data, uint64_t size, uint64_t offset);

    struct Dx12FillCommandResourceValue
    {
        uint64_t                                                   offset;
        format::ResourceValueType                                  type;
        std::array<uint8_t, D3D12_SHADER_IDENTIFIER_SIZE_IN_BYTES> value;
    };

  private:
    std::map<uint64_t, uint64_t, std::greater<uint64_t>> gpuva_map_;
    uint64_t                                             low_gpuva{ 0 };
    uint64_t                                             high_gpuva{ 0 };
    std::map<uint64_t, D3D12_DESCRIPTOR_HEAP_DESC>       descriptor_map_;
    uint64_t                                             low_handle{ 0 };
    uint64_t                                             high_handle{ 0 };
    std::map<D3D12_DESCRIPTOR_HEAP_TYPE, uint8_t>        increment_size_;

    std::set<graphics::Dx12ShaderIdentifier> shader_ids_;

    std::map<uint64_t, std::map<uint64_t, Dx12FillCommandResourceValue>> resource_values_map_;
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif GFXRECON_ENCODE_DX12_RV_ANNOTATOR_H
