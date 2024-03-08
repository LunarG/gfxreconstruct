/*
** Copyright (c) 2020 LunarG, Inc.
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

#include "encode/vulkan_handle_wrapper_util.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

VulkanStateHandleTable state_handle_table_;

uint64_t GetVulkanWrappedId(uint64_t object, VkObjectType object_type)
{
    switch (object_type)
    {
        case VK_OBJECT_TYPE_INSTANCE:
            return GetVulkanWrappedId<vulkan_wrappers::InstanceWrapper>(format::FromHandleId<VkInstance>(object));
        case VK_OBJECT_TYPE_PHYSICAL_DEVICE:
            return GetVulkanWrappedId<vulkan_wrappers::PhysicalDeviceWrapper>(
                format::FromHandleId<VkPhysicalDevice>(object));
        case VK_OBJECT_TYPE_DEVICE:
            return GetVulkanWrappedId<vulkan_wrappers::DeviceWrapper>(format::FromHandleId<VkDevice>(object));
        case VK_OBJECT_TYPE_QUEUE:
            return GetVulkanWrappedId<vulkan_wrappers::QueueWrapper>(format::FromHandleId<VkQueue>(object));
        case VK_OBJECT_TYPE_SEMAPHORE:
            return GetVulkanWrappedId<vulkan_wrappers::SemaphoreWrapper>(format::FromHandleId<VkSemaphore>(object));
        case VK_OBJECT_TYPE_COMMAND_BUFFER:
            return GetVulkanWrappedId<vulkan_wrappers::CommandBufferWrapper>(
                format::FromHandleId<VkCommandBuffer>(object));
        case VK_OBJECT_TYPE_FENCE:
            return GetVulkanWrappedId<vulkan_wrappers::FenceWrapper>(format::FromHandleId<VkFence>(object));
        case VK_OBJECT_TYPE_DEVICE_MEMORY:
            return GetVulkanWrappedId<vulkan_wrappers::DeviceMemoryWrapper>(
                format::FromHandleId<VkDeviceMemory>(object));
        case VK_OBJECT_TYPE_BUFFER:
            return GetVulkanWrappedId<vulkan_wrappers::BufferWrapper>(format::FromHandleId<VkBuffer>(object));
        case VK_OBJECT_TYPE_IMAGE:
            return GetVulkanWrappedId<vulkan_wrappers::ImageWrapper>(format::FromHandleId<VkImage>(object));
        case VK_OBJECT_TYPE_EVENT:
            return GetVulkanWrappedId<vulkan_wrappers::EventWrapper>(format::FromHandleId<VkEvent>(object));
        case VK_OBJECT_TYPE_QUERY_POOL:
            return GetVulkanWrappedId<vulkan_wrappers::QueryPoolWrapper>(format::FromHandleId<VkQueryPool>(object));
        case VK_OBJECT_TYPE_BUFFER_VIEW:
            return GetVulkanWrappedId<vulkan_wrappers::BufferViewWrapper>(format::FromHandleId<VkBufferView>(object));
        case VK_OBJECT_TYPE_IMAGE_VIEW:
            return GetVulkanWrappedId<vulkan_wrappers::ImageViewWrapper>(format::FromHandleId<VkImageView>(object));
        case VK_OBJECT_TYPE_SHADER_MODULE:
            return GetVulkanWrappedId<vulkan_wrappers::ShaderModuleWrapper>(
                format::FromHandleId<VkShaderModule>(object));
        case VK_OBJECT_TYPE_PIPELINE_CACHE:
            return GetVulkanWrappedId<vulkan_wrappers::PipelineCacheWrapper>(
                format::FromHandleId<VkPipelineCache>(object));
        case VK_OBJECT_TYPE_PIPELINE_LAYOUT:
            return GetVulkanWrappedId<vulkan_wrappers::PipelineLayoutWrapper>(
                format::FromHandleId<VkPipelineLayout>(object));
        case VK_OBJECT_TYPE_RENDER_PASS:
            return GetVulkanWrappedId<vulkan_wrappers::RenderPassWrapper>(format::FromHandleId<VkRenderPass>(object));
        case VK_OBJECT_TYPE_PIPELINE:
            return GetVulkanWrappedId<vulkan_wrappers::PipelineWrapper>(format::FromHandleId<VkPipeline>(object));
        case VK_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT:
            return GetVulkanWrappedId<vulkan_wrappers::DescriptorSetLayoutWrapper>(
                format::FromHandleId<VkDescriptorSetLayout>(object));
        case VK_OBJECT_TYPE_SAMPLER:
            return GetVulkanWrappedId<vulkan_wrappers::SamplerWrapper>(format::FromHandleId<VkSampler>(object));
        case VK_OBJECT_TYPE_DESCRIPTOR_POOL:
            return GetVulkanWrappedId<vulkan_wrappers::DescriptorPoolWrapper>(
                format::FromHandleId<VkDescriptorPool>(object));
        case VK_OBJECT_TYPE_DESCRIPTOR_SET:
            return GetVulkanWrappedId<vulkan_wrappers::DescriptorSetWrapper>(
                format::FromHandleId<VkDescriptorSet>(object));
        case VK_OBJECT_TYPE_FRAMEBUFFER:
            return GetVulkanWrappedId<vulkan_wrappers::FramebufferWrapper>(format::FromHandleId<VkFramebuffer>(object));
        case VK_OBJECT_TYPE_COMMAND_POOL:
            return GetVulkanWrappedId<vulkan_wrappers::CommandPoolWrapper>(format::FromHandleId<VkCommandPool>(object));
        case VK_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION:
            return GetVulkanWrappedId<vulkan_wrappers::SamplerYcbcrConversionWrapper>(
                format::FromHandleId<VkSamplerYcbcrConversion>(object));
        case VK_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE:
            return GetVulkanWrappedId<vulkan_wrappers::DescriptorUpdateTemplateWrapper>(
                format::FromHandleId<VkDescriptorUpdateTemplate>(object));
        case VK_OBJECT_TYPE_SURFACE_KHR:
            return GetVulkanWrappedId<vulkan_wrappers::SurfaceKHRWrapper>(format::FromHandleId<VkSurfaceKHR>(object));
        case VK_OBJECT_TYPE_SWAPCHAIN_KHR:
            return GetVulkanWrappedId<vulkan_wrappers::SwapchainKHRWrapper>(
                format::FromHandleId<VkSwapchainKHR>(object));
        case VK_OBJECT_TYPE_DISPLAY_KHR:
            return GetVulkanWrappedId<vulkan_wrappers::DisplayKHRWrapper>(format::FromHandleId<VkDisplayKHR>(object));
        case VK_OBJECT_TYPE_DISPLAY_MODE_KHR:
            return GetVulkanWrappedId<vulkan_wrappers::DisplayModeKHRWrapper>(
                format::FromHandleId<VkDisplayModeKHR>(object));
        case VK_OBJECT_TYPE_DEBUG_REPORT_CALLBACK_EXT:
            return GetVulkanWrappedId<vulkan_wrappers::DebugReportCallbackEXTWrapper>(
                format::FromHandleId<VkDebugReportCallbackEXT>(object));
        case VK_OBJECT_TYPE_DEBUG_UTILS_MESSENGER_EXT:
            return GetVulkanWrappedId<vulkan_wrappers::DebugUtilsMessengerEXTWrapper>(
                format::FromHandleId<VkDebugUtilsMessengerEXT>(object));
        case VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_KHR:
            return GetVulkanWrappedId<vulkan_wrappers::AccelerationStructureKHRWrapper>(
                format::FromHandleId<VkAccelerationStructureKHR>(object));
        case VK_OBJECT_TYPE_VALIDATION_CACHE_EXT:
            return GetVulkanWrappedId<vulkan_wrappers::ValidationCacheEXTWrapper>(
                format::FromHandleId<VkValidationCacheEXT>(object));
        case VK_OBJECT_TYPE_PERFORMANCE_CONFIGURATION_INTEL:
            return GetVulkanWrappedId<vulkan_wrappers::PerformanceConfigurationINTELWrapper>(
                format::FromHandleId<VkPerformanceConfigurationINTEL>(object));
        case VK_OBJECT_TYPE_DEFERRED_OPERATION_KHR:
            return GetVulkanWrappedId<vulkan_wrappers::DeferredOperationKHRWrapper>(
                format::FromHandleId<VkDeferredOperationKHR>(object));
        case VK_OBJECT_TYPE_INDIRECT_COMMANDS_LAYOUT_NV:
            return GetVulkanWrappedId<vulkan_wrappers::IndirectCommandsLayoutNVWrapper>(
                format::FromHandleId<VkIndirectCommandsLayoutNV>(object));
        case VK_OBJECT_TYPE_PRIVATE_DATA_SLOT_EXT:
            return GetVulkanWrappedId<vulkan_wrappers::PrivateDataSlotEXTWrapper>(
                format::FromHandleId<VkPrivateDataSlotEXT>(object));
        case VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_NV:
            return GetVulkanWrappedId<vulkan_wrappers::AccelerationStructureNVWrapper>(
                format::FromHandleId<VkAccelerationStructureNV>(object));
        case VK_OBJECT_TYPE_UNKNOWN:
            // No conversion will be performed for unknown objects.
            GFXRECON_LOG_WARNING("Skipping handle unwrapping for unknown debug marker object type.");
            return object;
        default:
            GFXRECON_LOG_WARNING("Skipping handle unwrapping for unrecognized debug marker object type %d",
                                 object_type);
            return object;
    }
}

uint64_t GetVulkanWrappedId(uint64_t object, VkDebugReportObjectTypeEXT object_type)
{
    switch (object_type)
    {
        case VK_DEBUG_REPORT_OBJECT_TYPE_INSTANCE_EXT:
            return GetVulkanWrappedId<vulkan_wrappers::InstanceWrapper>(format::FromHandleId<VkInstance>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_PHYSICAL_DEVICE_EXT:
            return GetVulkanWrappedId<vulkan_wrappers::PhysicalDeviceWrapper>(
                format::FromHandleId<VkPhysicalDevice>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_DEVICE_EXT:
            return GetVulkanWrappedId<vulkan_wrappers::DeviceWrapper>(format::FromHandleId<VkDevice>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_QUEUE_EXT:
            return GetVulkanWrappedId<vulkan_wrappers::QueueWrapper>(format::FromHandleId<VkQueue>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_SEMAPHORE_EXT:
            return GetVulkanWrappedId<vulkan_wrappers::SemaphoreWrapper>(format::FromHandleId<VkSemaphore>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_COMMAND_BUFFER_EXT:
            return GetVulkanWrappedId<vulkan_wrappers::CommandBufferWrapper>(
                format::FromHandleId<VkCommandBuffer>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_FENCE_EXT:
            return GetVulkanWrappedId<vulkan_wrappers::FenceWrapper>(format::FromHandleId<VkFence>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_DEVICE_MEMORY_EXT:
            return GetVulkanWrappedId<vulkan_wrappers::DeviceMemoryWrapper>(
                format::FromHandleId<VkDeviceMemory>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_BUFFER_EXT:
            return GetVulkanWrappedId<vulkan_wrappers::BufferWrapper>(format::FromHandleId<VkBuffer>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_IMAGE_EXT:
            return GetVulkanWrappedId<vulkan_wrappers::ImageWrapper>(format::FromHandleId<VkImage>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_EVENT_EXT:
            return GetVulkanWrappedId<vulkan_wrappers::EventWrapper>(format::FromHandleId<VkEvent>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_QUERY_POOL_EXT:
            return GetVulkanWrappedId<vulkan_wrappers::QueryPoolWrapper>(format::FromHandleId<VkQueryPool>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_BUFFER_VIEW_EXT:
            return GetVulkanWrappedId<vulkan_wrappers::BufferViewWrapper>(format::FromHandleId<VkBufferView>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_IMAGE_VIEW_EXT:
            return GetVulkanWrappedId<vulkan_wrappers::ImageViewWrapper>(format::FromHandleId<VkImageView>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_SHADER_MODULE_EXT:
            return GetVulkanWrappedId<vulkan_wrappers::ShaderModuleWrapper>(
                format::FromHandleId<VkShaderModule>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_CACHE_EXT:
            return GetVulkanWrappedId<vulkan_wrappers::PipelineCacheWrapper>(
                format::FromHandleId<VkPipelineCache>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_LAYOUT_EXT:
            return GetVulkanWrappedId<vulkan_wrappers::PipelineLayoutWrapper>(
                format::FromHandleId<VkPipelineLayout>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_RENDER_PASS_EXT:
            return GetVulkanWrappedId<vulkan_wrappers::RenderPassWrapper>(format::FromHandleId<VkRenderPass>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_EXT:
            return GetVulkanWrappedId<vulkan_wrappers::PipelineWrapper>(format::FromHandleId<VkPipeline>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT_EXT:
            return GetVulkanWrappedId<vulkan_wrappers::DescriptorSetLayoutWrapper>(
                format::FromHandleId<VkDescriptorSetLayout>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_SAMPLER_EXT:
            return GetVulkanWrappedId<vulkan_wrappers::SamplerWrapper>(format::FromHandleId<VkSampler>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_POOL_EXT:
            return GetVulkanWrappedId<vulkan_wrappers::DescriptorPoolWrapper>(
                format::FromHandleId<VkDescriptorPool>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_SET_EXT:
            return GetVulkanWrappedId<vulkan_wrappers::DescriptorSetWrapper>(
                format::FromHandleId<VkDescriptorSet>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_FRAMEBUFFER_EXT:
            return GetVulkanWrappedId<vulkan_wrappers::FramebufferWrapper>(format::FromHandleId<VkFramebuffer>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_COMMAND_POOL_EXT:
            return GetVulkanWrappedId<vulkan_wrappers::CommandPoolWrapper>(format::FromHandleId<VkCommandPool>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_SURFACE_KHR_EXT:
            return GetVulkanWrappedId<vulkan_wrappers::SurfaceKHRWrapper>(format::FromHandleId<VkSurfaceKHR>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_SWAPCHAIN_KHR_EXT:
            return GetVulkanWrappedId<vulkan_wrappers::SwapchainKHRWrapper>(
                format::FromHandleId<VkSwapchainKHR>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_DEBUG_REPORT_CALLBACK_EXT_EXT:
            return GetVulkanWrappedId<vulkan_wrappers::DebugReportCallbackEXTWrapper>(
                format::FromHandleId<VkDebugReportCallbackEXT>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_DISPLAY_KHR_EXT:
            return GetVulkanWrappedId<vulkan_wrappers::DisplayKHRWrapper>(format::FromHandleId<VkDisplayKHR>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_DISPLAY_MODE_KHR_EXT:
            return GetVulkanWrappedId<vulkan_wrappers::DisplayModeKHRWrapper>(
                format::FromHandleId<VkDisplayModeKHR>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_VALIDATION_CACHE_EXT_EXT:
            return GetVulkanWrappedId<vulkan_wrappers::ValidationCacheEXTWrapper>(
                format::FromHandleId<VkValidationCacheEXT>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION_EXT:
            return GetVulkanWrappedId<vulkan_wrappers::SamplerYcbcrConversionWrapper>(
                format::FromHandleId<VkSamplerYcbcrConversion>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_EXT:
            return GetVulkanWrappedId<vulkan_wrappers::DescriptorUpdateTemplateWrapper>(
                format::FromHandleId<VkDescriptorUpdateTemplate>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_ACCELERATION_STRUCTURE_KHR_EXT:
            return GetVulkanWrappedId<vulkan_wrappers::AccelerationStructureKHRWrapper>(
                format::FromHandleId<VkAccelerationStructureKHR>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_ACCELERATION_STRUCTURE_NV_EXT:
            return GetVulkanWrappedId<vulkan_wrappers::AccelerationStructureNVWrapper>(
                format::FromHandleId<VkAccelerationStructureNV>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_UNKNOWN_EXT:
            // No conversion will be performed for unknown objects.
            GFXRECON_LOG_WARNING("Skipping handle unwrapping for unknown debug marker object type.");
            return object;
        default:
            GFXRECON_LOG_WARNING("Skipping handle unwrapping for unrecognized debug marker object type %d",
                                 object_type);
            return object;
    }
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
