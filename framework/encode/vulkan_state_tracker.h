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
#include "format/format.h"
#include "format/format_util.h"
#include "util/defines.h"
#include "util/logging.h"
#include "util/memory_output_stream.h"

#include "vulkan/vulkan.h"

#include <cassert>
#include <mutex>
#include <unordered_map>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

class VulkanStateTracker
{
  public:
    VulkanStateTracker() : object_count_(0) {}

    ~VulkanStateTracker() {}

    template <typename Wrapper, typename CreateInfo>
    void AddEntry(typename Wrapper::HandleType*   new_handle,
                  const CreateInfo*               create_info,
                  format::ApiCallId               create_call_id,
                  const util::MemoryOutputStream* create_parameters)
    {
        assert(new_handle != nullptr);
        assert(create_parameters != nullptr);

        GFXRECON_UNREFERENCED_PARAMETER(create_info);

        if ((create_parameters != nullptr) && (new_handle != nullptr) && (*new_handle != VK_NULL_HANDLE))
        {
            Wrapper* wrapper = new Wrapper;
            wrapper->handle  = (*new_handle);

            {
                std::unique_lock<std::mutex> lock(mutex_);

                wrapper->handle_id = ++object_count_;
                vulkan_state_tracker::InitializeState<Wrapper, CreateInfo>(
                    wrapper, create_info, create_call_id, create_parameters, &state_table_);

                // Attempts to add a new entry to the table. Operation will fail for duplicate handles.
                // TODO: Handle wrapping will introduce a unique ID that eliminates duplicates.
                if (!state_table_.InsertWrapper(format::ToHandleId(*new_handle), wrapper))
                {
                    delete wrapper;
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
