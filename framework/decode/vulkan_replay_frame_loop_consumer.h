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

#ifndef GFXRECON_DECODE_VULKAN_REPLAY_FRAME_LOOP_CONSUMER_H
#define GFXRECON_DECODE_VULKAN_REPLAY_FRAME_LOOP_CONSUMER_H

#include "util/defines.h"
#include "decode/vulkan_replay_consumer_base.h"
#include "generated/generated_vulkan_replay_consumer.h"
#include "generated/generated_vulkan_replay_frame_loop_consumer_base.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class VulkanReplayFrameLoopConsumer : public VulkanReplayFrameLoopConsumerBase
{
  public:
    VulkanReplayFrameLoopConsumer(std::shared_ptr<application::Application> application,
                                  const VulkanReplayOptions&                options,
                                  graphics::FrameLoopInfo&                  frame_loop_info) :
        VulkanReplayFrameLoopConsumerBase(application, options),
        frame_loop_info_(frame_loop_info)
    {}

    ~VulkanReplayFrameLoopConsumer() override;

    graphics::FrameLoopInfo& getFrameLoopInfo() override { return frame_loop_info_; }

    virtual void ProcessStateEndMarker(uint64_t frame_number) override;

    void Process_vkCreateBuffer(const ApiCallInfo& call_info, args::CreateBuffer& args) override;

    void Process_vkCreateCommandPool(const ApiCallInfo& call_info, args::CreateCommandPool& args) override;

    void Process_vkDestroyDescriptorPool(const ApiCallInfo& call_info, args::DestroyDescriptorPool& args) override;

    void Process_vkResetDescriptorPool(const ApiCallInfo& call_info, args::ResetDescriptorPool& args) override;

    void Process_vkAllocateDescriptorSets(const ApiCallInfo& call_info, args::AllocateDescriptorSets& args) override;

    void Process_vkFreeDescriptorSets(const ApiCallInfo& call_info, args::FreeDescriptorSets& args) override;

    void Process_vkCreateFence(const ApiCallInfo& call_info, args::CreateFence& args) override;

    void Process_vkDestroyFence(const ApiCallInfo& call_info, args::DestroyFence& args) override;

    void Process_vkQueueBindSparse(const ApiCallInfo& call_info, args::QueueBindSparse& args) override;

    void Process_vkCreateEvent(const ApiCallInfo& call_info, args::CreateEvent& args) override;

    void Process_vkDestroyEvent(const ApiCallInfo& call_info, args::DestroyEvent& args) override;

    void Process_vkQueueSubmit(const ApiCallInfo& call_info, args::QueueSubmit& args) override;
    void Process_vkQueueSubmit2KHR(const ApiCallInfo& call_info, args::QueueSubmit2KHR& args) override;
    void Process_vkQueueSubmit2(const ApiCallInfo& call_info, args::QueueSubmit2& args) override;

    // Buffer queue-family ownership tracking (VK_SHARING_MODE_EXCLUSIVE only). See BufferTracking below.
    void Process_vkCmdCopyBuffer(const ApiCallInfo& call_info, args::CmdCopyBuffer& args) override;
    void Process_vkCmdCopyBuffer2(const ApiCallInfo& call_info, args::CmdCopyBuffer2& args) override;
    void Process_vkCmdCopyBuffer2KHR(const ApiCallInfo& call_info, args::CmdCopyBuffer2KHR& args) override;
    void Process_vkCmdFillBuffer(const ApiCallInfo& call_info, args::CmdFillBuffer& args) override;
    void Process_vkCmdUpdateBuffer(const ApiCallInfo& call_info, args::CmdUpdateBuffer& args) override;
    void Process_vkCmdBindVertexBuffers(const ApiCallInfo& call_info, args::CmdBindVertexBuffers& args) override;
    void Process_vkCmdBindVertexBuffers2(const ApiCallInfo& call_info, args::CmdBindVertexBuffers2& args) override;
    void Process_vkCmdBindVertexBuffers2EXT(const ApiCallInfo&              call_info,
                                            args::CmdBindVertexBuffers2EXT& args) override;
    void Process_vkCmdBindIndexBuffer(const ApiCallInfo& call_info, args::CmdBindIndexBuffer& args) override;
    void Process_vkCmdBindIndexBuffer2(const ApiCallInfo& call_info, args::CmdBindIndexBuffer2& args) override;
    void Process_vkCmdBindIndexBuffer2KHR(const ApiCallInfo& call_info, args::CmdBindIndexBuffer2KHR& args) override;
    void Process_vkCmdDrawIndirect(const ApiCallInfo& call_info, args::CmdDrawIndirect& args) override;
    void Process_vkCmdDrawIndexedIndirect(const ApiCallInfo& call_info, args::CmdDrawIndexedIndirect& args) override;
    void Process_vkCmdDrawIndirectCount(const ApiCallInfo& call_info, args::CmdDrawIndirectCount& args) override;
    void Process_vkCmdDrawIndirectCountKHR(const ApiCallInfo& call_info, args::CmdDrawIndirectCountKHR& args) override;
    void Process_vkCmdDrawIndexedIndirectCount(const ApiCallInfo&                 call_info,
                                               args::CmdDrawIndexedIndirectCount& args) override;
    void Process_vkCmdDrawIndexedIndirectCountKHR(const ApiCallInfo&                    call_info,
                                                  args::CmdDrawIndexedIndirectCountKHR& args) override;
    void Process_vkCmdDispatchIndirect(const ApiCallInfo& call_info, args::CmdDispatchIndirect& args) override;
    void Process_vkCmdCopyBufferToImage(const ApiCallInfo& call_info, args::CmdCopyBufferToImage& args) override;
    void Process_vkCmdCopyBufferToImage2(const ApiCallInfo& call_info, args::CmdCopyBufferToImage2& args) override;
    void Process_vkCmdCopyBufferToImage2KHR(const ApiCallInfo&              call_info,
                                            args::CmdCopyBufferToImage2KHR& args) override;
    void Process_vkCmdCopyImageToBuffer(const ApiCallInfo& call_info, args::CmdCopyImageToBuffer& args) override;
    void Process_vkCmdCopyImageToBuffer2(const ApiCallInfo& call_info, args::CmdCopyImageToBuffer2& args) override;
    void Process_vkCmdCopyImageToBuffer2KHR(const ApiCallInfo&              call_info,
                                            args::CmdCopyImageToBuffer2KHR& args) override;
    void Process_vkCmdCopyQueryPoolResults(const ApiCallInfo& call_info, args::CmdCopyQueryPoolResults& args) override;
    void Process_vkCmdPipelineBarrier(const ApiCallInfo& call_info, args::CmdPipelineBarrier& args) override;
    void Process_vkCmdPipelineBarrier2(const ApiCallInfo& call_info, args::CmdPipelineBarrier2& args) override;
    void Process_vkCmdPipelineBarrier2KHR(const ApiCallInfo& call_info, args::CmdPipelineBarrier2KHR& args) override;
    void Process_vkCmdWaitEvents(const ApiCallInfo& call_info, args::CmdWaitEvents& args) override;
    void Process_vkCmdWaitEvents2(const ApiCallInfo& call_info, args::CmdWaitEvents2& args) override;
    void Process_vkCmdWaitEvents2KHR(const ApiCallInfo& call_info, args::CmdWaitEvents2KHR& args) override;
    void Process_vkCmdExecuteCommands(const ApiCallInfo& call_info, args::CmdExecuteCommands& args) override;
    void Process_vkBeginCommandBuffer(const ApiCallInfo& call_info, args::BeginCommandBuffer& args) override;
    void Process_vkResetCommandBuffer(const ApiCallInfo& call_info, args::ResetCommandBuffer& args) override;

    void Process_vkCreateSemaphore(const ApiCallInfo& call_info, args::CreateSemaphore& args) override;
    void Process_vkDestroySemaphore(const ApiCallInfo& call_info, args::DestroySemaphore& args) override;

    void Process_vkAcquireNextImageKHR(const ApiCallInfo& call_info, args::AcquireNextImageKHR& args) override;
    void Process_vkAcquireNextImage2KHR(const ApiCallInfo& call_info, args::AcquireNextImage2KHR& args) override;

    void Process_vkQueuePresentKHR(const ApiCallInfo& call_info, args::QueuePresentKHR& args) override;

    void Process_vkMapMemory(const ApiCallInfo& call_info, args::MapMemory& args) override;

    void Process_vkUnmapMemory(const ApiCallInfo& call_info, args::UnmapMemory& args) override;

    void Process_vkAcquireProfilingLockKHR(const ApiCallInfo& call_info, args::AcquireProfilingLockKHR& args) override;

    void Process_vkReleaseProfilingLockKHR(const ApiCallInfo& call_info, args::ReleaseProfilingLockKHR& args) override;

    void Process_vkDestroyDevice(const ApiCallInfo& call_info, args::DestroyDevice& args) override;

    virtual void StartLooping() override;

    // Private declarations
  private:
    void RemovePoolDanglingCreateDescriptors(format::HandleId descriptorPool);

    struct FenceTracking
    {
        std::unordered_map<format::HandleId, bool> initial_fence_states_;
    };
    void TrackFenceStates();
    void TrackFenceState(format::HandleId device, format::HandleId fence);
    void FixupDeviceFences(format::HandleId device, format::HandleId queue);
    void FrameBoundaryEndOfFrame(format::HandleId queue, PNextNode* pNext);

    struct EventTracking
    {
        std::unordered_map<format::HandleId, bool> initial_event_states_;
    };
    void TrackEventStates();
    void TrackEventState(format::HandleId device, format::HandleId event);
    void FixupDeviceEvents(format::HandleId device);
    void FixupDeviceObjects(format::HandleId device, format::HandleId queue);

    struct SemaphoreTracking
    {
        SemaphoreTracking(VkDevice                           device,
                          const graphics::VulkanDeviceTable& device_table,
                          CommonObjectInfoTable&             object_table) :
            device_(device),
            device_table_(device_table), object_table_(object_table)
        {}

        /// Semaphores waited on by any submit inside the loop range that are expected
        /// to be signaled by a submission enqueued before start looping.
        /// These semaphores will be synthetically signaled before repeating the loop range.
        std::unordered_set<format::HandleId> before_loop_signaled_semaphores_;

        /// Semaphores signaled by any submit inside the loop range that are expected
        /// to be waited by a submission enqueued after looping.
        /// These semaphores will be synthetically waited on before repeating the loop range.
        std::unordered_set<format::HandleId> in_loop_signaled_semaphores_;

        /// Timeline semaphore values at the start of the loop range.
        std::unordered_map<format::HandleId, uint64_t> initial_timeline_values_;

        bool IsBinary(format::HandleId semaphore) const;

        void ClassifySignal(format::HandleId semaphore);
        void ClassifyWait(format::HandleId semaphore);

        void TrackSemaphores(const args::QueueSubmit& submit_info);
        void TrackSemaphores(const args::QueueSubmit2KHR& submit_info);
        void TrackSemaphores(const args::QueueSubmit2& submit_info);
        void TrackSemaphores(const args::QueuePresentKHR& present_info);
        void TrackSemaphores(const args::AcquireNextImageKHR& acquire_info);
        void TrackSemaphores(const args::AcquireNextImage2KHR& acquire_info);

        void TrackTimelineValue(format::HandleId semaphore);

        void FixupSemaphores(format::HandleId queue);
        void FixupBinarySemaphores(format::HandleId queue);
        void FixupTimelineSemaphores(format::HandleId queue);

        bool IsFixable(const VulkanSemaphoreInfo* semaphore_info) const;

        VkDevice                           device_;
        const graphics::VulkanDeviceTable& device_table_;
        CommonObjectInfoTable&             object_table_;
    };

    SemaphoreTracking& GetSemaphoreTracking(format::HandleId device);
    void               TrackSemaphoreStates();

    /// Tracks a device-local copy of each buffer's contents at the start of the loop range so that GPU
    /// writes made to the buffer during the loop can be undone before each repetition.
    struct BufferTracking
    {
        BufferTracking(format::HandleId                         device_id,
                       const graphics::VulkanDeviceTable&       device_table,
                       CommonObjectInfoTable&                   object_table,
                       std::shared_ptr<VulkanResourceAllocator> allocator,
                       const VkPhysicalDeviceMemoryProperties*  memory_properties) :
            device_id_(device_id),
            device_table_(device_table), object_table_(object_table), allocator_(allocator),
            memory_properties_(memory_properties)
        {}

        struct ShadowBuffer
        {
            VkBuffer                              buffer{ VK_NULL_HANDLE };
            VkDeviceMemory                        memory{ VK_NULL_HANDLE };
            VkDeviceSize                          size{ 0 };
            VulkanResourceAllocator::ResourceData alloc_data{ 0 };
            VulkanResourceAllocator::MemoryData   mem_data{ 0 };
        };

        void RecordInitialState(const std::vector<format::HandleId>& buffer_ids);
        void Restore(bool is_first_iteration);
        void DestroyShadowBuffers();

        format::HandleId                                   device_id_;
        const graphics::VulkanDeviceTable&                 device_table_;
        CommonObjectInfoTable&                             object_table_;
        std::shared_ptr<VulkanResourceAllocator>           allocator_;
        const VkPhysicalDeviceMemoryProperties*            memory_properties_;
        std::unordered_map<format::HandleId, ShadowBuffer> shadow_buffers_;

        std::unordered_map<uint32_t, std::vector<format::HandleId>> buffer_ids_by_family_;
    };

    BufferTracking& GetBufferTracking(format::HandleId device);
    void            RecordBufferStates();
    void            FixupDeviceBuffers(format::HandleId device);
    void            ResetBufferTracking();
    void            ResetBufferTracking(format::HandleId device);

    // Direct/first-use tracking for a single buffer referenced by command_buffer_id
    void TrackBufferQueueFamilyUsage(format::HandleId command_buffer_id, format::HandleId buffer_id);

    // Explicit queue-family-ownership-transfer tracking from a VkBufferMemoryBarrier
    void TrackBufferQueueFamilyTransfer(format::HandleId command_buffer_id,
                                        format::HandleId buffer_id,
                                        uint32_t         src_queue_family_index,
                                        uint32_t         dst_queue_family_index);
    void TrackBufferOwnershipTransfers(format::HandleId                command_buffer_id,
                                       const Decoded_VkDependencyInfo* dependency_info_meta);

    void TrackBufferMemoryBarrierTransfers(format::HandleId                                          command_buffer_id,
                                           const StructPointerDecoder<Decoded_VkBufferMemoryBarrier>&  barriers);
    void TrackBufferMemoryBarrierTransfers(format::HandleId                                           command_buffer_id,
                                           const StructPointerDecoder<Decoded_VkBufferMemoryBarrier2>& barriers);

    // Commits command_buffer_id's pending buffer_queue_family_touches onto
    // VulkanBufferInfo::current_queue_family_index
    void ApplyBufferQueueFamilyOwnership(format::HandleId command_buffer_id);
    void ApplyBufferQueueFamilyOwnership(StructPointerDecoder<Decoded_VkSubmitInfo>& submits);
    void ApplyBufferQueueFamilyOwnership(StructPointerDecoder<Decoded_VkSubmitInfo2>& submits);

    // Private data
  private:
    graphics::FrameLoopInfo& frame_loop_info_;

    VulkanDecoder* decoder_ = nullptr;

    /// A "dangling" resource is one that was either
    /// - created during the loop range but destroyed after it
    /// - or created before the loop range but destroyed during it
    std::unordered_set<format::HandleId> dangling_create_descriptor_sets_;
    std::unordered_set<format::HandleId> dangling_destroy_descriptor_sets_;

    std::unordered_map<format::HandleId, FenceTracking>     per_device_fence_tracking_;
    std::unordered_map<format::HandleId, SemaphoreTracking> per_device_semaphore_tracking_;

    std::unordered_set<format::HandleId>                host_visible_events_;
    std::unordered_map<format::HandleId, EventTracking> per_device_event_tracking_;

    std::unordered_map<format::HandleId, BufferTracking> per_device_buffer_tracking_;

    // Support for vkMapMemory/vkUnMapMemory
    std::set<format::HandleId> mapped_loop_memory;

    // Support for vkAcquireProfilingLockKHR/vkReleaseProfilingLockKHR
    std::unordered_map<format::HandleId, bool> profilingLockState;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_REPLAY_FRAME_LOOP_CONSUMER_H
