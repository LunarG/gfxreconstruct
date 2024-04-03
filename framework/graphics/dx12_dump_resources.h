/*
** Copyright (c) 2023 LunarG, Inc.
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

#ifndef GFXRECON_DECODE_DX12_DUMP_RESOURCES_H
#define GFXRECON_DECODE_DX12_DUMP_RESOURCES_H

#include "decode/api_decoder.h"
#include "decode/handle_pointer_decoder.h"
#include "decode/dx_replay_options.h"
#include "decode/dx12_object_info.h"
#include "decode/dx12_browse_consumer.h"
#include "graphics/dx12_util.h"
#include "util/defines.h"
#include "util/json_util.h"

#include <d3d12.h>

#include <memory>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

const gfxrecon::util::JsonFormat kDefaultDumpResourcesFileFormat = gfxrecon::util::JsonFormat::JSON;

struct Dx12DumpResourcesConfig
{
    std::string                           captured_file_name{};
    gfxrecon::decode::DumpResourcesTarget dump_resources_target{};
};

struct CopyResourceData
{
    format::HandleId                                source_resource_id{ format::kNullHandleId };
    D3D12_RESOURCE_DESC                             desc{};
    std::vector<uint64_t>                           subresource_offsets;
    std::vector<uint64_t>                           subresource_sizes;
    std::vector<uint64_t>                           subresource_footprint_offsets;
    std::vector<uint64_t>                           subresource_footprint_sizes;
    std::vector<uint32_t>                           subresource_indices; // Buffer has one index: 0.
    std::vector<D3D12_PLACED_SUBRESOURCE_FOOTPRINT> footprints;
    uint64_t                                        total_size{ 0 };
    bool                                            is_cpu_accessible{ false };

    std::vector<std::vector<uint8_t>> datas; // copy resource  drawcall

    graphics::dx12::ID3D12CommandAllocatorComPtr    cmd_allocator{ nullptr };
    graphics::dx12::ID3D12GraphicsCommandListComPtr cmd_list{ nullptr };
    ID3D12Resource*                                 read_resource{ nullptr };
    bool                                            read_resource_is_staging_buffer{ false };

    void Clear()
    {
        source_resource_id = format::kNullHandleId;
        desc               = {};
        subresource_offsets.clear();
        subresource_sizes.clear();
        subresource_footprint_offsets.clear();
        subresource_footprint_sizes.clear();
        subresource_indices.clear();
        footprints.clear();
        total_size        = 0;
        is_cpu_accessible = false;
        datas.clear();
        cmd_allocator                   = nullptr;
        cmd_list                        = nullptr;
        read_resource                   = nullptr;
        read_resource_is_staging_buffer = false;
    }
};

struct CommandSet
{
    dx12::ID3D12CommandAllocatorComPtr    allocator;
    dx12::ID3D12GraphicsCommandListComPtr list;
};

struct TrackDumpResources
{
    decode::TrackDumpDrawcall target{};

    // render target
    std::vector<format::HandleId>            render_target_heap_ids;
    std::vector<D3D12_CPU_DESCRIPTOR_HANDLE> replay_render_target_handles;
    format::HandleId                         depth_stencil_heap_id{ format::kNullHandleId };
    D3D12_CPU_DESCRIPTOR_HANDLE              replay_depth_stencil_handle{ decode::kNullCpuAddress };

    enum SplitCommandType
    {
        kBeforeDrawCall,
        kDrawCall,
        kAfterDrawCall,
    };
    std::array<CommandSet, 3> split_command_sets;
    std::array<CommandSet, 3> split_bundle_command_sets;

    graphics::dx12::ID3D12FenceComPtr fence;
    HANDLE                            fence_event;

    void Clear()
    {
        target.Clear();
        render_target_heap_ids.clear();
        replay_render_target_handles.clear();
    }
};

// TODO: This class copys a lot of code to write json from VulkanExportJsonConsumerBase.
//       We might need a class for writing json.
class Dx12DumpResources
{
  public:
    static std::unique_ptr<Dx12DumpResources> Create(const Dx12DumpResourcesConfig& config);

    ~Dx12DumpResources();

    void StartDump(const TrackDumpResources& resources);
    void WriteResource(const CopyResourceData&                             resource_data,
                       const std::vector<std::pair<std::string, int32_t>>& json_path,
                       const std::string&                                  file_name,
                       const std::string&                                  type);
    void CloseDump();

  private:
    Dx12DumpResources();

    HRESULT Init(const Dx12DumpResourcesConfig& config);

    void WriteResource(nlohmann::ordered_json& jdata,
                       const std::string&      prefix_file_name,
                       const std::string&      suffix,
                       const CopyResourceData& resource_data);

    void StartFile();
    void EndFile();
    void WriteBlockStart();
    void WriteBlockEnd();

    constexpr const char* NameDrawCall() const { return "drawcall"; }

    bool WriteBinaryFile(const std::string& filename, const std::vector<uint8_t>& data, uint64_t offset, uint64_t size);

    void TestWriteReadableResource(const std::string&      prefix_file_name,
                                   const std::string&      suffix,
                                   const CopyResourceData& resource_data);
    void TestWriteFloatResource(const std::string&      prefix_file_name,
                                const std::string&      suffix,
                                const CopyResourceData& resource_data);
    void TestWriteImageResource(const std::string&      prefix_file_name,
                                const std::string&      suffix,
                                const CopyResourceData& resource_data);

    util::JsonOptions      json_options_;
    std::string            json_filename_;
    FILE*                  json_file_handle_;
    nlohmann::ordered_json json_data_;
    nlohmann::ordered_json header_;
    nlohmann::ordered_json drawcall_;
    uint32_t               num_objects_{ 0 };
    uint32_t               num_files_{ 0 };
};

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
