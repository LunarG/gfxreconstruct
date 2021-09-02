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

#include "encode/dx12_state_tracker.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

Dx12StateTracker::Dx12StateTracker() {}

Dx12StateTracker::~Dx12StateTracker() {}

void Dx12StateTracker::WriteState(Dx12StateWriter* writer, uint64_t frame_number)
{
    if (writer != nullptr)
    {
        std::unique_lock<std::mutex> lock(state_table_mutex_);
        writer->WriteState(state_table_, frame_number);
    }
}

void Dx12StateTracker::TrackOpenExistingHeapFromAddress(void** heap, const void* address)
{
    assert((heap != nullptr) && ((*heap) != nullptr) && (address != nullptr));

    auto heap_wrapper = reinterpret_cast<ID3D12Heap_Wrapper*>(*heap);
    auto info         = heap_wrapper->GetObjectInfo();
    assert(info != nullptr);
    info->open_existing_address = address;
}

void Dx12StateTracker::TrackFenceSetEventOnCompletion(ID3D12Fence_Wrapper* fence_wrapper, UINT64 value, HANDLE event)
{
    assert(fence_wrapper != nullptr);
    assert(fence_wrapper->GetWrappedObject() != nullptr);
    assert(fence_wrapper->GetObjectInfo() != nullptr);

    auto fence      = fence_wrapper->GetWrappedObjectAs<ID3D12Fence>();
    auto fence_info = fence_wrapper->GetObjectInfo();

    auto lock = std::unique_lock<std::mutex>(fence_info->pending_events_mutex);
    fence_info->pending_events[value].push_back(event);
}

void Dx12StateTracker::TrackFenceSignal(ID3D12Fence_Wrapper* fence_wrapper, UINT64 value)
{
    assert(fence_wrapper != nullptr);
    assert(fence_wrapper->GetWrappedObject() != nullptr);
    assert(fence_wrapper->GetObjectInfo() != nullptr);

    auto fence      = fence_wrapper->GetWrappedObjectAs<ID3D12Fence>();
    auto fence_info = fence_wrapper->GetObjectInfo();

    // Remove any events that were waiting for a signal value <= the signaled value.
    auto lock = std::unique_lock<std::mutex>(fence_info->pending_events_mutex);
    for (auto iter = fence_info->pending_events.cbegin(); iter != fence_info->pending_events.cend();)
    {
        if (iter->first <= value)
        {
            fence_info->pending_events.erase(iter++);
        }
        else
        {
            ++iter;
        }
    }
}

void Dx12StateTracker::TrackCommandExecution(ID3D12GraphicsCommandList_Wrapper* list_wrapper,
                                             format::ApiCallId                  call_id,
                                             const util::MemoryOutputStream*    parameter_buffer)
{
    if (list_wrapper == nullptr)
    {
        return;
    }

    assert(list_wrapper->GetWrappedObject() != nullptr);
    assert(list_wrapper->GetObjectInfo() != nullptr);

    auto list_info = list_wrapper->GetObjectInfo();

    if (call_id == format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_Reset)
    {
        list_info->was_reset = true;
        list_info->is_closed = false;

        // Clear command data on command buffer reset.
        list_info->command_data.Reset();

        // Clear pending resource transitions.
        list_info->transition_barriers.clear();

        list_info->command_cpu_descriptor_handles.clear();
        list_info->command_gpu_descriptor_handles.clear();
        list_info->command_gpu_virtual_addresses.clear();

        for (size_t i = 0; i < D3D12GraphicsCommandObjectType::NumObjectTypes; ++i)
        {
            list_info->command_objects[i].clear();
        }
    }

    if (call_id == format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_Close)
    {
        list_info->is_closed = true;
    }

    // Append the command data.
    size_t size = parameter_buffer->GetDataSize();
    list_info->command_data.Write(&size, sizeof(size));
    list_info->command_data.Write(&call_id, sizeof(call_id));
    list_info->command_data.Write(parameter_buffer->GetData(), size);
}

void Dx12StateTracker::TrackCommand(ID3D12GraphicsCommandList_Wrapper* list_wrapper,
                                    format::ApiCallId                  call_id,
                                    const util::MemoryOutputStream*    parameter_buffer)
{
    if (list_wrapper != nullptr)
    {
        TrackCommandExecution(list_wrapper, call_id, parameter_buffer);
    }
}

void Dx12StateTracker::TrackResourceBarriers(ID3D12GraphicsCommandList_Wrapper* list_wrapper,
                                             UINT                               num_barriers,
                                             const D3D12_RESOURCE_BARRIER*      barriers)
{
    for (UINT i = 0; i < num_barriers; ++i)
    {
        // Save the transition barrier information with the command list to be applied to the resource when the command
        // list is executed.
        const auto& barrier = barriers[i];
        if (barrier.Type == D3D12_RESOURCE_BARRIER_TYPE_TRANSITION)
        {
            DxTransitionBarrier transition;
            transition.resource_wrapper = reinterpret_cast<ID3D12Resource_Wrapper*>(barrier.Transition.pResource);
            transition.subresource      = barrier.Transition.Subresource;
            transition.state_before     = barrier.Transition.StateBefore;
            transition.state_after      = barrier.Transition.StateAfter;
            transition.barrier_flags    = barrier.Flags;
            list_wrapper->GetObjectInfo()->transition_barriers.push_back(transition);
        }
    }
}

void Dx12StateTracker::TrackExecuteCommandLists(ID3D12CommandQueue_Wrapper* queue_wrapper,
                                                UINT                        num_lists,
                                                ID3D12CommandList* const*   lists)
{
    for (UINT i = 0; i < num_lists; ++i)
    {
        auto list_wrapper = reinterpret_cast<ID3D12GraphicsCommandList_Wrapper*>(lists[i]);
        auto list_info    = list_wrapper->GetObjectInfo();

        // Apply pending resource transitions to tracked resource states.
        for (const auto& transition_barrier : list_info->transition_barriers)
        {
            auto resource_wrapper = transition_barrier.resource_wrapper;
            auto resource_info    = resource_wrapper->GetObjectInfo();

            // TODO (GH #83): Should it be valid for resources to have an empty transitions array?
            if (resource_info->subresource_transitions.empty())
            {
                continue;
            }

            GFXRECON_ASSERT(resource_info->subresource_transitions.size() == resource_info->num_subresources);

            if (transition_barrier.subresource == D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES)
            {
                for (UINT i = 0; i < resource_info->num_subresources; ++i)
                {
                    TrackSubresourceTransitionBarrier(resource_info.get(), transition_barrier, i);
                }
            }
            else
            {
                GFXRECON_ASSERT(transition_barrier.subresource < resource_info->subresource_transitions.size());

                TrackSubresourceTransitionBarrier(
                    resource_info.get(), transition_barrier, transition_barrier.subresource);
            }
        }
    }
}

void Dx12StateTracker::TrackResourceCreation(ID3D12Resource_Wrapper* resource_wrapper,
                                             D3D12_RESOURCE_STATES   initial_state)
{
    auto resource_info = resource_wrapper->GetObjectInfo();

    // Set all subresources to the initial state.
    resource_info->initial_state = initial_state;
    resource_info->subresource_transitions.reserve(resource_info->num_subresources);
    for (UINT i = 0; i < resource_info->num_subresources; ++i)
    {
        resource_info->subresource_transitions.push_back({ initial_state, D3D12_RESOURCE_BARRIER_FLAG_NONE });
    }
}

void Dx12StateTracker::TrackCommandListCreation(ID3D12GraphicsCommandList_Wrapper* list_wrapper, bool created_closed)
{
    auto list_info       = list_wrapper->GetObjectInfo();
    list_info->is_closed = created_closed;
}

void Dx12StateTracker::TrackDescriptorCreation(ID3D12Device_Wrapper*           create_object_wrapper,
                                               format::ApiCallId               call_id,
                                               const util::MemoryOutputStream* parameter_buffer,
                                               DxDescriptorInfo*               descriptor_info)
{
    GFXRECON_ASSERT(descriptor_info != nullptr);

    // Store creation data with descriptor info struct.
    descriptor_info->create_object_id = create_object_wrapper->GetCaptureId();
    descriptor_info->create_call_id   = call_id;
    descriptor_info->create_parameters =
        std::make_unique<util::MemoryOutputStream>(parameter_buffer->GetData(), parameter_buffer->GetDataSize());
    descriptor_info->is_copy = false;
}

void Dx12StateTracker::TrackCopyDescriptors(UINT                    num_descriptors,
                                            DxDescriptorInfo*       dest_descriptor_info,
                                            const DxDescriptorInfo* src_descriptor_info)
{
    GFXRECON_ASSERT(dest_descriptor_info != nullptr);
    GFXRECON_ASSERT(src_descriptor_info != nullptr);

    for (UINT i = 0; i < num_descriptors; ++i)
    {
        if (dest_descriptor_info[i].create_parameters == src_descriptor_info[i].create_parameters)
        {
            GFXRECON_LOG_WARNING("Source and destination descriptors are the same in CopyDescriptors. Skipping copy.");
            continue;
        }

        size_t heap_and_index_size = 0;
        if (!src_descriptor_info->is_copy)
        {
            heap_and_index_size = sizeof(DxDescriptorInfo::heap_id) + sizeof(DxDescriptorInfo::index);
        }

        dest_descriptor_info[i].create_object_id = src_descriptor_info[i].create_object_id;
        dest_descriptor_info[i].create_call_id   = src_descriptor_info[i].create_call_id;

        dest_descriptor_info[i].is_copy = true;

        GFXRECON_ASSERT(src_descriptor_info[i].create_parameters->GetDataSize() > heap_and_index_size);

        // Copy source creation parameters to destination.
        if (dest_descriptor_info[i].create_parameters == nullptr)
        {
            dest_descriptor_info[i].create_parameters = std::make_unique<util::MemoryOutputStream>(
                src_descriptor_info[i].create_parameters->GetData(),
                src_descriptor_info[i].create_parameters->GetDataSize() - heap_and_index_size);
        }
        else
        {
            dest_descriptor_info[i].create_parameters->Reset();
            dest_descriptor_info[i].create_parameters->Write(src_descriptor_info[i].create_parameters->GetData(),
                                                             src_descriptor_info[i].create_parameters->GetDataSize() -
                                                                 heap_and_index_size);
        }
        dest_descriptor_info[i].resource_ids = src_descriptor_info[i].resource_ids;
    }
}

void Dx12StateTracker::TrackUpdateTileMappings(ID3D12Resource_Wrapper*         resource_wrapper,
                                               format::HandleId                queue_id,
                                               format::HandleId                heap_id,
                                               const util::MemoryOutputStream* parameter_buffer)
{
    GFXRECON_ASSERT(resource_wrapper != nullptr);
    GFXRECON_ASSERT(resource_wrapper->GetObjectInfo() != nullptr);

    auto resource_info = resource_wrapper->GetObjectInfo();
    resource_info->tile_mappings.push_back(
        { queue_id,
          heap_id,
          std::make_unique<util::MemoryOutputStream>(parameter_buffer->GetData(), parameter_buffer->GetDataSize()) });
}

void Dx12StateTracker::TrackSubresourceTransitionBarrier(ID3D12ResourceInfo*        resource_info,
                                                         const DxTransitionBarrier& transition,
                                                         UINT                       subresource)
{
    resource_info->subresource_transitions[subresource] = { transition.state_after, transition.barrier_flags };
}

void Dx12StateTracker::TrackAcquireImage(UINT image_index, IDXGISwapChain_Wrapper* wrapper)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    auto wrapper_info = wrapper->GetObjectInfo();

    GFXRECON_ASSERT((wrapper_info != nullptr) && (image_index < wrapper_info->image_acquired_info.size()));
    wrapper_info->current_back_buffer_index                    = image_index;
    wrapper_info->image_acquired_info[image_index].is_acquired = true;
}

void Dx12StateTracker::TrackPresentedImages(IDXGISwapChain_Wrapper*        wrapper,
                                            UINT                           sync_interval,
                                            UINT                           present_flags,
                                            const DXGI_PRESENT_PARAMETERS* present_parameters)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    auto     wrapper_info              = wrapper->GetObjectInfo();
    uint32_t image_index               = wrapper_info->current_back_buffer_index;
    wrapper_info->last_presented_image = image_index;

    GFXRECON_ASSERT((wrapper_info != nullptr) && (image_index < wrapper_info->image_acquired_info.size()));

    wrapper_info->image_acquired_info[image_index].sync_interval         = sync_interval;
    wrapper_info->image_acquired_info[image_index].present_flags         = present_flags;
    wrapper_info->image_acquired_info[image_index].is_acquired           = false;
    wrapper_info->image_acquired_info[image_index].is_present_parameters = false;
    if (present_parameters)
    {
        wrapper_info->image_acquired_info[image_index].is_present_parameters = true;
        wrapper_info->image_acquired_info[image_index].dirty_rects.resize(present_parameters->DirtyRectsCount);
        util::platform::MemoryCopy(wrapper_info->image_acquired_info[image_index].dirty_rects.data(),
                                   present_parameters->DirtyRectsCount * sizeof RECT,
                                   present_parameters->pDirtyRects,
                                   present_parameters->DirtyRectsCount * sizeof RECT);
        wrapper_info->image_acquired_info[image_index].scroll_rect   = *present_parameters->pScrollRect;
        wrapper_info->image_acquired_info[image_index].scroll_offset = *present_parameters->pScrollOffset;
    }
}

void Dx12StateTracker::TrackResizeBuffers(IDXGISwapChain_Wrapper*         swapchain_wrapper,
                                          format::ApiCallId               call_id,
                                          const util::MemoryOutputStream* parameter_buffer)
{
    GFXRECON_ASSERT(swapchain_wrapper != nullptr);
    GFXRECON_ASSERT(swapchain_wrapper->GetObjectInfo() != nullptr);

    auto swapchain_info         = swapchain_wrapper->GetObjectInfo();
    swapchain_info->resize_info = { call_id,
                                    std::make_unique<util::MemoryOutputStream>(parameter_buffer->GetData(),
                                                                               parameter_buffer->GetDataSize()) };
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
