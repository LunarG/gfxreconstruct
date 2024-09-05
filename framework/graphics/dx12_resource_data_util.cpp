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

#include "graphics/dx12_resource_data_util.h"

#include "graphics/dx12_util.h"
#include "util/logging.h"

#include <inttypes.h>
#include <algorithm>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

HRESULT
Dx12ResourceDataUtil::MapSubresourceAndReadData(ID3D12Resource* resource, UINT subresource, size_t size, uint8_t* data)
{
    uint8_t* subresource_data;
    HRESULT  result = dx12::MapSubresource(resource, subresource, nullptr, subresource_data);
    if (SUCCEEDED(result))
    {
        util::platform::MemoryCopy(data, size, subresource_data, size);
        resource->Unmap(subresource, &dx12::kZeroRange);
    }
    return result;
}

HRESULT Dx12ResourceDataUtil::MapSubresourceAndWriteData(ID3D12Resource* resource,
                                                         UINT            subresource,
                                                         size_t          size,
                                                         const uint8_t*  data)
{
    uint8_t* subresource_data;
    HRESULT  result = dx12::MapSubresource(resource, subresource, &dx12::kZeroRange, subresource_data);
    if (SUCCEEDED(result))
    {
        util::platform::MemoryCopy(subresource_data, size, data, size);
        resource->Unmap(subresource, nullptr);
    }
    return result;
}

// Add a transition barrier to cmd_list. Returns true if cmd_list was modified.
bool AddTransitionBarrier(ID3D12GraphicsCommandList*     cmd_list,
                          ID3D12Resource*                resource,
                          UINT                           subresource,
                          const dx12::ResourceStateInfo& current_state,
                          const dx12::ResourceStateInfo& desired_state)
{
    // It is expected that barrier_flags can have bits set for either D3D12_RESOURCE_BARRIER_FLAG_BEGIN_ONLY or
    // D3D12_RESOURCE_BARRIER_FLAG_END_ONLY, not both.
    GFXRECON_ASSERT((current_state.barrier_flags &
                     (D3D12_RESOURCE_BARRIER_FLAG_BEGIN_ONLY | D3D12_RESOURCE_BARRIER_FLAG_END_ONLY)) !=
                    (D3D12_RESOURCE_BARRIER_FLAG_BEGIN_ONLY | D3D12_RESOURCE_BARRIER_FLAG_END_ONLY));
    GFXRECON_ASSERT((current_state.barrier_flags &
                     (D3D12_RESOURCE_BARRIER_FLAG_BEGIN_ONLY | D3D12_RESOURCE_BARRIER_FLAG_END_ONLY)) !=
                    (D3D12_RESOURCE_BARRIER_FLAG_BEGIN_ONLY | D3D12_RESOURCE_BARRIER_FLAG_END_ONLY));

    // Return early if the resource is already in the desired state
    bool current_barrier_begins_split = ((current_state.barrier_flags & D3D12_RESOURCE_BARRIER_FLAG_BEGIN_ONLY) ==
                                         D3D12_RESOURCE_BARRIER_FLAG_BEGIN_ONLY);
    bool desired_barrier_begins_split = ((desired_state.barrier_flags & D3D12_RESOURCE_BARRIER_FLAG_BEGIN_ONLY) ==
                                         D3D12_RESOURCE_BARRIER_FLAG_BEGIN_ONLY);
    if (current_state.states == desired_state.states)
    {
        if (current_barrier_begins_split == desired_barrier_begins_split)
        {
            return false;
        }
    }

    D3D12_RESOURCE_BARRIER_FLAGS flags =
        desired_barrier_begins_split ? D3D12_RESOURCE_BARRIER_FLAG_BEGIN_ONLY : D3D12_RESOURCE_BARRIER_FLAG_NONE;

    // Handle the cases where the resource is currently in the middle of a split transition barrier.
    if (current_barrier_begins_split)
    {
        // If the previous state started a split transition to the desired state, complete the current split transition.
        if (desired_state.states == current_state.states)
        {
            flags = D3D12_RESOURCE_BARRIER_FLAG_END_ONLY;
        }
        else
        {
            // If the previous state started a split transition to a state other than the desired state, add an
            // additional transition to complete the split transition.
            AddTransitionBarrier(cmd_list,
                                 resource,
                                 subresource,
                                 current_state,
                                 { current_state.states, D3D12_RESOURCE_BARRIER_FLAG_END_ONLY });
        }
    }

    D3D12_RESOURCE_TRANSITION_BARRIER transition;
    transition.pResource   = resource;
    transition.Subresource = subresource;
    transition.StateBefore = current_state.states;
    transition.StateAfter  = desired_state.states;

    D3D12_RESOURCE_BARRIER barrier;
    barrier.Type       = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
    barrier.Flags      = flags;
    barrier.Transition = transition;

    cmd_list->ResourceBarrier(1, &barrier);

    return true;
}

size_t Dx12ResourceDataUtil::GetSubresourceCount(ID3D12Resource* resource)
{
    GFXRECON_ASSERT(resource != nullptr);

    size_t sub_count = 0;
    auto   device    = dx12::GetDeviceComPtrFromChild<ID3D12Device>(resource);
    auto   res_desc  = resource->GetDesc();

    if (res_desc.Dimension == D3D12_RESOURCE_DIMENSION_BUFFER)
    {
        sub_count = 1;
    }
    else
    {
        GFXRECON_ASSERT((res_desc.Dimension == D3D12_RESOURCE_DIMENSION_TEXTURE1D) ||
                        (res_desc.Dimension == D3D12_RESOURCE_DIMENSION_TEXTURE2D) ||
                        (res_desc.Dimension == D3D12_RESOURCE_DIMENSION_TEXTURE3D));

        uint32_t plane_count = 1;

        // Get the plane count for the texture format.  With D3D12, each plane has its own subresource.
        D3D12_FEATURE_DATA_FORMAT_INFO format_info = { res_desc.Format, 0 };
        if (SUCCEEDED(device->CheckFeatureSupport(D3D12_FEATURE_FORMAT_INFO, &format_info, sizeof(format_info))))
        {
            plane_count = format_info.PlaneCount;
        }

        sub_count = res_desc.MipLevels * plane_count;

        if ((res_desc.Dimension == D3D12_RESOURCE_DIMENSION_TEXTURE2D) ||
            (res_desc.Dimension == D3D12_RESOURCE_DIMENSION_TEXTURE1D))
        {
            sub_count *= res_desc.DepthOrArraySize;
        }
    }
    return sub_count;
}

void Dx12ResourceDataUtil::GetResourceCopyInfo(ID3D12Resource*                                  resource,
                                               size_t&                                          subresource_count,
                                               std::vector<uint64_t>&                           subresource_offsets,
                                               std::vector<uint64_t>&                           subresource_sizes,
                                               std::vector<D3D12_PLACED_SUBRESOURCE_FOOTPRINT>& layouts,
                                               uint64_t&                                        total_size,
                                               ID3D12Device*                                    device)
{
    GFXRECON_ASSERT(resource != nullptr);

    dx12::ID3D12DeviceComPtr device_com_ptr;
    if (device == nullptr)
    {
        device_com_ptr = dx12::GetDeviceComPtrFromChild<ID3D12Device>(resource);
        device         = device_com_ptr.GetInterfacePtr();
    }
    GFXRECON_ASSERT(device != nullptr);

    subresource_count = GetSubresourceCount(resource);
    subresource_offsets.clear();
    subresource_sizes.clear();
    layouts.clear();
    total_size = 0;

    auto resource_desc = resource->GetDesc();

    if (resource_desc.Dimension == D3D12_RESOURCE_DIMENSION_BUFFER)
    {
        layouts.resize(subresource_count);
        subresource_sizes.push_back(resource_desc.Width);
        subresource_offsets.push_back(0);

        device->GetCopyableFootprints(&resource_desc, 0, 1, 0, layouts.data(), nullptr, nullptr, &total_size);

        // Total resource size should be equal to buffer width and should have 0 offset.
        GFXRECON_ASSERT((total_size == resource_desc.Width) && (layouts[0].Offset == 0));
    }
    else
    {
        layouts.resize(subresource_count);
        std::vector<UINT>   subresource_row_counts(subresource_count);
        std::vector<UINT64> subresource_row_size_bytes(subresource_count);

        graphics::dx12::RobustGetCopyableFootprint(device,
                                                   resource,
                                                   &resource_desc,
                                                   0,
                                                   subresource_count,
                                                   0,
                                                   layouts.data(),
                                                   subresource_row_counts.data(),
                                                   subresource_row_size_bytes.data(),
                                                   &total_size);

        subresource_sizes.resize(subresource_count);
        subresource_offsets.resize(subresource_count);
        for (size_t i = 0; i < subresource_count; ++i)
        {
            size_t slice_count = 1;
            if (resource_desc.Dimension == D3D12_RESOURCE_DIMENSION_TEXTURE3D)
            {
                slice_count = layouts[i].Footprint.Depth;
            }
            else
            {
                GFXRECON_ASSERT(layouts[i].Footprint.Depth == 1);
            }

            // Compute the size required to copy the subresource. The final row of the subresource does not require
            // padding, so the total size is (row_count - 1) * row_pitch + row_size_bytes.
            size_t row_count     = subresource_row_counts[i] * slice_count;
            subresource_sizes[i] = (row_count - 1) * layouts[i].Footprint.RowPitch + subresource_row_size_bytes[i];

            subresource_offsets[i] = layouts[i].Offset;
        }

        GFXRECON_ASSERT((subresource_offsets.back() + subresource_sizes.back()) == total_size);
    }
}

Dx12ResourceDataUtil::Dx12ResourceDataUtil(ID3D12Device* device, uint64_t min_buffer_size) :
    device_(device), staging_buffers_{ nullptr, nullptr }, staging_buffer_sizes_{ 0, 0 },
    min_buffer_size_(min_buffer_size), fence_value_(0)
{
    HRESULT result = E_FAIL;

    // Create a command list (and its dependencies) that will be used to run the copy commands.
    D3D12_COMMAND_LIST_TYPE  list_type  = D3D12_COMMAND_LIST_TYPE_DIRECT;
    D3D12_COMMAND_QUEUE_DESC queue_desc = {};
    queue_desc.Flags                    = D3D12_COMMAND_QUEUE_FLAG_NONE;
    queue_desc.Type                     = list_type;
    result                              = device_->CreateCommandQueue(&queue_desc, IID_PPV_ARGS(&command_queue_));
    if (SUCCEEDED(result))
    {
        result = device_->CreateCommandAllocator(list_type, IID_PPV_ARGS(&command_allocator_));
        if (SUCCEEDED(result))
        {
            result =
                device_->CreateCommandList(0, list_type, command_allocator_, nullptr, IID_PPV_ARGS(&command_list_));
            if (SUCCEEDED(result))
            {
                result = command_list_->Close();
                if (SUCCEEDED(result))
                {
                    result = device_->CreateFence(fence_value_, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&command_fence_));
                }
            }
        }
    }

    if (FAILED(result))
    {
        GFXRECON_LOG_ERROR(
            "Failed to initialize DX12 command list and command queue for Dx12ResourceDataUtil. (error = %lx)", result);
    }
}

dx12::ID3D12ResourceComPtr Dx12ResourceDataUtil::GetStagingBuffer(CopyType type, uint64_t required_buffer_size)
{
    if (required_buffer_size == 0)
    {
        return E_INVALIDARG;
    }

    // If the buffer was already initialized with a size >= required_buffer_size, use the existing buffer.
    if ((staging_buffers_[type] != nullptr) && (required_buffer_size <= staging_buffer_sizes_[type]))
    {
        return staging_buffers_[type];
    }

    uint64_t buffer_size = std::max(required_buffer_size, min_buffer_size_);

    // Release existing buffer.
    staging_buffers_[type]      = nullptr;
    staging_buffer_sizes_[type] = 0;

    // Create the staging resource.
    D3D12_HEAP_PROPERTIES heap_properties = {};
    if (type == kCopyTypeRead)
    {
        heap_properties.Type = D3D12_HEAP_TYPE_READBACK;
    }
    else
    {
        heap_properties.Type = D3D12_HEAP_TYPE_UPLOAD;
    }

    D3D12_RESOURCE_DESC staging_resource_desc = {};
    staging_resource_desc.Dimension           = D3D12_RESOURCE_DIMENSION_BUFFER;
    staging_resource_desc.Alignment           = 0;
    staging_resource_desc.Width               = buffer_size;
    staging_resource_desc.Height              = 1;
    staging_resource_desc.DepthOrArraySize    = 1;
    staging_resource_desc.MipLevels           = 1;
    staging_resource_desc.Format              = DXGI_FORMAT_UNKNOWN;
    staging_resource_desc.SampleDesc.Count    = 1;
    staging_resource_desc.Layout              = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;
    staging_resource_desc.Flags               = D3D12_RESOURCE_FLAG_NONE;

    D3D12_RESOURCE_STATES staging_resource_state;
    if (type == kCopyTypeRead)
    {
        staging_resource_state = D3D12_RESOURCE_STATE_COPY_DEST;
    }
    else
    {
        staging_resource_state = D3D12_RESOURCE_STATE_GENERIC_READ;
    }
    HRESULT result = device_->CreateCommittedResource(&heap_properties,
                                                      D3D12_HEAP_FLAG_NONE,
                                                      &staging_resource_desc,
                                                      staging_resource_state,
                                                      nullptr,
                                                      IID_PPV_ARGS(&staging_buffers_[type]));

    if (FAILED(result))
    {
        GFXRECON_LOG_FATAL("Failed to create a staging buffer of size %" PRIu64 " for copying resource data.",
                           buffer_size);

        staging_buffers_[type]      = nullptr;
        staging_buffer_sizes_[type] = 0;
    }
    else
    {
        staging_buffer_sizes_[type] = buffer_size;
    }

    return staging_buffers_[type];
}

dx12::ID3D12ResourceComPtr
Dx12ResourceDataUtil::CreateStagingBuffer(ID3D12Device* device, CopyType type, uint64_t required_buffer_size)
{
    if (required_buffer_size == 0)
    {
        return nullptr;
    }

    // Create the staging resource.
    D3D12_HEAP_TYPE       staging_resource_type  = D3D12_HEAP_TYPE_READBACK;
    D3D12_RESOURCE_STATES staging_resource_state = D3D12_RESOURCE_STATE_COPY_DEST;
    if (type == kCopyTypeWrite)
    {
        staging_resource_type  = D3D12_HEAP_TYPE_UPLOAD;
        staging_resource_state = D3D12_RESOURCE_STATE_GENERIC_READ;
    }
    return graphics::dx12::CreateBufferResource(
        device, required_buffer_size, staging_resource_type, staging_resource_state, D3D12_RESOURCE_FLAG_NONE);
}

dx12::ID3D12ResourceComPtr Dx12ResourceDataUtil::CreateStagingBuffer(CopyType type, uint64_t required_buffer_size)
{
    return CreateStagingBuffer(device_, type, required_buffer_size);
}

HRESULT Dx12ResourceDataUtil::ReadFromResource(ID3D12Resource*                             target_resource,
                                               bool                                        try_map_and_copy,
                                               const std::vector<dx12::ResourceStateInfo>& before_states,
                                               const std::vector<dx12::ResourceStateInfo>& after_states,
                                               std::vector<uint8_t>&                       data,
                                               std::vector<uint64_t>&                      subresource_offsets,
                                               std::vector<uint64_t>&                      subresource_sizes,
                                               ID3D12Resource*                             staging_buffer_for_batching,
                                               ID3D12CommandQueue*                         queue)
{
    HRESULT result = E_FAIL;

    // Get the layout information for copying resource data.
    size_t   subresource_count;
    uint64_t required_data_size;
    temp_subresource_layouts_.clear();
    GetResourceCopyInfo(target_resource,
                        subresource_count,
                        subresource_offsets,
                        subresource_sizes,
                        temp_subresource_layouts_,
                        required_data_size,
                        device_);

    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, required_data_size);

    data.clear();

    // If the resource can be mapped, map it, copy the data, and return success.
    if (try_map_and_copy && IsResourceCpuAccessible(target_resource, kCopyTypeRead))
    {
        data.resize(static_cast<size_t>(required_data_size));
        if (CopyMappableResource(
                target_resource, kCopyTypeRead, &data, nullptr, subresource_offsets, subresource_sizes))
        {
            return S_OK;
        }
    }

    // Get or create the staging buffer for copying the resource on device.
    bool            batching;
    ID3D12Resource* staging_resource;
    if (staging_buffer_for_batching != nullptr)
    {
        batching         = true;
        staging_resource = staging_buffer_for_batching;
    }
    else
    {
        batching         = false;
        staging_resource = GetStagingBuffer(kCopyTypeRead, required_data_size);
    }

    // Build and execute commands to copy data to the resource.
    result = ExecuteCopyCommandList(target_resource,
                                    kCopyTypeRead,
                                    required_data_size,
                                    temp_subresource_layouts_,
                                    before_states,
                                    after_states,
                                    staging_resource,
                                    batching,
                                    queue);

    // After the command list has completed, map the copy resource and read its data.
    if (!batching && SUCCEEDED(result))
    {
        data.resize(static_cast<size_t>(required_data_size));
        result = MapSubresourceAndReadData(staging_resource, 0, static_cast<size_t>(required_data_size), data.data());
    }

    return result;
}

HRESULT Dx12ResourceDataUtil::WriteToResource(ID3D12Resource*                             target_resource,
                                              bool                                        try_map_and_copy,
                                              const std::vector<dx12::ResourceStateInfo>& before_states,
                                              const std::vector<dx12::ResourceStateInfo>& after_states,
                                              const std::vector<uint8_t>&                 data,
                                              const std::vector<uint64_t>&                subresource_offsets,
                                              const std::vector<uint64_t>&                subresource_sizes,
                                              ID3D12Resource*                             staging_buffer_for_batching)
{
    HRESULT result = E_FAIL;

    size_t   subresource_count;
    uint64_t required_data_size;

    // Get the layout information for copying resource data.
    std::vector<uint64_t> layout_offsets;
    std::vector<uint64_t> layout_sizes;
    temp_subresource_layouts_.clear();
    GetResourceCopyInfo(target_resource,
                        subresource_count,
                        layout_offsets,
                        layout_sizes,
                        temp_subresource_layouts_,
                        required_data_size,
                        device_);

    // If the resource can be mapped, map it, copy the data, and return success.
    if (try_map_and_copy && IsResourceCpuAccessible(target_resource, kCopyTypeWrite))
    {
        if (CopyMappableResource(
                target_resource, kCopyTypeWrite, nullptr, &data, subresource_offsets, subresource_sizes))
        {
            return S_OK;
        }
    }

    // Get or create the staging buffer for copying the resource on device.
    bool            batching;
    ID3D12Resource* staging_resource;
    if (staging_buffer_for_batching != nullptr)
    {
        batching         = true;
        staging_resource = staging_buffer_for_batching;
    }
    else
    {
        batching         = false;
        staging_resource = GetStagingBuffer(kCopyTypeWrite, required_data_size);
    }

    // When writing and before running the command list, map the copy resource and write its data.
    uint8_t* subresource_data;
    result = dx12::MapSubresource(staging_resource, 0, &dx12::kZeroRange, subresource_data);
    if (SUCCEEDED(result))
    {
        for (UINT i = 0; i < subresource_count; ++i)
        {
            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, subresource_sizes[i]);
            size_t subresource_size = static_cast<size_t>(std::min(subresource_sizes[i], layout_sizes[i]));

            if (layout_sizes[i] > subresource_sizes[i])
            {
                GFXRECON_LOG_DEBUG("The size of the data to be copied to the subresource does not match the size "
                                   "required by the subresource's copyable footprint (data size = %" PRIu64
                                   ", footprint size = %" PRIu64 ", subresouce index = %" PRIu32 ").",
                                   subresource_sizes[i],
                                   layout_sizes[i],
                                   i);
            }
            else if (layout_sizes[i] < subresource_sizes[i])
            {
                GFXRECON_LOG_ERROR("The size of the data to be copied to the subresource is greater than the size of the subresource's copyable footprint."
                                     "Not all data can be written to the subresource. (data size = %" PRIu64
                                     ", footprint size = %" PRIu64 ", subresouce index = %" PRIu32 ").",
                                     subresource_sizes[i],
                                     layout_sizes[i],
                                     i);

            }
            size_t layout_offset = static_cast<size_t>(layout_offsets[i]);
            size_t layout_size   = static_cast<size_t>(layout_sizes[i]);
            util::platform::MemoryCopy(
                subresource_data + layout_offset, layout_size, data.data() + subresource_offsets[i], subresource_size);
        }
        staging_resource->Unmap(0, nullptr);
    }
    else
    {
        GFXRECON_LOG_ERROR("Failed to map staging buffer for writing data to resource.");
    }

    // Build and execute commands to copy data to the resource.
    result = ExecuteCopyCommandList(target_resource,
                                    kCopyTypeWrite,
                                    required_data_size,
                                    temp_subresource_layouts_,
                                    before_states,
                                    after_states,
                                    staging_resource,
                                    batching);

    return result;
}

bool Dx12ResourceDataUtil::IsResourceCpuAccessible(ID3D12Resource* resource, CopyType copy_type)
{
    bool                  cpu_accessible = false;
    D3D12_HEAP_PROPERTIES heap_properties;
    D3D12_HEAP_FLAGS      heap_flags;
    HRESULT               hr = resource->GetHeapProperties(&heap_properties, &heap_flags);
    if (SUCCEEDED(hr))
    {
        cpu_accessible = ((heap_properties.Type == D3D12_HEAP_TYPE_UPLOAD) && (copy_type == kCopyTypeWrite)) ||
                         ((heap_properties.Type == D3D12_HEAP_TYPE_READBACK) && (copy_type == kCopyTypeRead)) ||
                         ((heap_properties.Type == D3D12_HEAP_TYPE_CUSTOM) &&
                          (heap_properties.CPUPageProperty != D3D12_CPU_PAGE_PROPERTY_UNKNOWN) &&
                          (heap_properties.CPUPageProperty != D3D12_CPU_PAGE_PROPERTY_NOT_AVAILABLE));
    }
    else
    {
        GFXRECON_LOG_DEBUG("Call to GetHeapProperties failed. Unable to determine if resource is CPU accessible.");
    }
    return cpu_accessible;
}

bool Dx12ResourceDataUtil::CopyMappableResource(ID3D12Resource*              target_resource,
                                                CopyType                     copy_type,
                                                std::vector<uint8_t>*        read_data,
                                                const std::vector<uint8_t>*  write_data,
                                                const std::vector<uint64_t>& subresource_offsets,
                                                const std::vector<uint64_t>& subresource_sizes)
{
    uint64_t subresource_count = subresource_offsets.size();

    GFXRECON_ASSERT((copy_type != kCopyTypeRead) || (read_data != nullptr));
    GFXRECON_ASSERT((copy_type != kCopyTypeWrite) || (write_data != nullptr));

    HRESULT result = S_OK;
    for (UINT i = 0; i < subresource_count && SUCCEEDED(result); ++i)
    {
        GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, subresource_sizes[i]);
        size_t subresource_size = static_cast<size_t>(subresource_sizes[i]);

        if (copy_type == kCopyTypeRead)
        {
            result = MapSubresourceAndReadData(
                target_resource, i, subresource_size, read_data->data() + subresource_offsets[i]);
        }
        else
        {
            result = MapSubresourceAndWriteData(
                target_resource, i, subresource_size, write_data->data() + subresource_offsets[i]);
        }
    }

    return SUCCEEDED(result);
}

HRESULT Dx12ResourceDataUtil::ExecuteAndWaitForCommandList(ID3D12CommandQueue* queue)
{
    // Execute the command list and wait for completion.
    ID3D12CommandList* cmd_lists[] = { command_list_ };

    ID3D12CommandQueue* command_queue = queue;
    if (command_queue == nullptr)
    {
        command_queue = command_queue_;
    }
    command_queue->ExecuteCommandLists(1, cmd_lists);
    return dx12::WaitForQueue(command_queue, command_fence_, ++fence_value_);

    // MakeResident and Evict are ref-counted. Remove the ref count added by MakeResident.
    for (auto resource : resident_resources)
    {
        if (!SUCCEEDED(device_->Evict(1, &resource)))
        {
            GFXRECON_LOG_WARNING("Failed to evict resource after copying resource data.");
        }
    }
}

HRESULT Dx12ResourceDataUtil::CloseCommandList()
{
    return command_list_->Close();
}

HRESULT
Dx12ResourceDataUtil::ResetCommandList()
{
    HRESULT result = command_allocator_->Reset();
    if (SUCCEEDED(result))
    {
        result = command_list_->Reset(command_allocator_, nullptr);
        if (FAILED(result))
        {
            GFXRECON_LOG_ERROR("Could not reset command list to copy resource data. (error = %lx)", result);
        }
    }
    else
    {
        GFXRECON_LOG_ERROR("Could not reset command allocator to copy resource data.. (error = %lx)", result);
    }
    return result;
}

HRESULT
Dx12ResourceDataUtil::RecordCommandsToCopyResource(
    ID3D12GraphicsCommandList*                             target_command_list,
    ID3D12Resource*                                        target_resource,
    CopyType                                               copy_type,
    uint64_t                                               copy_size,
    const std::vector<D3D12_PLACED_SUBRESOURCE_FOOTPRINT>& subresource_layouts,
    const std::vector<dx12::ResourceStateInfo>&            before_states,
    const std::vector<dx12::ResourceStateInfo>&            after_states,
    ID3D12Resource*                                        staging_buffer)
{
    const dx12::ResourceStateInfo common_state = { D3D12_RESOURCE_STATE_COMMON, D3D12_RESOURCE_BARRIER_FLAG_NONE };
    const dx12::ResourceStateInfo copy_state   = { copy_type == kCopyTypeRead ? D3D12_RESOURCE_STATE_COPY_SOURCE
                                                                              : D3D12_RESOURCE_STATE_COPY_DEST,
                                                 D3D12_RESOURCE_BARRIER_FLAG_NONE };

    uint64_t subresource_count = subresource_layouts.size();

    // The number of incoming subresource states should match the number of subresource layouts.
    if ((subresource_count != before_states.size()) || (subresource_count != after_states.size()))
    {
        GFXRECON_LOG_ERROR("Unexpected number of subresource states for copying resource data.");
        return E_INVALIDARG;
    }

    // Transition the resource, copy the data, and transition it back.
    auto resource_desc = target_resource->GetDesc();

    if (resource_desc.SampleDesc.Count > 1)
    {
        GFXRECON_LOG_ERROR("Dx12ResourceDataUtil: Multi-sampled resources are not supported.");
        return E_INVALIDARG;
    }

    // Transition subresources to copy state.
    for (UINT i = 0; i < subresource_count; ++i)
    {
        if ((before_states[i].states & D3D12_RESOURCE_STATE_RAYTRACING_ACCELERATION_STRUCTURE) ==
            D3D12_RESOURCE_STATE_RAYTRACING_ACCELERATION_STRUCTURE)
        {
            GFXRECON_LOG_ERROR("Copying ray tracing acceleration structure resources is not supported. Ray tracing "
                               "acceleration structure resources cannot be transitioned out of resource state "
                               "D3D12_RESOURCE_STATE_RAYTRACING_ACCELERATION_STRUCTURE.");
            return E_INVALIDARG;
        }

        // Prepare resource state. Resources in common state will be implicitly promoted to the appropriate copy state.
        AddTransitionBarrier(target_command_list, target_resource, i, before_states[i], common_state);
    }

    // Copy subresources' data.
    for (UINT i = 0; i < subresource_count; ++i)
    {
        // Copy data.
        if (resource_desc.Dimension == D3D12_RESOURCE_DIMENSION_BUFFER)
        {
            // There is only 1 subresource for buffers.
            GFXRECON_ASSERT(i == 0);

            if (copy_type == kCopyTypeRead)
            {
                // Copy from buffer.
                target_command_list->CopyBufferRegion(staging_buffer, 0, target_resource, 0, copy_size);
            }
            else
            {
                // Copy to buffer.
                target_command_list->CopyBufferRegion(target_resource, 0, staging_buffer, 0, copy_size);
            }
        }
        else
        {
            D3D12_TEXTURE_COPY_LOCATION texture_location = {};
            texture_location.pResource                   = target_resource;
            texture_location.Type                        = D3D12_TEXTURE_COPY_TYPE_SUBRESOURCE_INDEX;
            texture_location.SubresourceIndex            = i;

            D3D12_TEXTURE_COPY_LOCATION copy_location = {};
            copy_location.pResource                   = staging_buffer;
            copy_location.Type                        = D3D12_TEXTURE_COPY_TYPE_PLACED_FOOTPRINT;
            copy_location.PlacedFootprint             = subresource_layouts[i];

            if (copy_type == kCopyTypeRead)
            {
                // Copy from texture.
                target_command_list->CopyTextureRegion(&copy_location, 0, 0, 0, &texture_location, nullptr);
            }
            else
            {
                // Copy to texture.
                target_command_list->CopyTextureRegion(&texture_location, 0, 0, 0, &copy_location, nullptr);
            }
        }
    }

    // Transition subresources to final state.
    for (UINT i = 0; i < subresource_count; ++i)
    {
        // If the final desired state is STATE_COMMON and the resource will decay to STATE_COMMON, skip the final
        // transition barrier.
        bool decays_to_common = (copy_state.states == D3D12_RESOURCE_STATE_COPY_SOURCE) ||
                                (resource_desc.Dimension == D3D12_RESOURCE_DIMENSION_BUFFER) ||
                                ((resource_desc.Flags & D3D12_RESOURCE_FLAG_ALLOW_SIMULTANEOUS_ACCESS) != 0);
        if (!decays_to_common || (after_states[i].states != D3D12_RESOURCE_STATE_COMMON))
        {
            AddTransitionBarrier(target_command_list, target_resource, i, copy_state, after_states[i]);
        }
    }

    return S_OK;
}

HRESULT
Dx12ResourceDataUtil::ExecuteCopyCommandList(ID3D12Resource*                                        target_resource,
                                             CopyType                                               copy_type,
                                             uint64_t                                               copy_size,
                                             const std::vector<D3D12_PLACED_SUBRESOURCE_FOOTPRINT>& subresource_layouts,
                                             const std::vector<dx12::ResourceStateInfo>&            before_states,
                                             const std::vector<dx12::ResourceStateInfo>&            after_states,
                                             ID3D12Resource*                                        staging_buffer,
                                             bool                                                   batching,
                                             ID3D12CommandQueue*                                    queue)
{
    // Make sure the target resource is resident.
    ID3D12Pageable* const pageable = target_resource;
    if (!SUCCEEDED(device_->MakeResident(1, &pageable)))
    {
        GFXRECON_LOG_ERROR("Failed to make resource resident for copying resource data.");
        return E_FAIL;
    }

    GFXRECON_ASSERT(staging_buffer != nullptr);

    resident_resources.push_back(pageable);
    // Transition the resource, copy the data, and transition it back.
    auto resource_desc = target_resource->GetDesc();

    HRESULT result = S_OK;
    if (batching == false)
    {
        result = command_allocator_->Reset();
    }
    if (SUCCEEDED(result))
    {
        if (batching == false)
        {
            result = command_list_->Reset(command_allocator_, nullptr);
        }
        if (SUCCEEDED(result))
        {
            result = RecordCommandsToCopyResource(command_list_,
                                                  target_resource,
                                                  copy_type,
                                                  copy_size,
                                                  subresource_layouts,
                                                  before_states,
                                                  after_states,
                                                  staging_buffer);

            // Close and execute the command list.
            if (SUCCEEDED(result) && (batching == false))
            {
                result = command_list_->Close();
                if (SUCCEEDED(result))
                {
                    result = ExecuteAndWaitForCommandList(queue);
                }
            }
        }
    }

    if (FAILED(result))
    {
        GFXRECON_LOG_ERROR("Error executing command list to copy resource data. (error = %lx)", result);
    }

    return result;
}

HRESULT
Dx12ResourceDataUtil::ExecuteTransitionCommandList(ID3D12Resource*                             target_resource,
                                                   const std::vector<dx12::ResourceStateInfo>& before_states,
                                                   const std::vector<dx12::ResourceStateInfo>& after_states)
{
    GFXRECON_ASSERT(before_states.size() == after_states.size());
    uint64_t subresource_count = before_states.size();

    // Transition the subresources.
    bool    cmd_list_empty = true;
    auto    resource_desc  = target_resource->GetDesc();
    HRESULT result         = command_allocator_->Reset();
    if (SUCCEEDED(result))
    {
        result = command_list_->Reset(command_allocator_, nullptr);
        if (SUCCEEDED(result))
        {
            for (UINT i = 0; i < subresource_count; ++i)
            {
                if (AddTransitionBarrier(command_list_, target_resource, i, before_states[i], after_states[i]))
                {
                    cmd_list_empty = false;
                }
            }

            // Close and execute the command list.
            result = command_list_->Close();
            if (SUCCEEDED(result) && !cmd_list_empty)
            {
                result = ExecuteAndWaitForCommandList();
            }
        }
    }

    if (FAILED(result))
    {
        GFXRECON_LOG_ERROR("Error executing command list to transition resource state. (error = %lx)", result);
    }

    return result;
}

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)
