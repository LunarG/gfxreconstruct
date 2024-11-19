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
#include "decode/dx12_object_mapping_util.h"
#include "graphics/dx12_util.h"
#include "graphics/dx12_gpu_va_map.h"
#include "util/defines.h"
#include "util/json_util.h"

#include <d3d12.h>

#include <memory>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

constexpr gfxrecon::util::JsonFormat kDefaultDumpResourcesFileFormat = gfxrecon::util::JsonFormat::JSON;

enum class Dx12DumpResourceType : uint32_t
{
    kUnknown,
    kRtv,
    kDsv,
    kSrv,
    kUav,
    kUavCounter,
    kVertex,
    kIndex,
    kCbv,
    kExecuteIndirectArg,
    kExecuteIndirectCount,
    kGraphicsRootParameters,
    kComputeRootParameters,
};

struct CopyResourceData
{
    // Allow default constructor, disallow copy constructor.
    CopyResourceData()                        = default;
    CopyResourceData(const CopyResourceData&) = delete;

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

    std::vector<std::vector<uint8_t>> datas; // copy resource draw call

    graphics::dx12::ID3D12GraphicsCommandListComPtr cmd_list{ nullptr };
    graphics::dx12::ID3D12ResourceComPtr            read_resource{ nullptr };
    bool                                            read_resource_is_staging_buffer{ false };

    std::vector<std::pair<std::string, int32_t>> json_path;
    Dx12DumpResourceType                         resource_type{ Dx12DumpResourceType::kUnknown };
    graphics::dx12::Dx12DumpResourcePos          dump_position{ graphics::dx12::Dx12DumpResourcePos::kUnknown };

    format::HandleId descriptor_heap_id{ format::kNullHandleId };
    uint32_t         descriptor_heap_index{ 0 };

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
        total_size                      = 0;
        is_cpu_accessible               = false;
        datas                           = std::vector<std::vector<uint8_t>>();
        cmd_list                        = nullptr;
        read_resource                   = nullptr;
        read_resource_is_staging_buffer = false;
        resource_type                   = Dx12DumpResourceType::kUnknown;
        dump_position                   = graphics::dx12::Dx12DumpResourcePos::kUnknown;
        descriptor_heap_id              = format::kUnknown;
        descriptor_heap_index           = 0;
    }
};

typedef std::shared_ptr<CopyResourceData> CopyResourceDataPtr;

struct TrackDumpResources
{
    TrackDumpDrawCall target{};

    // render target
    std::vector<format::HandleId>            render_target_heap_ids;
    std::vector<D3D12_CPU_DESCRIPTOR_HANDLE> replay_render_target_handles;
    format::HandleId                         depth_stencil_heap_id{ format::kNullHandleId };
    D3D12_CPU_DESCRIPTOR_HANDLE              replay_depth_stencil_handle{ kNullCpuAddress };

    graphics::dx12::ID3D12CommandAllocatorComPtr copy_cmd_allocator{ nullptr };
    graphics::dx12::ID3D12ResourceComPtr         copy_staging_buffer{ nullptr };
    uint64_t                                     copy_staging_buffer_size{ 0 };

    std::array<graphics::dx12::CommandSet, 3> split_command_sets;
    std::array<graphics::dx12::CommandSet, 3> split_bundle_command_sets;

    graphics::dx12::ID3D12FenceComPtr fence;
    HANDLE                            fence_event;
    uint64_t                          fence_signal_value{ 1 };

    void Clear()
    {
        target.Clear();
        render_target_heap_ids.clear();
        replay_render_target_handles.clear();
        copy_cmd_allocator  = nullptr;
        copy_staging_buffer = nullptr;
    }
};

class Dx12DumpResourcesDelegate
{
  public:
    virtual ~Dx12DumpResourcesDelegate() {}

    virtual void BeginDumpResources(const std::string& filename, const TrackDumpResources& track_dump_resources) = 0;
    virtual void DumpResource(CopyResourceDataPtr resource_data)                                                 = 0;
    virtual void EndDumpResources()                                                                              = 0;
    virtual void WriteSingleData(const std::vector<std::pair<std::string, int32_t>>& json_path,
                                 const std::string&                                  key,
                                 uint64_t                                            value)                                                                    = 0;
    virtual void WriteSingleData(const std::vector<std::pair<std::string, int32_t>>& json_path,
                                 const uint32_t                                      index,
                                 uint64_t                                            value)                                                                    = 0;
    virtual void WriteSingleData(const std::vector<std::pair<std::string, int32_t>>& json_path,
                                 const std::string&                                  key,
                                 const std::string&                                  value)                                                          = 0;
    virtual void WriteEmptyNode(const std::vector<std::pair<std::string, int32_t>>& json_path)                      = 0;
    virtual void WriteNote(const std::vector<std::pair<std::string, int32_t>>& json_path, const std::string& value) = 0;
};

class DefaultDx12DumpResourcesDelegate : public Dx12DumpResourcesDelegate
{
  public:
    virtual ~DefaultDx12DumpResourcesDelegate() {}

    virtual void BeginDumpResources(const std::string&        capture_file_name,
                                    const TrackDumpResources& track_dump_resources) override;
    virtual void DumpResource(CopyResourceDataPtr resource_data) override;
    virtual void EndDumpResources() override;
    virtual void WriteSingleData(const std::vector<std::pair<std::string, int32_t>>& json_path,
                                 const std::string&                                  key,
                                 uint64_t                                            value) override;
    virtual void WriteSingleData(const std::vector<std::pair<std::string, int32_t>>& json_path,
                                 const uint32_t                                      index,
                                 uint64_t                                            value) override;
    virtual void WriteSingleData(const std::vector<std::pair<std::string, int32_t>>& json_path,
                                 const std::string&                                  key,
                                 const std::string&                                  value) override;
    virtual void WriteEmptyNode(const std::vector<std::pair<std::string, int32_t>>& json_path) override;
    virtual void WriteNote(const std::vector<std::pair<std::string, int32_t>>& json_path,
                           const std::string&                                  value) override;

  private:
    void WriteResource(const CopyResourceDataPtr resource_data);
    void WriteResource(nlohmann::ordered_json&   jdata,
                       const std::string&        prefix_file_name,
                       const CopyResourceDataPtr resource_data);

    void StartFile();
    void EndFile();
    void WriteBlockStart();
    void WriteBlockEnd();

    nlohmann::ordered_json* FindDrawCallJsonPath(const std::vector<std::pair<std::string, int32_t>>& json_path);

    constexpr const char* NameDrawCall() const { return "draw_call"; }
    constexpr const char* NameNotes() const { return "notes"; }

    bool WriteBinaryFile(const std::string& filename, const std::vector<uint8_t>& data, uint64_t offset, uint64_t size);

    void TestWriteReadableResource(const std::string& prefix_file_name, const CopyResourceDataPtr resource_data);

    void TestWriteFloatResource(const std::string& prefix_file_name, const CopyResourceDataPtr resource_data);

    void TestWriteImageResource(const std::string& prefix_file_name, const CopyResourceDataPtr resource_data);

    util::JsonOptions      json_options_;
    std::string            json_filename_;
    FILE*                  json_file_handle_{ nullptr };
    nlohmann::ordered_json json_data_;
    nlohmann::ordered_json header_;
    nlohmann::ordered_json draw_call_;
    uint32_t               num_objects_{ 0 };
    uint32_t               num_files_{ 0 };
};

// TODO: This class copys a lot of code to write json from VulkanExportJsonConsumerBase.
//       We might need a class for writing json.
class Dx12DumpResources
{
  public:
    Dx12DumpResources(std::function<DxObjectInfo*(format::HandleId id)> get_object_info_func,
                      const graphics::Dx12GpuVaMap&                     gpu_va_map,
                      DxReplayOptions&                                  options);

    void SetDelegate(Dx12DumpResourcesDelegate* delegate) { user_delegate_ = delegate; }

    std::vector<graphics::dx12::CommandSet> GetCommandListsForDumpResources(DxObjectInfo*     command_list_object_info,
                                                                            uint64_t          block_index,
                                                                            format::ApiCallId api_call_id);

    inline void SetDumpTarget(TrackDumpDrawCall& track_dump_target)
    {
        track_dump_resources_.target = track_dump_target;
    }

    bool ExecuteCommandLists(DxObjectInfo*                             replay_object_info,
                             UINT                                      num_command_lists,
                             HandlePointerDecoder<ID3D12CommandList*>* command_lists,
                             const uint64_t                            block_index,
                             const bool                                needs_mapping,
                             const std::string&                        filename);
    void ExecuteBundle(DxObjectInfo* replay_object_info, DxObjectInfo* command_list_object_info, uint64_t block_index);
    bool CreateRootSignature(DxObjectInfo*                device_object_info,
                             HRESULT&                     replay_result,
                             UINT                         node_mask,
                             PointerDecoder<uint8_t>*     blob_with_root_signature_decoder,
                             SIZE_T                       blob_length_in_bytes,
                             Decoded_GUID                 riid,
                             HandlePointerDecoder<void*>* root_signature_decoder);
    void OMSetRenderTargets(const ApiCallInfo&                                         call_info,
                            DxObjectInfo*                                              object_info,
                            UINT                                                       NumRenderTargetDescriptors,
                            StructPointerDecoder<Decoded_D3D12_CPU_DESCRIPTOR_HANDLE>* pRenderTargetDescriptors,
                            BOOL                                                       RTsSingleHandleToDescriptorRange,
                            StructPointerDecoder<Decoded_D3D12_CPU_DESCRIPTOR_HANDLE>* pDepthStencilDescriptor);
    void BeginRenderPass(DxObjectInfo*                                                       replay_object_info,
                         UINT                                                                NumRenderTargets,
                         StructPointerDecoder<Decoded_D3D12_RENDER_PASS_RENDER_TARGET_DESC>* pRenderTargets,
                         StructPointerDecoder<Decoded_D3D12_RENDER_PASS_DEPTH_STENCIL_DESC>* pDepthStencil,
                         D3D12_RENDER_PASS_FLAGS                                             Flags,
                         uint64_t                                                            block_index);
    void GetDescriptorSubresourceIndices(DHShaderResourceViewInfo& info, const DxObjectInfo* resource);
    void GetDescriptorSubresourceIndices(DHUnorderedAccessViewInfo& info, const DxObjectInfo* resource);
    void GetDescriptorSubresourceIndices(DHRenderTargetViewInfo& info, const DxObjectInfo* resource);
    void GetDescriptorSubresourceIndices(DHDepthStencilViewInfo& info, const DxObjectInfo* resource);

  private:
    void StartDump(ID3D12Device* device, const std::string& filename);
    void FinishDump(DxObjectInfo* queue_object_info);
    void CloseDump();

    void WriteDescripotTable(DxObjectInfo*                                queue_object_info,
                             const std::vector<format::HandleId>&         front_command_list_ids,
                             graphics::dx12::Dx12DumpResourcePos          pos,
                             std::vector<std::pair<std::string, int32_t>> json_path,
                             const D3D12DescriptorHeapInfo*               heap_info,
                             format::HandleId                             heap_id,
                             uint32_t                                     heap_index,
                             const D3D12_DESCRIPTOR_RANGE1*               range);

    void WriteRootParameters(DxObjectInfo*                                           queue_object_info,
                             const std::vector<format::HandleId>&                    front_command_list_ids,
                             graphics::dx12::Dx12DumpResourcePos                     pos,
                             Dx12DumpResourceType                                    res_type,
                             const std::vector<format::HandleId>&                    descriptor_heap_ids,
                             const std::unordered_map<uint32_t, TrackRootParameter>& root_parameters);

    void CopyDrawCallResources(DxObjectInfo*                        queue_object_info,
                               const std::vector<format::HandleId>& front_command_list_ids,
                               graphics::dx12::Dx12DumpResourcePos  pos);

    void CopyDrawCallResourceByGPUVA(DxObjectInfo*                                       queue_object_info,
                                     const std::vector<format::HandleId>&                front_command_list_ids,
                                     D3D12_GPU_VIRTUAL_ADDRESS                           capture_source_gpu_va,
                                     uint64_t                                            source_size,
                                     const std::vector<std::pair<std::string, int32_t>>& json_path,
                                     Dx12DumpResourceType                                resource_type,
                                     graphics::dx12::Dx12DumpResourcePos                 pos,
                                     format::HandleId                                    descriptor_heap_id,
                                     uint32_t                                            descriptor_heap_index);

    void CopyDrawCallResourceBySubresource(DxObjectInfo*                                       queue_object_info,
                                           const std::vector<format::HandleId>&                front_command_list_ids,
                                           format::HandleId                                    source_resource_id,
                                           uint64_t                                            source_offset,
                                           uint64_t                                            source_size,
                                           const std::vector<uint32_t>&                        subresource_indices,
                                           const std::vector<std::pair<std::string, int32_t>>& json_path,
                                           Dx12DumpResourceType                                resource_type,
                                           graphics::dx12::Dx12DumpResourcePos                 pos,
                                           format::HandleId                                    descriptor_heap_id,
                                           uint32_t                                            descriptor_heap_index);

    void CopyDrawCallResource(DxObjectInfo*                        queue_object_info,
                              const std::vector<format::HandleId>& front_command_list_ids,
                              format::HandleId                     source_resource_id,
                              uint64_t                             source_offset,
                              uint64_t                             source_size,
                              CopyResourceDataPtr                  copy_resource_data);

    bool CopyResourceAsyncQueue(const std::vector<format::HandleId>& front_command_list_ids,
                                CopyResourceDataPtr                  copy_resource_data,
                                ID3D12CommandQueue*                  queue,
                                ID3D12Fence*                         fence,
                                UINT64                               fence_signal_value,
                                UINT64                               fence_wait_value);

    void CopyResourceAsyncRead(graphics::dx12::ID3D12FenceComPtr fence,
                               UINT64                            fence_wait_value,
                               UINT64                            fence_signal_value,
                               HANDLE                            fence_event,
                               CopyResourceDataPtr               copy_resource_data);

    void CopyResourceAsync(DxObjectInfo*                        queue_object_info,
                           const std::vector<format::HandleId>& front_command_list_ids,
                           CopyResourceDataPtr                  copy_resource_data);

    QueueSyncEventInfo CreateCopyResourceAsyncReadQueueSyncEvent(graphics::dx12::ID3D12FenceComPtr fence,
                                                                 UINT64                            fence_wait_value,
                                                                 UINT64                            fence_signal_value,
                                                                 HANDLE                            fence_event,
                                                                 CopyResourceDataPtr               copy_resource_data);

    TrackDumpResources track_dump_resources_;

    std::function<DxObjectInfo*(format::HandleId id)> get_object_info_func_;
    const graphics::Dx12GpuVaMap&                     gpu_va_map_;
    const DxReplayOptions&                            options_;

    std::unique_ptr<DefaultDx12DumpResourcesDelegate> default_delegate_;
    Dx12DumpResourcesDelegate*                        user_delegate_;
    Dx12DumpResourcesDelegate*                        active_delegate_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
