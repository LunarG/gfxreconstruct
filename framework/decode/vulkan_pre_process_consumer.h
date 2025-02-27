/*
** Copyright (c) 2025 LunarG, Inc.
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

#ifndef GFXRECON_DECODE_VULKAN_PRE_PROCESS_CONSUMER_H
#define GFXRECON_DECODE_VULKAN_PRE_PROCESS_CONSUMER_H

#include "generated/generated_vulkan_consumer.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

const std::string DUMP_ARG_BEGIN_COMMAND_BUFFER = "BeginCommandBuffer";
const std::string DUMP_ARG_DRAW                 = "Draw";
const std::string DUMP_ARG_RENDER_PASS          = "RenderPass";
const std::string DUMP_ARG_BEGIN_RENDER_PASS    = "BeginRenderPass";
const std::string DUMP_ARG_NEXT_SUB_PASS        = "NextSubPass";
const std::string DUMP_ARG_END_RENDER_PASS      = "EndRenderPass";
const std::string DUMP_ARG_DISPATCH             = "Dispatch";
const std::string DUMP_ARG_TRACE_RAYS           = "TraceRays";
const std::string DUMP_ARG_QUEUE_SUBMIT         = "QueueSubmit";

enum class VkDumpDrawCallType
{
    kUnknown,
    kDraw,
    kDispatch,
    kTraceRays,
};

struct VkTrackDumpRenderPass
{
    uint64_t begin_block_index{ 0 };
    uint64_t end_block_index{ 0 };
    uint64_t next_sub_pass_block_index{ 0 };
};

struct VkTrackDumpDrawCall
{
    VkDumpDrawCallType    type{ VkDumpDrawCallType::kUnknown };
    uint64_t              block_index{ 0 };
    VkTrackDumpRenderPass render_pass{};
};

struct VkTrackDumpCommandBuffer
{
    uint64_t                         begin_block_index{ 0 };
    uint64_t                         current_begin_render_pass_block_index{ 0 };
    uint64_t                         current_next_sub_pass_block_index{ 0 };
    std::vector<VkTrackDumpDrawCall> draw_call_indices;

    void Clear()
    {
        begin_block_index                     = 0;
        current_begin_render_pass_block_index = 0;
        current_next_sub_pass_block_index     = 0;
        draw_call_indices.clear();
    }
};

// Convert vulkan_replay_options.dump_resources_target to vulkan_replay_options.dump_resources_block_indices.
// vulkan_replay_options.dump_resources_block_indices is parsed in parse_dump_resources_arg.
// BeginCommandBuffer=<n>,Draw=<o>,BeginRenderPass=<p>,NextSubPass=<q>,EndRenderPass=<r>,Dispatch=<s>,TraceRays=<t>,QueueSubmit=<u>

// It runs tasks that need to be completed before replay.
class VulkanPreProcessConsumer : public VulkanConsumer
{
  public:
    VulkanPreProcessConsumer() {}

    bool WasVulkanAPIDetected() { return vulkan_consumer_usage_; }

    virtual void Process_vkCreateDevice(const ApiCallInfo&         call_info,
                                        VkResult                   returnValue,
                                        gfxrecon::format::HandleId physicalDevice,
                                        StructPointerDecoder<Decoded_VkDeviceCreateInfo>*,
                                        StructPointerDecoder<Decoded_VkAllocationCallbacks>*,
                                        HandlePointerDecoder<VkDevice>*) override
    {
        vulkan_consumer_usage_                = true;
        check_vulkan_consumer_usage_complete_ = true;
    }

    void EnableDumpResources(const DumpResourcesTarget& dump_resources_target)
    {
        enable_dump_resources_         = true;
        check_dump_resources_complete_ = false;
        dump_resources_target_         = dump_resources_target;
    }

    std::string GetDumpResourcesBlockIndices()
    {
        GFXRECON_ASSERT(track_submit_index_ > dump_resources_target_.submit_index);

        std::string dump_resources_block_indices;
        auto        it = track_cmd_buf_infos_.find(target_command_buffer_);
        if (it != track_cmd_buf_infos_.end())
        {
            GFXRECON_ASSERT(it->second.draw_call_indices.size() > dump_resources_target_.draw_call_index);
            dump_resources_block_indices = DUMP_ARG_QUEUE_SUBMIT;
            dump_resources_block_indices += "=";
            dump_resources_block_indices += std::to_string(target_submit_block_index_);
            dump_resources_block_indices += ",";

            dump_resources_block_indices += DUMP_ARG_BEGIN_COMMAND_BUFFER;
            dump_resources_block_indices += "=";
            dump_resources_block_indices += std::to_string(it->second.begin_block_index);
            dump_resources_block_indices += ",";

            const auto& draw_call = it->second.draw_call_indices[dump_resources_target_.draw_call_index];
            switch (draw_call.type)
            {
                case VkDumpDrawCallType::kDraw:
                    dump_resources_block_indices += DUMP_ARG_BEGIN_RENDER_PASS;
                    dump_resources_block_indices += "=";
                    dump_resources_block_indices += std::to_string(draw_call.render_pass.begin_block_index);
                    dump_resources_block_indices += ",";

                    if (draw_call.render_pass.next_sub_pass_block_index > 0)
                    {
                        dump_resources_block_indices += DUMP_ARG_NEXT_SUB_PASS;
                        dump_resources_block_indices += "=";
                        dump_resources_block_indices += std::to_string(draw_call.render_pass.next_sub_pass_block_index);
                        dump_resources_block_indices += ",";
                    }

                    dump_resources_block_indices += DUMP_ARG_END_RENDER_PASS;
                    dump_resources_block_indices += "=";
                    dump_resources_block_indices += std::to_string(draw_call.render_pass.end_block_index);
                    dump_resources_block_indices += ",";

                    dump_resources_block_indices += DUMP_ARG_DRAW;
                    break;
                case VkDumpDrawCallType::kDispatch:
                    dump_resources_block_indices += DUMP_ARG_DISPATCH;
                    break;
                case VkDumpDrawCallType::kTraceRays:
                    dump_resources_block_indices += DUMP_ARG_TRACE_RAYS;
                    break;
                default:
                    break;
            }
            dump_resources_block_indices += "=";
            dump_resources_block_indices += std::to_string(draw_call.block_index);
        }
        GFXRECON_LOG_INFO("Dump resources block indices: %s", dump_resources_block_indices.c_str());
        return dump_resources_block_indices;
    }

    virtual void
    Process_vkAllocateCommandBuffers(const ApiCallInfo&                                         call_info,
                                     VkResult                                                   returnValue,
                                     format::HandleId                                           device,
                                     StructPointerDecoder<Decoded_VkCommandBufferAllocateInfo>* pAllocateInfo,
                                     HandlePointerDecoder<VkCommandBuffer>* pCommandBuffers) override
    {
        auto                     cmd_buf_handle_id = pCommandBuffers->GetPointer();
        VkTrackDumpCommandBuffer cmd_buf_info{};
        track_cmd_buf_infos_[*cmd_buf_handle_id] = cmd_buf_info;
    }

    virtual void Process_vkResetCommandBuffer(const ApiCallInfo&        call_info,
                                              VkResult                  returnValue,
                                              format::HandleId          commandBuffer,
                                              VkCommandBufferResetFlags flags) override
    {
        auto it = track_cmd_buf_infos_.find(commandBuffer);
        if (it != track_cmd_buf_infos_.end())
        {
            it->second.Clear();
        }
    }

    virtual void
    Process_vkBeginCommandBuffer(const ApiCallInfo&                                      call_info,
                                 VkResult                                                returnValue,
                                 format::HandleId                                        commandBuffer,
                                 StructPointerDecoder<Decoded_VkCommandBufferBeginInfo>* pBeginInfo) override
    {
        auto it = track_cmd_buf_infos_.find(commandBuffer);
        if (it != track_cmd_buf_infos_.end())
        {
            it->second.begin_block_index = call_info.index;
        }
    }

    virtual void Process_vkCmdBeginRenderPass(const ApiCallInfo&                                   call_info,
                                              format::HandleId                                     commandBuffer,
                                              StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
                                              VkSubpassContents                                    contents) override
    {
        BeginRenderPass(commandBuffer, call_info.index);
    }

    virtual void
    Process_vkCmdBeginRenderPass2(const ApiCallInfo&                                   call_info,
                                  format::HandleId                                     commandBuffer,
                                  StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
                                  StructPointerDecoder<Decoded_VkSubpassBeginInfo>*    pSubpassBeginInfo) override
    {
        BeginRenderPass(commandBuffer, call_info.index);
    }

    virtual void Process_vkCmdEndRenderPass(const ApiCallInfo& call_info, format::HandleId commandBuffer) override
    {
        EndRenderPass(commandBuffer, call_info.index);
    }

    virtual void Process_vkCmdEndRenderPass2(const ApiCallInfo&                              call_info,
                                             format::HandleId                                commandBuffer,
                                             StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo) override
    {
        EndRenderPass(commandBuffer, call_info.index);
    }

    virtual void Process_vkCmdNextSubpass(const ApiCallInfo& call_info,
                                          format::HandleId   commandBuffer,
                                          VkSubpassContents  contents) override
    {
        NextSubpass(commandBuffer, call_info.index);
    }

    virtual void Process_vkCmdNextSubpass2(const ApiCallInfo&                                call_info,
                                           format::HandleId                                  commandBuffer,
                                           StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo,
                                           StructPointerDecoder<Decoded_VkSubpassEndInfo>*   pSubpassEndInfo) override
    {
        NextSubpass(commandBuffer, call_info.index);
    }

    virtual void Process_vkQueueSubmit(const ApiCallInfo&                          call_info,
                                       VkResult                                    returnValue,
                                       format::HandleId                            queue,
                                       uint32_t                                    submitCount,
                                       StructPointerDecoder<Decoded_VkSubmitInfo>* pSubmits,
                                       format::HandleId                            fence) override
    {
        std::vector<format::HandleId> cmd_bufs;
        auto                          submit_info_data = pSubmits->GetMetaStructPointer();
        for (auto i = 0; i < submitCount; ++i)
        {
            const auto cmd_buf_count = submit_info_data[i].pCommandBuffers.GetLength();
            const auto cmd_buf_ids   = submit_info_data[i].pCommandBuffers.GetPointer();
            for (auto j = 0; j < cmd_buf_count; ++j)
            {
                cmd_bufs.emplace_back(cmd_buf_ids[j]);
            }
        }
        QueueSubmit(cmd_bufs, call_info.index);
    }

    virtual void Process_vkQueueSubmit2(const ApiCallInfo&                           call_info,
                                        VkResult                                     returnValue,
                                        format::HandleId                             queue,
                                        uint32_t                                     submitCount,
                                        StructPointerDecoder<Decoded_VkSubmitInfo2>* pSubmits,
                                        format::HandleId                             fence) override
    {
        std::vector<format::HandleId> cmd_bufs;
        auto                          submit_info_data = pSubmits->GetMetaStructPointer();
        for (auto i = 0; i < submitCount; ++i)
        {
            const auto cmd_buf_count = submit_info_data[i].pCommandBufferInfos->GetLength();
            const auto cmd_buf_infos = submit_info_data[i].pCommandBufferInfos->GetMetaStructPointer();
            for (auto j = 0; j < cmd_buf_count; ++j)
            {
                cmd_bufs.emplace_back(cmd_buf_infos[j].commandBuffer);
            }
        }
        QueueSubmit(cmd_bufs, call_info.index);
    }

    virtual void Process_vkQueueSubmit2KHR(const ApiCallInfo&                           call_info,
                                           VkResult                                     returnValue,
                                           format::HandleId                             queue,
                                           uint32_t                                     submitCount,
                                           StructPointerDecoder<Decoded_VkSubmitInfo2>* pSubmits,
                                           format::HandleId                             fence) override
    {
        std::vector<format::HandleId> cmd_bufs;
        auto                          submit_info_data = pSubmits->GetMetaStructPointer();
        for (auto i = 0; i < submitCount; ++i)
        {
            const auto cmd_buf_count = submit_info_data[i].pCommandBufferInfos->GetLength();
            const auto cmd_buf_infos = submit_info_data[i].pCommandBufferInfos->GetMetaStructPointer();
            for (auto j = 0; j < cmd_buf_count; ++j)
            {
                cmd_bufs.emplace_back(cmd_buf_infos[j].commandBuffer);
            }
        }
        QueueSubmit(cmd_bufs, call_info.index);
    }

    virtual void Process_vkCmdDraw(const ApiCallInfo& call_info,
                                   format::HandleId   commandBuffer,
                                   uint32_t           vertexCount,
                                   uint32_t           instanceCount,
                                   uint32_t           firstVertex,
                                   uint32_t           firstInstance) override
    {
        DrawCall(commandBuffer, call_info.index, VkDumpDrawCallType::kDraw);
    }

    virtual void Process_vkCmdDrawIndexed(const ApiCallInfo& call_info,
                                          format::HandleId   commandBuffer,
                                          uint32_t           indexCount,
                                          uint32_t           instanceCount,
                                          uint32_t           firstIndex,
                                          int32_t            vertexOffset,
                                          uint32_t           firstInstance) override
    {
        DrawCall(commandBuffer, call_info.index, VkDumpDrawCallType::kDraw);
    }

    virtual void Process_vkCmdDrawIndirect(const ApiCallInfo& call_info,
                                           format::HandleId   commandBuffer,
                                           format::HandleId   buffer,
                                           VkDeviceSize       offset,
                                           uint32_t           drawCount,
                                           uint32_t           stride) override
    {
        DrawCall(commandBuffer, call_info.index, VkDumpDrawCallType::kDraw);
    }

    virtual void Process_vkCmdDrawIndexedIndirect(const ApiCallInfo& call_info,
                                                  format::HandleId   commandBuffer,
                                                  format::HandleId   buffer,
                                                  VkDeviceSize       offset,
                                                  uint32_t           drawCount,
                                                  uint32_t           stride) override
    {
        DrawCall(commandBuffer, call_info.index, VkDumpDrawCallType::kDraw);
    }

    virtual void Process_vkCmdDrawIndirectCount(const ApiCallInfo& call_info,
                                                format::HandleId   commandBuffer,
                                                format::HandleId   buffer,
                                                VkDeviceSize       offset,
                                                format::HandleId   countBuffer,
                                                VkDeviceSize       countBufferOffset,
                                                uint32_t           maxDrawCount,
                                                uint32_t           stride) override
    {
        DrawCall(commandBuffer, call_info.index, VkDumpDrawCallType::kDraw);
    }

    virtual void Process_vkCmdDrawIndirectCountKHR(const ApiCallInfo& call_info,
                                                   format::HandleId   commandBuffer,
                                                   format::HandleId   buffer,
                                                   VkDeviceSize       offset,
                                                   format::HandleId   countBuffer,
                                                   VkDeviceSize       countBufferOffset,
                                                   uint32_t           maxDrawCount,
                                                   uint32_t           stride) override
    {
        DrawCall(commandBuffer, call_info.index, VkDumpDrawCallType::kDraw);
    }

    virtual void Process_vkCmdDrawIndexedIndirectCount(const ApiCallInfo& call_info,
                                                       format::HandleId   commandBuffer,
                                                       format::HandleId   buffer,
                                                       VkDeviceSize       offset,
                                                       format::HandleId   countBuffer,
                                                       VkDeviceSize       countBufferOffset,
                                                       uint32_t           maxDrawCount,
                                                       uint32_t           stride) override
    {
        DrawCall(commandBuffer, call_info.index, VkDumpDrawCallType::kDraw);
    }

    virtual void Process_vkCmdDrawIndexedIndirectCountKHR(const ApiCallInfo& call_info,
                                                          format::HandleId   commandBuffer,
                                                          format::HandleId   buffer,
                                                          VkDeviceSize       offset,
                                                          format::HandleId   countBuffer,
                                                          VkDeviceSize       countBufferOffset,
                                                          uint32_t           maxDrawCount,
                                                          uint32_t           stride) override
    {
        DrawCall(commandBuffer, call_info.index, VkDumpDrawCallType::kDraw);
    }

    virtual void Process_vkCmdDrawIndirectByteCountEXT(const ApiCallInfo& call_info,
                                                       format::HandleId   commandBuffer,
                                                       uint32_t           instanceCount,
                                                       uint32_t           firstInstance,
                                                       format::HandleId   counterBuffer,
                                                       VkDeviceSize       counterBufferOffset,
                                                       uint32_t           counterOffset,
                                                       uint32_t           vertexStride) override
    {
        DrawCall(commandBuffer, call_info.index, VkDumpDrawCallType::kDraw);
    }

    virtual void Process_vkCmdDrawIndirectCountAMD(const ApiCallInfo& call_info,
                                                   format::HandleId   commandBuffer,
                                                   format::HandleId   buffer,
                                                   VkDeviceSize       offset,
                                                   format::HandleId   countBuffer,
                                                   VkDeviceSize       countBufferOffset,
                                                   uint32_t           maxDrawCount,
                                                   uint32_t           stride) override
    {
        DrawCall(commandBuffer, call_info.index, VkDumpDrawCallType::kDraw);
    }

    virtual void Process_vkCmdDrawIndexedIndirectCountAMD(const ApiCallInfo& call_info,
                                                          format::HandleId   commandBuffer,
                                                          format::HandleId   buffer,
                                                          VkDeviceSize       offset,
                                                          format::HandleId   countBuffer,
                                                          VkDeviceSize       countBufferOffset,
                                                          uint32_t           maxDrawCount,
                                                          uint32_t           stride) override
    {
        DrawCall(commandBuffer, call_info.index, VkDumpDrawCallType::kDraw);
    }

    virtual void Process_vkCmdDrawMeshTasksEXT(const ApiCallInfo& call_info,
                                               format::HandleId   commandBuffer,
                                               uint32_t           groupCountX,
                                               uint32_t           groupCountY,
                                               uint32_t           groupCountZ) override
    {
        DrawCall(commandBuffer, call_info.index, VkDumpDrawCallType::kDraw);
    }

    virtual void Process_vkCmdDrawMeshTasksNV(const ApiCallInfo& call_info,
                                              format::HandleId   commandBuffer,
                                              uint32_t           taskCount,
                                              uint32_t           firstTask) override
    {
        DrawCall(commandBuffer, call_info.index, VkDumpDrawCallType::kDraw);
    }

    virtual void Process_vkCmdDrawMeshTasksIndirectEXT(const ApiCallInfo& call_info,
                                                       format::HandleId   commandBuffer,
                                                       format::HandleId   buffer,
                                                       VkDeviceSize       offset,
                                                       uint32_t           drawCount,
                                                       uint32_t           stride) override
    {
        DrawCall(commandBuffer, call_info.index, VkDumpDrawCallType::kDraw);
    }

    virtual void Process_vkCmdDrawMeshTasksIndirectNV(const ApiCallInfo& call_info,
                                                      format::HandleId   commandBuffer,
                                                      format::HandleId   buffer,
                                                      VkDeviceSize       offset,
                                                      uint32_t           drawCount,
                                                      uint32_t           stride) override
    {
        DrawCall(commandBuffer, call_info.index, VkDumpDrawCallType::kDraw);
    }

    virtual void Process_vkCmdDrawMeshTasksIndirectCountEXT(const ApiCallInfo& call_info,
                                                            format::HandleId   commandBuffer,
                                                            format::HandleId   buffer,
                                                            VkDeviceSize       offset,
                                                            format::HandleId   countBuffer,
                                                            VkDeviceSize       countBufferOffset,
                                                            uint32_t           maxDrawCount,
                                                            uint32_t           stride) override
    {
        DrawCall(commandBuffer, call_info.index, VkDumpDrawCallType::kDraw);
    }

    virtual void Process_vkCmdDrawMeshTasksIndirectCountNV(const ApiCallInfo& call_info,
                                                           format::HandleId   commandBuffer,
                                                           format::HandleId   buffer,
                                                           VkDeviceSize       offset,
                                                           format::HandleId   countBuffer,
                                                           VkDeviceSize       countBufferOffset,
                                                           uint32_t           maxDrawCount,
                                                           uint32_t           stride) override
    {
        DrawCall(commandBuffer, call_info.index, VkDumpDrawCallType::kDraw);
    }

    virtual void Process_vkCmdDrawMultiEXT(const ApiCallInfo&                                call_info,
                                           format::HandleId                                  commandBuffer,
                                           uint32_t                                          drawCount,
                                           StructPointerDecoder<Decoded_VkMultiDrawInfoEXT>* pVertexInfo,
                                           uint32_t                                          instanceCount,
                                           uint32_t                                          firstInstance,
                                           uint32_t                                          stride) override
    {
        DrawCall(commandBuffer, call_info.index, VkDumpDrawCallType::kDraw);
    }

    virtual void Process_vkCmdDrawMultiIndexedEXT(const ApiCallInfo& call_info,
                                                  format::HandleId   commandBuffer,
                                                  uint32_t           drawCount,
                                                  StructPointerDecoder<Decoded_VkMultiDrawIndexedInfoEXT>* pIndexInfo,
                                                  uint32_t                 instanceCount,
                                                  uint32_t                 firstInstance,
                                                  uint32_t                 stride,
                                                  PointerDecoder<int32_t>* pVertexOffset) override
    {
        DrawCall(commandBuffer, call_info.index, VkDumpDrawCallType::kDraw);
    }

    virtual void Process_vkCmdDrawClusterHUAWEI(const ApiCallInfo& call_info,
                                                format::HandleId   commandBuffer,
                                                uint32_t           groupCountX,
                                                uint32_t           groupCountY,
                                                uint32_t           groupCountZ) override
    {
        DrawCall(commandBuffer, call_info.index, VkDumpDrawCallType::kDraw);
    }

    virtual void Process_vkCmdDrawClusterIndirectHUAWEI(const ApiCallInfo& call_info,
                                                        format::HandleId   commandBuffer,
                                                        format::HandleId   buffer,
                                                        VkDeviceSize       offset) override
    {
        DrawCall(commandBuffer, call_info.index, VkDumpDrawCallType::kDraw);
    }

    virtual void Process_vkCmdDispatch(const ApiCallInfo& call_info,
                                       format::HandleId   commandBuffer,
                                       uint32_t           groupCountX,
                                       uint32_t           groupCountY,
                                       uint32_t           groupCountZ) override
    {
        DrawCall(commandBuffer, call_info.index, VkDumpDrawCallType::kDispatch);
    }

    virtual void Process_vkCmdDispatchIndirect(const ApiCallInfo& call_info,
                                               format::HandleId   commandBuffer,
                                               format::HandleId   buffer,
                                               VkDeviceSize       offset) override
    {
        DrawCall(commandBuffer, call_info.index, VkDumpDrawCallType::kDispatch);
    }

    virtual void Process_vkCmdDispatchBase(const ApiCallInfo& call_info,
                                           format::HandleId   commandBuffer,
                                           uint32_t           baseGroupX,
                                           uint32_t           baseGroupY,
                                           uint32_t           baseGroupZ,
                                           uint32_t           groupCountX,
                                           uint32_t           groupCountY,
                                           uint32_t           groupCountZ) override
    {
        DrawCall(commandBuffer, call_info.index, VkDumpDrawCallType::kDispatch);
    }

    virtual void Process_vkCmdDispatchBaseKHR(const ApiCallInfo& call_info,
                                              format::HandleId   commandBuffer,
                                              uint32_t           baseGroupX,
                                              uint32_t           baseGroupY,
                                              uint32_t           baseGroupZ,
                                              uint32_t           groupCountX,
                                              uint32_t           groupCountY,
                                              uint32_t           groupCountZ) override
    {
        DrawCall(commandBuffer, call_info.index, VkDumpDrawCallType::kDispatch);
    }

    virtual void Process_vkCmdTraceRaysKHR(
        const ApiCallInfo&                                             call_info,
        format::HandleId                                               commandBuffer,
        StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pRaygenShaderBindingTable,
        StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pMissShaderBindingTable,
        StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pHitShaderBindingTable,
        StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pCallableShaderBindingTable,
        uint32_t                                                       width,
        uint32_t                                                       height,
        uint32_t                                                       depth) override
    {
        DrawCall(commandBuffer, call_info.index, VkDumpDrawCallType::kTraceRays);
    }

    virtual void Process_vkCmdTraceRaysNV(const ApiCallInfo& call_info,
                                          format::HandleId   commandBuffer,
                                          format::HandleId   raygenShaderBindingTableBuffer,
                                          VkDeviceSize       raygenShaderBindingOffset,
                                          format::HandleId   missShaderBindingTableBuffer,
                                          VkDeviceSize       missShaderBindingOffset,
                                          VkDeviceSize       missShaderBindingStride,
                                          format::HandleId   hitShaderBindingTableBuffer,
                                          VkDeviceSize       hitShaderBindingOffset,
                                          VkDeviceSize       hitShaderBindingStride,
                                          format::HandleId   callableShaderBindingTableBuffer,
                                          VkDeviceSize       callableShaderBindingOffset,
                                          VkDeviceSize       callableShaderBindingStride,
                                          uint32_t           width,
                                          uint32_t           height,
                                          uint32_t           depth) override
    {
        DrawCall(commandBuffer, call_info.index, VkDumpDrawCallType::kTraceRays);
    }

    virtual void Process_vkCmdTraceRaysIndirectKHR(
        const ApiCallInfo&                                             call_info,
        format::HandleId                                               commandBuffer,
        StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pRaygenShaderBindingTable,
        StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pMissShaderBindingTable,
        StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pHitShaderBindingTable,
        StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pCallableShaderBindingTable,
        VkDeviceAddress                                                indirectDeviceAddress) override
    {
        DrawCall(commandBuffer, call_info.index, VkDumpDrawCallType::kTraceRays);
    }

    virtual void Process_vkCmdTraceRaysIndirect2KHR(const ApiCallInfo& call_info,
                                                    format::HandleId   commandBuffer,
                                                    VkDeviceAddress    indirectDeviceAddress) override
    {
        DrawCall(commandBuffer, call_info.index, VkDumpDrawCallType::kTraceRays);
    }

    virtual bool IsComplete(uint64_t block_index) override
    {
        return check_vulkan_consumer_usage_complete_ && (check_dump_resources_complete_ || !enable_dump_resources_);
    }

  private:
    bool vulkan_consumer_usage_{ false };
    bool check_vulkan_consumer_usage_complete_{ false };

    bool                enable_dump_resources_{ false };
    bool                check_dump_resources_complete_{ false };
    DumpResourcesTarget dump_resources_target_{};
    uint32_t            track_submit_index_{ 0 };
    uint64_t            target_submit_block_index_{ 0 };
    format::HandleId    target_command_buffer_{ format::kNullHandleId };

    std::map<format::HandleId, VkTrackDumpCommandBuffer> track_cmd_buf_infos_;

    void BeginRenderPass(format::HandleId cmd_buf_id, uint64_t block_index)
    {
        auto it = track_cmd_buf_infos_.find(cmd_buf_id);
        if (it != track_cmd_buf_infos_.end())
        {
            it->second.current_begin_render_pass_block_index = block_index;
        }
    }

    void EndRenderPass(format::HandleId cmd_buf_id, uint64_t block_index)
    {
        auto it = track_cmd_buf_infos_.find(cmd_buf_id);
        if (it != track_cmd_buf_infos_.end())
        {
            for (auto& draw_call : it->second.draw_call_indices)
            {
                if (draw_call.type == VkDumpDrawCallType::kDraw &&
                    draw_call.render_pass.begin_block_index == it->second.current_begin_render_pass_block_index)
                {
                    draw_call.render_pass.end_block_index = block_index;
                }
            }
            it->second.current_begin_render_pass_block_index = 0;
            it->second.current_next_sub_pass_block_index     = 0;
        }
    }

    void NextSubpass(format::HandleId cmd_buf_id, uint64_t block_index)
    {
        auto it = track_cmd_buf_infos_.find(cmd_buf_id);
        if (it != track_cmd_buf_infos_.end())
        {
            it->second.current_next_sub_pass_block_index = block_index;
        }
    }

    void DrawCall(format::HandleId cmd_buf_id, uint64_t block_index, VkDumpDrawCallType type)
    {
        auto it = track_cmd_buf_infos_.find(cmd_buf_id);
        if (it != track_cmd_buf_infos_.end())
        {
            VkTrackDumpDrawCall draw_call{};
            draw_call.type        = type;
            draw_call.block_index = block_index;

            switch (type)
            {
                case VkDumpDrawCallType::kDraw:
                    draw_call.render_pass.begin_block_index         = it->second.current_begin_render_pass_block_index;
                    draw_call.render_pass.next_sub_pass_block_index = it->second.current_next_sub_pass_block_index;
                    break;
                default:
                    break;
            }

            it->second.draw_call_indices.emplace_back(draw_call);
        }
    }

    void QueueSubmit(const std::vector<format::HandleId>& cmd_bufs, uint64_t block_index)
    {
        if (track_submit_index_ == dump_resources_target_.submit_index)
        {
            check_dump_resources_complete_ = true;
            target_submit_block_index_     = block_index;

            GFXRECON_ASSERT(cmd_bufs.size() > dump_resources_target_.command_index);
            target_command_buffer_ = cmd_bufs[dump_resources_target_.command_index];
        }
        ++track_submit_index_;
    }
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_PRE_PROCESS_CONSUMER_H