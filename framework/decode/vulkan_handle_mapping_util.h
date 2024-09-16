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

#include "decode/vulkan_object_info_table.h"
#include "format/format.h"
#include "generated/generated_vulkan_struct_decoders.h"
#include "util/defines.h"
#include "util/logging.h"

#include <encode/custom_exported_layer_funcs.h>

#include "vulkan/vulkan.h"
#include "vulkan/vulkan_core.h"

#include <cassert>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)
GFXRECON_BEGIN_NAMESPACE(handle_mapping)

template <typename T>
static typename T::HandleType MapHandle(format::HandleId             id,
                                        const VulkanObjectInfoTable& object_info_table,
                                        const T* (VulkanObjectInfoTable::*GetInfoFunc)(format::HandleId) const)
{
    typename T::HandleType handle = VK_NULL_HANDLE;

    if (id != format::kNullHandleId)
    {
        const T* info = (object_info_table.*GetInfoFunc)(id);

        if (info != nullptr)
        {
            handle = info->handle;

            if constexpr (has_handle_future_v<T>)
            {
                if (info->handle == VK_NULL_HANDLE && info->future.valid())
                {
                    const auto& [result, async_handles] = info->future.get();
                    handle                              = async_handles[info->future_handle_index];
                }
            }
        }
        else
        {
            GFXRECON_LOG_WARNING("Failed to map handle for object id %" PRIu64, id);
        }
    }
    return handle;
}

uint64_t MapHandle(uint64_t object, VkObjectType object_type, const VulkanObjectInfoTable& object_info_table);

uint64_t
MapHandle(uint64_t object, VkDebugReportObjectTypeEXT object_type, const VulkanObjectInfoTable& object_info_table);

template <typename T>
static typename T::HandleType* MapHandleArray(HandlePointerDecoder<typename T::HandleType>* handles_pointer,
                                              const VulkanObjectInfoTable&                  object_info_table,
                                              const T* (VulkanObjectInfoTable::*GetInfoFunc)(format::HandleId) const)
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

                    if constexpr (has_handle_future_v<T>)
                    {
                        if (info->handle == VK_NULL_HANDLE && info->future.valid())
                        {
                            const auto& [result, async_handles] = info->future.get();
                            handles[i]                          = async_handles[info->future_handle_index];
                        }
                    }
                }
                else
                {
                    handles[i] = VK_NULL_HANDLE;
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
                      VulkanObjectInfoTable*       object_info_table,
                      void (VulkanObjectInfoTable::*AddFunc)(T&&))
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
                      VulkanObjectInfoTable* object_info_table,
                      void (VulkanObjectInfoTable::*AddFunc)(T&&))
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
            info.parent_id  = parent_id;
            (object_info_table->*AddFunc)(std::move(info));
        }
    }
}

template <typename T>
static void AddHandleArrayAsync(format::HandleId        parent_id,
                                const format::HandleId* ids,
                                size_t                  ids_len,
                                VulkanObjectInfoTable*  object_info_table,
                                void (VulkanObjectInfoTable::*AddFunc)(T&&),
                                std::shared_future<handle_create_result_t<typename T::HandleType>> future)
{
    static_assert(has_handle_future_v<T>, "handle-type does not support asynchronous creation");
    assert(object_info_table != nullptr);

    if (ids != nullptr)
    {
        for (size_t i = 0; i < ids_len; ++i)
        {
            T info;
            info.handle              = VK_NULL_HANDLE; // handle does not yet exist
            info.capture_id          = ids[i];
            info.parent_id           = parent_id;
            info.future              = future;
            info.future_handle_index = i;
            (object_info_table->*AddFunc)(std::move(info));
        }
    }
}

template <typename T>
static void AddHandleArrayAsync(format::HandleId        parent_id,
                                const format::HandleId* ids,
                                size_t                  ids_len,
                                VulkanObjectInfoTable*  object_info_table,
                                std::vector<T>&&        initial_infos,
                                void (VulkanObjectInfoTable::*AddFunc)(T&&),
                                std::shared_future<handle_create_result_t<typename T::HandleType>> future)
{
    static_assert(has_handle_future_v<T>, "handle-type does not support asynchronous creation");
    assert(object_info_table != nullptr);

    if (ids != nullptr)
    {
        assert(ids_len <= initial_infos.size());

        for (size_t i = 0; i < ids_len; ++i)
        {
            auto info_iter                 = std::next(initial_infos.begin(), i);
            info_iter->handle              = VK_NULL_HANDLE; // handle does not yet exist
            info_iter->capture_id          = ids[i];
            info_iter->parent_id           = parent_id;
            info_iter->future              = future;
            info_iter->future_handle_index = i;
            (object_info_table->*AddFunc)(std::move(*info_iter));
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
                           VulkanObjectInfoTable*        object_info_table,
                           S* (VulkanObjectInfoTable::*GetPoolInfoFunc)(format::HandleId),
                           void (VulkanObjectInfoTable::*AddFunc)(T&&))
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
                           VulkanObjectInfoTable*        object_info_table,
                           S* (VulkanObjectInfoTable::*GetPoolInfoFunc)(format::HandleId),
                           void (VulkanObjectInfoTable::*AddFunc)(T&&))
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

inline void RemoveHandle(format::HandleId       id,
                         VulkanObjectInfoTable* object_info_table,
                         void (VulkanObjectInfoTable::*RemoveFunc)(format::HandleId))
{
    assert(object_info_table != nullptr);

    if (id != format::kNullHandleId)
    {
        (object_info_table->*RemoveFunc)(id);
    }
}

// Special case removal of pool objects, which require removal of objects allocated from the pool.
template <typename T>
void RemovePoolHandle(format::HandleId       id,
                      VulkanObjectInfoTable* object_info_table,
                      T* (VulkanObjectInfoTable::*GetPoolInfoFunc)(format::HandleId),
                      void (VulkanObjectInfoTable::*RemovePoolFunc)(format::HandleId),
                      void (VulkanObjectInfoTable::*RemoveObjectFunc)(format::HandleId))
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
                       VulkanObjectInfoTable*                              object_info_table,
                       S* (VulkanObjectInfoTable::*GetPoolInfoFunc)(format::HandleId),
                       void (VulkanObjectInfoTable::*RemoveFunc)(format::HandleId))
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
