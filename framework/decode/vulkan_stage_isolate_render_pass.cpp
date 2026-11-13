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

#include <vector>
#include <cstring>

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
constexpr uint32_t kStructPointer     = format::kIsStruct | format::kIsSingle | format::kHasAddress | format::kHasData;
constexpr uint32_t kNullStructPointer = format::kIsStruct | format::kIsSingle | format::kIsNull;
constexpr uint32_t kArrayPointer      = format::kIsArray | format::kHasAddress | format::kHasData;
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

void VulkanStageIsolateRenderPass::Split(Recording& recording, const ApiCallInfo& call_info)
{
    recording.split_pending = false;

    const format::HandleId synthetic_id = kSyntheticBit | next_synthetic_id_++;

    Emit(format::ApiCallId::ApiCall_vkEndCommandBuffer, call_info, EndBytes(recording.current_command_buffer_id));
    Emit(format::ApiCallId::ApiCall_vkAllocateCommandBuffers,
         call_info,
         AllocateBytes(recording.device_id, recording.pool_id, synthetic_id));
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

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
