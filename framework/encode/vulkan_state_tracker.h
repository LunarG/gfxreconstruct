/*
** Copyright (c) 2019 LunarG, Inc.
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

#ifndef GFXRECON_ENCODE_VULKAN_STATE_TRACKER_H
#define GFXRECON_ENCODE_VULKAN_STATE_TRACKER_H

#include "encode/descriptor_update_template_info.h"
#include "encode/vulkan_handle_wrappers.h"
#include "encode/vulkan_state_table.h"
#include "encode/vulkan_state_tracker_initializers.h"
#include "encode/vulkan_state_writer.h"
#include "format/format.h"
#include "format/format_util.h"
#include "util/file_output_stream.h"
#include "util/defines.h"
#include "util/logging.h"
#include "util/memory_output_stream.h"

#include "vulkan/vulkan.h"

#include <cassert>
#include <mutex>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

class VulkanStateTracker
{
  public:
    VulkanStateTracker();

    ~VulkanStateTracker();

    void WriteState(VulkanStateWriter* writer)
    {
        if (writer != nullptr)
        {
            std::unique_lock<std::mutex> lock(mutex_);
            writer->WriteState(state_table_);
        }
    }

    template <typename ParentHandle, typename Wrapper, typename CreateInfo>
    void AddEntry(ParentHandle                    parent_handle,
                  typename Wrapper::HandleType*   new_handle,
                  const CreateInfo*               create_info,
                  format::ApiCallId               create_call_id,
                  const util::MemoryOutputStream* create_parameter_buffer)
    {
        assert(new_handle != nullptr);
        assert(create_parameter_buffer != nullptr);

        if (*new_handle != VK_NULL_HANDLE)
        {
            Wrapper* wrapper = new Wrapper;
            wrapper->handle  = (*new_handle);

            {
                std::unique_lock<std::mutex> lock(mutex_);

                wrapper->handle_id = ++object_count_;
                vulkan_state_tracker::InitializeState<ParentHandle, Wrapper, CreateInfo>(
                    parent_handle,
                    wrapper,
                    create_info,
                    create_call_id,
                    std::make_shared<util::MemoryOutputStream>(create_parameter_buffer->GetData(),
                                                               create_parameter_buffer->GetDataSize()),
                    &state_table_);

                // Attempts to add a new entry to the table. Operation will fail for duplicate handles.
                // TODO: Handle wrapping will introduce a unique ID that eliminates duplicates.
                if (!state_table_.InsertWrapper(format::ToHandleId(*new_handle), wrapper))
                {
                    delete wrapper;
                }
            }
        }
    }

    template <typename ParentHandle, typename Wrapper, typename AllocateInfo>
    void AddPoolEntry(ParentHandle                    parent_handle,
                      uint32_t                        count,
                      typename Wrapper::HandleType*   new_handles,
                      const AllocateInfo*             alloc_info,
                      format::ApiCallId               create_call_id,
                      const util::MemoryOutputStream* create_parameter_buffer)
    {
        assert(new_handles != nullptr);
        assert(create_parameter_buffer != nullptr);

        CreateParameters create_parameters = std::make_shared<util::MemoryOutputStream>(
            create_parameter_buffer->GetData(), create_parameter_buffer->GetDataSize());

        {
            std::unique_lock<std::mutex> lock(mutex_);

            for (uint32_t i = 0; i < count; ++i)
            {
                if (new_handles[i] != VK_NULL_HANDLE)
                {
                    Wrapper* wrapper   = new Wrapper;
                    wrapper->handle    = new_handles[i];
                    wrapper->handle_id = ++object_count_;
                    vulkan_state_tracker::InitializePoolObjectState(
                        parent_handle, wrapper, i, alloc_info, create_call_id, create_parameters, &state_table_);

                    // Attempts to add a new entry to the table. Operation will fail for duplicate handles.
                    // TODO: Handle wrapping will introduce a unique ID that eliminates duplicates.
                    if (!state_table_.InsertWrapper(format::ToHandleId(new_handles[i]), wrapper))
                    {
                        delete wrapper;
                    }
                }
            }
        }
    }

    template <typename ParentHandle, typename SecondaryHandle, typename Wrapper, typename CreateInfo>
    void AddGroupEntry(ParentHandle                    parent_handle,
                       SecondaryHandle                 secondary_handle,
                       uint32_t                        count,
                       typename Wrapper::HandleType*   new_handles,
                       const CreateInfo*               create_infos,
                       format::ApiCallId               create_call_id,
                       const util::MemoryOutputStream* create_parameter_buffer)
    {
        assert(new_handles != nullptr);
        assert(create_parameter_buffer != nullptr);

        CreateParameters create_parameters = std::make_shared<util::MemoryOutputStream>(
            create_parameter_buffer->GetData(), create_parameter_buffer->GetDataSize());

        {
            std::unique_lock<std::mutex> lock(mutex_);

            for (uint32_t i = 0; i < count; ++i)
            {
                if (new_handles[i] != VK_NULL_HANDLE)
                {
                    const CreateInfo* create_info = nullptr;

                    // Not all handle creation operations will have a create info structure (e.g. VkPhysicalDevice
                    // handles retrieved with vkEnumeratePhysicalDevices).
                    if (create_infos != nullptr)
                    {
                        create_info = vulkan_state_tracker::GetCreateInfoEntry(i, create_infos);
                    }

                    Wrapper* wrapper   = new Wrapper;
                    wrapper->handle    = new_handles[i];
                    wrapper->handle_id = ++object_count_;
                    vulkan_state_tracker::
                        InitializeGroupObjectState<ParentHandle, SecondaryHandle, Wrapper, CreateInfo>(
                            parent_handle,
                            secondary_handle,
                            wrapper,
                            create_info,
                            create_call_id,
                            create_parameters,
                            &state_table_);

                    // Attempts to add a new entry to the table. Operation will fail for duplicate handles.
                    // TODO: Handle wrapping will introduce a unique ID that eliminates duplicates.
                    if (!state_table_.InsertWrapper(format::ToHandleId(new_handles[i]), wrapper))
                    {
                        delete wrapper;
                    }
                }
            }
        }
    }

    template <typename Wrapper>
    void RemoveEntry(typename Wrapper::HandleType handle)
    {
        Wrapper* wrapper = nullptr;

        {
            std::unique_lock<std::mutex> lock(mutex_);
            state_table_.RemoveWrapper(format::ToHandleId(handle), &wrapper);
            DestroyState(wrapper);
        }

        if (wrapper != nullptr)
        {
            delete wrapper;
        }
        else
        {
            GFXRECON_LOG_WARNING("Attempting to remove entry from state tracker for object that is not being tracked");
        }
    }

    void TrackCommand(VkCommandBuffer                 command_buffer,
                      format::ApiCallId               call_id,
                      const util::MemoryOutputStream* parameter_buffer);

    void TrackResetCommandPool(VkCommandPool command_pool);

    void TrackPhysicalDeviceMemoryProperties(VkPhysicalDevice                        physical_device,
                                             const VkPhysicalDeviceMemoryProperties* properties);

    void TrackPhysicalDeviceQueueFamilyProperties(VkPhysicalDevice               physical_device,
                                                  uint32_t                       property_count,
                                                  const VkQueueFamilyProperties* properties);

    void TrackPhysicalDeviceQueueFamilyProperties2(format::ApiCallId               call_id,
                                                   VkPhysicalDevice                physical_device,
                                                   uint32_t                        property_count,
                                                   const VkQueueFamilyProperties2* properties);

    void TrackBufferMemoryBinding(VkDevice device, VkBuffer buffer, VkDeviceMemory memory, VkDeviceSize memoryOffset);

    void TrackImageMemoryBinding(VkDevice device, VkImage image, VkDeviceMemory memory, VkDeviceSize memoryOffset);

    void TrackMappedMemory(VkDevice         device,
                           VkDeviceMemory   memory,
                           void*            mapped_data,
                           VkDeviceSize     mapped_offset,
                           VkDeviceSize     mapped_size,
                           VkMemoryMapFlags mapped_flags);

    void TrackBeginRenderPass(VkCommandBuffer command_buffer, const VkRenderPassBeginInfo* begin_info);

    void TrackEndRenderPass(VkCommandBuffer command_buffer);

    void TrackExecuteCommands(VkCommandBuffer        command_buffer,
                              uint32_t               command_buffer_count,
                              const VkCommandBuffer* command_buffers);

    void TrackImageBarriers(VkCommandBuffer             command_buffer,
                            uint32_t                    image_barrier_count,
                            const VkImageMemoryBarrier* image_barriers);

    void TrackImageLayoutTransitions(uint32_t submit_count, const VkSubmitInfo* submits);

    void TrackUpdateDescriptorSets(uint32_t                    write_count,
                                   const VkWriteDescriptorSet* writes,
                                   uint32_t                    copy_count,
                                   const VkCopyDescriptorSet*  copies);

    void TrackUpdateDescriptorSetWithTemplate(VkDescriptorSet           set,
                                              const UpdateTemplateInfo* template_info,
                                              const void*               data);

    void TrackResetDescriptorPool(VkDescriptorPool descriptor_pool);

    void TrackSemaphoreSignalState(uint32_t           wait_count,
                                   const VkSemaphore* waits,
                                   uint32_t           signal_count,
                                   const VkSemaphore* signals);

  private:
    template <typename Wrapper>
    void DestroyState(Wrapper* wrapper)
    {
        wrapper->create_parameters = nullptr;
    }

    void DestroyState(DeviceWrapper* wrapper);

    void DestroyState(CommandPoolWrapper* wrapper);

    void DestroyState(CommandBufferWrapper* wrapper);

    void DestroyState(DescriptorPoolWrapper* wrapper);

    void DestroyState(DescriptorSetWrapper* wrapper);

    void DestroyState(SwapchainKHRWrapper* wrapper);

  private:
    // TODO: Evaluate need for per-type locks.
    std::mutex mutex_;
    // TODO: Per-type counts.
    uint32_t object_count_;

    VulkanStateTable state_table_;
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_VULKAN_STATE_TRACKER_H
