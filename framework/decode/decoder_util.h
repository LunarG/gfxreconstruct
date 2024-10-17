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

static VkQueue GetDeviceQueue(const encode::VulkanDeviceTable* device_table,
                              const VulkanDeviceInfo*          device_info,
                              uint32_t                         queue_family_index,
                              uint32_t                         queue_index)
{
    VkQueue queue = VK_NULL_HANDLE;

    const auto queue_family_flags = device_info->queue_family_creation_flags.find(queue_family_index);
    assert(queue_family_flags != device_info->queue_family_creation_flags.end());

    // If the queue has flags, it has to use GetDeviceQueue2 to get it.
    if (queue_family_flags->second != 0)
    {
        const VkDeviceQueueInfo2 queue_info = {
            VK_STRUCTURE_TYPE_DEVICE_QUEUE_INFO_2, nullptr, queue_family_flags->second, queue_family_index, queue_index
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
