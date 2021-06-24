/*
** Copyright (c) 2021 LunarG, Inc.
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

#ifndef GFXRECON_ENCODE_DX12_STATE_TRACKER_H
#define GFXRECON_ENCODE_DX12_STATE_TRACKER_H

#include "encode/dx12_state_table.h"
#include "encode/dx12_state_tracker_initializers.h"
#include "encode/dx12_state_writer.h"
#include "generated/generated_dx12_wrapper_creators.h"
#include "util/defines.h"

#include <guiddef.h>
#include <mutex>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

class Dx12StateTracker
{
  public:
    Dx12StateTracker();

    ~Dx12StateTracker();

    void WriteState(Dx12StateWriter* writer, uint64_t frame_number);

    void AddEntry(REFIID                          riid,
                  typename void**                 new_handle,
                  format::ApiCallId               create_call_id,
                  format::HandleId                create_call_object_id,
                  const util::MemoryOutputStream* create_parameter_buffer);

    template <typename Wrapper>
    void AddEntry(typename void**                 new_handle,
                  format::ApiCallId               create_call_id,
                  format::HandleId                create_call_object_id,
                  const util::MemoryOutputStream* create_parameter_buffer)
    {
        assert(new_handle != nullptr);
        assert(create_parameter_buffer != nullptr);

        if (*new_handle != nullptr)
        {
            auto wrapper = reinterpret_cast<Wrapper*>(*new_handle);

            // Adds the handle wrapper to the object state table, filtering for duplicate handle retrieval.
            std::unique_lock<std::mutex> lock(state_table_mutex_);
            if (state_table_.InsertWrapper(wrapper->GetCaptureId(), wrapper))
            {
                dx12_state_tracker::InitializeState<Wrapper>(
                    wrapper,
                    create_call_id,
                    create_call_object_id,
                    std::make_shared<util::MemoryOutputStream>(create_parameter_buffer->GetData(),
                                                               create_parameter_buffer->GetDataSize()));
            }
        }
    }

    template <typename Wrapper>
    void RemoveEntry(typename Wrapper* wrapper)
    {
        if (wrapper != nullptr)
        {
            // Scope the state table mutex lock because DestroyState also modifies the state table and will attempt to
            // lock the mutex.
            {
                std::unique_lock<std::mutex> lock(state_table_mutex_);
                if (!state_table_.RemoveWrapper(wrapper))
                {
                    // TODO (GH #83): Once tracking is complete and all wrappers are tracked, enable this warning.
                    // Disable it for now in order to prevent redundant log messages.
                    // GFXRECON_LOG_WARNING(
                    //    "Attempting to remove entry from state tracker for object that is not being tracked");
                }
            }

            DestroyState(wrapper);
        }
    }

    void TrackOpenExistingHeapFromAddress(void** heap, const void* address);

    void TrackFenceSetEventOnCompletion(ID3D12Fence_Wrapper* fence, UINT64 value, HANDLE event);

    void TrackFenceSignal(ID3D12Fence_Wrapper* fence, UINT64 value);

  private:
    template <typename Wrapper>
    void DestroyState(Wrapper* wrapper)
    {
        assert(wrapper != nullptr);
        wrapper->GetObjectInfo()->create_parameters = nullptr;
    }

    // TODO (GH #83): Add D3D12 trimming support, add customized functions for tracking state.

  private:
    std::mutex     state_table_mutex_;
    Dx12StateTable state_table_;
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_DX12_STATE_TRACKER_H
