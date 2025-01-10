/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2020 LunarG, Inc.
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

#ifndef GFXRECON_ENCODE_CUSTOM_VULKAN_API_CALL_ENCODERS_H
#define GFXRECON_ENCODE_CUSTOM_VULKAN_API_CALL_ENCODERS_H

#include "util/defines.h"
#include "format/format.h"

#include "vulkan/vulkan.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

VKAPI_ATTR void VKAPI_CALL vkUpdateDescriptorSetWithTemplate(VkDevice                   device,
                                                             VkDescriptorSet            descriptorSet,
                                                             VkDescriptorUpdateTemplate descriptorUpdateTemplate,
                                                             const void*                pData);

VKAPI_ATTR void VKAPI_CALL vkCmdPushDescriptorSetWithTemplate(VkCommandBuffer            commandBuffer,
                                                              VkDescriptorUpdateTemplate descriptorUpdateTemplate,
                                                              VkPipelineLayout           layout,
                                                              uint32_t                   set,
                                                              const void*                pData);

VKAPI_ATTR void VKAPI_CALL vkCmdPushDescriptorSetWithTemplateKHR(VkCommandBuffer            commandBuffer,
                                                                 VkDescriptorUpdateTemplate descriptorUpdateTemplate,
                                                                 VkPipelineLayout           layout,
                                                                 uint32_t                   set,
                                                                 const void*                pData);

VKAPI_ATTR void VKAPI_CALL vkCmdPushDescriptorSetWithTemplate2(
    VkCommandBuffer commandBuffer, const VkPushDescriptorSetWithTemplateInfo* pPushDescriptorSetWithTemplateInfo);

VKAPI_ATTR void VKAPI_CALL vkCmdPushDescriptorSetWithTemplate2KHR(
    VkCommandBuffer commandBuffer, const VkPushDescriptorSetWithTemplateInfoKHR* pPushDescriptorSetWithTemplateInfo);

VKAPI_ATTR void VKAPI_CALL vkUpdateDescriptorSetWithTemplateKHR(VkDevice                   device,
                                                                VkDescriptorSet            descriptorSet,
                                                                VkDescriptorUpdateTemplate descriptorUpdateTemplate,
                                                                const void*                pData);

VKAPI_ATTR VkResult VKAPI_CALL
vkBuildAccelerationStructuresKHR(VkDevice                                               device,
                                 VkDeferredOperationKHR                                 deferredOperation,
                                 uint32_t                                               infoCount,
                                 const VkAccelerationStructureBuildGeometryInfoKHR*     pInfos,
                                 const VkAccelerationStructureBuildRangeInfoKHR* const* ppRangeInfos);

VKAPI_ATTR VkResult VKAPI_CALL vkCopyAccelerationStructureKHR(VkDevice               device,
                                                              VkDeferredOperationKHR deferredOperation,
                                                              const VkCopyAccelerationStructureInfoKHR* pInfo);

VKAPI_ATTR uint64_t VKAPI_CALL vkGetBlockIndexGFXR();

VKAPI_ATTR void VKAPI_CALL vkDumpAssetsGFXR();

VKAPI_ATTR VkResult VKAPI_CALL vkCreateGraphicsPipelines(VkDevice                            device,
                                                         VkPipelineCache                     pipelineCache,
                                                         uint32_t                            createInfoCount,
                                                         const VkGraphicsPipelineCreateInfo* pCreateInfos,
                                                         const VkAllocationCallbacks*        pAllocator,
                                                         VkPipeline*                         pPipelines);

VKAPI_ATTR VkResult VKAPI_CALL vkCreateComputePipelines(VkDevice                           device,
                                                        VkPipelineCache                    pipelineCache,
                                                        uint32_t                           createInfoCount,
                                                        const VkComputePipelineCreateInfo* pCreateInfos,
                                                        const VkAllocationCallbacks*       pAllocator,
                                                        VkPipeline*                        pPipelines);

VKAPI_ATTR VkResult VKAPI_CALL vkCreateRayTracingPipelinesNV(VkDevice                                device,
                                                             VkPipelineCache                         pipelineCache,
                                                             uint32_t                                createInfoCount,
                                                             const VkRayTracingPipelineCreateInfoNV* pCreateInfos,
                                                             const VkAllocationCallbacks*            pAllocator,
                                                             VkPipeline*                             pPipelines);

VKAPI_ATTR VkResult VKAPI_CALL vkCreateRayTracingPipelinesKHR(VkDevice               device,
                                                              VkDeferredOperationKHR deferredOperation,
                                                              VkPipelineCache        pipelineCache,
                                                              uint32_t               createInfoCount,
                                                              const VkRayTracingPipelineCreateInfoKHR* pCreateInfos,
                                                              const VkAllocationCallbacks*             pAllocator,
                                                              VkPipeline*                              pPipelines);

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_CUSTOM_VULKAN_API_CALL_ENCODERS_H
