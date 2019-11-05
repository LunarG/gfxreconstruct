/*
** Copyright (c) 2018-2019 Valve Corporation
** Copyright (c) 2018-2019 LunarG, Inc.
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
#include "util/logging.h"

#include "vulkan/vulkan.h"

#include <cassert>
#include <unordered_map>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class VulkanObjectMapper
{
  public:
    // clang-format off
    void AddVkInstance(format::HandleId id, VkInstance handle)                                           { AddObject<InstanceInfo>(id, handle, &instance_map_); }
    void AddVkPhysicalDevice(format::HandleId id, VkPhysicalDevice handle)                               { AddObject<PhysicalDeviceInfo>(id, handle, &physical_device_map_); }
    void AddVkDevice(format::HandleId id, VkDevice handle)                                               { AddObject<DeviceInfo>(id, handle, &device_map_); }
    void AddVkQueue(format::HandleId id, VkQueue handle)                                                 { AddObject<QueueInfo>(id, handle, &queue_map_); }
    void AddVkSemaphore(format::HandleId id, VkSemaphore handle)                                         { AddObject<SemaphoreInfo>(id, handle, &semaphore_map_); }
    void AddVkCommandBuffer(format::HandleId id, VkCommandBuffer handle)                                 { AddObject<CommandBufferInfo>(id, handle, &command_buffer_map_); }
    void AddVkFence(format::HandleId id, VkFence handle)                                                 { AddObject<FenceInfo>(id, handle, &fence_map_); }
    void AddVkDeviceMemory(format::HandleId id, VkDeviceMemory handle)                                   { AddObject<DeviceMemoryInfo>(id, handle, &device_memory_map_); }
    void AddVkBuffer(format::HandleId id, VkBuffer handle)                                               { AddObject<BufferInfo>(id, handle, &buffer_map_); }
    void AddVkImage(format::HandleId id, VkImage handle)                                                 { AddObject<ImageInfo>(id, handle, &image_map_); }
    void AddVkEvent(format::HandleId id, VkEvent handle)                                                 { AddObject<EventInfo>(id, handle, &event_map_); }
    void AddVkQueryPool(format::HandleId id, VkQueryPool handle)                                         { AddObject<QueryPoolInfo>(id, handle, &query_pool_map_); }
    void AddVkBufferView(format::HandleId id, VkBufferView handle)                                       { AddObject<BufferViewInfo>(id, handle, &buffer_view_map_); }
    void AddVkImageView(format::HandleId id, VkImageView handle)                                         { AddObject<ImageViewInfo>(id, handle, &image_view_map_); }
    void AddVkShaderModule(format::HandleId id, VkShaderModule handle)                                   { AddObject<ShaderModuleInfo>(id, handle, &shader_module_map_); }
    void AddVkPipelineCache(format::HandleId id, VkPipelineCache handle)                                 { AddObject<PipelineCacheInfo>(id, handle, &pipeline_cache_map_); }
    void AddVkPipelineLayout(format::HandleId id, VkPipelineLayout handle)                               { AddObject<PipelineLayoutInfo>(id, handle, &pipeline_layout_map_); }
    void AddVkRenderPass(format::HandleId id, VkRenderPass handle)                                       { AddObject<RenderPassInfo>(id, handle, &render_pass_map_); }
    void AddVkPipeline(format::HandleId id, VkPipeline handle)                                           { AddObject<PipelineInfo>(id, handle, &pipeline_map_); }
    void AddVkDescriptorSetLayout(format::HandleId id, VkDescriptorSetLayout handle)                     { AddObject<DescriptorSetLayoutInfo>(id, handle, &descriptor_set_layout_map_); }
    void AddVkSampler(format::HandleId id, VkSampler handle)                                             { AddObject<SamplerInfo>(id, handle, &sampler_map_); }
    void AddVkDescriptorPool(format::HandleId id, VkDescriptorPool handle)                               { AddObject<DescriptorPoolInfo>(id, handle, &descriptor_pool_map_); }
    void AddVkDescriptorSet(format::HandleId id, VkDescriptorSet handle)                                 { AddObject<DescriptorSetInfo>(id, handle, &descriptor_set_map_); }
    void AddVkFramebuffer(format::HandleId id, VkFramebuffer handle)                                     { AddObject<FramebufferInfo>(id, handle, &framebuffer_map_); }
    void AddVkCommandPool(format::HandleId id, VkCommandPool handle)                                     { AddObject<CommandPoolInfo>(id, handle, &command_pool_map_); }
    void AddVkSamplerYcbcrConversion(format::HandleId id, VkSamplerYcbcrConversion handle)               { AddObject<SamplerYcbcrConversionInfo>(id, handle, &sampler_ycbcr_conversion_map_); }
    void AddVkDescriptorUpdateTemplate(format::HandleId id, VkDescriptorUpdateTemplate handle)           { AddObject<DescriptorUpdateTemplateInfo>(id, handle, &descriptor_update_template_map_); }
    void AddVkSurfaceKHR(format::HandleId id, VkSurfaceKHR handle)                                       { AddObject<SurfaceKHRInfo>(id, handle, &surface_khr_map_); }
    void AddVkSwapchainKHR(format::HandleId id, VkSwapchainKHR handle)                                   { AddObject<SwapchainKHRInfo>(id, handle, &swapchain_khr_map_); }
    void AddVkDisplayKHR(format::HandleId id, VkDisplayKHR handle)                                       { AddObject<DisplayKHRInfo>(id, handle, &display_khr_map_); }
    void AddVkDisplayModeKHR(format::HandleId id, VkDisplayModeKHR handle)                               { AddObject<DisplayModeKHRInfo>(id, handle, &display_mode_khr_map_); }
    void AddVkSamplerYcbcrConversionKHR(format::HandleId id, VkSamplerYcbcrConversionKHR handle)         { AddObject<SamplerYcbcrConversionKHRInfo>(id, handle, &sampler_ycbcr_conversion_khr_map_); }
    void AddVkDebugReportCallbackEXT(format::HandleId id, VkDebugReportCallbackEXT handle)               { AddObject<DebugReportCallbackEXTInfo>(id, handle, &debug_report_callback_ext_map_); }
    void AddVkObjectTableNVX(format::HandleId id, VkObjectTableNVX handle)                               { AddObject<ObjectTableNVXInfo>(id, handle, &object_table_nvx_map_); }
    void AddVkIndirectCommandsLayoutNVX(format::HandleId id, VkIndirectCommandsLayoutNVX handle)         { AddObject<IndirectCommandsLayoutNVXInfo>(id, handle, &indirect_commands_layout_nvx_map_); }
    void AddVkDebugUtilsMessengerEXT(format::HandleId id, VkDebugUtilsMessengerEXT handle)               { AddObject<DebugUtilsMessengerEXTInfo>(id, handle, &debug_utils_messenger_ext_map_); }
    void AddVkValidationCacheEXT(format::HandleId id, VkValidationCacheEXT handle)                       { AddObject<ValidationCacheEXTInfo>(id, handle, &validation_cache_ext_map_); }
    void AddVkAccelerationStructureNV(format::HandleId id, VkAccelerationStructureNV handle)             { AddObject<AccelerationStructureNVInfo>(id, handle, &acceleration_structure_nv_map_); }
    void AddVkPerformanceConfigurationINTEL(format::HandleId id, VkPerformanceConfigurationINTEL handle) { AddObject<PerformanceConfigurationINTELInfo>(id, handle, &performance_configuration_intel_map_); }

    const InstanceInfo*                      MapVkInstance(format::HandleId id) const                       { return MapObject<InstanceInfo>(id, &instance_map_); }
    const PhysicalDeviceInfo*                MapVkPhysicalDevice(format::HandleId id) const                 { return MapObject<PhysicalDeviceInfo>(id, &physical_device_map_); }
    const DeviceInfo*                        MapVkDevice(format::HandleId id) const                         { return MapObject<DeviceInfo>(id, &device_map_); }
    const QueueInfo*                         MapVkQueue(format::HandleId id) const                          { return MapObject<QueueInfo>(id, &queue_map_); }
    const SemaphoreInfo*                     MapVkSemaphore(format::HandleId id) const                      { return MapObject<SemaphoreInfo>(id, &semaphore_map_); }
    const CommandBufferInfo*                 MapVkCommandBuffer(format::HandleId id) const                  { return MapObject<CommandBufferInfo>(id, &command_buffer_map_); }
    const FenceInfo*                         MapVkFence(format::HandleId id) const                          { return MapObject<FenceInfo>(id, &fence_map_); }
    const DeviceMemoryInfo*                  MapVkDeviceMemory(format::HandleId id) const                   { return MapObject<DeviceMemoryInfo>(id, &device_memory_map_); }
    const BufferInfo*                        MapVkBuffer(format::HandleId id) const                         { return MapObject<BufferInfo>(id, &buffer_map_); }
    const ImageInfo*                         MapVkImage(format::HandleId id) const                          { return MapObject<ImageInfo>(id, &image_map_); }
    const EventInfo*                         MapVkEvent(format::HandleId id) const                          { return MapObject<EventInfo>(id, &event_map_); }
    const QueryPoolInfo*                     MapVkQueryPool(format::HandleId id) const                      { return MapObject<QueryPoolInfo>(id, &query_pool_map_); }
    const BufferViewInfo*                    MapVkBufferView(format::HandleId id) const                     { return MapObject<BufferViewInfo>(id, &buffer_view_map_); }
    const ImageViewInfo*                     MapVkImageView(format::HandleId id) const                      { return MapObject<ImageViewInfo>(id, &image_view_map_); }
    const ShaderModuleInfo*                  MapVkShaderModule(format::HandleId id) const                   { return MapObject<ShaderModuleInfo>(id, &shader_module_map_); }
    const PipelineCacheInfo*                 MapVkPipelineCache(format::HandleId id) const                  { return MapObject<PipelineCacheInfo>(id, &pipeline_cache_map_); }
    const PipelineLayoutInfo*                MapVkPipelineLayout(format::HandleId id) const                 { return MapObject<PipelineLayoutInfo>(id, &pipeline_layout_map_); }
    const RenderPassInfo*                    MapVkRenderPass(format::HandleId id) const                     { return MapObject<RenderPassInfo>(id, &render_pass_map_); }
    const PipelineInfo*                      MapVkPipeline(format::HandleId id) const                       { return MapObject<PipelineInfo>(id, &pipeline_map_); }
    const DescriptorSetLayoutInfo*           MapVkDescriptorSetLayout(format::HandleId id) const            { return MapObject<DescriptorSetLayoutInfo>(id, &descriptor_set_layout_map_); }
    const SamplerInfo*                       MapVkSampler(format::HandleId id) const                        { return MapObject<SamplerInfo>(id, &sampler_map_); }
    const DescriptorPoolInfo*                MapVkDescriptorPool(format::HandleId id) const                 { return MapObject<DescriptorPoolInfo>(id, &descriptor_pool_map_); }
    const DescriptorSetInfo*                 MapVkDescriptorSet(format::HandleId id) const                  { return MapObject<DescriptorSetInfo>(id, &descriptor_set_map_); }
    const FramebufferInfo*                   MapVkFramebuffer(format::HandleId id) const                    { return MapObject<FramebufferInfo>(id, &framebuffer_map_); }
    const CommandPoolInfo*                   MapVkCommandPool(format::HandleId id) const                    { return MapObject<CommandPoolInfo>(id, &command_pool_map_); }
    const SamplerYcbcrConversionInfo*        MapVkSamplerYcbcrConversion(format::HandleId id) const         { return MapObject<SamplerYcbcrConversionInfo>(id, &sampler_ycbcr_conversion_map_); }
    const DescriptorUpdateTemplateInfo*      MapVkDescriptorUpdateTemplate(format::HandleId id) const       { return MapObject<DescriptorUpdateTemplateInfo>(id, &descriptor_update_template_map_); }
    const SurfaceKHRInfo*                    MapVkSurfaceKHR(format::HandleId id) const                     { return MapObject<SurfaceKHRInfo>(id, &surface_khr_map_); }
    const SwapchainKHRInfo*                  MapVkSwapchainKHR(format::HandleId id) const                   { return MapObject<SwapchainKHRInfo>(id, &swapchain_khr_map_); }
    const DisplayKHRInfo*                    MapVkDisplayKHR(format::HandleId id) const                     { return MapObject<DisplayKHRInfo>(id, &display_khr_map_); }
    const DisplayModeKHRInfo*                MapVkDisplayModeKHR(format::HandleId id) const                 { return MapObject<DisplayModeKHRInfo>(id, &display_mode_khr_map_); }
    const SamplerYcbcrConversionKHRInfo*     MapVkSamplerYcbcrConversionKHR(format::HandleId id) const      { return MapObject<SamplerYcbcrConversionKHRInfo>(id, &sampler_ycbcr_conversion_khr_map_); }
    const DebugReportCallbackEXTInfo*        MapVkDebugReportCallbackEXT(format::HandleId id) const         { return MapObject<DebugReportCallbackEXTInfo>(id, &debug_report_callback_ext_map_); }
    const ObjectTableNVXInfo*                MapVkObjectTableNVX(format::HandleId id) const                 { return MapObject<ObjectTableNVXInfo>(id, &object_table_nvx_map_); }
    const IndirectCommandsLayoutNVXInfo*     MapVkIndirectCommandsLayoutNVX(format::HandleId id) const      { return MapObject<IndirectCommandsLayoutNVXInfo>(id, &indirect_commands_layout_nvx_map_); }
    const DebugUtilsMessengerEXTInfo*        MapVkDebugUtilsMessengerEXT(format::HandleId id) const         { return MapObject<DebugUtilsMessengerEXTInfo>(id, &debug_utils_messenger_ext_map_); }
    const ValidationCacheEXTInfo*            MapVkValidationCacheEXT(format::HandleId id) const             { return MapObject<ValidationCacheEXTInfo>(id, &validation_cache_ext_map_); }
    const AccelerationStructureNVInfo*       MapVkAccelerationStructureNV(format::HandleId id) const        { return MapObject<AccelerationStructureNVInfo>(id, &acceleration_structure_nv_map_); }
    const PerformanceConfigurationINTELInfo* MapVkPerformanceConfigurationINTEL(format::HandleId id) const  { return MapObject<PerformanceConfigurationINTELInfo>(id, &performance_configuration_intel_map_); }
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
    void AddObject(format::HandleId id, typename T::HandleType handle, std::unordered_map<format::HandleId, T>* map)
    {
        assert(map != nullptr);

        if ((id != 0) && (handle != VK_NULL_HANDLE))
        {
            auto entry = map->find(id);
            if (entry == map->end())
            {
                T info;
                info.handle     = handle;
                info.capture_id = id;

                map->emplace(id, info);
            }
            else
            {
                // Handles that are retrieved, such as VkPhysicalDevice, may be processed twice, but the id/handle
                // pairing will always be the same.  Some trimming cases will recreate the same temporary object using
                // the same temporary id, and the info structure will be reset for this case.
                if (entry->second.handle != handle)
                {
                    entry->second = {};

                    entry->second.handle     = handle;
                    entry->second.capture_id = id;
                }
            }
        }
    }

    template <typename T>
    const T* MapObject(format::HandleId id, const std::unordered_map<format::HandleId, T>* map) const
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
            else
            {
                GFXRECON_LOG_WARNING("Failed to map handle for object id %" PRIu64, id);
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
    std::unordered_map<format::HandleId, SamplerYcbcrConversionKHRInfo>     sampler_ycbcr_conversion_khr_map_;
    std::unordered_map<format::HandleId, DebugReportCallbackEXTInfo>        debug_report_callback_ext_map_;
    std::unordered_map<format::HandleId, ObjectTableNVXInfo>                object_table_nvx_map_;
    std::unordered_map<format::HandleId, IndirectCommandsLayoutNVXInfo>     indirect_commands_layout_nvx_map_;
    std::unordered_map<format::HandleId, DebugUtilsMessengerEXTInfo>        debug_utils_messenger_ext_map_;
    std::unordered_map<format::HandleId, ValidationCacheEXTInfo>            validation_cache_ext_map_;
    std::unordered_map<format::HandleId, AccelerationStructureNVInfo>       acceleration_structure_nv_map_;
    std::unordered_map<format::HandleId, PerformanceConfigurationINTELInfo> performance_configuration_intel_map_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_OBJECT_MAPPER_H
