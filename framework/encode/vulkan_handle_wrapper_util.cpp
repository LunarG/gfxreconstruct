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

uint64_t GetWrappedHandle(uint64_t object, VkObjectType object_type)
{
    switch (object_type)
    {
        case VK_OBJECT_TYPE_INSTANCE:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkInstance>(object)));
        case VK_OBJECT_TYPE_PHYSICAL_DEVICE:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkPhysicalDevice>(object)));
        case VK_OBJECT_TYPE_DEVICE:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkDevice>(object)));
        case VK_OBJECT_TYPE_QUEUE:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkQueue>(object)));
        case VK_OBJECT_TYPE_SEMAPHORE:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkSemaphore>(object)));
        case VK_OBJECT_TYPE_COMMAND_BUFFER:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkCommandBuffer>(object)));
        case VK_OBJECT_TYPE_FENCE:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkFence>(object)));
        case VK_OBJECT_TYPE_DEVICE_MEMORY:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkDeviceMemory>(object)));
        case VK_OBJECT_TYPE_BUFFER:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkBuffer>(object)));
        case VK_OBJECT_TYPE_IMAGE:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkImage>(object)));
        case VK_OBJECT_TYPE_EVENT:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkEvent>(object)));
        case VK_OBJECT_TYPE_QUERY_POOL:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkQueryPool>(object)));
        case VK_OBJECT_TYPE_BUFFER_VIEW:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkBufferView>(object)));
        case VK_OBJECT_TYPE_IMAGE_VIEW:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkImageView>(object)));
        case VK_OBJECT_TYPE_SHADER_MODULE:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkShaderModule>(object)));
        case VK_OBJECT_TYPE_PIPELINE_CACHE:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkPipelineCache>(object)));
        case VK_OBJECT_TYPE_PIPELINE_LAYOUT:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkPipelineLayout>(object)));
        case VK_OBJECT_TYPE_RENDER_PASS:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkRenderPass>(object)));
        case VK_OBJECT_TYPE_PIPELINE:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkPipeline>(object)));
        case VK_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkDescriptorSetLayout>(object)));
        case VK_OBJECT_TYPE_SAMPLER:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkSampler>(object)));
        case VK_OBJECT_TYPE_DESCRIPTOR_POOL:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkDescriptorPool>(object)));
        case VK_OBJECT_TYPE_DESCRIPTOR_SET:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkDescriptorSet>(object)));
        case VK_OBJECT_TYPE_FRAMEBUFFER:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkFramebuffer>(object)));
        case VK_OBJECT_TYPE_COMMAND_POOL:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkCommandPool>(object)));
        case VK_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkSamplerYcbcrConversion>(object)));
        case VK_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkDescriptorUpdateTemplate>(object)));
        case VK_OBJECT_TYPE_SURFACE_KHR:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkSurfaceKHR>(object)));
        case VK_OBJECT_TYPE_SWAPCHAIN_KHR:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkSwapchainKHR>(object)));
        case VK_OBJECT_TYPE_DISPLAY_KHR:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkDisplayKHR>(object)));
        case VK_OBJECT_TYPE_DISPLAY_MODE_KHR:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkDisplayModeKHR>(object)));
        case VK_OBJECT_TYPE_DEBUG_REPORT_CALLBACK_EXT:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkDebugReportCallbackEXT>(object)));
        case VK_OBJECT_TYPE_DEBUG_UTILS_MESSENGER_EXT:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkDebugUtilsMessengerEXT>(object)));
        case VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_KHR:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkAccelerationStructureKHR>(object)));
        case VK_OBJECT_TYPE_VALIDATION_CACHE_EXT:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkValidationCacheEXT>(object)));
        case VK_OBJECT_TYPE_PERFORMANCE_CONFIGURATION_INTEL:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkPerformanceConfigurationINTEL>(object)));
        case VK_OBJECT_TYPE_DEFERRED_OPERATION_KHR:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkDeferredOperationKHR>(object)));
        case VK_OBJECT_TYPE_INDIRECT_COMMANDS_LAYOUT_NV:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkIndirectCommandsLayoutNV>(object)));
        case VK_OBJECT_TYPE_PRIVATE_DATA_SLOT_EXT:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkPrivateDataSlotEXT>(object)));
        case VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_NV:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkAccelerationStructureNV>(object)));
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

uint64_t GetWrappedHandle(uint64_t object, VkDebugReportObjectTypeEXT object_type)
{
    switch (object_type)
    {
        case VK_DEBUG_REPORT_OBJECT_TYPE_INSTANCE_EXT:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkInstance>(object)));
        case VK_DEBUG_REPORT_OBJECT_TYPE_PHYSICAL_DEVICE_EXT:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkPhysicalDevice>(object)));
        case VK_DEBUG_REPORT_OBJECT_TYPE_DEVICE_EXT:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkDevice>(object)));
        case VK_DEBUG_REPORT_OBJECT_TYPE_QUEUE_EXT:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkQueue>(object)));
        case VK_DEBUG_REPORT_OBJECT_TYPE_SEMAPHORE_EXT:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkSemaphore>(object)));
        case VK_DEBUG_REPORT_OBJECT_TYPE_COMMAND_BUFFER_EXT:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkCommandBuffer>(object)));
        case VK_DEBUG_REPORT_OBJECT_TYPE_FENCE_EXT:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkFence>(object)));
        case VK_DEBUG_REPORT_OBJECT_TYPE_DEVICE_MEMORY_EXT:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkDeviceMemory>(object)));
        case VK_DEBUG_REPORT_OBJECT_TYPE_BUFFER_EXT:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkBuffer>(object)));
        case VK_DEBUG_REPORT_OBJECT_TYPE_IMAGE_EXT:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkImage>(object)));
        case VK_DEBUG_REPORT_OBJECT_TYPE_EVENT_EXT:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkEvent>(object)));
        case VK_DEBUG_REPORT_OBJECT_TYPE_QUERY_POOL_EXT:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkQueryPool>(object)));
        case VK_DEBUG_REPORT_OBJECT_TYPE_BUFFER_VIEW_EXT:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkBufferView>(object)));
        case VK_DEBUG_REPORT_OBJECT_TYPE_IMAGE_VIEW_EXT:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkImageView>(object)));
        case VK_DEBUG_REPORT_OBJECT_TYPE_SHADER_MODULE_EXT:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkShaderModule>(object)));
        case VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_CACHE_EXT:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkPipelineCache>(object)));
        case VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_LAYOUT_EXT:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkPipelineLayout>(object)));
        case VK_DEBUG_REPORT_OBJECT_TYPE_RENDER_PASS_EXT:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkRenderPass>(object)));
        case VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_EXT:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkPipeline>(object)));
        case VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT_EXT:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkDescriptorSetLayout>(object)));
        case VK_DEBUG_REPORT_OBJECT_TYPE_SAMPLER_EXT:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkSampler>(object)));
        case VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_POOL_EXT:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkDescriptorPool>(object)));
        case VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_SET_EXT:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkDescriptorSet>(object)));
        case VK_DEBUG_REPORT_OBJECT_TYPE_FRAMEBUFFER_EXT:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkFramebuffer>(object)));
        case VK_DEBUG_REPORT_OBJECT_TYPE_COMMAND_POOL_EXT:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkCommandPool>(object)));
        case VK_DEBUG_REPORT_OBJECT_TYPE_SURFACE_KHR_EXT:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkSurfaceKHR>(object)));
        case VK_DEBUG_REPORT_OBJECT_TYPE_SWAPCHAIN_KHR_EXT:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkSwapchainKHR>(object)));
        case VK_DEBUG_REPORT_OBJECT_TYPE_DEBUG_REPORT_CALLBACK_EXT_EXT:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkDebugReportCallbackEXT>(object)));
        case VK_DEBUG_REPORT_OBJECT_TYPE_DISPLAY_KHR_EXT:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkDisplayKHR>(object)));
        case VK_DEBUG_REPORT_OBJECT_TYPE_DISPLAY_MODE_KHR_EXT:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkDisplayModeKHR>(object)));
        case VK_DEBUG_REPORT_OBJECT_TYPE_VALIDATION_CACHE_EXT_EXT:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkValidationCacheEXT>(object)));
        case VK_DEBUG_REPORT_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION_EXT:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkSamplerYcbcrConversion>(object)));
        case VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_EXT:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkDescriptorUpdateTemplate>(object)));
        case VK_DEBUG_REPORT_OBJECT_TYPE_ACCELERATION_STRUCTURE_KHR_EXT:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkAccelerationStructureKHR>(object)));
        case VK_DEBUG_REPORT_OBJECT_TYPE_ACCELERATION_STRUCTURE_NV_EXT:
            return format::ToHandleId(GetWrappedHandle(format::FromHandleId<VkAccelerationStructureNV>(object)));
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

uint64_t GetWrappedId(uint64_t object, VkObjectType object_type)
{
    switch (object_type)
    {
        case VK_OBJECT_TYPE_INSTANCE:
            return GetWrappedId(format::FromHandleId<VkInstance>(object));
        case VK_OBJECT_TYPE_PHYSICAL_DEVICE:
            return GetWrappedId(format::FromHandleId<VkPhysicalDevice>(object));
        case VK_OBJECT_TYPE_DEVICE:
            return GetWrappedId(format::FromHandleId<VkDevice>(object));
        case VK_OBJECT_TYPE_QUEUE:
            return GetWrappedId(format::FromHandleId<VkQueue>(object));
        case VK_OBJECT_TYPE_SEMAPHORE:
            return GetWrappedId(format::FromHandleId<VkSemaphore>(object));
        case VK_OBJECT_TYPE_COMMAND_BUFFER:
            return GetWrappedId(format::FromHandleId<VkCommandBuffer>(object));
        case VK_OBJECT_TYPE_FENCE:
            return GetWrappedId(format::FromHandleId<VkFence>(object));
        case VK_OBJECT_TYPE_DEVICE_MEMORY:
            return GetWrappedId(format::FromHandleId<VkDeviceMemory>(object));
        case VK_OBJECT_TYPE_BUFFER:
            return GetWrappedId(format::FromHandleId<VkBuffer>(object));
        case VK_OBJECT_TYPE_IMAGE:
            return GetWrappedId(format::FromHandleId<VkImage>(object));
        case VK_OBJECT_TYPE_EVENT:
            return GetWrappedId(format::FromHandleId<VkEvent>(object));
        case VK_OBJECT_TYPE_QUERY_POOL:
            return GetWrappedId(format::FromHandleId<VkQueryPool>(object));
        case VK_OBJECT_TYPE_BUFFER_VIEW:
            return GetWrappedId(format::FromHandleId<VkBufferView>(object));
        case VK_OBJECT_TYPE_IMAGE_VIEW:
            return GetWrappedId(format::FromHandleId<VkImageView>(object));
        case VK_OBJECT_TYPE_SHADER_MODULE:
            return GetWrappedId(format::FromHandleId<VkShaderModule>(object));
        case VK_OBJECT_TYPE_PIPELINE_CACHE:
            return GetWrappedId(format::FromHandleId<VkPipelineCache>(object));
        case VK_OBJECT_TYPE_PIPELINE_LAYOUT:
            return GetWrappedId(format::FromHandleId<VkPipelineLayout>(object));
        case VK_OBJECT_TYPE_RENDER_PASS:
            return GetWrappedId(format::FromHandleId<VkRenderPass>(object));
        case VK_OBJECT_TYPE_PIPELINE:
            return GetWrappedId(format::FromHandleId<VkPipeline>(object));
        case VK_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT:
            return GetWrappedId(format::FromHandleId<VkDescriptorSetLayout>(object));
        case VK_OBJECT_TYPE_SAMPLER:
            return GetWrappedId(format::FromHandleId<VkSampler>(object));
        case VK_OBJECT_TYPE_DESCRIPTOR_POOL:
            return GetWrappedId(format::FromHandleId<VkDescriptorPool>(object));
        case VK_OBJECT_TYPE_DESCRIPTOR_SET:
            return GetWrappedId(format::FromHandleId<VkDescriptorSet>(object));
        case VK_OBJECT_TYPE_FRAMEBUFFER:
            return GetWrappedId(format::FromHandleId<VkFramebuffer>(object));
        case VK_OBJECT_TYPE_COMMAND_POOL:
            return GetWrappedId(format::FromHandleId<VkCommandPool>(object));
        case VK_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION:
            return GetWrappedId(format::FromHandleId<VkSamplerYcbcrConversion>(object));
        case VK_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE:
            return GetWrappedId(format::FromHandleId<VkDescriptorUpdateTemplate>(object));
        case VK_OBJECT_TYPE_SURFACE_KHR:
            return GetWrappedId(format::FromHandleId<VkSurfaceKHR>(object));
        case VK_OBJECT_TYPE_SWAPCHAIN_KHR:
            return GetWrappedId(format::FromHandleId<VkSwapchainKHR>(object));
        case VK_OBJECT_TYPE_DISPLAY_KHR:
            return GetWrappedId(format::FromHandleId<VkDisplayKHR>(object));
        case VK_OBJECT_TYPE_DISPLAY_MODE_KHR:
            return GetWrappedId(format::FromHandleId<VkDisplayModeKHR>(object));
        case VK_OBJECT_TYPE_DEBUG_REPORT_CALLBACK_EXT:
            return GetWrappedId(format::FromHandleId<VkDebugReportCallbackEXT>(object));
        case VK_OBJECT_TYPE_DEBUG_UTILS_MESSENGER_EXT:
            return GetWrappedId(format::FromHandleId<VkDebugUtilsMessengerEXT>(object));
        case VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_KHR:
            return GetWrappedId(format::FromHandleId<VkAccelerationStructureKHR>(object));
        case VK_OBJECT_TYPE_VALIDATION_CACHE_EXT:
            return GetWrappedId(format::FromHandleId<VkValidationCacheEXT>(object));
        case VK_OBJECT_TYPE_PERFORMANCE_CONFIGURATION_INTEL:
            return GetWrappedId(format::FromHandleId<VkPerformanceConfigurationINTEL>(object));
        case VK_OBJECT_TYPE_DEFERRED_OPERATION_KHR:
            return GetWrappedId(format::FromHandleId<VkDeferredOperationKHR>(object));
        case VK_OBJECT_TYPE_INDIRECT_COMMANDS_LAYOUT_NV:
            return GetWrappedId(format::FromHandleId<VkIndirectCommandsLayoutNV>(object));
        case VK_OBJECT_TYPE_PRIVATE_DATA_SLOT_EXT:
            return GetWrappedId(format::FromHandleId<VkPrivateDataSlotEXT>(object));
        case VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_NV:
            return GetWrappedId(format::FromHandleId<VkAccelerationStructureNV>(object));
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
            return GetWrappedId(format::FromHandleId<VkInstance>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_PHYSICAL_DEVICE_EXT:
            return GetWrappedId(format::FromHandleId<VkPhysicalDevice>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_DEVICE_EXT:
            return GetWrappedId(format::FromHandleId<VkDevice>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_QUEUE_EXT:
            return GetWrappedId(format::FromHandleId<VkQueue>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_SEMAPHORE_EXT:
            return GetWrappedId(format::FromHandleId<VkSemaphore>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_COMMAND_BUFFER_EXT:
            return GetWrappedId(format::FromHandleId<VkCommandBuffer>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_FENCE_EXT:
            return GetWrappedId(format::FromHandleId<VkFence>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_DEVICE_MEMORY_EXT:
            return GetWrappedId(format::FromHandleId<VkDeviceMemory>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_BUFFER_EXT:
            return GetWrappedId(format::FromHandleId<VkBuffer>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_IMAGE_EXT:
            return GetWrappedId(format::FromHandleId<VkImage>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_EVENT_EXT:
            return GetWrappedId(format::FromHandleId<VkEvent>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_QUERY_POOL_EXT:
            return GetWrappedId(format::FromHandleId<VkQueryPool>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_BUFFER_VIEW_EXT:
            return GetWrappedId(format::FromHandleId<VkBufferView>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_IMAGE_VIEW_EXT:
            return GetWrappedId(format::FromHandleId<VkImageView>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_SHADER_MODULE_EXT:
            return GetWrappedId(format::FromHandleId<VkShaderModule>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_CACHE_EXT:
            return GetWrappedId(format::FromHandleId<VkPipelineCache>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_LAYOUT_EXT:
            return GetWrappedId(format::FromHandleId<VkPipelineLayout>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_RENDER_PASS_EXT:
            return GetWrappedId(format::FromHandleId<VkRenderPass>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_EXT:
            return GetWrappedId(format::FromHandleId<VkPipeline>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT_EXT:
            return GetWrappedId(format::FromHandleId<VkDescriptorSetLayout>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_SAMPLER_EXT:
            return GetWrappedId(format::FromHandleId<VkSampler>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_POOL_EXT:
            return GetWrappedId(format::FromHandleId<VkDescriptorPool>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_SET_EXT:
            return GetWrappedId(format::FromHandleId<VkDescriptorSet>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_FRAMEBUFFER_EXT:
            return GetWrappedId(format::FromHandleId<VkFramebuffer>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_COMMAND_POOL_EXT:
            return GetWrappedId(format::FromHandleId<VkCommandPool>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_SURFACE_KHR_EXT:
            return GetWrappedId(format::FromHandleId<VkSurfaceKHR>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_SWAPCHAIN_KHR_EXT:
            return GetWrappedId(format::FromHandleId<VkSwapchainKHR>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_DEBUG_REPORT_CALLBACK_EXT_EXT:
            return GetWrappedId(format::FromHandleId<VkDebugReportCallbackEXT>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_DISPLAY_KHR_EXT:
            return GetWrappedId(format::FromHandleId<VkDisplayKHR>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_DISPLAY_MODE_KHR_EXT:
            return GetWrappedId(format::FromHandleId<VkDisplayModeKHR>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_VALIDATION_CACHE_EXT_EXT:
            return GetWrappedId(format::FromHandleId<VkValidationCacheEXT>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION_EXT:
            return GetWrappedId(format::FromHandleId<VkSamplerYcbcrConversion>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_EXT:
            return GetWrappedId(format::FromHandleId<VkDescriptorUpdateTemplate>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_ACCELERATION_STRUCTURE_KHR_EXT:
            return GetWrappedId(format::FromHandleId<VkAccelerationStructureKHR>(object));
        case VK_DEBUG_REPORT_OBJECT_TYPE_ACCELERATION_STRUCTURE_NV_EXT:
            return GetWrappedId(format::FromHandleId<VkAccelerationStructureNV>(object));
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
