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
#include "graphics/vulkan_device_util.h"
#include "util/alignment_utils.h"

#include <vulkan/vulkan_core.h>

#include <algorithm>
#include <cinttypes>
#include <limits>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

TemporaryCommandBuffer::~TemporaryCommandBuffer()
{
    if (command_pool != VK_NULL_HANDLE)
    {
        auto injected = device_table.Open();
        injected->DestroyCommandPool(device_info.handle, command_pool, nullptr);
    }
}

VkResult TemporaryCommandBuffer::CreateAndBegin(graphics::FindQueueFamilyIndex_fp queue_finder_fp, uint32_t queue_index)
{
    const uint32_t queue_family_index = queue_finder_fp(device_info.enabled_queue_family_flags);
    if (queue_family_index == VK_QUEUE_FAMILY_IGNORED)
    {
        return VK_ERROR_UNKNOWN;
    }

    return CreateAndBegin(queue_family_index, queue_index);
}

VkResult TemporaryCommandBuffer::CreateAndBegin(uint32_t queue_family_index, uint32_t queue_index)
{
    auto                          injected         = device_table.Open();
    const VkCommandPoolCreateInfo pool_create_info = { VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO,
                                                       nullptr,
                                                       VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT,
                                                       queue_family_index };
    VkResult res = injected->CreateCommandPool(device_info.handle, &pool_create_info, nullptr, &command_pool);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("%s() CreateCommandPool failed (%s)", __func__, util::ToString(res).c_str());
        return res;
    }

    const VkCommandBufferAllocateInfo alloc_info = {
        VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO, nullptr, command_pool, VK_COMMAND_BUFFER_LEVEL_PRIMARY, 1
    };
    res = injected->AllocateCommandBuffers(device_info.handle, &alloc_info, &command_buffer);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("%s() AllocateCommandBuffers failed (%s)", __func__, util::ToString(res).c_str());
        return res;
    }

    queue = GetDeviceQueue(injected.GetTable(), &device_info, queue_family_index, queue_index);
    if (queue == VK_NULL_HANDLE)
    {
        return VK_ERROR_UNKNOWN;
    }

    injected->ResetCommandBuffer(command_buffer, VkCommandBufferResetFlagBits(0));

    const VkCommandBufferBeginInfo begin_info = {
        VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO, nullptr, VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT, nullptr
    };

    res = injected.BeginCommandBuffer(command_buffer, &begin_info, __func__);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("%s() BeginCommandBuffer failed (%s)", __func__, util::ToString(res).c_str());
        return res;
    }

    return VK_SUCCESS;
}

VkResult TemporaryCommandBuffer::Submit()
{
    GFXRECON_ASSERT(command_buffer != VK_NULL_HANDLE);
    GFXRECON_ASSERT(queue != VK_NULL_HANDLE);
    GFXRECON_ASSERT(command_pool != VK_NULL_HANDLE);

    auto           injected = device_table.Open();
    TemporaryFence fence(device_info.handle, device_table);

    VkResult res = injected->EndCommandBuffer(command_buffer);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("%s() EndCommandBuffer failed (%s)", __func__, util::ToString(res).c_str());
        return res;
    }

    const VkSubmitInfo submit_info = {
        VK_STRUCTURE_TYPE_SUBMIT_INFO, nullptr, 0, nullptr, nullptr, 1, &command_buffer, 0, nullptr
    };
    res = injected->QueueSubmit(queue, 1, &submit_info, fence.handle);
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

    return VK_SUCCESS;
}

VkResult TemporaryCommandBuffer::SubmitAndDestroy()
{
    VkResult res = Submit();
    if (res != VK_SUCCESS)
    {
        return res;
    }

    auto injected = device_table.Open();
    injected->DestroyCommandPool(device_info.handle, command_pool, nullptr);
    command_pool = VK_NULL_HANDLE;

    return VK_SUCCESS;
}

VkResult TemporaryCommandBuffer::SubmitAndReset()
{
    VkResult res = Submit();
    if (res != VK_SUCCESS)
    {
        return res;
    }

    auto injected = device_table.Open();

    res = injected->ResetCommandBuffer(command_buffer, VkCommandBufferResetFlagBits(0));
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("%s() ResetCommandBuffer failed (%s)", __func__, util::ToString(res).c_str());
        return res;
    }

    const VkCommandBufferBeginInfo begin_info = {
        VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO, nullptr, VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT, nullptr
    };

    res = injected.BeginCommandBuffer(command_buffer, &begin_info, __func__);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("%s() BeginCommandBuffer failed (%s)", __func__, util::ToString(res).c_str());
        return res;
    }

    return res;
}

TemporaryQueryPool::~TemporaryQueryPool()
{
    if (query_pool != VK_NULL_HANDLE)
    {
        auto injected = device_table.Open();
        injected->DestroyQueryPool(device, query_pool, nullptr);
        query_pool = VK_NULL_HANDLE;
    }
}

VkResult TemporaryQueryPool::Create(uint32_t query_count)
{
    VkResult res = VK_SUCCESS;

    if (query_pool == VK_NULL_HANDLE)
    {
        // A query pool is required for vkCmdWriteAccelerationStructuresPropertiesKHR
        const VkQueryPoolCreateInfo qci = { VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO,
                                            nullptr,
                                            VkQueryPoolCreateFlagBits(0),
                                            VK_QUERY_TYPE_ACCELERATION_STRUCTURE_SERIALIZATION_SIZE_KHR,
                                            static_cast<uint32_t>(query_count),
                                            VkQueryPipelineStatisticFlags(0) };

        auto injected = device_table.Open();

        res = injected->CreateQueryPool(device, &qci, nullptr, &query_pool);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("%s: CreateQueryPool failed (%s)", __func__, util::ToString(res).c_str())
        }
    }

    return res;
}

VkResult TemporaryBuffer::Create(VkDeviceSize buffer_size, VkBufferUsageFlags usage)
{
    GFXRECON_ASSERT(buffer == VK_NULL_HANDLE);

    if (device == VK_NULL_HANDLE)
    {
        GFXRECON_LOG_ERROR("%s() called on an unconfigured buffer", __func__);
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    if (allocator == nullptr)
    {
        GFXRECON_LOG_ERROR("%s() called for a device without a resource allocator", __func__);
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    if (buffer_size == 0)
    {
        GFXRECON_LOG_ERROR("%s() called with a size of zero", __func__);
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    VkBufferCreateInfo buffer_create_info = { VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO };
    buffer_create_info.size               = buffer_size;
    buffer_create_info.usage              = usage;
    buffer_create_info.sharingMode        = VK_SHARING_MODE_EXCLUSIVE;

    const VkResult res = allocator->CreateBufferDirect(&buffer_create_info, nullptr, &buffer, &resource_data);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("%s() CreateBufferDirect failed for %" PRIu64 " bytes (%s)",
                           __func__,
                           static_cast<uint64_t>(buffer_size),
                           util::ToString(res).c_str());
        Destroy();
        return res;
    }

    auto injected = device_table.Open();
    injected->GetBufferMemoryRequirements(device, buffer, &requirements);

    size = buffer_size;

    return VK_SUCCESS;
}

void TemporaryBuffer::Destroy()
{
    // The pool must already have released it.
    GFXRECON_ASSERT(mapped_data == nullptr);

    if ((allocator != nullptr) && (buffer != VK_NULL_HANDLE))
    {
        allocator->DestroyBufferDirect(buffer, nullptr, resource_data);
    }

    buffer                = VK_NULL_HANDLE;
    resource_data         = 0;
    size                  = 0;
    requirements          = {};
    memory                = VK_NULL_HANDLE;
    memory_data           = 0;
    memory_offset         = 0;
    memory_property_flags = 0;
    mapped_data           = nullptr;
}

bool TemporaryBufferPool::Add(TemporaryBuffer& buffer)
{
    if ((buffer.buffer == VK_NULL_HANDLE) || (buffer.requirements.size == 0))
    {
        GFXRECON_LOG_ERROR("%s() called with a buffer that has not been created", __func__);
        return false;
    }

    if (buffer.IsBound())
    {
        GFXRECON_LOG_ERROR("%s() called with a buffer that is already bound", __func__);
        return false;
    }

    pending.push_back(&buffer);

    return true;
}

uint32_t TemporaryBufferPool::GetMemoryTypeBits() const
{
    if (pending.empty())
    {
        return 0;
    }

    uint32_t type_bits = std::numeric_limits<uint32_t>::max();

    for (const TemporaryBuffer* buffer : pending)
    {
        type_bits &= buffer->requirements.memoryTypeBits;
    }

    return type_bits;
}

VkDeviceSize TemporaryBufferPool::GetRequiredSize() const
{
    VkDeviceSize total = 0;

    for (const TemporaryBuffer* buffer : pending)
    {
        total = util::aligned_value(total, buffer->requirements.alignment) + buffer->requirements.size;
    }

    return total;
}

VkResult TemporaryBufferPool::Allocate(uint32_t memory_type_index)
{
    if (pending.empty())
    {
        return VK_SUCCESS;
    }

    if ((device == VK_NULL_HANDLE) || (allocator == nullptr))
    {
        GFXRECON_LOG_ERROR("%s() called on an unconfigured pool", __func__);
        pending.clear();
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    VkResult first_error = VK_SUCCESS;
    size_t   next        = 0;

    while (next < pending.size())
    {
        // Fill one block with as many of the remaining buffers as fit under the size cap.
        VkDeviceSize block_bytes = 0;
        size_t       count       = 0;

        for (size_t i = next; i < pending.size(); ++i)
        {
            const VkMemoryRequirements& requirements = pending[i]->requirements;
            const VkDeviceSize          offset       = util::aligned_value(block_bytes, requirements.alignment);

            if ((offset > max_block_size) || (requirements.size > (max_block_size - offset)))
            {
                break;
            }

            block_bytes = offset + requirements.size;
            ++count;
        }

        if (count == 0)
        {
            // A buffer larger than the cap gets its own block, even if it exceeds the cap.
            block_bytes = pending[next]->requirements.size;
            count       = 1;
        }

        // Create a new block of memory.
        BufferBlock block;
        block.size                         = block_bytes;
        VkMemoryAllocateInfo allocate_info = { VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO };
        allocate_info.allocationSize       = block_bytes;
        allocate_info.memoryTypeIndex      = memory_type_index;

        VkResult res = allocator->AllocateMemoryDirect(&allocate_info, nullptr, &block.memory, &block.memory_data);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_WARNING("%s() AllocateMemoryDirect failed for %" PRIu64 " bytes (%s)",
                                 __func__,
                                 static_cast<uint64_t>(block_bytes),
                                 util::ToString(res).c_str());
            first_error = (first_error == VK_SUCCESS) ? res : first_error;
            break;
        }

        const size_t block_index    = blocks.size();
        size_t       bound_in_block = 0;

        blocks.push_back(block);

        for (size_t i = next; i < (next + count); ++i)
        {
            TemporaryBuffer* buffer = pending[i];

            // The memory type must be one the buffer accepts.
            GFXRECON_ASSERT((buffer->requirements.memoryTypeBits & (1u << memory_type_index)) != 0);

            // Bind offsets are power-of-two aligned.
            const VkDeviceSize offset = util::aligned_value(blocks[block_index].used, buffer->requirements.alignment);

            VkMemoryPropertyFlags property_flags = 0;

            res = allocator->BindBufferMemoryDirect(buffer->buffer,
                                                    blocks[block_index].memory,
                                                    offset,
                                                    buffer->resource_data,
                                                    blocks[block_index].memory_data,
                                                    &property_flags);
            if (res != VK_SUCCESS)
            {
                GFXRECON_LOG_WARNING("%s() BindBufferMemoryDirect failed at offset %" PRIu64 " (%s)",
                                     __func__,
                                     static_cast<uint64_t>(offset),
                                     util::ToString(res).c_str());
                first_error = (first_error == VK_SUCCESS) ? res : first_error;
                continue;
            }

            // Advance by requirements.size, which can exceed the requested size.
            blocks[block_index].used                  = offset + buffer->requirements.size;
            blocks[block_index].memory_property_flags = property_flags;

            buffer->memory                = blocks[block_index].memory;
            buffer->memory_data           = blocks[block_index].memory_data;
            buffer->memory_offset         = offset;
            buffer->memory_property_flags = property_flags;

            bound.push_back(buffer);
            ++bound_in_block;
        }

        if (map_host_visible &&
            ((blocks[block_index].memory_property_flags & VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT) != 0) &&
            (bound_in_block == 1))
        {
            TemporaryBuffer* buffer = bound.back();
            void*            mapped = nullptr;

            res = allocator->MapResourceMemoryDirect(VK_WHOLE_SIZE, 0, &mapped, buffer->resource_data);
            if (res == VK_SUCCESS)
            {
                buffer->mapped_data = static_cast<uint8_t*>(mapped);
            }
            else
            {
                GFXRECON_LOG_ERROR("%s() MapResourceMemoryDirect failed (%s)", __func__, util::ToString(res).c_str());
                first_error = (first_error == VK_SUCCESS) ? res : first_error;
            }
        }

        next += count;
    }

    // Anything still unbound is dropped.
    pending.clear();

    return first_error;
}

void TemporaryBufferPool::Destroy()
{
    if (allocator != nullptr)
    {
        for (TemporaryBuffer* buffer : bound)
        {
            if (buffer->mapped_data != nullptr)
            {
                allocator->UnmapResourceMemoryDirect(buffer->resource_data);
            }

            buffer->memory                = VK_NULL_HANDLE;
            buffer->memory_data           = 0;
            buffer->memory_offset         = 0;
            buffer->memory_property_flags = 0;
            buffer->mapped_data           = nullptr;
        }

        for (BufferBlock& block : blocks)
        {
            if (block.memory != VK_NULL_HANDLE)
            {
                allocator->FreeMemoryDirect(block.memory, nullptr, block.memory_data);
            }
        }
    }

    blocks.clear();
    bound.clear();
    pending.clear();
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
