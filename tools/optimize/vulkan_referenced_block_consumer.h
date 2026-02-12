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

#ifndef GFXRECON_TOOLS_OPTIMIZE_VULKAN_REFERENCED_BLOCK_CONSUMER_H
#define GFXRECON_TOOLS_OPTIMIZE_VULKAN_REFERENCED_BLOCK_CONSUMER_H

#include "generated/generated_vulkan_consumer.h"
#include <unordered_set>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)

// Although this class lives in the optimize tool project, it is derived from decode::VulkanConsumer so put it in
// the decode namespace.
GFXRECON_BEGIN_NAMESPACE(decode)

/**
 * @brief   VulkanReferencedBlockConsumer can be used to generate a list of unused blocks in a capture-file.
 *          This is done by comparing all referenced handle-ids inside a block
 *          against a provided list of unused handle-ids.
 */
class VulkanReferencedBlockConsumer : public VulkanConsumer
{
  public:
    VulkanReferencedBlockConsumer(std::unordered_set<format::HandleId> unreferenced_ids);

    const std::unordered_set<uint64_t>& GetUnreferencedBlocks() const { return unreferenced_blocks_; }

    void Process_vkCreateGraphicsPipelines(const ApiCallInfo&                                          call_info,
                                           VkResult                                                    returnValue,
                                           format::HandleId                                            device,
                                           format::HandleId                                            pipelineCache,
                                           uint32_t                                                    createInfoCount,
                                           StructPointerDecoder<Decoded_VkGraphicsPipelineCreateInfo>* pCreateInfos,
                                           StructPointerDecoder<Decoded_VkAllocationCallbacks>*        pAllocator,
                                           HandlePointerDecoder<VkPipeline>* pPipelines) override;

    void Process_vkCreateComputePipelines(const ApiCallInfo&                                         call_info,
                                          VkResult                                                   returnValue,
                                          format::HandleId                                           device,
                                          format::HandleId                                           pipelineCache,
                                          uint32_t                                                   createInfoCount,
                                          StructPointerDecoder<Decoded_VkComputePipelineCreateInfo>* pCreateInfos,
                                          StructPointerDecoder<Decoded_VkAllocationCallbacks>*       pAllocator,
                                          HandlePointerDecoder<VkPipeline>* pPipelines) override;

    void Process_vkCreateRayTracingPipelinesKHR(
        const ApiCallInfo&                                               call_info,
        VkResult                                                         returnValue,
        format::HandleId                                                 device,
        format::HandleId                                                 deferredOperation,
        format::HandleId                                                 pipelineCache,
        uint32_t                                                         createInfoCount,
        StructPointerDecoder<Decoded_VkRayTracingPipelineCreateInfoKHR>* pCreateInfos,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>*             pAllocator,
        HandlePointerDecoder<VkPipeline>*                                pPipelines) override;

  private:
    void process_handle_ids(const format::HandleId* handle_ids, uint32_t num_handle_ids, uint64_t block_index);

    std::unordered_set<format::HandleId> unreferenced_ids_;
    std::unordered_set<uint64_t>         unreferenced_blocks_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_TOOLS_OPTIMIZE_VULKAN_REFERENCED_BLOCK_CONSUMER_H
