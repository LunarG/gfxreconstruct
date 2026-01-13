/*
** Copyright (c) 2022 LunarG, Inc.
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

#include "decode/dx12_acceleration_structure_builder.h"

#include "graphics/dx12_gpu_va_map.h"
#include "graphics/dx12_util.h"
#include "util/logging.h"

#include <inttypes.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void UpdateBufferSize(ID3D12Device*                         device,
                      graphics::dx12::ID3D12ResourceComPtr& buffer,
                      uint64_t&                             buffer_size,
                      uint64_t                              required_size,
                      D3D12_HEAP_TYPE                       heap_type,
                      D3D12_RESOURCE_STATES                 initial_state,
                      D3D12_RESOURCE_FLAGS                  flags)
{
    // Create an upload resource of the required size.
    if (!buffer || (buffer_size < required_size))
    {
        buffer = graphics::dx12::CreateBufferResource(device, required_size, heap_type, initial_state, flags);
        if (!buffer)
        {
            buffer_size = 0;
            GFXRECON_LOG_FATAL("Failed to create a buffer of size %" PRIu64 " for building acceleration structures.",
                               required_size);
        }
        else
        {
            buffer_size = required_size;
        }
    }
}

HRESULT MapSubresourceAndWriteData(ID3D12Resource* resource, UINT subresource, size_t size, const uint8_t* data)
{
    uint8_t* subresource_data;
    HRESULT  result =
        graphics::dx12::MapSubresource(resource, subresource, &graphics::dx12::kZeroRange, subresource_data);
    if (SUCCEEDED(result))
    {
        util::platform::MemoryCopy(subresource_data, size, data, size);
        resource->Unmap(subresource, nullptr);
    }
    return result;
}

Dx12AccelerationStructureBuilder::Dx12AccelerationStructureBuilder(graphics::dx12::ID3D12Device5ComPtr device5) :
    device5_(device5), inputs_buffer_(nullptr), inputs_buffer_size_(0), scratch_buffer_(nullptr),
    scratch_buffer_size_(0), temp_dest_buffer_(nullptr), temp_dest_buffer_size_(0), fence_value_(0)
{
    HRESULT result = E_FAIL;

    // Create a command list (and its dependencies) that will be used to run the build commands.
    D3D12_COMMAND_LIST_TYPE  list_type  = D3D12_COMMAND_LIST_TYPE_DIRECT;
    D3D12_COMMAND_QUEUE_DESC queue_desc = {};
    queue_desc.Flags                    = D3D12_COMMAND_QUEUE_FLAG_NONE;
    queue_desc.Type                     = list_type;
    result                              = device5_->CreateCommandQueue(&queue_desc, IID_PPV_ARGS(&command_queue_));
    if (SUCCEEDED(result))
    {
        result = device5_->CreateCommandAllocator(list_type, IID_PPV_ARGS(&command_allocator_));
        if (SUCCEEDED(result))
        {
            graphics::dx12::ID3D12GraphicsCommandListComPtr command_list;
            result =
                device5_->CreateCommandList(0, list_type, command_allocator_, nullptr, IID_PPV_ARGS(&command_list));
            if (SUCCEEDED(result))
            {
                result = command_list->Close();
                if (SUCCEEDED(result))
                {
                    result = command_list->QueryInterface(IID_PPV_ARGS(&command_list4_));
                    if (SUCCEEDED(result))
                    {
                        result = device5_->CreateFence(fence_value_, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&fence_));
                    }
                }
            }
        }
    }

    if (FAILED(result))
    {
        GFXRECON_LOG_ERROR(
            "Failed to initialize required DX12 objects for Dx12AccelerationStructureBuilder. (error = %lx)", result);
    }
}

// TODO: Consider batching multiple accel struct builds where possible.
void Dx12AccelerationStructureBuilder::Build(
    const graphics::Dx12GpuVaMap&                                         gpu_va_map,
    const format::InitDx12AccelerationStructureCommandHeader&             command_header,
    const std::vector<format::InitDx12AccelerationStructureGeometryDesc>& init_geometry_descs,
    const uint8_t*                                                        build_inputs_data)
{
    D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC build_desc;

    bool build = true;
    bool copy  = false;
    if (command_header.copy_source_gpu_va != 0)
    {
        copy = true;

        // If the source GPU VA is not the same as the destination, then this is not an in-place build/copy. Skip the
        // build and instead copy from the previously built acceleration structure.
        if (command_header.copy_source_gpu_va != command_header.dest_acceleration_structure_data)
        {
            build = false;
        }
    }
    bool use_temp_dest_buffer = build && copy;

    if (build)
    {
        SetupBuild(
            gpu_va_map, command_header, init_geometry_descs, build_inputs_data, build_desc, use_temp_dest_buffer);
        ExecuteBuild(gpu_va_map, build_desc);
    }

    if (copy)
    {
        D3D12_GPU_VIRTUAL_ADDRESS dest = gpu_va_map.Map(command_header.dest_acceleration_structure_data);
        D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE mode =
            static_cast<D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE>(command_header.copy_mode);

        D3D12_GPU_VIRTUAL_ADDRESS source = 0;
        if (use_temp_dest_buffer)
        {
            source = temp_dest_buffer_->GetGPUVirtualAddress();
        }
        else
        {
            source = gpu_va_map.Map(command_header.copy_source_gpu_va);
        }

        ExecuteCopy(dest, source, mode);
    }
}

void Dx12AccelerationStructureBuilder::SetupBuild(
    const graphics::Dx12GpuVaMap&                                         gpu_va_map,
    const format::InitDx12AccelerationStructureCommandHeader&             command_header,
    const std::vector<format::InitDx12AccelerationStructureGeometryDesc>& init_geometry_descs,
    const uint8_t*                                                        build_inputs_data,
    D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC&                   build_desc,
    bool                                                                  use_temp_dest_buffer)
{
    // Build D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC from decoded data.
    build_desc.DestAccelerationStructureData    = gpu_va_map.Map(command_header.dest_acceleration_structure_data);
    auto& inputs_desc                           = build_desc.Inputs;
    build_desc.SourceAccelerationStructureData  = 0;
    build_desc.ScratchAccelerationStructureData = 0;

    inputs_desc.Type  = static_cast<D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE>(command_header.inputs_type);
    inputs_desc.Flags = static_cast<D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS>(command_header.inputs_flags);
    inputs_desc.DescsLayout     = D3D12_ELEMENTS_LAYOUT_ARRAY;
    inputs_desc.InstanceDescs   = 0;
    inputs_desc.pGeometryDescs  = nullptr;
    inputs_desc.ppGeometryDescs = nullptr;

    const uint8_t* final_data = build_inputs_data;

    // In order for GetAccelerationStructureInputsBufferEntries to correctly process inputs buffer entries, a
    // non-zero GPU VA must be set for values that will be used.
    const D3D12_GPU_VIRTUAL_ADDRESS kDefaultGpuVa = 1;

    // Reconstruct acceleration structure build descs.
    temp_geometry_descs_.clear();
    if (inputs_desc.Type == D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE_BOTTOM_LEVEL)
    {
        temp_geometry_descs_.resize(command_header.inputs_num_geometry_descs);

        inputs_desc.NumDescs = command_header.inputs_num_geometry_descs;
        GFXRECON_ASSERT(command_header.inputs_num_geometry_descs == init_geometry_descs.size());
        for (UINT i = 0; i < init_geometry_descs.size(); ++i)
        {
            const auto&                     init_geom_desc = init_geometry_descs[i];
            D3D12_RAYTRACING_GEOMETRY_DESC& geom_desc      = temp_geometry_descs_[i];

            geom_desc.Type  = static_cast<D3D12_RAYTRACING_GEOMETRY_TYPE>(init_geom_desc.geometry_type);
            geom_desc.Flags = static_cast<D3D12_RAYTRACING_GEOMETRY_FLAGS>(init_geom_desc.geometry_flags);
            if (geom_desc.Type == D3D12_RAYTRACING_GEOMETRY_TYPE_TRIANGLES)
            {
                auto& tris_desc                      = geom_desc.Triangles;
                tris_desc.Transform3x4               = init_geom_desc.triangles_has_transform ? kDefaultGpuVa : 0;
                tris_desc.IndexFormat                = static_cast<DXGI_FORMAT>(init_geom_desc.triangles_index_format);
                tris_desc.VertexFormat               = static_cast<DXGI_FORMAT>(init_geom_desc.triangles_vertex_format);
                tris_desc.IndexCount                 = init_geom_desc.triangles_index_count;
                tris_desc.VertexCount                = init_geom_desc.triangles_vertex_count;
                tris_desc.IndexBuffer                = init_geom_desc.triangles_index_count > 0 ? kDefaultGpuVa : 0;
                tris_desc.VertexBuffer.StartAddress  = kDefaultGpuVa;
                tris_desc.VertexBuffer.StrideInBytes = init_geom_desc.triangles_vertex_stride;
            }
            else if (geom_desc.Type == D3D12_RAYTRACING_GEOMETRY_TYPE_PROCEDURAL_PRIMITIVE_AABBS)
            {
                geom_desc.AABBs.AABBCount           = init_geom_desc.aabbs_count;
                geom_desc.AABBs.AABBs.StartAddress  = kDefaultGpuVa;
                geom_desc.AABBs.AABBs.StrideInBytes = init_geom_desc.aabbs_stride;
            }
            else
            {
                GFXRECON_ASSERT(false && "Invalid D3D12_RAYTRACING_GEOMETRY_TYPE.");
            }
        }
        inputs_desc.pGeometryDescs = temp_geometry_descs_.data();
    }
    else if (inputs_desc.Type == D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL)
    {
        inputs_desc.NumDescs      = command_header.inputs_num_instance_descs;
        inputs_desc.InstanceDescs = (inputs_desc.NumDescs > 0) ? kDefaultGpuVa : 0;

        // Map GPU VAs in instance desc input data.
        temp_instance_desc_input_data_.clear();
        temp_instance_desc_input_data_.insert(temp_instance_desc_input_data_.end(),
                                              build_inputs_data,
                                              build_inputs_data + command_header.inputs_data_size);
        constexpr auto address_stride = sizeof(D3D12_RAYTRACING_INSTANCE_DESC);
        constexpr auto address_offset = offsetof(D3D12_RAYTRACING_INSTANCE_DESC, AccelerationStructure);
        for (UINT i = 0; i < inputs_desc.NumDescs; ++i)
        {
            D3D12_GPU_VIRTUAL_ADDRESS* address = reinterpret_cast<D3D12_GPU_VIRTUAL_ADDRESS*>(
                temp_instance_desc_input_data_.data() + i * address_stride + address_offset);
            *address = gpu_va_map.Map(*address);
        }
        final_data = temp_instance_desc_input_data_.data();
    }
    else
    {
        GFXRECON_ASSERT(false && "Invalid D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE.");
    }

    // Compute the required inputs buffer size and entry information.
    uint64_t                                       inputs_buffer_size = 0;
    std::vector<graphics::dx12::InputsBufferEntry> inputs_buffer_entries;
    graphics::dx12::GetAccelerationStructureInputsBufferEntries(
        inputs_desc, temp_geometry_descs_.data(), inputs_buffer_size, inputs_buffer_entries);

    GFXRECON_ASSERT(inputs_buffer_size == command_header.inputs_data_size);

    // Get required sizes and update buffers.
    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO prebuild_info;
    device5_->GetRaytracingAccelerationStructurePrebuildInfo(&inputs_desc, &prebuild_info);
    UpdateBufferSize(device5_,
                     scratch_buffer_,
                     scratch_buffer_size_,
                     prebuild_info.ScratchDataSizeInBytes,
                     D3D12_HEAP_TYPE_DEFAULT,
                     D3D12_RESOURCE_STATE_COMMON,
                     D3D12_RESOURCE_FLAG_ALLOW_UNORDERED_ACCESS);
    UpdateBufferSize(device5_,
                     inputs_buffer_,
                     inputs_buffer_size_,
                     command_header.inputs_data_size,
                     D3D12_HEAP_TYPE_UPLOAD,
                     D3D12_RESOURCE_STATE_GENERIC_READ,
                     D3D12_RESOURCE_FLAG_NONE);

    if (use_temp_dest_buffer)
    {
        UpdateBufferSize(device5_,
                         temp_dest_buffer_,
                         temp_dest_buffer_size_,
                         prebuild_info.ResultDataMaxSizeInBytes,
                         D3D12_HEAP_TYPE_DEFAULT,
                         D3D12_RESOURCE_STATE_RAYTRACING_ACCELERATION_STRUCTURE,
                         D3D12_RESOURCE_FLAG_ALLOW_UNORDERED_ACCESS);
    }

    // Write inputs data to resources.
    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, command_header.inputs_data_size);
    HRESULT hr =
        MapSubresourceAndWriteData(inputs_buffer_, 0, static_cast<size_t>(command_header.inputs_data_size), final_data);
    GFXRECON_ASSERT(SUCCEEDED(hr));

    // Fix GPU VAs that point into buffers.
    if (use_temp_dest_buffer)
    {
        build_desc.DestAccelerationStructureData = temp_dest_buffer_->GetGPUVirtualAddress();
    }
    build_desc.ScratchAccelerationStructureData  = scratch_buffer_->GetGPUVirtualAddress();
    D3D12_GPU_VIRTUAL_ADDRESS inputs_buffer_base = inputs_buffer_->GetGPUVirtualAddress();
    for (auto& inputs_buffer_entry : inputs_buffer_entries)
    {
        *inputs_buffer_entry.desc_gpu_va = inputs_buffer_base + inputs_buffer_entry.offset;
    }
}

void Dx12AccelerationStructureBuilder::ExecuteBuild(const graphics::Dx12GpuVaMap&                       gpu_va_map,
                                                    D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC& build_desc)
{
    // Reset command allocator and command list.
    HRESULT hr = command_allocator_->Reset();
    GFXRECON_ASSERT(SUCCEEDED(hr));
    hr = command_list4_->Reset(command_allocator_, nullptr);
    GFXRECON_ASSERT(SUCCEEDED(hr));

    D3D12_RESOURCE_TRANSITION_BARRIER transition;
    transition.pResource   = scratch_buffer_.GetInterfacePtr();
    transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
    transition.StateBefore = D3D12_RESOURCE_STATE_COMMON;
    transition.StateAfter  = D3D12_RESOURCE_STATE_UNORDERED_ACCESS;

    D3D12_RESOURCE_BARRIER barrier;
    barrier.Type       = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
    barrier.Flags      = D3D12_RESOURCE_BARRIER_FLAG_NONE;
    barrier.Transition = transition;

    command_list4_->ResourceBarrier(1, &barrier);

    // Add the build command.
    command_list4_->BuildRaytracingAccelerationStructure(&build_desc, 0, nullptr);

    hr = command_list4_->Close();

    // Execute the command list and wait for completion.
    ID3D12CommandList* cmd_lists[] = { command_list4_ };
    command_queue_->ExecuteCommandLists(1, cmd_lists);
    hr = graphics::dx12::WaitForQueue(command_queue_, fence_, ++fence_value_);
    GFXRECON_ASSERT(SUCCEEDED(hr));
}

void Dx12AccelerationStructureBuilder::ExecuteCopy(D3D12_GPU_VIRTUAL_ADDRESS                         dest_gpu_va,
                                                   D3D12_GPU_VIRTUAL_ADDRESS                         source_gpu_va,
                                                   D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE mode)
{
    // Reset command allocator and command list.
    HRESULT hr = command_allocator_->Reset();
    GFXRECON_ASSERT(SUCCEEDED(hr));
    hr = command_list4_->Reset(command_allocator_, nullptr);
    GFXRECON_ASSERT(SUCCEEDED(hr));

    // Add copy commands.
    command_list4_->CopyRaytracingAccelerationStructure(dest_gpu_va, source_gpu_va, mode);

    hr = command_list4_->Close();

    // Execute the command list and wait for completion.
    ID3D12CommandList* cmd_lists[] = { command_list4_ };
    command_queue_->ExecuteCommandLists(1, cmd_lists);
    hr = graphics::dx12::WaitForQueue(command_queue_, fence_, ++fence_value_);
    GFXRECON_ASSERT(SUCCEEDED(hr));
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
