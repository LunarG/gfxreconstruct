/*
** Copyright (c) 2021-2023 LunarG, Inc.
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

/*
** This file is generated from dx12_struct_object_mappers_header_generator.py.
**
*/

#include "format/platform_types.h"
#include "generated/generated_dx12_struct_decoders_forward.h"
#include "decode/dx12_replay_consumer_base.h"
#include "graphics/dx12_gpu_va_map.h"
#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void MapStructObjects(Decoded_D3D12_GRAPHICS_PIPELINE_STATE_DESC* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map);

void MapStructObjects(Decoded_D3D12_COMPUTE_PIPELINE_STATE_DESC* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map);

void MapStructObjects(Decoded_D3D12_RESOURCE_TRANSITION_BARRIER* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map);

void MapStructObjects(Decoded_D3D12_RESOURCE_ALIASING_BARRIER* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map);

void MapStructObjects(Decoded_D3D12_RESOURCE_UAV_BARRIER* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map);

void MapStructObjects(Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_SRV* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map);

void MapStructObjects(Decoded_D3D12_CONSTANT_BUFFER_VIEW_DESC* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map);

void MapStructObjects(Decoded_D3D12_STREAM_OUTPUT_BUFFER_VIEW* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map);

void MapStructObjects(Decoded_D3D12_VERTEX_BUFFER_VIEW* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map);

void MapStructObjects(Decoded_D3D12_INDEX_BUFFER_VIEW* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map);

void MapStructObjects(Decoded_D3D12_WRITEBUFFERIMMEDIATE_PARAMETER* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map);

void MapStructObjects(Decoded_D3D12_GLOBAL_ROOT_SIGNATURE* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map);

void MapStructObjects(Decoded_D3D12_LOCAL_ROOT_SIGNATURE* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map);

void MapStructObjects(Decoded_D3D12_EXISTING_COLLECTION_DESC* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map);

void MapStructObjects(Decoded_D3D12_GENERIC_PROGRAM_DESC* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map);

void MapStructObjects(Decoded_D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map);

void MapStructObjects(Decoded_D3D12_GPU_VIRTUAL_ADDRESS_RANGE* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map);

void MapStructObjects(Decoded_D3D12_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map);

void MapStructObjects(Decoded_D3D12_RAYTRACING_GEOMETRY_TRIANGLES_DESC* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map);

void MapStructObjects(Decoded_D3D12_RAYTRACING_GEOMETRY_AABBS_DESC* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map);

void MapStructObjects(Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map);

void MapStructObjects(Decoded_D3D12_RAYTRACING_INSTANCE_DESC* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map);

void MapStructObjects(Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map);

void MapStructObjects(Decoded_D3D12_AUTO_BREADCRUMB_NODE* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map);

void MapStructObjects(Decoded_D3D12_AUTO_BREADCRUMB_NODE1* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map);

void MapStructObjects(Decoded_D3D12_DRED_ALLOCATION_NODE1* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map);

void MapStructObjects(Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map);

void MapStructObjects(Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT1* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map);

void MapStructObjects(Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT2* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map);

void MapStructObjects(Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA1* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map);

void MapStructObjects(Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA2* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map);

void MapStructObjects(Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA3* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map);

void MapStructObjects(Decoded_D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map);

void MapStructObjects(Decoded_D3D12_RENDER_PASS_RENDER_TARGET_DESC* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map);

void MapStructObjects(Decoded_D3D12_RENDER_PASS_DEPTH_STENCIL_DESC* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map);

void MapStructObjects(Decoded_D3D12_DISPATCH_RAYS_DESC* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map);

void MapStructObjects(Decoded_D3D12_SET_WORK_GRAPH_DESC* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map);

void MapStructObjects(Decoded_D3D12_NODE_GPU_INPUT* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map);

void MapStructObjects(Decoded_D3D12_MULTI_NODE_GPU_INPUT* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map);

void MapStructObjects(Decoded_D3D12_TEXTURE_BARRIER* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map);

void MapStructObjects(Decoded_D3D12_BUFFER_BARRIER* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map);

void AddStructObjects(const StructPointerDecoder<Decoded_D3D12_GRAPHICS_PIPELINE_STATE_DESC>* capture_value, const D3D12_GRAPHICS_PIPELINE_STATE_DESC* new_value, Dx12ObjectInfoTable& object_info_table);

void AddStructObjects(const StructPointerDecoder<Decoded_D3D12_COMPUTE_PIPELINE_STATE_DESC>* capture_value, const D3D12_COMPUTE_PIPELINE_STATE_DESC* new_value, Dx12ObjectInfoTable& object_info_table);

void AddStructObjects(const StructPointerDecoder<Decoded_D3D12_RESOURCE_TRANSITION_BARRIER>* capture_value, const D3D12_RESOURCE_TRANSITION_BARRIER* new_value, Dx12ObjectInfoTable& object_info_table);

void AddStructObjects(const StructPointerDecoder<Decoded_D3D12_RESOURCE_ALIASING_BARRIER>* capture_value, const D3D12_RESOURCE_ALIASING_BARRIER* new_value, Dx12ObjectInfoTable& object_info_table);

void AddStructObjects(const StructPointerDecoder<Decoded_D3D12_RESOURCE_UAV_BARRIER>* capture_value, const D3D12_RESOURCE_UAV_BARRIER* new_value, Dx12ObjectInfoTable& object_info_table);

void AddStructObjects(const StructPointerDecoder<Decoded_D3D12_GLOBAL_ROOT_SIGNATURE>* capture_value, const D3D12_GLOBAL_ROOT_SIGNATURE* new_value, Dx12ObjectInfoTable& object_info_table);

void AddStructObjects(const StructPointerDecoder<Decoded_D3D12_LOCAL_ROOT_SIGNATURE>* capture_value, const D3D12_LOCAL_ROOT_SIGNATURE* new_value, Dx12ObjectInfoTable& object_info_table);

void AddStructObjects(const StructPointerDecoder<Decoded_D3D12_EXISTING_COLLECTION_DESC>* capture_value, const D3D12_EXISTING_COLLECTION_DESC* new_value, Dx12ObjectInfoTable& object_info_table);

void AddStructObjects(const StructPointerDecoder<Decoded_D3D12_AUTO_BREADCRUMB_NODE>* capture_value, const D3D12_AUTO_BREADCRUMB_NODE* new_value, Dx12ObjectInfoTable& object_info_table);

void AddStructObjects(const StructPointerDecoder<Decoded_D3D12_AUTO_BREADCRUMB_NODE1>* capture_value, const D3D12_AUTO_BREADCRUMB_NODE1* new_value, Dx12ObjectInfoTable& object_info_table);

void AddStructObjects(const StructPointerDecoder<Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA>* capture_value, const D3D12_DEVICE_REMOVED_EXTENDED_DATA* new_value, Dx12ObjectInfoTable& object_info_table);

void AddStructObjects(const StructPointerDecoder<Decoded_D3D12_DRED_ALLOCATION_NODE1>* capture_value, const D3D12_DRED_ALLOCATION_NODE1* new_value, Dx12ObjectInfoTable& object_info_table);

void AddStructObjects(const StructPointerDecoder<Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT>* capture_value, const D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT* new_value, Dx12ObjectInfoTable& object_info_table);

void AddStructObjects(const StructPointerDecoder<Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1>* capture_value, const D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1* new_value, Dx12ObjectInfoTable& object_info_table);

void AddStructObjects(const StructPointerDecoder<Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT1>* capture_value, const D3D12_DRED_PAGE_FAULT_OUTPUT1* new_value, Dx12ObjectInfoTable& object_info_table);

void AddStructObjects(const StructPointerDecoder<Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT2>* capture_value, const D3D12_DRED_PAGE_FAULT_OUTPUT2* new_value, Dx12ObjectInfoTable& object_info_table);

void AddStructObjects(const StructPointerDecoder<Decoded_D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS>* capture_value, const D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS* new_value, Dx12ObjectInfoTable& object_info_table);

void AddStructObjects(const StructPointerDecoder<Decoded_D3D12_TEXTURE_BARRIER>* capture_value, const D3D12_TEXTURE_BARRIER* new_value, Dx12ObjectInfoTable& object_info_table);

void AddStructObjects(const StructPointerDecoder<Decoded_D3D12_BUFFER_BARRIER>* capture_value, const D3D12_BUFFER_BARRIER* new_value, Dx12ObjectInfoTable& object_info_table);


template <typename T>
void MapStructArrayObjects(T* structs, size_t len, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map)
{
    if (structs != nullptr)
    {
        for (size_t i = 0; i < len; ++i)
        {
            MapStructObjects(&structs[i], object_info_table, gpu_va_map);
        }
    }
}

template <typename T>
void AddStructArrayObjects(format::HandleId parent_id, const T* id_wrappers, size_t id_len, const typename T::struct_type* handle_structs, size_t handle_len, Dx12ObjectInfoTable* object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map)
{
    if (id_wrappers != nullptr && handle_structs != nullptr)
    {
        // TODO: Improved handling of array size mismatch.
        size_t len = std::min(id_len, handle_len);
        for (size_t i = 0; i < len; ++i)
        {
            AddStructObjects(parent_id, &id_wrappers[i], &handle_structs[i], object_info_table);
        }
    }
}

template <typename T>
void SetStructArrayObjectLengths(T* wrappers, size_t len)
{
    if (wrappers != nullptr)
    {
        for (size_t i = 0; i < len; ++i)
        {
            SetStructObjectLengths(&wrappers[i]);
        }
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
