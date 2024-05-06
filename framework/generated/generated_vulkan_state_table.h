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

    bool InsertWrapper(format::HandleId id, vulkan_wrappers::AccelerationStructureKHRWrapper* wrapper) { return InsertEntry(id, wrapper, accelerationStructureKHR_map_); }
    bool InsertWrapper(format::HandleId id, vulkan_wrappers::AccelerationStructureNVWrapper* wrapper) { return InsertEntry(id, wrapper, accelerationStructureNV_map_); }
    bool InsertWrapper(format::HandleId id, vulkan_wrappers::BufferWrapper* wrapper) { return InsertEntry(id, wrapper, buffer_map_); }
    bool InsertWrapper(format::HandleId id, vulkan_wrappers::BufferViewWrapper* wrapper) { return InsertEntry(id, wrapper, bufferView_map_); }
    bool InsertWrapper(format::HandleId id, vulkan_wrappers::CommandBufferWrapper* wrapper) { return InsertEntry(id, wrapper, commandBuffer_map_); }
    bool InsertWrapper(format::HandleId id, vulkan_wrappers::CommandPoolWrapper* wrapper) { return InsertEntry(id, wrapper, commandPool_map_); }
    bool InsertWrapper(format::HandleId id, vulkan_wrappers::DebugReportCallbackEXTWrapper* wrapper) { return InsertEntry(id, wrapper, debugReportCallbackEXT_map_); }
    bool InsertWrapper(format::HandleId id, vulkan_wrappers::DebugUtilsMessengerEXTWrapper* wrapper) { return InsertEntry(id, wrapper, debugUtilsMessengerEXT_map_); }
    bool InsertWrapper(format::HandleId id, vulkan_wrappers::DeferredOperationKHRWrapper* wrapper) { return InsertEntry(id, wrapper, deferredOperationKHR_map_); }
    bool InsertWrapper(format::HandleId id, vulkan_wrappers::DescriptorPoolWrapper* wrapper) { return InsertEntry(id, wrapper, descriptorPool_map_); }
    bool InsertWrapper(format::HandleId id, vulkan_wrappers::DescriptorSetWrapper* wrapper) { return InsertEntry(id, wrapper, descriptorSet_map_); }
    bool InsertWrapper(format::HandleId id, vulkan_wrappers::DescriptorSetLayoutWrapper* wrapper) { return InsertEntry(id, wrapper, descriptorSetLayout_map_); }
    bool InsertWrapper(format::HandleId id, vulkan_wrappers::DescriptorUpdateTemplateWrapper* wrapper) { return InsertEntry(id, wrapper, descriptorUpdateTemplate_map_); }
    bool InsertWrapper(format::HandleId id, vulkan_wrappers::DeviceWrapper* wrapper) { return InsertEntry(id, wrapper, device_map_); }
    bool InsertWrapper(format::HandleId id, vulkan_wrappers::DeviceMemoryWrapper* wrapper) { return InsertEntry(id, wrapper, deviceMemory_map_); }
    bool InsertWrapper(format::HandleId id, vulkan_wrappers::DisplayKHRWrapper* wrapper) { return InsertEntry(id, wrapper, displayKHR_map_); }
    bool InsertWrapper(format::HandleId id, vulkan_wrappers::DisplayModeKHRWrapper* wrapper) { return InsertEntry(id, wrapper, displayModeKHR_map_); }
    bool InsertWrapper(format::HandleId id, vulkan_wrappers::EventWrapper* wrapper) { return InsertEntry(id, wrapper, event_map_); }
    bool InsertWrapper(format::HandleId id, vulkan_wrappers::FenceWrapper* wrapper) { return InsertEntry(id, wrapper, fence_map_); }
    bool InsertWrapper(format::HandleId id, vulkan_wrappers::FramebufferWrapper* wrapper) { return InsertEntry(id, wrapper, framebuffer_map_); }
    bool InsertWrapper(format::HandleId id, vulkan_wrappers::ImageWrapper* wrapper) { return InsertEntry(id, wrapper, image_map_); }
    bool InsertWrapper(format::HandleId id, vulkan_wrappers::ImageViewWrapper* wrapper) { return InsertEntry(id, wrapper, imageView_map_); }
    bool InsertWrapper(format::HandleId id, vulkan_wrappers::IndirectCommandsLayoutNVWrapper* wrapper) { return InsertEntry(id, wrapper, indirectCommandsLayoutNV_map_); }
    bool InsertWrapper(format::HandleId id, vulkan_wrappers::InstanceWrapper* wrapper) { return InsertEntry(id, wrapper, instance_map_); }
    bool InsertWrapper(format::HandleId id, vulkan_wrappers::MicromapEXTWrapper* wrapper) { return InsertEntry(id, wrapper, micromapEXT_map_); }
    bool InsertWrapper(format::HandleId id, vulkan_wrappers::OpticalFlowSessionNVWrapper* wrapper) { return InsertEntry(id, wrapper, opticalFlowSessionNV_map_); }
    bool InsertWrapper(format::HandleId id, vulkan_wrappers::PerformanceConfigurationINTELWrapper* wrapper) { return InsertEntry(id, wrapper, performanceConfigurationINTEL_map_); }
    bool InsertWrapper(format::HandleId id, vulkan_wrappers::PhysicalDeviceWrapper* wrapper) { return InsertEntry(id, wrapper, physicalDevice_map_); }
    bool InsertWrapper(format::HandleId id, vulkan_wrappers::PipelineWrapper* wrapper) { return InsertEntry(id, wrapper, pipeline_map_); }
    bool InsertWrapper(format::HandleId id, vulkan_wrappers::PipelineCacheWrapper* wrapper) { return InsertEntry(id, wrapper, pipelineCache_map_); }
    bool InsertWrapper(format::HandleId id, vulkan_wrappers::PipelineLayoutWrapper* wrapper) { return InsertEntry(id, wrapper, pipelineLayout_map_); }
    bool InsertWrapper(format::HandleId id, vulkan_wrappers::PrivateDataSlotWrapper* wrapper) { return InsertEntry(id, wrapper, privateDataSlot_map_); }
    bool InsertWrapper(format::HandleId id, vulkan_wrappers::QueryPoolWrapper* wrapper) { return InsertEntry(id, wrapper, queryPool_map_); }
    bool InsertWrapper(format::HandleId id, vulkan_wrappers::QueueWrapper* wrapper) { return InsertEntry(id, wrapper, queue_map_); }
    bool InsertWrapper(format::HandleId id, vulkan_wrappers::RenderPassWrapper* wrapper) { return InsertEntry(id, wrapper, renderPass_map_); }
    bool InsertWrapper(format::HandleId id, vulkan_wrappers::SamplerWrapper* wrapper) { return InsertEntry(id, wrapper, sampler_map_); }
    bool InsertWrapper(format::HandleId id, vulkan_wrappers::SamplerYcbcrConversionWrapper* wrapper) { return InsertEntry(id, wrapper, samplerYcbcrConversion_map_); }
    bool InsertWrapper(format::HandleId id, vulkan_wrappers::SemaphoreWrapper* wrapper) { return InsertEntry(id, wrapper, semaphore_map_); }
    bool InsertWrapper(format::HandleId id, vulkan_wrappers::ShaderEXTWrapper* wrapper) { return InsertEntry(id, wrapper, shaderEXT_map_); }
    bool InsertWrapper(format::HandleId id, vulkan_wrappers::ShaderModuleWrapper* wrapper) { return InsertEntry(id, wrapper, shaderModule_map_); }
    bool InsertWrapper(format::HandleId id, vulkan_wrappers::SurfaceKHRWrapper* wrapper) { return InsertEntry(id, wrapper, surfaceKHR_map_); }
    bool InsertWrapper(format::HandleId id, vulkan_wrappers::SwapchainKHRWrapper* wrapper) { return InsertEntry(id, wrapper, swapchainKHR_map_); }
    bool InsertWrapper(format::HandleId id, vulkan_wrappers::ValidationCacheEXTWrapper* wrapper) { return InsertEntry(id, wrapper, validationCacheEXT_map_); }
    bool InsertWrapper(format::HandleId id, vulkan_wrappers::VideoSessionKHRWrapper* wrapper) { return InsertEntry(id, wrapper, videoSessionKHR_map_); }
    bool InsertWrapper(format::HandleId id, vulkan_wrappers::VideoSessionParametersKHRWrapper* wrapper) { return InsertEntry(id, wrapper, videoSessionParametersKHR_map_); }

    bool RemoveWrapper(const vulkan_wrappers::AccelerationStructureKHRWrapper* wrapper) { return RemoveEntry(wrapper, accelerationStructureKHR_map_); }
    bool RemoveWrapper(const vulkan_wrappers::AccelerationStructureNVWrapper* wrapper) { return RemoveEntry(wrapper, accelerationStructureNV_map_); }
    bool RemoveWrapper(const vulkan_wrappers::BufferWrapper* wrapper) { return RemoveEntry(wrapper, buffer_map_); }
    bool RemoveWrapper(const vulkan_wrappers::BufferViewWrapper* wrapper) { return RemoveEntry(wrapper, bufferView_map_); }
    bool RemoveWrapper(const vulkan_wrappers::CommandBufferWrapper* wrapper) { return RemoveEntry(wrapper, commandBuffer_map_); }
    bool RemoveWrapper(const vulkan_wrappers::CommandPoolWrapper* wrapper) { return RemoveEntry(wrapper, commandPool_map_); }
    bool RemoveWrapper(const vulkan_wrappers::DebugReportCallbackEXTWrapper* wrapper) { return RemoveEntry(wrapper, debugReportCallbackEXT_map_); }
    bool RemoveWrapper(const vulkan_wrappers::DebugUtilsMessengerEXTWrapper* wrapper) { return RemoveEntry(wrapper, debugUtilsMessengerEXT_map_); }
    bool RemoveWrapper(const vulkan_wrappers::DeferredOperationKHRWrapper* wrapper) { return RemoveEntry(wrapper, deferredOperationKHR_map_); }
    bool RemoveWrapper(const vulkan_wrappers::DescriptorPoolWrapper* wrapper) { return RemoveEntry(wrapper, descriptorPool_map_); }
    bool RemoveWrapper(const vulkan_wrappers::DescriptorSetWrapper* wrapper) { return RemoveEntry(wrapper, descriptorSet_map_); }
    bool RemoveWrapper(const vulkan_wrappers::DescriptorSetLayoutWrapper* wrapper) { return RemoveEntry(wrapper, descriptorSetLayout_map_); }
    bool RemoveWrapper(const vulkan_wrappers::DescriptorUpdateTemplateWrapper* wrapper) { return RemoveEntry(wrapper, descriptorUpdateTemplate_map_); }
    bool RemoveWrapper(const vulkan_wrappers::DeviceWrapper* wrapper) { return RemoveEntry(wrapper, device_map_); }
    bool RemoveWrapper(const vulkan_wrappers::DeviceMemoryWrapper* wrapper) { return RemoveEntry(wrapper, deviceMemory_map_); }
    bool RemoveWrapper(const vulkan_wrappers::DisplayKHRWrapper* wrapper) { return RemoveEntry(wrapper, displayKHR_map_); }
    bool RemoveWrapper(const vulkan_wrappers::DisplayModeKHRWrapper* wrapper) { return RemoveEntry(wrapper, displayModeKHR_map_); }
    bool RemoveWrapper(const vulkan_wrappers::EventWrapper* wrapper) { return RemoveEntry(wrapper, event_map_); }
    bool RemoveWrapper(const vulkan_wrappers::FenceWrapper* wrapper) { return RemoveEntry(wrapper, fence_map_); }
    bool RemoveWrapper(const vulkan_wrappers::FramebufferWrapper* wrapper) { return RemoveEntry(wrapper, framebuffer_map_); }
    bool RemoveWrapper(const vulkan_wrappers::ImageWrapper* wrapper) { return RemoveEntry(wrapper, image_map_); }
    bool RemoveWrapper(const vulkan_wrappers::ImageViewWrapper* wrapper) { return RemoveEntry(wrapper, imageView_map_); }
    bool RemoveWrapper(const vulkan_wrappers::IndirectCommandsLayoutNVWrapper* wrapper) { return RemoveEntry(wrapper, indirectCommandsLayoutNV_map_); }
    bool RemoveWrapper(const vulkan_wrappers::InstanceWrapper* wrapper) { return RemoveEntry(wrapper, instance_map_); }
    bool RemoveWrapper(const vulkan_wrappers::MicromapEXTWrapper* wrapper) { return RemoveEntry(wrapper, micromapEXT_map_); }
    bool RemoveWrapper(const vulkan_wrappers::OpticalFlowSessionNVWrapper* wrapper) { return RemoveEntry(wrapper, opticalFlowSessionNV_map_); }
    bool RemoveWrapper(const vulkan_wrappers::PerformanceConfigurationINTELWrapper* wrapper) { return RemoveEntry(wrapper, performanceConfigurationINTEL_map_); }
    bool RemoveWrapper(const vulkan_wrappers::PhysicalDeviceWrapper* wrapper) { return RemoveEntry(wrapper, physicalDevice_map_); }
    bool RemoveWrapper(const vulkan_wrappers::PipelineWrapper* wrapper) { return RemoveEntry(wrapper, pipeline_map_); }
    bool RemoveWrapper(const vulkan_wrappers::PipelineCacheWrapper* wrapper) { return RemoveEntry(wrapper, pipelineCache_map_); }
    bool RemoveWrapper(const vulkan_wrappers::PipelineLayoutWrapper* wrapper) { return RemoveEntry(wrapper, pipelineLayout_map_); }
    bool RemoveWrapper(const vulkan_wrappers::PrivateDataSlotWrapper* wrapper) { return RemoveEntry(wrapper, privateDataSlot_map_); }
    bool RemoveWrapper(const vulkan_wrappers::QueryPoolWrapper* wrapper) { return RemoveEntry(wrapper, queryPool_map_); }
    bool RemoveWrapper(const vulkan_wrappers::QueueWrapper* wrapper) { return RemoveEntry(wrapper, queue_map_); }
    bool RemoveWrapper(const vulkan_wrappers::RenderPassWrapper* wrapper) { return RemoveEntry(wrapper, renderPass_map_); }
    bool RemoveWrapper(const vulkan_wrappers::SamplerWrapper* wrapper) { return RemoveEntry(wrapper, sampler_map_); }
    bool RemoveWrapper(const vulkan_wrappers::SamplerYcbcrConversionWrapper* wrapper) { return RemoveEntry(wrapper, samplerYcbcrConversion_map_); }
    bool RemoveWrapper(const vulkan_wrappers::SemaphoreWrapper* wrapper) { return RemoveEntry(wrapper, semaphore_map_); }
    bool RemoveWrapper(const vulkan_wrappers::ShaderEXTWrapper* wrapper) { return RemoveEntry(wrapper, shaderEXT_map_); }
    bool RemoveWrapper(const vulkan_wrappers::ShaderModuleWrapper* wrapper) { return RemoveEntry(wrapper, shaderModule_map_); }
    bool RemoveWrapper(const vulkan_wrappers::SurfaceKHRWrapper* wrapper) { return RemoveEntry(wrapper, surfaceKHR_map_); }
    bool RemoveWrapper(const vulkan_wrappers::SwapchainKHRWrapper* wrapper) { return RemoveEntry(wrapper, swapchainKHR_map_); }
    bool RemoveWrapper(const vulkan_wrappers::ValidationCacheEXTWrapper* wrapper) { return RemoveEntry(wrapper, validationCacheEXT_map_); }
    bool RemoveWrapper(const vulkan_wrappers::VideoSessionKHRWrapper* wrapper) { return RemoveEntry(wrapper, videoSessionKHR_map_); }
    bool RemoveWrapper(const vulkan_wrappers::VideoSessionParametersKHRWrapper* wrapper) { return RemoveEntry(wrapper, videoSessionParametersKHR_map_); }

    const vulkan_wrappers::AccelerationStructureKHRWrapper* GetVulkanAccelerationStructureKHRWrapper(format::HandleId id) const { return GetWrapper<vulkan_wrappers::AccelerationStructureKHRWrapper>(id, accelerationStructureKHR_map_); }
    const vulkan_wrappers::AccelerationStructureNVWrapper* GetVulkanAccelerationStructureNVWrapper(format::HandleId id) const { return GetWrapper<vulkan_wrappers::AccelerationStructureNVWrapper>(id, accelerationStructureNV_map_); }
    const vulkan_wrappers::BufferWrapper* GetVulkanBufferWrapper(format::HandleId id) const { return GetWrapper<vulkan_wrappers::BufferWrapper>(id, buffer_map_); }
    const vulkan_wrappers::BufferViewWrapper* GetVulkanBufferViewWrapper(format::HandleId id) const { return GetWrapper<vulkan_wrappers::BufferViewWrapper>(id, bufferView_map_); }
    const vulkan_wrappers::CommandBufferWrapper* GetVulkanCommandBufferWrapper(format::HandleId id) const { return GetWrapper<vulkan_wrappers::CommandBufferWrapper>(id, commandBuffer_map_); }
    const vulkan_wrappers::CommandPoolWrapper* GetVulkanCommandPoolWrapper(format::HandleId id) const { return GetWrapper<vulkan_wrappers::CommandPoolWrapper>(id, commandPool_map_); }
    const vulkan_wrappers::DebugReportCallbackEXTWrapper* GetVulkanDebugReportCallbackEXTWrapper(format::HandleId id) const { return GetWrapper<vulkan_wrappers::DebugReportCallbackEXTWrapper>(id, debugReportCallbackEXT_map_); }
    const vulkan_wrappers::DebugUtilsMessengerEXTWrapper* GetVulkanDebugUtilsMessengerEXTWrapper(format::HandleId id) const { return GetWrapper<vulkan_wrappers::DebugUtilsMessengerEXTWrapper>(id, debugUtilsMessengerEXT_map_); }
    const vulkan_wrappers::DeferredOperationKHRWrapper* GetVulkanDeferredOperationKHRWrapper(format::HandleId id) const { return GetWrapper<vulkan_wrappers::DeferredOperationKHRWrapper>(id, deferredOperationKHR_map_); }
    const vulkan_wrappers::DescriptorPoolWrapper* GetVulkanDescriptorPoolWrapper(format::HandleId id) const { return GetWrapper<vulkan_wrappers::DescriptorPoolWrapper>(id, descriptorPool_map_); }
    const vulkan_wrappers::DescriptorSetWrapper* GetVulkanDescriptorSetWrapper(format::HandleId id) const { return GetWrapper<vulkan_wrappers::DescriptorSetWrapper>(id, descriptorSet_map_); }
    const vulkan_wrappers::DescriptorSetLayoutWrapper* GetVulkanDescriptorSetLayoutWrapper(format::HandleId id) const { return GetWrapper<vulkan_wrappers::DescriptorSetLayoutWrapper>(id, descriptorSetLayout_map_); }
    const vulkan_wrappers::DescriptorUpdateTemplateWrapper* GetVulkanDescriptorUpdateTemplateWrapper(format::HandleId id) const { return GetWrapper<vulkan_wrappers::DescriptorUpdateTemplateWrapper>(id, descriptorUpdateTemplate_map_); }
    const vulkan_wrappers::DeviceWrapper* GetVulkanDeviceWrapper(format::HandleId id) const { return GetWrapper<vulkan_wrappers::DeviceWrapper>(id, device_map_); }
    const vulkan_wrappers::DeviceMemoryWrapper* GetVulkanDeviceMemoryWrapper(format::HandleId id) const { return GetWrapper<vulkan_wrappers::DeviceMemoryWrapper>(id, deviceMemory_map_); }
    const vulkan_wrappers::DisplayKHRWrapper* GetVulkanDisplayKHRWrapper(format::HandleId id) const { return GetWrapper<vulkan_wrappers::DisplayKHRWrapper>(id, displayKHR_map_); }
    const vulkan_wrappers::DisplayModeKHRWrapper* GetVulkanDisplayModeKHRWrapper(format::HandleId id) const { return GetWrapper<vulkan_wrappers::DisplayModeKHRWrapper>(id, displayModeKHR_map_); }
    const vulkan_wrappers::EventWrapper* GetVulkanEventWrapper(format::HandleId id) const { return GetWrapper<vulkan_wrappers::EventWrapper>(id, event_map_); }
    const vulkan_wrappers::FenceWrapper* GetVulkanFenceWrapper(format::HandleId id) const { return GetWrapper<vulkan_wrappers::FenceWrapper>(id, fence_map_); }
    const vulkan_wrappers::FramebufferWrapper* GetVulkanFramebufferWrapper(format::HandleId id) const { return GetWrapper<vulkan_wrappers::FramebufferWrapper>(id, framebuffer_map_); }
    const vulkan_wrappers::ImageWrapper* GetVulkanImageWrapper(format::HandleId id) const { return GetWrapper<vulkan_wrappers::ImageWrapper>(id, image_map_); }
    const vulkan_wrappers::ImageViewWrapper* GetVulkanImageViewWrapper(format::HandleId id) const { return GetWrapper<vulkan_wrappers::ImageViewWrapper>(id, imageView_map_); }
    const vulkan_wrappers::IndirectCommandsLayoutNVWrapper* GetVulkanIndirectCommandsLayoutNVWrapper(format::HandleId id) const { return GetWrapper<vulkan_wrappers::IndirectCommandsLayoutNVWrapper>(id, indirectCommandsLayoutNV_map_); }
    const vulkan_wrappers::InstanceWrapper* GetVulkanInstanceWrapper(format::HandleId id) const { return GetWrapper<vulkan_wrappers::InstanceWrapper>(id, instance_map_); }
    const vulkan_wrappers::MicromapEXTWrapper* GetVulkanMicromapEXTWrapper(format::HandleId id) const { return GetWrapper<vulkan_wrappers::MicromapEXTWrapper>(id, micromapEXT_map_); }
    const vulkan_wrappers::OpticalFlowSessionNVWrapper* GetVulkanOpticalFlowSessionNVWrapper(format::HandleId id) const { return GetWrapper<vulkan_wrappers::OpticalFlowSessionNVWrapper>(id, opticalFlowSessionNV_map_); }
    const vulkan_wrappers::PerformanceConfigurationINTELWrapper* GetVulkanPerformanceConfigurationINTELWrapper(format::HandleId id) const { return GetWrapper<vulkan_wrappers::PerformanceConfigurationINTELWrapper>(id, performanceConfigurationINTEL_map_); }
    const vulkan_wrappers::PhysicalDeviceWrapper* GetVulkanPhysicalDeviceWrapper(format::HandleId id) const { return GetWrapper<vulkan_wrappers::PhysicalDeviceWrapper>(id, physicalDevice_map_); }
    const vulkan_wrappers::PipelineWrapper* GetVulkanPipelineWrapper(format::HandleId id) const { return GetWrapper<vulkan_wrappers::PipelineWrapper>(id, pipeline_map_); }
    const vulkan_wrappers::PipelineCacheWrapper* GetVulkanPipelineCacheWrapper(format::HandleId id) const { return GetWrapper<vulkan_wrappers::PipelineCacheWrapper>(id, pipelineCache_map_); }
    const vulkan_wrappers::PipelineLayoutWrapper* GetVulkanPipelineLayoutWrapper(format::HandleId id) const { return GetWrapper<vulkan_wrappers::PipelineLayoutWrapper>(id, pipelineLayout_map_); }
    const vulkan_wrappers::PrivateDataSlotWrapper* GetVulkanPrivateDataSlotWrapper(format::HandleId id) const { return GetWrapper<vulkan_wrappers::PrivateDataSlotWrapper>(id, privateDataSlot_map_); }
    const vulkan_wrappers::QueryPoolWrapper* GetVulkanQueryPoolWrapper(format::HandleId id) const { return GetWrapper<vulkan_wrappers::QueryPoolWrapper>(id, queryPool_map_); }
    const vulkan_wrappers::QueueWrapper* GetVulkanQueueWrapper(format::HandleId id) const { return GetWrapper<vulkan_wrappers::QueueWrapper>(id, queue_map_); }
    const vulkan_wrappers::RenderPassWrapper* GetVulkanRenderPassWrapper(format::HandleId id) const { return GetWrapper<vulkan_wrappers::RenderPassWrapper>(id, renderPass_map_); }
    const vulkan_wrappers::SamplerWrapper* GetVulkanSamplerWrapper(format::HandleId id) const { return GetWrapper<vulkan_wrappers::SamplerWrapper>(id, sampler_map_); }
    const vulkan_wrappers::SamplerYcbcrConversionWrapper* GetVulkanSamplerYcbcrConversionWrapper(format::HandleId id) const { return GetWrapper<vulkan_wrappers::SamplerYcbcrConversionWrapper>(id, samplerYcbcrConversion_map_); }
    const vulkan_wrappers::SemaphoreWrapper* GetVulkanSemaphoreWrapper(format::HandleId id) const { return GetWrapper<vulkan_wrappers::SemaphoreWrapper>(id, semaphore_map_); }
    const vulkan_wrappers::ShaderEXTWrapper* GetVulkanShaderEXTWrapper(format::HandleId id) const { return GetWrapper<vulkan_wrappers::ShaderEXTWrapper>(id, shaderEXT_map_); }
    const vulkan_wrappers::ShaderModuleWrapper* GetVulkanShaderModuleWrapper(format::HandleId id) const { return GetWrapper<vulkan_wrappers::ShaderModuleWrapper>(id, shaderModule_map_); }
    const vulkan_wrappers::SurfaceKHRWrapper* GetVulkanSurfaceKHRWrapper(format::HandleId id) const { return GetWrapper<vulkan_wrappers::SurfaceKHRWrapper>(id, surfaceKHR_map_); }
    const vulkan_wrappers::SwapchainKHRWrapper* GetVulkanSwapchainKHRWrapper(format::HandleId id) const { return GetWrapper<vulkan_wrappers::SwapchainKHRWrapper>(id, swapchainKHR_map_); }
    const vulkan_wrappers::ValidationCacheEXTWrapper* GetVulkanValidationCacheEXTWrapper(format::HandleId id) const { return GetWrapper<vulkan_wrappers::ValidationCacheEXTWrapper>(id, validationCacheEXT_map_); }
    const vulkan_wrappers::VideoSessionKHRWrapper* GetVulkanVideoSessionKHRWrapper(format::HandleId id) const { return GetWrapper<vulkan_wrappers::VideoSessionKHRWrapper>(id, videoSessionKHR_map_); }
    const vulkan_wrappers::VideoSessionParametersKHRWrapper* GetVulkanVideoSessionParametersKHRWrapper(format::HandleId id) const { return GetWrapper<vulkan_wrappers::VideoSessionParametersKHRWrapper>(id, videoSessionParametersKHR_map_); }

    vulkan_wrappers::AccelerationStructureKHRWrapper* GetVulkanAccelerationStructureKHRWrapper(format::HandleId id) { return GetWrapper<vulkan_wrappers::AccelerationStructureKHRWrapper>(id, accelerationStructureKHR_map_); }
    vulkan_wrappers::AccelerationStructureNVWrapper* GetVulkanAccelerationStructureNVWrapper(format::HandleId id) { return GetWrapper<vulkan_wrappers::AccelerationStructureNVWrapper>(id, accelerationStructureNV_map_); }
    vulkan_wrappers::BufferWrapper* GetVulkanBufferWrapper(format::HandleId id) { return GetWrapper<vulkan_wrappers::BufferWrapper>(id, buffer_map_); }
    vulkan_wrappers::BufferViewWrapper* GetVulkanBufferViewWrapper(format::HandleId id) { return GetWrapper<vulkan_wrappers::BufferViewWrapper>(id, bufferView_map_); }
    vulkan_wrappers::CommandBufferWrapper* GetVulkanCommandBufferWrapper(format::HandleId id) { return GetWrapper<vulkan_wrappers::CommandBufferWrapper>(id, commandBuffer_map_); }
    vulkan_wrappers::CommandPoolWrapper* GetVulkanCommandPoolWrapper(format::HandleId id) { return GetWrapper<vulkan_wrappers::CommandPoolWrapper>(id, commandPool_map_); }
    vulkan_wrappers::DebugReportCallbackEXTWrapper* GetVulkanDebugReportCallbackEXTWrapper(format::HandleId id) { return GetWrapper<vulkan_wrappers::DebugReportCallbackEXTWrapper>(id, debugReportCallbackEXT_map_); }
    vulkan_wrappers::DebugUtilsMessengerEXTWrapper* GetVulkanDebugUtilsMessengerEXTWrapper(format::HandleId id) { return GetWrapper<vulkan_wrappers::DebugUtilsMessengerEXTWrapper>(id, debugUtilsMessengerEXT_map_); }
    vulkan_wrappers::DeferredOperationKHRWrapper* GetVulkanDeferredOperationKHRWrapper(format::HandleId id) { return GetWrapper<vulkan_wrappers::DeferredOperationKHRWrapper>(id, deferredOperationKHR_map_); }
    vulkan_wrappers::DescriptorPoolWrapper* GetVulkanDescriptorPoolWrapper(format::HandleId id) { return GetWrapper<vulkan_wrappers::DescriptorPoolWrapper>(id, descriptorPool_map_); }
    vulkan_wrappers::DescriptorSetWrapper* GetVulkanDescriptorSetWrapper(format::HandleId id) { return GetWrapper<vulkan_wrappers::DescriptorSetWrapper>(id, descriptorSet_map_); }
    vulkan_wrappers::DescriptorSetLayoutWrapper* GetVulkanDescriptorSetLayoutWrapper(format::HandleId id) { return GetWrapper<vulkan_wrappers::DescriptorSetLayoutWrapper>(id, descriptorSetLayout_map_); }
    vulkan_wrappers::DescriptorUpdateTemplateWrapper* GetVulkanDescriptorUpdateTemplateWrapper(format::HandleId id) { return GetWrapper<vulkan_wrappers::DescriptorUpdateTemplateWrapper>(id, descriptorUpdateTemplate_map_); }
    vulkan_wrappers::DeviceWrapper* GetVulkanDeviceWrapper(format::HandleId id) { return GetWrapper<vulkan_wrappers::DeviceWrapper>(id, device_map_); }
    vulkan_wrappers::DeviceMemoryWrapper* GetVulkanDeviceMemoryWrapper(format::HandleId id) { return GetWrapper<vulkan_wrappers::DeviceMemoryWrapper>(id, deviceMemory_map_); }
    vulkan_wrappers::DisplayKHRWrapper* GetVulkanDisplayKHRWrapper(format::HandleId id) { return GetWrapper<vulkan_wrappers::DisplayKHRWrapper>(id, displayKHR_map_); }
    vulkan_wrappers::DisplayModeKHRWrapper* GetVulkanDisplayModeKHRWrapper(format::HandleId id) { return GetWrapper<vulkan_wrappers::DisplayModeKHRWrapper>(id, displayModeKHR_map_); }
    vulkan_wrappers::EventWrapper* GetVulkanEventWrapper(format::HandleId id) { return GetWrapper<vulkan_wrappers::EventWrapper>(id, event_map_); }
    vulkan_wrappers::FenceWrapper* GetVulkanFenceWrapper(format::HandleId id) { return GetWrapper<vulkan_wrappers::FenceWrapper>(id, fence_map_); }
    vulkan_wrappers::FramebufferWrapper* GetVulkanFramebufferWrapper(format::HandleId id) { return GetWrapper<vulkan_wrappers::FramebufferWrapper>(id, framebuffer_map_); }
    vulkan_wrappers::ImageWrapper* GetVulkanImageWrapper(format::HandleId id) { return GetWrapper<vulkan_wrappers::ImageWrapper>(id, image_map_); }
    vulkan_wrappers::ImageViewWrapper* GetVulkanImageViewWrapper(format::HandleId id) { return GetWrapper<vulkan_wrappers::ImageViewWrapper>(id, imageView_map_); }
    vulkan_wrappers::IndirectCommandsLayoutNVWrapper* GetVulkanIndirectCommandsLayoutNVWrapper(format::HandleId id) { return GetWrapper<vulkan_wrappers::IndirectCommandsLayoutNVWrapper>(id, indirectCommandsLayoutNV_map_); }
    vulkan_wrappers::InstanceWrapper* GetVulkanInstanceWrapper(format::HandleId id) { return GetWrapper<vulkan_wrappers::InstanceWrapper>(id, instance_map_); }
    vulkan_wrappers::MicromapEXTWrapper* GetVulkanMicromapEXTWrapper(format::HandleId id) { return GetWrapper<vulkan_wrappers::MicromapEXTWrapper>(id, micromapEXT_map_); }
    vulkan_wrappers::OpticalFlowSessionNVWrapper* GetVulkanOpticalFlowSessionNVWrapper(format::HandleId id) { return GetWrapper<vulkan_wrappers::OpticalFlowSessionNVWrapper>(id, opticalFlowSessionNV_map_); }
    vulkan_wrappers::PerformanceConfigurationINTELWrapper* GetVulkanPerformanceConfigurationINTELWrapper(format::HandleId id) { return GetWrapper<vulkan_wrappers::PerformanceConfigurationINTELWrapper>(id, performanceConfigurationINTEL_map_); }
    vulkan_wrappers::PhysicalDeviceWrapper* GetVulkanPhysicalDeviceWrapper(format::HandleId id) { return GetWrapper<vulkan_wrappers::PhysicalDeviceWrapper>(id, physicalDevice_map_); }
    vulkan_wrappers::PipelineWrapper* GetVulkanPipelineWrapper(format::HandleId id) { return GetWrapper<vulkan_wrappers::PipelineWrapper>(id, pipeline_map_); }
    vulkan_wrappers::PipelineCacheWrapper* GetVulkanPipelineCacheWrapper(format::HandleId id) { return GetWrapper<vulkan_wrappers::PipelineCacheWrapper>(id, pipelineCache_map_); }
    vulkan_wrappers::PipelineLayoutWrapper* GetVulkanPipelineLayoutWrapper(format::HandleId id) { return GetWrapper<vulkan_wrappers::PipelineLayoutWrapper>(id, pipelineLayout_map_); }
    vulkan_wrappers::PrivateDataSlotWrapper* GetVulkanPrivateDataSlotWrapper(format::HandleId id) { return GetWrapper<vulkan_wrappers::PrivateDataSlotWrapper>(id, privateDataSlot_map_); }
    vulkan_wrappers::QueryPoolWrapper* GetVulkanQueryPoolWrapper(format::HandleId id) { return GetWrapper<vulkan_wrappers::QueryPoolWrapper>(id, queryPool_map_); }
    vulkan_wrappers::QueueWrapper* GetVulkanQueueWrapper(format::HandleId id) { return GetWrapper<vulkan_wrappers::QueueWrapper>(id, queue_map_); }
    vulkan_wrappers::RenderPassWrapper* GetVulkanRenderPassWrapper(format::HandleId id) { return GetWrapper<vulkan_wrappers::RenderPassWrapper>(id, renderPass_map_); }
    vulkan_wrappers::SamplerWrapper* GetVulkanSamplerWrapper(format::HandleId id) { return GetWrapper<vulkan_wrappers::SamplerWrapper>(id, sampler_map_); }
    vulkan_wrappers::SamplerYcbcrConversionWrapper* GetVulkanSamplerYcbcrConversionWrapper(format::HandleId id) { return GetWrapper<vulkan_wrappers::SamplerYcbcrConversionWrapper>(id, samplerYcbcrConversion_map_); }
    vulkan_wrappers::SemaphoreWrapper* GetVulkanSemaphoreWrapper(format::HandleId id) { return GetWrapper<vulkan_wrappers::SemaphoreWrapper>(id, semaphore_map_); }
    vulkan_wrappers::ShaderEXTWrapper* GetVulkanShaderEXTWrapper(format::HandleId id) { return GetWrapper<vulkan_wrappers::ShaderEXTWrapper>(id, shaderEXT_map_); }
    vulkan_wrappers::ShaderModuleWrapper* GetVulkanShaderModuleWrapper(format::HandleId id) { return GetWrapper<vulkan_wrappers::ShaderModuleWrapper>(id, shaderModule_map_); }
    vulkan_wrappers::SurfaceKHRWrapper* GetVulkanSurfaceKHRWrapper(format::HandleId id) { return GetWrapper<vulkan_wrappers::SurfaceKHRWrapper>(id, surfaceKHR_map_); }
    vulkan_wrappers::SwapchainKHRWrapper* GetVulkanSwapchainKHRWrapper(format::HandleId id) { return GetWrapper<vulkan_wrappers::SwapchainKHRWrapper>(id, swapchainKHR_map_); }
    vulkan_wrappers::ValidationCacheEXTWrapper* GetVulkanValidationCacheEXTWrapper(format::HandleId id) { return GetWrapper<vulkan_wrappers::ValidationCacheEXTWrapper>(id, validationCacheEXT_map_); }
    vulkan_wrappers::VideoSessionKHRWrapper* GetVulkanVideoSessionKHRWrapper(format::HandleId id) { return GetWrapper<vulkan_wrappers::VideoSessionKHRWrapper>(id, videoSessionKHR_map_); }
    vulkan_wrappers::VideoSessionParametersKHRWrapper* GetVulkanVideoSessionParametersKHRWrapper(format::HandleId id) { return GetWrapper<vulkan_wrappers::VideoSessionParametersKHRWrapper>(id, videoSessionParametersKHR_map_); }

    void VisitWrappers(std::function<void(vulkan_wrappers::AccelerationStructureKHRWrapper*)> visitor) const { for (auto entry : accelerationStructureKHR_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(vulkan_wrappers::AccelerationStructureNVWrapper*)> visitor) const { for (auto entry : accelerationStructureNV_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(vulkan_wrappers::BufferWrapper*)> visitor) const { for (auto entry : buffer_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(vulkan_wrappers::BufferViewWrapper*)> visitor) const { for (auto entry : bufferView_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(vulkan_wrappers::CommandBufferWrapper*)> visitor) const { for (auto entry : commandBuffer_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(vulkan_wrappers::CommandPoolWrapper*)> visitor) const { for (auto entry : commandPool_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(vulkan_wrappers::DebugReportCallbackEXTWrapper*)> visitor) const { for (auto entry : debugReportCallbackEXT_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(vulkan_wrappers::DebugUtilsMessengerEXTWrapper*)> visitor) const { for (auto entry : debugUtilsMessengerEXT_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(vulkan_wrappers::DeferredOperationKHRWrapper*)> visitor) const { for (auto entry : deferredOperationKHR_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(vulkan_wrappers::DescriptorPoolWrapper*)> visitor) const { for (auto entry : descriptorPool_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(vulkan_wrappers::DescriptorSetWrapper*)> visitor) const { for (auto entry : descriptorSet_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(vulkan_wrappers::DescriptorSetLayoutWrapper*)> visitor) const { for (auto entry : descriptorSetLayout_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(vulkan_wrappers::DescriptorUpdateTemplateWrapper*)> visitor) const { for (auto entry : descriptorUpdateTemplate_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(vulkan_wrappers::DeviceWrapper*)> visitor) const { for (auto entry : device_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(vulkan_wrappers::DeviceMemoryWrapper*)> visitor) const { for (auto entry : deviceMemory_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(vulkan_wrappers::DisplayKHRWrapper*)> visitor) const { for (auto entry : displayKHR_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(vulkan_wrappers::DisplayModeKHRWrapper*)> visitor) const { for (auto entry : displayModeKHR_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(vulkan_wrappers::EventWrapper*)> visitor) const { for (auto entry : event_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(vulkan_wrappers::FenceWrapper*)> visitor) const { for (auto entry : fence_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(vulkan_wrappers::FramebufferWrapper*)> visitor) const { for (auto entry : framebuffer_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(vulkan_wrappers::ImageWrapper*)> visitor) const { for (auto entry : image_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(vulkan_wrappers::ImageViewWrapper*)> visitor) const { for (auto entry : imageView_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(vulkan_wrappers::IndirectCommandsLayoutNVWrapper*)> visitor) const { for (auto entry : indirectCommandsLayoutNV_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(vulkan_wrappers::InstanceWrapper*)> visitor) const { for (auto entry : instance_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(vulkan_wrappers::MicromapEXTWrapper*)> visitor) const { for (auto entry : micromapEXT_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(vulkan_wrappers::OpticalFlowSessionNVWrapper*)> visitor) const { for (auto entry : opticalFlowSessionNV_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(vulkan_wrappers::PerformanceConfigurationINTELWrapper*)> visitor) const { for (auto entry : performanceConfigurationINTEL_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(vulkan_wrappers::PhysicalDeviceWrapper*)> visitor) const { for (auto entry : physicalDevice_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(vulkan_wrappers::PipelineWrapper*)> visitor) const { for (auto entry : pipeline_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(vulkan_wrappers::PipelineCacheWrapper*)> visitor) const { for (auto entry : pipelineCache_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(vulkan_wrappers::PipelineLayoutWrapper*)> visitor) const { for (auto entry : pipelineLayout_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(vulkan_wrappers::PrivateDataSlotWrapper*)> visitor) const { for (auto entry : privateDataSlot_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(vulkan_wrappers::QueryPoolWrapper*)> visitor) const { for (auto entry : queryPool_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(vulkan_wrappers::QueueWrapper*)> visitor) const { for (auto entry : queue_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(vulkan_wrappers::RenderPassWrapper*)> visitor) const { for (auto entry : renderPass_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(vulkan_wrappers::SamplerWrapper*)> visitor) const { for (auto entry : sampler_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(vulkan_wrappers::SamplerYcbcrConversionWrapper*)> visitor) const { for (auto entry : samplerYcbcrConversion_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(vulkan_wrappers::SemaphoreWrapper*)> visitor) const { for (auto entry : semaphore_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(vulkan_wrappers::ShaderEXTWrapper*)> visitor) const { for (auto entry : shaderEXT_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(vulkan_wrappers::ShaderModuleWrapper*)> visitor) const { for (auto entry : shaderModule_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(vulkan_wrappers::SurfaceKHRWrapper*)> visitor) const { for (auto entry : surfaceKHR_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(vulkan_wrappers::SwapchainKHRWrapper*)> visitor) const { for (auto entry : swapchainKHR_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(vulkan_wrappers::ValidationCacheEXTWrapper*)> visitor) const { for (auto entry : validationCacheEXT_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(vulkan_wrappers::VideoSessionKHRWrapper*)> visitor) const { for (auto entry : videoSessionKHR_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(vulkan_wrappers::VideoSessionParametersKHRWrapper*)> visitor) const { for (auto entry : videoSessionParametersKHR_map_) { visitor(entry.second); } }

  private:
    std::map<format::HandleId, vulkan_wrappers::AccelerationStructureKHRWrapper*> accelerationStructureKHR_map_;
    std::map<format::HandleId, vulkan_wrappers::AccelerationStructureNVWrapper*> accelerationStructureNV_map_;
    std::map<format::HandleId, vulkan_wrappers::BufferWrapper*> buffer_map_;
    std::map<format::HandleId, vulkan_wrappers::BufferViewWrapper*> bufferView_map_;
    std::map<format::HandleId, vulkan_wrappers::CommandBufferWrapper*> commandBuffer_map_;
    std::map<format::HandleId, vulkan_wrappers::CommandPoolWrapper*> commandPool_map_;
    std::map<format::HandleId, vulkan_wrappers::DebugReportCallbackEXTWrapper*> debugReportCallbackEXT_map_;
    std::map<format::HandleId, vulkan_wrappers::DebugUtilsMessengerEXTWrapper*> debugUtilsMessengerEXT_map_;
    std::map<format::HandleId, vulkan_wrappers::DeferredOperationKHRWrapper*> deferredOperationKHR_map_;
    std::map<format::HandleId, vulkan_wrappers::DescriptorPoolWrapper*> descriptorPool_map_;
    std::map<format::HandleId, vulkan_wrappers::DescriptorSetWrapper*> descriptorSet_map_;
    std::map<format::HandleId, vulkan_wrappers::DescriptorSetLayoutWrapper*> descriptorSetLayout_map_;
    std::map<format::HandleId, vulkan_wrappers::DescriptorUpdateTemplateWrapper*> descriptorUpdateTemplate_map_;
    std::map<format::HandleId, vulkan_wrappers::DeviceWrapper*> device_map_;
    std::map<format::HandleId, vulkan_wrappers::DeviceMemoryWrapper*> deviceMemory_map_;
    std::map<format::HandleId, vulkan_wrappers::DisplayKHRWrapper*> displayKHR_map_;
    std::map<format::HandleId, vulkan_wrappers::DisplayModeKHRWrapper*> displayModeKHR_map_;
    std::map<format::HandleId, vulkan_wrappers::EventWrapper*> event_map_;
    std::map<format::HandleId, vulkan_wrappers::FenceWrapper*> fence_map_;
    std::map<format::HandleId, vulkan_wrappers::FramebufferWrapper*> framebuffer_map_;
    std::map<format::HandleId, vulkan_wrappers::ImageWrapper*> image_map_;
    std::map<format::HandleId, vulkan_wrappers::ImageViewWrapper*> imageView_map_;
    std::map<format::HandleId, vulkan_wrappers::IndirectCommandsLayoutNVWrapper*> indirectCommandsLayoutNV_map_;
    std::map<format::HandleId, vulkan_wrappers::InstanceWrapper*> instance_map_;
    std::map<format::HandleId, vulkan_wrappers::MicromapEXTWrapper*> micromapEXT_map_;
    std::map<format::HandleId, vulkan_wrappers::OpticalFlowSessionNVWrapper*> opticalFlowSessionNV_map_;
    std::map<format::HandleId, vulkan_wrappers::PerformanceConfigurationINTELWrapper*> performanceConfigurationINTEL_map_;
    std::map<format::HandleId, vulkan_wrappers::PhysicalDeviceWrapper*> physicalDevice_map_;
    std::map<format::HandleId, vulkan_wrappers::PipelineWrapper*> pipeline_map_;
    std::map<format::HandleId, vulkan_wrappers::PipelineCacheWrapper*> pipelineCache_map_;
    std::map<format::HandleId, vulkan_wrappers::PipelineLayoutWrapper*> pipelineLayout_map_;
    std::map<format::HandleId, vulkan_wrappers::PrivateDataSlotWrapper*> privateDataSlot_map_;
    std::map<format::HandleId, vulkan_wrappers::QueryPoolWrapper*> queryPool_map_;
    std::map<format::HandleId, vulkan_wrappers::QueueWrapper*> queue_map_;
    std::map<format::HandleId, vulkan_wrappers::RenderPassWrapper*> renderPass_map_;
    std::map<format::HandleId, vulkan_wrappers::SamplerWrapper*> sampler_map_;
    std::map<format::HandleId, vulkan_wrappers::SamplerYcbcrConversionWrapper*> samplerYcbcrConversion_map_;
    std::map<format::HandleId, vulkan_wrappers::SemaphoreWrapper*> semaphore_map_;
    std::map<format::HandleId, vulkan_wrappers::ShaderEXTWrapper*> shaderEXT_map_;
    std::map<format::HandleId, vulkan_wrappers::ShaderModuleWrapper*> shaderModule_map_;
    std::map<format::HandleId, vulkan_wrappers::SurfaceKHRWrapper*> surfaceKHR_map_;
    std::map<format::HandleId, vulkan_wrappers::SwapchainKHRWrapper*> swapchainKHR_map_;
    std::map<format::HandleId, vulkan_wrappers::ValidationCacheEXTWrapper*> validationCacheEXT_map_;
    std::map<format::HandleId, vulkan_wrappers::VideoSessionKHRWrapper*> videoSessionKHR_map_;
    std::map<format::HandleId, vulkan_wrappers::VideoSessionParametersKHRWrapper*> videoSessionParametersKHR_map_;
};

class VulkanStateHandleTable : VulkanStateTableBase
{
  public:
    VulkanStateHandleTable() {}
    ~VulkanStateHandleTable() {}

    bool InsertWrapper(vulkan_wrappers::AccelerationStructureKHRWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, accelerationStructureKHR_map_); }
    bool InsertWrapper(vulkan_wrappers::AccelerationStructureNVWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, accelerationStructureNV_map_); }
    bool InsertWrapper(vulkan_wrappers::BufferWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, buffer_map_); }
    bool InsertWrapper(vulkan_wrappers::BufferViewWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, bufferView_map_); }
    bool InsertWrapper(vulkan_wrappers::CommandBufferWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, commandBuffer_map_); }
    bool InsertWrapper(vulkan_wrappers::CommandPoolWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, commandPool_map_); }
    bool InsertWrapper(vulkan_wrappers::DebugReportCallbackEXTWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, debugReportCallbackEXT_map_); }
    bool InsertWrapper(vulkan_wrappers::DebugUtilsMessengerEXTWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, debugUtilsMessengerEXT_map_); }
    bool InsertWrapper(vulkan_wrappers::DeferredOperationKHRWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, deferredOperationKHR_map_); }
    bool InsertWrapper(vulkan_wrappers::DescriptorPoolWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, descriptorPool_map_); }
    bool InsertWrapper(vulkan_wrappers::DescriptorSetWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, descriptorSet_map_); }
    bool InsertWrapper(vulkan_wrappers::DescriptorSetLayoutWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, descriptorSetLayout_map_); }
    bool InsertWrapper(vulkan_wrappers::DescriptorUpdateTemplateWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, descriptorUpdateTemplate_map_); }
    bool InsertWrapper(vulkan_wrappers::DeviceWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, device_map_); }
    bool InsertWrapper(vulkan_wrappers::DeviceMemoryWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, deviceMemory_map_); }
    bool InsertWrapper(vulkan_wrappers::DisplayKHRWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, displayKHR_map_); }
    bool InsertWrapper(vulkan_wrappers::DisplayModeKHRWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, displayModeKHR_map_); }
    bool InsertWrapper(vulkan_wrappers::EventWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, event_map_); }
    bool InsertWrapper(vulkan_wrappers::FenceWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, fence_map_); }
    bool InsertWrapper(vulkan_wrappers::FramebufferWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, framebuffer_map_); }
    bool InsertWrapper(vulkan_wrappers::ImageWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, image_map_); }
    bool InsertWrapper(vulkan_wrappers::ImageViewWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, imageView_map_); }
    bool InsertWrapper(vulkan_wrappers::IndirectCommandsLayoutNVWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, indirectCommandsLayoutNV_map_); }
    bool InsertWrapper(vulkan_wrappers::InstanceWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, instance_map_); }
    bool InsertWrapper(vulkan_wrappers::MicromapEXTWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, micromapEXT_map_); }
    bool InsertWrapper(vulkan_wrappers::OpticalFlowSessionNVWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, opticalFlowSessionNV_map_); }
    bool InsertWrapper(vulkan_wrappers::PerformanceConfigurationINTELWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, performanceConfigurationINTEL_map_); }
    bool InsertWrapper(vulkan_wrappers::PhysicalDeviceWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, physicalDevice_map_); }
    bool InsertWrapper(vulkan_wrappers::PipelineWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, pipeline_map_); }
    bool InsertWrapper(vulkan_wrappers::PipelineCacheWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, pipelineCache_map_); }
    bool InsertWrapper(vulkan_wrappers::PipelineLayoutWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, pipelineLayout_map_); }
    bool InsertWrapper(vulkan_wrappers::PrivateDataSlotWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, privateDataSlot_map_); }
    bool InsertWrapper(vulkan_wrappers::QueryPoolWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, queryPool_map_); }
    bool InsertWrapper(vulkan_wrappers::QueueWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, queue_map_); }
    bool InsertWrapper(vulkan_wrappers::RenderPassWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, renderPass_map_); }
    bool InsertWrapper(vulkan_wrappers::SamplerWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, sampler_map_); }
    bool InsertWrapper(vulkan_wrappers::SamplerYcbcrConversionWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, samplerYcbcrConversion_map_); }
    bool InsertWrapper(vulkan_wrappers::SemaphoreWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, semaphore_map_); }
    bool InsertWrapper(vulkan_wrappers::ShaderEXTWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, shaderEXT_map_); }
    bool InsertWrapper(vulkan_wrappers::ShaderModuleWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, shaderModule_map_); }
    bool InsertWrapper(vulkan_wrappers::SurfaceKHRWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, surfaceKHR_map_); }
    bool InsertWrapper(vulkan_wrappers::SwapchainKHRWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, swapchainKHR_map_); }
    bool InsertWrapper(vulkan_wrappers::ValidationCacheEXTWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, validationCacheEXT_map_); }
    bool InsertWrapper(vulkan_wrappers::VideoSessionKHRWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, videoSessionKHR_map_); }
    bool InsertWrapper(vulkan_wrappers::VideoSessionParametersKHRWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, videoSessionParametersKHR_map_); }

    bool RemoveWrapper(const vulkan_wrappers::AccelerationStructureKHRWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, accelerationStructureKHR_map_);
    }
    bool RemoveWrapper(const vulkan_wrappers::AccelerationStructureNVWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, accelerationStructureNV_map_);
    }
    bool RemoveWrapper(const vulkan_wrappers::BufferWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, buffer_map_);
    }
    bool RemoveWrapper(const vulkan_wrappers::BufferViewWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, bufferView_map_);
    }
    bool RemoveWrapper(const vulkan_wrappers::CommandBufferWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, commandBuffer_map_);
    }
    bool RemoveWrapper(const vulkan_wrappers::CommandPoolWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, commandPool_map_);
    }
    bool RemoveWrapper(const vulkan_wrappers::DebugReportCallbackEXTWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, debugReportCallbackEXT_map_);
    }
    bool RemoveWrapper(const vulkan_wrappers::DebugUtilsMessengerEXTWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, debugUtilsMessengerEXT_map_);
    }
    bool RemoveWrapper(const vulkan_wrappers::DeferredOperationKHRWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, deferredOperationKHR_map_);
    }
    bool RemoveWrapper(const vulkan_wrappers::DescriptorPoolWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, descriptorPool_map_);
    }
    bool RemoveWrapper(const vulkan_wrappers::DescriptorSetWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, descriptorSet_map_);
    }
    bool RemoveWrapper(const vulkan_wrappers::DescriptorSetLayoutWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, descriptorSetLayout_map_);
    }
    bool RemoveWrapper(const vulkan_wrappers::DescriptorUpdateTemplateWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, descriptorUpdateTemplate_map_);
    }
    bool RemoveWrapper(const vulkan_wrappers::DeviceWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, device_map_);
    }
    bool RemoveWrapper(const vulkan_wrappers::DeviceMemoryWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, deviceMemory_map_);
    }
    bool RemoveWrapper(const vulkan_wrappers::DisplayKHRWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, displayKHR_map_);
    }
    bool RemoveWrapper(const vulkan_wrappers::DisplayModeKHRWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, displayModeKHR_map_);
    }
    bool RemoveWrapper(const vulkan_wrappers::EventWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, event_map_);
    }
    bool RemoveWrapper(const vulkan_wrappers::FenceWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, fence_map_);
    }
    bool RemoveWrapper(const vulkan_wrappers::FramebufferWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, framebuffer_map_);
    }
    bool RemoveWrapper(const vulkan_wrappers::ImageWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, image_map_);
    }
    bool RemoveWrapper(const vulkan_wrappers::ImageViewWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, imageView_map_);
    }
    bool RemoveWrapper(const vulkan_wrappers::IndirectCommandsLayoutNVWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, indirectCommandsLayoutNV_map_);
    }
    bool RemoveWrapper(const vulkan_wrappers::InstanceWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, instance_map_);
    }
    bool RemoveWrapper(const vulkan_wrappers::MicromapEXTWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, micromapEXT_map_);
    }
    bool RemoveWrapper(const vulkan_wrappers::OpticalFlowSessionNVWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, opticalFlowSessionNV_map_);
    }
    bool RemoveWrapper(const vulkan_wrappers::PerformanceConfigurationINTELWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, performanceConfigurationINTEL_map_);
    }
    bool RemoveWrapper(const vulkan_wrappers::PhysicalDeviceWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, physicalDevice_map_);
    }
    bool RemoveWrapper(const vulkan_wrappers::PipelineWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, pipeline_map_);
    }
    bool RemoveWrapper(const vulkan_wrappers::PipelineCacheWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, pipelineCache_map_);
    }
    bool RemoveWrapper(const vulkan_wrappers::PipelineLayoutWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, pipelineLayout_map_);
    }
    bool RemoveWrapper(const vulkan_wrappers::PrivateDataSlotWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, privateDataSlot_map_);
    }
    bool RemoveWrapper(const vulkan_wrappers::QueryPoolWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, queryPool_map_);
    }
    bool RemoveWrapper(const vulkan_wrappers::QueueWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, queue_map_);
    }
    bool RemoveWrapper(const vulkan_wrappers::RenderPassWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, renderPass_map_);
    }
    bool RemoveWrapper(const vulkan_wrappers::SamplerWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, sampler_map_);
    }
    bool RemoveWrapper(const vulkan_wrappers::SamplerYcbcrConversionWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, samplerYcbcrConversion_map_);
    }
    bool RemoveWrapper(const vulkan_wrappers::SemaphoreWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, semaphore_map_);
    }
    bool RemoveWrapper(const vulkan_wrappers::ShaderEXTWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, shaderEXT_map_);
    }
    bool RemoveWrapper(const vulkan_wrappers::ShaderModuleWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, shaderModule_map_);
    }
    bool RemoveWrapper(const vulkan_wrappers::SurfaceKHRWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, surfaceKHR_map_);
    }
    bool RemoveWrapper(const vulkan_wrappers::SwapchainKHRWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, swapchainKHR_map_);
    }
    bool RemoveWrapper(const vulkan_wrappers::ValidationCacheEXTWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, validationCacheEXT_map_);
    }
    bool RemoveWrapper(const vulkan_wrappers::VideoSessionKHRWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, videoSessionKHR_map_);
    }
    bool RemoveWrapper(const vulkan_wrappers::VideoSessionParametersKHRWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, videoSessionParametersKHR_map_);
    }

    template<typename Wrapper> const Wrapper* GetWrapper(typename Wrapper::HandleType handle) const { return nullptr; }

    template<typename Wrapper> Wrapper* GetWrapper(typename Wrapper::HandleType handle) { return nullptr; }

  private:
    std::unordered_map<VkAccelerationStructureKHR, vulkan_wrappers::AccelerationStructureKHRWrapper*> accelerationStructureKHR_map_;
    std::unordered_map<VkAccelerationStructureNV, vulkan_wrappers::AccelerationStructureNVWrapper*> accelerationStructureNV_map_;
    std::unordered_map<VkBuffer, vulkan_wrappers::BufferWrapper*> buffer_map_;
    std::unordered_map<VkBufferView, vulkan_wrappers::BufferViewWrapper*> bufferView_map_;
    std::unordered_map<VkCommandBuffer, vulkan_wrappers::CommandBufferWrapper*> commandBuffer_map_;
    std::unordered_map<VkCommandPool, vulkan_wrappers::CommandPoolWrapper*> commandPool_map_;
    std::unordered_map<VkDebugReportCallbackEXT, vulkan_wrappers::DebugReportCallbackEXTWrapper*> debugReportCallbackEXT_map_;
    std::unordered_map<VkDebugUtilsMessengerEXT, vulkan_wrappers::DebugUtilsMessengerEXTWrapper*> debugUtilsMessengerEXT_map_;
    std::unordered_map<VkDeferredOperationKHR, vulkan_wrappers::DeferredOperationKHRWrapper*> deferredOperationKHR_map_;
    std::unordered_map<VkDescriptorPool, vulkan_wrappers::DescriptorPoolWrapper*> descriptorPool_map_;
    std::unordered_map<VkDescriptorSet, vulkan_wrappers::DescriptorSetWrapper*> descriptorSet_map_;
    std::unordered_map<VkDescriptorSetLayout, vulkan_wrappers::DescriptorSetLayoutWrapper*> descriptorSetLayout_map_;
    std::unordered_map<VkDescriptorUpdateTemplate, vulkan_wrappers::DescriptorUpdateTemplateWrapper*> descriptorUpdateTemplate_map_;
    std::unordered_map<VkDevice, vulkan_wrappers::DeviceWrapper*> device_map_;
    std::unordered_map<VkDeviceMemory, vulkan_wrappers::DeviceMemoryWrapper*> deviceMemory_map_;
    std::unordered_map<VkDisplayKHR, vulkan_wrappers::DisplayKHRWrapper*> displayKHR_map_;
    std::unordered_map<VkDisplayModeKHR, vulkan_wrappers::DisplayModeKHRWrapper*> displayModeKHR_map_;
    std::unordered_map<VkEvent, vulkan_wrappers::EventWrapper*> event_map_;
    std::unordered_map<VkFence, vulkan_wrappers::FenceWrapper*> fence_map_;
    std::unordered_map<VkFramebuffer, vulkan_wrappers::FramebufferWrapper*> framebuffer_map_;
    std::unordered_map<VkImage, vulkan_wrappers::ImageWrapper*> image_map_;
    std::unordered_map<VkImageView, vulkan_wrappers::ImageViewWrapper*> imageView_map_;
    std::unordered_map<VkIndirectCommandsLayoutNV, vulkan_wrappers::IndirectCommandsLayoutNVWrapper*> indirectCommandsLayoutNV_map_;
    std::unordered_map<VkInstance, vulkan_wrappers::InstanceWrapper*> instance_map_;
    std::unordered_map<VkMicromapEXT, vulkan_wrappers::MicromapEXTWrapper*> micromapEXT_map_;
    std::unordered_map<VkOpticalFlowSessionNV, vulkan_wrappers::OpticalFlowSessionNVWrapper*> opticalFlowSessionNV_map_;
    std::unordered_map<VkPerformanceConfigurationINTEL, vulkan_wrappers::PerformanceConfigurationINTELWrapper*> performanceConfigurationINTEL_map_;
    std::unordered_map<VkPhysicalDevice, vulkan_wrappers::PhysicalDeviceWrapper*> physicalDevice_map_;
    std::unordered_map<VkPipeline, vulkan_wrappers::PipelineWrapper*> pipeline_map_;
    std::unordered_map<VkPipelineCache, vulkan_wrappers::PipelineCacheWrapper*> pipelineCache_map_;
    std::unordered_map<VkPipelineLayout, vulkan_wrappers::PipelineLayoutWrapper*> pipelineLayout_map_;
    std::unordered_map<VkPrivateDataSlot, vulkan_wrappers::PrivateDataSlotWrapper*> privateDataSlot_map_;
    std::unordered_map<VkQueryPool, vulkan_wrappers::QueryPoolWrapper*> queryPool_map_;
    std::unordered_map<VkQueue, vulkan_wrappers::QueueWrapper*> queue_map_;
    std::unordered_map<VkRenderPass, vulkan_wrappers::RenderPassWrapper*> renderPass_map_;
    std::unordered_map<VkSampler, vulkan_wrappers::SamplerWrapper*> sampler_map_;
    std::unordered_map<VkSamplerYcbcrConversion, vulkan_wrappers::SamplerYcbcrConversionWrapper*> samplerYcbcrConversion_map_;
    std::unordered_map<VkSemaphore, vulkan_wrappers::SemaphoreWrapper*> semaphore_map_;
    std::unordered_map<VkShaderEXT, vulkan_wrappers::ShaderEXTWrapper*> shaderEXT_map_;
    std::unordered_map<VkShaderModule, vulkan_wrappers::ShaderModuleWrapper*> shaderModule_map_;
    std::unordered_map<VkSurfaceKHR, vulkan_wrappers::SurfaceKHRWrapper*> surfaceKHR_map_;
    std::unordered_map<VkSwapchainKHR, vulkan_wrappers::SwapchainKHRWrapper*> swapchainKHR_map_;
    std::unordered_map<VkValidationCacheEXT, vulkan_wrappers::ValidationCacheEXTWrapper*> validationCacheEXT_map_;
    std::unordered_map<VkVideoSessionKHR, vulkan_wrappers::VideoSessionKHRWrapper*> videoSessionKHR_map_;
    std::unordered_map<VkVideoSessionParametersKHR, vulkan_wrappers::VideoSessionParametersKHRWrapper*> videoSessionParametersKHR_map_;
};

template<> inline const vulkan_wrappers::AccelerationStructureKHRWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::AccelerationStructureKHRWrapper>(VkAccelerationStructureKHR handle) const { return VulkanStateTableBase::GetWrapper(handle, accelerationStructureKHR_map_); }
template<> inline const vulkan_wrappers::AccelerationStructureNVWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::AccelerationStructureNVWrapper>(VkAccelerationStructureNV handle) const { return VulkanStateTableBase::GetWrapper(handle, accelerationStructureNV_map_); }
template<> inline const vulkan_wrappers::BufferWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::BufferWrapper>(VkBuffer handle) const { return VulkanStateTableBase::GetWrapper(handle, buffer_map_); }
template<> inline const vulkan_wrappers::BufferViewWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::BufferViewWrapper>(VkBufferView handle) const { return VulkanStateTableBase::GetWrapper(handle, bufferView_map_); }
template<> inline const vulkan_wrappers::CommandBufferWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(VkCommandBuffer handle) const { return VulkanStateTableBase::GetWrapper(handle, commandBuffer_map_); }
template<> inline const vulkan_wrappers::CommandPoolWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::CommandPoolWrapper>(VkCommandPool handle) const { return VulkanStateTableBase::GetWrapper(handle, commandPool_map_); }
template<> inline const vulkan_wrappers::DebugReportCallbackEXTWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::DebugReportCallbackEXTWrapper>(VkDebugReportCallbackEXT handle) const { return VulkanStateTableBase::GetWrapper(handle, debugReportCallbackEXT_map_); }
template<> inline const vulkan_wrappers::DebugUtilsMessengerEXTWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::DebugUtilsMessengerEXTWrapper>(VkDebugUtilsMessengerEXT handle) const { return VulkanStateTableBase::GetWrapper(handle, debugUtilsMessengerEXT_map_); }
template<> inline const vulkan_wrappers::DeferredOperationKHRWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::DeferredOperationKHRWrapper>(VkDeferredOperationKHR handle) const { return VulkanStateTableBase::GetWrapper(handle, deferredOperationKHR_map_); }
template<> inline const vulkan_wrappers::DescriptorPoolWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::DescriptorPoolWrapper>(VkDescriptorPool handle) const { return VulkanStateTableBase::GetWrapper(handle, descriptorPool_map_); }
template<> inline const vulkan_wrappers::DescriptorSetWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::DescriptorSetWrapper>(VkDescriptorSet handle) const { return VulkanStateTableBase::GetWrapper(handle, descriptorSet_map_); }
template<> inline const vulkan_wrappers::DescriptorSetLayoutWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::DescriptorSetLayoutWrapper>(VkDescriptorSetLayout handle) const { return VulkanStateTableBase::GetWrapper(handle, descriptorSetLayout_map_); }
template<> inline const vulkan_wrappers::DescriptorUpdateTemplateWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::DescriptorUpdateTemplateWrapper>(VkDescriptorUpdateTemplate handle) const { return VulkanStateTableBase::GetWrapper(handle, descriptorUpdateTemplate_map_); }
template<> inline const vulkan_wrappers::DeviceWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::DeviceWrapper>(VkDevice handle) const { return VulkanStateTableBase::GetWrapper(handle, device_map_); }
template<> inline const vulkan_wrappers::DeviceMemoryWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::DeviceMemoryWrapper>(VkDeviceMemory handle) const { return VulkanStateTableBase::GetWrapper(handle, deviceMemory_map_); }
template<> inline const vulkan_wrappers::DisplayKHRWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::DisplayKHRWrapper>(VkDisplayKHR handle) const { return VulkanStateTableBase::GetWrapper(handle, displayKHR_map_); }
template<> inline const vulkan_wrappers::DisplayModeKHRWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::DisplayModeKHRWrapper>(VkDisplayModeKHR handle) const { return VulkanStateTableBase::GetWrapper(handle, displayModeKHR_map_); }
template<> inline const vulkan_wrappers::EventWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::EventWrapper>(VkEvent handle) const { return VulkanStateTableBase::GetWrapper(handle, event_map_); }
template<> inline const vulkan_wrappers::FenceWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::FenceWrapper>(VkFence handle) const { return VulkanStateTableBase::GetWrapper(handle, fence_map_); }
template<> inline const vulkan_wrappers::FramebufferWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::FramebufferWrapper>(VkFramebuffer handle) const { return VulkanStateTableBase::GetWrapper(handle, framebuffer_map_); }
template<> inline const vulkan_wrappers::ImageWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::ImageWrapper>(VkImage handle) const { return VulkanStateTableBase::GetWrapper(handle, image_map_); }
template<> inline const vulkan_wrappers::ImageViewWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::ImageViewWrapper>(VkImageView handle) const { return VulkanStateTableBase::GetWrapper(handle, imageView_map_); }
template<> inline const vulkan_wrappers::IndirectCommandsLayoutNVWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::IndirectCommandsLayoutNVWrapper>(VkIndirectCommandsLayoutNV handle) const { return VulkanStateTableBase::GetWrapper(handle, indirectCommandsLayoutNV_map_); }
template<> inline const vulkan_wrappers::InstanceWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::InstanceWrapper>(VkInstance handle) const { return VulkanStateTableBase::GetWrapper(handle, instance_map_); }
template<> inline const vulkan_wrappers::MicromapEXTWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::MicromapEXTWrapper>(VkMicromapEXT handle) const { return VulkanStateTableBase::GetWrapper(handle, micromapEXT_map_); }
template<> inline const vulkan_wrappers::OpticalFlowSessionNVWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::OpticalFlowSessionNVWrapper>(VkOpticalFlowSessionNV handle) const { return VulkanStateTableBase::GetWrapper(handle, opticalFlowSessionNV_map_); }
template<> inline const vulkan_wrappers::PerformanceConfigurationINTELWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::PerformanceConfigurationINTELWrapper>(VkPerformanceConfigurationINTEL handle) const { return VulkanStateTableBase::GetWrapper(handle, performanceConfigurationINTEL_map_); }
template<> inline const vulkan_wrappers::PhysicalDeviceWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::PhysicalDeviceWrapper>(VkPhysicalDevice handle) const { return VulkanStateTableBase::GetWrapper(handle, physicalDevice_map_); }
template<> inline const vulkan_wrappers::PipelineWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::PipelineWrapper>(VkPipeline handle) const { return VulkanStateTableBase::GetWrapper(handle, pipeline_map_); }
template<> inline const vulkan_wrappers::PipelineCacheWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::PipelineCacheWrapper>(VkPipelineCache handle) const { return VulkanStateTableBase::GetWrapper(handle, pipelineCache_map_); }
template<> inline const vulkan_wrappers::PipelineLayoutWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::PipelineLayoutWrapper>(VkPipelineLayout handle) const { return VulkanStateTableBase::GetWrapper(handle, pipelineLayout_map_); }
template<> inline const vulkan_wrappers::PrivateDataSlotWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::PrivateDataSlotWrapper>(VkPrivateDataSlot handle) const { return VulkanStateTableBase::GetWrapper(handle, privateDataSlot_map_); }
template<> inline const vulkan_wrappers::QueryPoolWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::QueryPoolWrapper>(VkQueryPool handle) const { return VulkanStateTableBase::GetWrapper(handle, queryPool_map_); }
template<> inline const vulkan_wrappers::QueueWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::QueueWrapper>(VkQueue handle) const { return VulkanStateTableBase::GetWrapper(handle, queue_map_); }
template<> inline const vulkan_wrappers::RenderPassWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::RenderPassWrapper>(VkRenderPass handle) const { return VulkanStateTableBase::GetWrapper(handle, renderPass_map_); }
template<> inline const vulkan_wrappers::SamplerWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::SamplerWrapper>(VkSampler handle) const { return VulkanStateTableBase::GetWrapper(handle, sampler_map_); }
template<> inline const vulkan_wrappers::SamplerYcbcrConversionWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::SamplerYcbcrConversionWrapper>(VkSamplerYcbcrConversion handle) const { return VulkanStateTableBase::GetWrapper(handle, samplerYcbcrConversion_map_); }
template<> inline const vulkan_wrappers::SemaphoreWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::SemaphoreWrapper>(VkSemaphore handle) const { return VulkanStateTableBase::GetWrapper(handle, semaphore_map_); }
template<> inline const vulkan_wrappers::ShaderEXTWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::ShaderEXTWrapper>(VkShaderEXT handle) const { return VulkanStateTableBase::GetWrapper(handle, shaderEXT_map_); }
template<> inline const vulkan_wrappers::ShaderModuleWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::ShaderModuleWrapper>(VkShaderModule handle) const { return VulkanStateTableBase::GetWrapper(handle, shaderModule_map_); }
template<> inline const vulkan_wrappers::SurfaceKHRWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::SurfaceKHRWrapper>(VkSurfaceKHR handle) const { return VulkanStateTableBase::GetWrapper(handle, surfaceKHR_map_); }
template<> inline const vulkan_wrappers::SwapchainKHRWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::SwapchainKHRWrapper>(VkSwapchainKHR handle) const { return VulkanStateTableBase::GetWrapper(handle, swapchainKHR_map_); }
template<> inline const vulkan_wrappers::ValidationCacheEXTWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::ValidationCacheEXTWrapper>(VkValidationCacheEXT handle) const { return VulkanStateTableBase::GetWrapper(handle, validationCacheEXT_map_); }
template<> inline const vulkan_wrappers::VideoSessionKHRWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::VideoSessionKHRWrapper>(VkVideoSessionKHR handle) const { return VulkanStateTableBase::GetWrapper(handle, videoSessionKHR_map_); }
template<> inline const vulkan_wrappers::VideoSessionParametersKHRWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::VideoSessionParametersKHRWrapper>(VkVideoSessionParametersKHR handle) const { return VulkanStateTableBase::GetWrapper(handle, videoSessionParametersKHR_map_); }

template<> inline vulkan_wrappers::AccelerationStructureKHRWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::AccelerationStructureKHRWrapper>(VkAccelerationStructureKHR handle) { return VulkanStateTableBase::GetWrapper(handle, accelerationStructureKHR_map_); }
template<> inline vulkan_wrappers::AccelerationStructureNVWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::AccelerationStructureNVWrapper>(VkAccelerationStructureNV handle) { return VulkanStateTableBase::GetWrapper(handle, accelerationStructureNV_map_); }
template<> inline vulkan_wrappers::BufferWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::BufferWrapper>(VkBuffer handle) { return VulkanStateTableBase::GetWrapper(handle, buffer_map_); }
template<> inline vulkan_wrappers::BufferViewWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::BufferViewWrapper>(VkBufferView handle) { return VulkanStateTableBase::GetWrapper(handle, bufferView_map_); }
template<> inline vulkan_wrappers::CommandBufferWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(VkCommandBuffer handle) { return VulkanStateTableBase::GetWrapper(handle, commandBuffer_map_); }
template<> inline vulkan_wrappers::CommandPoolWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::CommandPoolWrapper>(VkCommandPool handle) { return VulkanStateTableBase::GetWrapper(handle, commandPool_map_); }
template<> inline vulkan_wrappers::DebugReportCallbackEXTWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::DebugReportCallbackEXTWrapper>(VkDebugReportCallbackEXT handle) { return VulkanStateTableBase::GetWrapper(handle, debugReportCallbackEXT_map_); }
template<> inline vulkan_wrappers::DebugUtilsMessengerEXTWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::DebugUtilsMessengerEXTWrapper>(VkDebugUtilsMessengerEXT handle) { return VulkanStateTableBase::GetWrapper(handle, debugUtilsMessengerEXT_map_); }
template<> inline vulkan_wrappers::DeferredOperationKHRWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::DeferredOperationKHRWrapper>(VkDeferredOperationKHR handle) { return VulkanStateTableBase::GetWrapper(handle, deferredOperationKHR_map_); }
template<> inline vulkan_wrappers::DescriptorPoolWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::DescriptorPoolWrapper>(VkDescriptorPool handle) { return VulkanStateTableBase::GetWrapper(handle, descriptorPool_map_); }
template<> inline vulkan_wrappers::DescriptorSetWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::DescriptorSetWrapper>(VkDescriptorSet handle) { return VulkanStateTableBase::GetWrapper(handle, descriptorSet_map_); }
template<> inline vulkan_wrappers::DescriptorSetLayoutWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::DescriptorSetLayoutWrapper>(VkDescriptorSetLayout handle) { return VulkanStateTableBase::GetWrapper(handle, descriptorSetLayout_map_); }
template<> inline vulkan_wrappers::DescriptorUpdateTemplateWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::DescriptorUpdateTemplateWrapper>(VkDescriptorUpdateTemplate handle) { return VulkanStateTableBase::GetWrapper(handle, descriptorUpdateTemplate_map_); }
template<> inline vulkan_wrappers::DeviceWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::DeviceWrapper>(VkDevice handle) { return VulkanStateTableBase::GetWrapper(handle, device_map_); }
template<> inline vulkan_wrappers::DeviceMemoryWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::DeviceMemoryWrapper>(VkDeviceMemory handle) { return VulkanStateTableBase::GetWrapper(handle, deviceMemory_map_); }
template<> inline vulkan_wrappers::DisplayKHRWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::DisplayKHRWrapper>(VkDisplayKHR handle) { return VulkanStateTableBase::GetWrapper(handle, displayKHR_map_); }
template<> inline vulkan_wrappers::DisplayModeKHRWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::DisplayModeKHRWrapper>(VkDisplayModeKHR handle) { return VulkanStateTableBase::GetWrapper(handle, displayModeKHR_map_); }
template<> inline vulkan_wrappers::EventWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::EventWrapper>(VkEvent handle) { return VulkanStateTableBase::GetWrapper(handle, event_map_); }
template<> inline vulkan_wrappers::FenceWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::FenceWrapper>(VkFence handle) { return VulkanStateTableBase::GetWrapper(handle, fence_map_); }
template<> inline vulkan_wrappers::FramebufferWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::FramebufferWrapper>(VkFramebuffer handle) { return VulkanStateTableBase::GetWrapper(handle, framebuffer_map_); }
template<> inline vulkan_wrappers::ImageWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::ImageWrapper>(VkImage handle) { return VulkanStateTableBase::GetWrapper(handle, image_map_); }
template<> inline vulkan_wrappers::ImageViewWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::ImageViewWrapper>(VkImageView handle) { return VulkanStateTableBase::GetWrapper(handle, imageView_map_); }
template<> inline vulkan_wrappers::IndirectCommandsLayoutNVWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::IndirectCommandsLayoutNVWrapper>(VkIndirectCommandsLayoutNV handle) { return VulkanStateTableBase::GetWrapper(handle, indirectCommandsLayoutNV_map_); }
template<> inline vulkan_wrappers::InstanceWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::InstanceWrapper>(VkInstance handle) { return VulkanStateTableBase::GetWrapper(handle, instance_map_); }
template<> inline vulkan_wrappers::MicromapEXTWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::MicromapEXTWrapper>(VkMicromapEXT handle) { return VulkanStateTableBase::GetWrapper(handle, micromapEXT_map_); }
template<> inline vulkan_wrappers::OpticalFlowSessionNVWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::OpticalFlowSessionNVWrapper>(VkOpticalFlowSessionNV handle) { return VulkanStateTableBase::GetWrapper(handle, opticalFlowSessionNV_map_); }
template<> inline vulkan_wrappers::PerformanceConfigurationINTELWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::PerformanceConfigurationINTELWrapper>(VkPerformanceConfigurationINTEL handle) { return VulkanStateTableBase::GetWrapper(handle, performanceConfigurationINTEL_map_); }
template<> inline vulkan_wrappers::PhysicalDeviceWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::PhysicalDeviceWrapper>(VkPhysicalDevice handle) { return VulkanStateTableBase::GetWrapper(handle, physicalDevice_map_); }
template<> inline vulkan_wrappers::PipelineWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::PipelineWrapper>(VkPipeline handle) { return VulkanStateTableBase::GetWrapper(handle, pipeline_map_); }
template<> inline vulkan_wrappers::PipelineCacheWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::PipelineCacheWrapper>(VkPipelineCache handle) { return VulkanStateTableBase::GetWrapper(handle, pipelineCache_map_); }
template<> inline vulkan_wrappers::PipelineLayoutWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::PipelineLayoutWrapper>(VkPipelineLayout handle) { return VulkanStateTableBase::GetWrapper(handle, pipelineLayout_map_); }
template<> inline vulkan_wrappers::PrivateDataSlotWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::PrivateDataSlotWrapper>(VkPrivateDataSlot handle) { return VulkanStateTableBase::GetWrapper(handle, privateDataSlot_map_); }
template<> inline vulkan_wrappers::QueryPoolWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::QueryPoolWrapper>(VkQueryPool handle) { return VulkanStateTableBase::GetWrapper(handle, queryPool_map_); }
template<> inline vulkan_wrappers::QueueWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::QueueWrapper>(VkQueue handle) { return VulkanStateTableBase::GetWrapper(handle, queue_map_); }
template<> inline vulkan_wrappers::RenderPassWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::RenderPassWrapper>(VkRenderPass handle) { return VulkanStateTableBase::GetWrapper(handle, renderPass_map_); }
template<> inline vulkan_wrappers::SamplerWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::SamplerWrapper>(VkSampler handle) { return VulkanStateTableBase::GetWrapper(handle, sampler_map_); }
template<> inline vulkan_wrappers::SamplerYcbcrConversionWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::SamplerYcbcrConversionWrapper>(VkSamplerYcbcrConversion handle) { return VulkanStateTableBase::GetWrapper(handle, samplerYcbcrConversion_map_); }
template<> inline vulkan_wrappers::SemaphoreWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::SemaphoreWrapper>(VkSemaphore handle) { return VulkanStateTableBase::GetWrapper(handle, semaphore_map_); }
template<> inline vulkan_wrappers::ShaderEXTWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::ShaderEXTWrapper>(VkShaderEXT handle) { return VulkanStateTableBase::GetWrapper(handle, shaderEXT_map_); }
template<> inline vulkan_wrappers::ShaderModuleWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::ShaderModuleWrapper>(VkShaderModule handle) { return VulkanStateTableBase::GetWrapper(handle, shaderModule_map_); }
template<> inline vulkan_wrappers::SurfaceKHRWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::SurfaceKHRWrapper>(VkSurfaceKHR handle) { return VulkanStateTableBase::GetWrapper(handle, surfaceKHR_map_); }
template<> inline vulkan_wrappers::SwapchainKHRWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::SwapchainKHRWrapper>(VkSwapchainKHR handle) { return VulkanStateTableBase::GetWrapper(handle, swapchainKHR_map_); }
template<> inline vulkan_wrappers::ValidationCacheEXTWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::ValidationCacheEXTWrapper>(VkValidationCacheEXT handle) { return VulkanStateTableBase::GetWrapper(handle, validationCacheEXT_map_); }
template<> inline vulkan_wrappers::VideoSessionKHRWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::VideoSessionKHRWrapper>(VkVideoSessionKHR handle) { return VulkanStateTableBase::GetWrapper(handle, videoSessionKHR_map_); }
template<> inline vulkan_wrappers::VideoSessionParametersKHRWrapper* VulkanStateHandleTable::GetWrapper<vulkan_wrappers::VideoSessionParametersKHRWrapper>(VkVideoSessionParametersKHR handle) { return VulkanStateTableBase::GetWrapper(handle, videoSessionParametersKHR_map_); }

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
