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

#include "format/platform_types.h"
#include "util/defines.h"
#include "format/format.h"

#include "vulkan/vulkan.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

VKAPI_ATTR void VKAPI_CALL UpdateDescriptorSetWithTemplate(VkDevice                   device,
                                                           VkDescriptorSet            descriptorSet,
                                                           VkDescriptorUpdateTemplate descriptorUpdateTemplate,
                                                           const void*                pData);

VKAPI_ATTR void VKAPI_CALL CmdPushDescriptorSetWithTemplateKHR(VkCommandBuffer            commandBuffer,
                                                               VkDescriptorUpdateTemplate descriptorUpdateTemplate,
                                                               VkPipelineLayout           layout,
                                                               uint32_t                   set,
                                                               const void*                pData);

VKAPI_ATTR void VKAPI_CALL CmdPushDescriptorSetWithTemplate2KHR(
    VkCommandBuffer commandBuffer, const VkPushDescriptorSetWithTemplateInfoKHR* pPushDescriptorSetWithTemplateInfo);

VKAPI_ATTR void VKAPI_CALL UpdateDescriptorSetWithTemplateKHR(VkDevice                   device,
                                                              VkDescriptorSet            descriptorSet,
                                                              VkDescriptorUpdateTemplate descriptorUpdateTemplate,
                                                              const void*                pData);

VKAPI_ATTR VkResult VKAPI_CALL
BuildAccelerationStructuresKHR(VkDevice                                               device,
                               VkDeferredOperationKHR                                 deferredOperation,
                               uint32_t                                               infoCount,
                               const VkAccelerationStructureBuildGeometryInfoKHR*     pInfos,
                               const VkAccelerationStructureBuildRangeInfoKHR* const* ppRangeInfos);

VKAPI_ATTR VkResult VKAPI_CALL CopyAccelerationStructureKHR(VkDevice                                  device,
                                                            VkDeferredOperationKHR                    deferredOperation,
                                                            const VkCopyAccelerationStructureInfoKHR* pInfo);

VKAPI_ATTR uint64_t VKAPI_CALL GetBlockIndexGFXR();

VKAPI_ATTR VkResult VKAPI_CALL CreateGraphicsPipelines(VkDevice                            device,
                                                       VkPipelineCache                     pipelineCache,
                                                       uint32_t                            createInfoCount,
                                                       const VkGraphicsPipelineCreateInfo* pCreateInfos,
                                                       const VkAllocationCallbacks*        pAllocator,
                                                       VkPipeline*                         pPipelines);

VKAPI_ATTR VkResult VKAPI_CALL CreateComputePipelines(VkDevice                           device,
                                                      VkPipelineCache                    pipelineCache,
                                                      uint32_t                           createInfoCount,
                                                      const VkComputePipelineCreateInfo* pCreateInfos,
                                                      const VkAllocationCallbacks*       pAllocator,
                                                      VkPipeline*                        pPipelines);

VKAPI_ATTR VkResult VKAPI_CALL CreateRayTracingPipelinesNV(VkDevice                                device,
                                                           VkPipelineCache                         pipelineCache,
                                                           uint32_t                                createInfoCount,
                                                           const VkRayTracingPipelineCreateInfoNV* pCreateInfos,
                                                           const VkAllocationCallbacks*            pAllocator,
                                                           VkPipeline*                             pPipelines);

VKAPI_ATTR VkResult VKAPI_CALL CreateRayTracingPipelinesKHR(VkDevice                                 device,
                                                            VkDeferredOperationKHR                   deferredOperation,
                                                            VkPipelineCache                          pipelineCache,
                                                            uint32_t                                 createInfoCount,
                                                            const VkRayTracingPipelineCreateInfoKHR* pCreateInfos,
                                                            const VkAllocationCallbacks*             pAllocator,
                                                            VkPipeline*                              pPipelines);

VKAPI_ATTR VkResult VKAPI_CALL CreateFence(VkDevice                     device,
                                           const VkFenceCreateInfo*     pCreateInfo,
                                           const VkAllocationCallbacks* pAllocator,
                                           VkFence*                     pFence);

VKAPI_ATTR void VKAPI_CALL DestroyFence(VkDevice device, VkFence fence, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR VkResult VKAPI_CALL ResetFences(VkDevice device, uint32_t fenceCount, const VkFence* pFences);

VKAPI_ATTR VkResult VKAPI_CALL GetFenceStatus(VkDevice device, VkFence fence);

VKAPI_ATTR VkResult VKAPI_CALL
WaitForFences(VkDevice device, uint32_t fenceCount, const VkFence* pFences, VkBool32 waitAll, uint64_t timeout);

VKAPI_ATTR VkResult VKAPI_CALL
ImportFenceWin32HandleKHR(VkDevice device, const VkImportFenceWin32HandleInfoKHR* pImportFenceWin32HandleInfo);

VKAPI_ATTR VkResult VKAPI_CALL ImportFenceFdKHR(VkDevice device, const VkImportFenceFdInfoKHR* pImportFenceFdInfo);

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_CUSTOM_VULKAN_API_CALL_ENCODERS_H
