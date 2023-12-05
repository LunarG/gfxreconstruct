//
// Copyright (c) 2021 Samsung
// Copyright (c) 2023 Google
// Copyright (c) 2023 LunarG, Inc
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef GFXRECON_DECODE_VULKAN_CPP_STRUCTS_H
#define GFXRECON_DECODE_VULKAN_CPP_STRUCTS_H

#include "vulkan_cpp_consumer_base.h"
#include "custom_vulkan_struct_decoders.h"

#include "vulkan/vulkan.h"

#include <util/defines.h>
#include <iostream>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

std::string GenerateStruct_VkMemoryAllocateInfo(std::ostream&                 out,
                                                format::HandleId              memoryHandleId,
                                                const VkMemoryAllocateInfo*   structInfo,
                                                Decoded_VkMemoryAllocateInfo* metainfo,
                                                VulkanCppConsumerBase&        consumer);

std::string GenerateStruct_VkClearColorValue(std::ostream&              out,
                                             const VkClearColorValue*   structInfo,
                                             Decoded_VkClearColorValue* metaInfo,
                                             VulkanCppConsumerBase&     consumer);

std::string GenerateStruct_VkWriteDescriptorSet(std::ostream&                 out,
                                                const VkWriteDescriptorSet*   structInfo,
                                                Decoded_VkWriteDescriptorSet* metaInfo,
                                                VulkanCppConsumerBase&        consumer);

std::string GenerateStruct_VkPresentInfoKHR(std::ostream&             out,
                                            const VkPresentInfoKHR*   structInfo,
                                            Decoded_VkPresentInfoKHR* metainfo,
                                            VulkanCppConsumerBase&    consumer);

std::string
GenerateStruct_VkDescriptorUpdateTemplateCreateInfoKHR(std::ostream&                                 out,
                                                       const VkDescriptorUpdateTemplateCreateInfo*   structInfo,
                                                       Decoded_VkDescriptorUpdateTemplateCreateInfo* metainfo,
                                                       VulkanCppConsumerBase&                        consumer,
                                                       const std::string& structTypeSuffix = "KHR");

std::string GenerateStruct_VkDescriptorImageInfo(std::ostream&                   out,
                                                 VkDescriptorUpdateTemplateEntry templateEntry,
                                                 const VkDescriptorImageInfo*    structInfo,
                                                 Decoded_VkDescriptorImageInfo*  metaInfo,
                                                 VulkanCppConsumerBase&          consumer);

std::string GenerateStruct_VkDescriptorUpdateTemplateEntry(std::ostream&                            out,
                                                           const VkDescriptorUpdateTemplateEntry*   structInfo,
                                                           Decoded_VkDescriptorUpdateTemplateEntry* metainfo,
                                                           VulkanCppConsumerBase&                   consumer);

std::string
GenerateStruct_VkAccelerationStructureMotionInstanceNV(std::ostream&                                    out,
                                                       const VkAccelerationStructureMotionInstanceNV*   structInfo,
                                                       Decoded_VkAccelerationStructureMotionInstanceNV* metainfo,
                                                       VulkanCppConsumerBase&                           consumer);

std::string GenerateStruct_VkAccelerationStructureGeometryKHR(std::ostream&                               out,
                                                              const VkAccelerationStructureGeometryKHR*   structInfo,
                                                              Decoded_VkAccelerationStructureGeometryKHR* metainfo,
                                                              VulkanCppConsumerBase&                      consumer);

std::string GenerateStruct_VkDebugUtilsMessengerCreateInfoEXT(std::ostream&                               out,
                                                              const VkDebugUtilsMessengerCreateInfoEXT*   structInfo,
                                                              Decoded_VkDebugUtilsMessengerCreateInfoEXT* metainfo,
                                                              VulkanCppConsumerBase&                      consumer);

std::string GenerateStruct_VkPerformanceValueINTEL(std::ostream&                    out,
                                                   const VkPerformanceValueINTEL*   structInfo,
                                                   Decoded_VkPerformanceValueINTEL* metainfo,
                                                   VulkanCppConsumerBase&           consumer);

std::string
GenerateStruct_VkImportAndroidHardwareBufferInfoANDROID(std::ostream&                                     out,
                                                        const VkImportAndroidHardwareBufferInfoANDROID*   structInfo,
                                                        Decoded_VkImportAndroidHardwareBufferInfoANDROID* metaInfo,
                                                        VulkanCppConsumerBase&                            consumer);

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)

#endif // GFXRECON_DECODE_VULKAN_CPP_STRUCTS_H
