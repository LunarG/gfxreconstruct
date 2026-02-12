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

#include "vulkan_referenced_block_consumer.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

VulkanReferencedBlockConsumer::VulkanReferencedBlockConsumer(std::unordered_set<format::HandleId> unreferenced_ids) :
    unreferenced_ids_(std::move(unreferenced_ids))
{}

void VulkanReferencedBlockConsumer::process_handle_ids(const format::HandleId* handle_ids,
                                                       uint32_t                num_handle_ids,
                                                       uint64_t                block_index)
{
    // skip this block if all VkPipelines created here are unused
    if (std::all_of(handle_ids, handle_ids + num_handle_ids, [this](const format::HandleId handle_id) {
            return unreferenced_ids_.contains(handle_id);
        }))
    {
        unreferenced_blocks_.insert(block_index);
    }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBindPipeline(const ApiCallInfo&  call_info,
                                                              format::HandleId    commandBuffer,
                                                              VkPipelineBindPoint pipelineBindPoint,
                                                              format::HandleId    pipeline)
{
    // tmp
    if (pipelineBindPoint != VK_PIPELINE_BIND_POINT_RAY_TRACING_KHR)
    {
        return;
    }
    process_handle_id(commandBuffer, call_info.index);
    process_handle_id(pipeline, call_info.index);
}

void VulkanReferencedBlockConsumer::Process_vkCreateGraphicsPipelines(
    const ApiCallInfo&                                          call_info,
    VkResult                                                    returnValue,
    format::HandleId                                            device,
    format::HandleId                                            pipelineCache,
    uint32_t                                                    createInfoCount,
    StructPointerDecoder<Decoded_VkGraphicsPipelineCreateInfo>* pCreateInfos,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*        pAllocator,
    HandlePointerDecoder<VkPipeline>*                           pPipelines)
{
    // process_handle_ids(pPipelines->GetPointer(), createInfoCount, call_info.index);
}

void VulkanReferencedBlockConsumer::Process_vkCreateComputePipelines(
    const ApiCallInfo&                                         call_info,
    VkResult                                                   returnValue,
    format::HandleId                                           device,
    format::HandleId                                           pipelineCache,
    uint32_t                                                   createInfoCount,
    StructPointerDecoder<Decoded_VkComputePipelineCreateInfo>* pCreateInfos,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*       pAllocator,
    HandlePointerDecoder<VkPipeline>*                          pPipelines)
{
    // process_handle_ids(pPipelines->GetPointer(), createInfoCount, call_info.index);
}

void VulkanReferencedBlockConsumer::Process_vkCreateRayTracingPipelinesKHR(
    const ApiCallInfo&                                               call_info,
    VkResult                                                         returnValue,
    format::HandleId                                                 device,
    format::HandleId                                                 deferredOperation,
    format::HandleId                                                 pipelineCache,
    uint32_t                                                         createInfoCount,
    StructPointerDecoder<Decoded_VkRayTracingPipelineCreateInfoKHR>* pCreateInfos,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*             pAllocator,
    HandlePointerDecoder<VkPipeline>*                                pPipelines)
{
    process_handle_ids(pPipelines->GetPointer(), createInfoCount, call_info.index);
}

void VulkanReferencedBlockConsumer::Process_vkGetRayTracingShaderGroupHandlesKHR(const ApiCallInfo&       call_info,
                                                                                 VkResult                 returnValue,
                                                                                 format::HandleId         device,
                                                                                 format::HandleId         pipeline,
                                                                                 uint32_t                 firstGroup,
                                                                                 uint32_t                 groupCount,
                                                                                 size_t                   dataSize,
                                                                                 PointerDecoder<uint8_t>* pData)
{
    process_handle_id(pipeline, call_info.index);
}

void VulkanReferencedBlockConsumer::Process_vkCmdTraceRaysKHR(
    const ApiCallInfo&                                             call_info,
    format::HandleId                                               commandBuffer,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pRaygenShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pMissShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pHitShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pCallableShaderBindingTable,
    uint32_t                                                       width,
    uint32_t                                                       height,
    uint32_t                                                       depth)
{
    process_handle_id(commandBuffer, call_info.index);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)