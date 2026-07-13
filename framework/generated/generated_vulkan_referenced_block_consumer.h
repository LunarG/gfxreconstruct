/*
** Copyright (c) 2018-2023 Valve Corporation
** Copyright (c) 2018-2026 LunarG, Inc.
** Copyright (c) 2023 Advanced Micro Devices, Inc.
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

/*
** This file is generated from the Khronos Vulkan XML API Registry.
**
*/

#ifndef  GFXRECON_GENERATED_VULKAN_REFERENCED_BLOCK_CONSUMER_H
#define  GFXRECON_GENERATED_VULKAN_REFERENCED_BLOCK_CONSUMER_H

#include "decode/vulkan_referenced_block_consumer_base.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"
#include "vk_video/vulkan_video_codec_h264std.h"
#include "vk_video/vulkan_video_codec_h264std_decode.h"
#include "vk_video/vulkan_video_codec_h264std_encode.h"
#include "vk_video/vulkan_video_codec_h265std.h"
#include "vk_video/vulkan_video_codec_h265std_decode.h"
#include "vk_video/vulkan_video_codec_h265std_encode.h"
#include "vk_video/vulkan_video_codecs_common.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class VulkanReferencedBlockConsumer : public VulkanReferencedBlockConsumerBase
{
  public:
    VulkanReferencedBlockConsumer(const std::unordered_set<format::HandleId>& unreferenced_ids):
        VulkanReferencedBlockConsumerBase(unreferenced_ids) { }


    void Process_vkBeginCommandBuffer(
        const ApiCallInfo&                          call_info,
        args::BeginCommandBuffer&                   args) override;

    void Process_vkEndCommandBuffer(
        const ApiCallInfo&                          call_info,
        args::EndCommandBuffer&                     args) override;

    void Process_vkResetCommandBuffer(
        const ApiCallInfo&                          call_info,
        args::ResetCommandBuffer&                   args) override;

    void Process_vkCmdCopyBuffer(
        const ApiCallInfo&                          call_info,
        args::CmdCopyBuffer&                        args) override;

    void Process_vkCmdCopyImage(
        const ApiCallInfo&                          call_info,
        args::CmdCopyImage&                         args) override;

    void Process_vkCmdCopyBufferToImage(
        const ApiCallInfo&                          call_info,
        args::CmdCopyBufferToImage&                 args) override;

    void Process_vkCmdCopyImageToBuffer(
        const ApiCallInfo&                          call_info,
        args::CmdCopyImageToBuffer&                 args) override;

    void Process_vkCmdUpdateBuffer(
        const ApiCallInfo&                          call_info,
        args::CmdUpdateBuffer&                      args) override;

    void Process_vkCmdFillBuffer(
        const ApiCallInfo&                          call_info,
        args::CmdFillBuffer&                        args) override;

    void Process_vkCmdPipelineBarrier(
        const ApiCallInfo&                          call_info,
        args::CmdPipelineBarrier&                   args) override;

    void Process_vkCmdBeginQuery(
        const ApiCallInfo&                          call_info,
        args::CmdBeginQuery&                        args) override;

    void Process_vkCmdEndQuery(
        const ApiCallInfo&                          call_info,
        args::CmdEndQuery&                          args) override;

    void Process_vkCmdResetQueryPool(
        const ApiCallInfo&                          call_info,
        args::CmdResetQueryPool&                    args) override;

    void Process_vkCmdWriteTimestamp(
        const ApiCallInfo&                          call_info,
        args::CmdWriteTimestamp&                    args) override;

    void Process_vkCmdCopyQueryPoolResults(
        const ApiCallInfo&                          call_info,
        args::CmdCopyQueryPoolResults&              args) override;

    void Process_vkCmdExecuteCommands(
        const ApiCallInfo&                          call_info,
        args::CmdExecuteCommands&                   args) override;

    void Process_vkCmdBindPipeline(
        const ApiCallInfo&                          call_info,
        args::CmdBindPipeline&                      args) override;

    void Process_vkCmdBindDescriptorSets(
        const ApiCallInfo&                          call_info,
        args::CmdBindDescriptorSets&                args) override;

    void Process_vkCmdClearColorImage(
        const ApiCallInfo&                          call_info,
        args::CmdClearColorImage&                   args) override;

    void Process_vkCmdDispatch(
        const ApiCallInfo&                          call_info,
        args::CmdDispatch&                          args) override;

    void Process_vkCmdDispatchIndirect(
        const ApiCallInfo&                          call_info,
        args::CmdDispatchIndirect&                  args) override;

    void Process_vkCmdSetEvent(
        const ApiCallInfo&                          call_info,
        args::CmdSetEvent&                          args) override;

    void Process_vkCmdResetEvent(
        const ApiCallInfo&                          call_info,
        args::CmdResetEvent&                        args) override;

    void Process_vkCmdWaitEvents(
        const ApiCallInfo&                          call_info,
        args::CmdWaitEvents&                        args) override;

    void Process_vkCmdPushConstants(
        const ApiCallInfo&                          call_info,
        args::CmdPushConstants&                     args) override;

    void Process_vkCmdSetViewport(
        const ApiCallInfo&                          call_info,
        args::CmdSetViewport&                       args) override;

    void Process_vkCmdSetScissor(
        const ApiCallInfo&                          call_info,
        args::CmdSetScissor&                        args) override;

    void Process_vkCmdSetLineWidth(
        const ApiCallInfo&                          call_info,
        args::CmdSetLineWidth&                      args) override;

    void Process_vkCmdSetDepthBias(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthBias&                      args) override;

    void Process_vkCmdSetBlendConstants(
        const ApiCallInfo&                          call_info,
        args::CmdSetBlendConstants&                 args) override;

    void Process_vkCmdSetDepthBounds(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthBounds&                    args) override;

    void Process_vkCmdSetStencilCompareMask(
        const ApiCallInfo&                          call_info,
        args::CmdSetStencilCompareMask&             args) override;

    void Process_vkCmdSetStencilWriteMask(
        const ApiCallInfo&                          call_info,
        args::CmdSetStencilWriteMask&               args) override;

    void Process_vkCmdSetStencilReference(
        const ApiCallInfo&                          call_info,
        args::CmdSetStencilReference&               args) override;

    void Process_vkCmdBindIndexBuffer(
        const ApiCallInfo&                          call_info,
        args::CmdBindIndexBuffer&                   args) override;

    void Process_vkCmdBindVertexBuffers(
        const ApiCallInfo&                          call_info,
        args::CmdBindVertexBuffers&                 args) override;

    void Process_vkCmdDraw(
        const ApiCallInfo&                          call_info,
        args::CmdDraw&                              args) override;

    void Process_vkCmdDrawIndexed(
        const ApiCallInfo&                          call_info,
        args::CmdDrawIndexed&                       args) override;

    void Process_vkCmdDrawIndirect(
        const ApiCallInfo&                          call_info,
        args::CmdDrawIndirect&                      args) override;

    void Process_vkCmdDrawIndexedIndirect(
        const ApiCallInfo&                          call_info,
        args::CmdDrawIndexedIndirect&               args) override;

    void Process_vkCmdBlitImage(
        const ApiCallInfo&                          call_info,
        args::CmdBlitImage&                         args) override;

    void Process_vkCmdClearDepthStencilImage(
        const ApiCallInfo&                          call_info,
        args::CmdClearDepthStencilImage&            args) override;

    void Process_vkCmdClearAttachments(
        const ApiCallInfo&                          call_info,
        args::CmdClearAttachments&                  args) override;

    void Process_vkCmdResolveImage(
        const ApiCallInfo&                          call_info,
        args::CmdResolveImage&                      args) override;

    void Process_vkCmdBeginRenderPass(
        const ApiCallInfo&                          call_info,
        args::CmdBeginRenderPass&                   args) override;

    void Process_vkCmdNextSubpass(
        const ApiCallInfo&                          call_info,
        args::CmdNextSubpass&                       args) override;

    void Process_vkCmdEndRenderPass(
        const ApiCallInfo&                          call_info,
        args::CmdEndRenderPass&                     args) override;

    void Process_vkCmdSetDeviceMask(
        const ApiCallInfo&                          call_info,
        args::CmdSetDeviceMask&                     args) override;

    void Process_vkCmdDispatchBase(
        const ApiCallInfo&                          call_info,
        args::CmdDispatchBase&                      args) override;

    void Process_vkCmdDrawIndirectCount(
        const ApiCallInfo&                          call_info,
        args::CmdDrawIndirectCount&                 args) override;

    void Process_vkCmdDrawIndexedIndirectCount(
        const ApiCallInfo&                          call_info,
        args::CmdDrawIndexedIndirectCount&          args) override;

    void Process_vkCmdBeginRenderPass2(
        const ApiCallInfo&                          call_info,
        args::CmdBeginRenderPass2&                  args) override;

    void Process_vkCmdNextSubpass2(
        const ApiCallInfo&                          call_info,
        args::CmdNextSubpass2&                      args) override;

    void Process_vkCmdEndRenderPass2(
        const ApiCallInfo&                          call_info,
        args::CmdEndRenderPass2&                    args) override;

    void Process_vkCmdPipelineBarrier2(
        const ApiCallInfo&                          call_info,
        args::CmdPipelineBarrier2&                  args) override;

    void Process_vkCmdWriteTimestamp2(
        const ApiCallInfo&                          call_info,
        args::CmdWriteTimestamp2&                   args) override;

    void Process_vkCmdCopyBuffer2(
        const ApiCallInfo&                          call_info,
        args::CmdCopyBuffer2&                       args) override;

    void Process_vkCmdCopyImage2(
        const ApiCallInfo&                          call_info,
        args::CmdCopyImage2&                        args) override;

    void Process_vkCmdCopyBufferToImage2(
        const ApiCallInfo&                          call_info,
        args::CmdCopyBufferToImage2&                args) override;

    void Process_vkCmdCopyImageToBuffer2(
        const ApiCallInfo&                          call_info,
        args::CmdCopyImageToBuffer2&                args) override;

    void Process_vkCmdSetEvent2(
        const ApiCallInfo&                          call_info,
        args::CmdSetEvent2&                         args) override;

    void Process_vkCmdResetEvent2(
        const ApiCallInfo&                          call_info,
        args::CmdResetEvent2&                       args) override;

    void Process_vkCmdWaitEvents2(
        const ApiCallInfo&                          call_info,
        args::CmdWaitEvents2&                       args) override;

    void Process_vkCmdBlitImage2(
        const ApiCallInfo&                          call_info,
        args::CmdBlitImage2&                        args) override;

    void Process_vkCmdResolveImage2(
        const ApiCallInfo&                          call_info,
        args::CmdResolveImage2&                     args) override;

    void Process_vkCmdBeginRendering(
        const ApiCallInfo&                          call_info,
        args::CmdBeginRendering&                    args) override;

    void Process_vkCmdEndRendering(
        const ApiCallInfo&                          call_info,
        args::CmdEndRendering&                      args) override;

    void Process_vkCmdSetCullMode(
        const ApiCallInfo&                          call_info,
        args::CmdSetCullMode&                       args) override;

    void Process_vkCmdSetFrontFace(
        const ApiCallInfo&                          call_info,
        args::CmdSetFrontFace&                      args) override;

    void Process_vkCmdSetPrimitiveTopology(
        const ApiCallInfo&                          call_info,
        args::CmdSetPrimitiveTopology&              args) override;

    void Process_vkCmdSetViewportWithCount(
        const ApiCallInfo&                          call_info,
        args::CmdSetViewportWithCount&              args) override;

    void Process_vkCmdSetScissorWithCount(
        const ApiCallInfo&                          call_info,
        args::CmdSetScissorWithCount&               args) override;

    void Process_vkCmdBindVertexBuffers2(
        const ApiCallInfo&                          call_info,
        args::CmdBindVertexBuffers2&                args) override;

    void Process_vkCmdSetDepthTestEnable(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthTestEnable&                args) override;

    void Process_vkCmdSetDepthWriteEnable(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthWriteEnable&               args) override;

    void Process_vkCmdSetDepthCompareOp(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthCompareOp&                 args) override;

    void Process_vkCmdSetDepthBoundsTestEnable(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthBoundsTestEnable&          args) override;

    void Process_vkCmdSetStencilTestEnable(
        const ApiCallInfo&                          call_info,
        args::CmdSetStencilTestEnable&              args) override;

    void Process_vkCmdSetStencilOp(
        const ApiCallInfo&                          call_info,
        args::CmdSetStencilOp&                      args) override;

    void Process_vkCmdSetRasterizerDiscardEnable(
        const ApiCallInfo&                          call_info,
        args::CmdSetRasterizerDiscardEnable&        args) override;

    void Process_vkCmdSetDepthBiasEnable(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthBiasEnable&                args) override;

    void Process_vkCmdSetPrimitiveRestartEnable(
        const ApiCallInfo&                          call_info,
        args::CmdSetPrimitiveRestartEnable&         args) override;

    void Process_vkCmdPushDescriptorSet(
        const ApiCallInfo&                          call_info,
        args::CmdPushDescriptorSet&                 args) override;

    void Process_vkCmdBindDescriptorSets2(
        const ApiCallInfo&                          call_info,
        args::CmdBindDescriptorSets2&               args) override;

    void Process_vkCmdPushConstants2(
        const ApiCallInfo&                          call_info,
        args::CmdPushConstants2&                    args) override;

    void Process_vkCmdPushDescriptorSet2(
        const ApiCallInfo&                          call_info,
        args::CmdPushDescriptorSet2&                args) override;

    void Process_vkCmdSetLineStipple(
        const ApiCallInfo&                          call_info,
        args::CmdSetLineStipple&                    args) override;

    void Process_vkCmdBindIndexBuffer2(
        const ApiCallInfo&                          call_info,
        args::CmdBindIndexBuffer2&                  args) override;

    void Process_vkCmdSetRenderingAttachmentLocations(
        const ApiCallInfo&                          call_info,
        args::CmdSetRenderingAttachmentLocations&   args) override;

    void Process_vkCmdSetRenderingInputAttachmentIndices(
        const ApiCallInfo&                          call_info,
        args::CmdSetRenderingInputAttachmentIndices& args) override;

    void Process_vkCmdBeginVideoCodingKHR(
        const ApiCallInfo&                          call_info,
        args::CmdBeginVideoCodingKHR&               args) override;

    void Process_vkCmdEndVideoCodingKHR(
        const ApiCallInfo&                          call_info,
        args::CmdEndVideoCodingKHR&                 args) override;

    void Process_vkCmdControlVideoCodingKHR(
        const ApiCallInfo&                          call_info,
        args::CmdControlVideoCodingKHR&             args) override;

    void Process_vkCmdDecodeVideoKHR(
        const ApiCallInfo&                          call_info,
        args::CmdDecodeVideoKHR&                    args) override;

    void Process_vkCmdBeginRenderingKHR(
        const ApiCallInfo&                          call_info,
        args::CmdBeginRenderingKHR&                 args) override;

    void Process_vkCmdEndRenderingKHR(
        const ApiCallInfo&                          call_info,
        args::CmdEndRenderingKHR&                   args) override;

    void Process_vkCmdSetDeviceMaskKHR(
        const ApiCallInfo&                          call_info,
        args::CmdSetDeviceMaskKHR&                  args) override;

    void Process_vkCmdDispatchBaseKHR(
        const ApiCallInfo&                          call_info,
        args::CmdDispatchBaseKHR&                   args) override;

    void Process_vkCmdPushDescriptorSetKHR(
        const ApiCallInfo&                          call_info,
        args::CmdPushDescriptorSetKHR&              args) override;

    void Process_vkCmdBeginRenderPass2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdBeginRenderPass2KHR&               args) override;

    void Process_vkCmdNextSubpass2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdNextSubpass2KHR&                   args) override;

    void Process_vkCmdEndRenderPass2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdEndRenderPass2KHR&                 args) override;

    void Process_vkCmdDrawIndirectCountKHR(
        const ApiCallInfo&                          call_info,
        args::CmdDrawIndirectCountKHR&              args) override;

    void Process_vkCmdDrawIndexedIndirectCountKHR(
        const ApiCallInfo&                          call_info,
        args::CmdDrawIndexedIndirectCountKHR&       args) override;

    void Process_vkCmdSetFragmentShadingRateKHR(
        const ApiCallInfo&                          call_info,
        args::CmdSetFragmentShadingRateKHR&         args) override;

    void Process_vkCmdSetRenderingAttachmentLocationsKHR(
        const ApiCallInfo&                          call_info,
        args::CmdSetRenderingAttachmentLocationsKHR& args) override;

    void Process_vkCmdSetRenderingInputAttachmentIndicesKHR(
        const ApiCallInfo&                          call_info,
        args::CmdSetRenderingInputAttachmentIndicesKHR& args) override;

    void Process_vkCmdEncodeVideoKHR(
        const ApiCallInfo&                          call_info,
        args::CmdEncodeVideoKHR&                    args) override;

    void Process_vkCmdSetEvent2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdSetEvent2KHR&                      args) override;

    void Process_vkCmdResetEvent2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdResetEvent2KHR&                    args) override;

    void Process_vkCmdWaitEvents2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdWaitEvents2KHR&                    args) override;

    void Process_vkCmdPipelineBarrier2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdPipelineBarrier2KHR&               args) override;

    void Process_vkCmdWriteTimestamp2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdWriteTimestamp2KHR&                args) override;

    void Process_vkCmdBindIndexBuffer3KHR(
        const ApiCallInfo&                          call_info,
        args::CmdBindIndexBuffer3KHR&               args) override;

    void Process_vkCmdBindVertexBuffers3KHR(
        const ApiCallInfo&                          call_info,
        args::CmdBindVertexBuffers3KHR&             args) override;

    void Process_vkCmdDrawIndirect2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdDrawIndirect2KHR&                  args) override;

    void Process_vkCmdDrawIndexedIndirect2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdDrawIndexedIndirect2KHR&           args) override;

    void Process_vkCmdDispatchIndirect2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdDispatchIndirect2KHR&              args) override;

    void Process_vkCmdCopyMemoryKHR(
        const ApiCallInfo&                          call_info,
        args::CmdCopyMemoryKHR&                     args) override;

    void Process_vkCmdCopyMemoryToImageKHR(
        const ApiCallInfo&                          call_info,
        args::CmdCopyMemoryToImageKHR&              args) override;

    void Process_vkCmdCopyImageToMemoryKHR(
        const ApiCallInfo&                          call_info,
        args::CmdCopyImageToMemoryKHR&              args) override;

    void Process_vkCmdUpdateMemoryKHR(
        const ApiCallInfo&                          call_info,
        args::CmdUpdateMemoryKHR&                   args) override;

    void Process_vkCmdFillMemoryKHR(
        const ApiCallInfo&                          call_info,
        args::CmdFillMemoryKHR&                     args) override;

    void Process_vkCmdCopyQueryPoolResultsToMemoryKHR(
        const ApiCallInfo&                          call_info,
        args::CmdCopyQueryPoolResultsToMemoryKHR&   args) override;

    void Process_vkCmdDrawIndirectCount2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdDrawIndirectCount2KHR&             args) override;

    void Process_vkCmdDrawIndexedIndirectCount2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdDrawIndexedIndirectCount2KHR&      args) override;

    void Process_vkCmdBeginConditionalRendering2EXT(
        const ApiCallInfo&                          call_info,
        args::CmdBeginConditionalRendering2EXT&     args) override;

    void Process_vkCmdBindTransformFeedbackBuffers2EXT(
        const ApiCallInfo&                          call_info,
        args::CmdBindTransformFeedbackBuffers2EXT&  args) override;

    void Process_vkCmdBeginTransformFeedback2EXT(
        const ApiCallInfo&                          call_info,
        args::CmdBeginTransformFeedback2EXT&        args) override;

    void Process_vkCmdEndTransformFeedback2EXT(
        const ApiCallInfo&                          call_info,
        args::CmdEndTransformFeedback2EXT&          args) override;

    void Process_vkCmdDrawIndirectByteCount2EXT(
        const ApiCallInfo&                          call_info,
        args::CmdDrawIndirectByteCount2EXT&         args) override;

    void Process_vkCmdDrawMeshTasksIndirect2EXT(
        const ApiCallInfo&                          call_info,
        args::CmdDrawMeshTasksIndirect2EXT&         args) override;

    void Process_vkCmdDrawMeshTasksIndirectCount2EXT(
        const ApiCallInfo&                          call_info,
        args::CmdDrawMeshTasksIndirectCount2EXT&    args) override;

    void Process_vkCmdWriteMarkerToMemoryAMD(
        const ApiCallInfo&                          call_info,
        args::CmdWriteMarkerToMemoryAMD&            args) override;

    void Process_vkCmdCopyBuffer2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdCopyBuffer2KHR&                    args) override;

    void Process_vkCmdCopyImage2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdCopyImage2KHR&                     args) override;

    void Process_vkCmdCopyBufferToImage2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdCopyBufferToImage2KHR&             args) override;

    void Process_vkCmdCopyImageToBuffer2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdCopyImageToBuffer2KHR&             args) override;

    void Process_vkCmdBlitImage2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdBlitImage2KHR&                     args) override;

    void Process_vkCmdResolveImage2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdResolveImage2KHR&                  args) override;

    void Process_vkCmdTraceRaysIndirect2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdTraceRaysIndirect2KHR&             args) override;

    void Process_vkCmdBindIndexBuffer2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdBindIndexBuffer2KHR&               args) override;

    void Process_vkCmdSetLineStippleKHR(
        const ApiCallInfo&                          call_info,
        args::CmdSetLineStippleKHR&                 args) override;

    void Process_vkCmdBindDescriptorSets2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdBindDescriptorSets2KHR&            args) override;

    void Process_vkCmdPushConstants2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdPushConstants2KHR&                 args) override;

    void Process_vkCmdPushDescriptorSet2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdPushDescriptorSet2KHR&             args) override;

    void Process_vkCmdSetDescriptorBufferOffsets2EXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetDescriptorBufferOffsets2EXT&    args) override;

    void Process_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT(
        const ApiCallInfo&                          call_info,
        args::CmdBindDescriptorBufferEmbeddedSamplers2EXT& args) override;

    void Process_vkCmdCopyMemoryIndirectKHR(
        const ApiCallInfo&                          call_info,
        args::CmdCopyMemoryIndirectKHR&             args) override;

    void Process_vkCmdCopyMemoryToImageIndirectKHR(
        const ApiCallInfo&                          call_info,
        args::CmdCopyMemoryToImageIndirectKHR&      args) override;

    void Process_vkCmdEndRendering2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdEndRendering2KHR&                  args) override;

    void Process_vkCmdDebugMarkerBeginEXT(
        const ApiCallInfo&                          call_info,
        args::CmdDebugMarkerBeginEXT&               args) override;

    void Process_vkCmdDebugMarkerEndEXT(
        const ApiCallInfo&                          call_info,
        args::CmdDebugMarkerEndEXT&                 args) override;

    void Process_vkCmdDebugMarkerInsertEXT(
        const ApiCallInfo&                          call_info,
        args::CmdDebugMarkerInsertEXT&              args) override;

    void Process_vkCmdBindTransformFeedbackBuffersEXT(
        const ApiCallInfo&                          call_info,
        args::CmdBindTransformFeedbackBuffersEXT&   args) override;

    void Process_vkCmdBeginTransformFeedbackEXT(
        const ApiCallInfo&                          call_info,
        args::CmdBeginTransformFeedbackEXT&         args) override;

    void Process_vkCmdEndTransformFeedbackEXT(
        const ApiCallInfo&                          call_info,
        args::CmdEndTransformFeedbackEXT&           args) override;

    void Process_vkCmdBeginQueryIndexedEXT(
        const ApiCallInfo&                          call_info,
        args::CmdBeginQueryIndexedEXT&              args) override;

    void Process_vkCmdEndQueryIndexedEXT(
        const ApiCallInfo&                          call_info,
        args::CmdEndQueryIndexedEXT&                args) override;

    void Process_vkCmdDrawIndirectByteCountEXT(
        const ApiCallInfo&                          call_info,
        args::CmdDrawIndirectByteCountEXT&          args) override;

    void Process_vkCmdDrawIndirectCountAMD(
        const ApiCallInfo&                          call_info,
        args::CmdDrawIndirectCountAMD&              args) override;

    void Process_vkCmdDrawIndexedIndirectCountAMD(
        const ApiCallInfo&                          call_info,
        args::CmdDrawIndexedIndirectCountAMD&       args) override;

    void Process_vkCmdBeginConditionalRenderingEXT(
        const ApiCallInfo&                          call_info,
        args::CmdBeginConditionalRenderingEXT&      args) override;

    void Process_vkCmdEndConditionalRenderingEXT(
        const ApiCallInfo&                          call_info,
        args::CmdEndConditionalRenderingEXT&        args) override;

    void Process_vkCmdSetViewportWScalingNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetViewportWScalingNV&             args) override;

    void Process_vkCmdSetDiscardRectangleEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetDiscardRectangleEXT&            args) override;

    void Process_vkCmdSetDiscardRectangleEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetDiscardRectangleEnableEXT&      args) override;

    void Process_vkCmdSetDiscardRectangleModeEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetDiscardRectangleModeEXT&        args) override;

    void Process_vkCmdBeginDebugUtilsLabelEXT(
        const ApiCallInfo&                          call_info,
        args::CmdBeginDebugUtilsLabelEXT&           args) override;

    void Process_vkCmdEndDebugUtilsLabelEXT(
        const ApiCallInfo&                          call_info,
        args::CmdEndDebugUtilsLabelEXT&             args) override;

    void Process_vkCmdInsertDebugUtilsLabelEXT(
        const ApiCallInfo&                          call_info,
        args::CmdInsertDebugUtilsLabelEXT&          args) override;

    void Process_vkCmdBeginGpaSessionAMD(
        const ApiCallInfo&                          call_info,
        args::CmdBeginGpaSessionAMD&                args) override;

    void Process_vkCmdEndGpaSessionAMD(
        const ApiCallInfo&                          call_info,
        args::CmdEndGpaSessionAMD&                  args) override;

    void Process_vkCmdBeginGpaSampleAMD(
        const ApiCallInfo&                          call_info,
        args::CmdBeginGpaSampleAMD&                 args) override;

    void Process_vkCmdEndGpaSampleAMD(
        const ApiCallInfo&                          call_info,
        args::CmdEndGpaSampleAMD&                   args) override;

    void Process_vkCmdCopyGpaSessionResultsAMD(
        const ApiCallInfo&                          call_info,
        args::CmdCopyGpaSessionResultsAMD&          args) override;

    void Process_vkCmdSetSampleLocationsEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetSampleLocationsEXT&             args) override;

    void Process_vkCmdBindShadingRateImageNV(
        const ApiCallInfo&                          call_info,
        args::CmdBindShadingRateImageNV&            args) override;

    void Process_vkCmdSetViewportShadingRatePaletteNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetViewportShadingRatePaletteNV&   args) override;

    void Process_vkCmdSetCoarseSampleOrderNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetCoarseSampleOrderNV&            args) override;

    void Process_vkCmdBuildAccelerationStructureNV(
        const ApiCallInfo&                          call_info,
        args::CmdBuildAccelerationStructureNV&      args) override;

    void Process_vkCmdCopyAccelerationStructureNV(
        const ApiCallInfo&                          call_info,
        args::CmdCopyAccelerationStructureNV&       args) override;

    void Process_vkCmdTraceRaysNV(
        const ApiCallInfo&                          call_info,
        args::CmdTraceRaysNV&                       args) override;

    void Process_vkCmdWriteAccelerationStructuresPropertiesNV(
        const ApiCallInfo&                          call_info,
        args::CmdWriteAccelerationStructuresPropertiesNV& args) override;

    void Process_vkCmdWriteBufferMarkerAMD(
        const ApiCallInfo&                          call_info,
        args::CmdWriteBufferMarkerAMD&              args) override;

    void Process_vkCmdWriteBufferMarker2AMD(
        const ApiCallInfo&                          call_info,
        args::CmdWriteBufferMarker2AMD&             args) override;

    void Process_vkCmdDrawMeshTasksNV(
        const ApiCallInfo&                          call_info,
        args::CmdDrawMeshTasksNV&                   args) override;

    void Process_vkCmdDrawMeshTasksIndirectNV(
        const ApiCallInfo&                          call_info,
        args::CmdDrawMeshTasksIndirectNV&           args) override;

    void Process_vkCmdDrawMeshTasksIndirectCountNV(
        const ApiCallInfo&                          call_info,
        args::CmdDrawMeshTasksIndirectCountNV&      args) override;

    void Process_vkCmdSetExclusiveScissorEnableNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetExclusiveScissorEnableNV&       args) override;

    void Process_vkCmdSetExclusiveScissorNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetExclusiveScissorNV&             args) override;

    void Process_vkCmdSetCheckpointNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetCheckpointNV&                   args) override;

    void Process_vkCmdSetPerformanceMarkerINTEL(
        const ApiCallInfo&                          call_info,
        args::CmdSetPerformanceMarkerINTEL&         args) override;

    void Process_vkCmdSetPerformanceStreamMarkerINTEL(
        const ApiCallInfo&                          call_info,
        args::CmdSetPerformanceStreamMarkerINTEL&   args) override;

    void Process_vkCmdSetPerformanceOverrideINTEL(
        const ApiCallInfo&                          call_info,
        args::CmdSetPerformanceOverrideINTEL&       args) override;

    void Process_vkCmdSetLineStippleEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetLineStippleEXT&                 args) override;

    void Process_vkCmdSetCullModeEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetCullModeEXT&                    args) override;

    void Process_vkCmdSetFrontFaceEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetFrontFaceEXT&                   args) override;

    void Process_vkCmdSetPrimitiveTopologyEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetPrimitiveTopologyEXT&           args) override;

    void Process_vkCmdSetViewportWithCountEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetViewportWithCountEXT&           args) override;

    void Process_vkCmdSetScissorWithCountEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetScissorWithCountEXT&            args) override;

    void Process_vkCmdBindVertexBuffers2EXT(
        const ApiCallInfo&                          call_info,
        args::CmdBindVertexBuffers2EXT&             args) override;

    void Process_vkCmdSetDepthTestEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthTestEnableEXT&             args) override;

    void Process_vkCmdSetDepthWriteEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthWriteEnableEXT&            args) override;

    void Process_vkCmdSetDepthCompareOpEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthCompareOpEXT&              args) override;

    void Process_vkCmdSetDepthBoundsTestEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthBoundsTestEnableEXT&       args) override;

    void Process_vkCmdSetStencilTestEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetStencilTestEnableEXT&           args) override;

    void Process_vkCmdSetStencilOpEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetStencilOpEXT&                   args) override;

    void Process_vkCmdPreprocessGeneratedCommandsNV(
        const ApiCallInfo&                          call_info,
        args::CmdPreprocessGeneratedCommandsNV&     args) override;

    void Process_vkCmdExecuteGeneratedCommandsNV(
        const ApiCallInfo&                          call_info,
        args::CmdExecuteGeneratedCommandsNV&        args) override;

    void Process_vkCmdBindPipelineShaderGroupNV(
        const ApiCallInfo&                          call_info,
        args::CmdBindPipelineShaderGroupNV&         args) override;

    void Process_vkCmdSetDepthBias2EXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthBias2EXT&                  args) override;

    void Process_vkCmdDispatchTileQCOM(
        const ApiCallInfo&                          call_info,
        args::CmdDispatchTileQCOM&                  args) override;

    void Process_vkCmdBeginPerTileExecutionQCOM(
        const ApiCallInfo&                          call_info,
        args::CmdBeginPerTileExecutionQCOM&         args) override;

    void Process_vkCmdEndPerTileExecutionQCOM(
        const ApiCallInfo&                          call_info,
        args::CmdEndPerTileExecutionQCOM&           args) override;

    void Process_vkCmdBindDescriptorBuffersEXT(
        const ApiCallInfo&                          call_info,
        args::CmdBindDescriptorBuffersEXT&          args) override;

    void Process_vkCmdSetDescriptorBufferOffsetsEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetDescriptorBufferOffsetsEXT&     args) override;

    void Process_vkCmdBindDescriptorBufferEmbeddedSamplersEXT(
        const ApiCallInfo&                          call_info,
        args::CmdBindDescriptorBufferEmbeddedSamplersEXT& args) override;

    void Process_vkCmdSetFragmentShadingRateEnumNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetFragmentShadingRateEnumNV&      args) override;

    void Process_vkCmdSetVertexInputEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetVertexInputEXT&                 args) override;

    void Process_vkCmdBindInvocationMaskHUAWEI(
        const ApiCallInfo&                          call_info,
        args::CmdBindInvocationMaskHUAWEI&          args) override;

    void Process_vkCmdSetPatchControlPointsEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetPatchControlPointsEXT&          args) override;

    void Process_vkCmdSetRasterizerDiscardEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetRasterizerDiscardEnableEXT&     args) override;

    void Process_vkCmdSetDepthBiasEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthBiasEnableEXT&             args) override;

    void Process_vkCmdSetLogicOpEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetLogicOpEXT&                     args) override;

    void Process_vkCmdSetPrimitiveRestartEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetPrimitiveRestartEnableEXT&      args) override;

    void Process_vkCmdSetColorWriteEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetColorWriteEnableEXT&            args) override;

    void Process_vkCmdDrawMultiEXT(
        const ApiCallInfo&                          call_info,
        args::CmdDrawMultiEXT&                      args) override;

    void Process_vkCmdDrawMultiIndexedEXT(
        const ApiCallInfo&                          call_info,
        args::CmdDrawMultiIndexedEXT&               args) override;

    void Process_vkCmdBuildMicromapsEXT(
        const ApiCallInfo&                          call_info,
        args::CmdBuildMicromapsEXT&                 args) override;

    void Process_vkCmdCopyMicromapEXT(
        const ApiCallInfo&                          call_info,
        args::CmdCopyMicromapEXT&                   args) override;

    void Process_vkCmdCopyMicromapToMemoryEXT(
        const ApiCallInfo&                          call_info,
        args::CmdCopyMicromapToMemoryEXT&           args) override;

    void Process_vkCmdCopyMemoryToMicromapEXT(
        const ApiCallInfo&                          call_info,
        args::CmdCopyMemoryToMicromapEXT&           args) override;

    void Process_vkCmdWriteMicromapsPropertiesEXT(
        const ApiCallInfo&                          call_info,
        args::CmdWriteMicromapsPropertiesEXT&       args) override;

    void Process_vkCmdDrawClusterHUAWEI(
        const ApiCallInfo&                          call_info,
        args::CmdDrawClusterHUAWEI&                 args) override;

    void Process_vkCmdDrawClusterIndirectHUAWEI(
        const ApiCallInfo&                          call_info,
        args::CmdDrawClusterIndirectHUAWEI&         args) override;

    void Process_vkCmdSetDispatchParametersARM(
        const ApiCallInfo&                          call_info,
        args::CmdSetDispatchParametersARM&          args) override;

    void Process_vkCmdUpdatePipelineIndirectBufferNV(
        const ApiCallInfo&                          call_info,
        args::CmdUpdatePipelineIndirectBufferNV&    args) override;

    void Process_vkCmdSetDepthClampEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthClampEnableEXT&            args) override;

    void Process_vkCmdSetPolygonModeEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetPolygonModeEXT&                 args) override;

    void Process_vkCmdSetRasterizationSamplesEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetRasterizationSamplesEXT&        args) override;

    void Process_vkCmdSetSampleMaskEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetSampleMaskEXT&                  args) override;

    void Process_vkCmdSetAlphaToCoverageEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetAlphaToCoverageEnableEXT&       args) override;

    void Process_vkCmdSetAlphaToOneEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetAlphaToOneEnableEXT&            args) override;

    void Process_vkCmdSetLogicOpEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetLogicOpEnableEXT&               args) override;

    void Process_vkCmdSetColorBlendEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetColorBlendEnableEXT&            args) override;

    void Process_vkCmdSetColorBlendEquationEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetColorBlendEquationEXT&          args) override;

    void Process_vkCmdSetColorWriteMaskEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetColorWriteMaskEXT&              args) override;

    void Process_vkCmdSetTessellationDomainOriginEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetTessellationDomainOriginEXT&    args) override;

    void Process_vkCmdSetRasterizationStreamEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetRasterizationStreamEXT&         args) override;

    void Process_vkCmdSetConservativeRasterizationModeEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetConservativeRasterizationModeEXT& args) override;

    void Process_vkCmdSetExtraPrimitiveOverestimationSizeEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetExtraPrimitiveOverestimationSizeEXT& args) override;

    void Process_vkCmdSetDepthClipEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthClipEnableEXT&             args) override;

    void Process_vkCmdSetSampleLocationsEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetSampleLocationsEnableEXT&       args) override;

    void Process_vkCmdSetColorBlendAdvancedEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetColorBlendAdvancedEXT&          args) override;

    void Process_vkCmdSetProvokingVertexModeEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetProvokingVertexModeEXT&         args) override;

    void Process_vkCmdSetLineRasterizationModeEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetLineRasterizationModeEXT&       args) override;

    void Process_vkCmdSetLineStippleEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetLineStippleEnableEXT&           args) override;

    void Process_vkCmdSetDepthClipNegativeOneToOneEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthClipNegativeOneToOneEXT&   args) override;

    void Process_vkCmdSetViewportWScalingEnableNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetViewportWScalingEnableNV&       args) override;

    void Process_vkCmdSetViewportSwizzleNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetViewportSwizzleNV&              args) override;

    void Process_vkCmdSetCoverageToColorEnableNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetCoverageToColorEnableNV&        args) override;

    void Process_vkCmdSetCoverageToColorLocationNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetCoverageToColorLocationNV&      args) override;

    void Process_vkCmdSetCoverageModulationModeNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetCoverageModulationModeNV&       args) override;

    void Process_vkCmdSetCoverageModulationTableEnableNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetCoverageModulationTableEnableNV& args) override;

    void Process_vkCmdSetCoverageModulationTableNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetCoverageModulationTableNV&      args) override;

    void Process_vkCmdSetShadingRateImageEnableNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetShadingRateImageEnableNV&       args) override;

    void Process_vkCmdSetRepresentativeFragmentTestEnableNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetRepresentativeFragmentTestEnableNV& args) override;

    void Process_vkCmdSetCoverageReductionModeNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetCoverageReductionModeNV&        args) override;

    void Process_vkCmdCopyTensorARM(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkCopyTensorInfoARM>* pCopyTensorInfo) override;

    void Process_vkCmdOpticalFlowExecuteNV(
        const ApiCallInfo&                          call_info,
        args::CmdOpticalFlowExecuteNV&              args) override;

    void Process_vkCmdBindShadersEXT(
        const ApiCallInfo&                          call_info,
        args::CmdBindShadersEXT&                    args) override;

    void Process_vkCmdSetDepthClampRangeEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthClampRangeEXT&             args) override;

    void Process_vkCmdConvertCooperativeVectorMatrixNV(
        const ApiCallInfo&                          call_info,
        args::CmdConvertCooperativeVectorMatrixNV&  args) override;

    void Process_vkCmdDispatchDataGraphARM(
        const ApiCallInfo&                          call_info,
        args::CmdDispatchDataGraphARM&              args) override;

    void Process_vkCmdSetAttachmentFeedbackLoopEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetAttachmentFeedbackLoopEnableEXT& args) override;

    void Process_vkCmdBindTileMemoryQCOM(
        const ApiCallInfo&                          call_info,
        args::CmdBindTileMemoryQCOM&                args) override;

    void Process_vkCmdDecompressMemoryEXT(
        const ApiCallInfo&                          call_info,
        args::CmdDecompressMemoryEXT&               args) override;

    void Process_vkCmdDecompressMemoryIndirectCountEXT(
        const ApiCallInfo&                          call_info,
        args::CmdDecompressMemoryIndirectCountEXT&  args) override;

    void Process_vkCmdBuildPartitionedAccelerationStructuresNV(
        const ApiCallInfo&                          call_info,
        args::CmdBuildPartitionedAccelerationStructuresNV& args) override;

    void Process_vkCmdPreprocessGeneratedCommandsEXT(
        const ApiCallInfo&                          call_info,
        args::CmdPreprocessGeneratedCommandsEXT&    args) override;

    void Process_vkCmdExecuteGeneratedCommandsEXT(
        const ApiCallInfo&                          call_info,
        args::CmdExecuteGeneratedCommandsEXT&       args) override;

    void Process_vkCmdEndRendering2EXT(
        const ApiCallInfo&                          call_info,
        args::CmdEndRendering2EXT&                  args) override;

    void Process_vkCmdBeginCustomResolveEXT(
        const ApiCallInfo&                          call_info,
        args::CmdBeginCustomResolveEXT&             args) override;

    void Process_vkCmdSetComputeOccupancyPriorityNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetComputeOccupancyPriorityNV&     args) override;

    void Process_vkCmdSetPrimitiveRestartIndexEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetPrimitiveRestartIndexEXT&       args) override;

    void Process_vkCmdBuildAccelerationStructuresKHR(
        const ApiCallInfo&                          call_info,
        args::CmdBuildAccelerationStructuresKHR&    args) override;

    void Process_vkCmdBuildAccelerationStructuresIndirectKHR(
        const ApiCallInfo&                          call_info,
        args::CmdBuildAccelerationStructuresIndirectKHR& args) override;

    void Process_vkCmdCopyAccelerationStructureKHR(
        const ApiCallInfo&                          call_info,
        args::CmdCopyAccelerationStructureKHR&      args) override;

    void Process_vkCmdCopyAccelerationStructureToMemoryKHR(
        const ApiCallInfo&                          call_info,
        args::CmdCopyAccelerationStructureToMemoryKHR& args) override;

    void Process_vkCmdCopyMemoryToAccelerationStructureKHR(
        const ApiCallInfo&                          call_info,
        args::CmdCopyMemoryToAccelerationStructureKHR& args) override;

    void Process_vkCmdWriteAccelerationStructuresPropertiesKHR(
        const ApiCallInfo&                          call_info,
        args::CmdWriteAccelerationStructuresPropertiesKHR& args) override;

    void Process_vkCmdTraceRaysKHR(
        const ApiCallInfo&                          call_info,
        args::CmdTraceRaysKHR&                      args) override;

    void Process_vkCmdTraceRaysIndirectKHR(
        const ApiCallInfo&                          call_info,
        args::CmdTraceRaysIndirectKHR&              args) override;

    void Process_vkCmdSetRayTracingPipelineStackSizeKHR(
        const ApiCallInfo&                          call_info,
        args::CmdSetRayTracingPipelineStackSizeKHR& args) override;

    void Process_vkCmdDrawMeshTasksEXT(
        const ApiCallInfo&                          call_info,
        args::CmdDrawMeshTasksEXT&                  args) override;

    void Process_vkCmdDrawMeshTasksIndirectEXT(
        const ApiCallInfo&                          call_info,
        args::CmdDrawMeshTasksIndirectEXT&          args) override;

    void Process_vkCmdDrawMeshTasksIndirectCountEXT(
        const ApiCallInfo&                          call_info,
        args::CmdDrawMeshTasksIndirectCountEXT&     args) override;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_GENERATED_VULKAN_REFERENCED_BLOCK_CONSUMER_H
