/*
** Copyright (c) 2020 LunarG, Inc.
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

#ifndef GFXRECON_DECODE_VULKAN_HANDLE_MAPPING_UTIL_H
#define GFXRECON_DECODE_VULKAN_HANDLE_MAPPING_UTIL_H

#include "decode/common_handle_mapping_util.h"
#include "generated/generated_vulkan_struct_decoders.h"

#include "vulkan/vulkan.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)
GFXRECON_BEGIN_NAMESPACE(handle_mapping)

uint64_t MapHandle(uint64_t object, VkObjectType object_type, const CommonObjectInfoTable& object_info_table);

uint64_t
MapHandle(uint64_t object, VkDebugReportObjectTypeEXT object_type, const CommonObjectInfoTable& object_info_table);

template <typename S, typename T>
static void AddHandleArray(format::HandleId              parent_id,
                           format::HandleId              pool_id,
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
            // Prevent the the ID from being added to the pool's child list if it would be rejectd by AddFunc due to a
            // null handle ID or null handle.
            if ((ids[i] != format::kNullHandleId) && (handles[i] != 0))
            {
                auto info_iter        = std::next(initial_infos.begin(), i);
                info_iter->handle     = handles[i];
                info_iter->capture_id = ids[i];
                info_iter->parent_id  = parent_id;
                info_iter->pool_id    = pool_id;
                (object_info_table->*AddFunc)(std::move(*info_iter));
            }
        }
    }
}

template <typename S, typename T>
static void AddHandleArray(format::HandleId              parent_id,
                           format::HandleId              pool_id,
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
            // Prevent the the ID from being added to the pool's child list if it would be rejectd by AddFunc due to a
            // null handle ID or null handle.
            if ((ids[i] != format::kNullHandleId) && (handles[i] != 0))
            {
                T info;
                info.handle     = handles[i];
                info.capture_id = ids[i];
                info.parent_id  = parent_id;
                info.pool_id    = pool_id;
                (object_info_table->*AddFunc)(std::move(info));
            }
        }
    }
}

template <typename S, typename T>
static void AddHandleArray(format::HandleId              parent_id,
                           format::HandleId              pool_id,
                           const format::HandleId*       ids,
                           size_t                        ids_len,
                           const typename T::HandleType* handles,
                           size_t                        handles_len,
                           std::vector<T>&&              initial_infos,
                           CommonObjectInfoTable*        object_info_table,
                           S* (CommonObjectInfoTable::*GetPoolInfoFunc)(format::HandleId),
                           void (CommonObjectInfoTable::*AddFunc)(T&&))
{
    assert(object_info_table != nullptr);

    if ((ids != nullptr) && (handles != nullptr))
    {
        auto pool_info = (object_info_table->*GetPoolInfoFunc)(pool_id);

        size_t len = std::min(ids_len, handles_len);

        assert(len <= initial_infos.size());

        for (size_t i = 0; i < len; ++i)
        {
            // Prevent the the ID from being added to the pool's child list if it would be rejectd by AddFunc due to a
            // null handle ID or null handle.
            if ((ids[i] != format::kNullHandleId) && (handles[i] != VK_NULL_HANDLE))
            {
                if (pool_info != nullptr)
                {
                    pool_info->child_ids.insert(ids[i]);
                }

                auto info_iter        = std::next(initial_infos.begin(), i);
                info_iter->handle     = handles[i];
                info_iter->capture_id = ids[i];
                info_iter->parent_id  = parent_id;
                info_iter->pool_id    = pool_id;
                (object_info_table->*AddFunc)(std::move(*info_iter));
            }
        }
    }
}

template <typename S, typename T>
static void AddHandleArray(format::HandleId              parent_id,
                           format::HandleId              pool_id,
                           const format::HandleId*       ids,
                           size_t                        ids_len,
                           const typename T::HandleType* handles,
                           size_t                        handles_len,
                           CommonObjectInfoTable*        object_info_table,
                           S* (CommonObjectInfoTable::*GetPoolInfoFunc)(format::HandleId),
                           void (CommonObjectInfoTable::*AddFunc)(T&&))
{
    assert(object_info_table != nullptr);

    if ((ids != nullptr) && (handles != nullptr))
    {
        auto pool_info = (object_info_table->*GetPoolInfoFunc)(pool_id);

        size_t len = std::min(ids_len, handles_len);
        for (size_t i = 0; i < len; ++i)
        {
            // Prevent the the ID from being added to the pool's child list if it would be rejectd by AddFunc due to a
            // null handle ID or null handle.
            if ((ids[i] != format::kNullHandleId) && (handles[i] != VK_NULL_HANDLE))
            {
                if (pool_info != nullptr)
                {
                    pool_info->child_ids.insert(ids[i]);
                }

                T info;
                info.handle     = handles[i];
                info.capture_id = ids[i];
                info.parent_id  = parent_id;
                info.pool_id    = pool_id;
                (object_info_table->*AddFunc)(std::move(info));
            }
        }
    }
}

// Special case removal of pool objects, which require removal of objects allocated from the pool.
template <typename T>
void RemovePoolHandle(format::HandleId       id,
                      CommonObjectInfoTable* object_info_table,
                      T* (CommonObjectInfoTable::*GetPoolInfoFunc)(format::HandleId),
                      void (CommonObjectInfoTable::*RemovePoolFunc)(format::HandleId),
                      void (CommonObjectInfoTable::*RemoveObjectFunc)(format::HandleId))
{
    assert(object_info_table != nullptr);

    const auto pool_info = (object_info_table->*GetPoolInfoFunc)(id);

    if (pool_info != nullptr)
    {
        for (auto child_id : pool_info->child_ids)
        {
            (object_info_table->*RemoveObjectFunc)(child_id);
        }

        (object_info_table->*RemovePoolFunc)(id);
    }
}

template <typename S, typename T>
void RemoveHandleArray(format::HandleId                                    pool_id,
                       const HandlePointerDecoder<typename T::HandleType>* handles_pointer,
                       CommonObjectInfoTable*                              object_info_table,
                       S* (CommonObjectInfoTable::*GetPoolInfoFunc)(format::HandleId),
                       void (CommonObjectInfoTable::*RemoveFunc)(format::HandleId))
{
    assert((handles_pointer != nullptr) && (object_info_table != nullptr));

    if (!handles_pointer->IsNull() && (handles_pointer->GetLength() > 0))
    {
        size_t                  len       = handles_pointer->GetLength();
        const format::HandleId* ids       = handles_pointer->GetPointer();
        auto                    pool_info = (object_info_table->*GetPoolInfoFunc)(pool_id);

        for (size_t i = 0; i < len; ++i)
        {
            if (ids[i] != format::kNullHandleId)
            {
                (object_info_table->*RemoveFunc)(ids[i]);

                if (pool_info != nullptr)
                {
                    pool_info->child_ids.erase(ids[i]);
                }
            }
        }
    }
}

inline format::HandleId GetPoolId(const Decoded_VkCommandBufferAllocateInfo* info)
{
    if (info != nullptr)
    {
        return info->commandPool;
    }

    return format::kNullHandleId;
}

inline format::HandleId GetPoolId(const Decoded_VkDescriptorSetAllocateInfo* info)
{
    if (info != nullptr)
    {
        return info->descriptorPool;
    }

    return format::kNullHandleId;
}

GFXRECON_END_NAMESPACE(handle_mapping)
GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_HANDLE_MAPPING_UTIL_H
