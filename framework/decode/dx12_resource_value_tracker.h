/*
** Copyright (c) 2022 LunarG, Inc.
** Copyright (c) 2022 Advanced Micro Devices, Inc. All rights reserved.
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

#ifndef GFXRECON_DECODE_DX12_RESOURCE_VALUE_TRACKER_H
#define GFXRECON_DECODE_DX12_RESOURCE_VALUE_TRACKER_H

#include "decode/dx12_object_info.h"
#include "decode/handle_pointer_decoder.h"
#include "decode/struct_pointer_decoder.h"
#include "graphics/dx12_gpu_va_map.h"
#include "util/defines.h"

#include <utility>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

typedef uint64_t Dx12FillCommandBlockIndex;
typedef uint64_t Dx12FillCommandByteOffset;
#pragma pack(push)
#pragma pack(1)
// There will be many Dx12FillCommandResourceValues. Set struct packing to 1 to minimize memory used.
struct Dx12FillCommandResourceValue
{
    Dx12FillCommandByteOffset offset;
    ResourceValueType         type;
};
#pragma pack(pop)
typedef std::map<Dx12FillCommandBlockIndex, std::vector<Dx12FillCommandResourceValue>> Dx12FillCommandResourceValueMap;

#pragma pack(push)
#pragma pack(1)
struct Dx12UnassociatedResourceValue
{
  private:
    static constexpr size_t kMaxResourceValueSize = D3D12_SHADER_IDENTIFIER_SIZE_IN_BYTES;

  public:
    ResourceValueType type{ ResourceValueType::kUnknown };

    union
    {
        graphics::Dx12ShaderIdentifier shader_id;
        format::HandleId               resource_id{ format::kNullHandleId };
    };
};
#pragma pack(pop)
struct Dx12UnassociatedResourceValueGroup
{
    uint64_t                                   block_index;
    std::vector<Dx12UnassociatedResourceValue> values;
};
typedef std::unordered_map<format::HandleId, std::vector<Dx12UnassociatedResourceValueGroup>>
    Dx12UnassociatedResourceValueMap;

class Dx12ResourceValueTracker
{
  public:
    Dx12ResourceValueTracker(std::function<DxObjectInfo*(format::HandleId id)> get_object_info_func,
                             std::function<uint64_t(void)>                     get_current_block_index_func) :
        get_object_info_func_(get_object_info_func),
        get_current_block_index_func_(get_current_block_index_func)
    {}

    // When Dx12ResourceValueMapper encounters a resource value that needs to be mapped, it will call
    // AddTrackedResourceValue which tries to determine which FillMemoryCommand originally wrote the data based on the
    // FillMemoryCommands and resource copies previously processed by the Dx12ResourceValueTracker.
    virtual bool AddTrackedResourceValue(format::HandleId              resource_id,
                                         ResourceValueType             type,
                                         uint64_t                      offset,
                                         const uint8_t*                resource_value_data,
                                         const graphics::Dx12GpuVaMap& gpu_va_map);

    virtual void PostProcessExecuteCommandLists(DxObjectInfo*                             command_queue_object_info,
                                                UINT                                      num_command_lists,
                                                HandlePointerDecoder<ID3D12CommandList*>* command_lists_decoder);

    virtual void
    PostProcessFillMemoryCommand(uint64_t resource_id, uint64_t offset, uint64_t size, const uint8_t* data);

    virtual void PostProcessInitSubresourceCommand(ID3D12Resource*                             resource,
                                                   const format::InitSubresourceCommandHeader& command_header,
                                                   const uint8_t*                              data);

    virtual void GetTrackedResourceValues(Dx12FillCommandResourceValueMap& values);

  protected:
    typedef std::vector<std::pair<uint64_t, uint64_t>> ResourceRanges;

    struct TrackedFillCommandInfo
    {
        uint64_t fill_command_block_index{ 0 };
        uint64_t original_offset{ 0 }; ///< Offset into the original resource from the original fill command.
        uint64_t offset{ 0 }; ///< Offset into the containing resource that has data from the original fill command.
        uint64_t size{ 0 };   ///< How much data in the containing resource came from this fill command.
        std::shared_ptr<std::vector<uint8_t>>
            init_subresource_data; ///< A copy of the data from init subresource calls.
    };

    struct ProcessExecuteCommandListArgs
    {
        std::vector<ResourceCopyInfo>              resource_copies;
        std::map<format::HandleId, ResourceRanges> non_dxr_resources;
    };

    void AddBlockResourceValue(uint64_t fill_command_block_index, uint64_t offset, ResourceValueType type);

    void UpdateFillCommandState(format::HandleId resource_id, const TrackedFillCommandInfo& new_fill_command);

    virtual void ProcessExecuteCommandList(ProcessExecuteCommandListArgs args);

    QueueSyncEventInfo CreateProcessExecuteCommandListSyncEvent(ProcessExecuteCommandListArgs args)
    {
        return QueueSyncEventInfo{ false, false, nullptr, 0, [this, captured_args = std::move(args)]() {
                                      ProcessExecuteCommandList(captured_args);
                                  } };
    }

    std::map<format::HandleId, std::map<uint64_t, TrackedFillCommandInfo>> tracked_fill_commands_;

    Dx12FillCommandResourceValueMap tracked_resource_values_;

    std::function<DxObjectInfo*(format::HandleId id)> get_object_info_func_;
    std::function<uint64_t(void)>                     get_current_block_index_func_;

  public:
    ////// Begin members to support experimental tracking for experimental DXR optimization:

    // After the first pass of experimental tracking, get the resource values that remained unassociated with a fill
    // memory or init subresource command.
    virtual void GetUnassociatedResourceValues(Dx12UnassociatedResourceValueMap& values) {}

    // The second pass attempts to resolve the unassociated values from the first pass. Set them here to indicate this
    // is a second pass.
    virtual void SetUnassociatedResourceValues(Dx12FillCommandResourceValueMap&&          tracked_values,
                                               decode::Dx12UnassociatedResourceValueMap&& unassociated_values)
    {}

    virtual void AddShaderRecordData(format::HandleId                 resource_id,
                                     uint64_t                         offset,
                                     uint64_t                         shader_record_size,
                                     const uint8_t*                   shader_record_data,
                                     const graphics::Dx12GpuVaMap&    gpu_va_map,
                                     const decode::Dx12DescriptorMap& descriptor_map)
    {}

    virtual void PostProcessCopyTextureRegion(DxObjectInfo* command_list_object_info,
                                              StructPointerDecoder<Decoded_D3D12_TEXTURE_COPY_LOCATION>* dst_decoder,
                                              UINT                                                       dst_x,
                                              UINT                                                       dst_y,
                                              UINT                                                       dst_z,
                                              StructPointerDecoder<Decoded_D3D12_TEXTURE_COPY_LOCATION>* src_decoder,
                                              StructPointerDecoder<Decoded_D3D12_BOX>* src_box_decoder)
    {}

    virtual void PostProcessIASetIndexBuffer(DxObjectInfo* command_list_object_info,
                                             StructPointerDecoder<Decoded_D3D12_INDEX_BUFFER_VIEW>* views_decoder,
                                             const graphics::Dx12GpuVaMap&                          reverse_gpu_va_map)
    {}

    virtual void PostProcessIASetVertexBuffers(DxObjectInfo* command_list_object_info,
                                               UINT          start_slot,
                                               UINT          num_views,
                                               StructPointerDecoder<Decoded_D3D12_VERTEX_BUFFER_VIEW>* views_decoder,
                                               const graphics::Dx12GpuVaMap& reverse_gpu_va_map)
    {}

    virtual void PostProcessCommandListReset(DxObjectInfo* command_list_object_info) {}

    virtual void AddResourceGpuVa(format::HandleId          resource_id,
                                  D3D12_GPU_VIRTUAL_ADDRESS replay_address,
                                  UINT64                    width,
                                  D3D12_GPU_VIRTUAL_ADDRESS capture_address)
    {}

    virtual void RemoveResourceGpuVa(format::HandleId resource_id, uint64_t capture_address) {}

    virtual void AddGpuDescriptorHeap(const D3D12_GPU_DESCRIPTOR_HANDLE&     capture_gpu_start,
                                      const D3D12_GPU_DESCRIPTOR_HANDLE&     replay_gpu_start,
                                      D3D12_DESCRIPTOR_HEAP_TYPE             heap_info_descriptor_type,
                                      uint32_t                               heap_info_descriptor_count,
                                      std::shared_ptr<DescriptorIncrements>& heap_info_capture_increments,
                                      std::shared_ptr<DescriptorIncrements>& heap_info_replay_increments)
    {}

    virtual void RemoveGpuDescriptorHeap(uint64_t capture_address) {}
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_DX12_RESOURCE_VALUE_TRACKER_H
