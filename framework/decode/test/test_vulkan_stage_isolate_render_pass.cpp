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

// Catch must come before the Vulkan headers.
#include <catch2/catch.hpp>

#include "decode/decode_allocator.h"
#include "decode/vulkan_stage_isolate_render_pass.h"
#include "generated/generated_vulkan_decoder.h"

#include <algorithm>
#include <initializer_list>
#include <map>
#include <span>
#include <string>
#include <utility>
#include <vector>

using namespace gfxrecon::decode;
namespace format = gfxrecon::format;

namespace
{

constexpr format::HandleId kDevice = 1;
constexpr format::HandleId kPool   = 2;

constexpr uint32_t kStructPointer     = format::kIsStruct | format::kIsSingle | format::kHasAddress | format::kHasData;
constexpr uint32_t kNullStructPointer = format::kIsStruct | format::kIsSingle | format::kIsNull;
constexpr uint32_t kNullStructArray   = format::kIsStruct | format::kIsArray | format::kIsNull;
constexpr uint32_t kNullArray         = format::kIsArray | format::kIsNull;
constexpr uint32_t kHandlePointer     = format::kIsSingle | format::kHasAddress | format::kHasData;
constexpr uint32_t kArrayPointer      = format::kIsArray | format::kHasAddress | format::kHasData;
constexpr uint32_t kStructArray       = format::kIsStruct | kArrayPointer;

constexpr format::HandleId kPipeline = 80;
constexpr format::HandleId kLayout   = 81;

// Writes call parameters in capture file order. The stage's own writer is private to its .cpp.
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

// Logs every call that the stage sends on, one line per call. A synthetic id prints as S1, S2 and so on,
// in the order that it first appears, so the expected streams read like section 5.1 of the lesson.
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

    // A submit prints, for each submit info, its wait semaphores, its command buffers, the native count and its
    // signal semaphores. The count comes from the native struct, so a test sees whether it matches the ids.

    void Process_vkQueueSubmit(const ApiCallInfo&, args::QueueSubmit& args) override
    {
        std::string line = "Submit";
        for (uint32_t i = 0; i < args.submitCount; ++i)
        {
            const Decoded_VkSubmitInfo& meta   = args.pSubmits.GetMetaStructPointer()[i];
            const VkSubmitInfo&         native = args.pSubmits.GetPointer()[i];

            line += Labeled(" wait", meta.pWaitSemaphores.GetSpan());
            line +=
                " [" + Names(meta.pCommandBuffers.GetSpan()) + "] count " + std::to_string(native.commandBufferCount);
            line += Labeled(" signal", meta.pSignalSemaphores.GetSpan());
        }
        lines.push_back(line + FenceText(args.fence));
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

            line += Labeled(" wait", SemaphoreIds(*meta.pWaitSemaphoreInfos));

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

            line += Labeled(" signal", SemaphoreIds(*meta.pSignalSemaphoreInfos));
        }
        lines.push_back(line + FenceText(args.fence));
    }

    static std::vector<format::HandleId> SemaphoreIds(StructPointerDecoder<Decoded_VkSemaphoreSubmitInfo>& infos)
    {
        std::vector<format::HandleId> ids;
        for (const Decoded_VkSemaphoreSubmitInfo& info : infos.GetMetaStructSpan())
        {
            ids.push_back(info.semaphore);
        }
        return ids;
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

    std::string Name(format::HandleId id)
    {
        if ((id >> 63) == 0)
        {
            return std::to_string(id);
        }

        const auto entry = synthetic_names_.try_emplace(id, synthetic_names_.size() + 1).first;
        return "S" + std::to_string(entry->second);
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
        }
    }

    void Process_vkQueueSubmit2(const ApiCallInfo&, args::QueueSubmit2& args) override { Keep(args); }

    void Process_vkQueueSubmit2KHR(const ApiCallInfo&, args::QueueSubmit2KHR& args) override { Keep(args); }

    std::vector<bool> replaced;

  private:
    template <typename ArgsT>
    void Keep(ArgsT& args)
    {
        for (const Decoded_VkSubmitInfo2& info : args.pSubmits.GetMetaStructSpan())
        {
            replaced.push_back(info.pCommandBufferInfos->GetAddress() != kAppArrayAddress);
        }
    }
};

// A VkRenderPassBeginInfo with no clear values.
void PutRenderPassBeginInfo(Bytes& bytes)
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

Bytes EncodeBeginRenderPass(format::HandleId command_buffer)
{
    Bytes bytes;
    bytes.Put<format::HandleId>(command_buffer);
    PutRenderPassBeginInfo(bytes);
    bytes.Put<uint32_t>(VK_SUBPASS_CONTENTS_INLINE);
    return bytes;
}

// Also the bytes of vkCmdBeginRenderPass2KHR.
Bytes EncodeBeginRenderPass2(format::HandleId command_buffer)
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
Bytes EncodeBeginRendering(format::HandleId command_buffer)
{
    Bytes bytes;
    bytes.Put<format::HandleId>(command_buffer)
        .Put<uint32_t>(kStructPointer) // pRenderingInfo
        .Put<uint64_t>(1)
        .Put<uint32_t>(VK_STRUCTURE_TYPE_RENDERING_INFO)
        .Put<uint32_t>(kNullStructPointer)
        .Put<uint32_t>(0) // flags
        .Put<int32_t>(0)  // renderArea.offset
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

// Also the bytes of vkCmdEndRendering and vkCmdEndRenderingKHR.
Bytes EncodeEndRenderPass(format::HandleId command_buffer)
{
    return Bytes().Put<format::HandleId>(command_buffer);
}

// Also the bytes of vkCmdEndRenderPass2KHR.
Bytes EncodeEndRenderPass2(format::HandleId command_buffer)
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

const std::vector<RenderPassCalls> kRenderPassCalls = {
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

Bytes EncodeBindPipeline(format::HandleId command_buffer, format::HandleId pipeline)
{
    Bytes bytes;
    bytes.Put<format::HandleId>(command_buffer)
        .Put<uint32_t>(VK_PIPELINE_BIND_POINT_GRAPHICS)
        .Put<format::HandleId>(pipeline);
    return bytes;
}

Bytes EncodeBindPipeline(format::HandleId command_buffer)
{
    return EncodeBindPipeline(command_buffer, kPipeline);
}

// Two sets, 60 and 61, and one dynamic offset of 8.
Bytes EncodeBindDescriptorSets(format::HandleId command_buffer)
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
Bytes EncodeBindIndexBuffer(format::HandleId command_buffer)
{
    Bytes bytes;
    bytes.Put<format::HandleId>(command_buffer)
        .Put<format::HandleId>(52)
        .Put<uint64_t>(256)
        .Put<uint32_t>(VK_INDEX_TYPE_UINT16);
    return bytes;
}

// Buffers 53 and 54 at offsets 0 and 128.
Bytes EncodeBindVertexBuffers(format::HandleId command_buffer)
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
Bytes EncodeSetViewport(format::HandleId command_buffer)
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
Bytes EncodeSetScissor(format::HandleId command_buffer)
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
Bytes EncodePushConstants(format::HandleId command_buffer)
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

const std::vector<StateCall> kStateCalls = {
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

constexpr format::HandleId kQueue = 90;
constexpr format::HandleId kFence = 40;

// One VkSubmitInfo or VkSubmitInfo2 of the app. vkQueueSubmit ignores the device masks, and vkQueueSubmit2 uses
// a mask of 0 for a command buffer that has none.
struct AppSubmitInfo
{
    std::vector<format::HandleId> command_buffers;
    std::vector<uint32_t>         device_masks;
    std::vector<format::HandleId> wait_semaphores;
    std::vector<format::HandleId> signal_semaphores;
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

Bytes EncodeQueueSubmit(const std::vector<AppSubmitInfo>& submits, format::HandleId fence)
{
    Bytes bytes;
    bytes.Put<format::HandleId>(kQueue)
        .Put<uint32_t>(static_cast<uint32_t>(submits.size()))
        .Put<uint32_t>(kStructArray)
        .Put<uint64_t>(kAppArrayAddress)
        .Put<uint64_t>(submits.size());
    for (const AppSubmitInfo& submit : submits)
    {
        const std::vector<uint32_t> wait_stages(submit.wait_semaphores.size(), VK_PIPELINE_STAGE_ALL_COMMANDS_BIT);

        bytes.Put<uint32_t>(VK_STRUCTURE_TYPE_SUBMIT_INFO).Put<uint32_t>(kNullStructPointer);
        bytes.Put<uint32_t>(static_cast<uint32_t>(submit.wait_semaphores.size()));
        PutArray(bytes, submit.wait_semaphores);
        PutArray(bytes, wait_stages);
        bytes.Put<uint32_t>(static_cast<uint32_t>(submit.command_buffers.size()));
        PutArray(bytes, submit.command_buffers);
        bytes.Put<uint32_t>(static_cast<uint32_t>(submit.signal_semaphores.size()));
        PutArray(bytes, submit.signal_semaphores);
    }
    bytes.Put<format::HandleId>(fence).Put<int32_t>(VK_SUCCESS);
    return bytes;
}

// A count and an array of VkSemaphoreSubmitInfo.
void PutSemaphoreInfos(Bytes& bytes, const std::vector<format::HandleId>& semaphores)
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
            .Put<uint64_t>(0)                                    // value
            .Put<uint64_t>(VK_PIPELINE_STAGE_2_ALL_COMMANDS_BIT) // stageMask
            .Put<uint32_t>(0);                                   // deviceIndex
    }
}

// Also the bytes of vkQueueSubmit2KHR.
Bytes EncodeQueueSubmit2(const std::vector<AppSubmitInfo>& submits, format::HandleId fence)
{
    Bytes bytes;
    bytes.Put<format::HandleId>(kQueue)
        .Put<uint32_t>(static_cast<uint32_t>(submits.size()))
        .Put<uint32_t>(kStructArray)
        .Put<uint64_t>(kAppArrayAddress)
        .Put<uint64_t>(submits.size());
    for (const AppSubmitInfo& submit : submits)
    {
        bytes.Put<uint32_t>(VK_STRUCTURE_TYPE_SUBMIT_INFO_2)
            .Put<uint32_t>(kNullStructPointer)
            .Put<uint32_t>(0); // flags
        PutSemaphoreInfos(bytes, submit.wait_semaphores);

        const auto& command_buffers = submit.command_buffers;
        bytes.Put<uint32_t>(static_cast<uint32_t>(command_buffers.size()))
            .Put<uint32_t>(kStructArray)
            .Put<uint64_t>(kAppArrayAddress)
            .Put<uint64_t>(command_buffers.size());
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
    bytes.Put<format::HandleId>(fence).Put<int32_t>(VK_SUCCESS);
    return bytes;
}

// Sends app calls through decoder -> stage -> log, the way the file processor would.
class Rig
{
  public:
    Rig()
    {
        decoder_.AddConsumer(&stage_);
        stage_.AddNext(&log);
    }

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

    void Submit(const std::vector<AppSubmitInfo>& submits, format::HandleId fence = format::kNullHandleId)
    {
        Send(format::ApiCall_vkQueueSubmit, EncodeQueueSubmit(submits, fence));
    }

    // The guard opens the allocator scope for one call, as the file processor does.
    void Send(format::ApiCallId call_id, const Bytes& bytes)
    {
        DecoderAllocGuard<true> guard;
        decoder_.DecodeFunctionCall(call_id, ApiCallInfo{}, bytes.data.data(), bytes.data.size());
    }

    void AddNext(VulkanConsumer* next) { stage_.AddNext(next); }

    CallLog log;

  private:
    VulkanDecoder                decoder_;
    VulkanStageIsolateRenderPass stage_;
};

using Lines = std::vector<std::string>;

} // namespace

TEST_CASE("Isolate stage splits a command buffer before a render pass", "[stage][isolate]")
{
    Rig rig;
    rig.Allocate({ 10 });
    rig.Begin(10);
    rig.CopyBuffer(10);
    rig.BeginRenderPass(10);
    rig.Draw(10);
    rig.EndRenderPass(10);
    rig.End(10);

    CHECK(rig.log.lines == Lines{
                               "Allocate 1 2 primary 10",
                               "Begin 10 flags 0",
                               "CopyBuffer 10",
                               "End 10",
                               "Allocate 1 2 primary S1",
                               "Begin S1 flags 0",
                               "BeginRenderPass S1",
                               "Draw S1",
                               "EndRenderPass S1",
                               "End S1",
                           });
}

TEST_CASE("Isolate stage does not split a recording that starts with a render pass", "[stage][isolate]")
{
    Rig rig;
    rig.Allocate({ 10 });
    rig.Begin(10);
    rig.BeginRenderPass(10);
    rig.Draw(10);
    rig.EndRenderPass(10);
    rig.End(10);

    CHECK(rig.log.lines == Lines{
                               "Allocate 1 2 primary 10",
                               "Begin 10 flags 0",
                               "BeginRenderPass 10",
                               "Draw 10",
                               "EndRenderPass 10",
                               "End 10",
                           });
}

TEST_CASE("Isolate stage begins each part with the app's begin flags", "[stage][isolate]")
{
    constexpr VkCommandBufferUsageFlags kFlags =
        VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT | VK_COMMAND_BUFFER_USAGE_SIMULTANEOUS_USE_BIT;

    Rig rig;
    rig.Allocate({ 10 });
    rig.Begin(10, kFlags);
    rig.CopyBuffer(10);
    rig.BeginRenderPass(10);

    REQUIRE(rig.log.lines.size() == 7);
    CHECK(rig.log.lines[5] == "Begin S1 flags " + std::to_string(kFlags));
}

TEST_CASE("Isolate stage never splits or redirects a secondary command buffer", "[stage][isolate]")
{
    Rig rig;
    rig.Allocate({ 20 }, VK_COMMAND_BUFFER_LEVEL_SECONDARY);
    rig.Begin(20);
    rig.CopyBuffer(20);

    // vkCmdBeginRenderPass is not valid in a secondary, but the stage must still leave it alone.
    rig.BeginRenderPass(20);
    rig.End(20);

    CHECK(rig.log.lines == Lines{
                               "Allocate 1 2 secondary 20",
                               "Begin 20 flags 0",
                               "CopyBuffer 20",
                               "BeginRenderPass 20",
                               "End 20",
                           });
}

TEST_CASE("Isolate stage gives each part its own synthetic id", "[stage][isolate]")
{
    Rig rig;
    rig.Allocate({ 10 });
    rig.Begin(10);
    rig.CopyBuffer(10);
    rig.BeginRenderPass(10);
    rig.EndRenderPass(10);
    rig.BeginRenderPass(10);
    rig.EndRenderPass(10);
    rig.End(10);

    CHECK(rig.log.lines == Lines{
                               "Allocate 1 2 primary 10",
                               "Begin 10 flags 0",
                               "CopyBuffer 10",
                               "End 10",
                               "Allocate 1 2 primary S1",
                               "Begin S1 flags 0",
                               "BeginRenderPass S1",
                               "EndRenderPass S1",
                               "End S1",
                               "Allocate 1 2 primary S2",
                               "Begin S2 flags 0",
                               "BeginRenderPass S2",
                               "EndRenderPass S2",
                               "End S2",
                           });
}

TEST_CASE("Isolate stage tracks every command buffer of one allocation", "[stage][isolate]")
{
    Rig rig;
    rig.Allocate({ 10, 11 });
    rig.Begin(11);
    rig.CopyBuffer(11);
    rig.BeginRenderPass(11);

    CHECK(rig.log.lines == Lines{
                               "Allocate 1 2 primary 10 11",
                               "Begin 11 flags 0",
                               "CopyBuffer 11",
                               "End 11",
                               "Allocate 1 2 primary S1",
                               "Begin S1 flags 0",
                               "BeginRenderPass S1",
                           });
}

TEST_CASE("Isolate stage starts a new recording in the app's own command buffer", "[stage][isolate]")
{
    Rig rig;
    rig.Allocate({ 10 });
    rig.Begin(10);
    rig.CopyBuffer(10);
    rig.BeginRenderPass(10);
    rig.EndRenderPass(10);
    rig.End(10);

    rig.log.lines.clear();
    rig.Begin(10);
    rig.CopyBuffer(10);
    rig.End(10);

    CHECK(rig.log.lines == Lines{
                               "Begin 10 flags 0",
                               "CopyBuffer 10",
                               "End 10",
                           });
}

TEST_CASE("Isolate stage gives the app call's bytes back after a split", "[stage][isolate]")
{
    CallBytesProbe probe;

    Rig rig;
    rig.AddNext(&probe);
    rig.Allocate({ 10 });
    rig.Begin(10);
    rig.CopyBuffer(10);
    const auto bytes = rig.BeginRenderPass(10);

    // The invented calls set their own bytes on the probe first. The app call's bytes must win.
    CHECK(probe.seen_at_render_pass.call_id == format::ApiCall_vkCmdBeginRenderPass);
    CHECK(probe.seen_at_render_pass.buffer_size == bytes.size());
}

TEST_CASE("Isolate stage gives back-to-back render passes one part each", "[stage][isolate]")
{
    Rig rig;
    rig.Allocate({ 10 });
    rig.Begin(10);
    rig.BeginRenderPass(10);
    rig.Draw(10);
    rig.EndRenderPass(10);
    rig.BeginRenderPass(10);
    rig.Draw(10);
    rig.EndRenderPass(10);
    rig.End(10);

    // The split after the first pass and the split before the second are one split, so no part is empty.
    CHECK(rig.log.lines == Lines{
                               "Allocate 1 2 primary 10",
                               "Begin 10 flags 0",
                               "BeginRenderPass 10",
                               "Draw 10",
                               "EndRenderPass 10",
                               "End 10",
                               "Allocate 1 2 primary S1",
                               "Begin S1 flags 0",
                               "BeginRenderPass S1",
                               "Draw S1",
                               "EndRenderPass S1",
                               "End S1",
                           });
}

TEST_CASE("Isolate stage puts a command after a split render pass in its own part", "[stage][isolate]")
{
    Rig rig;
    rig.Allocate({ 10 });
    rig.Begin(10);
    rig.CopyBuffer(10);
    rig.BeginRenderPass(10);
    rig.EndRenderPass(10);
    rig.CopyBuffer(10);
    rig.End(10);

    // The render pass runs in S1, so the stage must find the recording of 10 after the pass ends there.
    CHECK(rig.log.lines == Lines{
                               "Allocate 1 2 primary 10",
                               "Begin 10 flags 0",
                               "CopyBuffer 10",
                               "End 10",
                               "Allocate 1 2 primary S1",
                               "Begin S1 flags 0",
                               "BeginRenderPass S1",
                               "EndRenderPass S1",
                               "End S1",
                               "Allocate 1 2 primary S2",
                               "Begin S2 flags 0",
                               "CopyBuffer S2",
                               "End S2",
                           });
}

TEST_CASE("Isolate stage puts a command between two render passes in its own part", "[stage][isolate]")
{
    Rig rig;
    rig.Allocate({ 10 });
    rig.Begin(10);
    rig.CopyBuffer(10);
    rig.BeginRenderPass(10);
    rig.EndRenderPass(10);
    rig.CopyBuffer(10);
    rig.BeginRenderPass(10);
    rig.EndRenderPass(10);
    rig.End(10);

    CHECK(rig.log.lines == Lines{
                               "Allocate 1 2 primary 10",
                               "Begin 10 flags 0",
                               "CopyBuffer 10",
                               "End 10",
                               "Allocate 1 2 primary S1",
                               "Begin S1 flags 0",
                               "BeginRenderPass S1",
                               "EndRenderPass S1",
                               "End S1",
                               "Allocate 1 2 primary S2",
                               "Begin S2 flags 0",
                               "CopyBuffer S2",
                               "End S2",
                               "Allocate 1 2 primary S3",
                               "Begin S3 flags 0",
                               "BeginRenderPass S3",
                               "EndRenderPass S3",
                               "End S3",
                           });
}

TEST_CASE("Isolate stage splits around every begin and end call of a render pass", "[stage][isolate]")
{
    for (const RenderPassCalls& calls : kRenderPassCalls)
    {
        INFO(calls.begin_name);

        Rig rig;
        rig.Allocate({ 10 });
        rig.Begin(10);
        rig.CopyBuffer(10);
        rig.Send(calls.begin_id, calls.encode_begin(10));
        rig.Send(calls.end_id, calls.encode_end(10));
        rig.CopyBuffer(10);
        rig.End(10);

        CHECK(rig.log.lines == Lines{
                                   "Allocate 1 2 primary 10",
                                   "Begin 10 flags 0",
                                   "CopyBuffer 10",
                                   "End 10",
                                   "Allocate 1 2 primary S1",
                                   "Begin S1 flags 0",
                                   calls.begin_name + " S1",
                                   calls.end_name + " S1",
                                   "End S1",
                                   "Allocate 1 2 primary S2",
                                   "Begin S2 flags 0",
                                   "CopyBuffer S2",
                                   "End S2",
                               });
    }
}

TEST_CASE("Isolate stage turns the lesson's example into the stream of section 2", "[stage][isolate]")
{
    Rig rig;
    rig.Allocate({ 10 });
    rig.Begin(10);
    rig.BindPipeline(10);
    rig.CopyBuffer(10);
    rig.BeginRenderPass(10);
    rig.Draw(10);
    rig.EndRenderPass(10);
    rig.BeginRenderPass(10);
    rig.Draw(10);
    rig.EndRenderPass(10);
    rig.End(10);

    CHECK(rig.log.lines == Lines{
                               "Allocate 1 2 primary 10",
                               "Begin 10 flags 0",
                               "BindPipeline 10 80",
                               "CopyBuffer 10",
                               "End 10",
                               "Allocate 1 2 primary S1",
                               "Begin S1 flags 0",
                               "BindPipeline S1 80",
                               "BeginRenderPass S1",
                               "Draw S1",
                               "EndRenderPass S1",
                               "End S1",
                               "Allocate 1 2 primary S2",
                               "Begin S2 flags 0",
                               "BindPipeline S2 80",
                               "BeginRenderPass S2",
                               "Draw S2",
                               "EndRenderPass S2",
                               "End S2",
                           });
}

TEST_CASE("Isolate stage reissues every state command with the data behind its pointers", "[stage][isolate]")
{
    for (const StateCall& call : kStateCalls)
    {
        INFO(call.name);

        Rig rig;
        rig.Allocate({ 10 });
        rig.Begin(10);
        rig.Send(call.id, call.encode(10));
        rig.CopyBuffer(10);
        rig.BeginRenderPass(10);

        CHECK(rig.log.lines == Lines{
                                   "Allocate 1 2 primary 10",
                                   "Begin 10 flags 0",
                                   call.name + " 10" + call.values,
                                   "CopyBuffer 10",
                                   "End 10",
                                   "Allocate 1 2 primary S1",
                                   "Begin S1 flags 0",
                                   call.name + " S1" + call.values,
                                   "BeginRenderPass S1",
                               });
    }
}

TEST_CASE("Isolate stage reissues state commands in the order that the app recorded them", "[stage][isolate]")
{
    Rig rig;
    rig.Allocate({ 10 });
    rig.Begin(10);
    rig.BindPipeline(10, 80);
    rig.SetViewport(10);
    rig.BindPipeline(10, 81);
    rig.CopyBuffer(10);
    rig.BeginRenderPass(10);

    // The last bind wins on the GPU, so the order decides which pipeline the part draws with.
    CHECK(rig.log.lines == Lines{
                               "Allocate 1 2 primary 10",
                               "Begin 10 flags 0",
                               "BindPipeline 10 80",
                               "SetViewport 10 640x480 320x240",
                               "BindPipeline 10 81",
                               "CopyBuffer 10",
                               "End 10",
                               "Allocate 1 2 primary S1",
                               "Begin S1 flags 0",
                               "BindPipeline S1 80",
                               "SetViewport S1 640x480 320x240",
                               "BindPipeline S1 81",
                               "BeginRenderPass S1",
                           });
}

TEST_CASE("Isolate stage sends a state command that follows a pass to the next part once", "[stage][isolate]")
{
    Rig rig;
    rig.Allocate({ 10 });
    rig.Begin(10);
    rig.BeginRenderPass(10);
    rig.Draw(10);
    rig.EndRenderPass(10);
    rig.BindPipeline(10);
    rig.Draw(10);
    rig.End(10);

    // The bind opens the new part. The part must not get the bind both as a reissue and as the app's call.
    CHECK(rig.log.lines == Lines{
                               "Allocate 1 2 primary 10",
                               "Begin 10 flags 0",
                               "BeginRenderPass 10",
                               "Draw 10",
                               "EndRenderPass 10",
                               "End 10",
                               "Allocate 1 2 primary S1",
                               "Begin S1 flags 0",
                               "BindPipeline S1 80",
                               "Draw S1",
                               "End S1",
                           });
}

TEST_CASE("Isolate stage lets state commands share the part of the render pass after them", "[stage][isolate]")
{
    Rig rig;
    rig.Allocate({ 10 });
    rig.Begin(10);
    rig.BindPipeline(10, 80);
    rig.BeginRenderPass(10);
    rig.EndRenderPass(10);
    rig.BindPipeline(10, 81);
    rig.BeginRenderPass(10);
    rig.EndRenderPass(10);
    rig.End(10);

    // A state command is not work. A part that holds only state commands is still fresh, so the render pass
    // after it does not split again.
    CHECK(rig.log.lines == Lines{
                               "Allocate 1 2 primary 10",
                               "Begin 10 flags 0",
                               "BindPipeline 10 80",
                               "BeginRenderPass 10",
                               "EndRenderPass 10",
                               "End 10",
                               "Allocate 1 2 primary S1",
                               "Begin S1 flags 0",
                               "BindPipeline S1 80",
                               "BindPipeline S1 81",
                               "BeginRenderPass S1",
                               "EndRenderPass S1",
                               "End S1",
                           });
}

TEST_CASE("Isolate stage reissues clean values after a consumer edits the arguments", "[stage][isolate]")
{
    ViewportEditor editor;

    Rig rig;
    rig.AddNext(&editor);
    rig.Allocate({ 10 });
    rig.Begin(10);
    rig.SetViewport(10);
    rig.CopyBuffer(10);
    rig.BeginRenderPass(10);
    rig.EndRenderPass(10);
    rig.CopyBuffer(10);
    rig.End(10);

    // The editor runs after the log. A stage that sent the same decoded viewports again would show the
    // editor's 1x1 in the log on the second and third line.
    Lines viewports;
    for (const std::string& line : rig.log.lines)
    {
        if (line.rfind("SetViewport", 0) == 0)
        {
            viewports.push_back(line);
        }
    }
    CHECK(viewports == Lines{
                           "SetViewport 10 640x480 320x240",
                           "SetViewport S1 640x480 320x240",
                           "SetViewport S2 640x480 320x240",
                       });
}

TEST_CASE("Isolate stage keeps its own copy of the bytes of a state command", "[stage][isolate]")
{
    Rig rig;
    rig.Allocate({ 10 });
    rig.Begin(10);

    // The file processor reuses its buffer for the next block, so the bytes change after the call returns.
    Bytes bind = EncodeBindPipeline(10);
    rig.Send(format::ApiCall_vkCmdBindPipeline, bind);
    std::fill(bind.data.begin(), bind.data.end(), uint8_t{ 0xAB });

    rig.CopyBuffer(10);
    rig.BeginRenderPass(10);

    REQUIRE(rig.log.lines.size() == 9);
    CHECK(rig.log.lines[7] == "BindPipeline S1 80");
}

TEST_CASE("Isolate stage does not reissue the state of an earlier recording", "[stage][isolate]")
{
    Rig rig;
    rig.Allocate({ 10 });
    rig.Begin(10);
    rig.BindPipeline(10);
    rig.End(10);

    rig.log.lines.clear();
    rig.Begin(10);
    rig.CopyBuffer(10);
    rig.BeginRenderPass(10);

    CHECK(rig.log.lines == Lines{
                               "Begin 10 flags 0",
                               "CopyBuffer 10",
                               "End 10",
                               "Allocate 1 2 primary S1",
                               "Begin S1 flags 0",
                               "BeginRenderPass S1",
                           });
}

TEST_CASE("Isolate stage submits every part of a split command buffer", "[stage][isolate][submit]")
{
    Rig rig;
    rig.Allocate({ 10 });
    rig.RecordCopyAndRenderPasses(10, 2);
    rig.Submit({ { .command_buffers = { 10 } } });

    CHECK(rig.log.lines.back() == "Submit [10 S1 S2] count 3");
}

TEST_CASE("Isolate stage keeps the submitted order and leaves an unsplit command buffer single",
          "[stage][isolate][submit]")
{
    Rig rig;
    rig.Allocate({ 10, 11 });
    rig.RecordCopyAndRenderPasses(10, 2);
    rig.RecordCopyAndRenderPasses(11, 0);
    rig.Submit({ { .command_buffers = { 10, 11 } } });
    rig.Submit({ { .command_buffers = { 11, 10 } } });

    REQUIRE(rig.log.lines.size() >= 2);
    CHECK(Lines(rig.log.lines.end() - 2, rig.log.lines.end()) == Lines{
                                                                     "Submit [10 S1 S2 11] count 4",
                                                                     "Submit [11 10 S1 S2] count 4",
                                                                 });
}

TEST_CASE("Isolate stage rewrites each submit info of one call on its own", "[stage][isolate][submit]")
{
    SubmitProbe probe;

    Rig rig;
    rig.AddNext(&probe);
    rig.Allocate({ 10, 11, 12 });
    rig.RecordCopyAndRenderPasses(10, 2);
    rig.RecordCopyAndRenderPasses(11, 1);
    rig.RecordCopyAndRenderPasses(12, 0);
    rig.Submit({ { .command_buffers = { 10 } }, { .command_buffers = { 12 } }, { .command_buffers = { 11 } } });

    CHECK(rig.log.lines.back() == "Submit [10 S1 S2] count 3 [12] count 1 [11 S3] count 2");
    CHECK(probe.replaced == std::vector<bool>{ true, false, true });
}

TEST_CASE("Isolate stage keeps the semaphores and the fence of a rewritten submit", "[stage][isolate][submit]")
{
    Rig rig;
    rig.Allocate({ 10 });
    rig.RecordCopyAndRenderPasses(10, 2);
    rig.Submit({ { .command_buffers = { 10 }, .wait_semaphores = { 30 }, .signal_semaphores = { 31 } } }, kFence);

    CHECK(rig.log.lines.back() == "Submit wait 30 [10 S1 S2] count 3 signal 31 fence 40");
}

TEST_CASE("Isolate stage forwards a submit with no split command buffer untouched", "[stage][isolate][submit]")
{
    SubmitProbe probe;

    Rig rig;
    rig.AddNext(&probe);
    rig.Allocate({ 10, 11 });
    rig.RecordCopyAndRenderPasses(10, 2);
    rig.RecordCopyAndRenderPasses(11, 0);

    // The stage tracks no command buffer 99.
    rig.Submit({ { .command_buffers = { 11, 99 } } });

    CHECK(rig.log.lines.back() == "Submit [11 99] count 2");
    CHECK(probe.replaced == std::vector<bool>{ false });
}

TEST_CASE("Isolate stage rewrites vkQueueSubmit2 and vkQueueSubmit2KHR", "[stage][isolate][submit]")
{
    const std::vector<std::pair<std::string, format::ApiCallId>> calls = {
        { "Submit2", format::ApiCall_vkQueueSubmit2 },
        { "Submit2KHR", format::ApiCall_vkQueueSubmit2KHR },
    };

    for (const auto& [name, call_id] : calls)
    {
        INFO(name);

        SubmitProbe probe;

        Rig rig;
        rig.AddNext(&probe);
        rig.Allocate({ 10, 11, 12, 13 });
        rig.RecordCopyAndRenderPasses(10, 2);
        rig.RecordCopyAndRenderPasses(11, 0);
        rig.RecordCopyAndRenderPasses(12, 0);
        rig.RecordCopyAndRenderPasses(13, 1);
        rig.Send(call_id,
                 EncodeQueueSubmit2(
                     {
                         { .command_buffers = { 10, 11 }, .device_masks = { 1, 2 }, .wait_semaphores = { 30 } },
                         { .command_buffers = { 12 }, .device_masks = { 4 }, .signal_semaphores = { 31 } },
                         { .command_buffers = { 13 }, .device_masks = { 8 } },
                     },
                     kFence));

        // Each part takes the device mask of the app's entry that it replaces.
        CHECK(rig.log.lines.back() ==
              name + " wait 30 [10:1 S1:1 S2:1 11:2] count 4 [12:4] count 1 signal 31 [13:8 S3:8] count 2 fence 40");
        CHECK(probe.replaced == std::vector<bool>{ true, false, true });
    }
}

TEST_CASE("Isolate stage reuses the parts of a command buffer that the app records again",
          "[stage][isolate][lifecycle]")
{
    Rig rig;
    rig.CreateCommandPool(kPool, VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT);
    rig.Allocate({ 10 });
    rig.RecordCopyAndRenderPasses(10, 2);

    rig.log.lines.clear();
    rig.RecordCopyAndRenderPasses(10, 2);
    rig.Submit({ { .command_buffers = { 10 } } });

    // The spare list hands out the newest part first, so S2 comes before S1. No part is allocated again.
    CHECK(rig.log.lines == Lines{
                               "Begin 10 flags 0",
                               "CopyBuffer 10",
                               "End 10",
                               "Begin S2 flags 0",
                               "BeginRenderPass S2",
                               "Draw S2",
                               "EndRenderPass S2",
                               "End S2",
                               "Begin S1 flags 0",
                               "BeginRenderPass S1",
                               "Draw S1",
                               "EndRenderPass S1",
                               "End S1",
                               "Submit [10 S2 S1] count 3",
                           });
}

TEST_CASE("Isolate stage reuses a part of a pool without the reset bit only after a pool reset",
          "[stage][isolate][lifecycle]")
{
    Rig rig;
    rig.CreateCommandPool(kPool, 0);
    rig.Allocate({ 10, 11 });
    rig.RecordCopyAndRenderPasses(10, 1);

    // S1 has not been reset, so 11 cannot begin it.
    rig.FreeCommandBuffers({ 10 });
    rig.log.lines.clear();
    rig.RecordCopyAndRenderPasses(11, 1);
    CHECK(rig.log.lines[3] == "Allocate 1 2 primary S2");

    rig.ResetCommandPool(kPool);
    rig.log.lines.clear();
    rig.RecordCopyAndRenderPasses(11, 1);
    CHECK(rig.log.lines == Lines{
                               "Begin 11 flags 0",
                               "CopyBuffer 11",
                               "End 11",
                               "Begin S2 flags 0",
                               "BeginRenderPass S2",
                               "Draw S2",
                               "EndRenderPass S2",
                               "End S2",
                           });
}

TEST_CASE("Isolate stage releases each part once on a pool reset", "[stage][isolate][lifecycle]")
{
    Rig rig;
    rig.CreateCommandPool(kPool, 0);
    rig.Allocate({ 10 });
    rig.RecordCopyAndRenderPasses(10, 1);
    rig.ResetCommandPool(kPool);
    rig.RecordCopyAndRenderPasses(10, 1);
    rig.ResetCommandPool(kPool);

    // Only S1 is spare, so the second split must allocate. A part that sits twice in the spare list would be
    // begun twice in one recording.
    rig.log.lines.clear();
    rig.RecordCopyAndRenderPasses(10, 2);
    CHECK(rig.log.lines == Lines{
                               "Begin 10 flags 0",
                               "CopyBuffer 10",
                               "End 10",
                               "Begin S1 flags 0",
                               "BeginRenderPass S1",
                               "Draw S1",
                               "EndRenderPass S1",
                               "End S1",
                               "Allocate 1 2 primary S2",
                               "Begin S2 flags 0",
                               "BeginRenderPass S2",
                               "Draw S2",
                               "EndRenderPass S2",
                               "End S2",
                           });
}

TEST_CASE("Isolate stage gives the parts of a freed command buffer to another command buffer of the pool",
          "[stage][isolate][lifecycle]")
{
    Rig rig;
    rig.CreateCommandPool(kPool, VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT);
    rig.Allocate({ 10, 11 });
    rig.RecordCopyAndRenderPasses(10, 1);
    rig.FreeCommandBuffers({ 10 });

    rig.log.lines.clear();
    rig.RecordCopyAndRenderPasses(11, 1);
    rig.Submit({ { .command_buffers = { 11 } } });

    CHECK(rig.log.lines == Lines{
                               "Begin 11 flags 0",
                               "CopyBuffer 11",
                               "End 11",
                               "Begin S1 flags 0",
                               "BeginRenderPass S1",
                               "Draw S1",
                               "EndRenderPass S1",
                               "End S1",
                               "Submit [11 S1] count 2",
                           });
}

TEST_CASE("Isolate stage gives the parts of a reset command buffer to the pool", "[stage][isolate][lifecycle]")
{
    Rig rig;
    rig.CreateCommandPool(kPool, VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT);
    rig.Allocate({ 10, 11 });
    rig.RecordCopyAndRenderPasses(10, 1);
    rig.ResetCommandBuffer(10);

    // After the reset, 10 is one command buffer again, and 11 can begin its old part.
    rig.Submit({ { .command_buffers = { 10 } } });
    CHECK(rig.log.lines.back() == "Submit [10] count 1");
    rig.log.lines.clear();
    rig.RecordCopyAndRenderPasses(11, 1);

    CHECK(rig.log.lines[3] == "Begin S1 flags 0");
}

TEST_CASE("Isolate stage forgets a destroyed pool and its command buffers", "[stage][isolate][lifecycle]")
{
    Rig rig;
    rig.CreateCommandPool(kPool, VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT);
    rig.Allocate({ 10, 11 });
    rig.RecordCopyAndRenderPasses(10, 1);
    rig.RecordCopyAndRenderPasses(11, 1);
    rig.FreeCommandBuffers({ 10 });
    rig.DestroyCommandPool(kPool);

    // Destroying the pool frees 11, so the stage no longer expands it.
    rig.Submit({ { .command_buffers = { 11 } } });
    CHECK(rig.log.lines.back() == "Submit [11] count 1");

    // A capture never reuses a pool id. The test reuses it to see that the spare S1 went with the old pool.
    rig.CreateCommandPool(kPool, VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT);
    rig.Allocate({ 12 });
    rig.log.lines.clear();
    rig.RecordCopyAndRenderPasses(12, 1);
    CHECK(rig.log.lines[3] == "Allocate 1 2 primary S3");
}
