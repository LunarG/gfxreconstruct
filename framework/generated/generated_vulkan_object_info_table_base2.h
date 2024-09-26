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

    void AddAccelerationStructureKHRInfo(AccelerationStructureKHRInfo&& info) { AddObjectInfo(std::move(info), &accelerationStructureKHR_map_); }
    void AddAccelerationStructureNVInfo(AccelerationStructureNVInfo&& info) { AddObjectInfo(std::move(info), &accelerationStructureNV_map_); }
    void AddBufferInfo(BufferInfo&& info) { AddObjectInfo(std::move(info), &buffer_map_); }
    void AddBufferViewInfo(BufferViewInfo&& info) { AddObjectInfo(std::move(info), &bufferView_map_); }
    void AddCommandBufferInfo(CommandBufferInfo&& info) { AddObjectInfo(std::move(info), &commandBuffer_map_); }
    void AddCommandPoolInfo(CommandPoolInfo&& info) { AddObjectInfo(std::move(info), &commandPool_map_); }
    void AddDebugReportCallbackEXTInfo(DebugReportCallbackEXTInfo&& info) { AddObjectInfo(std::move(info), &debugReportCallbackEXT_map_); }
    void AddDebugUtilsMessengerEXTInfo(DebugUtilsMessengerEXTInfo&& info) { AddObjectInfo(std::move(info), &debugUtilsMessengerEXT_map_); }
    void AddDeferredOperationKHRInfo(DeferredOperationKHRInfo&& info) { AddObjectInfo(std::move(info), &deferredOperationKHR_map_); }
    void AddDescriptorPoolInfo(DescriptorPoolInfo&& info) { AddObjectInfo(std::move(info), &descriptorPool_map_); }
    void AddDescriptorSetInfo(DescriptorSetInfo&& info) { AddObjectInfo(std::move(info), &descriptorSet_map_); }
    void AddDescriptorSetLayoutInfo(DescriptorSetLayoutInfo&& info) { AddObjectInfo(std::move(info), &descriptorSetLayout_map_); }
    void AddDescriptorUpdateTemplateInfo(DescriptorUpdateTemplateInfo&& info) { AddObjectInfo(std::move(info), &descriptorUpdateTemplate_map_); }
    void AddDeviceInfo(DeviceInfo&& info) { AddObjectInfo(std::move(info), &device_map_); }
    void AddDeviceMemoryInfo(DeviceMemoryInfo&& info) { AddObjectInfo(std::move(info), &deviceMemory_map_); }
    void AddDisplayKHRInfo(DisplayKHRInfo&& info) { AddObjectInfo(std::move(info), &displayKHR_map_); }
    void AddDisplayModeKHRInfo(DisplayModeKHRInfo&& info) { AddObjectInfo(std::move(info), &displayModeKHR_map_); }
    void AddEventInfo(EventInfo&& info) { AddObjectInfo(std::move(info), &event_map_); }
    void AddFenceInfo(FenceInfo&& info) { AddObjectInfo(std::move(info), &fence_map_); }
    void AddFramebufferInfo(FramebufferInfo&& info) { AddObjectInfo(std::move(info), &framebuffer_map_); }
    void AddImageInfo(ImageInfo&& info) { AddObjectInfo(std::move(info), &image_map_); }
    void AddImageViewInfo(ImageViewInfo&& info) { AddObjectInfo(std::move(info), &imageView_map_); }
    void AddIndirectCommandsLayoutNVInfo(IndirectCommandsLayoutNVInfo&& info) { AddObjectInfo(std::move(info), &indirectCommandsLayoutNV_map_); }
    void AddInstanceInfo(InstanceInfo&& info) { AddObjectInfo(std::move(info), &instance_map_); }
    void AddMicromapEXTInfo(MicromapEXTInfo&& info) { AddObjectInfo(std::move(info), &micromapEXT_map_); }
    void AddOpticalFlowSessionNVInfo(OpticalFlowSessionNVInfo&& info) { AddObjectInfo(std::move(info), &opticalFlowSessionNV_map_); }
    void AddPerformanceConfigurationINTELInfo(PerformanceConfigurationINTELInfo&& info) { AddObjectInfo(std::move(info), &performanceConfigurationINTEL_map_); }
    void AddPhysicalDeviceInfo(PhysicalDeviceInfo&& info) { AddObjectInfo(std::move(info), &physicalDevice_map_); }
    void AddPipelineInfo(PipelineInfo&& info) { AddObjectInfo(std::move(info), &pipeline_map_); }
    void AddPipelineBinaryKHRInfo(PipelineBinaryKHRInfo&& info) { AddObjectInfo(std::move(info), &pipelineBinaryKHR_map_); }
    void AddPipelineCacheInfo(PipelineCacheInfo&& info) { AddObjectInfo(std::move(info), &pipelineCache_map_); }
    void AddPipelineLayoutInfo(PipelineLayoutInfo&& info) { AddObjectInfo(std::move(info), &pipelineLayout_map_); }
    void AddPrivateDataSlotInfo(PrivateDataSlotInfo&& info) { AddObjectInfo(std::move(info), &privateDataSlot_map_); }
    void AddQueryPoolInfo(QueryPoolInfo&& info) { AddObjectInfo(std::move(info), &queryPool_map_); }
    void AddQueueInfo(QueueInfo&& info) { AddObjectInfo(std::move(info), &queue_map_); }
    void AddRenderPassInfo(RenderPassInfo&& info) { AddObjectInfo(std::move(info), &renderPass_map_); }
    void AddSamplerInfo(SamplerInfo&& info) { AddObjectInfo(std::move(info), &sampler_map_); }
    void AddSamplerYcbcrConversionInfo(SamplerYcbcrConversionInfo&& info) { AddObjectInfo(std::move(info), &samplerYcbcrConversion_map_); }
    void AddSemaphoreInfo(SemaphoreInfo&& info) { AddObjectInfo(std::move(info), &semaphore_map_); }
    void AddShaderEXTInfo(ShaderEXTInfo&& info) { AddObjectInfo(std::move(info), &shaderEXT_map_); }
    void AddShaderModuleInfo(ShaderModuleInfo&& info) { AddObjectInfo(std::move(info), &shaderModule_map_); }
    void AddSurfaceKHRInfo(SurfaceKHRInfo&& info) { AddObjectInfo(std::move(info), &surfaceKHR_map_); }
    void AddSwapchainKHRInfo(SwapchainKHRInfo&& info) { AddObjectInfo(std::move(info), &swapchainKHR_map_); }
    void AddValidationCacheEXTInfo(ValidationCacheEXTInfo&& info) { AddObjectInfo(std::move(info), &validationCacheEXT_map_); }
    void AddVideoSessionKHRInfo(VideoSessionKHRInfo&& info) { AddObjectInfo(std::move(info), &videoSessionKHR_map_); }
    void AddVideoSessionParametersKHRInfo(VideoSessionParametersKHRInfo&& info) { AddObjectInfo(std::move(info), &videoSessionParametersKHR_map_); }

    void RemoveAccelerationStructureKHRInfo(format::HandleId id) { accelerationStructureKHR_map_.erase(id); }
    void RemoveAccelerationStructureNVInfo(format::HandleId id) { accelerationStructureNV_map_.erase(id); }
    void RemoveBufferInfo(format::HandleId id) { buffer_map_.erase(id); }
    void RemoveBufferViewInfo(format::HandleId id) { bufferView_map_.erase(id); }
    void RemoveCommandBufferInfo(format::HandleId id) { commandBuffer_map_.erase(id); }
    void RemoveCommandPoolInfo(format::HandleId id) { commandPool_map_.erase(id); }
    void RemoveDebugReportCallbackEXTInfo(format::HandleId id) { debugReportCallbackEXT_map_.erase(id); }
    void RemoveDebugUtilsMessengerEXTInfo(format::HandleId id) { debugUtilsMessengerEXT_map_.erase(id); }
    void RemoveDeferredOperationKHRInfo(format::HandleId id) { deferredOperationKHR_map_.erase(id); }
    void RemoveDescriptorPoolInfo(format::HandleId id) { descriptorPool_map_.erase(id); }
    void RemoveDescriptorSetInfo(format::HandleId id) { descriptorSet_map_.erase(id); }
    void RemoveDescriptorSetLayoutInfo(format::HandleId id) { descriptorSetLayout_map_.erase(id); }
    void RemoveDescriptorUpdateTemplateInfo(format::HandleId id) { descriptorUpdateTemplate_map_.erase(id); }
    void RemoveDeviceInfo(format::HandleId id) { device_map_.erase(id); }
    void RemoveDeviceMemoryInfo(format::HandleId id) { deviceMemory_map_.erase(id); }
    void RemoveDisplayKHRInfo(format::HandleId id) { displayKHR_map_.erase(id); }
    void RemoveDisplayModeKHRInfo(format::HandleId id) { displayModeKHR_map_.erase(id); }
    void RemoveEventInfo(format::HandleId id) { event_map_.erase(id); }
    void RemoveFenceInfo(format::HandleId id) { fence_map_.erase(id); }
    void RemoveFramebufferInfo(format::HandleId id) { framebuffer_map_.erase(id); }
    void RemoveImageInfo(format::HandleId id) { image_map_.erase(id); }
    void RemoveImageViewInfo(format::HandleId id) { imageView_map_.erase(id); }
    void RemoveIndirectCommandsLayoutNVInfo(format::HandleId id) { indirectCommandsLayoutNV_map_.erase(id); }
    void RemoveInstanceInfo(format::HandleId id) { instance_map_.erase(id); }
    void RemoveMicromapEXTInfo(format::HandleId id) { micromapEXT_map_.erase(id); }
    void RemoveOpticalFlowSessionNVInfo(format::HandleId id) { opticalFlowSessionNV_map_.erase(id); }
    void RemovePerformanceConfigurationINTELInfo(format::HandleId id) { performanceConfigurationINTEL_map_.erase(id); }
    void RemovePhysicalDeviceInfo(format::HandleId id) { physicalDevice_map_.erase(id); }
    void RemovePipelineInfo(format::HandleId id) { pipeline_map_.erase(id); }
    void RemovePipelineBinaryKHRInfo(format::HandleId id) { pipelineBinaryKHR_map_.erase(id); }
    void RemovePipelineCacheInfo(format::HandleId id) { pipelineCache_map_.erase(id); }
    void RemovePipelineLayoutInfo(format::HandleId id) { pipelineLayout_map_.erase(id); }
    void RemovePrivateDataSlotInfo(format::HandleId id) { privateDataSlot_map_.erase(id); }
    void RemoveQueryPoolInfo(format::HandleId id) { queryPool_map_.erase(id); }
    void RemoveQueueInfo(format::HandleId id) { queue_map_.erase(id); }
    void RemoveRenderPassInfo(format::HandleId id) { renderPass_map_.erase(id); }
    void RemoveSamplerInfo(format::HandleId id) { sampler_map_.erase(id); }
    void RemoveSamplerYcbcrConversionInfo(format::HandleId id) { samplerYcbcrConversion_map_.erase(id); }
    void RemoveSemaphoreInfo(format::HandleId id) { semaphore_map_.erase(id); }
    void RemoveShaderEXTInfo(format::HandleId id) { shaderEXT_map_.erase(id); }
    void RemoveShaderModuleInfo(format::HandleId id) { shaderModule_map_.erase(id); }
    void RemoveSurfaceKHRInfo(format::HandleId id) { surfaceKHR_map_.erase(id); }
    void RemoveSwapchainKHRInfo(format::HandleId id) { swapchainKHR_map_.erase(id); }
    void RemoveValidationCacheEXTInfo(format::HandleId id) { validationCacheEXT_map_.erase(id); }
    void RemoveVideoSessionKHRInfo(format::HandleId id) { videoSessionKHR_map_.erase(id); }
    void RemoveVideoSessionParametersKHRInfo(format::HandleId id) { videoSessionParametersKHR_map_.erase(id); }

    const AccelerationStructureKHRInfo* GetAccelerationStructureKHRInfo(format::HandleId id) const { return GetObjectInfo<AccelerationStructureKHRInfo>(id, &accelerationStructureKHR_map_); }
    const AccelerationStructureNVInfo* GetAccelerationStructureNVInfo(format::HandleId id) const { return GetObjectInfo<AccelerationStructureNVInfo>(id, &accelerationStructureNV_map_); }
    const BufferInfo* GetBufferInfo(format::HandleId id) const { return GetObjectInfo<BufferInfo>(id, &buffer_map_); }
    const BufferViewInfo* GetBufferViewInfo(format::HandleId id) const { return GetObjectInfo<BufferViewInfo>(id, &bufferView_map_); }
    const CommandBufferInfo* GetCommandBufferInfo(format::HandleId id) const { return GetObjectInfo<CommandBufferInfo>(id, &commandBuffer_map_); }
    const CommandPoolInfo* GetCommandPoolInfo(format::HandleId id) const { return GetObjectInfo<CommandPoolInfo>(id, &commandPool_map_); }
    const DebugReportCallbackEXTInfo* GetDebugReportCallbackEXTInfo(format::HandleId id) const { return GetObjectInfo<DebugReportCallbackEXTInfo>(id, &debugReportCallbackEXT_map_); }
    const DebugUtilsMessengerEXTInfo* GetDebugUtilsMessengerEXTInfo(format::HandleId id) const { return GetObjectInfo<DebugUtilsMessengerEXTInfo>(id, &debugUtilsMessengerEXT_map_); }
    const DeferredOperationKHRInfo* GetDeferredOperationKHRInfo(format::HandleId id) const { return GetObjectInfo<DeferredOperationKHRInfo>(id, &deferredOperationKHR_map_); }
    const DescriptorPoolInfo* GetDescriptorPoolInfo(format::HandleId id) const { return GetObjectInfo<DescriptorPoolInfo>(id, &descriptorPool_map_); }
    const DescriptorSetInfo* GetDescriptorSetInfo(format::HandleId id) const { return GetObjectInfo<DescriptorSetInfo>(id, &descriptorSet_map_); }
    const DescriptorSetLayoutInfo* GetDescriptorSetLayoutInfo(format::HandleId id) const { return GetObjectInfo<DescriptorSetLayoutInfo>(id, &descriptorSetLayout_map_); }
    const DescriptorUpdateTemplateInfo* GetDescriptorUpdateTemplateInfo(format::HandleId id) const { return GetObjectInfo<DescriptorUpdateTemplateInfo>(id, &descriptorUpdateTemplate_map_); }
    const DeviceInfo* GetDeviceInfo(format::HandleId id) const { return GetObjectInfo<DeviceInfo>(id, &device_map_); }
    const DeviceMemoryInfo* GetDeviceMemoryInfo(format::HandleId id) const { return GetObjectInfo<DeviceMemoryInfo>(id, &deviceMemory_map_); }
    const DisplayKHRInfo* GetDisplayKHRInfo(format::HandleId id) const { return GetObjectInfo<DisplayKHRInfo>(id, &displayKHR_map_); }
    const DisplayModeKHRInfo* GetDisplayModeKHRInfo(format::HandleId id) const { return GetObjectInfo<DisplayModeKHRInfo>(id, &displayModeKHR_map_); }
    const EventInfo* GetEventInfo(format::HandleId id) const { return GetObjectInfo<EventInfo>(id, &event_map_); }
    const FenceInfo* GetFenceInfo(format::HandleId id) const { return GetObjectInfo<FenceInfo>(id, &fence_map_); }
    const FramebufferInfo* GetFramebufferInfo(format::HandleId id) const { return GetObjectInfo<FramebufferInfo>(id, &framebuffer_map_); }
    const ImageInfo* GetImageInfo(format::HandleId id) const { return GetObjectInfo<ImageInfo>(id, &image_map_); }
    const ImageViewInfo* GetImageViewInfo(format::HandleId id) const { return GetObjectInfo<ImageViewInfo>(id, &imageView_map_); }
    const IndirectCommandsLayoutNVInfo* GetIndirectCommandsLayoutNVInfo(format::HandleId id) const { return GetObjectInfo<IndirectCommandsLayoutNVInfo>(id, &indirectCommandsLayoutNV_map_); }
    const InstanceInfo* GetInstanceInfo(format::HandleId id) const { return GetObjectInfo<InstanceInfo>(id, &instance_map_); }
    const MicromapEXTInfo* GetMicromapEXTInfo(format::HandleId id) const { return GetObjectInfo<MicromapEXTInfo>(id, &micromapEXT_map_); }
    const OpticalFlowSessionNVInfo* GetOpticalFlowSessionNVInfo(format::HandleId id) const { return GetObjectInfo<OpticalFlowSessionNVInfo>(id, &opticalFlowSessionNV_map_); }
    const PerformanceConfigurationINTELInfo* GetPerformanceConfigurationINTELInfo(format::HandleId id) const { return GetObjectInfo<PerformanceConfigurationINTELInfo>(id, &performanceConfigurationINTEL_map_); }
    const PhysicalDeviceInfo* GetPhysicalDeviceInfo(format::HandleId id) const { return GetObjectInfo<PhysicalDeviceInfo>(id, &physicalDevice_map_); }
    const PipelineInfo* GetPipelineInfo(format::HandleId id) const { return GetObjectInfo<PipelineInfo>(id, &pipeline_map_); }
    const PipelineBinaryKHRInfo* GetPipelineBinaryKHRInfo(format::HandleId id) const { return GetObjectInfo<PipelineBinaryKHRInfo>(id, &pipelineBinaryKHR_map_); }
    const PipelineCacheInfo* GetPipelineCacheInfo(format::HandleId id) const { return GetObjectInfo<PipelineCacheInfo>(id, &pipelineCache_map_); }
    const PipelineLayoutInfo* GetPipelineLayoutInfo(format::HandleId id) const { return GetObjectInfo<PipelineLayoutInfo>(id, &pipelineLayout_map_); }
    const PrivateDataSlotInfo* GetPrivateDataSlotInfo(format::HandleId id) const { return GetObjectInfo<PrivateDataSlotInfo>(id, &privateDataSlot_map_); }
    const QueryPoolInfo* GetQueryPoolInfo(format::HandleId id) const { return GetObjectInfo<QueryPoolInfo>(id, &queryPool_map_); }
    const QueueInfo* GetQueueInfo(format::HandleId id) const { return GetObjectInfo<QueueInfo>(id, &queue_map_); }
    const RenderPassInfo* GetRenderPassInfo(format::HandleId id) const { return GetObjectInfo<RenderPassInfo>(id, &renderPass_map_); }
    const SamplerInfo* GetSamplerInfo(format::HandleId id) const { return GetObjectInfo<SamplerInfo>(id, &sampler_map_); }
    const SamplerYcbcrConversionInfo* GetSamplerYcbcrConversionInfo(format::HandleId id) const { return GetObjectInfo<SamplerYcbcrConversionInfo>(id, &samplerYcbcrConversion_map_); }
    const SemaphoreInfo* GetSemaphoreInfo(format::HandleId id) const { return GetObjectInfo<SemaphoreInfo>(id, &semaphore_map_); }
    const ShaderEXTInfo* GetShaderEXTInfo(format::HandleId id) const { return GetObjectInfo<ShaderEXTInfo>(id, &shaderEXT_map_); }
    const ShaderModuleInfo* GetShaderModuleInfo(format::HandleId id) const { return GetObjectInfo<ShaderModuleInfo>(id, &shaderModule_map_); }
    const SurfaceKHRInfo* GetSurfaceKHRInfo(format::HandleId id) const { return GetObjectInfo<SurfaceKHRInfo>(id, &surfaceKHR_map_); }
    const SwapchainKHRInfo* GetSwapchainKHRInfo(format::HandleId id) const { return GetObjectInfo<SwapchainKHRInfo>(id, &swapchainKHR_map_); }
    const ValidationCacheEXTInfo* GetValidationCacheEXTInfo(format::HandleId id) const { return GetObjectInfo<ValidationCacheEXTInfo>(id, &validationCacheEXT_map_); }
    const VideoSessionKHRInfo* GetVideoSessionKHRInfo(format::HandleId id) const { return GetObjectInfo<VideoSessionKHRInfo>(id, &videoSessionKHR_map_); }
    const VideoSessionParametersKHRInfo* GetVideoSessionParametersKHRInfo(format::HandleId id) const { return GetObjectInfo<VideoSessionParametersKHRInfo>(id, &videoSessionParametersKHR_map_); }

    AccelerationStructureKHRInfo* GetAccelerationStructureKHRInfo(format::HandleId id) { return GetObjectInfo<AccelerationStructureKHRInfo>(id, &accelerationStructureKHR_map_); }
    AccelerationStructureNVInfo* GetAccelerationStructureNVInfo(format::HandleId id) { return GetObjectInfo<AccelerationStructureNVInfo>(id, &accelerationStructureNV_map_); }
    BufferInfo* GetBufferInfo(format::HandleId id) { return GetObjectInfo<BufferInfo>(id, &buffer_map_); }
    BufferViewInfo* GetBufferViewInfo(format::HandleId id) { return GetObjectInfo<BufferViewInfo>(id, &bufferView_map_); }
    CommandBufferInfo* GetCommandBufferInfo(format::HandleId id) { return GetObjectInfo<CommandBufferInfo>(id, &commandBuffer_map_); }
    CommandPoolInfo* GetCommandPoolInfo(format::HandleId id) { return GetObjectInfo<CommandPoolInfo>(id, &commandPool_map_); }
    DebugReportCallbackEXTInfo* GetDebugReportCallbackEXTInfo(format::HandleId id) { return GetObjectInfo<DebugReportCallbackEXTInfo>(id, &debugReportCallbackEXT_map_); }
    DebugUtilsMessengerEXTInfo* GetDebugUtilsMessengerEXTInfo(format::HandleId id) { return GetObjectInfo<DebugUtilsMessengerEXTInfo>(id, &debugUtilsMessengerEXT_map_); }
    DeferredOperationKHRInfo* GetDeferredOperationKHRInfo(format::HandleId id) { return GetObjectInfo<DeferredOperationKHRInfo>(id, &deferredOperationKHR_map_); }
    DescriptorPoolInfo* GetDescriptorPoolInfo(format::HandleId id) { return GetObjectInfo<DescriptorPoolInfo>(id, &descriptorPool_map_); }
    DescriptorSetInfo* GetDescriptorSetInfo(format::HandleId id) { return GetObjectInfo<DescriptorSetInfo>(id, &descriptorSet_map_); }
    DescriptorSetLayoutInfo* GetDescriptorSetLayoutInfo(format::HandleId id) { return GetObjectInfo<DescriptorSetLayoutInfo>(id, &descriptorSetLayout_map_); }
    DescriptorUpdateTemplateInfo* GetDescriptorUpdateTemplateInfo(format::HandleId id) { return GetObjectInfo<DescriptorUpdateTemplateInfo>(id, &descriptorUpdateTemplate_map_); }
    DeviceInfo* GetDeviceInfo(format::HandleId id) { return GetObjectInfo<DeviceInfo>(id, &device_map_); }
    DeviceMemoryInfo* GetDeviceMemoryInfo(format::HandleId id) { return GetObjectInfo<DeviceMemoryInfo>(id, &deviceMemory_map_); }
    DisplayKHRInfo* GetDisplayKHRInfo(format::HandleId id) { return GetObjectInfo<DisplayKHRInfo>(id, &displayKHR_map_); }
    DisplayModeKHRInfo* GetDisplayModeKHRInfo(format::HandleId id) { return GetObjectInfo<DisplayModeKHRInfo>(id, &displayModeKHR_map_); }
    EventInfo* GetEventInfo(format::HandleId id) { return GetObjectInfo<EventInfo>(id, &event_map_); }
    FenceInfo* GetFenceInfo(format::HandleId id) { return GetObjectInfo<FenceInfo>(id, &fence_map_); }
    FramebufferInfo* GetFramebufferInfo(format::HandleId id) { return GetObjectInfo<FramebufferInfo>(id, &framebuffer_map_); }
    ImageInfo* GetImageInfo(format::HandleId id) { return GetObjectInfo<ImageInfo>(id, &image_map_); }
    ImageViewInfo* GetImageViewInfo(format::HandleId id) { return GetObjectInfo<ImageViewInfo>(id, &imageView_map_); }
    IndirectCommandsLayoutNVInfo* GetIndirectCommandsLayoutNVInfo(format::HandleId id) { return GetObjectInfo<IndirectCommandsLayoutNVInfo>(id, &indirectCommandsLayoutNV_map_); }
    InstanceInfo* GetInstanceInfo(format::HandleId id) { return GetObjectInfo<InstanceInfo>(id, &instance_map_); }
    MicromapEXTInfo* GetMicromapEXTInfo(format::HandleId id) { return GetObjectInfo<MicromapEXTInfo>(id, &micromapEXT_map_); }
    OpticalFlowSessionNVInfo* GetOpticalFlowSessionNVInfo(format::HandleId id) { return GetObjectInfo<OpticalFlowSessionNVInfo>(id, &opticalFlowSessionNV_map_); }
    PerformanceConfigurationINTELInfo* GetPerformanceConfigurationINTELInfo(format::HandleId id) { return GetObjectInfo<PerformanceConfigurationINTELInfo>(id, &performanceConfigurationINTEL_map_); }
    PhysicalDeviceInfo* GetPhysicalDeviceInfo(format::HandleId id) { return GetObjectInfo<PhysicalDeviceInfo>(id, &physicalDevice_map_); }
    PipelineInfo* GetPipelineInfo(format::HandleId id) { return GetObjectInfo<PipelineInfo>(id, &pipeline_map_); }
    PipelineBinaryKHRInfo* GetPipelineBinaryKHRInfo(format::HandleId id) { return GetObjectInfo<PipelineBinaryKHRInfo>(id, &pipelineBinaryKHR_map_); }
    PipelineCacheInfo* GetPipelineCacheInfo(format::HandleId id) { return GetObjectInfo<PipelineCacheInfo>(id, &pipelineCache_map_); }
    PipelineLayoutInfo* GetPipelineLayoutInfo(format::HandleId id) { return GetObjectInfo<PipelineLayoutInfo>(id, &pipelineLayout_map_); }
    PrivateDataSlotInfo* GetPrivateDataSlotInfo(format::HandleId id) { return GetObjectInfo<PrivateDataSlotInfo>(id, &privateDataSlot_map_); }
    QueryPoolInfo* GetQueryPoolInfo(format::HandleId id) { return GetObjectInfo<QueryPoolInfo>(id, &queryPool_map_); }
    QueueInfo* GetQueueInfo(format::HandleId id) { return GetObjectInfo<QueueInfo>(id, &queue_map_); }
    RenderPassInfo* GetRenderPassInfo(format::HandleId id) { return GetObjectInfo<RenderPassInfo>(id, &renderPass_map_); }
    SamplerInfo* GetSamplerInfo(format::HandleId id) { return GetObjectInfo<SamplerInfo>(id, &sampler_map_); }
    SamplerYcbcrConversionInfo* GetSamplerYcbcrConversionInfo(format::HandleId id) { return GetObjectInfo<SamplerYcbcrConversionInfo>(id, &samplerYcbcrConversion_map_); }
    SemaphoreInfo* GetSemaphoreInfo(format::HandleId id) { return GetObjectInfo<SemaphoreInfo>(id, &semaphore_map_); }
    ShaderEXTInfo* GetShaderEXTInfo(format::HandleId id) { return GetObjectInfo<ShaderEXTInfo>(id, &shaderEXT_map_); }
    ShaderModuleInfo* GetShaderModuleInfo(format::HandleId id) { return GetObjectInfo<ShaderModuleInfo>(id, &shaderModule_map_); }
    SurfaceKHRInfo* GetSurfaceKHRInfo(format::HandleId id) { return GetObjectInfo<SurfaceKHRInfo>(id, &surfaceKHR_map_); }
    SwapchainKHRInfo* GetSwapchainKHRInfo(format::HandleId id) { return GetObjectInfo<SwapchainKHRInfo>(id, &swapchainKHR_map_); }
    ValidationCacheEXTInfo* GetValidationCacheEXTInfo(format::HandleId id) { return GetObjectInfo<ValidationCacheEXTInfo>(id, &validationCacheEXT_map_); }
    VideoSessionKHRInfo* GetVideoSessionKHRInfo(format::HandleId id) { return GetObjectInfo<VideoSessionKHRInfo>(id, &videoSessionKHR_map_); }
    VideoSessionParametersKHRInfo* GetVideoSessionParametersKHRInfo(format::HandleId id) { return GetObjectInfo<VideoSessionParametersKHRInfo>(id, &videoSessionParametersKHR_map_); }

    void VisitAccelerationStructureKHRInfo(std::function<void(const AccelerationStructureKHRInfo*)> visitor) const {  for (const auto& entry : accelerationStructureKHR_map_) { visitor(&entry.second); }  }
    void VisitAccelerationStructureNVInfo(std::function<void(const AccelerationStructureNVInfo*)> visitor) const {  for (const auto& entry : accelerationStructureNV_map_) { visitor(&entry.second); }  }
    void VisitBufferInfo(std::function<void(const BufferInfo*)> visitor) const {  for (const auto& entry : buffer_map_) { visitor(&entry.second); }  }
    void VisitBufferViewInfo(std::function<void(const BufferViewInfo*)> visitor) const {  for (const auto& entry : bufferView_map_) { visitor(&entry.second); }  }
    void VisitCommandBufferInfo(std::function<void(const CommandBufferInfo*)> visitor) const {  for (const auto& entry : commandBuffer_map_) { visitor(&entry.second); }  }
    void VisitCommandPoolInfo(std::function<void(const CommandPoolInfo*)> visitor) const {  for (const auto& entry : commandPool_map_) { visitor(&entry.second); }  }
    void VisitDebugReportCallbackEXTInfo(std::function<void(const DebugReportCallbackEXTInfo*)> visitor) const {  for (const auto& entry : debugReportCallbackEXT_map_) { visitor(&entry.second); }  }
    void VisitDebugUtilsMessengerEXTInfo(std::function<void(const DebugUtilsMessengerEXTInfo*)> visitor) const {  for (const auto& entry : debugUtilsMessengerEXT_map_) { visitor(&entry.second); }  }
    void VisitDeferredOperationKHRInfo(std::function<void(const DeferredOperationKHRInfo*)> visitor) const {  for (const auto& entry : deferredOperationKHR_map_) { visitor(&entry.second); }  }
    void VisitDescriptorPoolInfo(std::function<void(const DescriptorPoolInfo*)> visitor) const {  for (const auto& entry : descriptorPool_map_) { visitor(&entry.second); }  }
    void VisitDescriptorSetInfo(std::function<void(const DescriptorSetInfo*)> visitor) const {  for (const auto& entry : descriptorSet_map_) { visitor(&entry.second); }  }
    void VisitDescriptorSetLayoutInfo(std::function<void(const DescriptorSetLayoutInfo*)> visitor) const {  for (const auto& entry : descriptorSetLayout_map_) { visitor(&entry.second); }  }
    void VisitDescriptorUpdateTemplateInfo(std::function<void(const DescriptorUpdateTemplateInfo*)> visitor) const {  for (const auto& entry : descriptorUpdateTemplate_map_) { visitor(&entry.second); }  }
    void VisitDeviceInfo(std::function<void(const DeviceInfo*)> visitor) const {  for (const auto& entry : device_map_) { visitor(&entry.second); }  }
    void VisitDeviceMemoryInfo(std::function<void(const DeviceMemoryInfo*)> visitor) const {  for (const auto& entry : deviceMemory_map_) { visitor(&entry.second); }  }
    void VisitDisplayKHRInfo(std::function<void(const DisplayKHRInfo*)> visitor) const {  for (const auto& entry : displayKHR_map_) { visitor(&entry.second); }  }
    void VisitDisplayModeKHRInfo(std::function<void(const DisplayModeKHRInfo*)> visitor) const {  for (const auto& entry : displayModeKHR_map_) { visitor(&entry.second); }  }
    void VisitEventInfo(std::function<void(const EventInfo*)> visitor) const {  for (const auto& entry : event_map_) { visitor(&entry.second); }  }
    void VisitFenceInfo(std::function<void(const FenceInfo*)> visitor) const {  for (const auto& entry : fence_map_) { visitor(&entry.second); }  }
    void VisitFramebufferInfo(std::function<void(const FramebufferInfo*)> visitor) const {  for (const auto& entry : framebuffer_map_) { visitor(&entry.second); }  }
    void VisitImageInfo(std::function<void(const ImageInfo*)> visitor) const {  for (const auto& entry : image_map_) { visitor(&entry.second); }  }
    void VisitImageViewInfo(std::function<void(const ImageViewInfo*)> visitor) const {  for (const auto& entry : imageView_map_) { visitor(&entry.second); }  }
    void VisitIndirectCommandsLayoutNVInfo(std::function<void(const IndirectCommandsLayoutNVInfo*)> visitor) const {  for (const auto& entry : indirectCommandsLayoutNV_map_) { visitor(&entry.second); }  }
    void VisitInstanceInfo(std::function<void(const InstanceInfo*)> visitor) const {  for (const auto& entry : instance_map_) { visitor(&entry.second); }  }
    void VisitMicromapEXTInfo(std::function<void(const MicromapEXTInfo*)> visitor) const {  for (const auto& entry : micromapEXT_map_) { visitor(&entry.second); }  }
    void VisitOpticalFlowSessionNVInfo(std::function<void(const OpticalFlowSessionNVInfo*)> visitor) const {  for (const auto& entry : opticalFlowSessionNV_map_) { visitor(&entry.second); }  }
    void VisitPerformanceConfigurationINTELInfo(std::function<void(const PerformanceConfigurationINTELInfo*)> visitor) const {  for (const auto& entry : performanceConfigurationINTEL_map_) { visitor(&entry.second); }  }
    void VisitPhysicalDeviceInfo(std::function<void(const PhysicalDeviceInfo*)> visitor) const {  for (const auto& entry : physicalDevice_map_) { visitor(&entry.second); }  }
    void VisitPipelineInfo(std::function<void(const PipelineInfo*)> visitor) const {  for (const auto& entry : pipeline_map_) { visitor(&entry.second); }  }
    void VisitPipelineBinaryKHRInfo(std::function<void(const PipelineBinaryKHRInfo*)> visitor) const {  for (const auto& entry : pipelineBinaryKHR_map_) { visitor(&entry.second); }  }
    void VisitPipelineCacheInfo(std::function<void(const PipelineCacheInfo*)> visitor) const {  for (const auto& entry : pipelineCache_map_) { visitor(&entry.second); }  }
    void VisitPipelineLayoutInfo(std::function<void(const PipelineLayoutInfo*)> visitor) const {  for (const auto& entry : pipelineLayout_map_) { visitor(&entry.second); }  }
    void VisitPrivateDataSlotInfo(std::function<void(const PrivateDataSlotInfo*)> visitor) const {  for (const auto& entry : privateDataSlot_map_) { visitor(&entry.second); }  }
    void VisitQueryPoolInfo(std::function<void(const QueryPoolInfo*)> visitor) const {  for (const auto& entry : queryPool_map_) { visitor(&entry.second); }  }
    void VisitQueueInfo(std::function<void(const QueueInfo*)> visitor) const {  for (const auto& entry : queue_map_) { visitor(&entry.second); }  }
    void VisitRenderPassInfo(std::function<void(const RenderPassInfo*)> visitor) const {  for (const auto& entry : renderPass_map_) { visitor(&entry.second); }  }
    void VisitSamplerInfo(std::function<void(const SamplerInfo*)> visitor) const {  for (const auto& entry : sampler_map_) { visitor(&entry.second); }  }
    void VisitSamplerYcbcrConversionInfo(std::function<void(const SamplerYcbcrConversionInfo*)> visitor) const {  for (const auto& entry : samplerYcbcrConversion_map_) { visitor(&entry.second); }  }
    void VisitSemaphoreInfo(std::function<void(const SemaphoreInfo*)> visitor) const {  for (const auto& entry : semaphore_map_) { visitor(&entry.second); }  }
    void VisitShaderEXTInfo(std::function<void(const ShaderEXTInfo*)> visitor) const {  for (const auto& entry : shaderEXT_map_) { visitor(&entry.second); }  }
    void VisitShaderModuleInfo(std::function<void(const ShaderModuleInfo*)> visitor) const {  for (const auto& entry : shaderModule_map_) { visitor(&entry.second); }  }
    void VisitSurfaceKHRInfo(std::function<void(const SurfaceKHRInfo*)> visitor) const {  for (const auto& entry : surfaceKHR_map_) { visitor(&entry.second); }  }
    void VisitSwapchainKHRInfo(std::function<void(const SwapchainKHRInfo*)> visitor) const {  for (const auto& entry : swapchainKHR_map_) { visitor(&entry.second); }  }
    void VisitValidationCacheEXTInfo(std::function<void(const ValidationCacheEXTInfo*)> visitor) const {  for (const auto& entry : validationCacheEXT_map_) { visitor(&entry.second); }  }
    void VisitVideoSessionKHRInfo(std::function<void(const VideoSessionKHRInfo*)> visitor) const {  for (const auto& entry : videoSessionKHR_map_) { visitor(&entry.second); }  }
    void VisitVideoSessionParametersKHRInfo(std::function<void(const VideoSessionParametersKHRInfo*)> visitor) const {  for (const auto& entry : videoSessionParametersKHR_map_) { visitor(&entry.second); }  }

  protected:
     std::unordered_map<format::HandleId, AccelerationStructureKHRInfo> accelerationStructureKHR_map_;
     std::unordered_map<format::HandleId, AccelerationStructureNVInfo> accelerationStructureNV_map_;
     std::unordered_map<format::HandleId, BufferInfo> buffer_map_;
     std::unordered_map<format::HandleId, BufferViewInfo> bufferView_map_;
     std::unordered_map<format::HandleId, CommandBufferInfo> commandBuffer_map_;
     std::unordered_map<format::HandleId, CommandPoolInfo> commandPool_map_;
     std::unordered_map<format::HandleId, DebugReportCallbackEXTInfo> debugReportCallbackEXT_map_;
     std::unordered_map<format::HandleId, DebugUtilsMessengerEXTInfo> debugUtilsMessengerEXT_map_;
     std::unordered_map<format::HandleId, DeferredOperationKHRInfo> deferredOperationKHR_map_;
     std::unordered_map<format::HandleId, DescriptorPoolInfo> descriptorPool_map_;
     std::unordered_map<format::HandleId, DescriptorSetInfo> descriptorSet_map_;
     std::unordered_map<format::HandleId, DescriptorSetLayoutInfo> descriptorSetLayout_map_;
     std::unordered_map<format::HandleId, DescriptorUpdateTemplateInfo> descriptorUpdateTemplate_map_;
     std::unordered_map<format::HandleId, DeviceInfo> device_map_;
     std::unordered_map<format::HandleId, DeviceMemoryInfo> deviceMemory_map_;
     std::unordered_map<format::HandleId, DisplayKHRInfo> displayKHR_map_;
     std::unordered_map<format::HandleId, DisplayModeKHRInfo> displayModeKHR_map_;
     std::unordered_map<format::HandleId, EventInfo> event_map_;
     std::unordered_map<format::HandleId, FenceInfo> fence_map_;
     std::unordered_map<format::HandleId, FramebufferInfo> framebuffer_map_;
     std::unordered_map<format::HandleId, ImageInfo> image_map_;
     std::unordered_map<format::HandleId, ImageViewInfo> imageView_map_;
     std::unordered_map<format::HandleId, IndirectCommandsLayoutNVInfo> indirectCommandsLayoutNV_map_;
     std::unordered_map<format::HandleId, InstanceInfo> instance_map_;
     std::unordered_map<format::HandleId, MicromapEXTInfo> micromapEXT_map_;
     std::unordered_map<format::HandleId, OpticalFlowSessionNVInfo> opticalFlowSessionNV_map_;
     std::unordered_map<format::HandleId, PerformanceConfigurationINTELInfo> performanceConfigurationINTEL_map_;
     std::unordered_map<format::HandleId, PhysicalDeviceInfo> physicalDevice_map_;
     std::unordered_map<format::HandleId, PipelineInfo> pipeline_map_;
     std::unordered_map<format::HandleId, PipelineBinaryKHRInfo> pipelineBinaryKHR_map_;
     std::unordered_map<format::HandleId, PipelineCacheInfo> pipelineCache_map_;
     std::unordered_map<format::HandleId, PipelineLayoutInfo> pipelineLayout_map_;
     std::unordered_map<format::HandleId, PrivateDataSlotInfo> privateDataSlot_map_;
     std::unordered_map<format::HandleId, QueryPoolInfo> queryPool_map_;
     std::unordered_map<format::HandleId, QueueInfo> queue_map_;
     std::unordered_map<format::HandleId, RenderPassInfo> renderPass_map_;
     std::unordered_map<format::HandleId, SamplerInfo> sampler_map_;
     std::unordered_map<format::HandleId, SamplerYcbcrConversionInfo> samplerYcbcrConversion_map_;
     std::unordered_map<format::HandleId, SemaphoreInfo> semaphore_map_;
     std::unordered_map<format::HandleId, ShaderEXTInfo> shaderEXT_map_;
     std::unordered_map<format::HandleId, ShaderModuleInfo> shaderModule_map_;
     std::unordered_map<format::HandleId, SurfaceKHRInfo> surfaceKHR_map_;
     std::unordered_map<format::HandleId, SwapchainKHRInfo> swapchainKHR_map_;
     std::unordered_map<format::HandleId, ValidationCacheEXTInfo> validationCacheEXT_map_;
     std::unordered_map<format::HandleId, VideoSessionKHRInfo> videoSessionKHR_map_;
     std::unordered_map<format::HandleId, VideoSessionParametersKHRInfo> videoSessionParametersKHR_map_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
