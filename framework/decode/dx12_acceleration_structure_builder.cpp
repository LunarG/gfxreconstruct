/*
** Copyright (c) 2022 LunarG, Inc.
** Copyright (c) 2026 Advanced Micro Devices, Inc. All rights reserved.
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

#include "decode/dx12_object_info.h"
#include "graphics/dx12_gpu_va_map.h"
#include "graphics/dx12_util.h"
#include "util/logging.h"

#include <functional>
#include <inttypes.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

// Maximum 1GB allowed for batched group allocations
static const uint64_t kMaxStaticGpuBudget = 0x40000000;

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

Dx12AccelerationStructureBuilder::Dx12AccelerationStructureBuilder(graphics::dx12::ID3D12Device5ComPtr device5,
                                                                   IDXGIAdapter3*                      adapter3,
                                                                   const BatchedASBuildConfig&         config) :
    device5_(device5),
    adapter3_(adapter3), config_(config), fence_value_(0)
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

    max_batched_mem_usage_ = static_cast<double>(config_.memory_usage) / 100.0;

    is_uma_ = graphics::dx12::IsUma(device5);
}

void Dx12AccelerationStructureBuilder::AddNewInstance(
    const format::InitDx12AccelerationStructureCommandHeader& command_header,
    const uint8_t*                                            build_inputs_data,
    const IDASCInstance&                                      new_instance)
{
    batched_instances_.push_back(new_instance);
    IDASCInstance& batched_instance = batched_instances_.back();

    batched_instance.build_inputs_data = new uint8_t[command_header.inputs_data_size]{};
    memcpy(batched_instance.build_inputs_data, build_inputs_data, command_header.inputs_data_size);

    batched_instance.cpu_build_inputs_data = batched_instance.build_inputs_data;
}

void Dx12AccelerationStructureBuilder::Build(
    const graphics::Dx12GpuVaMap&                                         gpu_va_map,
    const format::InitDx12AccelerationStructureCommandHeader&             command_header,
    const std::vector<format::InitDx12AccelerationStructureGeometryDesc>& init_geometry_descs,
    const uint8_t*                                                        build_inputs_data)
{
    IDASCInstance new_instance;
    new_instance.command_header      = command_header;
    new_instance.init_geometry_descs = init_geometry_descs;
    new_instance.build               = true;
    new_instance.copy                = false;

    if (command_header.copy_source_gpu_va != 0)
    {
        new_instance.copy = true;

        // If the source GPU VA is not the same as the destination, then this is not an in-place build/copy. Skip
        // the build and instead copy from the previously built acceleration structure.
        if (command_header.copy_source_gpu_va != command_header.dest_acceleration_structure_data)
        {
            new_instance.build = false;
        }
    }

    new_instance.use_temp_dest_buffer = new_instance.build && new_instance.copy;

    // Batching disabled
    if (config_.mode == BATCHED_AS_BUILD_MODE_DISABLED)
    {
        unbatched_instance_.command_header       = new_instance.command_header;
        unbatched_instance_.init_geometry_descs  = new_instance.init_geometry_descs;
        unbatched_instance_.build                = new_instance.build;
        unbatched_instance_.copy                 = new_instance.copy;
        unbatched_instance_.use_temp_dest_buffer = new_instance.use_temp_dest_buffer;

        unbatched_instance_.build_inputs_data = const_cast<uint8_t*>(build_inputs_data);

        ExecuteNoBatch(gpu_va_map, unbatched_instance_);
    }

    // Batch as blocks are seen
    else if (config_.mode == BATCHED_AS_BUILD_MODE_INCREMENTAL_GROUPING)
    {
        AddNewInstance(command_header, build_inputs_data, new_instance);

        IDASCInstance& batched_instance = batched_instances_.back();

        SetupInstance(gpu_va_map, batched_instance);

        const uint64_t total_requirement = batched_instance.buffer_sizes.total_size * graphics::dx12::kMemoryTolerance;

        incremental_info_.running_requirement += total_requirement;

        const uint64_t budget = GetMemoryBudget();

        if (incremental_info_.running_requirement >= budget)
        {
            ExecuteBatchIncrementalGrouping(gpu_va_map, incremental_info_.idasc_start);

            incremental_info_.idasc_start         = incremental_info_.idasc_idx;
            incremental_info_.running_requirement = total_requirement;
        }

        incremental_info_.idasc_idx++;
    }

    // Batch once we find the final IDASC
    else if (config_.mode == BATCHED_AS_BUILD_MODE_END_GROUPING)
    {
        AddNewInstance(command_header, build_inputs_data, new_instance);
    }
}

void Dx12AccelerationStructureBuilder::End(const graphics::Dx12GpuVaMap& gpu_va_map)
{
    if (fence_ != nullptr)
    {
        if (config_.mode == BATCHED_AS_BUILD_MODE_INCREMENTAL_GROUPING)
        {
            ExecuteRemainingInstances(gpu_va_map);
        }
        else if (config_.mode == BATCHED_AS_BUILD_MODE_END_GROUPING)
        {
            ExecuteBatchEndGrouping(gpu_va_map);
        }
        fence_ = nullptr;
    }
}

void Dx12AccelerationStructureBuilder::ExecuteBatchIncrementalGrouping(const graphics::Dx12GpuVaMap& gpu_va_map,
                                                                       uint32_t                      start)
{
    IDASCGroup group;
    if (batched_instances_.size() > 0)
    {
        for (UINT i = start; i < batched_instances_.size() - 1; i++)
        {
            IDASCInstance& instance = batched_instances_[i];

            instance.build_info.inputs_buffer_entries.clear();
            graphics::dx12::GetAccelerationStructureInputsBufferEntries(instance.build_info.build_desc.Inputs,
                                                                        instance.build_info.temp_geometry_descs.data(),
                                                                        instance.build_info.inputs_buffer_size,
                                                                        instance.build_info.inputs_buffer_entries);

            AddInstanceToGroup(group, instance);
        }

        ExecuteGroup(gpu_va_map, group);
    }
}

void Dx12AccelerationStructureBuilder::ExecuteBatchEndGrouping(const graphics::Dx12GpuVaMap& gpu_va_map)
{
    for (auto& instance : batched_instances_)
    {
        SetupInstance(gpu_va_map, instance);
    }

    std::vector<IDASCGroup> groups;
    GroupInstancesByMemoryBudget(groups);

    for (auto& group : groups)
    {
        ExecuteGroup(gpu_va_map, group);
    }
}

void Dx12AccelerationStructureBuilder::SetupBuild(const graphics::Dx12GpuVaMap& gpu_va_map, IDASCInstance& instance)
{
    // Build D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC from decoded data.
    instance.build_info.build_desc.DestAccelerationStructureData =
        gpu_va_map.Map(instance.command_header.dest_acceleration_structure_data);
    auto& inputs_desc                                               = instance.build_info.build_desc.Inputs;
    instance.build_info.build_desc.SourceAccelerationStructureData  = 0;
    instance.build_info.build_desc.ScratchAccelerationStructureData = 0;

    inputs_desc.Type = static_cast<D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE>(instance.command_header.inputs_type);
    inputs_desc.Flags =
        static_cast<D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS>(instance.command_header.inputs_flags);

    inputs_desc.DescsLayout     = D3D12_ELEMENTS_LAYOUT_ARRAY;
    inputs_desc.InstanceDescs   = 0;
    inputs_desc.pGeometryDescs  = nullptr;
    inputs_desc.ppGeometryDescs = nullptr;

    // In order for GetAccelerationStructureInputsBufferEntries to correctly process inputs buffer entries, a
    // non-zero GPU VA must be set for values that will be used.
    const D3D12_GPU_VIRTUAL_ADDRESS kDefaultGpuVa = 1;

    // Reconstruct acceleration structure build descs.
    if (inputs_desc.Type == D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE_BOTTOM_LEVEL)
    {
        instance.build_info.temp_geometry_descs.resize(instance.command_header.inputs_num_geometry_descs);

        inputs_desc.NumDescs = instance.command_header.inputs_num_geometry_descs;
        GFXRECON_ASSERT(instance.command_header.inputs_num_geometry_descs == instance.init_geometry_descs.size());
        for (UINT i = 0; i < instance.init_geometry_descs.size(); ++i)

        {
            const auto&                     init_geom_desc = instance.init_geometry_descs[i];
            D3D12_RAYTRACING_GEOMETRY_DESC& geom_desc      = instance.build_info.temp_geometry_descs[i];

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
        inputs_desc.pGeometryDescs = instance.build_info.temp_geometry_descs.data();
    }
    else if (inputs_desc.Type == D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL)
    {
        inputs_desc.NumDescs      = instance.command_header.inputs_num_instance_descs;
        inputs_desc.InstanceDescs = (inputs_desc.NumDescs > 0) ? kDefaultGpuVa : 0;

        // Map GPU VAs in instance desc input data.
        instance.build_info.temp_instance_desc_input_data.clear();
        instance.build_info.temp_instance_desc_input_data.insert(
            instance.build_info.temp_instance_desc_input_data.end(),
            instance.build_inputs_data,
            instance.build_inputs_data + instance.command_header.inputs_data_size);

        constexpr auto address_stride = sizeof(D3D12_RAYTRACING_INSTANCE_DESC);
        constexpr auto address_offset = offsetof(D3D12_RAYTRACING_INSTANCE_DESC, AccelerationStructure);
        for (UINT i = 0; i < inputs_desc.NumDescs; ++i)
        {
            D3D12_GPU_VIRTUAL_ADDRESS* address = reinterpret_cast<D3D12_GPU_VIRTUAL_ADDRESS*>(
                instance.build_info.temp_instance_desc_input_data.data() + i * address_stride + address_offset);
            *address = gpu_va_map.Map(*address);
        }
        instance.build_inputs_data = instance.build_info.temp_instance_desc_input_data.data();
    }
    else
    {
        GFXRECON_ASSERT(false && "Invalid D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE.");
    }

    // Compute the required inputs buffer size and entry information.
    uint64_t inputs_buffer_size = 0;
    graphics::dx12::GetAccelerationStructureInputsBufferEntries(inputs_desc,
                                                                instance.build_info.temp_geometry_descs.data(),
                                                                inputs_buffer_size,
                                                                instance.build_info.inputs_buffer_entries);

    GFXRECON_ASSERT(inputs_buffer_size == instance.command_header.inputs_data_size);

    // Get required sizes and update buffers.
    device5_->GetRaytracingAccelerationStructurePrebuildInfo(&inputs_desc, &instance.build_info.prebuild_info);
}

void Dx12AccelerationStructureBuilder::UpdateGpuMemBuild(const graphics::Dx12GpuVaMap& gpu_va_map,
                                                         IDASCInstance&                instance)
{
    if (instance.use_temp_dest_buffer)
    {
        UpdateBufferSize(device5_,
                         instance.temp_dest_buffer,
                         instance.buffer_sizes.temp_dest_buffer_size,
                         instance.build_info.prebuild_info.ResultDataMaxSizeInBytes,
                         D3D12_HEAP_TYPE_DEFAULT,
                         D3D12_RESOURCE_STATE_RAYTRACING_ACCELERATION_STRUCTURE,
                         D3D12_RESOURCE_FLAG_ALLOW_UNORDERED_ACCESS);

        // Fix GPU VAs that point into buffers.
        instance.build_info.build_desc.DestAccelerationStructureData =
            instance.temp_dest_buffer->GetGPUVirtualAddress();
    }

    UpdateBufferSize(device5_,
                     instance.scratch_buffer,
                     instance.build_info.scratch_buffer_size,
                     instance.build_info.prebuild_info.ScratchDataSizeInBytes,
                     D3D12_HEAP_TYPE_DEFAULT,
                     D3D12_RESOURCE_STATE_COMMON,
                     D3D12_RESOURCE_FLAG_ALLOW_UNORDERED_ACCESS);

    UpdateBufferSize(device5_,
                     instance.inputs_buffer,
                     instance.build_info.inputs_buffer_size,
                     instance.command_header.inputs_data_size,
                     D3D12_HEAP_TYPE_UPLOAD,
                     D3D12_RESOURCE_STATE_GENERIC_READ,
                     D3D12_RESOURCE_FLAG_NONE);

    // Write inputs data to resources.
    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, instance.command_header.inputs_data_size);
    HRESULT hr = MapSubresourceAndWriteData(instance.inputs_buffer,
                                            0,
                                            static_cast<size_t>(instance.command_header.inputs_data_size),
                                            instance.build_inputs_data);
    GFXRECON_ASSERT(SUCCEEDED(hr));

    instance.build_info.build_desc.ScratchAccelerationStructureData = instance.scratch_buffer->GetGPUVirtualAddress();

    D3D12_GPU_VIRTUAL_ADDRESS inputs_buffer_base = instance.inputs_buffer->GetGPUVirtualAddress();
    for (auto& inputs_buffer_entry : instance.build_info.inputs_buffer_entries)
    {
        *inputs_buffer_entry.desc_gpu_va = inputs_buffer_base + inputs_buffer_entry.offset;
    }

    instance.build_info.inputs_buffer_entries.clear();
}

void Dx12AccelerationStructureBuilder::SetupCopy(const graphics::Dx12GpuVaMap& gpu_va_map, IDASCInstance& instance)
{
    instance.copy_info.dst = gpu_va_map.Map(instance.command_header.dest_acceleration_structure_data);
    instance.copy_info.mode =
        static_cast<D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE>(instance.command_header.copy_mode);
    instance.copy_info.src = gpu_va_map.Map(instance.command_header.copy_source_gpu_va);
}

void Dx12AccelerationStructureBuilder::UpdateGpuMemCopy(IDASCInstance& instance)
{
    if (instance.use_temp_dest_buffer)
    {
        UpdateBufferSize(device5_,
                         instance.temp_dest_buffer,
                         instance.buffer_sizes.temp_dest_buffer_size,
                         instance.build_info.prebuild_info.ResultDataMaxSizeInBytes,
                         D3D12_HEAP_TYPE_DEFAULT,
                         D3D12_RESOURCE_STATE_RAYTRACING_ACCELERATION_STRUCTURE,
                         D3D12_RESOURCE_FLAG_ALLOW_UNORDERED_ACCESS);

        instance.copy_info.src = instance.temp_dest_buffer->GetGPUVirtualAddress();
    }
}

void Dx12AccelerationStructureBuilder::ExecuteNoBatch(const graphics::Dx12GpuVaMap& gpu_va_map, IDASCInstance& instance)
{
    if (instance.build)
    {
        SetupBuild(gpu_va_map, instance);
        UpdateGpuMemBuild(gpu_va_map, instance);
        ExecuteBuild(instance);
    }

    if (instance.copy)
    {
        SetupCopy(gpu_va_map, instance);
        UpdateGpuMemCopy(instance);
        ExecuteCopy(instance.copy_info);
    }
}

void Dx12AccelerationStructureBuilder::ExecuteRemainingInstances(const graphics::Dx12GpuVaMap& gpu_va_map)
{
    IDASCGroup group;

    for (auto& instance : batched_instances_)
    {
        if (instance.executed == false)
        {
            instance.build_info.inputs_buffer_entries.clear();
            graphics::dx12::GetAccelerationStructureInputsBufferEntries(instance.build_info.build_desc.Inputs,
                                                                        instance.build_info.temp_geometry_descs.data(),
                                                                        instance.build_info.inputs_buffer_size,
                                                                        instance.build_info.inputs_buffer_entries);

            AddInstanceToGroup(group, instance);
        }
    }

    ExecuteGroup(gpu_va_map, group);
}

uint64_t UpdateSizeAligned(uint64_t increment_size, uint64_t& out_size)
{
    D3D12_GPU_VIRTUAL_ADDRESS non_aligned_offset = out_size + increment_size;

    D3D12_GPU_VIRTUAL_ADDRESS aligned_offset =
        util::platform::AlignValue<D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BYTE_ALIGNMENT>(non_aligned_offset);

    uint64_t size_increase = increment_size + (aligned_offset - non_aligned_offset);

    out_size += size_increase;

    return size_increase;
}

uint64_t Dx12AccelerationStructureBuilder::GetMemoryBudget()
{
    uint64_t available_gpu_mem =
        graphics::dx12::GetAvailableGpuAdapterMemory(adapter3_, max_batched_mem_usage_, is_uma_);
    uint64_t available_cpu_mem = graphics::dx12::GetAvailableCpuMemory(max_batched_mem_usage_);

    // 1 GB limit for each group
    uint64_t dynamic_budget = std::min(available_gpu_mem, available_cpu_mem);

    return std::min(kMaxStaticGpuBudget, dynamic_budget);
}

uint64_t Dx12AccelerationStructureBuilder::GetIDASCConsumption(const IDASCInstance& instance,
                                                               uint64_t&            scratch_buffer_size,
                                                               uint64_t&            inputs_buffer_size,
                                                               uint64_t&            temp_dest_buffer_size)
{
    UpdateSizeAligned(instance.build_info.prebuild_info.ScratchDataSizeInBytes, scratch_buffer_size);
    UpdateSizeAligned(instance.command_header.inputs_data_size, inputs_buffer_size);

    if (instance.use_temp_dest_buffer)
    {
        UpdateSizeAligned(instance.build_info.prebuild_info.ResultDataMaxSizeInBytes, temp_dest_buffer_size);
    }

    return scratch_buffer_size + inputs_buffer_size + temp_dest_buffer_size;
}

void Dx12AccelerationStructureBuilder::ResetGroupSizes(IDASCGroup& group)
{
    group.buffer_sizes.scratch_buffer_size   = 0;
    group.buffer_sizes.inputs_buffer_size    = 0;
    group.buffer_sizes.temp_dest_buffer_size = 0;
    group.buffer_sizes.total_size            = 0;
}

void Dx12AccelerationStructureBuilder::UpdateGroupSizes(IDASCGroup& group, const IDASCInstance& instance)
{
    group.buffer_sizes.scratch_buffer_size += instance.buffer_sizes.scratch_buffer_size;
    group.buffer_sizes.inputs_buffer_size += instance.buffer_sizes.inputs_buffer_size;
    group.buffer_sizes.temp_dest_buffer_size += instance.buffer_sizes.temp_dest_buffer_size;
    group.buffer_sizes.total_size += instance.buffer_sizes.total_size;
}

void Dx12AccelerationStructureBuilder::AddInstanceToGroup(IDASCGroup& group, IDASCInstance& instance)
{
    group.instances.push_back(&instance);
    UpdateGroupSizes(group, instance);
}

void Dx12AccelerationStructureBuilder::GroupInstancesByMemoryBudget(std::vector<IDASCGroup>& groups)
{
    const uint64_t budget = GetMemoryBudget();

    IDASCGroup group;

    uint64_t running_requirement = 0;
    for (auto& instance : batched_instances_)
    {
        if (instance.build)
        {
            const uint64_t total_requirement = instance.buffer_sizes.total_size * graphics::dx12::kMemoryTolerance;

            running_requirement += total_requirement;

            if (running_requirement >= budget)
            {
                groups.push_back(group);
                group.instances.clear();
                ResetGroupSizes(group);
                running_requirement = 0;
            }
        }

        AddInstanceToGroup(group, instance);
    }

    if (group.instances.empty() == false)
    {
        groups.push_back(group);
    }
}

void Dx12AccelerationStructureBuilder::ExecuteGroup(const graphics::Dx12GpuVaMap& gpu_va_map, IDASCGroup& group)
{
    if (group.instances.empty() == false)
    {
        // Scratch
        graphics::dx12::ID3D12ResourceComPtr big_scratch_buffer{ nullptr };
        UpdateBufferSize(device5_,
                         big_scratch_buffer,
                         group.buffer_sizes.scratch_buffer_size,
                         group.buffer_sizes.scratch_buffer_size,
                         D3D12_HEAP_TYPE_DEFAULT,
                         D3D12_RESOURCE_STATE_COMMON,
                         D3D12_RESOURCE_FLAG_ALLOW_UNORDERED_ACCESS);

        D3D12_GPU_VIRTUAL_ADDRESS scratch_offset = big_scratch_buffer->GetGPUVirtualAddress();
        for (auto instance : group.instances)
        {
            if (instance->build)
            {
                instance->build_info.build_desc.ScratchAccelerationStructureData = scratch_offset;

                scratch_offset += instance->buffer_sizes.scratch_buffer_size;
            }
        }

        // Inputs
        graphics::dx12::ID3D12ResourceComPtr big_inputs_buffer{ nullptr };
        UpdateBufferSize(device5_,
                         big_inputs_buffer,
                         group.buffer_sizes.inputs_buffer_size,
                         group.buffer_sizes.inputs_buffer_size,
                         D3D12_HEAP_TYPE_UPLOAD,
                         D3D12_RESOURCE_STATE_GENERIC_READ,
                         D3D12_RESOURCE_FLAG_NONE);

        uint8_t* subresource_data = nullptr;
        HRESULT  result =
            graphics::dx12::MapSubresource(big_inputs_buffer, 0, &graphics::dx12::kZeroRange, subresource_data);

        if (SUCCEEDED(result))
        {
            D3D12_GPU_VIRTUAL_ADDRESS inputs_offset = big_inputs_buffer->GetGPUVirtualAddress();

            for (auto instance : group.instances)
            {
                if (instance->build)
                {
                    // Write inputs data to resources.
                    util::platform::MemoryCopy(subresource_data,
                                               instance->command_header.inputs_data_size,
                                               instance->build_inputs_data,
                                               instance->command_header.inputs_data_size);

                    for (auto& inputs_buffer_entry : instance->build_info.inputs_buffer_entries)
                    {
                        *inputs_buffer_entry.desc_gpu_va = inputs_offset + inputs_buffer_entry.offset;
                    }

                    inputs_offset += instance->buffer_sizes.inputs_buffer_size;
                    subresource_data += instance->buffer_sizes.inputs_buffer_size;
                }
            }

            big_inputs_buffer->Unmap(0, nullptr);
        }

        // Temp desc buffer
        graphics::dx12::ID3D12ResourceComPtr big_temp_desc_buffer{ nullptr };
        if (group.buffer_sizes.temp_dest_buffer_size > 0)
        {
            UpdateBufferSize(device5_,
                             big_temp_desc_buffer,
                             group.buffer_sizes.temp_dest_buffer_size,
                             group.buffer_sizes.temp_dest_buffer_size,
                             D3D12_HEAP_TYPE_DEFAULT,
                             D3D12_RESOURCE_STATE_RAYTRACING_ACCELERATION_STRUCTURE,
                             D3D12_RESOURCE_FLAG_ALLOW_UNORDERED_ACCESS);

            D3D12_GPU_VIRTUAL_ADDRESS temp_desc_offset = big_temp_desc_buffer->GetGPUVirtualAddress();

            for (auto instance : group.instances)
            {
                if (instance->use_temp_dest_buffer)
                {
                    // Fix GPU VAs that point into buffers.
                    instance->build_info.build_desc.DestAccelerationStructureData = temp_desc_offset;

                    instance->copy_info.src = temp_desc_offset;

                    temp_desc_offset += instance->buffer_sizes.temp_dest_buffer_size;
                }
            }
        }

        // Execute
        BeginCommandList();

        InjectTransitionBarrierCmd(
            big_scratch_buffer, D3D12_RESOURCE_STATE_COMMON, D3D12_RESOURCE_STATE_UNORDERED_ACCESS);

        for (auto instance : group.instances)
        {
            InjectBlockCmd(gpu_va_map, *instance);
        }

        CloseAndExecute();

        // Cleanup
        for (uint32_t i = 0; i < group.instances.size(); i++)
        {
            IDASCInstance* instance = group.instances[i];

            if (instance->cpu_build_inputs_data)
            {
                delete[] instance->cpu_build_inputs_data;
                instance->cpu_build_inputs_data = nullptr;
            }
        }
    }
}

void Dx12AccelerationStructureBuilder::InjectTransitionBarrierCmd(ID3D12Resource*       resource,
                                                                  D3D12_RESOURCE_STATES state_before,
                                                                  D3D12_RESOURCE_STATES state_after)
{
    if (resource != nullptr)
    {
        D3D12_RESOURCE_BARRIER barrier = {};
        barrier.Type                   = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
        barrier.Transition.pResource   = resource;
        barrier.Transition.StateBefore = state_before;
        barrier.Transition.StateAfter  = state_after;

        command_list4_->ResourceBarrier(1, &barrier);
    }
}

void Dx12AccelerationStructureBuilder::SetupInstance(const graphics::Dx12GpuVaMap& gpu_va_map, IDASCInstance& instance)
{
    if (instance.build)
    {
        SetupBuild(gpu_va_map, instance);
    }

    if (instance.copy)
    {
        SetupCopy(gpu_va_map, instance);
    }

    instance.buffer_sizes.total_size = GetIDASCConsumption(instance,
                                                           instance.buffer_sizes.scratch_buffer_size,
                                                           instance.buffer_sizes.inputs_buffer_size,
                                                           instance.buffer_sizes.temp_dest_buffer_size);
}

void Dx12AccelerationStructureBuilder::InjectBlockCmd(const graphics::Dx12GpuVaMap& gpu_va_map, IDASCInstance& instance)
{
    if (instance.build)
    {
        if (instance.build_info.build_desc.Inputs.Type == D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL)
        {
            InjectUavBarrierCmd();
        }

        command_list4_->BuildRaytracingAccelerationStructure(&instance.build_info.build_desc, 0, nullptr);
    }

    if (instance.copy)
    {
        InjectUavBarrierCmd();

        command_list4_->CopyRaytracingAccelerationStructure(
            instance.copy_info.dst, instance.copy_info.src, instance.copy_info.mode);
    }

    instance.executed = true;
}

void Dx12AccelerationStructureBuilder::InjectUavBarrierCmd()
{
    D3D12_RESOURCE_BARRIER barrier = {};
    barrier.Type                   = D3D12_RESOURCE_BARRIER_TYPE_UAV;
    barrier.UAV.pResource          = nullptr;

    command_list4_->ResourceBarrier(1, &barrier);
}

void Dx12AccelerationStructureBuilder::ExecuteBuild(IDASCInstance& instance)
{
    BeginCommandList();

    // Add the build command.
    command_list4_->BuildRaytracingAccelerationStructure(&instance.build_info.build_desc, 0, nullptr);

    CloseAndExecute();
}

void Dx12AccelerationStructureBuilder::ExecuteCopy(AsCopyInfo& copy_info)
{
    BeginCommandList();

    // Add copy command
    command_list4_->CopyRaytracingAccelerationStructure(copy_info.dst, copy_info.src, copy_info.mode);

    CloseAndExecute();
}

void Dx12AccelerationStructureBuilder::BeginCommandList()
{
    // Reset command allocator and command list.
    HRESULT hr = command_allocator_->Reset();
    GFXRECON_ASSERT(SUCCEEDED(hr));
    hr = command_list4_->Reset(command_allocator_, nullptr);
    GFXRECON_ASSERT(SUCCEEDED(hr));
}

void Dx12AccelerationStructureBuilder::CloseAndExecute()
{
    HRESULT hr = command_list4_->Close();

    // Execute the command list and wait for completion.
    ID3D12CommandList* cmd_lists[] = { command_list4_ };
    command_queue_->ExecuteCommandLists(1, cmd_lists);
    hr = graphics::dx12::WaitForQueue(command_queue_, fence_, ++fence_value_);
    GFXRECON_ASSERT(SUCCEEDED(hr));
}

void Dx12AccelerationStructureBuilder::BeginTimestamp()
{
    static bool timestamped_start = false;

    if (timestamped_start == false)
    {
        QueryPerformanceFrequency(&frequency);
        QueryPerformanceCounter(&begin_ts);
        timestamped_start = true;
    }
}

void Dx12AccelerationStructureBuilder::EndTimestamp()
{
    static bool timestamped_end = false;

    if (timestamped_end == false)
    {
        QueryPerformanceCounter(&end_ts);
        double duration = ((end_ts.QuadPart - begin_ts.QuadPart) / (double)frequency.QuadPart);
        GFXRECON_LOG_INFO("Duration of all InitDx12AccelerationStructureCommands: %.2f sec", duration);
        timestamped_end = true;
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
