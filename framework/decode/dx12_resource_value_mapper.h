/*
** Copyright (c) 2022 LunarG, Inc.
** Copyright (c) 2022-2023 Advanced Micro Devices, Inc. All rights reserved.
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

#ifndef GFXRECON_DECODE_DX12_RESOURCE_MAPPING_UTIL_H
#define GFXRECON_DECODE_DX12_RESOURCE_MAPPING_UTIL_H

#include "decode/dx12_object_info.h"
#include "decode/dx12_object_mapping_util.h"
#include "decode/dx12_descriptor_map.h"
#include "decode/dx12_resource_value_tracker.h"
#include "decode/string_decoder.h"
#include "decode/struct_pointer_decoder.h"
#include "graphics/dx12_gpu_va_map.h"
#include "graphics/dx12_resource_data_util.h"
#include "graphics/dx12_shader_id_map.h"
#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class Dx12ResourceValueMapper
{
  public:
    Dx12ResourceValueMapper(std::function<DxObjectInfo*(format::HandleId id)> get_object_info_func,
                            const graphics::Dx12ShaderIdMap&                  shader_id_map,
                            const graphics::Dx12GpuVaMap&                     gpu_va_map,
                            const decode::Dx12DescriptorMap&                  descriptor_map);

    // Enable the Dx12ResoruceValueTracker. This should be done after construction, before any processing.
    void EnableResourceValueTracker(std::function<uint64_t(void)> get_current_block_index_func,
                                    bool                          experimental_tracker);

    // Get the result of the resource value tracker.
    void GetTrackedResourceValues(Dx12FillCommandResourceValueMap& values);

    void GetUnassociatedResourceValues(Dx12UnassociatedResourceValueMap& unassociated_values);

    void SetUnassociatedResourceValues(Dx12FillCommandResourceValueMap&&  tracked_values,
                                       Dx12UnassociatedResourceValueMap&& unassociated_values);

    // Sets needs_mapping = true if the command lists contain resources that need to be mapped.
    void PreProcessExecuteCommandLists(DxObjectInfo*                             command_queue_object_info,
                                       UINT                                      num_command_lists,
                                       HandlePointerDecoder<ID3D12CommandList*>* command_lists_decoder,
                                       bool&                                     needs_mapping);

    void PostProcessExecuteCommandLists(DxObjectInfo*                             command_queue_object_info,
                                        UINT                                      num_command_lists,
                                        HandlePointerDecoder<ID3D12CommandList*>* command_lists_decoder,
                                        bool                                      needs_mapping);

    void PostProcessCommandListReset(DxObjectInfo* command_list_object_info);

    void PostProcessCopyResource(DxObjectInfo* command_list_object_info,
                                 DxObjectInfo* dst_resource_object_info,
                                 DxObjectInfo* src_resource_object_info);

    void PostProcessCopyBufferRegion(DxObjectInfo* command_list_object_info,
                                     DxObjectInfo* dst_buffer_object_info,
                                     UINT64        dst_offset,
                                     DxObjectInfo* src_buffer_object_info,
                                     UINT64        src_offset,
                                     UINT64        num_bytes);

    void PostProcessCreateCommandSignature(HandlePointerDecoder<void*>*        command_signature_decoder,
                                           const D3D12_COMMAND_SIGNATURE_DESC* desc);

    void PostProcessExecuteIndirect(DxObjectInfo* command_list_object_info,
                                    DxObjectInfo* command_signature_object_info,
                                    UINT          max_command_count,
                                    DxObjectInfo* argument_buffer_object_info,
                                    UINT64        argument_buffer_offset,
                                    DxObjectInfo* count_buffer_object_info,
                                    UINT64        count_buffer_offset);

    void PostProcessBuildRaytracingAccelerationStructure(
        DxObjectInfo*                                                                     command_list4_object_info,
        StructPointerDecoder<Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC>* desc);

    void PostProcessCreateRootSignature(PointerDecoder<uint8_t>*     blob_with_root_signature_decoder,
                                        SIZE_T                       blob_length_in_bytes,
                                        HandlePointerDecoder<void*>* root_signature_decoder);

    void PostProcessCreateStateObject(HandlePointerDecoder<void*>*                           state_object_decoder,
                                      StructPointerDecoder<Decoded_D3D12_STATE_OBJECT_DESC>* desc_decoder,
                                      const std::map<std::wstring, format::HandleId>&        in_lrs_associations_map);

    void PostProcessDispatchRays(DxObjectInfo*                                           command_list4_object_info,
                                 StructPointerDecoder<Decoded_D3D12_DISPATCH_RAYS_DESC>* desc_decoder);

    void PostProcessSetPipelineState1(DxObjectInfo* command_list4_object_info, DxObjectInfo* state_object_object_info);

    void PostProcessFillMemoryCommand(uint64_t resource_id, uint64_t offset, uint64_t size, const uint8_t* data);

    void PostProcessInitSubresourceCommand(ID3D12Resource*                             resource,
                                           const format::InitSubresourceCommandHeader& command_header,
                                           const uint8_t*                              data);

    void PostProcessCopyTextureRegion(DxObjectInfo* command_list_object_info,
                                      StructPointerDecoder<Decoded_D3D12_TEXTURE_COPY_LOCATION>* dst_decoder,
                                      UINT                                                       dst_x,
                                      UINT                                                       dst_y,
                                      UINT                                                       dst_z,
                                      StructPointerDecoder<Decoded_D3D12_TEXTURE_COPY_LOCATION>* src_decoder,
                                      StructPointerDecoder<Decoded_D3D12_BOX>*                   src_box_decoder);

    void PostProcessIASetIndexBuffer(DxObjectInfo*                                          command_list_object_info,
                                     StructPointerDecoder<Decoded_D3D12_INDEX_BUFFER_VIEW>* views_decoder);

    void PostProcessIASetVertexBuffers(DxObjectInfo*                                           command_list_object_info,
                                       UINT                                                    start_slot,
                                       UINT                                                    num_views,
                                       StructPointerDecoder<Decoded_D3D12_VERTEX_BUFFER_VIEW>* views_decoder);

    void AddResourceGpuVa(format::HandleId          resource_id,
                          D3D12_GPU_VIRTUAL_ADDRESS replay_address,
                          UINT64                    width,
                          D3D12_GPU_VIRTUAL_ADDRESS capture_address);

    void RemoveResourceGpuVa(format::HandleId resource_id, uint64_t replay_address, uint64_t capture_address);

    void AddGpuDescriptorHeap(const D3D12_GPU_DESCRIPTOR_HANDLE&     capture_gpu_start,
                              const D3D12_GPU_DESCRIPTOR_HANDLE&     replay_gpu_start,
                              D3D12_DESCRIPTOR_HEAP_TYPE             heap_info_descriptor_type,
                              uint32_t                               heap_info_descriptor_count,
                              std::shared_ptr<DescriptorIncrements>& heap_info_capture_increments,
                              std::shared_ptr<DescriptorIncrements>& heap_info_replay_increments);

    void RemoveGpuDescriptorHeap(uint64_t capture_gpu_start);

    bool PerformedRvMapping() { return performed_rv_mapping_; };

  private:
    struct ProcessResourceMappingsArgs
    {
        ID3D12Fence*                  fence{ nullptr };
        uint64_t                      fence_value{ 0 };
        HANDLE                        fence_event{ nullptr };
        std::vector<ResourceCopyInfo> resource_copies;
        ResourceValueInfoMap          resource_value_info_map;
    };

    struct MappedResourceRevertInfo
    {
        std::vector<uint8_t>                               data;
        std::vector<graphics::dx12::ResourceStateInfo>     states;
        std::map<uint64_t, uint64_t>                       mapped_gpu_addresses;
        std::map<uint64_t, graphics::Dx12ShaderIdentifier> mapped_shader_ids;
    };

    static void CopyResourceValues(const ResourceCopyInfo& copy_info, ResourceValueInfoMap& resource_value_info_map);

    static void CopyMappedResourceValues(const ResourceCopyInfo& copy_info);

    void ProcessResourceMappings(ProcessResourceMappingsArgs args);

    void SourceCopyResources(std::vector<ResourceCopyInfo>& copy_infos, ResourceValueInfoMap& resource_value_info_map);

    bool MapValue(const ResourceValueInfo& value_info,
                  std::vector<uint8_t>&    result_data,
                  format::HandleId         resource_id,
                  D3D12ResourceInfo*       resource_info,
                  ResourceValueInfoMap&    indirect_values_map,
                  uint64_t                 base_offset = 0);

    bool IsNonEmptyShaderRecord(const std::vector<uint8_t>& data, uint64_t offset, uint64_t size);

    void MapResources(const ResourceValueInfoMap&                        resource_value_info_map,
                      std::map<DxObjectInfo*, MappedResourceRevertInfo>& resource_data_to_revert,
                      ResourceValueInfoMap&                              indirect_values_map);

    void InitializeRequiredObjects(ID3D12CommandQueue* command_queue, D3D12CommandQueueInfo* command_queue_extra_info);

    void GetShaderTableResourceValues(ResourceValueInfoMap&     resource_value_info_map,
                                      D3D12StateObjectInfo*     state_object_extra_info,
                                      D3D12_GPU_VIRTUAL_ADDRESS start_address,
                                      UINT64                    size,
                                      UINT64                    stride);

    void GetDispatchRaysResourceValues(ResourceValueInfoMap&           resource_value_info_map,
                                       D3D12StateObjectInfo*           state_object_extra_info,
                                       const D3D12_DISPATCH_RAYS_DESC& desc);

    void GetExecuteIndirectResourceValues(std::set<ResourceValueInfo>& dst_resource_value_info_map,
                                          std::set<ResourceValueInfo>& command_signature_resource_value_info_map,
                                          uint32_t                     command_count,
                                          uint64_t                     command_offset,
                                          uint8_t                      stride,
                                          D3D12StateObjectInfo*        state_object);

    // Parse the D3D12_STATE_OBJECT_DESC for LRS association information.
    void GetStateObjectLrsAssociationInfo(
        format::HandleId                                       state_object_id,
        StructPointerDecoder<Decoded_D3D12_STATE_OBJECT_DESC>* desc_decoder,
        std::set<std::wstring>&                                export_names,
        std::vector<format::HandleId>&                         local_root_signature_ids,
        format::HandleId&                                      explicit_default_local_root_signature_id,
        std::map<std::wstring, format::HandleId>&              explicit_local_root_signature_associations,
        std::map<std::wstring, std::set<std::wstring>>&        hit_group_imports,
        std::map<std::wstring, format::HandleId>&              lrs_associations_map);

    QueueSyncEventInfo CreateProcessProcessResourceMappingsSyncEvent(ProcessResourceMappingsArgs args);

  private:
    std::function<DxObjectInfo*(format::HandleId id)> get_object_info_func_;

    graphics::Dx12GpuVaMap           reverse_gpu_va_map_; ///< Used to lookup a resource ID from a replay GPU VA.
    const graphics::Dx12ShaderIdMap& shader_id_map_;

    std::unique_ptr<graphics::Dx12ResourceDataUtil> resource_data_util_;
    std::unique_ptr<Dx12ResourceValueTracker>       resource_value_tracker_;
    bool                                            performed_rv_mapping_{ false };

    const graphics::Dx12GpuVaMap&    gpu_va_map_;
    const decode::Dx12DescriptorMap& descriptor_map_;

    bool do_value_mapping_;

    // Temporary vectors to reduce allocations.
    std::vector<uint8_t>                           temp_resource_data;
    std::vector<uint64_t>                          temp_resource_sizes;
    std::vector<uint64_t>                          temp_resource_offsets;
    std::vector<graphics::dx12::ResourceStateInfo> temp_resource_states;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_DX12_RESOURCE_MAPPING_UTIL_H
