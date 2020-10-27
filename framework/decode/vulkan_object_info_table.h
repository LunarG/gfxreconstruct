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

#ifndef GFXRECON_DECODE_VULKAN_OBJECT_MAPPER_H
#define GFXRECON_DECODE_VULKAN_OBJECT_MAPPER_H

#include "decode/vulkan_object_info.h"
#include "format/format.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"

#include <cassert>
#include <functional>
#include <unordered_map>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class VulkanObjectInfoTable
{
  public:
    // clang-format off
    void AddInstanceInfo(InstanceInfo&& info)                                           { AddObjectInfo(std::move(info), &instance_map_); }
    void AddPhysicalDeviceInfo(PhysicalDeviceInfo&& info)                               { AddObjectInfo(std::move(info), &physical_device_map_); }
    void AddDeviceInfo(DeviceInfo&& info)                                               { AddObjectInfo(std::move(info), &device_map_); }
    void AddQueueInfo(QueueInfo&& info)                                                 { AddObjectInfo(std::move(info), &queue_map_); }
    void AddSemaphoreInfo(SemaphoreInfo&& info)                                         { AddObjectInfo(std::move(info), &semaphore_map_); }
    void AddCommandBufferInfo(CommandBufferInfo&& info)                                 { AddObjectInfo(std::move(info), &command_buffer_map_); }
    void AddFenceInfo(FenceInfo&& info)                                                 { AddObjectInfo(std::move(info), &fence_map_); }
    void AddDeviceMemoryInfo(DeviceMemoryInfo&& info)                                   { AddObjectInfo(std::move(info), &device_memory_map_); }
    void AddBufferInfo(BufferInfo&& info)                                               { AddObjectInfo(std::move(info), &buffer_map_); }
    void AddImageInfo(ImageInfo&& info)                                                 { AddObjectInfo(std::move(info), &image_map_); }
    void AddEventInfo(EventInfo&& info)                                                 { AddObjectInfo(std::move(info), &event_map_); }
    void AddQueryPoolInfo(QueryPoolInfo&& info)                                         { AddObjectInfo(std::move(info), &query_pool_map_); }
    void AddBufferViewInfo(BufferViewInfo&& info)                                       { AddObjectInfo(std::move(info), &buffer_view_map_); }
    void AddImageViewInfo(ImageViewInfo&& info)                                         { AddObjectInfo(std::move(info), &image_view_map_); }
    void AddShaderModuleInfo(ShaderModuleInfo&& info)                                   { AddObjectInfo(std::move(info), &shader_module_map_); }
    void AddPipelineCacheInfo(PipelineCacheInfo&& info)                                 { AddObjectInfo(std::move(info), &pipeline_cache_map_); }
    void AddPipelineLayoutInfo(PipelineLayoutInfo&& info)                               { AddObjectInfo(std::move(info), &pipeline_layout_map_); }
    void AddRenderPassInfo(RenderPassInfo&& info)                                       { AddObjectInfo(std::move(info), &render_pass_map_); }
    void AddPipelineInfo(PipelineInfo&& info)                                           { AddObjectInfo(std::move(info), &pipeline_map_); }
    void AddDescriptorSetLayoutInfo(DescriptorSetLayoutInfo&& info)                     { AddObjectInfo(std::move(info), &descriptor_set_layout_map_); }
    void AddSamplerInfo(SamplerInfo&& info)                                             { AddObjectInfo(std::move(info), &sampler_map_); }
    void AddDescriptorPoolInfo(DescriptorPoolInfo&& info)                               { AddObjectInfo(std::move(info), &descriptor_pool_map_); }
    void AddDescriptorSetInfo(DescriptorSetInfo&& info)                                 { AddObjectInfo(std::move(info), &descriptor_set_map_); }
    void AddFramebufferInfo(FramebufferInfo&& info)                                     { AddObjectInfo(std::move(info), &framebuffer_map_); }
    void AddCommandPoolInfo(CommandPoolInfo&& info)                                     { AddObjectInfo(std::move(info), &command_pool_map_); }
    void AddSamplerYcbcrConversionInfo(SamplerYcbcrConversionInfo&& info)               { AddObjectInfo(std::move(info), &sampler_ycbcr_conversion_map_); }
    void AddDescriptorUpdateTemplateInfo(DescriptorUpdateTemplateInfo&& info)           { AddObjectInfo(std::move(info), &descriptor_update_template_map_); }
    void AddSurfaceKHRInfo(SurfaceKHRInfo&& info)                                       { AddObjectInfo(std::move(info), &surface_khr_map_); }
    void AddSwapchainKHRInfo(SwapchainKHRInfo&& info)                                   { AddObjectInfo(std::move(info), &swapchain_khr_map_); }
    void AddDisplayKHRInfo(DisplayKHRInfo&& info)                                       { AddObjectInfo(std::move(info), &display_khr_map_); }
    void AddDisplayModeKHRInfo(DisplayModeKHRInfo&& info)                               { AddObjectInfo(std::move(info), &display_mode_khr_map_); }
    void AddDebugReportCallbackEXTInfo(DebugReportCallbackEXTInfo&& info)               { AddObjectInfo(std::move(info), &debug_report_callback_ext_map_); }
    void AddIndirectCommandsLayoutNVInfo(IndirectCommandsLayoutNVInfo&& info)           { AddObjectInfo(std::move(info), &indirect_commands_layout_nv_map_); }
    void AddDebugUtilsMessengerEXTInfo(DebugUtilsMessengerEXTInfo&& info)               { AddObjectInfo(std::move(info), &debug_utils_messenger_ext_map_); }
    void AddValidationCacheEXTInfo(ValidationCacheEXTInfo&& info)                       { AddObjectInfo(std::move(info), &validation_cache_ext_map_); }
    void AddAccelerationStructureKHRInfo(AccelerationStructureKHRInfo&& info)           { AddObjectInfo(std::move(info), &acceleration_structure_khr_map_); }
    void AddAccelerationStructureNVInfo(AccelerationStructureNVInfo&& info)             { AddObjectInfo(std::move(info), &acceleration_structure_nv_map_); }
    void AddPerformanceConfigurationINTELInfo(PerformanceConfigurationINTELInfo&& info) { AddObjectInfo(std::move(info), &performance_configuration_intel_map_); }
    void AddDeferredOperationKHRInfo(DeferredOperationKHRInfo&& info)                   { AddObjectInfo(std::move(info), &deferred_operation_khr_map_); }
    void AddPrivateDataSlotEXTInfo(PrivateDataSlotEXTInfo&& info)                       { AddObjectInfo(std::move(info), &private_data_slot_ext_map_); }

    void RemoveInstanceInfo(format::HandleId id)                      { instance_map_.erase(id); }
    void RemovePhysicalDeviceInfo(format::HandleId id)                { physical_device_map_.erase(id); }
    void RemoveDeviceInfo(format::HandleId id)                        { device_map_.erase(id); }
    void RemoveQueueInfo(format::HandleId id)                         { queue_map_.erase(id); }
    void RemoveSemaphoreInfo(format::HandleId id)                     { semaphore_map_.erase(id); }
    void RemoveCommandBufferInfo(format::HandleId id)                 { command_buffer_map_.erase(id); }
    void RemoveFenceInfo(format::HandleId id)                         { fence_map_.erase(id); }
    void RemoveDeviceMemoryInfo(format::HandleId id)                  { device_memory_map_.erase(id); }
    void RemoveBufferInfo(format::HandleId id)                        { buffer_map_.erase(id); }
    void RemoveImageInfo(format::HandleId id)                         { image_map_.erase(id); }
    void RemoveEventInfo(format::HandleId id)                         { event_map_.erase(id); }
    void RemoveQueryPoolInfo(format::HandleId id)                     { query_pool_map_.erase(id); }
    void RemoveBufferViewInfo(format::HandleId id)                    { buffer_view_map_.erase(id); }
    void RemoveImageViewInfo(format::HandleId id)                     { image_view_map_.erase(id); }
    void RemoveShaderModuleInfo(format::HandleId id)                  { shader_module_map_.erase(id); }
    void RemovePipelineCacheInfo(format::HandleId id)                 { pipeline_cache_map_.erase(id); }
    void RemovePipelineLayoutInfo(format::HandleId id)                { pipeline_layout_map_.erase(id); }
    void RemoveRenderPassInfo(format::HandleId id)                    { render_pass_map_.erase(id); }
    void RemovePipelineInfo(format::HandleId id)                      { pipeline_map_.erase(id); }
    void RemoveDescriptorSetLayoutInfo(format::HandleId id)           { descriptor_set_layout_map_.erase(id); }
    void RemoveSamplerInfo(format::HandleId id)                       { sampler_map_.erase(id); }
    void RemoveDescriptorPoolInfo(format::HandleId id)                { descriptor_pool_map_.erase(id); }
    void RemoveDescriptorSetInfo(format::HandleId id)                 { descriptor_set_map_.erase(id); }
    void RemoveFramebufferInfo(format::HandleId id)                   { framebuffer_map_.erase(id); }
    void RemoveCommandPoolInfo(format::HandleId id)                   { command_pool_map_.erase(id); }
    void RemoveSamplerYcbcrConversionInfo(format::HandleId id)        { sampler_ycbcr_conversion_map_.erase(id); }
    void RemoveDescriptorUpdateTemplateInfo(format::HandleId id)      { descriptor_update_template_map_.erase(id); }
    void RemoveSurfaceKHRInfo(format::HandleId id)                    { surface_khr_map_.erase(id); }
    void RemoveSwapchainKHRInfo(format::HandleId id)                  { swapchain_khr_map_.erase(id); }
    void RemoveDisplayKHRInfo(format::HandleId id)                    { display_khr_map_.erase(id); }
    void RemoveDisplayModeKHRInfo(format::HandleId id)                { display_mode_khr_map_.erase(id); }
    void RemoveDebugReportCallbackEXTInfo(format::HandleId id)        { debug_report_callback_ext_map_.erase(id); }
    void RemoveIndirectCommandsLayoutNVInfo(format::HandleId id)      { indirect_commands_layout_nv_map_.erase(id); }
    void RemoveDebugUtilsMessengerEXTInfo(format::HandleId id)        { debug_utils_messenger_ext_map_.erase(id); }
    void RemoveValidationCacheEXTInfo(format::HandleId id)            { validation_cache_ext_map_.erase(id); }
    void RemoveAccelerationStructureKHRInfo(format::HandleId id)      { acceleration_structure_khr_map_.erase(id); }
    void RemoveAccelerationStructureNVInfo(format::HandleId id)       { acceleration_structure_nv_map_.erase(id); }
    void RemovePerformanceConfigurationINTELInfo(format::HandleId id) { performance_configuration_intel_map_.erase(id); }
    void RemoveDeferredOperationKHRInfo(format::HandleId id)          { deferred_operation_khr_map_.erase(id); }
    void RemovePrivateDataSlotEXTInfo(format::HandleId id)            { private_data_slot_ext_map_.erase(id); }

    const InstanceInfo*                      GetInstanceInfo(format::HandleId id) const                       { return GetObjectInfo<InstanceInfo>(id, &instance_map_); }
    const PhysicalDeviceInfo*                GetPhysicalDeviceInfo(format::HandleId id) const                 { return GetObjectInfo<PhysicalDeviceInfo>(id, &physical_device_map_); }
    const DeviceInfo*                        GetDeviceInfo(format::HandleId id) const                         { return GetObjectInfo<DeviceInfo>(id, &device_map_); }
    const QueueInfo*                         GetQueueInfo(format::HandleId id) const                          { return GetObjectInfo<QueueInfo>(id, &queue_map_); }
    const SemaphoreInfo*                     GetSemaphoreInfo(format::HandleId id) const                      { return GetObjectInfo<SemaphoreInfo>(id, &semaphore_map_); }
    const CommandBufferInfo*                 GetCommandBufferInfo(format::HandleId id) const                  { return GetObjectInfo<CommandBufferInfo>(id, &command_buffer_map_); }
    const FenceInfo*                         GetFenceInfo(format::HandleId id) const                          { return GetObjectInfo<FenceInfo>(id, &fence_map_); }
    const DeviceMemoryInfo*                  GetDeviceMemoryInfo(format::HandleId id) const                   { return GetObjectInfo<DeviceMemoryInfo>(id, &device_memory_map_); }
    const BufferInfo*                        GetBufferInfo(format::HandleId id) const                         { return GetObjectInfo<BufferInfo>(id, &buffer_map_); }
    const ImageInfo*                         GetImageInfo(format::HandleId id) const                          { return GetObjectInfo<ImageInfo>(id, &image_map_); }
    const EventInfo*                         GetEventInfo(format::HandleId id) const                          { return GetObjectInfo<EventInfo>(id, &event_map_); }
    const QueryPoolInfo*                     GetQueryPoolInfo(format::HandleId id) const                      { return GetObjectInfo<QueryPoolInfo>(id, &query_pool_map_); }
    const BufferViewInfo*                    GetBufferViewInfo(format::HandleId id) const                     { return GetObjectInfo<BufferViewInfo>(id, &buffer_view_map_); }
    const ImageViewInfo*                     GetImageViewInfo(format::HandleId id) const                      { return GetObjectInfo<ImageViewInfo>(id, &image_view_map_); }
    const ShaderModuleInfo*                  GetShaderModuleInfo(format::HandleId id) const                   { return GetObjectInfo<ShaderModuleInfo>(id, &shader_module_map_); }
    const PipelineCacheInfo*                 GetPipelineCacheInfo(format::HandleId id) const                  { return GetObjectInfo<PipelineCacheInfo>(id, &pipeline_cache_map_); }
    const PipelineLayoutInfo*                GetPipelineLayoutInfo(format::HandleId id) const                 { return GetObjectInfo<PipelineLayoutInfo>(id, &pipeline_layout_map_); }
    const RenderPassInfo*                    GetRenderPassInfo(format::HandleId id) const                     { return GetObjectInfo<RenderPassInfo>(id, &render_pass_map_); }
    const PipelineInfo*                      GetPipelineInfo(format::HandleId id) const                       { return GetObjectInfo<PipelineInfo>(id, &pipeline_map_); }
    const DescriptorSetLayoutInfo*           GetDescriptorSetLayoutInfo(format::HandleId id) const            { return GetObjectInfo<DescriptorSetLayoutInfo>(id, &descriptor_set_layout_map_); }
    const SamplerInfo*                       GetSamplerInfo(format::HandleId id) const                        { return GetObjectInfo<SamplerInfo>(id, &sampler_map_); }
    const DescriptorPoolInfo*                GetDescriptorPoolInfo(format::HandleId id) const                 { return GetObjectInfo<DescriptorPoolInfo>(id, &descriptor_pool_map_); }
    const DescriptorSetInfo*                 GetDescriptorSetInfo(format::HandleId id) const                  { return GetObjectInfo<DescriptorSetInfo>(id, &descriptor_set_map_); }
    const FramebufferInfo*                   GetFramebufferInfo(format::HandleId id) const                    { return GetObjectInfo<FramebufferInfo>(id, &framebuffer_map_); }
    const CommandPoolInfo*                   GetCommandPoolInfo(format::HandleId id) const                    { return GetObjectInfo<CommandPoolInfo>(id, &command_pool_map_); }
    const SamplerYcbcrConversionInfo*        GetSamplerYcbcrConversionInfo(format::HandleId id) const         { return GetObjectInfo<SamplerYcbcrConversionInfo>(id, &sampler_ycbcr_conversion_map_); }
    const DescriptorUpdateTemplateInfo*      GetDescriptorUpdateTemplateInfo(format::HandleId id) const       { return GetObjectInfo<DescriptorUpdateTemplateInfo>(id, &descriptor_update_template_map_); }
    const SurfaceKHRInfo*                    GetSurfaceKHRInfo(format::HandleId id) const                     { return GetObjectInfo<SurfaceKHRInfo>(id, &surface_khr_map_); }
    const SwapchainKHRInfo*                  GetSwapchainKHRInfo(format::HandleId id) const                   { return GetObjectInfo<SwapchainKHRInfo>(id, &swapchain_khr_map_); }
    const DisplayKHRInfo*                    GetDisplayKHRInfo(format::HandleId id) const                     { return GetObjectInfo<DisplayKHRInfo>(id, &display_khr_map_); }
    const DisplayModeKHRInfo*                GetDisplayModeKHRInfo(format::HandleId id) const                 { return GetObjectInfo<DisplayModeKHRInfo>(id, &display_mode_khr_map_); }
    const DebugReportCallbackEXTInfo*        GetDebugReportCallbackEXTInfo(format::HandleId id) const         { return GetObjectInfo<DebugReportCallbackEXTInfo>(id, &debug_report_callback_ext_map_); }
    const IndirectCommandsLayoutNVInfo*      GetIndirectCommandsLayoutNVInfo(format::HandleId id) const       { return GetObjectInfo<IndirectCommandsLayoutNVInfo>(id, &indirect_commands_layout_nv_map_); }
    const DebugUtilsMessengerEXTInfo*        GetDebugUtilsMessengerEXTInfo(format::HandleId id) const         { return GetObjectInfo<DebugUtilsMessengerEXTInfo>(id, &debug_utils_messenger_ext_map_); }
    const ValidationCacheEXTInfo*            GetValidationCacheEXTInfo(format::HandleId id) const             { return GetObjectInfo<ValidationCacheEXTInfo>(id, &validation_cache_ext_map_); }
    const AccelerationStructureKHRInfo*      GetAccelerationStructureKHRInfo(format::HandleId id) const       { return GetObjectInfo<AccelerationStructureKHRInfo>(id, &acceleration_structure_khr_map_); }
    const AccelerationStructureNVInfo*       GetAccelerationStructureNVInfo(format::HandleId id) const        { return GetObjectInfo<AccelerationStructureNVInfo>(id, &acceleration_structure_nv_map_); }
    const PerformanceConfigurationINTELInfo* GetPerformanceConfigurationINTELInfo(format::HandleId id) const  { return GetObjectInfo<PerformanceConfigurationINTELInfo>(id, &performance_configuration_intel_map_); }
    const DeferredOperationKHRInfo*          GetDeferredOperationKHRInfo(format::HandleId id) const           { return GetObjectInfo<DeferredOperationKHRInfo>(id, &deferred_operation_khr_map_); }
    const PrivateDataSlotEXTInfo*            GetPrivateDataSlotEXTInfo(format::HandleId id) const             { return GetObjectInfo<PrivateDataSlotEXTInfo>(id, &private_data_slot_ext_map_); }

    InstanceInfo*                      GetInstanceInfo(format::HandleId id)                       { return GetObjectInfo<InstanceInfo>(id, &instance_map_); }
    PhysicalDeviceInfo*                GetPhysicalDeviceInfo(format::HandleId id)                 { return GetObjectInfo<PhysicalDeviceInfo>(id, &physical_device_map_); }
    DeviceInfo*                        GetDeviceInfo(format::HandleId id)                         { return GetObjectInfo<DeviceInfo>(id, &device_map_); }
    QueueInfo*                         GetQueueInfo(format::HandleId id)                          { return GetObjectInfo<QueueInfo>(id, &queue_map_); }
    SemaphoreInfo*                     GetSemaphoreInfo(format::HandleId id)                      { return GetObjectInfo<SemaphoreInfo>(id, &semaphore_map_); }
    CommandBufferInfo*                 GetCommandBufferInfo(format::HandleId id)                  { return GetObjectInfo<CommandBufferInfo>(id, &command_buffer_map_); }
    FenceInfo*                         GetFenceInfo(format::HandleId id)                          { return GetObjectInfo<FenceInfo>(id, &fence_map_); }
    DeviceMemoryInfo*                  GetDeviceMemoryInfo(format::HandleId id)                   { return GetObjectInfo<DeviceMemoryInfo>(id, &device_memory_map_); }
    BufferInfo*                        GetBufferInfo(format::HandleId id)                         { return GetObjectInfo<BufferInfo>(id, &buffer_map_); }
    ImageInfo*                         GetImageInfo(format::HandleId id)                          { return GetObjectInfo<ImageInfo>(id, &image_map_); }
    EventInfo*                         GetEventInfo(format::HandleId id)                          { return GetObjectInfo<EventInfo>(id, &event_map_); }
    QueryPoolInfo*                     GetQueryPoolInfo(format::HandleId id)                      { return GetObjectInfo<QueryPoolInfo>(id, &query_pool_map_); }
    BufferViewInfo*                    GetBufferViewInfo(format::HandleId id)                     { return GetObjectInfo<BufferViewInfo>(id, &buffer_view_map_); }
    ImageViewInfo*                     GetImageViewInfo(format::HandleId id)                      { return GetObjectInfo<ImageViewInfo>(id, &image_view_map_); }
    ShaderModuleInfo*                  GetShaderModuleInfo(format::HandleId id)                   { return GetObjectInfo<ShaderModuleInfo>(id, &shader_module_map_); }
    PipelineCacheInfo*                 GetPipelineCacheInfo(format::HandleId id)                  { return GetObjectInfo<PipelineCacheInfo>(id, &pipeline_cache_map_); }
    PipelineLayoutInfo*                GetPipelineLayoutInfo(format::HandleId id)                 { return GetObjectInfo<PipelineLayoutInfo>(id, &pipeline_layout_map_); }
    RenderPassInfo*                    GetRenderPassInfo(format::HandleId id)                     { return GetObjectInfo<RenderPassInfo>(id, &render_pass_map_); }
    PipelineInfo*                      GetPipelineInfo(format::HandleId id)                       { return GetObjectInfo<PipelineInfo>(id, &pipeline_map_); }
    DescriptorSetLayoutInfo*           GetDescriptorSetLayoutInfo(format::HandleId id)            { return GetObjectInfo<DescriptorSetLayoutInfo>(id, &descriptor_set_layout_map_); }
    SamplerInfo*                       GetSamplerInfo(format::HandleId id)                        { return GetObjectInfo<SamplerInfo>(id, &sampler_map_); }
    DescriptorPoolInfo*                GetDescriptorPoolInfo(format::HandleId id)                 { return GetObjectInfo<DescriptorPoolInfo>(id, &descriptor_pool_map_); }
    DescriptorSetInfo*                 GetDescriptorSetInfo(format::HandleId id)                  { return GetObjectInfo<DescriptorSetInfo>(id, &descriptor_set_map_); }
    FramebufferInfo*                   GetFramebufferInfo(format::HandleId id)                    { return GetObjectInfo<FramebufferInfo>(id, &framebuffer_map_); }
    CommandPoolInfo*                   GetCommandPoolInfo(format::HandleId id)                    { return GetObjectInfo<CommandPoolInfo>(id, &command_pool_map_); }
    SamplerYcbcrConversionInfo*        GetSamplerYcbcrConversionInfo(format::HandleId id)         { return GetObjectInfo<SamplerYcbcrConversionInfo>(id, &sampler_ycbcr_conversion_map_); }
    DescriptorUpdateTemplateInfo*      GetDescriptorUpdateTemplateInfo(format::HandleId id)       { return GetObjectInfo<DescriptorUpdateTemplateInfo>(id, &descriptor_update_template_map_); }
    SurfaceKHRInfo*                    GetSurfaceKHRInfo(format::HandleId id)                     { return GetObjectInfo<SurfaceKHRInfo>(id, &surface_khr_map_); }
    SwapchainKHRInfo*                  GetSwapchainKHRInfo(format::HandleId id)                   { return GetObjectInfo<SwapchainKHRInfo>(id, &swapchain_khr_map_); }
    DisplayKHRInfo*                    GetDisplayKHRInfo(format::HandleId id)                     { return GetObjectInfo<DisplayKHRInfo>(id, &display_khr_map_); }
    DisplayModeKHRInfo*                GetDisplayModeKHRInfo(format::HandleId id)                 { return GetObjectInfo<DisplayModeKHRInfo>(id, &display_mode_khr_map_); }
    DebugReportCallbackEXTInfo*        GetDebugReportCallbackEXTInfo(format::HandleId id)         { return GetObjectInfo<DebugReportCallbackEXTInfo>(id, &debug_report_callback_ext_map_); }
    IndirectCommandsLayoutNVInfo*      GetIndirectCommandsLayoutNVInfo(format::HandleId id)       { return GetObjectInfo<IndirectCommandsLayoutNVInfo>(id, &indirect_commands_layout_nv_map_); }
    DebugUtilsMessengerEXTInfo*        GetDebugUtilsMessengerEXTInfo(format::HandleId id)         { return GetObjectInfo<DebugUtilsMessengerEXTInfo>(id, &debug_utils_messenger_ext_map_); }
    ValidationCacheEXTInfo*            GetValidationCacheEXTInfo(format::HandleId id)             { return GetObjectInfo<ValidationCacheEXTInfo>(id, &validation_cache_ext_map_); }
    AccelerationStructureKHRInfo*      GetAccelerationStructureKHRInfo(format::HandleId id)       { return GetObjectInfo<AccelerationStructureKHRInfo>(id, &acceleration_structure_khr_map_); }
    AccelerationStructureNVInfo*       GetAccelerationStructureNVInfo(format::HandleId id)        { return GetObjectInfo<AccelerationStructureNVInfo>(id, &acceleration_structure_nv_map_); }
    PerformanceConfigurationINTELInfo* GetPerformanceConfigurationINTELInfo(format::HandleId id)  { return GetObjectInfo<PerformanceConfigurationINTELInfo>(id, &performance_configuration_intel_map_); }
    DeferredOperationKHRInfo*          GetDeferredOperationKHRInfo(format::HandleId id)           { return GetObjectInfo<DeferredOperationKHRInfo>(id, &deferred_operation_khr_map_); }
    PrivateDataSlotEXTInfo*            GetPrivateDataSlotEXTInfo(format::HandleId id)             { return GetObjectInfo<PrivateDataSlotEXTInfo>(id, &private_data_slot_ext_map_); }

    void VisitInstanceInfo(std::function<void(const InstanceInfo*)> visitor) const                                           { for (const auto& entry : instance_map_) { visitor(&entry.second); } }
    void VisitPhysicalDeviceInfo(std::function<void(const PhysicalDeviceInfo*)> visitor) const                               { for (const auto& entry : physical_device_map_) { visitor(&entry.second); } }
    void VisitDeviceInfo(std::function<void(const DeviceInfo*)> visitor) const                                               { for (const auto& entry : device_map_) { visitor(&entry.second); } }
    void VisitQueueInfo(std::function<void(const QueueInfo*)> visitor) const                                                 { for (const auto& entry : queue_map_) { visitor(&entry.second); } }
    void VisitSemaphoreInfo(std::function<void(const SemaphoreInfo*)> visitor) const                                         { for (const auto& entry : semaphore_map_) { visitor(&entry.second); } }
    void VisitCommandBufferInfo(std::function<void(const CommandBufferInfo*)> visitor) const                                 { for (const auto& entry : command_buffer_map_) { visitor(&entry.second); } }
    void VisitFenceInfo(std::function<void(const FenceInfo*)> visitor) const                                                 { for (const auto& entry : fence_map_) { visitor(&entry.second); } }
    void VisitDeviceMemoryInfo(std::function<void(const DeviceMemoryInfo*)> visitor) const                                   { for (const auto& entry : device_memory_map_) { visitor(&entry.second); } }
    void VisitBufferInfo(std::function<void(const BufferInfo*)> visitor) const                                               { for (const auto& entry : buffer_map_) { visitor(&entry.second); } }
    void VisitImageInfo(std::function<void(const ImageInfo*)> visitor) const                                                 { for (const auto& entry : image_map_) { visitor(&entry.second); } }
    void VisitEventInfo(std::function<void(const EventInfo*)> visitor) const                                                 { for (const auto& entry : event_map_) { visitor(&entry.second); } }
    void VisitQueryPoolInfo(std::function<void(const QueryPoolInfo*)> visitor) const                                         { for (const auto& entry : query_pool_map_) { visitor(&entry.second); } }
    void VisitBufferViewInfo(std::function<void(const BufferViewInfo*)> visitor) const                                       { for (const auto& entry : buffer_view_map_) { visitor(&entry.second); } }
    void VisitImageViewInfo(std::function<void(const ImageViewInfo*)> visitor) const                                         { for (const auto& entry : image_view_map_) { visitor(&entry.second); } }
    void VisitShaderModuleInfo(std::function<void(const ShaderModuleInfo*)> visitor) const                                   { for (const auto& entry : shader_module_map_) { visitor(&entry.second); } }
    void VisitPipelineCacheInfo(std::function<void(const PipelineCacheInfo*)> visitor) const                                 { for (const auto& entry : pipeline_cache_map_) { visitor(&entry.second); } }
    void VisitPipelineLayoutInfo(std::function<void(const PipelineLayoutInfo*)> visitor) const                               { for (const auto& entry : pipeline_layout_map_) { visitor(&entry.second); } }
    void VisitRenderPassInfo(std::function<void(const RenderPassInfo*)> visitor) const                                       { for (const auto& entry : render_pass_map_) { visitor(&entry.second); } }
    void VisitPipelineInfo(std::function<void(const PipelineInfo*)> visitor) const                                           { for (const auto& entry : pipeline_map_) { visitor(&entry.second); } }
    void VisitDescriptorSetLayoutInfo(std::function<void(const DescriptorSetLayoutInfo*)> visitor) const                     { for (const auto& entry : descriptor_set_layout_map_) { visitor(&entry.second); } }
    void VisitSamplerInfo(std::function<void(const SamplerInfo*)> visitor) const                                             { for (const auto& entry : sampler_map_) { visitor(&entry.second); } }
    void VisitDescriptorPoolInfo(std::function<void(const DescriptorPoolInfo*)> visitor) const                               { for (const auto& entry : descriptor_pool_map_) { visitor(&entry.second); } }
    void VisitDescriptorSetInfo(std::function<void(const DescriptorSetInfo*)> visitor) const                                 { for (const auto& entry : descriptor_set_map_) { visitor(&entry.second); } }
    void VisitFramebufferInfo(std::function<void(const FramebufferInfo*)> visitor) const                                     { for (const auto& entry : framebuffer_map_) { visitor(&entry.second); } }
    void VisitCommandPoolInfo(std::function<void(const CommandPoolInfo*)> visitor) const                                     { for (const auto& entry : command_pool_map_) { visitor(&entry.second); } }
    void VisitSamplerYcbcrConversionInfo(std::function<void(const SamplerYcbcrConversionInfo*)> visitor) const               { for (const auto& entry : sampler_ycbcr_conversion_map_) { visitor(&entry.second); } }
    void VisitDescriptorUpdateTemplateInfo(std::function<void(const DescriptorUpdateTemplateInfo*)> visitor) const           { for (const auto& entry : descriptor_update_template_map_) { visitor(&entry.second); } }
    void VisitSurfaceKHRInfo(std::function<void(const SurfaceKHRInfo*)> visitor) const                                       { for (const auto& entry : surface_khr_map_) { visitor(&entry.second); } }
    void VisitSwapchainKHRInfo(std::function<void(const SwapchainKHRInfo*)> visitor) const                                   { for (const auto& entry : swapchain_khr_map_) { visitor(&entry.second); } }
    void VisitDisplayKHRInfo(std::function<void(const DisplayKHRInfo*)> visitor) const                                       { for (const auto& entry : display_khr_map_) { visitor(&entry.second); } }
    void VisitDisplayModeKHRInfo(std::function<void(const DisplayModeKHRInfo*)> visitor) const                               { for (const auto& entry : display_mode_khr_map_) { visitor(&entry.second); } }
    void VisitDebugReportCallbackEXTInfo(std::function<void(const DebugReportCallbackEXTInfo*)> visitor) const               { for (const auto& entry : debug_report_callback_ext_map_) { visitor(&entry.second); } }
    void VisitIndirectCommandsLayoutNVInfo(std::function<void(const IndirectCommandsLayoutNVInfo*)> visitor) const           { for (const auto& entry : indirect_commands_layout_nv_map_) { visitor(&entry.second); } }
    void VisitDebugUtilsMessengerEXTInfo(std::function<void(const DebugUtilsMessengerEXTInfo*)> visitor) const               { for (const auto& entry : debug_utils_messenger_ext_map_) { visitor(&entry.second); } }
    void VisitValidationCacheEXTInfo(std::function<void(const ValidationCacheEXTInfo*)> visitor) const                       { for (const auto& entry : validation_cache_ext_map_) { visitor(&entry.second); } }
    void VisitAccelerationStructureKHRInfo(std::function<void(const AccelerationStructureKHRInfo*)> visitor) const           { for (const auto& entry : acceleration_structure_khr_map_) { visitor(&entry.second); } }
    void VisitAccelerationStructureNVInfo(std::function<void(const AccelerationStructureNVInfo*)> visitor) const             { for (const auto& entry : acceleration_structure_nv_map_) { visitor(&entry.second); } }
    void VisitPerformanceConfigurationINTELInfo(std::function<void(const PerformanceConfigurationINTELInfo*)> visitor) const { for (const auto& entry : performance_configuration_intel_map_) { visitor(&entry.second); } }
    void VisitDeferredOperationKHRInfo(std::function<void(const DeferredOperationKHRInfo*)> visitor) const                   { for (const auto& entry : deferred_operation_khr_map_) { visitor(&entry.second); } }
    void VisitPrivateDataSlotEXTInfo(std::function<void(const PrivateDataSlotEXTInfo*)> visitor) const                       { for (const auto& entry : private_data_slot_ext_map_) { visitor(&entry.second); } }
    // clang-format on

    void ReplaceSemaphore(VkSemaphore target, VkSemaphore replacement)
    {
        for (auto& entry : semaphore_map_)
        {
            if (entry.second.handle == target)
            {
                entry.second.handle = replacement;
                break;
            }
        }
    }

    void ReplaceFence(VkFence target, VkFence replacement)
    {
        for (auto& entry : fence_map_)
        {
            if (entry.second.handle == target)
            {
                entry.second.handle = replacement;
                break;
            }
        }
    }

  private:
    template <typename T>
    void AddObjectInfo(T&& info, std::unordered_map<format::HandleId, T>* map)
    {
        assert(map != nullptr);

        if ((info.capture_id != 0) && (info.handle != VK_NULL_HANDLE))
        {
            auto result = map->emplace(info.capture_id, std::forward<T>(info));

            if (!result.second)
            {
                // There are two expected cases where a capture ID would already be in the map. The first case is for
                // handles that are retrieved, such as VkPhysicalDevice, which can be processed more than once. For
                // this case we a have a duplicate info structure with the same ID and handle value, and do not need
                // to update the map entry. The existing entry may even contain additional info that would be lost if
                // replaced with this newly created, default initialized, info structure. The second case is for
                // temporary objects created during the trimmed file state setup. IDs may be reused when creating these
                // temporary objects, creating a case where we have a new handle that is not a duplicate of the existing
                // map entry. In this case, the map entry needs to be updated with the new object's info.
                auto iter = result.first;
                if (iter->second.handle != info.handle)
                {
                    iter->second = std::forward<T>(info);
                }
            }
        }
    }

    template <typename T>
    const T* GetObjectInfo(format::HandleId id, const std::unordered_map<format::HandleId, T>* map) const
    {
        assert(map != nullptr);

        const T* object_info = nullptr;

        if (id != 0)
        {
            const auto entry = map->find(id);

            if (entry != map->end())
            {
                object_info = &entry->second;
            }
        }

        return object_info;
    }

    template <typename T>
    T* GetObjectInfo(format::HandleId id, std::unordered_map<format::HandleId, T>* map)
    {
        assert(map != nullptr);

        T* object_info = nullptr;

        if (id != 0)
        {
            auto entry = map->find(id);

            if (entry != map->end())
            {
                object_info = &entry->second;
            }
        }

        return object_info;
    }

  private:
    std::unordered_map<format::HandleId, InstanceInfo>                      instance_map_;
    std::unordered_map<format::HandleId, PhysicalDeviceInfo>                physical_device_map_;
    std::unordered_map<format::HandleId, DeviceInfo>                        device_map_;
    std::unordered_map<format::HandleId, QueueInfo>                         queue_map_;
    std::unordered_map<format::HandleId, SemaphoreInfo>                     semaphore_map_;
    std::unordered_map<format::HandleId, CommandBufferInfo>                 command_buffer_map_;
    std::unordered_map<format::HandleId, FenceInfo>                         fence_map_;
    std::unordered_map<format::HandleId, DeviceMemoryInfo>                  device_memory_map_;
    std::unordered_map<format::HandleId, BufferInfo>                        buffer_map_;
    std::unordered_map<format::HandleId, ImageInfo>                         image_map_;
    std::unordered_map<format::HandleId, EventInfo>                         event_map_;
    std::unordered_map<format::HandleId, QueryPoolInfo>                     query_pool_map_;
    std::unordered_map<format::HandleId, BufferViewInfo>                    buffer_view_map_;
    std::unordered_map<format::HandleId, ImageViewInfo>                     image_view_map_;
    std::unordered_map<format::HandleId, ShaderModuleInfo>                  shader_module_map_;
    std::unordered_map<format::HandleId, PipelineCacheInfo>                 pipeline_cache_map_;
    std::unordered_map<format::HandleId, PipelineLayoutInfo>                pipeline_layout_map_;
    std::unordered_map<format::HandleId, RenderPassInfo>                    render_pass_map_;
    std::unordered_map<format::HandleId, PipelineInfo>                      pipeline_map_;
    std::unordered_map<format::HandleId, DescriptorSetLayoutInfo>           descriptor_set_layout_map_;
    std::unordered_map<format::HandleId, SamplerInfo>                       sampler_map_;
    std::unordered_map<format::HandleId, DescriptorPoolInfo>                descriptor_pool_map_;
    std::unordered_map<format::HandleId, DescriptorSetInfo>                 descriptor_set_map_;
    std::unordered_map<format::HandleId, FramebufferInfo>                   framebuffer_map_;
    std::unordered_map<format::HandleId, CommandPoolInfo>                   command_pool_map_;
    std::unordered_map<format::HandleId, SamplerYcbcrConversionInfo>        sampler_ycbcr_conversion_map_;
    std::unordered_map<format::HandleId, DescriptorUpdateTemplateInfo>      descriptor_update_template_map_;
    std::unordered_map<format::HandleId, SurfaceKHRInfo>                    surface_khr_map_;
    std::unordered_map<format::HandleId, SwapchainKHRInfo>                  swapchain_khr_map_;
    std::unordered_map<format::HandleId, DisplayKHRInfo>                    display_khr_map_;
    std::unordered_map<format::HandleId, DisplayModeKHRInfo>                display_mode_khr_map_;
    std::unordered_map<format::HandleId, DebugReportCallbackEXTInfo>        debug_report_callback_ext_map_;
    std::unordered_map<format::HandleId, IndirectCommandsLayoutNVInfo>      indirect_commands_layout_nv_map_;
    std::unordered_map<format::HandleId, DebugUtilsMessengerEXTInfo>        debug_utils_messenger_ext_map_;
    std::unordered_map<format::HandleId, ValidationCacheEXTInfo>            validation_cache_ext_map_;
    std::unordered_map<format::HandleId, AccelerationStructureKHRInfo>      acceleration_structure_khr_map_;
    std::unordered_map<format::HandleId, AccelerationStructureNVInfo>       acceleration_structure_nv_map_;
    std::unordered_map<format::HandleId, PerformanceConfigurationINTELInfo> performance_configuration_intel_map_;
    std::unordered_map<format::HandleId, DeferredOperationKHRInfo>          deferred_operation_khr_map_;
    std::unordered_map<format::HandleId, PrivateDataSlotEXTInfo>            private_data_slot_ext_map_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_OBJECT_MAPPER_H
