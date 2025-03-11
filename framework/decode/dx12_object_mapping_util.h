/*
** Copyright (c) 2021 LunarG, Inc.
** Copyright (c) 2025 Advanced Micro Devices, Inc. All rights reserved.
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

#ifndef GFXRECON_DECODE_DX12_OBJECT_MAPPING_UTIL_H
#define GFXRECON_DECODE_DX12_OBJECT_MAPPING_UTIL_H

#include "decode/custom_dx12_struct_decoders_forward.h"
#include "decode/dx12_object_info.h"
#include "decode/dx12_descriptor_map.h"
#include "decode/handle_pointer_decoder.h"
#include "format/format.h"
#include "graphics/dx12_gpu_va_map.h"

#include <map>
#include <unordered_map>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

typedef std::unordered_map<format::HandleId, DxObjectInfo> Dx12ObjectInfoTable;

GFXRECON_BEGIN_NAMESPACE(object_mapping)

void MapGpuDescriptorHandle(D3D12_GPU_DESCRIPTOR_HANDLE& handle, const Dx12DescriptorMap& descriptor_map);

void MapGpuDescriptorHandles(D3D12_GPU_DESCRIPTOR_HANDLE* handles,
                             size_t                       handles_len,
                             const Dx12DescriptorMap&     descriptor_map);

void MapCpuDescriptorHandle(D3D12_CPU_DESCRIPTOR_HANDLE& handle, const Dx12DescriptorMap& descriptor_map);

void MapGpuVirtualAddress(D3D12_GPU_VIRTUAL_ADDRESS& address, const graphics::Dx12GpuVaMap& gpu_va_map);

void MapGpuVirtualAddresses(D3D12_GPU_VIRTUAL_ADDRESS*    addresses,
                            size_t                        addresses_len,
                            const graphics::Dx12GpuVaMap& gpu_va_map);

format::HandleId FindResourceIDbyGpuVA(D3D12_GPU_VIRTUAL_ADDRESS     captured_address,
                                       const graphics::Dx12GpuVaMap& gpu_va_map);

template <typename T>
static T* MapObject(format::HandleId id, const Dx12ObjectInfoTable& object_info_table)
{
    auto entry = object_info_table.find(id);
    if (entry != object_info_table.end())
    {
        auto& info = entry->second;
        return reinterpret_cast<T*>(info.object);
    }

    return nullptr;
}

template <typename T>
static T** MapObjectArray(HandlePointerDecoder<T*>* handles_pointer, const Dx12ObjectInfoTable& object_info_table)
{
    assert(handles_pointer != nullptr);

    T** handles = nullptr;

    if (!handles_pointer->IsNull())
    {
        size_t                  len = handles_pointer->GetLength();
        const format::HandleId* ids = handles_pointer->GetPointer();

        handles_pointer->SetHandleLength(len);

        handles = handles_pointer->GetHandlePointer();

        for (size_t i = 0; i < len; ++i)
        {
            if (ids[i] != format::kNullHandleId)
            {
                auto object = MapObject<T>(ids[i], object_info_table);
                if (object != nullptr)
                {
                    handles[i] = object;
                }
                else
                {
                    handles[i] = nullptr;
                    GFXRECON_LOG_WARNING("Failed to map handle for object id %" PRIu64, ids[i]);
                }
            }
        }
    }

    return handles;
}

template <typename T>
static void AddObject(const format::HandleId* p_id, T** pp_object, Dx12ObjectInfoTable* object_info_table)
{
    AddObject(p_id, pp_object, DxObjectInfo{}, object_info_table);
}

template <typename T>
static void AddObject(const format::HandleId* p_id,
                      T**                     pp_object,
                      DxObjectInfo&&          initial_info,
                      Dx12ObjectInfoTable*    object_info_table)
{
    assert(object_info_table != nullptr);

    if ((p_id != nullptr) && (*p_id != format::kNullHandleId) && (pp_object != nullptr) && (*pp_object != nullptr))
    {
        auto id    = *p_id;
        auto entry = object_info_table->find(id);
        if (entry == object_info_table->end())
        {
            initial_info.capture_id = id;
            initial_info.object     = reinterpret_cast<IUnknown*>(*pp_object);
            object_info_table->emplace(id, std::move(initial_info));
        }
        else
        {
            assert(entry->second.object == *pp_object);
            ++(entry->second.ref_count);
        }
    }
    else if ((pp_object != nullptr) && (*pp_object != nullptr))
    {
        // The ID was null, but the object was not, the object creation failed at capture, but succeeded at replay.
        // Release the object to avoid leaking.
        reinterpret_cast<IUnknown*>(*pp_object)->Release();
    }
}

static void RemoveObject(format::HandleId id, Dx12ObjectInfoTable* object_info_table)
{
    assert(object_info_table != nullptr);

    if (id != format::kNullHandleId)
    {
        object_info_table->erase(id);
    }
}

GFXRECON_END_NAMESPACE(object_mapping)
GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_DX12_OBJECT_MAPPING_UTIL_H
