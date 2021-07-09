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

void Dx12StateTracker::TrackCommand(ID3D12GraphicsCommandList_Wrapper* list_wrapper,
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
        // Clear command data on command buffer reset.
        list_info->command_data.Reset();
    }

    // Append the command data.
    size_t size = parameter_buffer->GetDataSize();
    list_info->command_data.Write(&size, sizeof(size));
    list_info->command_data.Write(&call_id, sizeof(call_id));
    list_info->command_data.Write(parameter_buffer->GetData(), size);
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
