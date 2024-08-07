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

#include "decode/common_object_info_table.h"
#include "decode/vulkan_replay_dump_resources_common.h"
#include "decode/vulkan_object_info.h"
#include "decode/vulkan_replay_options.h"
#include "generated/generated_vulkan_dispatch_table.h"
#include "decode/vulkan_replay_dump_resources_json.h"
#include "format/format.h"
#include "util/defines.h"
#include "vulkan/vulkan_core.h"

#include <cstdint>
#include <unordered_map>
#include <unordered_set>
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
                                    CommonObjectInfoTable&         object_info_table,
                                    const VulkanReplayOptions&     options,
                                    VulkanReplayDumpResourcesJson& dump_json,
                                    std::string                    capture_filename);

    ~DispatchTraceRaysDumpingContext();

    VkResult CloneCommandBuffer(VulkanCommandBufferInfo*           orig_cmd_buf_info,
                                const encode::VulkanDeviceTable*   dev_table,
                                const encode::VulkanInstanceTable* inst_table);

    VkCommandBuffer GetDispatchRaysCommandBuffer() const { return DR_command_buffer; }

    void BindPipeline(VkPipelineBindPoint bind_point, const VulkanPipelineInfo* pipeline);

    bool IsRecording() const;

    bool MustDumpDispatch(uint64_t index) const;

    bool MustDumpTraceRays(uint64_t index) const;

    void BindDescriptorSets(VkPipelineBindPoint                                pipeline_bind_point,
                            uint32_t                                           first_set,
                            const std::vector<const VulkanDescriptorSetInfo*>& descriptor_sets_infos,
                            uint32_t                                           dynamicOffsetCount,
                            const uint32_t*                                    pDynamicOffsets);

    VkResult DumpDispatchTraceRays(
        VkQueue queue, uint64_t qs_index, uint64_t bcb_index, const VkSubmitInfo& submit_info, VkFence fence);

    VkResult DumpMutableResources(uint64_t bcb_index, uint64_t qs_index, uint64_t cmd_index, bool is_dispatch);

    void FinalizeCommandBuffer(bool is_dispatch);

    void InsertNewDispatchParameters(uint64_t index, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ);

    void InsertNewDispatchParameters(uint64_t index, const VulkanBufferInfo* buffer_info, VkDeviceSize offset);

    void InsertNewTraceRaysParameters(uint64_t                               index,
                                      const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
                                      const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable,
                                      const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable,
                                      const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable,
                                      uint32_t                               width,
                                      uint32_t                               height,
                                      uint32_t                               depth);

    void InsertNewTraceRaysIndirectParameters(uint64_t                               index,
                                              const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
                                              const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable,
                                              const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable,
                                              const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable,
                                              VkDeviceAddress                        indirectDeviceAddress);

    void InsertNewTraceRaysIndirect2Parameters(uint64_t index, VkDeviceAddress indirectDeviceAddress);

    VkResult CloneDispatchMutableResources(uint64_t index, bool cloning_before_cmd);

    VkResult CloneTraceRaysMutableResources(uint64_t index, bool cloning_before_cmd);

    void SnapshotBoundDescriptorsDispatch(uint64_t index);

    void SnapshotBoundDescriptorsTraceRays(uint64_t index);

    VkResult CopyDispatchIndirectParameters(uint64_t index);

    VkResult CopyTraceRaysIndirectParameters(uint64_t index);

    void Release();

  private:
    std::vector<std::string> GenerateDispatchTraceRaysImageFilename(VkFormat              format,
                                                                    uint32_t              levels,
                                                                    uint32_t              layers,
                                                                    bool                  is_dispatch,
                                                                    uint64_t              qs_index,
                                                                    uint64_t              bcb_index,
                                                                    uint64_t              cmd_index,
                                                                    uint32_t              desc_set,
                                                                    uint32_t              desc_binding,
                                                                    uint32_t              array_index,
                                                                    VkShaderStageFlagBits stage,
                                                                    bool                  before_cmd,
                                                                    bool                  dump_all_subresources) const;

    std::string GenerateDispatchTraceRaysBufferFilename(bool                  is_dispatch,
                                                        uint64_t              qs_index,
                                                        uint64_t              bcb_index,
                                                        uint64_t              cmd_index,
                                                        uint32_t              desc_set,
                                                        uint32_t              desc_binding,
                                                        uint32_t              array_index,
                                                        VkShaderStageFlagBits stage,
                                                        bool                  before_cmd) const;

    std::vector<std::string>
    GenerateImageDescriptorFilename(uint64_t bcb_index, uint64_t cmd_index, const VulkanImageInfo* img_info) const;

    std::string
    GenerateBufferDescriptorFilename(uint64_t bcb_index, uint64_t cmd_index, format::HandleId buffer_id) const;

    std::string GenerateInlineUniformBufferDescriptorFilename(uint64_t bcb_index,
                                                              uint64_t cmd_index,
                                                              uint32_t set,
                                                              uint32_t binding) const;

    void CopyImageResource(const VulkanImageInfo* src_image_info, VkImage dst_image);

    void CopyBufferResource(const VulkanBufferInfo* src_buffer_info,
                            VkDeviceSize            offset,
                            VkDeviceSize            range,
                            VkBuffer                dst_buffer);

    void DestroyMutableResourcesClones();

    void ReleaseIndirectParams();

    VkResult FetchIndirectParams();

    VkResult DumpImmutableDescriptors(uint64_t qs_index, uint64_t bcb_index, uint64_t cmd_index, bool is_dispatch);

    void GenerateOutputJsonDispatchInfo(uint64_t qs_index,
                                        uint64_t bcb_index,
                                        uint64_t disp_index,
                                        uint64_t cmd_index) const;

    void GenerateOutputJsonTraceRaysIndex(uint64_t qs_index,
                                          uint64_t bcb_index,
                                          uint64_t tr_index,
                                          uint64_t cmd_index) const;

    const VulkanCommandBufferInfo* original_command_buffer_info;
    VkCommandBuffer                DR_command_buffer;
    std::vector<uint64_t>          dispatch_indices;
    std::vector<uint64_t>          trace_rays_indices;
    const VulkanPipelineInfo*      bound_pipelines[kBindPoint_count];
    bool                           dump_resources_before;
    const std::string&             dump_resource_path;
    util::ScreenshotFormat         image_file_format;
    float                          dump_resources_scale;
    VulkanReplayDumpResourcesJson& dump_json;
    bool                           output_json_per_command;
    bool                           dump_immutable_resources;
    bool                           dump_all_image_subresources;

    // One entry per descriptor set for each compute and ray tracing binding points
    std::unordered_map<uint32_t, VulkanDescriptorSetInfo> bound_descriptor_sets_compute;
    std::unordered_map<uint32_t, VulkanDescriptorSetInfo> bound_descriptor_sets_ray_tracing;

    // For each Dispatch/TraceRays that we dump we create a clone of all mutable resources used in the
    // shaders/pipeline and the content of the original resources are copied into the clones
    struct MutableResourcesBackupContext
    {
        MutableResourcesBackupContext() = default;

        struct ImageContext
        {
            const VulkanImageInfo* original_image{ nullptr };
            VkImage                image{ VK_NULL_HANDLE };
            VkDeviceMemory         image_memory{ VK_NULL_HANDLE };
            VkShaderStageFlagBits  stage;
            VkDescriptorType       desc_type;
            uint32_t               desc_set;
            uint32_t               desc_binding;
            uint32_t               array_index;
        };

        std::vector<ImageContext> images;

        struct BufferContext
        {
            const VulkanBufferInfo* original_buffer{ nullptr };
            VkBuffer                buffer{ VK_NULL_HANDLE };
            VkDeviceMemory          buffer_memory{ VK_NULL_HANDLE };
            VkShaderStageFlagBits   stage;
            VkDescriptorType        desc_type;
            uint32_t                desc_set;
            uint32_t                desc_binding;
            uint32_t                array_index;
        };

        std::vector<BufferContext> buffers;
    };

    enum DispatchTypes
    {
        kDispatch,
        kDispatchIndirect,
        kDispatchBase
    };

    static const char* DispatchTypeToStr(DispatchTypes type)
    {
        switch (type)
        {
            case kDispatch:
                return "vkCmdDispatch";
            case kDispatchIndirect:
                return "vkCmdDispatchIndirect";
            case kDispatchBase:
                return "vkCmdDispatchBase";
            default:
                assert(0);
                return "UnrecognizedDispatchCommand";
        }
    }

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
                const VulkanBufferInfo* params_buffer_info;
                VkDeviceSize            params_buffer_offset;

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

            DispatchParamsUnion(const VulkanBufferInfo* params_buffer_info, VkDeviceSize offset) :
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

        DispatchParameters(DispatchTypes type, const VulkanBufferInfo* params_buffer_info, VkDeviceSize offset) :
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

        std::unordered_map<uint32_t, VulkanDescriptorSetInfo::VulkanDescriptorBindingsInfo> referenced_descriptors;

        MutableResourcesBackupContext mutable_resources_clones;
        MutableResourcesBackupContext mutable_resources_clones_before;
    };

    enum TraceRaysTypes
    {
        kTraceRays,
        kTraceRaysIndirect,
        kTraceRaysIndirect2
    };

    static const char* TraceRaysTypeToStr(TraceRaysTypes type)
    {
        switch (type)
        {
            case kTraceRays:
                return "vkCmdTraceRays";
            case kTraceRaysIndirect:
                return "vkCmdTraceRaysIndirectKHR";
            case kTraceRaysIndirect2:
                return "vkCmdTraceRaysIndirect2KHR";
            default:
                assert(0);
                return "UnrecognizedTraceRaysCommand";
        }
    }

    struct TraceRaysParameters
    {
        union TraceRaysParamsUnion
        {
            VkTraceRaysIndirectCommandKHR trace_rays;

            struct TraceRaysIndirect
            {
                VkDeviceAddress indirect_device_address;

                VkBuffer       buffer_on_device_address;
                VkDeviceMemory buffer_on_device_address_memory;

                VkBuffer       new_params_buffer;
                VkDeviceMemory new_params_buffer_memory;

                VkTraceRaysIndirectCommandKHR trace_rays_params;
            };

            TraceRaysIndirect trace_rays_indirect;

            struct TraceRaysIndirect2
            {
                VkDeviceAddress indirect_device_address;

                VkBuffer       buffer_on_device_address;
                VkDeviceMemory buffer_on_device_address_memory;

                VkBuffer       new_params_buffer;
                VkDeviceMemory new_params_buffer_memory;

                VkTraceRaysIndirectCommand2KHR trace_rays_params;
            };

            TraceRaysIndirect2 trace_rays_indirect2;

            TraceRaysParamsUnion(uint32_t width, uint32_t height, uint32_t depth) : trace_rays{ width, height, depth }
            {}

            TraceRaysParamsUnion(VkDeviceAddress indirect_device_address) :
                trace_rays_indirect{ indirect_device_address, VK_NULL_HANDLE, VK_NULL_HANDLE,
                                     VK_NULL_HANDLE,          VK_NULL_HANDLE, { 0 } }
            {}
        } trace_rays_params_union;

        TraceRaysParameters(TraceRaysTypes type, uint32_t width, uint32_t height, uint32_t depth) :
            type(type), trace_rays_params_union(width, height, depth)
        {
            assert(type == kTraceRays);
        }

        TraceRaysParameters(TraceRaysTypes type, VkDeviceAddress indirectDeviceAddress) :
            type(type), trace_rays_params_union(indirectDeviceAddress)

        {
            assert(type == kTraceRaysIndirect);
        }

        TraceRaysTypes type;

        std::unordered_map<VkShaderStageFlagBits,
                           std::unordered_map<uint32_t, VulkanDescriptorSetInfo::VulkanDescriptorBindingsInfo>>
            referenced_descriptors;

        // Keep copies of all mutable resources that are changed by the dumped commands/shaders
        MutableResourcesBackupContext mutable_resources_clones;
        MutableResourcesBackupContext mutable_resources_clones_before;
    };

    VkResult CloneMutableResources(MutableResourcesBackupContext& backup_context, bool is_dispatch);

    void SnapshotBoundDescriptors(DispatchParameters& disp_params);

    void SnapshotBoundDescriptors(TraceRaysParameters& tr_params);

    // Gather here all descriptors referenced by commands that have already been dumped
    // in order to avoid dumping descriptors referenced from multiple shader stages,
    // multiple times
    struct DumpedDescriptors
    {
        std::unordered_set<const VulkanImageInfo*>      image_descriptors;
        std::unordered_set<const VulkanBufferInfo*>     buffer_descriptors;
        std::unordered_set<const std::vector<uint8_t>*> inline_uniform_blocks;
    };

    DumpedDescriptors dispatch_dumped_descriptors;
    DumpedDescriptors trace_rays_dumped_descriptors;

    // Keep track of images for which scalling failed so we can
    // note them in the output json
    std::unordered_set<std::string> images_failed_scaling;

    bool ImageFailedScaling(const std::string& filename) const { return images_failed_scaling.count(filename); }

    // One entry for each dispatch command
    std::unordered_map<uint64_t, DispatchParameters> dispatch_params;

    // One entry for each trace rays command
    std::unordered_map<uint64_t, TraceRaysParameters> trace_rays_params;

    const encode::VulkanDeviceTable*        device_table;
    VkDevice                                parent_device;
    const encode::VulkanInstanceTable*      instance_table;
    CommonObjectInfoTable&                  object_info_table;
    const VkPhysicalDeviceMemoryProperties* replay_device_phys_mem_props;
    size_t                                  current_dispatch_index;
    size_t                                  current_trace_rays_index;
    std::string                             capture_filename;
};

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)

#endif /* GFXRECON_GENERATED_VULKAN_REPLAY_DUMP_RESOURCES_COMPUTE_RAY_TRACING_H */
