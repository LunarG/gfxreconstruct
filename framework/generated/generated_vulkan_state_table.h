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

#ifndef  GFXRECON_GENERATED_VULKAN_STATE_TABLE_H
#define  GFXRECON_GENERATED_VULKAN_STATE_TABLE_H

#include "encode/vulkan_state_table_base.h"


GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

class VulkanStateTable : VulkanStateTableBase
{
  public:
    VulkanStateTable() {}
    ~VulkanStateTable() {}

    bool InsertWrapper(format::HandleId id, VulkanAccelerationStructureKHRWrapper* wrapper) { return InsertEntry(id, wrapper, accelerationStructureKHR_map_); }
    bool InsertWrapper(format::HandleId id, VulkanAccelerationStructureNVWrapper* wrapper) { return InsertEntry(id, wrapper, accelerationStructureNV_map_); }
    bool InsertWrapper(format::HandleId id, VulkanBufferWrapper* wrapper) { return InsertEntry(id, wrapper, buffer_map_); }
    bool InsertWrapper(format::HandleId id, VulkanBufferViewWrapper* wrapper) { return InsertEntry(id, wrapper, bufferView_map_); }
    bool InsertWrapper(format::HandleId id, VulkanCommandBufferWrapper* wrapper) { return InsertEntry(id, wrapper, commandBuffer_map_); }
    bool InsertWrapper(format::HandleId id, VulkanCommandPoolWrapper* wrapper) { return InsertEntry(id, wrapper, commandPool_map_); }
    bool InsertWrapper(format::HandleId id, VulkanDebugReportCallbackEXTWrapper* wrapper) { return InsertEntry(id, wrapper, debugReportCallbackEXT_map_); }
    bool InsertWrapper(format::HandleId id, VulkanDebugUtilsMessengerEXTWrapper* wrapper) { return InsertEntry(id, wrapper, debugUtilsMessengerEXT_map_); }
    bool InsertWrapper(format::HandleId id, VulkanDeferredOperationKHRWrapper* wrapper) { return InsertEntry(id, wrapper, deferredOperationKHR_map_); }
    bool InsertWrapper(format::HandleId id, VulkanDescriptorPoolWrapper* wrapper) { return InsertEntry(id, wrapper, descriptorPool_map_); }
    bool InsertWrapper(format::HandleId id, VulkanDescriptorSetWrapper* wrapper) { return InsertEntry(id, wrapper, descriptorSet_map_); }
    bool InsertWrapper(format::HandleId id, VulkanDescriptorSetLayoutWrapper* wrapper) { return InsertEntry(id, wrapper, descriptorSetLayout_map_); }
    bool InsertWrapper(format::HandleId id, VulkanDescriptorUpdateTemplateWrapper* wrapper) { return InsertEntry(id, wrapper, descriptorUpdateTemplate_map_); }
    bool InsertWrapper(format::HandleId id, VulkanDeviceWrapper* wrapper) { return InsertEntry(id, wrapper, device_map_); }
    bool InsertWrapper(format::HandleId id, VulkanDeviceMemoryWrapper* wrapper) { return InsertEntry(id, wrapper, deviceMemory_map_); }
    bool InsertWrapper(format::HandleId id, VulkanDisplayKHRWrapper* wrapper) { return InsertEntry(id, wrapper, displayKHR_map_); }
    bool InsertWrapper(format::HandleId id, VulkanDisplayModeKHRWrapper* wrapper) { return InsertEntry(id, wrapper, displayModeKHR_map_); }
    bool InsertWrapper(format::HandleId id, VulkanEventWrapper* wrapper) { return InsertEntry(id, wrapper, event_map_); }
    bool InsertWrapper(format::HandleId id, VulkanFenceWrapper* wrapper) { return InsertEntry(id, wrapper, fence_map_); }
    bool InsertWrapper(format::HandleId id, VulkanFramebufferWrapper* wrapper) { return InsertEntry(id, wrapper, framebuffer_map_); }
    bool InsertWrapper(format::HandleId id, VulkanImageWrapper* wrapper) { return InsertEntry(id, wrapper, image_map_); }
    bool InsertWrapper(format::HandleId id, VulkanImageViewWrapper* wrapper) { return InsertEntry(id, wrapper, imageView_map_); }
    bool InsertWrapper(format::HandleId id, VulkanIndirectCommandsLayoutNVWrapper* wrapper) { return InsertEntry(id, wrapper, indirectCommandsLayoutNV_map_); }
    bool InsertWrapper(format::HandleId id, VulkanInstanceWrapper* wrapper) { return InsertEntry(id, wrapper, instance_map_); }
    bool InsertWrapper(format::HandleId id, VulkanMicromapEXTWrapper* wrapper) { return InsertEntry(id, wrapper, micromapEXT_map_); }
    bool InsertWrapper(format::HandleId id, VulkanOpticalFlowSessionNVWrapper* wrapper) { return InsertEntry(id, wrapper, opticalFlowSessionNV_map_); }
    bool InsertWrapper(format::HandleId id, VulkanPerformanceConfigurationINTELWrapper* wrapper) { return InsertEntry(id, wrapper, performanceConfigurationINTEL_map_); }
    bool InsertWrapper(format::HandleId id, VulkanPhysicalDeviceWrapper* wrapper) { return InsertEntry(id, wrapper, physicalDevice_map_); }
    bool InsertWrapper(format::HandleId id, VulkanPipelineWrapper* wrapper) { return InsertEntry(id, wrapper, pipeline_map_); }
    bool InsertWrapper(format::HandleId id, VulkanPipelineCacheWrapper* wrapper) { return InsertEntry(id, wrapper, pipelineCache_map_); }
    bool InsertWrapper(format::HandleId id, VulkanPipelineLayoutWrapper* wrapper) { return InsertEntry(id, wrapper, pipelineLayout_map_); }
    bool InsertWrapper(format::HandleId id, VulkanPrivateDataSlotWrapper* wrapper) { return InsertEntry(id, wrapper, privateDataSlot_map_); }
    bool InsertWrapper(format::HandleId id, VulkanQueryPoolWrapper* wrapper) { return InsertEntry(id, wrapper, queryPool_map_); }
    bool InsertWrapper(format::HandleId id, VulkanQueueWrapper* wrapper) { return InsertEntry(id, wrapper, queue_map_); }
    bool InsertWrapper(format::HandleId id, VulkanRenderPassWrapper* wrapper) { return InsertEntry(id, wrapper, renderPass_map_); }
    bool InsertWrapper(format::HandleId id, VulkanSamplerWrapper* wrapper) { return InsertEntry(id, wrapper, sampler_map_); }
    bool InsertWrapper(format::HandleId id, VulkanSamplerYcbcrConversionWrapper* wrapper) { return InsertEntry(id, wrapper, samplerYcbcrConversion_map_); }
    bool InsertWrapper(format::HandleId id, VulkanSemaphoreWrapper* wrapper) { return InsertEntry(id, wrapper, semaphore_map_); }
    bool InsertWrapper(format::HandleId id, VulkanShaderEXTWrapper* wrapper) { return InsertEntry(id, wrapper, shaderEXT_map_); }
    bool InsertWrapper(format::HandleId id, VulkanShaderModuleWrapper* wrapper) { return InsertEntry(id, wrapper, shaderModule_map_); }
    bool InsertWrapper(format::HandleId id, VulkanSurfaceKHRWrapper* wrapper) { return InsertEntry(id, wrapper, surfaceKHR_map_); }
    bool InsertWrapper(format::HandleId id, VulkanSwapchainKHRWrapper* wrapper) { return InsertEntry(id, wrapper, swapchainKHR_map_); }
    bool InsertWrapper(format::HandleId id, VulkanValidationCacheEXTWrapper* wrapper) { return InsertEntry(id, wrapper, validationCacheEXT_map_); }
    bool InsertWrapper(format::HandleId id, VulkanVideoSessionKHRWrapper* wrapper) { return InsertEntry(id, wrapper, videoSessionKHR_map_); }
    bool InsertWrapper(format::HandleId id, VulkanVideoSessionParametersKHRWrapper* wrapper) { return InsertEntry(id, wrapper, videoSessionParametersKHR_map_); }

    bool RemoveWrapper(const VulkanAccelerationStructureKHRWrapper* wrapper) { return RemoveEntry(wrapper, accelerationStructureKHR_map_); }
    bool RemoveWrapper(const VulkanAccelerationStructureNVWrapper* wrapper) { return RemoveEntry(wrapper, accelerationStructureNV_map_); }
    bool RemoveWrapper(const VulkanBufferWrapper* wrapper) { return RemoveEntry(wrapper, buffer_map_); }
    bool RemoveWrapper(const VulkanBufferViewWrapper* wrapper) { return RemoveEntry(wrapper, bufferView_map_); }
    bool RemoveWrapper(const VulkanCommandBufferWrapper* wrapper) { return RemoveEntry(wrapper, commandBuffer_map_); }
    bool RemoveWrapper(const VulkanCommandPoolWrapper* wrapper) { return RemoveEntry(wrapper, commandPool_map_); }
    bool RemoveWrapper(const VulkanDebugReportCallbackEXTWrapper* wrapper) { return RemoveEntry(wrapper, debugReportCallbackEXT_map_); }
    bool RemoveWrapper(const VulkanDebugUtilsMessengerEXTWrapper* wrapper) { return RemoveEntry(wrapper, debugUtilsMessengerEXT_map_); }
    bool RemoveWrapper(const VulkanDeferredOperationKHRWrapper* wrapper) { return RemoveEntry(wrapper, deferredOperationKHR_map_); }
    bool RemoveWrapper(const VulkanDescriptorPoolWrapper* wrapper) { return RemoveEntry(wrapper, descriptorPool_map_); }
    bool RemoveWrapper(const VulkanDescriptorSetWrapper* wrapper) { return RemoveEntry(wrapper, descriptorSet_map_); }
    bool RemoveWrapper(const VulkanDescriptorSetLayoutWrapper* wrapper) { return RemoveEntry(wrapper, descriptorSetLayout_map_); }
    bool RemoveWrapper(const VulkanDescriptorUpdateTemplateWrapper* wrapper) { return RemoveEntry(wrapper, descriptorUpdateTemplate_map_); }
    bool RemoveWrapper(const VulkanDeviceWrapper* wrapper) { return RemoveEntry(wrapper, device_map_); }
    bool RemoveWrapper(const VulkanDeviceMemoryWrapper* wrapper) { return RemoveEntry(wrapper, deviceMemory_map_); }
    bool RemoveWrapper(const VulkanDisplayKHRWrapper* wrapper) { return RemoveEntry(wrapper, displayKHR_map_); }
    bool RemoveWrapper(const VulkanDisplayModeKHRWrapper* wrapper) { return RemoveEntry(wrapper, displayModeKHR_map_); }
    bool RemoveWrapper(const VulkanEventWrapper* wrapper) { return RemoveEntry(wrapper, event_map_); }
    bool RemoveWrapper(const VulkanFenceWrapper* wrapper) { return RemoveEntry(wrapper, fence_map_); }
    bool RemoveWrapper(const VulkanFramebufferWrapper* wrapper) { return RemoveEntry(wrapper, framebuffer_map_); }
    bool RemoveWrapper(const VulkanImageWrapper* wrapper) { return RemoveEntry(wrapper, image_map_); }
    bool RemoveWrapper(const VulkanImageViewWrapper* wrapper) { return RemoveEntry(wrapper, imageView_map_); }
    bool RemoveWrapper(const VulkanIndirectCommandsLayoutNVWrapper* wrapper) { return RemoveEntry(wrapper, indirectCommandsLayoutNV_map_); }
    bool RemoveWrapper(const VulkanInstanceWrapper* wrapper) { return RemoveEntry(wrapper, instance_map_); }
    bool RemoveWrapper(const VulkanMicromapEXTWrapper* wrapper) { return RemoveEntry(wrapper, micromapEXT_map_); }
    bool RemoveWrapper(const VulkanOpticalFlowSessionNVWrapper* wrapper) { return RemoveEntry(wrapper, opticalFlowSessionNV_map_); }
    bool RemoveWrapper(const VulkanPerformanceConfigurationINTELWrapper* wrapper) { return RemoveEntry(wrapper, performanceConfigurationINTEL_map_); }
    bool RemoveWrapper(const VulkanPhysicalDeviceWrapper* wrapper) { return RemoveEntry(wrapper, physicalDevice_map_); }
    bool RemoveWrapper(const VulkanPipelineWrapper* wrapper) { return RemoveEntry(wrapper, pipeline_map_); }
    bool RemoveWrapper(const VulkanPipelineCacheWrapper* wrapper) { return RemoveEntry(wrapper, pipelineCache_map_); }
    bool RemoveWrapper(const VulkanPipelineLayoutWrapper* wrapper) { return RemoveEntry(wrapper, pipelineLayout_map_); }
    bool RemoveWrapper(const VulkanPrivateDataSlotWrapper* wrapper) { return RemoveEntry(wrapper, privateDataSlot_map_); }
    bool RemoveWrapper(const VulkanQueryPoolWrapper* wrapper) { return RemoveEntry(wrapper, queryPool_map_); }
    bool RemoveWrapper(const VulkanQueueWrapper* wrapper) { return RemoveEntry(wrapper, queue_map_); }
    bool RemoveWrapper(const VulkanRenderPassWrapper* wrapper) { return RemoveEntry(wrapper, renderPass_map_); }
    bool RemoveWrapper(const VulkanSamplerWrapper* wrapper) { return RemoveEntry(wrapper, sampler_map_); }
    bool RemoveWrapper(const VulkanSamplerYcbcrConversionWrapper* wrapper) { return RemoveEntry(wrapper, samplerYcbcrConversion_map_); }
    bool RemoveWrapper(const VulkanSemaphoreWrapper* wrapper) { return RemoveEntry(wrapper, semaphore_map_); }
    bool RemoveWrapper(const VulkanShaderEXTWrapper* wrapper) { return RemoveEntry(wrapper, shaderEXT_map_); }
    bool RemoveWrapper(const VulkanShaderModuleWrapper* wrapper) { return RemoveEntry(wrapper, shaderModule_map_); }
    bool RemoveWrapper(const VulkanSurfaceKHRWrapper* wrapper) { return RemoveEntry(wrapper, surfaceKHR_map_); }
    bool RemoveWrapper(const VulkanSwapchainKHRWrapper* wrapper) { return RemoveEntry(wrapper, swapchainKHR_map_); }
    bool RemoveWrapper(const VulkanValidationCacheEXTWrapper* wrapper) { return RemoveEntry(wrapper, validationCacheEXT_map_); }
    bool RemoveWrapper(const VulkanVideoSessionKHRWrapper* wrapper) { return RemoveEntry(wrapper, videoSessionKHR_map_); }
    bool RemoveWrapper(const VulkanVideoSessionParametersKHRWrapper* wrapper) { return RemoveEntry(wrapper, videoSessionParametersKHR_map_); }

    const VulkanAccelerationStructureKHRWrapper* GetVulkanAccelerationStructureKHRWrapper(format::HandleId id) const { return GetWrapper<VulkanAccelerationStructureKHRWrapper>(id, accelerationStructureKHR_map_); }
    const VulkanAccelerationStructureNVWrapper* GetVulkanAccelerationStructureNVWrapper(format::HandleId id) const { return GetWrapper<VulkanAccelerationStructureNVWrapper>(id, accelerationStructureNV_map_); }
    const VulkanBufferWrapper* GetVulkanBufferWrapper(format::HandleId id) const { return GetWrapper<VulkanBufferWrapper>(id, buffer_map_); }
    const VulkanBufferViewWrapper* GetVulkanBufferViewWrapper(format::HandleId id) const { return GetWrapper<VulkanBufferViewWrapper>(id, bufferView_map_); }
    const VulkanCommandBufferWrapper* GetVulkanCommandBufferWrapper(format::HandleId id) const { return GetWrapper<VulkanCommandBufferWrapper>(id, commandBuffer_map_); }
    const VulkanCommandPoolWrapper* GetVulkanCommandPoolWrapper(format::HandleId id) const { return GetWrapper<VulkanCommandPoolWrapper>(id, commandPool_map_); }
    const VulkanDebugReportCallbackEXTWrapper* GetVulkanDebugReportCallbackEXTWrapper(format::HandleId id) const { return GetWrapper<VulkanDebugReportCallbackEXTWrapper>(id, debugReportCallbackEXT_map_); }
    const VulkanDebugUtilsMessengerEXTWrapper* GetVulkanDebugUtilsMessengerEXTWrapper(format::HandleId id) const { return GetWrapper<VulkanDebugUtilsMessengerEXTWrapper>(id, debugUtilsMessengerEXT_map_); }
    const VulkanDeferredOperationKHRWrapper* GetVulkanDeferredOperationKHRWrapper(format::HandleId id) const { return GetWrapper<VulkanDeferredOperationKHRWrapper>(id, deferredOperationKHR_map_); }
    const VulkanDescriptorPoolWrapper* GetVulkanDescriptorPoolWrapper(format::HandleId id) const { return GetWrapper<VulkanDescriptorPoolWrapper>(id, descriptorPool_map_); }
    const VulkanDescriptorSetWrapper* GetVulkanDescriptorSetWrapper(format::HandleId id) const { return GetWrapper<VulkanDescriptorSetWrapper>(id, descriptorSet_map_); }
    const VulkanDescriptorSetLayoutWrapper* GetVulkanDescriptorSetLayoutWrapper(format::HandleId id) const { return GetWrapper<VulkanDescriptorSetLayoutWrapper>(id, descriptorSetLayout_map_); }
    const VulkanDescriptorUpdateTemplateWrapper* GetVulkanDescriptorUpdateTemplateWrapper(format::HandleId id) const { return GetWrapper<VulkanDescriptorUpdateTemplateWrapper>(id, descriptorUpdateTemplate_map_); }
    const VulkanDeviceWrapper* GetVulkanDeviceWrapper(format::HandleId id) const { return GetWrapper<VulkanDeviceWrapper>(id, device_map_); }
    const VulkanDeviceMemoryWrapper* GetVulkanDeviceMemoryWrapper(format::HandleId id) const { return GetWrapper<VulkanDeviceMemoryWrapper>(id, deviceMemory_map_); }
    const VulkanDisplayKHRWrapper* GetVulkanDisplayKHRWrapper(format::HandleId id) const { return GetWrapper<VulkanDisplayKHRWrapper>(id, displayKHR_map_); }
    const VulkanDisplayModeKHRWrapper* GetVulkanDisplayModeKHRWrapper(format::HandleId id) const { return GetWrapper<VulkanDisplayModeKHRWrapper>(id, displayModeKHR_map_); }
    const VulkanEventWrapper* GetVulkanEventWrapper(format::HandleId id) const { return GetWrapper<VulkanEventWrapper>(id, event_map_); }
    const VulkanFenceWrapper* GetVulkanFenceWrapper(format::HandleId id) const { return GetWrapper<VulkanFenceWrapper>(id, fence_map_); }
    const VulkanFramebufferWrapper* GetVulkanFramebufferWrapper(format::HandleId id) const { return GetWrapper<VulkanFramebufferWrapper>(id, framebuffer_map_); }
    const VulkanImageWrapper* GetVulkanImageWrapper(format::HandleId id) const { return GetWrapper<VulkanImageWrapper>(id, image_map_); }
    const VulkanImageViewWrapper* GetVulkanImageViewWrapper(format::HandleId id) const { return GetWrapper<VulkanImageViewWrapper>(id, imageView_map_); }
    const VulkanIndirectCommandsLayoutNVWrapper* GetVulkanIndirectCommandsLayoutNVWrapper(format::HandleId id) const { return GetWrapper<VulkanIndirectCommandsLayoutNVWrapper>(id, indirectCommandsLayoutNV_map_); }
    const VulkanInstanceWrapper* GetVulkanInstanceWrapper(format::HandleId id) const { return GetWrapper<VulkanInstanceWrapper>(id, instance_map_); }
    const VulkanMicromapEXTWrapper* GetVulkanMicromapEXTWrapper(format::HandleId id) const { return GetWrapper<VulkanMicromapEXTWrapper>(id, micromapEXT_map_); }
    const VulkanOpticalFlowSessionNVWrapper* GetVulkanOpticalFlowSessionNVWrapper(format::HandleId id) const { return GetWrapper<VulkanOpticalFlowSessionNVWrapper>(id, opticalFlowSessionNV_map_); }
    const VulkanPerformanceConfigurationINTELWrapper* GetVulkanPerformanceConfigurationINTELWrapper(format::HandleId id) const { return GetWrapper<VulkanPerformanceConfigurationINTELWrapper>(id, performanceConfigurationINTEL_map_); }
    const VulkanPhysicalDeviceWrapper* GetVulkanPhysicalDeviceWrapper(format::HandleId id) const { return GetWrapper<VulkanPhysicalDeviceWrapper>(id, physicalDevice_map_); }
    const VulkanPipelineWrapper* GetVulkanPipelineWrapper(format::HandleId id) const { return GetWrapper<VulkanPipelineWrapper>(id, pipeline_map_); }
    const VulkanPipelineCacheWrapper* GetVulkanPipelineCacheWrapper(format::HandleId id) const { return GetWrapper<VulkanPipelineCacheWrapper>(id, pipelineCache_map_); }
    const VulkanPipelineLayoutWrapper* GetVulkanPipelineLayoutWrapper(format::HandleId id) const { return GetWrapper<VulkanPipelineLayoutWrapper>(id, pipelineLayout_map_); }
    const VulkanPrivateDataSlotWrapper* GetVulkanPrivateDataSlotWrapper(format::HandleId id) const { return GetWrapper<VulkanPrivateDataSlotWrapper>(id, privateDataSlot_map_); }
    const VulkanQueryPoolWrapper* GetVulkanQueryPoolWrapper(format::HandleId id) const { return GetWrapper<VulkanQueryPoolWrapper>(id, queryPool_map_); }
    const VulkanQueueWrapper* GetVulkanQueueWrapper(format::HandleId id) const { return GetWrapper<VulkanQueueWrapper>(id, queue_map_); }
    const VulkanRenderPassWrapper* GetVulkanRenderPassWrapper(format::HandleId id) const { return GetWrapper<VulkanRenderPassWrapper>(id, renderPass_map_); }
    const VulkanSamplerWrapper* GetVulkanSamplerWrapper(format::HandleId id) const { return GetWrapper<VulkanSamplerWrapper>(id, sampler_map_); }
    const VulkanSamplerYcbcrConversionWrapper* GetVulkanSamplerYcbcrConversionWrapper(format::HandleId id) const { return GetWrapper<VulkanSamplerYcbcrConversionWrapper>(id, samplerYcbcrConversion_map_); }
    const VulkanSemaphoreWrapper* GetVulkanSemaphoreWrapper(format::HandleId id) const { return GetWrapper<VulkanSemaphoreWrapper>(id, semaphore_map_); }
    const VulkanShaderEXTWrapper* GetVulkanShaderEXTWrapper(format::HandleId id) const { return GetWrapper<VulkanShaderEXTWrapper>(id, shaderEXT_map_); }
    const VulkanShaderModuleWrapper* GetVulkanShaderModuleWrapper(format::HandleId id) const { return GetWrapper<VulkanShaderModuleWrapper>(id, shaderModule_map_); }
    const VulkanSurfaceKHRWrapper* GetVulkanSurfaceKHRWrapper(format::HandleId id) const { return GetWrapper<VulkanSurfaceKHRWrapper>(id, surfaceKHR_map_); }
    const VulkanSwapchainKHRWrapper* GetVulkanSwapchainKHRWrapper(format::HandleId id) const { return GetWrapper<VulkanSwapchainKHRWrapper>(id, swapchainKHR_map_); }
    const VulkanValidationCacheEXTWrapper* GetVulkanValidationCacheEXTWrapper(format::HandleId id) const { return GetWrapper<VulkanValidationCacheEXTWrapper>(id, validationCacheEXT_map_); }
    const VulkanVideoSessionKHRWrapper* GetVulkanVideoSessionKHRWrapper(format::HandleId id) const { return GetWrapper<VulkanVideoSessionKHRWrapper>(id, videoSessionKHR_map_); }
    const VulkanVideoSessionParametersKHRWrapper* GetVulkanVideoSessionParametersKHRWrapper(format::HandleId id) const { return GetWrapper<VulkanVideoSessionParametersKHRWrapper>(id, videoSessionParametersKHR_map_); }

    VulkanAccelerationStructureKHRWrapper* GetVulkanAccelerationStructureKHRWrapper(format::HandleId id) { return GetWrapper<VulkanAccelerationStructureKHRWrapper>(id, accelerationStructureKHR_map_); }
    VulkanAccelerationStructureNVWrapper* GetVulkanAccelerationStructureNVWrapper(format::HandleId id) { return GetWrapper<VulkanAccelerationStructureNVWrapper>(id, accelerationStructureNV_map_); }
    VulkanBufferWrapper* GetVulkanBufferWrapper(format::HandleId id) { return GetWrapper<VulkanBufferWrapper>(id, buffer_map_); }
    VulkanBufferViewWrapper* GetVulkanBufferViewWrapper(format::HandleId id) { return GetWrapper<VulkanBufferViewWrapper>(id, bufferView_map_); }
    VulkanCommandBufferWrapper* GetVulkanCommandBufferWrapper(format::HandleId id) { return GetWrapper<VulkanCommandBufferWrapper>(id, commandBuffer_map_); }
    VulkanCommandPoolWrapper* GetVulkanCommandPoolWrapper(format::HandleId id) { return GetWrapper<VulkanCommandPoolWrapper>(id, commandPool_map_); }
    VulkanDebugReportCallbackEXTWrapper* GetVulkanDebugReportCallbackEXTWrapper(format::HandleId id) { return GetWrapper<VulkanDebugReportCallbackEXTWrapper>(id, debugReportCallbackEXT_map_); }
    VulkanDebugUtilsMessengerEXTWrapper* GetVulkanDebugUtilsMessengerEXTWrapper(format::HandleId id) { return GetWrapper<VulkanDebugUtilsMessengerEXTWrapper>(id, debugUtilsMessengerEXT_map_); }
    VulkanDeferredOperationKHRWrapper* GetVulkanDeferredOperationKHRWrapper(format::HandleId id) { return GetWrapper<VulkanDeferredOperationKHRWrapper>(id, deferredOperationKHR_map_); }
    VulkanDescriptorPoolWrapper* GetVulkanDescriptorPoolWrapper(format::HandleId id) { return GetWrapper<VulkanDescriptorPoolWrapper>(id, descriptorPool_map_); }
    VulkanDescriptorSetWrapper* GetVulkanDescriptorSetWrapper(format::HandleId id) { return GetWrapper<VulkanDescriptorSetWrapper>(id, descriptorSet_map_); }
    VulkanDescriptorSetLayoutWrapper* GetVulkanDescriptorSetLayoutWrapper(format::HandleId id) { return GetWrapper<VulkanDescriptorSetLayoutWrapper>(id, descriptorSetLayout_map_); }
    VulkanDescriptorUpdateTemplateWrapper* GetVulkanDescriptorUpdateTemplateWrapper(format::HandleId id) { return GetWrapper<VulkanDescriptorUpdateTemplateWrapper>(id, descriptorUpdateTemplate_map_); }
    VulkanDeviceWrapper* GetVulkanDeviceWrapper(format::HandleId id) { return GetWrapper<VulkanDeviceWrapper>(id, device_map_); }
    VulkanDeviceMemoryWrapper* GetVulkanDeviceMemoryWrapper(format::HandleId id) { return GetWrapper<VulkanDeviceMemoryWrapper>(id, deviceMemory_map_); }
    VulkanDisplayKHRWrapper* GetVulkanDisplayKHRWrapper(format::HandleId id) { return GetWrapper<VulkanDisplayKHRWrapper>(id, displayKHR_map_); }
    VulkanDisplayModeKHRWrapper* GetVulkanDisplayModeKHRWrapper(format::HandleId id) { return GetWrapper<VulkanDisplayModeKHRWrapper>(id, displayModeKHR_map_); }
    VulkanEventWrapper* GetVulkanEventWrapper(format::HandleId id) { return GetWrapper<VulkanEventWrapper>(id, event_map_); }
    VulkanFenceWrapper* GetVulkanFenceWrapper(format::HandleId id) { return GetWrapper<VulkanFenceWrapper>(id, fence_map_); }
    VulkanFramebufferWrapper* GetVulkanFramebufferWrapper(format::HandleId id) { return GetWrapper<VulkanFramebufferWrapper>(id, framebuffer_map_); }
    VulkanImageWrapper* GetVulkanImageWrapper(format::HandleId id) { return GetWrapper<VulkanImageWrapper>(id, image_map_); }
    VulkanImageViewWrapper* GetVulkanImageViewWrapper(format::HandleId id) { return GetWrapper<VulkanImageViewWrapper>(id, imageView_map_); }
    VulkanIndirectCommandsLayoutNVWrapper* GetVulkanIndirectCommandsLayoutNVWrapper(format::HandleId id) { return GetWrapper<VulkanIndirectCommandsLayoutNVWrapper>(id, indirectCommandsLayoutNV_map_); }
    VulkanInstanceWrapper* GetVulkanInstanceWrapper(format::HandleId id) { return GetWrapper<VulkanInstanceWrapper>(id, instance_map_); }
    VulkanMicromapEXTWrapper* GetVulkanMicromapEXTWrapper(format::HandleId id) { return GetWrapper<VulkanMicromapEXTWrapper>(id, micromapEXT_map_); }
    VulkanOpticalFlowSessionNVWrapper* GetVulkanOpticalFlowSessionNVWrapper(format::HandleId id) { return GetWrapper<VulkanOpticalFlowSessionNVWrapper>(id, opticalFlowSessionNV_map_); }
    VulkanPerformanceConfigurationINTELWrapper* GetVulkanPerformanceConfigurationINTELWrapper(format::HandleId id) { return GetWrapper<VulkanPerformanceConfigurationINTELWrapper>(id, performanceConfigurationINTEL_map_); }
    VulkanPhysicalDeviceWrapper* GetVulkanPhysicalDeviceWrapper(format::HandleId id) { return GetWrapper<VulkanPhysicalDeviceWrapper>(id, physicalDevice_map_); }
    VulkanPipelineWrapper* GetVulkanPipelineWrapper(format::HandleId id) { return GetWrapper<VulkanPipelineWrapper>(id, pipeline_map_); }
    VulkanPipelineCacheWrapper* GetVulkanPipelineCacheWrapper(format::HandleId id) { return GetWrapper<VulkanPipelineCacheWrapper>(id, pipelineCache_map_); }
    VulkanPipelineLayoutWrapper* GetVulkanPipelineLayoutWrapper(format::HandleId id) { return GetWrapper<VulkanPipelineLayoutWrapper>(id, pipelineLayout_map_); }
    VulkanPrivateDataSlotWrapper* GetVulkanPrivateDataSlotWrapper(format::HandleId id) { return GetWrapper<VulkanPrivateDataSlotWrapper>(id, privateDataSlot_map_); }
    VulkanQueryPoolWrapper* GetVulkanQueryPoolWrapper(format::HandleId id) { return GetWrapper<VulkanQueryPoolWrapper>(id, queryPool_map_); }
    VulkanQueueWrapper* GetVulkanQueueWrapper(format::HandleId id) { return GetWrapper<VulkanQueueWrapper>(id, queue_map_); }
    VulkanRenderPassWrapper* GetVulkanRenderPassWrapper(format::HandleId id) { return GetWrapper<VulkanRenderPassWrapper>(id, renderPass_map_); }
    VulkanSamplerWrapper* GetVulkanSamplerWrapper(format::HandleId id) { return GetWrapper<VulkanSamplerWrapper>(id, sampler_map_); }
    VulkanSamplerYcbcrConversionWrapper* GetVulkanSamplerYcbcrConversionWrapper(format::HandleId id) { return GetWrapper<VulkanSamplerYcbcrConversionWrapper>(id, samplerYcbcrConversion_map_); }
    VulkanSemaphoreWrapper* GetVulkanSemaphoreWrapper(format::HandleId id) { return GetWrapper<VulkanSemaphoreWrapper>(id, semaphore_map_); }
    VulkanShaderEXTWrapper* GetVulkanShaderEXTWrapper(format::HandleId id) { return GetWrapper<VulkanShaderEXTWrapper>(id, shaderEXT_map_); }
    VulkanShaderModuleWrapper* GetVulkanShaderModuleWrapper(format::HandleId id) { return GetWrapper<VulkanShaderModuleWrapper>(id, shaderModule_map_); }
    VulkanSurfaceKHRWrapper* GetVulkanSurfaceKHRWrapper(format::HandleId id) { return GetWrapper<VulkanSurfaceKHRWrapper>(id, surfaceKHR_map_); }
    VulkanSwapchainKHRWrapper* GetVulkanSwapchainKHRWrapper(format::HandleId id) { return GetWrapper<VulkanSwapchainKHRWrapper>(id, swapchainKHR_map_); }
    VulkanValidationCacheEXTWrapper* GetVulkanValidationCacheEXTWrapper(format::HandleId id) { return GetWrapper<VulkanValidationCacheEXTWrapper>(id, validationCacheEXT_map_); }
    VulkanVideoSessionKHRWrapper* GetVulkanVideoSessionKHRWrapper(format::HandleId id) { return GetWrapper<VulkanVideoSessionKHRWrapper>(id, videoSessionKHR_map_); }
    VulkanVideoSessionParametersKHRWrapper* GetVulkanVideoSessionParametersKHRWrapper(format::HandleId id) { return GetWrapper<VulkanVideoSessionParametersKHRWrapper>(id, videoSessionParametersKHR_map_); }

    void VisitWrappers(std::function<void(VulkanAccelerationStructureKHRWrapper*)> visitor) const { for (auto entry : accelerationStructureKHR_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(VulkanAccelerationStructureNVWrapper*)> visitor) const { for (auto entry : accelerationStructureNV_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(VulkanBufferWrapper*)> visitor) const { for (auto entry : buffer_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(VulkanBufferViewWrapper*)> visitor) const { for (auto entry : bufferView_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(VulkanCommandBufferWrapper*)> visitor) const { for (auto entry : commandBuffer_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(VulkanCommandPoolWrapper*)> visitor) const { for (auto entry : commandPool_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(VulkanDebugReportCallbackEXTWrapper*)> visitor) const { for (auto entry : debugReportCallbackEXT_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(VulkanDebugUtilsMessengerEXTWrapper*)> visitor) const { for (auto entry : debugUtilsMessengerEXT_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(VulkanDeferredOperationKHRWrapper*)> visitor) const { for (auto entry : deferredOperationKHR_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(VulkanDescriptorPoolWrapper*)> visitor) const { for (auto entry : descriptorPool_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(VulkanDescriptorSetWrapper*)> visitor) const { for (auto entry : descriptorSet_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(VulkanDescriptorSetLayoutWrapper*)> visitor) const { for (auto entry : descriptorSetLayout_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(VulkanDescriptorUpdateTemplateWrapper*)> visitor) const { for (auto entry : descriptorUpdateTemplate_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(VulkanDeviceWrapper*)> visitor) const { for (auto entry : device_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(VulkanDeviceMemoryWrapper*)> visitor) const { for (auto entry : deviceMemory_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(VulkanDisplayKHRWrapper*)> visitor) const { for (auto entry : displayKHR_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(VulkanDisplayModeKHRWrapper*)> visitor) const { for (auto entry : displayModeKHR_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(VulkanEventWrapper*)> visitor) const { for (auto entry : event_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(VulkanFenceWrapper*)> visitor) const { for (auto entry : fence_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(VulkanFramebufferWrapper*)> visitor) const { for (auto entry : framebuffer_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(VulkanImageWrapper*)> visitor) const { for (auto entry : image_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(VulkanImageViewWrapper*)> visitor) const { for (auto entry : imageView_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(VulkanIndirectCommandsLayoutNVWrapper*)> visitor) const { for (auto entry : indirectCommandsLayoutNV_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(VulkanInstanceWrapper*)> visitor) const { for (auto entry : instance_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(VulkanMicromapEXTWrapper*)> visitor) const { for (auto entry : micromapEXT_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(VulkanOpticalFlowSessionNVWrapper*)> visitor) const { for (auto entry : opticalFlowSessionNV_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(VulkanPerformanceConfigurationINTELWrapper*)> visitor) const { for (auto entry : performanceConfigurationINTEL_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(VulkanPhysicalDeviceWrapper*)> visitor) const { for (auto entry : physicalDevice_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(VulkanPipelineWrapper*)> visitor) const { for (auto entry : pipeline_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(VulkanPipelineCacheWrapper*)> visitor) const { for (auto entry : pipelineCache_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(VulkanPipelineLayoutWrapper*)> visitor) const { for (auto entry : pipelineLayout_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(VulkanPrivateDataSlotWrapper*)> visitor) const { for (auto entry : privateDataSlot_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(VulkanQueryPoolWrapper*)> visitor) const { for (auto entry : queryPool_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(VulkanQueueWrapper*)> visitor) const { for (auto entry : queue_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(VulkanRenderPassWrapper*)> visitor) const { for (auto entry : renderPass_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(VulkanSamplerWrapper*)> visitor) const { for (auto entry : sampler_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(VulkanSamplerYcbcrConversionWrapper*)> visitor) const { for (auto entry : samplerYcbcrConversion_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(VulkanSemaphoreWrapper*)> visitor) const { for (auto entry : semaphore_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(VulkanShaderEXTWrapper*)> visitor) const { for (auto entry : shaderEXT_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(VulkanShaderModuleWrapper*)> visitor) const { for (auto entry : shaderModule_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(VulkanSurfaceKHRWrapper*)> visitor) const { for (auto entry : surfaceKHR_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(VulkanSwapchainKHRWrapper*)> visitor) const { for (auto entry : swapchainKHR_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(VulkanValidationCacheEXTWrapper*)> visitor) const { for (auto entry : validationCacheEXT_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(VulkanVideoSessionKHRWrapper*)> visitor) const { for (auto entry : videoSessionKHR_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(VulkanVideoSessionParametersKHRWrapper*)> visitor) const { for (auto entry : videoSessionParametersKHR_map_) { visitor(entry.second); } }

  private:
    std::map<format::HandleId, VulkanAccelerationStructureKHRWrapper*> accelerationStructureKHR_map_;
    std::map<format::HandleId, VulkanAccelerationStructureNVWrapper*> accelerationStructureNV_map_;
    std::map<format::HandleId, VulkanBufferWrapper*> buffer_map_;
    std::map<format::HandleId, VulkanBufferViewWrapper*> bufferView_map_;
    std::map<format::HandleId, VulkanCommandBufferWrapper*> commandBuffer_map_;
    std::map<format::HandleId, VulkanCommandPoolWrapper*> commandPool_map_;
    std::map<format::HandleId, VulkanDebugReportCallbackEXTWrapper*> debugReportCallbackEXT_map_;
    std::map<format::HandleId, VulkanDebugUtilsMessengerEXTWrapper*> debugUtilsMessengerEXT_map_;
    std::map<format::HandleId, VulkanDeferredOperationKHRWrapper*> deferredOperationKHR_map_;
    std::map<format::HandleId, VulkanDescriptorPoolWrapper*> descriptorPool_map_;
    std::map<format::HandleId, VulkanDescriptorSetWrapper*> descriptorSet_map_;
    std::map<format::HandleId, VulkanDescriptorSetLayoutWrapper*> descriptorSetLayout_map_;
    std::map<format::HandleId, VulkanDescriptorUpdateTemplateWrapper*> descriptorUpdateTemplate_map_;
    std::map<format::HandleId, VulkanDeviceWrapper*> device_map_;
    std::map<format::HandleId, VulkanDeviceMemoryWrapper*> deviceMemory_map_;
    std::map<format::HandleId, VulkanDisplayKHRWrapper*> displayKHR_map_;
    std::map<format::HandleId, VulkanDisplayModeKHRWrapper*> displayModeKHR_map_;
    std::map<format::HandleId, VulkanEventWrapper*> event_map_;
    std::map<format::HandleId, VulkanFenceWrapper*> fence_map_;
    std::map<format::HandleId, VulkanFramebufferWrapper*> framebuffer_map_;
    std::map<format::HandleId, VulkanImageWrapper*> image_map_;
    std::map<format::HandleId, VulkanImageViewWrapper*> imageView_map_;
    std::map<format::HandleId, VulkanIndirectCommandsLayoutNVWrapper*> indirectCommandsLayoutNV_map_;
    std::map<format::HandleId, VulkanInstanceWrapper*> instance_map_;
    std::map<format::HandleId, VulkanMicromapEXTWrapper*> micromapEXT_map_;
    std::map<format::HandleId, VulkanOpticalFlowSessionNVWrapper*> opticalFlowSessionNV_map_;
    std::map<format::HandleId, VulkanPerformanceConfigurationINTELWrapper*> performanceConfigurationINTEL_map_;
    std::map<format::HandleId, VulkanPhysicalDeviceWrapper*> physicalDevice_map_;
    std::map<format::HandleId, VulkanPipelineWrapper*> pipeline_map_;
    std::map<format::HandleId, VulkanPipelineCacheWrapper*> pipelineCache_map_;
    std::map<format::HandleId, VulkanPipelineLayoutWrapper*> pipelineLayout_map_;
    std::map<format::HandleId, VulkanPrivateDataSlotWrapper*> privateDataSlot_map_;
    std::map<format::HandleId, VulkanQueryPoolWrapper*> queryPool_map_;
    std::map<format::HandleId, VulkanQueueWrapper*> queue_map_;
    std::map<format::HandleId, VulkanRenderPassWrapper*> renderPass_map_;
    std::map<format::HandleId, VulkanSamplerWrapper*> sampler_map_;
    std::map<format::HandleId, VulkanSamplerYcbcrConversionWrapper*> samplerYcbcrConversion_map_;
    std::map<format::HandleId, VulkanSemaphoreWrapper*> semaphore_map_;
    std::map<format::HandleId, VulkanShaderEXTWrapper*> shaderEXT_map_;
    std::map<format::HandleId, VulkanShaderModuleWrapper*> shaderModule_map_;
    std::map<format::HandleId, VulkanSurfaceKHRWrapper*> surfaceKHR_map_;
    std::map<format::HandleId, VulkanSwapchainKHRWrapper*> swapchainKHR_map_;
    std::map<format::HandleId, VulkanValidationCacheEXTWrapper*> validationCacheEXT_map_;
    std::map<format::HandleId, VulkanVideoSessionKHRWrapper*> videoSessionKHR_map_;
    std::map<format::HandleId, VulkanVideoSessionParametersKHRWrapper*> videoSessionParametersKHR_map_;
};

class VulkanStateHandleTable : VulkanStateTableBase
{
  public:
    VulkanStateHandleTable() {}
    ~VulkanStateHandleTable() {}

    bool InsertWrapper(VulkanAccelerationStructureKHRWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, accelerationStructureKHR_map_); }
    bool InsertWrapper(VulkanAccelerationStructureNVWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, accelerationStructureNV_map_); }
    bool InsertWrapper(VulkanBufferWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, buffer_map_); }
    bool InsertWrapper(VulkanBufferViewWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, bufferView_map_); }
    bool InsertWrapper(VulkanCommandBufferWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, commandBuffer_map_); }
    bool InsertWrapper(VulkanCommandPoolWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, commandPool_map_); }
    bool InsertWrapper(VulkanDebugReportCallbackEXTWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, debugReportCallbackEXT_map_); }
    bool InsertWrapper(VulkanDebugUtilsMessengerEXTWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, debugUtilsMessengerEXT_map_); }
    bool InsertWrapper(VulkanDeferredOperationKHRWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, deferredOperationKHR_map_); }
    bool InsertWrapper(VulkanDescriptorPoolWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, descriptorPool_map_); }
    bool InsertWrapper(VulkanDescriptorSetWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, descriptorSet_map_); }
    bool InsertWrapper(VulkanDescriptorSetLayoutWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, descriptorSetLayout_map_); }
    bool InsertWrapper(VulkanDescriptorUpdateTemplateWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, descriptorUpdateTemplate_map_); }
    bool InsertWrapper(VulkanDeviceWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, device_map_); }
    bool InsertWrapper(VulkanDeviceMemoryWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, deviceMemory_map_); }
    bool InsertWrapper(VulkanDisplayKHRWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, displayKHR_map_); }
    bool InsertWrapper(VulkanDisplayModeKHRWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, displayModeKHR_map_); }
    bool InsertWrapper(VulkanEventWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, event_map_); }
    bool InsertWrapper(VulkanFenceWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, fence_map_); }
    bool InsertWrapper(VulkanFramebufferWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, framebuffer_map_); }
    bool InsertWrapper(VulkanImageWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, image_map_); }
    bool InsertWrapper(VulkanImageViewWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, imageView_map_); }
    bool InsertWrapper(VulkanIndirectCommandsLayoutNVWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, indirectCommandsLayoutNV_map_); }
    bool InsertWrapper(VulkanInstanceWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, instance_map_); }
    bool InsertWrapper(VulkanMicromapEXTWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, micromapEXT_map_); }
    bool InsertWrapper(VulkanOpticalFlowSessionNVWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, opticalFlowSessionNV_map_); }
    bool InsertWrapper(VulkanPerformanceConfigurationINTELWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, performanceConfigurationINTEL_map_); }
    bool InsertWrapper(VulkanPhysicalDeviceWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, physicalDevice_map_); }
    bool InsertWrapper(VulkanPipelineWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, pipeline_map_); }
    bool InsertWrapper(VulkanPipelineCacheWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, pipelineCache_map_); }
    bool InsertWrapper(VulkanPipelineLayoutWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, pipelineLayout_map_); }
    bool InsertWrapper(VulkanPrivateDataSlotWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, privateDataSlot_map_); }
    bool InsertWrapper(VulkanQueryPoolWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, queryPool_map_); }
    bool InsertWrapper(VulkanQueueWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, queue_map_); }
    bool InsertWrapper(VulkanRenderPassWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, renderPass_map_); }
    bool InsertWrapper(VulkanSamplerWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, sampler_map_); }
    bool InsertWrapper(VulkanSamplerYcbcrConversionWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, samplerYcbcrConversion_map_); }
    bool InsertWrapper(VulkanSemaphoreWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, semaphore_map_); }
    bool InsertWrapper(VulkanShaderEXTWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, shaderEXT_map_); }
    bool InsertWrapper(VulkanShaderModuleWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, shaderModule_map_); }
    bool InsertWrapper(VulkanSurfaceKHRWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, surfaceKHR_map_); }
    bool InsertWrapper(VulkanSwapchainKHRWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, swapchainKHR_map_); }
    bool InsertWrapper(VulkanValidationCacheEXTWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, validationCacheEXT_map_); }
    bool InsertWrapper(VulkanVideoSessionKHRWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, videoSessionKHR_map_); }
    bool InsertWrapper(VulkanVideoSessionParametersKHRWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, videoSessionParametersKHR_map_); }

    bool RemoveWrapper(const VulkanAccelerationStructureKHRWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, accelerationStructureKHR_map_);
    }
    bool RemoveWrapper(const VulkanAccelerationStructureNVWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, accelerationStructureNV_map_);
    }
    bool RemoveWrapper(const VulkanBufferWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, buffer_map_);
    }
    bool RemoveWrapper(const VulkanBufferViewWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, bufferView_map_);
    }
    bool RemoveWrapper(const VulkanCommandBufferWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, commandBuffer_map_);
    }
    bool RemoveWrapper(const VulkanCommandPoolWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, commandPool_map_);
    }
    bool RemoveWrapper(const VulkanDebugReportCallbackEXTWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, debugReportCallbackEXT_map_);
    }
    bool RemoveWrapper(const VulkanDebugUtilsMessengerEXTWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, debugUtilsMessengerEXT_map_);
    }
    bool RemoveWrapper(const VulkanDeferredOperationKHRWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, deferredOperationKHR_map_);
    }
    bool RemoveWrapper(const VulkanDescriptorPoolWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, descriptorPool_map_);
    }
    bool RemoveWrapper(const VulkanDescriptorSetWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, descriptorSet_map_);
    }
    bool RemoveWrapper(const VulkanDescriptorSetLayoutWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, descriptorSetLayout_map_);
    }
    bool RemoveWrapper(const VulkanDescriptorUpdateTemplateWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, descriptorUpdateTemplate_map_);
    }
    bool RemoveWrapper(const VulkanDeviceWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, device_map_);
    }
    bool RemoveWrapper(const VulkanDeviceMemoryWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, deviceMemory_map_);
    }
    bool RemoveWrapper(const VulkanDisplayKHRWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, displayKHR_map_);
    }
    bool RemoveWrapper(const VulkanDisplayModeKHRWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, displayModeKHR_map_);
    }
    bool RemoveWrapper(const VulkanEventWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, event_map_);
    }
    bool RemoveWrapper(const VulkanFenceWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, fence_map_);
    }
    bool RemoveWrapper(const VulkanFramebufferWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, framebuffer_map_);
    }
    bool RemoveWrapper(const VulkanImageWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, image_map_);
    }
    bool RemoveWrapper(const VulkanImageViewWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, imageView_map_);
    }
    bool RemoveWrapper(const VulkanIndirectCommandsLayoutNVWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, indirectCommandsLayoutNV_map_);
    }
    bool RemoveWrapper(const VulkanInstanceWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, instance_map_);
    }
    bool RemoveWrapper(const VulkanMicromapEXTWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, micromapEXT_map_);
    }
    bool RemoveWrapper(const VulkanOpticalFlowSessionNVWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, opticalFlowSessionNV_map_);
    }
    bool RemoveWrapper(const VulkanPerformanceConfigurationINTELWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, performanceConfigurationINTEL_map_);
    }
    bool RemoveWrapper(const VulkanPhysicalDeviceWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, physicalDevice_map_);
    }
    bool RemoveWrapper(const VulkanPipelineWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, pipeline_map_);
    }
    bool RemoveWrapper(const VulkanPipelineCacheWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, pipelineCache_map_);
    }
    bool RemoveWrapper(const VulkanPipelineLayoutWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, pipelineLayout_map_);
    }
    bool RemoveWrapper(const VulkanPrivateDataSlotWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, privateDataSlot_map_);
    }
    bool RemoveWrapper(const VulkanQueryPoolWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, queryPool_map_);
    }
    bool RemoveWrapper(const VulkanQueueWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, queue_map_);
    }
    bool RemoveWrapper(const VulkanRenderPassWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, renderPass_map_);
    }
    bool RemoveWrapper(const VulkanSamplerWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, sampler_map_);
    }
    bool RemoveWrapper(const VulkanSamplerYcbcrConversionWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, samplerYcbcrConversion_map_);
    }
    bool RemoveWrapper(const VulkanSemaphoreWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, semaphore_map_);
    }
    bool RemoveWrapper(const VulkanShaderEXTWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, shaderEXT_map_);
    }
    bool RemoveWrapper(const VulkanShaderModuleWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, shaderModule_map_);
    }
    bool RemoveWrapper(const VulkanSurfaceKHRWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, surfaceKHR_map_);
    }
    bool RemoveWrapper(const VulkanSwapchainKHRWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, swapchainKHR_map_);
    }
    bool RemoveWrapper(const VulkanValidationCacheEXTWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, validationCacheEXT_map_);
    }
    bool RemoveWrapper(const VulkanVideoSessionKHRWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, videoSessionKHR_map_);
    }
    bool RemoveWrapper(const VulkanVideoSessionParametersKHRWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, videoSessionParametersKHR_map_);
    }

    template<typename Wrapper> const Wrapper* GetWrapper(typename Wrapper::HandleType handle) const { return nullptr; }

    template<typename Wrapper> Wrapper* GetWrapper(typename Wrapper::HandleType handle) { return nullptr; }

  private:
    std::unordered_map<VkAccelerationStructureKHR, VulkanAccelerationStructureKHRWrapper*> accelerationStructureKHR_map_;
    std::unordered_map<VkAccelerationStructureNV, VulkanAccelerationStructureNVWrapper*> accelerationStructureNV_map_;
    std::unordered_map<VkBuffer, VulkanBufferWrapper*> buffer_map_;
    std::unordered_map<VkBufferView, VulkanBufferViewWrapper*> bufferView_map_;
    std::unordered_map<VkCommandBuffer, VulkanCommandBufferWrapper*> commandBuffer_map_;
    std::unordered_map<VkCommandPool, VulkanCommandPoolWrapper*> commandPool_map_;
    std::unordered_map<VkDebugReportCallbackEXT, VulkanDebugReportCallbackEXTWrapper*> debugReportCallbackEXT_map_;
    std::unordered_map<VkDebugUtilsMessengerEXT, VulkanDebugUtilsMessengerEXTWrapper*> debugUtilsMessengerEXT_map_;
    std::unordered_map<VkDeferredOperationKHR, VulkanDeferredOperationKHRWrapper*> deferredOperationKHR_map_;
    std::unordered_map<VkDescriptorPool, VulkanDescriptorPoolWrapper*> descriptorPool_map_;
    std::unordered_map<VkDescriptorSet, VulkanDescriptorSetWrapper*> descriptorSet_map_;
    std::unordered_map<VkDescriptorSetLayout, VulkanDescriptorSetLayoutWrapper*> descriptorSetLayout_map_;
    std::unordered_map<VkDescriptorUpdateTemplate, VulkanDescriptorUpdateTemplateWrapper*> descriptorUpdateTemplate_map_;
    std::unordered_map<VkDevice, VulkanDeviceWrapper*> device_map_;
    std::unordered_map<VkDeviceMemory, VulkanDeviceMemoryWrapper*> deviceMemory_map_;
    std::unordered_map<VkDisplayKHR, VulkanDisplayKHRWrapper*> displayKHR_map_;
    std::unordered_map<VkDisplayModeKHR, VulkanDisplayModeKHRWrapper*> displayModeKHR_map_;
    std::unordered_map<VkEvent, VulkanEventWrapper*> event_map_;
    std::unordered_map<VkFence, VulkanFenceWrapper*> fence_map_;
    std::unordered_map<VkFramebuffer, VulkanFramebufferWrapper*> framebuffer_map_;
    std::unordered_map<VkImage, VulkanImageWrapper*> image_map_;
    std::unordered_map<VkImageView, VulkanImageViewWrapper*> imageView_map_;
    std::unordered_map<VkIndirectCommandsLayoutNV, VulkanIndirectCommandsLayoutNVWrapper*> indirectCommandsLayoutNV_map_;
    std::unordered_map<VkInstance, VulkanInstanceWrapper*> instance_map_;
    std::unordered_map<VkMicromapEXT, VulkanMicromapEXTWrapper*> micromapEXT_map_;
    std::unordered_map<VkOpticalFlowSessionNV, VulkanOpticalFlowSessionNVWrapper*> opticalFlowSessionNV_map_;
    std::unordered_map<VkPerformanceConfigurationINTEL, VulkanPerformanceConfigurationINTELWrapper*> performanceConfigurationINTEL_map_;
    std::unordered_map<VkPhysicalDevice, VulkanPhysicalDeviceWrapper*> physicalDevice_map_;
    std::unordered_map<VkPipeline, VulkanPipelineWrapper*> pipeline_map_;
    std::unordered_map<VkPipelineCache, VulkanPipelineCacheWrapper*> pipelineCache_map_;
    std::unordered_map<VkPipelineLayout, VulkanPipelineLayoutWrapper*> pipelineLayout_map_;
    std::unordered_map<VkPrivateDataSlot, VulkanPrivateDataSlotWrapper*> privateDataSlot_map_;
    std::unordered_map<VkQueryPool, VulkanQueryPoolWrapper*> queryPool_map_;
    std::unordered_map<VkQueue, VulkanQueueWrapper*> queue_map_;
    std::unordered_map<VkRenderPass, VulkanRenderPassWrapper*> renderPass_map_;
    std::unordered_map<VkSampler, VulkanSamplerWrapper*> sampler_map_;
    std::unordered_map<VkSamplerYcbcrConversion, VulkanSamplerYcbcrConversionWrapper*> samplerYcbcrConversion_map_;
    std::unordered_map<VkSemaphore, VulkanSemaphoreWrapper*> semaphore_map_;
    std::unordered_map<VkShaderEXT, VulkanShaderEXTWrapper*> shaderEXT_map_;
    std::unordered_map<VkShaderModule, VulkanShaderModuleWrapper*> shaderModule_map_;
    std::unordered_map<VkSurfaceKHR, VulkanSurfaceKHRWrapper*> surfaceKHR_map_;
    std::unordered_map<VkSwapchainKHR, VulkanSwapchainKHRWrapper*> swapchainKHR_map_;
    std::unordered_map<VkValidationCacheEXT, VulkanValidationCacheEXTWrapper*> validationCacheEXT_map_;
    std::unordered_map<VkVideoSessionKHR, VulkanVideoSessionKHRWrapper*> videoSessionKHR_map_;
    std::unordered_map<VkVideoSessionParametersKHR, VulkanVideoSessionParametersKHRWrapper*> videoSessionParametersKHR_map_;
};

template<> inline const VulkanAccelerationStructureKHRWrapper* VulkanStateHandleTable::GetWrapper<VulkanAccelerationStructureKHRWrapper>(VkAccelerationStructureKHR handle) const { return VulkanStateTableBase::GetWrapper(handle, accelerationStructureKHR_map_); }
template<> inline const VulkanAccelerationStructureNVWrapper* VulkanStateHandleTable::GetWrapper<VulkanAccelerationStructureNVWrapper>(VkAccelerationStructureNV handle) const { return VulkanStateTableBase::GetWrapper(handle, accelerationStructureNV_map_); }
template<> inline const VulkanBufferWrapper* VulkanStateHandleTable::GetWrapper<VulkanBufferWrapper>(VkBuffer handle) const { return VulkanStateTableBase::GetWrapper(handle, buffer_map_); }
template<> inline const VulkanBufferViewWrapper* VulkanStateHandleTable::GetWrapper<VulkanBufferViewWrapper>(VkBufferView handle) const { return VulkanStateTableBase::GetWrapper(handle, bufferView_map_); }
template<> inline const VulkanCommandBufferWrapper* VulkanStateHandleTable::GetWrapper<VulkanCommandBufferWrapper>(VkCommandBuffer handle) const { return VulkanStateTableBase::GetWrapper(handle, commandBuffer_map_); }
template<> inline const VulkanCommandPoolWrapper* VulkanStateHandleTable::GetWrapper<VulkanCommandPoolWrapper>(VkCommandPool handle) const { return VulkanStateTableBase::GetWrapper(handle, commandPool_map_); }
template<> inline const VulkanDebugReportCallbackEXTWrapper* VulkanStateHandleTable::GetWrapper<VulkanDebugReportCallbackEXTWrapper>(VkDebugReportCallbackEXT handle) const { return VulkanStateTableBase::GetWrapper(handle, debugReportCallbackEXT_map_); }
template<> inline const VulkanDebugUtilsMessengerEXTWrapper* VulkanStateHandleTable::GetWrapper<VulkanDebugUtilsMessengerEXTWrapper>(VkDebugUtilsMessengerEXT handle) const { return VulkanStateTableBase::GetWrapper(handle, debugUtilsMessengerEXT_map_); }
template<> inline const VulkanDeferredOperationKHRWrapper* VulkanStateHandleTable::GetWrapper<VulkanDeferredOperationKHRWrapper>(VkDeferredOperationKHR handle) const { return VulkanStateTableBase::GetWrapper(handle, deferredOperationKHR_map_); }
template<> inline const VulkanDescriptorPoolWrapper* VulkanStateHandleTable::GetWrapper<VulkanDescriptorPoolWrapper>(VkDescriptorPool handle) const { return VulkanStateTableBase::GetWrapper(handle, descriptorPool_map_); }
template<> inline const VulkanDescriptorSetWrapper* VulkanStateHandleTable::GetWrapper<VulkanDescriptorSetWrapper>(VkDescriptorSet handle) const { return VulkanStateTableBase::GetWrapper(handle, descriptorSet_map_); }
template<> inline const VulkanDescriptorSetLayoutWrapper* VulkanStateHandleTable::GetWrapper<VulkanDescriptorSetLayoutWrapper>(VkDescriptorSetLayout handle) const { return VulkanStateTableBase::GetWrapper(handle, descriptorSetLayout_map_); }
template<> inline const VulkanDescriptorUpdateTemplateWrapper* VulkanStateHandleTable::GetWrapper<VulkanDescriptorUpdateTemplateWrapper>(VkDescriptorUpdateTemplate handle) const { return VulkanStateTableBase::GetWrapper(handle, descriptorUpdateTemplate_map_); }
template<> inline const VulkanDeviceWrapper* VulkanStateHandleTable::GetWrapper<VulkanDeviceWrapper>(VkDevice handle) const { return VulkanStateTableBase::GetWrapper(handle, device_map_); }
template<> inline const VulkanDeviceMemoryWrapper* VulkanStateHandleTable::GetWrapper<VulkanDeviceMemoryWrapper>(VkDeviceMemory handle) const { return VulkanStateTableBase::GetWrapper(handle, deviceMemory_map_); }
template<> inline const VulkanDisplayKHRWrapper* VulkanStateHandleTable::GetWrapper<VulkanDisplayKHRWrapper>(VkDisplayKHR handle) const { return VulkanStateTableBase::GetWrapper(handle, displayKHR_map_); }
template<> inline const VulkanDisplayModeKHRWrapper* VulkanStateHandleTable::GetWrapper<VulkanDisplayModeKHRWrapper>(VkDisplayModeKHR handle) const { return VulkanStateTableBase::GetWrapper(handle, displayModeKHR_map_); }
template<> inline const VulkanEventWrapper* VulkanStateHandleTable::GetWrapper<VulkanEventWrapper>(VkEvent handle) const { return VulkanStateTableBase::GetWrapper(handle, event_map_); }
template<> inline const VulkanFenceWrapper* VulkanStateHandleTable::GetWrapper<VulkanFenceWrapper>(VkFence handle) const { return VulkanStateTableBase::GetWrapper(handle, fence_map_); }
template<> inline const VulkanFramebufferWrapper* VulkanStateHandleTable::GetWrapper<VulkanFramebufferWrapper>(VkFramebuffer handle) const { return VulkanStateTableBase::GetWrapper(handle, framebuffer_map_); }
template<> inline const VulkanImageWrapper* VulkanStateHandleTable::GetWrapper<VulkanImageWrapper>(VkImage handle) const { return VulkanStateTableBase::GetWrapper(handle, image_map_); }
template<> inline const VulkanImageViewWrapper* VulkanStateHandleTable::GetWrapper<VulkanImageViewWrapper>(VkImageView handle) const { return VulkanStateTableBase::GetWrapper(handle, imageView_map_); }
template<> inline const VulkanIndirectCommandsLayoutNVWrapper* VulkanStateHandleTable::GetWrapper<VulkanIndirectCommandsLayoutNVWrapper>(VkIndirectCommandsLayoutNV handle) const { return VulkanStateTableBase::GetWrapper(handle, indirectCommandsLayoutNV_map_); }
template<> inline const VulkanInstanceWrapper* VulkanStateHandleTable::GetWrapper<VulkanInstanceWrapper>(VkInstance handle) const { return VulkanStateTableBase::GetWrapper(handle, instance_map_); }
template<> inline const VulkanMicromapEXTWrapper* VulkanStateHandleTable::GetWrapper<VulkanMicromapEXTWrapper>(VkMicromapEXT handle) const { return VulkanStateTableBase::GetWrapper(handle, micromapEXT_map_); }
template<> inline const VulkanOpticalFlowSessionNVWrapper* VulkanStateHandleTable::GetWrapper<VulkanOpticalFlowSessionNVWrapper>(VkOpticalFlowSessionNV handle) const { return VulkanStateTableBase::GetWrapper(handle, opticalFlowSessionNV_map_); }
template<> inline const VulkanPerformanceConfigurationINTELWrapper* VulkanStateHandleTable::GetWrapper<VulkanPerformanceConfigurationINTELWrapper>(VkPerformanceConfigurationINTEL handle) const { return VulkanStateTableBase::GetWrapper(handle, performanceConfigurationINTEL_map_); }
template<> inline const VulkanPhysicalDeviceWrapper* VulkanStateHandleTable::GetWrapper<VulkanPhysicalDeviceWrapper>(VkPhysicalDevice handle) const { return VulkanStateTableBase::GetWrapper(handle, physicalDevice_map_); }
template<> inline const VulkanPipelineWrapper* VulkanStateHandleTable::GetWrapper<VulkanPipelineWrapper>(VkPipeline handle) const { return VulkanStateTableBase::GetWrapper(handle, pipeline_map_); }
template<> inline const VulkanPipelineCacheWrapper* VulkanStateHandleTable::GetWrapper<VulkanPipelineCacheWrapper>(VkPipelineCache handle) const { return VulkanStateTableBase::GetWrapper(handle, pipelineCache_map_); }
template<> inline const VulkanPipelineLayoutWrapper* VulkanStateHandleTable::GetWrapper<VulkanPipelineLayoutWrapper>(VkPipelineLayout handle) const { return VulkanStateTableBase::GetWrapper(handle, pipelineLayout_map_); }
template<> inline const VulkanPrivateDataSlotWrapper* VulkanStateHandleTable::GetWrapper<VulkanPrivateDataSlotWrapper>(VkPrivateDataSlot handle) const { return VulkanStateTableBase::GetWrapper(handle, privateDataSlot_map_); }
template<> inline const VulkanQueryPoolWrapper* VulkanStateHandleTable::GetWrapper<VulkanQueryPoolWrapper>(VkQueryPool handle) const { return VulkanStateTableBase::GetWrapper(handle, queryPool_map_); }
template<> inline const VulkanQueueWrapper* VulkanStateHandleTable::GetWrapper<VulkanQueueWrapper>(VkQueue handle) const { return VulkanStateTableBase::GetWrapper(handle, queue_map_); }
template<> inline const VulkanRenderPassWrapper* VulkanStateHandleTable::GetWrapper<VulkanRenderPassWrapper>(VkRenderPass handle) const { return VulkanStateTableBase::GetWrapper(handle, renderPass_map_); }
template<> inline const VulkanSamplerWrapper* VulkanStateHandleTable::GetWrapper<VulkanSamplerWrapper>(VkSampler handle) const { return VulkanStateTableBase::GetWrapper(handle, sampler_map_); }
template<> inline const VulkanSamplerYcbcrConversionWrapper* VulkanStateHandleTable::GetWrapper<VulkanSamplerYcbcrConversionWrapper>(VkSamplerYcbcrConversion handle) const { return VulkanStateTableBase::GetWrapper(handle, samplerYcbcrConversion_map_); }
template<> inline const VulkanSemaphoreWrapper* VulkanStateHandleTable::GetWrapper<VulkanSemaphoreWrapper>(VkSemaphore handle) const { return VulkanStateTableBase::GetWrapper(handle, semaphore_map_); }
template<> inline const VulkanShaderEXTWrapper* VulkanStateHandleTable::GetWrapper<VulkanShaderEXTWrapper>(VkShaderEXT handle) const { return VulkanStateTableBase::GetWrapper(handle, shaderEXT_map_); }
template<> inline const VulkanShaderModuleWrapper* VulkanStateHandleTable::GetWrapper<VulkanShaderModuleWrapper>(VkShaderModule handle) const { return VulkanStateTableBase::GetWrapper(handle, shaderModule_map_); }
template<> inline const VulkanSurfaceKHRWrapper* VulkanStateHandleTable::GetWrapper<VulkanSurfaceKHRWrapper>(VkSurfaceKHR handle) const { return VulkanStateTableBase::GetWrapper(handle, surfaceKHR_map_); }
template<> inline const VulkanSwapchainKHRWrapper* VulkanStateHandleTable::GetWrapper<VulkanSwapchainKHRWrapper>(VkSwapchainKHR handle) const { return VulkanStateTableBase::GetWrapper(handle, swapchainKHR_map_); }
template<> inline const VulkanValidationCacheEXTWrapper* VulkanStateHandleTable::GetWrapper<VulkanValidationCacheEXTWrapper>(VkValidationCacheEXT handle) const { return VulkanStateTableBase::GetWrapper(handle, validationCacheEXT_map_); }
template<> inline const VulkanVideoSessionKHRWrapper* VulkanStateHandleTable::GetWrapper<VulkanVideoSessionKHRWrapper>(VkVideoSessionKHR handle) const { return VulkanStateTableBase::GetWrapper(handle, videoSessionKHR_map_); }
template<> inline const VulkanVideoSessionParametersKHRWrapper* VulkanStateHandleTable::GetWrapper<VulkanVideoSessionParametersKHRWrapper>(VkVideoSessionParametersKHR handle) const { return VulkanStateTableBase::GetWrapper(handle, videoSessionParametersKHR_map_); }

template<> inline VulkanAccelerationStructureKHRWrapper* VulkanStateHandleTable::GetWrapper<VulkanAccelerationStructureKHRWrapper>(VkAccelerationStructureKHR handle) { return VulkanStateTableBase::GetWrapper(handle, accelerationStructureKHR_map_); }
template<> inline VulkanAccelerationStructureNVWrapper* VulkanStateHandleTable::GetWrapper<VulkanAccelerationStructureNVWrapper>(VkAccelerationStructureNV handle) { return VulkanStateTableBase::GetWrapper(handle, accelerationStructureNV_map_); }
template<> inline VulkanBufferWrapper* VulkanStateHandleTable::GetWrapper<VulkanBufferWrapper>(VkBuffer handle) { return VulkanStateTableBase::GetWrapper(handle, buffer_map_); }
template<> inline VulkanBufferViewWrapper* VulkanStateHandleTable::GetWrapper<VulkanBufferViewWrapper>(VkBufferView handle) { return VulkanStateTableBase::GetWrapper(handle, bufferView_map_); }
template<> inline VulkanCommandBufferWrapper* VulkanStateHandleTable::GetWrapper<VulkanCommandBufferWrapper>(VkCommandBuffer handle) { return VulkanStateTableBase::GetWrapper(handle, commandBuffer_map_); }
template<> inline VulkanCommandPoolWrapper* VulkanStateHandleTable::GetWrapper<VulkanCommandPoolWrapper>(VkCommandPool handle) { return VulkanStateTableBase::GetWrapper(handle, commandPool_map_); }
template<> inline VulkanDebugReportCallbackEXTWrapper* VulkanStateHandleTable::GetWrapper<VulkanDebugReportCallbackEXTWrapper>(VkDebugReportCallbackEXT handle) { return VulkanStateTableBase::GetWrapper(handle, debugReportCallbackEXT_map_); }
template<> inline VulkanDebugUtilsMessengerEXTWrapper* VulkanStateHandleTable::GetWrapper<VulkanDebugUtilsMessengerEXTWrapper>(VkDebugUtilsMessengerEXT handle) { return VulkanStateTableBase::GetWrapper(handle, debugUtilsMessengerEXT_map_); }
template<> inline VulkanDeferredOperationKHRWrapper* VulkanStateHandleTable::GetWrapper<VulkanDeferredOperationKHRWrapper>(VkDeferredOperationKHR handle) { return VulkanStateTableBase::GetWrapper(handle, deferredOperationKHR_map_); }
template<> inline VulkanDescriptorPoolWrapper* VulkanStateHandleTable::GetWrapper<VulkanDescriptorPoolWrapper>(VkDescriptorPool handle) { return VulkanStateTableBase::GetWrapper(handle, descriptorPool_map_); }
template<> inline VulkanDescriptorSetWrapper* VulkanStateHandleTable::GetWrapper<VulkanDescriptorSetWrapper>(VkDescriptorSet handle) { return VulkanStateTableBase::GetWrapper(handle, descriptorSet_map_); }
template<> inline VulkanDescriptorSetLayoutWrapper* VulkanStateHandleTable::GetWrapper<VulkanDescriptorSetLayoutWrapper>(VkDescriptorSetLayout handle) { return VulkanStateTableBase::GetWrapper(handle, descriptorSetLayout_map_); }
template<> inline VulkanDescriptorUpdateTemplateWrapper* VulkanStateHandleTable::GetWrapper<VulkanDescriptorUpdateTemplateWrapper>(VkDescriptorUpdateTemplate handle) { return VulkanStateTableBase::GetWrapper(handle, descriptorUpdateTemplate_map_); }
template<> inline VulkanDeviceWrapper* VulkanStateHandleTable::GetWrapper<VulkanDeviceWrapper>(VkDevice handle) { return VulkanStateTableBase::GetWrapper(handle, device_map_); }
template<> inline VulkanDeviceMemoryWrapper* VulkanStateHandleTable::GetWrapper<VulkanDeviceMemoryWrapper>(VkDeviceMemory handle) { return VulkanStateTableBase::GetWrapper(handle, deviceMemory_map_); }
template<> inline VulkanDisplayKHRWrapper* VulkanStateHandleTable::GetWrapper<VulkanDisplayKHRWrapper>(VkDisplayKHR handle) { return VulkanStateTableBase::GetWrapper(handle, displayKHR_map_); }
template<> inline VulkanDisplayModeKHRWrapper* VulkanStateHandleTable::GetWrapper<VulkanDisplayModeKHRWrapper>(VkDisplayModeKHR handle) { return VulkanStateTableBase::GetWrapper(handle, displayModeKHR_map_); }
template<> inline VulkanEventWrapper* VulkanStateHandleTable::GetWrapper<VulkanEventWrapper>(VkEvent handle) { return VulkanStateTableBase::GetWrapper(handle, event_map_); }
template<> inline VulkanFenceWrapper* VulkanStateHandleTable::GetWrapper<VulkanFenceWrapper>(VkFence handle) { return VulkanStateTableBase::GetWrapper(handle, fence_map_); }
template<> inline VulkanFramebufferWrapper* VulkanStateHandleTable::GetWrapper<VulkanFramebufferWrapper>(VkFramebuffer handle) { return VulkanStateTableBase::GetWrapper(handle, framebuffer_map_); }
template<> inline VulkanImageWrapper* VulkanStateHandleTable::GetWrapper<VulkanImageWrapper>(VkImage handle) { return VulkanStateTableBase::GetWrapper(handle, image_map_); }
template<> inline VulkanImageViewWrapper* VulkanStateHandleTable::GetWrapper<VulkanImageViewWrapper>(VkImageView handle) { return VulkanStateTableBase::GetWrapper(handle, imageView_map_); }
template<> inline VulkanIndirectCommandsLayoutNVWrapper* VulkanStateHandleTable::GetWrapper<VulkanIndirectCommandsLayoutNVWrapper>(VkIndirectCommandsLayoutNV handle) { return VulkanStateTableBase::GetWrapper(handle, indirectCommandsLayoutNV_map_); }
template<> inline VulkanInstanceWrapper* VulkanStateHandleTable::GetWrapper<VulkanInstanceWrapper>(VkInstance handle) { return VulkanStateTableBase::GetWrapper(handle, instance_map_); }
template<> inline VulkanMicromapEXTWrapper* VulkanStateHandleTable::GetWrapper<VulkanMicromapEXTWrapper>(VkMicromapEXT handle) { return VulkanStateTableBase::GetWrapper(handle, micromapEXT_map_); }
template<> inline VulkanOpticalFlowSessionNVWrapper* VulkanStateHandleTable::GetWrapper<VulkanOpticalFlowSessionNVWrapper>(VkOpticalFlowSessionNV handle) { return VulkanStateTableBase::GetWrapper(handle, opticalFlowSessionNV_map_); }
template<> inline VulkanPerformanceConfigurationINTELWrapper* VulkanStateHandleTable::GetWrapper<VulkanPerformanceConfigurationINTELWrapper>(VkPerformanceConfigurationINTEL handle) { return VulkanStateTableBase::GetWrapper(handle, performanceConfigurationINTEL_map_); }
template<> inline VulkanPhysicalDeviceWrapper* VulkanStateHandleTable::GetWrapper<VulkanPhysicalDeviceWrapper>(VkPhysicalDevice handle) { return VulkanStateTableBase::GetWrapper(handle, physicalDevice_map_); }
template<> inline VulkanPipelineWrapper* VulkanStateHandleTable::GetWrapper<VulkanPipelineWrapper>(VkPipeline handle) { return VulkanStateTableBase::GetWrapper(handle, pipeline_map_); }
template<> inline VulkanPipelineCacheWrapper* VulkanStateHandleTable::GetWrapper<VulkanPipelineCacheWrapper>(VkPipelineCache handle) { return VulkanStateTableBase::GetWrapper(handle, pipelineCache_map_); }
template<> inline VulkanPipelineLayoutWrapper* VulkanStateHandleTable::GetWrapper<VulkanPipelineLayoutWrapper>(VkPipelineLayout handle) { return VulkanStateTableBase::GetWrapper(handle, pipelineLayout_map_); }
template<> inline VulkanPrivateDataSlotWrapper* VulkanStateHandleTable::GetWrapper<VulkanPrivateDataSlotWrapper>(VkPrivateDataSlot handle) { return VulkanStateTableBase::GetWrapper(handle, privateDataSlot_map_); }
template<> inline VulkanQueryPoolWrapper* VulkanStateHandleTable::GetWrapper<VulkanQueryPoolWrapper>(VkQueryPool handle) { return VulkanStateTableBase::GetWrapper(handle, queryPool_map_); }
template<> inline VulkanQueueWrapper* VulkanStateHandleTable::GetWrapper<VulkanQueueWrapper>(VkQueue handle) { return VulkanStateTableBase::GetWrapper(handle, queue_map_); }
template<> inline VulkanRenderPassWrapper* VulkanStateHandleTable::GetWrapper<VulkanRenderPassWrapper>(VkRenderPass handle) { return VulkanStateTableBase::GetWrapper(handle, renderPass_map_); }
template<> inline VulkanSamplerWrapper* VulkanStateHandleTable::GetWrapper<VulkanSamplerWrapper>(VkSampler handle) { return VulkanStateTableBase::GetWrapper(handle, sampler_map_); }
template<> inline VulkanSamplerYcbcrConversionWrapper* VulkanStateHandleTable::GetWrapper<VulkanSamplerYcbcrConversionWrapper>(VkSamplerYcbcrConversion handle) { return VulkanStateTableBase::GetWrapper(handle, samplerYcbcrConversion_map_); }
template<> inline VulkanSemaphoreWrapper* VulkanStateHandleTable::GetWrapper<VulkanSemaphoreWrapper>(VkSemaphore handle) { return VulkanStateTableBase::GetWrapper(handle, semaphore_map_); }
template<> inline VulkanShaderEXTWrapper* VulkanStateHandleTable::GetWrapper<VulkanShaderEXTWrapper>(VkShaderEXT handle) { return VulkanStateTableBase::GetWrapper(handle, shaderEXT_map_); }
template<> inline VulkanShaderModuleWrapper* VulkanStateHandleTable::GetWrapper<VulkanShaderModuleWrapper>(VkShaderModule handle) { return VulkanStateTableBase::GetWrapper(handle, shaderModule_map_); }
template<> inline VulkanSurfaceKHRWrapper* VulkanStateHandleTable::GetWrapper<VulkanSurfaceKHRWrapper>(VkSurfaceKHR handle) { return VulkanStateTableBase::GetWrapper(handle, surfaceKHR_map_); }
template<> inline VulkanSwapchainKHRWrapper* VulkanStateHandleTable::GetWrapper<VulkanSwapchainKHRWrapper>(VkSwapchainKHR handle) { return VulkanStateTableBase::GetWrapper(handle, swapchainKHR_map_); }
template<> inline VulkanValidationCacheEXTWrapper* VulkanStateHandleTable::GetWrapper<VulkanValidationCacheEXTWrapper>(VkValidationCacheEXT handle) { return VulkanStateTableBase::GetWrapper(handle, validationCacheEXT_map_); }
template<> inline VulkanVideoSessionKHRWrapper* VulkanStateHandleTable::GetWrapper<VulkanVideoSessionKHRWrapper>(VkVideoSessionKHR handle) { return VulkanStateTableBase::GetWrapper(handle, videoSessionKHR_map_); }
template<> inline VulkanVideoSessionParametersKHRWrapper* VulkanStateHandleTable::GetWrapper<VulkanVideoSessionParametersKHRWrapper>(VkVideoSessionParametersKHR handle) { return VulkanStateTableBase::GetWrapper(handle, videoSessionParametersKHR_map_); }

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
