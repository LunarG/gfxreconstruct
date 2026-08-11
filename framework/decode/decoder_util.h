/*
** Copyright (c) 2022 Advanced Micro Devices, Inc. All rights reserved.
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

#ifndef GFXRECON_DECODE_DECODER_UTIL_H
#define GFXRECON_DECODE_DECODER_UTIL_H

#include "util/defines.h"
#include "decode/vulkan_object_info.h"

#include <string>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

template <typename T>
bool IsComplete(std::vector<T>& consumers, uint64_t block_index)
{
    for (auto it = std::begin(consumers); it != std::end(consumers);)
    {
        if ((*it)->IsComplete(block_index) == true)
        {
            it = consumers.erase(it);
        }
        else
        {
            ++it;
        }
    }

    return consumers.empty();
}

static VkQueue GetDeviceQueue(const graphics::VulkanDeviceTable* device_table,
                              const VulkanDeviceInfo*            device_info,
                              uint32_t                           queue_family_index,
                              uint32_t                           queue_index)
{
    VkQueue queue = VK_NULL_HANDLE;

    const auto& queue_counts = device_info->enabled_queue_family_flags.queue_family_queue_counts;
    const auto  family_entry = queue_counts.find(queue_family_index);
    GFXRECON_ASSERT(family_entry != queue_counts.end());

    if (family_entry == queue_counts.end() || family_entry->second.empty())
    {
        GFXRECON_LOG_ERROR("No queues were created for queue-family %u, returning a null queue.", queue_family_index);
        return queue;
    }

    // callers want an ordinary queue, so prefer the unprotected combination. the map is ordered,
    // so flags 0 sorts first when it exists.
    const VkDeviceQueueCreateFlags create_flags = family_entry->second.begin()->first;

    // If the queue has flags, it has to use GetDeviceQueue2 to get it.
    if (create_flags != 0)
    {
        const VkDeviceQueueInfo2 queue_info = {
            VK_STRUCTURE_TYPE_DEVICE_QUEUE_INFO_2, nullptr, create_flags, queue_family_index, queue_index
        };
        device_table->GetDeviceQueue2(device_info->handle, &queue_info, &queue);
    }
    else
    {
        device_table->GetDeviceQueue(device_info->handle, queue_family_index, queue_index, &queue);
    }
    return queue;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_DECODER_UTIL_H
