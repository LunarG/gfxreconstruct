/*
** Copyright (c) 2018 LunarG, Inc.
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

#ifndef BRIMSTONE_DECODE_VULKAN_OBJECT_MAPPER_H
#define BRIMSTONE_DECODE_VULKAN_OBJECT_MAPPER_H

#include <cassert>
#include <unordered_map>

#include "vulkan/vulkan.h"

#include "format/format.h"
#include "util/defines.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(decode)

class VulkanObjectMapper
{
  public:
    // clang-format off
    void AddVkInstance(format::HandleId id, VkInstance handle)                                       { AddObject<VkInstance>(id, handle, &instance_map_); }
    void AddVkPhysicalDevice(format::HandleId id, VkPhysicalDevice handle)                           { AddObject<VkPhysicalDevice>(id, handle, &physical_device_map_); }
    void AddVkDevice(format::HandleId id, VkDevice handle)                                           { AddObject<VkDevice>(id, handle, &device_map_); }
    void AddVkQueue(format::HandleId id, VkQueue handle)                                             { AddObject<VkQueue>(id, handle, &queue_map_); }
    void AddVkSemaphore(format::HandleId id, VkSemaphore handle)                                     { AddObject<VkSemaphore>(id, handle, &semaphore_map_); }
    void AddVkCommandBuffer(format::HandleId id, VkCommandBuffer handle)                             { AddObject<VkCommandBuffer>(id, handle, &command_buffer_map_); }
    void AddVkFence(format::HandleId id, VkFence handle)                                             { AddObject<VkFence>(id, handle, &fence_map_); }
    void AddVkDeviceMemory(format::HandleId id, VkDeviceMemory handle)                               { AddObject<VkDeviceMemory>(id, handle, &device_memory_map_); }
    void AddVkBuffer(format::HandleId id, VkBuffer handle)                                           { AddObject<VkBuffer>(id, handle, &buffer_map_); }
    void AddVkImage(format::HandleId id, VkImage handle)                                             { AddObject<VkImage>(id, handle, &image_map_); }
    void AddVkEvent(format::HandleId id, VkEvent handle)                                             { AddObject<VkEvent>(id, handle, &event_map_); }
    void AddVkQueryPool(format::HandleId id, VkQueryPool handle)                                     { AddObject<VkQueryPool>(id, handle, &query_pool_map_); }
    void AddVkBufferView(format::HandleId id, VkBufferView handle)                                   { AddObject<VkBufferView>(id, handle, &buffer_view_map_); }
    void AddVkImageView(format::HandleId id, VkImageView handle)                                     { AddObject<VkImageView>(id, handle, &image_view_map_); }
    void AddVkShaderModule(format::HandleId id, VkShaderModule handle)                               { AddObject<VkShaderModule>(id, handle, &shader_module_map_); }
    void AddVkPipelineCache(format::HandleId id, VkPipelineCache handle)                             { AddObject<VkPipelineCache>(id, handle, &pipeline_cache_map_); }
    void AddVkPipelineLayout(format::HandleId id, VkPipelineLayout handle)                           { AddObject<VkPipelineLayout>(id, handle, &pipeline_layout_map_); }
    void AddVkRenderPass(format::HandleId id, VkRenderPass handle)                                   { AddObject<VkRenderPass>(id, handle, &render_pass_map_); }
    void AddVkPipeline(format::HandleId id, VkPipeline handle)                                       { AddObject<VkPipeline>(id, handle, &pipeline_map_); }
    void AddVkDescriptorSetLayout(format::HandleId id, VkDescriptorSetLayout handle)                 { AddObject<VkDescriptorSetLayout>(id, handle, &descriptor_set_layout_map_); }
    void AddVkSampler(format::HandleId id, VkSampler handle)                                         { AddObject<VkSampler>(id, handle, &sampler_map_); }
    void AddVkDescriptorPool(format::HandleId id, VkDescriptorPool handle)                           { AddObject<VkDescriptorPool>(id, handle, &descriptor_pool_map_); }
    void AddVkDescriptorSet(format::HandleId id, VkDescriptorSet handle)                             { AddObject<VkDescriptorSet>(id, handle, &descriptor_set_map_); }
    void AddVkFramebuffer(format::HandleId id, VkFramebuffer handle)                                 { AddObject<VkFramebuffer>(id, handle, &framebuffer_map_); }
    void AddVkCommandPool(format::HandleId id, VkCommandPool handle)                                 { AddObject<VkCommandPool>(id, handle, &command_pool_map_); }
    void AddVkSamplerYcbcrConversion(format::HandleId id, VkSamplerYcbcrConversion handle)           { AddObject<VkSamplerYcbcrConversion>(id, handle, &sampler_ycbcr_conversion_map_); }
    void AddVkDescriptorUpdateTemplate(format::HandleId id, VkDescriptorUpdateTemplate handle)       { AddObject<VkDescriptorUpdateTemplate>(id, handle, &descriptor_update_template_map_); }
    void AddVkSurfaceKHR(format::HandleId id, VkSurfaceKHR handle)                                   { AddObject<VkSurfaceKHR>(id, handle, &surface_khr_map_); }
    void AddVkSwapchainKHR(format::HandleId id, VkSwapchainKHR handle)                               { AddObject<VkSwapchainKHR>(id, handle, &swapchain_khr_map_); }
    void AddVkDisplayKHR(format::HandleId id, VkDisplayKHR handle)                                   { AddObject<VkDisplayKHR>(id, handle, &display_khr_map_); }
    void AddVkDisplayModeKHR(format::HandleId id, VkDisplayModeKHR handle)                           { AddObject<VkDisplayModeKHR>(id, handle, &display_mode_khr_map_); }
    void AddVkDescriptorUpdateTemplateKHR(format::HandleId id, VkDescriptorUpdateTemplateKHR handle) { AddObject<VkDescriptorUpdateTemplateKHR>(id, handle, &descriptor_update_template_khr_map_); }
    void AddVkSamplerYcbcrConversionKHR(format::HandleId id, VkSamplerYcbcrConversionKHR handle)     { AddObject<VkSamplerYcbcrConversionKHR>(id, handle, &sampler_ycbcr_conversion_khr_map_); }
    void AddVkDebugReportCallbackEXT(format::HandleId id, VkDebugReportCallbackEXT handle)           { AddObject<VkDebugReportCallbackEXT>(id, handle, &debug_report_callback_ext_map_); }
    void AddVkObjectTableNVX(format::HandleId id, VkObjectTableNVX handle)                           { AddObject<VkObjectTableNVX>(id, handle, &object_table_nvx_map_); }
    void AddVkIndirectCommandsLayoutNVX(format::HandleId id, VkIndirectCommandsLayoutNVX handle)     { AddObject<VkIndirectCommandsLayoutNVX>(id, handle, &indirect_commands_layout_nvx_map_); }
    void AddVkDebugUtilsMessengerEXT(format::HandleId id, VkDebugUtilsMessengerEXT handle)           { AddObject<VkDebugUtilsMessengerEXT>(id, handle, &debug_utils_messenger_ext_map_); }
    void AddVkValidationCacheEXT(format::HandleId id, VkValidationCacheEXT handle)                   { AddObject<VkValidationCacheEXT>(id, handle, &validation_cache_ext_map_); }

    VkInstance                    MapVkInstance(format::HandleId id) const                    { return MapObject<VkInstance>(id, &instance_map_); }
    VkPhysicalDevice              MapVkPhysicalDevice(format::HandleId id) const              { return MapObject<VkPhysicalDevice>(id, &physical_device_map_); }
    VkDevice                      MapVkDevice(format::HandleId id) const                      { return MapObject<VkDevice>(id, &device_map_); }
    VkQueue                       MapVkQueue(format::HandleId id) const                       { return MapObject<VkQueue>(id, &queue_map_); }
    VkSemaphore                   MapVkSemaphore(format::HandleId id) const                   { return MapObject<VkSemaphore>(id, &semaphore_map_); }
    VkCommandBuffer               MapVkCommandBuffer(format::HandleId id) const               { return MapObject<VkCommandBuffer>(id, &command_buffer_map_); }
    VkFence                       MapVkFence(format::HandleId id) const                       { return MapObject<VkFence>(id, &fence_map_); }
    VkDeviceMemory                MapVkDeviceMemory(format::HandleId id) const                { return MapObject<VkDeviceMemory>(id, &device_memory_map_); }
    VkBuffer                      MapVkBuffer(format::HandleId id) const                      { return MapObject<VkBuffer>(id, &buffer_map_); }
    VkImage                       MapVkImage(format::HandleId id) const                       { return MapObject<VkImage>(id, &image_map_); }
    VkEvent                       MapVkEvent(format::HandleId id) const                       { return MapObject<VkEvent>(id, &event_map_); }
    VkQueryPool                   MapVkQueryPool(format::HandleId id) const                   { return MapObject<VkQueryPool>(id, &query_pool_map_); }
    VkBufferView                  MapVkBufferView(format::HandleId id) const                  { return MapObject<VkBufferView>(id, &buffer_view_map_); }
    VkImageView                   MapVkImageView(format::HandleId id) const                   { return MapObject<VkImageView>(id, &image_view_map_); }
    VkShaderModule                MapVkShaderModule(format::HandleId id) const                { return MapObject<VkShaderModule>(id, &shader_module_map_); }
    VkPipelineCache               MapVkPipelineCache(format::HandleId id) const               { return MapObject<VkPipelineCache>(id, &pipeline_cache_map_); }
    VkPipelineLayout              MapVkPipelineLayout(format::HandleId id) const              { return MapObject<VkPipelineLayout>(id, &pipeline_layout_map_); }
    VkRenderPass                  MapVkRenderPass(format::HandleId id) const                  { return MapObject<VkRenderPass>(id, &render_pass_map_); }
    VkPipeline                    MapVkPipeline(format::HandleId id) const                    { return MapObject<VkPipeline>(id, &pipeline_map_); }
    VkDescriptorSetLayout         MapVkDescriptorSetLayout(format::HandleId id) const         { return MapObject<VkDescriptorSetLayout>(id, &descriptor_set_layout_map_); }
    VkSampler                     MapVkSampler(format::HandleId id) const                     { return MapObject<VkSampler>(id, &sampler_map_); }
    VkDescriptorPool              MapVkDescriptorPool(format::HandleId id) const              { return MapObject<VkDescriptorPool>(id, &descriptor_pool_map_); }
    VkDescriptorSet               MapVkDescriptorSet(format::HandleId id) const               { return MapObject<VkDescriptorSet>(id, &descriptor_set_map_); }
    VkFramebuffer                 MapVkFramebuffer(format::HandleId id) const                 { return MapObject<VkFramebuffer>(id, &framebuffer_map_); }
    VkCommandPool                 MapVkCommandPool(format::HandleId id) const                 { return MapObject<VkCommandPool>(id, &command_pool_map_); }
    VkSamplerYcbcrConversion      MapVkSamplerYcbcrConversion(format::HandleId id) const      { return MapObject<VkSamplerYcbcrConversion>(id, &sampler_ycbcr_conversion_map_); }
    VkDescriptorUpdateTemplate    MapVkDescriptorUpdateTemplate(format::HandleId id) const    { return MapObject<VkDescriptorUpdateTemplate>(id, &descriptor_update_template_map_); }
    VkSurfaceKHR                  MapVkSurfaceKHR(format::HandleId id) const                  { return MapObject<VkSurfaceKHR>(id, &surface_khr_map_); }
    VkSwapchainKHR                MapVkSwapchainKHR(format::HandleId id) const                { return MapObject<VkSwapchainKHR>(id, &swapchain_khr_map_); }
    VkDisplayKHR                  MapVkDisplayKHR(format::HandleId id) const                  { return MapObject<VkDisplayKHR>(id, &display_khr_map_); }
    VkDisplayModeKHR              MapVkDisplayModeKHR(format::HandleId id) const              { return MapObject<VkDisplayModeKHR>(id, &display_mode_khr_map_); }
    VkDescriptorUpdateTemplateKHR MapVkDescriptorUpdateTemplateKHR(format::HandleId id) const { return MapObject<VkDescriptorUpdateTemplateKHR>(id, &descriptor_update_template_khr_map_); }
    VkSamplerYcbcrConversionKHR   MapVkSamplerYcbcrConversionKHR(format::HandleId id) const   { return MapObject<VkSamplerYcbcrConversionKHR>(id, &sampler_ycbcr_conversion_khr_map_); }
    VkDebugReportCallbackEXT      MapVkDebugReportCallbackEXT(format::HandleId id) const      { return MapObject<VkDebugReportCallbackEXT>(id, &debug_report_callback_ext_map_); }
    VkObjectTableNVX              MapVkObjectTableNVX(format::HandleId id) const              { return MapObject<VkObjectTableNVX>(id, &object_table_nvx_map_); }
    VkIndirectCommandsLayoutNVX   MapVkIndirectCommandsLayoutNVX(format::HandleId id) const   { return MapObject<VkIndirectCommandsLayoutNVX>(id, &indirect_commands_layout_nvx_map_); }
    VkDebugUtilsMessengerEXT      MapVkDebugUtilsMessengerEXT(format::HandleId id) const      { return MapObject<VkDebugUtilsMessengerEXT>(id, &debug_utils_messenger_ext_map_); }
    VkValidationCacheEXT          MapVkValidationCacheEXT(format::HandleId id) const          { return MapObject<VkValidationCacheEXT>(id, &validation_cache_ext_map_); }
    // clang-format on

  private:
    template <typename T>
    void AddObject(format::HandleId id, T handle, std::unordered_map<format::HandleId, T>* map)
    {
        assert(map != nullptr);

        if ((id != 0) && (handle != VK_NULL_HANDLE))
        {
            (*map)[id] = handle;
        }
    }

    template <typename T>
    T MapObject(format::HandleId id, const std::unordered_map<format::HandleId, T>* map) const
    {
        assert(map != nullptr);

        T handle = VK_NULL_HANDLE;

        if (id != 0)
        {
            const auto entry = map->find(id);

            if (entry != map->end())
            {
                handle = entry->second;
            }
            else
            {
                BRIMSTONE_LOG_WARNING("Failed to map handle for object id %" PRIx64, id);
            }
        }

        return handle;
    }

  private:
    std::unordered_map<format::HandleId, VkInstance>                    instance_map_;
    std::unordered_map<format::HandleId, VkPhysicalDevice>              physical_device_map_;
    std::unordered_map<format::HandleId, VkDevice>                      device_map_;
    std::unordered_map<format::HandleId, VkQueue>                       queue_map_;
    std::unordered_map<format::HandleId, VkSemaphore>                   semaphore_map_;
    std::unordered_map<format::HandleId, VkCommandBuffer>               command_buffer_map_;
    std::unordered_map<format::HandleId, VkFence>                       fence_map_;
    std::unordered_map<format::HandleId, VkDeviceMemory>                device_memory_map_;
    std::unordered_map<format::HandleId, VkBuffer>                      buffer_map_;
    std::unordered_map<format::HandleId, VkImage>                       image_map_;
    std::unordered_map<format::HandleId, VkEvent>                       event_map_;
    std::unordered_map<format::HandleId, VkQueryPool>                   query_pool_map_;
    std::unordered_map<format::HandleId, VkBufferView>                  buffer_view_map_;
    std::unordered_map<format::HandleId, VkImageView>                   image_view_map_;
    std::unordered_map<format::HandleId, VkShaderModule>                shader_module_map_;
    std::unordered_map<format::HandleId, VkPipelineCache>               pipeline_cache_map_;
    std::unordered_map<format::HandleId, VkPipelineLayout>              pipeline_layout_map_;
    std::unordered_map<format::HandleId, VkRenderPass>                  render_pass_map_;
    std::unordered_map<format::HandleId, VkPipeline>                    pipeline_map_;
    std::unordered_map<format::HandleId, VkDescriptorSetLayout>         descriptor_set_layout_map_;
    std::unordered_map<format::HandleId, VkSampler>                     sampler_map_;
    std::unordered_map<format::HandleId, VkDescriptorPool>              descriptor_pool_map_;
    std::unordered_map<format::HandleId, VkDescriptorSet>               descriptor_set_map_;
    std::unordered_map<format::HandleId, VkFramebuffer>                 framebuffer_map_;
    std::unordered_map<format::HandleId, VkCommandPool>                 command_pool_map_;
    std::unordered_map<format::HandleId, VkSamplerYcbcrConversion>      sampler_ycbcr_conversion_map_;
    std::unordered_map<format::HandleId, VkDescriptorUpdateTemplate>    descriptor_update_template_map_;
    std::unordered_map<format::HandleId, VkSurfaceKHR>                  surface_khr_map_;
    std::unordered_map<format::HandleId, VkSwapchainKHR>                swapchain_khr_map_;
    std::unordered_map<format::HandleId, VkDisplayKHR>                  display_khr_map_;
    std::unordered_map<format::HandleId, VkDisplayModeKHR>              display_mode_khr_map_;
    std::unordered_map<format::HandleId, VkDescriptorUpdateTemplateKHR> descriptor_update_template_khr_map_;
    std::unordered_map<format::HandleId, VkSamplerYcbcrConversionKHR>   sampler_ycbcr_conversion_khr_map_;
    std::unordered_map<format::HandleId, VkDebugReportCallbackEXT>      debug_report_callback_ext_map_;
    std::unordered_map<format::HandleId, VkObjectTableNVX>              object_table_nvx_map_;
    std::unordered_map<format::HandleId, VkIndirectCommandsLayoutNVX>   indirect_commands_layout_nvx_map_;
    std::unordered_map<format::HandleId, VkDebugUtilsMessengerEXT>      debug_utils_messenger_ext_map_;
    std::unordered_map<format::HandleId, VkValidationCacheEXT>          validation_cache_ext_map_;
};

BRIMSTONE_END_NAMESPACE(decode)
BRIMSTONE_END_NAMESPACE(brimstone)

#endif // BRIMSTONE_DECODE_VULKAN_OBJECT_MAPPER_H
