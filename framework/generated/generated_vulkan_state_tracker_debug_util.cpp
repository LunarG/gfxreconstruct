/*
** Copyright (c) 2018-2023 Valve Corporation
** Copyright (c) 2018-2026 LunarG, Inc.
** Copyright (c) 2023 Advanced Micro Devices, Inc.
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

/*
** This file is generated from the Khronos Vulkan XML API Registry.
**
*/

#include "encode/vulkan_state_tracker.h"

#include "encode/vulkan_handle_wrapper_util.h"
#include "encode/vulkan_handle_wrappers.h"
#include "encode/vulkan_state_writer.h"
#include "format/format_util.h"
#include "util/logging.h"

#include <utility>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

void AssignDebugToObject(VkObjectType                        object_type,
                         uint64_t                            object_handle,
                         vulkan_state_info::CreateParameters object_name_parameter_buffer,
                         vulkan_state_info::CreateParameters object_tag_parameter_buffer)
{
    switch (object_type)
    {
        case VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_KHR:
        {
            auto* wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::AccelerationStructureKHRWrapper>(
                format::FromHandleId<VkAccelerationStructureKHR>(object_handle));
            if (wrapper != nullptr)
            {
                if (object_name_parameter_buffer)
                {
                    wrapper->debug_name_create_parameters = std::move(object_name_parameter_buffer);
                }

                if (object_tag_parameter_buffer)
                {
                    wrapper->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
                }
            }
            break;
        }
        case VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_NV:
        {
            auto* wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::AccelerationStructureNVWrapper>(
                format::FromHandleId<VkAccelerationStructureNV>(object_handle));
            if (wrapper != nullptr)
            {
                if (object_name_parameter_buffer)
                {
                    wrapper->debug_name_create_parameters = std::move(object_name_parameter_buffer);
                }

                if (object_tag_parameter_buffer)
                {
                    wrapper->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
                }
            }
            break;
        }
        case VK_OBJECT_TYPE_BUFFER:
        {
            auto* wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferWrapper>(
                format::FromHandleId<VkBuffer>(object_handle));
            if (wrapper != nullptr)
            {
                if (object_name_parameter_buffer)
                {
                    wrapper->debug_name_create_parameters = std::move(object_name_parameter_buffer);
                }

                if (object_tag_parameter_buffer)
                {
                    wrapper->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
                }
            }
            break;
        }
        case VK_OBJECT_TYPE_BUFFER_VIEW:
        {
            auto* wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferViewWrapper>(
                format::FromHandleId<VkBufferView>(object_handle));
            if (wrapper != nullptr)
            {
                if (object_name_parameter_buffer)
                {
                    wrapper->debug_name_create_parameters = std::move(object_name_parameter_buffer);
                }

                if (object_tag_parameter_buffer)
                {
                    wrapper->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
                }
            }
            break;
        }
        case VK_OBJECT_TYPE_COMMAND_BUFFER:
        {
            auto* wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(
                format::FromHandleId<VkCommandBuffer>(object_handle));
            if (wrapper != nullptr)
            {
                if (object_name_parameter_buffer)
                {
                    wrapper->debug_name_create_parameters = std::move(object_name_parameter_buffer);
                }

                if (object_tag_parameter_buffer)
                {
                    wrapper->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
                }
            }
            break;
        }
        case VK_OBJECT_TYPE_COMMAND_POOL:
        {
            auto* wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandPoolWrapper>(
                format::FromHandleId<VkCommandPool>(object_handle));
            if (wrapper != nullptr)
            {
                if (object_name_parameter_buffer)
                {
                    wrapper->debug_name_create_parameters = std::move(object_name_parameter_buffer);
                }

                if (object_tag_parameter_buffer)
                {
                    wrapper->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
                }
            }
            break;
        }
        case VK_OBJECT_TYPE_DATA_GRAPH_PIPELINE_SESSION_ARM:
        {
            auto* wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DataGraphPipelineSessionARMWrapper>(
                format::FromHandleId<VkDataGraphPipelineSessionARM>(object_handle));
            if (wrapper != nullptr)
            {
                if (object_name_parameter_buffer)
                {
                    wrapper->debug_name_create_parameters = std::move(object_name_parameter_buffer);
                }

                if (object_tag_parameter_buffer)
                {
                    wrapper->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
                }
            }
            break;
        }
        case VK_OBJECT_TYPE_DEBUG_REPORT_CALLBACK_EXT:
        {
            auto* wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DebugReportCallbackEXTWrapper>(
                format::FromHandleId<VkDebugReportCallbackEXT>(object_handle));
            if (wrapper != nullptr)
            {
                if (object_name_parameter_buffer)
                {
                    wrapper->debug_name_create_parameters = std::move(object_name_parameter_buffer);
                }

                if (object_tag_parameter_buffer)
                {
                    wrapper->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
                }
            }
            break;
        }
        case VK_OBJECT_TYPE_DEBUG_UTILS_MESSENGER_EXT:
        {
            auto* wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DebugUtilsMessengerEXTWrapper>(
                format::FromHandleId<VkDebugUtilsMessengerEXT>(object_handle));
            if (wrapper != nullptr)
            {
                if (object_name_parameter_buffer)
                {
                    wrapper->debug_name_create_parameters = std::move(object_name_parameter_buffer);
                }

                if (object_tag_parameter_buffer)
                {
                    wrapper->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
                }
            }
            break;
        }
        case VK_OBJECT_TYPE_DEFERRED_OPERATION_KHR:
        {
            auto* wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeferredOperationKHRWrapper>(
                format::FromHandleId<VkDeferredOperationKHR>(object_handle));
            if (wrapper != nullptr)
            {
                if (object_name_parameter_buffer)
                {
                    wrapper->debug_name_create_parameters = std::move(object_name_parameter_buffer);
                }

                if (object_tag_parameter_buffer)
                {
                    wrapper->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
                }
            }
            break;
        }
        case VK_OBJECT_TYPE_DESCRIPTOR_POOL:
        {
            auto* wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DescriptorPoolWrapper>(
                format::FromHandleId<VkDescriptorPool>(object_handle));
            if (wrapper != nullptr)
            {
                if (object_name_parameter_buffer)
                {
                    wrapper->debug_name_create_parameters = std::move(object_name_parameter_buffer);
                }

                if (object_tag_parameter_buffer)
                {
                    wrapper->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
                }
            }
            break;
        }
        case VK_OBJECT_TYPE_DESCRIPTOR_SET:
        {
            auto* wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DescriptorSetWrapper>(
                format::FromHandleId<VkDescriptorSet>(object_handle));
            if (wrapper != nullptr)
            {
                if (object_name_parameter_buffer)
                {
                    wrapper->debug_name_create_parameters = std::move(object_name_parameter_buffer);
                }

                if (object_tag_parameter_buffer)
                {
                    wrapper->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
                }
            }
            break;
        }
        case VK_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT:
        {
            auto* wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DescriptorSetLayoutWrapper>(
                format::FromHandleId<VkDescriptorSetLayout>(object_handle));
            if (wrapper != nullptr)
            {
                if (object_name_parameter_buffer)
                {
                    wrapper->debug_name_create_parameters = std::move(object_name_parameter_buffer);
                }

                if (object_tag_parameter_buffer)
                {
                    wrapper->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
                }
            }
            break;
        }
        case VK_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE:
        {
            auto* wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DescriptorUpdateTemplateWrapper>(
                format::FromHandleId<VkDescriptorUpdateTemplate>(object_handle));
            if (wrapper != nullptr)
            {
                if (object_name_parameter_buffer)
                {
                    wrapper->debug_name_create_parameters = std::move(object_name_parameter_buffer);
                }

                if (object_tag_parameter_buffer)
                {
                    wrapper->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
                }
            }
            break;
        }
        case VK_OBJECT_TYPE_DEVICE:
        {
            auto* wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceWrapper>(
                format::FromHandleId<VkDevice>(object_handle));
            if (wrapper != nullptr)
            {
                if (object_name_parameter_buffer)
                {
                    wrapper->debug_name_create_parameters = std::move(object_name_parameter_buffer);
                }

                if (object_tag_parameter_buffer)
                {
                    wrapper->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
                }
            }
            break;
        }
        case VK_OBJECT_TYPE_DEVICE_MEMORY:
        {
            auto* wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceMemoryWrapper>(
                format::FromHandleId<VkDeviceMemory>(object_handle));
            if (wrapper != nullptr)
            {
                if (object_name_parameter_buffer)
                {
                    wrapper->debug_name_create_parameters = std::move(object_name_parameter_buffer);
                }

                if (object_tag_parameter_buffer)
                {
                    wrapper->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
                }
            }
            break;
        }
        case VK_OBJECT_TYPE_DISPLAY_KHR:
        {
            auto* wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DisplayKHRWrapper>(
                format::FromHandleId<VkDisplayKHR>(object_handle));
            if (wrapper != nullptr)
            {
                if (object_name_parameter_buffer)
                {
                    wrapper->debug_name_create_parameters = std::move(object_name_parameter_buffer);
                }

                if (object_tag_parameter_buffer)
                {
                    wrapper->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
                }
            }
            break;
        }
        case VK_OBJECT_TYPE_DISPLAY_MODE_KHR:
        {
            auto* wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DisplayModeKHRWrapper>(
                format::FromHandleId<VkDisplayModeKHR>(object_handle));
            if (wrapper != nullptr)
            {
                if (object_name_parameter_buffer)
                {
                    wrapper->debug_name_create_parameters = std::move(object_name_parameter_buffer);
                }

                if (object_tag_parameter_buffer)
                {
                    wrapper->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
                }
            }
            break;
        }
        case VK_OBJECT_TYPE_EVENT:
        {
            auto* wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::EventWrapper>(
                format::FromHandleId<VkEvent>(object_handle));
            if (wrapper != nullptr)
            {
                if (object_name_parameter_buffer)
                {
                    wrapper->debug_name_create_parameters = std::move(object_name_parameter_buffer);
                }

                if (object_tag_parameter_buffer)
                {
                    wrapper->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
                }
            }
            break;
        }
        case VK_OBJECT_TYPE_FENCE:
        {
            auto* wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::FenceWrapper>(
                format::FromHandleId<VkFence>(object_handle));
            if (wrapper != nullptr)
            {
                if (object_name_parameter_buffer)
                {
                    wrapper->debug_name_create_parameters = std::move(object_name_parameter_buffer);
                }

                if (object_tag_parameter_buffer)
                {
                    wrapper->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
                }
            }
            break;
        }
        case VK_OBJECT_TYPE_FRAMEBUFFER:
        {
            auto* wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::FramebufferWrapper>(
                format::FromHandleId<VkFramebuffer>(object_handle));
            if (wrapper != nullptr)
            {
                if (object_name_parameter_buffer)
                {
                    wrapper->debug_name_create_parameters = std::move(object_name_parameter_buffer);
                }

                if (object_tag_parameter_buffer)
                {
                    wrapper->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
                }
            }
            break;
        }
        case VK_OBJECT_TYPE_GPA_SESSION_AMD:
        {
            auto* wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::GpaSessionAMDWrapper>(
                format::FromHandleId<VkGpaSessionAMD>(object_handle));
            if (wrapper != nullptr)
            {
                if (object_name_parameter_buffer)
                {
                    wrapper->debug_name_create_parameters = std::move(object_name_parameter_buffer);
                }

                if (object_tag_parameter_buffer)
                {
                    wrapper->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
                }
            }
            break;
        }
        case VK_OBJECT_TYPE_IMAGE:
        {
            auto* wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageWrapper>(
                format::FromHandleId<VkImage>(object_handle));
            if (wrapper != nullptr)
            {
                if (object_name_parameter_buffer)
                {
                    wrapper->debug_name_create_parameters = std::move(object_name_parameter_buffer);
                }

                if (object_tag_parameter_buffer)
                {
                    wrapper->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
                }
            }
            break;
        }
        case VK_OBJECT_TYPE_IMAGE_VIEW:
        {
            auto* wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageViewWrapper>(
                format::FromHandleId<VkImageView>(object_handle));
            if (wrapper != nullptr)
            {
                if (object_name_parameter_buffer)
                {
                    wrapper->debug_name_create_parameters = std::move(object_name_parameter_buffer);
                }

                if (object_tag_parameter_buffer)
                {
                    wrapper->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
                }
            }
            break;
        }
        case VK_OBJECT_TYPE_INDIRECT_COMMANDS_LAYOUT_EXT:
        {
            auto* wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::IndirectCommandsLayoutEXTWrapper>(
                format::FromHandleId<VkIndirectCommandsLayoutEXT>(object_handle));
            if (wrapper != nullptr)
            {
                if (object_name_parameter_buffer)
                {
                    wrapper->debug_name_create_parameters = std::move(object_name_parameter_buffer);
                }

                if (object_tag_parameter_buffer)
                {
                    wrapper->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
                }
            }
            break;
        }
        case VK_OBJECT_TYPE_INDIRECT_COMMANDS_LAYOUT_NV:
        {
            auto* wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::IndirectCommandsLayoutNVWrapper>(
                format::FromHandleId<VkIndirectCommandsLayoutNV>(object_handle));
            if (wrapper != nullptr)
            {
                if (object_name_parameter_buffer)
                {
                    wrapper->debug_name_create_parameters = std::move(object_name_parameter_buffer);
                }

                if (object_tag_parameter_buffer)
                {
                    wrapper->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
                }
            }
            break;
        }
        case VK_OBJECT_TYPE_INDIRECT_EXECUTION_SET_EXT:
        {
            auto* wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::IndirectExecutionSetEXTWrapper>(
                format::FromHandleId<VkIndirectExecutionSetEXT>(object_handle));
            if (wrapper != nullptr)
            {
                if (object_name_parameter_buffer)
                {
                    wrapper->debug_name_create_parameters = std::move(object_name_parameter_buffer);
                }

                if (object_tag_parameter_buffer)
                {
                    wrapper->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
                }
            }
            break;
        }
        case VK_OBJECT_TYPE_INSTANCE:
        {
            auto* wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::InstanceWrapper>(
                format::FromHandleId<VkInstance>(object_handle));
            if (wrapper != nullptr)
            {
                if (object_name_parameter_buffer)
                {
                    wrapper->debug_name_create_parameters = std::move(object_name_parameter_buffer);
                }

                if (object_tag_parameter_buffer)
                {
                    wrapper->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
                }
            }
            break;
        }
        case VK_OBJECT_TYPE_MICROMAP_EXT:
        {
            auto* wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::MicromapEXTWrapper>(
                format::FromHandleId<VkMicromapEXT>(object_handle));
            if (wrapper != nullptr)
            {
                if (object_name_parameter_buffer)
                {
                    wrapper->debug_name_create_parameters = std::move(object_name_parameter_buffer);
                }

                if (object_tag_parameter_buffer)
                {
                    wrapper->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
                }
            }
            break;
        }
        case VK_OBJECT_TYPE_OPTICAL_FLOW_SESSION_NV:
        {
            auto* wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::OpticalFlowSessionNVWrapper>(
                format::FromHandleId<VkOpticalFlowSessionNV>(object_handle));
            if (wrapper != nullptr)
            {
                if (object_name_parameter_buffer)
                {
                    wrapper->debug_name_create_parameters = std::move(object_name_parameter_buffer);
                }

                if (object_tag_parameter_buffer)
                {
                    wrapper->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
                }
            }
            break;
        }
        case VK_OBJECT_TYPE_PERFORMANCE_CONFIGURATION_INTEL:
        {
            auto* wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::PerformanceConfigurationINTELWrapper>(
                format::FromHandleId<VkPerformanceConfigurationINTEL>(object_handle));
            if (wrapper != nullptr)
            {
                if (object_name_parameter_buffer)
                {
                    wrapper->debug_name_create_parameters = std::move(object_name_parameter_buffer);
                }

                if (object_tag_parameter_buffer)
                {
                    wrapper->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
                }
            }
            break;
        }
        case VK_OBJECT_TYPE_PHYSICAL_DEVICE:
        {
            auto* wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::PhysicalDeviceWrapper>(
                format::FromHandleId<VkPhysicalDevice>(object_handle));
            if (wrapper != nullptr)
            {
                if (object_name_parameter_buffer)
                {
                    wrapper->debug_name_create_parameters = std::move(object_name_parameter_buffer);
                }

                if (object_tag_parameter_buffer)
                {
                    wrapper->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
                }
            }
            break;
        }
        case VK_OBJECT_TYPE_PIPELINE:
        {
            auto* wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::PipelineWrapper>(
                format::FromHandleId<VkPipeline>(object_handle));
            if (wrapper != nullptr)
            {
                if (object_name_parameter_buffer)
                {
                    wrapper->debug_name_create_parameters = std::move(object_name_parameter_buffer);
                }

                if (object_tag_parameter_buffer)
                {
                    wrapper->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
                }
            }
            break;
        }
        case VK_OBJECT_TYPE_PIPELINE_BINARY_KHR:
        {
            auto* wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::PipelineBinaryKHRWrapper>(
                format::FromHandleId<VkPipelineBinaryKHR>(object_handle));
            if (wrapper != nullptr)
            {
                if (object_name_parameter_buffer)
                {
                    wrapper->debug_name_create_parameters = std::move(object_name_parameter_buffer);
                }

                if (object_tag_parameter_buffer)
                {
                    wrapper->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
                }
            }
            break;
        }
        case VK_OBJECT_TYPE_PIPELINE_CACHE:
        {
            auto* wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::PipelineCacheWrapper>(
                format::FromHandleId<VkPipelineCache>(object_handle));
            if (wrapper != nullptr)
            {
                if (object_name_parameter_buffer)
                {
                    wrapper->debug_name_create_parameters = std::move(object_name_parameter_buffer);
                }

                if (object_tag_parameter_buffer)
                {
                    wrapper->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
                }
            }
            break;
        }
        case VK_OBJECT_TYPE_PIPELINE_LAYOUT:
        {
            auto* wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::PipelineLayoutWrapper>(
                format::FromHandleId<VkPipelineLayout>(object_handle));
            if (wrapper != nullptr)
            {
                if (object_name_parameter_buffer)
                {
                    wrapper->debug_name_create_parameters = std::move(object_name_parameter_buffer);
                }

                if (object_tag_parameter_buffer)
                {
                    wrapper->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
                }
            }
            break;
        }
        case VK_OBJECT_TYPE_PRIVATE_DATA_SLOT:
        {
            auto* wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::PrivateDataSlotWrapper>(
                format::FromHandleId<VkPrivateDataSlot>(object_handle));
            if (wrapper != nullptr)
            {
                if (object_name_parameter_buffer)
                {
                    wrapper->debug_name_create_parameters = std::move(object_name_parameter_buffer);
                }

                if (object_tag_parameter_buffer)
                {
                    wrapper->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
                }
            }
            break;
        }
        case VK_OBJECT_TYPE_QUERY_POOL:
        {
            auto* wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::QueryPoolWrapper>(
                format::FromHandleId<VkQueryPool>(object_handle));
            if (wrapper != nullptr)
            {
                if (object_name_parameter_buffer)
                {
                    wrapper->debug_name_create_parameters = std::move(object_name_parameter_buffer);
                }

                if (object_tag_parameter_buffer)
                {
                    wrapper->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
                }
            }
            break;
        }
        case VK_OBJECT_TYPE_QUEUE:
        {
            auto* wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::QueueWrapper>(
                format::FromHandleId<VkQueue>(object_handle));
            if (wrapper != nullptr)
            {
                if (object_name_parameter_buffer)
                {
                    wrapper->debug_name_create_parameters = std::move(object_name_parameter_buffer);
                }

                if (object_tag_parameter_buffer)
                {
                    wrapper->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
                }
            }
            break;
        }
        case VK_OBJECT_TYPE_RENDER_PASS:
        {
            auto* wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::RenderPassWrapper>(
                format::FromHandleId<VkRenderPass>(object_handle));
            if (wrapper != nullptr)
            {
                if (object_name_parameter_buffer)
                {
                    wrapper->debug_name_create_parameters = std::move(object_name_parameter_buffer);
                }

                if (object_tag_parameter_buffer)
                {
                    wrapper->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
                }
            }
            break;
        }
        case VK_OBJECT_TYPE_SAMPLER:
        {
            auto* wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::SamplerWrapper>(
                format::FromHandleId<VkSampler>(object_handle));
            if (wrapper != nullptr)
            {
                if (object_name_parameter_buffer)
                {
                    wrapper->debug_name_create_parameters = std::move(object_name_parameter_buffer);
                }

                if (object_tag_parameter_buffer)
                {
                    wrapper->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
                }
            }
            break;
        }
        case VK_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION:
        {
            auto* wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::SamplerYcbcrConversionWrapper>(
                format::FromHandleId<VkSamplerYcbcrConversion>(object_handle));
            if (wrapper != nullptr)
            {
                if (object_name_parameter_buffer)
                {
                    wrapper->debug_name_create_parameters = std::move(object_name_parameter_buffer);
                }

                if (object_tag_parameter_buffer)
                {
                    wrapper->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
                }
            }
            break;
        }
        case VK_OBJECT_TYPE_SEMAPHORE:
        {
            auto* wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::SemaphoreWrapper>(
                format::FromHandleId<VkSemaphore>(object_handle));
            if (wrapper != nullptr)
            {
                if (object_name_parameter_buffer)
                {
                    wrapper->debug_name_create_parameters = std::move(object_name_parameter_buffer);
                }

                if (object_tag_parameter_buffer)
                {
                    wrapper->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
                }
            }
            break;
        }
        case VK_OBJECT_TYPE_SHADER_EXT:
        {
            auto* wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::ShaderEXTWrapper>(
                format::FromHandleId<VkShaderEXT>(object_handle));
            if (wrapper != nullptr)
            {
                if (object_name_parameter_buffer)
                {
                    wrapper->debug_name_create_parameters = std::move(object_name_parameter_buffer);
                }

                if (object_tag_parameter_buffer)
                {
                    wrapper->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
                }
            }
            break;
        }
        case VK_OBJECT_TYPE_SHADER_MODULE:
        {
            auto* wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::ShaderModuleWrapper>(
                format::FromHandleId<VkShaderModule>(object_handle));
            if (wrapper != nullptr)
            {
                if (object_name_parameter_buffer)
                {
                    wrapper->debug_name_create_parameters = std::move(object_name_parameter_buffer);
                }

                if (object_tag_parameter_buffer)
                {
                    wrapper->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
                }
            }
            break;
        }
        case VK_OBJECT_TYPE_SURFACE_KHR:
        {
            auto* wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::SurfaceKHRWrapper>(
                format::FromHandleId<VkSurfaceKHR>(object_handle));
            if (wrapper != nullptr)
            {
                if (object_name_parameter_buffer)
                {
                    wrapper->debug_name_create_parameters = std::move(object_name_parameter_buffer);
                }

                if (object_tag_parameter_buffer)
                {
                    wrapper->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
                }
            }
            break;
        }
        case VK_OBJECT_TYPE_SWAPCHAIN_KHR:
        {
            auto* wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::SwapchainKHRWrapper>(
                format::FromHandleId<VkSwapchainKHR>(object_handle));
            if (wrapper != nullptr)
            {
                if (object_name_parameter_buffer)
                {
                    wrapper->debug_name_create_parameters = std::move(object_name_parameter_buffer);
                }

                if (object_tag_parameter_buffer)
                {
                    wrapper->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
                }
            }
            break;
        }
        case VK_OBJECT_TYPE_TENSOR_ARM:
        {
            auto* wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::TensorARMWrapper>(
                format::FromHandleId<VkTensorARM>(object_handle));
            if (wrapper != nullptr)
            {
                if (object_name_parameter_buffer)
                {
                    wrapper->debug_name_create_parameters = std::move(object_name_parameter_buffer);
                }

                if (object_tag_parameter_buffer)
                {
                    wrapper->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
                }
            }
            break;
        }
        case VK_OBJECT_TYPE_TENSOR_VIEW_ARM:
        {
            auto* wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::TensorViewARMWrapper>(
                format::FromHandleId<VkTensorViewARM>(object_handle));
            if (wrapper != nullptr)
            {
                if (object_name_parameter_buffer)
                {
                    wrapper->debug_name_create_parameters = std::move(object_name_parameter_buffer);
                }

                if (object_tag_parameter_buffer)
                {
                    wrapper->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
                }
            }
            break;
        }
        case VK_OBJECT_TYPE_VALIDATION_CACHE_EXT:
        {
            auto* wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::ValidationCacheEXTWrapper>(
                format::FromHandleId<VkValidationCacheEXT>(object_handle));
            if (wrapper != nullptr)
            {
                if (object_name_parameter_buffer)
                {
                    wrapper->debug_name_create_parameters = std::move(object_name_parameter_buffer);
                }

                if (object_tag_parameter_buffer)
                {
                    wrapper->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
                }
            }
            break;
        }
        case VK_OBJECT_TYPE_VIDEO_SESSION_KHR:
        {
            auto* wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::VideoSessionKHRWrapper>(
                format::FromHandleId<VkVideoSessionKHR>(object_handle));
            if (wrapper != nullptr)
            {
                if (object_name_parameter_buffer)
                {
                    wrapper->debug_name_create_parameters = std::move(object_name_parameter_buffer);
                }

                if (object_tag_parameter_buffer)
                {
                    wrapper->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
                }
            }
            break;
        }
        case VK_OBJECT_TYPE_VIDEO_SESSION_PARAMETERS_KHR:
        {
            auto* wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::VideoSessionParametersKHRWrapper>(
                format::FromHandleId<VkVideoSessionParametersKHR>(object_handle));
            if (wrapper != nullptr)
            {
                if (object_name_parameter_buffer)
                {
                    wrapper->debug_name_create_parameters = std::move(object_name_parameter_buffer);
                }

                if (object_tag_parameter_buffer)
                {
                    wrapper->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
                }
            }
            break;
        }
        case VK_OBJECT_TYPE_UNKNOWN:
        default:
            break;
    }
}


void VulkanStateWriter::WriteDebugUtilsState(const VulkanStateTable& state_table)
{
    auto write_debug_utils_calls = [&](const auto* wrapper) {
        GFXRECON_ASSERT(wrapper != nullptr);
        if (wrapper->debug_name_create_parameters)
        {
            WriteFunctionCall(format::ApiCall_vkSetDebugUtilsObjectNameEXT,
                              wrapper->debug_name_create_parameters.get());
        }

        if (wrapper->debug_tag_create_parameters)
        {
            WriteFunctionCall(format::ApiCall_vkSetDebugUtilsObjectTagEXT,
                              wrapper->debug_tag_create_parameters.get());
        }
    };

    // clang-format off
    state_table.VisitWrappers([&](const vulkan_wrappers::AccelerationStructureKHRWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::AccelerationStructureNVWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::BufferWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::BufferViewWrapper* wrapper) { if (IsBufferViewValid(wrapper->handle_id, state_table)) { write_debug_utils_calls(wrapper); } });
    state_table.VisitWrappers([&](const vulkan_wrappers::CommandBufferWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::CommandPoolWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::DataGraphPipelineSessionARMWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::DebugReportCallbackEXTWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::DebugUtilsMessengerEXTWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::DeferredOperationKHRWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::DescriptorPoolWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::DescriptorSetWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::DescriptorSetLayoutWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::DescriptorUpdateTemplateWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::DeviceWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::DeviceMemoryWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::DisplayKHRWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::DisplayModeKHRWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::EventWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::FenceWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::FramebufferWrapper* wrapper) { if (IsFramebufferValid(wrapper->handle_id, state_table)) { write_debug_utils_calls(wrapper); } });
    state_table.VisitWrappers([&](const vulkan_wrappers::GpaSessionAMDWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::ImageWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::ImageViewWrapper* wrapper) { if (IsImageViewValid(wrapper->handle_id, state_table)) { write_debug_utils_calls(wrapper); } });
    state_table.VisitWrappers([&](const vulkan_wrappers::IndirectCommandsLayoutEXTWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::IndirectCommandsLayoutNVWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::IndirectExecutionSetEXTWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::InstanceWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::MicromapEXTWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::OpticalFlowSessionNVWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::PerformanceConfigurationINTELWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::PhysicalDeviceWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::PipelineWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::PipelineBinaryKHRWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::PipelineCacheWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::PipelineLayoutWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::PrivateDataSlotWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::QueryPoolWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::QueueWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::RenderPassWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::SamplerWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::SamplerYcbcrConversionWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::SemaphoreWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::ShaderEXTWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::ShaderModuleWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::SurfaceKHRWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::SwapchainKHRWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::TensorARMWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::TensorViewARMWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::ValidationCacheEXTWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::VideoSessionKHRWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::VideoSessionParametersKHRWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    // clang-format on
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
