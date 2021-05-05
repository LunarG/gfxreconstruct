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

#include "decode/custom_dx12_struct_object_mappers.h"

#include "decode/custom_dx12_struct_decoders.h"
#include "decode/dx12_object_mapping_util.h"
#include "generated/generated_dx12_struct_object_mappers.h"
#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

template <typename Handle, typename Function>
void MapDescriptorStructObjects(Handle*                    wrapper,
                                const Dx12ObjectInfoTable& object_info_table,
                                const util::GpuVaMap&      gpu_va_map,
                                Function                   get_begin_addr)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        auto entry = object_info_table.find(wrapper->heap_id);
        if (entry != object_info_table.end())
        {
            auto  index     = wrapper->index;
            auto  value     = wrapper->decoded_value;
            auto& info      = entry->second;
            auto  heap_info = reinterpret_cast<D3D12DescriptorHeapInfo*>(info.extra_info);

            value->ptr = get_begin_addr(heap_info);
            if (index > 0)
            {
                auto offset = (*heap_info->replay_increments)[heap_info->descriptor_type] * index;
                value->ptr += offset;
            }
        }
    }
}

void MapStructObjects(Decoded_D3D12_CPU_DESCRIPTOR_HANDLE* wrapper,
                      const Dx12ObjectInfoTable&           object_info_table,
                      const util::GpuVaMap&                gpu_va_map)
{
    MapDescriptorStructObjects(wrapper, object_info_table, gpu_va_map, [](const D3D12DescriptorHeapInfo* info) {
        return info->replay_cpu_addr_begin;
    });
}

void MapStructObjects(Decoded_D3D12_GPU_DESCRIPTOR_HANDLE* wrapper,
                      const Dx12ObjectInfoTable&           object_info_table,
                      const util::GpuVaMap&                gpu_va_map)
{
    MapDescriptorStructObjects(wrapper, object_info_table, gpu_va_map, [](const D3D12DescriptorHeapInfo* info) {
        return info->replay_gpu_addr_begin;
    });
}

void MapStructObjects(Decoded_D3D12_RESOURCE_BARRIER* wrapper,
                      const Dx12ObjectInfoTable&      object_info_table,
                      const util::GpuVaMap&           gpu_va_map)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        auto value = wrapper->decoded_value;

        switch (value->Type)
        {
            case D3D12_RESOURCE_BARRIER_TYPE_TRANSITION:
                MapStructObjects(wrapper->Transition, object_info_table, gpu_va_map);
                break;
            case D3D12_RESOURCE_BARRIER_TYPE_ALIASING:
                MapStructObjects(wrapper->Aliasing, object_info_table, gpu_va_map);
                break;
            case D3D12_RESOURCE_BARRIER_TYPE_UAV:
                MapStructObjects(wrapper->UAV, object_info_table, gpu_va_map);
                break;
            default:
                break;
        }
    }
}

void MapStructObjects(Decoded_D3D12_TEXTURE_COPY_LOCATION* wrapper,
                      const Dx12ObjectInfoTable&           object_info_table,
                      const util::GpuVaMap&                gpu_va_map)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        auto value = wrapper->decoded_value;

        value->pResource = object_mapping::MapObject<ID3D12Resource>(wrapper->pResource, object_info_table);
    }
}

void MapStructObjects(Decoded_D3D12_RAYTRACING_GEOMETRY_DESC* wrapper,
                      const Dx12ObjectInfoTable&              object_info_table,
                      const util::GpuVaMap&                   gpu_va_map)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        auto value = wrapper->decoded_value;

        switch (value->Type)
        {
            case D3D12_RAYTRACING_GEOMETRY_TYPE_TRIANGLES:
                MapStructObjects(wrapper->Triangles, object_info_table, gpu_va_map);
                break;
            case D3D12_RAYTRACING_GEOMETRY_TYPE_PROCEDURAL_PRIMITIVE_AABBS:
                MapStructObjects(wrapper->AABBs, object_info_table, gpu_va_map);
                break;
            default:
                break;
        }
    }
}

void MapStructObjects(Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS* wrapper,
                      const Dx12ObjectInfoTable&                                    object_info_table,
                      const util::GpuVaMap&                                         gpu_va_map)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        auto value = wrapper->decoded_value;

        switch (value->Type)
        {
            case D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL:
                object_mapping::MapGpuVirtualAddress(value->InstanceDescs, gpu_va_map);
                break;
            case D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE_BOTTOM_LEVEL:
                switch (value->DescsLayout)
                {
                    case D3D12_ELEMENTS_LAYOUT_ARRAY:
                        MapStructArrayObjects(wrapper->pGeometryDescs->GetMetaStructPointer(),
                                              wrapper->pGeometryDescs->GetLength(),
                                              object_info_table,
                                              gpu_va_map);
                        break;
                    case D3D12_ELEMENTS_LAYOUT_ARRAY_OF_POINTERS:
                    {
                        auto descs     = wrapper->ppGeometryDescs->GetMetaStructPointer();
                        auto num_descs = wrapper->ppGeometryDescs->GetLength();

                        for (size_t i = 0; i < num_descs; ++i)
                        {
                            MapStructObjects(descs[i], object_info_table, gpu_va_map);
                        }

                        break;
                    }
                    default:
                        break;
                }
                break;
            default:
                break;
        }
    }
}

void MapStructObjects(Decoded_D3D12_RENDER_PASS_ENDING_ACCESS* wrapper,
                      const Dx12ObjectInfoTable&               object_info_table,
                      const util::GpuVaMap&                    gpu_va_map)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        auto value = wrapper->decoded_value;

        switch (value->Type)
        {
            case D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_RESOLVE:
                MapStructObjects(wrapper->Resolve, object_info_table, gpu_va_map);
                break;
            default:
                break;
        }
    }
}

void MapStructObjects(Decoded_D3D12_PIPELINE_STATE_STREAM_DESC* wrapper,
                      const Dx12ObjectInfoTable&                object_info_table,
                      const util::GpuVaMap&                     gpu_va_map)
{
    if ((wrapper != nullptr) && (wrapper->root_signature_ptr != nullptr))
    {
        (*wrapper->root_signature_ptr) =
            object_mapping::MapObject<ID3D12RootSignature>(wrapper->root_signature, object_info_table);
    }
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
