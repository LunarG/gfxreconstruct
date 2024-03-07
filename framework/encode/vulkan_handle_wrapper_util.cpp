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

uint64_t GetWrappedId(uint64_t object, VkObjectType object_type)
{
    switch (object_type)
    {
        case VK_OBJECT_TYPE_INSTANCE:
            return GetWrappedId<VulkanInstanceWrapper>(format::FromHandleId<VkInstance>(object));
        case VK_OBJECT_TYPE_PHYSICAL_DEVICE:
            return GetWrappedId<VulkanPhysicalDeviceWrapper>(format::FromHandleId<VkPhysicalDevice>(object));
        case VK_OBJECT_TYPE_DEVICE:
            return GetWrappedId<VulkanDeviceWrapper>(format::FromHandleId<VkDevice>(object));
        case VK_OBJECT_TYPE_QUEUE:
            return GetWrappedId<VulkanQueueWrapper>(format::FromHandleId<VkQueue>(object));
        case VK_OBJECT_TYPE_SEMAPHORE:
            return GetWrappedId<VulkanSemaphoreWrapper>(format::FromHandleId<VkSemaphore>(object));
        case VK_OBJECT_TYPE_COMMAND_BUFFER:
            return GetWrappedId<VulkanCommandBufferWrapper>(format::FromHandleId<VkCommandBuffer>(object));
        case VK_OBJECT_TYPE_FENCE:
            return GetWrappedId<VulkanFenceWrapper>(format::FromHandleId<VkFence>(object));
        case VK_OBJECT_TYPE_DEVICE_MEMORY:
            return GetWrappedId<VulkanDeviceMemoryWrapper>(format::FromHandleId<VkDeviceMemory>(object));
        case VK_OBJECT_TYPE_BUFFER:
            return GetWrappedId<VulkanBufferWrapper>(format::FromHandleId<VkBuffer>(object));
        case VK_OBJECT_TYPE_IMAGE:
            return GetWrappedId<VulkanImageWrapper>(format::FromHandleId<VkImage>(object));
        case VK_OBJECT_TYPE_EVENT:
            return GetWrappedId<VulkanEventWrapper>(format::FromHandleId<VkEvent>(object));
        case VK_OBJECT_TYPE_QUERY_POOL:
            return GetWrappedId<VulkanQueryPoolWrapper>(format::FromHandleId<VkQueryPool>(object));
        case VK_OBJECT_TYPE_BUFFER_VIEW:
            return GetWrappedId<VulkanBufferViewWrapper>(format::FromHandleId<VkBufferView>(object));
        case VK_OBJECT_TYPE_IMAGE_VIEW:
            return GetWrappedId<VulkanImageViewWrapper>(format::FromHandleId<VkImageView>(object));
        case VK_OBJECT_TYPE_SHADER_MODULE:
            return GetWrappedId<VulkanShaderModuleWrapper>(format::FromHandleId<VkShaderModule>(object));
        case VK_OBJECT_TYPE_PIPELINE_CACHE:
            return GetWrappedId<VulkanPipelineCacheWrapper>(format::FromHandleId<VkPipelineCache>(object));
        case VK_OBJECT_TYPE_PIPELINE_LAYOUT:
            return GetWrappedId<VulkanPipelineLayoutWrapper>(format::FromHandleId<VkPipelineLayout>(object));
        case VK_OBJECT_TYPE_RENDER_PASS:
            return GetWrappedId<VulkanRenderPassWrapper>(format::FromHandleId<VkRenderPass>(object));
        case VK_OBJECT_TYPE_PIPELINE:
            return GetWrappedId<VulkanPipelineWrapper>(format::FromHandleId<VkPipeline>(object));
        case VK_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT:
            return GetWrappedId<VulkanDescriptorSetLayoutWrapper>(format::FromHandleId<VkDescriptorSetLayout>(object));
        case VK_OBJECT_TYPE_SAMPLER:
            return GetWrappedId<VulkanSamplerWrapper>(format::FromHandleId<VkSampler>(object));
        case VK_OBJECT_TYPE_DESCRIPTOR_POOL:
            return GetWrappedId<VulkanDescriptorPoolWrapper>(format::FromHandleId<VkDescriptorPool>(object));
        case VK_OBJECT_TYPE_DESCRIPTOR_SET:
            return GetWrappedId<VulkanDescriptorSetWrapper>(format::FromHandleId<VkDescriptorSet>(object));
        case VK_OBJECT_TYPE_FRAMEBUFFER:
            return GetWrappedId<VulkanFramebufferWrapper>(format::FromHandleId<VkFramebuffer>(object));
        case VK_OBJECT_TYPE_COMMAND_POOL:
            return GetWrappedId<VulkanCommandPoolWrapper>(format::FromHandleId<VkCommandPool>(object));
        case VK_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION:
            return GetWrappedId<VulkanSamplerYcbcrConversionWrapper>(
                format::FromHandleId<VkSamplerYcbcrConversion>(object));
        case VK_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE:
            return GetWrappedId<VulkanDescriptorUpdateTemplateWrapper>(
                format::FromHandleId<VkDescriptorUpdateTemplate>(object));
        case VK_OBJECT_TYPE_SURFACE_KHR:
            return GetWrappedId<VulkanSurfaceKHRWrapper>(format::FromHandleId<VkSurfaceKHR>(object));
        case VK_OBJECT_TYPE_SWAPCHAIN_KHR:
            return GetWrappedId<VulkanSwapchainKHRWrapper>(format::FromHandleId<VkSwapchainKHR>(object));
        case VK_OBJECT_TYPE_DISPLAY_KHR:
            return GetWrappedId<VulkanDisplayKHRWrapper>(format::FromHandleId<VkDisplayKHR>(object));
        case VK_OBJECT_TYPE_DISPLAY_MODE_KHR:
            return GetWrappedId<VulkanDisplayModeKHRWrapper>(format::FromHandleId<VkDisplayModeKHR>(object));
        case VK_OBJECT_TYPE_DEBUG_REPORT_CALLBACK_EXT:
            return GetWrappedId<VulkanDebugReportCallbackEXTWrapper>(
                format::FromHandleId<VkDebugReportCallbackEXT>(object));
        case VK_OBJECT_TYPE_DEBUG_UTILS_MESSENGER_EXT:
            return GetWrappedId<VulkanDebugUtilsMessengerEXTWrapper>(
                format::FromHandleId<VkDebugUtilsMessengerEXT>(object));
        case VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_KHR:
            return GetWrappedId<VulkanAccelerationStructureKHRWrapper>(
                format::FromHandleId<VkAccelerationStructureKHR>(object));
        case VK_OBJECT_TYPE_VALIDATION_CACHE_EXT:
            return GetWrappedId<VulkanValidationCacheEXTWrapper>(format::FromHandleId<VkValidationCacheEXT>(object));
        case VK_OBJECT_TYPE_PERFORMANCE_CONFIGURATION_INTEL:
            return GetWrappedId<VulkanPerformanceConfigurationINTELWrapper>(
                format::FromHandleId<VkPerformanceConfigurationINTEL>(object));
        case VK_OBJECT_TYPE_DEFERRED_OPERATION_KHR:
            return GetWrappedId<VulkanDeferredOperationKHRWrapper>(
                format::FromHandleId<VkDeferredOperationKHR>(object));
        case VK_OBJECT_TYPE_INDIRECT_COMMANDS_LAYOUT_NV:
            return GetWrappedId<VulkanIndirectCommandsLayoutNVWrapper>(
                format::FromHandleId<VkIndirectCommandsLayoutNV>(object));
        case VK_OBJECT_TYPE_PRIVATE_DATA_SLOT_EXT:
            return GetWrappedId<VulkanPrivateDataSlotEXTWrapper>(format::FromHandleId<VkPrivateDataSlotEXT>(object));
        case VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_NV:
            return GetWrappedId<VulkanAccelerationStructureNVWrapper>(
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

uint64_t GetWrappedId(uint64_t object, VkDebugReportObjectTypeEXT object_type)
{
    switch (object_type)
    {
        case VK_DEBUG_REPORT_OBJECT_TYPE_INSTANCE_EXT:
            return GetWrappedId<VulkanInstanceWrapper>(format::FromHandleId<VkInstance>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_PHYSICAL_DEVICE_EXT:
            return GetWrappedId<VulkanPhysicalDeviceWrapper>(format::FromHandleId<VkPhysicalDevice>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_DEVICE_EXT:
            return GetWrappedId<VulkanDeviceWrapper>(format::FromHandleId<VkDevice>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_QUEUE_EXT:
            return GetWrappedId<VulkanQueueWrapper>(format::FromHandleId<VkQueue>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_SEMAPHORE_EXT:
            return GetWrappedId<VulkanSemaphoreWrapper>(format::FromHandleId<VkSemaphore>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_COMMAND_BUFFER_EXT:
            return GetWrappedId<VulkanCommandBufferWrapper>(format::FromHandleId<VkCommandBuffer>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_FENCE_EXT:
            return GetWrappedId<VulkanFenceWrapper>(format::FromHandleId<VkFence>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_DEVICE_MEMORY_EXT:
            return GetWrappedId<VulkanDeviceMemoryWrapper>(format::FromHandleId<VkDeviceMemory>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_BUFFER_EXT:
            return GetWrappedId<VulkanBufferWrapper>(format::FromHandleId<VkBuffer>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_IMAGE_EXT:
            return GetWrappedId<VulkanImageWrapper>(format::FromHandleId<VkImage>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_EVENT_EXT:
            return GetWrappedId<VulkanEventWrapper>(format::FromHandleId<VkEvent>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_QUERY_POOL_EXT:
            return GetWrappedId<VulkanQueryPoolWrapper>(format::FromHandleId<VkQueryPool>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_BUFFER_VIEW_EXT:
            return GetWrappedId<VulkanBufferViewWrapper>(format::FromHandleId<VkBufferView>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_IMAGE_VIEW_EXT:
            return GetWrappedId<VulkanImageViewWrapper>(format::FromHandleId<VkImageView>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_SHADER_MODULE_EXT:
            return GetWrappedId<VulkanShaderModuleWrapper>(format::FromHandleId<VkShaderModule>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_CACHE_EXT:
            return GetWrappedId<VulkanPipelineCacheWrapper>(format::FromHandleId<VkPipelineCache>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_LAYOUT_EXT:
            return GetWrappedId<VulkanPipelineLayoutWrapper>(format::FromHandleId<VkPipelineLayout>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_RENDER_PASS_EXT:
            return GetWrappedId<VulkanRenderPassWrapper>(format::FromHandleId<VkRenderPass>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_EXT:
            return GetWrappedId<VulkanPipelineWrapper>(format::FromHandleId<VkPipeline>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT_EXT:
            return GetWrappedId<VulkanDescriptorSetLayoutWrapper>(format::FromHandleId<VkDescriptorSetLayout>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_SAMPLER_EXT:
            return GetWrappedId<VulkanSamplerWrapper>(format::FromHandleId<VkSampler>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_POOL_EXT:
            return GetWrappedId<VulkanDescriptorPoolWrapper>(format::FromHandleId<VkDescriptorPool>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_SET_EXT:
            return GetWrappedId<VulkanDescriptorSetWrapper>(format::FromHandleId<VkDescriptorSet>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_FRAMEBUFFER_EXT:
            return GetWrappedId<VulkanFramebufferWrapper>(format::FromHandleId<VkFramebuffer>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_COMMAND_POOL_EXT:
            return GetWrappedId<VulkanCommandPoolWrapper>(format::FromHandleId<VkCommandPool>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_SURFACE_KHR_EXT:
            return GetWrappedId<VulkanSurfaceKHRWrapper>(format::FromHandleId<VkSurfaceKHR>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_SWAPCHAIN_KHR_EXT:
            return GetWrappedId<VulkanSwapchainKHRWrapper>(format::FromHandleId<VkSwapchainKHR>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_DEBUG_REPORT_CALLBACK_EXT_EXT:
            return GetWrappedId<VulkanDebugReportCallbackEXTWrapper>(
                format::FromHandleId<VkDebugReportCallbackEXT>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_DISPLAY_KHR_EXT:
            return GetWrappedId<VulkanDisplayKHRWrapper>(format::FromHandleId<VkDisplayKHR>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_DISPLAY_MODE_KHR_EXT:
            return GetWrappedId<VulkanDisplayModeKHRWrapper>(format::FromHandleId<VkDisplayModeKHR>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_VALIDATION_CACHE_EXT_EXT:
            return GetWrappedId<VulkanValidationCacheEXTWrapper>(format::FromHandleId<VkValidationCacheEXT>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION_EXT:
            return GetWrappedId<VulkanSamplerYcbcrConversionWrapper>(
                format::FromHandleId<VkSamplerYcbcrConversion>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_EXT:
            return GetWrappedId<VulkanDescriptorUpdateTemplateWrapper>(
                format::FromHandleId<VkDescriptorUpdateTemplate>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_ACCELERATION_STRUCTURE_KHR_EXT:
            return GetWrappedId<VulkanAccelerationStructureKHRWrapper>(
                format::FromHandleId<VkAccelerationStructureKHR>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_ACCELERATION_STRUCTURE_NV_EXT:
            return GetWrappedId<VulkanAccelerationStructureNVWrapper>(
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
