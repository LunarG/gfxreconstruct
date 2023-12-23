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
    format::HandleId                   source_resource_id{ format::kNullHandleId };
    uint64_t                           source_offset{ 0 };
    uint64_t                           source_size{ 0 };
    D3D12_PLACED_SUBRESOURCE_FOOTPRINT source_footprint{};
    D3D12_RESOURCE_DESC                desc{};
    dx12::ID3D12ResourceComPtr         before_resource{ nullptr }; // copy resource before drawcall
    dx12::ID3D12ResourceComPtr         after_resource{ nullptr };  // copy resource after drawcall
};

struct DescriptorHeapData
{
    std::vector<CopyResourceData> copy_constant_buffer_resources;
    std::vector<CopyResourceData> copy_shader_resources;
};

// TODO: The required data could be a piece of the ID3D12Resource, not the whole ID3D12Resource.
//       we need to handle resource's views' offset, byte stride, count, ...
struct TrackDumpResources
{
    decode::TrackDumpDrawcall target{};

    // vertex
    std::vector<CopyResourceData> copy_vertex_resources;

    // index
    CopyResourceData copy_index_resource;

    // descriptor
    std::vector<DescriptorHeapData> descriptor_heap_datas;

    // render target
    std::vector<format::HandleId>            render_target_heap_ids;
    std::vector<D3D12_CPU_DESCRIPTOR_HANDLE> replay_render_target_handles;
    std::vector<CopyResourceData>            copy_render_target_resources;
    format::HandleId                         depth_stencil_heap_id{ format::kNullHandleId };
    D3D12_CPU_DESCRIPTOR_HANDLE              replay_depth_stencil_handle{ decode::kNullCpuAddress };
    CopyResourceData                         copy_depth_stencil_resource;

    // record BeginRenderPass parameters
    std::vector<D3D12_RENDER_PASS_ENDING_ACCESS> record_render_target_ending_accesses;
    D3D12_RENDER_PASS_ENDING_ACCESS              record_depth_ending_access{};
    D3D12_RENDER_PASS_ENDING_ACCESS              record_stencil_ending_access{};
    D3D12_RENDER_PASS_FLAGS                      record_render_pass_flags{ D3D12_RENDER_PASS_FLAG_NONE };

    // ExecuteIndirect
    CopyResourceData copy_exe_indirect_argument;
    CopyResourceData copy_exe_indirect_count;

    ~TrackDumpResources() {}
};

// TODO: This class copys a lot of code to write json from VulkanExportJsonConsumerBase.
//       We might need a class for writing json.
class Dx12DumpResources
{
  public:
    static std::unique_ptr<Dx12DumpResources> Create(const Dx12DumpResourcesConfig& config);

    ~Dx12DumpResources();

    void WriteResources(const TrackDumpResources& resources);

  private:
    Dx12DumpResources();

    HRESULT Init(const Dx12DumpResourcesConfig& config);

    void WriteResources(nlohmann::ordered_json&              jdata,
                        const std::string&                   prefix_file_name,
                        const std::vector<CopyResourceData>& resource_datas);

    void WriteResource(nlohmann::ordered_json& jdata,
                       const std::string&      prefix_file_name,
                       const CopyResourceData& resource_data);

    void StartFile();
    void EndFile();
    void WriteBlockStart();
    void WriteBlockEnd();

    constexpr const char* NameMeta() const { return "meta"; }
    constexpr const char* NameName() const { return "name"; }
    constexpr const char* NameArgs() const { return "args"; }

    template <typename ToJsonFunctionType>
    inline void WriteMetaCommandToFile(const std::string& command_name, ToJsonFunctionType to_json_function)
    {
        using namespace util;
        WriteBlockStart();

        nlohmann::ordered_json& meta = json_data_[NameMeta()];
        meta[NameName()]             = command_name;
        to_json_function(meta[NameArgs()]);

        WriteBlockEnd();
    }

    bool WriteBinaryFile(const std::string& filename, uint64_t buffer_size, const uint8_t* data);

    util::JsonOptions      json_options_;
    std::string            json_filename_;
    FILE*                  json_file_handle_;
    nlohmann::ordered_json header_;
    nlohmann::ordered_json json_data_;
    uint32_t               num_objects_{ 0 };
    uint32_t               num_files_{ 0 };
};

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
