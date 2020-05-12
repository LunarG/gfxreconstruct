/*
** Copyright (c) 2020 LunarG, Inc.
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

#ifndef GFXRECON_DECODE_VULKAN_HANDLE_MAPPING_UTIL_H
#define GFXRECON_DECODE_VULKAN_HANDLE_MAPPING_UTIL_H

#include "decode/vulkan_object_info_table.h"
#include "format/format.h"

#include "vulkan/vulkan.h"

#include <cassert>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)
GFXRECON_BEGIN_NAMESPACE(handle_mapping)

template <typename T>
static typename T::HandleType MapHandle(format::HandleId             id,
                                        const VulkanObjectInfoTable& object_info_table,
                                        const T* (VulkanObjectInfoTable::*MapFunc)(format::HandleId) const)
{
    typename T::HandleType handle = VK_NULL_HANDLE;
    const T*               info   = (object_info_table.*MapFunc)(id);

    if (info != nullptr)
    {
        handle = info->handle;
    }

    return handle;
}

template <typename T>
static typename T::HandleType* MapHandleArray(HandlePointerDecoder<typename T::HandleType>* handle_pointer,
                                              const VulkanObjectInfoTable&                  object_info_table,
                                              const T* (VulkanObjectInfoTable::*MapFunc)(format::HandleId) const)
{
    assert(handle_pointer != nullptr);

    typename T::HandleType* handles = nullptr;

    if (!handle_pointer->IsNull())
    {
        size_t                  len = handle_pointer->GetLength();
        const format::HandleId* ids = handle_pointer->GetPointer();

        handle_pointer->SetHandleLength(len);

        handles = handle_pointer->GetHandlePointer();

        for (size_t i = 0; i < len; ++i)
        {
            const T* info = (object_info_table.*MapFunc)(ids[i]);
            if (info != nullptr)
            {
                handles[i] = info->handle;
            }
            else
            {
                handles[i] = VK_NULL_HANDLE;
            }
        }
    }

    return handles;
}

template <typename T>
static void AddHandle(const format::HandleId       id,
                      const typename T::HandleType handle,
                      T&&                          initial_info,
                      VulkanObjectInfoTable*       object_info_table,
                      void (VulkanObjectInfoTable::*AddFunc)(T&&))
{
    assert(object_info_table != nullptr);

    initial_info.handle     = handle;
    initial_info.capture_id = id;
    (object_info_table->*AddFunc)(std::forward<T>(initial_info));
}

template <typename T>
static void AddHandle(format::HandleId       id,
                      typename T::HandleType handle,
                      VulkanObjectInfoTable* object_info_table,
                      void (VulkanObjectInfoTable::*AddFunc)(T&&))
{
    assert(object_info_table != nullptr);

    T info;
    info.handle     = handle;
    info.capture_id = id;
    (object_info_table->*AddFunc)(std::move(info));
}

template <typename T>
static void AddHandleArray(const format::HandleId*       ids,
                           size_t                        ids_len,
                           const typename T::HandleType* handles,
                           size_t                        handles_len,
                           std::vector<T>&&              initial_infos,
                           VulkanObjectInfoTable*        object_info_table,
                           void (VulkanObjectInfoTable::*AddFunc)(T&&))
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
            (object_info_table->*AddFunc)(std::move(*info_iter));
        }
    }
}

template <typename T>
static void AddHandleArray(const format::HandleId*       ids,
                           size_t                        ids_len,
                           const typename T::HandleType* handles,
                           size_t                        handles_len,
                           VulkanObjectInfoTable*        object_info_table,
                           void (VulkanObjectInfoTable::*AddFunc)(T&&))
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
            (object_info_table->*AddFunc)(std::move(info));
        }
    }
}

GFXRECON_END_NAMESPACE(handle_mapping)
GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_HANDLE_MAPPING_UTIL_H
