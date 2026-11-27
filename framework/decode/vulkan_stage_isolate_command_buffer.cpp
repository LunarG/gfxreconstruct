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

#include "decode/vulkan_stage_isolate_command_buffer.h"

#include "encode/parameter_encoder.h"
#include "format/format.h"
#include "generated/generated_vulkan_enum_to_string.h"
#include "util/memory_output_stream.h"

#include <algorithm>
#include <optional>
#include <span>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

namespace
{

// The stage invents these calls, so they have no app addresses to write.
constexpr bool kOmitAddresses = true;

// One queue submit that the stage sends in place of part of an app call.
struct PlannedSubmit
{
    // Which submit info of the app call this submit comes from.
    size_t submit_info_index = 0;

    // Which command buffer of that submit info this submit takes. Unset when the submit info has none.
    std::optional<size_t> command_buffer_index;

    // Whether this submit carries the waits of its submit info.
    bool waits = false;

    // Whether this submit carries the signals of its submit info.
    bool signals = false;

    // Whether this submit carries the fence of the app call.
    bool fence = false;
};

size_t GetCommandBufferCount(const Decoded_VkSubmitInfo& submit_info)
{
    return submit_info.pCommandBuffers.GetLength();
}

size_t GetCommandBufferCount(const Decoded_VkSubmitInfo2& submit_info)
{
    return submit_info.pCommandBufferInfos->GetLength();
}

// Plans one submit per command buffer, in submission order. A submit info without command buffers gets one
// submit for its waits and signals. The meta structs hold the edits of an earlier stage.
template <typename ArgsT>
std::vector<PlannedSubmit> PlanSubmits(const ArgsT& args)
{
    std::vector<PlannedSubmit> planned_submits;

    const auto submit_infos = args.pSubmits.GetMetaStructSpan();
    for (size_t submit_info_index = 0; submit_info_index < submit_infos.size(); ++submit_info_index)
    {
        const size_t command_buffer_count = GetCommandBufferCount(submit_infos[submit_info_index]);
        const size_t submit_count         = std::max<size_t>(command_buffer_count, 1);
        for (size_t index = 0; index < submit_count; ++index)
        {
            PlannedSubmit planned_submit;
            planned_submit.submit_info_index = submit_info_index;
            planned_submit.waits             = (index == 0);
            planned_submit.signals           = (index == submit_count - 1);
            if (command_buffer_count > 0)
            {
                planned_submit.command_buffer_index = index;
            }
            planned_submits.push_back(planned_submit);
        }
    }

    if (!planned_submits.empty())
    {
        planned_submits.back().fence = true;
    }

    return planned_submits;
}

void WarnAboutDroppedStructs(const PNextNode* pnext)
{
    while (pnext != nullptr)
    {
        const auto* header = reinterpret_cast<const VulkanMetaStructHeader*>(pnext->GetMetaStructPointer());
        if (*header->sType != util::GetSType<Decoded_VkTimelineSemaphoreSubmitInfo::struct_type>() &&
            *header->sType != util::GetSType<Decoded_VkFrameBoundaryEXT::struct_type>())
        {
            GFXRECON_LOG_WARNING_ONCE("Isolating command buffers drops %s from a pNext chain of a queue submit",
                                      util::ToString(*header->sType).c_str());
        }
        pnext = header->pNext;
    }
}

void WarnAboutSuspendedRenderPass(const StructPointerDecoder<Decoded_VkRenderingInfo>& rendering_info)
{
    const VkRenderingInfo* info = rendering_info.GetPointer();
    if ((info != nullptr) && ((info->flags & (VK_RENDERING_SUSPENDING_BIT | VK_RENDERING_RESUMING_BIT)) != 0))
    {
        GFXRECON_LOG_WARNING_ONCE("Isolating command buffers may break a render pass that is suspended in one command "
                                  "buffer and resumed in another, because they are submitted in separate calls");
    }
}

// A frame boundary goes with the signals, because replay ends a frame at each boundary that it finds.
const Decoded_VkFrameBoundaryEXT* GetFrameBoundary(const PNextNode* pnext, const PlannedSubmit& planned_submit)
{
    return planned_submit.signals ? GetPNextMetaStruct<Decoded_VkFrameBoundaryEXT>(pnext) : nullptr;
}

// Writes the struct, or a null pointer when boundary is null.
void EncodeFrameBoundary(encode::ParameterEncoder& encoder, const Decoded_VkFrameBoundaryEXT* boundary)
{
    encoder.EncodeStructPtrPreamble(boundary);
    if (boundary == nullptr)
    {
        return;
    }

    const VkFrameBoundaryEXT& value   = *boundary->decoded_value;
    const auto                images  = boundary->pImages.GetSpan();
    const auto                buffers = boundary->pBuffers.GetSpan();
    const auto                tag     = boundary->pTag.GetSpan();

    encoder.EncodeEnumValue(VK_STRUCTURE_TYPE_FRAME_BOUNDARY_EXT); // sType
    encoder.EncodeStructPtrPreamble(nullptr);                      // pNext
    encoder.EncodeFlagsValue(value.flags);                         // flags
    encoder.EncodeUInt64Value(value.frameID);                      // frameID
    encoder.EncodeUInt32Value(value.imageCount);                   // imageCount
    encoder.EncodeHandleIdArray(images.data(), images.size());     // pImages
    encoder.EncodeUInt32Value(value.bufferCount);                  // bufferCount
    encoder.EncodeHandleIdArray(buffers.data(), buffers.size());   // pBuffers
    encoder.EncodeUInt64Value(value.tagName);                      // tagName
    encoder.EncodeSizeTValue(value.tagSize);                       // tagSize
    encoder.EncodeVoidArray(tag.data(), tag.size());               // pTag
}

void EncodeSubmitInfo(encode::ParameterEncoder&   encoder,
                      const Decoded_VkSubmitInfo& submit_info,
                      const PlannedSubmit&        planned_submit)
{
    WarnAboutDroppedStructs(submit_info.pNext);

    const auto* timeline       = GetPNextMetaStruct<Decoded_VkTimelineSemaphoreSubmitInfo>(submit_info.pNext);
    const auto* frame_boundary = GetFrameBoundary(submit_info.pNext, planned_submit);

    encoder.EncodeEnumValue(VK_STRUCTURE_TYPE_SUBMIT_INFO); // sType

    if (timeline != nullptr)
    {
        const VkTimelineSemaphoreSubmitInfo& value         = *timeline->decoded_value;
        const auto                           wait_values   = timeline->pWaitSemaphoreValues.GetSpan();
        const auto                           signal_values = timeline->pSignalSemaphoreValues.GetSpan();

        encoder.EncodeStructPtrPreamble(timeline);                                 // pNext
        encoder.EncodeEnumValue(VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO); // sType
        EncodeFrameBoundary(encoder, frame_boundary);                              // pNext
        encoder.EncodeUInt32Value(value.waitSemaphoreValueCount);                  // waitSemaphoreValueCount
        encoder.EncodeUInt64Array(wait_values.data(), wait_values.size());         // pWaitSemaphoreValues
        encoder.EncodeUInt32Value(value.signalSemaphoreValueCount);                // signalSemaphoreValueCount
        encoder.EncodeUInt64Array(signal_values.data(), signal_values.size());     // pSignalSemaphoreValues
    }
    else
    {
        EncodeFrameBoundary(encoder, frame_boundary); // pNext
    }

    // A default span has a null pointer, so an array that stays empty becomes a null array.
    std::span<const format::HandleId>     wait_semaphores;
    std::span<const VkPipelineStageFlags> wait_stages;
    std::span<const format::HandleId>     command_buffers;
    std::span<const format::HandleId>     signal_semaphores;
    if (planned_submit.waits)
    {
        wait_semaphores = submit_info.pWaitSemaphores.GetSpan();
        wait_stages     = submit_info.pWaitDstStageMask.GetSpan();
    }
    if (planned_submit.command_buffer_index.has_value())
    {
        command_buffers = submit_info.pCommandBuffers.GetSpan().subspan(*planned_submit.command_buffer_index, 1);
    }
    if (planned_submit.signals)
    {
        signal_semaphores = submit_info.pSignalSemaphores.GetSpan();
    }

    encoder.EncodeUInt32Value(static_cast<uint32_t>(wait_semaphores.size()));        // waitSemaphoreCount
    encoder.EncodeHandleIdArray(wait_semaphores.data(), wait_semaphores.size());     // pWaitSemaphores
    encoder.EncodeFlagsArray(wait_stages.data(), wait_stages.size());                // pWaitDstStageMask
    encoder.EncodeUInt32Value(static_cast<uint32_t>(command_buffers.size()));        // commandBufferCount
    encoder.EncodeHandleIdArray(command_buffers.data(), command_buffers.size());     // pCommandBuffers
    encoder.EncodeUInt32Value(static_cast<uint32_t>(signal_semaphores.size()));      // signalSemaphoreCount
    encoder.EncodeHandleIdArray(signal_semaphores.data(), signal_semaphores.size()); // pSignalSemaphores
}

// The ids come from the meta structs. The other values are not handles, so they come from the native structs.

void EncodeSemaphoreInfos(encode::ParameterEncoder&                      encoder,
                          std::span<const Decoded_VkSemaphoreSubmitInfo> semaphore_infos)
{
    encoder.EncodeUInt32Value(static_cast<uint32_t>(semaphore_infos.size()));
    encoder.EncodeStructArrayPreamble(semaphore_infos.data(), semaphore_infos.size());
    for (const Decoded_VkSemaphoreSubmitInfo& info : semaphore_infos)
    {
        encoder.EncodeEnumValue(VK_STRUCTURE_TYPE_SEMAPHORE_SUBMIT_INFO); // sType
        encoder.EncodeStructPtrPreamble(nullptr);                         // pNext
        encoder.EncodeHandleIdValue(info.semaphore);                      // semaphore
        encoder.EncodeUInt64Value(info.decoded_value->value);             // value
        encoder.EncodeFlags64Value(info.decoded_value->stageMask);        // stageMask
        encoder.EncodeUInt32Value(info.decoded_value->deviceIndex);       // deviceIndex
    }
}

void EncodeCommandBufferInfos(encode::ParameterEncoder&                          encoder,
                              std::span<const Decoded_VkCommandBufferSubmitInfo> command_buffer_infos)
{
    encoder.EncodeUInt32Value(static_cast<uint32_t>(command_buffer_infos.size()));
    encoder.EncodeStructArrayPreamble(command_buffer_infos.data(), command_buffer_infos.size());
    for (const Decoded_VkCommandBufferSubmitInfo& info : command_buffer_infos)
    {
        WarnAboutDroppedStructs(info.pNext);

        encoder.EncodeEnumValue(VK_STRUCTURE_TYPE_COMMAND_BUFFER_SUBMIT_INFO); // sType
        encoder.EncodeStructPtrPreamble(nullptr);                              // pNext
        encoder.EncodeHandleIdValue(info.commandBuffer);                       // commandBuffer
        encoder.EncodeUInt32Value(info.decoded_value->deviceMask);             // deviceMask
    }
}

void EncodeSubmitInfo(encode::ParameterEncoder&    encoder,
                      const Decoded_VkSubmitInfo2& submit_info,
                      const PlannedSubmit&         planned_submit)
{
    WarnAboutDroppedStructs(submit_info.pNext);

    // A default span has a null pointer, so an array that stays empty becomes a null array.
    std::span<const Decoded_VkSemaphoreSubmitInfo>     wait_infos;
    std::span<const Decoded_VkCommandBufferSubmitInfo> command_buffer_infos;
    std::span<const Decoded_VkSemaphoreSubmitInfo>     signal_infos;
    if (planned_submit.waits)
    {
        wait_infos = submit_info.pWaitSemaphoreInfos->GetMetaStructSpan();
    }
    if (planned_submit.command_buffer_index.has_value())
    {
        command_buffer_infos =
            submit_info.pCommandBufferInfos->GetMetaStructSpan().subspan(*planned_submit.command_buffer_index, 1);
    }
    if (planned_submit.signals)
    {
        signal_infos = submit_info.pSignalSemaphoreInfos->GetMetaStructSpan();
    }

    encoder.EncodeEnumValue(VK_STRUCTURE_TYPE_SUBMIT_INFO_2);                          // sType
    EncodeFrameBoundary(encoder, GetFrameBoundary(submit_info.pNext, planned_submit)); // pNext
    encoder.EncodeFlagsValue(submit_info.decoded_value->flags);                        // flags
    EncodeSemaphoreInfos(encoder, wait_infos);               // waitSemaphoreInfoCount, pWaitSemaphoreInfos
    EncodeCommandBufferInfos(encoder, command_buffer_infos); // commandBufferInfoCount, pCommandBufferInfos
    EncodeSemaphoreInfos(encoder, signal_infos);             // signalSemaphoreInfoCount, pSignalSemaphoreInfos
}

template <typename ArgsT>
util::MemoryOutputStream EncodeSubmit(const ArgsT& args, const PlannedSubmit& planned_submit)
{
    util::MemoryOutputStream stream;
    encode::ParameterEncoder encoder(&stream, kOmitAddresses);

    const auto& submit_info = args.pSubmits.GetMetaStructSpan()[planned_submit.submit_info_index];

    encoder.EncodeHandleIdValue(args.queue);                                                // queue
    encoder.EncodeUInt32Value(1);                                                           // submitCount
    encoder.EncodeStructArrayPreamble(&submit_info, 1);                                     // pSubmits
    EncodeSubmitInfo(encoder, submit_info, planned_submit);                                 //   the submit info
    encoder.EncodeHandleIdValue(planned_submit.fence ? args.fence : format::kNullHandleId); // fence
    encoder.EncodeEnumValue(args.result);                                                   // result

    return stream;
}

} // namespace

void VulkanStageIsolateCommandBuffer::Process_vkQueueSubmit(const ApiCallInfo& call_info, args::QueueSubmit& args)
{
    ProcessQueueSubmit(format::ApiCallId::ApiCall_vkQueueSubmit, call_info, args);
}

void VulkanStageIsolateCommandBuffer::Process_vkQueueSubmit2(const ApiCallInfo& call_info, args::QueueSubmit2& args)
{
    ProcessQueueSubmit(format::ApiCallId::ApiCall_vkQueueSubmit2, call_info, args);
}

void VulkanStageIsolateCommandBuffer::Process_vkQueueSubmit2KHR(const ApiCallInfo&     call_info,
                                                                args::QueueSubmit2KHR& args)
{
    ProcessQueueSubmit(format::ApiCallId::ApiCall_vkQueueSubmit2KHR, call_info, args);
}

void VulkanStageIsolateCommandBuffer::Process_vkCmdBeginRendering(const ApiCallInfo&       call_info,
                                                                  args::CmdBeginRendering& args)
{
    WarnAboutSuspendedRenderPass(args.pRenderingInfo);
    Forward(call_info, args);
}

void VulkanStageIsolateCommandBuffer::Process_vkCmdBeginRenderingKHR(const ApiCallInfo&          call_info,
                                                                     args::CmdBeginRenderingKHR& args)
{
    WarnAboutSuspendedRenderPass(args.pRenderingInfo);
    Forward(call_info, args);
}

template <typename ArgsT>
void VulkanStageIsolateCommandBuffer::ProcessQueueSubmit(format::ApiCallId  call_id,
                                                         const ApiCallInfo& call_info,
                                                         ArgsT&             args)
{
    const std::vector<PlannedSubmit> planned_submits = PlanSubmits(args);
    if (planned_submits.size() <= 1)
    {
        Forward(call_info, args);
        return;
    }

    for (const PlannedSubmit& planned_submit : planned_submits)
    {
        Emit(call_id, call_info, EncodeSubmit(args, planned_submit).GetBytes());
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
