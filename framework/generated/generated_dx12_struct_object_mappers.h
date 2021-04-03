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

/*
** This file is generated from dx12_struct_object_mappers_header_generator.py.
**
*/

#include "format/platform_types.h"
#include "generated/generated_dx12_struct_decoders_forward.h"
#include "decode/dx12_replay_consumer_base.h"
#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void MapStructObjects(Decoded_D3D12_GRAPHICS_PIPELINE_STATE_DESC* wrapper, const Dx12ObjectInfoTable& object_info_table);

void MapStructObjects(Decoded_D3D12_COMPUTE_PIPELINE_STATE_DESC* wrapper, const Dx12ObjectInfoTable& object_info_table);

void MapStructObjects(Decoded_D3D12_RESOURCE_TRANSITION_BARRIER* wrapper, const Dx12ObjectInfoTable& object_info_table);

void MapStructObjects(Decoded_D3D12_RESOURCE_ALIASING_BARRIER* wrapper, const Dx12ObjectInfoTable& object_info_table);

void MapStructObjects(Decoded_D3D12_RESOURCE_UAV_BARRIER* wrapper, const Dx12ObjectInfoTable& object_info_table);

void MapStructObjects(Decoded_D3D12_GLOBAL_ROOT_SIGNATURE* wrapper, const Dx12ObjectInfoTable& object_info_table);

void MapStructObjects(Decoded_D3D12_LOCAL_ROOT_SIGNATURE* wrapper, const Dx12ObjectInfoTable& object_info_table);

void MapStructObjects(Decoded_D3D12_EXISTING_COLLECTION_DESC* wrapper, const Dx12ObjectInfoTable& object_info_table);

void MapStructObjects(Decoded_D3D12_AUTO_BREADCRUMB_NODE* wrapper, const Dx12ObjectInfoTable& object_info_table);

void MapStructObjects(Decoded_D3D12_AUTO_BREADCRUMB_NODE1* wrapper, const Dx12ObjectInfoTable& object_info_table);

void MapStructObjects(Decoded_D3D12_DRED_ALLOCATION_NODE1* wrapper, const Dx12ObjectInfoTable& object_info_table);

void MapStructObjects(Decoded_D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS* wrapper, const Dx12ObjectInfoTable& object_info_table);

void MapStructObjects(Decoded_D3D12_RENDER_PASS_RENDER_TARGET_DESC* wrapper, const Dx12ObjectInfoTable& object_info_table);

void MapStructObjects(Decoded_D3D12_RENDER_PASS_DEPTH_STENCIL_DESC* wrapper, const Dx12ObjectInfoTable& object_info_table);

template <typename T>
void MapStructArrayObjects(T* structs, size_t len, const Dx12ObjectInfoTable& object_info_table)
{
    if (structs != nullptr)
    {
        for (size_t i = 0; i < len; ++i)
        {
            MapStructObjects(&structs[i], object_info_table);
        }
    }
}

template <typename T>
void AddStructArrayObjects(format::HandleId parent_id, const T* id_wrappers, size_t id_len, const typename T::struct_type* handle_structs, size_t handle_len, Dx12ObjectInfoTable* object_info_table)
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
