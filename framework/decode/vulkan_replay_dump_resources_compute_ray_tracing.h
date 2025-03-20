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
#include "format/format.h"
#include "util/defines.h"
#include "util/logging.h"
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
    DispatchTraceRaysDumpingContext(const std::vector<uint64_t>& dispatch_indices,
                                    const std::vector<uint64_t>& trace_rays_indices,
                                    CommonObjectInfoTable&       object_info_table,
                                    const VulkanReplayOptions&   options,
                                    VulkanDumpResourcesDelegate& delegate);

    ~DispatchTraceRaysDumpingContext();

    VkResult CloneCommandBuffer(VulkanCommandBufferInfo*           orig_cmd_buf_info,
                                const encode::VulkanDeviceTable*   dev_table,
                                const encode::VulkanInstanceTable* inst_table);

    VkCommandBuffer GetDispatchRaysCommandBuffer() const { return DR_command_buffer; }

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

    void SnapshotDispatchState(uint64_t index);

    void SnapshotTraceRaysState(uint64_t index);

    void BindPipeline(VkPipelineBindPoint bind_point, const VulkanPipelineInfo* pipeline);

    void EndCommandBuffer();

    void Release();

  private:
    void CopyImageResource(const VulkanImageInfo* src_image_info, VkImage dst_image);

    void CopyBufferResource(const VulkanBufferInfo* src_buffer_info,
                            VkDeviceSize            offset,
                            VkDeviceSize            range,
                            VkBuffer                dst_buffer);

    void DestroyMutableResourcesClones();

    void ReleaseIndirectParams();

    VkResult FetchIndirectParams();

    VkResult DumpImmutableDescriptors(uint64_t qs_index, uint64_t bcb_index, uint64_t cmd_index, bool is_dispatch);

    const VulkanCommandBufferInfo* original_command_buffer_info;
    VkCommandBuffer                DR_command_buffer;
    std::vector<uint64_t>          dispatch_indices;
    std::vector<uint64_t>          trace_rays_indices;
    bool                           dump_resources_before;
    VulkanDumpResourcesDelegate&   delegate_;
    bool                           dump_immutable_resources;

    // One entry per descriptor set for each compute and ray tracing binding points
    std::unordered_map<uint32_t, VulkanDescriptorSetInfo> bound_descriptor_sets_compute;
    std::unordered_map<uint32_t, VulkanDescriptorSetInfo> bound_descriptor_sets_ray_tracing;

    const VulkanPipelineInfo* bound_pipeline_compute;
    const VulkanPipelineInfo* bound_pipeline_trace_rays;

  public:
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
            VkShaderStageFlags     stages;
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
            VkShaderStageFlags      stages;
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

    static bool IsDispatchIndirect(DispatchTypes type)
    {
        switch (type)
        {
            case kDispatch:
            case kDispatchBase:
                return false;

            case kDispatchIndirect:
                return true;

            default:
                GFXRECON_LOG_ERROR("%s() Unrecognized dispatch call type (%u)", __func__, static_cast<uint32_t>(type))
                GFXRECON_ASSERT(0);
                return false;
        }
    }

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

        std::unordered_map<uint32_t, VulkanDescriptorSetInfo::VulkanDescriptorBindingsInfo> referenced_descriptors;

        // Keep copies of all mutable resources that are changed by the dumped commands/shaders
        MutableResourcesBackupContext mutable_resources_clones;
        MutableResourcesBackupContext mutable_resources_clones_before;
    };

  private:
    VkResult CloneMutableResources(MutableResourcesBackupContext& backup_context, bool is_dispatch);

    void SnapshotDispatchState(DispatchParameters& disp_params);

    void SnapshotTraceRaysState(TraceRaysParameters& tr_params);

    VkResult CopyDispatchIndirectParameters(DispatchParameters& disp_params);

    VkResult CopyTraceRaysIndirectParameters(TraceRaysParameters& tr_params);

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
    bool                                    reached_end_command_buffer;
};

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)

#endif /* GFXRECON_GENERATED_VULKAN_REPLAY_DUMP_RESOURCES_COMPUTE_RAY_TRACING_H */
