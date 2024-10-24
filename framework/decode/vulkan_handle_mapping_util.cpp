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

#include "decode/vulkan_handle_mapping_util.h"

#include "decode/vulkan_object_info.h"
#include "format/format_util.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)
GFXRECON_BEGIN_NAMESPACE(handle_mapping)

uint64_t MapHandle(uint64_t object, VkObjectType object_type, const CommonObjectInfoTable& object_info_table)
{
    switch (object_type)
    {
        case VK_OBJECT_TYPE_INSTANCE:
            return format::ToHandleId(
                MapHandle<VulkanInstanceInfo>(object, object_info_table, &CommonObjectInfoTable::GetVkInstanceInfo));
        case VK_OBJECT_TYPE_PHYSICAL_DEVICE:
            return format::ToHandleId(MapHandle<VulkanPhysicalDeviceInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo));
        case VK_OBJECT_TYPE_DEVICE:
            return format::ToHandleId(
                MapHandle<VulkanDeviceInfo>(object, object_info_table, &CommonObjectInfoTable::GetVkDeviceInfo));
        case VK_OBJECT_TYPE_QUEUE:
            return format::ToHandleId(
                MapHandle<VulkanQueueInfo>(object, object_info_table, &CommonObjectInfoTable::GetVkQueueInfo));
        case VK_OBJECT_TYPE_SEMAPHORE:
            return format::ToHandleId(
                MapHandle<VulkanSemaphoreInfo>(object, object_info_table, &CommonObjectInfoTable::GetVkSemaphoreInfo));
        case VK_OBJECT_TYPE_COMMAND_BUFFER:
            return format::ToHandleId(MapHandle<VulkanCommandBufferInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetVkCommandBufferInfo));
        case VK_OBJECT_TYPE_FENCE:
            return format::ToHandleId(
                MapHandle<VulkanFenceInfo>(object, object_info_table, &CommonObjectInfoTable::GetVkFenceInfo));
        case VK_OBJECT_TYPE_DEVICE_MEMORY:
            return format::ToHandleId(MapHandle<VulkanDeviceMemoryInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetVkDeviceMemoryInfo));
        case VK_OBJECT_TYPE_BUFFER:
            return format::ToHandleId(
                MapHandle<VulkanBufferInfo>(object, object_info_table, &CommonObjectInfoTable::GetVkBufferInfo));
        case VK_OBJECT_TYPE_IMAGE:
            return format::ToHandleId(
                MapHandle<VulkanImageInfo>(object, object_info_table, &CommonObjectInfoTable::GetVkImageInfo));
        case VK_OBJECT_TYPE_EVENT:
            return format::ToHandleId(
                MapHandle<VulkanEventInfo>(object, object_info_table, &CommonObjectInfoTable::GetVkEventInfo));
        case VK_OBJECT_TYPE_QUERY_POOL:
            return format::ToHandleId(
                MapHandle<VulkanQueryPoolInfo>(object, object_info_table, &CommonObjectInfoTable::GetVkQueryPoolInfo));
        case VK_OBJECT_TYPE_BUFFER_VIEW:
            return format::ToHandleId(MapHandle<VulkanBufferViewInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetVkBufferViewInfo));
        case VK_OBJECT_TYPE_IMAGE_VIEW:
            return format::ToHandleId(
                MapHandle<VulkanImageViewInfo>(object, object_info_table, &CommonObjectInfoTable::GetVkImageViewInfo));
        case VK_OBJECT_TYPE_SHADER_MODULE:
            return format::ToHandleId(MapHandle<VulkanShaderModuleInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetVkShaderModuleInfo));
        case VK_OBJECT_TYPE_PIPELINE_CACHE:
            return format::ToHandleId(MapHandle<VulkanPipelineCacheInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetVkPipelineCacheInfo));
        case VK_OBJECT_TYPE_PIPELINE_LAYOUT:
            return format::ToHandleId(MapHandle<VulkanPipelineLayoutInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetVkPipelineLayoutInfo));
        case VK_OBJECT_TYPE_RENDER_PASS:
            return format::ToHandleId(MapHandle<VulkanRenderPassInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetVkRenderPassInfo));
        case VK_OBJECT_TYPE_PIPELINE:
            return format::ToHandleId(
                MapHandle<VulkanPipelineInfo>(object, object_info_table, &CommonObjectInfoTable::GetVkPipelineInfo));
        case VK_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT:
            return format::ToHandleId(MapHandle<VulkanDescriptorSetLayoutInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetVkDescriptorSetLayoutInfo));
        case VK_OBJECT_TYPE_SAMPLER:
            return format::ToHandleId(
                MapHandle<VulkanSamplerInfo>(object, object_info_table, &CommonObjectInfoTable::GetVkSamplerInfo));
        case VK_OBJECT_TYPE_DESCRIPTOR_POOL:
            return format::ToHandleId(MapHandle<VulkanDescriptorPoolInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetVkDescriptorPoolInfo));
        case VK_OBJECT_TYPE_DESCRIPTOR_SET:
            return format::ToHandleId(MapHandle<VulkanDescriptorSetInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetVkDescriptorSetInfo));
        case VK_OBJECT_TYPE_FRAMEBUFFER:
            return format::ToHandleId(MapHandle<VulkanFramebufferInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetVkFramebufferInfo));
        case VK_OBJECT_TYPE_COMMAND_POOL:
            return format::ToHandleId(MapHandle<VulkanCommandPoolInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetVkCommandPoolInfo));
        case VK_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION:
            return format::ToHandleId(MapHandle<VulkanSamplerYcbcrConversionInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetVkSamplerYcbcrConversionInfo));
        case VK_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE:
            return format::ToHandleId(MapHandle<VulkanDescriptorUpdateTemplateInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetVkDescriptorUpdateTemplateInfo));
        case VK_OBJECT_TYPE_SURFACE_KHR:
            return format::ToHandleId(MapHandle<VulkanSurfaceKHRInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetVkSurfaceKHRInfo));
        case VK_OBJECT_TYPE_SWAPCHAIN_KHR:
            return format::ToHandleId(MapHandle<VulkanSwapchainKHRInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetVkSwapchainKHRInfo));
        case VK_OBJECT_TYPE_DISPLAY_KHR:
            return format::ToHandleId(MapHandle<VulkanDisplayKHRInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetVkDisplayKHRInfo));
        case VK_OBJECT_TYPE_DISPLAY_MODE_KHR:
            return format::ToHandleId(MapHandle<VulkanDisplayModeKHRInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetVkDisplayModeKHRInfo));
        case VK_OBJECT_TYPE_DEBUG_REPORT_CALLBACK_EXT:
            return format::ToHandleId(MapHandle<VulkanDebugReportCallbackEXTInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetVkDebugReportCallbackEXTInfo));
        case VK_OBJECT_TYPE_DEBUG_UTILS_MESSENGER_EXT:
            return format::ToHandleId(MapHandle<VulkanDebugUtilsMessengerEXTInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetVkDebugUtilsMessengerEXTInfo));
        case VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_KHR:
            return format::ToHandleId(MapHandle<VulkanAccelerationStructureKHRInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetVkAccelerationStructureKHRInfo));
        case VK_OBJECT_TYPE_VALIDATION_CACHE_EXT:
            return format::ToHandleId(MapHandle<VulkanValidationCacheEXTInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetVkValidationCacheEXTInfo));
        case VK_OBJECT_TYPE_PERFORMANCE_CONFIGURATION_INTEL:
            return format::ToHandleId(MapHandle<VulkanPerformanceConfigurationINTELInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetVkPerformanceConfigurationINTELInfo));
        case VK_OBJECT_TYPE_DEFERRED_OPERATION_KHR:
            return format::ToHandleId(MapHandle<VulkanDeferredOperationKHRInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetVkDeferredOperationKHRInfo));
        case VK_OBJECT_TYPE_INDIRECT_COMMANDS_LAYOUT_NV:
            return format::ToHandleId(MapHandle<VulkanIndirectCommandsLayoutNVInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetVkIndirectCommandsLayoutNVInfo));
        case VK_OBJECT_TYPE_MICROMAP_EXT:
            return format::ToHandleId(MapHandle<VulkanMicromapEXTInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetVkMicromapEXTInfo));
        case VK_OBJECT_TYPE_PRIVATE_DATA_SLOT_EXT:
            return format::ToHandleId(MapHandle<VulkanPrivateDataSlotEXTInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetVkPrivateDataSlotInfo));
        case VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_NV:
            return format::ToHandleId(MapHandle<VulkanAccelerationStructureNVInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetVkAccelerationStructureNVInfo));
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

uint64_t
MapHandle(uint64_t object, VkDebugReportObjectTypeEXT object_type, const CommonObjectInfoTable& object_info_table)
{
    switch (object_type)
    {
        case VK_DEBUG_REPORT_OBJECT_TYPE_INSTANCE_EXT:
            return format::ToHandleId(
                MapHandle<VulkanInstanceInfo>(object, object_info_table, &CommonObjectInfoTable::GetVkInstanceInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_PHYSICAL_DEVICE_EXT:
            return format::ToHandleId(MapHandle<VulkanPhysicalDeviceInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_DEVICE_EXT:
            return format::ToHandleId(
                MapHandle<VulkanDeviceInfo>(object, object_info_table, &CommonObjectInfoTable::GetVkDeviceInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_QUEUE_EXT:
            return format::ToHandleId(
                MapHandle<VulkanQueueInfo>(object, object_info_table, &CommonObjectInfoTable::GetVkQueueInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_SEMAPHORE_EXT:
            return format::ToHandleId(
                MapHandle<VulkanSemaphoreInfo>(object, object_info_table, &CommonObjectInfoTable::GetVkSemaphoreInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_COMMAND_BUFFER_EXT:
            return format::ToHandleId(MapHandle<VulkanCommandBufferInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetVkCommandBufferInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_FENCE_EXT:
            return format::ToHandleId(
                MapHandle<VulkanFenceInfo>(object, object_info_table, &CommonObjectInfoTable::GetVkFenceInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_DEVICE_MEMORY_EXT:
            return format::ToHandleId(MapHandle<VulkanDeviceMemoryInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetVkDeviceMemoryInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_BUFFER_EXT:
            return format::ToHandleId(
                MapHandle<VulkanBufferInfo>(object, object_info_table, &CommonObjectInfoTable::GetVkBufferInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_IMAGE_EXT:
            return format::ToHandleId(
                MapHandle<VulkanImageInfo>(object, object_info_table, &CommonObjectInfoTable::GetVkImageInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_EVENT_EXT:
            return format::ToHandleId(
                MapHandle<VulkanEventInfo>(object, object_info_table, &CommonObjectInfoTable::GetVkEventInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_QUERY_POOL_EXT:
            return format::ToHandleId(
                MapHandle<VulkanQueryPoolInfo>(object, object_info_table, &CommonObjectInfoTable::GetVkQueryPoolInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_BUFFER_VIEW_EXT:
            return format::ToHandleId(MapHandle<VulkanBufferViewInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetVkBufferViewInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_IMAGE_VIEW_EXT:
            return format::ToHandleId(
                MapHandle<VulkanImageViewInfo>(object, object_info_table, &CommonObjectInfoTable::GetVkImageViewInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_SHADER_MODULE_EXT:
            return format::ToHandleId(MapHandle<VulkanShaderModuleInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetVkShaderModuleInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_CACHE_EXT:
            return format::ToHandleId(MapHandle<VulkanPipelineCacheInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetVkPipelineCacheInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_LAYOUT_EXT:
            return format::ToHandleId(MapHandle<VulkanPipelineLayoutInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetVkPipelineLayoutInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_RENDER_PASS_EXT:
            return format::ToHandleId(MapHandle<VulkanRenderPassInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetVkRenderPassInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_EXT:
            return format::ToHandleId(
                MapHandle<VulkanPipelineInfo>(object, object_info_table, &CommonObjectInfoTable::GetVkPipelineInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT_EXT:
            return format::ToHandleId(MapHandle<VulkanDescriptorSetLayoutInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetVkDescriptorSetLayoutInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_SAMPLER_EXT:
            return format::ToHandleId(
                MapHandle<VulkanSamplerInfo>(object, object_info_table, &CommonObjectInfoTable::GetVkSamplerInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_POOL_EXT:
            return format::ToHandleId(MapHandle<VulkanDescriptorPoolInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetVkDescriptorPoolInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_SET_EXT:
            return format::ToHandleId(MapHandle<VulkanDescriptorSetInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetVkDescriptorSetInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_FRAMEBUFFER_EXT:
            return format::ToHandleId(MapHandle<VulkanFramebufferInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetVkFramebufferInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_COMMAND_POOL_EXT:
            return format::ToHandleId(MapHandle<VulkanCommandPoolInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetVkCommandPoolInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_SURFACE_KHR_EXT:
            return format::ToHandleId(MapHandle<VulkanSurfaceKHRInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetVkSurfaceKHRInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_SWAPCHAIN_KHR_EXT:
            return format::ToHandleId(MapHandle<VulkanSwapchainKHRInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetVkSwapchainKHRInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_DEBUG_REPORT_CALLBACK_EXT_EXT:
            return format::ToHandleId(MapHandle<VulkanDebugReportCallbackEXTInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetVkDebugReportCallbackEXTInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_DISPLAY_KHR_EXT:
            return format::ToHandleId(MapHandle<VulkanDisplayKHRInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetVkDisplayKHRInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_DISPLAY_MODE_KHR_EXT:
            return format::ToHandleId(MapHandle<VulkanDisplayModeKHRInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetVkDisplayModeKHRInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_VALIDATION_CACHE_EXT_EXT:
            return format::ToHandleId(MapHandle<VulkanValidationCacheEXTInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetVkValidationCacheEXTInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION_EXT:
            return format::ToHandleId(MapHandle<VulkanSamplerYcbcrConversionInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetVkSamplerYcbcrConversionInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_EXT:
            return format::ToHandleId(MapHandle<VulkanDescriptorUpdateTemplateInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetVkDescriptorUpdateTemplateInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_ACCELERATION_STRUCTURE_KHR_EXT:
            return format::ToHandleId(MapHandle<VulkanAccelerationStructureKHRInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetVkAccelerationStructureKHRInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_ACCELERATION_STRUCTURE_NV_EXT:
            return format::ToHandleId(MapHandle<VulkanAccelerationStructureNVInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetVkAccelerationStructureNVInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_UNKNOWN_EXT:
            // No conversion will be performed for unknown objects.
            GFXRECON_LOG_WARNING("Skipping handle mapping for unknown debug marker object type.");
            return object;
        default:
            GFXRECON_LOG_WARNING("Skipping handle mapping for unrecognized debug marker object type %d", object_type);
            return object;
    }
}

GFXRECON_END_NAMESPACE(handle_mapping)
GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
