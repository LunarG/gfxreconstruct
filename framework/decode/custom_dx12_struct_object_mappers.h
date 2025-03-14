/*
** Copyright (c) 2021 LunarG, Inc.
**
** Permission is hereby granted, free of charge, to any person obtaining a copy
** of this software and associated documentation files (the "Software"), to
** deal in the Software without restriction, including without limitation the
** rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
** sell copies of the Software, and to permit persons to whom the Software is
** furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in
** all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
** IN THE SOFTWARE.
*/

#ifndef GFXRECON_DECODE_CUSTOM_DX12_STRUCT_OBJECT_MAPPERS_H
#define GFXRECON_DECODE_CUSTOM_DX12_STRUCT_OBJECT_MAPPERS_H

#include "decode/custom_dx12_struct_decoders_forward.h"
#include "decode/dx12_object_mapping_util.h"
#include "decode/struct_pointer_decoder.h"
#include "graphics/dx12_gpu_va_map.h"
#include "util/defines.h"

#include <d3d12.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

// Structs with descriptor handles.
void MapStructObjects(Decoded_D3D12_CPU_DESCRIPTOR_HANDLE* wrapper,
                      const Dx12ObjectInfoTable&           object_info_table,
                      const graphics::Dx12GpuVaMap&        gpu_va_map);

void MapStructObjects(Decoded_D3D12_GPU_DESCRIPTOR_HANDLE* wrapper,
                      const Dx12ObjectInfoTable&           object_info_table,
                      const graphics::Dx12GpuVaMap&        gpu_va_map);

// Structs with anonymous union members.
void MapStructObjects(Decoded_D3D12_RESOURCE_BARRIER* wrapper,
                      const Dx12ObjectInfoTable&      object_info_table,
                      const graphics::Dx12GpuVaMap&   gpu_va_map);

void MapStructObjects(Decoded_D3D12_TEXTURE_COPY_LOCATION* wrapper,
                      const Dx12ObjectInfoTable&           object_info_table,
                      const graphics::Dx12GpuVaMap&        gpu_va_map);

void MapStructObjects(Decoded_D3D12_RAYTRACING_GEOMETRY_DESC* wrapper,
                      const Dx12ObjectInfoTable&              object_info_table,
                      const graphics::Dx12GpuVaMap&           gpu_va_map);

void MapStructObjects(Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS* wrapper,
                      const Dx12ObjectInfoTable&                                    object_info_table,
                      const graphics::Dx12GpuVaMap&                                 gpu_va_map);

void MapStructObjects(Decoded_D3D12_RENDER_PASS_ENDING_ACCESS* wrapper,
                      const Dx12ObjectInfoTable&               object_info_table,
                      const graphics::Dx12GpuVaMap&            gpu_va_map);

void MapStructObjects(Decoded_D3D12_PIPELINE_STATE_STREAM_DESC* wrapper,
                      const Dx12ObjectInfoTable&                object_info_table,
                      const graphics::Dx12GpuVaMap&             gpu_va_map);

void MapStructObjects(Decoded_D3D12_STATE_OBJECT_DESC* wrapper,
                      const Dx12ObjectInfoTable&       object_info_table,
                      const graphics::Dx12GpuVaMap&    gpu_va_map);

void MapStructObjects(Decoded_D3D12_STATE_SUBOBJECT*                       wrapper,
                      StructPointerDecoder<Decoded_D3D12_STATE_SUBOBJECT>* subobjects,
                      size_t                                               subobject_stride,
                      const Dx12ObjectInfoTable&                           object_info_table,
                      const graphics::Dx12GpuVaMap&                        gpu_va_map);

void MapStructObjects(Decoded_D3D12_SUBOBJECT_TO_EXPORTS_ASSOCIATION*      wrapper,
                      StructPointerDecoder<Decoded_D3D12_STATE_SUBOBJECT>* subobjects,
                      size_t                                               subobject_stride,
                      const Dx12ObjectInfoTable&                           object_info_table,
                      const graphics::Dx12GpuVaMap&                        gpu_va_map);

void MapStructObjects(Decoded_D3D12_SHADER_RESOURCE_VIEW_DESC* wrapper,
                      const Dx12ObjectInfoTable&               object_info_table,
                      const graphics::Dx12GpuVaMap&            gpu_va_map);

void MapStructObjects(Decoded_D3D12_BARRIER_GROUP*  wrapper,
                      const Dx12ObjectInfoTable&    object_info_table,
                      const graphics::Dx12GpuVaMap& gpu_va_map);

void MapStructObjects(Decoded_D3D12_SET_PROGRAM_DESC* wrapper,
                      const Dx12ObjectInfoTable&      object_info_table,
                      const graphics::Dx12GpuVaMap&   gpu_va_map);

void MapStructObjects(Decoded_D3D12_DISPATCH_GRAPH_DESC* wrapper,
                      const Dx12ObjectInfoTable&         object_info_table,
                      const graphics::Dx12GpuVaMap&      gpu_va_map);

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_CUSTOM_DX12_STRUCT_OBJECT_MAPPERS_H
