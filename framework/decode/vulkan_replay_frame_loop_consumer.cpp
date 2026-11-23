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

#include "decode/vulkan_replay_frame_loop_consumer.h"

#include "decode/vulkan_stage_frame_loop_fixup.h"
#include "generated/generated_vulkan_replay_consumer.h"
#include "generated/generated_vulkan_replay_frame_loop_consumer_base.h"
#include "util/callbacks.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void VulkanReplayFrameLoopConsumer::Process_vkFreeMemory(const ApiCallInfo& call_info, args::FreeMemory& args)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if args.memory is in allocatedLoopResources

    // Call Process_vkFreeMemory if:
    //    We are not looping
    //    We are looping and args.memory is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(args.memory))
        VulkanReplayConsumer::Process_vkFreeMemory(call_info, args);

        // Remove all boundMemory entries whose value equals args.memory
        for (auto it = boundMemory.begin(); it != boundMemory.end();)
        {
            if (it->second == args.memory)
            {
                boundMemory.erase(it++);
            }
            else
            {
                ++it;
            }
        }
    }
    else if (allocatedLoopResources.contains(args.memory))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkFreeMemory(call_info, args);
        allocatedLoopResources.erase(args.memory);

        // Remove all boundMemory entries whose value equals args.memory
        for (auto it = boundMemory.begin(); it != boundMemory.end();)
        {
            if (it->second == args.memory)
            {
                boundMemory.erase(it++);
            }
            else
            {
                ++it;
            }
        }
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkFreeMemory(call_info, args);

        // Remove all boundMemory entries whose value equals args.memory
        for (auto it = boundMemory.begin(); it != boundMemory.end();)
        {
            if (it->second == args.memory)
            {
                boundMemory.erase(it++);
            }
            else
            {
                ++it;
            }
        }
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkCreateCommandPool(const ApiCallInfo&       call_info,
                                                                args::CreateCommandPool& args)
{
    // Set VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT in order to prevent validation
    // error regarding implicitly resetting the command buffer
    VkCommandPoolCreateInfo* create_info = args.pCreateInfo.GetPointer();
    create_info->flags |= VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;

    VulkanReplayFrameLoopConsumerBase::Process_vkCreateCommandPool(call_info, args);
}

void VulkanReplayFrameLoopConsumer::Process_vkDestroyDescriptorPool(const ApiCallInfo&           call_info,
                                                                    args::DestroyDescriptorPool& args)
{
    // Call Process_vkDestroyDescriptorPool if:
    //    We are not looping
    //    We are looping and args.descriptorPool is in allocatedLoopResources
    //    We are looping and this is the last iteration
    const bool allocated_within_loop = allocatedLoopResources.contains(args.descriptorPool);
    GFXRECON_ASSERT(getFrameLoopInfo().IsLooping() || !allocated_within_loop);

    if (getFrameLoopInfo().IsLooping() && !allocated_within_loop && !getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        return;
    }

    // The descriptor sets allocated from the pool are freed along with it. Without any pool info, no pool exists on
    // replay, as the destroyed handle is VK_NULL_HANDLE or the pool failed to be created, so neither do its sets.
    const VulkanDescriptorPoolInfo* pool_info = GetObjectInfoTable().GetVkDescriptorPoolInfo(args.descriptorPool);
    if (pool_info != nullptr)
    {
        lifetime_tracker_.OnPoolDestroy(pool_info->child_ids);
    }

    VulkanReplayConsumer::Process_vkDestroyDescriptorPool(call_info, args);

    // A pool allocated WITHIN the loop range gets also destroyed within the same iteration.
    // Therefore it should be allocated again by the next iteration.
    allocatedLoopResources.erase(args.descriptorPool);
}

void VulkanReplayFrameLoopConsumer::Process_vkBeginCommandBuffer(const ApiCallInfo&        call_info,
                                                                 args::BeginCommandBuffer& args)
{
    VulkanReplayConsumer::Process_vkBeginCommandBuffer(call_info, args);

    if (frame_loop_info_.IsLooping())
    {
        // The query pool resets are not commands of the application.
        util::MarkInjectedCommandsHelper injected_commands_scope;

        // Record query pool reset commands
        VulkanCommandBufferInfo* cb_info       = GetObjectInfoTable().GetVkCommandBufferInfo(args.commandBuffer);
        format::HandleId         device        = cb_info->parent_id;
        VkDevice                 replay_device = GetObjectInfoTable().GetVkDeviceInfo(device)->handle;
        GFXRECON_ASSERT(replay_device != 0);
        GetObjectInfoTable().VisitVkQueryPoolInfo([this, replay_device, cb_info](const VulkanQueryPoolInfo* info) {
            // A command buffer can only reference query pools created from its own device.
            if (info->parent_id != cb_info->parent_id)
            {
                return;
            }

            GFXRECON_ASSERT(query_pool_sizes_.contains(info->capture_id));
            const graphics::VulkanDeviceTable* device_table = GetDeviceTable(replay_device);
            GFXRECON_ASSERT(device_table != nullptr);
            VkQueryPool pool_handle = info->handle;
            uint32_t    pool_size   = query_pool_sizes_[info->capture_id];
            GFXRECON_LOG_DEBUG(
                "Resetting pool 0x%" PRIx64 " (replay time handle == 0x%" PRIx64 ")", info->handle, info->capture_id);
            device_table->CmdResetQueryPool(cb_info->handle, pool_handle, 0, pool_size);

            // keep tracked query availability in sync with the injected reset
            cb_info->recorded_query_ops.push_back({ info->capture_id, 0, pool_size, false });
        });
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkResetDescriptorPool(const ApiCallInfo&         call_info,
                                                                  args::ResetDescriptorPool& args)
{
    const VulkanDescriptorPoolInfo* pool_info = GetObjectInfoTable().GetVkDescriptorPoolInfo(args.descriptorPool);
    if ((pool_info == nullptr) || lifetime_tracker_.OnPoolReset(pool_info->child_ids))
    {
        VulkanReplayConsumer::Process_vkResetDescriptorPool(call_info, args);
    }
}

/// Restricts a vkAllocateDescriptorSets call to the descriptor sets at `indices`. Every array indexed like
/// pDescriptorSets is restricted as well, so that each remaining set keeps its own layout and variable count.
/// The arguments are decoded again for every iteration, so restricting them in place does not leak into the next one.
static void RestrictDescriptorSets(args::AllocateDescriptorSets& args, const std::vector<uint32_t>& indices)
{
    const uint32_t count = static_cast<uint32_t>(indices.size());

    Decoded_VkDescriptorSetAllocateInfo* allocate_info = args.pAllocateInfo.GetMetaStructPointer();
    GFXRECON_ASSERT(allocate_info->decoded_value->descriptorSetCount == args.pDescriptorSets.GetLength());
    GFXRECON_ASSERT(allocate_info->pSetLayouts.GetLength() == args.pDescriptorSets.GetLength());

    allocate_info->decoded_value->descriptorSetCount = count;

    args.pDescriptorSets.KeepIndices(indices);

    // The replay consumer maps the layout IDs to replay handles, so restricting the IDs is enough.
    allocate_info->pSetLayouts.KeepIndices(indices);

    auto* variable_counts =
        GetPNextMetaStruct<Decoded_VkDescriptorSetVariableDescriptorCountAllocateInfo>(allocate_info->pNext);

    // A descriptorSetCount of zero gives every set a variable descriptor count of zero, which still holds.
    if ((variable_counts != nullptr) && (variable_counts->decoded_value->descriptorSetCount != 0))
    {
        GFXRECON_ASSERT(variable_counts->pDescriptorCounts.GetLength() ==
                        variable_counts->decoded_value->descriptorSetCount);

        variable_counts->decoded_value->descriptorSetCount = count;

        // decoded_value->pDescriptorCounts points to the decoded counts, which are restricted in place.
        variable_counts->pDescriptorCounts.KeepIndices(indices);
    }
}

/// Restricts a vkFreeDescriptorSets call to the descriptor sets at `indices`.
static void RestrictDescriptorSets(args::FreeDescriptorSets& args, const std::vector<uint32_t>& indices)
{
    GFXRECON_ASSERT(args.descriptorSetCount == args.pDescriptorSets.GetLength());
    args.descriptorSetCount = static_cast<uint32_t>(indices.size());

    args.pDescriptorSets.KeepIndices(indices);
}

void VulkanReplayFrameLoopConsumer::Process_vkAllocateDescriptorSets(const ApiCallInfo&            call_info,
                                                                     args::AllocateDescriptorSets& args)
{
    const FrameLoopLifetimeTracker::CallReplay replay = lifetime_tracker_.OnAllocate(args.pDescriptorSets.GetSpan());
    if (!replay.IsSkipped())
    {
        if (replay.IsRestricted())
        {
            RestrictDescriptorSets(args, replay.indices);
        }

        VulkanReplayConsumer::Process_vkAllocateDescriptorSets(call_info, args);
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkFreeDescriptorSets(const ApiCallInfo&        call_info,
                                                                 args::FreeDescriptorSets& args)
{
    const FrameLoopLifetimeTracker::CallReplay replay = lifetime_tracker_.OnFree(args.pDescriptorSets.GetSpan());
    if (!replay.IsSkipped())
    {
        if (replay.IsRestricted())
        {
            RestrictDescriptorSets(args, replay.indices);
        }

        VulkanReplayConsumer::Process_vkFreeDescriptorSets(call_info, args);
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkCreateQueryPool(const ApiCallInfo& call_info, args::CreateQueryPool& args)
{
    VulkanReplayFrameLoopConsumerBase::Process_vkCreateQueryPool(call_info, args);

    if (!frame_loop_info_.IsLooping() || (frame_loop_info_.IsLooping() && !frame_loop_info_.IsRepetition()))
    {
        // If this query pool was created outside the loop range or if it's the first iteration
        // of the loop range, save query pool creation sizes
        uint32_t               count  = args.pCreateInfo.GetPointer()->queryCount;
        const format::HandleId handle = *args.pQueryPool.GetPointer();
        query_pool_sizes_[handle]     = count;
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkMapMemory(const ApiCallInfo& call_info, args::MapMemory& args)
{
    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in mapped_loop_memory
    if (frame_loop_info_.IsLooping())
    {
        if (mapped_loop_memory.contains(args.memory))
        {
            return; // Already mapped in loop range, skip re-mapping
        }

        // First time mapping in the loop
        mapped_loop_memory.insert(args.memory);
    }
    VulkanReplayConsumer::Process_vkMapMemory(call_info, args);
}

template <typename SubmitInfoT>
void VulkanReplayFrameLoopConsumer::EndFrameAtBoundaries(std::span<SubmitInfoT> submits)
{
    if (!frame_loop_info_.IsLooping())
    {
        return;
    }

    for (const SubmitInfoT& submit : submits)
    {
        if (IsFrameEndBoundary(submit.pNext))
        {
            lifetime_tracker_.OnFrameEnd();
        }
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkQueueBindSparse(const ApiCallInfo& call_info, args::QueueBindSparse& args)
{
    VulkanReplayFrameLoopConsumerBase::Process_vkQueueBindSparse(call_info, args);
    EndFrameAtBoundaries(args.pBindInfo.GetMetaStructSpan());
}

void VulkanReplayFrameLoopConsumer::Process_vkQueueSubmit(const ApiCallInfo& call_info, args::QueueSubmit& args)
{
    VulkanReplayConsumer::Process_vkQueueSubmit(call_info, args);
    EndFrameAtBoundaries(args.pSubmits.GetMetaStructSpan());
}

void VulkanReplayFrameLoopConsumer::Process_vkQueueSubmit2(const ApiCallInfo& call_info, args::QueueSubmit2& args)
{
    VulkanReplayConsumer::Process_vkQueueSubmit2(call_info, args);
    EndFrameAtBoundaries(args.pSubmits.GetMetaStructSpan());
}

void VulkanReplayFrameLoopConsumer::Process_vkQueueSubmit2KHR(const ApiCallInfo& call_info, args::QueueSubmit2KHR& args)
{
    VulkanReplayConsumer::Process_vkQueueSubmit2KHR(call_info, args);
    EndFrameAtBoundaries(args.pSubmits.GetMetaStructSpan());
}

void VulkanReplayFrameLoopConsumer::Process_vkQueuePresentKHR(const ApiCallInfo& call_info, args::QueuePresentKHR& args)
{
    VulkanReplayConsumer::Process_vkQueuePresentKHR(call_info, args);

    if (frame_loop_info_.IsLooping())
    {
        lifetime_tracker_.OnFrameEnd();
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkUnmapMemory(const ApiCallInfo& call_info, args::UnmapMemory& args)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if memory is in mapped_loop_memory

    // Call Process_vkUnmapMemory if:
    //    We are not looping
    //    We are looping and memory is in mapped_loop_memory, i.e. it is mapped/unmapped inside loop
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(args.memory));
        VulkanReplayConsumer::Process_vkUnmapMemory(call_info, args);
    }
    else if (mapped_loop_memory.contains(args.memory))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkUnmapMemory(call_info, args);
        mapped_loop_memory.erase(args.memory);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkUnmapMemory(call_info, args);
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkAcquireProfilingLockKHR(const ApiCallInfo&             call_info,
                                                                      args::AcquireProfilingLockKHR& args)
{
    // If we are not looping, if current lock state for this device is undefined, or
    // the current state is false (not acquired), call replay consumer
    if (!frame_loop_info_.IsLooping() || !profilingLockState.contains(args.device) || !profilingLockState[args.device])
    {
        VulkanReplayConsumer::Process_vkAcquireProfilingLockKHR(call_info, args);
        // We're assuming call was successful. We don't have a way to check result.
        profilingLockState[args.device] = true;
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkReleaseProfilingLockKHR(const ApiCallInfo&             call_info,
                                                                      args::ReleaseProfilingLockKHR& args)
{
    // If we are not looping, if current lock state for this device is undefined, or
    // the current state is true (acquired), call replay consumer
    if (!frame_loop_info_.IsLooping() || !profilingLockState.contains(args.device) || profilingLockState[args.device])
    {
        VulkanReplayConsumer::Process_vkReleaseProfilingLockKHR(call_info, args);
        // We're assuming call was successful. We don't have a way to check result.
        profilingLockState[args.device] = false;
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
