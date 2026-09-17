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

#include <vulkan/vulkan_core.h>

#include <cinttypes>
#include <utility>

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
    auto injected = device_table.Open();

    return CreateAndBegin(queue_family_index,
                          GetDeviceQueue(injected.GetTable(), &device_info, queue_family_index, queue_index));
}

VkResult TemporaryCommandBuffer::CreateAndBegin(uint32_t queue_family_index, VkQueue submit_queue)
{
    if (submit_queue == VK_NULL_HANDLE)
    {
        return VK_ERROR_UNKNOWN;
    }

    queue = submit_queue;

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
    GFXRECON_ASSERT(handle == VK_NULL_HANDLE);

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

    const VkResult res = allocator->CreateBufferDirect(&buffer_create_info, nullptr, &handle, &resource_data);
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
    injected->GetBufferMemoryRequirements(device, handle, &requirements);

    size = buffer_size;

    return VK_SUCCESS;
}

void TemporaryBuffer::Destroy()
{
    if ((allocator != nullptr) && (handle != VK_NULL_HANDLE))
    {
        allocator->DestroyBufferDirect(handle, nullptr, resource_data);
    }

    handle        = VK_NULL_HANDLE;
    resource_data = 0;
    size          = 0;
    requirements  = {};
}

TemporaryBuffer::TemporaryBuffer(TemporaryBuffer&& other) noexcept :
    device(other.device), allocator(other.allocator), device_table(other.device_table)
{
    swap(other);
}

TemporaryBuffer& TemporaryBuffer::operator=(TemporaryBuffer&& other) noexcept
{
    if (this != &other)
    {
        // Release what this buffer already holds, then take over what `other` holds.
        Destroy();
        device       = other.device;
        allocator    = other.allocator;
        device_table = other.device_table;
        swap(other);
    }
    return *this;
}

void TemporaryBuffer::swap(TemporaryBuffer& other) noexcept
{
    std::swap(handle, other.handle);
    std::swap(size, other.size);
    std::swap(requirements, other.requirements);
    std::swap(resource_data, other.resource_data);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
