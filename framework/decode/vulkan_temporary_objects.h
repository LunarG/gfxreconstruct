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

#include "decode/vulkan_object_info.h"
#include "decode/vulkan_resource_allocator.h"
#include "generated/generated_vulkan_dispatch_table.h"
#include "generated/generated_vulkan_enum_to_string.h"
#include "graphics/vulkan_injected_calls.h"
#include "graphics/vulkan_util.h"
#include "util/defines.h"
#include "util/logging.h"

#include <memory>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

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

    ~TemporaryCommandBuffer()
    {
        if (command_pool != VK_NULL_HANDLE)
        {
            auto injected = device_table.Open();
            injected->DestroyCommandPool(device_info.handle, command_pool, nullptr);
        }
    };

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
    VkBuffer     buffer{ VK_NULL_HANDLE };
    VkDeviceSize offset{ 0 };
    VkDeviceSize size{ 0 };

    bool IsValid() const { return (buffer != VK_NULL_HANDLE) && (size != 0); }
};

struct TemporaryBufferBlock
{
    static constexpr VkBufferUsageFlags kDefaultUsage =
        VK_BUFFER_USAGE_TRANSFER_SRC_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT;

    static constexpr VkDeviceSize kDefaultAlignment = 256;

    TemporaryBufferBlock(const VulkanDeviceInfo&                    dev_info,
                         const VulkanPhysicalDeviceInfo&            phys_dev_info,
                         const graphics::VulkanInjectedDeviceCalls& injected_calls,
                         VkBufferUsageFlags                         usage = kDefaultUsage,
                         VkMemoryPropertyFlags memory_properties          = VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT) :
        buffer_usage(usage),
        requested_memory_properties(memory_properties), device_info(dev_info), physical_device_info(phys_dev_info),
        device_table(injected_calls)
    {}

    TemporaryBufferBlock(const VulkanDeviceInfo&            dev_info,
                         const VulkanPhysicalDeviceInfo&    phys_dev_info,
                         const graphics::VulkanDeviceTable& dev_table,
                         VkBufferUsageFlags                 usage             = kDefaultUsage,
                         VkMemoryPropertyFlags              memory_properties = VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT) :
        TemporaryBufferBlock(
            dev_info, phys_dev_info, graphics::VulkanInjectedDeviceCalls(&dev_table), usage, memory_properties)
    {}

    ~TemporaryBufferBlock() { Destroy(); }

    // Allocates the block.
    VkResult Create(VkDeviceSize block_bytes);

    // Releases the block. Every TemporaryBuffer handed out becomes stale.
    void Destroy();

    // Carves size bytes out of the block.
    TemporaryBuffer CreateBuffer(VkDeviceSize size, VkDeviceSize alignment = kDefaultAlignment);

    VkBuffer                              buffer{ VK_NULL_HANDLE };
    VkDeviceMemory                        memory{ VK_NULL_HANDLE };
    VulkanResourceAllocator::ResourceData resource_data{ 0 };
    VulkanResourceAllocator::MemoryData   memory_data{ 0 };

    VkDeviceSize size{ 0 };
    VkDeviceSize used{ 0 };

    uint8_t* mapped_data{ nullptr };

    VkMemoryPropertyFlags memory_property_flags{ 0 };

    VkBufferUsageFlags    buffer_usage;
    VkMemoryPropertyFlags requested_memory_properties;

    const VulkanDeviceInfo&             device_info;
    const VulkanPhysicalDeviceInfo&     physical_device_info;
    graphics::VulkanInjectedDeviceCalls device_table;
};

// Collection of TemporaryBufferBlocks
struct TemporaryBufferPool
{
    // Preferred size for a new block. Both maxMemoryAllocationSize and maxBufferSize are only
    // guaranteed to be 1 GiB.
    static constexpr VkDeviceSize kDefaultMaxBlockSize = 256ull * 1024 * 1024;

    TemporaryBufferPool(const VulkanDeviceInfo&                    dev_info,
                        const VulkanPhysicalDeviceInfo&            phys_dev_info,
                        const graphics::VulkanInjectedDeviceCalls& injected_calls,
                        VkBufferUsageFlags                         usage = TemporaryBufferBlock::kDefaultUsage,
                        VkMemoryPropertyFlags memory_properties          = VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT,
                        VkDeviceSize          max_block_bytes            = kDefaultMaxBlockSize) :
        buffer_usage(usage),
        requested_memory_properties(memory_properties), max_block_size(max_block_bytes), device_info(dev_info),
        physical_device_info(phys_dev_info), device_table(injected_calls)
    {}

    TemporaryBufferPool(const VulkanDeviceInfo&            dev_info,
                        const VulkanPhysicalDeviceInfo&    phys_dev_info,
                        const graphics::VulkanDeviceTable& dev_table,
                        VkBufferUsageFlags                 usage             = TemporaryBufferBlock::kDefaultUsage,
                        VkMemoryPropertyFlags              memory_properties = VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT,
                        VkDeviceSize                       max_block_bytes   = kDefaultMaxBlockSize) :
        TemporaryBufferPool(dev_info,
                            phys_dev_info,
                            graphics::VulkanInjectedDeviceCalls(&dev_table),
                            usage,
                            memory_properties,
                            max_block_bytes)
    {}

    // Hints at the total number of bytes still expected to be requested.
    void Reserve(VkDeviceSize total_bytes) { expected_bytes = total_bytes; }

    TemporaryBuffer CreateBuffer(VkDeviceSize size, VkDeviceSize alignment = TemporaryBufferBlock::kDefaultAlignment);

    VkResult AddBlock(VkDeviceSize block_bytes);

    void Destroy();

    std::vector<std::unique_ptr<TemporaryBufferBlock>> blocks;

    VkBufferUsageFlags    buffer_usage;
    VkMemoryPropertyFlags requested_memory_properties;
    VkDeviceSize          max_block_size;

    VkDeviceSize expected_bytes{ 0 };
    bool         exhausted{ false };

    const VulkanDeviceInfo&             device_info;
    const VulkanPhysicalDeviceInfo&     physical_device_info;
    graphics::VulkanInjectedDeviceCalls device_table;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif /* GFXRECON_DECODE_VULKAN_TEMPORARY_OBJECTS_H */
