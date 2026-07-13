/*
** Copyright (c) 2026 LunarG, Inc.
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

#include "decode/vulkan_temporary_objects.h"

#include "decode/decoder_util.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

VkResult TemporaryCommandBuffer::CreateAndBegin(graphics::FindQueueFamilyIndex_fp queue_finder_fp)
{
    const uint32_t queue_index = queue_finder_fp(device_info.enabled_queue_family_flags);
    GFXRECON_ASSERT(queue_index != VK_QUEUE_FAMILY_IGNORED);

    return CreateAndBegin(queue_index);
}

VkResult TemporaryCommandBuffer::CreateAndBegin(uint32_t queue_family_index)
{
    const VkCommandPoolCreateInfo pool_create_info = { VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO,
                                                       nullptr,
                                                       VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT,
                                                       queue_family_index };
    VkResult res = device_table.CreateCommandPool(device_info.handle, &pool_create_info, nullptr, &command_pool);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("%s() CreateCommandPool failed (%s)", __func__, util::ToString(res).c_str());
        return res;
    }

    const VkCommandBufferAllocateInfo alloc_info = {
        VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO, nullptr, command_pool, VK_COMMAND_BUFFER_LEVEL_PRIMARY, 1
    };
    res = device_table.AllocateCommandBuffers(device_info.handle, &alloc_info, &command_buffer);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("%s() AllocateCommandBuffers failed (%s)", __func__, util::ToString(res).c_str());
        return res;
    }

    queue = GetDeviceQueue(&device_table, &device_info, queue_family_index, 0);

    device_table.ResetCommandBuffer(command_buffer, VkCommandBufferResetFlagBits(0));

    const VkCommandBufferBeginInfo begin_info = {
        VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO, nullptr, VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT, nullptr
    };

    res = device_table.BeginCommandBuffer(command_buffer, &begin_info);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("%s() BeginCommandBuffer failed (%s)", __func__, util::ToString(res).c_str());
        return res;
    }

    return VK_SUCCESS;
}

VkResult TemporaryCommandBuffer::SubmitAndDestroy()
{
    GFXRECON_ASSERT(command_buffer != VK_NULL_HANDLE);
    GFXRECON_ASSERT(queue != VK_NULL_HANDLE);
    GFXRECON_ASSERT(command_pool != VK_NULL_HANDLE);

    TemporaryFence fence(device_info.handle, device_table);

    VkResult res = device_table.EndCommandBuffer(command_buffer);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("%s() EndCommandBuffer failed (%s)", __func__, util::ToString(res).c_str());
        return res;
    }

    const VkSubmitInfo submit_info = {
        VK_STRUCTURE_TYPE_SUBMIT_INFO, nullptr, 0, nullptr, nullptr, 1, &command_buffer, 0, nullptr
    };
    res = device_table.QueueSubmit(queue, 1, &submit_info, fence.handle);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("%s() QueueSubmit failed (%s)", __func__, util::ToString(res).c_str());
        return res;
    }

    res = fence.Wait();
    if (res != VK_SUCCESS)
    {
        return res;
    }

    device_table.DestroyCommandPool(device_info.handle, command_pool, nullptr);
    command_pool = VK_NULL_HANDLE;

    return VK_SUCCESS;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
