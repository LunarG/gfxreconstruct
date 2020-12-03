/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2020 LunarG, Inc.
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

#ifndef GFXRECON_ENCODE_CUSTOM_VULKAN_API_CALL_ENCODERS_H
#define GFXRECON_ENCODE_CUSTOM_VULKAN_API_CALL_ENCODERS_H

#include "util/defines.h"

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

VKAPI_ATTR void VKAPI_CALL UpdateDescriptorSetWithTemplateKHR(VkDevice                   device,
                                                              VkDescriptorSet            descriptorSet,
                                                              VkDescriptorUpdateTemplate descriptorUpdateTemplate,
                                                              const void*                pData);

VKAPI_ATTR void VKAPI_CALL
CmdBuildAccelerationStructuresKHR(VkCommandBuffer                                        commandBuffer,
                                  uint32_t                                               infoCount,
                                  const VkAccelerationStructureBuildGeometryInfoKHR*     pInfos,
                                  const VkAccelerationStructureBuildRangeInfoKHR* const* ppRangeInfos);

VKAPI_ATTR void VKAPI_CALL
CmdBuildAccelerationStructuresIndirectKHR(VkCommandBuffer                                    commandBuffer,
                                          uint32_t                                           infoCount,
                                          const VkAccelerationStructureBuildGeometryInfoKHR* pInfos,
                                          const VkDeviceAddress*                             pIndirectDeviceAddresses,
                                          const uint32_t*                                    pIndirectStrides,
                                          const uint32_t* const*                             ppMaxPrimitiveCounts);

VKAPI_ATTR VkResult VKAPI_CALL
BuildAccelerationStructuresKHR(VkDevice                                               device,
                               VkDeferredOperationKHR                                 deferredOperation,
                               uint32_t                                               infoCount,
                               const VkAccelerationStructureBuildGeometryInfoKHR*     pInfos,
                               const VkAccelerationStructureBuildRangeInfoKHR* const* ppRangeInfos);

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_CUSTOM_VULKAN_API_CALL_ENCODERS_H
