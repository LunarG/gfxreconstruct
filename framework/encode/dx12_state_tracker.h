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

#include "encode/dx12_state_tracker_initializers.h"
#include "encode/dx12_state_writer.h"
#include "generated/generated_dx12_state_table.h"
#include "generated/generated_dx12_wrapper_creators.h"
#include "generated/generated_dx12_add_entries.h"
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

    template <typename ParentWrapper>
    void AddEntry(REFIID                          riid,
                  typename void**                 new_handle,
                  format::ApiCallId               create_call_id,
                  ParentWrapper*                  create_object_wrapper,
                  const util::MemoryOutputStream* create_parameter_buffer)
    {
        assert(new_handle != nullptr);
        assert(create_parameter_buffer != nullptr);

        auto it = kAddEntryFunctionTable<ParentWrapper>.find(riid);
        if (it != kAddEntryFunctionTable<ParentWrapper>.end())
        {
            it->second(new_handle,
                       create_call_id,
                       create_object_wrapper,
                       create_parameter_buffer,
                       state_table_mutex_,
                       state_table_);
        }
    }

    // Specialize templated AddEntry for API calls (which do not have a calling object).
    void AddEntry(REFIID                          riid,
                  typename void**                 new_handle,
                  format::ApiCallId               create_call_id,
                  void*                           create_object_wrapper,
                  const util::MemoryOutputStream* create_parameter_buffer)
    {
        assert(new_handle != nullptr);
        assert(create_parameter_buffer != nullptr);

        auto it = kAddEntryVoidFunctionTable.find(riid);
        if (it != kAddEntryVoidFunctionTable.end())
        {
            it->second(new_handle,
                       create_call_id,
                       create_object_wrapper,
                       create_parameter_buffer,
                       state_table_mutex_,
                       state_table_);
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

    void TrackCommand(ID3D12GraphicsCommandList_Wrapper* list_wrapper,
                      format::ApiCallId                  call_id,
                      const util::MemoryOutputStream*    parameter_buffer);

    void TrackResourceBarriers(ID3D12GraphicsCommandList_Wrapper* list_wrapper,
                               UINT                               num_barriers,
                               const D3D12_RESOURCE_BARRIER*      barriers);

    void TrackExecuteCommandLists(ID3D12CommandQueue_Wrapper* queue_wrapper,
                                  UINT                        num_lists,
                                  ID3D12CommandList* const*   lists);

    void TrackResourceCreation(ID3D12Resource_Wrapper* resource_wrapper, D3D12_RESOURCE_STATES initial_state);

    void TrackCommandListCreation(ID3D12GraphicsCommandList_Wrapper* list_wrapper, bool created_closed);

    void TrackAcquireImage(UINT image_index, IDXGISwapChain_Wrapper* wrapper);

    void TrackPresentedImages(IDXGISwapChain_Wrapper*        wrapper,
                              UINT                           sync_interval,
                              UINT                           present_flags,
                              const DXGI_PRESENT_PARAMETERS* present_parameters);

    void TrackCopyDescriptors(UINT                    num_descriptors,
                              DxDescriptorInfo*       dest_descriptor_info,
                              const DxDescriptorInfo* src_descriptor_info);

  private:
    template <typename Wrapper>
    void DestroyState(Wrapper* wrapper)
    {
        assert(wrapper != nullptr);

        // Tracked state is stored in the wrapper's info struct as a shared pointer. It may need to exist after
        // wrapper is no longer being tracked--for example, if another tracked state needs to create a temporary copy of
        // the wrapped object. The tracked state will be freed when all dependent object wrappers are destroyed, so
        // nothing needs to be destroyed here.
    }

    void TrackSubresourceTransitionBarrier(ID3D12ResourceInfo*        resource_info,
                                           const DxTransitionBarrier& transition,
                                           UINT                       subresource);

  private:
    std::mutex     state_table_mutex_;
    Dx12StateTable state_table_;
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_DX12_STATE_TRACKER_H
