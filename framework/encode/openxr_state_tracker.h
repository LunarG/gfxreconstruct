/*
** Copyright (c) 2019-2024 LunarG, Inc.
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

#ifndef GFXRECON_ENCODE_OPENXR_STATE_TRACKER_H
#define GFXRECON_ENCODE_OPENXR_STATE_TRACKER_H

#if ENABLE_OPENXR_SUPPORT

#include "encode/openxr_handle_wrappers.h"
#include "generated/generated_openxr_state_table.h"
#include "encode/openxr_state_tracker_initializers.h"
#include "encode/openxr_state_writer.h"
#include "format/format.h"
#include "format/format_util.h"
#include "util/file_output_stream.h"
#include "util/defines.h"
#include "util/logging.h"

#include "openxr/openxr.h"

#include <cassert>
#include <functional>
#include <mutex>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

class OpenXrStateTracker
{
  public:
    OpenXrStateTracker();

    ~OpenXrStateTracker();

    uint64_t WriteState(OpenXrStateWriter* writer, uint64_t frame_number)
    {
        if (writer != nullptr)
        {
            std::unique_lock<std::mutex> lock(state_table_mutex_);
            return writer->WriteState(state_table_, frame_number);
        }

        return 0;
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
            auto wrapper = GetOpenXrWrapper<Wrapper>(*new_handle);

            // Adds the handle wrapper to the object state table, filtering for duplicate handle retrieval.
            std::unique_lock<std::mutex> lock(state_table_mutex_);
            if (state_table_.InsertWrapper(wrapper->handle_id, wrapper))
            {
                openxr_state_tracker::InitializeState<ParentHandle, Wrapper, CreateInfo>(
                    parent_handle,
                    wrapper,
                    create_info,
                    create_call_id,
                    std::make_shared<util::MemoryOutputStream>(create_parameter_buffer->GetData(),
                                                               create_parameter_buffer->GetDataSize()));
            }
        }
    }

    template <typename ParentHandle, typename Wrapper, typename CreateInfo>
    void AddAtomEntry(ParentHandle                    parent_handle,
                      typename Wrapper::HandleType*   new_handle,
                      const CreateInfo*               create_info,
                      format::ApiCallId               create_call_id,
                      const util::MemoryOutputStream* create_parameter_buffer)
    {
        assert(new_handle != nullptr);
        assert(create_parameter_buffer != nullptr);

        if (*new_handle != 0ULL)
        {
            auto wrapper = GetOpenXrAtomWrapper<Wrapper>(*new_handle);

            // Adds the handle wrapper to the object state table, filtering for duplicate handle retrieval.
            std::unique_lock<std::mutex> lock(state_table_mutex_);
            if (state_table_.InsertWrapper(wrapper->handle_id, wrapper))
            {
                openxr_state_tracker::InitializeState<ParentHandle, Wrapper, CreateInfo>(
                    parent_handle,
                    wrapper,
                    create_info,
                    create_call_id,
                    std::make_shared<util::MemoryOutputStream>(create_parameter_buffer->GetData(),
                                                               create_parameter_buffer->GetDataSize()));
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
        assert(create_parameter_buffer != nullptr);

        openxr_state_info::CreateParameters create_parameters = std::make_shared<util::MemoryOutputStream>(
            create_parameter_buffer->GetData(), create_parameter_buffer->GetDataSize());

        {
            AddGroupHandles<ParentHandle, SecondaryHandle, Wrapper, CreateInfo>(
                parent_handle, secondary_handle, count, new_handles, create_infos, create_call_id, create_parameters);
        }
    }

    template <typename ParentHandle, typename Wrapper, typename HandleStruct>
    void AddStructGroupEntry(ParentHandle                           parent_handle,
                             uint32_t                               count,
                             HandleStruct*                          handle_structs,
                             std::function<Wrapper*(HandleStruct*)> unwrap_struct_handle,
                             format::ApiCallId                      create_call_id,
                             const util::MemoryOutputStream*        create_parameter_buffer)
    {
        assert(handle_structs != nullptr);
        assert(unwrap_struct_handle != nullptr);
        assert(create_parameter_buffer != nullptr);

        openxr_state_info::CreateParameters create_parameters = std::make_shared<util::MemoryOutputStream>(
            create_parameter_buffer->GetData(), create_parameter_buffer->GetDataSize());

        std::unique_lock<std::mutex> lock(state_table_mutex_);
        for (uint32_t i = 0; i < count; ++i)
        {
            auto wrapper = unwrap_struct_handle(&handle_structs[i]);

            if ((wrapper != nullptr) && (state_table_.InsertWrapper(wrapper->handle_id, wrapper)))
            {
                openxr_state_tracker::InitializeGroupObjectState<ParentHandle, void*, Wrapper, void>(
                    parent_handle, nullptr, wrapper, nullptr, create_call_id, create_parameters);
            }
        }
    }
    template <typename Wrapper>
    void RemoveEntry(typename Wrapper::HandleType handle)
    {
        if (handle != VK_NULL_HANDLE)
        {
            auto wrapper = GetOpenXrWrapper<Wrapper>(handle);

            // Scope the state table mutex lock because DestroyState also modifies the state table and will attempt to
            // lock the mutex.
            {
                std::unique_lock<std::mutex> lock(state_table_mutex_);
                if (!state_table_.RemoveWrapper(wrapper))
                {
                    GFXRECON_LOG_WARNING(
                        "Attempting to remove entry from state tracker for object that is not being tracked");
                }
            }

            DestroyState(wrapper);
        }
    }

  private:
    template <typename ParentHandle, typename SecondaryHandle, typename Wrapper, typename CreateInfo>
    void AddGroupHandles(ParentHandle                        parent_handle,
                         SecondaryHandle                     secondary_handle,
                         uint32_t                            count,
                         typename Wrapper::HandleType*       new_handles,
                         const CreateInfo*                   create_infos,
                         format::ApiCallId                   create_call_id,
                         openxr_state_info::CreateParameters create_parameters)
    {
        assert(new_handles != nullptr);
        assert(create_parameters != nullptr);

        std::unique_lock<std::mutex> lock(state_table_mutex_);
        for (uint32_t i = 0; i < count; ++i)
        {
            if (new_handles[i] != VK_NULL_HANDLE)
            {
                auto wrapper = GetOpenXrWrapper<Wrapper>(new_handles[i]);

                // Adds the handle wrapper to the object state table, filtering for duplicate handle retrieval.
                if (state_table_.InsertWrapper(wrapper->handle_id, wrapper))
                {
                    const CreateInfo* create_info = nullptr;

                    // Not all handle creation operations will have a create info structure (e.g.
                    // VkPhysicalDevice handles retrieved with vkEnumeratePhysicalDevices).
                    if (create_infos != nullptr)
                    {
                        create_info = openxr_state_tracker::GetCreateInfoEntry(i, create_infos);
                    }

                    openxr_state_tracker::
                        InitializeGroupObjectState<ParentHandle, SecondaryHandle, Wrapper, CreateInfo>(
                            parent_handle, secondary_handle, wrapper, create_info, create_call_id, create_parameters);
                }
            }
        }
    }

    template <typename Wrapper>
    void DestroyState(Wrapper* wrapper)
    {
        assert(wrapper != nullptr);
        wrapper->create_parameters = nullptr;
    }

    void DestroyState(openxr_wrappers::InstanceWrapper* wrapper);

    void DestroyState(openxr_wrappers::SessionWrapper* wrapper);

    std::mutex       state_table_mutex_;
    OpenXrStateTable state_table_;
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT

#endif // GFXRECON_ENCODE_OPENXR_STATE_TRACKER_H
