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

#ifndef BRIMSTONE_VULKAN_OBJECT_MAPPER_H
#define BRIMSTONE_VULKAN_OBJECT_MAPPER_H

#include <cassert>
#include <unordered_map>

#include "vulkan/vulkan.h"

#include "util/defines.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(format)

class VulkanObjectMapper
{
  public:
    void AddVkInstance(HandleId id, VkInstance handle) { AddObject<VkInstance>(id, handle, &instance_map_); }
    void AddVkPhysicalDevice(HandleId id, VkPhysicalDevice handle)
    {
        AddObject<VkPhysicalDevice>(id, handle, &physical_device_map_);
    }
    void AddVkDevice(HandleId id, VkDevice handle) { AddObject<VkDevice>(id, handle, &device_map_); }
    void AddVkQueue(HandleId id, VkQueue handle) { AddObject<VkQueue>(id, handle, &queue_map_); }
    void AddVkSemaphore(HandleId id, VkSemaphore handle) { AddObject<VkSemaphore>(id, handle, &semaphore_map_); }
    void AddVkCommandBuffer(HandleId id, VkCommandBuffer handle)
    {
        AddObject<VkCommandBuffer>(id, handle, &command_buffer_map_);
    }
    void AddVkFence(HandleId id, VkFence handle) { AddObject<VkFence>(id, handle, &fence_map_); }
    void AddVkDeviceMemory(HandleId id, VkDeviceMemory handle)
    {
        AddObject<VkDeviceMemory>(id, handle, &device_memory_map_);
    }
    void AddVkBuffer(HandleId id, VkBuffer handle) { AddObject<VkBuffer>(id, handle, &buffer_map_); }
    void AddVkImage(HandleId id, VkImage handle) { AddObject<VkImage>(id, handle, &image_map_); }
    void AddVkEvent(HandleId id, VkEvent handle) { AddObject<VkEvent>(id, handle, &event_map_); }
    void AddVkQueryPool(HandleId id, VkQueryPool handle) { AddObject<VkQueryPool>(id, handle, &query_pool_map_); }
    void AddVkBufferView(HandleId id, VkBufferView handle) { AddObject<VkBufferView>(id, handle, &buffer_view_map_); }
    void AddVkImageView(HandleId id, VkImageView handle) { AddObject<VkImageView>(id, handle, &image_view_map_); }
    void AddVkShaderModule(HandleId id, VkShaderModule handle)
    {
        AddObject<VkShaderModule>(id, handle, &shader_module_map_);
    }
    void AddVkPipelineCache(HandleId id, VkPipelineCache handle)
    {
        AddObject<VkPipelineCache>(id, handle, &pipeline_cache_map_);
    }
    void AddVkPipelineLayout(HandleId id, VkPipelineLayout handle)
    {
        AddObject<VkPipelineLayout>(id, handle, &pipeline_layout_map_);
    }
    void AddVkRenderPass(HandleId id, VkRenderPass handle) { AddObject<VkRenderPass>(id, handle, &render_pass_map_); }
    void AddVkPipeline(HandleId id, VkPipeline handle) { AddObject<VkPipeline>(id, handle, &pipeline_map_); }
    void AddVkDescriptorSetLayout(HandleId id, VkDescriptorSetLayout handle)
    {
        AddObject<VkDescriptorSetLayout>(id, handle, &descriptor_set_layout_map_);
    }
    void AddVkSampler(HandleId id, VkSampler handle) { AddObject<VkSampler>(id, handle, &sampler_map_); }
    void AddVkDescriptorPool(HandleId id, VkDescriptorPool handle)
    {
        AddObject<VkDescriptorPool>(id, handle, &descriptor_pool_map_);
    }
    void AddVkDescriptorSet(HandleId id, VkDescriptorSet handle)
    {
        AddObject<VkDescriptorSet>(id, handle, &descriptor_set_map_);
    }
    void AddVkFramebuffer(HandleId id, VkFramebuffer handle)
    {
        AddObject<VkFramebuffer>(id, handle, &framebuffer_map_);
    }
    void AddVkCommandPool(HandleId id, VkCommandPool handle)
    {
        AddObject<VkCommandPool>(id, handle, &command_pool_map_);
    }
    void AddVkSamplerYcbcrConversion(HandleId id, VkSamplerYcbcrConversion handle)
    {
        AddObject<VkSamplerYcbcrConversion>(id, handle, &sampler_ycbcr_conversion_map_);
    }
    void AddVkDescriptorUpdateTemplate(HandleId id, VkDescriptorUpdateTemplate handle)
    {
        AddObject<VkDescriptorUpdateTemplate>(id, handle, &descriptor_update_template_map_);
    }
    void AddVkSurfaceKHR(HandleId id, VkSurfaceKHR handle) { AddObject<VkSurfaceKHR>(id, handle, &surface_khr_map_); }
    void AddVkSwapchainKHR(HandleId id, VkSwapchainKHR handle)
    {
        AddObject<VkSwapchainKHR>(id, handle, &swapchain_khr_map_);
    }
    void AddVkDisplayKHR(HandleId id, VkDisplayKHR handle) { AddObject<VkDisplayKHR>(id, handle, &display_khr_map_); }
    void AddVkDisplayModeKHR(HandleId id, VkDisplayModeKHR handle)
    {
        AddObject<VkDisplayModeKHR>(id, handle, &display_mode_khr_map_);
    }
    void AddVkDescriptorUpdateTemplateKHR(HandleId id, VkDescriptorUpdateTemplateKHR handle)
    {
        AddObject<VkDescriptorUpdateTemplateKHR>(id, handle, &descriptor_update_template_khr_map_);
    }
    void AddVkSamplerYcbcrConversionKHR(HandleId id, VkSamplerYcbcrConversionKHR handle)
    {
        AddObject<VkSamplerYcbcrConversionKHR>(id, handle, &sampler_ycbcr_conversion_khr_map_);
    }
    void AddVkDebugReportCallbackEXT(HandleId id, VkDebugReportCallbackEXT handle)
    {
        AddObject<VkDebugReportCallbackEXT>(id, handle, &debug_report_callback_ext_map_);
    }
    void AddVkObjectTableNVX(HandleId id, VkObjectTableNVX handle)
    {
        AddObject<VkObjectTableNVX>(id, handle, &object_table_nvx_map_);
    }
    void AddVkIndirectCommandsLayoutNVX(HandleId id, VkIndirectCommandsLayoutNVX handle)
    {
        AddObject<VkIndirectCommandsLayoutNVX>(id, handle, &indirect_commands_layout_nvx_map_);
    }
    void AddVkDebugUtilsMessengerEXT(HandleId id, VkDebugUtilsMessengerEXT handle)
    {
        AddObject<VkDebugUtilsMessengerEXT>(id, handle, &debug_utils_messenger_ext_map_);
    }
    void AddVkValidationCacheEXT(HandleId id, VkValidationCacheEXT handle)
    {
        AddObject<VkValidationCacheEXT>(id, handle, &validation_cache_ext_map_);
    }

    VkInstance MapVkInstance(HandleId id) const { return MapObject<VkInstance>(id, &instance_map_); }
    VkPhysicalDevice MapVkPhysicalDevice(HandleId id) const
    {
        return MapObject<VkPhysicalDevice>(id, &physical_device_map_);
    }
    VkDevice        MapVkDevice(HandleId id) const { return MapObject<VkDevice>(id, &device_map_); }
    VkQueue         MapVkQueue(HandleId id) const { return MapObject<VkQueue>(id, &queue_map_); }
    VkSemaphore     MapVkSemaphore(HandleId id) const { return MapObject<VkSemaphore>(id, &semaphore_map_); }
    VkCommandBuffer MapVkCommandBuffer(HandleId id) const
    {
        return MapObject<VkCommandBuffer>(id, &command_buffer_map_);
    }
    VkFence         MapVkFence(HandleId id) const { return MapObject<VkFence>(id, &fence_map_); }
    VkDeviceMemory  MapVkDeviceMemory(HandleId id) const { return MapObject<VkDeviceMemory>(id, &device_memory_map_); }
    VkBuffer        MapVkBuffer(HandleId id) const { return MapObject<VkBuffer>(id, &buffer_map_); }
    VkImage         MapVkImage(HandleId id) const { return MapObject<VkImage>(id, &image_map_); }
    VkEvent         MapVkEvent(HandleId id) const { return MapObject<VkEvent>(id, &event_map_); }
    VkQueryPool     MapVkQueryPool(HandleId id) const { return MapObject<VkQueryPool>(id, &query_pool_map_); }
    VkBufferView    MapVkBufferView(HandleId id) const { return MapObject<VkBufferView>(id, &buffer_view_map_); }
    VkImageView     MapVkImageView(HandleId id) const { return MapObject<VkImageView>(id, &image_view_map_); }
    VkShaderModule  MapVkShaderModule(HandleId id) const { return MapObject<VkShaderModule>(id, &shader_module_map_); }
    VkPipelineCache MapVkPipelineCache(HandleId id) const
    {
        return MapObject<VkPipelineCache>(id, &pipeline_cache_map_);
    }
    VkPipelineLayout MapVkPipelineLayout(HandleId id) const
    {
        return MapObject<VkPipelineLayout>(id, &pipeline_layout_map_);
    }
    VkRenderPass          MapVkRenderPass(HandleId id) const { return MapObject<VkRenderPass>(id, &render_pass_map_); }
    VkPipeline            MapVkPipeline(HandleId id) const { return MapObject<VkPipeline>(id, &pipeline_map_); }
    VkDescriptorSetLayout MapVkDescriptorSetLayout(HandleId id) const
    {
        return MapObject<VkDescriptorSetLayout>(id, &descriptor_set_layout_map_);
    }
    VkSampler        MapVkSampler(HandleId id) const { return MapObject<VkSampler>(id, &sampler_map_); }
    VkDescriptorPool MapVkDescriptorPool(HandleId id) const
    {
        return MapObject<VkDescriptorPool>(id, &descriptor_pool_map_);
    }
    VkDescriptorSet MapVkDescriptorSet(HandleId id) const
    {
        return MapObject<VkDescriptorSet>(id, &descriptor_set_map_);
    }
    VkFramebuffer MapVkFramebuffer(HandleId id) const { return MapObject<VkFramebuffer>(id, &framebuffer_map_); }
    VkCommandPool MapVkCommandPool(HandleId id) const { return MapObject<VkCommandPool>(id, &command_pool_map_); }
    VkSamplerYcbcrConversion MapVkSamplerYcbcrConversion(HandleId id) const
    {
        return MapObject<VkSamplerYcbcrConversion>(id, &sampler_ycbcr_conversion_map_);
    }
    VkDescriptorUpdateTemplate MapVkDescriptorUpdateTemplate(HandleId id) const
    {
        return MapObject<VkDescriptorUpdateTemplate>(id, &descriptor_update_template_map_);
    }
    VkSurfaceKHR   MapVkSurfaceKHR(HandleId id) const { return MapObject<VkSurfaceKHR>(id, &surface_khr_map_); }
    VkSwapchainKHR MapVkSwapchainKHR(HandleId id) const { return MapObject<VkSwapchainKHR>(id, &swapchain_khr_map_); }
    VkDisplayKHR   MapVkDisplayKHR(HandleId id) const { return MapObject<VkDisplayKHR>(id, &display_khr_map_); }
    VkDisplayModeKHR MapVkDisplayModeKHR(HandleId id) const
    {
        return MapObject<VkDisplayModeKHR>(id, &display_mode_khr_map_);
    }
    VkDescriptorUpdateTemplateKHR MapVkDescriptorUpdateTemplateKHR(HandleId id) const
    {
        return MapObject<VkDescriptorUpdateTemplateKHR>(id, &descriptor_update_template_khr_map_);
    }
    VkSamplerYcbcrConversionKHR MapVkSamplerYcbcrConversionKHR(HandleId id) const
    {
        return MapObject<VkSamplerYcbcrConversionKHR>(id, &sampler_ycbcr_conversion_khr_map_);
    }
    VkDebugReportCallbackEXT MapVkDebugReportCallbackEXT(HandleId id) const
    {
        return MapObject<VkDebugReportCallbackEXT>(id, &debug_report_callback_ext_map_);
    }
    VkObjectTableNVX MapVkObjectTableNVX(HandleId id) const
    {
        return MapObject<VkObjectTableNVX>(id, &object_table_nvx_map_);
    }
    VkIndirectCommandsLayoutNVX MapVkIndirectCommandsLayoutNVX(HandleId id) const
    {
        return MapObject<VkIndirectCommandsLayoutNVX>(id, &indirect_commands_layout_nvx_map_);
    }
    VkDebugUtilsMessengerEXT MapVkDebugUtilsMessengerEXT(HandleId id) const
    {
        return MapObject<VkDebugUtilsMessengerEXT>(id, &debug_utils_messenger_ext_map_);
    }
    VkValidationCacheEXT MapVkValidationCacheEXT(HandleId id) const
    {
        return MapObject<VkValidationCacheEXT>(id, &validation_cache_ext_map_);
    }

  private:
    template <typename T>
    void AddObject(HandleId id, T handle, std::unordered_map<HandleId, T>* map)
    {
        assert(map != nullptr);

        if ((id != 0) && (handle != VK_NULL_HANDLE))
        {
            (*map)[id] = handle;
        }
    }

    template <typename T>
    T MapObject(HandleId id, const std::unordered_map<HandleId, T>* map) const
    {
        assert(map != nullptr);

        const auto entry = map->find(id);
        return (entry != map->end()) ? entry->second : VK_NULL_HANDLE;
    }

  private:
    std::unordered_map<HandleId, VkInstance>                    instance_map_;
    std::unordered_map<HandleId, VkPhysicalDevice>              physical_device_map_;
    std::unordered_map<HandleId, VkDevice>                      device_map_;
    std::unordered_map<HandleId, VkQueue>                       queue_map_;
    std::unordered_map<HandleId, VkSemaphore>                   semaphore_map_;
    std::unordered_map<HandleId, VkCommandBuffer>               command_buffer_map_;
    std::unordered_map<HandleId, VkFence>                       fence_map_;
    std::unordered_map<HandleId, VkDeviceMemory>                device_memory_map_;
    std::unordered_map<HandleId, VkBuffer>                      buffer_map_;
    std::unordered_map<HandleId, VkImage>                       image_map_;
    std::unordered_map<HandleId, VkEvent>                       event_map_;
    std::unordered_map<HandleId, VkQueryPool>                   query_pool_map_;
    std::unordered_map<HandleId, VkBufferView>                  buffer_view_map_;
    std::unordered_map<HandleId, VkImageView>                   image_view_map_;
    std::unordered_map<HandleId, VkShaderModule>                shader_module_map_;
    std::unordered_map<HandleId, VkPipelineCache>               pipeline_cache_map_;
    std::unordered_map<HandleId, VkPipelineLayout>              pipeline_layout_map_;
    std::unordered_map<HandleId, VkRenderPass>                  render_pass_map_;
    std::unordered_map<HandleId, VkPipeline>                    pipeline_map_;
    std::unordered_map<HandleId, VkDescriptorSetLayout>         descriptor_set_layout_map_;
    std::unordered_map<HandleId, VkSampler>                     sampler_map_;
    std::unordered_map<HandleId, VkDescriptorPool>              descriptor_pool_map_;
    std::unordered_map<HandleId, VkDescriptorSet>               descriptor_set_map_;
    std::unordered_map<HandleId, VkFramebuffer>                 framebuffer_map_;
    std::unordered_map<HandleId, VkCommandPool>                 command_pool_map_;
    std::unordered_map<HandleId, VkSamplerYcbcrConversion>      sampler_ycbcr_conversion_map_;
    std::unordered_map<HandleId, VkDescriptorUpdateTemplate>    descriptor_update_template_map_;
    std::unordered_map<HandleId, VkSurfaceKHR>                  surface_khr_map_;
    std::unordered_map<HandleId, VkSwapchainKHR>                swapchain_khr_map_;
    std::unordered_map<HandleId, VkDisplayKHR>                  display_khr_map_;
    std::unordered_map<HandleId, VkDisplayModeKHR>              display_mode_khr_map_;
    std::unordered_map<HandleId, VkDescriptorUpdateTemplateKHR> descriptor_update_template_khr_map_;
    std::unordered_map<HandleId, VkSamplerYcbcrConversionKHR>   sampler_ycbcr_conversion_khr_map_;
    std::unordered_map<HandleId, VkDebugReportCallbackEXT>      debug_report_callback_ext_map_;
    std::unordered_map<HandleId, VkObjectTableNVX>              object_table_nvx_map_;
    std::unordered_map<HandleId, VkIndirectCommandsLayoutNVX>   indirect_commands_layout_nvx_map_;
    std::unordered_map<HandleId, VkDebugUtilsMessengerEXT>      debug_utils_messenger_ext_map_;
    std::unordered_map<HandleId, VkValidationCacheEXT>          validation_cache_ext_map_;
};

BRIMSTONE_END_NAMESPACE(format)
BRIMSTONE_END_NAMESPACE(brimstone)

#endif // BRIMSTONE_VULKAN_OBJECT_MAPPER_H
