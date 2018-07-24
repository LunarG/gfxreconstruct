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
        const PointerDecoder<VkInstance>&           pInstance) override;

    virtual void Process_vkDestroyInstance(
        VkInstance                                  instance,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) override;

    virtual void Process_vkEnumeratePhysicalDevices(
        VkResult                                    returnValue,
        VkInstance                                  instance,
        const PointerDecoder<uint32_t>&             pPhysicalDeviceCount,
        const PointerDecoder<VkPhysicalDevice>&     pPhysicalDevices) override;

    virtual void Process_vkGetPhysicalDeviceFeatures(
        VkPhysicalDevice                            physicalDevice,
        const StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures>& pFeatures) override;

    virtual void Process_vkGetPhysicalDeviceFormatProperties(
        VkPhysicalDevice                            physicalDevice,
        VkFormat                                    format,
        const StructPointerDecoder<Decoded_VkFormatProperties>& pFormatProperties) override;

    virtual void Process_vkGetPhysicalDeviceImageFormatProperties(
        VkResult                                    returnValue,
        VkPhysicalDevice                            physicalDevice,
        VkFormat                                    format,
        VkImageType                                 type,
        VkImageTiling                               tiling,
        VkImageUsageFlags                           usage,
        VkImageCreateFlags                          flags,
        const StructPointerDecoder<Decoded_VkImageFormatProperties>& pImageFormatProperties) override;

    virtual void Process_vkGetPhysicalDeviceProperties(
        VkPhysicalDevice                            physicalDevice,
        const StructPointerDecoder<Decoded_VkPhysicalDeviceProperties>& pProperties) override;

    virtual void Process_vkGetPhysicalDeviceQueueFamilyProperties(
        VkPhysicalDevice                            physicalDevice,
        const PointerDecoder<uint32_t>&             pQueueFamilyPropertyCount,
        const StructPointerDecoder<Decoded_VkQueueFamilyProperties>& pQueueFamilyProperties) override;

    virtual void Process_vkGetPhysicalDeviceMemoryProperties(
        VkPhysicalDevice                            physicalDevice,
        const StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties>& pMemoryProperties) override;

    virtual void Process_vkCreateDevice(
        VkResult                                    returnValue,
        VkPhysicalDevice                            physicalDevice,
        const StructPointerDecoder<Decoded_VkDeviceCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<VkDevice>&             pDevice) override;

    virtual void Process_vkDestroyDevice(
        VkDevice                                    device,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) override;

    virtual void Process_vkGetDeviceQueue(
        VkDevice                                    device,
        uint32_t                                    queueFamilyIndex,
        uint32_t                                    queueIndex,
        const PointerDecoder<VkQueue>&              pQueue) override;

    virtual void Process_vkQueueSubmit(
        VkResult                                    returnValue,
        VkQueue                                     queue,
        uint32_t                                    submitCount,
        const StructPointerDecoder<Decoded_VkSubmitInfo>& pSubmits,
        VkFence                                     fence) override;

    virtual void Process_vkQueueWaitIdle(
        VkResult                                    returnValue,
        VkQueue                                     queue) override;

    virtual void Process_vkDeviceWaitIdle(
        VkResult                                    returnValue,
        VkDevice                                    device) override;

    virtual void Process_vkAllocateMemory(
        VkResult                                    returnValue,
        VkDevice                                    device,
        const StructPointerDecoder<Decoded_VkMemoryAllocateInfo>& pAllocateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<VkDeviceMemory>&       pMemory) override;

    virtual void Process_vkFreeMemory(
        VkDevice                                    device,
        VkDeviceMemory                              memory,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) override;

    virtual void Process_vkMapMemory(
        VkResult                                    returnValue,
        VkDevice                                    device,
        VkDeviceMemory                              memory,
        VkDeviceSize                                offset,
        VkDeviceSize                                size,
        VkMemoryMapFlags                            flags,
        const PointerDecoder<uint64_t>&             ppData) override;

    virtual void Process_vkUnmapMemory(
        VkDevice                                    device,
        VkDeviceMemory                              memory) override;

    virtual void Process_vkFlushMappedMemoryRanges(
        VkResult                                    returnValue,
        VkDevice                                    device,
        uint32_t                                    memoryRangeCount,
        const StructPointerDecoder<Decoded_VkMappedMemoryRange>& pMemoryRanges) override;

    virtual void Process_vkInvalidateMappedMemoryRanges(
        VkResult                                    returnValue,
        VkDevice                                    device,
        uint32_t                                    memoryRangeCount,
        const StructPointerDecoder<Decoded_VkMappedMemoryRange>& pMemoryRanges) override;

    virtual void Process_vkGetDeviceMemoryCommitment(
        VkDevice                                    device,
        VkDeviceMemory                              memory,
        const PointerDecoder<VkDeviceSize>&         pCommittedMemoryInBytes) override;

    virtual void Process_vkBindBufferMemory(
        VkResult                                    returnValue,
        VkDevice                                    device,
        VkBuffer                                    buffer,
        VkDeviceMemory                              memory,
        VkDeviceSize                                memoryOffset) override;

    virtual void Process_vkBindImageMemory(
        VkResult                                    returnValue,
        VkDevice                                    device,
        VkImage                                     image,
        VkDeviceMemory                              memory,
        VkDeviceSize                                memoryOffset) override;

    virtual void Process_vkGetBufferMemoryRequirements(
        VkDevice                                    device,
        VkBuffer                                    buffer,
        const StructPointerDecoder<Decoded_VkMemoryRequirements>& pMemoryRequirements) override;

    virtual void Process_vkGetImageMemoryRequirements(
        VkDevice                                    device,
        VkImage                                     image,
        const StructPointerDecoder<Decoded_VkMemoryRequirements>& pMemoryRequirements) override;

    virtual void Process_vkGetImageSparseMemoryRequirements(
        VkDevice                                    device,
        VkImage                                     image,
        const PointerDecoder<uint32_t>&             pSparseMemoryRequirementCount,
        const StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements>& pSparseMemoryRequirements) override;

    virtual void Process_vkGetPhysicalDeviceSparseImageFormatProperties(
        VkPhysicalDevice                            physicalDevice,
        VkFormat                                    format,
        VkImageType                                 type,
        VkSampleCountFlagBits                       samples,
        VkImageUsageFlags                           usage,
        VkImageTiling                               tiling,
        const PointerDecoder<uint32_t>&             pPropertyCount,
        const StructPointerDecoder<Decoded_VkSparseImageFormatProperties>& pProperties) override;

    virtual void Process_vkQueueBindSparse(
        VkResult                                    returnValue,
        VkQueue                                     queue,
        uint32_t                                    bindInfoCount,
        const StructPointerDecoder<Decoded_VkBindSparseInfo>& pBindInfo,
        VkFence                                     fence) override;

    virtual void Process_vkCreateFence(
        VkResult                                    returnValue,
        VkDevice                                    device,
        const StructPointerDecoder<Decoded_VkFenceCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<VkFence>&              pFence) override;

    virtual void Process_vkDestroyFence(
        VkDevice                                    device,
        VkFence                                     fence,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) override;

    virtual void Process_vkResetFences(
        VkResult                                    returnValue,
        VkDevice                                    device,
        uint32_t                                    fenceCount,
        const PointerDecoder<VkFence>&              pFences) override;

    virtual void Process_vkGetFenceStatus(
        VkResult                                    returnValue,
        VkDevice                                    device,
        VkFence                                     fence) override;

    virtual void Process_vkWaitForFences(
        VkResult                                    returnValue,
        VkDevice                                    device,
        uint32_t                                    fenceCount,
        const PointerDecoder<VkFence>&              pFences,
        VkBool32                                    waitAll,
        uint64_t                                    timeout) override;

    virtual void Process_vkCreateSemaphore(
        VkResult                                    returnValue,
        VkDevice                                    device,
        const StructPointerDecoder<Decoded_VkSemaphoreCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<VkSemaphore>&          pSemaphore) override;

    virtual void Process_vkDestroySemaphore(
        VkDevice                                    device,
        VkSemaphore                                 semaphore,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) override;

    virtual void Process_vkCreateEvent(
        VkResult                                    returnValue,
        VkDevice                                    device,
        const StructPointerDecoder<Decoded_VkEventCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<VkEvent>&              pEvent) override;

    virtual void Process_vkDestroyEvent(
        VkDevice                                    device,
        VkEvent                                     event,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) override;

    virtual void Process_vkGetEventStatus(
        VkResult                                    returnValue,
        VkDevice                                    device,
        VkEvent                                     event) override;

    virtual void Process_vkSetEvent(
        VkResult                                    returnValue,
        VkDevice                                    device,
        VkEvent                                     event) override;

    virtual void Process_vkResetEvent(
        VkResult                                    returnValue,
        VkDevice                                    device,
        VkEvent                                     event) override;

    virtual void Process_vkCreateQueryPool(
        VkResult                                    returnValue,
        VkDevice                                    device,
        const StructPointerDecoder<Decoded_VkQueryPoolCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<VkQueryPool>&          pQueryPool) override;

    virtual void Process_vkDestroyQueryPool(
        VkDevice                                    device,
        VkQueryPool                                 queryPool,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) override;

    virtual void Process_vkGetQueryPoolResults(
        VkResult                                    returnValue,
        VkDevice                                    device,
        VkQueryPool                                 queryPool,
        uint32_t                                    firstQuery,
        uint32_t                                    queryCount,
        size_t                                      dataSize,
        const PointerDecoder<uint8_t>&              pData,
        VkDeviceSize                                stride,
        VkQueryResultFlags                          flags) override;

    virtual void Process_vkCreateBuffer(
        VkResult                                    returnValue,
        VkDevice                                    device,
        const StructPointerDecoder<Decoded_VkBufferCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<VkBuffer>&             pBuffer) override;

    virtual void Process_vkDestroyBuffer(
        VkDevice                                    device,
        VkBuffer                                    buffer,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) override;

    virtual void Process_vkCreateBufferView(
        VkResult                                    returnValue,
        VkDevice                                    device,
        const StructPointerDecoder<Decoded_VkBufferViewCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<VkBufferView>&         pView) override;

    virtual void Process_vkDestroyBufferView(
        VkDevice                                    device,
        VkBufferView                                bufferView,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) override;

    virtual void Process_vkCreateImage(
        VkResult                                    returnValue,
        VkDevice                                    device,
        const StructPointerDecoder<Decoded_VkImageCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<VkImage>&              pImage) override;

    virtual void Process_vkDestroyImage(
        VkDevice                                    device,
        VkImage                                     image,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) override;

    virtual void Process_vkGetImageSubresourceLayout(
        VkDevice                                    device,
        VkImage                                     image,
        const StructPointerDecoder<Decoded_VkImageSubresource>& pSubresource,
        const StructPointerDecoder<Decoded_VkSubresourceLayout>& pLayout) override;

    virtual void Process_vkCreateImageView(
        VkResult                                    returnValue,
        VkDevice                                    device,
        const StructPointerDecoder<Decoded_VkImageViewCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<VkImageView>&          pView) override;

    virtual void Process_vkDestroyImageView(
        VkDevice                                    device,
        VkImageView                                 imageView,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) override;

    virtual void Process_vkCreateShaderModule(
        VkResult                                    returnValue,
        VkDevice                                    device,
        const StructPointerDecoder<Decoded_VkShaderModuleCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<VkShaderModule>&       pShaderModule) override;

    virtual void Process_vkDestroyShaderModule(
        VkDevice                                    device,
        VkShaderModule                              shaderModule,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) override;

    virtual void Process_vkCreatePipelineCache(
        VkResult                                    returnValue,
        VkDevice                                    device,
        const StructPointerDecoder<Decoded_VkPipelineCacheCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<VkPipelineCache>&      pPipelineCache) override;

    virtual void Process_vkDestroyPipelineCache(
        VkDevice                                    device,
        VkPipelineCache                             pipelineCache,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) override;

    virtual void Process_vkGetPipelineCacheData(
        VkResult                                    returnValue,
        VkDevice                                    device,
        VkPipelineCache                             pipelineCache,
        const PointerDecoder<size_t>&               pDataSize,
        const PointerDecoder<uint8_t>&              pData) override;

    virtual void Process_vkMergePipelineCaches(
        VkResult                                    returnValue,
        VkDevice                                    device,
        VkPipelineCache                             dstCache,
        uint32_t                                    srcCacheCount,
        const PointerDecoder<VkPipelineCache>&      pSrcCaches) override;

    virtual void Process_vkCreateGraphicsPipelines(
        VkResult                                    returnValue,
        VkDevice                                    device,
        VkPipelineCache                             pipelineCache,
        uint32_t                                    createInfoCount,
        const StructPointerDecoder<Decoded_VkGraphicsPipelineCreateInfo>& pCreateInfos,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<VkPipeline>&           pPipelines) override;

    virtual void Process_vkCreateComputePipelines(
        VkResult                                    returnValue,
        VkDevice                                    device,
        VkPipelineCache                             pipelineCache,
        uint32_t                                    createInfoCount,
        const StructPointerDecoder<Decoded_VkComputePipelineCreateInfo>& pCreateInfos,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<VkPipeline>&           pPipelines) override;

    virtual void Process_vkDestroyPipeline(
        VkDevice                                    device,
        VkPipeline                                  pipeline,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) override;

    virtual void Process_vkCreatePipelineLayout(
        VkResult                                    returnValue,
        VkDevice                                    device,
        const StructPointerDecoder<Decoded_VkPipelineLayoutCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<VkPipelineLayout>&     pPipelineLayout) override;

    virtual void Process_vkDestroyPipelineLayout(
        VkDevice                                    device,
        VkPipelineLayout                            pipelineLayout,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) override;

    virtual void Process_vkCreateSampler(
        VkResult                                    returnValue,
        VkDevice                                    device,
        const StructPointerDecoder<Decoded_VkSamplerCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<VkSampler>&            pSampler) override;

    virtual void Process_vkDestroySampler(
        VkDevice                                    device,
        VkSampler                                   sampler,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) override;

    virtual void Process_vkCreateDescriptorSetLayout(
        VkResult                                    returnValue,
        VkDevice                                    device,
        const StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<VkDescriptorSetLayout>& pSetLayout) override;

    virtual void Process_vkDestroyDescriptorSetLayout(
        VkDevice                                    device,
        VkDescriptorSetLayout                       descriptorSetLayout,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) override;

    virtual void Process_vkCreateDescriptorPool(
        VkResult                                    returnValue,
        VkDevice                                    device,
        const StructPointerDecoder<Decoded_VkDescriptorPoolCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<VkDescriptorPool>&     pDescriptorPool) override;

    virtual void Process_vkDestroyDescriptorPool(
        VkDevice                                    device,
        VkDescriptorPool                            descriptorPool,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) override;

    virtual void Process_vkResetDescriptorPool(
        VkResult                                    returnValue,
        VkDevice                                    device,
        VkDescriptorPool                            descriptorPool,
        VkDescriptorPoolResetFlags                  flags) override;

    virtual void Process_vkAllocateDescriptorSets(
        VkResult                                    returnValue,
        VkDevice                                    device,
        const StructPointerDecoder<Decoded_VkDescriptorSetAllocateInfo>& pAllocateInfo,
        const PointerDecoder<VkDescriptorSet>&      pDescriptorSets) override;

    virtual void Process_vkFreeDescriptorSets(
        VkResult                                    returnValue,
        VkDevice                                    device,
        VkDescriptorPool                            descriptorPool,
        uint32_t                                    descriptorSetCount,
        const PointerDecoder<VkDescriptorSet>&      pDescriptorSets) override;

    virtual void Process_vkUpdateDescriptorSets(
        VkDevice                                    device,
        uint32_t                                    descriptorWriteCount,
        const StructPointerDecoder<Decoded_VkWriteDescriptorSet>& pDescriptorWrites,
        uint32_t                                    descriptorCopyCount,
        const StructPointerDecoder<Decoded_VkCopyDescriptorSet>& pDescriptorCopies) override;

    virtual void Process_vkCreateFramebuffer(
        VkResult                                    returnValue,
        VkDevice                                    device,
        const StructPointerDecoder<Decoded_VkFramebufferCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<VkFramebuffer>&        pFramebuffer) override;

    virtual void Process_vkDestroyFramebuffer(
        VkDevice                                    device,
        VkFramebuffer                               framebuffer,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) override;

    virtual void Process_vkCreateRenderPass(
        VkResult                                    returnValue,
        VkDevice                                    device,
        const StructPointerDecoder<Decoded_VkRenderPassCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<VkRenderPass>&         pRenderPass) override;

    virtual void Process_vkDestroyRenderPass(
        VkDevice                                    device,
        VkRenderPass                                renderPass,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) override;

    virtual void Process_vkGetRenderAreaGranularity(
        VkDevice                                    device,
        VkRenderPass                                renderPass,
        const StructPointerDecoder<Decoded_VkExtent2D>& pGranularity) override;

    virtual void Process_vkCreateCommandPool(
        VkResult                                    returnValue,
        VkDevice                                    device,
        const StructPointerDecoder<Decoded_VkCommandPoolCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<VkCommandPool>&        pCommandPool) override;

    virtual void Process_vkDestroyCommandPool(
        VkDevice                                    device,
        VkCommandPool                               commandPool,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) override;

    virtual void Process_vkResetCommandPool(
        VkResult                                    returnValue,
        VkDevice                                    device,
        VkCommandPool                               commandPool,
        VkCommandPoolResetFlags                     flags) override;

    virtual void Process_vkAllocateCommandBuffers(
        VkResult                                    returnValue,
        VkDevice                                    device,
        const StructPointerDecoder<Decoded_VkCommandBufferAllocateInfo>& pAllocateInfo,
        const PointerDecoder<VkCommandBuffer>&      pCommandBuffers) override;

    virtual void Process_vkFreeCommandBuffers(
        VkDevice                                    device,
        VkCommandPool                               commandPool,
        uint32_t                                    commandBufferCount,
        const PointerDecoder<VkCommandBuffer>&      pCommandBuffers) override;

    virtual void Process_vkBeginCommandBuffer(
        VkResult                                    returnValue,
        VkCommandBuffer                             commandBuffer,
        const StructPointerDecoder<Decoded_VkCommandBufferBeginInfo>& pBeginInfo) override;

    virtual void Process_vkEndCommandBuffer(
        VkResult                                    returnValue,
        VkCommandBuffer                             commandBuffer) override;

    virtual void Process_vkResetCommandBuffer(
        VkResult                                    returnValue,
        VkCommandBuffer                             commandBuffer,
        VkCommandBufferResetFlags                   flags) override;

    virtual void Process_vkCmdBindPipeline(
        VkCommandBuffer                             commandBuffer,
        VkPipelineBindPoint                         pipelineBindPoint,
        VkPipeline                                  pipeline) override;

    virtual void Process_vkCmdSetViewport(
        VkCommandBuffer                             commandBuffer,
        uint32_t                                    firstViewport,
        uint32_t                                    viewportCount,
        const StructPointerDecoder<Decoded_VkViewport>& pViewports) override;

    virtual void Process_vkCmdSetScissor(
        VkCommandBuffer                             commandBuffer,
        uint32_t                                    firstScissor,
        uint32_t                                    scissorCount,
        const StructPointerDecoder<Decoded_VkRect2D>& pScissors) override;

    virtual void Process_vkCmdSetLineWidth(
        VkCommandBuffer                             commandBuffer,
        float                                       lineWidth) override;

    virtual void Process_vkCmdSetDepthBias(
        VkCommandBuffer                             commandBuffer,
        float                                       depthBiasConstantFactor,
        float                                       depthBiasClamp,
        float                                       depthBiasSlopeFactor) override;

    virtual void Process_vkCmdSetBlendConstants(
        VkCommandBuffer                             commandBuffer,
        const PointerDecoder<float>&                blendConstants) override;

    virtual void Process_vkCmdSetDepthBounds(
        VkCommandBuffer                             commandBuffer,
        float                                       minDepthBounds,
        float                                       maxDepthBounds) override;

    virtual void Process_vkCmdSetStencilCompareMask(
        VkCommandBuffer                             commandBuffer,
        VkStencilFaceFlags                          faceMask,
        uint32_t                                    compareMask) override;

    virtual void Process_vkCmdSetStencilWriteMask(
        VkCommandBuffer                             commandBuffer,
        VkStencilFaceFlags                          faceMask,
        uint32_t                                    writeMask) override;

    virtual void Process_vkCmdSetStencilReference(
        VkCommandBuffer                             commandBuffer,
        VkStencilFaceFlags                          faceMask,
        uint32_t                                    reference) override;

    virtual void Process_vkCmdBindDescriptorSets(
        VkCommandBuffer                             commandBuffer,
        VkPipelineBindPoint                         pipelineBindPoint,
        VkPipelineLayout                            layout,
        uint32_t                                    firstSet,
        uint32_t                                    descriptorSetCount,
        const PointerDecoder<VkDescriptorSet>&      pDescriptorSets,
        uint32_t                                    dynamicOffsetCount,
        const PointerDecoder<uint32_t>&             pDynamicOffsets) override;

    virtual void Process_vkCmdBindIndexBuffer(
        VkCommandBuffer                             commandBuffer,
        VkBuffer                                    buffer,
        VkDeviceSize                                offset,
        VkIndexType                                 indexType) override;

    virtual void Process_vkCmdBindVertexBuffers(
        VkCommandBuffer                             commandBuffer,
        uint32_t                                    firstBinding,
        uint32_t                                    bindingCount,
        const PointerDecoder<VkBuffer>&             pBuffers,
        const PointerDecoder<VkDeviceSize>&         pOffsets) override;

    virtual void Process_vkCmdDraw(
        VkCommandBuffer                             commandBuffer,
        uint32_t                                    vertexCount,
        uint32_t                                    instanceCount,
        uint32_t                                    firstVertex,
        uint32_t                                    firstInstance) override;

    virtual void Process_vkCmdDrawIndexed(
        VkCommandBuffer                             commandBuffer,
        uint32_t                                    indexCount,
        uint32_t                                    instanceCount,
        uint32_t                                    firstIndex,
        int32_t                                     vertexOffset,
        uint32_t                                    firstInstance) override;

    virtual void Process_vkCmdDrawIndirect(
        VkCommandBuffer                             commandBuffer,
        VkBuffer                                    buffer,
        VkDeviceSize                                offset,
        uint32_t                                    drawCount,
        uint32_t                                    stride) override;

    virtual void Process_vkCmdDrawIndexedIndirect(
        VkCommandBuffer                             commandBuffer,
        VkBuffer                                    buffer,
        VkDeviceSize                                offset,
        uint32_t                                    drawCount,
        uint32_t                                    stride) override;

    virtual void Process_vkCmdDispatch(
        VkCommandBuffer                             commandBuffer,
        uint32_t                                    groupCountX,
        uint32_t                                    groupCountY,
        uint32_t                                    groupCountZ) override;

    virtual void Process_vkCmdDispatchIndirect(
        VkCommandBuffer                             commandBuffer,
        VkBuffer                                    buffer,
        VkDeviceSize                                offset) override;

    virtual void Process_vkCmdCopyBuffer(
        VkCommandBuffer                             commandBuffer,
        VkBuffer                                    srcBuffer,
        VkBuffer                                    dstBuffer,
        uint32_t                                    regionCount,
        const StructPointerDecoder<Decoded_VkBufferCopy>& pRegions) override;

    virtual void Process_vkCmdCopyImage(
        VkCommandBuffer                             commandBuffer,
        VkImage                                     srcImage,
        VkImageLayout                               srcImageLayout,
        VkImage                                     dstImage,
        VkImageLayout                               dstImageLayout,
        uint32_t                                    regionCount,
        const StructPointerDecoder<Decoded_VkImageCopy>& pRegions) override;

    virtual void Process_vkCmdBlitImage(
        VkCommandBuffer                             commandBuffer,
        VkImage                                     srcImage,
        VkImageLayout                               srcImageLayout,
        VkImage                                     dstImage,
        VkImageLayout                               dstImageLayout,
        uint32_t                                    regionCount,
        const StructPointerDecoder<Decoded_VkImageBlit>& pRegions,
        VkFilter                                    filter) override;

    virtual void Process_vkCmdCopyBufferToImage(
        VkCommandBuffer                             commandBuffer,
        VkBuffer                                    srcBuffer,
        VkImage                                     dstImage,
        VkImageLayout                               dstImageLayout,
        uint32_t                                    regionCount,
        const StructPointerDecoder<Decoded_VkBufferImageCopy>& pRegions) override;

    virtual void Process_vkCmdCopyImageToBuffer(
        VkCommandBuffer                             commandBuffer,
        VkImage                                     srcImage,
        VkImageLayout                               srcImageLayout,
        VkBuffer                                    dstBuffer,
        uint32_t                                    regionCount,
        const StructPointerDecoder<Decoded_VkBufferImageCopy>& pRegions) override;

    virtual void Process_vkCmdUpdateBuffer(
        VkCommandBuffer                             commandBuffer,
        VkBuffer                                    dstBuffer,
        VkDeviceSize                                dstOffset,
        VkDeviceSize                                dataSize,
        const PointerDecoder<uint8_t>&              pData) override;

    virtual void Process_vkCmdFillBuffer(
        VkCommandBuffer                             commandBuffer,
        VkBuffer                                    dstBuffer,
        VkDeviceSize                                dstOffset,
        VkDeviceSize                                size,
        uint32_t                                    data) override;

    virtual void Process_vkCmdClearColorImage(
        VkCommandBuffer                             commandBuffer,
        VkImage                                     image,
        VkImageLayout                               imageLayout,
        const StructPointerDecoder<Decoded_VkClearColorValue>& pColor,
        uint32_t                                    rangeCount,
        const StructPointerDecoder<Decoded_VkImageSubresourceRange>& pRanges) override;

    virtual void Process_vkCmdClearDepthStencilImage(
        VkCommandBuffer                             commandBuffer,
        VkImage                                     image,
        VkImageLayout                               imageLayout,
        const StructPointerDecoder<Decoded_VkClearDepthStencilValue>& pDepthStencil,
        uint32_t                                    rangeCount,
        const StructPointerDecoder<Decoded_VkImageSubresourceRange>& pRanges) override;

    virtual void Process_vkCmdClearAttachments(
        VkCommandBuffer                             commandBuffer,
        uint32_t                                    attachmentCount,
        const StructPointerDecoder<Decoded_VkClearAttachment>& pAttachments,
        uint32_t                                    rectCount,
        const StructPointerDecoder<Decoded_VkClearRect>& pRects) override;

    virtual void Process_vkCmdResolveImage(
        VkCommandBuffer                             commandBuffer,
        VkImage                                     srcImage,
        VkImageLayout                               srcImageLayout,
        VkImage                                     dstImage,
        VkImageLayout                               dstImageLayout,
        uint32_t                                    regionCount,
        const StructPointerDecoder<Decoded_VkImageResolve>& pRegions) override;

    virtual void Process_vkCmdSetEvent(
        VkCommandBuffer                             commandBuffer,
        VkEvent                                     event,
        VkPipelineStageFlags                        stageMask) override;

    virtual void Process_vkCmdResetEvent(
        VkCommandBuffer                             commandBuffer,
        VkEvent                                     event,
        VkPipelineStageFlags                        stageMask) override;

    virtual void Process_vkCmdWaitEvents(
        VkCommandBuffer                             commandBuffer,
        uint32_t                                    eventCount,
        const PointerDecoder<VkEvent>&              pEvents,
        VkPipelineStageFlags                        srcStageMask,
        VkPipelineStageFlags                        dstStageMask,
        uint32_t                                    memoryBarrierCount,
        const StructPointerDecoder<Decoded_VkMemoryBarrier>& pMemoryBarriers,
        uint32_t                                    bufferMemoryBarrierCount,
        const StructPointerDecoder<Decoded_VkBufferMemoryBarrier>& pBufferMemoryBarriers,
        uint32_t                                    imageMemoryBarrierCount,
        const StructPointerDecoder<Decoded_VkImageMemoryBarrier>& pImageMemoryBarriers) override;

    virtual void Process_vkCmdPipelineBarrier(
        VkCommandBuffer                             commandBuffer,
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
        VkCommandBuffer                             commandBuffer,
        VkQueryPool                                 queryPool,
        uint32_t                                    query,
        VkQueryControlFlags                         flags) override;

    virtual void Process_vkCmdEndQuery(
        VkCommandBuffer                             commandBuffer,
        VkQueryPool                                 queryPool,
        uint32_t                                    query) override;

    virtual void Process_vkCmdResetQueryPool(
        VkCommandBuffer                             commandBuffer,
        VkQueryPool                                 queryPool,
        uint32_t                                    firstQuery,
        uint32_t                                    queryCount) override;

    virtual void Process_vkCmdWriteTimestamp(
        VkCommandBuffer                             commandBuffer,
        VkPipelineStageFlagBits                     pipelineStage,
        VkQueryPool                                 queryPool,
        uint32_t                                    query) override;

    virtual void Process_vkCmdCopyQueryPoolResults(
        VkCommandBuffer                             commandBuffer,
        VkQueryPool                                 queryPool,
        uint32_t                                    firstQuery,
        uint32_t                                    queryCount,
        VkBuffer                                    dstBuffer,
        VkDeviceSize                                dstOffset,
        VkDeviceSize                                stride,
        VkQueryResultFlags                          flags) override;

    virtual void Process_vkCmdPushConstants(
        VkCommandBuffer                             commandBuffer,
        VkPipelineLayout                            layout,
        VkShaderStageFlags                          stageFlags,
        uint32_t                                    offset,
        uint32_t                                    size,
        const PointerDecoder<uint8_t>&              pValues) override;

    virtual void Process_vkCmdBeginRenderPass(
        VkCommandBuffer                             commandBuffer,
        const StructPointerDecoder<Decoded_VkRenderPassBeginInfo>& pRenderPassBegin,
        VkSubpassContents                           contents) override;

    virtual void Process_vkCmdNextSubpass(
        VkCommandBuffer                             commandBuffer,
        VkSubpassContents                           contents) override;

    virtual void Process_vkCmdEndRenderPass(
        VkCommandBuffer                             commandBuffer) override;

    virtual void Process_vkCmdExecuteCommands(
        VkCommandBuffer                             commandBuffer,
        uint32_t                                    commandBufferCount,
        const PointerDecoder<VkCommandBuffer>&      pCommandBuffers) override;

    virtual void Process_vkBindBufferMemory2(
        VkResult                                    returnValue,
        VkDevice                                    device,
        uint32_t                                    bindInfoCount,
        const StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>& pBindInfos) override;

    virtual void Process_vkBindImageMemory2(
        VkResult                                    returnValue,
        VkDevice                                    device,
        uint32_t                                    bindInfoCount,
        const StructPointerDecoder<Decoded_VkBindImageMemoryInfo>& pBindInfos) override;

    virtual void Process_vkGetDeviceGroupPeerMemoryFeatures(
        VkDevice                                    device,
        uint32_t                                    heapIndex,
        uint32_t                                    localDeviceIndex,
        uint32_t                                    remoteDeviceIndex,
        const PointerDecoder<VkPeerMemoryFeatureFlags>& pPeerMemoryFeatures) override;

    virtual void Process_vkCmdSetDeviceMask(
        VkCommandBuffer                             commandBuffer,
        uint32_t                                    deviceMask) override;

    virtual void Process_vkCmdDispatchBase(
        VkCommandBuffer                             commandBuffer,
        uint32_t                                    baseGroupX,
        uint32_t                                    baseGroupY,
        uint32_t                                    baseGroupZ,
        uint32_t                                    groupCountX,
        uint32_t                                    groupCountY,
        uint32_t                                    groupCountZ) override;

    virtual void Process_vkEnumeratePhysicalDeviceGroups(
        VkResult                                    returnValue,
        VkInstance                                  instance,
        const PointerDecoder<uint32_t>&             pPhysicalDeviceGroupCount,
        const StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties>& pPhysicalDeviceGroupProperties) override;

    virtual void Process_vkGetImageMemoryRequirements2(
        VkDevice                                    device,
        const StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2>& pInfo,
        const StructPointerDecoder<Decoded_VkMemoryRequirements2>& pMemoryRequirements) override;

    virtual void Process_vkGetBufferMemoryRequirements2(
        VkDevice                                    device,
        const StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2>& pInfo,
        const StructPointerDecoder<Decoded_VkMemoryRequirements2>& pMemoryRequirements) override;

    virtual void Process_vkGetImageSparseMemoryRequirements2(
        VkDevice                                    device,
        const StructPointerDecoder<Decoded_VkImageSparseMemoryRequirementsInfo2>& pInfo,
        const PointerDecoder<uint32_t>&             pSparseMemoryRequirementCount,
        const StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>& pSparseMemoryRequirements) override;

    virtual void Process_vkGetPhysicalDeviceFeatures2(
        VkPhysicalDevice                            physicalDevice,
        const StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2>& pFeatures) override;

    virtual void Process_vkGetPhysicalDeviceProperties2(
        VkPhysicalDevice                            physicalDevice,
        const StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>& pProperties) override;

    virtual void Process_vkGetPhysicalDeviceFormatProperties2(
        VkPhysicalDevice                            physicalDevice,
        VkFormat                                    format,
        const StructPointerDecoder<Decoded_VkFormatProperties2>& pFormatProperties) override;

    virtual void Process_vkGetPhysicalDeviceImageFormatProperties2(
        VkResult                                    returnValue,
        VkPhysicalDevice                            physicalDevice,
        const StructPointerDecoder<Decoded_VkPhysicalDeviceImageFormatInfo2>& pImageFormatInfo,
        const StructPointerDecoder<Decoded_VkImageFormatProperties2>& pImageFormatProperties) override;

    virtual void Process_vkGetPhysicalDeviceQueueFamilyProperties2(
        VkPhysicalDevice                            physicalDevice,
        const PointerDecoder<uint32_t>&             pQueueFamilyPropertyCount,
        const StructPointerDecoder<Decoded_VkQueueFamilyProperties2>& pQueueFamilyProperties) override;

    virtual void Process_vkGetPhysicalDeviceMemoryProperties2(
        VkPhysicalDevice                            physicalDevice,
        const StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2>& pMemoryProperties) override;

    virtual void Process_vkGetPhysicalDeviceSparseImageFormatProperties2(
        VkPhysicalDevice                            physicalDevice,
        const StructPointerDecoder<Decoded_VkPhysicalDeviceSparseImageFormatInfo2>& pFormatInfo,
        const PointerDecoder<uint32_t>&             pPropertyCount,
        const StructPointerDecoder<Decoded_VkSparseImageFormatProperties2>& pProperties) override;

    virtual void Process_vkTrimCommandPool(
        VkDevice                                    device,
        VkCommandPool                               commandPool,
        VkCommandPoolTrimFlags                      flags) override;

    virtual void Process_vkGetDeviceQueue2(
        VkDevice                                    device,
        const StructPointerDecoder<Decoded_VkDeviceQueueInfo2>& pQueueInfo,
        const PointerDecoder<VkQueue>&              pQueue) override;

    virtual void Process_vkCreateSamplerYcbcrConversion(
        VkResult                                    returnValue,
        VkDevice                                    device,
        const StructPointerDecoder<Decoded_VkSamplerYcbcrConversionCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<VkSamplerYcbcrConversion>& pYcbcrConversion) override;

    virtual void Process_vkDestroySamplerYcbcrConversion(
        VkDevice                                    device,
        VkSamplerYcbcrConversion                    ycbcrConversion,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) override;

    virtual void Process_vkCreateDescriptorUpdateTemplate(
        VkResult                                    returnValue,
        VkDevice                                    device,
        const StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<VkDescriptorUpdateTemplate>& pDescriptorUpdateTemplate) override;

    virtual void Process_vkDestroyDescriptorUpdateTemplate(
        VkDevice                                    device,
        VkDescriptorUpdateTemplate                  descriptorUpdateTemplate,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) override;

    virtual void Process_vkUpdateDescriptorSetWithTemplate(
        VkDevice                                    device,
        VkDescriptorSet                             descriptorSet,
        VkDescriptorUpdateTemplate                  descriptorUpdateTemplate,
        uint64_t                                    pData) override;

    virtual void Process_vkGetPhysicalDeviceExternalBufferProperties(
        VkPhysicalDevice                            physicalDevice,
        const StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo>& pExternalBufferInfo,
        const StructPointerDecoder<Decoded_VkExternalBufferProperties>& pExternalBufferProperties) override;

    virtual void Process_vkGetPhysicalDeviceExternalFenceProperties(
        VkPhysicalDevice                            physicalDevice,
        const StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo>& pExternalFenceInfo,
        const StructPointerDecoder<Decoded_VkExternalFenceProperties>& pExternalFenceProperties) override;

    virtual void Process_vkGetPhysicalDeviceExternalSemaphoreProperties(
        VkPhysicalDevice                            physicalDevice,
        const StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo>& pExternalSemaphoreInfo,
        const StructPointerDecoder<Decoded_VkExternalSemaphoreProperties>& pExternalSemaphoreProperties) override;

    virtual void Process_vkGetDescriptorSetLayoutSupport(
        VkDevice                                    device,
        const StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport>& pSupport) override;

    virtual void Process_vkDestroySurfaceKHR(
        VkInstance                                  instance,
        VkSurfaceKHR                                surface,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) override;

    virtual void Process_vkGetPhysicalDeviceSurfaceSupportKHR(
        VkResult                                    returnValue,
        VkPhysicalDevice                            physicalDevice,
        uint32_t                                    queueFamilyIndex,
        VkSurfaceKHR                                surface,
        const PointerDecoder<VkBool32>&             pSupported) override;

    virtual void Process_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(
        VkResult                                    returnValue,
        VkPhysicalDevice                            physicalDevice,
        VkSurfaceKHR                                surface,
        const StructPointerDecoder<Decoded_VkSurfaceCapabilitiesKHR>& pSurfaceCapabilities) override;

    virtual void Process_vkGetPhysicalDeviceSurfaceFormatsKHR(
        VkResult                                    returnValue,
        VkPhysicalDevice                            physicalDevice,
        VkSurfaceKHR                                surface,
        const PointerDecoder<uint32_t>&             pSurfaceFormatCount,
        const StructPointerDecoder<Decoded_VkSurfaceFormatKHR>& pSurfaceFormats) override;

    virtual void Process_vkGetPhysicalDeviceSurfacePresentModesKHR(
        VkResult                                    returnValue,
        VkPhysicalDevice                            physicalDevice,
        VkSurfaceKHR                                surface,
        const PointerDecoder<uint32_t>&             pPresentModeCount,
        const PointerDecoder<VkPresentModeKHR>&     pPresentModes) override;

    virtual void Process_vkCreateSwapchainKHR(
        VkResult                                    returnValue,
        VkDevice                                    device,
        const StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<VkSwapchainKHR>&       pSwapchain) override;

    virtual void Process_vkDestroySwapchainKHR(
        VkDevice                                    device,
        VkSwapchainKHR                              swapchain,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) override;

    virtual void Process_vkGetSwapchainImagesKHR(
        VkResult                                    returnValue,
        VkDevice                                    device,
        VkSwapchainKHR                              swapchain,
        const PointerDecoder<uint32_t>&             pSwapchainImageCount,
        const PointerDecoder<VkImage>&              pSwapchainImages) override;

    virtual void Process_vkAcquireNextImageKHR(
        VkResult                                    returnValue,
        VkDevice                                    device,
        VkSwapchainKHR                              swapchain,
        uint64_t                                    timeout,
        VkSemaphore                                 semaphore,
        VkFence                                     fence,
        const PointerDecoder<uint32_t>&             pImageIndex) override;

    virtual void Process_vkQueuePresentKHR(
        VkResult                                    returnValue,
        VkQueue                                     queue,
        const StructPointerDecoder<Decoded_VkPresentInfoKHR>& pPresentInfo) override;

    virtual void Process_vkGetDeviceGroupPresentCapabilitiesKHR(
        VkResult                                    returnValue,
        VkDevice                                    device,
        const StructPointerDecoder<Decoded_VkDeviceGroupPresentCapabilitiesKHR>& pDeviceGroupPresentCapabilities) override;

    virtual void Process_vkGetDeviceGroupSurfacePresentModesKHR(
        VkResult                                    returnValue,
        VkDevice                                    device,
        VkSurfaceKHR                                surface,
        const PointerDecoder<VkDeviceGroupPresentModeFlagsKHR>& pModes) override;

    virtual void Process_vkGetPhysicalDevicePresentRectanglesKHR(
        VkResult                                    returnValue,
        VkPhysicalDevice                            physicalDevice,
        VkSurfaceKHR                                surface,
        const PointerDecoder<uint32_t>&             pRectCount,
        const StructPointerDecoder<Decoded_VkRect2D>& pRects) override;

    virtual void Process_vkAcquireNextImage2KHR(
        VkResult                                    returnValue,
        VkDevice                                    device,
        const StructPointerDecoder<Decoded_VkAcquireNextImageInfoKHR>& pAcquireInfo,
        const PointerDecoder<uint32_t>&             pImageIndex) override;

    virtual void Process_vkGetPhysicalDeviceDisplayPropertiesKHR(
        VkResult                                    returnValue,
        VkPhysicalDevice                            physicalDevice,
        const PointerDecoder<uint32_t>&             pPropertyCount,
        const StructPointerDecoder<Decoded_VkDisplayPropertiesKHR>& pProperties) override;

    virtual void Process_vkGetPhysicalDeviceDisplayPlanePropertiesKHR(
        VkResult                                    returnValue,
        VkPhysicalDevice                            physicalDevice,
        const PointerDecoder<uint32_t>&             pPropertyCount,
        const StructPointerDecoder<Decoded_VkDisplayPlanePropertiesKHR>& pProperties) override;

    virtual void Process_vkGetDisplayPlaneSupportedDisplaysKHR(
        VkResult                                    returnValue,
        VkPhysicalDevice                            physicalDevice,
        uint32_t                                    planeIndex,
        const PointerDecoder<uint32_t>&             pDisplayCount,
        const PointerDecoder<VkDisplayKHR>&         pDisplays) override;

    virtual void Process_vkGetDisplayModePropertiesKHR(
        VkResult                                    returnValue,
        VkPhysicalDevice                            physicalDevice,
        VkDisplayKHR                                display,
        const PointerDecoder<uint32_t>&             pPropertyCount,
        const StructPointerDecoder<Decoded_VkDisplayModePropertiesKHR>& pProperties) override;

    virtual void Process_vkCreateDisplayModeKHR(
        VkResult                                    returnValue,
        VkPhysicalDevice                            physicalDevice,
        VkDisplayKHR                                display,
        const StructPointerDecoder<Decoded_VkDisplayModeCreateInfoKHR>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<VkDisplayModeKHR>&     pMode) override;

    virtual void Process_vkGetDisplayPlaneCapabilitiesKHR(
        VkResult                                    returnValue,
        VkPhysicalDevice                            physicalDevice,
        VkDisplayModeKHR                            mode,
        uint32_t                                    planeIndex,
        const StructPointerDecoder<Decoded_VkDisplayPlaneCapabilitiesKHR>& pCapabilities) override;

    virtual void Process_vkCreateDisplayPlaneSurfaceKHR(
        VkResult                                    returnValue,
        VkInstance                                  instance,
        const StructPointerDecoder<Decoded_VkDisplaySurfaceCreateInfoKHR>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<VkSurfaceKHR>&         pSurface) override;

    virtual void Process_vkCreateSharedSwapchainsKHR(
        VkResult                                    returnValue,
        VkDevice                                    device,
        uint32_t                                    swapchainCount,
        const StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>& pCreateInfos,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<VkSwapchainKHR>&       pSwapchains) override;

#ifdef VK_USE_PLATFORM_XLIB_KHR
    virtual void Process_vkCreateXlibSurfaceKHR(
        VkResult                                    returnValue,
        VkInstance                                  instance,
        const StructPointerDecoder<Decoded_VkXlibSurfaceCreateInfoKHR>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<VkSurfaceKHR>&         pSurface) override;

    virtual void Process_vkGetPhysicalDeviceXlibPresentationSupportKHR(
        VkBool32                                    returnValue,
        VkPhysicalDevice                            physicalDevice,
        uint32_t                                    queueFamilyIndex,
        const PointerDecoder<Display>&              dpy,
        VisualID                                    visualID) override;
#endif /* VK_USE_PLATFORM_XLIB_KHR */

#ifdef VK_USE_PLATFORM_XCB_KHR
    virtual void Process_vkCreateXcbSurfaceKHR(
        VkResult                                    returnValue,
        VkInstance                                  instance,
        const StructPointerDecoder<Decoded_VkXcbSurfaceCreateInfoKHR>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<VkSurfaceKHR>&         pSurface) override;

    virtual void Process_vkGetPhysicalDeviceXcbPresentationSupportKHR(
        VkBool32                                    returnValue,
        VkPhysicalDevice                            physicalDevice,
        uint32_t                                    queueFamilyIndex,
        const PointerDecoder<xcb_connection_t>&     connection,
        xcb_visualid_t                              visual_id) override;
#endif /* VK_USE_PLATFORM_XCB_KHR */

#ifdef VK_USE_PLATFORM_WAYLAND_KHR
    virtual void Process_vkCreateWaylandSurfaceKHR(
        VkResult                                    returnValue,
        VkInstance                                  instance,
        const StructPointerDecoder<Decoded_VkWaylandSurfaceCreateInfoKHR>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<VkSurfaceKHR>&         pSurface) override;

    virtual void Process_vkGetPhysicalDeviceWaylandPresentationSupportKHR(
        VkBool32                                    returnValue,
        VkPhysicalDevice                            physicalDevice,
        uint32_t                                    queueFamilyIndex,
        const PointerDecoder<wl_display>&           display) override;
#endif /* VK_USE_PLATFORM_WAYLAND_KHR */

#ifdef VK_USE_PLATFORM_MIR_KHR
    virtual void Process_vkCreateMirSurfaceKHR(
        VkResult                                    returnValue,
        VkInstance                                  instance,
        const StructPointerDecoder<Decoded_VkMirSurfaceCreateInfoKHR>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<VkSurfaceKHR>&         pSurface) override;

    virtual void Process_vkGetPhysicalDeviceMirPresentationSupportKHR(
        VkBool32                                    returnValue,
        VkPhysicalDevice                            physicalDevice,
        uint32_t                                    queueFamilyIndex,
        const PointerDecoder<MirConnection>&        connection) override;
#endif /* VK_USE_PLATFORM_MIR_KHR */

#ifdef VK_USE_PLATFORM_ANDROID_KHR
    virtual void Process_vkCreateAndroidSurfaceKHR(
        VkResult                                    returnValue,
        VkInstance                                  instance,
        const StructPointerDecoder<Decoded_VkAndroidSurfaceCreateInfoKHR>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<VkSurfaceKHR>&         pSurface) override;
#endif /* VK_USE_PLATFORM_ANDROID_KHR */

#ifdef VK_USE_PLATFORM_WIN32_KHR
    virtual void Process_vkCreateWin32SurfaceKHR(
        VkResult                                    returnValue,
        VkInstance                                  instance,
        const StructPointerDecoder<Decoded_VkWin32SurfaceCreateInfoKHR>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<VkSurfaceKHR>&         pSurface) override;

    virtual void Process_vkGetPhysicalDeviceWin32PresentationSupportKHR(
        VkBool32                                    returnValue,
        VkPhysicalDevice                            physicalDevice,
        uint32_t                                    queueFamilyIndex) override;
#endif /* VK_USE_PLATFORM_WIN32_KHR */

    virtual void Process_vkGetPhysicalDeviceFeatures2KHR(
        VkPhysicalDevice                            physicalDevice,
        const StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2>& pFeatures) override;

    virtual void Process_vkGetPhysicalDeviceProperties2KHR(
        VkPhysicalDevice                            physicalDevice,
        const StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>& pProperties) override;

    virtual void Process_vkGetPhysicalDeviceFormatProperties2KHR(
        VkPhysicalDevice                            physicalDevice,
        VkFormat                                    format,
        const StructPointerDecoder<Decoded_VkFormatProperties2>& pFormatProperties) override;

    virtual void Process_vkGetPhysicalDeviceImageFormatProperties2KHR(
        VkResult                                    returnValue,
        VkPhysicalDevice                            physicalDevice,
        const StructPointerDecoder<Decoded_VkPhysicalDeviceImageFormatInfo2>& pImageFormatInfo,
        const StructPointerDecoder<Decoded_VkImageFormatProperties2>& pImageFormatProperties) override;

    virtual void Process_vkGetPhysicalDeviceQueueFamilyProperties2KHR(
        VkPhysicalDevice                            physicalDevice,
        const PointerDecoder<uint32_t>&             pQueueFamilyPropertyCount,
        const StructPointerDecoder<Decoded_VkQueueFamilyProperties2>& pQueueFamilyProperties) override;

    virtual void Process_vkGetPhysicalDeviceMemoryProperties2KHR(
        VkPhysicalDevice                            physicalDevice,
        const StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2>& pMemoryProperties) override;

    virtual void Process_vkGetPhysicalDeviceSparseImageFormatProperties2KHR(
        VkPhysicalDevice                            physicalDevice,
        const StructPointerDecoder<Decoded_VkPhysicalDeviceSparseImageFormatInfo2>& pFormatInfo,
        const PointerDecoder<uint32_t>&             pPropertyCount,
        const StructPointerDecoder<Decoded_VkSparseImageFormatProperties2>& pProperties) override;

    virtual void Process_vkGetDeviceGroupPeerMemoryFeaturesKHR(
        VkDevice                                    device,
        uint32_t                                    heapIndex,
        uint32_t                                    localDeviceIndex,
        uint32_t                                    remoteDeviceIndex,
        const PointerDecoder<VkPeerMemoryFeatureFlags>& pPeerMemoryFeatures) override;

    virtual void Process_vkCmdSetDeviceMaskKHR(
        VkCommandBuffer                             commandBuffer,
        uint32_t                                    deviceMask) override;

    virtual void Process_vkCmdDispatchBaseKHR(
        VkCommandBuffer                             commandBuffer,
        uint32_t                                    baseGroupX,
        uint32_t                                    baseGroupY,
        uint32_t                                    baseGroupZ,
        uint32_t                                    groupCountX,
        uint32_t                                    groupCountY,
        uint32_t                                    groupCountZ) override;

    virtual void Process_vkTrimCommandPoolKHR(
        VkDevice                                    device,
        VkCommandPool                               commandPool,
        VkCommandPoolTrimFlags                      flags) override;

    virtual void Process_vkEnumeratePhysicalDeviceGroupsKHR(
        VkResult                                    returnValue,
        VkInstance                                  instance,
        const PointerDecoder<uint32_t>&             pPhysicalDeviceGroupCount,
        const StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties>& pPhysicalDeviceGroupProperties) override;

    virtual void Process_vkGetPhysicalDeviceExternalBufferPropertiesKHR(
        VkPhysicalDevice                            physicalDevice,
        const StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo>& pExternalBufferInfo,
        const StructPointerDecoder<Decoded_VkExternalBufferProperties>& pExternalBufferProperties) override;

#ifdef VK_USE_PLATFORM_WIN32_KHR
    virtual void Process_vkGetMemoryWin32HandleKHR(
        VkResult                                    returnValue,
        VkDevice                                    device,
        const StructPointerDecoder<Decoded_VkMemoryGetWin32HandleInfoKHR>& pGetWin32HandleInfo,
        const PointerDecoder<HANDLE>&               pHandle) override;

    virtual void Process_vkGetMemoryWin32HandlePropertiesKHR(
        VkResult                                    returnValue,
        VkDevice                                    device,
        VkExternalMemoryHandleTypeFlagBits          handleType,
        HANDLE                                      handle,
        const StructPointerDecoder<Decoded_VkMemoryWin32HandlePropertiesKHR>& pMemoryWin32HandleProperties) override;
#endif /* VK_USE_PLATFORM_WIN32_KHR */

    virtual void Process_vkGetMemoryFdKHR(
        VkResult                                    returnValue,
        VkDevice                                    device,
        const StructPointerDecoder<Decoded_VkMemoryGetFdInfoKHR>& pGetFdInfo,
        const PointerDecoder<int>&                  pFd) override;

    virtual void Process_vkGetMemoryFdPropertiesKHR(
        VkResult                                    returnValue,
        VkDevice                                    device,
        VkExternalMemoryHandleTypeFlagBits          handleType,
        int                                         fd,
        const StructPointerDecoder<Decoded_VkMemoryFdPropertiesKHR>& pMemoryFdProperties) override;

    virtual void Process_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(
        VkPhysicalDevice                            physicalDevice,
        const StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo>& pExternalSemaphoreInfo,
        const StructPointerDecoder<Decoded_VkExternalSemaphoreProperties>& pExternalSemaphoreProperties) override;

#ifdef VK_USE_PLATFORM_WIN32_KHR
    virtual void Process_vkImportSemaphoreWin32HandleKHR(
        VkResult                                    returnValue,
        VkDevice                                    device,
        const StructPointerDecoder<Decoded_VkImportSemaphoreWin32HandleInfoKHR>& pImportSemaphoreWin32HandleInfo) override;

    virtual void Process_vkGetSemaphoreWin32HandleKHR(
        VkResult                                    returnValue,
        VkDevice                                    device,
        const StructPointerDecoder<Decoded_VkSemaphoreGetWin32HandleInfoKHR>& pGetWin32HandleInfo,
        const PointerDecoder<HANDLE>&               pHandle) override;
#endif /* VK_USE_PLATFORM_WIN32_KHR */

    virtual void Process_vkImportSemaphoreFdKHR(
        VkResult                                    returnValue,
        VkDevice                                    device,
        const StructPointerDecoder<Decoded_VkImportSemaphoreFdInfoKHR>& pImportSemaphoreFdInfo) override;

    virtual void Process_vkGetSemaphoreFdKHR(
        VkResult                                    returnValue,
        VkDevice                                    device,
        const StructPointerDecoder<Decoded_VkSemaphoreGetFdInfoKHR>& pGetFdInfo,
        const PointerDecoder<int>&                  pFd) override;

    virtual void Process_vkCmdPushDescriptorSetKHR(
        VkCommandBuffer                             commandBuffer,
        VkPipelineBindPoint                         pipelineBindPoint,
        VkPipelineLayout                            layout,
        uint32_t                                    set,
        uint32_t                                    descriptorWriteCount,
        const StructPointerDecoder<Decoded_VkWriteDescriptorSet>& pDescriptorWrites) override;

    virtual void Process_vkCmdPushDescriptorSetWithTemplateKHR(
        VkCommandBuffer                             commandBuffer,
        VkDescriptorUpdateTemplate                  descriptorUpdateTemplate,
        VkPipelineLayout                            layout,
        uint32_t                                    set,
        uint64_t                                    pData) override;

    virtual void Process_vkCreateDescriptorUpdateTemplateKHR(
        VkResult                                    returnValue,
        VkDevice                                    device,
        const StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<VkDescriptorUpdateTemplate>& pDescriptorUpdateTemplate) override;

    virtual void Process_vkDestroyDescriptorUpdateTemplateKHR(
        VkDevice                                    device,
        VkDescriptorUpdateTemplate                  descriptorUpdateTemplate,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) override;

    virtual void Process_vkUpdateDescriptorSetWithTemplateKHR(
        VkDevice                                    device,
        VkDescriptorSet                             descriptorSet,
        VkDescriptorUpdateTemplate                  descriptorUpdateTemplate,
        uint64_t                                    pData) override;

    virtual void Process_vkCreateRenderPass2KHR(
        VkResult                                    returnValue,
        VkDevice                                    device,
        const StructPointerDecoder<Decoded_VkRenderPassCreateInfo2KHR>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<VkRenderPass>&         pRenderPass) override;

    virtual void Process_vkCmdBeginRenderPass2KHR(
        VkCommandBuffer                             commandBuffer,
        const StructPointerDecoder<Decoded_VkRenderPassBeginInfo>& pRenderPassBegin,
        const StructPointerDecoder<Decoded_VkSubpassBeginInfoKHR>& pSubpassBeginInfo) override;

    virtual void Process_vkCmdNextSubpass2KHR(
        VkCommandBuffer                             commandBuffer,
        const StructPointerDecoder<Decoded_VkSubpassBeginInfoKHR>& pSubpassBeginInfo,
        const StructPointerDecoder<Decoded_VkSubpassEndInfoKHR>& pSubpassEndInfo) override;

    virtual void Process_vkCmdEndRenderPass2KHR(
        VkCommandBuffer                             commandBuffer,
        const StructPointerDecoder<Decoded_VkSubpassEndInfoKHR>& pSubpassEndInfo) override;

    virtual void Process_vkGetSwapchainStatusKHR(
        VkResult                                    returnValue,
        VkDevice                                    device,
        VkSwapchainKHR                              swapchain) override;

    virtual void Process_vkGetPhysicalDeviceExternalFencePropertiesKHR(
        VkPhysicalDevice                            physicalDevice,
        const StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo>& pExternalFenceInfo,
        const StructPointerDecoder<Decoded_VkExternalFenceProperties>& pExternalFenceProperties) override;

#ifdef VK_USE_PLATFORM_WIN32_KHR
    virtual void Process_vkImportFenceWin32HandleKHR(
        VkResult                                    returnValue,
        VkDevice                                    device,
        const StructPointerDecoder<Decoded_VkImportFenceWin32HandleInfoKHR>& pImportFenceWin32HandleInfo) override;

    virtual void Process_vkGetFenceWin32HandleKHR(
        VkResult                                    returnValue,
        VkDevice                                    device,
        const StructPointerDecoder<Decoded_VkFenceGetWin32HandleInfoKHR>& pGetWin32HandleInfo,
        const PointerDecoder<HANDLE>&               pHandle) override;
#endif /* VK_USE_PLATFORM_WIN32_KHR */

    virtual void Process_vkImportFenceFdKHR(
        VkResult                                    returnValue,
        VkDevice                                    device,
        const StructPointerDecoder<Decoded_VkImportFenceFdInfoKHR>& pImportFenceFdInfo) override;

    virtual void Process_vkGetFenceFdKHR(
        VkResult                                    returnValue,
        VkDevice                                    device,
        const StructPointerDecoder<Decoded_VkFenceGetFdInfoKHR>& pGetFdInfo,
        const PointerDecoder<int>&                  pFd) override;

    virtual void Process_vkGetPhysicalDeviceSurfaceCapabilities2KHR(
        VkResult                                    returnValue,
        VkPhysicalDevice                            physicalDevice,
        const StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>& pSurfaceInfo,
        const StructPointerDecoder<Decoded_VkSurfaceCapabilities2KHR>& pSurfaceCapabilities) override;

    virtual void Process_vkGetPhysicalDeviceSurfaceFormats2KHR(
        VkResult                                    returnValue,
        VkPhysicalDevice                            physicalDevice,
        const StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>& pSurfaceInfo,
        const PointerDecoder<uint32_t>&             pSurfaceFormatCount,
        const StructPointerDecoder<Decoded_VkSurfaceFormat2KHR>& pSurfaceFormats) override;

    virtual void Process_vkGetPhysicalDeviceDisplayProperties2KHR(
        VkResult                                    returnValue,
        VkPhysicalDevice                            physicalDevice,
        const PointerDecoder<uint32_t>&             pPropertyCount,
        const StructPointerDecoder<Decoded_VkDisplayProperties2KHR>& pProperties) override;

    virtual void Process_vkGetPhysicalDeviceDisplayPlaneProperties2KHR(
        VkResult                                    returnValue,
        VkPhysicalDevice                            physicalDevice,
        const PointerDecoder<uint32_t>&             pPropertyCount,
        const StructPointerDecoder<Decoded_VkDisplayPlaneProperties2KHR>& pProperties) override;

    virtual void Process_vkGetDisplayModeProperties2KHR(
        VkResult                                    returnValue,
        VkPhysicalDevice                            physicalDevice,
        VkDisplayKHR                                display,
        const PointerDecoder<uint32_t>&             pPropertyCount,
        const StructPointerDecoder<Decoded_VkDisplayModeProperties2KHR>& pProperties) override;

    virtual void Process_vkGetDisplayPlaneCapabilities2KHR(
        VkResult                                    returnValue,
        VkPhysicalDevice                            physicalDevice,
        const StructPointerDecoder<Decoded_VkDisplayPlaneInfo2KHR>& pDisplayPlaneInfo,
        const StructPointerDecoder<Decoded_VkDisplayPlaneCapabilities2KHR>& pCapabilities) override;

    virtual void Process_vkGetImageMemoryRequirements2KHR(
        VkDevice                                    device,
        const StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2>& pInfo,
        const StructPointerDecoder<Decoded_VkMemoryRequirements2>& pMemoryRequirements) override;

    virtual void Process_vkGetBufferMemoryRequirements2KHR(
        VkDevice                                    device,
        const StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2>& pInfo,
        const StructPointerDecoder<Decoded_VkMemoryRequirements2>& pMemoryRequirements) override;

    virtual void Process_vkGetImageSparseMemoryRequirements2KHR(
        VkDevice                                    device,
        const StructPointerDecoder<Decoded_VkImageSparseMemoryRequirementsInfo2>& pInfo,
        const PointerDecoder<uint32_t>&             pSparseMemoryRequirementCount,
        const StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>& pSparseMemoryRequirements) override;

    virtual void Process_vkCreateSamplerYcbcrConversionKHR(
        VkResult                                    returnValue,
        VkDevice                                    device,
        const StructPointerDecoder<Decoded_VkSamplerYcbcrConversionCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<VkSamplerYcbcrConversion>& pYcbcrConversion) override;

    virtual void Process_vkDestroySamplerYcbcrConversionKHR(
        VkDevice                                    device,
        VkSamplerYcbcrConversion                    ycbcrConversion,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) override;

    virtual void Process_vkBindBufferMemory2KHR(
        VkResult                                    returnValue,
        VkDevice                                    device,
        uint32_t                                    bindInfoCount,
        const StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>& pBindInfos) override;

    virtual void Process_vkBindImageMemory2KHR(
        VkResult                                    returnValue,
        VkDevice                                    device,
        uint32_t                                    bindInfoCount,
        const StructPointerDecoder<Decoded_VkBindImageMemoryInfo>& pBindInfos) override;

    virtual void Process_vkGetDescriptorSetLayoutSupportKHR(
        VkDevice                                    device,
        const StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport>& pSupport) override;

    virtual void Process_vkCmdDrawIndirectCountKHR(
        VkCommandBuffer                             commandBuffer,
        VkBuffer                                    buffer,
        VkDeviceSize                                offset,
        VkBuffer                                    countBuffer,
        VkDeviceSize                                countBufferOffset,
        uint32_t                                    maxDrawCount,
        uint32_t                                    stride) override;

    virtual void Process_vkCmdDrawIndexedIndirectCountKHR(
        VkCommandBuffer                             commandBuffer,
        VkBuffer                                    buffer,
        VkDeviceSize                                offset,
        VkBuffer                                    countBuffer,
        VkDeviceSize                                countBufferOffset,
        uint32_t                                    maxDrawCount,
        uint32_t                                    stride) override;

    virtual void Process_vkCreateDebugReportCallbackEXT(
        VkResult                                    returnValue,
        VkInstance                                  instance,
        const StructPointerDecoder<Decoded_VkDebugReportCallbackCreateInfoEXT>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<VkDebugReportCallbackEXT>& pCallback) override;

    virtual void Process_vkDestroyDebugReportCallbackEXT(
        VkInstance                                  instance,
        VkDebugReportCallbackEXT                    callback,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) override;

    virtual void Process_vkDebugReportMessageEXT(
        VkInstance                                  instance,
        VkDebugReportFlagsEXT                       flags,
        VkDebugReportObjectTypeEXT                  objectType,
        uint64_t                                    object,
        size_t                                      location,
        int32_t                                     messageCode,
        const StringDecoder&                        pLayerPrefix,
        const StringDecoder&                        pMessage) override;

    virtual void Process_vkDebugMarkerSetObjectTagEXT(
        VkResult                                    returnValue,
        VkDevice                                    device,
        const StructPointerDecoder<Decoded_VkDebugMarkerObjectTagInfoEXT>& pTagInfo) override;

    virtual void Process_vkDebugMarkerSetObjectNameEXT(
        VkResult                                    returnValue,
        VkDevice                                    device,
        const StructPointerDecoder<Decoded_VkDebugMarkerObjectNameInfoEXT>& pNameInfo) override;

    virtual void Process_vkCmdDebugMarkerBeginEXT(
        VkCommandBuffer                             commandBuffer,
        const StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT>& pMarkerInfo) override;

    virtual void Process_vkCmdDebugMarkerEndEXT(
        VkCommandBuffer                             commandBuffer) override;

    virtual void Process_vkCmdDebugMarkerInsertEXT(
        VkCommandBuffer                             commandBuffer,
        const StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT>& pMarkerInfo) override;

    virtual void Process_vkCmdDrawIndirectCountAMD(
        VkCommandBuffer                             commandBuffer,
        VkBuffer                                    buffer,
        VkDeviceSize                                offset,
        VkBuffer                                    countBuffer,
        VkDeviceSize                                countBufferOffset,
        uint32_t                                    maxDrawCount,
        uint32_t                                    stride) override;

    virtual void Process_vkCmdDrawIndexedIndirectCountAMD(
        VkCommandBuffer                             commandBuffer,
        VkBuffer                                    buffer,
        VkDeviceSize                                offset,
        VkBuffer                                    countBuffer,
        VkDeviceSize                                countBufferOffset,
        uint32_t                                    maxDrawCount,
        uint32_t                                    stride) override;

    virtual void Process_vkGetShaderInfoAMD(
        VkResult                                    returnValue,
        VkDevice                                    device,
        VkPipeline                                  pipeline,
        VkShaderStageFlagBits                       shaderStage,
        VkShaderInfoTypeAMD                         infoType,
        const PointerDecoder<size_t>&               pInfoSize,
        const PointerDecoder<uint8_t>&              pInfo) override;

    virtual void Process_vkGetPhysicalDeviceExternalImageFormatPropertiesNV(
        VkResult                                    returnValue,
        VkPhysicalDevice                            physicalDevice,
        VkFormat                                    format,
        VkImageType                                 type,
        VkImageTiling                               tiling,
        VkImageUsageFlags                           usage,
        VkImageCreateFlags                          flags,
        VkExternalMemoryHandleTypeFlagsNV           externalHandleType,
        const StructPointerDecoder<Decoded_VkExternalImageFormatPropertiesNV>& pExternalImageFormatProperties) override;

#ifdef VK_USE_PLATFORM_WIN32_KHR
    virtual void Process_vkGetMemoryWin32HandleNV(
        VkResult                                    returnValue,
        VkDevice                                    device,
        VkDeviceMemory                              memory,
        VkExternalMemoryHandleTypeFlagsNV           handleType,
        const PointerDecoder<HANDLE>&               pHandle) override;
#endif /* VK_USE_PLATFORM_WIN32_KHR */

#ifdef VK_USE_PLATFORM_VI_NN
    virtual void Process_vkCreateViSurfaceNN(
        VkResult                                    returnValue,
        VkInstance                                  instance,
        const StructPointerDecoder<Decoded_VkViSurfaceCreateInfoNN>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<VkSurfaceKHR>&         pSurface) override;
#endif /* VK_USE_PLATFORM_VI_NN */

    virtual void Process_vkCmdBeginConditionalRenderingEXT(
        VkCommandBuffer                             commandBuffer,
        const StructPointerDecoder<Decoded_VkConditionalRenderingBeginInfoEXT>& pConditionalRenderingBegin) override;

    virtual void Process_vkCmdEndConditionalRenderingEXT(
        VkCommandBuffer                             commandBuffer) override;

    virtual void Process_vkCmdProcessCommandsNVX(
        VkCommandBuffer                             commandBuffer,
        const StructPointerDecoder<Decoded_VkCmdProcessCommandsInfoNVX>& pProcessCommandsInfo) override;

    virtual void Process_vkCmdReserveSpaceForCommandsNVX(
        VkCommandBuffer                             commandBuffer,
        const StructPointerDecoder<Decoded_VkCmdReserveSpaceForCommandsInfoNVX>& pReserveSpaceInfo) override;

    virtual void Process_vkCreateIndirectCommandsLayoutNVX(
        VkResult                                    returnValue,
        VkDevice                                    device,
        const StructPointerDecoder<Decoded_VkIndirectCommandsLayoutCreateInfoNVX>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<VkIndirectCommandsLayoutNVX>& pIndirectCommandsLayout) override;

    virtual void Process_vkDestroyIndirectCommandsLayoutNVX(
        VkDevice                                    device,
        VkIndirectCommandsLayoutNVX                 indirectCommandsLayout,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) override;

    virtual void Process_vkCreateObjectTableNVX(
        VkResult                                    returnValue,
        VkDevice                                    device,
        const StructPointerDecoder<Decoded_VkObjectTableCreateInfoNVX>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<VkObjectTableNVX>&     pObjectTable) override;

    virtual void Process_vkDestroyObjectTableNVX(
        VkDevice                                    device,
        VkObjectTableNVX                            objectTable,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) override;

    virtual void Process_vkRegisterObjectsNVX(
        VkResult                                    returnValue,
        VkDevice                                    device,
        VkObjectTableNVX                            objectTable,
        uint32_t                                    objectCount,
        const StructPointerDecoder<Decoded_VkObjectTableEntryNVX>& ppObjectTableEntries,
        const PointerDecoder<uint32_t>&             pObjectIndices) override;

    virtual void Process_vkUnregisterObjectsNVX(
        VkResult                                    returnValue,
        VkDevice                                    device,
        VkObjectTableNVX                            objectTable,
        uint32_t                                    objectCount,
        const PointerDecoder<VkObjectEntryTypeNVX>& pObjectEntryTypes,
        const PointerDecoder<uint32_t>&             pObjectIndices) override;

    virtual void Process_vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX(
        VkPhysicalDevice                            physicalDevice,
        const StructPointerDecoder<Decoded_VkDeviceGeneratedCommandsFeaturesNVX>& pFeatures,
        const StructPointerDecoder<Decoded_VkDeviceGeneratedCommandsLimitsNVX>& pLimits) override;

    virtual void Process_vkCmdSetViewportWScalingNV(
        VkCommandBuffer                             commandBuffer,
        uint32_t                                    firstViewport,
        uint32_t                                    viewportCount,
        const StructPointerDecoder<Decoded_VkViewportWScalingNV>& pViewportWScalings) override;

    virtual void Process_vkReleaseDisplayEXT(
        VkResult                                    returnValue,
        VkPhysicalDevice                            physicalDevice,
        VkDisplayKHR                                display) override;

#ifdef VK_USE_PLATFORM_XLIB_XRANDR_EXT
    virtual void Process_vkAcquireXlibDisplayEXT(
        VkResult                                    returnValue,
        VkPhysicalDevice                            physicalDevice,
        const PointerDecoder<Display>&              dpy,
        VkDisplayKHR                                display) override;

    virtual void Process_vkGetRandROutputDisplayEXT(
        VkResult                                    returnValue,
        VkPhysicalDevice                            physicalDevice,
        const PointerDecoder<Display>&              dpy,
        RROutput                                    rrOutput,
        const PointerDecoder<VkDisplayKHR>&         pDisplay) override;
#endif /* VK_USE_PLATFORM_XLIB_XRANDR_EXT */

    virtual void Process_vkGetPhysicalDeviceSurfaceCapabilities2EXT(
        VkResult                                    returnValue,
        VkPhysicalDevice                            physicalDevice,
        VkSurfaceKHR                                surface,
        const StructPointerDecoder<Decoded_VkSurfaceCapabilities2EXT>& pSurfaceCapabilities) override;

    virtual void Process_vkDisplayPowerControlEXT(
        VkResult                                    returnValue,
        VkDevice                                    device,
        VkDisplayKHR                                display,
        const StructPointerDecoder<Decoded_VkDisplayPowerInfoEXT>& pDisplayPowerInfo) override;

    virtual void Process_vkRegisterDeviceEventEXT(
        VkResult                                    returnValue,
        VkDevice                                    device,
        const StructPointerDecoder<Decoded_VkDeviceEventInfoEXT>& pDeviceEventInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<VkFence>&              pFence) override;

    virtual void Process_vkRegisterDisplayEventEXT(
        VkResult                                    returnValue,
        VkDevice                                    device,
        VkDisplayKHR                                display,
        const StructPointerDecoder<Decoded_VkDisplayEventInfoEXT>& pDisplayEventInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<VkFence>&              pFence) override;

    virtual void Process_vkGetSwapchainCounterEXT(
        VkResult                                    returnValue,
        VkDevice                                    device,
        VkSwapchainKHR                              swapchain,
        VkSurfaceCounterFlagBitsEXT                 counter,
        const PointerDecoder<uint64_t>&             pCounterValue) override;

    virtual void Process_vkGetRefreshCycleDurationGOOGLE(
        VkResult                                    returnValue,
        VkDevice                                    device,
        VkSwapchainKHR                              swapchain,
        const StructPointerDecoder<Decoded_VkRefreshCycleDurationGOOGLE>& pDisplayTimingProperties) override;

    virtual void Process_vkGetPastPresentationTimingGOOGLE(
        VkResult                                    returnValue,
        VkDevice                                    device,
        VkSwapchainKHR                              swapchain,
        const PointerDecoder<uint32_t>&             pPresentationTimingCount,
        const StructPointerDecoder<Decoded_VkPastPresentationTimingGOOGLE>& pPresentationTimings) override;

    virtual void Process_vkCmdSetDiscardRectangleEXT(
        VkCommandBuffer                             commandBuffer,
        uint32_t                                    firstDiscardRectangle,
        uint32_t                                    discardRectangleCount,
        const StructPointerDecoder<Decoded_VkRect2D>& pDiscardRectangles) override;

    virtual void Process_vkSetHdrMetadataEXT(
        VkDevice                                    device,
        uint32_t                                    swapchainCount,
        const PointerDecoder<VkSwapchainKHR>&       pSwapchains,
        const StructPointerDecoder<Decoded_VkHdrMetadataEXT>& pMetadata) override;

#ifdef VK_USE_PLATFORM_IOS_MVK
    virtual void Process_vkCreateIOSSurfaceMVK(
        VkResult                                    returnValue,
        VkInstance                                  instance,
        const StructPointerDecoder<Decoded_VkIOSSurfaceCreateInfoMVK>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<VkSurfaceKHR>&         pSurface) override;
#endif /* VK_USE_PLATFORM_IOS_MVK */

#ifdef VK_USE_PLATFORM_MACOS_MVK
    virtual void Process_vkCreateMacOSSurfaceMVK(
        VkResult                                    returnValue,
        VkInstance                                  instance,
        const StructPointerDecoder<Decoded_VkMacOSSurfaceCreateInfoMVK>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<VkSurfaceKHR>&         pSurface) override;
#endif /* VK_USE_PLATFORM_MACOS_MVK */

    virtual void Process_vkSetDebugUtilsObjectNameEXT(
        VkResult                                    returnValue,
        VkDevice                                    device,
        const StructPointerDecoder<Decoded_VkDebugUtilsObjectNameInfoEXT>& pNameInfo) override;

    virtual void Process_vkSetDebugUtilsObjectTagEXT(
        VkResult                                    returnValue,
        VkDevice                                    device,
        const StructPointerDecoder<Decoded_VkDebugUtilsObjectTagInfoEXT>& pTagInfo) override;

    virtual void Process_vkQueueBeginDebugUtilsLabelEXT(
        VkQueue                                     queue,
        const StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>& pLabelInfo) override;

    virtual void Process_vkQueueEndDebugUtilsLabelEXT(
        VkQueue                                     queue) override;

    virtual void Process_vkQueueInsertDebugUtilsLabelEXT(
        VkQueue                                     queue,
        const StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>& pLabelInfo) override;

    virtual void Process_vkCmdBeginDebugUtilsLabelEXT(
        VkCommandBuffer                             commandBuffer,
        const StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>& pLabelInfo) override;

    virtual void Process_vkCmdEndDebugUtilsLabelEXT(
        VkCommandBuffer                             commandBuffer) override;

    virtual void Process_vkCmdInsertDebugUtilsLabelEXT(
        VkCommandBuffer                             commandBuffer,
        const StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>& pLabelInfo) override;

    virtual void Process_vkCreateDebugUtilsMessengerEXT(
        VkResult                                    returnValue,
        VkInstance                                  instance,
        const StructPointerDecoder<Decoded_VkDebugUtilsMessengerCreateInfoEXT>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<VkDebugUtilsMessengerEXT>& pMessenger) override;

    virtual void Process_vkDestroyDebugUtilsMessengerEXT(
        VkInstance                                  instance,
        VkDebugUtilsMessengerEXT                    messenger,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) override;

    virtual void Process_vkSubmitDebugUtilsMessageEXT(
        VkInstance                                  instance,
        VkDebugUtilsMessageSeverityFlagBitsEXT      messageSeverity,
        VkDebugUtilsMessageTypeFlagsEXT             messageTypes,
        const StructPointerDecoder<Decoded_VkDebugUtilsMessengerCallbackDataEXT>& pCallbackData) override;

#ifdef VK_USE_PLATFORM_ANDROID_KHR
    virtual void Process_vkGetAndroidHardwareBufferPropertiesANDROID(
        VkResult                                    returnValue,
        VkDevice                                    device,
        const PointerDecoder<AHardwareBuffer>&      buffer,
        const StructPointerDecoder<Decoded_VkAndroidHardwareBufferPropertiesANDROID>& pProperties) override;

    virtual void Process_vkGetMemoryAndroidHardwareBufferANDROID(
        VkResult                                    returnValue,
        VkDevice                                    device,
        const StructPointerDecoder<Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID>& pInfo,
        const PointerDecoder<AHardwareBuffer>&      pBuffer) override;
#endif /* VK_USE_PLATFORM_ANDROID_KHR */

    virtual void Process_vkCmdSetSampleLocationsEXT(
        VkCommandBuffer                             commandBuffer,
        const StructPointerDecoder<Decoded_VkSampleLocationsInfoEXT>& pSampleLocationsInfo) override;

    virtual void Process_vkGetPhysicalDeviceMultisamplePropertiesEXT(
        VkPhysicalDevice                            physicalDevice,
        VkSampleCountFlagBits                       samples,
        const StructPointerDecoder<Decoded_VkMultisamplePropertiesEXT>& pMultisampleProperties) override;

    virtual void Process_vkCreateValidationCacheEXT(
        VkResult                                    returnValue,
        VkDevice                                    device,
        const StructPointerDecoder<Decoded_VkValidationCacheCreateInfoEXT>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        const PointerDecoder<VkValidationCacheEXT>& pValidationCache) override;

    virtual void Process_vkDestroyValidationCacheEXT(
        VkDevice                                    device,
        VkValidationCacheEXT                        validationCache,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) override;

    virtual void Process_vkMergeValidationCachesEXT(
        VkResult                                    returnValue,
        VkDevice                                    device,
        VkValidationCacheEXT                        dstCache,
        uint32_t                                    srcCacheCount,
        const PointerDecoder<VkValidationCacheEXT>& pSrcCaches) override;

    virtual void Process_vkGetValidationCacheDataEXT(
        VkResult                                    returnValue,
        VkDevice                                    device,
        VkValidationCacheEXT                        validationCache,
        const PointerDecoder<size_t>&               pDataSize,
        const PointerDecoder<uint8_t>&              pData) override;

    virtual void Process_vkGetMemoryHostPointerPropertiesEXT(
        VkResult                                    returnValue,
        VkDevice                                    device,
        VkExternalMemoryHandleTypeFlagBits          handleType,
        uint64_t                                    pHostPointer,
        const StructPointerDecoder<Decoded_VkMemoryHostPointerPropertiesEXT>& pMemoryHostPointerProperties) override;

    virtual void Process_vkCmdWriteBufferMarkerAMD(
        VkCommandBuffer                             commandBuffer,
        VkPipelineStageFlagBits                     pipelineStage,
        VkBuffer                                    dstBuffer,
        VkDeviceSize                                dstOffset,
        uint32_t                                    marker) override;
