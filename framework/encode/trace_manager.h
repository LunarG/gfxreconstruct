/*
** Copyright (c) 2018-2019 Valve Corporation
** Copyright (c) 2018-2019 LunarG, Inc.
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

#ifndef GFXRECON_ENCODE_TRACE_MANAGER_H
#define GFXRECON_ENCODE_TRACE_MANAGER_H

#include "encode/capture_settings.h"
#include "encode/descriptor_update_template_info.h"
#include "encode/memory_tracker.h"
#include "encode/parameter_encoder.h"
#include "encode/vulkan_state_tracker.h"
#include "format/api_call_id.h"
#include "format/format.h"
#include "generated/generated_vulkan_dispatch_table.h"
#include "util/compressor.h"
#include "util/defines.h"
#include "util/file_output_stream.h"
#include "util/memory_output_stream.h"

#include "vulkan/vulkan.h"

#include <cassert>
#include <memory>
#include <mutex>
#include <string>
#include <unordered_map>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

class TraceManager
{
  public:
    // Register special layer provided functions, which perform layer specific initialization.
    // These must be set before the application calls vkCreateInstance.
    static void SetLayerFuncs(PFN_vkCreateInstance create_instance, PFN_vkCreateDevice create_device);

    // Creates the trace manager instance if none exists, or increments a reference count if an instance already exists.
    // Intended to be called by the layer's vkCreateInstance function, before the driver's vkCreateInstance has been
    // called, to initialize capture resources.
    static bool CreateInstance();

    // Called by the layer's vkCreateInstance function, after the driver's vkCreateInstance function has been called, to
    // check for failure.  If vkCreateInstance failed, the reference count will be decremented and resources will be
    // released as necessry.  Allows a failed vkCreateInstance call to be logged to the capture file while performing
    // the appropriate resource cleanup.
    static void CheckCreateInstanceStatus(VkResult result);

    // Dectement the instance reference count, releasing reources when the count reaches zero.  Ignored if the count is
    // already zero.
    static void DestroyInstance();

    static TraceManager* Get() { return instance_; }

    static const LayerTable* GetLayerTable() { return &layer_table_; }

    void AddInstanceTable(VkInstance instance, PFN_vkGetInstanceProcAddr gpa);

    void AddDeviceTable(VkDevice device, PFN_vkGetDeviceProcAddr gpa);

    const InstanceTable* GetInstanceTable(const void* handle) const;

    const DeviceTable* GetDeviceTable(const void* handle) const;

    ParameterEncoder* BeginTrackedApiCallTrace(format::ApiCallId call_id)
    {
        if (capture_mode_ != kModeDisabled)
        {
            return InitApiCallTrace(call_id);
        }

        return nullptr;
    }

    ParameterEncoder* BeginApiCallTrace(format::ApiCallId call_id)
    {
        if ((capture_mode_ & kModeWrite) == kModeWrite)
        {
            return InitApiCallTrace(call_id);
        }

        return nullptr;
    }

    // Single object creation.
    template <typename ParentHandle, typename Wrapper, typename CreateInfo>
    void EndCreateApiCallTrace(VkResult                      result,
                               ParentHandle                  parent_handle,
                               typename Wrapper::HandleType* handle,
                               const CreateInfo*             create_info,
                               ParameterEncoder*             encoder)
    {
        if (((capture_mode_ & kModeTrack) == kModeTrack) && result == VK_SUCCESS)
        {
            assert(state_tracker_ != nullptr);

            auto thread_data = GetThreadData();
            assert(thread_data != nullptr);

            state_tracker_->AddEntry<ParentHandle, Wrapper, CreateInfo>(
                parent_handle, handle, create_info, thread_data->call_id_, thread_data->parameter_buffer_.get());
        }

        EndApiCallTrace(encoder);
    }

    // Pool allocation.
    template <typename ParentHandle, typename Wrapper, typename AllocateInfo>
    void EndPoolCreateApiCallTrace(VkResult                      result,
                                   ParentHandle                  parent_handle,
                                   uint32_t                      count,
                                   typename Wrapper::HandleType* handles,
                                   const AllocateInfo*           alloc_info,
                                   ParameterEncoder*             encoder)
    {
        if (((capture_mode_ & kModeTrack) == kModeTrack) && (result == VK_SUCCESS) && (handles != nullptr))
        {
            assert(state_tracker_ != nullptr);

            auto thread_data = GetThreadData();
            assert(thread_data != nullptr);

            state_tracker_->AddPoolEntry<ParentHandle, Wrapper, AllocateInfo>(
                parent_handle, count, handles, alloc_info, thread_data->call_id_, thread_data->parameter_buffer_.get());
        }

        EndApiCallTrace(encoder);
    }

    // Multiple object creation.
    template <typename ParentHandle, typename Wrapper, typename CreateInfo>
    void EndGroupCreateApiCallTrace(VkResult                      result,
                                    ParentHandle                  parent_handle,
                                    uint32_t                      count,
                                    typename Wrapper::HandleType* handles,
                                    const CreateInfo*             create_infos,
                                    ParameterEncoder*             encoder)
    {
        if (((capture_mode_ & kModeTrack) == kModeTrack) && (result == VK_SUCCESS) && (handles != nullptr))
        {
            assert(state_tracker_ != nullptr);

            auto thread_data = GetThreadData();
            assert(thread_data != nullptr);

            state_tracker_->AddGroupEntry<ParentHandle, Wrapper, CreateInfo>(parent_handle,
                                                                             count,
                                                                             handles,
                                                                             create_infos,
                                                                             thread_data->call_id_,
                                                                             thread_data->parameter_buffer_.get());
        }

        EndApiCallTrace(encoder);
    }

    // Single object destruction.
    template <typename Wrapper>
    void EndDestroyApiCallTrace(typename Wrapper::HandleType handle, ParameterEncoder* encoder)
    {
        if ((capture_mode_ & kModeTrack) == kModeTrack)
        {
            assert(state_tracker_ != nullptr);
            state_tracker_->RemoveEntry<Wrapper>(handle);
        }

        EndApiCallTrace(encoder);
    }

    // Multiple object destruction.
    template <typename Wrapper>
    void EndDestroyApiCallTrace(uint32_t count, const typename Wrapper::HandleType* handles, ParameterEncoder* encoder)
    {
        if ((capture_mode_ & kModeTrack) == kModeTrack)
        {
            assert(state_tracker_ != nullptr);

            for (uint32_t i = 0; i < count; ++i)
            {
                state_tracker_->RemoveEntry<Wrapper>(handles[i]);
            }
        }

        EndApiCallTrace(encoder);
    }

    void EndCommandApiCallTrace(VkCommandBuffer command_buffer, ParameterEncoder* encoder)
    {
        if ((capture_mode_ & kModeTrack) == kModeTrack)
        {
            assert(state_tracker_ != nullptr);

            auto thread_data = GetThreadData();
            assert(thread_data != nullptr);

            state_tracker_->TrackCommand(command_buffer, thread_data->call_id_, thread_data->parameter_buffer_.get());
        }

        EndApiCallTrace(encoder);
    }

    void EndApiCallTrace(ParameterEncoder* encoder);

    void EndFrame();

    void WriteDisplayMessageCmd(const char* message);

    bool GetDescriptorUpdateTemplateInfo(VkDescriptorUpdateTemplate update_template,
                                         const UpdateTemplateInfo** info) const;

    void PostProcess_vkGetPhysicalDeviceMemoryProperties(VkPhysicalDevice                  physicalDevice,
                                                         VkPhysicalDeviceMemoryProperties* pMemoryProperties)
    {
        if ((capture_mode_ & kModeTrack) == kModeTrack)
        {
            assert(state_tracker_ != nullptr);
            state_tracker_->TrackPhysicalDeviceMemoryProperties(physicalDevice, pMemoryProperties);
        }
    }

    void PreProcess_vkCreateSwapchain(VkDevice                        device,
                                      const VkSwapchainCreateInfoKHR* pCreateInfo,
                                      const VkAllocationCallbacks*    pAllocator,
                                      VkSwapchainKHR*                 pSwapchain);

    void PostProcess_vkAllocateMemory(VkResult                     result,
                                      VkDevice                     device,
                                      const VkMemoryAllocateInfo*  pAllocateInfo,
                                      const VkAllocationCallbacks* pAllocator,
                                      VkDeviceMemory*              pMemory);

    void PostProcess_vkAcquireNextImageKHR(
        VkResult result, VkDevice, VkSwapchainKHR, uint64_t, VkSemaphore semaphore, VkFence, uint32_t*)
    {
        if (((capture_mode_ & kModeTrack) == kModeTrack) && (result == VK_SUCCESS))
        {
            assert(state_tracker_ != nullptr);
            state_tracker_->TrackSemaphoreSignalState(0, nullptr, 1, &semaphore);
        }
    }

    void PostProcess_vkAcquireNextImage2KHR(VkResult result,
                                            VkDevice,
                                            const VkAcquireNextImageInfoKHR* pAcquireInfo,
                                            uint32_t*)
    {
        if (((capture_mode_ & kModeTrack) == kModeTrack) && (result == VK_SUCCESS))
        {
            assert((state_tracker_ != nullptr) && (pAcquireInfo != nullptr));
            state_tracker_->TrackSemaphoreSignalState(0, nullptr, 1, &pAcquireInfo->semaphore);
        }
    }

    void PostProcess_vkQueuePresentKHR(VkResult result, VkQueue, const VkPresentInfoKHR* pPresentInfo)
    {
        if (((capture_mode_ & kModeTrack) == kModeTrack) && (result == VK_SUCCESS))
        {
            assert((state_tracker_ != nullptr) && (pPresentInfo != nullptr));
            state_tracker_->TrackSemaphoreSignalState(
                pPresentInfo->waitSemaphoreCount, pPresentInfo->pWaitSemaphores, 0, nullptr);
        }

        EndFrame();
    }

    void PostProcess_vkQueueBindSparse(
        VkResult result, VkQueue, uint32_t bindInfoCount, const VkBindSparseInfo* pBindInfo, VkFence)
    {
        if (((capture_mode_ & kModeTrack) == kModeTrack) && (result == VK_SUCCESS))
        {
            assert((state_tracker_ != nullptr) && ((bindInfoCount == 0) || (pBindInfo != nullptr)));
            for (uint32_t i = 0; i < bindInfoCount; ++i)
            {
                state_tracker_->TrackSemaphoreSignalState(pBindInfo[i].waitSemaphoreCount,
                                                          pBindInfo[i].pWaitSemaphores,
                                                          pBindInfo[i].signalSemaphoreCount,
                                                          pBindInfo[i].pSignalSemaphores);
            }
        }
    }

    void PostProcess_vkBindBufferMemory(
        VkResult result, VkDevice device, VkBuffer buffer, VkDeviceMemory memory, VkDeviceSize memoryOffset)
    {
        if (((capture_mode_ & kModeTrack) == kModeTrack) && (result == VK_SUCCESS))
        {
            assert(state_tracker_ != nullptr);
            state_tracker_->TrackBufferMemoryBinding(device, buffer, memory, memoryOffset);
        }
    }

    void PostProcess_vkBindImageMemory(
        VkResult result, VkDevice device, VkImage image, VkDeviceMemory memory, VkDeviceSize memoryOffset)
    {
        if (((capture_mode_ & kModeTrack) == kModeTrack) && (result == VK_SUCCESS))
        {
            assert(state_tracker_ != nullptr);
            state_tracker_->TrackImageMemoryBinding(device, image, memory, memoryOffset);
        }
    }

    void PostProcess_vkCmdBeginRenderPass(VkCommandBuffer              commandBuffer,
                                          const VkRenderPassBeginInfo* pRenderPassBegin,
                                          VkSubpassContents            contents)
    {
        if ((capture_mode_ & kModeTrack) == kModeTrack)
        {
            assert(state_tracker_ != nullptr);
            GFXRECON_UNREFERENCED_PARAMETER(contents);
            state_tracker_->TrackBeginRenderPass(commandBuffer, pRenderPassBegin);
        }
    }

    void PostProcess_vkCmdBeginRenderPass2KHR(VkCommandBuffer              commandBuffer,
                                              const VkRenderPassBeginInfo* pRenderPassBegin,
                                              const VkSubpassBeginInfoKHR* pSubpassBeginInfo)
    {
        if ((capture_mode_ & kModeTrack) == kModeTrack)
        {
            assert(state_tracker_ != nullptr);
            GFXRECON_UNREFERENCED_PARAMETER(pSubpassBeginInfo);
            state_tracker_->TrackBeginRenderPass(commandBuffer, pRenderPassBegin);
        }
    }

    void PostProcess_vkCmdEndRenderPass(VkCommandBuffer commandBuffer)
    {
        if ((capture_mode_ & kModeTrack) == kModeTrack)
        {
            assert(state_tracker_ != nullptr);
            state_tracker_->TrackEndRenderPass(commandBuffer);
        }
    }

    void PostProcess_vkCmdEndRenderPass2KHR(VkCommandBuffer commandBuffer, const VkSubpassEndInfoKHR* pSubpassEndInfo)
    {
        if ((capture_mode_ & kModeTrack) == kModeTrack)
        {
            assert(state_tracker_ != nullptr);
            GFXRECON_UNREFERENCED_PARAMETER(pSubpassEndInfo);
            state_tracker_->TrackEndRenderPass(commandBuffer);
        }
    }

    void PostProcess_vkCmdPipelineBarrier(VkCommandBuffer              commandBuffer,
                                          VkPipelineStageFlags         srcStageMask,
                                          VkPipelineStageFlags         dstStageMask,
                                          VkDependencyFlags            dependencyFlags,
                                          uint32_t                     memoryBarrierCount,
                                          const VkMemoryBarrier*       pMemoryBarriers,
                                          uint32_t                     bufferMemoryBarrierCount,
                                          const VkBufferMemoryBarrier* pBufferMemoryBarriers,
                                          uint32_t                     imageMemoryBarrierCount,
                                          const VkImageMemoryBarrier*  pImageMemoryBarriers)
    {
        if ((capture_mode_ & kModeTrack) == kModeTrack)
        {
            assert(state_tracker_ != nullptr);

            GFXRECON_UNREFERENCED_PARAMETER(srcStageMask);
            GFXRECON_UNREFERENCED_PARAMETER(dstStageMask);
            GFXRECON_UNREFERENCED_PARAMETER(dependencyFlags);
            GFXRECON_UNREFERENCED_PARAMETER(memoryBarrierCount);
            GFXRECON_UNREFERENCED_PARAMETER(pMemoryBarriers);
            GFXRECON_UNREFERENCED_PARAMETER(bufferMemoryBarrierCount);
            GFXRECON_UNREFERENCED_PARAMETER(pBufferMemoryBarriers);

            state_tracker_->TrackImageBarriers(commandBuffer, imageMemoryBarrierCount, pImageMemoryBarriers);
        }
    }

    void PostProcess_vkCmdExecuteCommands(VkCommandBuffer        commandBuffer,
                                          uint32_t               commandBufferCount,
                                          const VkCommandBuffer* pCommandBuffers)
    {
        if ((capture_mode_ & kModeTrack) == kModeTrack)
        {
            assert(state_tracker_ != nullptr);
            state_tracker_->TrackExecuteCommands(commandBuffer, commandBufferCount, pCommandBuffers);
        }
    }

    void PostProcess_vkResetCommandPool(VkResult                result,
                                        VkDevice                device,
                                        VkCommandPool           commandPool,
                                        VkCommandPoolResetFlags flags)
    {
        if (((capture_mode_ & kModeTrack) == kModeTrack) && (result == VK_SUCCESS))
        {
            assert(state_tracker_ != nullptr);
            GFXRECON_UNREFERENCED_PARAMETER(device);
            GFXRECON_UNREFERENCED_PARAMETER(flags);
            state_tracker_->TrackResetCommandPool(commandPool);
        }
    }

    void
    PostProcess_vkQueueSubmit(VkResult result, VkQueue, uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence)
    {
        if (((capture_mode_ & kModeTrack) == kModeTrack) && (result == VK_SUCCESS))
        {
            assert((state_tracker_ != nullptr) && ((submitCount == 0) || (pSubmits != nullptr)));

            state_tracker_->TrackImageLayoutTransitions(submitCount, pSubmits);

            for (uint32_t i = 0; i < submitCount; ++i)
            {
                state_tracker_->TrackSemaphoreSignalState(pSubmits[i].waitSemaphoreCount,
                                                          pSubmits[i].pWaitSemaphores,
                                                          pSubmits[i].signalSemaphoreCount,
                                                          pSubmits[i].pSignalSemaphores);
            }
        }
    }

    void PostProcess_vkUpdateDescriptorSets(VkDevice                    device,
                                            uint32_t                    descriptorWriteCount,
                                            const VkWriteDescriptorSet* pDescriptorWrites,
                                            uint32_t                    descriptorCopyCount,
                                            const VkCopyDescriptorSet*  pDescriptorCopies)
    {
        if ((capture_mode_ & kModeTrack) == kModeTrack)
        {
            assert(state_tracker_ != nullptr);
            GFXRECON_UNREFERENCED_PARAMETER(device);
            state_tracker_->TrackUpdateDescriptorSets(
                descriptorWriteCount, pDescriptorWrites, descriptorCopyCount, pDescriptorCopies);
        }
    }

    void PostProcess_vkUpdateDescriptorSetWithTemplate(VkDevice                   device,
                                                       VkDescriptorSet            descriptorSet,
                                                       VkDescriptorUpdateTemplate descriptorUpdateTemplate,
                                                       const void*                pData)
    {
        GFXRECON_UNREFERENCED_PARAMETER(device);
        if ((capture_mode_ & kModeTrack) == kModeTrack)
        {
            TrackUpdateDescriptorSetWithTemplate(descriptorSet, descriptorUpdateTemplate, pData);
        }
    }

    void PostProcess_vkUpdateDescriptorSetWithTemplateKHR(VkDevice                   device,
                                                          VkDescriptorSet            descriptorSet,
                                                          VkDescriptorUpdateTemplate descriptorUpdateTemplate,
                                                          const void*                pData)
    {
        GFXRECON_UNREFERENCED_PARAMETER(device);
        if ((capture_mode_ & kModeTrack) == kModeTrack)
        {
            TrackUpdateDescriptorSetWithTemplate(descriptorSet, descriptorUpdateTemplate, pData);
        }
    }

    void PostProcess_vkCmdPushDescriptorSetKHR(VkCommandBuffer             commandBuffer,
                                               VkPipelineBindPoint         pipelineBindPoint,
                                               VkPipelineLayout            layout,
                                               uint32_t                    set,
                                               uint32_t                    descriptorWriteCount,
                                               const VkWriteDescriptorSet* pDescriptorWrites)
    {
        GFXRECON_UNREFERENCED_PARAMETER(commandBuffer);
        GFXRECON_UNREFERENCED_PARAMETER(pipelineBindPoint);
        GFXRECON_UNREFERENCED_PARAMETER(layout);
        GFXRECON_UNREFERENCED_PARAMETER(set);
        GFXRECON_UNREFERENCED_PARAMETER(descriptorWriteCount);
        GFXRECON_UNREFERENCED_PARAMETER(pDescriptorWrites);
        // TODO: Need to be able to map layout + set to a VkDescriptorSet handle.
    }

    void PostProcess_vkCmdPushDescriptorSetWithTemplateKHR(VkCommandBuffer            commandBuffer,
                                                           VkDescriptorUpdateTemplate descriptorUpdateTemplate,
                                                           VkPipelineLayout           layout,
                                                           uint32_t                   set,
                                                           const void*                pData)
    {
        GFXRECON_UNREFERENCED_PARAMETER(commandBuffer);
        GFXRECON_UNREFERENCED_PARAMETER(descriptorUpdateTemplate);
        GFXRECON_UNREFERENCED_PARAMETER(layout);
        GFXRECON_UNREFERENCED_PARAMETER(set);
        GFXRECON_UNREFERENCED_PARAMETER(pData);
        // TODO: Need to be able to map layout + set to a VkDescriptorSet handle.
    }

    void PostProcess_vkResetDescriptorPool(VkResult                   result,
                                           VkDevice                   device,
                                           VkDescriptorPool           descriptorPool,
                                           VkDescriptorPoolResetFlags flags)
    {
        if (((capture_mode_ & kModeTrack) == kModeTrack) && (result == VK_SUCCESS))
        {
            assert(state_tracker_ != nullptr);
            GFXRECON_UNREFERENCED_PARAMETER(device);
            GFXRECON_UNREFERENCED_PARAMETER(flags);
            state_tracker_->TrackResetDescriptorPool(descriptorPool);
        }
    }

    void PostProcess_vkMapMemory(VkResult         result,
                                 VkDevice         device,
                                 VkDeviceMemory   memory,
                                 VkDeviceSize     offset,
                                 VkDeviceSize     size,
                                 VkMemoryMapFlags flags,
                                 void**           ppData);

    void PreProcess_vkFlushMappedMemoryRanges(VkDevice                   device,
                                              uint32_t                   memoryRangeCount,
                                              const VkMappedMemoryRange* pMemoryRanges);

    void PreProcess_vkUnmapMemory(VkDevice device, VkDeviceMemory memory);

    void PreProcess_vkFreeMemory(VkDevice device, VkDeviceMemory memory, const VkAllocationCallbacks* pAllocator);

    void PreProcess_vkQueueSubmit(VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence);

    void PreProcess_vkCreateDescriptorUpdateTemplate(VkResult                                    result,
                                                     VkDevice                                    device,
                                                     const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo,
                                                     const VkAllocationCallbacks*                pAllocator,
                                                     VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate);

    void PreProcess_vkCreateDescriptorUpdateTemplateKHR(VkResult                                    result,
                                                        VkDevice                                    device,
                                                        const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo,
                                                        const VkAllocationCallbacks*                pAllocator,
                                                        VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate);

    void PreProcess_vkDestroyDescriptorUpdateTemplate(VkDevice                     device,
                                                      VkDescriptorUpdateTemplate   descriptorUpdateTemplate,
                                                      const VkAllocationCallbacks* pAllocator);

    void PreProcess_vkDestroyDescriptorUpdateTemplateKHR(VkDevice                     device,
                                                         VkDescriptorUpdateTemplate   descriptorUpdateTemplate,
                                                         const VkAllocationCallbacks* pAllocator);

#if defined(__ANDROID__)
    void PreProcess_GetPhysicalDeviceSurfacePresentModesKHR(VkResult          result,
                                                            VkPhysicalDevice  physicalDevice,
                                                            VkSurfaceKHR      surface,
                                                            uint32_t*         pPresentModeCount,
                                                            VkPresentModeKHR* pPresentModes);
#endif

  protected:
    TraceManager();

    ~TraceManager();

    bool Initialize(std::string base_filename, const CaptureSettings::TraceSettings& trace_settings);

  private:
    enum CaptureModeFlags : uint32_t
    {
        kModeDisabled      = 0x0,
        kModeWrite         = 0x01,
        kModeTrack         = 0x02,
        kModeWriteAndTrack = (kModeWrite | kModeTrack)
    };

    typedef uint32_t CaptureMode;

    class ThreadData
    {
      public:
        ThreadData();

        ~ThreadData() {}

      public:
        const format::ThreadId                    thread_id_;
        format::ApiCallId                         call_id_;
        std::unique_ptr<util::MemoryOutputStream> parameter_buffer_;
        std::unique_ptr<ParameterEncoder>         parameter_encoder_;
        std::vector<uint8_t>                      compressed_buffer_;

      private:
        static format::ThreadId GetThreadId();

      private:
        static std::mutex                                     count_lock_;
        static format::ThreadId                               thread_count_;
        static std::unordered_map<uint64_t, format::ThreadId> id_map_;
    };

    typedef std::unordered_map<VkDescriptorUpdateTemplate, UpdateTemplateInfo> UpdateTemplateMap;

  private:
    ThreadData* GetThreadData()
    {
        if (!thread_data_)
        {
            thread_data_ = std::make_unique<ThreadData>();
        }
        return thread_data_.get();
    }

    bool CreateCaptureFile();
    void WriteFileHeader();
    void BuildOptionList(const format::EnabledOptions&        enabled_options,
                         std::vector<format::FileOptionPair>* option_list);

    ParameterEncoder* InitApiCallTrace(format::ApiCallId call_id);

    void WriteResizeWindowCmd(VkSurfaceKHR surface, uint32_t width, uint32_t height);
    void WriteFillMemoryCmd(VkDeviceMemory memory, VkDeviceSize offset, VkDeviceSize size, const void* data);

    void AddDescriptorUpdateTemplate(VkDescriptorUpdateTemplate                  update_template,
                                     const VkDescriptorUpdateTemplateCreateInfo* create_info);
    void RemoveDescriptorUpdateTemplate(VkDescriptorUpdateTemplate update_template);

    void TrackUpdateDescriptorSetWithTemplate(VkDescriptorSet            set,
                                              VkDescriptorUpdateTemplate update_templat,
                                              const void*                data);

  private:
    static TraceManager*                            instance_;
    static uint32_t                                 instance_count_;
    static std::mutex                               instance_lock_;
    static thread_local std::unique_ptr<ThreadData> thread_data_;
    static LayerTable                               layer_table_;
    std::unordered_map<DispatchKey, InstanceTable>  instance_tables_;
    std::unordered_map<DispatchKey, DeviceTable>    device_tables_;
    format::EnabledOptions                          file_options_;
    std::unique_ptr<util::FileOutputStream>         file_stream_;
    std::string                                     base_filename_;
    std::mutex                                      file_lock_;
    bool                                            timestamp_filename_;
    bool                                            force_file_flush_;
    uint64_t                                        bytes_written_;
    std::unique_ptr<util::Compressor>               compressor_;
    CaptureSettings::MemoryTrackingMode             memory_tracking_mode_;
    MemoryTracker                                   memory_tracker_;
    mutable std::mutex                              memory_tracker_lock_;
    UpdateTemplateMap                               update_template_map_;
    mutable std::mutex                              update_template_map_lock_;
    bool                                            trim_enabled_;
    std::vector<CaptureSettings::TrimRange>         trim_ranges_;
    size_t                                          trim_current_range_;
    uint32_t                                        current_frame_;
    std::unique_ptr<VulkanStateTracker>             state_tracker_;
    CaptureMode                                     capture_mode_;
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_TRACE_MANAGER_H
