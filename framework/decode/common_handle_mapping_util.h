/*
** Copyright (c) 2020-2024 LunarG, Inc.
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

#ifndef GFXRECON_DECODE_COMMON_HANDLE_MAPPING_UTIL_H
#define GFXRECON_DECODE_COMMON_HANDLE_MAPPING_UTIL_H

#include "decode/common_object_info_table.h"
#include "format/format.h"
#include "util/defines.h"
#include "util/logging.h"

#include <cassert>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)
GFXRECON_BEGIN_NAMESPACE(handle_mapping)

template <typename T>
static typename T::HandleType MapHandle(format::HandleId             id,
                                        const CommonObjectInfoTable& object_info_table,
                                        const T* (CommonObjectInfoTable::*GetInfoFunc)(format::HandleId) const)
{
    typename T::HandleType handle = 0;

    if (id != format::kNullHandleId)
    {
        const T* info = (object_info_table.*GetInfoFunc)(id);

        if (info != nullptr)
        {
            handle = info->handle;
        }
        else
        {
            GFXRECON_LOG_WARNING("Failed to map handle for object id %" PRIu64, id);
        }
    }

    return handle;
}

template <typename T>
static typename T::HandleType* MapHandleArray(HandlePointerDecoder<typename T::HandleType>* handles_pointer,
                                              const CommonObjectInfoTable&                  object_info_table,
                                              const T* (CommonObjectInfoTable::*GetInfoFunc)(format::HandleId) const)
{
    assert(handles_pointer != nullptr);

    typename T::HandleType* handles = nullptr;

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
                const T* info = (object_info_table.*GetInfoFunc)(ids[i]);
                if (info != nullptr)
                {
                    handles[i] = info->handle;
                }
                else
                {
                    handles[i] = 0;
                    GFXRECON_LOG_WARNING("Failed to map handle for object id %" PRIu64, ids[i]);
                }
            }
        }
    }

    return handles;
}

template <typename T>
static void AddHandle(format::HandleId             parent_id,
                      format::HandleId             id,
                      const typename T::HandleType handle,
                      T&&                          initial_info,
                      CommonObjectInfoTable*       object_info_table,
                      void (CommonObjectInfoTable::*AddFunc)(T&&))
{
    assert(object_info_table != nullptr);

    initial_info.handle     = handle;
    initial_info.capture_id = id;
    initial_info.parent_id  = parent_id;
    (object_info_table->*AddFunc)(std::forward<T>(initial_info));
}

template <typename T>
static void AddHandle(format::HandleId       parent_id,
                      format::HandleId       id,
                      typename T::HandleType handle,
                      CommonObjectInfoTable* object_info_table,
                      void (CommonObjectInfoTable::*AddFunc)(T&&))
{
    assert(object_info_table != nullptr);

    T info;
    info.handle     = handle;
    info.capture_id = id;
    info.parent_id  = parent_id;
    (object_info_table->*AddFunc)(std::move(info));
}

template <typename T>
static void AddHandleArray(format::HandleId              parent_id,
                           const format::HandleId*       ids,
                           size_t                        ids_len,
                           const typename T::HandleType* handles,
                           size_t                        handles_len,
                           std::vector<T>&&              initial_infos,
                           CommonObjectInfoTable*        object_info_table,
                           void (CommonObjectInfoTable::*AddFunc)(T&&))
{
    assert(object_info_table != nullptr);

    if ((ids != nullptr) && (handles != nullptr))
    {
        size_t len = std::min(ids_len, handles_len);

        assert(len <= initial_infos.size());

        for (size_t i = 0; i < len; ++i)
        {
            auto info_iter        = std::next(initial_infos.begin(), i);
            info_iter->handle     = handles[i];
            info_iter->capture_id = ids[i];
            info_iter->parent_id  = parent_id;
            (object_info_table->*AddFunc)(std::move(*info_iter));
        }
    }
}

template <typename T>
static void AddHandleArray(format::HandleId              parent_id,
                           const format::HandleId*       ids,
                           size_t                        ids_len,
                           const typename T::HandleType* handles,
                           size_t                        handles_len,
                           CommonObjectInfoTable*        object_info_table,
                           void (CommonObjectInfoTable::*AddFunc)(T&&))
{
    assert(object_info_table != nullptr);

    if ((ids != nullptr) && (handles != nullptr))
    {
        size_t len = std::min(ids_len, handles_len);
        for (size_t i = 0; i < len; ++i)
        {
            T info;
            info.handle     = handles[i];
            info.capture_id = ids[i];
            info.parent_id  = parent_id;
            (object_info_table->*AddFunc)(std::move(info));
        }
    }
}

inline void RemoveHandle(format::HandleId       id,
                         CommonObjectInfoTable* object_info_table,
                         void (CommonObjectInfoTable::*RemoveFunc)(format::HandleId))
{
    assert(object_info_table != nullptr);

    if (id != format::kNullHandleId)
    {
        (object_info_table->*RemoveFunc)(id);
    }
}

GFXRECON_END_NAMESPACE(handle_mapping)
GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_COMMON_HANDLE_MAPPING_UTIL_H
