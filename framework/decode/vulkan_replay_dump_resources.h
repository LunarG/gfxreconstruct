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

#ifndef GFXRECON_GENERATED_VULKAN_REPLAY_DUMP_RESOURCES_BASE_H
#define GFXRECON_GENERATED_VULKAN_REPLAY_DUMP_RESOURCES_BASE_H

#include "decode/api_decoder.h"
#include "decode/common_object_info_table.h"
#include "decode/vulkan_device_address_tracker.h"
#include "decode/vulkan_object_info.h"
#include "decode/vulkan_replay_options.h"
#include "decode/struct_pointer_decoder.h"
#include "decode/vulkan_replay_dump_resources_common.h"
#include "decode/vulkan_replay_dump_resources_draw_calls.h"
#include "decode/vulkan_replay_dump_resources_compute_ray_tracing.h"
#include "generated/generated_vulkan_dispatch_table.h"
#include "format/format.h"
#include "generated/generated_vulkan_struct_decoders.h"
#include "util/compressor.h"
#include "util/defines.h"
#include "vulkan/vulkan_core.h"

#include <cstdint>
#include <type_traits>
#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class VulkanReplayDumpResourcesBase
{
  public:
    VulkanReplayDumpResourcesBase() = delete;

    VulkanReplayDumpResourcesBase(const VulkanReplayOptions&            options,
                                  CommonObjectInfoTable*                object_info_table,
                                  const VulkanPerDeviceAddressTrackers& address_trackers);

    ~VulkanReplayDumpResourcesBase();

    VkResult BeginCommandBuffer(uint64_t                             bcb_index,
                                VulkanCommandBufferInfo*             original_command_buffer_info,
                                const graphics::VulkanDeviceTable*   device_table,
                                const graphics::VulkanInstanceTable* inst_table,
                                const VkCommandBufferBeginInfo*      begin_info);

    void OverrideCmdDraw(const ApiCallInfo& call_info,
                         PFN_vkCmdDraw      func,
                         VkCommandBuffer    original_command_buffer,
                         uint32_t           vertex_count,
                         uint32_t           instance_count,
                         uint32_t           first_vertex,
                         uint32_t           first_instance);

    void OverrideCmdDrawIndexed(const ApiCallInfo&   call_info,
                                PFN_vkCmdDrawIndexed func,
                                VkCommandBuffer      original_command_buffer,
                                uint32_t             index_count,
                                uint32_t             instance_count,
                                uint32_t             first_index,
                                int32_t              vertex_offset,
                                uint32_t             first_instance);

    void OverrideCmdDrawIndirect(const ApiCallInfo&      call_info,
                                 PFN_vkCmdDrawIndirect   func,
                                 VkCommandBuffer         original_command_buffer,
                                 const VulkanBufferInfo* buffer_info,
                                 VkDeviceSize            offset,
                                 uint32_t                draw_count,
                                 uint32_t                stride);

    void OverrideCmdDrawIndexedIndirect(const ApiCallInfo&           call_info,
                                        PFN_vkCmdDrawIndexedIndirect func,
                                        VkCommandBuffer              original_command_buffer,
                                        const VulkanBufferInfo*      buffer_info,
                                        VkDeviceSize                 offset,
                                        uint32_t                     draw_count,
                                        uint32_t                     stride);

    void OverrideCmdDrawIndirectCount(const ApiCallInfo&         call_info,
                                      PFN_vkCmdDrawIndirectCount func,
                                      VkCommandBuffer            original_command_buffer,
                                      const VulkanBufferInfo*    buffer_info,
                                      VkDeviceSize               offset,
                                      const VulkanBufferInfo*    count_buffer_info,
                                      VkDeviceSize               count_buffer_offset,
                                      uint32_t                   max_draw_count,
                                      uint32_t                   stride)
    {
        HandleCmdDrawIndirectCount(call_info,
                                   func,
                                   original_command_buffer,
                                   buffer_info,
                                   offset,
                                   count_buffer_info,
                                   count_buffer_offset,
                                   max_draw_count,
                                   stride,
                                   DrawCallsDumpingContext::kDrawIndirectCount);
    }

    void OverrideCmdDrawIndirectCountKHR(const ApiCallInfo&            call_info,
                                         PFN_vkCmdDrawIndirectCountKHR func,
                                         VkCommandBuffer               original_command_buffer,
                                         const VulkanBufferInfo*       buffer_info,
                                         VkDeviceSize                  offset,
                                         const VulkanBufferInfo*       count_buffer_info,
                                         VkDeviceSize                  count_buffer_offset,
                                         uint32_t                      max_draw_count,
                                         uint32_t                      stride)
    {
        HandleCmdDrawIndirectCount(call_info,
                                   func,
                                   original_command_buffer,
                                   buffer_info,
                                   offset,
                                   count_buffer_info,
                                   count_buffer_offset,
                                   max_draw_count,
                                   stride,
                                   DrawCallsDumpingContext::kDrawIndirectCountKHR);
    }

    void OverrideCmdDrawIndirectCountAMD(const ApiCallInfo&            call_info,
                                         PFN_vkCmdDrawIndirectCountAMD func,
                                         VkCommandBuffer               original_command_buffer,
                                         const VulkanBufferInfo*       buffer_info,
                                         VkDeviceSize                  offset,
                                         const VulkanBufferInfo*       count_buffer_info,
                                         VkDeviceSize                  count_buffer_offset,
                                         uint32_t                      max_draw_count,
                                         uint32_t                      stride)
    {
        HandleCmdDrawIndirectCount(call_info,
                                   func,
                                   original_command_buffer,
                                   buffer_info,
                                   offset,
                                   count_buffer_info,
                                   count_buffer_offset,
                                   max_draw_count,
                                   stride,
                                   DrawCallsDumpingContext::kDrawIndirectCountAMD);
    }

    void OverrideCmdDrawIndexedIndirectCount(const ApiCallInfo&                call_info,
                                             PFN_vkCmdDrawIndexedIndirectCount func,
                                             VkCommandBuffer                   original_command_buffer,
                                             const VulkanBufferInfo*           buffer_info,
                                             VkDeviceSize                      offset,
                                             const VulkanBufferInfo*           count_buffer_info,
                                             VkDeviceSize                      count_buffer_offset,
                                             uint32_t                          max_draw_count,
                                             uint32_t                          stride)
    {
        HandleCmdDrawIndexedIndirectCount(call_info,
                                          func,
                                          original_command_buffer,
                                          buffer_info,
                                          offset,
                                          count_buffer_info,
                                          count_buffer_offset,
                                          max_draw_count,
                                          stride,
                                          DrawCallsDumpingContext::kDrawIndexedIndirectCount);
    }

    void OverrideCmdDrawIndexedIndirectCountKHR(const ApiCallInfo&                   call_info,
                                                PFN_vkCmdDrawIndexedIndirectCountKHR func,
                                                VkCommandBuffer                      original_command_buffer,
                                                const VulkanBufferInfo*              buffer_info,
                                                VkDeviceSize                         offset,
                                                const VulkanBufferInfo*              count_buffer_info,
                                                VkDeviceSize                         count_buffer_offset,
                                                uint32_t                             max_draw_count,
                                                uint32_t                             stride)
    {
        HandleCmdDrawIndexedIndirectCount(call_info,
                                          func,
                                          original_command_buffer,
                                          buffer_info,
                                          offset,
                                          count_buffer_info,
                                          count_buffer_offset,
                                          max_draw_count,
                                          stride,
                                          DrawCallsDumpingContext::kDrawIndexedIndirectCountKHR);
    }

    void OverrideCmdDrawIndexedIndirectCountAMD(const ApiCallInfo&                   call_info,
                                                PFN_vkCmdDrawIndexedIndirectCountAMD func,
                                                VkCommandBuffer                      original_command_buffer,
                                                const VulkanBufferInfo*              buffer_info,
                                                VkDeviceSize                         offset,
                                                const VulkanBufferInfo*              count_buffer_info,
                                                VkDeviceSize                         count_buffer_offset,
                                                uint32_t                             max_draw_count,
                                                uint32_t                             stride)
    {
        HandleCmdDrawIndexedIndirectCount(call_info,
                                          func,
                                          original_command_buffer,
                                          buffer_info,
                                          offset,
                                          count_buffer_info,
                                          count_buffer_offset,
                                          max_draw_count,
                                          stride,
                                          DrawCallsDumpingContext::kDrawIndexedIndirectCountAMD);
    }

    void OverrideCmdBeginRenderPass(const ApiCallInfo&                                   call_info,
                                    PFN_vkCmdBeginRenderPass                             func,
                                    VkCommandBuffer                                      original_command_buffer,
                                    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
                                    VkSubpassContents                                    contents);

    void OverrideCmdBeginRenderPass2(const ApiCallInfo&                                   call_info,
                                     PFN_vkCmdBeginRenderPass2                            func,
                                     VkCommandBuffer                                      original_command_buffer,
                                     StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
                                     StructPointerDecoder<Decoded_VkSubpassBeginInfo>*    pSubpassBeginInfo);

    void OverrideCmdEndRenderPass(const ApiCallInfo&     call_info,
                                  PFN_vkCmdEndRenderPass func,
                                  VkCommandBuffer        original_command_buffer);

    void OverrideCmdEndRenderPass2(const ApiCallInfo&                              call_info,
                                   PFN_vkCmdEndRenderPass2                         func,
                                   VkCommandBuffer                                 original_command_buffer,
                                   StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo);

    void OverrideCmdNextSubpass(const ApiCallInfo&   call_info,
                                PFN_vkCmdNextSubpass func,
                                VkCommandBuffer      original_command_buffer,
                                VkSubpassContents    contents);

    void OverrideCmdNextSubpass2(const ApiCallInfo&                                call_info,
                                 PFN_vkCmdNextSubpass2                             func,
                                 VkCommandBuffer                                   original_command_buffer,
                                 StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo,
                                 StructPointerDecoder<Decoded_VkSubpassEndInfo>*   pSubpassEndInfo);

    void OverrideCmdBindPipeline(const ApiCallInfo&        call_info,
                                 PFN_vkCmdBindPipeline     func,
                                 VkCommandBuffer           original_command_buffer,
                                 VkPipelineBindPoint       pipelineBindPoint,
                                 const VulkanPipelineInfo* pipeline);

    void OverrideCmdDispatch(const ApiCallInfo& call_info,
                             PFN_vkCmdDispatch  func,
                             VkCommandBuffer    original_command_buffer,
                             uint32_t           groupCountX,
                             uint32_t           groupCountY,
                             uint32_t           groupCountZ);

    void OverrideCmdDispatchIndirect(const ApiCallInfo&        call_info,
                                     PFN_vkCmdDispatchIndirect func,
                                     VkCommandBuffer           original_command_buffer,
                                     const VulkanBufferInfo*   buffer_info,
                                     VkDeviceSize              offset);

    void
    OverrideCmdTraceRaysKHR(const ApiCallInfo&                                             call_info,
                            PFN_vkCmdTraceRaysKHR                                          func,
                            VkCommandBuffer                                                original_command_buffer,
                            StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pRaygenShaderBindingTable,
                            StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pMissShaderBindingTable,
                            StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pHitShaderBindingTable,
                            StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pCallableShaderBindingTable,
                            uint32_t                                                       width,
                            uint32_t                                                       height,
                            uint32_t                                                       depth);

    void OverrideCmdTraceRaysIndirectKHR(
        const ApiCallInfo&                                             call_info,
        PFN_vkCmdTraceRaysIndirectKHR                                  func,
        VkCommandBuffer                                                original_command_buffer,
        StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pRaygenShaderBindingTable,
        StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pMissShaderBindingTable,
        StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pHitShaderBindingTable,
        StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pCallableShaderBindingTable,
        VkDeviceAddress                                                indirectDeviceAddress);

    void OverrideCmdTraceRaysIndirect2KHR(const ApiCallInfo&             call_info,
                                          PFN_vkCmdTraceRaysIndirect2KHR func,
                                          VkCommandBuffer                original_command_buffer,
                                          VkDeviceAddress                indirectDeviceAddress);

    void OverrideCmdBindDescriptorSets(const ApiCallInfo&              call_info,
                                       PFN_vkCmdBindDescriptorSets     func,
                                       VkCommandBuffer                 original_command_buffer,
                                       VkPipelineBindPoint             pipeline_bind_point,
                                       const VulkanPipelineLayoutInfo* layout_info,
                                       uint32_t                        first_set,
                                       uint32_t                        descriptor_sets_count,
                                       const format::HandleId*         descriptor_sets_ids,
                                       uint32_t                        dynamicOffsetCount,
                                       const uint32_t*                 pDynamicOffsets);

    void
    OverrideCmdBindDescriptorSets2(const ApiCallInfo&                                      call_info,
                                   PFN_vkCmdBindDescriptorSets2                            func,
                                   VkCommandBuffer                                         original_command_buffer,
                                   StructPointerDecoder<Decoded_VkBindDescriptorSetsInfo>* pBindDescriptorSetsInfo);

    void OverrideCmdBindIndexBuffer(const ApiCallInfo&       call_info,
                                    PFN_vkCmdBindIndexBuffer func,
                                    VkCommandBuffer          original_command_buffer,
                                    const VulkanBufferInfo*  buffer,
                                    VkDeviceSize             offset,
                                    VkIndexType              indexType);

    void OverrideCmdBindVertexBuffers(const ApiCallInfo&         call_info,
                                      PFN_vkCmdBindVertexBuffers func,
                                      VkCommandBuffer            original_command_buffer,
                                      uint32_t                   firstBinding,
                                      uint32_t                   bindingCount,
                                      const format::HandleId*    buffer_ids,
                                      const VkDeviceSize*        pOffsets);

    void OverrideCmdSetVertexInputEXT(
        const ApiCallInfo&                                                   call_info,
        PFN_vkCmdSetVertexInputEXT                                           func,
        VkCommandBuffer                                                      original_command_buffer,
        uint32_t                                                             vertexBindingDescriptionCount,
        StructPointerDecoder<Decoded_VkVertexInputBindingDescription2EXT>*   pVertexBindingDescriptions,
        uint32_t                                                             vertexAttributeDescriptionCount,
        StructPointerDecoder<Decoded_VkVertexInputAttributeDescription2EXT>* pVertexAttributeDescriptions);

    void OverrideCmdBindVertexBuffers2(const ApiCallInfo&          call_info,
                                       PFN_vkCmdBindVertexBuffers2 func,
                                       VkCommandBuffer             original_command_buffer,
                                       uint32_t                    firstBinding,
                                       uint32_t                    bindingCount,
                                       const format::HandleId*     pBuffers_ids,
                                       const VkDeviceSize*         pOffsets,
                                       const VkDeviceSize*         pSizes,
                                       const VkDeviceSize*         pStrides);

    void OverrideCmdBindVertexBuffers2EXT(const ApiCallInfo&             call_info,
                                          PFN_vkCmdBindVertexBuffers2EXT func,
                                          VkCommandBuffer                original_command_buffer,
                                          uint32_t                       firstBinding,
                                          uint32_t                       bindingCount,
                                          const format::HandleId*        pBuffers_ids,
                                          const VkDeviceSize*            pOffsets,
                                          const VkDeviceSize*            pSizes,
                                          const VkDeviceSize*            pStrides);

    void OverrideCmdBindIndexBuffer2KHR(const ApiCallInfo&           call_info,
                                        PFN_vkCmdBindIndexBuffer2KHR func,
                                        VkCommandBuffer              commandBuffer,
                                        const VulkanBufferInfo*      buffer,
                                        VkDeviceSize                 offset,
                                        VkDeviceSize                 size,
                                        VkIndexType                  indexType);

    void OverrideCmdBeginRendering(const ApiCallInfo&                             call_info,
                                   PFN_vkCmdBeginRendering                        func,
                                   VkCommandBuffer                                commandBuffer,
                                   StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo);

    void OverrideCmdBeginRenderingKHR(const ApiCallInfo&                             call_info,
                                      PFN_vkCmdBeginRenderingKHR                     func,
                                      VkCommandBuffer                                commandBuffer,
                                      StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo);

    void
    OverrideCmdEndRendering(const ApiCallInfo& call_info, PFN_vkCmdEndRendering func, VkCommandBuffer commandBuffer);

    void OverrideCmdEndRenderingKHR(const ApiCallInfo&       call_info,
                                    PFN_vkCmdEndRenderingKHR func,
                                    VkCommandBuffer          commandBuffer);

    void
    OverrideEndCommandBuffer(const ApiCallInfo& call_info, PFN_vkEndCommandBuffer func, VkCommandBuffer commandBuffer);

    void OverrideCmdExecuteCommands(const ApiCallInfo&       call_info,
                                    PFN_vkCmdExecuteCommands func,
                                    VkCommandBuffer          commandBuffer,
                                    uint32_t                 commandBufferCount,
                                    const VkCommandBuffer*   pCommandBuffers);

    VkResult QueueSubmit(const std::vector<VkSubmitInfo>&   modified_submit_infos,
                         const graphics::VulkanDeviceTable& device_table,
                         VkQueue                            queue,
                         VkFence                            fence,
                         uint64_t                           index);

    bool MustDumpQueueSubmitIndex(uint64_t index) const;

    bool DumpingBeginCommandBufferIndex(uint64_t index) const;

    bool IsRecording(VkCommandBuffer original_command_buffer) const;

    void Release();

    void ResetCommandBuffer(VkCommandBuffer original_command_buffer);

    void DumpGraphicsPipelineInfos(const StructPointerDecoder<Decoded_VkGraphicsPipelineCreateInfo>* pCreateInfos,
                                   uint32_t                                                          createInfoCount,
                                   HandlePointerDecoder<VkPipeline>*                                 pPipelines);

    template <typename DecodedCreateInfoType>
    void DumpRayTracingPipelineInfos(DecodedCreateInfoType             pCreateInfos,
                                     uint32_t                          createInfoCount,
                                     HandlePointerDecoder<VkPipeline>* pPipelines)
    {
        static_assert((std::is_same<decltype(pCreateInfos),
                                    const StructPointerDecoder<Decoded_VkRayTracingPipelineCreateInfoKHR>*>::value) ||
                          (std::is_same<decltype(pCreateInfos),
                                        const StructPointerDecoder<Decoded_VkRayTracingPipelineCreateInfoNV>*>::value),
                      "pCreateInfos is of wrong type");

        const auto* create_info_meta  = pCreateInfos->GetMetaStructPointer();
        const auto* in_p_create_infos = pCreateInfos->GetPointer();
        if (create_info_meta != nullptr && in_p_create_infos != nullptr)
        {
            for (uint32_t i = 0; i < createInfoCount; ++i)
            {
                VulkanPipelineInfo* pipeline_info =
                    reinterpret_cast<VulkanPipelineInfo*>(pPipelines->GetConsumerData(i));

                // Copy pipeline layout information
                const auto ppl_layout_info = object_info_table_->GetVkPipelineLayoutInfo(create_info_meta[i].layout);
                if (ppl_layout_info != nullptr)
                {
                    pipeline_info->desc_set_layouts = ppl_layout_info->desc_set_layouts;
                }

                // Aggregate used shader stages flags
                for (uint32_t ss = 0; ss < in_p_create_infos[i].stageCount; ++ss)
                {
                    pipeline_info->shader_stages |=
                        static_cast<VkShaderStageFlags>(in_p_create_infos[i].pStages[ss].stage);
                }

                // handle optional VkPipelineLibraryCreateInfoKHR
                const auto* pipeline_library_info =
                    GetPNextMetaStruct<Decoded_VkPipelineLibraryCreateInfoKHR>(create_info_meta->pNext);
                if (pipeline_library_info != nullptr)
                {
                    const uint32_t          library_count = pipeline_library_info->pLibraries.GetLength();
                    const format::HandleId* ppl_ids       = pipeline_library_info->pLibraries.GetPointer();

                    for (uint32_t lib_idx = 0; lib_idx < library_count; ++lib_idx)
                    {
                        const VulkanPipelineInfo* gpl_ppl = object_info_table_->GetVkPipelineInfo(ppl_ids[lib_idx]);

                        // Accumulate shader stages from the other pipelines from the library
                        pipeline_info->shader_stages |= gpl_ppl->shader_stages;
                    }
                }
            }
        }
    }

    void DumpComputePipelineInfos(const StructPointerDecoder<Decoded_VkComputePipelineCreateInfo>* pCreateInfos,
                                  uint32_t                                                         createInfoCount,
                                  HandlePointerDecoder<VkPipeline>*                                pPipelines)
    {
        const auto* create_info_meta  = pCreateInfos->GetMetaStructPointer();
        const auto* in_p_create_infos = pCreateInfos->GetPointer();
        if (create_info_meta != nullptr && in_p_create_infos != nullptr)
        {
            for (uint32_t i = 0; i < createInfoCount; ++i)
            {
                VulkanPipelineInfo* pipeline_info =
                    reinterpret_cast<VulkanPipelineInfo*>(pPipelines->GetConsumerData(i));

                // Copy pipeline layout information
                const auto ppl_layout_info = object_info_table_->GetVkPipelineLayoutInfo(create_info_meta[i].layout);
                if (ppl_layout_info != nullptr)
                {
                    pipeline_info->desc_set_layouts = ppl_layout_info->desc_set_layouts;
                }

                // Used shader stages
                pipeline_info->shader_stages = in_p_create_infos->stage.stage;
            }
        }
    }

    void DumpResourcesSetFatalErrorHandler(std::function<void(const char*)> handler);

    // Handles population of acceleration_structures_context_ map. For each AS that is build an entry in that map is
    // created and the input buffers are cloned
    void OverrideCmdBuildAccelerationStructuresKHR(
        const VulkanCommandBufferInfo*                                             original_command_buffer,
        const graphics::VulkanDeviceTable&                                         device_table,
        uint32_t                                                                   infoCount,
        StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* pInfos,
        StructPointerDecoder<Decoded_VkAccelerationStructureBuildRangeInfoKHR*>*   ppBuildRangeInfos);

    // Like OverrideCmdBuildAccelerationStructuresKHR Handles population of acceleration_structures_context_ map.
    // In this case of copying AS it simply makes the new entry in the map to point at the src AS's entry.
    void HandleCmdCopyAccelerationStructureKHR(const graphics::VulkanDeviceTable&        device_table,
                                               const VulkanAccelerationStructureKHRInfo* src,
                                               const VulkanAccelerationStructureKHRInfo* dst);

    void HandleDestroyAccelerationStructureKHR(const VulkanAccelerationStructureKHRInfo* as_info);

    std::vector<DrawCallsDumpingContext*> FindDrawCallCommandBufferContext(VkCommandBuffer original_command_buffer);

    std::vector<DispatchTraceRaysDumpingContext*>
    FindDispatchRaysCommandBufferContext(VkCommandBuffer original_command_buffer);

  private:
    bool UpdateRecordingStatus(VkCommandBuffer original_command_buffer);

    std::vector<DispatchTraceRaysDumpingContext*> FindDispatchRaysCommandBufferContext(uint64_t bcb_id);
    DispatchTraceRaysDumpingContext* FindDispatchRaysCommandBufferContext(VkCommandBuffer original_command_buffer,
                                                                          decode::Index   qs_index);

    std::vector<const DispatchTraceRaysDumpingContext*> FindDispatchRaysCommandBufferContext(uint64_t bcb_id) const;
    std::vector<const DispatchTraceRaysDumpingContext*>
    FindDispatchRaysCommandBufferContext(VkCommandBuffer original_command_buffer) const;

    DrawCallsDumpingContext* FindDrawCallCommandBufferContext(VkCommandBuffer original_command_buffer,
                                                              decode::Index   qs_index);

    std::vector<DrawCallsDumpingContext*> FindDrawCallCommandBufferContext(uint64_t bcb_id);

    std::vector<const DrawCallsDumpingContext*>
    FindDrawCallCommandBufferContext(VkCommandBuffer original_command_buffer) const;
    std::vector<const DrawCallsDumpingContext*> FindDrawCallCommandBufferContext(uint64_t bcb_id) const;

    void HandleCmdBindVertexBuffers2(const ApiCallInfo&          call_info,
                                     PFN_vkCmdBindVertexBuffers2 func,
                                     VkCommandBuffer             original_command_buffer,
                                     uint32_t                    firstBinding,
                                     uint32_t                    bindingCount,
                                     const format::HandleId*     pBuffers_ids,
                                     const VkDeviceSize*         pOffsets,
                                     const VkDeviceSize*         pSizes,
                                     const VkDeviceSize*         pStrides);

    void HandleCmdDrawIndirectCount(const ApiCallInfo&                    call_info,
                                    PFN_vkCmdDrawIndirectCount            func,
                                    VkCommandBuffer                       original_command_buffer,
                                    const VulkanBufferInfo*               buffer_info,
                                    VkDeviceSize                          offset,
                                    const VulkanBufferInfo*               count_buffer_info,
                                    VkDeviceSize                          count_buffer_offset,
                                    uint32_t                              max_draw_count,
                                    uint32_t                              stride,
                                    DrawCallsDumpingContext::DrawCallType drawcall_type);

    void HandleCmdDrawIndexedIndirectCount(const ApiCallInfo&                    call_info,
                                           PFN_vkCmdDrawIndexedIndirectCount     func,
                                           VkCommandBuffer                       original_command_buffer,
                                           const VulkanBufferInfo*               buffer_info,
                                           VkDeviceSize                          offset,
                                           const VulkanBufferInfo*               count_buffer_info,
                                           VkDeviceSize                          count_buffer_offset,
                                           uint32_t                              max_draw_count,
                                           uint32_t                              stride,
                                           DrawCallsDumpingContext::DrawCallType drawcall_type);

    // Mapping between the original VkCommandBuffer handle and BeginCommandBuffer index
    std::unordered_map<VkCommandBuffer, uint64_t> cmd_buf_begin_map_;

    // BeginCommandBuffer - QueueSubmit pairs
    std::vector<BeginCmdBufQueueSubmitPair> BeginCommandBufferQueueSubmit_Indices_;

    // Mapping between the original VkCommandBuffer handle and its BeginCommandBuffer indices we care about
    std::unordered_map<VkCommandBuffer, decode::Index> cb_bcb_map_;

    // DrawCall dumping contexts. One per BeginCommandBuffer - QueueSubmit pair
    std::map<BeginCmdBufQueueSubmitPair, DrawCallsDumpingContext> draw_call_contexts_;

    // Dispatch-TraceRays call dumping contexts. One per BeginCommandBuffer - QueueSubmit pair
    std::map<BeginCmdBufQueueSubmitPair, DispatchTraceRaysDumpingContext> dispatch_ray_contexts_;

    bool                   recording_;
    bool                   dump_resources_before_;
    CommonObjectInfoTable* object_info_table_;
    bool                   output_json_per_command;

    std::unique_ptr<DefaultVulkanDumpResourcesDelegate> default_delegate_;
    VulkanDumpResourcesDelegate*                        user_delegate_;
    VulkanDumpResourcesDelegate*                        active_delegate_;

    std::unique_ptr<util::Compressor> compressor_;

    std::string capture_filename;

    const VulkanPerDeviceAddressTrackers& address_trackers_;

    DumpResourcesAccelerationStructuresContext acceleration_structures_context_;
    bool                                       dump_as_build_input_buffers_;

    std::function<void(const char*)> fatal_error_handler_;
    void                             RaiseFatalError(const char* message) const;
};

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)

#endif /* GFXRECON_GENERATED_VULKAN_REPLAY_DUMP_RESOURCES_BASE_H */
