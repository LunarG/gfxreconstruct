/*
** Copyright (c) 2018 LunarG, Inc.
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

#ifndef BRIMSTONE_VULKAN_REPLAY_CONSUMER_H
#define BRIMSTONE_VULKAN_REPLAY_CONSUMER_H

#include <cassert>
#include <cstdio>
#include <string>

#include "vulkan/vulkan.h"

#include "util/defines.h"
#include "format/vulkan_consumer.h"
#include "format/vulkan_object_mapper.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(format)

class VulkanReplayConsumer : public VulkanConsumer
{
  public:
    VulkanReplayConsumer();

    virtual ~VulkanReplayConsumer();

  private:
    template <typename T>
    T* AllocateArray(size_t len) const
    {
        return new T[len];
    }

    template <typename T>
    void FreeArray(T** arr) const
    {
        assert(arr != nullptr);

        if ((*arr) != nullptr)
        {
            delete[](*arr);
            *arr = nullptr;
        }
    }

    template <typename T>
    void MapHandles(const HandleId* ids, T* handles, size_t len, T (VulkanObjectMapper::*MapFunc)(HandleId) const) const
    {
        if ((ids != nullptr) && (handles != nullptr))
        {
            for (size_t i = 0; i < len; ++i)
            {
                handles[i] = (object_mapper_.*MapFunc)(ids[i]);
            }
        }
    }

    template <typename T>
    void AddHandles(const HandleId* ids, const T* handles, size_t len, void (VulkanObjectMapper::*AddFunc)(HandleId, T))
    {
        if ((ids != nullptr) && (handles != nullptr))
        {
            for (size_t i = 0; i < len; ++i)
            {
                (object_mapper_.*AddFunc)(ids[i], handles[i]);
            }
        }
    }

    const VkAllocationCallbacks*
    GetAllocationCallbacks(const StructPointerDecoder<Decoded_VkAllocationCallbacks>& original_callbacks);

#include "generated/generated_api_call_consumer_override_declarations.inc"

  private:
    VulkanObjectMapper object_mapper_;
};

BRIMSTONE_END_NAMESPACE(format)
BRIMSTONE_END_NAMESPACE(brimstone)

#endif // BRIMSTONE_VULKAN_REPLAY_CONSUMER_H
