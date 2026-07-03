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
#include "decode/api_decoder.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class VulkanReplayFrameLoopConsumer : public VulkanReplayFrameLoopConsumerBase, public LoopStartListener
{
  public:
    VulkanReplayFrameLoopConsumer(std::shared_ptr<application::Application> application,
                                  const VulkanReplayOptions&                options,
                                  graphics::FrameLoopInfo&                  frame_loop_info) :
        VulkanReplayFrameLoopConsumerBase(application, options),
        frame_loop_info_(frame_loop_info),
        uses_frame_markers_(frame_loop_info.UsesFrameMarkers())
    {}

    ~VulkanReplayFrameLoopConsumer() override;

    graphics::FrameLoopInfo& getFrameLoopInfo() override { return frame_loop_info_; }

    virtual void OnLoopStart() override;

    virtual void ProcessStateEndMarker(uint64_t frame_number) override;

    void ProcessFrameEndMarker(uint64_t frame_number) override;

    void Process_vkCreateBuffer(const ApiCallInfo&                                   call_info,
                                VkResult                                             returnValue,
                                format::HandleId                                     device,
                                StructPointerDecoder<Decoded_VkBufferCreateInfo>*    pCreateInfo,
                                StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                                HandlePointerDecoder<VkBuffer>*                      pBuffer) override;

    void Process_vkCreateCommandPool(const ApiCallInfo&                                     call_info,
                                     VkResult                                               returnValue,
                                     format::HandleId                                       device,
                                     StructPointerDecoder<Decoded_VkCommandPoolCreateInfo>* pCreateInfo,
                                     StructPointerDecoder<Decoded_VkAllocationCallbacks>*   pAllocator,
                                     HandlePointerDecoder<VkCommandPool>*                   pCommandPool) override;

    void Process_vkDestroyCommandPool(const ApiCallInfo&                                   call_info,
                                      format::HandleId                                     device,
                                      format::HandleId                                     commandPool,
                                      StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    void Process_vkCreateDescriptorPool(const ApiCallInfo&                                        call_info,
                                        VkResult                                                  returnValue,
                                        format::HandleId                                          device,
                                        StructPointerDecoder<Decoded_VkDescriptorPoolCreateInfo>* pCreateInfo,
                                        StructPointerDecoder<Decoded_VkAllocationCallbacks>*      pAllocator,
                                        HandlePointerDecoder<VkDescriptorPool>* pDescriptorPool) override;

    void Process_vkDestroyDescriptorPool(const ApiCallInfo&                                   call_info,
                                         format::HandleId                                     device,
                                         format::HandleId                                     descriptorPool,
                                         StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    void Process_vkDestroyBuffer(const ApiCallInfo&                                   call_info,
                                 format::HandleId                                     device,
                                 format::HandleId                                     buffer,
                                 StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    void Process_vkDestroyImage(const ApiCallInfo&                                   call_info,
                                format::HandleId                                     device,
                                format::HandleId                                     image,
                                StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    void Process_vkDestroyEvent(const ApiCallInfo&                                   call_info,
                                format::HandleId                                     device,
                                format::HandleId                                     event,
                                StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    void Process_vkResetDescriptorPool(const ApiCallInfo&         call_info,
                                       VkResult                   returnValue,
                                       format::HandleId           device,
                                       format::HandleId           descriptorPool,
                                       VkDescriptorPoolResetFlags flags) override;

    void Process_vkAllocateDescriptorSets(const ApiCallInfo&                                         call_info,
                                          VkResult                                                   returnValue,
                                          format::HandleId                                           device,
                                          StructPointerDecoder<Decoded_VkDescriptorSetAllocateInfo>* pAllocateInfo,
                                          HandlePointerDecoder<VkDescriptorSet>* pDescriptorSets) override;

    void Process_vkFreeDescriptorSets(const ApiCallInfo&                     call_info,
                                      VkResult                               returnValue,
                                      format::HandleId                       device,
                                      format::HandleId                       descriptorPool,
                                      uint32_t                               descriptorSetCount,
                                      HandlePointerDecoder<VkDescriptorSet>* pDescriptorSets) override;

    void Process_vkQueuePresentKHR(const ApiCallInfo&                              call_info,
                                   VkResult                                        returnValue,
                                   format::HandleId                                queue,
                                   StructPointerDecoder<Decoded_VkPresentInfoKHR>* pPresentInfo) override;

    void Process_vkQueueSubmit(const ApiCallInfo&                          call_info,
                               VkResult                                    returnValue,
                               format::HandleId                            queue,
                               uint32_t                                    submitCount,
                               StructPointerDecoder<Decoded_VkSubmitInfo>* pSubmits,
                               format::HandleId                            fence) override;

    void Process_vkQueueSubmit2(const ApiCallInfo&                           call_info,
                                VkResult                                     returnValue,
                                format::HandleId                             queue,
                                uint32_t                                     submitCount,
                                StructPointerDecoder<Decoded_VkSubmitInfo2>* pSubmits,
                                format::HandleId                             fence) override;

    void Process_vkQueueSubmit2KHR(const ApiCallInfo&                           call_info,
                                   VkResult                                     returnValue,
                                   format::HandleId                             queue,
                                   uint32_t                                     submitCount,
                                   StructPointerDecoder<Decoded_VkSubmitInfo2>* pSubmits,
                                   format::HandleId                             fence) override;

    void Process_vkAllocateCommandBuffers(const ApiCallInfo&                                         call_info,
                                          VkResult                                                   returnValue,
                                          format::HandleId                                           device,
                                          StructPointerDecoder<Decoded_VkCommandBufferAllocateInfo>* pAllocateInfo,
                                          HandlePointerDecoder<VkCommandBuffer>* pCommandBuffers) override;

    void Process_vkFreeCommandBuffers(const ApiCallInfo&                     call_info,
                                      format::HandleId                       device,
                                      format::HandleId                       commandPool,
                                      uint32_t                               commandBufferCount,
                                      HandlePointerDecoder<VkCommandBuffer>* pCommandBuffers) override;

    void Process_vkBeginCommandBuffer(const ApiCallInfo&                                      call_info,
                                      VkResult                                                returnValue,
                                      format::HandleId                                        commandBuffer,
                                      StructPointerDecoder<Decoded_VkCommandBufferBeginInfo>* pBeginInfo) override;

    void Process_vkEndCommandBuffer(const ApiCallInfo& call_info,
                                    VkResult           returnValue,
                                    format::HandleId   commandBuffer) override;

    void Process_vkMapMemory(const ApiCallInfo&               call_info,
                             VkResult                         returnValue,
                             format::HandleId                 device,
                             format::HandleId                 memory,
                             VkDeviceSize                     offset,
                             VkDeviceSize                     size,
                             VkMemoryMapFlags                 flags,
                             PointerDecoder<uint64_t, void*>* ppData) override;

    void Process_vkUnmapMemory(const ApiCallInfo& call_info, format::HandleId device, format::HandleId memory) override;

    void Process_vkAcquireProfilingLockKHR(const ApiCallInfo&                                           call_info,
                                           VkResult                                                     returnValue,
                                           format::HandleId                                             device,
                                           StructPointerDecoder<Decoded_VkAcquireProfilingLockInfoKHR>* pInfo) override;

    void Process_vkReleaseProfilingLockKHR(const ApiCallInfo& call_info, format::HandleId device) override;

    virtual void Process_vkCmdExecuteCommands(const ApiCallInfo&                     call_info,
                                              format::HandleId                       commandBuffer,
                                              uint32_t                               commandBufferCount,
                                              HandlePointerDecoder<VkCommandBuffer>* pCommandBuffers) override;

    virtual void Process_vkCreateEvent(const ApiCallInfo&                                   call_info,
                                       VkResult                                             returnValue,
                                       format::HandleId                                     device,
                                       StructPointerDecoder<Decoded_VkEventCreateInfo>*     pCreateInfo,
                                       StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                                       HandlePointerDecoder<VkEvent>*                       pEvent) override;

    // Private declarations
  private:
    void RemovePoolDanglingCreateDescriptors(format::HandleId descriptorPool);
    void FixupDeviceFences(format::HandleId device, format::HandleId queue);
    void CaptureInitialFenceStates();
    void CaptureInitialEventStates();
    void RestoreInitialEventStates();
    void ClassifyActiveCommandPools();
    void ResetActiveCommandPools();
    void DestroyShadowPools();
    void RebeginCommandBuffer(format::HandleId cb_id);
    void RecreateAndRebeginCommandBuffer(format::HandleId cb_id, bool rebegin);
    void ResetLoopBoundary();
    // Removed rendering layout tracking declarations

    // Image layout restoration helpers
    void RecordInitialLayouts();
    // Removed ObserveDescriptorSetLayouts
    void RestoreImageLayouts(VkDevice                           device,
                             const graphics::VulkanDeviceTable* device_table,
                             VulkanQueueInfo*                   queue_info);
    bool InitializeRestorationResources(VkDevice device, uint32_t queue_family_index);

    // Private data
  private:
    graphics::FrameLoopInfo& frame_loop_info_;
    bool                     uses_frame_markers_{ false };

    // Removed render_pass_initial_layouts_

    /// A "dangling" resource is one that was either
    /// - created during the loop range but destroyed after it
    /// - or created before the loop range but destroyed during it
    std::unordered_set<format::HandleId> dangling_create_descriptor_pools_;
    std::unordered_set<format::HandleId> dangling_create_descriptor_sets_;
    std::unordered_set<format::HandleId> dangling_destroy_descriptor_pools_;
    std::unordered_set<format::HandleId> dangling_destroy_descriptor_sets_;
    std::unordered_set<format::HandleId> dangling_create_command_pools_;
    std::unordered_set<format::HandleId> dangling_destroy_command_pools_;
    std::unordered_set<format::HandleId> dangling_allocate_command_buffers_;
    std::unordered_set<format::HandleId> dangling_free_command_buffers_;

    std::unordered_map<format::HandleId, VkResult> initial_fence_states_;
    std::unordered_map<format::HandleId, bool>     initial_event_states_;
    std::unordered_set<format::HandleId>           device_only_events_;

    // Support for vkMapMemory/vkUnMapMemory
    std::set<format::HandleId> mapped_loop_memory;

    // Support for vkAcquireProfilingLockKHR/vkReleaseProfilingLockKHR
    std::unordered_map<format::HandleId, bool> profilingLockState;

    // Support for loop command pool resetting
    std::unordered_map<VkDevice, std::unordered_set<VkCommandPool>> active_command_pools_;

    // Dynamic command pool reset safety analysis
    std::unordered_set<format::HandleId>                            loop_recorded_cbs_;
    std::unordered_set<format::HandleId>                            loop_ended_cbs_;
    std::unordered_set<format::HandleId>                            loop_submitted_cbs_;
    bool                                                            loop_state_classified_ = false;
    std::unordered_map<VkDevice, std::unordered_set<VkCommandPool>> pools_to_reset_;
    std::vector<format::HandleId>                                   cbs_to_rebegin_;
    std::vector<format::HandleId>                                   cbs_to_recreate_with_rebegin_;
    std::vector<format::HandleId>                                   cbs_to_recreate_without_rebegin_;
    std::unordered_map<VkCommandPool, VkCommandPool>                shadow_pools_;
    std::unordered_set<VkCommandPool>                               pools_requiring_shadows_;
    std::unordered_set<VkCommandBuffer>                             redirected_cbs_;
    bool                                                            setup_complete_{ false };

    // Image layout restoration data
    std::unordered_map<format::HandleId, ImageSubresourceLayoutTracker> initial_image_layouts_;

    VkCommandPool   restoration_command_pool_{ VK_NULL_HANDLE };
    VkCommandBuffer restoration_command_buffer_{ VK_NULL_HANDLE };
    VkDevice        restoration_device_{ VK_NULL_HANDLE };

    // Buffer restoration data
    struct ShadowBufferInfo
    {
        format::HandleId                      parent_id{ format::kNullHandleId };
        VkBuffer                              shadow_buffer{ VK_NULL_HANDLE };
        VkDeviceMemory                        shadow_memory{ VK_NULL_HANDLE };
        VkDeviceSize                          size{ 0 };
        VulkanResourceAllocator::ResourceData alloc_data{ 0 };
        VulkanResourceAllocator::MemoryData   mem_data{ 0 };
    };
    std::unordered_map<format::HandleId, ShadowBufferInfo> shadow_buffers_;

    // Image restoration data
    struct ShadowImageInfo
    {
        format::HandleId                      parent_id{ format::kNullHandleId };
        VkImage                               shadow_image{ VK_NULL_HANDLE };
        VkDeviceMemory                        shadow_memory{ VK_NULL_HANDLE };
        VulkanResourceAllocator::ResourceData alloc_data{ 0 };
        VulkanResourceAllocator::MemoryData   mem_data{ 0 };
        VkFormat                              format;
        VkExtent3D                            extent;
        uint32_t                              mip_levels;
        uint32_t                              array_layers;
        VkSampleCountFlagBits                 samples;
        VkImageLayout                         current_layout{ VK_IMAGE_LAYOUT_UNDEFINED };
    };
    std::unordered_map<format::HandleId, ShadowImageInfo> shadow_images_;

    void     LazyBackupImagesForSubmit(VkQueue queue, uint32_t cb_count, const format::HandleId* cb_ids);
    void     RestoreImageContents(VkDevice                           device,
                                  const graphics::VulkanDeviceTable* device_table,
                                  VulkanQueueInfo*                   queue_info);
    void     DestroyShadowImages();
    VkResult CreateShadowImage(VkDevice                               device,
                               const VulkanImageInfo*                 orig_info,
                               VkImage*                               shadow_image,
                               VkDeviceMemory*                        shadow_memory,
                               VulkanResourceAllocator::ResourceData* alloc_data,
                               VulkanResourceAllocator::MemoryData*   mem_data);

    void RecordInitialBufferStates(VkDevice                           device,
                                   const graphics::VulkanDeviceTable* device_table,
                                   VulkanQueueInfo*                   queue_info);
    void RestoreBufferStates(VkDevice                           device,
                             const graphics::VulkanDeviceTable* device_table,
                             VulkanQueueInfo*                   queue_info);
    void DestroyShadowBuffers();

    // Support for loop boundary resetting across present or non-present submissions
    VkDevice                           active_device_{ VK_NULL_HANDLE };
    const graphics::VulkanDeviceTable* active_device_table_{ nullptr };
    VulkanQueueInfo*                   active_queue_info_{ nullptr };
    format::HandleId                   active_queue_id_{ format::kNullHandleId };

    void UpdateActiveQueueInfo(format::HandleId queue);

    // Synthetic command buffer re-begin tracking
    struct SavedCommandBufferBeginInfo
    {
        VkDevice                       device{ VK_NULL_HANDLE };
        VkCommandBufferUsageFlags      flags{ 0 };
        bool                           has_inheritance_info{ false };
        VkCommandBufferInheritanceInfo inheritance_info{};
    };

    template <typename T>
    void TrackSubmittedCommandBuffers(StructPointerDecoder<T>* pSubmits);

    void ExtractAndTrackCommandBuffers(const Decoded_VkSubmitInfo& submit);
    void ExtractAndTrackCommandBuffers(const Decoded_VkSubmitInfo2& submit);

    template <typename T>
    void BackupImagesForSubmit(format::HandleId queue, StructPointerDecoder<T>* pSubmits);

    void ExtractCommandBuffersForBackup(const Decoded_VkSubmitInfo& submit, std::vector<format::HandleId>& cb_ids);
    void ExtractCommandBuffersForBackup(const Decoded_VkSubmitInfo2& submit, std::vector<format::HandleId>& cb_ids);

    template <typename T>
    void ObserveAndTransitionSubmitDescriptorSets(StructPointerDecoder<T>* pSubmits);

    void ObserveAndTransitionDescriptorSets(const Decoded_VkSubmitInfo& submit);
    void ObserveAndTransitionDescriptorSets(const Decoded_VkSubmitInfo2& submit);
    void ObserveCommandBufferDescriptorSets(format::HandleId command_buffer_id);

    /**
     * @brief Checks if the replayer is in the setup (state restoration) phase before the loop starts.
     */
    bool IsBeforeLoop() const { return frame_loop_info_.IsLooping() && !setup_complete_; }

    /**
     * @brief Checks if the replayer is currently playing the very first iteration of the loop.
     */
    bool IsLoopFirstIteration() const
    {
        return frame_loop_info_.IsLooping() && setup_complete_ && !frame_loop_info_.IsRepetition();
    }

    /**
     * @brief Checks if the replayer is currently playing a repeated (non-first) iteration of the loop.
     */
    bool IsLoopNotFirstIteration() const
    {
        return frame_loop_info_.IsLooping() && setup_complete_ && frame_loop_info_.IsRepetition();
    }

    /**
     * @brief Checks if the replayer is actively replaying the loop range (any iteration).
     */
    bool IsLoopAnyIteration() const { return frame_loop_info_.IsLooping() && setup_complete_; }

    /**
     * @brief Checks if the replayer is currently playing the final iteration of the loop.
     */
    bool IsLoopLastIteration() const
    {
        return frame_loop_info_.IsLooping() && setup_complete_ && frame_loop_info_.IsFinalIteration();
    }

    /**
     * @brief Checks if the replayer should use frame markers for boundary synchronization.
     */
    bool ShouldUseFrameMarkers() const { return frame_loop_info_.UsesFrameMarkers(); }

    bool ShouldIgnoreRecordingCommand(format::HandleId commandBuffer) const override
    {
        return IsLoopNotFirstIteration() && loop_start_recording_cbs_.contains(commandBuffer);
    }

    void CollectTouchedImagesFromCommandBuffer(format::HandleId commandBuffer);

    std::unordered_set<format::HandleId>                              recording_cbs_;
    std::unordered_set<format::HandleId>                              initial_loop_recording_cbs_;
    std::unordered_set<format::HandleId>                              loop_start_recording_cbs_;
    std::unordered_set<format::HandleId>                              loop_touched_images_;
    std::unordered_map<format::HandleId, SavedCommandBufferBeginInfo> cb_begin_infos_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_REPLAY_FRAME_LOOP_CONSUMER_H
