/*
** Copyright (c) 2024 LunarG, Inc.
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

#ifndef GFXRECON_GENERATED_VULKAN_REPLAY_DUMP_RESOURCES_COMPUTE_RAY_TRACING_H
#define GFXRECON_GENERATED_VULKAN_REPLAY_DUMP_RESOURCES_COMPUTE_RAY_TRACING_H

#include "decode/vulkan_replay_dump_resources_common.h"
#include "decode/vulkan_object_info.h"
#include "decode/vulkan_object_info_table.h"
#include "decode/vulkan_replay_options.h"
#include "generated/generated_vulkan_dispatch_table.h"
#include "decode/vulkan_replay_dump_resources_json.h"
#include "format/format.h"
#include "util/defines.h"

#include <cstdint>
#include <unordered_map>
#include <utility>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

// This class handles the context related to dumping Dispatch and TraceRays resouces
class DispatchTraceRaysDumpingContext
{
  public:
    DispatchTraceRaysDumpingContext(const std::vector<uint64_t>&   dispatch_indices,
                                    const std::vector<uint64_t>&   trace_rays_indices,
                                    VulkanObjectInfoTable&         object_info_table,
                                    const VulkanReplayOptions&     options,
                                    VulkanReplayDumpResourcesJson& dump_json);

    ~DispatchTraceRaysDumpingContext();

    VkResult CloneCommandBuffer(CommandBufferInfo*           orig_cmd_buf_info,
                                const encode::VulkanDeviceTable*   dev_table,
                                const encode::VulkanInstanceTable* inst_table);

    VkCommandBuffer GetDispatchRaysCommandBuffer() const { return DR_command_buffer; }

    void BindPipeline(VkPipelineBindPoint bind_point, const PipelineInfo* pipeline);

    bool IsRecording() const;

    bool MustDumpDispatch(uint64_t index) const;

    bool MustDumpTraceRays(uint64_t index) const;

    void BindDescriptorSets(VkPipelineBindPoint                          pipeline_bind_point,
                            uint32_t                                     first_set,
                            const std::vector<const DescriptorSetInfo*>& descriptor_sets_infos,
                            uint32_t                                     dynamicOffsetCount,
                            const uint32_t*                              pDynamicOffsets);

    VkResult DumpDispatchTraceRays(
        VkQueue queue, uint64_t qs_index, uint64_t bcb_index, const VkSubmitInfo& submit_info, VkFence fence);

    VkResult DumpMutableResources(uint64_t bcb_index, uint64_t index, uint64_t qs_index, bool is_dispatch);

    void FinalizeCommandBuffer(bool is_dispatch);

    void InsertNewDispatchParameters(uint64_t index, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ);

    void InsertNewDispatchParameters(uint64_t index, const BufferInfo* buffer_info, VkDeviceSize offset);

    void InsertNewTraceRaysParameters(uint64_t                               index,
                                      const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
                                      const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable,
                                      const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable,
                                      const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable,
                                      uint32_t                               width,
                                      uint32_t                               height,
                                      uint32_t                               depth);

    VkResult CloneDispatchMutableResources(uint64_t index, bool cloning_before_cmd);

    VkResult CloneTraceRaysMutableResources(uint64_t index, bool cloning_before_cmd);

    void SnapshotBoundDescriptorsDispatch(uint64_t index);

    void SnapshotBoundDescriptorsTraceRays(uint64_t index);

    VkResult CopyDispatchIndirectParameters(uint64_t index);

  private:
    std::vector<std::string> GenerateDispatchTraceRaysImageFilename(VkFormat              format,
                                                                    uint32_t              levels,
                                                                    uint32_t              layers,
                                                                    bool                  is_dispatch,
                                                                    uint64_t              index,
                                                                    uint32_t              desc_set,
                                                                    uint32_t              desc_binding,
                                                                    VkShaderStageFlagBits stage,
                                                                    bool                  before_cmd,
                                                                    bool                  dump_all_subresources) const;

    std::string GenerateDispatchTraceRaysBufferFilename(bool                  is_dispatch,
                                                        uint64_t              index,
                                                        uint32_t              desc_set,
                                                        uint32_t              desc_binding,
                                                        VkShaderStageFlagBits stage,
                                                        bool                  before_cmd) const;

    void CopyImageResource(const ImageInfo* src_image_info, VkImage dst_image);

    void CopyBufferResource(const BufferInfo* src_buffer_info, VkBuffer dst_buffer);

    void DestroyMutableResourcesClones();

    VkResult FetchIndirectParams();

    std::vector<std::string> GenerateImageDescriptorFilename(const ImageInfo* img_info) const;

    std::string GenerateBufferDescriptorFilename(format::HandleId buffer_id) const;

    VkResult DumpImmutableResources(uint64_t qs_index, uint64_t bcb_index) const;

    void GenerateOutputJson(uint64_t qs_index, uint64_t bcb_index) const;

    const CommandBufferInfo*       original_command_buffer_info;
    VkCommandBuffer                DR_command_buffer;
    std::vector<uint64_t>          dispatch_indices;
    std::vector<uint64_t>          trace_rays_indices;
    const PipelineInfo*            bound_pipelines[kBindPoint_count];
    bool                           dump_resources_before;
    const std::string&             dump_resource_path;
    util::ScreenshotFormat         image_file_format;
    float                          dump_resources_scale;
    VulkanReplayDumpResourcesJson& dump_json;
    bool                           output_json_per_command;
    bool                           dump_immutable_resources;
    bool                           dump_all_image_subresources;

    // One entry per descriptor set for each compute and ray tracing binding points
    std::unordered_map<uint32_t, DescriptorSetInfo> bound_descriptor_sets_compute;
    std::unordered_map<uint32_t, DescriptorSetInfo> bound_descriptor_sets_ray_tracing;

    // For each Dispatch/TraceRays that we dump we create a clone of all mutable resources used in the
    // shaders/pipeline and the content of the original resources are copied into the clones
    struct MutableResourcesBackupContext
    {
        MutableResourcesBackupContext() = default;

        std::vector<const ImageInfo*>              original_images;
        std::vector<VkImage>                       images;
        std::vector<VkDeviceMemory>                image_memories;
        std::vector<std::pair<uint32_t, uint32_t>> image_desc_set_binding_pair;
        std::vector<VkShaderStageFlagBits>         image_shader_stage;

        std::vector<const BufferInfo*>             original_buffers;
        std::vector<VkBuffer>                      buffers;
        std::vector<VkDeviceMemory>                buffer_memories;
        std::vector<std::pair<uint32_t, uint32_t>> buffer_desc_set_binding_pair;
        std::vector<VkShaderStageFlagBits>         buffer_shader_stage;
    };

    enum DispatchTypes
    {
        kDispatch,
        kDispatchIndirect,
        kDispatchBase
    };

    struct DispatchParameters
    {
        union DispatchParamsUnion
        {
            struct DispatchParams
            {
                uint32_t groupCountX;
                uint32_t groupCountY;
                uint32_t groupCountZ;
            };

            DispatchParams dispatch;

            struct DispatchBaseParams
            {
                uint32_t baseGroupX;
                uint32_t baseGroupY;
                uint32_t baseGroupZ;
                uint32_t groupCountX;
                uint32_t groupCountY;
                uint32_t groupCountZ;
            };

            DispatchBaseParams dispatch_base;

            struct DispatchIndirect
            {
                const BufferInfo* params_buffer_info;
                VkDeviceSize      params_buffer_offset;

                VkBuffer       new_params_buffer;
                VkDeviceMemory new_params_memory;

                // Pointers that will point to host allocated memory and filled with the dispatch
                // params read back after executing on the gpu. Because of the union a data
                // structure with a non default destructor (vector/unique_ptr) cannot be used
                // and we will handle the memory managment ourselves.
                DispatchParams* dispatch_params;
            };

            DispatchIndirect dispatch_indirect;

            DispatchParamsUnion(uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) :
                dispatch{ groupCountX, groupCountY, groupCountZ }
            {}

            DispatchParamsUnion(const BufferInfo* params_buffer_info, VkDeviceSize offset) :
                dispatch_indirect{ params_buffer_info, offset, VK_NULL_HANDLE, VK_NULL_HANDLE, nullptr }
            {}

            DispatchParamsUnion(uint32_t baseGroupX,
                                uint32_t baseGroupY,
                                uint32_t baseGroupZ,
                                uint32_t groupCountX,
                                uint32_t groupCountY,
                                uint32_t groupCountZ) :
                dispatch_base{ baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ }
            {}
        } dispatch_params_union;

        DispatchParameters(DispatchTypes type, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) :
            dispatch_params_union{ groupCountX, groupCountY, groupCountZ }, type(type)
        {
            assert(type == kDispatch);
        }

        DispatchParameters(DispatchTypes type, const BufferInfo* params_buffer_info, VkDeviceSize offset) :
            dispatch_params_union{ params_buffer_info, offset }, type(type)
        {
            assert(type == kDispatchIndirect);
        }

        DispatchParameters(DispatchTypes type,
                           uint32_t      baseGroupX,
                           uint32_t      baseGroupY,
                           uint32_t      baseGroupZ,
                           uint32_t      groupCountX,
                           uint32_t      groupCountY,
                           uint32_t      groupCountZ) :
            dispatch_params_union{ baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ },
            type(type)
        {
            assert(type == kDispatchBase);
        }

        DispatchTypes type;

        std::unordered_map<uint32_t, DescriptorSetInfo::DescriptorBindingsInfo> referenced_descriptors;

        MutableResourcesBackupContext mutable_resources_clones;
        MutableResourcesBackupContext mutable_resources_clones_before;
    };

    enum TraceRaysTypes
    {
        kTraceRays,
        kTraceRaysIndirect
    };

    struct TraceRaysParameters
    {
        union TraceRaysParamsUnion
        {
            struct TraceRaysParams
            {
                uint32_t width;
                uint32_t height;
                uint32_t depth;
            };

            TraceRaysParams trace_rays;

            struct TraceRaysIndirect
            {
                const BufferInfo* params_buffer_info;
                VkDeviceSize      params_buffer_offset;

                TraceRaysParams trace_rays_params;
            };

            TraceRaysIndirect trace_rays_indirect;

            TraceRaysParamsUnion(uint32_t width, uint32_t height, uint32_t depth) : trace_rays{ width, height, depth }
            {}

            TraceRaysParamsUnion(const BufferInfo* params_buffer_info, VkDeviceSize params_buffer_offset) :
                trace_rays_indirect{ params_buffer_info, params_buffer_offset }
            {}
        } trace_rays_params_union;

        TraceRaysParameters(TraceRaysTypes                         type,
                            const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
                            const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable,
                            const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable,
                            const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable,
                            uint32_t                               width,
                            uint32_t                               height,
                            uint32_t                               depth) :
            trace_rays_params_union(width, height, depth),
            type(type), pRaygenShaderBindingTable(pRaygenShaderBindingTable),
            pMissShaderBindingTable(pMissShaderBindingTable), pHitShaderBindingTable(pHitShaderBindingTable),
            pCallableShaderBindingTable(pCallableShaderBindingTable)
        {
            assert(type == kTraceRays);
        }

        TraceRaysTypes                         type;
        const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable;
        const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable;
        const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable;
        const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable;

        std::unordered_map<VkShaderStageFlagBits,
                           std::unordered_map<uint32_t, DescriptorSetInfo::DescriptorBindingsInfo>>
            referenced_descriptors;

        // Keep copies of all mutable resources that are changed by the dumped commands/shaders
        MutableResourcesBackupContext mutable_resources_clones;
        MutableResourcesBackupContext mutable_resources_clones_before;
    };

    VkResult CloneMutableResources(MutableResourcesBackupContext& backup_context, bool is_dispatch);

    void SnapshotBoundDescriptors(DispatchParameters& disp_params);

    void SnapshotBoundDescriptors(TraceRaysParameters& tr_params);

    // One entry for each dispatch command
    std::unordered_map<uint64_t, DispatchParameters> dispatch_params;

    // One entry for each trace rays command
    std::unordered_map<uint64_t, TraceRaysParameters> trace_rays_params;

    const encode::VulkanDeviceTable*              device_table;
    const encode::VulkanInstanceTable*            instance_table;
    VulkanObjectInfoTable&                  object_info_table;
    const VkPhysicalDeviceMemoryProperties* replay_device_phys_mem_props;
    size_t                                  current_dispatch_index;
    size_t                                  current_trace_rays_index;
};

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)

#endif /* GFXRECON_GENERATED_VULKAN_REPLAY_DUMP_RESOURCES_COMPUTE_RAY_TRACING_H */
