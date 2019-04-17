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

    template <typename ParentHandle, typename Wrapper, typename CreateInfo>
    void AddGroupEntry(ParentHandle                    parent_handle,
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
                    vulkan_state_tracker::InitializeState<ParentHandle, Wrapper, CreateInfo>(
                        parent_handle, wrapper, create_info, create_call_id, create_parameters, &state_table_);

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

    void TrackBufferMemoryBinding(VkDevice device, VkBuffer buffer, VkDeviceMemory memory, VkDeviceSize memoryOffset);

    void TrackImageMemoryBinding(VkDevice device, VkImage image, VkDeviceMemory memory, VkDeviceSize memoryOffset);

    void
    TrackMappedMemory(VkDeviceMemory memory, void* mapped_data, VkDeviceSize mapped_offset, VkDeviceSize mapped_size);

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

    void TrackResetDescriptorPool(VkDescriptorPool descriptor_pool);

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
