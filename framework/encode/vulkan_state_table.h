/*
** Copyright (c) 2019 LunarG, Inc.
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

#ifndef GFXRECON_ENCODE_VULKAN_STATE_TABLE_H
#define GFXRECON_ENCODE_VULKAN_STATE_TABLE_H

#include "encode/vulkan_handle_wrappers.h"
#include "format/format.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"

#include <cassert>
#include <functional>
#include <map>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

class VulkanStateTable
{
  public:
    VulkanStateTable() {}

    ~VulkanStateTable() {}

    // clang-format off
    bool InsertWrapper(format::HandleId id, InstanceWrapper* wrapper)                      { return InsertEntry(id, wrapper, instance_map_); }
    bool InsertWrapper(format::HandleId id, PhysicalDeviceWrapper* wrapper)                { return InsertEntry(id, wrapper, physical_device_map_); }
    bool InsertWrapper(format::HandleId id, DeviceWrapper* wrapper)                        { return InsertEntry(id, wrapper, device_map_); }
    bool InsertWrapper(format::HandleId id, QueueWrapper* wrapper)                         { return InsertEntry(id, wrapper, queue_map_); }
    bool InsertWrapper(format::HandleId id, SemaphoreWrapper* wrapper)                     { return InsertEntry(id, wrapper, semaphore_map_); }
    bool InsertWrapper(format::HandleId id, CommandBufferWrapper* wrapper)                 { return InsertEntry(id, wrapper, command_buffer_map_); }
    bool InsertWrapper(format::HandleId id, FenceWrapper* wrapper)                         { return InsertEntry(id, wrapper, fence_map_); }
    bool InsertWrapper(format::HandleId id, DeviceMemoryWrapper* wrapper)                  { return InsertEntry(id, wrapper, device_memory_map_); }
    bool InsertWrapper(format::HandleId id, BufferWrapper* wrapper)                        { return InsertEntry(id, wrapper, buffer_map_); }
    bool InsertWrapper(format::HandleId id, ImageWrapper* wrapper)                         { return InsertEntry(id, wrapper, image_map_); }
    bool InsertWrapper(format::HandleId id, EventWrapper* wrapper)                         { return InsertEntry(id, wrapper, event_map_); }
    bool InsertWrapper(format::HandleId id, QueryPoolWrapper* wrapper)                     { return InsertEntry(id, wrapper, query_pool_map_); }
    bool InsertWrapper(format::HandleId id, BufferViewWrapper* wrapper)                    { return InsertEntry(id, wrapper, buffer_view_map_); }
    bool InsertWrapper(format::HandleId id, ImageViewWrapper* wrapper)                     { return InsertEntry(id, wrapper, image_view_map_); }
    bool InsertWrapper(format::HandleId id, ShaderModuleWrapper* wrapper)                  { return InsertEntry(id, wrapper, shader_module_map_); }
    bool InsertWrapper(format::HandleId id, PipelineCacheWrapper* wrapper)                 { return InsertEntry(id, wrapper, pipeline_cache_map_); }
    bool InsertWrapper(format::HandleId id, PipelineLayoutWrapper* wrapper)                { return InsertEntry(id, wrapper, pipeline_layout_map_); }
    bool InsertWrapper(format::HandleId id, RenderPassWrapper* wrapper)                    { return InsertEntry(id, wrapper, render_pass_map_); }
    bool InsertWrapper(format::HandleId id, PipelineWrapper* wrapper)                      { return InsertEntry(id, wrapper, pipeline_map_); }
    bool InsertWrapper(format::HandleId id, DescriptorSetLayoutWrapper* wrapper)           { return InsertEntry(id, wrapper, descriptor_set_layout_map_); }
    bool InsertWrapper(format::HandleId id, SamplerWrapper* wrapper)                       { return InsertEntry(id, wrapper, sampler_map_); }
    bool InsertWrapper(format::HandleId id, DescriptorPoolWrapper* wrapper)                { return InsertEntry(id, wrapper, descriptor_pool_map_); }
    bool InsertWrapper(format::HandleId id, DescriptorSetWrapper* wrapper)                 { return InsertEntry(id, wrapper, descriptor_set_map_); }
    bool InsertWrapper(format::HandleId id, FramebufferWrapper* wrapper)                   { return InsertEntry(id, wrapper, framebuffer_map_); }
    bool InsertWrapper(format::HandleId id, CommandPoolWrapper* wrapper)                   { return InsertEntry(id, wrapper, command_pool_map_); }
    bool InsertWrapper(format::HandleId id, SamplerYcbcrConversionWrapper* wrapper)        { return InsertEntry(id, wrapper, sampler_ycbcr_conversion_map_); }
    bool InsertWrapper(format::HandleId id, DescriptorUpdateTemplateWrapper* wrapper)      { return InsertEntry(id, wrapper, descriptor_update_template_map_); }
    bool InsertWrapper(format::HandleId id, SurfaceKHRWrapper* wrapper)                    { return InsertEntry(id, wrapper, surface_khr_map_); }
    bool InsertWrapper(format::HandleId id, SwapchainKHRWrapper* wrapper)                  { return InsertEntry(id, wrapper, swapchain_khr_map_); }
    bool InsertWrapper(format::HandleId id, DisplayKHRWrapper* wrapper)                    { return InsertEntry(id, wrapper, display_khr_map_); }
    bool InsertWrapper(format::HandleId id, DisplayModeKHRWrapper* wrapper)                { return InsertEntry(id, wrapper, display_mode_khr_map_); }
    bool InsertWrapper(format::HandleId id, DebugReportCallbackEXTWrapper* wrapper)        { return InsertEntry(id, wrapper, debug_report_callback_ext_map_); }
    bool InsertWrapper(format::HandleId id, IndirectCommandsLayoutNVWrapper* wrapper)      { return InsertEntry(id, wrapper, indirect_commands_layout_nv_map_); }
    bool InsertWrapper(format::HandleId id, DebugUtilsMessengerEXTWrapper* wrapper)        { return InsertEntry(id, wrapper, debug_utils_messenger_ext_map_); }
    bool InsertWrapper(format::HandleId id, ValidationCacheEXTWrapper* wrapper)            { return InsertEntry(id, wrapper, validation_cache_ext_map_); }
    bool InsertWrapper(format::HandleId id, AccelerationStructureKHRWrapper* wrapper)      { return InsertEntry(id, wrapper, acceleration_structure_khr_map_); }
    bool InsertWrapper(format::HandleId id, AccelerationStructureNVWrapper* wrapper)       { return InsertEntry(id, wrapper, acceleration_structure_nv_map_); }
    bool InsertWrapper(format::HandleId id, PerformanceConfigurationINTELWrapper* wrapper) { return InsertEntry(id, wrapper, performance_configuration_intel_map_); }
    bool InsertWrapper(format::HandleId id, DeferredOperationKHRWrapper* wrapper)          { return InsertEntry(id, wrapper, deferred_operation_khr_map_); }
    bool InsertWrapper(format::HandleId id, PrivateDataSlotEXTWrapper* wrapper)            { return InsertEntry(id, wrapper, private_data_slot_ext_map_); }

    bool RemoveWrapper(const InstanceWrapper* wrapper)                      { return RemoveEntry(wrapper, instance_map_); }
    bool RemoveWrapper(const PhysicalDeviceWrapper* wrapper)                { return RemoveEntry(wrapper, physical_device_map_); }
    bool RemoveWrapper(const DeviceWrapper* wrapper)                        { return RemoveEntry(wrapper, device_map_); }
    bool RemoveWrapper(const QueueWrapper* wrapper)                         { return RemoveEntry(wrapper, queue_map_); }
    bool RemoveWrapper(const SemaphoreWrapper* wrapper)                     { return RemoveEntry(wrapper, semaphore_map_); }
    bool RemoveWrapper(const CommandBufferWrapper* wrapper)                 { return RemoveEntry(wrapper, command_buffer_map_); }
    bool RemoveWrapper(const FenceWrapper* wrapper)                         { return RemoveEntry(wrapper, fence_map_); }
    bool RemoveWrapper(const DeviceMemoryWrapper* wrapper)                  { return RemoveEntry(wrapper, device_memory_map_); }
    bool RemoveWrapper(const BufferWrapper* wrapper)                        { return RemoveEntry(wrapper, buffer_map_); }
    bool RemoveWrapper(const ImageWrapper* wrapper)                         { return RemoveEntry(wrapper, image_map_); }
    bool RemoveWrapper(const EventWrapper* wrapper)                         { return RemoveEntry(wrapper, event_map_); }
    bool RemoveWrapper(const QueryPoolWrapper* wrapper)                     { return RemoveEntry(wrapper, query_pool_map_); }
    bool RemoveWrapper(const BufferViewWrapper* wrapper)                    { return RemoveEntry(wrapper, buffer_view_map_); }
    bool RemoveWrapper(const ImageViewWrapper* wrapper)                     { return RemoveEntry(wrapper, image_view_map_); }
    bool RemoveWrapper(const ShaderModuleWrapper* wrapper)                  { return RemoveEntry(wrapper, shader_module_map_); }
    bool RemoveWrapper(const PipelineCacheWrapper* wrapper)                 { return RemoveEntry(wrapper, pipeline_cache_map_); }
    bool RemoveWrapper(const PipelineLayoutWrapper* wrapper)                { return RemoveEntry(wrapper, pipeline_layout_map_); }
    bool RemoveWrapper(const RenderPassWrapper* wrapper)                    { return RemoveEntry(wrapper, render_pass_map_); }
    bool RemoveWrapper(const PipelineWrapper* wrapper)                      { return RemoveEntry(wrapper, pipeline_map_); }
    bool RemoveWrapper(const DescriptorSetLayoutWrapper* wrapper)           { return RemoveEntry(wrapper, descriptor_set_layout_map_); }
    bool RemoveWrapper(const SamplerWrapper* wrapper)                       { return RemoveEntry(wrapper, sampler_map_); }
    bool RemoveWrapper(const DescriptorPoolWrapper* wrapper)                { return RemoveEntry(wrapper, descriptor_pool_map_); }
    bool RemoveWrapper(const DescriptorSetWrapper* wrapper)                 { return RemoveEntry(wrapper, descriptor_set_map_); }
    bool RemoveWrapper(const FramebufferWrapper* wrapper)                   { return RemoveEntry(wrapper, framebuffer_map_); }
    bool RemoveWrapper(const CommandPoolWrapper* wrapper)                   { return RemoveEntry(wrapper, command_pool_map_); }
    bool RemoveWrapper(const SamplerYcbcrConversionWrapper* wrapper)        { return RemoveEntry(wrapper, sampler_ycbcr_conversion_map_); }
    bool RemoveWrapper(const DescriptorUpdateTemplateWrapper* wrapper)      { return RemoveEntry(wrapper, descriptor_update_template_map_); }
    bool RemoveWrapper(const SurfaceKHRWrapper* wrapper)                    { return RemoveEntry(wrapper, surface_khr_map_); }
    bool RemoveWrapper(const SwapchainKHRWrapper* wrapper)                  { return RemoveEntry(wrapper, swapchain_khr_map_); }
    bool RemoveWrapper(const DisplayKHRWrapper* wrapper)                    { return RemoveEntry(wrapper, display_khr_map_); }
    bool RemoveWrapper(const DisplayModeKHRWrapper* wrapper)                { return RemoveEntry(wrapper, display_mode_khr_map_); }
    bool RemoveWrapper(const DebugReportCallbackEXTWrapper* wrapper)        { return RemoveEntry(wrapper, debug_report_callback_ext_map_); }
    bool RemoveWrapper(const IndirectCommandsLayoutNVWrapper* wrapper)      { return RemoveEntry(wrapper, indirect_commands_layout_nv_map_); }
    bool RemoveWrapper(const DebugUtilsMessengerEXTWrapper* wrapper)        { return RemoveEntry(wrapper, debug_utils_messenger_ext_map_); }
    bool RemoveWrapper(const ValidationCacheEXTWrapper* wrapper)            { return RemoveEntry(wrapper, validation_cache_ext_map_); }
    bool RemoveWrapper(const AccelerationStructureKHRWrapper* wrapper)      { return RemoveEntry(wrapper, acceleration_structure_khr_map_); }
    bool RemoveWrapper(const AccelerationStructureNVWrapper* wrapper)       { return RemoveEntry(wrapper, acceleration_structure_nv_map_); }
    bool RemoveWrapper(const PerformanceConfigurationINTELWrapper* wrapper) { return RemoveEntry(wrapper, performance_configuration_intel_map_); }
    bool RemoveWrapper(const DeferredOperationKHRWrapper* wrapper)          { return RemoveEntry(wrapper, deferred_operation_khr_map_); }
    bool RemoveWrapper(const PrivateDataSlotEXTWrapper* wrapper)            { return RemoveEntry(wrapper, private_data_slot_ext_map_); }

    void VisitWrappers(std::function<void(const InstanceWrapper*)> visitor) const                      { for (auto entry : instance_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const PhysicalDeviceWrapper*)> visitor) const                { for (auto entry : physical_device_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const DeviceWrapper*)> visitor) const                        { for (auto entry : device_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const QueueWrapper*)> visitor) const                         { for (auto entry : queue_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const SemaphoreWrapper*)> visitor) const                     { for (auto entry : semaphore_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const CommandBufferWrapper*)> visitor) const                 { for (auto entry : command_buffer_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const FenceWrapper*)> visitor) const                         { for (auto entry : fence_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const DeviceMemoryWrapper*)> visitor) const                  { for (auto entry : device_memory_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const BufferWrapper*)> visitor) const                        { for (auto entry : buffer_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const ImageWrapper*)> visitor) const                         { for (auto entry : image_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const EventWrapper*)> visitor) const                         { for (auto entry : event_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const QueryPoolWrapper*)> visitor) const                     { for (auto entry : query_pool_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const BufferViewWrapper*)> visitor) const                    { for (auto entry : buffer_view_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const ImageViewWrapper*)> visitor) const                     { for (auto entry : image_view_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const ShaderModuleWrapper*)> visitor) const                  { for (auto entry : shader_module_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const PipelineCacheWrapper*)> visitor) const                 { for (auto entry : pipeline_cache_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const PipelineLayoutWrapper*)> visitor) const                { for (auto entry : pipeline_layout_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const RenderPassWrapper*)> visitor) const                    { for (auto entry : render_pass_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const PipelineWrapper*)> visitor) const                      { for (auto entry : pipeline_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const DescriptorSetLayoutWrapper*)> visitor) const           { for (auto entry : descriptor_set_layout_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const SamplerWrapper*)> visitor) const                       { for (auto entry : sampler_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const DescriptorPoolWrapper*)> visitor) const                { for (auto entry : descriptor_pool_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const DescriptorSetWrapper*)> visitor) const                 { for (auto entry : descriptor_set_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const FramebufferWrapper*)> visitor) const                   { for (auto entry : framebuffer_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const CommandPoolWrapper*)> visitor) const                   { for (auto entry : command_pool_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const SamplerYcbcrConversionWrapper*)> visitor) const        { for (auto entry : sampler_ycbcr_conversion_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const DescriptorUpdateTemplateWrapper*)> visitor) const      { for (auto entry : descriptor_update_template_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const SurfaceKHRWrapper*)> visitor) const                    { for (auto entry : surface_khr_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const SwapchainKHRWrapper*)> visitor) const                  { for (auto entry : swapchain_khr_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const DisplayKHRWrapper*)> visitor) const                    { for (auto entry : display_khr_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const DisplayModeKHRWrapper*)> visitor) const                { for (auto entry : display_mode_khr_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const DebugReportCallbackEXTWrapper*)> visitor) const        { for (auto entry : debug_report_callback_ext_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const IndirectCommandsLayoutNVWrapper*)> visitor) const      { for (auto entry : indirect_commands_layout_nv_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const DebugUtilsMessengerEXTWrapper*)> visitor) const        { for (auto entry : debug_utils_messenger_ext_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const ValidationCacheEXTWrapper*)> visitor) const            { for (auto entry : validation_cache_ext_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const AccelerationStructureKHRWrapper*)> visitor) const      { for (auto entry : acceleration_structure_khr_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const AccelerationStructureNVWrapper*)> visitor) const       { for (auto entry : acceleration_structure_nv_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const PerformanceConfigurationINTELWrapper*)> visitor) const { for (auto entry : performance_configuration_intel_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const DeferredOperationKHRWrapper*)> visitor) const          { for (auto entry : deferred_operation_khr_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const PrivateDataSlotEXTWrapper*)> visitor) const            { for (auto entry : private_data_slot_ext_map_) { visitor(entry.second); } }
    // clang-format on

    //
    // Helper functions for state initialization.
    //

    // clang-format off
    PhysicalDeviceWrapper*       GetPhysicalDeviceWrapper(format::HandleId id)       { return GetWrapper<PhysicalDeviceWrapper>(id, physical_device_map_); }
    const PhysicalDeviceWrapper* GetPhysicalDeviceWrapper(format::HandleId id) const { return GetWrapper<PhysicalDeviceWrapper>(id, physical_device_map_); }

    DeviceWrapper*       GetDeviceWrapper(format::HandleId id)       { return GetWrapper<DeviceWrapper>(id, device_map_); }
    const DeviceWrapper* GetDeviceWrapper(format::HandleId id) const { return GetWrapper<DeviceWrapper>(id, device_map_); }

    DeviceMemoryWrapper*       GetDeviceMemoryWrapper(format::HandleId id)       { return GetWrapper<DeviceMemoryWrapper>(id, device_memory_map_); }
    const DeviceMemoryWrapper* GetDeviceMemoryWrapper(format::HandleId id) const { return GetWrapper<DeviceMemoryWrapper>(id, device_memory_map_); }

    BufferWrapper*       GetBufferWrapper(format::HandleId id)       { return GetWrapper<BufferWrapper>(id, buffer_map_); }
    const BufferWrapper* GetBufferWrapper(format::HandleId id) const { return GetWrapper<BufferWrapper>(id, buffer_map_); }

    BufferViewWrapper*       GetBufferViewWrapper(format::HandleId id)       { return GetWrapper<BufferViewWrapper>(id, buffer_view_map_); }
    const BufferViewWrapper* GetBufferViewWrapper(format::HandleId id) const { return GetWrapper<BufferViewWrapper>(id, buffer_view_map_); }

    ImageWrapper*       GetImageWrapper(format::HandleId id)       { return GetWrapper<ImageWrapper>(id, image_map_); }
    const ImageWrapper* GetImageWrapper(format::HandleId id) const { return GetWrapper<ImageWrapper>(id, image_map_); }

    ImageViewWrapper*       GetImageViewWrapper(format::HandleId id)       { return GetWrapper<ImageViewWrapper>(id, image_view_map_); }
    const ImageViewWrapper* GetImageViewWrapper(format::HandleId id) const { return GetWrapper<ImageViewWrapper>(id, image_view_map_); }

    SamplerWrapper*       GetSamplerWrapper(format::HandleId id)       { return GetWrapper<SamplerWrapper>(id, sampler_map_); }
    const SamplerWrapper* GetSamplerWrapper(format::HandleId id) const { return GetWrapper<SamplerWrapper>(id, sampler_map_); }

    FramebufferWrapper*       GetFramebufferWrapper(format::HandleId id)       { return GetWrapper<FramebufferWrapper>(id, framebuffer_map_); }
    const FramebufferWrapper* GetFramebufferWrapper(format::HandleId id) const { return GetWrapper<FramebufferWrapper>(id, framebuffer_map_); }

    CommandPoolWrapper*       GetCommandPoolWrapper(format::HandleId id)       { return GetWrapper<CommandPoolWrapper>(id, command_pool_map_);}
    const CommandPoolWrapper* GetCommandPoolWrapper(format::HandleId id) const { return GetWrapper<CommandPoolWrapper>(id, command_pool_map_);}

    CommandBufferWrapper*       GetCommandBufferWrapper(format::HandleId id)       { return GetWrapper<CommandBufferWrapper>(id, command_buffer_map_);}
    const CommandBufferWrapper* GetCommandBufferWrapper(format::HandleId id) const { return GetWrapper<CommandBufferWrapper>(id, command_buffer_map_);}

    DescriptorPoolWrapper*       GetDescriptorPoolWrapper(format::HandleId id)       { return GetWrapper<DescriptorPoolWrapper>(id, descriptor_pool_map_); }
    const DescriptorPoolWrapper* GetDescriptorPoolWrapper(format::HandleId id) const { return GetWrapper<DescriptorPoolWrapper>(id, descriptor_pool_map_); }

    DescriptorSetWrapper*       GetDescriptorSetWrapper(format::HandleId id)       { return GetWrapper<DescriptorSetWrapper>(id, descriptor_set_map_); }
    const DescriptorSetWrapper* GetDescriptorSetWrapper(format::HandleId id) const { return GetWrapper<DescriptorSetWrapper>(id, descriptor_set_map_); }

    DescriptorSetLayoutWrapper*       GetDescriptorSetLayoutWrapper(format::HandleId id)       { return GetWrapper<DescriptorSetLayoutWrapper>(id, descriptor_set_layout_map_); }
    const DescriptorSetLayoutWrapper* GetDescriptorSetLayoutWrapper(format::HandleId id) const { return GetWrapper<DescriptorSetLayoutWrapper>(id, descriptor_set_layout_map_); }

    QueryPoolWrapper*       GetQueryPoolWrapper(format::HandleId id)       { return GetWrapper<QueryPoolWrapper>(id, query_pool_map_); }
    const QueryPoolWrapper* GetQueryPoolWrapper(format::HandleId id) const { return GetWrapper<QueryPoolWrapper>(id, query_pool_map_); }

    PipelineWrapper*       GetPipelineWrapper(format::HandleId id)       { return GetWrapper<PipelineWrapper>(id, pipeline_map_); }
    const PipelineWrapper* GetPipelineWrapper(format::HandleId id) const { return GetWrapper<PipelineWrapper>(id, pipeline_map_); }

    PipelineLayoutWrapper*       GetPipelineLayoutWrapper(format::HandleId id)       { return GetWrapper<PipelineLayoutWrapper>(id, pipeline_layout_map_); }
    const PipelineLayoutWrapper* GetPipelineLayoutWrapper(format::HandleId id) const { return GetWrapper<PipelineLayoutWrapper>(id, pipeline_layout_map_); }

    RenderPassWrapper*       GetRenderPassWrapper(format::HandleId id)       { return GetWrapper<RenderPassWrapper>(id, render_pass_map_); }
    const RenderPassWrapper* GetRenderPassWrapper(format::HandleId id) const { return GetWrapper<RenderPassWrapper>(id, render_pass_map_); }

    ShaderModuleWrapper*       GetShaderModuleWrapper(format::HandleId id)       { return GetWrapper<ShaderModuleWrapper>(id, shader_module_map_); }
    const ShaderModuleWrapper* GetShaderModuleWrapper(format::HandleId id) const { return GetWrapper<ShaderModuleWrapper>(id, shader_module_map_); }

    EventWrapper*       GetEventWrapper(format::HandleId id)       { return GetWrapper<EventWrapper>(id, event_map_); }
    const EventWrapper* GetEventWrapper(format::HandleId id) const { return GetWrapper<EventWrapper>(id, event_map_); }

    FenceWrapper*       GetFenceWrapper(format::HandleId id)       { return GetWrapper<FenceWrapper>(id, fence_map_); }
    const FenceWrapper* GetFenceWrapper(format::HandleId id) const { return GetWrapper<FenceWrapper>(id, fence_map_); }

    SemaphoreWrapper*       GetSemaphoreWrapper(format::HandleId id)       { return GetWrapper<SemaphoreWrapper>(id, semaphore_map_); }
    const SemaphoreWrapper* GetSemaphoreWrapper(format::HandleId id) const { return GetWrapper<SemaphoreWrapper>(id, semaphore_map_); }

    SurfaceKHRWrapper*       GetSurfaceKHRWrapper(format::HandleId id)       { return GetWrapper<SurfaceKHRWrapper>(id, surface_khr_map_); }
    const SurfaceKHRWrapper* GetSurfaceKHRWrapper(format::HandleId id) const { return GetWrapper<SurfaceKHRWrapper>(id, surface_khr_map_); }

    SwapchainKHRWrapper*       GetSwapchainKHRWrapper(format::HandleId id)       { return GetWrapper<SwapchainKHRWrapper>(id, swapchain_khr_map_); }
    const SwapchainKHRWrapper* GetSwapchainKHRWrapper(format::HandleId id) const { return GetWrapper<SwapchainKHRWrapper>(id, swapchain_khr_map_); }

    AccelerationStructureKHRWrapper*       GetAccelerationStructureKHRWrapper(format::HandleId id)       { return GetWrapper<AccelerationStructureKHRWrapper>(id, acceleration_structure_khr_map_); }
    const AccelerationStructureKHRWrapper* GetAccelerationStructureKHRWrapper(format::HandleId id) const { return GetWrapper<AccelerationStructureKHRWrapper>(id, acceleration_structure_khr_map_); }

    AccelerationStructureNVWrapper*       GetAccelerationStructureNVWrapper(format::HandleId id)       { return GetWrapper<AccelerationStructureNVWrapper>(id, acceleration_structure_nv_map_); }
    const AccelerationStructureNVWrapper* GetAccelerationStructureNVWrapper(format::HandleId id) const { return GetWrapper<AccelerationStructureNVWrapper>(id, acceleration_structure_nv_map_); }

    IndirectCommandsLayoutNVWrapper*       GetIndirectCommandsLayoutNVWrapper(format::HandleId id)       { return GetWrapper<IndirectCommandsLayoutNVWrapper>(id, indirect_commands_layout_nv_map_); }
    const IndirectCommandsLayoutNVWrapper* GetIndirectCommandsLayoutNVWrapper(format::HandleId id) const { return GetWrapper<IndirectCommandsLayoutNVWrapper>(id, indirect_commands_layout_nv_map_); }

    DeferredOperationKHRWrapper*       GetDeferredOperationKHRWrapper(format::HandleId id)       { return GetWrapper<DeferredOperationKHRWrapper>(id, deferred_operation_khr_map_); }
    const DeferredOperationKHRWrapper* GetDeferredOperationKHRWrapper(format::HandleId id) const { return GetWrapper<DeferredOperationKHRWrapper>(id, deferred_operation_khr_map_); }
    // clang-format off

  private:
    template <typename T>
    bool InsertEntry(format::HandleId id, T* wrapper, std::map<format::HandleId, T*>& map)
    {
        const auto& inserted = map.insert(std::make_pair(id, wrapper));
        return inserted.second;
    }

    template <typename Wrapper>
    bool RemoveEntry(const Wrapper* wrapper, std::map<format::HandleId, Wrapper*>& map)
    {
        assert(wrapper != nullptr);
        return (map.erase(wrapper->handle_id) != 0);
    }

    template <typename T>
    T* GetWrapper(format::HandleId id, std::map<format::HandleId, T*>& map)
    {
        auto entry = map.find(id);
        return (entry != map.end()) ? entry->second : nullptr;
    }

    template <typename T>
    const T* GetWrapper(format::HandleId id, const std::map<format::HandleId, T*>& map) const
    {
        auto entry = map.find(id);
        return (entry != map.end()) ? entry->second : nullptr;
    }

  private:
    std::map<format::HandleId, InstanceWrapper*>                      instance_map_;
    std::map<format::HandleId, PhysicalDeviceWrapper*>                physical_device_map_;
    std::map<format::HandleId, DeviceWrapper*>                        device_map_;
    std::map<format::HandleId, QueueWrapper*>                         queue_map_;
    std::map<format::HandleId, SemaphoreWrapper*>                     semaphore_map_;
    std::map<format::HandleId, CommandBufferWrapper*>                 command_buffer_map_;
    std::map<format::HandleId, FenceWrapper*>                         fence_map_;
    std::map<format::HandleId, DeviceMemoryWrapper*>                  device_memory_map_;
    std::map<format::HandleId, BufferWrapper*>                        buffer_map_;
    std::map<format::HandleId, ImageWrapper*>                         image_map_;
    std::map<format::HandleId, EventWrapper*>                         event_map_;
    std::map<format::HandleId, QueryPoolWrapper*>                     query_pool_map_;
    std::map<format::HandleId, BufferViewWrapper*>                    buffer_view_map_;
    std::map<format::HandleId, ImageViewWrapper*>                     image_view_map_;
    std::map<format::HandleId, ShaderModuleWrapper*>                  shader_module_map_;
    std::map<format::HandleId, PipelineCacheWrapper*>                 pipeline_cache_map_;
    std::map<format::HandleId, PipelineLayoutWrapper*>                pipeline_layout_map_;
    std::map<format::HandleId, RenderPassWrapper*>                    render_pass_map_;
    std::map<format::HandleId, PipelineWrapper*>                      pipeline_map_;
    std::map<format::HandleId, DescriptorSetLayoutWrapper*>           descriptor_set_layout_map_;
    std::map<format::HandleId, SamplerWrapper*>                       sampler_map_;
    std::map<format::HandleId, DescriptorPoolWrapper*>                descriptor_pool_map_;
    std::map<format::HandleId, DescriptorSetWrapper*>                 descriptor_set_map_;
    std::map<format::HandleId, FramebufferWrapper*>                   framebuffer_map_;
    std::map<format::HandleId, CommandPoolWrapper*>                   command_pool_map_;
    std::map<format::HandleId, SamplerYcbcrConversionWrapper*>        sampler_ycbcr_conversion_map_;
    std::map<format::HandleId, DescriptorUpdateTemplateWrapper*>      descriptor_update_template_map_;
    std::map<format::HandleId, SurfaceKHRWrapper*>                    surface_khr_map_;
    std::map<format::HandleId, SwapchainKHRWrapper*>                  swapchain_khr_map_;
    std::map<format::HandleId, DisplayKHRWrapper*>                    display_khr_map_;
    std::map<format::HandleId, DisplayModeKHRWrapper*>                display_mode_khr_map_;
    std::map<format::HandleId, DebugReportCallbackEXTWrapper*>        debug_report_callback_ext_map_;
    std::map<format::HandleId, IndirectCommandsLayoutNVWrapper*>      indirect_commands_layout_nv_map_;
    std::map<format::HandleId, DebugUtilsMessengerEXTWrapper*>        debug_utils_messenger_ext_map_;
    std::map<format::HandleId, ValidationCacheEXTWrapper*>            validation_cache_ext_map_;
    std::map<format::HandleId, AccelerationStructureKHRWrapper*>      acceleration_structure_khr_map_;
    std::map<format::HandleId, AccelerationStructureNVWrapper*>       acceleration_structure_nv_map_;
    std::map<format::HandleId, PerformanceConfigurationINTELWrapper*> performance_configuration_intel_map_;
    std::map<format::HandleId, DeferredOperationKHRWrapper*>          deferred_operation_khr_map_;
    std::map<format::HandleId, PrivateDataSlotEXTWrapper*>            private_data_slot_ext_map_;
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_VULKAN_STATE_TABLE_H
