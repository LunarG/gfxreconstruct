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

    graphics::FrameLoopInfo& getFrameLoopInfo() override { return frame_loop_info_; }

    void Process_vkCreateCommandPool(const ApiCallInfo&                                     call_info,
                                     VkResult                                               returnValue,
                                     format::HandleId                                       device,
                                     StructPointerDecoder<Decoded_VkCommandPoolCreateInfo>* pCreateInfo,
                                     StructPointerDecoder<Decoded_VkAllocationCallbacks>*   pAllocator,
                                     HandlePointerDecoder<VkCommandPool>*                   pCommandPool) override;

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

    void Process_vkWaitForFences(const ApiCallInfo&             call_info,
                                 VkResult                       returnValue,
                                 format::HandleId               device,
                                 uint32_t                       fenceCount,
                                 HandlePointerDecoder<VkFence>* pFences,
                                 VkBool32                       waitAll,
                                 uint64_t                       timeout) override;

    void Process_vkQueueSubmit(const ApiCallInfo&                          call_info,
                               VkResult                                    returnValue,
                               format::HandleId                            queue,
                               uint32_t                                    submitCount,
                               StructPointerDecoder<Decoded_VkSubmitInfo>* pSubmits,
                               format::HandleId                            fence) override;

    void Process_vkAcquireNextImageKHR(const ApiCallInfo&        call_info,
                                       VkResult                  returnValue,
                                       format::HandleId          device,
                                       format::HandleId          swapchain,
                                       uint64_t                  timeout,
                                       format::HandleId          semaphore,
                                       format::HandleId          fence,
                                       PointerDecoder<uint32_t>* pImageIndex) override;

    void Process_vkQueuePresentKHR(const ApiCallInfo&                              call_info,
                                   VkResult                                        returnValue,
                                   format::HandleId                                queue,
                                   StructPointerDecoder<Decoded_VkPresentInfoKHR>* pPresentInfo) override;

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

    // Private declarations
  private:
    void RemovePoolDanglingCreateDescriptors(format::HandleId descriptorPool);
    struct FenceTracking
    {
        std::unordered_map<format::HandleId, uint32_t> signaled_fences_;
        std::unordered_map<format::HandleId, uint32_t> waited_upon_fences_;
    };
    void FixupDeviceFences(format::HandleId device, format::HandleId queue);

    // Support for vkMapMemory/vkUnMapMemory
    bool inMappedLoopMemory(format::HandleId handle)
    {
        return std::find(mappedLoopMemory.begin(), mappedLoopMemory.end(), handle) != mappedLoopMemory.end();
    }

    // Private data
  private:
    graphics::FrameLoopInfo& frame_loop_info_;

    /// A "dangling" resource is one that was either
    /// - created during the loop range but destroyed after it
    /// - or created before the loop range but destroyed during it
    std::unordered_set<format::HandleId> dangling_create_descriptor_pools_;
    std::unordered_set<format::HandleId> dangling_create_descriptor_sets_;
    std::unordered_set<format::HandleId> dangling_destroy_descriptor_pools_;
    std::unordered_set<format::HandleId> dangling_destroy_descriptor_sets_;

    std::unordered_map<format::HandleId, FenceTracking> per_device_fence_tracking_;

    // Support for vkMapMemory/vkUnMapMemory
    std::set<format::HandleId> mappedLoopMemory;

    // Support for vkAcquireProfilingLockKHR/vkReleaseProfilingLockKHR
    std::unordered_map<format::HandleId, bool> profilingLockState;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_REPLAY_FRAME_LOOP_CONSUMER_H
