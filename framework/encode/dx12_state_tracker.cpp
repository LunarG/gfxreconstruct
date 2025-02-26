/*
** Copyright (c) 2021 LunarG, Inc.
** Copyright (c) 2022-2025 Advanced Micro Devices, Inc. All rights reserved.
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

#include "encode/custom_dx12_struct_unwrappers.h"
#include <encode/d3d12_capture_manager.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

// The function is used as function pointer parameter for GPUVA map functions
// in dx12_gpu_va_map.cpp for searching resource which has flag
// D3D12_RESOURCE_FLAG_RAYTRACING_ACCELERATION_STRUCTURE. Such handling is for
// keeping headfile organized without having to add too much change to headfile
// structure.
bool IsResourceUsedForAccelerationStructure(format::HandleId id)
{
    return D3D12CaptureManager::Get()->IsAccelerationStructureResource(id);
}

#define GFXRECON_ACCEL_STRUCT_TRIM_BARRIER 0

Dx12StateTracker::Dx12StateTracker() : accel_struct_id_(1) {}

Dx12StateTracker::~Dx12StateTracker() {}

void Dx12StateTracker::WriteState(Dx12StateWriter* writer, uint64_t frame_number)
{
    if (writer != nullptr)
    {
        std::unique_lock<std::mutex> lock(state_table_mutex_);
#ifdef GFXRECON_AGS_SUPPORT
        writer->WriteState(state_table_, ags_state_table_, frame_number);
#else
        writer->WriteState(state_table_, frame_number);
#endif // GFXRECON_AGS_SUPPORT
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

void Dx12StateTracker::TrackCommandExecution(ID3D12CommandList_Wrapper*      list_wrapper,
                                             format::ApiCallId               call_id,
                                             const util::MemoryOutputStream* parameter_buffer)
{
    if (list_wrapper == nullptr)
    {
        return;
    }

    assert(list_wrapper->GetWrappedObject() != nullptr);
    assert(list_wrapper->GetObjectInfo() != nullptr);

    auto list_info = list_wrapper->GetObjectInfo();

    switch (call_id)
    {
        case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_Reset:
            list_info->was_reset = true;
            list_info->is_closed = false;

            // Clear command data on command buffer reset.
            list_info->command_data.Clear();

            // Clear pending resource transitions.
            list_info->transition_barriers.clear();

            list_info->command_cpu_descriptor_handles.clear();
            list_info->command_gpu_descriptor_handles.clear();
            list_info->command_gpu_virtual_addresses.clear();
            list_info->draw_call_count                = 0;
            list_info->find_target_draw_call_count    = 0;
            list_info->target_bundle_commandlist_info = nullptr;

            for (size_t i = 0; i < D3D12GraphicsCommandObjectType::NumObjectTypes; ++i)
            {
                list_info->command_objects[i].clear();
            }

            // Clear pending acceleration structure builds & copies.
            list_info->acceleration_structure_builds.clear();
            list_info->acceleration_structure_copies.clear();
            break;
        case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_Close:
            list_info->is_closed = true;
            break;
        case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_DrawInstanced:
        case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_DrawIndexedInstanced:
        case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_Dispatch:
        case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_ExecuteIndirect:
        case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_ExecuteBundle:
            ++list_info->draw_call_count;
            break;
        default:
            break;
    }

    // Append the command data.
    size_t size = parameter_buffer->GetDataSize();
    list_info->command_data.Write(&size, sizeof(size));
    list_info->command_data.Write(&call_id, sizeof(call_id));
    list_info->command_data.Write(parameter_buffer->GetData(), size);
}

void Dx12StateTracker::TrackCommand(ID3D12CommandList_Wrapper*      list_wrapper,
                                    format::ApiCallId               call_id,
                                    const util::MemoryOutputStream* parameter_buffer)
{
    if (list_wrapper != nullptr)
    {
        TrackCommandExecution(list_wrapper, call_id, parameter_buffer);
    }
}

void Dx12StateTracker::TrackResourceBarriers(ID3D12CommandList_Wrapper*    list_wrapper,
                                             UINT                          num_barriers,
                                             const D3D12_RESOURCE_BARRIER* barriers)
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

void Dx12StateTracker::TrackCommandList_Reset(ID3D12CommandList_Wrapper* list_wrapper,
                                              ID3D12CommandAllocator*    pAllocator,
                                              ID3D12PipelineState*       pInitialState)
{
    auto allocator = reinterpret_cast<ID3D12CommandAllocator_Wrapper*>(pAllocator);
    list_wrapper->GetObjectInfo()->reset_command_allocator_id = allocator->GetCaptureId();
}

void Dx12StateTracker::TrackExecuteCommandLists(ID3D12CommandQueue_Wrapper* queue_wrapper,
                                                UINT                        num_lists,
                                                ID3D12CommandList* const*   lists)
{
    GFXRECON_ASSERT(queue_wrapper != nullptr);
    GFXRECON_ASSERT(queue_wrapper->GetObjectInfo() != nullptr);
    auto queue_info = queue_wrapper->GetObjectInfo();
    auto queue      = queue_wrapper->GetWrappedObjectAs<ID3D12CommandQueue>();
    auto device     = graphics::dx12::GetDeviceComPtrFromChild<ID3D12Device>(queue);

    graphics::dx12::ID3D12CommandAllocatorComPtr     post_build_as_copy_cmd_allocator = nullptr;
    graphics::dx12::ID3D12GraphicsCommandList4ComPtr post_build_as_copy_cmd_list      = nullptr;

    HRESULT  result                                 = S_OK;
    uint64_t highest_as_build_id                    = 0;
    bool     executing_acceleration_structure_build = false;

    for (UINT i = 0; i < num_lists; ++i)
    {
        auto list_wrapper = reinterpret_cast<ID3D12CommandList_Wrapper*>(lists[i]);
        auto list_info    = list_wrapper->GetObjectInfo();

        // Apply pending resource transitions to tracked resource states.
        for (const auto& transition_barrier : list_info->transition_barriers)
        {
            auto resource_wrapper = transition_barrier.resource_wrapper;
            auto resource_info    = resource_wrapper->GetObjectInfo();

            // TODO: Should it be valid for resources to have an empty transitions array?
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

        bool has_acceleration_structure_build =
            !list_info->acceleration_structure_builds.empty() || !list_info->acceleration_structure_copies.empty();
        if (has_acceleration_structure_build)
        {
            executing_acceleration_structure_build = true;
            bool has_tlas_with_array_of_pointers   = false;
            for (const auto& as_build_info : list_info->acceleration_structure_builds)
            {
                if (as_build_info.is_tlas_with_array_of_pointers)
                {
                    has_tlas_with_array_of_pointers = true;
                }
            }

            // If the command list contains a TLAS build that uses the ARRAY_OF_POINTER DescLayout then use
            // COPY_MODE_VISUALIZATION to save the inputs to the build.
            if (has_tlas_with_array_of_pointers)
            {
                D3D12_COMMAND_LIST_TYPE list_type = queue->GetDesc().Type;

                if (post_build_as_copy_cmd_allocator == nullptr)
                {
                    result = device->CreateCommandAllocator(list_type, IID_PPV_ARGS(&post_build_as_copy_cmd_allocator));
                }
                if (SUCCEEDED(result))
                {
                    if (post_build_as_copy_cmd_list == nullptr)
                    {
                        result = device->CreateCommandList(0,
                                                           list_type,
                                                           post_build_as_copy_cmd_allocator,
                                                           nullptr,
                                                           IID_PPV_ARGS(&post_build_as_copy_cmd_list));
                    }
                    if (SUCCEEDED(result))
                    {
                        for (const auto& as_build_info : list_info->acceleration_structure_builds)
                        {
                            if (as_build_info.is_tlas_with_array_of_pointers &&
                                as_build_info.input_data_resource != nullptr)
                            {
                                {
                                    D3D12_RESOURCE_TRANSITION_BARRIER pre_transition;
                                    pre_transition.pResource   = as_build_info.input_data_resource;
                                    pre_transition.Subresource = 0;
                                    pre_transition.StateBefore = D3D12_RESOURCE_STATE_COPY_DEST;
                                    pre_transition.StateAfter  = D3D12_RESOURCE_STATE_UNORDERED_ACCESS;
                                    D3D12_RESOURCE_BARRIER pre_barrier;
                                    pre_barrier.Type       = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
                                    pre_barrier.Flags      = D3D12_RESOURCE_BARRIER_FLAG_NONE;
                                    pre_barrier.Transition = pre_transition;
                                    post_build_as_copy_cmd_list->ResourceBarrier(1, &pre_barrier);
                                }

                                {
                                    auto dst_gpuva = as_build_info.input_data_resource->GetGPUVirtualAddress();
                                    auto src_gpuva = as_build_info.dest_gpu_va;
                                    post_build_as_copy_cmd_list->CopyRaytracingAccelerationStructure(
                                        dst_gpuva,
                                        src_gpuva,
                                        D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE_VISUALIZATION_DECODE_FOR_TOOLS);
                                }

                                {
                                    D3D12_RESOURCE_TRANSITION_BARRIER post_transition;
                                    post_transition.pResource   = as_build_info.input_data_resource;
                                    post_transition.Subresource = 0;
                                    post_transition.StateBefore = D3D12_RESOURCE_STATE_UNORDERED_ACCESS;
                                    post_transition.StateAfter  = D3D12_RESOURCE_STATE_COPY_DEST;
                                    D3D12_RESOURCE_BARRIER post_barrier;
                                    post_barrier.Type       = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
                                    post_barrier.Flags      = D3D12_RESOURCE_BARRIER_FLAG_NONE;
                                    post_barrier.Transition = post_transition;
                                    post_build_as_copy_cmd_list->ResourceBarrier(1, &post_barrier);
                                }
                            }
                        }
                    }
                }

                if (FAILED(result))
                {
                    GFXRECON_LOG_ERROR("Failed to record command list to copy instance descs for TLAS build.");
                }
            }

            // Add acceleration structure build infos to their destination resources.
            for (auto& accel_struct_build : list_info->acceleration_structure_builds)
            {
                auto build_id       = CommitAccelerationStructureBuildInfo(accel_struct_build);
                highest_as_build_id = std::max(build_id, highest_as_build_id);
                GFXRECON_ASSERT(queue_info->acceleration_structure_build_tracking_objects.count(build_id) == 0);
                queue_info->acceleration_structure_build_tracking_objects.emplace(
                    build_id,
                    AccelerationStructureBuildTrackingObjects(accel_struct_build.input_data_resource,
                                                              post_build_as_copy_cmd_allocator,
                                                              post_build_as_copy_cmd_list));
            }

            // Add acceleration structure copy infos to their resources.
            for (auto& accel_struct_copy : list_info->acceleration_structure_copies)
            {
                graphics::dx12::ID3D12ResourceComPtr inputs_data_resource;
                auto build_id       = CommitAccelerationStructureCopyInfo(accel_struct_copy, inputs_data_resource);
                highest_as_build_id = std::max(build_id, highest_as_build_id);
                GFXRECON_ASSERT(queue_info->acceleration_structure_build_tracking_objects.count(build_id) == 0);
                queue_info->acceleration_structure_build_tracking_objects.emplace(
                    build_id,
                    AccelerationStructureBuildTrackingObjects(
                        inputs_data_resource, post_build_as_copy_cmd_allocator, post_build_as_copy_cmd_list));
            }

            GFXRECON_ASSERT(queue_wrapper->GetWrappedObject() != nullptr);
            auto queue = queue_wrapper->GetWrappedObjectAs<ID3D12CommandQueue>();

            // Create the fence that will be signaled by the queue to indicate that builds are complete.
            if (queue_info->acceleration_structure_build_tracking_fence == nullptr)
            {
                auto device = graphics::dx12::GetDeviceComPtrFromChild<ID3D12Device>(queue);
                GFXRECON_ASSERT(device != nullptr);

                auto hr = device->CreateFence(
                    0, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&queue_info->acceleration_structure_build_tracking_fence));
                GFXRECON_ASSERT(SUCCEEDED(hr));
            }
        }
    }

    if (executing_acceleration_structure_build)
    {
        // Execute the commands to copy the TLAS build inputs.
        if (post_build_as_copy_cmd_list != nullptr)
        {
            result = post_build_as_copy_cmd_list->Close();
            if (SUCCEEDED(result))
            {
                ID3D12CommandList* cmd_list[] = { post_build_as_copy_cmd_list };
                queue->ExecuteCommandLists(1, cmd_list);
            }
            else
            {
                GFXRECON_LOG_ERROR("Failed to close command list to copy instance descs for TLAS build.");
            }
        }

        // Add a signal to the queue to indicate that the acceleration structure builds have completed.
        if ((queue_info->acceleration_structure_build_tracking_fence != nullptr) && (highest_as_build_id > 0))
        {
            GFXRECON_ASSERT(queue_info->acceleration_structure_build_tracking_fence->GetCompletedValue() <=
                            highest_as_build_id);
            queue->Signal(queue_info->acceleration_structure_build_tracking_fence, highest_as_build_id);
        }
    }

    // Clear out any completed entries in acceleration_structure_build_tracking_objects.
    if (!queue_info->acceleration_structure_build_tracking_objects.empty())
    {
        GFXRECON_ASSERT(queue_info->acceleration_structure_build_tracking_fence != nullptr);
        auto& objects_map = queue_info->acceleration_structure_build_tracking_objects;
        auto  completed_end =
            objects_map.upper_bound(queue_info->acceleration_structure_build_tracking_fence->GetCompletedValue());
        objects_map.erase(objects_map.begin(), completed_end);
    }
}

void Dx12StateTracker::TrackResourceCreation(ID3D12Resource_Wrapper* resource_wrapper,
                                             D3D12_RESOURCE_STATES   initial_state,
                                             bool                    swapchain_buffer)
{
    auto resource_info = resource_wrapper->GetObjectInfo();

    resource_info->is_swapchain_buffer = swapchain_buffer;

    // Set all subresources to the initial state.
    resource_info->initial_state = initial_state;
    resource_info->subresource_transitions.reserve(resource_info->num_subresources);
    for (UINT i = 0; i < resource_info->num_subresources; ++i)
    {
        resource_info->subresource_transitions.push_back({ initial_state, D3D12_RESOURCE_BARRIER_FLAG_NONE });
    }
}

void Dx12StateTracker::TrackResourceGpuVa(ID3D12Resource_Wrapper* resource_wrapper, D3D12_GPU_VIRTUAL_ADDRESS address)
{
    GFXRECON_ASSERT(resource_wrapper);
    GFXRECON_ASSERT(address != 0);

    resource_wrapper->GetObjectInfo()->gpu_va = address;
    std::unique_lock<std::mutex> lock(state_table_mutex_);
    state_table_.AddResourceGpuVa(resource_wrapper, address);
}

void Dx12StateTracker::TrackCommandListCreation(ID3D12CommandList_Wrapper* list_wrapper,
                                                bool                       created_closed,
                                                D3D12_COMMAND_LIST_TYPE    command_list_type,
                                                ID3D12CommandAllocator*    pCommandAllocator)
{
    auto list_info               = list_wrapper->GetObjectInfo();
    list_info->is_closed         = created_closed;
    list_info->command_list_type = command_list_type;

    if (pCommandAllocator != nullptr)
    {
        auto cmd_alloc_wrapper                   = reinterpret_cast<ID3D12CommandAllocator_Wrapper*>(pCommandAllocator);
        list_info->create_command_allocator_id   = cmd_alloc_wrapper->GetCaptureId();
        list_info->reset_command_allocator_id    = list_info->create_command_allocator_id;
        list_info->create_command_allocator_info = cmd_alloc_wrapper->GetObjectInfo();
    }
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
    if (descriptor_info->create_parameters == nullptr)
    {
        descriptor_info->create_parameters =
            std::make_unique<util::MemoryOutputStream>(parameter_buffer->GetData(), parameter_buffer->GetDataSize());
    }
    else
    {
        descriptor_info->create_parameters->Clear();
        descriptor_info->create_parameters->Write(parameter_buffer->GetData(), parameter_buffer->GetDataSize());
    }
    descriptor_info->is_copy         = false;
    descriptor_info->resource_ids    = { format::kNullHandleId, format::kNullHandleId };
    descriptor_info->resource_gpu_va = 0;
}

void Dx12StateTracker::TrackCopyDescriptors(UINT                    num_descriptors,
                                            DxDescriptorInfo*       dest_descriptor_infos,
                                            const DxDescriptorInfo* src_descriptor_infos)
{
    GFXRECON_ASSERT(dest_descriptor_infos != nullptr);
    GFXRECON_ASSERT(src_descriptor_infos != nullptr);

    for (UINT i = 0; i < num_descriptors; ++i)
    {
        auto src = &src_descriptor_infos[i];
        auto dst = &dest_descriptor_infos[i];

        // Copy tracked descriptor state values.
        dst->create_object_id = src->create_object_id;
        dst->create_call_id   = src->create_call_id;
        dst->is_copy          = true;
        dst->resource_ids     = src->resource_ids;
        dst->resource_gpu_va  = src->resource_gpu_va;

        // Create or reset the destination descriptor's create_parameters buffer.
        if (dst->create_parameters == nullptr)
        {
            dst->create_parameters = std::make_unique<util::MemoryOutputStream>();
        }
        else
        {
            dst->create_parameters->Clear();
        }

        // Copy the source descriptor's creation parameters to destination.
        if ((src->create_parameters != nullptr) && (src->create_parameters->GetDataSize() != 0))
        {
            // Compute copy size.
            size_t heap_and_index_size = 0;
            if (!src->is_copy)
            {
                heap_and_index_size = sizeof(DxDescriptorInfo::heap_id) + sizeof(DxDescriptorInfo::index);
            }
            size_t src_size  = src->create_parameters->GetDataSize();
            size_t copy_size = src_size - heap_and_index_size;

            // If the source descriptor is modified asynchronously in another thread, its create_parameters may be
            // invalid. This behavior is not supported by DX12--descriptor creations and copies are free-threaded. Log a
            // warning and prevent the copy from crashing if an unexpected copy size is encountered.
            if ((copy_size == 0) || (copy_size > src_size))
            {
                GFXRECON_LOG_WARNING("The state of the source descriptor (0x%zx) in CopyDescriptors has an unexpected "
                                     "size. Skipping copy to destination descriptor (0x%zx).",
                                     src->cpu_address,
                                     dst->cpu_address);
            }
            else
            {
                dst->create_parameters->Write(src->create_parameters->GetData(), copy_size);

                // Additonal check to detect potential errors in the copy due to asynchronous changes to the source
                // descriptor.
                if ((src->create_parameters->GetDataSize() - heap_and_index_size) !=
                    dst->create_parameters->GetDataSize())
                {
                    GFXRECON_LOG_WARNING(
                        "The state of the source descriptor (0x%zx) may have changed during CopyDescriptors. The state "
                        "of the destination descriptor (0x%zx) may be invalid.",
                        src->cpu_address,
                        dst->cpu_address);
                }
            }
        }
        else
        {
            GFXRECON_LOG_WARNING_ONCE("CopyDescriptors was called with a source descriptor that may not have been "
                                      "initialized (created or copied to).");
        }
    }
}

void Dx12StateTracker::TrackDescriptorResources(SIZE_T          descriptor_cpu_address,
                                                ID3D12Resource* resource1,
                                                ID3D12Resource* resource2)
{
    auto* descriptor_info            = GetDescriptorInfo(descriptor_cpu_address);
    descriptor_info->resource_ids[0] = GetDx12WrappedId<ID3D12Resource>(resource1);
    descriptor_info->resource_ids[1] = GetDx12WrappedId<ID3D12Resource>(resource2);
}

void Dx12StateTracker::TrackDescriptorGpuVa(SIZE_T descriptor_cpu_address, D3D12_GPU_VIRTUAL_ADDRESS address)
{
    auto* descriptor_info            = GetDescriptorInfo(descriptor_cpu_address);
    descriptor_info->resource_gpu_va = address;
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

void Dx12StateTracker::TrackPrivateData(IUnknown_Wrapper* wrapper, REFGUID name, UINT data_size, const void* data)
{
    GFXRECON_ASSERT(wrapper != nullptr);

    auto* info = GetWrapperInfo(wrapper);
    if (info)
    {
        if (data != nullptr)
        {
            std::vector<uint8_t> private_data(data_size);
            memcpy(private_data.data(), data, data_size);
            info->private_datas[name] = std::move(private_data);
        }
        else
        {
            info->private_datas.erase(name);
        }
    }
}

void Dx12StateTracker::TrackResidencyPriority(ID3D12Device1_Wrapper*          device_wrapper,
                                              UINT                            num_objects,
                                              ID3D12Pageable* const*          objects,
                                              const D3D12_RESIDENCY_PRIORITY* priorities)
{
    if (num_objects > 0)
    {
        GFXRECON_ASSERT(device_wrapper != nullptr);
        GFXRECON_ASSERT(device_wrapper->GetObjectInfo() != nullptr);
        GFXRECON_ASSERT(objects != nullptr);
        GFXRECON_ASSERT(priorities != nullptr);

        auto                         device_info = device_wrapper->GetObjectInfo();
        std::unique_lock<std::mutex> lock(state_table_mutex_);
        for (UINT i = 0; i < num_objects; ++i)
        {
            GFXRECON_ASSERT(objects[i] != nullptr);
            auto handle_id                               = GetDx12WrappedId<ID3D12Pageable>(objects[i]);
            device_info->residency_priorities[handle_id] = priorities[i];
        }
    }
}

void Dx12StateTracker::TrackRelease(IUnknown_Wrapper* wrapper)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    auto* info = GetWrapperInfo(wrapper);
    if (info && info->create_object_id != format::kNullHandleId)
    {
        auto* device_wrapper = state_table_.GetID3D12Device_Wrapper(info->create_object_id);
        if (device_wrapper)
        {
            auto device_info = device_wrapper->GetObjectInfo();
            GFXRECON_ASSERT(device_info != nullptr);
            std::unique_lock<std::mutex> lock(state_table_mutex_);
            device_info->residency_priorities.erase(wrapper->GetCaptureId());
        }
    }
}

void Dx12StateTracker::TrackBuildRaytracingAccelerationStructure(
    ID3D12GraphicsCommandList4_Wrapper* list_wrapper, const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC* desc)
{
    // Get the wrapper of the destination resource.
    ID3D12Resource_Wrapper* resource_wrapper = nullptr;
    auto                    device5          = graphics::dx12::GetDeviceComPtrFromChild<ID3D12Device5>(
        list_wrapper->GetWrappedObjectAs<ID3D12GraphicsCommandList4>());

    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO prebuild_info;
    device5->GetRaytracingAccelerationStructurePrebuildInfo(&desc->Inputs, &prebuild_info);
    {
        std::unique_lock<std::mutex> lock(state_table_mutex_);
        resource_wrapper =
            GetResourceWrapperForGpuVa(desc->DestAccelerationStructureData,
                                       desc->DestAccelerationStructureData + prebuild_info.ResultDataMaxSizeInBytes,
                                       IsResourceUsedForAccelerationStructure);
    }

    if (resource_wrapper)
    {

        DxAccelerationStructureBuildInfo build_info;
        build_info.dest_gpu_va          = desc->DestAccelerationStructureData;
        build_info.destination_resource = resource_wrapper;
        build_info.dest_size            = prebuild_info.ResultDataMaxSizeInBytes;

        // Save build input arguments.
        build_info.inputs = desc->Inputs;

        build_info.is_tlas_with_array_of_pointers = false;

        // Save a copy of the input's geometry desc pointers.
        if (desc->Inputs.Type == D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE_BOTTOM_LEVEL)
        {
            for (UINT i = 0; i < desc->Inputs.NumDescs; ++i)
            {
                if (desc->Inputs.DescsLayout == D3D12_ELEMENTS_LAYOUT_ARRAY)
                {
                    build_info.inputs_geometry_descs.push_back(desc->Inputs.pGeometryDescs[i]);
                }
                else if (desc->Inputs.DescsLayout == D3D12_ELEMENTS_LAYOUT_ARRAY_OF_POINTERS)
                {
                    build_info.inputs_geometry_descs.push_back(*desc->Inputs.ppGeometryDescs[i]);
                }
            }

            // The geometry desc pointers may be invalid when build_info is used in the future, so clear them here.
            build_info.inputs.pGeometryDescs  = nullptr;
            build_info.inputs.ppGeometryDescs = nullptr;
        }
        else if (desc->Inputs.Type == D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL)
        {
            // This code path adds support for top level AS builds where `DescsLayout ==
            // D3D12_ELEMENTS_LAYOUT_ARRAY_OF_POINTERS`. Any top level AS build--regardless of DescLayout value--could
            // also use this code path, but this path is newer and not as thoroughly tested so use the original code
            // path where possible.
            if (desc->Inputs.DescsLayout == D3D12_ELEMENTS_LAYOUT_ARRAY_OF_POINTERS)
            {
                // In order to store TLAS instance descs, use CopyRaytracingAccelerationStructure with
                // D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE_VISUALIZATION_DECODE_FOR_TOOLS after the build
                // command list has completed.
                build_info.is_tlas_with_array_of_pointers = true;
            }
        }

        // Compute the required inputs buffer size and entry information.
        uint64_t                                       inputs_buffer_size = 0;
        std::vector<graphics::dx12::InputsBufferEntry> inputs_buffer_entries;
        graphics::dx12::GetAccelerationStructureInputsBufferEntries(
            build_info.inputs, build_info.inputs_geometry_descs.data(), inputs_buffer_size, inputs_buffer_entries);

        // TLAS builds shouldn't have more than one input buffer entry.
        GFXRECON_ASSERT((desc->Inputs.Type == D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE_BOTTOM_LEVEL) ||
                        (inputs_buffer_entries.size() <= 1));

        // Save input data to a secodary resource.
        build_info.input_data_size = inputs_buffer_size;
        if (build_info.input_data_size > 0)
        {
            if (build_info.is_tlas_with_array_of_pointers)
            {
                build_info.input_data_header_size =
                    sizeof(D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_TOOLS_VISUALIZATION_HEADER);
                build_info.input_data_size += build_info.input_data_header_size;
            }

            // Sort the entries by GPU VA so that entries from the same resource are contiguous.
            std::sort(inputs_buffer_entries.begin(),
                      inputs_buffer_entries.end(),
                      [](const graphics::dx12::InputsBufferEntry& e1, const graphics::dx12::InputsBufferEntry& e2) {
                          return (*e1.desc_gpu_va) < (*e2.desc_gpu_va);
                      });

            graphics::dx12::ID3D12ResourceComPtr inputs_data_resource = nullptr;

            // If the destination resource already has an acceleration structure at the same address, with the same
            // inputs size, and has not been copied to or from, then reuse its inputs_data_resource.
            auto resource_info         = resource_wrapper->GetObjectInfo();
            auto existing_accel_struct = resource_info->acceleration_structure_builds.find(build_info.dest_gpu_va);
            if (existing_accel_struct != resource_info->acceleration_structure_builds.end())
            {
                if ((existing_accel_struct->second.input_data_size == build_info.input_data_size) &&
                    (!existing_accel_struct->second.was_copy_source) &&
                    (existing_accel_struct->second.copy_source_gpu_va == 0))
                {
                    inputs_data_resource = existing_accel_struct->second.input_data_resource;
                }
            }

            // If a reusable inputs_data_resource was not found, create a new buffer.
            if (inputs_data_resource == nullptr)
            {
                inputs_data_resource = graphics::dx12::CreateBufferResource(device5,
                                                                            build_info.input_data_size,
                                                                            D3D12_HEAP_TYPE_DEFAULT,
                                                                            D3D12_RESOURCE_STATE_COPY_DEST,
                                                                            D3D12_RESOURCE_FLAG_ALLOW_UNORDERED_ACCESS);
            }
            GFXRECON_ASSERT(inputs_data_resource);
            build_info.input_data_resource = inputs_data_resource;

            // Save the build info with the command list info.
            auto list_info = list_wrapper->GetObjectInfo();
            GFXRECON_ASSERT(list_info);
            list_info->acceleration_structure_builds.push_back(build_info);

            bool is_direct_command_list = (list_info->command_list_type == D3D12_COMMAND_LIST_TYPE_DIRECT);

            // Add CopyBufferRegion(s) and ResourceBarrier(s) to command list to save the build input resource data.
            auto curr_entry_iter = inputs_buffer_entries.begin();
            auto end_entry_iter  = inputs_buffer_entries.end();
            while (!build_info.is_tlas_with_array_of_pointers && curr_entry_iter != end_entry_iter)
            {
                ID3D12Resource_Wrapper* src_resource_wrapper = nullptr;
                {
                    std::unique_lock<std::mutex> lock(state_table_mutex_);
                    src_resource_wrapper = GetResourceWrapperForGpuVa(
                        *curr_entry_iter->desc_gpu_va, *curr_entry_iter->desc_gpu_va + curr_entry_iter->size);
                }

                if (src_resource_wrapper == nullptr)
                {
                    GFXRECON_LOG_ERROR(
                        "Failed to find the resource object that contains the GPU VA (value=%" PRIu64
                        ") of acceleration structure build input data. Acceleration structure trimming may "
                        "fail.",
                        *curr_entry_iter->desc_gpu_va);
                    ++curr_entry_iter;
                    continue;
                }

                auto src_resource_info = src_resource_wrapper->GetObjectInfo();
                GFXRECON_ASSERT(src_resource_info != nullptr);
                GFXRECON_ASSERT(src_resource_info->subresource_sizes[0] > 0);

#if GFXRECON_ACCEL_STRUCT_TRIM_BARRIER
                auto src_resource = src_resource_wrapper->GetWrappedObjectAs<ID3D12Resource>();

                GFXRECON_ASSERT(src_resource != nullptr);

                // Look for a transition for the resource that was recorded to the current command list.
                auto src_resource_states = src_resource_info->subresource_transitions.at(0).states;
                for (auto& transition_barrier : list_info->transition_barriers)
                {
                    if (transition_barrier.resource_wrapper == src_resource_wrapper)
                    {
                        src_resource_states = transition_barrier.state_after;
                    }
                }

                // Determine if the resource transitions should be injected to the command list.
                bool needs_resource_transition =
                    ((src_resource_states & D3D12_RESOURCE_STATE_COPY_SOURCE) != D3D12_RESOURCE_STATE_COPY_SOURCE);
                if (!is_direct_command_list && (src_resource_states != D3D12_RESOURCE_STATE_NON_PIXEL_SHADER_RESOURCE))
                {
                    // Build input resources should have state D3D12_RESOURCE_STATE_NON_PIXEL_SHADER_RESOURCE, but can
                    // also have other resource states. Compute command lists may not be able to transition to and from
                    // the other states, so skip the resource state transitions for this resource. This may result in
                    // debug layer errors due to the resource missing the D3D12_RESOURCE_STATE_COPY_SOURCE state for
                    // CopyBufferRegions, but it otherwise appears to work.
                    needs_resource_transition = false;
                }

                // Add a resource transition before the copy, adding state D3D12_RESOURCE_STATE_COPY_SOURCE.
                if (needs_resource_transition)
                {
                    D3D12_RESOURCE_TRANSITION_BARRIER pre_transition;
                    pre_transition.pResource   = src_resource;
                    pre_transition.Subresource = 0;
                    pre_transition.StateBefore = src_resource_states;
                    pre_transition.StateAfter  = src_resource_states | D3D12_RESOURCE_STATE_COPY_SOURCE;
                    D3D12_RESOURCE_BARRIER pre_barrier;
                    pre_barrier.Type       = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
                    pre_barrier.Flags      = D3D12_RESOURCE_BARRIER_FLAG_NONE;
                    pre_barrier.Transition = pre_transition;
                    list_wrapper->ResourceBarrier(1, &pre_barrier);
                }
#endif
                // Copy all inputs data from the current resource to the inputs_data_resource.
                auto end_gpu_va = src_resource_info->gpu_va + src_resource_info->subresource_sizes[0];
                while ((curr_entry_iter != end_entry_iter) && (*curr_entry_iter->desc_gpu_va < end_gpu_va))
                {
                    auto curr_gpu_va = *curr_entry_iter->desc_gpu_va;
                    auto src_offset  = curr_gpu_va - src_resource_info->gpu_va;

                    // Copy the inputs data to the inputs_data_resource.
                    list_wrapper->CopyBufferRegion(inputs_data_resource,
                                                   curr_entry_iter->offset,
                                                   src_resource_wrapper->GetWrappedObjectAs<ID3D12Resource>(),
                                                   src_offset,
                                                   curr_entry_iter->size);

                    ++curr_entry_iter;
                }

#if GFXRECON_ACCEL_STRUCT_TRIM_BARRIER
                // Add a resource transition after the copy, restoring the original state.
                if (needs_resource_transition)
                {
                    D3D12_RESOURCE_TRANSITION_BARRIER post_transition;
                    post_transition.pResource   = src_resource;
                    post_transition.Subresource = 0;
                    post_transition.StateBefore = src_resource_states | D3D12_RESOURCE_STATE_COPY_SOURCE;
                    post_transition.StateAfter  = src_resource_states;
                    D3D12_RESOURCE_BARRIER post_barrier;
                    post_barrier.Type       = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
                    post_barrier.Flags      = D3D12_RESOURCE_BARRIER_FLAG_NONE;
                    post_barrier.Transition = post_transition;
                    list_wrapper->ResourceBarrier(1, &post_barrier);
                }
#endif
            }
        }
    }
    else
    {
        GFXRECON_LOG_ERROR("Failed to find the resource object that corresponds to the DestAccelerationStructureData "
                           "GPU VA (value=%" PRIu64
                           ") in BuildRaytracingAccelerationStructure. Acceleration structure trimming may fail.",
                           desc->DestAccelerationStructureData);
    }
}

void Dx12StateTracker::TrackCopyRaytracingAccelerationStructure(
    ID3D12GraphicsCommandList4_Wrapper*               list_wrapper,
    D3D12_GPU_VIRTUAL_ADDRESS                         dest_acceleration_structure_data,
    D3D12_GPU_VIRTUAL_ADDRESS                         source_acceleration_structure_data,
    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE mode)
{
    // Only track clone and compact copies.
    if ((mode != D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE_CLONE) &&
        (mode != D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE_COMPACT))
    {
        return;
    }

    ID3D12Resource_Wrapper* dest_resource_wrapper   = nullptr;
    ID3D12Resource_Wrapper* source_resource_wrapper = nullptr;
    {
        std::unique_lock<std::mutex> lock(state_table_mutex_);
        // TODO: find and use the data size of acceleration structure to replace 0
        //       for function GetResourceWrapperForGpuVa.
        dest_resource_wrapper =
            GetResourceWrapperForGpuVa(dest_acceleration_structure_data, 0, IsResourceUsedForAccelerationStructure);
        source_resource_wrapper =
            GetResourceWrapperForGpuVa(source_acceleration_structure_data, 0, IsResourceUsedForAccelerationStructure);
    }

    if (dest_resource_wrapper && source_resource_wrapper)
    {
        DxAccelerationStructureCopyInfo copy_info;
        copy_info.dest_gpu_va             = dest_acceleration_structure_data;
        copy_info.dest_resource_wrapper   = dest_resource_wrapper;
        copy_info.source_gpu_va           = source_acceleration_structure_data;
        copy_info.source_resource_wrapper = source_resource_wrapper;
        copy_info.mode                    = mode;
        list_wrapper->GetObjectInfo()->acceleration_structure_copies.push_back(copy_info);
    }
    else
    {
        GFXRECON_LOG_ERROR("Failed to find the resource objects that corresponds to the source and dest GPU VAs in "
                           "CopyRaytracingAccelerationStructure. Acceleration structure trimming may fail.");
    }
}

void Dx12StateTracker::TrackCreateStateObject(ID3D12Device5_Wrapper*         device5_wrapper,
                                              const D3D12_STATE_OBJECT_DESC* desc,
                                              void**                         state_object_void_ptr)
{
    // Track root signatures associated with this state object.
    TrackRootSignatureWithStateObject(desc, state_object_void_ptr);
}

void Dx12StateTracker::TrackRootSignatureWithStateObject(const D3D12_STATE_OBJECT_DESC* desc,
                                                         void**                         state_object_void_ptr)
{
    for (UINT i = 0; i < desc->NumSubobjects; ++i)
    {
        const auto&                  subobject              = desc->pSubobjects[i];
        ID3D12RootSignature_Wrapper* root_signature_wrapper = nullptr;
        if (subobject.Type == D3D12_STATE_SUBOBJECT_TYPE_LOCAL_ROOT_SIGNATURE)
        {
            if (subobject.pDesc != nullptr)
            {
                auto local_root_signature_desc = reinterpret_cast<const D3D12_LOCAL_ROOT_SIGNATURE*>(subobject.pDesc);
                if (local_root_signature_desc->pLocalRootSignature != nullptr)
                {
                    root_signature_wrapper =
                        reinterpret_cast<ID3D12RootSignature_Wrapper*>(local_root_signature_desc->pLocalRootSignature);
                }
            }
        }
        else if (subobject.Type == D3D12_STATE_SUBOBJECT_TYPE_GLOBAL_ROOT_SIGNATURE)
        {
            if (subobject.pDesc != nullptr)
            {
                auto global_root_signature_desc = reinterpret_cast<const D3D12_GLOBAL_ROOT_SIGNATURE*>(subobject.pDesc);
                if (global_root_signature_desc->pGlobalRootSignature != nullptr)
                {
                    root_signature_wrapper = reinterpret_cast<ID3D12RootSignature_Wrapper*>(
                        global_root_signature_desc->pGlobalRootSignature);
                }
            }
        }

        if (root_signature_wrapper != nullptr)
        {
            GFXRECON_ASSERT(state_object_void_ptr != nullptr);
            GFXRECON_ASSERT(*state_object_void_ptr != nullptr);
            auto state_object_wrapper = reinterpret_cast<ID3D12StateObject_Wrapper*>(*state_object_void_ptr);

            GFXRECON_ASSERT(state_object_wrapper->GetObjectInfo() != nullptr);
            GFXRECON_ASSERT(root_signature_wrapper->GetObjectInfo() != nullptr);
            auto state_object_info = state_object_wrapper->GetObjectInfo();
            state_object_info->root_signature_wrapper_infos[root_signature_wrapper->GetCaptureId()] =
                root_signature_wrapper->GetObjectInfo();
        }
    }
}

void Dx12StateTracker::TrackAddToStateObject(ID3D12Device7_Wrapper*         device5_wrapper,
                                             const D3D12_STATE_OBJECT_DESC* desc,
                                             ID3D12StateObject*             state_object_to_grow_from,
                                             void**                         state_object_void_ptr)
{
    if ((state_object_to_grow_from != nullptr) && (state_object_void_ptr != nullptr) &&
        (*state_object_void_ptr != nullptr))
    {
        TrackRootSignatureWithStateObject(desc, state_object_void_ptr);
        auto state_object_wrapper           = reinterpret_cast<ID3D12StateObject_Wrapper*>(*state_object_void_ptr);
        auto grow_from_state_object_wrapper = reinterpret_cast<ID3D12StateObject_Wrapper*>(state_object_to_grow_from);

        GFXRECON_ASSERT(state_object_wrapper->GetObjectInfo() != nullptr);
        GFXRECON_ASSERT(grow_from_state_object_wrapper->GetObjectInfo() != nullptr);
        auto state_object_info                                 = state_object_wrapper->GetObjectInfo();
        state_object_info->grow_from_state_object_wrapper_info = std::make_pair(
            grow_from_state_object_wrapper->GetCaptureId(), grow_from_state_object_wrapper->GetObjectInfo());
    }
}

void Dx12StateTracker::TrackGetShaderIdentifier(ID3D12StateObjectProperties_Wrapper* state_object_properties_wrapper,
                                                void*                                result,
                                                LPCWSTR                              export_name,
                                                const util::MemoryOutputStream*      parameter_buffer)
{
    GFXRECON_ASSERT(state_object_properties_wrapper != nullptr);
    GFXRECON_ASSERT(state_object_properties_wrapper->GetObjectInfo() != nullptr);

    auto         state_object_properties_info = state_object_properties_wrapper->GetObjectInfo();
    std::wstring export_name_wstring          = export_name;
    state_object_properties_info->get_shader_identifier_call_parameters[export_name_wstring] =
        std::make_shared<util::MemoryOutputStream>(parameter_buffer->GetData(), parameter_buffer->GetDataSize());
}

bool Dx12StateTracker::IsAccelerationStructureResource(format::HandleId id)
{
    ID3D12Resource_Wrapper* resource_wrapper = nullptr;
    bool                    result           = false;

    if (id != format::kNullHandleId)
    {
        resource_wrapper = state_table_.GetID3D12Resource_Wrapper(id);

        if (resource_wrapper != nullptr)
        {
            auto object_info = resource_wrapper->GetObjectInfo();

            if ((object_info->initial_state & D3D12_RESOURCE_STATE_RAYTRACING_ACCELERATION_STRUCTURE) != 0)
            {
                result = true;
            }
        }
    }

    return result;
}

ID3D12Resource_Wrapper*
Dx12StateTracker::GetResourceWrapperForGpuVa(D3D12_GPU_VIRTUAL_ADDRESS          gpu_va,
                                             uint64_t                           minimum_end_address,
                                             graphics::ResourceMatchFunctionPtr resource_match_func)
{
    ID3D12Resource_Wrapper* result = nullptr;
    auto resource_id               = state_table_.GetResourceForGpuVa(gpu_va, minimum_end_address, resource_match_func);

    if (resource_id != format::kNullHandleId)
    {
        result = state_table_.GetID3D12Resource_Wrapper(resource_id);
    }

    return result;
}

uint64_t Dx12StateTracker::CommitAccelerationStructureBuildInfo(DxAccelerationStructureBuildInfo& accel_struct_build)
{
    accel_struct_build.id = accel_struct_id_.fetch_add(1);

    auto  dest_resource_info = accel_struct_build.destination_resource->GetObjectInfo();
    auto& builds_map         = dest_resource_info->acceleration_structure_builds;
    auto  exact_iter         = builds_map.find(accel_struct_build.dest_gpu_va);
    if (exact_iter != builds_map.end() && exact_iter->second.dest_size == accel_struct_build.dest_size)
    {
        // Replace the existing AS build info if the dest_gpu_va and dest_size match.
        builds_map[accel_struct_build.dest_gpu_va] = accel_struct_build;
    }
    else
    {
        // Find overlapping acceleration structures that were previously built to the destination resource.
        auto lower_iter = builds_map.lower_bound(accel_struct_build.dest_gpu_va);
        auto upper_iter = builds_map.lower_bound(accel_struct_build.dest_gpu_va + accel_struct_build.dest_size);

        // Fixup lower_iter to point to the first map entry that overlaps with accel_struct_build.dest_gpu_va.
        if (lower_iter != builds_map.begin())
        {
            --lower_iter;
        }
        if ((lower_iter != upper_iter) &&
            ((lower_iter->second.dest_gpu_va + lower_iter->second.dest_size) <= accel_struct_build.dest_gpu_va))
        {
            ++lower_iter;
        }

        // Erase entries for AS builds that overlap with the new build.
        builds_map.erase(lower_iter, upper_iter);

        // Add the new build info to the resource.
        builds_map[accel_struct_build.dest_gpu_va] = accel_struct_build;
    }

    return accel_struct_build.id;
}

uint64_t
Dx12StateTracker::CommitAccelerationStructureCopyInfo(DxAccelerationStructureCopyInfo&      accel_struct_copy,
                                                      graphics::dx12::ID3D12ResourceComPtr& inputs_data_resource)
{
    auto& source_builds_map = accel_struct_copy.source_resource_wrapper->GetObjectInfo()->acceleration_structure_builds;
    GFXRECON_ASSERT(source_builds_map.find(accel_struct_copy.source_gpu_va) != source_builds_map.end());
    auto& source_build_info = source_builds_map[accel_struct_copy.source_gpu_va];

    // Add a build info for the copy dest.
    DxAccelerationStructureBuildInfo dest_build_info = source_build_info;

    // Fix up destination info for the dest acceleration structure.
    dest_build_info.dest_gpu_va          = accel_struct_copy.dest_gpu_va;
    dest_build_info.destination_resource = accel_struct_copy.dest_resource_wrapper;

    // Fix up copy state for the dest acceleration structure.
    dest_build_info.was_copy_source    = false;
    dest_build_info.copy_source_gpu_va = source_build_info.dest_gpu_va;
    dest_build_info.copy_mode          = accel_struct_copy.mode;

    // Mark that the source acceleration structure was copied.
    source_build_info.was_copy_source = true;

    if (D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE_CLONE != accel_struct_copy.mode)
    {
        // TODO: Set dest_size from post build info.
        dest_build_info.dest_size = 1;
    }

    inputs_data_resource = dest_build_info.input_data_resource;

    return CommitAccelerationStructureBuildInfo(dest_build_info);
}

void Dx12StateTracker::TrackSetColorSpace1(IDXGISwapChain_Wrapper* wrapper,
                                           HRESULT                 result,
                                           DXGI_COLOR_SPACE_TYPE   ColorSpace)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    auto wrapper_info = wrapper->GetObjectInfo();

    wrapper_info->set_color_space  = true;
    wrapper_info->color_space_type = ColorSpace;
}

void Dx12StateTracker::TrackSetHDRMetaData(
    IDXGISwapChain_Wrapper* wrapper, HRESULT result, DXGI_HDR_METADATA_TYPE Type, UINT Size, void* pMetaData)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    auto wrapper_info = wrapper->GetObjectInfo();

    wrapper_info->set_hdr_metadata  = true;
    wrapper_info->hdr_metadata_type = Type;
    wrapper_info->hdr_metadata_size = Size;

    if (pMetaData != nullptr)
    {
        wrapper_info->hdr_metadata = new char[Size]();
        memcpy(wrapper_info->hdr_metadata, pMetaData, Size);
    }
}

void Dx12StateTracker::TrackSetName(IUnknown_Wrapper* wrapper, HRESULT result, LPCWSTR Name)
{
    GFXRECON_ASSERT(wrapper != nullptr);

    auto* info = GetWrapperInfo(wrapper);
    if (info)
    {
        if (Name != nullptr)
        {
            info->object_name = Name;
        }
        else
        {
            info->object_name = L"";
        }
    }
}

#ifdef GFXRECON_AGS_SUPPORT
void Dx12StateTracker::TrackAgsCalls(void*                           object_ptr,
                                     format::ApiCallId               call_id,
                                     const util::MemoryOutputStream* call_parameter_buffer)
{
    std::unique_lock<std::mutex> lock(ags_state_table_mutex_);
    switch (call_id)
    {
        case format::ApiCallId::ApiCall_Ags_agsInitialize_6_0_1:
            AddAgsInitializeEntry(reinterpret_cast<AGSContext*>(object_ptr), call_id, call_parameter_buffer);
            break;
        case format::ApiCallId::ApiCall_Ags_agsDeInitialize_6_0_1:
            TrackAgsDeInitialize(reinterpret_cast<AGSContext*>(object_ptr));
            break;
        case format::ApiCallId::ApiCall_Ags_agsDriverExtensionsDX12_CreateDevice_6_0_1:
            AddAgsDriverExtensionsDX12CreateDeviceEntry(
                reinterpret_cast<ID3D12Device*>(object_ptr), call_id, call_parameter_buffer);
            break;
        case format::ApiCallId::ApiCall_Ags_agsDriverExtensionsDX12_DestroyDevice_6_0_1:
            TrackAgsDestroyDevice(reinterpret_cast<ID3D12Device*>(object_ptr));
            break;
        default:
            GFXRECON_LOG_WARNING("AGS call track handler has not been implemented, call ID: %d.", call_id);
            break;
    }
}

void Dx12StateTracker::AddAgsInitializeEntry(AGSContext*                     context,
                                             format::ApiCallId               call_id,
                                             const util::MemoryOutputStream* create_parameter_buffer)
{
    ags_state_table_.InsertContextCreateData(context, create_parameter_buffer);
}

void Dx12StateTracker::TrackAgsDeInitialize(AGSContext* context)
{
    ags_state_table_.RemoveContextCreateData(context);
}

void Dx12StateTracker::AddAgsDriverExtensionsDX12CreateDeviceEntry(
    ID3D12Device* device, format::ApiCallId call_id, const util::MemoryOutputStream* create_parameter_buffer)
{
    ags_state_table_.InsertDeviceCreateData(device, create_parameter_buffer);
}

void Dx12StateTracker::TrackAgsDestroyDevice(ID3D12Device* device)
{
    ags_state_table_.RemoveDeviceCreateData(device);
}
#endif // GFXRECON_AGS_SUPPORT

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
