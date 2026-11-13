/*
** Copyright (c) 2026 LunarG, Inc.
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

#include "decode/vulkan_stage_isolate_render_pass.h"

#include "format/format.h"
#include "generated/generated_vulkan_decoder.h"

#include <cstring>
#include <iterator>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

namespace
{

// ByteWriter appends values to a byte vector. Each Put returns the writer, so the calls chain.
class ByteWriter
{
  public:
    template <typename T>
    ByteWriter& Put(T value)
    {
        const auto* first = reinterpret_cast<const uint8_t*>(&value);
        bytes_.insert(bytes_.end(), first, first + sizeof(T));
        return *this;
    }

    const std::vector<uint8_t>& Bytes() const { return bytes_; }

  private:
    std::vector<uint8_t> bytes_;
};

// A pointer starts with an attribute word. An address follows when kHasAddress is set, and the data
// follows when kHasData is set. Array data starts with its length.
constexpr uint32_t kStructPointer      = format::kIsStruct | format::kIsSingle | format::kHasAddress | format::kHasData;
constexpr uint32_t kNullStructPointer  = format::kIsStruct | format::kIsSingle | format::kIsNull;
constexpr uint32_t kArrayPointer       = format::kIsArray | format::kHasAddress | format::kHasData;
constexpr uint32_t kStructArrayPointer = format::kIsStruct | kArrayPointer;

// The decoder reads the address of a pointer, but these calls never use it, so any non-zero value works.
constexpr uint64_t kUnusedAddress = 1;

// Each function below writes the parameters of one call in the order that its Decode_vk* function
// reads them. The result always comes last.

std::vector<uint8_t> EndBytes(format::HandleId command_buffer)
{
    return ByteWriter().Put<format::HandleId>(command_buffer).Put<int32_t>(VK_SUCCESS).Bytes();
}

std::vector<uint8_t> AllocateBytes(format::HandleId device, format::HandleId pool, format::HandleId command_buffer)
{
    return ByteWriter()
        .Put<format::HandleId>(device)                                 // device
        .Put<uint32_t>(kStructPointer)                                 // pAllocateInfo
        .Put<uint64_t>(kUnusedAddress)                                 //   address
        .Put<uint32_t>(VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO) //   sType
        .Put<uint32_t>(kNullStructPointer)                             //   pNext
        .Put<format::HandleId>(pool)                                   //   commandPool
        .Put<uint32_t>(VK_COMMAND_BUFFER_LEVEL_PRIMARY)                //   level
        .Put<uint32_t>(1)                                              //   commandBufferCount
        .Put<uint32_t>(kArrayPointer)                                  // pCommandBuffers
        .Put<uint64_t>(kUnusedAddress)                                 //   address
        .Put<uint64_t>(1)                                              //   array length
        .Put<format::HandleId>(command_buffer)                         //   id
        .Put<int32_t>(VK_SUCCESS)                                      // result
        .Bytes();
}

// The pCommandBuffers array of a VkSubmitInfo.
std::vector<uint8_t> CommandBufferIdArrayBytes(std::span<const format::HandleId> command_buffer_ids)
{
    ByteWriter writer;
    writer.Put<uint32_t>(kArrayPointer).Put<uint64_t>(kUnusedAddress).Put<uint64_t>(command_buffer_ids.size());
    for (const format::HandleId command_buffer_id : command_buffer_ids)
    {
        writer.Put<format::HandleId>(command_buffer_id);
    }
    return writer.Bytes();
}

// One entry of the pCommandBufferInfos array of a VkSubmitInfo2. It holds the capture id of the command buffer,
// because VkCommandBufferSubmitInfo holds a driver handle, and replay maps the id to the handle later.
struct CommandBufferInfo
{
    format::HandleId command_buffer_id = format::kNullHandleId;
    uint32_t         device_mask       = 0;
};

// The pCommandBufferInfos array of a VkSubmitInfo2.
std::vector<uint8_t> CommandBufferInfoArrayBytes(std::span<const CommandBufferInfo> command_buffer_infos)
{
    ByteWriter writer;
    writer.Put<uint32_t>(kStructArrayPointer).Put<uint64_t>(kUnusedAddress).Put<uint64_t>(command_buffer_infos.size());
    for (const CommandBufferInfo& info : command_buffer_infos)
    {
        writer
            .Put<uint32_t>(VK_STRUCTURE_TYPE_COMMAND_BUFFER_SUBMIT_INFO) // sType
            .Put<uint32_t>(kNullStructPointer)                           // pNext
            .Put<format::HandleId>(info.command_buffer_id)               // commandBuffer
            .Put<uint32_t>(info.device_mask);                            // deviceMask
    }
    return writer.Bytes();
}

std::vector<uint8_t> BeginBytes(format::HandleId command_buffer, VkCommandBufferUsageFlags flags)
{
    return ByteWriter()
        .Put<format::HandleId>(command_buffer)                      // commandBuffer
        .Put<uint32_t>(kStructPointer)                              // pBeginInfo
        .Put<uint64_t>(kUnusedAddress)                              //   address
        .Put<uint32_t>(VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO) //   sType
        .Put<uint32_t>(kNullStructPointer)                          //   pNext
        .Put<uint32_t>(flags)                                       //   flags
        .Put<uint32_t>(kNullStructPointer)                          //   pInheritanceInfo
        .Put<int32_t>(VK_SUCCESS)                                   // result
        .Bytes();
}

} // namespace

// Command pools

void VulkanStageIsolateRenderPass::Process_vkCreateCommandPool(const ApiCallInfo&       call_info,
                                                               args::CreateCommandPool& args)
{
    const format::HandleId         command_pool_id = *args.pCommandPool.GetPointer();
    const VkCommandPoolCreateFlags flags           = args.pCreateInfo.GetPointer()->flags;
    pool_info_map_[command_pool_id].reset_bit      = (flags & VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT) != 0;

    Forward(call_info, args);
}

void VulkanStageIsolateRenderPass::Process_vkDestroyCommandPool(const ApiCallInfo&        call_info,
                                                                args::DestroyCommandPool& args)
{
    // Destroying a pool frees its command buffers, and replay frees the parts as children of the pool.
    std::erase_if(command_buffer_to_recording_map_,
                  [&args](const auto& entry) { return entry.second.pool_id == args.commandPool; });
    pool_info_map_.erase(args.commandPool);

    Forward(call_info, args);
}

void VulkanStageIsolateRenderPass::Process_vkResetCommandPool(const ApiCallInfo&      call_info,
                                                              args::ResetCommandPool& args)
{
    // Release the recording of every command buffer of this pool.
    for (auto& [command_buffer_id, recording] : command_buffer_to_recording_map_)
    {
        if (recording.pool_id == args.commandPool)
        {
            Release(recording);
        }
    }

    // After a reset we can move all dirty command buffers to the spare list for reuse.
    auto& pool_info = pool_info_map_[args.commandPool];
    pool_info.spare_command_buffer_ids.insert(pool_info.spare_command_buffer_ids.end(),
                                              pool_info.dirty_command_buffer_ids.begin(),
                                              pool_info.dirty_command_buffer_ids.end());
    pool_info.dirty_command_buffer_ids.clear();

    Forward(call_info, args);
}

// Command buffers

void VulkanStageIsolateRenderPass::Process_vkAllocateCommandBuffers(const ApiCallInfo&            call_info,
                                                                    args::AllocateCommandBuffers& args)
{
    const auto* allocate_info = args.pAllocateInfo.GetMetaStructPointer();

    // vkCmdBeginRenderPass is valid only in a primary command buffer, so only primaries are tracked.
    // Commands on a secondary find no recording and pass through unchanged.
    if (allocate_info->decoded_value->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY)
    {
        const format::HandleId pool_id = allocate_info->commandPool;
        for (const format::HandleId command_buffer_id : args.pCommandBuffers.GetSpan())
        {
            command_buffer_to_recording_map_[command_buffer_id] = Recording{ args.device, pool_id };
        }
    }

    Forward(call_info, args);
}

void VulkanStageIsolateRenderPass::Process_vkFreeCommandBuffers(const ApiCallInfo&        call_info,
                                                                args::FreeCommandBuffers& args)
{
    for (const format::HandleId command_buffer_id : args.pCommandBuffers.GetSpan())
    {
        if (auto entry = command_buffer_to_recording_map_.find(command_buffer_id);
            entry != command_buffer_to_recording_map_.end())
        {
            Release(entry->second);
            command_buffer_to_recording_map_.erase(entry);
        }
    }

    Forward(call_info, args);
}

void VulkanStageIsolateRenderPass::Process_vkResetCommandBuffer(const ApiCallInfo&        call_info,
                                                                args::ResetCommandBuffer& args)
{
    if (auto entry = command_buffer_to_recording_map_.find(args.commandBuffer);
        entry != command_buffer_to_recording_map_.end())
    {
        Release(entry->second);
    }

    Forward(call_info, args);
}

void VulkanStageIsolateRenderPass::Process_vkBeginCommandBuffer(const ApiCallInfo&        call_info,
                                                                args::BeginCommandBuffer& args)
{
    if (auto entry = command_buffer_to_recording_map_.find(args.commandBuffer);
        entry != command_buffer_to_recording_map_.end())
    {
        // Each recording starts in the app's own command buffer.
        Recording& recording = entry->second;
        Release(recording);
        recording.current_command_buffer_id = args.commandBuffer;
        recording.working_command_count     = 0;
        recording.begin_flags               = args.pBeginInfo.GetPointer()->flags;
        recording.split_pending             = false;
    }

    Forward(call_info, args);
}

void VulkanStageIsolateRenderPass::Process_vkEndCommandBuffer(const ApiCallInfo&      call_info,
                                                              args::EndCommandBuffer& args)
{
    if (auto entry = command_buffer_to_recording_map_.find(args.commandBuffer);
        entry != command_buffer_to_recording_map_.end())
    {
        Recording& recording    = entry->second;
        recording.split_pending = false;

        // Explanation of why this works:
        // Case 1, no split happens:
        // - recording.current_command_buffer_id is the original app command buffer id
        //   which means it is just the normal course of events.
        // Case 2, a split has occurred:
        // - original command buffer has already been ended by the split
        // - recording.current_command_buffer_id is the new synthetic command buffer id
        //   which must be ended, so we redirect the End call to it.
        args.commandBuffer = recording.current_command_buffer_id;
    }

    Forward(call_info, args);
}

void VulkanStageIsolateRenderPass::OnCommand(const ApiCallInfo& call_info, format::HandleId& command_buffer_id)
{
    if (auto entry = command_buffer_to_recording_map_.find(command_buffer_id);
        entry != command_buffer_to_recording_map_.end())
    {
        Recording& recording = entry->second;

        if (recording.split_pending)
        {
            Split(recording, call_info);
        }

        recording.working_command_count++;

        // Send the command to the current part. Before the first split, the current part is
        // the app's own command buffer.
        command_buffer_id = recording.current_command_buffer_id;
    }
}

// Render passes

template <typename ArgsT>
void VulkanStageIsolateRenderPass::ProcessBeginRender(const ApiCallInfo& call_info, ArgsT& args)
{
    if (auto entry = command_buffer_to_recording_map_.find(args.commandBuffer);
        entry != command_buffer_to_recording_map_.end())
    {
        Recording& recording = entry->second;
        // Instead of splitting immediately here, we can set a flag to indicate
        // that a split should occur before the next command.
        // In this case, the next command is expected to be the beginning of a renderpass/rendering.
        recording.split_pending = recording.working_command_count > 0;
    }

    ProcessCommand(call_info, args);
}

template <typename ArgsT>
void VulkanStageIsolateRenderPass::ProcessEndRender(const ApiCallInfo& call_info, ArgsT& args)
{
    // Save the original command buffer ID before processing the command,
    // as `args.commandBuffer` may be modified during processing.
    const format::HandleId original_command_buffer_id = args.commandBuffer;

    ProcessCommand(call_info, args);

    if (auto entry = command_buffer_to_recording_map_.find(original_command_buffer_id);
        entry != command_buffer_to_recording_map_.end())
    {
        Recording& recording = entry->second;
        // Do not split yet, just mark that a split is pending for this recording.
        // Reason is that we might not need to split if the next call is `vkEndCommandBuffer`,
        // or we might want to emit different calls if the next command is `vkBeginRenderPass`
        // in case we want to avoid an empty recording between render passes.
        recording.split_pending = true;
    }
}

void VulkanStageIsolateRenderPass::Process_vkCmdBeginRenderPass(const ApiCallInfo&        call_info,
                                                                args::CmdBeginRenderPass& args)
{
    ProcessBeginRender(call_info, args);
}

void VulkanStageIsolateRenderPass::Process_vkCmdBeginRenderPass2(const ApiCallInfo&         call_info,
                                                                 args::CmdBeginRenderPass2& args)
{
    ProcessBeginRender(call_info, args);
}

void VulkanStageIsolateRenderPass::Process_vkCmdBeginRenderPass2KHR(const ApiCallInfo&            call_info,
                                                                    args::CmdBeginRenderPass2KHR& args)
{
    ProcessBeginRender(call_info, args);
}

void VulkanStageIsolateRenderPass::Process_vkCmdBeginRendering(const ApiCallInfo&       call_info,
                                                               args::CmdBeginRendering& args)
{
    ProcessBeginRender(call_info, args);
}

void VulkanStageIsolateRenderPass::Process_vkCmdBeginRenderingKHR(const ApiCallInfo&          call_info,
                                                                  args::CmdBeginRenderingKHR& args)
{
    ProcessBeginRender(call_info, args);
}

void VulkanStageIsolateRenderPass::Process_vkCmdEndRenderPass(const ApiCallInfo&      call_info,
                                                              args::CmdEndRenderPass& args)
{
    ProcessEndRender(call_info, args);
}

void VulkanStageIsolateRenderPass::Process_vkCmdEndRenderPass2(const ApiCallInfo&       call_info,
                                                               args::CmdEndRenderPass2& args)
{
    ProcessEndRender(call_info, args);
}

void VulkanStageIsolateRenderPass::Process_vkCmdEndRenderPass2KHR(const ApiCallInfo&          call_info,
                                                                  args::CmdEndRenderPass2KHR& args)
{
    ProcessEndRender(call_info, args);
}

void VulkanStageIsolateRenderPass::Process_vkCmdEndRendering(const ApiCallInfo& call_info, args::CmdEndRendering& args)
{
    ProcessEndRender(call_info, args);
}

void VulkanStageIsolateRenderPass::Process_vkCmdEndRenderingKHR(const ApiCallInfo&        call_info,
                                                                args::CmdEndRenderingKHR& args)
{
    ProcessEndRender(call_info, args);
}

// State commands

template <typename ArgsT>
void VulkanStageIsolateRenderPass::ProcessStateCommand(const ApiCallInfo& call_info, ArgsT& args)
{
    if (auto entry = command_buffer_to_recording_map_.find(args.commandBuffer);
        entry != command_buffer_to_recording_map_.end())
    {
        Recording& recording = entry->second;

        if (recording.split_pending)
        {
            Split(recording, call_info);
        }

        // Append the current call to the recording's state log.
        auto& bytes = GetCurrentCallBytes();
        recording.state_log.Append(bytes.call_id, call_info, bytes.parameter_buffer, bytes.buffer_size);

        args.commandBuffer = recording.current_command_buffer_id;
    }

    Forward(call_info, args);
}

void VulkanStageIsolateRenderPass::Process_vkCmdBindPipeline(const ApiCallInfo& call_info, args::CmdBindPipeline& args)
{
    ProcessStateCommand(call_info, args);
}

void VulkanStageIsolateRenderPass::Process_vkCmdBindDescriptorSets(const ApiCallInfo&           call_info,
                                                                   args::CmdBindDescriptorSets& args)
{
    ProcessStateCommand(call_info, args);
}

void VulkanStageIsolateRenderPass::Process_vkCmdBindIndexBuffer(const ApiCallInfo&        call_info,
                                                                args::CmdBindIndexBuffer& args)
{
    ProcessStateCommand(call_info, args);
}

void VulkanStageIsolateRenderPass::Process_vkCmdBindVertexBuffers(const ApiCallInfo&          call_info,
                                                                  args::CmdBindVertexBuffers& args)
{
    ProcessStateCommand(call_info, args);
}

void VulkanStageIsolateRenderPass::Process_vkCmdSetViewport(const ApiCallInfo& call_info, args::CmdSetViewport& args)
{
    ProcessStateCommand(call_info, args);
}

void VulkanStageIsolateRenderPass::Process_vkCmdSetScissor(const ApiCallInfo& call_info, args::CmdSetScissor& args)
{
    ProcessStateCommand(call_info, args);
}

void VulkanStageIsolateRenderPass::Process_vkCmdPushConstants(const ApiCallInfo&      call_info,
                                                              args::CmdPushConstants& args)
{
    ProcessStateCommand(call_info, args);
}

// Helpers

void VulkanStageIsolateRenderPass::Split(Recording& recording, const ApiCallInfo& call_info)
{
    recording.split_pending = false;

    Emit(format::ApiCallId::ApiCall_vkEndCommandBuffer, call_info, EndBytes(recording.current_command_buffer_id));

    format::HandleId synthetic_id = format::kNullHandleId;

    // There might be a spare command buffer that we can reuse in the pool.
    auto& pool_info = pool_info_map_[recording.pool_id];
    if (!pool_info.spare_command_buffer_ids.empty())
    {
        synthetic_id = pool_info.spare_command_buffer_ids.back();
        pool_info.spare_command_buffer_ids.pop_back();
    }
    else
    {
        // No spare command buffer available, allocate a new one.
        synthetic_id = kSyntheticBit | next_synthetic_id_++;
        Emit(format::ApiCallId::ApiCall_vkAllocateCommandBuffers,
             call_info,
             AllocateBytes(recording.device_id, recording.pool_id, synthetic_id));
    }

    Emit(format::ApiCallId::ApiCall_vkBeginCommandBuffer, call_info, BeginBytes(synthetic_id, recording.begin_flags));

    recording.previous_command_buffer_ids.push_back(recording.current_command_buffer_id);
    recording.current_command_buffer_id = synthetic_id;
    recording.working_command_count     = 0;

    ReissueStateCommands(recording);
}

void VulkanStageIsolateRenderPass::ReissueStateCommands(const Recording& recording)
{
    recording.state_log.ForEach([this, &recording](format::ApiCallId  call_id,
                                                   const ApiCallInfo& call_info,
                                                   const uint8_t*     parameter_buffer,
                                                   size_t             buffer_size) {
        std::vector<uint8_t> modified_buffer(parameter_buffer, parameter_buffer + buffer_size);
        // First 8 bytes of the parameter buffer contain the original command buffer ID.
        // Before emitting the state commands, overwrite it with the current command buffer ID.
        GFXRECON_ASSERT(buffer_size >= sizeof(format::HandleId));
        std::memcpy(modified_buffer.data(), &recording.current_command_buffer_id, sizeof(format::HandleId));

        Emit(call_id, call_info, modified_buffer);
    });
}

void VulkanStageIsolateRenderPass::Emit(format::ApiCallId        call_id,
                                        const ApiCallInfo&       call_info,
                                        std::span<const uint8_t> bytes)
{
    // The local decoder hands the call to the next consumers only, so the call never comes back into this stage.
    VulkanDecoder decoder;
    for (auto* consumer : GetNextConsumers())
    {
        decoder.AddConsumer(consumer);
    }

    // Emit opens no DecoderAllocGuard, because the app call's allocator scope is still open
    // and a nested Begin asserts.
    decoder.DecodeFunctionCall(call_id, call_info, bytes.data(), bytes.size());

    // The local decoder gave the next consumers the bytes of the invented call. Give them back the bytes
    // of the app call, because the stage forwards that call next.
    Broadcast(&VulkanConsumer::SetCurrentCallBytes, GetCurrentCallBytes());
}

bool VulkanStageIsolateRenderPass::AppendCommandBufferIdsToSubmit(format::HandleId               app_command_buffer_id,
                                                                  std::vector<format::HandleId>& ids_to_submit) const
{
    if (auto entry = command_buffer_to_recording_map_.find(app_command_buffer_id);
        entry != command_buffer_to_recording_map_.end())
    {
        const Recording& recording = entry->second;
        if (!recording.previous_command_buffer_ids.empty())
        {
            ids_to_submit.insert(ids_to_submit.end(),
                                 recording.previous_command_buffer_ids.begin(),
                                 recording.previous_command_buffer_ids.end());
            ids_to_submit.push_back(recording.current_command_buffer_id);
            return true;
        }
    }

    ids_to_submit.push_back(app_command_buffer_id);
    return false;
}

void VulkanStageIsolateRenderPass::Process_vkQueueSubmit(const ApiCallInfo& call_info, args::QueueSubmit& args)
{
    // Patch the command buffer array of each submit info to account for any command buffer splits.
    for (uint32_t submit_index = 0; submit_index < args.submitCount; ++submit_index)
    {
        Decoded_VkSubmitInfo& meta_submit_info   = args.pSubmits.GetMetaStructPointer()[submit_index];
        VkSubmitInfo&         native_submit_info = args.pSubmits.GetPointer()[submit_index];

        std::vector<format::HandleId> ids_to_submit;
        bool                          any_split = false;
        for (const format::HandleId app_command_buffer_id : meta_submit_info.pCommandBuffers.GetSpan())
        {
            any_split |= AppendCommandBufferIdsToSubmit(app_command_buffer_id, ids_to_submit);
        }

        if (!any_split)
        {
            continue;
        }

        // Decode() copies the ids into the arena, so the bytes can be a local.
        const std::vector<uint8_t> command_buffer_ids_bytes = CommandBufferIdArrayBytes(ids_to_submit);
        meta_submit_info.pCommandBuffers                    = HandlePointerDecoder<VkCommandBuffer>();
        meta_submit_info.pCommandBuffers.Decode(command_buffer_ids_bytes.data(), command_buffer_ids_bytes.size());

        // Replay fills native_submit_info.pCommandBuffers later, when MapHandleArray() maps the meta ids.
        // That does not change commandBufferCount, so the stage sets it here.
        native_submit_info.commandBufferCount = static_cast<uint32_t>(ids_to_submit.size());
    }

    Forward(call_info, args);
}

template <typename ArgsT>
void VulkanStageIsolateRenderPass::ProcessQueueSubmit2(const ApiCallInfo& call_info, ArgsT& args)
{
    // Patch the command buffer infos of each submit info to account for any command buffer splits.
    for (uint32_t submit_index = 0; submit_index < args.submitCount; ++submit_index)
    {
        Decoded_VkSubmitInfo2& meta_submit_info   = args.pSubmits.GetMetaStructPointer()[submit_index];
        VkSubmitInfo2&         native_submit_info = args.pSubmits.GetPointer()[submit_index];

        std::vector<CommandBufferInfo> infos_to_submit;
        std::vector<format::HandleId>  ids_to_submit;
        bool                           any_split = false;
        for (const Decoded_VkCommandBufferSubmitInfo& app_info :
             meta_submit_info.pCommandBufferInfos->GetMetaStructSpan())
        {
            ids_to_submit.clear();
            any_split |= AppendCommandBufferIdsToSubmit(app_info.commandBuffer, ids_to_submit);

            // Every command buffer of a split recording takes the device mask of the app's entry.
            for (const format::HandleId command_buffer_id : ids_to_submit)
            {
                infos_to_submit.push_back({ command_buffer_id, app_info.decoded_value->deviceMask });
            }
        }

        if (!any_split)
        {
            continue;
        }

        // Decoded_VkSubmitInfo2 points to its decoder, so the new decoder must live in the arena until the call
        // has been forwarded.
        const std::vector<uint8_t> command_buffer_infos_bytes = CommandBufferInfoArrayBytes(infos_to_submit);
        auto*                      command_buffer_infos =
            DecodeAllocator::Allocate<StructPointerDecoder<Decoded_VkCommandBufferSubmitInfo>>();
        command_buffer_infos->Decode(command_buffer_infos_bytes.data(), command_buffer_infos_bytes.size());

        meta_submit_info.pCommandBufferInfos      = command_buffer_infos;
        native_submit_info.commandBufferInfoCount = static_cast<uint32_t>(infos_to_submit.size());
        native_submit_info.pCommandBufferInfos    = command_buffer_infos->GetPointer();
    }

    Forward(call_info, args);
}

void VulkanStageIsolateRenderPass::Process_vkQueueSubmit2(const ApiCallInfo& call_info, args::QueueSubmit2& args)
{
    ProcessQueueSubmit2(call_info, args);
}

void VulkanStageIsolateRenderPass::Process_vkQueueSubmit2KHR(const ApiCallInfo& call_info, args::QueueSubmit2KHR& args)
{
    ProcessQueueSubmit2(call_info, args);
}

void VulkanStageIsolateRenderPass::Release(Recording& recording)
{
    if (!recording.previous_command_buffer_ids.empty())
    {
        // Every part except the first, which is the app's own command buffer, goes back to the pool.
        auto& pool_info = pool_info_map_[recording.pool_id];
        auto& destination =
            pool_info.reset_bit ? pool_info.spare_command_buffer_ids : pool_info.dirty_command_buffer_ids;
        destination.insert(destination.end(),
                           std::next(recording.previous_command_buffer_ids.begin()),
                           recording.previous_command_buffer_ids.end());
        destination.push_back(recording.current_command_buffer_id);

        recording.current_command_buffer_id = recording.previous_command_buffer_ids.front();
        recording.previous_command_buffer_ids.clear();
    }

    recording.state_log.Clear();
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
