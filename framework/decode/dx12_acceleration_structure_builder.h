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

#ifndef GFXRECON_DECODE_DX12_ACCELERATION_STRUCTURE_BUILDER_H
#define GFXRECON_DECODE_DX12_ACCELERATION_STRUCTURE_BUILDER_H

#include "decode/dx_replay_options.h"
#include "decode/dx12_object_info.h"
#include "graphics/dx12_gpu_va_map.h"
#include "graphics/dx12_util.h"
#include "format/format.h"
#include "util/defines.h"

#include <d3d12.h>
#include <vector>
#include <functional>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

// Information specific to copies
struct AsCopyInfo
{
    D3D12_GPU_VIRTUAL_ADDRESS                         dst;
    D3D12_GPU_VIRTUAL_ADDRESS                         src;
    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE mode;
};

// Information specific to builds
struct AsBuildInfo
{
    uint64_t                                    inputs_buffer_size{ 0 };
    uint64_t                                    scratch_buffer_size{ 0 };
    std::vector<D3D12_RAYTRACING_GEOMETRY_DESC> temp_geometry_descs;
    std::vector<uint8_t>                        temp_instance_desc_input_data;

    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO prebuild_info{};
    D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC    build_desc{};

    std::vector<graphics::dx12::InputsBufferEntry> inputs_buffer_entries;
};

// GPU buffer sizes
struct AsBufferSizes
{
    uint64_t scratch_buffer_size{ 0 };
    uint64_t inputs_buffer_size{ 0 };
    uint64_t temp_dest_buffer_size{ 0 };
    uint64_t total_size{ 0 };
};

// Contains everything needed to execute an IDASC block
struct IDASCInstance
{
    format::InitDx12AccelerationStructureCommandHeader             command_header;
    std::vector<format::InitDx12AccelerationStructureGeometryDesc> init_geometry_descs;
    bool                                                           build{ false };
    bool                                                           copy{ false };
    bool                                                           use_temp_dest_buffer{ false };

    AsBuildInfo build_info{};
    AsCopyInfo  copy_info{};

    AsBufferSizes buffer_sizes{};

    graphics::dx12::ID3D12ResourceComPtr temp_dest_buffer{ nullptr };
    graphics::dx12::ID3D12ResourceComPtr inputs_buffer{ nullptr };
    graphics::dx12::ID3D12ResourceComPtr scratch_buffer{ nullptr };

    uint8_t* build_inputs_data{ nullptr };
    uint8_t* cpu_build_inputs_data{ nullptr };

    bool executed{ false };
};

// For batching purposes, these groups contain lists of instances plus their total size
struct IDASCGroup
{
    std::vector<IDASCInstance*> instances;
    AsBufferSizes               buffer_sizes{};
};

// Information only relevant to BATCHED_AS_BUILD_MODE_INCREMENTAL_GROUPING
struct IncrementalBatchingInfo
{
    uint64_t running_requirement{ 0 };
    uint32_t idasc_start{ 0 };
    uint32_t idasc_idx{ 0 };
};

class Dx12AccelerationStructureBuilder
{
  public:
    Dx12AccelerationStructureBuilder(graphics::dx12::ID3D12Device5ComPtr device5,
                                     IDXGIAdapter3*                      adapter3,
                                     const BatchedASBuildConfig&         config);

    virtual ~Dx12AccelerationStructureBuilder() {}

    void Build(const graphics::Dx12GpuVaMap&                                         gpu_va_map,
               const format::InitDx12AccelerationStructureCommandHeader&             command_header,
               const std::vector<format::InitDx12AccelerationStructureGeometryDesc>& init_geometry_descs,
               const uint8_t*                                                        build_inputs_data);

    void End(const graphics::Dx12GpuVaMap& gpu_va_map);

    void BeginTimestamp();

    void EndTimestamp();

  private:
    void AddNewInstance(const format::InitDx12AccelerationStructureCommandHeader& command_header,
                        const uint8_t*                                            build_inputs_data,
                        const IDASCInstance&                                      new_instance);

    void InjectUavBarrierCmd();

    void ExecuteGroup(const graphics::Dx12GpuVaMap& gpu_va_map, IDASCGroup& group);

    void UpdateGpuMemCopy(IDASCInstance& instance);

    void InjectBlockCmd(const graphics::Dx12GpuVaMap& gpu_va_map, IDASCInstance& instance);

    void BeginCommandList();

    void CloseAndExecute();

    void ExecuteBatchEndGrouping(const graphics::Dx12GpuVaMap& gpu_va_map);

    void SetupInstance(const graphics::Dx12GpuVaMap& gpu_va_map, IDASCInstance& instance);

    void GroupInstancesByMemoryBudget(std::vector<IDASCGroup>& groups);

    void UpdateGpuMemBuild(const graphics::Dx12GpuVaMap& gpu_va_map, IDASCInstance& instance);

    void ExecuteBuild(IDASCInstance& instance);

    void SetupCopy(const graphics::Dx12GpuVaMap& gpu_va_map, IDASCInstance& instance);

    void SetupBuild(const graphics::Dx12GpuVaMap& gpu_va_map, IDASCInstance& instance);

    void ExecuteNoBatch(const graphics::Dx12GpuVaMap& gpu_va_map, IDASCInstance& instance);

    void AddInstanceToGroup(IDASCGroup& group, IDASCInstance& instance);

    void ResetGroupSizes(IDASCGroup& group);

    void ExecuteRemainingInstances(const graphics::Dx12GpuVaMap& gpu_va_map);

    void ExecuteBatchIncrementalGrouping(const graphics::Dx12GpuVaMap& gpu_va_map, uint32_t start);

    void ExecuteCopy(AsCopyInfo& copy_info);

    uint64_t GetMemoryBudget();

    uint64_t GetIDASCConsumption(const IDASCInstance& instance,
                                 uint64_t&            scratch_buffer_size,
                                 uint64_t&            inputs_buffer_size,
                                 uint64_t&            temp_dest_buffer_size);

    void UpdateGroupSizes(IDASCGroup& group, const IDASCInstance& instance);

    void InjectTransitionBarrierCmd(ID3D12Resource*       resource,
                                    D3D12_RESOURCE_STATES state_before,
                                    D3D12_RESOURCE_STATES state_after);

  private:
    graphics::dx12::ID3D12Device5ComPtr              device5_;
    graphics::dx12::ID3D12CommandQueueComPtr         command_queue_;
    graphics::dx12::ID3D12CommandAllocatorComPtr     command_allocator_;
    graphics::dx12::ID3D12GraphicsCommandList4ComPtr command_list4_;
    graphics::dx12::ID3D12FenceComPtr                fence_;
    graphics::dx12::IDXGIAdapter3ComPtr              adapter3_{ nullptr };
    bool                                             is_uma_{ false };
    uint64_t                                         fence_value_;

    // Unbatched data
    IDASCInstance unbatched_instance_;

    // Batched data
    std::vector<IDASCInstance> batched_instances_;
    IncrementalBatchingInfo    incremental_info_{};
    BatchedASBuildConfig       config_;
    double                     max_batched_mem_usage_{ 0 };

    // Timestamping
    LARGE_INTEGER begin_ts  = {};
    LARGE_INTEGER end_ts    = {};
    LARGE_INTEGER frequency = {};
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_DX12_ACCELERATION_STRUCTURE_BUILDER_H
