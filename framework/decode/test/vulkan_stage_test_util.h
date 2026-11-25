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

#ifndef GFXRECON_DECODE_TEST_VULKAN_STAGE_TEST_UTIL_H
#define GFXRECON_DECODE_TEST_VULKAN_STAGE_TEST_UTIL_H

#include "decode/decode_allocator.h"
#include "decode/vulkan_consumer_stage_base.h"
#include "generated/generated_vulkan_decoder.h"

#include <initializer_list>
#include <map>
#include <optional>
#include <span>
#include <string>
#include <utility>
#include <vector>

// Helpers shared by the tests of the stages.
namespace stage_test
{

using namespace gfxrecon::decode;
namespace format = gfxrecon::format;

constexpr format::HandleId kDevice = 1;
constexpr format::HandleId kPool   = 2;
constexpr format::HandleId kQueue  = 90;

constexpr uint32_t kStructPointer     = format::kIsStruct | format::kIsSingle | format::kHasAddress | format::kHasData;
constexpr uint32_t kNullStructPointer = format::kIsStruct | format::kIsSingle | format::kIsNull;
constexpr uint32_t kNullStructArray   = format::kIsStruct | format::kIsArray | format::kIsNull;
constexpr uint32_t kNullArray         = format::kIsArray | format::kIsNull;
constexpr uint32_t kHandlePointer     = format::kIsSingle | format::kHasAddress | format::kHasData;
constexpr uint32_t kArrayPointer      = format::kIsArray | format::kHasAddress | format::kHasData;
constexpr uint32_t kStructArray       = format::kIsStruct | kArrayPointer;

constexpr format::HandleId kPipeline = 80;
constexpr format::HandleId kLayout   = 81;

// Writes call parameters in capture file order.
class Bytes
{
  public:
    template <typename T>
    Bytes& Put(T value)
    {
        const auto* first = reinterpret_cast<const uint8_t*>(&value);
        data.insert(data.end(), first, first + sizeof(T));
        return *this;
    }

    std::vector<uint8_t> data;
};

// The values that a test gives to a semaphore of vkQueueSubmit2. The stage mask needs more than 32 bits.
constexpr uint64_t SemaphoreValue(format::HandleId semaphore)
{
    return 1000 + semaphore;
}

constexpr VkPipelineStageFlags2 SemaphoreStageMask(format::HandleId semaphore)
{
    return VK_PIPELINE_STAGE_2_COPY_BIT | semaphore;
}

constexpr uint32_t SemaphoreDeviceIndex(format::HandleId semaphore)
{
    return static_cast<uint32_t>(semaphore % 7);
}

// Logs every call that the stage sends on, one line per call. A synthetic id prints as S1, S2 and so on,
// in the order that it first appears, so the expected streams do not depend on its value.
class CallLog : public VulkanConsumer
{
  public:
    void Process_vkAllocateCommandBuffers(const ApiCallInfo&, args::AllocateCommandBuffers& args) override
    {
        const auto* info  = args.pAllocateInfo.GetMetaStructPointer();
        std::string level = info->decoded_value->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY ? "primary" : "secondary";
        std::string line  = "Allocate " + Name(args.device) + " " + Name(info->commandPool) + " " + level;
        for (const format::HandleId id : args.pCommandBuffers.GetSpan())
        {
            line += " " + Name(id);
        }
        lines.push_back(line);
    }

    void Process_vkBeginCommandBuffer(const ApiCallInfo&, args::BeginCommandBuffer& args) override
    {
        lines.push_back("Begin " + Name(args.commandBuffer) + " flags " +
                        std::to_string(args.pBeginInfo.GetPointer()->flags));
    }

    void Process_vkEndCommandBuffer(const ApiCallInfo&, args::EndCommandBuffer& args) override
    {
        lines.push_back("End " + Name(args.commandBuffer));
    }

    void Process_vkCmdCopyBuffer(const ApiCallInfo&, args::CmdCopyBuffer& args) override
    {
        lines.push_back("CopyBuffer " + Name(args.commandBuffer));
    }

    void Process_vkCmdBeginRenderPass(const ApiCallInfo&, args::CmdBeginRenderPass& args) override
    {
        lines.push_back("BeginRenderPass " + Name(args.commandBuffer));
    }

    void Process_vkCmdDraw(const ApiCallInfo&, args::CmdDraw& args) override
    {
        lines.push_back("Draw " + Name(args.commandBuffer));
    }

    void Process_vkCmdEndRenderPass(const ApiCallInfo&, args::CmdEndRenderPass& args) override
    {
        lines.push_back("EndRenderPass " + Name(args.commandBuffer));
    }

    void Process_vkCmdBeginRenderPass2(const ApiCallInfo&, args::CmdBeginRenderPass2& args) override
    {
        lines.push_back("BeginRenderPass2 " + Name(args.commandBuffer));
    }

    void Process_vkCmdBeginRenderPass2KHR(const ApiCallInfo&, args::CmdBeginRenderPass2KHR& args) override
    {
        lines.push_back("BeginRenderPass2KHR " + Name(args.commandBuffer));
    }

    void Process_vkCmdBeginRendering(const ApiCallInfo&, args::CmdBeginRendering& args) override
    {
        lines.push_back("BeginRendering " + Name(args.commandBuffer));
    }

    void Process_vkCmdBeginRenderingKHR(const ApiCallInfo&, args::CmdBeginRenderingKHR& args) override
    {
        lines.push_back("BeginRenderingKHR " + Name(args.commandBuffer));
    }

    void Process_vkCmdEndRenderPass2(const ApiCallInfo&, args::CmdEndRenderPass2& args) override
    {
        lines.push_back("EndRenderPass2 " + Name(args.commandBuffer));
    }

    void Process_vkCmdEndRenderPass2KHR(const ApiCallInfo&, args::CmdEndRenderPass2KHR& args) override
    {
        lines.push_back("EndRenderPass2KHR " + Name(args.commandBuffer));
    }

    void Process_vkCmdEndRendering(const ApiCallInfo&, args::CmdEndRendering& args) override
    {
        lines.push_back("EndRendering " + Name(args.commandBuffer));
    }

    void Process_vkCmdEndRenderingKHR(const ApiCallInfo&, args::CmdEndRenderingKHR& args) override
    {
        lines.push_back("EndRenderingKHR " + Name(args.commandBuffer));
    }

    // Each state command prints its values, and the values that sit behind pointers too, so a test sees
    // whether a reissue kept them.

    void Process_vkCmdBindPipeline(const ApiCallInfo&, args::CmdBindPipeline& args) override
    {
        lines.push_back("BindPipeline " + Name(args.commandBuffer) + " " + std::to_string(args.pipeline));
    }

    void Process_vkCmdBindDescriptorSets(const ApiCallInfo&, args::CmdBindDescriptorSets& args) override
    {
        std::string line = "BindDescriptorSets " + Name(args.commandBuffer) + " sets";
        for (const format::HandleId set : args.pDescriptorSets.GetSpan())
        {
            line += " " + std::to_string(set);
        }
        line += " offsets";
        for (const uint32_t offset : args.pDynamicOffsets.GetSpan())
        {
            line += " " + std::to_string(offset);
        }
        lines.push_back(line);
    }

    void Process_vkCmdBindIndexBuffer(const ApiCallInfo&, args::CmdBindIndexBuffer& args) override
    {
        lines.push_back("BindIndexBuffer " + Name(args.commandBuffer) + " " + std::to_string(args.buffer) + " " +
                        std::to_string(args.offset));
    }

    void Process_vkCmdBindVertexBuffers(const ApiCallInfo&, args::CmdBindVertexBuffers& args) override
    {
        std::string line = "BindVertexBuffers " + Name(args.commandBuffer) + " buffers";
        for (const format::HandleId buffer : args.pBuffers.GetSpan())
        {
            line += " " + std::to_string(buffer);
        }
        line += " offsets";
        for (const VkDeviceSize offset : args.pOffsets.GetSpan())
        {
            line += " " + std::to_string(offset);
        }
        lines.push_back(line);
    }

    void Process_vkCmdSetViewport(const ApiCallInfo&, args::CmdSetViewport& args) override
    {
        std::string line = "SetViewport " + Name(args.commandBuffer);
        for (const VkViewport& viewport : args.pViewports.GetSpan())
        {
            line += " " + std::to_string(static_cast<int>(viewport.width)) + "x" +
                    std::to_string(static_cast<int>(viewport.height));
        }
        lines.push_back(line);
    }

    void Process_vkCmdSetScissor(const ApiCallInfo&, args::CmdSetScissor& args) override
    {
        std::string line = "SetScissor " + Name(args.commandBuffer);
        for (const VkRect2D& scissor : args.pScissors.GetSpan())
        {
            line += " " + std::to_string(scissor.extent.width) + "x" + std::to_string(scissor.extent.height);
        }
        lines.push_back(line);
    }

    void Process_vkCmdPushConstants(const ApiCallInfo&, args::CmdPushConstants& args) override
    {
        std::string line = "PushConstants " + Name(args.commandBuffer);
        for (const uint8_t value : args.pValues.GetSpan())
        {
            line += " " + std::to_string(value);
        }
        lines.push_back(line);
    }

    // A submit prints, for each submit info, its wait semaphores with their stage masks, its command buffers, the
    // native count and its signal semaphores. The counts come from the native struct, so a test sees whether they
    // match the ids. A wait or signal count prints only when it does not match. The queue prints only when it is not
    // kQueue, and the result only when it is not VK_SUCCESS.

    void Process_vkQueueSubmit(const ApiCallInfo&, args::QueueSubmit& args) override
    {
        std::string line = "Submit";
        for (uint32_t i = 0; i < args.submitCount; ++i)
        {
            const Decoded_VkSubmitInfo& meta   = args.pSubmits.GetMetaStructPointer()[i];
            const VkSubmitInfo&         native = args.pSubmits.GetPointer()[i];

            line += TimelineText(meta);
            line += FrameBoundaryText(meta.pNext);
            line += PerformanceQueryText(meta.pNext);
            line += Labeled(" wait", meta.pWaitSemaphores.GetSpan());
            for (const VkPipelineStageFlags stage_mask : meta.pWaitDstStageMask.GetSpan())
            {
                line += " stage " + std::to_string(stage_mask);
            }
            line += CountMismatch(native.waitSemaphoreCount, meta.pWaitSemaphores.GetLength());
            line +=
                " [" + Names(meta.pCommandBuffers.GetSpan()) + "] count " + std::to_string(native.commandBufferCount);
            line += Labeled(" signal", meta.pSignalSemaphores.GetSpan());
            line += CountMismatch(native.signalSemaphoreCount, meta.pSignalSemaphores.GetLength());
        }
        line += FenceText(args.fence);
        line += (args.queue == kQueue) ? "" : " queue " + std::to_string(args.queue);
        line += (args.result == VK_SUCCESS) ? "" : " result " + std::to_string(args.result);
        lines.push_back(line);
    }

    void Process_vkQueueSubmit2(const ApiCallInfo&, args::QueueSubmit2& args) override
    {
        LogQueueSubmit2("Submit2", args);
    }

    void Process_vkQueueSubmit2KHR(const ApiCallInfo&, args::QueueSubmit2KHR& args) override
    {
        LogQueueSubmit2("Submit2KHR", args);
    }

    std::vector<std::string> lines;

    // A capture id prints as itself. A synthetic id prints as S1, S2, … in the order the log first sees it.
    std::string Name(format::HandleId id)
    {
        if ((id >> 63) == 0)
        {
            return std::to_string(id);
        }

        const auto entry = synthetic_names_.try_emplace(id, synthetic_names_.size() + 1).first;
        return "S" + std::to_string(entry->second);
    }

  private:
    // Each command buffer prints as id:deviceMask. The mask comes from the native array, so a submit info whose
    // native pointer no longer matches its meta array prints "stale".
    template <typename ArgsT>
    void LogQueueSubmit2(const std::string& name, ArgsT& args)
    {
        std::string line = name;
        for (uint32_t i = 0; i < args.submitCount; ++i)
        {
            const Decoded_VkSubmitInfo2& meta   = args.pSubmits.GetMetaStructPointer()[i];
            const VkSubmitInfo2&         native = args.pSubmits.GetPointer()[i];

            line += FrameBoundaryText(meta.pNext);
            line += PerformanceQueryText(meta.pNext);
            line += (native.flags == 0) ? "" : " flags " + std::to_string(native.flags);
            line += SemaphoresText(" wait", *meta.pWaitSemaphoreInfos, native.waitSemaphoreInfoCount);

            StructPointerDecoder<Decoded_VkCommandBufferSubmitInfo>& infos = *meta.pCommandBufferInfos;
            line += " [";
            if (native.pCommandBufferInfos != infos.GetPointer())
            {
                line += "stale";
            }
            else
            {
                for (size_t k = 0; k < infos.GetLength(); ++k)
                {
                    line += (k == 0 ? "" : " ") + Name(infos.GetMetaStructPointer()[k].commandBuffer) + ":" +
                            std::to_string(native.pCommandBufferInfos[k].deviceMask);
                }
            }
            line += "] count " + std::to_string(native.commandBufferInfoCount);

            line += SemaphoresText(" signal", *meta.pSignalSemaphoreInfos, native.signalSemaphoreInfoCount);
        }
        line += FenceText(args.fence);
        line += (args.queue == kQueue) ? "" : " queue " + std::to_string(args.queue);
        line += (args.result == VK_SUCCESS) ? "" : " result " + std::to_string(args.result);
        lines.push_back(line);
    }

    // Prints the label and the ids, or nothing when there are no ids. Adds "wrong" to a semaphore whose other values
    // are not the ones that the test gave it.
    static std::string SemaphoresText(const std::string&                                   label,
                                      StructPointerDecoder<Decoded_VkSemaphoreSubmitInfo>& infos,
                                      uint32_t                                             native_count)
    {
        std::string text;
        for (const Decoded_VkSemaphoreSubmitInfo& info : infos.GetMetaStructSpan())
        {
            const VkSemaphoreSubmitInfo& native   = *info.decoded_value;
            const bool                   is_right = (native.value == SemaphoreValue(info.semaphore)) &&
                                  (native.stageMask == SemaphoreStageMask(info.semaphore)) &&
                                  (native.deviceIndex == SemaphoreDeviceIndex(info.semaphore));
            text += " " + std::to_string(info.semaphore) + (is_right ? "" : " wrong");
        }
        return (text.empty() ? "" : label + text) + CountMismatch(native_count, infos.GetLength());
    }

    // Prints the wait values and then the signal values, each with its count in front, for example
    // " timeline 1 [7] 1 [9]". Prints nothing when the submit info has no timeline struct.
    static std::string TimelineText(const Decoded_VkSubmitInfo& info)
    {
        const auto* timeline = GetPNextMetaStruct<Decoded_VkTimelineSemaphoreSubmitInfo>(info.pNext);
        if (timeline == nullptr)
        {
            return "";
        }

        return " timeline " + std::to_string(timeline->decoded_value->waitSemaphoreValueCount) +
               ValuesText(timeline->pWaitSemaphoreValues.GetSpan()) + " " +
               std::to_string(timeline->decoded_value->signalSemaphoreValueCount) +
               ValuesText(timeline->pSignalSemaphoreValues.GetSpan());
    }

    // Prints the frame id, the flags, the images, the buffers and the tag, each list with its count in front, for
    // example " boundary 5 flags 1 images 1 [50] buffers 0 [] tag 77 size 2 [1 2]". Prints nothing when the submit
    // info has no frame boundary.
    static std::string FrameBoundaryText(const PNextNode* pnext)
    {
        const auto* boundary = GetPNextMetaStruct<Decoded_VkFrameBoundaryEXT>(pnext);
        if (boundary == nullptr)
        {
            return "";
        }

        const VkFrameBoundaryEXT& native = *boundary->decoded_value;
        return " boundary " + std::to_string(native.frameID) + " flags " + std::to_string(native.flags) + " images " +
               std::to_string(native.imageCount) + ValuesText(boundary->pImages.GetSpan()) + " buffers " +
               std::to_string(native.bufferCount) + ValuesText(boundary->pBuffers.GetSpan()) + " tag " +
               std::to_string(native.tagName) + " size " + std::to_string(native.tagSize) +
               ValuesText(boundary->pTag.GetSpan());
    }

    // Prints " query" when the chain has a VkPerformanceQuerySubmitInfoKHR, which the command buffer stage cannot
    // write.
    static std::string PerformanceQueryText(const PNextNode* pnext)
    {
        return (GetPNextMetaStruct<Decoded_VkPerformanceQuerySubmitInfoKHR>(pnext) == nullptr) ? "" : " query";
    }

    template <typename T>
    static std::string ValuesText(std::span<const T> values)
    {
        std::string text;
        for (const T& value : values)
        {
            text += (text.empty() ? "" : " ") + std::to_string(value);
        }
        return " [" + text + "]";
    }

    static std::string CountMismatch(size_t native_count, size_t id_count)
    {
        return (native_count == id_count) ? "" : " wrong count " + std::to_string(native_count);
    }

    static std::string FenceText(format::HandleId fence)
    {
        return (fence == format::kNullHandleId) ? "" : " fence " + std::to_string(fence);
    }

    // Prints the label and the ids, or nothing when there are no ids.
    std::string Labeled(const std::string& label, std::span<const format::HandleId> ids)
    {
        return ids.empty() ? "" : label + " " + Names(ids);
    }

    std::string Names(std::span<const format::HandleId> ids)
    {
        std::string text;
        for (const format::HandleId id : ids)
        {
            text += (text.empty() ? "" : " ") + Name(id);
        }
        return text;
    }

    std::map<format::HandleId, size_t> synthetic_names_;
};

// Keeps the call bytes that it holds when vkCmdBeginRenderPass arrives.
class CallBytesProbe : public VulkanConsumer
{
  public:
    void SetCurrentCallBytes(const CallBytes& call_bytes) override { current = call_bytes; }

    void Process_vkCmdBeginRenderPass(const ApiCallInfo&, args::CmdBeginRenderPass&) override
    {
        seen_at_render_pass = current;
    }

    CallBytes current;
    CallBytes seen_at_render_pass;
};

// Edits the viewports that it receives. The stage must reissue the values of the capture, not the edits.
class ViewportEditor : public VulkanConsumer
{
  public:
    void Process_vkCmdSetViewport(const ApiCallInfo&, args::CmdSetViewport& args) override
    {
        for (VkViewport& viewport : args.pViewports.GetSpan())
        {
            viewport.width  = 1;
            viewport.height = 1;
        }
    }
};

// The rig writes this address for every array of a submit. A probe that sees another address knows that the stage
// replaced the array.
constexpr uint64_t kAppArrayAddress = 0xA0;

// Keeps, for each submit info that it receives, whether the stage replaced its command buffer array.
class SubmitProbe : public VulkanConsumer
{
  public:
    void Process_vkQueueSubmit(const ApiCallInfo&, args::QueueSubmit& args) override
    {
        for (const Decoded_VkSubmitInfo& info : args.pSubmits.GetMetaStructSpan())
        {
            replaced.push_back(info.pCommandBuffers.GetAddress() != kAppArrayAddress);

            AddNullArrays({ { "waits", info.pWaitSemaphores.IsNull() },
                            { "stages", info.pWaitDstStageMask.IsNull() },
                            { "command buffers", info.pCommandBuffers.IsNull() },
                            { "signals", info.pSignalSemaphores.IsNull() } });
        }
    }

    void Process_vkQueueSubmit2(const ApiCallInfo&, args::QueueSubmit2& args) override { Keep(args); }

    void Process_vkQueueSubmit2KHR(const ApiCallInfo&, args::QueueSubmit2KHR& args) override { Keep(args); }

    std::vector<bool> replaced;

    // The arrays of each submit info that are null.
    std::vector<std::string> null_arrays;

  private:
    void AddNullArrays(const std::vector<std::pair<std::string, bool>>& arrays)
    {
        for (const auto& [name, is_null] : arrays)
        {
            if (is_null)
            {
                null_arrays.push_back(name);
            }
        }
    }

    template <typename ArgsT>
    void Keep(ArgsT& args)
    {
        for (const Decoded_VkSubmitInfo2& info : args.pSubmits.GetMetaStructSpan())
        {
            replaced.push_back(info.pCommandBufferInfos->GetAddress() != kAppArrayAddress);

            AddNullArrays({ { "waits", info.pWaitSemaphoreInfos->IsNull() },
                            { "command buffers", info.pCommandBufferInfos->IsNull() },
                            { "signals", info.pSignalSemaphoreInfos->IsNull() } });
        }
    }
};

// A VkRenderPassBeginInfo with no clear values.
inline void PutRenderPassBeginInfo(Bytes& bytes)
{
    bytes.Put<uint32_t>(kStructPointer)
        .Put<uint64_t>(1)
        .Put<uint32_t>(VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO)
        .Put<uint32_t>(kNullStructPointer)
        .Put<format::HandleId>(70) // renderPass
        .Put<format::HandleId>(71) // framebuffer
        .Put<int32_t>(0)           // renderArea.offset
        .Put<int32_t>(0)
        .Put<uint32_t>(4) // renderArea.extent
        .Put<uint32_t>(4)
        .Put<uint32_t>(0) // clearValueCount
        .Put<uint32_t>(kNullStructArray);
}

inline Bytes EncodeBeginRenderPass(format::HandleId command_buffer)
{
    Bytes bytes;
    bytes.Put<format::HandleId>(command_buffer);
    PutRenderPassBeginInfo(bytes);
    bytes.Put<uint32_t>(VK_SUBPASS_CONTENTS_INLINE);
    return bytes;
}

// Also the bytes of vkCmdBeginRenderPass2KHR.
inline Bytes EncodeBeginRenderPass2(format::HandleId command_buffer)
{
    Bytes bytes;
    bytes.Put<format::HandleId>(command_buffer);
    PutRenderPassBeginInfo(bytes);
    bytes
        .Put<uint32_t>(kStructPointer) // pSubpassBeginInfo
        .Put<uint64_t>(1)
        .Put<uint32_t>(VK_STRUCTURE_TYPE_SUBPASS_BEGIN_INFO)
        .Put<uint32_t>(kNullStructPointer)
        .Put<uint32_t>(VK_SUBPASS_CONTENTS_INLINE);
    return bytes;
}

// Also the bytes of vkCmdBeginRenderingKHR. The VkRenderingInfo has no attachments.
inline Bytes EncodeBeginRendering(format::HandleId command_buffer, VkRenderingFlags flags)
{
    Bytes bytes;
    bytes.Put<format::HandleId>(command_buffer)
        .Put<uint32_t>(kStructPointer) // pRenderingInfo
        .Put<uint64_t>(1)
        .Put<uint32_t>(VK_STRUCTURE_TYPE_RENDERING_INFO)
        .Put<uint32_t>(kNullStructPointer)
        .Put<uint32_t>(flags)
        .Put<int32_t>(0) // renderArea.offset
        .Put<int32_t>(0)
        .Put<uint32_t>(4) // renderArea.extent
        .Put<uint32_t>(4)
        .Put<uint32_t>(1)                   // layerCount
        .Put<uint32_t>(0)                   // viewMask
        .Put<uint32_t>(0)                   // colorAttachmentCount
        .Put<uint32_t>(kNullStructArray)    // pColorAttachments
        .Put<uint32_t>(kNullStructPointer)  // pDepthAttachment
        .Put<uint32_t>(kNullStructPointer); // pStencilAttachment
    return bytes;
}

inline Bytes EncodeBeginRendering(format::HandleId command_buffer)
{
    return EncodeBeginRendering(command_buffer, 0);
}

// Also the bytes of vkCmdEndRendering and vkCmdEndRenderingKHR.
inline Bytes EncodeEndRenderPass(format::HandleId command_buffer)
{
    return Bytes().Put<format::HandleId>(command_buffer);
}

// Also the bytes of vkCmdEndRenderPass2KHR.
inline Bytes EncodeEndRenderPass2(format::HandleId command_buffer)
{
    Bytes bytes;
    bytes.Put<format::HandleId>(command_buffer)
        .Put<uint32_t>(kStructPointer) // pSubpassEndInfo
        .Put<uint64_t>(1)
        .Put<uint32_t>(VK_STRUCTURE_TYPE_SUBPASS_END_INFO)
        .Put<uint32_t>(kNullStructPointer);
    return bytes;
}

// One way to begin and end a render pass, with the names that CallLog prints for it.
struct RenderPassCalls
{
    std::string       begin_name;
    format::ApiCallId begin_id;
    Bytes (*encode_begin)(format::HandleId);
    std::string       end_name;
    format::ApiCallId end_id;
    Bytes (*encode_end)(format::HandleId);
};

inline const std::vector<RenderPassCalls> kRenderPassCalls = {
    { "BeginRenderPass",
      format::ApiCall_vkCmdBeginRenderPass,
      EncodeBeginRenderPass,
      "EndRenderPass",
      format::ApiCall_vkCmdEndRenderPass,
      EncodeEndRenderPass },
    { "BeginRenderPass2",
      format::ApiCall_vkCmdBeginRenderPass2,
      EncodeBeginRenderPass2,
      "EndRenderPass2",
      format::ApiCall_vkCmdEndRenderPass2,
      EncodeEndRenderPass2 },
    { "BeginRenderPass2KHR",
      format::ApiCall_vkCmdBeginRenderPass2KHR,
      EncodeBeginRenderPass2,
      "EndRenderPass2KHR",
      format::ApiCall_vkCmdEndRenderPass2KHR,
      EncodeEndRenderPass2 },
    { "BeginRendering",
      format::ApiCall_vkCmdBeginRendering,
      EncodeBeginRendering,
      "EndRendering",
      format::ApiCall_vkCmdEndRendering,
      EncodeEndRenderPass },
    { "BeginRenderingKHR",
      format::ApiCall_vkCmdBeginRenderingKHR,
      EncodeBeginRendering,
      "EndRenderingKHR",
      format::ApiCall_vkCmdEndRenderingKHR,
      EncodeEndRenderPass },
};

inline Bytes EncodeBindPipeline(format::HandleId command_buffer, format::HandleId pipeline)
{
    Bytes bytes;
    bytes.Put<format::HandleId>(command_buffer)
        .Put<uint32_t>(VK_PIPELINE_BIND_POINT_GRAPHICS)
        .Put<format::HandleId>(pipeline);
    return bytes;
}

inline Bytes EncodeBindPipeline(format::HandleId command_buffer)
{
    return EncodeBindPipeline(command_buffer, kPipeline);
}

// Two sets, 60 and 61, and one dynamic offset of 8.
inline Bytes EncodeBindDescriptorSets(format::HandleId command_buffer)
{
    Bytes bytes;
    bytes.Put<format::HandleId>(command_buffer)
        .Put<uint32_t>(VK_PIPELINE_BIND_POINT_GRAPHICS)
        .Put<format::HandleId>(kLayout)
        .Put<uint32_t>(0) // firstSet
        .Put<uint32_t>(2) // descriptorSetCount
        .Put<uint32_t>(kArrayPointer)
        .Put<uint64_t>(1)
        .Put<uint64_t>(2)
        .Put<format::HandleId>(60)
        .Put<format::HandleId>(61)
        .Put<uint32_t>(1) // dynamicOffsetCount
        .Put<uint32_t>(kArrayPointer)
        .Put<uint64_t>(1)
        .Put<uint64_t>(1)
        .Put<uint32_t>(8);
    return bytes;
}

// Buffer 52 at offset 256.
inline Bytes EncodeBindIndexBuffer(format::HandleId command_buffer)
{
    Bytes bytes;
    bytes.Put<format::HandleId>(command_buffer)
        .Put<format::HandleId>(52)
        .Put<uint64_t>(256)
        .Put<uint32_t>(VK_INDEX_TYPE_UINT16);
    return bytes;
}

// Buffers 53 and 54 at offsets 0 and 128.
inline Bytes EncodeBindVertexBuffers(format::HandleId command_buffer)
{
    Bytes bytes;
    bytes.Put<format::HandleId>(command_buffer)
        .Put<uint32_t>(0) // firstBinding
        .Put<uint32_t>(2) // bindingCount
        .Put<uint32_t>(kArrayPointer)
        .Put<uint64_t>(1)
        .Put<uint64_t>(2)
        .Put<format::HandleId>(53)
        .Put<format::HandleId>(54)
        .Put<uint32_t>(kArrayPointer)
        .Put<uint64_t>(1)
        .Put<uint64_t>(2)
        .Put<uint64_t>(0)
        .Put<uint64_t>(128);
    return bytes;
}

// Two viewports, 640x480 and 320x240.
inline Bytes EncodeSetViewport(format::HandleId command_buffer)
{
    Bytes bytes;
    bytes.Put<format::HandleId>(command_buffer)
        .Put<uint32_t>(0) // firstViewport
        .Put<uint32_t>(2) // viewportCount
        .Put<uint32_t>(kStructArray)
        .Put<uint64_t>(1)
        .Put<uint64_t>(2);
    for (const float width : { 640.0f, 320.0f })
    {
        bytes.Put<float>(0).Put<float>(0).Put<float>(width).Put<float>(width * 0.75f).Put<float>(0).Put<float>(1);
    }
    return bytes;
}

// One scissor, 640x480.
inline Bytes EncodeSetScissor(format::HandleId command_buffer)
{
    Bytes bytes;
    bytes.Put<format::HandleId>(command_buffer)
        .Put<uint32_t>(0) // firstScissor
        .Put<uint32_t>(1) // scissorCount
        .Put<uint32_t>(kStructArray)
        .Put<uint64_t>(1)
        .Put<uint64_t>(1)
        .Put<int32_t>(0) // offset
        .Put<int32_t>(0)
        .Put<uint32_t>(640) // extent
        .Put<uint32_t>(480);
    return bytes;
}

// Four bytes, 1 2 3 4.
inline Bytes EncodePushConstants(format::HandleId command_buffer)
{
    Bytes bytes;
    bytes.Put<format::HandleId>(command_buffer)
        .Put<format::HandleId>(kLayout)
        .Put<uint32_t>(VK_SHADER_STAGE_VERTEX_BIT)
        .Put<uint32_t>(0) // offset
        .Put<uint32_t>(4) // size
        .Put<uint32_t>(kArrayPointer)
        .Put<uint64_t>(1)
        .Put<uint64_t>(4)
        .Put<uint8_t>(1)
        .Put<uint8_t>(2)
        .Put<uint8_t>(3)
        .Put<uint8_t>(4);
    return bytes;
}

// One state command, with the text that CallLog prints after the command buffer id.
struct StateCall
{
    std::string       name;
    format::ApiCallId id;
    Bytes (*encode)(format::HandleId);
    std::string values;
};

inline const std::vector<StateCall> kStateCalls = {
    { "BindPipeline", format::ApiCall_vkCmdBindPipeline, EncodeBindPipeline, " 80" },
    { "BindDescriptorSets",
      format::ApiCall_vkCmdBindDescriptorSets,
      EncodeBindDescriptorSets,
      " sets 60 61 offsets 8" },
    { "BindIndexBuffer", format::ApiCall_vkCmdBindIndexBuffer, EncodeBindIndexBuffer, " 52 256" },
    { "BindVertexBuffers",
      format::ApiCall_vkCmdBindVertexBuffers,
      EncodeBindVertexBuffers,
      " buffers 53 54 offsets 0 128" },
    { "SetViewport", format::ApiCall_vkCmdSetViewport, EncodeSetViewport, " 640x480 320x240" },
    { "SetScissor", format::ApiCall_vkCmdSetScissor, EncodeSetScissor, " 640x480" },
    { "PushConstants", format::ApiCall_vkCmdPushConstants, EncodePushConstants, " 1 2 3 4" },
};

constexpr format::HandleId kFence = 40;

// One VkTimelineSemaphoreSubmitInfo of the app. Empty values are a null array, and the app may still give a count.
struct AppTimelineInfo
{
    uint32_t              wait_count = 0;
    std::vector<uint64_t> wait_values;
    uint32_t              signal_count = 0;
    std::vector<uint64_t> signal_values;
};

// One VkFrameBoundaryEXT of the app. An empty list is a null array, and the app may still give a count.
struct AppFrameBoundary
{
    VkFrameBoundaryFlagsEXT       flags       = 0;
    uint64_t                      frame_id    = 0;
    uint32_t                      image_count = 0;
    std::vector<format::HandleId> images;
    uint32_t                      buffer_count = 0;
    std::vector<format::HandleId> buffers;
    uint64_t                      tag_name = 0;
    uint64_t                      tag_size = 0;
    std::vector<uint8_t>          tag;
};

inline const AppFrameBoundary kFrameBoundary = { .flags        = VK_FRAME_BOUNDARY_FRAME_END_BIT_EXT,
                                                 .frame_id     = 5,
                                                 .image_count  = 2,
                                                 .images       = { 50, 51 },
                                                 .buffer_count = 1,
                                                 .buffers      = { 52 },
                                                 .tag_name     = 77,
                                                 .tag_size     = 3,
                                                 .tag          = { 1, 2, 3 } };

// The text that CallLog prints for kFrameBoundary.
inline const std::string kFrameBoundaryText =
    " boundary 5 flags 1 images 2 [50 51] buffers 1 [52] tag 77 size 3 [1 2 3]";

// One VkSubmitInfo or VkSubmitInfo2 of the app. vkQueueSubmit ignores the device masks, and vkQueueSubmit2 uses
// a mask of 0 for a command buffer that has none. Only vkQueueSubmit uses the wait stages and the timeline struct,
// and a wait that has no stage gets VK_PIPELINE_STAGE_ALL_COMMANDS_BIT. vkQueueSubmit2 derives the values of a
// semaphore from its id, so that CallLog can check them.
struct AppSubmitInfo
{
    std::vector<format::HandleId> command_buffers;
    std::vector<uint32_t>         device_masks;
    std::vector<format::HandleId> wait_semaphores;
    std::vector<uint32_t>         wait_stages;
    std::vector<format::HandleId> signal_semaphores;

    std::optional<AppTimelineInfo>  timeline       = std::nullopt;
    std::optional<AppFrameBoundary> frame_boundary = std::nullopt;

    // The timeline struct comes before the frame boundary, unless this is set.
    bool frame_boundary_first = false;

    // Puts a VkPerformanceQuerySubmitInfoKHR at the start of the pNext chain.
    bool performance_query = false;

    // Only vkQueueSubmit2 uses the flags.
    VkSubmitFlags flags = 0;
};

template <typename T>
void PutArray(Bytes& bytes, const std::vector<T>& values)
{
    if (values.empty())
    {
        bytes.Put<uint32_t>(kNullArray);
        return;
    }

    bytes.Put<uint32_t>(kArrayPointer).Put<uint64_t>(kAppArrayAddress).Put<uint64_t>(values.size());
    for (const T& value : values)
    {
        bytes.Put<T>(value);
    }
}

// Writes a pNext struct, or only the rest of the chain when the app has no such struct. put_next writes the rest.
template <typename PutNext>
void PutTimelineInfo(Bytes& bytes, const std::optional<AppTimelineInfo>& timeline, PutNext put_next)
{
    if (!timeline.has_value())
    {
        put_next();
        return;
    }

    bytes.Put<uint32_t>(kStructPointer)
        .Put<uint64_t>(kAppArrayAddress)
        .Put<uint32_t>(VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO);
    put_next();
    bytes.Put<uint32_t>(timeline->wait_count);
    PutArray(bytes, timeline->wait_values);
    bytes.Put<uint32_t>(timeline->signal_count);
    PutArray(bytes, timeline->signal_values);
}

template <typename PutNext>
void PutFrameBoundary(Bytes& bytes, const std::optional<AppFrameBoundary>& boundary, PutNext put_next)
{
    if (!boundary.has_value())
    {
        put_next();
        return;
    }

    bytes.Put<uint32_t>(kStructPointer)
        .Put<uint64_t>(kAppArrayAddress)
        .Put<uint32_t>(VK_STRUCTURE_TYPE_FRAME_BOUNDARY_EXT);
    put_next();
    bytes.Put<uint32_t>(boundary->flags).Put<uint64_t>(boundary->frame_id);
    bytes.Put<uint32_t>(boundary->image_count);
    PutArray(bytes, boundary->images);
    bytes.Put<uint32_t>(boundary->buffer_count);
    PutArray(bytes, boundary->buffers);
    bytes.Put<uint64_t>(boundary->tag_name).Put<uint64_t>(boundary->tag_size);
    PutArray(bytes, boundary->tag);
}

// The pNext chain of a VkSubmitInfo or VkSubmitInfo2.
inline void PutPNext(Bytes& bytes, const AppSubmitInfo& submit)
{
    if (submit.performance_query)
    {
        bytes.Put<uint32_t>(kStructPointer)
            .Put<uint64_t>(kAppArrayAddress)
            .Put<uint32_t>(VK_STRUCTURE_TYPE_PERFORMANCE_QUERY_SUBMIT_INFO_KHR);
    }

    const auto put_null = [&] { bytes.Put<uint32_t>(kNullStructPointer); };
    if (submit.frame_boundary_first)
    {
        PutFrameBoundary(bytes, submit.frame_boundary, [&] { PutTimelineInfo(bytes, submit.timeline, put_null); });
    }
    else
    {
        PutTimelineInfo(bytes, submit.timeline, [&] { PutFrameBoundary(bytes, submit.frame_boundary, put_null); });
    }

    if (submit.performance_query)
    {
        bytes.Put<uint32_t>(1); // counterPassIndex, after the struct's own pNext
    }
}

inline Bytes EncodeQueueSubmit(const std::vector<AppSubmitInfo>& submits, format::HandleId fence, VkResult result)
{
    Bytes bytes;
    bytes.Put<format::HandleId>(kQueue)
        .Put<uint32_t>(static_cast<uint32_t>(submits.size()))
        .Put<uint32_t>(kStructArray)
        .Put<uint64_t>(kAppArrayAddress)
        .Put<uint64_t>(submits.size());
    for (const AppSubmitInfo& submit : submits)
    {
        std::vector<uint32_t> wait_stages = submit.wait_stages;
        wait_stages.resize(submit.wait_semaphores.size(), VK_PIPELINE_STAGE_ALL_COMMANDS_BIT);

        bytes.Put<uint32_t>(VK_STRUCTURE_TYPE_SUBMIT_INFO);
        PutPNext(bytes, submit);
        bytes.Put<uint32_t>(static_cast<uint32_t>(submit.wait_semaphores.size()));
        PutArray(bytes, submit.wait_semaphores);
        PutArray(bytes, wait_stages);
        bytes.Put<uint32_t>(static_cast<uint32_t>(submit.command_buffers.size()));
        PutArray(bytes, submit.command_buffers);
        bytes.Put<uint32_t>(static_cast<uint32_t>(submit.signal_semaphores.size()));
        PutArray(bytes, submit.signal_semaphores);
    }
    bytes.Put<format::HandleId>(fence).Put<int32_t>(result);
    return bytes;
}

// A count and an array of VkSemaphoreSubmitInfo.
inline void PutSemaphoreInfos(Bytes& bytes, const std::vector<format::HandleId>& semaphores)
{
    bytes.Put<uint32_t>(static_cast<uint32_t>(semaphores.size()));
    if (semaphores.empty())
    {
        bytes.Put<uint32_t>(kNullStructArray);
        return;
    }

    bytes.Put<uint32_t>(kStructArray).Put<uint64_t>(kAppArrayAddress).Put<uint64_t>(semaphores.size());
    for (const format::HandleId semaphore : semaphores)
    {
        bytes.Put<uint32_t>(VK_STRUCTURE_TYPE_SEMAPHORE_SUBMIT_INFO)
            .Put<uint32_t>(kNullStructPointer)
            .Put<format::HandleId>(semaphore)
            .Put<uint64_t>(SemaphoreValue(semaphore))        // value
            .Put<uint64_t>(SemaphoreStageMask(semaphore))    // stageMask
            .Put<uint32_t>(SemaphoreDeviceIndex(semaphore)); // deviceIndex
    }
}

// Also the bytes of vkQueueSubmit2KHR.
inline Bytes
EncodeQueueSubmit2(const std::vector<AppSubmitInfo>& submits, format::HandleId fence, VkResult result = VK_SUCCESS)
{
    Bytes bytes;
    bytes.Put<format::HandleId>(kQueue)
        .Put<uint32_t>(static_cast<uint32_t>(submits.size()))
        .Put<uint32_t>(kStructArray)
        .Put<uint64_t>(kAppArrayAddress)
        .Put<uint64_t>(submits.size());
    for (const AppSubmitInfo& submit : submits)
    {
        bytes.Put<uint32_t>(VK_STRUCTURE_TYPE_SUBMIT_INFO_2);
        PutPNext(bytes, submit);
        bytes.Put<uint32_t>(submit.flags);
        PutSemaphoreInfos(bytes, submit.wait_semaphores);

        const auto& command_buffers = submit.command_buffers;
        bytes.Put<uint32_t>(static_cast<uint32_t>(command_buffers.size()));
        if (command_buffers.empty())
        {
            bytes.Put<uint32_t>(kNullStructArray);
        }
        else
        {
            bytes.Put<uint32_t>(kStructArray).Put<uint64_t>(kAppArrayAddress).Put<uint64_t>(command_buffers.size());
        }
        for (size_t k = 0; k < command_buffers.size(); ++k)
        {
            const uint32_t device_mask = (k < submit.device_masks.size()) ? submit.device_masks[k] : 0;
            bytes.Put<uint32_t>(VK_STRUCTURE_TYPE_COMMAND_BUFFER_SUBMIT_INFO)
                .Put<uint32_t>(kNullStructPointer)
                .Put<format::HandleId>(command_buffers[k])
                .Put<uint32_t>(device_mask);
        }

        PutSemaphoreInfos(bytes, submit.signal_semaphores);
    }
    bytes.Put<format::HandleId>(fence).Put<int32_t>(result);
    return bytes;
}

// Sends app calls through decoder -> stages -> log, the way the file processor would.
class StageRig
{
  public:
    void Allocate(std::initializer_list<format::HandleId> command_buffers,
                  VkCommandBufferLevel                    level = VK_COMMAND_BUFFER_LEVEL_PRIMARY)
    {
        Bytes bytes;
        bytes.Put<format::HandleId>(kDevice)
            .Put<uint32_t>(kStructPointer)
            .Put<uint64_t>(1)
            .Put<uint32_t>(VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO)
            .Put<uint32_t>(kNullStructPointer)
            .Put<format::HandleId>(kPool)
            .Put<uint32_t>(level)
            .Put<uint32_t>(static_cast<uint32_t>(command_buffers.size()))
            .Put<uint32_t>(kArrayPointer)
            .Put<uint64_t>(1)
            .Put<uint64_t>(command_buffers.size());
        for (const format::HandleId id : command_buffers)
        {
            bytes.Put<format::HandleId>(id);
        }
        bytes.Put<int32_t>(VK_SUCCESS);
        Send(format::ApiCall_vkAllocateCommandBuffers, bytes);
    }

    void CreateCommandPool(format::HandleId pool, VkCommandPoolCreateFlags flags)
    {
        Bytes bytes;
        bytes.Put<format::HandleId>(kDevice)
            .Put<uint32_t>(kStructPointer) // pCreateInfo
            .Put<uint64_t>(1)
            .Put<uint32_t>(VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO)
            .Put<uint32_t>(kNullStructPointer)
            .Put<uint32_t>(flags)
            .Put<uint32_t>(0)                  // queueFamilyIndex
            .Put<uint32_t>(kNullStructPointer) // pAllocator
            .Put<uint32_t>(kHandlePointer)     // pCommandPool
            .Put<uint64_t>(1)
            .Put<format::HandleId>(pool)
            .Put<int32_t>(VK_SUCCESS);
        Send(format::ApiCall_vkCreateCommandPool, bytes);
    }

    void ResetCommandPool(format::HandleId pool)
    {
        Send(format::ApiCall_vkResetCommandPool,
             Bytes().Put<format::HandleId>(kDevice).Put<format::HandleId>(pool).Put<uint32_t>(0).Put<int32_t>(
                 VK_SUCCESS));
    }

    void DestroyCommandPool(format::HandleId pool)
    {
        Send(format::ApiCall_vkDestroyCommandPool,
             Bytes().Put<format::HandleId>(kDevice).Put<format::HandleId>(pool).Put<uint32_t>(kNullStructPointer));
    }

    void FreeCommandBuffers(const std::vector<format::HandleId>& command_buffers)
    {
        Bytes bytes;
        bytes.Put<format::HandleId>(kDevice).Put<format::HandleId>(kPool).Put<uint32_t>(
            static_cast<uint32_t>(command_buffers.size()));
        PutArray(bytes, command_buffers);
        Send(format::ApiCall_vkFreeCommandBuffers, bytes);
    }

    void ResetCommandBuffer(format::HandleId command_buffer)
    {
        Send(format::ApiCall_vkResetCommandBuffer,
             Bytes().Put<format::HandleId>(command_buffer).Put<uint32_t>(0).Put<int32_t>(VK_SUCCESS));
    }

    void Begin(format::HandleId command_buffer, VkCommandBufferUsageFlags flags = 0)
    {
        Bytes bytes;
        bytes.Put<format::HandleId>(command_buffer)
            .Put<uint32_t>(kStructPointer)
            .Put<uint64_t>(1)
            .Put<uint32_t>(VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO)
            .Put<uint32_t>(kNullStructPointer)
            .Put<uint32_t>(flags)
            .Put<uint32_t>(kNullStructPointer)
            .Put<int32_t>(VK_SUCCESS);
        Send(format::ApiCall_vkBeginCommandBuffer, bytes);
    }

    void End(format::HandleId command_buffer)
    {
        Send(format::ApiCall_vkEndCommandBuffer,
             Bytes().Put<format::HandleId>(command_buffer).Put<int32_t>(VK_SUCCESS));
    }

    void CopyBuffer(format::HandleId command_buffer)
    {
        Bytes bytes;
        bytes.Put<format::HandleId>(command_buffer)
            .Put<format::HandleId>(50) // srcBuffer
            .Put<format::HandleId>(51) // dstBuffer
            .Put<uint32_t>(0)          // regionCount
            .Put<uint32_t>(kNullStructArray);
        Send(format::ApiCall_vkCmdCopyBuffer, bytes);
    }

    // Returns the bytes of the call, so a test can compare them with what a consumer saw.
    std::vector<uint8_t> BeginRenderPass(format::HandleId command_buffer)
    {
        const Bytes bytes = EncodeBeginRenderPass(command_buffer);
        Send(format::ApiCall_vkCmdBeginRenderPass, bytes);
        return bytes.data;
    }

    void Draw(format::HandleId command_buffer)
    {
        Bytes bytes;
        bytes.Put<format::HandleId>(command_buffer).Put<uint32_t>(3).Put<uint32_t>(1).Put<uint32_t>(0).Put<uint32_t>(0);
        Send(format::ApiCall_vkCmdDraw, bytes);
    }

    void EndRenderPass(format::HandleId command_buffer)
    {
        Send(format::ApiCall_vkCmdEndRenderPass, EncodeEndRenderPass(command_buffer));
    }

    void BindPipeline(format::HandleId command_buffer, format::HandleId pipeline = kPipeline)
    {
        Send(format::ApiCall_vkCmdBindPipeline, EncodeBindPipeline(command_buffer, pipeline));
    }

    void SetViewport(format::HandleId command_buffer)
    {
        Send(format::ApiCall_vkCmdSetViewport, EncodeSetViewport(command_buffer));
    }

    // Records a copy and then the given number of render passes. The stage splits the recording into one part
    // more than the number of passes. With no pass the recording stays whole.
    void RecordCopyAndRenderPasses(format::HandleId command_buffer, size_t render_pass_count)
    {
        Begin(command_buffer);
        CopyBuffer(command_buffer);
        for (size_t i = 0; i < render_pass_count; ++i)
        {
            BeginRenderPass(command_buffer);
            Draw(command_buffer);
            EndRenderPass(command_buffer);
        }
        End(command_buffer);
    }

    void Submit(const std::vector<AppSubmitInfo>& submits,
                format::HandleId                  fence  = format::kNullHandleId,
                VkResult                          result = VK_SUCCESS)
    {
        Send(format::ApiCall_vkQueueSubmit, EncodeQueueSubmit(submits, fence, result));
    }

    // Sends a vkQueueSubmit and returns only the lines that it adds to the log.
    std::vector<std::string> SubmitLines(const std::vector<AppSubmitInfo>& submits,
                                         format::HandleId                  fence  = format::kNullHandleId,
                                         VkResult                          result = VK_SUCCESS)
    {
        const size_t first_line = log.lines.size();
        Submit(submits, fence, result);
        return { log.lines.begin() + first_line, log.lines.end() };
    }

    // Sends a vkQueueSubmit2 or vkQueueSubmit2KHR and returns only the lines that it adds to the log.
    std::vector<std::string> Submit2Lines(format::ApiCallId                 call_id,
                                          const std::vector<AppSubmitInfo>& submits,
                                          format::HandleId                  fence  = format::kNullHandleId,
                                          VkResult                          result = VK_SUCCESS)
    {
        const size_t first_line = log.lines.size();
        Send(call_id, EncodeQueueSubmit2(submits, fence, result));
        return { log.lines.begin() + first_line, log.lines.end() };
    }

    // The guard opens the allocator scope for one call, as the file processor does.
    void Send(format::ApiCallId call_id, const Bytes& bytes)
    {
        DecoderAllocGuard<true> guard;
        decoder_.DecodeFunctionCall(call_id, ApiCallInfo{}, bytes.data);
    }

    // Adds a consumer after the last stage.
    void AddNext(VulkanConsumer* next) { last_stage_->AddNext(next); }

    CallLog log;

  protected:
    // Chains the stages in the given order.
    void Connect(std::initializer_list<VulkanConsumerStageBase*> stages)
    {
        for (VulkanConsumerStageBase* stage : stages)
        {
            if (last_stage_ == nullptr)
            {
                decoder_.AddConsumer(stage);
            }
            else
            {
                last_stage_->AddNext(stage);
            }
            last_stage_ = stage;
        }
        last_stage_->AddNext(&log);
    }

  private:
    VulkanDecoder            decoder_;
    VulkanConsumerStageBase* last_stage_ = nullptr;
};

using Lines = std::vector<std::string>;

} // namespace stage_test

#endif // GFXRECON_DECODE_TEST_VULKAN_STAGE_TEST_UTIL_H
