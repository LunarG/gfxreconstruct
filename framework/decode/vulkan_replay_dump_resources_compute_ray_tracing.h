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

#include "decode/api_decoder.h"
#include "decode/common_object_info_table.h"
#include "decode/vulkan_replay_device_context.h"
#include "decode/vulkan_replay_dump_resources_as.h"
#include "decode/vulkan_replay_dump_resources_common.h"
#include "decode/vulkan_replay_dump_resources_windows.h"
#include "decode/vulkan_object_info.h"
#include "decode/vulkan_replay_options.h"
#include "format/format.h"
#include "generated/generated_vulkan_dispatch_table.h"
#include "graphics/vulkan_injected_calls.h"
#include "util/compressor.h"
#include "util/defines.h"
#include "util/logging.h"

#include <cstdint>
#include <memory>
#include <map>
#include <unordered_map>
#include <utility>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

// This class handles the context related to dumping Dispatch and TraceRays resouces.
//
// It owns the dispatch and trace rays slots of the DumpingContextWindows of its (BeginCommandBuffer, QueueSubmit)
// pair. It tracks the compute/ray tracing state while the command buffer is recorded, snapshots the descriptors
// referenced by a target command, records the command into the clone taking work and closes the window there. Once
// the windows have executed a window it dumps the command's storage descriptors straight from the original
// resources, which at that moment hold exactly the state after (or, with --dump-resources-before, before) the
// command. No descriptor is ever cloned.
class DispatchTraceRaysDumpingContext : public DumpingContextBase
{
  public:
    DispatchTraceRaysDumpingContext(std::shared_ptr<DumpingContextWindows>            windows,
                                    const CommandImageSubresource&                    disp_subresources,
                                    decode::Index                                     bcb_index,
                                    decode::Index                                     qs_index,
                                    const CommandImageSubresource&                    tr_subresources,
                                    CommonObjectInfoTable&                            object_info_table,
                                    const VulkanReplayOptions&                        options,
                                    VulkanDumpResourcesDelegate&                      delegate,
                                    const util::Compressor*                           compressor,
                                    const DumpResourcesAccelerationStructuresContext& acceleration_structures_context,
                                    const VulkanPerDeviceContexts&                    device_contexts);

    ~DispatchTraceRaysDumpingContext();

    VkResult BeginCommandBuffer(const VulkanCommandBufferInfo*             orig_cmd_buf_info,
                                const graphics::VulkanInjectedDeviceCalls& dev_table,
                                const graphics::VulkanInstanceTable*       inst_table) override;

    // This context does not record dispatch/trace rays commands: VulkanReplayDumpResourcesBase records every one of
    // them into the clone taking work. It only brackets the ones it dumps. Before*() is called right before the
    // command is recorded and AfterDispatch()/AfterTraceRays() right after; they do nothing for a command that is
    // not dumped.
    //
    // Before*(): stores the command's parameters and snapshots the bound state, then with --dump-resources-before
    //            closes the window that ends right before the command.
    // After*(): closes the window that ends with the command.
    void BeforeDispatch(uint64_t index, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ);

    void BeforeDispatchIndirect(uint64_t index, const VulkanBufferInfo* buffer_info, VkDeviceSize offset);

    void AfterDispatch(uint64_t index);

    void BeforeTraceRays(uint64_t                               index,
                         const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
                         const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable,
                         const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable,
                         const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable,
                         uint32_t                               width,
                         uint32_t                               height,
                         uint32_t                               depth);

    void BeforeTraceRaysIndirect(uint64_t                               index,
                                 const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
                                 const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable,
                                 const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable,
                                 const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable,
                                 VkDeviceAddress                        indirectDeviceAddress);

    void BeforeTraceRaysIndirect2(uint64_t index, VkDeviceAddress indirectDeviceAddress);

    void AfterTraceRays(uint64_t index);

    bool MustDumpDispatch(uint64_t index) const;

    bool MustDumpTraceRays(uint64_t index) const;

    void BindDescriptorSets(VkPipelineBindPoint                                pipeline_bind_point,
                            uint32_t                                           first_set,
                            const std::vector<const VulkanDescriptorSetInfo*>& descriptor_sets_infos,
                            uint32_t                                           dynamicOffsetCount,
                            const uint32_t*                                    pDynamicOffsets);

    void PushDescriptorSet(VkShaderStageFlags                                        stage_flags,
                           uint32_t                                                  set,
                           uint32_t                                                  descriptor_write_count,
                           const StructPointerDecoder<Decoded_VkWriteDescriptorSet>* p_descriptor_writes);

    // DumpingContextBase
    VkResult DumpSlot(const WindowSlot& slot,
                      size_t            window_index,
                      VkQueue           queue,
                      Index             submit_info_index,
                      Index             submit_info_cmd_buf_index) override;

    void ResetDumpedResources() override;

    void PrepareSecondary(DumpingContextBase& secondary_owner) override;

    void ExecuteSecondarySlot(DumpingContextBase& secondary_owner,
                              const WindowSlot&   secondary_slot,
                              Index               execute_cmd_index,
                              Index               command_buffer_execute_index) override;

    void BindPipeline(VkPipelineBindPoint bind_point, const VulkanPipelineInfo* pipeline);

    void Release();

  private:
    // Dumps the resources of one dispatch/trace rays command right after the window that ends with it executed (or,
    // with --dump-resources-before, the window that ends right before it; is_before_window tells the two apart).
    // window_index is the index of that window: it keys the identifiers of commands merged from secondaries.
    VkResult DumpCommand(Index cmd_index,
                         bool  is_trace_rays,
                         bool  is_before_window,
                         Index window_index,
                         Index submit_info_index,
                         Index submit_info_cmd_buf_index);

    // Shares the secondary's parameters of a command with this (primary) context and records under which window
    // (window_index) and which vkCmdExecuteCommands this execution of the command runs.
    void MergeSecondaryCommand(DispatchTraceRaysDumpingContext& secondary_context,
                               Index                            cmd_index,
                               bool                             is_trace_rays,
                               Index                            window_index,
                               Index                            execute_cmd_index,
                               Index                            command_buffer_execute_index);

    // The dispatch/trace rays contexts of the secondaries this context's command buffer executes
    std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> GetSecondaryContexts() const;

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

    void ReleaseIndirectParams();

    // Reads back the parameters an indirect command took from its device buffer. Called once the window that holds
    // the copy of those parameters has executed.
    VkResult ReadIndirectParams(VkBuffer params_buffer, VkDeviceSize size, void* params);

    VkResult DumpDescriptors(const DumpedResourceBase& dumped_resource_base, bool is_dispatch);

    // Dumps the storage descriptors the command references, from the original resources. With
    // --dump-resources-before it runs twice per command, first for the "before" window, which creates the entries,
    // then for the "after" window, which finds them again.
    VkResult
    DumpMutableResources(const DumpedResourceBase& dumped_resource_base, bool is_dispatch, bool before_command);

    // The clone taking work: where this context records the copies of indirect parameters
    VkCommandBuffer RecordingCommandBuffer() const;

    // With --dump-resources-before, closes the window that ends right before a dumped command
    void FinalizeBeforeWindow();

    CommandImageSubresource disp_subresources_;
    CommandImageSubresource tr_subresources_;

    // One entry per descriptor set for each compute and ray tracing binding points
    BoundDescriptorSets bound_descriptor_sets_compute_;
    BoundDescriptorSets bound_descriptor_sets_ray_tracing_;

    const VulkanPipelineInfo* bound_pipeline_compute_;
    const VulkanPipelineInfo* bound_pipeline_trace_rays_;

  public:
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

    struct DispatchParams
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

                DispatchParams fetched_dispatch_params;
            };

            DispatchIndirect dispatch_indirect;

            DispatchParamsUnion(uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) :
                dispatch{ groupCountX, groupCountY, groupCountZ }
            {}

            DispatchParamsUnion(const VulkanBufferInfo* params_buffer_info, VkDeviceSize offset) :
                dispatch_indirect{ params_buffer_info, offset, VK_NULL_HANDLE, VK_NULL_HANDLE }
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

        DispatchParams(DispatchTypes                   type,
                       DumpResourcesCommandBufferLevel lvl,
                       Index                           index,
                       uint32_t                        groupCountX,
                       uint32_t                        groupCountY,
                       uint32_t                        groupCountZ) :
            dispatch_params_union{ groupCountX, groupCountY, groupCountZ },
            type(type), updated_referenced_descriptors(false), command_index(index), command_buffer_level(lvl)
        {
            assert(type == kDispatch);
        }

        DispatchParams(DispatchTypes                   type,
                       DumpResourcesCommandBufferLevel lvl,
                       Index                           index,
                       const VulkanBufferInfo*         params_buffer_info,
                       VkDeviceSize                    offset) :
            dispatch_params_union{ params_buffer_info, offset },
            type(type), updated_referenced_descriptors(false), command_index(index), command_buffer_level(lvl)
        {
            assert(type == kDispatchIndirect);
        }

        DispatchParams(DispatchTypes                   type,
                       DumpResourcesCommandBufferLevel lvl,
                       Index                           index,
                       uint32_t                        baseGroupX,
                       uint32_t                        baseGroupY,
                       uint32_t                        baseGroupZ,
                       uint32_t                        groupCountX,
                       uint32_t                        groupCountY,
                       uint32_t                        groupCountZ) :
            dispatch_params_union{ baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ },
            type(type), updated_referenced_descriptors(false), command_index(index), command_buffer_level(lvl)
        {
            assert(type == kDispatchBase);
        }

        DispatchTypes type;

        BoundDescriptorSets referenced_descriptors;

        // Need to keep track if a dispatch context from a secondary command buffer has been updated with information
        // that might be available only from the primary command buffer
        bool updated_referenced_descriptors;

        Index command_index{ UNDEFINED_INDEX };

        // Relevant only for secondary command buffers
        DumpResourcesCommandBufferLevel command_buffer_level;

        // Store the vkCmdExecuteCommands block index and the secondary's command buffer index inside pCommandBuffers.
        // This is a map in order to support the case where the same secondary is executed multiple times either from
        // the same vkCmdExecuteCommands or when vkCmdExecuteCommands is recorded multiple times in the primary command
        // buffer. The index of the primary's window that runs the command is used as the map's key.
        std::map<Index, SecondaryIdentifiers> secondary_identifiers;

        DumpedResourcesInfo dumped_resources;
    };

    enum TraceRaysTypes
    {
        kTraceRays,
        kTraceRaysIndirect,
        kTraceRaysIndirect2
    };

    static bool IsTraceRaysIndirect(TraceRaysTypes type)
    {
        switch (type)
        {
            case kTraceRays:
                return false;

            case kTraceRaysIndirect:
            case kTraceRaysIndirect2:
                return true;

            default:
                GFXRECON_LOG_ERROR("%s() Unrecognized trace rays call type (%u)", __func__, static_cast<uint32_t>(type))
                GFXRECON_ASSERT(0);
                return false;
        }
    }

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

    struct TraceRaysParams
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

        TraceRaysParams(TraceRaysTypes                  type,
                        DumpResourcesCommandBufferLevel lvl,
                        Index                           index,
                        uint32_t                        width,
                        uint32_t                        height,
                        uint32_t                        depth) :
            type(type),
            trace_rays_params_union(width, height, depth), updated_referenced_descriptors(false), command_index(index),
            command_buffer_level(lvl)
        {
            assert(type == kTraceRays);
        }

        TraceRaysParams(TraceRaysTypes                  type,
                        DumpResourcesCommandBufferLevel lvl,
                        Index                           index,
                        VkDeviceAddress                 indirectDeviceAddress) :
            type(type),
            trace_rays_params_union(indirectDeviceAddress), updated_referenced_descriptors(false), command_index(index),
            command_buffer_level(lvl)

        {
            assert(type == kTraceRaysIndirect);
        }

        TraceRaysTypes type;

        BoundDescriptorSets referenced_descriptors;

        // Need to keep track if a trace rays context from a secondary command buffer has been updated with information
        // that might be available only from the primary command buffer
        bool updated_referenced_descriptors;

        Index command_index{ UNDEFINED_INDEX };

        // Relevant only for secondary command buffers
        DumpResourcesCommandBufferLevel command_buffer_level;

        // Store the vkCmdExecuteCommands block index and the secondary's command buffer index inside pCommandBuffers.
        // This is a map in order to support the case where the same secondary is executed multiple times either from
        // the same vkCmdExecuteCommands or when vkCmdExecuteCommands is recorded multiple times in the primary command
        // buffer. The index of the primary's window that runs the command is used as the map's key.
        std::map<Index, SecondaryIdentifiers> secondary_identifiers;

        DumpedResourcesInfo dumped_resources;
    };

  private:
    void SnapshotDispatchState(DispatchParams& disp_params);

    void SnapshotTraceRaysState(TraceRaysParams& tr_params);

    VkResult CopyDispatchIndirectParameters(DispatchParams& disp_params);

    VkResult CopyTraceRaysIndirectParameters(TraceRaysParams& tr_params);

    VkResult FetchDispatchIndirectParams(DispatchParams& disp_params);

    VkResult FetchTraceRaysIndirectParams(TraceRaysParams& tr_params);

    // Gather here all descriptors referenced by commands that have already been dumped
    // in order to avoid dumping descriptors referenced from multiple shader stages,
    // multiple times
    struct DumpedDescriptors
    {
        std::map<DescriptorLocation, DumpedImage>                 image_descriptors;
        std::map<DescriptorLocation, DumpedBuffer>                buffer_descriptors;
        std::map<DescriptorLocation, DumpedAccelerationStructure> acceleration_structures;
    };

    DumpedDescriptors dispatch_dumped_descriptors_;
    DumpedDescriptors trace_rays_dumped_descriptors_;

    void SecondaryUpdateContextFromPrimary(const BoundDescriptorSets& dispatch_descriptor_sets,
                                           const BoundDescriptorSets& tr_descriptor_sets);

    // One entry for each dispatch command
    using DispatchParameters = std::unordered_map<uint64_t, std::shared_ptr<DispatchParams>>;
    DispatchParameters dispatch_params_;

    DispatchParameters& GetDispatchParameters() { return dispatch_params_; }

    // One entry for each trace rays command
    using TraceRaysParameters = std::unordered_map<uint64_t, std::shared_ptr<TraceRaysParams>>;
    TraceRaysParameters trace_rays_params_;

    TraceRaysParameters& GetTraceRaysParameters() { return trace_rays_params_; }

    VkDevice parent_device_;
};

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)

#endif /* GFXRECON_GENERATED_VULKAN_REPLAY_DUMP_RESOURCES_COMPUTE_RAY_TRACING_H */
