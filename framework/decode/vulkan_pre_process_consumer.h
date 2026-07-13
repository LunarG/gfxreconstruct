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
#include "generated/generated_vulkan_decoder_args.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

const std::string DUMP_ARG_BEGIN_COMMAND_BUFFER = "BeginCommandBuffer";
const std::string DUMP_ARG_TRANSFER             = "Transfer";
const std::string DUMP_ARG_DRAW                 = "Draw";
const std::string DUMP_ARG_RENDER_PASS          = "RenderPass";
const std::string DUMP_ARG_BEGIN_RENDER_PASS    = "BeginRenderPass";
const std::string DUMP_ARG_NEXT_SUB_PASS        = "NextSubPass";
const std::string DUMP_ARG_END_RENDER_PASS      = "EndRenderPass";
const std::string DUMP_ARG_DISPATCH             = "Dispatch";
const std::string DUMP_ARG_TRACE_RAYS           = "TraceRays";
const std::string DUMP_ARG_QUEUE_SUBMIT         = "QueueSubmit";
const std::string DUMP_ARG_EXECUTE_COMMANDS     = "ExecuteCommands";

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

    void Process_vkCreateDevice(const ApiCallInfo& call_info, args::CreateDevice& args) override
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

    virtual void Process_vkAllocateCommandBuffers(const ApiCallInfo&            call_info,
                                                  args::AllocateCommandBuffers& args) override
    {
        auto                     cmd_buf_handle_id = args.pCommandBuffers.GetPointer();
        VkTrackDumpCommandBuffer cmd_buf_info{};
        track_cmd_buf_infos_[*cmd_buf_handle_id] = cmd_buf_info;
    }

    virtual void Process_vkResetCommandBuffer(const ApiCallInfo& call_info, args::ResetCommandBuffer& args) override
    {
        auto it = track_cmd_buf_infos_.find(args.commandBuffer);
        if (it != track_cmd_buf_infos_.end())
        {
            it->second.Clear();
        }
    }

    virtual void Process_vkBeginCommandBuffer(const ApiCallInfo& call_info, args::BeginCommandBuffer& args) override
    {
        auto it = track_cmd_buf_infos_.find(args.commandBuffer);
        if (it != track_cmd_buf_infos_.end())
        {
            it->second.begin_block_index = call_info.index;
        }
    }

    virtual void Process_vkCmdBeginRenderPass(const ApiCallInfo& call_info, args::CmdBeginRenderPass& args) override
    {
        BeginRenderPass(args.commandBuffer, call_info.index);
    }

    virtual void Process_vkCmdBeginRenderPass2(const ApiCallInfo& call_info, args::CmdBeginRenderPass2& args) override
    {
        BeginRenderPass(args.commandBuffer, call_info.index);
    }

    virtual void Process_vkCmdEndRenderPass(const ApiCallInfo& call_info, args::CmdEndRenderPass& args) override
    {
        EndRenderPass(args.commandBuffer, call_info.index);
    }

    virtual void Process_vkCmdEndRenderPass2(const ApiCallInfo& call_info, args::CmdEndRenderPass2& args) override
    {
        EndRenderPass(args.commandBuffer, call_info.index);
    }

    virtual void Process_vkCmdNextSubpass(const ApiCallInfo& call_info, args::CmdNextSubpass& args) override
    {
        NextSubpass(args.commandBuffer, call_info.index);
    }

    virtual void Process_vkCmdNextSubpass2(const ApiCallInfo& call_info, args::CmdNextSubpass2& args) override
    {
        NextSubpass(args.commandBuffer, call_info.index);
    }

    virtual void Process_vkQueueSubmit(const ApiCallInfo& call_info, args::QueueSubmit& args) override
    {
        std::vector<format::HandleId> cmd_bufs;
        auto                          submit_info_data = args.pSubmits.GetMetaStructPointer();
        for (auto i = 0; i < args.submitCount; ++i)
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

    virtual void Process_vkQueueSubmit2(const ApiCallInfo& call_info, args::QueueSubmit2& args) override
    {
        std::vector<format::HandleId> cmd_bufs;
        auto                          submit_info_data = args.pSubmits.GetMetaStructPointer();
        for (auto i = 0; i < args.submitCount; ++i)
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

    virtual void Process_vkQueueSubmit2KHR(const ApiCallInfo& call_info, args::QueueSubmit2KHR& args) override
    {
        std::vector<format::HandleId> cmd_bufs;
        auto                          submit_info_data = args.pSubmits.GetMetaStructPointer();
        for (auto i = 0; i < args.submitCount; ++i)
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

    virtual void Process_vkCmdDraw(const ApiCallInfo& call_info, args::CmdDraw& args) override
    {
        DrawCall(args.commandBuffer, call_info.index, VkDumpDrawCallType::kDraw);
    }

    virtual void Process_vkCmdDrawIndexed(const ApiCallInfo& call_info, args::CmdDrawIndexed& args) override
    {
        DrawCall(args.commandBuffer, call_info.index, VkDumpDrawCallType::kDraw);
    }

    virtual void Process_vkCmdDrawIndirect(const ApiCallInfo& call_info, args::CmdDrawIndirect& args) override
    {
        DrawCall(args.commandBuffer, call_info.index, VkDumpDrawCallType::kDraw);
    }

    virtual void Process_vkCmdDrawIndexedIndirect(const ApiCallInfo&            call_info,
                                                  args::CmdDrawIndexedIndirect& args) override
    {
        DrawCall(args.commandBuffer, call_info.index, VkDumpDrawCallType::kDraw);
    }

    virtual void Process_vkCmdDrawIndirectCount(const ApiCallInfo& call_info, args::CmdDrawIndirectCount& args) override
    {
        DrawCall(args.commandBuffer, call_info.index, VkDumpDrawCallType::kDraw);
    }

    virtual void Process_vkCmdDrawIndirectCountKHR(const ApiCallInfo&             call_info,
                                                   args::CmdDrawIndirectCountKHR& args) override
    {
        DrawCall(args.commandBuffer, call_info.index, VkDumpDrawCallType::kDraw);
    }

    virtual void Process_vkCmdDrawIndexedIndirectCount(const ApiCallInfo&                 call_info,
                                                       args::CmdDrawIndexedIndirectCount& args) override
    {
        DrawCall(args.commandBuffer, call_info.index, VkDumpDrawCallType::kDraw);
    }

    virtual void Process_vkCmdDrawIndexedIndirectCountKHR(const ApiCallInfo&                    call_info,
                                                          args::CmdDrawIndexedIndirectCountKHR& args) override
    {
        DrawCall(args.commandBuffer, call_info.index, VkDumpDrawCallType::kDraw);
    }

    virtual void Process_vkCmdDrawIndirectByteCountEXT(const ApiCallInfo&                 call_info,
                                                       args::CmdDrawIndirectByteCountEXT& args) override
    {
        DrawCall(args.commandBuffer, call_info.index, VkDumpDrawCallType::kDraw);
    }

    virtual void Process_vkCmdDrawIndirectCountAMD(const ApiCallInfo&             call_info,
                                                   args::CmdDrawIndirectCountAMD& args) override
    {
        DrawCall(args.commandBuffer, call_info.index, VkDumpDrawCallType::kDraw);
    }

    virtual void Process_vkCmdDrawIndexedIndirectCountAMD(const ApiCallInfo&                    call_info,
                                                          args::CmdDrawIndexedIndirectCountAMD& args) override
    {
        DrawCall(args.commandBuffer, call_info.index, VkDumpDrawCallType::kDraw);
    }

    virtual void Process_vkCmdDrawMeshTasksEXT(const ApiCallInfo& call_info, args::CmdDrawMeshTasksEXT& args) override
    {
        DrawCall(args.commandBuffer, call_info.index, VkDumpDrawCallType::kDraw);
    }

    virtual void Process_vkCmdDrawMeshTasksNV(const ApiCallInfo& call_info, args::CmdDrawMeshTasksNV& args) override
    {
        DrawCall(args.commandBuffer, call_info.index, VkDumpDrawCallType::kDraw);
    }

    virtual void Process_vkCmdDrawMeshTasksIndirectEXT(const ApiCallInfo&                 call_info,
                                                       args::CmdDrawMeshTasksIndirectEXT& args) override
    {
        DrawCall(args.commandBuffer, call_info.index, VkDumpDrawCallType::kDraw);
    }

    virtual void Process_vkCmdDrawMeshTasksIndirectNV(const ApiCallInfo&                call_info,
                                                      args::CmdDrawMeshTasksIndirectNV& args) override
    {
        DrawCall(args.commandBuffer, call_info.index, VkDumpDrawCallType::kDraw);
    }

    virtual void Process_vkCmdDrawMeshTasksIndirectCountEXT(const ApiCallInfo&                      call_info,
                                                            args::CmdDrawMeshTasksIndirectCountEXT& args) override
    {
        DrawCall(args.commandBuffer, call_info.index, VkDumpDrawCallType::kDraw);
    }

    virtual void Process_vkCmdDrawMeshTasksIndirectCountNV(const ApiCallInfo&                     call_info,
                                                           args::CmdDrawMeshTasksIndirectCountNV& args) override
    {
        DrawCall(args.commandBuffer, call_info.index, VkDumpDrawCallType::kDraw);
    }

    virtual void Process_vkCmdDrawMultiEXT(const ApiCallInfo& call_info, args::CmdDrawMultiEXT& args) override
    {
        DrawCall(args.commandBuffer, call_info.index, VkDumpDrawCallType::kDraw);
    }

    virtual void Process_vkCmdDrawMultiIndexedEXT(const ApiCallInfo&            call_info,
                                                  args::CmdDrawMultiIndexedEXT& args) override
    {
        DrawCall(args.commandBuffer, call_info.index, VkDumpDrawCallType::kDraw);
    }

    virtual void Process_vkCmdDrawClusterHUAWEI(const ApiCallInfo& call_info, args::CmdDrawClusterHUAWEI& args) override
    {
        DrawCall(args.commandBuffer, call_info.index, VkDumpDrawCallType::kDraw);
    }

    virtual void Process_vkCmdDrawClusterIndirectHUAWEI(const ApiCallInfo&                  call_info,
                                                        args::CmdDrawClusterIndirectHUAWEI& args) override
    {
        DrawCall(args.commandBuffer, call_info.index, VkDumpDrawCallType::kDraw);
    }

    virtual void Process_vkCmdDispatch(const ApiCallInfo& call_info, args::CmdDispatch& args) override
    {
        DrawCall(args.commandBuffer, call_info.index, VkDumpDrawCallType::kDispatch);
    }

    virtual void Process_vkCmdDispatchIndirect(const ApiCallInfo& call_info, args::CmdDispatchIndirect& args) override
    {
        DrawCall(args.commandBuffer, call_info.index, VkDumpDrawCallType::kDispatch);
    }

    virtual void Process_vkCmdDispatchBase(const ApiCallInfo& call_info, args::CmdDispatchBase& args) override
    {
        DrawCall(args.commandBuffer, call_info.index, VkDumpDrawCallType::kDispatch);
    }

    virtual void Process_vkCmdDispatchBaseKHR(const ApiCallInfo& call_info, args::CmdDispatchBaseKHR& args) override
    {
        DrawCall(args.commandBuffer, call_info.index, VkDumpDrawCallType::kDispatch);
    }

    virtual void Process_vkCmdTraceRaysKHR(const ApiCallInfo& call_info, args::CmdTraceRaysKHR& args) override
    {
        DrawCall(args.commandBuffer, call_info.index, VkDumpDrawCallType::kTraceRays);
    }

    virtual void Process_vkCmdTraceRaysNV(const ApiCallInfo& call_info, args::CmdTraceRaysNV& args) override
    {
        DrawCall(args.commandBuffer, call_info.index, VkDumpDrawCallType::kTraceRays);
    }

    virtual void Process_vkCmdTraceRaysIndirectKHR(const ApiCallInfo&             call_info,
                                                   args::CmdTraceRaysIndirectKHR& args) override
    {
        DrawCall(args.commandBuffer, call_info.index, VkDumpDrawCallType::kTraceRays);
    }

    virtual void Process_vkCmdTraceRaysIndirect2KHR(const ApiCallInfo&              call_info,
                                                    args::CmdTraceRaysIndirect2KHR& args) override
    {
        DrawCall(args.commandBuffer, call_info.index, VkDumpDrawCallType::kTraceRays);
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
