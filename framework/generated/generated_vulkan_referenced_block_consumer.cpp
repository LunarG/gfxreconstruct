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

#include "generated/generated_vulkan_referenced_block_consumer.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void VulkanReferencedBlockConsumer::Process_vkBeginCommandBuffer(
    const ApiCallInfo&                          call_info,
    args::BeginCommandBuffer&                   args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkEndCommandBuffer(
    const ApiCallInfo&                          call_info,
    args::EndCommandBuffer&                     args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkResetCommandBuffer(
    const ApiCallInfo&                          call_info,
    args::ResetCommandBuffer&                   args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdCopyBuffer(
    const ApiCallInfo&                          call_info,
    args::CmdCopyBuffer&                        args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdCopyImage(
    const ApiCallInfo&                          call_info,
    args::CmdCopyImage&                         args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdCopyBufferToImage(
    const ApiCallInfo&                          call_info,
    args::CmdCopyBufferToImage&                 args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdCopyImageToBuffer(
    const ApiCallInfo&                          call_info,
    args::CmdCopyImageToBuffer&                 args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdUpdateBuffer(
    const ApiCallInfo&                          call_info,
    args::CmdUpdateBuffer&                      args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdFillBuffer(
    const ApiCallInfo&                          call_info,
    args::CmdFillBuffer&                        args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdPipelineBarrier(
    const ApiCallInfo&                          call_info,
    args::CmdPipelineBarrier&                   args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBeginQuery(
    const ApiCallInfo&                          call_info,
    args::CmdBeginQuery&                        args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdEndQuery(
    const ApiCallInfo&                          call_info,
    args::CmdEndQuery&                          args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdResetQueryPool(
    const ApiCallInfo&                          call_info,
    args::CmdResetQueryPool&                    args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdWriteTimestamp(
    const ApiCallInfo&                          call_info,
    args::CmdWriteTimestamp&                    args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdCopyQueryPoolResults(
    const ApiCallInfo&                          call_info,
    args::CmdCopyQueryPoolResults&              args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdExecuteCommands(
    const ApiCallInfo&                          call_info,
    args::CmdExecuteCommands&                   args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBindPipeline(
    const ApiCallInfo&                          call_info,
    args::CmdBindPipeline&                      args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBindDescriptorSets(
    const ApiCallInfo&                          call_info,
    args::CmdBindDescriptorSets&                args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdClearColorImage(
    const ApiCallInfo&                          call_info,
    args::CmdClearColorImage&                   args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDispatch(
    const ApiCallInfo&                          call_info,
    args::CmdDispatch&                          args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDispatchIndirect(
    const ApiCallInfo&                          call_info,
    args::CmdDispatchIndirect&                  args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetEvent(
    const ApiCallInfo&                          call_info,
    args::CmdSetEvent&                          args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdResetEvent(
    const ApiCallInfo&                          call_info,
    args::CmdResetEvent&                        args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdWaitEvents(
    const ApiCallInfo&                          call_info,
    args::CmdWaitEvents&                        args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdPushConstants(
    const ApiCallInfo&                          call_info,
    args::CmdPushConstants&                     args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetViewport(
    const ApiCallInfo&                          call_info,
    args::CmdSetViewport&                       args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetScissor(
    const ApiCallInfo&                          call_info,
    args::CmdSetScissor&                        args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetLineWidth(
    const ApiCallInfo&                          call_info,
    args::CmdSetLineWidth&                      args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetDepthBias(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthBias&                      args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetBlendConstants(
    const ApiCallInfo&                          call_info,
    args::CmdSetBlendConstants&                 args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetDepthBounds(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthBounds&                    args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetStencilCompareMask(
    const ApiCallInfo&                          call_info,
    args::CmdSetStencilCompareMask&             args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetStencilWriteMask(
    const ApiCallInfo&                          call_info,
    args::CmdSetStencilWriteMask&               args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetStencilReference(
    const ApiCallInfo&                          call_info,
    args::CmdSetStencilReference&               args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBindIndexBuffer(
    const ApiCallInfo&                          call_info,
    args::CmdBindIndexBuffer&                   args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBindVertexBuffers(
    const ApiCallInfo&                          call_info,
    args::CmdBindVertexBuffers&                 args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDraw(
    const ApiCallInfo&                          call_info,
    args::CmdDraw&                              args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDrawIndexed(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndexed&                       args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDrawIndirect(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndirect&                      args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDrawIndexedIndirect(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndexedIndirect&               args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBlitImage(
    const ApiCallInfo&                          call_info,
    args::CmdBlitImage&                         args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdClearDepthStencilImage(
    const ApiCallInfo&                          call_info,
    args::CmdClearDepthStencilImage&            args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdClearAttachments(
    const ApiCallInfo&                          call_info,
    args::CmdClearAttachments&                  args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdResolveImage(
    const ApiCallInfo&                          call_info,
    args::CmdResolveImage&                      args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBeginRenderPass(
    const ApiCallInfo&                          call_info,
    args::CmdBeginRenderPass&                   args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdNextSubpass(
    const ApiCallInfo&                          call_info,
    args::CmdNextSubpass&                       args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdEndRenderPass(
    const ApiCallInfo&                          call_info,
    args::CmdEndRenderPass&                     args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetDeviceMask(
    const ApiCallInfo&                          call_info,
    args::CmdSetDeviceMask&                     args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDispatchBase(
    const ApiCallInfo&                          call_info,
    args::CmdDispatchBase&                      args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDrawIndirectCount(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndirectCount&                 args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDrawIndexedIndirectCount(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndexedIndirectCount&          args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBeginRenderPass2(
    const ApiCallInfo&                          call_info,
    args::CmdBeginRenderPass2&                  args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdNextSubpass2(
    const ApiCallInfo&                          call_info,
    args::CmdNextSubpass2&                      args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdEndRenderPass2(
    const ApiCallInfo&                          call_info,
    args::CmdEndRenderPass2&                    args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdPipelineBarrier2(
    const ApiCallInfo&                          call_info,
    args::CmdPipelineBarrier2&                  args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdWriteTimestamp2(
    const ApiCallInfo&                          call_info,
    args::CmdWriteTimestamp2&                   args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdCopyBuffer2(
    const ApiCallInfo&                          call_info,
    args::CmdCopyBuffer2&                       args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdCopyImage2(
    const ApiCallInfo&                          call_info,
    args::CmdCopyImage2&                        args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdCopyBufferToImage2(
    const ApiCallInfo&                          call_info,
    args::CmdCopyBufferToImage2&                args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdCopyImageToBuffer2(
    const ApiCallInfo&                          call_info,
    args::CmdCopyImageToBuffer2&                args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetEvent2(
    const ApiCallInfo&                          call_info,
    args::CmdSetEvent2&                         args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdResetEvent2(
    const ApiCallInfo&                          call_info,
    args::CmdResetEvent2&                       args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdWaitEvents2(
    const ApiCallInfo&                          call_info,
    args::CmdWaitEvents2&                       args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBlitImage2(
    const ApiCallInfo&                          call_info,
    args::CmdBlitImage2&                        args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdResolveImage2(
    const ApiCallInfo&                          call_info,
    args::CmdResolveImage2&                     args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBeginRendering(
    const ApiCallInfo&                          call_info,
    args::CmdBeginRendering&                    args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdEndRendering(
    const ApiCallInfo&                          call_info,
    args::CmdEndRendering&                      args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetCullMode(
    const ApiCallInfo&                          call_info,
    args::CmdSetCullMode&                       args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetFrontFace(
    const ApiCallInfo&                          call_info,
    args::CmdSetFrontFace&                      args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetPrimitiveTopology(
    const ApiCallInfo&                          call_info,
    args::CmdSetPrimitiveTopology&              args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetViewportWithCount(
    const ApiCallInfo&                          call_info,
    args::CmdSetViewportWithCount&              args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetScissorWithCount(
    const ApiCallInfo&                          call_info,
    args::CmdSetScissorWithCount&               args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBindVertexBuffers2(
    const ApiCallInfo&                          call_info,
    args::CmdBindVertexBuffers2&                args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetDepthTestEnable(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthTestEnable&                args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetDepthWriteEnable(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthWriteEnable&               args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetDepthCompareOp(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthCompareOp&                 args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetDepthBoundsTestEnable(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthBoundsTestEnable&          args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetStencilTestEnable(
    const ApiCallInfo&                          call_info,
    args::CmdSetStencilTestEnable&              args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetStencilOp(
    const ApiCallInfo&                          call_info,
    args::CmdSetStencilOp&                      args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetRasterizerDiscardEnable(
    const ApiCallInfo&                          call_info,
    args::CmdSetRasterizerDiscardEnable&        args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetDepthBiasEnable(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthBiasEnable&                args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetPrimitiveRestartEnable(
    const ApiCallInfo&                          call_info,
    args::CmdSetPrimitiveRestartEnable&         args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdPushDescriptorSet(
    const ApiCallInfo&                          call_info,
    args::CmdPushDescriptorSet&                 args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBindDescriptorSets2(
    const ApiCallInfo&                          call_info,
    args::CmdBindDescriptorSets2&               args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdPushConstants2(
    const ApiCallInfo&                          call_info,
    args::CmdPushConstants2&                    args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdPushDescriptorSet2(
    const ApiCallInfo&                          call_info,
    args::CmdPushDescriptorSet2&                args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetLineStipple(
    const ApiCallInfo&                          call_info,
    args::CmdSetLineStipple&                    args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBindIndexBuffer2(
    const ApiCallInfo&                          call_info,
    args::CmdBindIndexBuffer2&                  args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetRenderingAttachmentLocations(
    const ApiCallInfo&                          call_info,
    args::CmdSetRenderingAttachmentLocations&   args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetRenderingInputAttachmentIndices(
    const ApiCallInfo&                          call_info,
    args::CmdSetRenderingInputAttachmentIndices& args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBeginVideoCodingKHR(
    const ApiCallInfo&                          call_info,
    args::CmdBeginVideoCodingKHR&               args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdEndVideoCodingKHR(
    const ApiCallInfo&                          call_info,
    args::CmdEndVideoCodingKHR&                 args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdControlVideoCodingKHR(
    const ApiCallInfo&                          call_info,
    args::CmdControlVideoCodingKHR&             args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDecodeVideoKHR(
    const ApiCallInfo&                          call_info,
    args::CmdDecodeVideoKHR&                    args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBeginRenderingKHR(
    const ApiCallInfo&                          call_info,
    args::CmdBeginRenderingKHR&                 args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdEndRenderingKHR(
    const ApiCallInfo&                          call_info,
    args::CmdEndRenderingKHR&                   args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetDeviceMaskKHR(
    const ApiCallInfo&                          call_info,
    args::CmdSetDeviceMaskKHR&                  args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDispatchBaseKHR(
    const ApiCallInfo&                          call_info,
    args::CmdDispatchBaseKHR&                   args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdPushDescriptorSetKHR(
    const ApiCallInfo&                          call_info,
    args::CmdPushDescriptorSetKHR&              args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBeginRenderPass2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdBeginRenderPass2KHR&               args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdNextSubpass2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdNextSubpass2KHR&                   args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdEndRenderPass2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdEndRenderPass2KHR&                 args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDrawIndirectCountKHR(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndirectCountKHR&              args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDrawIndexedIndirectCountKHR(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndexedIndirectCountKHR&       args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetFragmentShadingRateKHR(
    const ApiCallInfo&                          call_info,
    args::CmdSetFragmentShadingRateKHR&         args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetRenderingAttachmentLocationsKHR(
    const ApiCallInfo&                          call_info,
    args::CmdSetRenderingAttachmentLocationsKHR& args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetRenderingInputAttachmentIndicesKHR(
    const ApiCallInfo&                          call_info,
    args::CmdSetRenderingInputAttachmentIndicesKHR& args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdEncodeVideoKHR(
    const ApiCallInfo&                          call_info,
    args::CmdEncodeVideoKHR&                    args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetEvent2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdSetEvent2KHR&                      args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdResetEvent2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdResetEvent2KHR&                    args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdWaitEvents2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdWaitEvents2KHR&                    args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdPipelineBarrier2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdPipelineBarrier2KHR&               args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdWriteTimestamp2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdWriteTimestamp2KHR&                args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBindIndexBuffer3KHR(
    const ApiCallInfo&                          call_info,
    args::CmdBindIndexBuffer3KHR&               args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBindVertexBuffers3KHR(
    const ApiCallInfo&                          call_info,
    args::CmdBindVertexBuffers3KHR&             args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDrawIndirect2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndirect2KHR&                  args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDrawIndexedIndirect2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndexedIndirect2KHR&           args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDispatchIndirect2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdDispatchIndirect2KHR&              args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdCopyMemoryKHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyMemoryKHR&                     args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdCopyMemoryToImageKHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyMemoryToImageKHR&              args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdCopyImageToMemoryKHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyImageToMemoryKHR&              args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdUpdateMemoryKHR(
    const ApiCallInfo&                          call_info,
    args::CmdUpdateMemoryKHR&                   args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdFillMemoryKHR(
    const ApiCallInfo&                          call_info,
    args::CmdFillMemoryKHR&                     args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdCopyQueryPoolResultsToMemoryKHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyQueryPoolResultsToMemoryKHR&   args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDrawIndirectCount2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndirectCount2KHR&             args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDrawIndexedIndirectCount2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndexedIndirectCount2KHR&      args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBeginConditionalRendering2EXT(
    const ApiCallInfo&                          call_info,
    args::CmdBeginConditionalRendering2EXT&     args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBindTransformFeedbackBuffers2EXT(
    const ApiCallInfo&                          call_info,
    args::CmdBindTransformFeedbackBuffers2EXT&  args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBeginTransformFeedback2EXT(
    const ApiCallInfo&                          call_info,
    args::CmdBeginTransformFeedback2EXT&        args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdEndTransformFeedback2EXT(
    const ApiCallInfo&                          call_info,
    args::CmdEndTransformFeedback2EXT&          args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDrawIndirectByteCount2EXT(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndirectByteCount2EXT&         args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDrawMeshTasksIndirect2EXT(
    const ApiCallInfo&                          call_info,
    args::CmdDrawMeshTasksIndirect2EXT&         args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDrawMeshTasksIndirectCount2EXT(
    const ApiCallInfo&                          call_info,
    args::CmdDrawMeshTasksIndirectCount2EXT&    args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdWriteMarkerToMemoryAMD(
    const ApiCallInfo&                          call_info,
    args::CmdWriteMarkerToMemoryAMD&            args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdCopyBuffer2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyBuffer2KHR&                    args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdCopyImage2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyImage2KHR&                     args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdCopyBufferToImage2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyBufferToImage2KHR&             args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdCopyImageToBuffer2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyImageToBuffer2KHR&             args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBlitImage2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdBlitImage2KHR&                     args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdResolveImage2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdResolveImage2KHR&                  args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdTraceRaysIndirect2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdTraceRaysIndirect2KHR&             args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBindIndexBuffer2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdBindIndexBuffer2KHR&               args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetLineStippleKHR(
    const ApiCallInfo&                          call_info,
    args::CmdSetLineStippleKHR&                 args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBindDescriptorSets2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdBindDescriptorSets2KHR&            args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdPushConstants2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdPushConstants2KHR&                 args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdPushDescriptorSet2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdPushDescriptorSet2KHR&             args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetDescriptorBufferOffsets2EXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDescriptorBufferOffsets2EXT&    args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT(
    const ApiCallInfo&                          call_info,
    args::CmdBindDescriptorBufferEmbeddedSamplers2EXT& args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdCopyMemoryIndirectKHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyMemoryIndirectKHR&             args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdCopyMemoryToImageIndirectKHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyMemoryToImageIndirectKHR&      args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdEndRendering2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdEndRendering2KHR&                  args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDebugMarkerBeginEXT(
    const ApiCallInfo&                          call_info,
    args::CmdDebugMarkerBeginEXT&               args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDebugMarkerEndEXT(
    const ApiCallInfo&                          call_info,
    args::CmdDebugMarkerEndEXT&                 args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDebugMarkerInsertEXT(
    const ApiCallInfo&                          call_info,
    args::CmdDebugMarkerInsertEXT&              args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBindTransformFeedbackBuffersEXT(
    const ApiCallInfo&                          call_info,
    args::CmdBindTransformFeedbackBuffersEXT&   args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBeginTransformFeedbackEXT(
    const ApiCallInfo&                          call_info,
    args::CmdBeginTransformFeedbackEXT&         args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdEndTransformFeedbackEXT(
    const ApiCallInfo&                          call_info,
    args::CmdEndTransformFeedbackEXT&           args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBeginQueryIndexedEXT(
    const ApiCallInfo&                          call_info,
    args::CmdBeginQueryIndexedEXT&              args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdEndQueryIndexedEXT(
    const ApiCallInfo&                          call_info,
    args::CmdEndQueryIndexedEXT&                args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDrawIndirectByteCountEXT(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndirectByteCountEXT&          args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDrawIndirectCountAMD(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndirectCountAMD&              args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDrawIndexedIndirectCountAMD(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndexedIndirectCountAMD&       args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBeginConditionalRenderingEXT(
    const ApiCallInfo&                          call_info,
    args::CmdBeginConditionalRenderingEXT&      args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdEndConditionalRenderingEXT(
    const ApiCallInfo&                          call_info,
    args::CmdEndConditionalRenderingEXT&        args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetViewportWScalingNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetViewportWScalingNV&             args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetDiscardRectangleEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDiscardRectangleEXT&            args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetDiscardRectangleEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDiscardRectangleEnableEXT&      args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetDiscardRectangleModeEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDiscardRectangleModeEXT&        args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBeginDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    args::CmdBeginDebugUtilsLabelEXT&           args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdEndDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    args::CmdEndDebugUtilsLabelEXT&             args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdInsertDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    args::CmdInsertDebugUtilsLabelEXT&          args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBeginGpaSessionAMD(
    const ApiCallInfo&                          call_info,
    args::CmdBeginGpaSessionAMD&                args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdEndGpaSessionAMD(
    const ApiCallInfo&                          call_info,
    args::CmdEndGpaSessionAMD&                  args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBeginGpaSampleAMD(
    const ApiCallInfo&                          call_info,
    args::CmdBeginGpaSampleAMD&                 args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdEndGpaSampleAMD(
    const ApiCallInfo&                          call_info,
    args::CmdEndGpaSampleAMD&                   args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdCopyGpaSessionResultsAMD(
    const ApiCallInfo&                          call_info,
    args::CmdCopyGpaSessionResultsAMD&          args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetSampleLocationsEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetSampleLocationsEXT&             args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBindShadingRateImageNV(
    const ApiCallInfo&                          call_info,
    args::CmdBindShadingRateImageNV&            args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetViewportShadingRatePaletteNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetViewportShadingRatePaletteNV&   args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetCoarseSampleOrderNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetCoarseSampleOrderNV&            args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBuildAccelerationStructureNV(
    const ApiCallInfo&                          call_info,
    args::CmdBuildAccelerationStructureNV&      args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdCopyAccelerationStructureNV(
    const ApiCallInfo&                          call_info,
    args::CmdCopyAccelerationStructureNV&       args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdTraceRaysNV(
    const ApiCallInfo&                          call_info,
    args::CmdTraceRaysNV&                       args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdWriteAccelerationStructuresPropertiesNV(
    const ApiCallInfo&                          call_info,
    args::CmdWriteAccelerationStructuresPropertiesNV& args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdWriteBufferMarkerAMD(
    const ApiCallInfo&                          call_info,
    args::CmdWriteBufferMarkerAMD&              args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdWriteBufferMarker2AMD(
    const ApiCallInfo&                          call_info,
    args::CmdWriteBufferMarker2AMD&             args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDrawMeshTasksNV(
    const ApiCallInfo&                          call_info,
    args::CmdDrawMeshTasksNV&                   args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDrawMeshTasksIndirectNV(
    const ApiCallInfo&                          call_info,
    args::CmdDrawMeshTasksIndirectNV&           args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDrawMeshTasksIndirectCountNV(
    const ApiCallInfo&                          call_info,
    args::CmdDrawMeshTasksIndirectCountNV&      args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetExclusiveScissorEnableNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetExclusiveScissorEnableNV&       args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetExclusiveScissorNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetExclusiveScissorNV&             args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetCheckpointNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetCheckpointNV&                   args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetPerformanceMarkerINTEL(
    const ApiCallInfo&                          call_info,
    args::CmdSetPerformanceMarkerINTEL&         args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetPerformanceStreamMarkerINTEL(
    const ApiCallInfo&                          call_info,
    args::CmdSetPerformanceStreamMarkerINTEL&   args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetPerformanceOverrideINTEL(
    const ApiCallInfo&                          call_info,
    args::CmdSetPerformanceOverrideINTEL&       args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetLineStippleEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetLineStippleEXT&                 args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetCullModeEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetCullModeEXT&                    args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetFrontFaceEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetFrontFaceEXT&                   args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetPrimitiveTopologyEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetPrimitiveTopologyEXT&           args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetViewportWithCountEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetViewportWithCountEXT&           args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetScissorWithCountEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetScissorWithCountEXT&            args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBindVertexBuffers2EXT(
    const ApiCallInfo&                          call_info,
    args::CmdBindVertexBuffers2EXT&             args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetDepthTestEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthTestEnableEXT&             args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetDepthWriteEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthWriteEnableEXT&            args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetDepthCompareOpEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthCompareOpEXT&              args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetDepthBoundsTestEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthBoundsTestEnableEXT&       args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetStencilTestEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetStencilTestEnableEXT&           args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetStencilOpEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetStencilOpEXT&                   args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdPreprocessGeneratedCommandsNV(
    const ApiCallInfo&                          call_info,
    args::CmdPreprocessGeneratedCommandsNV&     args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdExecuteGeneratedCommandsNV(
    const ApiCallInfo&                          call_info,
    args::CmdExecuteGeneratedCommandsNV&        args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBindPipelineShaderGroupNV(
    const ApiCallInfo&                          call_info,
    args::CmdBindPipelineShaderGroupNV&         args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetDepthBias2EXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthBias2EXT&                  args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDispatchTileQCOM(
    const ApiCallInfo&                          call_info,
    args::CmdDispatchTileQCOM&                  args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBeginPerTileExecutionQCOM(
    const ApiCallInfo&                          call_info,
    args::CmdBeginPerTileExecutionQCOM&         args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdEndPerTileExecutionQCOM(
    const ApiCallInfo&                          call_info,
    args::CmdEndPerTileExecutionQCOM&           args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBindDescriptorBuffersEXT(
    const ApiCallInfo&                          call_info,
    args::CmdBindDescriptorBuffersEXT&          args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetDescriptorBufferOffsetsEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDescriptorBufferOffsetsEXT&     args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBindDescriptorBufferEmbeddedSamplersEXT(
    const ApiCallInfo&                          call_info,
    args::CmdBindDescriptorBufferEmbeddedSamplersEXT& args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetFragmentShadingRateEnumNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetFragmentShadingRateEnumNV&      args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetVertexInputEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetVertexInputEXT&                 args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBindInvocationMaskHUAWEI(
    const ApiCallInfo&                          call_info,
    args::CmdBindInvocationMaskHUAWEI&          args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetPatchControlPointsEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetPatchControlPointsEXT&          args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetRasterizerDiscardEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetRasterizerDiscardEnableEXT&     args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetDepthBiasEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthBiasEnableEXT&             args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetLogicOpEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetLogicOpEXT&                     args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetPrimitiveRestartEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetPrimitiveRestartEnableEXT&      args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetColorWriteEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetColorWriteEnableEXT&            args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDrawMultiEXT(
    const ApiCallInfo&                          call_info,
    args::CmdDrawMultiEXT&                      args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDrawMultiIndexedEXT(
    const ApiCallInfo&                          call_info,
    args::CmdDrawMultiIndexedEXT&               args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBuildMicromapsEXT(
    const ApiCallInfo&                          call_info,
    args::CmdBuildMicromapsEXT&                 args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdCopyMicromapEXT(
    const ApiCallInfo&                          call_info,
    args::CmdCopyMicromapEXT&                   args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdCopyMicromapToMemoryEXT(
    const ApiCallInfo&                          call_info,
    args::CmdCopyMicromapToMemoryEXT&           args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdCopyMemoryToMicromapEXT(
    const ApiCallInfo&                          call_info,
    args::CmdCopyMemoryToMicromapEXT&           args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdWriteMicromapsPropertiesEXT(
    const ApiCallInfo&                          call_info,
    args::CmdWriteMicromapsPropertiesEXT&       args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDrawClusterHUAWEI(
    const ApiCallInfo&                          call_info,
    args::CmdDrawClusterHUAWEI&                 args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDrawClusterIndirectHUAWEI(
    const ApiCallInfo&                          call_info,
    args::CmdDrawClusterIndirectHUAWEI&         args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetDispatchParametersARM(
    const ApiCallInfo&                          call_info,
    args::CmdSetDispatchParametersARM&          args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdUpdatePipelineIndirectBufferNV(
    const ApiCallInfo&                          call_info,
    args::CmdUpdatePipelineIndirectBufferNV&    args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetDepthClampEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthClampEnableEXT&            args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetPolygonModeEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetPolygonModeEXT&                 args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetRasterizationSamplesEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetRasterizationSamplesEXT&        args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetSampleMaskEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetSampleMaskEXT&                  args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetAlphaToCoverageEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetAlphaToCoverageEnableEXT&       args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetAlphaToOneEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetAlphaToOneEnableEXT&            args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetLogicOpEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetLogicOpEnableEXT&               args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetColorBlendEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetColorBlendEnableEXT&            args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetColorBlendEquationEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetColorBlendEquationEXT&          args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetColorWriteMaskEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetColorWriteMaskEXT&              args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetTessellationDomainOriginEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetTessellationDomainOriginEXT&    args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetRasterizationStreamEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetRasterizationStreamEXT&         args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetConservativeRasterizationModeEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetConservativeRasterizationModeEXT& args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetExtraPrimitiveOverestimationSizeEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetExtraPrimitiveOverestimationSizeEXT& args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetDepthClipEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthClipEnableEXT&             args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetSampleLocationsEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetSampleLocationsEnableEXT&       args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetColorBlendAdvancedEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetColorBlendAdvancedEXT&          args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetProvokingVertexModeEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetProvokingVertexModeEXT&         args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetLineRasterizationModeEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetLineRasterizationModeEXT&       args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetLineStippleEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetLineStippleEnableEXT&           args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetDepthClipNegativeOneToOneEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthClipNegativeOneToOneEXT&   args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetViewportWScalingEnableNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetViewportWScalingEnableNV&       args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetViewportSwizzleNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetViewportSwizzleNV&              args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetCoverageToColorEnableNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetCoverageToColorEnableNV&        args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetCoverageToColorLocationNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetCoverageToColorLocationNV&      args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetCoverageModulationModeNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetCoverageModulationModeNV&       args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetCoverageModulationTableEnableNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetCoverageModulationTableEnableNV& args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetCoverageModulationTableNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetCoverageModulationTableNV&      args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetShadingRateImageEnableNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetShadingRateImageEnableNV&       args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetRepresentativeFragmentTestEnableNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetRepresentativeFragmentTestEnableNV& args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetCoverageReductionModeNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetCoverageReductionModeNV&        args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdOpticalFlowExecuteNV(
    const ApiCallInfo&                          call_info,
    args::CmdOpticalFlowExecuteNV&              args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBindShadersEXT(
    const ApiCallInfo&                          call_info,
    args::CmdBindShadersEXT&                    args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetDepthClampRangeEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthClampRangeEXT&             args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdConvertCooperativeVectorMatrixNV(
    const ApiCallInfo&                          call_info,
    args::CmdConvertCooperativeVectorMatrixNV&  args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDispatchDataGraphARM(
    const ApiCallInfo&                          call_info,
    args::CmdDispatchDataGraphARM&              args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetAttachmentFeedbackLoopEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetAttachmentFeedbackLoopEnableEXT& args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBindTileMemoryQCOM(
    const ApiCallInfo&                          call_info,
    args::CmdBindTileMemoryQCOM&                args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDecompressMemoryEXT(
    const ApiCallInfo&                          call_info,
    args::CmdDecompressMemoryEXT&               args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDecompressMemoryIndirectCountEXT(
    const ApiCallInfo&                          call_info,
    args::CmdDecompressMemoryIndirectCountEXT&  args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBuildPartitionedAccelerationStructuresNV(
    const ApiCallInfo&                          call_info,
    args::CmdBuildPartitionedAccelerationStructuresNV& args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdPreprocessGeneratedCommandsEXT(
    const ApiCallInfo&                          call_info,
    args::CmdPreprocessGeneratedCommandsEXT&    args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdExecuteGeneratedCommandsEXT(
    const ApiCallInfo&                          call_info,
    args::CmdExecuteGeneratedCommandsEXT&       args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdEndRendering2EXT(
    const ApiCallInfo&                          call_info,
    args::CmdEndRendering2EXT&                  args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBeginCustomResolveEXT(
    const ApiCallInfo&                          call_info,
    args::CmdBeginCustomResolveEXT&             args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetComputeOccupancyPriorityNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetComputeOccupancyPriorityNV&     args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetPrimitiveRestartIndexEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetPrimitiveRestartIndexEXT&       args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBuildAccelerationStructuresKHR(
    const ApiCallInfo&                          call_info,
    args::CmdBuildAccelerationStructuresKHR&    args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBuildAccelerationStructuresIndirectKHR(
    const ApiCallInfo&                          call_info,
    args::CmdBuildAccelerationStructuresIndirectKHR& args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdCopyAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyAccelerationStructureKHR&      args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdCopyAccelerationStructureToMemoryKHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyAccelerationStructureToMemoryKHR& args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdCopyMemoryToAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyMemoryToAccelerationStructureKHR& args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdWriteAccelerationStructuresPropertiesKHR(
    const ApiCallInfo&                          call_info,
    args::CmdWriteAccelerationStructuresPropertiesKHR& args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdTraceRaysKHR(
    const ApiCallInfo&                          call_info,
    args::CmdTraceRaysKHR&                      args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdTraceRaysIndirectKHR(
    const ApiCallInfo&                          call_info,
    args::CmdTraceRaysIndirectKHR&              args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetRayTracingPipelineStackSizeKHR(
    const ApiCallInfo&                          call_info,
    args::CmdSetRayTracingPipelineStackSizeKHR& args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDrawMeshTasksEXT(
    const ApiCallInfo&                          call_info,
    args::CmdDrawMeshTasksEXT&                  args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDrawMeshTasksIndirectEXT(
    const ApiCallInfo&                          call_info,
    args::CmdDrawMeshTasksIndirectEXT&          args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDrawMeshTasksIndirectCountEXT(
    const ApiCallInfo&                          call_info,
    args::CmdDrawMeshTasksIndirectCountEXT&     args)
{
    if (check_handle_id_unused(args.commandBuffer)){ set_block_index_unused(call_info.index); }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
