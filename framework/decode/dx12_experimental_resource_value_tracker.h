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

#ifndef GFXRECON_DECODE_DX12_EXPERIMENTAL_RESOURCE_VALUE_TRACKER_H
#define GFXRECON_DECODE_DX12_EXPERIMENTAL_RESOURCE_VALUE_TRACKER_H

#include "decode/dx12_resource_value_tracker.h"

#include "decode/dx12_descriptor_map.h"
#include "decode/dx12_object_info.h"
#include "decode/handle_pointer_decoder.h"
#include "decode/struct_pointer_decoder.h"
#include "graphics/dx12_gpu_va_map.h"
#include "util/defines.h"

#include <utility>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class Dx12ExperimentalResourceValueTracker : public Dx12ResourceValueTracker
{
  public:
    Dx12ExperimentalResourceValueTracker(std::function<DxObjectInfo*(format::HandleId id)> get_object_info_func,
                                         std::function<uint64_t(void)> get_current_block_index_func) :
        Dx12ResourceValueTracker(get_object_info_func, get_current_block_index_func),
        track_unassociated_values_(true), resolve_unassociated_values_(false),
        min_gpu_va_(std::numeric_limits<uint64_t>::max()), max_gpu_va_(0),
        min_gpu_descriptor_(std::numeric_limits<uint64_t>::max()), max_gpu_descriptor_(0),
        min_gpu_descriptor_alignment_(std::numeric_limits<uint64_t>::max())
    {}

    virtual bool AddTrackedResourceValue(format::HandleId              resource_id,
                                         ResourceValueType             type,
                                         uint64_t                      offset,
                                         const uint8_t*                resource_value_data,
                                         const graphics::Dx12GpuVaMap& gpu_va_map) override;

    virtual void
    PostProcessExecuteCommandLists(DxObjectInfo*                             command_queue_object_info,
                                   UINT                                      num_command_lists,
                                   HandlePointerDecoder<ID3D12CommandList*>* command_lists_decoder) override;

    virtual void
    PostProcessFillMemoryCommand(uint64_t resource_id, uint64_t offset, uint64_t size, const uint8_t* data) override;

    virtual void PostProcessInitSubresourceCommand(ID3D12Resource*                             resource,
                                                   const format::InitSubresourceCommandHeader& command_header,
                                                   const uint8_t*                              data) override;

    virtual void GetTrackedResourceValues(Dx12FillCommandResourceValueMap& values) override;

  protected:
    virtual void ProcessExecuteCommandList(ProcessExecuteCommandListArgs args) override;

  private:
    Dx12UnassociatedResourceValueMap unassociated_resource_values_;

  public:
    // After the first pass of experimental tracking, get the resource values that remained unassociated with a fill
    // memory or init subresource command.
    virtual void GetUnassociatedResourceValues(Dx12UnassociatedResourceValueMap& values) override;

    // The second pass attempts to resolve the unassociated values from the first pass. Set them here to indicate this
    // is a second pass.
    virtual void SetUnassociatedResourceValues(Dx12FillCommandResourceValueMap&&          tracked_values,
                                               decode::Dx12UnassociatedResourceValueMap&& unassociated_values) override;

    virtual void AddShaderRecordData(format::HandleId                 resource_id,
                                     uint64_t                         offset,
                                     uint64_t                         shader_record_size,
                                     const uint8_t*                   shader_record_data,
                                     const graphics::Dx12GpuVaMap&    gpu_va_map,
                                     const decode::Dx12DescriptorMap& descriptor_map) override;

    virtual void PostProcessCopyTextureRegion(DxObjectInfo* command_list_object_info,
                                              StructPointerDecoder<Decoded_D3D12_TEXTURE_COPY_LOCATION>* dst_decoder,
                                              UINT                                                       dst_x,
                                              UINT                                                       dst_y,
                                              UINT                                                       dst_z,
                                              StructPointerDecoder<Decoded_D3D12_TEXTURE_COPY_LOCATION>* src_decoder,
                                              StructPointerDecoder<Decoded_D3D12_BOX>* src_box_decoder) override;

    virtual void PostProcessIASetIndexBuffer(DxObjectInfo* command_list_object_info,
                                             StructPointerDecoder<Decoded_D3D12_INDEX_BUFFER_VIEW>* views_decoder,
                                             const graphics::Dx12GpuVaMap& reverse_gpu_va_map) override;

    virtual void PostProcessIASetVertexBuffers(DxObjectInfo* command_list_object_info,
                                               UINT          start_slot,
                                               UINT          num_views,
                                               StructPointerDecoder<Decoded_D3D12_VERTEX_BUFFER_VIEW>* views_decoder,
                                               const graphics::Dx12GpuVaMap& reverse_gpu_va_map) override;

    virtual void PostProcessCommandListReset(DxObjectInfo* command_list_object_info) override;

    virtual void AddResourceGpuVa(format::HandleId          resource_id,
                                  D3D12_GPU_VIRTUAL_ADDRESS replay_address,
                                  UINT64                    width,
                                  D3D12_GPU_VIRTUAL_ADDRESS capture_address) override;

    virtual void RemoveResourceGpuVa(format::HandleId resource_id, uint64_t capture_address) override;

    virtual void AddGpuDescriptorHeap(const D3D12_GPU_DESCRIPTOR_HANDLE&     capture_gpu_start,
                                      const D3D12_GPU_DESCRIPTOR_HANDLE&     replay_gpu_start,
                                      D3D12_DESCRIPTOR_HEAP_TYPE             heap_info_descriptor_type,
                                      uint32_t                               heap_info_descriptor_count,
                                      std::shared_ptr<DescriptorIncrements>& heap_info_capture_increments,
                                      std::shared_ptr<DescriptorIncrements>& heap_info_replay_increments) override;

    virtual void RemoveGpuDescriptorHeap(uint64_t capture_address) override;

  private:
    const uint64_t kMinDataAlignment = 4;

    struct FindResourceValuesThreadData
    {
        std::thread                                                 thread;
        uint64_t                                                    data_offset{ 0 };
        uint64_t                                                    data_size{ 0 };
        std::vector<std::pair<uint64_t, format::ResourceValueType>> found_resource_values;
    };

    struct TrackerCommandListInfo
    {
        std::map<format::HandleId, ResourceRanges> non_dxr_resources_;

        void Reset() { non_dxr_resources_.clear(); }
    };

    void AddNonDxrFillCommandBlocks(format::HandleId resource_id,
                                    uint64_t         resource_min_offset,
                                    uint64_t         resource_max_offset);

    void FindResourceValues(const uint8_t*                                               data,
                            uint64_t                                                     data_size,
                            const std::set<graphics::Dx12ShaderIdentifier>*              shader_ids,
                            const graphics::Dx12GpuVaMap*                                gpu_va_map,
                            const decode::Dx12DescriptorMap*                             gpu_descriptor_map,
                            std::vector<std::pair<uint64_t, format::ResourceValueType>>* found_resource_values) const;

    void FindResourceValuesThreaded(const TrackedFillCommandInfo& tracked_fill_command,
                                    const uint8_t*                data,
                                    uint64_t                      data_size);

    bool track_unassociated_values_;   ///< True for first pass of experimental tracking.
    bool resolve_unassociated_values_; ///< True for second pass of experimental tracking.

    std::set<graphics::Dx12ShaderIdentifier> unique_unassociated_shader_ids_;

    std::set<format::HandleId> all_unassociated_gpu_va_map_;
    graphics::Dx12GpuVaMap     active_unassociated_gpu_va_map_;
    uint64_t                   min_gpu_va_;
    uint64_t                   max_gpu_va_;

    decode::Dx12DescriptorMap active_unassociated_gpu_descriptor_map_;
    uint64_t                  min_gpu_descriptor_;
    uint64_t                  max_gpu_descriptor_;
    uint64_t                  min_gpu_descriptor_alignment_;

    std::vector<FindResourceValuesThreadData> find_resource_values_thread_datas_;

    std::map<format::HandleId, TrackerCommandListInfo> tracker_command_list_infos_;

    std::map<Dx12FillCommandBlockIndex, std::map<uint64_t, uint64_t, std::greater<uint64_t>>>
        non_dxr_fill_command_data_;

    // Temp vector to reduce allocations.
    std::vector<std::pair<uint64_t, format::ResourceValueType>> temp_found_shader_record_values_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_DX12_EXPERIMENTAL_RESOURCE_VALUE_TRACKER_H
