/*
** Copyright (c) 2018 LunarG, Inc.
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

/*
** This file is generated from the Khronos Vulkan XML API Registry.
**
*/


    virtual void Process_vkCreateInstance(
        VkResult                                    returnValue,
        const StructPointerDecoder<Decoded_VkInstanceCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<HandleId>&             pInstance) override;

    virtual void Process_vkDestroyInstance(
        HandleId                                    instance,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) override;

    virtual void Process_vkEnumeratePhysicalDevices(
        VkResult                                    returnValue,
        HandleId                                    instance,
        const PointerDecoder<uint32_t>&             pPhysicalDeviceCount,
        const PointerDecoder<HandleId>&             pPhysicalDevices) override;

    virtual void Process_vkGetPhysicalDeviceFeatures(
        HandleId                                    physicalDevice,
        const StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures>& pFeatures) override;

    virtual void Process_vkGetPhysicalDeviceFormatProperties(
        HandleId                                    physicalDevice,
        VkFormat                                    format,
        const StructPointerDecoder<Decoded_VkFormatProperties>& pFormatProperties) override;

    virtual void Process_vkGetPhysicalDeviceImageFormatProperties(
        VkResult                                    returnValue,
        HandleId                                    physicalDevice,
        VkFormat                                    format,
        VkImageType                                 type,
        VkImageTiling                               tiling,
        VkImageUsageFlags                           usage,
        VkImageCreateFlags                          flags,
        const StructPointerDecoder<Decoded_VkImageFormatProperties>& pImageFormatProperties) override;

    virtual void Process_vkGetPhysicalDeviceProperties(
        HandleId                                    physicalDevice,
        const StructPointerDecoder<Decoded_VkPhysicalDeviceProperties>& pProperties) override;

    virtual void Process_vkGetPhysicalDeviceQueueFamilyProperties(
        HandleId                                    physicalDevice,
        const PointerDecoder<uint32_t>&             pQueueFamilyPropertyCount,
        const StructPointerDecoder<Decoded_VkQueueFamilyProperties>& pQueueFamilyProperties) override;

    virtual void Process_vkGetPhysicalDeviceMemoryProperties(
        HandleId                                    physicalDevice,
        const StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties>& pMemoryProperties) override;

    virtual void Process_vkCreateDevice(
        VkResult                                    returnValue,
        HandleId                                    physicalDevice,
        const StructPointerDecoder<Decoded_VkDeviceCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<HandleId>&             pDevice) override;

    virtual void Process_vkDestroyDevice(
        HandleId                                    device,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) override;

    virtual void Process_vkGetDeviceQueue(
        HandleId                                    device,
        uint32_t                                    queueFamilyIndex,
        uint32_t                                    queueIndex,
        const PointerDecoder<HandleId>&             pQueue) override;

    virtual void Process_vkQueueSubmit(
        VkResult                                    returnValue,
        HandleId                                    queue,
        uint32_t                                    submitCount,
        const StructPointerDecoder<Decoded_VkSubmitInfo>& pSubmits,
        HandleId                                    fence) override;

    virtual void Process_vkQueueWaitIdle(
        VkResult                                    returnValue,
        HandleId                                    queue) override;

    virtual void Process_vkDeviceWaitIdle(
        VkResult                                    returnValue,
        HandleId                                    device) override;

    virtual void Process_vkAllocateMemory(
        VkResult                                    returnValue,
        HandleId                                    device,
        const StructPointerDecoder<Decoded_VkMemoryAllocateInfo>& pAllocateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<HandleId>&             pMemory) override;

    virtual void Process_vkFreeMemory(
        HandleId                                    device,
        HandleId                                    memory,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) override;

    virtual void Process_vkMapMemory(
        VkResult                                    returnValue,
        HandleId                                    device,
        HandleId                                    memory,
        VkDeviceSize                                offset,
        VkDeviceSize                                size,
        VkMemoryMapFlags                            flags,
        const PointerDecoder<uint64_t>&             ppData) override;

    virtual void Process_vkUnmapMemory(
        HandleId                                    device,
        HandleId                                    memory) override;

    virtual void Process_vkFlushMappedMemoryRanges(
        VkResult                                    returnValue,
        HandleId                                    device,
        uint32_t                                    memoryRangeCount,
        const StructPointerDecoder<Decoded_VkMappedMemoryRange>& pMemoryRanges) override;

    virtual void Process_vkInvalidateMappedMemoryRanges(
        VkResult                                    returnValue,
        HandleId                                    device,
        uint32_t                                    memoryRangeCount,
        const StructPointerDecoder<Decoded_VkMappedMemoryRange>& pMemoryRanges) override;

    virtual void Process_vkGetDeviceMemoryCommitment(
        HandleId                                    device,
        HandleId                                    memory,
        const PointerDecoder<VkDeviceSize>&         pCommittedMemoryInBytes) override;

    virtual void Process_vkBindBufferMemory(
        VkResult                                    returnValue,
        HandleId                                    device,
        HandleId                                    buffer,
        HandleId                                    memory,
        VkDeviceSize                                memoryOffset) override;

    virtual void Process_vkBindImageMemory(
        VkResult                                    returnValue,
        HandleId                                    device,
        HandleId                                    image,
        HandleId                                    memory,
        VkDeviceSize                                memoryOffset) override;

    virtual void Process_vkGetBufferMemoryRequirements(
        HandleId                                    device,
        HandleId                                    buffer,
        const StructPointerDecoder<Decoded_VkMemoryRequirements>& pMemoryRequirements) override;

    virtual void Process_vkGetImageMemoryRequirements(
        HandleId                                    device,
        HandleId                                    image,
        const StructPointerDecoder<Decoded_VkMemoryRequirements>& pMemoryRequirements) override;

    virtual void Process_vkGetImageSparseMemoryRequirements(
        HandleId                                    device,
        HandleId                                    image,
        const PointerDecoder<uint32_t>&             pSparseMemoryRequirementCount,
        const StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements>& pSparseMemoryRequirements) override;

    virtual void Process_vkGetPhysicalDeviceSparseImageFormatProperties(
        HandleId                                    physicalDevice,
        VkFormat                                    format,
        VkImageType                                 type,
        VkSampleCountFlagBits                       samples,
        VkImageUsageFlags                           usage,
        VkImageTiling                               tiling,
        const PointerDecoder<uint32_t>&             pPropertyCount,
        const StructPointerDecoder<Decoded_VkSparseImageFormatProperties>& pProperties) override;

    virtual void Process_vkQueueBindSparse(
        VkResult                                    returnValue,
        HandleId                                    queue,
        uint32_t                                    bindInfoCount,
        const StructPointerDecoder<Decoded_VkBindSparseInfo>& pBindInfo,
        HandleId                                    fence) override;

    virtual void Process_vkCreateFence(
        VkResult                                    returnValue,
        HandleId                                    device,
        const StructPointerDecoder<Decoded_VkFenceCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<HandleId>&             pFence) override;

    virtual void Process_vkDestroyFence(
        HandleId                                    device,
        HandleId                                    fence,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) override;

    virtual void Process_vkResetFences(
        VkResult                                    returnValue,
        HandleId                                    device,
        uint32_t                                    fenceCount,
        const PointerDecoder<HandleId>&             pFences) override;

    virtual void Process_vkGetFenceStatus(
        VkResult                                    returnValue,
        HandleId                                    device,
        HandleId                                    fence) override;

    virtual void Process_vkWaitForFences(
        VkResult                                    returnValue,
        HandleId                                    device,
        uint32_t                                    fenceCount,
        const PointerDecoder<HandleId>&             pFences,
        VkBool32                                    waitAll,
        uint64_t                                    timeout) override;

    virtual void Process_vkCreateSemaphore(
        VkResult                                    returnValue,
        HandleId                                    device,
        const StructPointerDecoder<Decoded_VkSemaphoreCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<HandleId>&             pSemaphore) override;

    virtual void Process_vkDestroySemaphore(
        HandleId                                    device,
        HandleId                                    semaphore,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) override;

    virtual void Process_vkCreateEvent(
        VkResult                                    returnValue,
        HandleId                                    device,
        const StructPointerDecoder<Decoded_VkEventCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<HandleId>&             pEvent) override;

    virtual void Process_vkDestroyEvent(
        HandleId                                    device,
        HandleId                                    event,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) override;

    virtual void Process_vkGetEventStatus(
        VkResult                                    returnValue,
        HandleId                                    device,
        HandleId                                    event) override;

    virtual void Process_vkSetEvent(
        VkResult                                    returnValue,
        HandleId                                    device,
        HandleId                                    event) override;

    virtual void Process_vkResetEvent(
        VkResult                                    returnValue,
        HandleId                                    device,
        HandleId                                    event) override;

    virtual void Process_vkCreateQueryPool(
        VkResult                                    returnValue,
        HandleId                                    device,
        const StructPointerDecoder<Decoded_VkQueryPoolCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<HandleId>&             pQueryPool) override;

    virtual void Process_vkDestroyQueryPool(
        HandleId                                    device,
        HandleId                                    queryPool,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) override;

    virtual void Process_vkGetQueryPoolResults(
        VkResult                                    returnValue,
        HandleId                                    device,
        HandleId                                    queryPool,
        uint32_t                                    firstQuery,
        uint32_t                                    queryCount,
        size_t                                      dataSize,
        const PointerDecoder<uint8_t>&              pData,
        VkDeviceSize                                stride,
        VkQueryResultFlags                          flags) override;

    virtual void Process_vkCreateBuffer(
        VkResult                                    returnValue,
        HandleId                                    device,
        const StructPointerDecoder<Decoded_VkBufferCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<HandleId>&             pBuffer) override;

    virtual void Process_vkDestroyBuffer(
        HandleId                                    device,
        HandleId                                    buffer,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) override;

    virtual void Process_vkCreateBufferView(
        VkResult                                    returnValue,
        HandleId                                    device,
        const StructPointerDecoder<Decoded_VkBufferViewCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<HandleId>&             pView) override;

    virtual void Process_vkDestroyBufferView(
        HandleId                                    device,
        HandleId                                    bufferView,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) override;

    virtual void Process_vkCreateImage(
        VkResult                                    returnValue,
        HandleId                                    device,
        const StructPointerDecoder<Decoded_VkImageCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<HandleId>&             pImage) override;

    virtual void Process_vkDestroyImage(
        HandleId                                    device,
        HandleId                                    image,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) override;

    virtual void Process_vkGetImageSubresourceLayout(
        HandleId                                    device,
        HandleId                                    image,
        const StructPointerDecoder<Decoded_VkImageSubresource>& pSubresource,
        const StructPointerDecoder<Decoded_VkSubresourceLayout>& pLayout) override;

    virtual void Process_vkCreateImageView(
        VkResult                                    returnValue,
        HandleId                                    device,
        const StructPointerDecoder<Decoded_VkImageViewCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<HandleId>&             pView) override;

    virtual void Process_vkDestroyImageView(
        HandleId                                    device,
        HandleId                                    imageView,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) override;

    virtual void Process_vkCreateShaderModule(
        VkResult                                    returnValue,
        HandleId                                    device,
        const StructPointerDecoder<Decoded_VkShaderModuleCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<HandleId>&             pShaderModule) override;

    virtual void Process_vkDestroyShaderModule(
        HandleId                                    device,
        HandleId                                    shaderModule,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) override;

    virtual void Process_vkCreatePipelineCache(
        VkResult                                    returnValue,
        HandleId                                    device,
        const StructPointerDecoder<Decoded_VkPipelineCacheCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<HandleId>&             pPipelineCache) override;

    virtual void Process_vkDestroyPipelineCache(
        HandleId                                    device,
        HandleId                                    pipelineCache,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) override;

    virtual void Process_vkGetPipelineCacheData(
        VkResult                                    returnValue,
        HandleId                                    device,
        HandleId                                    pipelineCache,
        const PointerDecoder<size_t>&               pDataSize,
        const PointerDecoder<uint8_t>&              pData) override;

    virtual void Process_vkMergePipelineCaches(
        VkResult                                    returnValue,
        HandleId                                    device,
        HandleId                                    dstCache,
        uint32_t                                    srcCacheCount,
        const PointerDecoder<HandleId>&             pSrcCaches) override;

    virtual void Process_vkCreateGraphicsPipelines(
        VkResult                                    returnValue,
        HandleId                                    device,
        HandleId                                    pipelineCache,
        uint32_t                                    createInfoCount,
        const StructPointerDecoder<Decoded_VkGraphicsPipelineCreateInfo>& pCreateInfos,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<HandleId>&             pPipelines) override;

    virtual void Process_vkCreateComputePipelines(
        VkResult                                    returnValue,
        HandleId                                    device,
        HandleId                                    pipelineCache,
        uint32_t                                    createInfoCount,
        const StructPointerDecoder<Decoded_VkComputePipelineCreateInfo>& pCreateInfos,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<HandleId>&             pPipelines) override;

    virtual void Process_vkDestroyPipeline(
        HandleId                                    device,
        HandleId                                    pipeline,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) override;

    virtual void Process_vkCreatePipelineLayout(
        VkResult                                    returnValue,
        HandleId                                    device,
        const StructPointerDecoder<Decoded_VkPipelineLayoutCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<HandleId>&             pPipelineLayout) override;

    virtual void Process_vkDestroyPipelineLayout(
        HandleId                                    device,
        HandleId                                    pipelineLayout,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) override;

    virtual void Process_vkCreateSampler(
        VkResult                                    returnValue,
        HandleId                                    device,
        const StructPointerDecoder<Decoded_VkSamplerCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<HandleId>&             pSampler) override;

    virtual void Process_vkDestroySampler(
        HandleId                                    device,
        HandleId                                    sampler,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) override;

    virtual void Process_vkCreateDescriptorSetLayout(
        VkResult                                    returnValue,
        HandleId                                    device,
        const StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<HandleId>&             pSetLayout) override;

    virtual void Process_vkDestroyDescriptorSetLayout(
        HandleId                                    device,
        HandleId                                    descriptorSetLayout,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) override;

    virtual void Process_vkCreateDescriptorPool(
        VkResult                                    returnValue,
        HandleId                                    device,
        const StructPointerDecoder<Decoded_VkDescriptorPoolCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<HandleId>&             pDescriptorPool) override;

    virtual void Process_vkDestroyDescriptorPool(
        HandleId                                    device,
        HandleId                                    descriptorPool,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) override;

    virtual void Process_vkResetDescriptorPool(
        VkResult                                    returnValue,
        HandleId                                    device,
        HandleId                                    descriptorPool,
        VkDescriptorPoolResetFlags                  flags) override;

    virtual void Process_vkAllocateDescriptorSets(
        VkResult                                    returnValue,
        HandleId                                    device,
        const StructPointerDecoder<Decoded_VkDescriptorSetAllocateInfo>& pAllocateInfo,
        const PointerDecoder<HandleId>&             pDescriptorSets) override;

    virtual void Process_vkFreeDescriptorSets(
        VkResult                                    returnValue,
        HandleId                                    device,
        HandleId                                    descriptorPool,
        uint32_t                                    descriptorSetCount,
        const PointerDecoder<HandleId>&             pDescriptorSets) override;

    virtual void Process_vkUpdateDescriptorSets(
        HandleId                                    device,
        uint32_t                                    descriptorWriteCount,
        const StructPointerDecoder<Decoded_VkWriteDescriptorSet>& pDescriptorWrites,
        uint32_t                                    descriptorCopyCount,
        const StructPointerDecoder<Decoded_VkCopyDescriptorSet>& pDescriptorCopies) override;

    virtual void Process_vkCreateFramebuffer(
        VkResult                                    returnValue,
        HandleId                                    device,
        const StructPointerDecoder<Decoded_VkFramebufferCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<HandleId>&             pFramebuffer) override;

    virtual void Process_vkDestroyFramebuffer(
        HandleId                                    device,
        HandleId                                    framebuffer,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) override;

    virtual void Process_vkCreateRenderPass(
        VkResult                                    returnValue,
        HandleId                                    device,
        const StructPointerDecoder<Decoded_VkRenderPassCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<HandleId>&             pRenderPass) override;

    virtual void Process_vkDestroyRenderPass(
        HandleId                                    device,
        HandleId                                    renderPass,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) override;

    virtual void Process_vkGetRenderAreaGranularity(
        HandleId                                    device,
        HandleId                                    renderPass,
        const StructPointerDecoder<Decoded_VkExtent2D>& pGranularity) override;

    virtual void Process_vkCreateCommandPool(
        VkResult                                    returnValue,
        HandleId                                    device,
        const StructPointerDecoder<Decoded_VkCommandPoolCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<HandleId>&             pCommandPool) override;

    virtual void Process_vkDestroyCommandPool(
        HandleId                                    device,
        HandleId                                    commandPool,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) override;

    virtual void Process_vkResetCommandPool(
        VkResult                                    returnValue,
        HandleId                                    device,
        HandleId                                    commandPool,
        VkCommandPoolResetFlags                     flags) override;

    virtual void Process_vkAllocateCommandBuffers(
        VkResult                                    returnValue,
        HandleId                                    device,
        const StructPointerDecoder<Decoded_VkCommandBufferAllocateInfo>& pAllocateInfo,
        const PointerDecoder<HandleId>&             pCommandBuffers) override;

    virtual void Process_vkFreeCommandBuffers(
        HandleId                                    device,
        HandleId                                    commandPool,
        uint32_t                                    commandBufferCount,
        const PointerDecoder<HandleId>&             pCommandBuffers) override;

    virtual void Process_vkBeginCommandBuffer(
        VkResult                                    returnValue,
        HandleId                                    commandBuffer,
        const StructPointerDecoder<Decoded_VkCommandBufferBeginInfo>& pBeginInfo) override;

    virtual void Process_vkEndCommandBuffer(
        VkResult                                    returnValue,
        HandleId                                    commandBuffer) override;

    virtual void Process_vkResetCommandBuffer(
        VkResult                                    returnValue,
        HandleId                                    commandBuffer,
        VkCommandBufferResetFlags                   flags) override;

    virtual void Process_vkCmdBindPipeline(
        HandleId                                    commandBuffer,
        VkPipelineBindPoint                         pipelineBindPoint,
        HandleId                                    pipeline) override;

    virtual void Process_vkCmdSetViewport(
        HandleId                                    commandBuffer,
        uint32_t                                    firstViewport,
        uint32_t                                    viewportCount,
        const StructPointerDecoder<Decoded_VkViewport>& pViewports) override;

    virtual void Process_vkCmdSetScissor(
        HandleId                                    commandBuffer,
        uint32_t                                    firstScissor,
        uint32_t                                    scissorCount,
        const StructPointerDecoder<Decoded_VkRect2D>& pScissors) override;

    virtual void Process_vkCmdSetLineWidth(
        HandleId                                    commandBuffer,
        float                                       lineWidth) override;

    virtual void Process_vkCmdSetDepthBias(
        HandleId                                    commandBuffer,
        float                                       depthBiasConstantFactor,
        float                                       depthBiasClamp,
        float                                       depthBiasSlopeFactor) override;

    virtual void Process_vkCmdSetBlendConstants(
        HandleId                                    commandBuffer,
        const PointerDecoder<float>&                blendConstants) override;

    virtual void Process_vkCmdSetDepthBounds(
        HandleId                                    commandBuffer,
        float                                       minDepthBounds,
        float                                       maxDepthBounds) override;

    virtual void Process_vkCmdSetStencilCompareMask(
        HandleId                                    commandBuffer,
        VkStencilFaceFlags                          faceMask,
        uint32_t                                    compareMask) override;

    virtual void Process_vkCmdSetStencilWriteMask(
        HandleId                                    commandBuffer,
        VkStencilFaceFlags                          faceMask,
        uint32_t                                    writeMask) override;

    virtual void Process_vkCmdSetStencilReference(
        HandleId                                    commandBuffer,
        VkStencilFaceFlags                          faceMask,
        uint32_t                                    reference) override;

    virtual void Process_vkCmdBindDescriptorSets(
        HandleId                                    commandBuffer,
        VkPipelineBindPoint                         pipelineBindPoint,
        HandleId                                    layout,
        uint32_t                                    firstSet,
        uint32_t                                    descriptorSetCount,
        const PointerDecoder<HandleId>&             pDescriptorSets,
        uint32_t                                    dynamicOffsetCount,
        const PointerDecoder<uint32_t>&             pDynamicOffsets) override;

    virtual void Process_vkCmdBindIndexBuffer(
        HandleId                                    commandBuffer,
        HandleId                                    buffer,
        VkDeviceSize                                offset,
        VkIndexType                                 indexType) override;

    virtual void Process_vkCmdBindVertexBuffers(
        HandleId                                    commandBuffer,
        uint32_t                                    firstBinding,
        uint32_t                                    bindingCount,
        const PointerDecoder<HandleId>&             pBuffers,
        const PointerDecoder<VkDeviceSize>&         pOffsets) override;

    virtual void Process_vkCmdDraw(
        HandleId                                    commandBuffer,
        uint32_t                                    vertexCount,
        uint32_t                                    instanceCount,
        uint32_t                                    firstVertex,
        uint32_t                                    firstInstance) override;

    virtual void Process_vkCmdDrawIndexed(
        HandleId                                    commandBuffer,
        uint32_t                                    indexCount,
        uint32_t                                    instanceCount,
        uint32_t                                    firstIndex,
        int32_t                                     vertexOffset,
        uint32_t                                    firstInstance) override;

    virtual void Process_vkCmdDrawIndirect(
        HandleId                                    commandBuffer,
        HandleId                                    buffer,
        VkDeviceSize                                offset,
        uint32_t                                    drawCount,
        uint32_t                                    stride) override;

    virtual void Process_vkCmdDrawIndexedIndirect(
        HandleId                                    commandBuffer,
        HandleId                                    buffer,
        VkDeviceSize                                offset,
        uint32_t                                    drawCount,
        uint32_t                                    stride) override;

    virtual void Process_vkCmdDispatch(
        HandleId                                    commandBuffer,
        uint32_t                                    groupCountX,
        uint32_t                                    groupCountY,
        uint32_t                                    groupCountZ) override;

    virtual void Process_vkCmdDispatchIndirect(
        HandleId                                    commandBuffer,
        HandleId                                    buffer,
        VkDeviceSize                                offset) override;

    virtual void Process_vkCmdCopyBuffer(
        HandleId                                    commandBuffer,
        HandleId                                    srcBuffer,
        HandleId                                    dstBuffer,
        uint32_t                                    regionCount,
        const StructPointerDecoder<Decoded_VkBufferCopy>& pRegions) override;

    virtual void Process_vkCmdCopyImage(
        HandleId                                    commandBuffer,
        HandleId                                    srcImage,
        VkImageLayout                               srcImageLayout,
        HandleId                                    dstImage,
        VkImageLayout                               dstImageLayout,
        uint32_t                                    regionCount,
        const StructPointerDecoder<Decoded_VkImageCopy>& pRegions) override;

    virtual void Process_vkCmdBlitImage(
        HandleId                                    commandBuffer,
        HandleId                                    srcImage,
        VkImageLayout                               srcImageLayout,
        HandleId                                    dstImage,
        VkImageLayout                               dstImageLayout,
        uint32_t                                    regionCount,
        const StructPointerDecoder<Decoded_VkImageBlit>& pRegions,
        VkFilter                                    filter) override;

    virtual void Process_vkCmdCopyBufferToImage(
        HandleId                                    commandBuffer,
        HandleId                                    srcBuffer,
        HandleId                                    dstImage,
        VkImageLayout                               dstImageLayout,
        uint32_t                                    regionCount,
        const StructPointerDecoder<Decoded_VkBufferImageCopy>& pRegions) override;

    virtual void Process_vkCmdCopyImageToBuffer(
        HandleId                                    commandBuffer,
        HandleId                                    srcImage,
        VkImageLayout                               srcImageLayout,
        HandleId                                    dstBuffer,
        uint32_t                                    regionCount,
        const StructPointerDecoder<Decoded_VkBufferImageCopy>& pRegions) override;

    virtual void Process_vkCmdUpdateBuffer(
        HandleId                                    commandBuffer,
        HandleId                                    dstBuffer,
        VkDeviceSize                                dstOffset,
        VkDeviceSize                                dataSize,
        const PointerDecoder<uint8_t>&              pData) override;

    virtual void Process_vkCmdFillBuffer(
        HandleId                                    commandBuffer,
        HandleId                                    dstBuffer,
        VkDeviceSize                                dstOffset,
        VkDeviceSize                                size,
        uint32_t                                    data) override;

    virtual void Process_vkCmdClearColorImage(
        HandleId                                    commandBuffer,
        HandleId                                    image,
        VkImageLayout                               imageLayout,
        const StructPointerDecoder<Decoded_VkClearColorValue>& pColor,
        uint32_t                                    rangeCount,
        const StructPointerDecoder<Decoded_VkImageSubresourceRange>& pRanges) override;

    virtual void Process_vkCmdClearDepthStencilImage(
        HandleId                                    commandBuffer,
        HandleId                                    image,
        VkImageLayout                               imageLayout,
        const StructPointerDecoder<Decoded_VkClearDepthStencilValue>& pDepthStencil,
        uint32_t                                    rangeCount,
        const StructPointerDecoder<Decoded_VkImageSubresourceRange>& pRanges) override;

    virtual void Process_vkCmdClearAttachments(
        HandleId                                    commandBuffer,
        uint32_t                                    attachmentCount,
        const StructPointerDecoder<Decoded_VkClearAttachment>& pAttachments,
        uint32_t                                    rectCount,
        const StructPointerDecoder<Decoded_VkClearRect>& pRects) override;

    virtual void Process_vkCmdResolveImage(
        HandleId                                    commandBuffer,
        HandleId                                    srcImage,
        VkImageLayout                               srcImageLayout,
        HandleId                                    dstImage,
        VkImageLayout                               dstImageLayout,
        uint32_t                                    regionCount,
        const StructPointerDecoder<Decoded_VkImageResolve>& pRegions) override;

    virtual void Process_vkCmdSetEvent(
        HandleId                                    commandBuffer,
        HandleId                                    event,
        VkPipelineStageFlags                        stageMask) override;

    virtual void Process_vkCmdResetEvent(
        HandleId                                    commandBuffer,
        HandleId                                    event,
        VkPipelineStageFlags                        stageMask) override;

    virtual void Process_vkCmdWaitEvents(
        HandleId                                    commandBuffer,
        uint32_t                                    eventCount,
        const PointerDecoder<HandleId>&             pEvents,
        VkPipelineStageFlags                        srcStageMask,
        VkPipelineStageFlags                        dstStageMask,
        uint32_t                                    memoryBarrierCount,
        const StructPointerDecoder<Decoded_VkMemoryBarrier>& pMemoryBarriers,
        uint32_t                                    bufferMemoryBarrierCount,
        const StructPointerDecoder<Decoded_VkBufferMemoryBarrier>& pBufferMemoryBarriers,
        uint32_t                                    imageMemoryBarrierCount,
        const StructPointerDecoder<Decoded_VkImageMemoryBarrier>& pImageMemoryBarriers) override;

    virtual void Process_vkCmdPipelineBarrier(
        HandleId                                    commandBuffer,
        VkPipelineStageFlags                        srcStageMask,
        VkPipelineStageFlags                        dstStageMask,
        VkDependencyFlags                           dependencyFlags,
        uint32_t                                    memoryBarrierCount,
        const StructPointerDecoder<Decoded_VkMemoryBarrier>& pMemoryBarriers,
        uint32_t                                    bufferMemoryBarrierCount,
        const StructPointerDecoder<Decoded_VkBufferMemoryBarrier>& pBufferMemoryBarriers,
        uint32_t                                    imageMemoryBarrierCount,
        const StructPointerDecoder<Decoded_VkImageMemoryBarrier>& pImageMemoryBarriers) override;

    virtual void Process_vkCmdBeginQuery(
        HandleId                                    commandBuffer,
        HandleId                                    queryPool,
        uint32_t                                    query,
        VkQueryControlFlags                         flags) override;

    virtual void Process_vkCmdEndQuery(
        HandleId                                    commandBuffer,
        HandleId                                    queryPool,
        uint32_t                                    query) override;

    virtual void Process_vkCmdResetQueryPool(
        HandleId                                    commandBuffer,
        HandleId                                    queryPool,
        uint32_t                                    firstQuery,
        uint32_t                                    queryCount) override;

    virtual void Process_vkCmdWriteTimestamp(
        HandleId                                    commandBuffer,
        VkPipelineStageFlagBits                     pipelineStage,
        HandleId                                    queryPool,
        uint32_t                                    query) override;

    virtual void Process_vkCmdCopyQueryPoolResults(
        HandleId                                    commandBuffer,
        HandleId                                    queryPool,
        uint32_t                                    firstQuery,
        uint32_t                                    queryCount,
        HandleId                                    dstBuffer,
        VkDeviceSize                                dstOffset,
        VkDeviceSize                                stride,
        VkQueryResultFlags                          flags) override;

    virtual void Process_vkCmdPushConstants(
        HandleId                                    commandBuffer,
        HandleId                                    layout,
        VkShaderStageFlags                          stageFlags,
        uint32_t                                    offset,
        uint32_t                                    size,
        const PointerDecoder<uint8_t>&              pValues) override;

    virtual void Process_vkCmdBeginRenderPass(
        HandleId                                    commandBuffer,
        const StructPointerDecoder<Decoded_VkRenderPassBeginInfo>& pRenderPassBegin,
        VkSubpassContents                           contents) override;

    virtual void Process_vkCmdNextSubpass(
        HandleId                                    commandBuffer,
        VkSubpassContents                           contents) override;

    virtual void Process_vkCmdEndRenderPass(
        HandleId                                    commandBuffer) override;

    virtual void Process_vkCmdExecuteCommands(
        HandleId                                    commandBuffer,
        uint32_t                                    commandBufferCount,
        const PointerDecoder<HandleId>&             pCommandBuffers) override;

    virtual void Process_vkBindBufferMemory2(
        VkResult                                    returnValue,
        HandleId                                    device,
        uint32_t                                    bindInfoCount,
        const StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>& pBindInfos) override;

    virtual void Process_vkBindImageMemory2(
        VkResult                                    returnValue,
        HandleId                                    device,
        uint32_t                                    bindInfoCount,
        const StructPointerDecoder<Decoded_VkBindImageMemoryInfo>& pBindInfos) override;

    virtual void Process_vkGetDeviceGroupPeerMemoryFeatures(
        HandleId                                    device,
        uint32_t                                    heapIndex,
        uint32_t                                    localDeviceIndex,
        uint32_t                                    remoteDeviceIndex,
        const PointerDecoder<VkPeerMemoryFeatureFlags>& pPeerMemoryFeatures) override;

    virtual void Process_vkCmdSetDeviceMask(
        HandleId                                    commandBuffer,
        uint32_t                                    deviceMask) override;

    virtual void Process_vkCmdDispatchBase(
        HandleId                                    commandBuffer,
        uint32_t                                    baseGroupX,
        uint32_t                                    baseGroupY,
        uint32_t                                    baseGroupZ,
        uint32_t                                    groupCountX,
        uint32_t                                    groupCountY,
        uint32_t                                    groupCountZ) override;

    virtual void Process_vkEnumeratePhysicalDeviceGroups(
        VkResult                                    returnValue,
        HandleId                                    instance,
        const PointerDecoder<uint32_t>&             pPhysicalDeviceGroupCount,
        const StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties>& pPhysicalDeviceGroupProperties) override;

    virtual void Process_vkGetImageMemoryRequirements2(
        HandleId                                    device,
        const StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2>& pInfo,
        const StructPointerDecoder<Decoded_VkMemoryRequirements2>& pMemoryRequirements) override;

    virtual void Process_vkGetBufferMemoryRequirements2(
        HandleId                                    device,
        const StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2>& pInfo,
        const StructPointerDecoder<Decoded_VkMemoryRequirements2>& pMemoryRequirements) override;

    virtual void Process_vkGetImageSparseMemoryRequirements2(
        HandleId                                    device,
        const StructPointerDecoder<Decoded_VkImageSparseMemoryRequirementsInfo2>& pInfo,
        const PointerDecoder<uint32_t>&             pSparseMemoryRequirementCount,
        const StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>& pSparseMemoryRequirements) override;

    virtual void Process_vkGetPhysicalDeviceFeatures2(
        HandleId                                    physicalDevice,
        const StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2>& pFeatures) override;

    virtual void Process_vkGetPhysicalDeviceProperties2(
        HandleId                                    physicalDevice,
        const StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>& pProperties) override;

    virtual void Process_vkGetPhysicalDeviceFormatProperties2(
        HandleId                                    physicalDevice,
        VkFormat                                    format,
        const StructPointerDecoder<Decoded_VkFormatProperties2>& pFormatProperties) override;

    virtual void Process_vkGetPhysicalDeviceImageFormatProperties2(
        VkResult                                    returnValue,
        HandleId                                    physicalDevice,
        const StructPointerDecoder<Decoded_VkPhysicalDeviceImageFormatInfo2>& pImageFormatInfo,
        const StructPointerDecoder<Decoded_VkImageFormatProperties2>& pImageFormatProperties) override;

    virtual void Process_vkGetPhysicalDeviceQueueFamilyProperties2(
        HandleId                                    physicalDevice,
        const PointerDecoder<uint32_t>&             pQueueFamilyPropertyCount,
        const StructPointerDecoder<Decoded_VkQueueFamilyProperties2>& pQueueFamilyProperties) override;

    virtual void Process_vkGetPhysicalDeviceMemoryProperties2(
        HandleId                                    physicalDevice,
        const StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2>& pMemoryProperties) override;

    virtual void Process_vkGetPhysicalDeviceSparseImageFormatProperties2(
        HandleId                                    physicalDevice,
        const StructPointerDecoder<Decoded_VkPhysicalDeviceSparseImageFormatInfo2>& pFormatInfo,
        const PointerDecoder<uint32_t>&             pPropertyCount,
        const StructPointerDecoder<Decoded_VkSparseImageFormatProperties2>& pProperties) override;

    virtual void Process_vkTrimCommandPool(
        HandleId                                    device,
        HandleId                                    commandPool,
        VkCommandPoolTrimFlags                      flags) override;

    virtual void Process_vkGetDeviceQueue2(
        HandleId                                    device,
        const StructPointerDecoder<Decoded_VkDeviceQueueInfo2>& pQueueInfo,
        const PointerDecoder<HandleId>&             pQueue) override;

    virtual void Process_vkCreateSamplerYcbcrConversion(
        VkResult                                    returnValue,
        HandleId                                    device,
        const StructPointerDecoder<Decoded_VkSamplerYcbcrConversionCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<HandleId>&             pYcbcrConversion) override;

    virtual void Process_vkDestroySamplerYcbcrConversion(
        HandleId                                    device,
        HandleId                                    ycbcrConversion,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) override;

    virtual void Process_vkCreateDescriptorUpdateTemplate(
        VkResult                                    returnValue,
        HandleId                                    device,
        const StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<HandleId>&             pDescriptorUpdateTemplate) override;

    virtual void Process_vkDestroyDescriptorUpdateTemplate(
        HandleId                                    device,
        HandleId                                    descriptorUpdateTemplate,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) override;

    virtual void Process_vkUpdateDescriptorSetWithTemplate(
        HandleId                                    device,
        HandleId                                    descriptorSet,
        HandleId                                    descriptorUpdateTemplate,
        uint64_t                                    pData) override;

    virtual void Process_vkGetPhysicalDeviceExternalBufferProperties(
        HandleId                                    physicalDevice,
        const StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo>& pExternalBufferInfo,
        const StructPointerDecoder<Decoded_VkExternalBufferProperties>& pExternalBufferProperties) override;

    virtual void Process_vkGetPhysicalDeviceExternalFenceProperties(
        HandleId                                    physicalDevice,
        const StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo>& pExternalFenceInfo,
        const StructPointerDecoder<Decoded_VkExternalFenceProperties>& pExternalFenceProperties) override;

    virtual void Process_vkGetPhysicalDeviceExternalSemaphoreProperties(
        HandleId                                    physicalDevice,
        const StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo>& pExternalSemaphoreInfo,
        const StructPointerDecoder<Decoded_VkExternalSemaphoreProperties>& pExternalSemaphoreProperties) override;

    virtual void Process_vkGetDescriptorSetLayoutSupport(
        HandleId                                    device,
        const StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport>& pSupport) override;

    virtual void Process_vkDestroySurfaceKHR(
        HandleId                                    instance,
        HandleId                                    surface,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) override;

    virtual void Process_vkGetPhysicalDeviceSurfaceSupportKHR(
        VkResult                                    returnValue,
        HandleId                                    physicalDevice,
        uint32_t                                    queueFamilyIndex,
        HandleId                                    surface,
        const PointerDecoder<VkBool32>&             pSupported) override;

    virtual void Process_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(
        VkResult                                    returnValue,
        HandleId                                    physicalDevice,
        HandleId                                    surface,
        const StructPointerDecoder<Decoded_VkSurfaceCapabilitiesKHR>& pSurfaceCapabilities) override;

    virtual void Process_vkGetPhysicalDeviceSurfaceFormatsKHR(
        VkResult                                    returnValue,
        HandleId                                    physicalDevice,
        HandleId                                    surface,
        const PointerDecoder<uint32_t>&             pSurfaceFormatCount,
        const StructPointerDecoder<Decoded_VkSurfaceFormatKHR>& pSurfaceFormats) override;

    virtual void Process_vkGetPhysicalDeviceSurfacePresentModesKHR(
        VkResult                                    returnValue,
        HandleId                                    physicalDevice,
        HandleId                                    surface,
        const PointerDecoder<uint32_t>&             pPresentModeCount,
        const PointerDecoder<VkPresentModeKHR>&     pPresentModes) override;

    virtual void Process_vkCreateSwapchainKHR(
        VkResult                                    returnValue,
        HandleId                                    device,
        const StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<HandleId>&             pSwapchain) override;

    virtual void Process_vkDestroySwapchainKHR(
        HandleId                                    device,
        HandleId                                    swapchain,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) override;

    virtual void Process_vkGetSwapchainImagesKHR(
        VkResult                                    returnValue,
        HandleId                                    device,
        HandleId                                    swapchain,
        const PointerDecoder<uint32_t>&             pSwapchainImageCount,
        const PointerDecoder<HandleId>&             pSwapchainImages) override;

    virtual void Process_vkAcquireNextImageKHR(
        VkResult                                    returnValue,
        HandleId                                    device,
        HandleId                                    swapchain,
        uint64_t                                    timeout,
        HandleId                                    semaphore,
        HandleId                                    fence,
        const PointerDecoder<uint32_t>&             pImageIndex) override;

    virtual void Process_vkQueuePresentKHR(
        VkResult                                    returnValue,
        HandleId                                    queue,
        const StructPointerDecoder<Decoded_VkPresentInfoKHR>& pPresentInfo) override;

    virtual void Process_vkGetDeviceGroupPresentCapabilitiesKHR(
        VkResult                                    returnValue,
        HandleId                                    device,
        const StructPointerDecoder<Decoded_VkDeviceGroupPresentCapabilitiesKHR>& pDeviceGroupPresentCapabilities) override;

    virtual void Process_vkGetDeviceGroupSurfacePresentModesKHR(
        VkResult                                    returnValue,
        HandleId                                    device,
        HandleId                                    surface,
        const PointerDecoder<VkDeviceGroupPresentModeFlagsKHR>& pModes) override;

    virtual void Process_vkGetPhysicalDevicePresentRectanglesKHR(
        VkResult                                    returnValue,
        HandleId                                    physicalDevice,
        HandleId                                    surface,
        const PointerDecoder<uint32_t>&             pRectCount,
        const StructPointerDecoder<Decoded_VkRect2D>& pRects) override;

    virtual void Process_vkAcquireNextImage2KHR(
        VkResult                                    returnValue,
        HandleId                                    device,
        const StructPointerDecoder<Decoded_VkAcquireNextImageInfoKHR>& pAcquireInfo,
        const PointerDecoder<uint32_t>&             pImageIndex) override;

    virtual void Process_vkGetPhysicalDeviceDisplayPropertiesKHR(
        VkResult                                    returnValue,
        HandleId                                    physicalDevice,
        const PointerDecoder<uint32_t>&             pPropertyCount,
        const StructPointerDecoder<Decoded_VkDisplayPropertiesKHR>& pProperties) override;

    virtual void Process_vkGetPhysicalDeviceDisplayPlanePropertiesKHR(
        VkResult                                    returnValue,
        HandleId                                    physicalDevice,
        const PointerDecoder<uint32_t>&             pPropertyCount,
        const StructPointerDecoder<Decoded_VkDisplayPlanePropertiesKHR>& pProperties) override;

    virtual void Process_vkGetDisplayPlaneSupportedDisplaysKHR(
        VkResult                                    returnValue,
        HandleId                                    physicalDevice,
        uint32_t                                    planeIndex,
        const PointerDecoder<uint32_t>&             pDisplayCount,
        const PointerDecoder<HandleId>&             pDisplays) override;

    virtual void Process_vkGetDisplayModePropertiesKHR(
        VkResult                                    returnValue,
        HandleId                                    physicalDevice,
        HandleId                                    display,
        const PointerDecoder<uint32_t>&             pPropertyCount,
        const StructPointerDecoder<Decoded_VkDisplayModePropertiesKHR>& pProperties) override;

    virtual void Process_vkCreateDisplayModeKHR(
        VkResult                                    returnValue,
        HandleId                                    physicalDevice,
        HandleId                                    display,
        const StructPointerDecoder<Decoded_VkDisplayModeCreateInfoKHR>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<HandleId>&             pMode) override;

    virtual void Process_vkGetDisplayPlaneCapabilitiesKHR(
        VkResult                                    returnValue,
        HandleId                                    physicalDevice,
        HandleId                                    mode,
        uint32_t                                    planeIndex,
        const StructPointerDecoder<Decoded_VkDisplayPlaneCapabilitiesKHR>& pCapabilities) override;

    virtual void Process_vkCreateDisplayPlaneSurfaceKHR(
        VkResult                                    returnValue,
        HandleId                                    instance,
        const StructPointerDecoder<Decoded_VkDisplaySurfaceCreateInfoKHR>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<HandleId>&             pSurface) override;

    virtual void Process_vkCreateSharedSwapchainsKHR(
        VkResult                                    returnValue,
        HandleId                                    device,
        uint32_t                                    swapchainCount,
        const StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>& pCreateInfos,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<HandleId>&             pSwapchains) override;

    virtual void Process_vkCreateXlibSurfaceKHR(
        VkResult                                    returnValue,
        HandleId                                    instance,
        const StructPointerDecoder<Decoded_VkXlibSurfaceCreateInfoKHR>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<HandleId>&             pSurface) override;

    virtual void Process_vkGetPhysicalDeviceXlibPresentationSupportKHR(
        VkBool32                                    returnValue,
        HandleId                                    physicalDevice,
        uint32_t                                    queueFamilyIndex,
        uint64_t                                    dpy,
        uint32_t                                    visualID) override;

    virtual void Process_vkCreateXcbSurfaceKHR(
        VkResult                                    returnValue,
        HandleId                                    instance,
        const StructPointerDecoder<Decoded_VkXcbSurfaceCreateInfoKHR>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<HandleId>&             pSurface) override;

    virtual void Process_vkGetPhysicalDeviceXcbPresentationSupportKHR(
        VkBool32                                    returnValue,
        HandleId                                    physicalDevice,
        uint32_t                                    queueFamilyIndex,
        uint64_t                                    connection,
        uint32_t                                    visual_id) override;

    virtual void Process_vkCreateWaylandSurfaceKHR(
        VkResult                                    returnValue,
        HandleId                                    instance,
        const StructPointerDecoder<Decoded_VkWaylandSurfaceCreateInfoKHR>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<HandleId>&             pSurface) override;

    virtual void Process_vkGetPhysicalDeviceWaylandPresentationSupportKHR(
        VkBool32                                    returnValue,
        HandleId                                    physicalDevice,
        uint32_t                                    queueFamilyIndex,
        uint64_t                                    display) override;

    virtual void Process_vkCreateMirSurfaceKHR(
        VkResult                                    returnValue,
        HandleId                                    instance,
        const StructPointerDecoder<Decoded_VkMirSurfaceCreateInfoKHR>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<HandleId>&             pSurface) override;

    virtual void Process_vkGetPhysicalDeviceMirPresentationSupportKHR(
        VkBool32                                    returnValue,
        HandleId                                    physicalDevice,
        uint32_t                                    queueFamilyIndex,
        uint64_t                                    connection) override;

    virtual void Process_vkCreateAndroidSurfaceKHR(
        VkResult                                    returnValue,
        HandleId                                    instance,
        const StructPointerDecoder<Decoded_VkAndroidSurfaceCreateInfoKHR>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<HandleId>&             pSurface) override;

    virtual void Process_vkCreateWin32SurfaceKHR(
        VkResult                                    returnValue,
        HandleId                                    instance,
        const StructPointerDecoder<Decoded_VkWin32SurfaceCreateInfoKHR>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<HandleId>&             pSurface) override;

    virtual void Process_vkGetPhysicalDeviceWin32PresentationSupportKHR(
        VkBool32                                    returnValue,
        HandleId                                    physicalDevice,
        uint32_t                                    queueFamilyIndex) override;

    virtual void Process_vkGetPhysicalDeviceFeatures2KHR(
        HandleId                                    physicalDevice,
        const StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2>& pFeatures) override;

    virtual void Process_vkGetPhysicalDeviceProperties2KHR(
        HandleId                                    physicalDevice,
        const StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>& pProperties) override;

    virtual void Process_vkGetPhysicalDeviceFormatProperties2KHR(
        HandleId                                    physicalDevice,
        VkFormat                                    format,
        const StructPointerDecoder<Decoded_VkFormatProperties2>& pFormatProperties) override;

    virtual void Process_vkGetPhysicalDeviceImageFormatProperties2KHR(
        VkResult                                    returnValue,
        HandleId                                    physicalDevice,
        const StructPointerDecoder<Decoded_VkPhysicalDeviceImageFormatInfo2>& pImageFormatInfo,
        const StructPointerDecoder<Decoded_VkImageFormatProperties2>& pImageFormatProperties) override;

    virtual void Process_vkGetPhysicalDeviceQueueFamilyProperties2KHR(
        HandleId                                    physicalDevice,
        const PointerDecoder<uint32_t>&             pQueueFamilyPropertyCount,
        const StructPointerDecoder<Decoded_VkQueueFamilyProperties2>& pQueueFamilyProperties) override;

    virtual void Process_vkGetPhysicalDeviceMemoryProperties2KHR(
        HandleId                                    physicalDevice,
        const StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2>& pMemoryProperties) override;

    virtual void Process_vkGetPhysicalDeviceSparseImageFormatProperties2KHR(
        HandleId                                    physicalDevice,
        const StructPointerDecoder<Decoded_VkPhysicalDeviceSparseImageFormatInfo2>& pFormatInfo,
        const PointerDecoder<uint32_t>&             pPropertyCount,
        const StructPointerDecoder<Decoded_VkSparseImageFormatProperties2>& pProperties) override;

    virtual void Process_vkGetDeviceGroupPeerMemoryFeaturesKHR(
        HandleId                                    device,
        uint32_t                                    heapIndex,
        uint32_t                                    localDeviceIndex,
        uint32_t                                    remoteDeviceIndex,
        const PointerDecoder<VkPeerMemoryFeatureFlags>& pPeerMemoryFeatures) override;

    virtual void Process_vkCmdSetDeviceMaskKHR(
        HandleId                                    commandBuffer,
        uint32_t                                    deviceMask) override;

    virtual void Process_vkCmdDispatchBaseKHR(
        HandleId                                    commandBuffer,
        uint32_t                                    baseGroupX,
        uint32_t                                    baseGroupY,
        uint32_t                                    baseGroupZ,
        uint32_t                                    groupCountX,
        uint32_t                                    groupCountY,
        uint32_t                                    groupCountZ) override;

    virtual void Process_vkTrimCommandPoolKHR(
        HandleId                                    device,
        HandleId                                    commandPool,
        VkCommandPoolTrimFlags                      flags) override;

    virtual void Process_vkEnumeratePhysicalDeviceGroupsKHR(
        VkResult                                    returnValue,
        HandleId                                    instance,
        const PointerDecoder<uint32_t>&             pPhysicalDeviceGroupCount,
        const StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties>& pPhysicalDeviceGroupProperties) override;

    virtual void Process_vkGetPhysicalDeviceExternalBufferPropertiesKHR(
        HandleId                                    physicalDevice,
        const StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo>& pExternalBufferInfo,
        const StructPointerDecoder<Decoded_VkExternalBufferProperties>& pExternalBufferProperties) override;

    virtual void Process_vkGetMemoryWin32HandleKHR(
        VkResult                                    returnValue,
        HandleId                                    device,
        const StructPointerDecoder<Decoded_VkMemoryGetWin32HandleInfoKHR>& pGetWin32HandleInfo,
        const PointerDecoder<uint64_t>&             pHandle) override;

    virtual void Process_vkGetMemoryWin32HandlePropertiesKHR(
        VkResult                                    returnValue,
        HandleId                                    device,
        VkExternalMemoryHandleTypeFlagBits          handleType,
        uint64_t                                    handle,
        const StructPointerDecoder<Decoded_VkMemoryWin32HandlePropertiesKHR>& pMemoryWin32HandleProperties) override;

    virtual void Process_vkGetMemoryFdKHR(
        VkResult                                    returnValue,
        HandleId                                    device,
        const StructPointerDecoder<Decoded_VkMemoryGetFdInfoKHR>& pGetFdInfo,
        const PointerDecoder<int>&                  pFd) override;

    virtual void Process_vkGetMemoryFdPropertiesKHR(
        VkResult                                    returnValue,
        HandleId                                    device,
        VkExternalMemoryHandleTypeFlagBits          handleType,
        int                                         fd,
        const StructPointerDecoder<Decoded_VkMemoryFdPropertiesKHR>& pMemoryFdProperties) override;

    virtual void Process_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(
        HandleId                                    physicalDevice,
        const StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo>& pExternalSemaphoreInfo,
        const StructPointerDecoder<Decoded_VkExternalSemaphoreProperties>& pExternalSemaphoreProperties) override;

    virtual void Process_vkImportSemaphoreWin32HandleKHR(
        VkResult                                    returnValue,
        HandleId                                    device,
        const StructPointerDecoder<Decoded_VkImportSemaphoreWin32HandleInfoKHR>& pImportSemaphoreWin32HandleInfo) override;

    virtual void Process_vkGetSemaphoreWin32HandleKHR(
        VkResult                                    returnValue,
        HandleId                                    device,
        const StructPointerDecoder<Decoded_VkSemaphoreGetWin32HandleInfoKHR>& pGetWin32HandleInfo,
        const PointerDecoder<uint64_t>&             pHandle) override;

    virtual void Process_vkImportSemaphoreFdKHR(
        VkResult                                    returnValue,
        HandleId                                    device,
        const StructPointerDecoder<Decoded_VkImportSemaphoreFdInfoKHR>& pImportSemaphoreFdInfo) override;

    virtual void Process_vkGetSemaphoreFdKHR(
        VkResult                                    returnValue,
        HandleId                                    device,
        const StructPointerDecoder<Decoded_VkSemaphoreGetFdInfoKHR>& pGetFdInfo,
        const PointerDecoder<int>&                  pFd) override;

    virtual void Process_vkCmdPushDescriptorSetKHR(
        HandleId                                    commandBuffer,
        VkPipelineBindPoint                         pipelineBindPoint,
        HandleId                                    layout,
        uint32_t                                    set,
        uint32_t                                    descriptorWriteCount,
        const StructPointerDecoder<Decoded_VkWriteDescriptorSet>& pDescriptorWrites) override;

    virtual void Process_vkCmdPushDescriptorSetWithTemplateKHR(
        HandleId                                    commandBuffer,
        HandleId                                    descriptorUpdateTemplate,
        HandleId                                    layout,
        uint32_t                                    set,
        uint64_t                                    pData) override;

    virtual void Process_vkCreateDescriptorUpdateTemplateKHR(
        VkResult                                    returnValue,
        HandleId                                    device,
        const StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<HandleId>&             pDescriptorUpdateTemplate) override;

    virtual void Process_vkDestroyDescriptorUpdateTemplateKHR(
        HandleId                                    device,
        HandleId                                    descriptorUpdateTemplate,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) override;

    virtual void Process_vkUpdateDescriptorSetWithTemplateKHR(
        HandleId                                    device,
        HandleId                                    descriptorSet,
        HandleId                                    descriptorUpdateTemplate,
        uint64_t                                    pData) override;

    virtual void Process_vkCreateRenderPass2KHR(
        VkResult                                    returnValue,
        HandleId                                    device,
        const StructPointerDecoder<Decoded_VkRenderPassCreateInfo2KHR>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<HandleId>&             pRenderPass) override;

    virtual void Process_vkCmdBeginRenderPass2KHR(
        HandleId                                    commandBuffer,
        const StructPointerDecoder<Decoded_VkRenderPassBeginInfo>& pRenderPassBegin,
        const StructPointerDecoder<Decoded_VkSubpassBeginInfoKHR>& pSubpassBeginInfo) override;

    virtual void Process_vkCmdNextSubpass2KHR(
        HandleId                                    commandBuffer,
        const StructPointerDecoder<Decoded_VkSubpassBeginInfoKHR>& pSubpassBeginInfo,
        const StructPointerDecoder<Decoded_VkSubpassEndInfoKHR>& pSubpassEndInfo) override;

    virtual void Process_vkCmdEndRenderPass2KHR(
        HandleId                                    commandBuffer,
        const StructPointerDecoder<Decoded_VkSubpassEndInfoKHR>& pSubpassEndInfo) override;

    virtual void Process_vkGetSwapchainStatusKHR(
        VkResult                                    returnValue,
        HandleId                                    device,
        HandleId                                    swapchain) override;

    virtual void Process_vkGetPhysicalDeviceExternalFencePropertiesKHR(
        HandleId                                    physicalDevice,
        const StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo>& pExternalFenceInfo,
        const StructPointerDecoder<Decoded_VkExternalFenceProperties>& pExternalFenceProperties) override;

    virtual void Process_vkImportFenceWin32HandleKHR(
        VkResult                                    returnValue,
        HandleId                                    device,
        const StructPointerDecoder<Decoded_VkImportFenceWin32HandleInfoKHR>& pImportFenceWin32HandleInfo) override;

    virtual void Process_vkGetFenceWin32HandleKHR(
        VkResult                                    returnValue,
        HandleId                                    device,
        const StructPointerDecoder<Decoded_VkFenceGetWin32HandleInfoKHR>& pGetWin32HandleInfo,
        const PointerDecoder<uint64_t>&             pHandle) override;

    virtual void Process_vkImportFenceFdKHR(
        VkResult                                    returnValue,
        HandleId                                    device,
        const StructPointerDecoder<Decoded_VkImportFenceFdInfoKHR>& pImportFenceFdInfo) override;

    virtual void Process_vkGetFenceFdKHR(
        VkResult                                    returnValue,
        HandleId                                    device,
        const StructPointerDecoder<Decoded_VkFenceGetFdInfoKHR>& pGetFdInfo,
        const PointerDecoder<int>&                  pFd) override;

    virtual void Process_vkGetPhysicalDeviceSurfaceCapabilities2KHR(
        VkResult                                    returnValue,
        HandleId                                    physicalDevice,
        const StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>& pSurfaceInfo,
        const StructPointerDecoder<Decoded_VkSurfaceCapabilities2KHR>& pSurfaceCapabilities) override;

    virtual void Process_vkGetPhysicalDeviceSurfaceFormats2KHR(
        VkResult                                    returnValue,
        HandleId                                    physicalDevice,
        const StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>& pSurfaceInfo,
        const PointerDecoder<uint32_t>&             pSurfaceFormatCount,
        const StructPointerDecoder<Decoded_VkSurfaceFormat2KHR>& pSurfaceFormats) override;

    virtual void Process_vkGetPhysicalDeviceDisplayProperties2KHR(
        VkResult                                    returnValue,
        HandleId                                    physicalDevice,
        const PointerDecoder<uint32_t>&             pPropertyCount,
        const StructPointerDecoder<Decoded_VkDisplayProperties2KHR>& pProperties) override;

    virtual void Process_vkGetPhysicalDeviceDisplayPlaneProperties2KHR(
        VkResult                                    returnValue,
        HandleId                                    physicalDevice,
        const PointerDecoder<uint32_t>&             pPropertyCount,
        const StructPointerDecoder<Decoded_VkDisplayPlaneProperties2KHR>& pProperties) override;

    virtual void Process_vkGetDisplayModeProperties2KHR(
        VkResult                                    returnValue,
        HandleId                                    physicalDevice,
        HandleId                                    display,
        const PointerDecoder<uint32_t>&             pPropertyCount,
        const StructPointerDecoder<Decoded_VkDisplayModeProperties2KHR>& pProperties) override;

    virtual void Process_vkGetDisplayPlaneCapabilities2KHR(
        VkResult                                    returnValue,
        HandleId                                    physicalDevice,
        const StructPointerDecoder<Decoded_VkDisplayPlaneInfo2KHR>& pDisplayPlaneInfo,
        const StructPointerDecoder<Decoded_VkDisplayPlaneCapabilities2KHR>& pCapabilities) override;

    virtual void Process_vkGetImageMemoryRequirements2KHR(
        HandleId                                    device,
        const StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2>& pInfo,
        const StructPointerDecoder<Decoded_VkMemoryRequirements2>& pMemoryRequirements) override;

    virtual void Process_vkGetBufferMemoryRequirements2KHR(
        HandleId                                    device,
        const StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2>& pInfo,
        const StructPointerDecoder<Decoded_VkMemoryRequirements2>& pMemoryRequirements) override;

    virtual void Process_vkGetImageSparseMemoryRequirements2KHR(
        HandleId                                    device,
        const StructPointerDecoder<Decoded_VkImageSparseMemoryRequirementsInfo2>& pInfo,
        const PointerDecoder<uint32_t>&             pSparseMemoryRequirementCount,
        const StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>& pSparseMemoryRequirements) override;

    virtual void Process_vkCreateSamplerYcbcrConversionKHR(
        VkResult                                    returnValue,
        HandleId                                    device,
        const StructPointerDecoder<Decoded_VkSamplerYcbcrConversionCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<HandleId>&             pYcbcrConversion) override;

    virtual void Process_vkDestroySamplerYcbcrConversionKHR(
        HandleId                                    device,
        HandleId                                    ycbcrConversion,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) override;

    virtual void Process_vkBindBufferMemory2KHR(
        VkResult                                    returnValue,
        HandleId                                    device,
        uint32_t                                    bindInfoCount,
        const StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>& pBindInfos) override;

    virtual void Process_vkBindImageMemory2KHR(
        VkResult                                    returnValue,
        HandleId                                    device,
        uint32_t                                    bindInfoCount,
        const StructPointerDecoder<Decoded_VkBindImageMemoryInfo>& pBindInfos) override;

    virtual void Process_vkGetDescriptorSetLayoutSupportKHR(
        HandleId                                    device,
        const StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport>& pSupport) override;

    virtual void Process_vkCmdDrawIndirectCountKHR(
        HandleId                                    commandBuffer,
        HandleId                                    buffer,
        VkDeviceSize                                offset,
        HandleId                                    countBuffer,
        VkDeviceSize                                countBufferOffset,
        uint32_t                                    maxDrawCount,
        uint32_t                                    stride) override;

    virtual void Process_vkCmdDrawIndexedIndirectCountKHR(
        HandleId                                    commandBuffer,
        HandleId                                    buffer,
        VkDeviceSize                                offset,
        HandleId                                    countBuffer,
        VkDeviceSize                                countBufferOffset,
        uint32_t                                    maxDrawCount,
        uint32_t                                    stride) override;

    virtual void Process_vkCreateDebugReportCallbackEXT(
        VkResult                                    returnValue,
        HandleId                                    instance,
        const StructPointerDecoder<Decoded_VkDebugReportCallbackCreateInfoEXT>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<HandleId>&             pCallback) override;

    virtual void Process_vkDestroyDebugReportCallbackEXT(
        HandleId                                    instance,
        HandleId                                    callback,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) override;

    virtual void Process_vkDebugReportMessageEXT(
        HandleId                                    instance,
        VkDebugReportFlagsEXT                       flags,
        VkDebugReportObjectTypeEXT                  objectType,
        uint64_t                                    object,
        size_t                                      location,
        int32_t                                     messageCode,
        const StringDecoder&                        pLayerPrefix,
        const StringDecoder&                        pMessage) override;

    virtual void Process_vkDebugMarkerSetObjectTagEXT(
        VkResult                                    returnValue,
        HandleId                                    device,
        const StructPointerDecoder<Decoded_VkDebugMarkerObjectTagInfoEXT>& pTagInfo) override;

    virtual void Process_vkDebugMarkerSetObjectNameEXT(
        VkResult                                    returnValue,
        HandleId                                    device,
        const StructPointerDecoder<Decoded_VkDebugMarkerObjectNameInfoEXT>& pNameInfo) override;

    virtual void Process_vkCmdDebugMarkerBeginEXT(
        HandleId                                    commandBuffer,
        const StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT>& pMarkerInfo) override;

    virtual void Process_vkCmdDebugMarkerEndEXT(
        HandleId                                    commandBuffer) override;

    virtual void Process_vkCmdDebugMarkerInsertEXT(
        HandleId                                    commandBuffer,
        const StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT>& pMarkerInfo) override;

    virtual void Process_vkCmdDrawIndirectCountAMD(
        HandleId                                    commandBuffer,
        HandleId                                    buffer,
        VkDeviceSize                                offset,
        HandleId                                    countBuffer,
        VkDeviceSize                                countBufferOffset,
        uint32_t                                    maxDrawCount,
        uint32_t                                    stride) override;

    virtual void Process_vkCmdDrawIndexedIndirectCountAMD(
        HandleId                                    commandBuffer,
        HandleId                                    buffer,
        VkDeviceSize                                offset,
        HandleId                                    countBuffer,
        VkDeviceSize                                countBufferOffset,
        uint32_t                                    maxDrawCount,
        uint32_t                                    stride) override;

    virtual void Process_vkGetShaderInfoAMD(
        VkResult                                    returnValue,
        HandleId                                    device,
        HandleId                                    pipeline,
        VkShaderStageFlagBits                       shaderStage,
        VkShaderInfoTypeAMD                         infoType,
        const PointerDecoder<size_t>&               pInfoSize,
        const PointerDecoder<uint8_t>&              pInfo) override;

    virtual void Process_vkGetPhysicalDeviceExternalImageFormatPropertiesNV(
        VkResult                                    returnValue,
        HandleId                                    physicalDevice,
        VkFormat                                    format,
        VkImageType                                 type,
        VkImageTiling                               tiling,
        VkImageUsageFlags                           usage,
        VkImageCreateFlags                          flags,
        VkExternalMemoryHandleTypeFlagsNV           externalHandleType,
        const StructPointerDecoder<Decoded_VkExternalImageFormatPropertiesNV>& pExternalImageFormatProperties) override;

    virtual void Process_vkGetMemoryWin32HandleNV(
        VkResult                                    returnValue,
        HandleId                                    device,
        HandleId                                    memory,
        VkExternalMemoryHandleTypeFlagsNV           handleType,
        const PointerDecoder<uint64_t>&             pHandle) override;

    virtual void Process_vkCreateViSurfaceNN(
        VkResult                                    returnValue,
        HandleId                                    instance,
        const StructPointerDecoder<Decoded_VkViSurfaceCreateInfoNN>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<HandleId>&             pSurface) override;

    virtual void Process_vkCmdBeginConditionalRenderingEXT(
        HandleId                                    commandBuffer,
        const StructPointerDecoder<Decoded_VkConditionalRenderingBeginInfoEXT>& pConditionalRenderingBegin) override;

    virtual void Process_vkCmdEndConditionalRenderingEXT(
        HandleId                                    commandBuffer) override;

    virtual void Process_vkCmdProcessCommandsNVX(
        HandleId                                    commandBuffer,
        const StructPointerDecoder<Decoded_VkCmdProcessCommandsInfoNVX>& pProcessCommandsInfo) override;

    virtual void Process_vkCmdReserveSpaceForCommandsNVX(
        HandleId                                    commandBuffer,
        const StructPointerDecoder<Decoded_VkCmdReserveSpaceForCommandsInfoNVX>& pReserveSpaceInfo) override;

    virtual void Process_vkCreateIndirectCommandsLayoutNVX(
        VkResult                                    returnValue,
        HandleId                                    device,
        const StructPointerDecoder<Decoded_VkIndirectCommandsLayoutCreateInfoNVX>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<HandleId>&             pIndirectCommandsLayout) override;

    virtual void Process_vkDestroyIndirectCommandsLayoutNVX(
        HandleId                                    device,
        HandleId                                    indirectCommandsLayout,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) override;

    virtual void Process_vkCreateObjectTableNVX(
        VkResult                                    returnValue,
        HandleId                                    device,
        const StructPointerDecoder<Decoded_VkObjectTableCreateInfoNVX>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<HandleId>&             pObjectTable) override;

    virtual void Process_vkDestroyObjectTableNVX(
        HandleId                                    device,
        HandleId                                    objectTable,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) override;

    virtual void Process_vkRegisterObjectsNVX(
        VkResult                                    returnValue,
        HandleId                                    device,
        HandleId                                    objectTable,
        uint32_t                                    objectCount,
        const StructPointerDecoder<Decoded_VkObjectTableEntryNVX>& ppObjectTableEntries,
        const PointerDecoder<uint32_t>&             pObjectIndices) override;

    virtual void Process_vkUnregisterObjectsNVX(
        VkResult                                    returnValue,
        HandleId                                    device,
        HandleId                                    objectTable,
        uint32_t                                    objectCount,
        const PointerDecoder<VkObjectEntryTypeNVX>& pObjectEntryTypes,
        const PointerDecoder<uint32_t>&             pObjectIndices) override;

    virtual void Process_vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX(
        HandleId                                    physicalDevice,
        const StructPointerDecoder<Decoded_VkDeviceGeneratedCommandsFeaturesNVX>& pFeatures,
        const StructPointerDecoder<Decoded_VkDeviceGeneratedCommandsLimitsNVX>& pLimits) override;

    virtual void Process_vkCmdSetViewportWScalingNV(
        HandleId                                    commandBuffer,
        uint32_t                                    firstViewport,
        uint32_t                                    viewportCount,
        const StructPointerDecoder<Decoded_VkViewportWScalingNV>& pViewportWScalings) override;

    virtual void Process_vkReleaseDisplayEXT(
        VkResult                                    returnValue,
        HandleId                                    physicalDevice,
        HandleId                                    display) override;

    virtual void Process_vkAcquireXlibDisplayEXT(
        VkResult                                    returnValue,
        HandleId                                    physicalDevice,
        uint64_t                                    dpy,
        HandleId                                    display) override;

    virtual void Process_vkGetRandROutputDisplayEXT(
        VkResult                                    returnValue,
        HandleId                                    physicalDevice,
        uint64_t                                    dpy,
        uint32_t                                    rrOutput,
        const PointerDecoder<HandleId>&             pDisplay) override;

    virtual void Process_vkGetPhysicalDeviceSurfaceCapabilities2EXT(
        VkResult                                    returnValue,
        HandleId                                    physicalDevice,
        HandleId                                    surface,
        const StructPointerDecoder<Decoded_VkSurfaceCapabilities2EXT>& pSurfaceCapabilities) override;

    virtual void Process_vkDisplayPowerControlEXT(
        VkResult                                    returnValue,
        HandleId                                    device,
        HandleId                                    display,
        const StructPointerDecoder<Decoded_VkDisplayPowerInfoEXT>& pDisplayPowerInfo) override;

    virtual void Process_vkRegisterDeviceEventEXT(
        VkResult                                    returnValue,
        HandleId                                    device,
        const StructPointerDecoder<Decoded_VkDeviceEventInfoEXT>& pDeviceEventInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<HandleId>&             pFence) override;

    virtual void Process_vkRegisterDisplayEventEXT(
        VkResult                                    returnValue,
        HandleId                                    device,
        HandleId                                    display,
        const StructPointerDecoder<Decoded_VkDisplayEventInfoEXT>& pDisplayEventInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<HandleId>&             pFence) override;

    virtual void Process_vkGetSwapchainCounterEXT(
        VkResult                                    returnValue,
        HandleId                                    device,
        HandleId                                    swapchain,
        VkSurfaceCounterFlagBitsEXT                 counter,
        const PointerDecoder<uint64_t>&             pCounterValue) override;

    virtual void Process_vkGetRefreshCycleDurationGOOGLE(
        VkResult                                    returnValue,
        HandleId                                    device,
        HandleId                                    swapchain,
        const StructPointerDecoder<Decoded_VkRefreshCycleDurationGOOGLE>& pDisplayTimingProperties) override;

    virtual void Process_vkGetPastPresentationTimingGOOGLE(
        VkResult                                    returnValue,
        HandleId                                    device,
        HandleId                                    swapchain,
        const PointerDecoder<uint32_t>&             pPresentationTimingCount,
        const StructPointerDecoder<Decoded_VkPastPresentationTimingGOOGLE>& pPresentationTimings) override;

    virtual void Process_vkCmdSetDiscardRectangleEXT(
        HandleId                                    commandBuffer,
        uint32_t                                    firstDiscardRectangle,
        uint32_t                                    discardRectangleCount,
        const StructPointerDecoder<Decoded_VkRect2D>& pDiscardRectangles) override;

    virtual void Process_vkSetHdrMetadataEXT(
        HandleId                                    device,
        uint32_t                                    swapchainCount,
        const PointerDecoder<HandleId>&             pSwapchains,
        const StructPointerDecoder<Decoded_VkHdrMetadataEXT>& pMetadata) override;

    virtual void Process_vkCreateIOSSurfaceMVK(
        VkResult                                    returnValue,
        HandleId                                    instance,
        const StructPointerDecoder<Decoded_VkIOSSurfaceCreateInfoMVK>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<HandleId>&             pSurface) override;

    virtual void Process_vkCreateMacOSSurfaceMVK(
        VkResult                                    returnValue,
        HandleId                                    instance,
        const StructPointerDecoder<Decoded_VkMacOSSurfaceCreateInfoMVK>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<HandleId>&             pSurface) override;

    virtual void Process_vkSetDebugUtilsObjectNameEXT(
        VkResult                                    returnValue,
        HandleId                                    device,
        const StructPointerDecoder<Decoded_VkDebugUtilsObjectNameInfoEXT>& pNameInfo) override;

    virtual void Process_vkSetDebugUtilsObjectTagEXT(
        VkResult                                    returnValue,
        HandleId                                    device,
        const StructPointerDecoder<Decoded_VkDebugUtilsObjectTagInfoEXT>& pTagInfo) override;

    virtual void Process_vkQueueBeginDebugUtilsLabelEXT(
        HandleId                                    queue,
        const StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>& pLabelInfo) override;

    virtual void Process_vkQueueEndDebugUtilsLabelEXT(
        HandleId                                    queue) override;

    virtual void Process_vkQueueInsertDebugUtilsLabelEXT(
        HandleId                                    queue,
        const StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>& pLabelInfo) override;

    virtual void Process_vkCmdBeginDebugUtilsLabelEXT(
        HandleId                                    commandBuffer,
        const StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>& pLabelInfo) override;

    virtual void Process_vkCmdEndDebugUtilsLabelEXT(
        HandleId                                    commandBuffer) override;

    virtual void Process_vkCmdInsertDebugUtilsLabelEXT(
        HandleId                                    commandBuffer,
        const StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>& pLabelInfo) override;

    virtual void Process_vkCreateDebugUtilsMessengerEXT(
        VkResult                                    returnValue,
        HandleId                                    instance,
        const StructPointerDecoder<Decoded_VkDebugUtilsMessengerCreateInfoEXT>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<HandleId>&             pMessenger) override;

    virtual void Process_vkDestroyDebugUtilsMessengerEXT(
        HandleId                                    instance,
        HandleId                                    messenger,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) override;

    virtual void Process_vkSubmitDebugUtilsMessageEXT(
        HandleId                                    instance,
        VkDebugUtilsMessageSeverityFlagBitsEXT      messageSeverity,
        VkDebugUtilsMessageTypeFlagsEXT             messageTypes,
        const StructPointerDecoder<Decoded_VkDebugUtilsMessengerCallbackDataEXT>& pCallbackData) override;

    virtual void Process_vkGetAndroidHardwareBufferPropertiesANDROID(
        VkResult                                    returnValue,
        HandleId                                    device,
        uint64_t                                    buffer,
        const StructPointerDecoder<Decoded_VkAndroidHardwareBufferPropertiesANDROID>& pProperties) override;

    virtual void Process_vkGetMemoryAndroidHardwareBufferANDROID(
        VkResult                                    returnValue,
        HandleId                                    device,
        const StructPointerDecoder<Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID>& pInfo,
        const PointerDecoder<uint64_t>&             pBuffer) override;

    virtual void Process_vkCmdSetSampleLocationsEXT(
        HandleId                                    commandBuffer,
        const StructPointerDecoder<Decoded_VkSampleLocationsInfoEXT>& pSampleLocationsInfo) override;

    virtual void Process_vkGetPhysicalDeviceMultisamplePropertiesEXT(
        HandleId                                    physicalDevice,
        VkSampleCountFlagBits                       samples,
        const StructPointerDecoder<Decoded_VkMultisamplePropertiesEXT>& pMultisampleProperties) override;

    virtual void Process_vkCreateValidationCacheEXT(
        VkResult                                    returnValue,
        HandleId                                    device,
        const StructPointerDecoder<Decoded_VkValidationCacheCreateInfoEXT>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<HandleId>&             pValidationCache) override;

    virtual void Process_vkDestroyValidationCacheEXT(
        HandleId                                    device,
        HandleId                                    validationCache,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) override;

    virtual void Process_vkMergeValidationCachesEXT(
        VkResult                                    returnValue,
        HandleId                                    device,
        HandleId                                    dstCache,
        uint32_t                                    srcCacheCount,
        const PointerDecoder<HandleId>&             pSrcCaches) override;

    virtual void Process_vkGetValidationCacheDataEXT(
        VkResult                                    returnValue,
        HandleId                                    device,
        HandleId                                    validationCache,
        const PointerDecoder<size_t>&               pDataSize,
        const PointerDecoder<uint8_t>&              pData) override;

    virtual void Process_vkGetMemoryHostPointerPropertiesEXT(
        VkResult                                    returnValue,
        HandleId                                    device,
        VkExternalMemoryHandleTypeFlagBits          handleType,
        uint64_t                                    pHostPointer,
        const StructPointerDecoder<Decoded_VkMemoryHostPointerPropertiesEXT>& pMemoryHostPointerProperties) override;

    virtual void Process_vkCmdWriteBufferMarkerAMD(
        HandleId                                    commandBuffer,
        VkPipelineStageFlagBits                     pipelineStage,
        HandleId                                    dstBuffer,
        VkDeviceSize                                dstOffset,
        uint32_t                                    marker) override;
