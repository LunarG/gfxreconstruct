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

// Catch must come before the Vulkan headers because Xlib defines None and Always as macros.
#include <catch2/catch.hpp>

#include "decode/common_object_info_table.h"
#include "decode/vulkan_command_buffer_util.h"
#include "decode/vulkan_object_info.h"
#include "decode/vulkan_state_recording_decoder.h"
#include "format/format_util.h"
#include "generated/generated_vulkan_dispatch_table.h"
#include "graphics/vulkan_injected_calls.h"
#include "util/logging.h"

#include <cstdint>
#include <optional>
#include <span>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

namespace
{

constexpr format::HandleId kDeviceId              = 1;
constexpr format::HandleId kPoolId                = 2;
constexpr format::HandleId kNewPoolId             = 3;
constexpr format::HandleId kCommandBufferId       = 42;
constexpr format::HandleId kReusedCommandBufferId = 43;

const VkDevice        kDeviceHandle   = format::FromHandleId<VkDevice>(0xD000);
const VkQueue         kQueueHandle    = format::FromHandleId<VkQueue>(0xE000);
const VkCommandPool   kPoolHandle     = format::FromHandleId<VkCommandPool>(0xC000);
const VkCommandPool   kNewPoolHandle  = format::FromHandleId<VkCommandPool>(0xC001);
const VkCommandBuffer kOriginalHandle = format::FromHandleId<VkCommandBuffer>(0xA000);

// Records the driver calls of the splitter.
// The dispatch table holds plain function pointers, so the fakes write to this global and each fixture resets it.
struct FakeDriver
{
    uint64_t                     next_command_buffer{ 0xB000 };
    std::vector<VkCommandBuffer> allocated;
    std::vector<VkCommandBuffer> freed;
    std::vector<VkCommandBuffer> reset;
    uint32_t                     submits{ 0 };
};

FakeDriver fake_driver;

VKAPI_ATTR VkResult VKAPI_CALL FakeAllocateCommandBuffers(VkDevice,
                                                          const VkCommandBufferAllocateInfo* allocate_info,
                                                          VkCommandBuffer*                   command_buffers)
{
    for (uint32_t i = 0; i < allocate_info->commandBufferCount; ++i)
    {
        command_buffers[i] = format::FromHandleId<VkCommandBuffer>(fake_driver.next_command_buffer++);
        fake_driver.allocated.push_back(command_buffers[i]);
    }
    return VK_SUCCESS;
}

VKAPI_ATTR void VKAPI_CALL FakeFreeCommandBuffers(VkDevice,
                                                  VkCommandPool,
                                                  uint32_t               command_buffer_count,
                                                  const VkCommandBuffer* command_buffers)
{
    fake_driver.freed.insert(fake_driver.freed.end(), command_buffers, command_buffers + command_buffer_count);
}

VKAPI_ATTR VkResult VKAPI_CALL FakeBeginCommandBuffer(VkCommandBuffer, const VkCommandBufferBeginInfo*)
{
    return VK_SUCCESS;
}

VKAPI_ATTR VkResult VKAPI_CALL FakeEndCommandBuffer(VkCommandBuffer)
{
    return VK_SUCCESS;
}

VKAPI_ATTR VkResult VKAPI_CALL FakeResetCommandBuffer(VkCommandBuffer command_buffer, VkCommandBufferResetFlags)
{
    fake_driver.reset.push_back(command_buffer);
    return VK_SUCCESS;
}

VKAPI_ATTR VkResult VKAPI_CALL FakeQueueSubmit(VkQueue, uint32_t, const VkSubmitInfo*, VkFence)
{
    ++fake_driver.submits;
    return VK_SUCCESS;
}

VKAPI_ATTR VkResult VKAPI_CALL FakeCreateSemaphore(VkDevice,
                                                   const VkSemaphoreCreateInfo*,
                                                   const VkAllocationCallbacks*,
                                                   VkSemaphore* semaphore)
{
    *semaphore = format::FromHandleId<VkSemaphore>(0x5000);
    return VK_SUCCESS;
}

VKAPI_ATTR void VKAPI_CALL FakeDestroySemaphore(VkDevice, VkSemaphore, const VkAllocationCallbacks*) {}

// The split semaphore reads its counter when it is destroyed. Every target value counts as reached.
VKAPI_ATTR VkResult VKAPI_CALL FakeGetSemaphoreCounterValue(VkDevice, VkSemaphore, uint64_t* value)
{
    *value = UINT64_MAX;
    return VK_SUCCESS;
}

// One device with one reset-capable pool, which holds command buffer kCommandBufferId with handle kOriginalHandle.
class SplitterFixture
{
  public:
    SplitterFixture()
    {
        util::Log::Init(util::LoggingSeverity::kError);
        fake_driver = {};

        device_table_.AllocateCommandBuffers   = FakeAllocateCommandBuffers;
        device_table_.FreeCommandBuffers       = FakeFreeCommandBuffers;
        device_table_.BeginCommandBuffer       = FakeBeginCommandBuffer;
        device_table_.EndCommandBuffer         = FakeEndCommandBuffer;
        device_table_.ResetCommandBuffer       = FakeResetCommandBuffer;
        device_table_.QueueSubmit              = FakeQueueSubmit;
        device_table_.CreateSemaphore          = FakeCreateSemaphore;
        device_table_.DestroySemaphore         = FakeDestroySemaphore;
        device_table_.GetSemaphoreCounterValue = FakeGetSemaphoreCounterValue;

        VulkanDeviceInfo device_info;
        device_info.handle     = kDeviceHandle;
        device_info.capture_id = kDeviceId;
        object_table_.AddVkDeviceInfo(std::move(device_info));

        queue_info_.handle = kQueueHandle;

        AddCommandPool(kPoolId, kPoolHandle);
        AddCommandBuffer(kCommandBufferId, kOriginalHandle, kPoolId);

        splitter_.emplace(object_table_.GetVkDeviceInfo(kDeviceId),
                          graphics::VulkanInjectedDeviceCalls(&device_table_),
                          &object_table_,
                          &decoder_);
    }

    ~SplitterFixture()
    {
        // The splitter destroys its split semaphores through the fake table.
        splitter_.reset();
        util::Log::Release();
    }

  protected:
    // Adds a reset-capable pool of the device.
    void AddCommandPool(format::HandleId pool_id, VkCommandPool handle)
    {
        VulkanCommandPoolInfo pool_info;
        pool_info.handle       = handle;
        pool_info.capture_id   = pool_id;
        pool_info.parent_id    = kDeviceId;
        pool_info.create_flags = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
        object_table_.AddVkCommandPoolInfo(std::move(pool_info));
    }

    // Adds a command buffer of the device to the pool.
    VulkanCommandBufferInfo*
    AddCommandBuffer(format::HandleId command_buffer_id, VkCommandBuffer handle, format::HandleId pool_id)
    {
        object_table_.GetVkCommandPoolInfo(pool_id)->child_ids.insert(command_buffer_id);

        VulkanCommandBufferInfo command_buffer_info;
        command_buffer_info.handle     = handle;
        command_buffer_info.capture_id = command_buffer_id;
        command_buffer_info.parent_id  = kDeviceId;
        command_buffer_info.pool_id    = pool_id;
        object_table_.AddVkCommandBufferInfo(std::move(command_buffer_info));

        return object_table_.GetVkCommandBufferInfo(command_buffer_id);
    }

    graphics::VulkanDeviceTable            device_table_;
    CommonObjectInfoTable                  object_table_;
    VulkanStateRecordingDecoder            decoder_;
    VulkanQueueInfo                        queue_info_;
    std::optional<VulkanCommandBufferUtil> splitter_;
};

} // namespace

TEST_CASE_METHOD(SplitterFixture,
                 "FreeCommandBuffers frees the split handles and restores the original handle",
                 "[isolate-render-passes]")
{
    VulkanCommandBufferInfo* command_buffer_info = object_table_.GetVkCommandBufferInfo(kCommandBufferId);

    splitter_->SplitCommandBuffer(command_buffer_info);
    REQUIRE(command_buffer_info->handle != kOriginalHandle);

    const format::HandleId command_buffer_ids[] = { kCommandBufferId };
    splitter_->FreeCommandBuffers(kPoolHandle, command_buffer_ids);

    // The caller frees the original handle, so the splitter must restore it and free only the handles it allocated.
    CHECK(command_buffer_info->handle == kOriginalHandle);
    CHECK_THAT(fake_driver.freed, Catch::Matchers::UnorderedEquals(fake_driver.allocated));
}

TEST_CASE_METHOD(SplitterFixture,
                 "FreeCommandBuffers leaves no split state on the freed original handle",
                 "[isolate-render-passes]")
{
    VulkanCommandBufferInfo* command_buffer_info = object_table_.GetVkCommandBufferInfo(kCommandBufferId);
    splitter_->SplitCommandBuffer(command_buffer_info);

    const format::HandleId command_buffer_ids[] = { kCommandBufferId };
    splitter_->FreeCommandBuffers(kPoolHandle, command_buffer_ids);

    // The driver can give the freed handle to the next command buffer it allocates.
    VulkanCommandBufferInfo* reused_info = AddCommandBuffer(kReusedCommandBufferId, kOriginalHandle, kPoolId);
    fake_driver.reset.clear();

    SECTION("Begin")
    {
        splitter_->BeginCommandBuffer(reused_info);

        CHECK(reused_info->handle == kOriginalHandle);
        CHECK(fake_driver.reset.empty());
    }

    SECTION("Submit")
    {
        VkSubmitInfo submit_info       = { VK_STRUCTURE_TYPE_SUBMIT_INFO };
        submit_info.commandBufferCount = 1;
        submit_info.pCommandBuffers    = &reused_info->handle;

        graphics::VulkanSemaphore semaphore =
            splitter_->SubmitPreviouslySplitCommandBuffers(&queue_info_, std::span<VkSubmitInfo>(&submit_info, 1));

        CHECK(semaphore.semaphore == VK_NULL_HANDLE);
        CHECK(fake_driver.submits == 0);
    }
}

TEST_CASE_METHOD(SplitterFixture,
                 "DestroyCommandPool leaves no split state on the handles of the pool",
                 "[isolate-render-passes]")
{
    VulkanCommandBufferInfo* command_buffer_info = object_table_.GetVkCommandBufferInfo(kCommandBufferId);
    splitter_->SplitCommandBuffer(command_buffer_info);
    const VkCommandBuffer split_handle = command_buffer_info->handle;

    splitter_->DestroyCommandPool(object_table_.GetVkCommandPoolInfo(kPoolId));

    // Destroying the pool frees every handle in it, so the splitter frees none.
    CHECK(fake_driver.freed.empty());

    // The driver can give the dead handles to command buffers of a new pool.
    AddCommandPool(kNewPoolId, kNewPoolHandle);
    fake_driver.reset.clear();

    VkCommandBuffer reused_handle = VK_NULL_HANDLE;
    SECTION("Original handle")
    {
        reused_handle = kOriginalHandle;
    }
    SECTION("Split handle")
    {
        reused_handle = split_handle;
    }

    VulkanCommandBufferInfo* reused_info = AddCommandBuffer(kReusedCommandBufferId, reused_handle, kNewPoolId);
    splitter_->BeginCommandBuffer(reused_info);

    // Stale split state would reset the dead handles and swap in the dead original handle.
    CHECK(reused_info->handle == reused_handle);
    CHECK(fake_driver.reset.empty());
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
