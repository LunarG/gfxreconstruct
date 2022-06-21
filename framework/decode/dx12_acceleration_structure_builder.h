/*
** Copyright (c) 2022 LunarG, Inc.
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

#ifndef GFXRECON_DECODE_DX12_ACCELERATION_STRUCTURE_BUILDER_H
#define GFXRECON_DECODE_DX12_ACCELERATION_STRUCTURE_BUILDER_H

#include "graphics/dx12_gpu_va_map.h"
#include "graphics/dx12_util.h"
#include "format/format.h"
#include "util/defines.h"

#include <d3d12.h>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class Dx12AccelerationStructureBuilder
{
  public:
    Dx12AccelerationStructureBuilder(graphics::dx12::ID3D12Device5ComPtr device5);

    virtual ~Dx12AccelerationStructureBuilder() {}

    void Build(const graphics::Dx12GpuVaMap&                                         gpu_va_map,
               const format::InitDx12AccelerationStructureCommandHeader&             command_header,
               const std::vector<format::InitDx12AccelerationStructureGeometryDesc>& init_geometry_descs,
               const uint8_t*                                                        build_inputs_data);

  private:
    void SetupBuild(const graphics::Dx12GpuVaMap&                                         gpu_va_map,
                    const format::InitDx12AccelerationStructureCommandHeader&             command_header,
                    const std::vector<format::InitDx12AccelerationStructureGeometryDesc>& init_geometry_descs,
                    const uint8_t*                                                        build_inputs_data,
                    D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC&                   build_desc,
                    bool                                                                  use_temp_dest_buffer);

    void ExecuteBuild(const graphics::Dx12GpuVaMap&                       gpu_va_map,
                      D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC& build_desc);

    void ExecuteCopy(D3D12_GPU_VIRTUAL_ADDRESS                         dest_gpu_va,
                     D3D12_GPU_VIRTUAL_ADDRESS                         source_gpu_va,
                     D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE mode);

  private:
    graphics::dx12::ID3D12Device5ComPtr              device5_;
    graphics::dx12::ID3D12CommandQueueComPtr         command_queue_;
    graphics::dx12::ID3D12CommandAllocatorComPtr     command_allocator_;
    graphics::dx12::ID3D12GraphicsCommandList4ComPtr command_list4_;
    graphics::dx12::ID3D12ResourceComPtr             inputs_buffer_;
    graphics::dx12::ID3D12FenceComPtr                fence_;
    uint64_t                                         inputs_buffer_size_;
    graphics::dx12::ID3D12ResourceComPtr             scratch_buffer_;
    uint64_t                                         scratch_buffer_size_;
    graphics::dx12::ID3D12ResourceComPtr             temp_dest_buffer_;
    uint64_t                                         temp_dest_buffer_size_;
    uint64_t                                         fence_value_;

    std::vector<D3D12_RAYTRACING_GEOMETRY_DESC> temp_geometry_descs_;
    std::vector<uint8_t>                        temp_instance_desc_input_data_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_DX12_ACCELERATION_STRUCTURE_BUILDER_H
