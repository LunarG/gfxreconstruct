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
#include "generated/generated_vulkan_dispatch_table.h"
#include "generated/generated_vulkan_enum_to_string.h"
#include "graphics/vulkan_util.h"
#include "util/defines.h"
#include "util/logging.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

// Wrapper class for VkFence. Either holds an existing VkFence or creates and handles destruction of one
struct TemporaryFence
{
    TemporaryFence(VkFence other, VkDevice device, const graphics::VulkanDeviceTable& dt) :
        handle(other), parent_device(device), device_table(dt)
    {
        if (other == VK_NULL_HANDLE)
        {
            VkFenceCreateInfo fence_ci = { VK_STRUCTURE_TYPE_FENCE_CREATE_INFO, nullptr, 0 };
            const VkResult    res      = device_table.CreateFence(parent_device, &fence_ci, nullptr, &handle);
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

    TemporaryFence(VkDevice device, const graphics::VulkanDeviceTable& dt) : TemporaryFence(VK_NULL_HANDLE, device, dt)
    {}

    VkResult Wait()
    {
        GFXRECON_ASSERT(parent_device != VK_NULL_HANDLE);
        GFXRECON_ASSERT(handle != VK_NULL_HANDLE);

        // Wait a sensible amount of time (10 seconds) in case we did something that can cause the GPU to hang or crash.
        VkResult res = device_table.WaitForFences(parent_device, 1, &handle, VK_TRUE, 10000000000);
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

        VkResult res = device_table.ResetFences(parent_device, 1, &handle);
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

            device_table.DestroyFence(parent_device, handle, nullptr);
        }
    }

    VkFence                            handle;
    VkDevice                           parent_device;
    const graphics::VulkanDeviceTable& device_table;
    bool                               needs_cleanup;
};

struct TemporaryCommandBuffer
{
    TemporaryCommandBuffer(const VulkanDeviceInfo& dev_info, const graphics::VulkanDeviceTable& dev_table) :
        device_info(dev_info), device_table(dev_table)
    {}

    ~TemporaryCommandBuffer()
    {
        if (command_pool != VK_NULL_HANDLE)
        {
            device_table.DestroyCommandPool(device_info.handle, command_pool, nullptr);
        }
    };

    VkResult CreateAndBegin(graphics::FindQueueFamilyIndex_fp queue_finder_fp);

    VkResult CreateAndBegin(uint32_t queue_family_index);

    VkResult SubmitAndDestroy();

    const VulkanDeviceInfo&            device_info{ nullptr };
    const graphics::VulkanDeviceTable& device_table{ nullptr };
    VkCommandPool                      command_pool{ VK_NULL_HANDLE };
    VkCommandBuffer                    command_buffer{ VK_NULL_HANDLE };
    VkQueue                            queue{ VK_NULL_HANDLE };
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif /* GFXRECON_DECODE_VULKAN_TEMPORARY_OBJECTS_H */
