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

#ifndef  GFXRECON_GENERATED_VULKAN_WRAPPER_HANDLE_LIST_H
#define  GFXRECON_GENERATED_VULKAN_WRAPPER_HANDLE_LIST_H

#include "encode/vulkan_handle_wrappers.h"


GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

class VulkanWrapperHandleList
{
  public:
    static VulkanWrapperHandleList* Get() { return &instance_; }

    void AddWrapperHandle(AccelerationStructureKHRWrapper* wrapper) { AccelerationStructureKHRWrapper_list_.emplace_back(wrapper); }
    void AddWrapperHandle(AccelerationStructureNVWrapper* wrapper) { AccelerationStructureNVWrapper_list_.emplace_back(wrapper); }
    void AddWrapperHandle(BufferWrapper* wrapper) { BufferWrapper_list_.emplace_back(wrapper); }
    void AddWrapperHandle(BufferViewWrapper* wrapper) { BufferViewWrapper_list_.emplace_back(wrapper); }
    void AddWrapperHandle(CommandBufferWrapper* wrapper) { CommandBufferWrapper_list_.emplace_back(wrapper); }
    void AddWrapperHandle(CommandPoolWrapper* wrapper) { CommandPoolWrapper_list_.emplace_back(wrapper); }
    void AddWrapperHandle(DebugReportCallbackEXTWrapper* wrapper) { DebugReportCallbackEXTWrapper_list_.emplace_back(wrapper); }
    void AddWrapperHandle(DebugUtilsMessengerEXTWrapper* wrapper) { DebugUtilsMessengerEXTWrapper_list_.emplace_back(wrapper); }
    void AddWrapperHandle(DeferredOperationKHRWrapper* wrapper) { DeferredOperationKHRWrapper_list_.emplace_back(wrapper); }
    void AddWrapperHandle(DescriptorPoolWrapper* wrapper) { DescriptorPoolWrapper_list_.emplace_back(wrapper); }
    void AddWrapperHandle(DescriptorSetWrapper* wrapper) { DescriptorSetWrapper_list_.emplace_back(wrapper); }
    void AddWrapperHandle(DescriptorSetLayoutWrapper* wrapper) { DescriptorSetLayoutWrapper_list_.emplace_back(wrapper); }
    void AddWrapperHandle(DescriptorUpdateTemplateWrapper* wrapper) { DescriptorUpdateTemplateWrapper_list_.emplace_back(wrapper); }
    void AddWrapperHandle(DeviceWrapper* wrapper) { DeviceWrapper_list_.emplace_back(wrapper); }
    void AddWrapperHandle(DeviceMemoryWrapper* wrapper) { DeviceMemoryWrapper_list_.emplace_back(wrapper); }
    void AddWrapperHandle(DisplayKHRWrapper* wrapper) { DisplayKHRWrapper_list_.emplace_back(wrapper); }
    void AddWrapperHandle(DisplayModeKHRWrapper* wrapper) { DisplayModeKHRWrapper_list_.emplace_back(wrapper); }
    void AddWrapperHandle(EventWrapper* wrapper) { EventWrapper_list_.emplace_back(wrapper); }
    void AddWrapperHandle(FenceWrapper* wrapper) { FenceWrapper_list_.emplace_back(wrapper); }
    void AddWrapperHandle(FramebufferWrapper* wrapper) { FramebufferWrapper_list_.emplace_back(wrapper); }
    void AddWrapperHandle(ImageWrapper* wrapper) { ImageWrapper_list_.emplace_back(wrapper); }
    void AddWrapperHandle(ImageViewWrapper* wrapper) { ImageViewWrapper_list_.emplace_back(wrapper); }
    void AddWrapperHandle(IndirectCommandsLayoutNVWrapper* wrapper) { IndirectCommandsLayoutNVWrapper_list_.emplace_back(wrapper); }
    void AddWrapperHandle(InstanceWrapper* wrapper) { InstanceWrapper_list_.emplace_back(wrapper); }
    void AddWrapperHandle(MicromapEXTWrapper* wrapper) { MicromapEXTWrapper_list_.emplace_back(wrapper); }
    void AddWrapperHandle(OpticalFlowSessionNVWrapper* wrapper) { OpticalFlowSessionNVWrapper_list_.emplace_back(wrapper); }
    void AddWrapperHandle(PerformanceConfigurationINTELWrapper* wrapper) { PerformanceConfigurationINTELWrapper_list_.emplace_back(wrapper); }
    void AddWrapperHandle(PhysicalDeviceWrapper* wrapper) { PhysicalDeviceWrapper_list_.emplace_back(wrapper); }
    void AddWrapperHandle(PipelineWrapper* wrapper) { PipelineWrapper_list_.emplace_back(wrapper); }
    void AddWrapperHandle(PipelineCacheWrapper* wrapper) { PipelineCacheWrapper_list_.emplace_back(wrapper); }
    void AddWrapperHandle(PipelineLayoutWrapper* wrapper) { PipelineLayoutWrapper_list_.emplace_back(wrapper); }
    void AddWrapperHandle(PrivateDataSlotWrapper* wrapper) { PrivateDataSlotWrapper_list_.emplace_back(wrapper); }
    void AddWrapperHandle(QueryPoolWrapper* wrapper) { QueryPoolWrapper_list_.emplace_back(wrapper); }
    void AddWrapperHandle(QueueWrapper* wrapper) { QueueWrapper_list_.emplace_back(wrapper); }
    void AddWrapperHandle(RenderPassWrapper* wrapper) { RenderPassWrapper_list_.emplace_back(wrapper); }
    void AddWrapperHandle(SamplerWrapper* wrapper) { SamplerWrapper_list_.emplace_back(wrapper); }
    void AddWrapperHandle(SamplerYcbcrConversionWrapper* wrapper) { SamplerYcbcrConversionWrapper_list_.emplace_back(wrapper); }
    void AddWrapperHandle(SemaphoreWrapper* wrapper) { SemaphoreWrapper_list_.emplace_back(wrapper); }
    void AddWrapperHandle(ShaderModuleWrapper* wrapper) { ShaderModuleWrapper_list_.emplace_back(wrapper); }
    void AddWrapperHandle(SurfaceKHRWrapper* wrapper) { SurfaceKHRWrapper_list_.emplace_back(wrapper); }
    void AddWrapperHandle(SwapchainKHRWrapper* wrapper) { SwapchainKHRWrapper_list_.emplace_back(wrapper); }
    void AddWrapperHandle(ValidationCacheEXTWrapper* wrapper) { ValidationCacheEXTWrapper_list_.emplace_back(wrapper); }

  private:
    VulkanWrapperHandleList(){}
    static VulkanWrapperHandleList instance_;

    std::vector<std::shared_ptr<AccelerationStructureKHRWrapper>> AccelerationStructureKHRWrapper_list_;
    std::vector<std::shared_ptr<AccelerationStructureNVWrapper>> AccelerationStructureNVWrapper_list_;
    std::vector<std::shared_ptr<BufferWrapper>> BufferWrapper_list_;
    std::vector<std::shared_ptr<BufferViewWrapper>> BufferViewWrapper_list_;
    std::vector<std::shared_ptr<CommandBufferWrapper>> CommandBufferWrapper_list_;
    std::vector<std::shared_ptr<CommandPoolWrapper>> CommandPoolWrapper_list_;
    std::vector<std::shared_ptr<DebugReportCallbackEXTWrapper>> DebugReportCallbackEXTWrapper_list_;
    std::vector<std::shared_ptr<DebugUtilsMessengerEXTWrapper>> DebugUtilsMessengerEXTWrapper_list_;
    std::vector<std::shared_ptr<DeferredOperationKHRWrapper>> DeferredOperationKHRWrapper_list_;
    std::vector<std::shared_ptr<DescriptorPoolWrapper>> DescriptorPoolWrapper_list_;
    std::vector<std::shared_ptr<DescriptorSetWrapper>> DescriptorSetWrapper_list_;
    std::vector<std::shared_ptr<DescriptorSetLayoutWrapper>> DescriptorSetLayoutWrapper_list_;
    std::vector<std::shared_ptr<DescriptorUpdateTemplateWrapper>> DescriptorUpdateTemplateWrapper_list_;
    std::vector<std::shared_ptr<DeviceWrapper>> DeviceWrapper_list_;
    std::vector<std::shared_ptr<DeviceMemoryWrapper>> DeviceMemoryWrapper_list_;
    std::vector<std::shared_ptr<DisplayKHRWrapper>> DisplayKHRWrapper_list_;
    std::vector<std::shared_ptr<DisplayModeKHRWrapper>> DisplayModeKHRWrapper_list_;
    std::vector<std::shared_ptr<EventWrapper>> EventWrapper_list_;
    std::vector<std::shared_ptr<FenceWrapper>> FenceWrapper_list_;
    std::vector<std::shared_ptr<FramebufferWrapper>> FramebufferWrapper_list_;
    std::vector<std::shared_ptr<ImageWrapper>> ImageWrapper_list_;
    std::vector<std::shared_ptr<ImageViewWrapper>> ImageViewWrapper_list_;
    std::vector<std::shared_ptr<IndirectCommandsLayoutNVWrapper>> IndirectCommandsLayoutNVWrapper_list_;
    std::vector<std::shared_ptr<InstanceWrapper>> InstanceWrapper_list_;
    std::vector<std::shared_ptr<MicromapEXTWrapper>> MicromapEXTWrapper_list_;
    std::vector<std::shared_ptr<OpticalFlowSessionNVWrapper>> OpticalFlowSessionNVWrapper_list_;
    std::vector<std::shared_ptr<PerformanceConfigurationINTELWrapper>> PerformanceConfigurationINTELWrapper_list_;
    std::vector<std::shared_ptr<PhysicalDeviceWrapper>> PhysicalDeviceWrapper_list_;
    std::vector<std::shared_ptr<PipelineWrapper>> PipelineWrapper_list_;
    std::vector<std::shared_ptr<PipelineCacheWrapper>> PipelineCacheWrapper_list_;
    std::vector<std::shared_ptr<PipelineLayoutWrapper>> PipelineLayoutWrapper_list_;
    std::vector<std::shared_ptr<PrivateDataSlotWrapper>> PrivateDataSlotWrapper_list_;
    std::vector<std::shared_ptr<QueryPoolWrapper>> QueryPoolWrapper_list_;
    std::vector<std::shared_ptr<QueueWrapper>> QueueWrapper_list_;
    std::vector<std::shared_ptr<RenderPassWrapper>> RenderPassWrapper_list_;
    std::vector<std::shared_ptr<SamplerWrapper>> SamplerWrapper_list_;
    std::vector<std::shared_ptr<SamplerYcbcrConversionWrapper>> SamplerYcbcrConversionWrapper_list_;
    std::vector<std::shared_ptr<SemaphoreWrapper>> SemaphoreWrapper_list_;
    std::vector<std::shared_ptr<ShaderModuleWrapper>> ShaderModuleWrapper_list_;
    std::vector<std::shared_ptr<SurfaceKHRWrapper>> SurfaceKHRWrapper_list_;
    std::vector<std::shared_ptr<SwapchainKHRWrapper>> SwapchainKHRWrapper_list_;
    std::vector<std::shared_ptr<ValidationCacheEXTWrapper>> ValidationCacheEXTWrapper_list_;
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
