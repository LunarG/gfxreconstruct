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
#include "generated/generated_dx12_struct_object_mappers.h"
#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

template <typename Handle, typename Function>
void MapDescriptorStructObjects(Handle*                       wrapper,
                                const Dx12ObjectInfoTable&    object_info_table,
                                const graphics::Dx12GpuVaMap& gpu_va_map,
                                Function                      get_begin_addr)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        auto entry = object_info_table.find(wrapper->heap_id);
        if (entry != object_info_table.end())
        {
            auto  index     = wrapper->index;
            auto  value     = wrapper->decoded_value;
            auto& info      = entry->second;
            auto  heap_info = reinterpret_cast<D3D12DescriptorHeapInfo*>(info.extra_info.get());
            assert(heap_info->extra_info_type == DxObjectInfoType::kID3D12DescriptorHeapInfo);

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
                      const graphics::Dx12GpuVaMap&        gpu_va_map)
{
    MapDescriptorStructObjects(wrapper, object_info_table, gpu_va_map, [](const D3D12DescriptorHeapInfo* info) {
        return info->replay_cpu_addr_begin;
    });
}

void MapStructObjects(Decoded_D3D12_RESOURCE_BARRIER* wrapper,
                      const Dx12ObjectInfoTable&      object_info_table,
                      const graphics::Dx12GpuVaMap&   gpu_va_map)
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
                      const graphics::Dx12GpuVaMap&        gpu_va_map)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        auto value = wrapper->decoded_value;

        value->pResource = object_mapping::MapObject<ID3D12Resource>(wrapper->pResource, object_info_table);
    }
}

void MapStructObjects(Decoded_D3D12_RAYTRACING_GEOMETRY_DESC* wrapper,
                      const Dx12ObjectInfoTable&              object_info_table,
                      const graphics::Dx12GpuVaMap&           gpu_va_map)
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
                      const graphics::Dx12GpuVaMap&                                 gpu_va_map)
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
                      const graphics::Dx12GpuVaMap&            gpu_va_map)
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
                      const graphics::Dx12GpuVaMap&             gpu_va_map)
{
    if ((wrapper != nullptr) && (wrapper->root_signature_ptr != nullptr))
    {
        (*wrapper->root_signature_ptr) =
            object_mapping::MapObject<ID3D12RootSignature>(wrapper->root_signature, object_info_table);
    }
}

void MapStructObjects(Decoded_D3D12_STATE_OBJECT_DESC* wrapper,
                      const Dx12ObjectInfoTable&       object_info_table,
                      const graphics::Dx12GpuVaMap&    gpu_va_map)
{
    if (wrapper != nullptr)
    {
        auto length   = wrapper->pSubobjects->GetLength();
        auto wrappers = wrapper->pSubobjects->GetMetaStructPointer();

        for (size_t i = 0; i < length; ++i)
        {
            MapStructObjects(
                &wrappers[i], wrapper->pSubobjects, wrapper->subobject_stride, object_info_table, gpu_va_map);
        }
    }
}

void MapStructObjects(Decoded_D3D12_STATE_SUBOBJECT*                       wrapper,
                      StructPointerDecoder<Decoded_D3D12_STATE_SUBOBJECT>* subobjects,
                      size_t                                               subobject_stride,
                      const Dx12ObjectInfoTable&                           object_info_table,
                      const graphics::Dx12GpuVaMap&                        gpu_va_map)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        auto value = wrapper->decoded_value;

        switch (value->Type)
        {
            case D3D12_STATE_SUBOBJECT_TYPE_STATE_OBJECT_CONFIG:
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_GLOBAL_ROOT_SIGNATURE:
                MapStructObjects(wrapper->global_root_signature->GetMetaStructPointer(), object_info_table, gpu_va_map);
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_LOCAL_ROOT_SIGNATURE:
                MapStructObjects(wrapper->local_root_signature->GetMetaStructPointer(), object_info_table, gpu_va_map);
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_NODE_MASK:
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_DXIL_LIBRARY:
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_EXISTING_COLLECTION:
                MapStructObjects(
                    wrapper->existing_collection_desc->GetMetaStructPointer(), object_info_table, gpu_va_map);
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_SUBOBJECT_TO_EXPORTS_ASSOCIATION:
                MapStructObjects(wrapper->subobject_to_exports_association->GetMetaStructPointer(),
                                 subobjects,
                                 subobject_stride,
                                 object_info_table,
                                 gpu_va_map);
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_DXIL_SUBOBJECT_TO_EXPORTS_ASSOCIATION:
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_RAYTRACING_SHADER_CONFIG:
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_RAYTRACING_PIPELINE_CONFIG:
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_HIT_GROUP:
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_RAYTRACING_PIPELINE_CONFIG1:
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_WORK_GRAPH:
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_STREAM_OUTPUT:
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_BLEND:
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_SAMPLE_MASK:
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_RASTERIZER:
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_DEPTH_STENCIL:
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_INPUT_LAYOUT:
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_IB_STRIP_CUT_VALUE:
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_PRIMITIVE_TOPOLOGY:
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_RENDER_TARGET_FORMATS:
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_DEPTH_STENCIL_FORMAT:
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_SAMPLE_DESC:
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_FLAGS:
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_DEPTH_STENCIL1:
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_VIEW_INSTANCING:
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_GENERIC_PROGRAM:
                MapStructObjects(wrapper->generic_program_desc->GetMetaStructPointer(),
                                 subobjects,
                                 subobject_stride,
                                 object_info_table,
                                 gpu_va_map);
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_DEPTH_STENCIL2:
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_MAX_VALID:
                break;
            default:
                break;
        }
    }
}

void MapStructObjects(Decoded_D3D12_SUBOBJECT_TO_EXPORTS_ASSOCIATION*      wrapper,
                      StructPointerDecoder<Decoded_D3D12_STATE_SUBOBJECT>* subobjects,
                      size_t                                               subobject_stride,
                      const Dx12ObjectInfoTable&                           object_info_table,
                      const graphics::Dx12GpuVaMap&                        gpu_va_map)
{
    if (wrapper != nullptr)
    {
        assert(wrapper->pSubobjectToAssociate->HasAddress() && (subobjects != nullptr) && subobjects->HasAddress());

        // This may be a pointer to an existing subobject structure.
        auto subobject_address = wrapper->pSubobjectToAssociate->GetAddress();
        auto subobject_array   = subobjects->GetPointer();
        auto base_address      = subobjects->GetAddress();
        auto num_subobjects    = subobjects->GetLength();

        for (UINT i = 0; i < num_subobjects; ++i)
        {
            if (subobject_address == (base_address + (subobject_stride * i)))
            {
                // Point to the existing struct value.
                auto value                   = wrapper->decoded_value;
                value->pSubobjectToAssociate = &subobject_array[i];
                return;
            }
        }

        // The subobject was not found in the list of existing subobjects, so fall back on standard object mapping.
        MapStructObjects(wrapper->pSubobjectToAssociate->GetMetaStructPointer(),
                         subobjects,
                         subobject_stride,
                         object_info_table,
                         gpu_va_map);
    }
}

void MapStructObjects(Decoded_D3D12_GENERIC_PROGRAM_DESC*                  wrapper,
                      StructPointerDecoder<Decoded_D3D12_STATE_SUBOBJECT>* subobjects,
                      size_t                                               subobject_stride,
                      const Dx12ObjectInfoTable&                           object_info_table,
                      const graphics::Dx12GpuVaMap&                        gpu_va_map)
{
    if (wrapper != nullptr)
    {
        auto descs     = wrapper->ppSubobjects->GetMetaStructPointer();
        auto num_descs = wrapper->ppSubobjects->GetLength();

        for (size_t i = 0; i < num_descs; ++i)
        {
            MapStructObjects(descs[i], subobjects, subobject_stride, object_info_table, gpu_va_map);
        }
    }
}

void MapStructObjects(Decoded_D3D12_SHADER_RESOURCE_VIEW_DESC* wrapper,
                      const Dx12ObjectInfoTable&               object_info_table,
                      const graphics::Dx12GpuVaMap&            gpu_va_map)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        auto value = wrapper->decoded_value;

        switch (value->ViewDimension)
        {
            case D3D12_SRV_DIMENSION_RAYTRACING_ACCELERATION_STRUCTURE:
                MapStructObjects(wrapper->RaytracingAccelerationStructure, object_info_table, gpu_va_map);
                break;
            default:
                break;
        }
    }
}

void MapStructObjects(Decoded_D3D12_BARRIER_GROUP*  wrapper,
                      const Dx12ObjectInfoTable&    object_info_table,
                      const graphics::Dx12GpuVaMap& gpu_va_map)
{
    if (wrapper != nullptr)
    {
        auto length   = wrapper->texture_barriers->GetLength();
        auto wrappers = wrapper->texture_barriers->GetMetaStructPointer();

        for (size_t i = 0; i < length; ++i)
        {
            MapStructObjects(&wrappers[i], object_info_table, gpu_va_map);
        }
    }
}

void MapStructObjects(Decoded_D3D12_SET_PROGRAM_DESC* wrapper,
                      const Dx12ObjectInfoTable&      object_info_table,
                      const graphics::Dx12GpuVaMap&   gpu_va_map)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        auto value = wrapper->decoded_value;

        switch (value->Type)
        {
            case D3D12_PROGRAM_TYPE_GENERIC_PIPELINE:
                break;
            case D3D12_PROGRAM_TYPE_RAYTRACING_PIPELINE:
                break;
            case D3D12_PROGRAM_TYPE_WORK_GRAPH:
                MapStructObjects(wrapper->work_graph, object_info_table, gpu_va_map);
                break;
            default:
                break;
        }
    }
}

void MapStructObjects(Decoded_D3D12_DISPATCH_GRAPH_DESC* wrapper,
                      const Dx12ObjectInfoTable&         object_info_table,
                      const graphics::Dx12GpuVaMap&      gpu_va_map)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        auto value = wrapper->decoded_value;

        switch (value->Mode)
        {
            case D3D12_DISPATCH_MODE_NODE_CPU_INPUT:
                break;
            case D3D12_DISPATCH_MODE_NODE_GPU_INPUT:
                object_mapping::MapGpuVirtualAddress(value->NodeGPUInput, gpu_va_map);
                break;
            case D3D12_DISPATCH_MODE_MULTI_NODE_CPU_INPUT:
                break;
            case D3D12_DISPATCH_MODE_MULTI_NODE_GPU_INPUT:
                object_mapping::MapGpuVirtualAddress(value->MultiNodeGPUInput, gpu_va_map);
                break;
            default:
                break;
        }
    }
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
