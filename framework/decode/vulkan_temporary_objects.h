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

#ifndef GFXRECON_DECODE_VULKAN_TEMPORARY_OBJECTS_H
#define GFXRECON_DECODE_VULKAN_TEMPORARY_OBJECTS_H

#include "decode/vulkan_resource_allocator.h"
#include "generated/generated_vulkan_dispatch_table.h"
#include "generated/generated_vulkan_enum_to_string.h"
#include "graphics/vulkan_injected_calls.h"
#include "graphics/vulkan_util.h"
#include "util/defines.h"
#include "util/logging.h"

#include <memory>
#include <utility>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

struct VulkanDeviceInfo;

// Wrapper class for VkFence. Either holds an existing VkFence or creates and handles destruction of one
struct TemporaryFence
{
    TemporaryFence(VkFence other, VkDevice device, const graphics::VulkanInjectedDeviceCalls& injected_calls) :
        handle(other), parent_device(device), device_table(injected_calls)
    {
        if (other == VK_NULL_HANDLE)
        {
            auto              injected = device_table.Open();
            VkFenceCreateInfo fence_ci = { VK_STRUCTURE_TYPE_FENCE_CREATE_INFO, nullptr, 0 };
            const VkResult    res      = injected->CreateFence(parent_device, &fence_ci, nullptr, &handle);
            needs_cleanup              = (res == VK_SUCCESS);
            if (res != VK_SUCCESS)
            {
                GFXRECON_LOG_ERROR(
                    "[%s:%u] CreateFence failed with %s", __FILE__, __LINE__, util::ToString(res).c_str());
            }
        }
        else
        {
            needs_cleanup = false;
        }
    }

    TemporaryFence(VkFence other, VkDevice device, const graphics::VulkanDeviceTable& dt) :
        TemporaryFence(other, device, graphics::VulkanInjectedDeviceCalls(&dt))
    {}

    TemporaryFence(VkDevice device, const graphics::VulkanInjectedDeviceCalls& injected_calls) :
        TemporaryFence(VK_NULL_HANDLE, device, injected_calls)
    {}

    TemporaryFence(VkDevice device, const graphics::VulkanDeviceTable& dt) : TemporaryFence(VK_NULL_HANDLE, device, dt)
    {}

    VkResult Wait()
    {
        GFXRECON_ASSERT(parent_device != VK_NULL_HANDLE);
        GFXRECON_ASSERT(handle != VK_NULL_HANDLE);

        // Wait a sensible amount of time (10 seconds) in case we did something that can cause the GPU to hang or crash.
        auto     injected = device_table.Open();
        VkResult res      = injected->WaitForFences(parent_device, 1, &handle, VK_TRUE, 10000000000);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("WaitForFences failed with %s", util::ToString(res).c_str());
        }

        return res;
    }

    VkResult Reset()
    {
        GFXRECON_ASSERT(parent_device != VK_NULL_HANDLE);
        GFXRECON_ASSERT(handle != VK_NULL_HANDLE);

        auto     injected = device_table.Open();
        VkResult res      = injected->ResetFences(parent_device, 1, &handle);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("ResetFences failed with %s", util::ToString(res).c_str());
        }

        return res;
    }

    ~TemporaryFence()
    {
        if (needs_cleanup)
        {
            GFXRECON_ASSERT(parent_device != VK_NULL_HANDLE);
            GFXRECON_ASSERT(handle != VK_NULL_HANDLE);

            auto injected = device_table.Open();
            injected->DestroyFence(parent_device, handle, nullptr);
        }
    }

    VkFence                             handle;
    VkDevice                            parent_device;
    graphics::VulkanInjectedDeviceCalls device_table;
    bool                                needs_cleanup;
};

struct TemporaryCommandBuffer
{
    TemporaryCommandBuffer(const VulkanDeviceInfo&                    dev_info,
                           const graphics::VulkanInjectedDeviceCalls& injected_calls) :
        device_info(dev_info),
        device_table(injected_calls)
    {}

    TemporaryCommandBuffer(const VulkanDeviceInfo& dev_info, const graphics::VulkanDeviceTable& dev_table) :
        TemporaryCommandBuffer(dev_info, graphics::VulkanInjectedDeviceCalls(&dev_table))
    {}

    ~TemporaryCommandBuffer();

    VkResult CreateAndBegin(graphics::FindQueueFamilyIndex_fp queue_finder_fp, uint32_t queue_index = 0);

    VkResult CreateAndBegin(uint32_t queue_family_index, uint32_t queue_index = 0);

    VkResult SubmitAndDestroy();

    VkResult SubmitAndReset();

    VkResult Submit();

    VkCommandPool                       command_pool{ VK_NULL_HANDLE };
    VkCommandBuffer                     command_buffer{ VK_NULL_HANDLE };
    VkQueue                             queue{ VK_NULL_HANDLE };
    const VulkanDeviceInfo&             device_info;
    graphics::VulkanInjectedDeviceCalls device_table;
};

struct TemporaryQueryPool
{
    TemporaryQueryPool() = delete;

    TemporaryQueryPool(VkDevice dev, const graphics::VulkanInjectedDeviceCalls& dev_table) :
        query_pool(VK_NULL_HANDLE), device(dev), device_table(dev_table)
    {}

    ~TemporaryQueryPool();

    VkResult Create(uint32_t query_count);

    VkQueryPool                         query_pool;
    VkDevice                            device;
    graphics::VulkanInjectedDeviceCalls device_table;
};

struct TemporaryBuffer
{
    TemporaryBuffer(VkDevice                                   dev,
                    VulkanResourceAllocator*                   alloc,
                    const graphics::VulkanInjectedDeviceCalls& injected_calls) :
        device(dev),
        allocator(alloc), device_table(injected_calls)
    {}

    TemporaryBuffer(VkDevice dev, VulkanResourceAllocator* alloc, const graphics::VulkanDeviceTable& dev_table) :
        TemporaryBuffer(dev, alloc, graphics::VulkanInjectedDeviceCalls(&dev_table))
    {}

    TemporaryBuffer(const TemporaryBuffer&)            = delete;
    TemporaryBuffer& operator=(const TemporaryBuffer&) = delete;

    ~TemporaryBuffer() { Destroy(); }

    VkResult Create(VkDeviceSize buffer_size, VkBufferUsageFlags usage);

    void Destroy();

    bool IsBound() const { return (buffer != VK_NULL_HANDLE) && (memory != VK_NULL_HANDLE); }

    VkBuffer                              buffer{ VK_NULL_HANDLE };
    VkDeviceSize                          size{ 0 }; // Requested size
    VkMemoryRequirements                  requirements{};
    VulkanResourceAllocator::ResourceData resource_data{ 0 };

    // Member populated by TemporaryBufferPool::Allocate()
    VkDeviceMemory                      memory{ VK_NULL_HANDLE };
    VulkanResourceAllocator::MemoryData memory_data{ 0 };
    VkDeviceSize                        memory_offset{ 0 };
    VkMemoryPropertyFlags               memory_property_flags{ 0 };

    // Set only for a buffer that is alone in a host-visible block
    uint8_t* mapped_data{ nullptr };

    VkDevice                            device{ VK_NULL_HANDLE };
    VulkanResourceAllocator*            allocator{ nullptr };
    graphics::VulkanInjectedDeviceCalls device_table;
};

struct TemporaryBufferPool
{
    // Preferred maximum size for a single allocation.  Both maxMemoryAllocationSize and maxBufferSize
    // are only guaranteed to be 1 GiB.
    static constexpr VkDeviceSize kDefaultMaxBlockSize = 256ull * 1024 * 1024;

    TemporaryBufferPool(VkDevice                                   dev,
                        VulkanResourceAllocator*                   alloc,
                        const graphics::VulkanInjectedDeviceCalls& injected_calls,
                        bool                                       map_memory      = false,
                        VkDeviceSize                               max_block_bytes = kDefaultMaxBlockSize) :
        map_host_visible(map_memory),
        max_block_size(max_block_bytes), device(dev), allocator(alloc), device_table(injected_calls)
    {}

    TemporaryBufferPool(VkDevice                           dev,
                        VulkanResourceAllocator*           alloc,
                        const graphics::VulkanDeviceTable& dev_table,
                        bool                               map_memory      = false,
                        VkDeviceSize                       max_block_bytes = kDefaultMaxBlockSize) :
        TemporaryBufferPool(dev, alloc, graphics::VulkanInjectedDeviceCalls(&dev_table), map_memory, max_block_bytes)
    {}

    TemporaryBufferPool(const TemporaryBufferPool&)            = delete;
    TemporaryBufferPool& operator=(const TemporaryBufferPool&) = delete;

    ~TemporaryBufferPool() { Destroy(); }

    // Queues a created, unbound buffer for the next Allocate().
    bool Add(TemporaryBuffer& buffer);

    uint32_t GetMemoryTypeBits() const;

    VkDeviceSize GetRequiredSize() const;

    // Allocates blocks of VkDeviceMemory and binds queued buffers to them.
    VkResult Allocate(uint32_t memory_type_index);

    void Destroy();

    // A single VkDeviceMemory allocation holding one or more bound buffers.
    struct BufferBlock
    {
        VkDeviceMemory                      memory{ VK_NULL_HANDLE };
        VulkanResourceAllocator::MemoryData memory_data{ 0 };
        VkDeviceSize                        size{ 0 };
        VkDeviceSize                        used{ 0 };
        VkMemoryPropertyFlags               memory_property_flags{ 0 };
    };

    // Allocated blocks of memory
    std::vector<BufferBlock> blocks;

    std::vector<TemporaryBuffer*> pending;
    std::vector<TemporaryBuffer*> bound;

    bool map_host_visible{ false };

    VkDeviceSize max_block_size{ kDefaultMaxBlockSize };

    VkDevice                            device{ VK_NULL_HANDLE };
    VulkanResourceAllocator*            allocator{ nullptr };
    graphics::VulkanInjectedDeviceCalls device_table;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif /* GFXRECON_DECODE_VULKAN_TEMPORARY_OBJECTS_H */
