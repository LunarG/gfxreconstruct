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

#ifndef  GFXRECON_GENERATED_VULKAN_CAPTURE_WRAPPER_OF_H
#define  GFXRECON_GENERATED_VULKAN_CAPTURE_WRAPPER_OF_H

#include "encode/vulkan_encode_capture_wrappers.h"
#include "encode/vulkan_handle_wrappers.h"
#include "generated/generated_vulkan_schema_types.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"
#include "vk_video/vulkan_video_codec_h264std.h"
#include "vk_video/vulkan_video_codec_h264std_decode.h"
#include "vk_video/vulkan_video_codec_h264std_encode.h"
#include "vk_video/vulkan_video_codec_h265std.h"
#include "vk_video/vulkan_video_codec_h265std_decode.h"
#include "vk_video/vulkan_video_codec_h265std_encode.h"
#include "vk_video/vulkan_video_codecs_common.h"

#ifdef WIN32
#ifdef CreateEvent
#undef CreateEvent
#endif
#ifdef CreateSemaphore
#undef CreateSemaphore
#endif
#endif

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

// encode::CaptureWrapperOf for every handle: vulkan_wrappers::<Stem>Wrapper, where Stem is the handle name
// without its Vk prefix.
template <> struct CaptureWrapperOf<schema::vulkan::api_elements::VkAccelerationStructureKHR> { using type = vulkan_wrappers::AccelerationStructureKHRWrapper; };
template <> struct CaptureWrapperOf<schema::vulkan::api_elements::VkAccelerationStructureNV> { using type = vulkan_wrappers::AccelerationStructureNVWrapper; };
template <> struct CaptureWrapperOf<schema::vulkan::api_elements::VkBuffer> { using type = vulkan_wrappers::BufferWrapper; };
template <> struct CaptureWrapperOf<schema::vulkan::api_elements::VkBufferView> { using type = vulkan_wrappers::BufferViewWrapper; };
template <> struct CaptureWrapperOf<schema::vulkan::api_elements::VkCommandBuffer> { using type = vulkan_wrappers::CommandBufferWrapper; };
template <> struct CaptureWrapperOf<schema::vulkan::api_elements::VkCommandPool> { using type = vulkan_wrappers::CommandPoolWrapper; };
template <> struct CaptureWrapperOf<schema::vulkan::api_elements::VkDataGraphPipelineSessionARM> { using type = vulkan_wrappers::DataGraphPipelineSessionARMWrapper; };
template <> struct CaptureWrapperOf<schema::vulkan::api_elements::VkDebugReportCallbackEXT> { using type = vulkan_wrappers::DebugReportCallbackEXTWrapper; };
template <> struct CaptureWrapperOf<schema::vulkan::api_elements::VkDebugUtilsMessengerEXT> { using type = vulkan_wrappers::DebugUtilsMessengerEXTWrapper; };
template <> struct CaptureWrapperOf<schema::vulkan::api_elements::VkDeferredOperationKHR> { using type = vulkan_wrappers::DeferredOperationKHRWrapper; };
template <> struct CaptureWrapperOf<schema::vulkan::api_elements::VkDescriptorPool> { using type = vulkan_wrappers::DescriptorPoolWrapper; };
template <> struct CaptureWrapperOf<schema::vulkan::api_elements::VkDescriptorSet> { using type = vulkan_wrappers::DescriptorSetWrapper; };
template <> struct CaptureWrapperOf<schema::vulkan::api_elements::VkDescriptorSetLayout> { using type = vulkan_wrappers::DescriptorSetLayoutWrapper; };
template <> struct CaptureWrapperOf<schema::vulkan::api_elements::VkDescriptorUpdateTemplate> { using type = vulkan_wrappers::DescriptorUpdateTemplateWrapper; };
template <> struct CaptureWrapperOf<schema::vulkan::api_elements::VkDevice> { using type = vulkan_wrappers::DeviceWrapper; };
template <> struct CaptureWrapperOf<schema::vulkan::api_elements::VkDeviceMemory> { using type = vulkan_wrappers::DeviceMemoryWrapper; };
template <> struct CaptureWrapperOf<schema::vulkan::api_elements::VkDisplayKHR> { using type = vulkan_wrappers::DisplayKHRWrapper; };
template <> struct CaptureWrapperOf<schema::vulkan::api_elements::VkDisplayModeKHR> { using type = vulkan_wrappers::DisplayModeKHRWrapper; };
template <> struct CaptureWrapperOf<schema::vulkan::api_elements::VkEvent> { using type = vulkan_wrappers::EventWrapper; };
template <> struct CaptureWrapperOf<schema::vulkan::api_elements::VkFence> { using type = vulkan_wrappers::FenceWrapper; };
template <> struct CaptureWrapperOf<schema::vulkan::api_elements::VkFramebuffer> { using type = vulkan_wrappers::FramebufferWrapper; };
template <> struct CaptureWrapperOf<schema::vulkan::api_elements::VkGpaSessionAMD> { using type = vulkan_wrappers::GpaSessionAMDWrapper; };
template <> struct CaptureWrapperOf<schema::vulkan::api_elements::VkImage> { using type = vulkan_wrappers::ImageWrapper; };
template <> struct CaptureWrapperOf<schema::vulkan::api_elements::VkImageView> { using type = vulkan_wrappers::ImageViewWrapper; };
template <> struct CaptureWrapperOf<schema::vulkan::api_elements::VkIndirectCommandsLayoutEXT> { using type = vulkan_wrappers::IndirectCommandsLayoutEXTWrapper; };
template <> struct CaptureWrapperOf<schema::vulkan::api_elements::VkIndirectCommandsLayoutNV> { using type = vulkan_wrappers::IndirectCommandsLayoutNVWrapper; };
template <> struct CaptureWrapperOf<schema::vulkan::api_elements::VkIndirectExecutionSetEXT> { using type = vulkan_wrappers::IndirectExecutionSetEXTWrapper; };
template <> struct CaptureWrapperOf<schema::vulkan::api_elements::VkInstance> { using type = vulkan_wrappers::InstanceWrapper; };
template <> struct CaptureWrapperOf<schema::vulkan::api_elements::VkMicromapEXT> { using type = vulkan_wrappers::MicromapEXTWrapper; };
template <> struct CaptureWrapperOf<schema::vulkan::api_elements::VkOpticalFlowSessionNV> { using type = vulkan_wrappers::OpticalFlowSessionNVWrapper; };
template <> struct CaptureWrapperOf<schema::vulkan::api_elements::VkPerformanceConfigurationINTEL> { using type = vulkan_wrappers::PerformanceConfigurationINTELWrapper; };
template <> struct CaptureWrapperOf<schema::vulkan::api_elements::VkPhysicalDevice> { using type = vulkan_wrappers::PhysicalDeviceWrapper; };
template <> struct CaptureWrapperOf<schema::vulkan::api_elements::VkPipeline> { using type = vulkan_wrappers::PipelineWrapper; };
template <> struct CaptureWrapperOf<schema::vulkan::api_elements::VkPipelineBinaryKHR> { using type = vulkan_wrappers::PipelineBinaryKHRWrapper; };
template <> struct CaptureWrapperOf<schema::vulkan::api_elements::VkPipelineCache> { using type = vulkan_wrappers::PipelineCacheWrapper; };
template <> struct CaptureWrapperOf<schema::vulkan::api_elements::VkPipelineLayout> { using type = vulkan_wrappers::PipelineLayoutWrapper; };
template <> struct CaptureWrapperOf<schema::vulkan::api_elements::VkPrivateDataSlot> { using type = vulkan_wrappers::PrivateDataSlotWrapper; };
template <> struct CaptureWrapperOf<schema::vulkan::api_elements::VkQueryPool> { using type = vulkan_wrappers::QueryPoolWrapper; };
template <> struct CaptureWrapperOf<schema::vulkan::api_elements::VkQueue> { using type = vulkan_wrappers::QueueWrapper; };
template <> struct CaptureWrapperOf<schema::vulkan::api_elements::VkRenderPass> { using type = vulkan_wrappers::RenderPassWrapper; };
template <> struct CaptureWrapperOf<schema::vulkan::api_elements::VkSampler> { using type = vulkan_wrappers::SamplerWrapper; };
template <> struct CaptureWrapperOf<schema::vulkan::api_elements::VkSamplerYcbcrConversion> { using type = vulkan_wrappers::SamplerYcbcrConversionWrapper; };
template <> struct CaptureWrapperOf<schema::vulkan::api_elements::VkSemaphore> { using type = vulkan_wrappers::SemaphoreWrapper; };
template <> struct CaptureWrapperOf<schema::vulkan::api_elements::VkShaderEXT> { using type = vulkan_wrappers::ShaderEXTWrapper; };
template <> struct CaptureWrapperOf<schema::vulkan::api_elements::VkShaderModule> { using type = vulkan_wrappers::ShaderModuleWrapper; };
template <> struct CaptureWrapperOf<schema::vulkan::api_elements::VkSurfaceKHR> { using type = vulkan_wrappers::SurfaceKHRWrapper; };
template <> struct CaptureWrapperOf<schema::vulkan::api_elements::VkSwapchainKHR> { using type = vulkan_wrappers::SwapchainKHRWrapper; };
template <> struct CaptureWrapperOf<schema::vulkan::api_elements::VkTensorARM> { using type = vulkan_wrappers::TensorARMWrapper; };
template <> struct CaptureWrapperOf<schema::vulkan::api_elements::VkTensorViewARM> { using type = vulkan_wrappers::TensorViewARMWrapper; };
template <> struct CaptureWrapperOf<schema::vulkan::api_elements::VkValidationCacheEXT> { using type = vulkan_wrappers::ValidationCacheEXTWrapper; };
template <> struct CaptureWrapperOf<schema::vulkan::api_elements::VkVideoSessionKHR> { using type = vulkan_wrappers::VideoSessionKHRWrapper; };
template <> struct CaptureWrapperOf<schema::vulkan::api_elements::VkVideoSessionParametersKHR> { using type = vulkan_wrappers::VideoSessionParametersKHRWrapper; };

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_GENERATED_VULKAN_CAPTURE_WRAPPER_OF_H
