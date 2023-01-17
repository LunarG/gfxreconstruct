/*
** Copyright (c) 2018-2021 Valve Corporation
** Copyright (c) 2018-2022 LunarG, Inc.
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

    bool InsertWrapper(format::HandleId id, AccelerationStructureKHRWrapper* wrapper) { return InsertEntry(id, wrapper, accelerationStructureKHR_map_); }
    bool InsertWrapper(format::HandleId id, AccelerationStructureNVWrapper* wrapper) { return InsertEntry(id, wrapper, accelerationStructureNV_map_); }
    bool InsertWrapper(format::HandleId id, BufferWrapper* wrapper) { return InsertEntry(id, wrapper, buffer_map_); }
    bool InsertWrapper(format::HandleId id, BufferViewWrapper* wrapper) { return InsertEntry(id, wrapper, bufferView_map_); }
    bool InsertWrapper(format::HandleId id, CommandBufferWrapper* wrapper) { return InsertEntry(id, wrapper, commandBuffer_map_); }
    bool InsertWrapper(format::HandleId id, CommandPoolWrapper* wrapper) { return InsertEntry(id, wrapper, commandPool_map_); }
    bool InsertWrapper(format::HandleId id, DebugReportCallbackEXTWrapper* wrapper) { return InsertEntry(id, wrapper, debugReportCallbackEXT_map_); }
    bool InsertWrapper(format::HandleId id, DebugUtilsMessengerEXTWrapper* wrapper) { return InsertEntry(id, wrapper, debugUtilsMessengerEXT_map_); }
    bool InsertWrapper(format::HandleId id, DeferredOperationKHRWrapper* wrapper) { return InsertEntry(id, wrapper, deferredOperationKHR_map_); }
    bool InsertWrapper(format::HandleId id, DescriptorPoolWrapper* wrapper) { return InsertEntry(id, wrapper, descriptorPool_map_); }
    bool InsertWrapper(format::HandleId id, DescriptorSetWrapper* wrapper) { return InsertEntry(id, wrapper, descriptorSet_map_); }
    bool InsertWrapper(format::HandleId id, DescriptorSetLayoutWrapper* wrapper) { return InsertEntry(id, wrapper, descriptorSetLayout_map_); }
    bool InsertWrapper(format::HandleId id, DescriptorUpdateTemplateWrapper* wrapper) { return InsertEntry(id, wrapper, descriptorUpdateTemplate_map_); }
    bool InsertWrapper(format::HandleId id, DeviceWrapper* wrapper) { return InsertEntry(id, wrapper, device_map_); }
    bool InsertWrapper(format::HandleId id, DeviceMemoryWrapper* wrapper) { return InsertEntry(id, wrapper, deviceMemory_map_); }
    bool InsertWrapper(format::HandleId id, DisplayKHRWrapper* wrapper) { return InsertEntry(id, wrapper, displayKHR_map_); }
    bool InsertWrapper(format::HandleId id, DisplayModeKHRWrapper* wrapper) { return InsertEntry(id, wrapper, displayModeKHR_map_); }
    bool InsertWrapper(format::HandleId id, EventWrapper* wrapper) { return InsertEntry(id, wrapper, event_map_); }
    bool InsertWrapper(format::HandleId id, FenceWrapper* wrapper) { return InsertEntry(id, wrapper, fence_map_); }
    bool InsertWrapper(format::HandleId id, FramebufferWrapper* wrapper) { return InsertEntry(id, wrapper, framebuffer_map_); }
    bool InsertWrapper(format::HandleId id, ImageWrapper* wrapper) { return InsertEntry(id, wrapper, image_map_); }
    bool InsertWrapper(format::HandleId id, ImageViewWrapper* wrapper) { return InsertEntry(id, wrapper, imageView_map_); }
    bool InsertWrapper(format::HandleId id, IndirectCommandsLayoutNVWrapper* wrapper) { return InsertEntry(id, wrapper, indirectCommandsLayoutNV_map_); }
    bool InsertWrapper(format::HandleId id, InstanceWrapper* wrapper) { return InsertEntry(id, wrapper, instance_map_); }
    bool InsertWrapper(format::HandleId id, MicromapEXTWrapper* wrapper) { return InsertEntry(id, wrapper, micromapEXT_map_); }
    bool InsertWrapper(format::HandleId id, OpticalFlowSessionNVWrapper* wrapper) { return InsertEntry(id, wrapper, opticalFlowSessionNV_map_); }
    bool InsertWrapper(format::HandleId id, PerformanceConfigurationINTELWrapper* wrapper) { return InsertEntry(id, wrapper, performanceConfigurationINTEL_map_); }
    bool InsertWrapper(format::HandleId id, PhysicalDeviceWrapper* wrapper) { return InsertEntry(id, wrapper, physicalDevice_map_); }
    bool InsertWrapper(format::HandleId id, PipelineWrapper* wrapper) { return InsertEntry(id, wrapper, pipeline_map_); }
    bool InsertWrapper(format::HandleId id, PipelineCacheWrapper* wrapper) { return InsertEntry(id, wrapper, pipelineCache_map_); }
    bool InsertWrapper(format::HandleId id, PipelineLayoutWrapper* wrapper) { return InsertEntry(id, wrapper, pipelineLayout_map_); }
    bool InsertWrapper(format::HandleId id, PrivateDataSlotWrapper* wrapper) { return InsertEntry(id, wrapper, privateDataSlot_map_); }
    bool InsertWrapper(format::HandleId id, QueryPoolWrapper* wrapper) { return InsertEntry(id, wrapper, queryPool_map_); }
    bool InsertWrapper(format::HandleId id, QueueWrapper* wrapper) { return InsertEntry(id, wrapper, queue_map_); }
    bool InsertWrapper(format::HandleId id, RenderPassWrapper* wrapper) { return InsertEntry(id, wrapper, renderPass_map_); }
    bool InsertWrapper(format::HandleId id, SamplerWrapper* wrapper) { return InsertEntry(id, wrapper, sampler_map_); }
    bool InsertWrapper(format::HandleId id, SamplerYcbcrConversionWrapper* wrapper) { return InsertEntry(id, wrapper, samplerYcbcrConversion_map_); }
    bool InsertWrapper(format::HandleId id, SemaphoreWrapper* wrapper) { return InsertEntry(id, wrapper, semaphore_map_); }
    bool InsertWrapper(format::HandleId id, ShaderModuleWrapper* wrapper) { return InsertEntry(id, wrapper, shaderModule_map_); }
    bool InsertWrapper(format::HandleId id, SurfaceKHRWrapper* wrapper) { return InsertEntry(id, wrapper, surfaceKHR_map_); }
    bool InsertWrapper(format::HandleId id, SwapchainKHRWrapper* wrapper) { return InsertEntry(id, wrapper, swapchainKHR_map_); }
    bool InsertWrapper(format::HandleId id, ValidationCacheEXTWrapper* wrapper) { return InsertEntry(id, wrapper, validationCacheEXT_map_); }
    bool InsertWrapper(format::HandleId id, VideoSessionKHRWrapper* wrapper) { return InsertEntry(id, wrapper, videoSessionKHR_map_); }
    bool InsertWrapper(format::HandleId id, VideoSessionParametersKHRWrapper* wrapper) { return InsertEntry(id, wrapper, videoSessionParametersKHR_map_); }

    bool RemoveWrapper(const AccelerationStructureKHRWrapper* wrapper) { return RemoveEntry(wrapper, accelerationStructureKHR_map_); }
    bool RemoveWrapper(const AccelerationStructureNVWrapper* wrapper) { return RemoveEntry(wrapper, accelerationStructureNV_map_); }
    bool RemoveWrapper(const BufferWrapper* wrapper) { return RemoveEntry(wrapper, buffer_map_); }
    bool RemoveWrapper(const BufferViewWrapper* wrapper) { return RemoveEntry(wrapper, bufferView_map_); }
    bool RemoveWrapper(const CommandBufferWrapper* wrapper) { return RemoveEntry(wrapper, commandBuffer_map_); }
    bool RemoveWrapper(const CommandPoolWrapper* wrapper) { return RemoveEntry(wrapper, commandPool_map_); }
    bool RemoveWrapper(const DebugReportCallbackEXTWrapper* wrapper) { return RemoveEntry(wrapper, debugReportCallbackEXT_map_); }
    bool RemoveWrapper(const DebugUtilsMessengerEXTWrapper* wrapper) { return RemoveEntry(wrapper, debugUtilsMessengerEXT_map_); }
    bool RemoveWrapper(const DeferredOperationKHRWrapper* wrapper) { return RemoveEntry(wrapper, deferredOperationKHR_map_); }
    bool RemoveWrapper(const DescriptorPoolWrapper* wrapper) { return RemoveEntry(wrapper, descriptorPool_map_); }
    bool RemoveWrapper(const DescriptorSetWrapper* wrapper) { return RemoveEntry(wrapper, descriptorSet_map_); }
    bool RemoveWrapper(const DescriptorSetLayoutWrapper* wrapper) { return RemoveEntry(wrapper, descriptorSetLayout_map_); }
    bool RemoveWrapper(const DescriptorUpdateTemplateWrapper* wrapper) { return RemoveEntry(wrapper, descriptorUpdateTemplate_map_); }
    bool RemoveWrapper(const DeviceWrapper* wrapper) { return RemoveEntry(wrapper, device_map_); }
    bool RemoveWrapper(const DeviceMemoryWrapper* wrapper) { return RemoveEntry(wrapper, deviceMemory_map_); }
    bool RemoveWrapper(const DisplayKHRWrapper* wrapper) { return RemoveEntry(wrapper, displayKHR_map_); }
    bool RemoveWrapper(const DisplayModeKHRWrapper* wrapper) { return RemoveEntry(wrapper, displayModeKHR_map_); }
    bool RemoveWrapper(const EventWrapper* wrapper) { return RemoveEntry(wrapper, event_map_); }
    bool RemoveWrapper(const FenceWrapper* wrapper) { return RemoveEntry(wrapper, fence_map_); }
    bool RemoveWrapper(const FramebufferWrapper* wrapper) { return RemoveEntry(wrapper, framebuffer_map_); }
    bool RemoveWrapper(const ImageWrapper* wrapper) { return RemoveEntry(wrapper, image_map_); }
    bool RemoveWrapper(const ImageViewWrapper* wrapper) { return RemoveEntry(wrapper, imageView_map_); }
    bool RemoveWrapper(const IndirectCommandsLayoutNVWrapper* wrapper) { return RemoveEntry(wrapper, indirectCommandsLayoutNV_map_); }
    bool RemoveWrapper(const InstanceWrapper* wrapper) { return RemoveEntry(wrapper, instance_map_); }
    bool RemoveWrapper(const MicromapEXTWrapper* wrapper) { return RemoveEntry(wrapper, micromapEXT_map_); }
    bool RemoveWrapper(const OpticalFlowSessionNVWrapper* wrapper) { return RemoveEntry(wrapper, opticalFlowSessionNV_map_); }
    bool RemoveWrapper(const PerformanceConfigurationINTELWrapper* wrapper) { return RemoveEntry(wrapper, performanceConfigurationINTEL_map_); }
    bool RemoveWrapper(const PhysicalDeviceWrapper* wrapper) { return RemoveEntry(wrapper, physicalDevice_map_); }
    bool RemoveWrapper(const PipelineWrapper* wrapper) { return RemoveEntry(wrapper, pipeline_map_); }
    bool RemoveWrapper(const PipelineCacheWrapper* wrapper) { return RemoveEntry(wrapper, pipelineCache_map_); }
    bool RemoveWrapper(const PipelineLayoutWrapper* wrapper) { return RemoveEntry(wrapper, pipelineLayout_map_); }
    bool RemoveWrapper(const PrivateDataSlotWrapper* wrapper) { return RemoveEntry(wrapper, privateDataSlot_map_); }
    bool RemoveWrapper(const QueryPoolWrapper* wrapper) { return RemoveEntry(wrapper, queryPool_map_); }
    bool RemoveWrapper(const QueueWrapper* wrapper) { return RemoveEntry(wrapper, queue_map_); }
    bool RemoveWrapper(const RenderPassWrapper* wrapper) { return RemoveEntry(wrapper, renderPass_map_); }
    bool RemoveWrapper(const SamplerWrapper* wrapper) { return RemoveEntry(wrapper, sampler_map_); }
    bool RemoveWrapper(const SamplerYcbcrConversionWrapper* wrapper) { return RemoveEntry(wrapper, samplerYcbcrConversion_map_); }
    bool RemoveWrapper(const SemaphoreWrapper* wrapper) { return RemoveEntry(wrapper, semaphore_map_); }
    bool RemoveWrapper(const ShaderModuleWrapper* wrapper) { return RemoveEntry(wrapper, shaderModule_map_); }
    bool RemoveWrapper(const SurfaceKHRWrapper* wrapper) { return RemoveEntry(wrapper, surfaceKHR_map_); }
    bool RemoveWrapper(const SwapchainKHRWrapper* wrapper) { return RemoveEntry(wrapper, swapchainKHR_map_); }
    bool RemoveWrapper(const ValidationCacheEXTWrapper* wrapper) { return RemoveEntry(wrapper, validationCacheEXT_map_); }
    bool RemoveWrapper(const VideoSessionKHRWrapper* wrapper) { return RemoveEntry(wrapper, videoSessionKHR_map_); }
    bool RemoveWrapper(const VideoSessionParametersKHRWrapper* wrapper) { return RemoveEntry(wrapper, videoSessionParametersKHR_map_); }

    const AccelerationStructureKHRWrapper* GetAccelerationStructureKHRWrapper(format::HandleId id) const { return GetWrapper<AccelerationStructureKHRWrapper>(id, accelerationStructureKHR_map_); }
    const AccelerationStructureNVWrapper* GetAccelerationStructureNVWrapper(format::HandleId id) const { return GetWrapper<AccelerationStructureNVWrapper>(id, accelerationStructureNV_map_); }
    const BufferWrapper* GetBufferWrapper(format::HandleId id) const { return GetWrapper<BufferWrapper>(id, buffer_map_); }
    const BufferViewWrapper* GetBufferViewWrapper(format::HandleId id) const { return GetWrapper<BufferViewWrapper>(id, bufferView_map_); }
    const CommandBufferWrapper* GetCommandBufferWrapper(format::HandleId id) const { return GetWrapper<CommandBufferWrapper>(id, commandBuffer_map_); }
    const CommandPoolWrapper* GetCommandPoolWrapper(format::HandleId id) const { return GetWrapper<CommandPoolWrapper>(id, commandPool_map_); }
    const DebugReportCallbackEXTWrapper* GetDebugReportCallbackEXTWrapper(format::HandleId id) const { return GetWrapper<DebugReportCallbackEXTWrapper>(id, debugReportCallbackEXT_map_); }
    const DebugUtilsMessengerEXTWrapper* GetDebugUtilsMessengerEXTWrapper(format::HandleId id) const { return GetWrapper<DebugUtilsMessengerEXTWrapper>(id, debugUtilsMessengerEXT_map_); }
    const DeferredOperationKHRWrapper* GetDeferredOperationKHRWrapper(format::HandleId id) const { return GetWrapper<DeferredOperationKHRWrapper>(id, deferredOperationKHR_map_); }
    const DescriptorPoolWrapper* GetDescriptorPoolWrapper(format::HandleId id) const { return GetWrapper<DescriptorPoolWrapper>(id, descriptorPool_map_); }
    const DescriptorSetWrapper* GetDescriptorSetWrapper(format::HandleId id) const { return GetWrapper<DescriptorSetWrapper>(id, descriptorSet_map_); }
    const DescriptorSetLayoutWrapper* GetDescriptorSetLayoutWrapper(format::HandleId id) const { return GetWrapper<DescriptorSetLayoutWrapper>(id, descriptorSetLayout_map_); }
    const DescriptorUpdateTemplateWrapper* GetDescriptorUpdateTemplateWrapper(format::HandleId id) const { return GetWrapper<DescriptorUpdateTemplateWrapper>(id, descriptorUpdateTemplate_map_); }
    const DeviceWrapper* GetDeviceWrapper(format::HandleId id) const { return GetWrapper<DeviceWrapper>(id, device_map_); }
    const DeviceMemoryWrapper* GetDeviceMemoryWrapper(format::HandleId id) const { return GetWrapper<DeviceMemoryWrapper>(id, deviceMemory_map_); }
    const DisplayKHRWrapper* GetDisplayKHRWrapper(format::HandleId id) const { return GetWrapper<DisplayKHRWrapper>(id, displayKHR_map_); }
    const DisplayModeKHRWrapper* GetDisplayModeKHRWrapper(format::HandleId id) const { return GetWrapper<DisplayModeKHRWrapper>(id, displayModeKHR_map_); }
    const EventWrapper* GetEventWrapper(format::HandleId id) const { return GetWrapper<EventWrapper>(id, event_map_); }
    const FenceWrapper* GetFenceWrapper(format::HandleId id) const { return GetWrapper<FenceWrapper>(id, fence_map_); }
    const FramebufferWrapper* GetFramebufferWrapper(format::HandleId id) const { return GetWrapper<FramebufferWrapper>(id, framebuffer_map_); }
    const ImageWrapper* GetImageWrapper(format::HandleId id) const { return GetWrapper<ImageWrapper>(id, image_map_); }
    const ImageViewWrapper* GetImageViewWrapper(format::HandleId id) const { return GetWrapper<ImageViewWrapper>(id, imageView_map_); }
    const IndirectCommandsLayoutNVWrapper* GetIndirectCommandsLayoutNVWrapper(format::HandleId id) const { return GetWrapper<IndirectCommandsLayoutNVWrapper>(id, indirectCommandsLayoutNV_map_); }
    const InstanceWrapper* GetInstanceWrapper(format::HandleId id) const { return GetWrapper<InstanceWrapper>(id, instance_map_); }
    const MicromapEXTWrapper* GetMicromapEXTWrapper(format::HandleId id) const { return GetWrapper<MicromapEXTWrapper>(id, micromapEXT_map_); }
    const OpticalFlowSessionNVWrapper* GetOpticalFlowSessionNVWrapper(format::HandleId id) const { return GetWrapper<OpticalFlowSessionNVWrapper>(id, opticalFlowSessionNV_map_); }
    const PerformanceConfigurationINTELWrapper* GetPerformanceConfigurationINTELWrapper(format::HandleId id) const { return GetWrapper<PerformanceConfigurationINTELWrapper>(id, performanceConfigurationINTEL_map_); }
    const PhysicalDeviceWrapper* GetPhysicalDeviceWrapper(format::HandleId id) const { return GetWrapper<PhysicalDeviceWrapper>(id, physicalDevice_map_); }
    const PipelineWrapper* GetPipelineWrapper(format::HandleId id) const { return GetWrapper<PipelineWrapper>(id, pipeline_map_); }
    const PipelineCacheWrapper* GetPipelineCacheWrapper(format::HandleId id) const { return GetWrapper<PipelineCacheWrapper>(id, pipelineCache_map_); }
    const PipelineLayoutWrapper* GetPipelineLayoutWrapper(format::HandleId id) const { return GetWrapper<PipelineLayoutWrapper>(id, pipelineLayout_map_); }
    const PrivateDataSlotWrapper* GetPrivateDataSlotWrapper(format::HandleId id) const { return GetWrapper<PrivateDataSlotWrapper>(id, privateDataSlot_map_); }
    const QueryPoolWrapper* GetQueryPoolWrapper(format::HandleId id) const { return GetWrapper<QueryPoolWrapper>(id, queryPool_map_); }
    const QueueWrapper* GetQueueWrapper(format::HandleId id) const { return GetWrapper<QueueWrapper>(id, queue_map_); }
    const RenderPassWrapper* GetRenderPassWrapper(format::HandleId id) const { return GetWrapper<RenderPassWrapper>(id, renderPass_map_); }
    const SamplerWrapper* GetSamplerWrapper(format::HandleId id) const { return GetWrapper<SamplerWrapper>(id, sampler_map_); }
    const SamplerYcbcrConversionWrapper* GetSamplerYcbcrConversionWrapper(format::HandleId id) const { return GetWrapper<SamplerYcbcrConversionWrapper>(id, samplerYcbcrConversion_map_); }
    const SemaphoreWrapper* GetSemaphoreWrapper(format::HandleId id) const { return GetWrapper<SemaphoreWrapper>(id, semaphore_map_); }
    const ShaderModuleWrapper* GetShaderModuleWrapper(format::HandleId id) const { return GetWrapper<ShaderModuleWrapper>(id, shaderModule_map_); }
    const SurfaceKHRWrapper* GetSurfaceKHRWrapper(format::HandleId id) const { return GetWrapper<SurfaceKHRWrapper>(id, surfaceKHR_map_); }
    const SwapchainKHRWrapper* GetSwapchainKHRWrapper(format::HandleId id) const { return GetWrapper<SwapchainKHRWrapper>(id, swapchainKHR_map_); }
    const ValidationCacheEXTWrapper* GetValidationCacheEXTWrapper(format::HandleId id) const { return GetWrapper<ValidationCacheEXTWrapper>(id, validationCacheEXT_map_); }
    const VideoSessionKHRWrapper* GetVideoSessionKHRWrapper(format::HandleId id) const { return GetWrapper<VideoSessionKHRWrapper>(id, videoSessionKHR_map_); }
    const VideoSessionParametersKHRWrapper* GetVideoSessionParametersKHRWrapper(format::HandleId id) const { return GetWrapper<VideoSessionParametersKHRWrapper>(id, videoSessionParametersKHR_map_); }

    AccelerationStructureKHRWrapper* GetAccelerationStructureKHRWrapper(format::HandleId id) { return GetWrapper<AccelerationStructureKHRWrapper>(id, accelerationStructureKHR_map_); }
    AccelerationStructureNVWrapper* GetAccelerationStructureNVWrapper(format::HandleId id) { return GetWrapper<AccelerationStructureNVWrapper>(id, accelerationStructureNV_map_); }
    BufferWrapper* GetBufferWrapper(format::HandleId id) { return GetWrapper<BufferWrapper>(id, buffer_map_); }
    BufferViewWrapper* GetBufferViewWrapper(format::HandleId id) { return GetWrapper<BufferViewWrapper>(id, bufferView_map_); }
    CommandBufferWrapper* GetCommandBufferWrapper(format::HandleId id) { return GetWrapper<CommandBufferWrapper>(id, commandBuffer_map_); }
    CommandPoolWrapper* GetCommandPoolWrapper(format::HandleId id) { return GetWrapper<CommandPoolWrapper>(id, commandPool_map_); }
    DebugReportCallbackEXTWrapper* GetDebugReportCallbackEXTWrapper(format::HandleId id) { return GetWrapper<DebugReportCallbackEXTWrapper>(id, debugReportCallbackEXT_map_); }
    DebugUtilsMessengerEXTWrapper* GetDebugUtilsMessengerEXTWrapper(format::HandleId id) { return GetWrapper<DebugUtilsMessengerEXTWrapper>(id, debugUtilsMessengerEXT_map_); }
    DeferredOperationKHRWrapper* GetDeferredOperationKHRWrapper(format::HandleId id) { return GetWrapper<DeferredOperationKHRWrapper>(id, deferredOperationKHR_map_); }
    DescriptorPoolWrapper* GetDescriptorPoolWrapper(format::HandleId id) { return GetWrapper<DescriptorPoolWrapper>(id, descriptorPool_map_); }
    DescriptorSetWrapper* GetDescriptorSetWrapper(format::HandleId id) { return GetWrapper<DescriptorSetWrapper>(id, descriptorSet_map_); }
    DescriptorSetLayoutWrapper* GetDescriptorSetLayoutWrapper(format::HandleId id) { return GetWrapper<DescriptorSetLayoutWrapper>(id, descriptorSetLayout_map_); }
    DescriptorUpdateTemplateWrapper* GetDescriptorUpdateTemplateWrapper(format::HandleId id) { return GetWrapper<DescriptorUpdateTemplateWrapper>(id, descriptorUpdateTemplate_map_); }
    DeviceWrapper* GetDeviceWrapper(format::HandleId id) { return GetWrapper<DeviceWrapper>(id, device_map_); }
    DeviceMemoryWrapper* GetDeviceMemoryWrapper(format::HandleId id) { return GetWrapper<DeviceMemoryWrapper>(id, deviceMemory_map_); }
    DisplayKHRWrapper* GetDisplayKHRWrapper(format::HandleId id) { return GetWrapper<DisplayKHRWrapper>(id, displayKHR_map_); }
    DisplayModeKHRWrapper* GetDisplayModeKHRWrapper(format::HandleId id) { return GetWrapper<DisplayModeKHRWrapper>(id, displayModeKHR_map_); }
    EventWrapper* GetEventWrapper(format::HandleId id) { return GetWrapper<EventWrapper>(id, event_map_); }
    FenceWrapper* GetFenceWrapper(format::HandleId id) { return GetWrapper<FenceWrapper>(id, fence_map_); }
    FramebufferWrapper* GetFramebufferWrapper(format::HandleId id) { return GetWrapper<FramebufferWrapper>(id, framebuffer_map_); }
    ImageWrapper* GetImageWrapper(format::HandleId id) { return GetWrapper<ImageWrapper>(id, image_map_); }
    ImageViewWrapper* GetImageViewWrapper(format::HandleId id) { return GetWrapper<ImageViewWrapper>(id, imageView_map_); }
    IndirectCommandsLayoutNVWrapper* GetIndirectCommandsLayoutNVWrapper(format::HandleId id) { return GetWrapper<IndirectCommandsLayoutNVWrapper>(id, indirectCommandsLayoutNV_map_); }
    InstanceWrapper* GetInstanceWrapper(format::HandleId id) { return GetWrapper<InstanceWrapper>(id, instance_map_); }
    MicromapEXTWrapper* GetMicromapEXTWrapper(format::HandleId id) { return GetWrapper<MicromapEXTWrapper>(id, micromapEXT_map_); }
    OpticalFlowSessionNVWrapper* GetOpticalFlowSessionNVWrapper(format::HandleId id) { return GetWrapper<OpticalFlowSessionNVWrapper>(id, opticalFlowSessionNV_map_); }
    PerformanceConfigurationINTELWrapper* GetPerformanceConfigurationINTELWrapper(format::HandleId id) { return GetWrapper<PerformanceConfigurationINTELWrapper>(id, performanceConfigurationINTEL_map_); }
    PhysicalDeviceWrapper* GetPhysicalDeviceWrapper(format::HandleId id) { return GetWrapper<PhysicalDeviceWrapper>(id, physicalDevice_map_); }
    PipelineWrapper* GetPipelineWrapper(format::HandleId id) { return GetWrapper<PipelineWrapper>(id, pipeline_map_); }
    PipelineCacheWrapper* GetPipelineCacheWrapper(format::HandleId id) { return GetWrapper<PipelineCacheWrapper>(id, pipelineCache_map_); }
    PipelineLayoutWrapper* GetPipelineLayoutWrapper(format::HandleId id) { return GetWrapper<PipelineLayoutWrapper>(id, pipelineLayout_map_); }
    PrivateDataSlotWrapper* GetPrivateDataSlotWrapper(format::HandleId id) { return GetWrapper<PrivateDataSlotWrapper>(id, privateDataSlot_map_); }
    QueryPoolWrapper* GetQueryPoolWrapper(format::HandleId id) { return GetWrapper<QueryPoolWrapper>(id, queryPool_map_); }
    QueueWrapper* GetQueueWrapper(format::HandleId id) { return GetWrapper<QueueWrapper>(id, queue_map_); }
    RenderPassWrapper* GetRenderPassWrapper(format::HandleId id) { return GetWrapper<RenderPassWrapper>(id, renderPass_map_); }
    SamplerWrapper* GetSamplerWrapper(format::HandleId id) { return GetWrapper<SamplerWrapper>(id, sampler_map_); }
    SamplerYcbcrConversionWrapper* GetSamplerYcbcrConversionWrapper(format::HandleId id) { return GetWrapper<SamplerYcbcrConversionWrapper>(id, samplerYcbcrConversion_map_); }
    SemaphoreWrapper* GetSemaphoreWrapper(format::HandleId id) { return GetWrapper<SemaphoreWrapper>(id, semaphore_map_); }
    ShaderModuleWrapper* GetShaderModuleWrapper(format::HandleId id) { return GetWrapper<ShaderModuleWrapper>(id, shaderModule_map_); }
    SurfaceKHRWrapper* GetSurfaceKHRWrapper(format::HandleId id) { return GetWrapper<SurfaceKHRWrapper>(id, surfaceKHR_map_); }
    SwapchainKHRWrapper* GetSwapchainKHRWrapper(format::HandleId id) { return GetWrapper<SwapchainKHRWrapper>(id, swapchainKHR_map_); }
    ValidationCacheEXTWrapper* GetValidationCacheEXTWrapper(format::HandleId id) { return GetWrapper<ValidationCacheEXTWrapper>(id, validationCacheEXT_map_); }
    VideoSessionKHRWrapper* GetVideoSessionKHRWrapper(format::HandleId id) { return GetWrapper<VideoSessionKHRWrapper>(id, videoSessionKHR_map_); }
    VideoSessionParametersKHRWrapper* GetVideoSessionParametersKHRWrapper(format::HandleId id) { return GetWrapper<VideoSessionParametersKHRWrapper>(id, videoSessionParametersKHR_map_); }

    void VisitWrappers(std::function<void(AccelerationStructureKHRWrapper*)> visitor) const { for (auto entry : accelerationStructureKHR_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(AccelerationStructureNVWrapper*)> visitor) const { for (auto entry : accelerationStructureNV_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(BufferWrapper*)> visitor) const { for (auto entry : buffer_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(BufferViewWrapper*)> visitor) const { for (auto entry : bufferView_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(CommandBufferWrapper*)> visitor) const { for (auto entry : commandBuffer_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(CommandPoolWrapper*)> visitor) const { for (auto entry : commandPool_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(DebugReportCallbackEXTWrapper*)> visitor) const { for (auto entry : debugReportCallbackEXT_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(DebugUtilsMessengerEXTWrapper*)> visitor) const { for (auto entry : debugUtilsMessengerEXT_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(DeferredOperationKHRWrapper*)> visitor) const { for (auto entry : deferredOperationKHR_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(DescriptorPoolWrapper*)> visitor) const { for (auto entry : descriptorPool_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(DescriptorSetWrapper*)> visitor) const { for (auto entry : descriptorSet_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(DescriptorSetLayoutWrapper*)> visitor) const { for (auto entry : descriptorSetLayout_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(DescriptorUpdateTemplateWrapper*)> visitor) const { for (auto entry : descriptorUpdateTemplate_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(DeviceWrapper*)> visitor) const { for (auto entry : device_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(DeviceMemoryWrapper*)> visitor) const { for (auto entry : deviceMemory_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(DisplayKHRWrapper*)> visitor) const { for (auto entry : displayKHR_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(DisplayModeKHRWrapper*)> visitor) const { for (auto entry : displayModeKHR_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(EventWrapper*)> visitor) const { for (auto entry : event_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(FenceWrapper*)> visitor) const { for (auto entry : fence_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(FramebufferWrapper*)> visitor) const { for (auto entry : framebuffer_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ImageWrapper*)> visitor) const { for (auto entry : image_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ImageViewWrapper*)> visitor) const { for (auto entry : imageView_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(IndirectCommandsLayoutNVWrapper*)> visitor) const { for (auto entry : indirectCommandsLayoutNV_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(InstanceWrapper*)> visitor) const { for (auto entry : instance_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(MicromapEXTWrapper*)> visitor) const { for (auto entry : micromapEXT_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(OpticalFlowSessionNVWrapper*)> visitor) const { for (auto entry : opticalFlowSessionNV_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(PerformanceConfigurationINTELWrapper*)> visitor) const { for (auto entry : performanceConfigurationINTEL_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(PhysicalDeviceWrapper*)> visitor) const { for (auto entry : physicalDevice_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(PipelineWrapper*)> visitor) const { for (auto entry : pipeline_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(PipelineCacheWrapper*)> visitor) const { for (auto entry : pipelineCache_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(PipelineLayoutWrapper*)> visitor) const { for (auto entry : pipelineLayout_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(PrivateDataSlotWrapper*)> visitor) const { for (auto entry : privateDataSlot_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(QueryPoolWrapper*)> visitor) const { for (auto entry : queryPool_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(QueueWrapper*)> visitor) const { for (auto entry : queue_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(RenderPassWrapper*)> visitor) const { for (auto entry : renderPass_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(SamplerWrapper*)> visitor) const { for (auto entry : sampler_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(SamplerYcbcrConversionWrapper*)> visitor) const { for (auto entry : samplerYcbcrConversion_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(SemaphoreWrapper*)> visitor) const { for (auto entry : semaphore_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ShaderModuleWrapper*)> visitor) const { for (auto entry : shaderModule_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(SurfaceKHRWrapper*)> visitor) const { for (auto entry : surfaceKHR_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(SwapchainKHRWrapper*)> visitor) const { for (auto entry : swapchainKHR_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ValidationCacheEXTWrapper*)> visitor) const { for (auto entry : validationCacheEXT_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(VideoSessionKHRWrapper*)> visitor) const { for (auto entry : videoSessionKHR_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(VideoSessionParametersKHRWrapper*)> visitor) const { for (auto entry : videoSessionParametersKHR_map_) { visitor(entry.second); } }

  private:
    std::map<format::HandleId, AccelerationStructureKHRWrapper*> accelerationStructureKHR_map_;
    std::map<format::HandleId, AccelerationStructureNVWrapper*> accelerationStructureNV_map_;
    std::map<format::HandleId, BufferWrapper*> buffer_map_;
    std::map<format::HandleId, BufferViewWrapper*> bufferView_map_;
    std::map<format::HandleId, CommandBufferWrapper*> commandBuffer_map_;
    std::map<format::HandleId, CommandPoolWrapper*> commandPool_map_;
    std::map<format::HandleId, DebugReportCallbackEXTWrapper*> debugReportCallbackEXT_map_;
    std::map<format::HandleId, DebugUtilsMessengerEXTWrapper*> debugUtilsMessengerEXT_map_;
    std::map<format::HandleId, DeferredOperationKHRWrapper*> deferredOperationKHR_map_;
    std::map<format::HandleId, DescriptorPoolWrapper*> descriptorPool_map_;
    std::map<format::HandleId, DescriptorSetWrapper*> descriptorSet_map_;
    std::map<format::HandleId, DescriptorSetLayoutWrapper*> descriptorSetLayout_map_;
    std::map<format::HandleId, DescriptorUpdateTemplateWrapper*> descriptorUpdateTemplate_map_;
    std::map<format::HandleId, DeviceWrapper*> device_map_;
    std::map<format::HandleId, DeviceMemoryWrapper*> deviceMemory_map_;
    std::map<format::HandleId, DisplayKHRWrapper*> displayKHR_map_;
    std::map<format::HandleId, DisplayModeKHRWrapper*> displayModeKHR_map_;
    std::map<format::HandleId, EventWrapper*> event_map_;
    std::map<format::HandleId, FenceWrapper*> fence_map_;
    std::map<format::HandleId, FramebufferWrapper*> framebuffer_map_;
    std::map<format::HandleId, ImageWrapper*> image_map_;
    std::map<format::HandleId, ImageViewWrapper*> imageView_map_;
    std::map<format::HandleId, IndirectCommandsLayoutNVWrapper*> indirectCommandsLayoutNV_map_;
    std::map<format::HandleId, InstanceWrapper*> instance_map_;
    std::map<format::HandleId, MicromapEXTWrapper*> micromapEXT_map_;
    std::map<format::HandleId, OpticalFlowSessionNVWrapper*> opticalFlowSessionNV_map_;
    std::map<format::HandleId, PerformanceConfigurationINTELWrapper*> performanceConfigurationINTEL_map_;
    std::map<format::HandleId, PhysicalDeviceWrapper*> physicalDevice_map_;
    std::map<format::HandleId, PipelineWrapper*> pipeline_map_;
    std::map<format::HandleId, PipelineCacheWrapper*> pipelineCache_map_;
    std::map<format::HandleId, PipelineLayoutWrapper*> pipelineLayout_map_;
    std::map<format::HandleId, PrivateDataSlotWrapper*> privateDataSlot_map_;
    std::map<format::HandleId, QueryPoolWrapper*> queryPool_map_;
    std::map<format::HandleId, QueueWrapper*> queue_map_;
    std::map<format::HandleId, RenderPassWrapper*> renderPass_map_;
    std::map<format::HandleId, SamplerWrapper*> sampler_map_;
    std::map<format::HandleId, SamplerYcbcrConversionWrapper*> samplerYcbcrConversion_map_;
    std::map<format::HandleId, SemaphoreWrapper*> semaphore_map_;
    std::map<format::HandleId, ShaderModuleWrapper*> shaderModule_map_;
    std::map<format::HandleId, SurfaceKHRWrapper*> surfaceKHR_map_;
    std::map<format::HandleId, SwapchainKHRWrapper*> swapchainKHR_map_;
    std::map<format::HandleId, ValidationCacheEXTWrapper*> validationCacheEXT_map_;
    std::map<format::HandleId, VideoSessionKHRWrapper*> videoSessionKHR_map_;
    std::map<format::HandleId, VideoSessionParametersKHRWrapper*> videoSessionParametersKHR_map_;
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
