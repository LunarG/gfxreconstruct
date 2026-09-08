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

VkResult TemporaryBufferBlock::Create(VkDeviceSize block_bytes)
{
    GFXRECON_ASSERT(buffer == VK_NULL_HANDLE);

    const auto& allocator = device_info.allocator;
    if (allocator == nullptr)
    {
        GFXRECON_LOG_ERROR("%s() called for a device without a resource allocator", __func__);
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    if (block_bytes == 0)
    {
        GFXRECON_LOG_ERROR("%s() called with a size of zero", __func__);
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    VkBufferCreateInfo buffer_create_info = { VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO };
    buffer_create_info.size               = block_bytes;
    buffer_create_info.usage              = buffer_usage;
    buffer_create_info.sharingMode        = VK_SHARING_MODE_EXCLUSIVE;

    VkResult res = allocator->CreateBufferDirect(&buffer_create_info, nullptr, &buffer, &resource_data);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("%s() CreateBufferDirect failed for %" PRIu64 " bytes (%s)",
                           __func__,
                           static_cast<uint64_t>(block_bytes),
                           util::ToString(res).c_str());
        Destroy();
        return res;
    }

    VkMemoryRequirements memory_requirements = {};

    auto injected = device_table.Open();
    injected->GetBufferMemoryRequirements(device_info.handle, buffer, &memory_requirements);

    const bool have_replay_properties = (physical_device_info.replay_device_info != nullptr) &&
                                        physical_device_info.replay_device_info->memory_properties.has_value();
    const VkPhysicalDeviceMemoryProperties& replay_memory_properties =
        have_replay_properties ? physical_device_info.replay_device_info->memory_properties.value()
                               : physical_device_info.capture_memory_properties;

    const uint32_t memory_type_index = graphics::GetMemoryTypeIndex(
        replay_memory_properties, memory_requirements.memoryTypeBits, requested_memory_properties);

    if (memory_type_index == std::numeric_limits<uint32_t>::max())
    {
        GFXRECON_LOG_ERROR("%s() found no memory type with properties 0x%x",
                           __func__,
                           static_cast<unsigned int>(requested_memory_properties));
        Destroy();
        return VK_ERROR_OUT_OF_DEVICE_MEMORY;
    }

    VkMemoryAllocateInfo allocate_info = { VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO };
    allocate_info.allocationSize       = memory_requirements.size;
    allocate_info.memoryTypeIndex      = memory_type_index;

    res = allocator->AllocateMemoryDirect(&allocate_info, nullptr, &memory, &memory_data);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("%s() AllocateMemoryDirect failed for %" PRIu64 " bytes (%s)",
                           __func__,
                           static_cast<uint64_t>(memory_requirements.size),
                           util::ToString(res).c_str());
        Destroy();
        return res;
    }

    res = allocator->BindBufferMemoryDirect(buffer, memory, 0, resource_data, memory_data, &memory_property_flags);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("%s() BindBufferMemoryDirect failed (%s)", __func__, util::ToString(res).c_str());
        Destroy();
        return res;
    }

    size = block_bytes;

    if ((requested_memory_properties & VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT) != 0)
    {
        void* mapped = nullptr;
        res          = allocator->MapResourceMemoryDirect(VK_WHOLE_SIZE, 0, &mapped, resource_data);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("%s() MapResourceMemoryDirect failed (%s)", __func__, util::ToString(res).c_str());
            Destroy();
            return res;
        }

        mapped_data = static_cast<uint8_t*>(mapped);
    }

    return VK_SUCCESS;
}

void TemporaryBufferBlock::Destroy()
{
    const auto& allocator = device_info.allocator;
    if (allocator != nullptr)
    {
        if (mapped_data != nullptr)
        {
            allocator->UnmapResourceMemoryDirect(resource_data);
        }

        if (buffer != VK_NULL_HANDLE)
        {
            allocator->DestroyBufferDirect(buffer, nullptr, resource_data);
        }

        if (memory != VK_NULL_HANDLE)
        {
            allocator->FreeMemoryDirect(memory, nullptr, memory_data);
        }
    }

    buffer                = VK_NULL_HANDLE;
    memory                = VK_NULL_HANDLE;
    resource_data         = 0;
    memory_data           = 0;
    size                  = 0;
    used                  = 0;
    mapped_data           = nullptr;
    memory_property_flags = 0;
}

TemporaryBuffer TemporaryBufferBlock::CreateBuffer(VkDeviceSize buffer_size, VkDeviceSize alignment)
{
    TemporaryBuffer temp_buffer;

    if ((buffer == VK_NULL_HANDLE) || (buffer_size == 0))
    {
        return temp_buffer;
    }

    if ((alignment == 0) || !util::is_pow_2(alignment))
    {
        GFXRECON_LOG_ERROR(
            "%s() alignment %" PRIu64 " is not a power of two", __func__, static_cast<uint64_t>(alignment));
        return temp_buffer;
    }

    // Round up for alignment
    const VkDeviceSize mask = alignment - 1;
    if (used > (std::numeric_limits<VkDeviceSize>::max() - mask))
    {
        return temp_buffer;
    }

    const VkDeviceSize offset = (used + mask) & ~mask;
    if ((offset > size) || (buffer_size > (size - offset)))
    {
        GFXRECON_LOG_DEBUG("%s() a %" PRIu64 " byte request does not fit in the %" PRIu64
                           " bytes remaining in this block",
                           __func__,
                           static_cast<uint64_t>(buffer_size),
                           static_cast<uint64_t>((offset <= size) ? (size - offset) : 0));
        return temp_buffer;
    }

    temp_buffer.buffer = buffer;
    temp_buffer.offset = offset;
    temp_buffer.size   = buffer_size;

    used = offset + buffer_size;

    return temp_buffer;
}

VkResult TemporaryBufferPool::AddBlock(VkDeviceSize block_bytes)
{
    auto block = std::make_unique<TemporaryBufferBlock>(
        device_info, physical_device_info, device_table, buffer_usage, requested_memory_properties);

    const VkResult res = block->Create(block_bytes);
    if (res != VK_SUCCESS)
    {
        return res;
    }

    blocks.push_back(std::move(block));

    return VK_SUCCESS;
}

TemporaryBuffer TemporaryBufferPool::CreateBuffer(VkDeviceSize buffer_size, VkDeviceSize alignment)
{
    TemporaryBuffer temp_buffer;

    if (buffer_size == 0)
    {
        return temp_buffer;
    }

    if ((alignment == 0) || !util::is_pow_2(alignment))
    {
        GFXRECON_LOG_ERROR(
            "%s() alignment %" PRIu64 " is not a power of two", __func__, static_cast<uint64_t>(alignment));
        return temp_buffer;
    }

    // The most recently added block is the one most likely to have room.
    for (auto it = blocks.rbegin(); it != blocks.rend(); ++it)
    {
        temp_buffer = (*it)->CreateBuffer(buffer_size, alignment);
        if (temp_buffer.IsValid())
        {
            break;
        }
    }

    const VkDeviceSize needed = util::aligned_value(buffer_size, alignment);

    if (!temp_buffer.IsValid() && !exhausted)
    {
        // Size the new block for everything still expected.
        const VkDeviceSize block_bytes = std::max(needed, std::min(expected_bytes, max_block_size));

        if (AddBlock(block_bytes) == VK_SUCCESS)
        {
            temp_buffer = blocks.back()->CreateBuffer(buffer_size, alignment);
            if (!temp_buffer.IsValid())
            {
                blocks.pop_back();
                exhausted = true;
            }
        }
        else
        {
            exhausted = true;
        }
    }

    expected_bytes -= std::min(expected_bytes, needed);

    return temp_buffer;
}

void TemporaryBufferPool::Destroy()
{
    // Each block releases its own resources.
    blocks.clear();
    expected_bytes = 0;
    exhausted      = false;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
