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

uint64_t MapHandle(uint64_t object, VkObjectType object_type, const VulkanObjectInfoTable& object_info_table)
{
    switch (object_type)
    {
        case VK_OBJECT_TYPE_INSTANCE:
            return format::ToHandleId(
                MapHandle<InstanceInfo>(object, object_info_table, &VulkanObjectInfoTable::GetInstanceInfo));
        case VK_OBJECT_TYPE_PHYSICAL_DEVICE:
            return format::ToHandleId(MapHandle<PhysicalDeviceInfo>(
                object, object_info_table, &VulkanObjectInfoTable::GetPhysicalDeviceInfo));
        case VK_OBJECT_TYPE_DEVICE:
            return format::ToHandleId(
                MapHandle<DeviceInfo>(object, object_info_table, &VulkanObjectInfoTable::GetDeviceInfo));
        case VK_OBJECT_TYPE_QUEUE:
            return format::ToHandleId(
                MapHandle<QueueInfo>(object, object_info_table, &VulkanObjectInfoTable::GetQueueInfo));
        case VK_OBJECT_TYPE_SEMAPHORE:
            return format::ToHandleId(
                MapHandle<SemaphoreInfo>(object, object_info_table, &VulkanObjectInfoTable::GetSemaphoreInfo));
        case VK_OBJECT_TYPE_COMMAND_BUFFER:
            return format::ToHandleId(
                MapHandle<CommandBufferInfo>(object, object_info_table, &VulkanObjectInfoTable::GetCommandBufferInfo));
        case VK_OBJECT_TYPE_FENCE:
            return format::ToHandleId(
                MapHandle<FenceInfo>(object, object_info_table, &VulkanObjectInfoTable::GetFenceInfo));
        case VK_OBJECT_TYPE_DEVICE_MEMORY:
            return format::ToHandleId(
                MapHandle<DeviceMemoryInfo>(object, object_info_table, &VulkanObjectInfoTable::GetDeviceMemoryInfo));
        case VK_OBJECT_TYPE_BUFFER:
            return format::ToHandleId(
                MapHandle<BufferInfo>(object, object_info_table, &VulkanObjectInfoTable::GetBufferInfo));
        case VK_OBJECT_TYPE_IMAGE:
            return format::ToHandleId(
                MapHandle<ImageInfo>(object, object_info_table, &VulkanObjectInfoTable::GetImageInfo));
        case VK_OBJECT_TYPE_EVENT:
            return format::ToHandleId(
                MapHandle<EventInfo>(object, object_info_table, &VulkanObjectInfoTable::GetEventInfo));
        case VK_OBJECT_TYPE_QUERY_POOL:
            return format::ToHandleId(
                MapHandle<QueryPoolInfo>(object, object_info_table, &VulkanObjectInfoTable::GetQueryPoolInfo));
        case VK_OBJECT_TYPE_BUFFER_VIEW:
            return format::ToHandleId(
                MapHandle<BufferViewInfo>(object, object_info_table, &VulkanObjectInfoTable::GetBufferViewInfo));
        case VK_OBJECT_TYPE_IMAGE_VIEW:
            return format::ToHandleId(
                MapHandle<ImageViewInfo>(object, object_info_table, &VulkanObjectInfoTable::GetImageViewInfo));
        case VK_OBJECT_TYPE_SHADER_MODULE:
            return format::ToHandleId(
                MapHandle<ShaderModuleInfo>(object, object_info_table, &VulkanObjectInfoTable::GetShaderModuleInfo));
        case VK_OBJECT_TYPE_PIPELINE_CACHE:
            return format::ToHandleId(
                MapHandle<PipelineCacheInfo>(object, object_info_table, &VulkanObjectInfoTable::GetPipelineCacheInfo));
        case VK_OBJECT_TYPE_PIPELINE_LAYOUT:
            return format::ToHandleId(MapHandle<PipelineLayoutInfo>(
                object, object_info_table, &VulkanObjectInfoTable::GetPipelineLayoutInfo));
        case VK_OBJECT_TYPE_RENDER_PASS:
            return format::ToHandleId(
                MapHandle<RenderPassInfo>(object, object_info_table, &VulkanObjectInfoTable::GetRenderPassInfo));
        case VK_OBJECT_TYPE_PIPELINE:
            return format::ToHandleId(
                MapHandle<PipelineInfo>(object, object_info_table, &VulkanObjectInfoTable::GetPipelineInfo));
        case VK_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT:
            return format::ToHandleId(MapHandle<DescriptorSetLayoutInfo>(
                object, object_info_table, &VulkanObjectInfoTable::GetDescriptorSetLayoutInfo));
        case VK_OBJECT_TYPE_SAMPLER:
            return format::ToHandleId(
                MapHandle<SamplerInfo>(object, object_info_table, &VulkanObjectInfoTable::GetSamplerInfo));
        case VK_OBJECT_TYPE_DESCRIPTOR_POOL:
            return format::ToHandleId(MapHandle<DescriptorPoolInfo>(
                object, object_info_table, &VulkanObjectInfoTable::GetDescriptorPoolInfo));
        case VK_OBJECT_TYPE_DESCRIPTOR_SET:
            return format::ToHandleId(
                MapHandle<DescriptorSetInfo>(object, object_info_table, &VulkanObjectInfoTable::GetDescriptorSetInfo));
        case VK_OBJECT_TYPE_FRAMEBUFFER:
            return format::ToHandleId(
                MapHandle<FramebufferInfo>(object, object_info_table, &VulkanObjectInfoTable::GetFramebufferInfo));
        case VK_OBJECT_TYPE_COMMAND_POOL:
            return format::ToHandleId(
                MapHandle<CommandPoolInfo>(object, object_info_table, &VulkanObjectInfoTable::GetCommandPoolInfo));
        case VK_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION:
            return format::ToHandleId(MapHandle<SamplerYcbcrConversionInfo>(
                object, object_info_table, &VulkanObjectInfoTable::GetSamplerYcbcrConversionInfo));
        case VK_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE:
            return format::ToHandleId(MapHandle<DescriptorUpdateTemplateInfo>(
                object, object_info_table, &VulkanObjectInfoTable::GetDescriptorUpdateTemplateInfo));
        case VK_OBJECT_TYPE_SURFACE_KHR:
            return format::ToHandleId(
                MapHandle<SurfaceKHRInfo>(object, object_info_table, &VulkanObjectInfoTable::GetSurfaceKHRInfo));
        case VK_OBJECT_TYPE_SWAPCHAIN_KHR:
            return format::ToHandleId(
                MapHandle<SwapchainKHRInfo>(object, object_info_table, &VulkanObjectInfoTable::GetSwapchainKHRInfo));
        case VK_OBJECT_TYPE_DISPLAY_KHR:
            return format::ToHandleId(
                MapHandle<DisplayKHRInfo>(object, object_info_table, &VulkanObjectInfoTable::GetDisplayKHRInfo));
        case VK_OBJECT_TYPE_DISPLAY_MODE_KHR:
            return format::ToHandleId(MapHandle<DisplayModeKHRInfo>(
                object, object_info_table, &VulkanObjectInfoTable::GetDisplayModeKHRInfo));
        case VK_OBJECT_TYPE_DEBUG_REPORT_CALLBACK_EXT:
            return format::ToHandleId(MapHandle<DebugReportCallbackEXTInfo>(
                object, object_info_table, &VulkanObjectInfoTable::GetDebugReportCallbackEXTInfo));
        case VK_OBJECT_TYPE_DEBUG_UTILS_MESSENGER_EXT:
            return format::ToHandleId(MapHandle<DebugUtilsMessengerEXTInfo>(
                object, object_info_table, &VulkanObjectInfoTable::GetDebugUtilsMessengerEXTInfo));
        case VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_KHR:
            return format::ToHandleId(MapHandle<AccelerationStructureKHRInfo>(
                object, object_info_table, &VulkanObjectInfoTable::GetAccelerationStructureKHRInfo));
        case VK_OBJECT_TYPE_VALIDATION_CACHE_EXT:
            return format::ToHandleId(MapHandle<ValidationCacheEXTInfo>(
                object, object_info_table, &VulkanObjectInfoTable::GetValidationCacheEXTInfo));
        case VK_OBJECT_TYPE_PERFORMANCE_CONFIGURATION_INTEL:
            return format::ToHandleId(MapHandle<PerformanceConfigurationINTELInfo>(
                object, object_info_table, &VulkanObjectInfoTable::GetPerformanceConfigurationINTELInfo));
        case VK_OBJECT_TYPE_DEFERRED_OPERATION_KHR:
            return format::ToHandleId(MapHandle<DeferredOperationKHRInfo>(
                object, object_info_table, &VulkanObjectInfoTable::GetDeferredOperationKHRInfo));
        case VK_OBJECT_TYPE_INDIRECT_COMMANDS_LAYOUT_NV:
            return format::ToHandleId(MapHandle<IndirectCommandsLayoutNVInfo>(
                object, object_info_table, &VulkanObjectInfoTable::GetIndirectCommandsLayoutNVInfo));
        case VK_OBJECT_TYPE_MICROMAP_EXT:
            return format::ToHandleId(
                MapHandle<MicromapEXTInfo>(object, object_info_table, &VulkanObjectInfoTable::GetMicromapEXTInfo));
        case VK_OBJECT_TYPE_PRIVATE_DATA_SLOT_EXT:
            return format::ToHandleId(MapHandle<PrivateDataSlotEXTInfo>(
                object, object_info_table, &VulkanObjectInfoTable::GetPrivateDataSlotInfo));
        case VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_NV:
            return format::ToHandleId(MapHandle<AccelerationStructureNVInfo>(
                object, object_info_table, &VulkanObjectInfoTable::GetAccelerationStructureNVInfo));
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
MapHandle(uint64_t object, VkDebugReportObjectTypeEXT object_type, const VulkanObjectInfoTable& object_info_table)
{
    switch (object_type)
    {
        case VK_DEBUG_REPORT_OBJECT_TYPE_INSTANCE_EXT:
            return format::ToHandleId(
                MapHandle<InstanceInfo>(object, object_info_table, &VulkanObjectInfoTable::GetInstanceInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_PHYSICAL_DEVICE_EXT:
            return format::ToHandleId(MapHandle<PhysicalDeviceInfo>(
                object, object_info_table, &VulkanObjectInfoTable::GetPhysicalDeviceInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_DEVICE_EXT:
            return format::ToHandleId(
                MapHandle<DeviceInfo>(object, object_info_table, &VulkanObjectInfoTable::GetDeviceInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_QUEUE_EXT:
            return format::ToHandleId(
                MapHandle<QueueInfo>(object, object_info_table, &VulkanObjectInfoTable::GetQueueInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_SEMAPHORE_EXT:
            return format::ToHandleId(
                MapHandle<SemaphoreInfo>(object, object_info_table, &VulkanObjectInfoTable::GetSemaphoreInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_COMMAND_BUFFER_EXT:
            return format::ToHandleId(
                MapHandle<CommandBufferInfo>(object, object_info_table, &VulkanObjectInfoTable::GetCommandBufferInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_FENCE_EXT:
            return format::ToHandleId(
                MapHandle<FenceInfo>(object, object_info_table, &VulkanObjectInfoTable::GetFenceInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_DEVICE_MEMORY_EXT:
            return format::ToHandleId(
                MapHandle<DeviceMemoryInfo>(object, object_info_table, &VulkanObjectInfoTable::GetDeviceMemoryInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_BUFFER_EXT:
            return format::ToHandleId(
                MapHandle<BufferInfo>(object, object_info_table, &VulkanObjectInfoTable::GetBufferInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_IMAGE_EXT:
            return format::ToHandleId(
                MapHandle<ImageInfo>(object, object_info_table, &VulkanObjectInfoTable::GetImageInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_EVENT_EXT:
            return format::ToHandleId(
                MapHandle<EventInfo>(object, object_info_table, &VulkanObjectInfoTable::GetEventInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_QUERY_POOL_EXT:
            return format::ToHandleId(
                MapHandle<QueryPoolInfo>(object, object_info_table, &VulkanObjectInfoTable::GetQueryPoolInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_BUFFER_VIEW_EXT:
            return format::ToHandleId(
                MapHandle<BufferViewInfo>(object, object_info_table, &VulkanObjectInfoTable::GetBufferViewInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_IMAGE_VIEW_EXT:
            return format::ToHandleId(
                MapHandle<ImageViewInfo>(object, object_info_table, &VulkanObjectInfoTable::GetImageViewInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_SHADER_MODULE_EXT:
            return format::ToHandleId(
                MapHandle<ShaderModuleInfo>(object, object_info_table, &VulkanObjectInfoTable::GetShaderModuleInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_CACHE_EXT:
            return format::ToHandleId(
                MapHandle<PipelineCacheInfo>(object, object_info_table, &VulkanObjectInfoTable::GetPipelineCacheInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_LAYOUT_EXT:
            return format::ToHandleId(MapHandle<PipelineLayoutInfo>(
                object, object_info_table, &VulkanObjectInfoTable::GetPipelineLayoutInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_RENDER_PASS_EXT:
            return format::ToHandleId(
                MapHandle<RenderPassInfo>(object, object_info_table, &VulkanObjectInfoTable::GetRenderPassInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_EXT:
            return format::ToHandleId(
                MapHandle<PipelineInfo>(object, object_info_table, &VulkanObjectInfoTable::GetPipelineInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT_EXT:
            return format::ToHandleId(MapHandle<DescriptorSetLayoutInfo>(
                object, object_info_table, &VulkanObjectInfoTable::GetDescriptorSetLayoutInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_SAMPLER_EXT:
            return format::ToHandleId(
                MapHandle<SamplerInfo>(object, object_info_table, &VulkanObjectInfoTable::GetSamplerInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_POOL_EXT:
            return format::ToHandleId(MapHandle<DescriptorPoolInfo>(
                object, object_info_table, &VulkanObjectInfoTable::GetDescriptorPoolInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_SET_EXT:
            return format::ToHandleId(
                MapHandle<DescriptorSetInfo>(object, object_info_table, &VulkanObjectInfoTable::GetDescriptorSetInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_FRAMEBUFFER_EXT:
            return format::ToHandleId(
                MapHandle<FramebufferInfo>(object, object_info_table, &VulkanObjectInfoTable::GetFramebufferInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_COMMAND_POOL_EXT:
            return format::ToHandleId(
                MapHandle<CommandPoolInfo>(object, object_info_table, &VulkanObjectInfoTable::GetCommandPoolInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_SURFACE_KHR_EXT:
            return format::ToHandleId(
                MapHandle<SurfaceKHRInfo>(object, object_info_table, &VulkanObjectInfoTable::GetSurfaceKHRInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_SWAPCHAIN_KHR_EXT:
            return format::ToHandleId(
                MapHandle<SwapchainKHRInfo>(object, object_info_table, &VulkanObjectInfoTable::GetSwapchainKHRInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_DEBUG_REPORT_CALLBACK_EXT_EXT:
            return format::ToHandleId(MapHandle<DebugReportCallbackEXTInfo>(
                object, object_info_table, &VulkanObjectInfoTable::GetDebugReportCallbackEXTInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_DISPLAY_KHR_EXT:
            return format::ToHandleId(
                MapHandle<DisplayKHRInfo>(object, object_info_table, &VulkanObjectInfoTable::GetDisplayKHRInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_DISPLAY_MODE_KHR_EXT:
            return format::ToHandleId(MapHandle<DisplayModeKHRInfo>(
                object, object_info_table, &VulkanObjectInfoTable::GetDisplayModeKHRInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_VALIDATION_CACHE_EXT_EXT:
            return format::ToHandleId(MapHandle<ValidationCacheEXTInfo>(
                object, object_info_table, &VulkanObjectInfoTable::GetValidationCacheEXTInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION_EXT:
            return format::ToHandleId(MapHandle<SamplerYcbcrConversionInfo>(
                object, object_info_table, &VulkanObjectInfoTable::GetSamplerYcbcrConversionInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_EXT:
            return format::ToHandleId(MapHandle<DescriptorUpdateTemplateInfo>(
                object, object_info_table, &VulkanObjectInfoTable::GetDescriptorUpdateTemplateInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_ACCELERATION_STRUCTURE_KHR_EXT:
            return format::ToHandleId(MapHandle<AccelerationStructureKHRInfo>(
                object, object_info_table, &VulkanObjectInfoTable::GetAccelerationStructureKHRInfo));
        case VK_DEBUG_REPORT_OBJECT_TYPE_ACCELERATION_STRUCTURE_NV_EXT:
            return format::ToHandleId(MapHandle<AccelerationStructureNVInfo>(
                object, object_info_table, &VulkanObjectInfoTable::GetAccelerationStructureNVInfo));
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
