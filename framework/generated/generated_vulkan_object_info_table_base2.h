/*
** Copyright (c) 2018-2023 Valve Corporation
** Copyright (c) 2018-2023 LunarG, Inc.
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

#ifndef  GFXRECON_GENERATED_VULKAN_OBJECT_INFO_TABLE_BASE2_H
#define  GFXRECON_GENERATED_VULKAN_OBJECT_INFO_TABLE_BASE2_H

#include "decode/vulkan_object_info_table_base.h"


GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class VulkanObjectInfoTableBase2 : VulkanObjectInfoTableBase
{
  public:
    VulkanObjectInfoTableBase2() {}
    ~VulkanObjectInfoTableBase2() {}

    void AddVkAccelerationStructureKHRInfo(VulkanAccelerationStructureKHRInfo&& info) { AddVkObjectInfo(std::move(info), &accelerationStructureKHR_map_); }
    void AddVkAccelerationStructureNVInfo(VulkanAccelerationStructureNVInfo&& info) { AddVkObjectInfo(std::move(info), &accelerationStructureNV_map_); }
    void AddVkBufferInfo(VulkanBufferInfo&& info) { AddVkObjectInfo(std::move(info), &buffer_map_); }
    void AddVkBufferViewInfo(VulkanBufferViewInfo&& info) { AddVkObjectInfo(std::move(info), &bufferView_map_); }
    void AddVkCommandBufferInfo(VulkanCommandBufferInfo&& info) { AddVkObjectInfo(std::move(info), &commandBuffer_map_); }
    void AddVkCommandPoolInfo(VulkanCommandPoolInfo&& info) { AddVkObjectInfo(std::move(info), &commandPool_map_); }
    void AddVkDebugReportCallbackEXTInfo(VulkanDebugReportCallbackEXTInfo&& info) { AddVkObjectInfo(std::move(info), &debugReportCallbackEXT_map_); }
    void AddVkDebugUtilsMessengerEXTInfo(VulkanDebugUtilsMessengerEXTInfo&& info) { AddVkObjectInfo(std::move(info), &debugUtilsMessengerEXT_map_); }
    void AddVkDeferredOperationKHRInfo(VulkanDeferredOperationKHRInfo&& info) { AddVkObjectInfo(std::move(info), &deferredOperationKHR_map_); }
    void AddVkDescriptorPoolInfo(VulkanDescriptorPoolInfo&& info) { AddVkObjectInfo(std::move(info), &descriptorPool_map_); }
    void AddVkDescriptorSetInfo(VulkanDescriptorSetInfo&& info) { AddVkObjectInfo(std::move(info), &descriptorSet_map_); }
    void AddVkDescriptorSetLayoutInfo(VulkanDescriptorSetLayoutInfo&& info) { AddVkObjectInfo(std::move(info), &descriptorSetLayout_map_); }
    void AddVkDescriptorUpdateTemplateInfo(VulkanDescriptorUpdateTemplateInfo&& info) { AddVkObjectInfo(std::move(info), &descriptorUpdateTemplate_map_); }
    void AddVkDeviceInfo(VulkanDeviceInfo&& info) { AddVkObjectInfo(std::move(info), &device_map_); }
    void AddVkDeviceMemoryInfo(VulkanDeviceMemoryInfo&& info) { AddVkObjectInfo(std::move(info), &deviceMemory_map_); }
    void AddVkDisplayKHRInfo(VulkanDisplayKHRInfo&& info) { AddVkObjectInfo(std::move(info), &displayKHR_map_); }
    void AddVkDisplayModeKHRInfo(VulkanDisplayModeKHRInfo&& info) { AddVkObjectInfo(std::move(info), &displayModeKHR_map_); }
    void AddVkEventInfo(VulkanEventInfo&& info) { AddVkObjectInfo(std::move(info), &event_map_); }
    void AddVkFenceInfo(VulkanFenceInfo&& info) { AddVkObjectInfo(std::move(info), &fence_map_); }
    void AddVkFramebufferInfo(VulkanFramebufferInfo&& info) { AddVkObjectInfo(std::move(info), &framebuffer_map_); }
    void AddVkImageInfo(VulkanImageInfo&& info) { AddVkObjectInfo(std::move(info), &image_map_); }
    void AddVkImageViewInfo(VulkanImageViewInfo&& info) { AddVkObjectInfo(std::move(info), &imageView_map_); }
    void AddVkIndirectCommandsLayoutNVInfo(VulkanIndirectCommandsLayoutNVInfo&& info) { AddVkObjectInfo(std::move(info), &indirectCommandsLayoutNV_map_); }
    void AddVkInstanceInfo(VulkanInstanceInfo&& info) { AddVkObjectInfo(std::move(info), &instance_map_); }
    void AddVkMicromapEXTInfo(VulkanMicromapEXTInfo&& info) { AddVkObjectInfo(std::move(info), &micromapEXT_map_); }
    void AddVkOpticalFlowSessionNVInfo(VulkanOpticalFlowSessionNVInfo&& info) { AddVkObjectInfo(std::move(info), &opticalFlowSessionNV_map_); }
    void AddVkPerformanceConfigurationINTELInfo(VulkanPerformanceConfigurationINTELInfo&& info) { AddVkObjectInfo(std::move(info), &performanceConfigurationINTEL_map_); }
    void AddVkPhysicalDeviceInfo(VulkanPhysicalDeviceInfo&& info) { AddVkObjectInfo(std::move(info), &physicalDevice_map_); }
    void AddVkPipelineInfo(VulkanPipelineInfo&& info) { AddVkObjectInfo(std::move(info), &pipeline_map_); }
    void AddVkPipelineCacheInfo(VulkanPipelineCacheInfo&& info) { AddVkObjectInfo(std::move(info), &pipelineCache_map_); }
    void AddVkPipelineLayoutInfo(VulkanPipelineLayoutInfo&& info) { AddVkObjectInfo(std::move(info), &pipelineLayout_map_); }
    void AddVkPrivateDataSlotInfo(VulkanPrivateDataSlotInfo&& info) { AddVkObjectInfo(std::move(info), &privateDataSlot_map_); }
    void AddVkQueryPoolInfo(VulkanQueryPoolInfo&& info) { AddVkObjectInfo(std::move(info), &queryPool_map_); }
    void AddVkQueueInfo(VulkanQueueInfo&& info) { AddVkObjectInfo(std::move(info), &queue_map_); }
    void AddVkRenderPassInfo(VulkanRenderPassInfo&& info) { AddVkObjectInfo(std::move(info), &renderPass_map_); }
    void AddVkSamplerInfo(VulkanSamplerInfo&& info) { AddVkObjectInfo(std::move(info), &sampler_map_); }
    void AddVkSamplerYcbcrConversionInfo(VulkanSamplerYcbcrConversionInfo&& info) { AddVkObjectInfo(std::move(info), &samplerYcbcrConversion_map_); }
    void AddVkSemaphoreInfo(VulkanSemaphoreInfo&& info) { AddVkObjectInfo(std::move(info), &semaphore_map_); }
    void AddVkShaderEXTInfo(VulkanShaderEXTInfo&& info) { AddVkObjectInfo(std::move(info), &shaderEXT_map_); }
    void AddVkShaderModuleInfo(VulkanShaderModuleInfo&& info) { AddVkObjectInfo(std::move(info), &shaderModule_map_); }
    void AddVkSurfaceKHRInfo(VulkanSurfaceKHRInfo&& info) { AddVkObjectInfo(std::move(info), &surfaceKHR_map_); }
    void AddVkSwapchainKHRInfo(VulkanSwapchainKHRInfo&& info) { AddVkObjectInfo(std::move(info), &swapchainKHR_map_); }
    void AddVkValidationCacheEXTInfo(VulkanValidationCacheEXTInfo&& info) { AddVkObjectInfo(std::move(info), &validationCacheEXT_map_); }
    void AddVkVideoSessionKHRInfo(VulkanVideoSessionKHRInfo&& info) { AddVkObjectInfo(std::move(info), &videoSessionKHR_map_); }
    void AddVkVideoSessionParametersKHRInfo(VulkanVideoSessionParametersKHRInfo&& info) { AddVkObjectInfo(std::move(info), &videoSessionParametersKHR_map_); }

    void RemoveVkAccelerationStructureKHRInfo(format::HandleId id) { accelerationStructureKHR_map_.erase(id); }
    void RemoveVkAccelerationStructureNVInfo(format::HandleId id) { accelerationStructureNV_map_.erase(id); }
    void RemoveVkBufferInfo(format::HandleId id) { buffer_map_.erase(id); }
    void RemoveVkBufferViewInfo(format::HandleId id) { bufferView_map_.erase(id); }
    void RemoveVkCommandBufferInfo(format::HandleId id) { commandBuffer_map_.erase(id); }
    void RemoveVkCommandPoolInfo(format::HandleId id) { commandPool_map_.erase(id); }
    void RemoveVkDebugReportCallbackEXTInfo(format::HandleId id) { debugReportCallbackEXT_map_.erase(id); }
    void RemoveVkDebugUtilsMessengerEXTInfo(format::HandleId id) { debugUtilsMessengerEXT_map_.erase(id); }
    void RemoveVkDeferredOperationKHRInfo(format::HandleId id) { deferredOperationKHR_map_.erase(id); }
    void RemoveVkDescriptorPoolInfo(format::HandleId id) { descriptorPool_map_.erase(id); }
    void RemoveVkDescriptorSetInfo(format::HandleId id) { descriptorSet_map_.erase(id); }
    void RemoveVkDescriptorSetLayoutInfo(format::HandleId id) { descriptorSetLayout_map_.erase(id); }
    void RemoveVkDescriptorUpdateTemplateInfo(format::HandleId id) { descriptorUpdateTemplate_map_.erase(id); }
    void RemoveVkDeviceInfo(format::HandleId id) { device_map_.erase(id); }
    void RemoveVkDeviceMemoryInfo(format::HandleId id) { deviceMemory_map_.erase(id); }
    void RemoveVkDisplayKHRInfo(format::HandleId id) { displayKHR_map_.erase(id); }
    void RemoveVkDisplayModeKHRInfo(format::HandleId id) { displayModeKHR_map_.erase(id); }
    void RemoveVkEventInfo(format::HandleId id) { event_map_.erase(id); }
    void RemoveVkFenceInfo(format::HandleId id) { fence_map_.erase(id); }
    void RemoveVkFramebufferInfo(format::HandleId id) { framebuffer_map_.erase(id); }
    void RemoveVkImageInfo(format::HandleId id) { image_map_.erase(id); }
    void RemoveVkImageViewInfo(format::HandleId id) { imageView_map_.erase(id); }
    void RemoveVkIndirectCommandsLayoutNVInfo(format::HandleId id) { indirectCommandsLayoutNV_map_.erase(id); }
    void RemoveVkInstanceInfo(format::HandleId id) { instance_map_.erase(id); }
    void RemoveVkMicromapEXTInfo(format::HandleId id) { micromapEXT_map_.erase(id); }
    void RemoveVkOpticalFlowSessionNVInfo(format::HandleId id) { opticalFlowSessionNV_map_.erase(id); }
    void RemoveVkPerformanceConfigurationINTELInfo(format::HandleId id) { performanceConfigurationINTEL_map_.erase(id); }
    void RemoveVkPhysicalDeviceInfo(format::HandleId id) { physicalDevice_map_.erase(id); }
    void RemoveVkPipelineInfo(format::HandleId id) { pipeline_map_.erase(id); }
    void RemoveVkPipelineCacheInfo(format::HandleId id) { pipelineCache_map_.erase(id); }
    void RemoveVkPipelineLayoutInfo(format::HandleId id) { pipelineLayout_map_.erase(id); }
    void RemoveVkPrivateDataSlotInfo(format::HandleId id) { privateDataSlot_map_.erase(id); }
    void RemoveVkQueryPoolInfo(format::HandleId id) { queryPool_map_.erase(id); }
    void RemoveVkQueueInfo(format::HandleId id) { queue_map_.erase(id); }
    void RemoveVkRenderPassInfo(format::HandleId id) { renderPass_map_.erase(id); }
    void RemoveVkSamplerInfo(format::HandleId id) { sampler_map_.erase(id); }
    void RemoveVkSamplerYcbcrConversionInfo(format::HandleId id) { samplerYcbcrConversion_map_.erase(id); }
    void RemoveVkSemaphoreInfo(format::HandleId id) { semaphore_map_.erase(id); }
    void RemoveVkShaderEXTInfo(format::HandleId id) { shaderEXT_map_.erase(id); }
    void RemoveVkShaderModuleInfo(format::HandleId id) { shaderModule_map_.erase(id); }
    void RemoveVkSurfaceKHRInfo(format::HandleId id) { surfaceKHR_map_.erase(id); }
    void RemoveVkSwapchainKHRInfo(format::HandleId id) { swapchainKHR_map_.erase(id); }
    void RemoveVkValidationCacheEXTInfo(format::HandleId id) { validationCacheEXT_map_.erase(id); }
    void RemoveVkVideoSessionKHRInfo(format::HandleId id) { videoSessionKHR_map_.erase(id); }
    void RemoveVkVideoSessionParametersKHRInfo(format::HandleId id) { videoSessionParametersKHR_map_.erase(id); }

    const VulkanAccelerationStructureKHRInfo* GetVkAccelerationStructureKHRInfo(format::HandleId id) const { return GetVkObjectInfo<VulkanAccelerationStructureKHRInfo>(id, &accelerationStructureKHR_map_); }
    const VulkanAccelerationStructureNVInfo* GetVkAccelerationStructureNVInfo(format::HandleId id) const { return GetVkObjectInfo<VulkanAccelerationStructureNVInfo>(id, &accelerationStructureNV_map_); }
    const VulkanBufferInfo* GetVkBufferInfo(format::HandleId id) const { return GetVkObjectInfo<VulkanBufferInfo>(id, &buffer_map_); }
    const VulkanBufferViewInfo* GetVkBufferViewInfo(format::HandleId id) const { return GetVkObjectInfo<VulkanBufferViewInfo>(id, &bufferView_map_); }
    const VulkanCommandBufferInfo* GetVkCommandBufferInfo(format::HandleId id) const { return GetVkObjectInfo<VulkanCommandBufferInfo>(id, &commandBuffer_map_); }
    const VulkanCommandPoolInfo* GetVkCommandPoolInfo(format::HandleId id) const { return GetVkObjectInfo<VulkanCommandPoolInfo>(id, &commandPool_map_); }
    const VulkanDebugReportCallbackEXTInfo* GetVkDebugReportCallbackEXTInfo(format::HandleId id) const { return GetVkObjectInfo<VulkanDebugReportCallbackEXTInfo>(id, &debugReportCallbackEXT_map_); }
    const VulkanDebugUtilsMessengerEXTInfo* GetVkDebugUtilsMessengerEXTInfo(format::HandleId id) const { return GetVkObjectInfo<VulkanDebugUtilsMessengerEXTInfo>(id, &debugUtilsMessengerEXT_map_); }
    const VulkanDeferredOperationKHRInfo* GetVkDeferredOperationKHRInfo(format::HandleId id) const { return GetVkObjectInfo<VulkanDeferredOperationKHRInfo>(id, &deferredOperationKHR_map_); }
    const VulkanDescriptorPoolInfo* GetVkDescriptorPoolInfo(format::HandleId id) const { return GetVkObjectInfo<VulkanDescriptorPoolInfo>(id, &descriptorPool_map_); }
    const VulkanDescriptorSetInfo* GetVkDescriptorSetInfo(format::HandleId id) const { return GetVkObjectInfo<VulkanDescriptorSetInfo>(id, &descriptorSet_map_); }
    const VulkanDescriptorSetLayoutInfo* GetVkDescriptorSetLayoutInfo(format::HandleId id) const { return GetVkObjectInfo<VulkanDescriptorSetLayoutInfo>(id, &descriptorSetLayout_map_); }
    const VulkanDescriptorUpdateTemplateInfo* GetVkDescriptorUpdateTemplateInfo(format::HandleId id) const { return GetVkObjectInfo<VulkanDescriptorUpdateTemplateInfo>(id, &descriptorUpdateTemplate_map_); }
    const VulkanDeviceInfo* GetVkDeviceInfo(format::HandleId id) const { return GetVkObjectInfo<VulkanDeviceInfo>(id, &device_map_); }
    const VulkanDeviceMemoryInfo* GetVkDeviceMemoryInfo(format::HandleId id) const { return GetVkObjectInfo<VulkanDeviceMemoryInfo>(id, &deviceMemory_map_); }
    const VulkanDisplayKHRInfo* GetVkDisplayKHRInfo(format::HandleId id) const { return GetVkObjectInfo<VulkanDisplayKHRInfo>(id, &displayKHR_map_); }
    const VulkanDisplayModeKHRInfo* GetVkDisplayModeKHRInfo(format::HandleId id) const { return GetVkObjectInfo<VulkanDisplayModeKHRInfo>(id, &displayModeKHR_map_); }
    const VulkanEventInfo* GetVkEventInfo(format::HandleId id) const { return GetVkObjectInfo<VulkanEventInfo>(id, &event_map_); }
    const VulkanFenceInfo* GetVkFenceInfo(format::HandleId id) const { return GetVkObjectInfo<VulkanFenceInfo>(id, &fence_map_); }
    const VulkanFramebufferInfo* GetVkFramebufferInfo(format::HandleId id) const { return GetVkObjectInfo<VulkanFramebufferInfo>(id, &framebuffer_map_); }
    const VulkanImageInfo* GetVkImageInfo(format::HandleId id) const { return GetVkObjectInfo<VulkanImageInfo>(id, &image_map_); }
    const VulkanImageViewInfo* GetVkImageViewInfo(format::HandleId id) const { return GetVkObjectInfo<VulkanImageViewInfo>(id, &imageView_map_); }
    const VulkanIndirectCommandsLayoutNVInfo* GetVkIndirectCommandsLayoutNVInfo(format::HandleId id) const { return GetVkObjectInfo<VulkanIndirectCommandsLayoutNVInfo>(id, &indirectCommandsLayoutNV_map_); }
    const VulkanInstanceInfo* GetVkInstanceInfo(format::HandleId id) const { return GetVkObjectInfo<VulkanInstanceInfo>(id, &instance_map_); }
    const VulkanMicromapEXTInfo* GetVkMicromapEXTInfo(format::HandleId id) const { return GetVkObjectInfo<VulkanMicromapEXTInfo>(id, &micromapEXT_map_); }
    const VulkanOpticalFlowSessionNVInfo* GetVkOpticalFlowSessionNVInfo(format::HandleId id) const { return GetVkObjectInfo<VulkanOpticalFlowSessionNVInfo>(id, &opticalFlowSessionNV_map_); }
    const VulkanPerformanceConfigurationINTELInfo* GetVkPerformanceConfigurationINTELInfo(format::HandleId id) const { return GetVkObjectInfo<VulkanPerformanceConfigurationINTELInfo>(id, &performanceConfigurationINTEL_map_); }
    const VulkanPhysicalDeviceInfo* GetVkPhysicalDeviceInfo(format::HandleId id) const { return GetVkObjectInfo<VulkanPhysicalDeviceInfo>(id, &physicalDevice_map_); }
    const VulkanPipelineInfo* GetVkPipelineInfo(format::HandleId id) const { return GetVkObjectInfo<VulkanPipelineInfo>(id, &pipeline_map_); }
    const VulkanPipelineCacheInfo* GetVkPipelineCacheInfo(format::HandleId id) const { return GetVkObjectInfo<VulkanPipelineCacheInfo>(id, &pipelineCache_map_); }
    const VulkanPipelineLayoutInfo* GetVkPipelineLayoutInfo(format::HandleId id) const { return GetVkObjectInfo<VulkanPipelineLayoutInfo>(id, &pipelineLayout_map_); }
    const VulkanPrivateDataSlotInfo* GetVkPrivateDataSlotInfo(format::HandleId id) const { return GetVkObjectInfo<VulkanPrivateDataSlotInfo>(id, &privateDataSlot_map_); }
    const VulkanQueryPoolInfo* GetVkQueryPoolInfo(format::HandleId id) const { return GetVkObjectInfo<VulkanQueryPoolInfo>(id, &queryPool_map_); }
    const VulkanQueueInfo* GetVkQueueInfo(format::HandleId id) const { return GetVkObjectInfo<VulkanQueueInfo>(id, &queue_map_); }
    const VulkanRenderPassInfo* GetVkRenderPassInfo(format::HandleId id) const { return GetVkObjectInfo<VulkanRenderPassInfo>(id, &renderPass_map_); }
    const VulkanSamplerInfo* GetVkSamplerInfo(format::HandleId id) const { return GetVkObjectInfo<VulkanSamplerInfo>(id, &sampler_map_); }
    const VulkanSamplerYcbcrConversionInfo* GetVkSamplerYcbcrConversionInfo(format::HandleId id) const { return GetVkObjectInfo<VulkanSamplerYcbcrConversionInfo>(id, &samplerYcbcrConversion_map_); }
    const VulkanSemaphoreInfo* GetVkSemaphoreInfo(format::HandleId id) const { return GetVkObjectInfo<VulkanSemaphoreInfo>(id, &semaphore_map_); }
    const VulkanShaderEXTInfo* GetVkShaderEXTInfo(format::HandleId id) const { return GetVkObjectInfo<VulkanShaderEXTInfo>(id, &shaderEXT_map_); }
    const VulkanShaderModuleInfo* GetVkShaderModuleInfo(format::HandleId id) const { return GetVkObjectInfo<VulkanShaderModuleInfo>(id, &shaderModule_map_); }
    const VulkanSurfaceKHRInfo* GetVkSurfaceKHRInfo(format::HandleId id) const { return GetVkObjectInfo<VulkanSurfaceKHRInfo>(id, &surfaceKHR_map_); }
    const VulkanSwapchainKHRInfo* GetVkSwapchainKHRInfo(format::HandleId id) const { return GetVkObjectInfo<VulkanSwapchainKHRInfo>(id, &swapchainKHR_map_); }
    const VulkanValidationCacheEXTInfo* GetVkValidationCacheEXTInfo(format::HandleId id) const { return GetVkObjectInfo<VulkanValidationCacheEXTInfo>(id, &validationCacheEXT_map_); }
    const VulkanVideoSessionKHRInfo* GetVkVideoSessionKHRInfo(format::HandleId id) const { return GetVkObjectInfo<VulkanVideoSessionKHRInfo>(id, &videoSessionKHR_map_); }
    const VulkanVideoSessionParametersKHRInfo* GetVkVideoSessionParametersKHRInfo(format::HandleId id) const { return GetVkObjectInfo<VulkanVideoSessionParametersKHRInfo>(id, &videoSessionParametersKHR_map_); }

    VulkanAccelerationStructureKHRInfo* GetVkAccelerationStructureKHRInfo(format::HandleId id) { return GetVkObjectInfo<VulkanAccelerationStructureKHRInfo>(id, &accelerationStructureKHR_map_); }
    VulkanAccelerationStructureNVInfo* GetVkAccelerationStructureNVInfo(format::HandleId id) { return GetVkObjectInfo<VulkanAccelerationStructureNVInfo>(id, &accelerationStructureNV_map_); }
    VulkanBufferInfo* GetVkBufferInfo(format::HandleId id) { return GetVkObjectInfo<VulkanBufferInfo>(id, &buffer_map_); }
    VulkanBufferViewInfo* GetVkBufferViewInfo(format::HandleId id) { return GetVkObjectInfo<VulkanBufferViewInfo>(id, &bufferView_map_); }
    VulkanCommandBufferInfo* GetVkCommandBufferInfo(format::HandleId id) { return GetVkObjectInfo<VulkanCommandBufferInfo>(id, &commandBuffer_map_); }
    VulkanCommandPoolInfo* GetVkCommandPoolInfo(format::HandleId id) { return GetVkObjectInfo<VulkanCommandPoolInfo>(id, &commandPool_map_); }
    VulkanDebugReportCallbackEXTInfo* GetVkDebugReportCallbackEXTInfo(format::HandleId id) { return GetVkObjectInfo<VulkanDebugReportCallbackEXTInfo>(id, &debugReportCallbackEXT_map_); }
    VulkanDebugUtilsMessengerEXTInfo* GetVkDebugUtilsMessengerEXTInfo(format::HandleId id) { return GetVkObjectInfo<VulkanDebugUtilsMessengerEXTInfo>(id, &debugUtilsMessengerEXT_map_); }
    VulkanDeferredOperationKHRInfo* GetVkDeferredOperationKHRInfo(format::HandleId id) { return GetVkObjectInfo<VulkanDeferredOperationKHRInfo>(id, &deferredOperationKHR_map_); }
    VulkanDescriptorPoolInfo* GetVkDescriptorPoolInfo(format::HandleId id) { return GetVkObjectInfo<VulkanDescriptorPoolInfo>(id, &descriptorPool_map_); }
    VulkanDescriptorSetInfo* GetVkDescriptorSetInfo(format::HandleId id) { return GetVkObjectInfo<VulkanDescriptorSetInfo>(id, &descriptorSet_map_); }
    VulkanDescriptorSetLayoutInfo* GetVkDescriptorSetLayoutInfo(format::HandleId id) { return GetVkObjectInfo<VulkanDescriptorSetLayoutInfo>(id, &descriptorSetLayout_map_); }
    VulkanDescriptorUpdateTemplateInfo* GetVkDescriptorUpdateTemplateInfo(format::HandleId id) { return GetVkObjectInfo<VulkanDescriptorUpdateTemplateInfo>(id, &descriptorUpdateTemplate_map_); }
    VulkanDeviceInfo* GetVkDeviceInfo(format::HandleId id) { return GetVkObjectInfo<VulkanDeviceInfo>(id, &device_map_); }
    VulkanDeviceMemoryInfo* GetVkDeviceMemoryInfo(format::HandleId id) { return GetVkObjectInfo<VulkanDeviceMemoryInfo>(id, &deviceMemory_map_); }
    VulkanDisplayKHRInfo* GetVkDisplayKHRInfo(format::HandleId id) { return GetVkObjectInfo<VulkanDisplayKHRInfo>(id, &displayKHR_map_); }
    VulkanDisplayModeKHRInfo* GetVkDisplayModeKHRInfo(format::HandleId id) { return GetVkObjectInfo<VulkanDisplayModeKHRInfo>(id, &displayModeKHR_map_); }
    VulkanEventInfo* GetVkEventInfo(format::HandleId id) { return GetVkObjectInfo<VulkanEventInfo>(id, &event_map_); }
    VulkanFenceInfo* GetVkFenceInfo(format::HandleId id) { return GetVkObjectInfo<VulkanFenceInfo>(id, &fence_map_); }
    VulkanFramebufferInfo* GetVkFramebufferInfo(format::HandleId id) { return GetVkObjectInfo<VulkanFramebufferInfo>(id, &framebuffer_map_); }
    VulkanImageInfo* GetVkImageInfo(format::HandleId id) { return GetVkObjectInfo<VulkanImageInfo>(id, &image_map_); }
    VulkanImageViewInfo* GetVkImageViewInfo(format::HandleId id) { return GetVkObjectInfo<VulkanImageViewInfo>(id, &imageView_map_); }
    VulkanIndirectCommandsLayoutNVInfo* GetVkIndirectCommandsLayoutNVInfo(format::HandleId id) { return GetVkObjectInfo<VulkanIndirectCommandsLayoutNVInfo>(id, &indirectCommandsLayoutNV_map_); }
    VulkanInstanceInfo* GetVkInstanceInfo(format::HandleId id) { return GetVkObjectInfo<VulkanInstanceInfo>(id, &instance_map_); }
    VulkanMicromapEXTInfo* GetVkMicromapEXTInfo(format::HandleId id) { return GetVkObjectInfo<VulkanMicromapEXTInfo>(id, &micromapEXT_map_); }
    VulkanOpticalFlowSessionNVInfo* GetVkOpticalFlowSessionNVInfo(format::HandleId id) { return GetVkObjectInfo<VulkanOpticalFlowSessionNVInfo>(id, &opticalFlowSessionNV_map_); }
    VulkanPerformanceConfigurationINTELInfo* GetVkPerformanceConfigurationINTELInfo(format::HandleId id) { return GetVkObjectInfo<VulkanPerformanceConfigurationINTELInfo>(id, &performanceConfigurationINTEL_map_); }
    VulkanPhysicalDeviceInfo* GetVkPhysicalDeviceInfo(format::HandleId id) { return GetVkObjectInfo<VulkanPhysicalDeviceInfo>(id, &physicalDevice_map_); }
    VulkanPipelineInfo* GetVkPipelineInfo(format::HandleId id) { return GetVkObjectInfo<VulkanPipelineInfo>(id, &pipeline_map_); }
    VulkanPipelineCacheInfo* GetVkPipelineCacheInfo(format::HandleId id) { return GetVkObjectInfo<VulkanPipelineCacheInfo>(id, &pipelineCache_map_); }
    VulkanPipelineLayoutInfo* GetVkPipelineLayoutInfo(format::HandleId id) { return GetVkObjectInfo<VulkanPipelineLayoutInfo>(id, &pipelineLayout_map_); }
    VulkanPrivateDataSlotInfo* GetVkPrivateDataSlotInfo(format::HandleId id) { return GetVkObjectInfo<VulkanPrivateDataSlotInfo>(id, &privateDataSlot_map_); }
    VulkanQueryPoolInfo* GetVkQueryPoolInfo(format::HandleId id) { return GetVkObjectInfo<VulkanQueryPoolInfo>(id, &queryPool_map_); }
    VulkanQueueInfo* GetVkQueueInfo(format::HandleId id) { return GetVkObjectInfo<VulkanQueueInfo>(id, &queue_map_); }
    VulkanRenderPassInfo* GetVkRenderPassInfo(format::HandleId id) { return GetVkObjectInfo<VulkanRenderPassInfo>(id, &renderPass_map_); }
    VulkanSamplerInfo* GetVkSamplerInfo(format::HandleId id) { return GetVkObjectInfo<VulkanSamplerInfo>(id, &sampler_map_); }
    VulkanSamplerYcbcrConversionInfo* GetVkSamplerYcbcrConversionInfo(format::HandleId id) { return GetVkObjectInfo<VulkanSamplerYcbcrConversionInfo>(id, &samplerYcbcrConversion_map_); }
    VulkanSemaphoreInfo* GetVkSemaphoreInfo(format::HandleId id) { return GetVkObjectInfo<VulkanSemaphoreInfo>(id, &semaphore_map_); }
    VulkanShaderEXTInfo* GetVkShaderEXTInfo(format::HandleId id) { return GetVkObjectInfo<VulkanShaderEXTInfo>(id, &shaderEXT_map_); }
    VulkanShaderModuleInfo* GetVkShaderModuleInfo(format::HandleId id) { return GetVkObjectInfo<VulkanShaderModuleInfo>(id, &shaderModule_map_); }
    VulkanSurfaceKHRInfo* GetVkSurfaceKHRInfo(format::HandleId id) { return GetVkObjectInfo<VulkanSurfaceKHRInfo>(id, &surfaceKHR_map_); }
    VulkanSwapchainKHRInfo* GetVkSwapchainKHRInfo(format::HandleId id) { return GetVkObjectInfo<VulkanSwapchainKHRInfo>(id, &swapchainKHR_map_); }
    VulkanValidationCacheEXTInfo* GetVkValidationCacheEXTInfo(format::HandleId id) { return GetVkObjectInfo<VulkanValidationCacheEXTInfo>(id, &validationCacheEXT_map_); }
    VulkanVideoSessionKHRInfo* GetVkVideoSessionKHRInfo(format::HandleId id) { return GetVkObjectInfo<VulkanVideoSessionKHRInfo>(id, &videoSessionKHR_map_); }
    VulkanVideoSessionParametersKHRInfo* GetVkVideoSessionParametersKHRInfo(format::HandleId id) { return GetVkObjectInfo<VulkanVideoSessionParametersKHRInfo>(id, &videoSessionParametersKHR_map_); }

    void VisitVkAccelerationStructureKHRInfo(std::function<void(const VulkanAccelerationStructureKHRInfo*)> visitor) const {  for (const auto& entry : accelerationStructureKHR_map_) { visitor(&entry.second); }  }
    void VisitVkAccelerationStructureNVInfo(std::function<void(const VulkanAccelerationStructureNVInfo*)> visitor) const {  for (const auto& entry : accelerationStructureNV_map_) { visitor(&entry.second); }  }
    void VisitVkBufferInfo(std::function<void(const VulkanBufferInfo*)> visitor) const {  for (const auto& entry : buffer_map_) { visitor(&entry.second); }  }
    void VisitVkBufferViewInfo(std::function<void(const VulkanBufferViewInfo*)> visitor) const {  for (const auto& entry : bufferView_map_) { visitor(&entry.second); }  }
    void VisitVkCommandBufferInfo(std::function<void(const VulkanCommandBufferInfo*)> visitor) const {  for (const auto& entry : commandBuffer_map_) { visitor(&entry.second); }  }
    void VisitVkCommandPoolInfo(std::function<void(const VulkanCommandPoolInfo*)> visitor) const {  for (const auto& entry : commandPool_map_) { visitor(&entry.second); }  }
    void VisitVkDebugReportCallbackEXTInfo(std::function<void(const VulkanDebugReportCallbackEXTInfo*)> visitor) const {  for (const auto& entry : debugReportCallbackEXT_map_) { visitor(&entry.second); }  }
    void VisitVkDebugUtilsMessengerEXTInfo(std::function<void(const VulkanDebugUtilsMessengerEXTInfo*)> visitor) const {  for (const auto& entry : debugUtilsMessengerEXT_map_) { visitor(&entry.second); }  }
    void VisitVkDeferredOperationKHRInfo(std::function<void(const VulkanDeferredOperationKHRInfo*)> visitor) const {  for (const auto& entry : deferredOperationKHR_map_) { visitor(&entry.second); }  }
    void VisitVkDescriptorPoolInfo(std::function<void(const VulkanDescriptorPoolInfo*)> visitor) const {  for (const auto& entry : descriptorPool_map_) { visitor(&entry.second); }  }
    void VisitVkDescriptorSetInfo(std::function<void(const VulkanDescriptorSetInfo*)> visitor) const {  for (const auto& entry : descriptorSet_map_) { visitor(&entry.second); }  }
    void VisitVkDescriptorSetLayoutInfo(std::function<void(const VulkanDescriptorSetLayoutInfo*)> visitor) const {  for (const auto& entry : descriptorSetLayout_map_) { visitor(&entry.second); }  }
    void VisitVkDescriptorUpdateTemplateInfo(std::function<void(const VulkanDescriptorUpdateTemplateInfo*)> visitor) const {  for (const auto& entry : descriptorUpdateTemplate_map_) { visitor(&entry.second); }  }
    void VisitVkDeviceInfo(std::function<void(const VulkanDeviceInfo*)> visitor) const {  for (const auto& entry : device_map_) { visitor(&entry.second); }  }
    void VisitVkDeviceMemoryInfo(std::function<void(const VulkanDeviceMemoryInfo*)> visitor) const {  for (const auto& entry : deviceMemory_map_) { visitor(&entry.second); }  }
    void VisitVkDisplayKHRInfo(std::function<void(const VulkanDisplayKHRInfo*)> visitor) const {  for (const auto& entry : displayKHR_map_) { visitor(&entry.second); }  }
    void VisitVkDisplayModeKHRInfo(std::function<void(const VulkanDisplayModeKHRInfo*)> visitor) const {  for (const auto& entry : displayModeKHR_map_) { visitor(&entry.second); }  }
    void VisitVkEventInfo(std::function<void(const VulkanEventInfo*)> visitor) const {  for (const auto& entry : event_map_) { visitor(&entry.second); }  }
    void VisitVkFenceInfo(std::function<void(const VulkanFenceInfo*)> visitor) const {  for (const auto& entry : fence_map_) { visitor(&entry.second); }  }
    void VisitVkFramebufferInfo(std::function<void(const VulkanFramebufferInfo*)> visitor) const {  for (const auto& entry : framebuffer_map_) { visitor(&entry.second); }  }
    void VisitVkImageInfo(std::function<void(const VulkanImageInfo*)> visitor) const {  for (const auto& entry : image_map_) { visitor(&entry.second); }  }
    void VisitVkImageViewInfo(std::function<void(const VulkanImageViewInfo*)> visitor) const {  for (const auto& entry : imageView_map_) { visitor(&entry.second); }  }
    void VisitVkIndirectCommandsLayoutNVInfo(std::function<void(const VulkanIndirectCommandsLayoutNVInfo*)> visitor) const {  for (const auto& entry : indirectCommandsLayoutNV_map_) { visitor(&entry.second); }  }
    void VisitVkInstanceInfo(std::function<void(const VulkanInstanceInfo*)> visitor) const {  for (const auto& entry : instance_map_) { visitor(&entry.second); }  }
    void VisitVkMicromapEXTInfo(std::function<void(const VulkanMicromapEXTInfo*)> visitor) const {  for (const auto& entry : micromapEXT_map_) { visitor(&entry.second); }  }
    void VisitVkOpticalFlowSessionNVInfo(std::function<void(const VulkanOpticalFlowSessionNVInfo*)> visitor) const {  for (const auto& entry : opticalFlowSessionNV_map_) { visitor(&entry.second); }  }
    void VisitVkPerformanceConfigurationINTELInfo(std::function<void(const VulkanPerformanceConfigurationINTELInfo*)> visitor) const {  for (const auto& entry : performanceConfigurationINTEL_map_) { visitor(&entry.second); }  }
    void VisitVkPhysicalDeviceInfo(std::function<void(const VulkanPhysicalDeviceInfo*)> visitor) const {  for (const auto& entry : physicalDevice_map_) { visitor(&entry.second); }  }
    void VisitVkPipelineInfo(std::function<void(const VulkanPipelineInfo*)> visitor) const {  for (const auto& entry : pipeline_map_) { visitor(&entry.second); }  }
    void VisitVkPipelineCacheInfo(std::function<void(const VulkanPipelineCacheInfo*)> visitor) const {  for (const auto& entry : pipelineCache_map_) { visitor(&entry.second); }  }
    void VisitVkPipelineLayoutInfo(std::function<void(const VulkanPipelineLayoutInfo*)> visitor) const {  for (const auto& entry : pipelineLayout_map_) { visitor(&entry.second); }  }
    void VisitVkPrivateDataSlotInfo(std::function<void(const VulkanPrivateDataSlotInfo*)> visitor) const {  for (const auto& entry : privateDataSlot_map_) { visitor(&entry.second); }  }
    void VisitVkQueryPoolInfo(std::function<void(const VulkanQueryPoolInfo*)> visitor) const {  for (const auto& entry : queryPool_map_) { visitor(&entry.second); }  }
    void VisitVkQueueInfo(std::function<void(const VulkanQueueInfo*)> visitor) const {  for (const auto& entry : queue_map_) { visitor(&entry.second); }  }
    void VisitVkRenderPassInfo(std::function<void(const VulkanRenderPassInfo*)> visitor) const {  for (const auto& entry : renderPass_map_) { visitor(&entry.second); }  }
    void VisitVkSamplerInfo(std::function<void(const VulkanSamplerInfo*)> visitor) const {  for (const auto& entry : sampler_map_) { visitor(&entry.second); }  }
    void VisitVkSamplerYcbcrConversionInfo(std::function<void(const VulkanSamplerYcbcrConversionInfo*)> visitor) const {  for (const auto& entry : samplerYcbcrConversion_map_) { visitor(&entry.second); }  }
    void VisitVkSemaphoreInfo(std::function<void(const VulkanSemaphoreInfo*)> visitor) const {  for (const auto& entry : semaphore_map_) { visitor(&entry.second); }  }
    void VisitVkShaderEXTInfo(std::function<void(const VulkanShaderEXTInfo*)> visitor) const {  for (const auto& entry : shaderEXT_map_) { visitor(&entry.second); }  }
    void VisitVkShaderModuleInfo(std::function<void(const VulkanShaderModuleInfo*)> visitor) const {  for (const auto& entry : shaderModule_map_) { visitor(&entry.second); }  }
    void VisitVkSurfaceKHRInfo(std::function<void(const VulkanSurfaceKHRInfo*)> visitor) const {  for (const auto& entry : surfaceKHR_map_) { visitor(&entry.second); }  }
    void VisitVkSwapchainKHRInfo(std::function<void(const VulkanSwapchainKHRInfo*)> visitor) const {  for (const auto& entry : swapchainKHR_map_) { visitor(&entry.second); }  }
    void VisitVkValidationCacheEXTInfo(std::function<void(const VulkanValidationCacheEXTInfo*)> visitor) const {  for (const auto& entry : validationCacheEXT_map_) { visitor(&entry.second); }  }
    void VisitVkVideoSessionKHRInfo(std::function<void(const VulkanVideoSessionKHRInfo*)> visitor) const {  for (const auto& entry : videoSessionKHR_map_) { visitor(&entry.second); }  }
    void VisitVkVideoSessionParametersKHRInfo(std::function<void(const VulkanVideoSessionParametersKHRInfo*)> visitor) const {  for (const auto& entry : videoSessionParametersKHR_map_) { visitor(&entry.second); }  }

  protected:
     std::unordered_map<format::HandleId, VulkanAccelerationStructureKHRInfo> accelerationStructureKHR_map_;
     std::unordered_map<format::HandleId, VulkanAccelerationStructureNVInfo> accelerationStructureNV_map_;
     std::unordered_map<format::HandleId, VulkanBufferInfo> buffer_map_;
     std::unordered_map<format::HandleId, VulkanBufferViewInfo> bufferView_map_;
     std::unordered_map<format::HandleId, VulkanCommandBufferInfo> commandBuffer_map_;
     std::unordered_map<format::HandleId, VulkanCommandPoolInfo> commandPool_map_;
     std::unordered_map<format::HandleId, VulkanDebugReportCallbackEXTInfo> debugReportCallbackEXT_map_;
     std::unordered_map<format::HandleId, VulkanDebugUtilsMessengerEXTInfo> debugUtilsMessengerEXT_map_;
     std::unordered_map<format::HandleId, VulkanDeferredOperationKHRInfo> deferredOperationKHR_map_;
     std::unordered_map<format::HandleId, VulkanDescriptorPoolInfo> descriptorPool_map_;
     std::unordered_map<format::HandleId, VulkanDescriptorSetInfo> descriptorSet_map_;
     std::unordered_map<format::HandleId, VulkanDescriptorSetLayoutInfo> descriptorSetLayout_map_;
     std::unordered_map<format::HandleId, VulkanDescriptorUpdateTemplateInfo> descriptorUpdateTemplate_map_;
     std::unordered_map<format::HandleId, VulkanDeviceInfo> device_map_;
     std::unordered_map<format::HandleId, VulkanDeviceMemoryInfo> deviceMemory_map_;
     std::unordered_map<format::HandleId, VulkanDisplayKHRInfo> displayKHR_map_;
     std::unordered_map<format::HandleId, VulkanDisplayModeKHRInfo> displayModeKHR_map_;
     std::unordered_map<format::HandleId, VulkanEventInfo> event_map_;
     std::unordered_map<format::HandleId, VulkanFenceInfo> fence_map_;
     std::unordered_map<format::HandleId, VulkanFramebufferInfo> framebuffer_map_;
     std::unordered_map<format::HandleId, VulkanImageInfo> image_map_;
     std::unordered_map<format::HandleId, VulkanImageViewInfo> imageView_map_;
     std::unordered_map<format::HandleId, VulkanIndirectCommandsLayoutNVInfo> indirectCommandsLayoutNV_map_;
     std::unordered_map<format::HandleId, VulkanInstanceInfo> instance_map_;
     std::unordered_map<format::HandleId, VulkanMicromapEXTInfo> micromapEXT_map_;
     std::unordered_map<format::HandleId, VulkanOpticalFlowSessionNVInfo> opticalFlowSessionNV_map_;
     std::unordered_map<format::HandleId, VulkanPerformanceConfigurationINTELInfo> performanceConfigurationINTEL_map_;
     std::unordered_map<format::HandleId, VulkanPhysicalDeviceInfo> physicalDevice_map_;
     std::unordered_map<format::HandleId, VulkanPipelineInfo> pipeline_map_;
     std::unordered_map<format::HandleId, VulkanPipelineCacheInfo> pipelineCache_map_;
     std::unordered_map<format::HandleId, VulkanPipelineLayoutInfo> pipelineLayout_map_;
     std::unordered_map<format::HandleId, VulkanPrivateDataSlotInfo> privateDataSlot_map_;
     std::unordered_map<format::HandleId, VulkanQueryPoolInfo> queryPool_map_;
     std::unordered_map<format::HandleId, VulkanQueueInfo> queue_map_;
     std::unordered_map<format::HandleId, VulkanRenderPassInfo> renderPass_map_;
     std::unordered_map<format::HandleId, VulkanSamplerInfo> sampler_map_;
     std::unordered_map<format::HandleId, VulkanSamplerYcbcrConversionInfo> samplerYcbcrConversion_map_;
     std::unordered_map<format::HandleId, VulkanSemaphoreInfo> semaphore_map_;
     std::unordered_map<format::HandleId, VulkanShaderEXTInfo> shaderEXT_map_;
     std::unordered_map<format::HandleId, VulkanShaderModuleInfo> shaderModule_map_;
     std::unordered_map<format::HandleId, VulkanSurfaceKHRInfo> surfaceKHR_map_;
     std::unordered_map<format::HandleId, VulkanSwapchainKHRInfo> swapchainKHR_map_;
     std::unordered_map<format::HandleId, VulkanValidationCacheEXTInfo> validationCacheEXT_map_;
     std::unordered_map<format::HandleId, VulkanVideoSessionKHRInfo> videoSessionKHR_map_;
     std::unordered_map<format::HandleId, VulkanVideoSessionParametersKHRInfo> videoSessionParametersKHR_map_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
