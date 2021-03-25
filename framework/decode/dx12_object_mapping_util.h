/*
** Copyright (c) 2021 LunarG, Inc.
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

#include "format/format.h"
#include <unordered_map>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

typedef std::unordered_map<format::HandleId, IUnknown*> Dx12ObjectInfoTable;

GFXRECON_BEGIN_NAMESPACE(object_mapping)

template <typename T>
static T* MapObject(format::HandleId id, const Dx12ObjectInfoTable& object_info_table)
{
    auto entry = object_info_table.find(id);
    if (entry != object_info_table.end())
    {
        return reinterpret_cast<T*>(entry->second);
    }

    return nullptr;
}

template <typename T>
static std::vector<T*>
MapObjectArray(const format::HandleId* p_ids, const size_t ids_len, const Dx12ObjectInfoTable& object_info_table)
{
    std::vector<T*> objects(ids_len);
    if (p_ids != nullptr)
    {
        for (uint32_t i = 0; i < ids_len; ++i)
        {
            objects[i] = MapObject<T>(p_ids[i], object_info_table);
        }
    }
    return objects;
}

template <typename T>
static void AddObject(const format::HandleId* p_id, T** pp_object, Dx12ObjectInfoTable* object_info_table)
{
    assert(object_info_table != nullptr);

    if ((p_id != nullptr) && (*p_id != format::kNullHandleId) && (pp_object != nullptr) && (*pp_object != nullptr))
    {
        (*object_info_table)[*p_id] = reinterpret_cast<IUnknown*>(*pp_object);
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
