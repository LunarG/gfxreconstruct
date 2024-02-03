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
    format::HandleId    source_resource_id{ format::kNullHandleId };
    D3D12_RESOURCE_DESC desc{};
    // Buffer has its one offset and size, not for subresources.
    // Texture has offsets and sizes of subresources.
    std::vector<uint64_t>                           offsets;
    std::vector<uint64_t>                           sizes;
    std::vector<uint32_t>                           subresource_indices; // Buffer has one index: 0.
    std::vector<D3D12_PLACED_SUBRESOURCE_FOOTPRINT> footprints;
    uint64_t                                        total_size{ 0 };
    std::vector<uint8_t>                            before_data; // copy resource before drawcall
    std::vector<uint8_t>                            after_data;  // copy resource after drawcall

    void Clear()
    {
        before_data.clear();
        after_data.clear();
    }
};

struct UnorderedAccess
{
    CopyResourceData resource;
    CopyResourceData counter_resource;
};

struct DescriptorHeapData
{
    std::vector<CopyResourceData> copy_constant_buffer_resources;
    std::vector<CopyResourceData> copy_shader_resources;
    std::vector<UnorderedAccess>  copy_unordered_accesses;
};

struct CommandSet
{
    dx12::ID3D12CommandAllocatorComPtr    allocator;
    dx12::ID3D12GraphicsCommandListComPtr list;
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

    // ExecuteIndirect
    CopyResourceData copy_exe_indirect_argument;
    CopyResourceData copy_exe_indirect_count;

    // pair: captured_buffer, modified_buffer
    std::vector<std::pair<std::vector<uint8_t>, std::vector<uint8_t>>> signature_buffers;

    enum SplitCommandType
    {
        kBeforeDrawCall,
        kDrawCall,
        kAfterDrawCall,
    };
    std::array<CommandSet, 3> split_command_sets;

    graphics::dx12::ID3D12FenceComPtr fence;

    void Clear()
    {
        target.Clear();
        copy_vertex_resources.clear();
        copy_index_resource.Clear();
        descriptor_heap_datas.clear();
        render_target_heap_ids.clear();
        replay_render_target_handles.clear();
        copy_render_target_resources.clear();
        copy_depth_stencil_resource.Clear();
        copy_exe_indirect_argument.Clear();
        copy_exe_indirect_count.Clear();
        signature_buffers.clear();
    }
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

    bool WriteBinaryFile(const std::string& filename, const std::vector<uint8_t>& data, uint64_t offset, uint64_t size);

    void TestWriteReadableResources(const std::string&                   prefix_file_name,
                                    const std::vector<CopyResourceData>& resource_datas);
    void TestWriteReadableResource(const std::string& prefix_file_name, const CopyResourceData& resource_data);

    void TestWriteFloatResource(const std::string& prefix_file_name, const CopyResourceData& resource_data);
    void TestWriteImageResource(const std::string& prefix_file_name, const CopyResourceData& resource_data);

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
