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

#ifndef  GFXRECON_GENERATED_VULKAN_ENCODE_CAPTURE_WRAPPERS_H
#define  GFXRECON_GENERATED_VULKAN_ENCODE_CAPTURE_WRAPPERS_H

#include "encode/vulkan_encode_capture_wrappers.h"
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

GFXRECON_VULKAN_CAPTURE_WRAPPER_FOR(VkAccelerationStructureKHR, AccelerationStructureKHRWrapper);
GFXRECON_VULKAN_CAPTURE_WRAPPER_FOR(VkAccelerationStructureNV, AccelerationStructureNVWrapper);
GFXRECON_VULKAN_CAPTURE_WRAPPER_FOR(VkBuffer, BufferWrapper);
GFXRECON_VULKAN_CAPTURE_WRAPPER_FOR(VkBufferView, BufferViewWrapper);
GFXRECON_VULKAN_CAPTURE_WRAPPER_FOR(VkCommandBuffer, CommandBufferWrapper);
GFXRECON_VULKAN_CAPTURE_WRAPPER_FOR(VkCommandPool, CommandPoolWrapper);
GFXRECON_VULKAN_CAPTURE_WRAPPER_FOR(VkDataGraphPipelineSessionARM, DataGraphPipelineSessionARMWrapper);
GFXRECON_VULKAN_CAPTURE_WRAPPER_FOR(VkDebugReportCallbackEXT, DebugReportCallbackEXTWrapper);
GFXRECON_VULKAN_CAPTURE_WRAPPER_FOR(VkDebugUtilsMessengerEXT, DebugUtilsMessengerEXTWrapper);
GFXRECON_VULKAN_CAPTURE_WRAPPER_FOR(VkDeferredOperationKHR, DeferredOperationKHRWrapper);
GFXRECON_VULKAN_CAPTURE_WRAPPER_FOR(VkDescriptorPool, DescriptorPoolWrapper);
GFXRECON_VULKAN_CAPTURE_WRAPPER_FOR(VkDescriptorSet, DescriptorSetWrapper);
GFXRECON_VULKAN_CAPTURE_WRAPPER_FOR(VkDescriptorSetLayout, DescriptorSetLayoutWrapper);
GFXRECON_VULKAN_CAPTURE_WRAPPER_FOR(VkDescriptorUpdateTemplate, DescriptorUpdateTemplateWrapper);
GFXRECON_VULKAN_CAPTURE_WRAPPER_FOR(VkDevice, DeviceWrapper);
GFXRECON_VULKAN_CAPTURE_WRAPPER_FOR(VkDeviceMemory, DeviceMemoryWrapper);
GFXRECON_VULKAN_CAPTURE_WRAPPER_FOR(VkDisplayKHR, DisplayKHRWrapper);
GFXRECON_VULKAN_CAPTURE_WRAPPER_FOR(VkDisplayModeKHR, DisplayModeKHRWrapper);
GFXRECON_VULKAN_CAPTURE_WRAPPER_FOR(VkEvent, EventWrapper);
GFXRECON_VULKAN_CAPTURE_WRAPPER_FOR(VkFence, FenceWrapper);
GFXRECON_VULKAN_CAPTURE_WRAPPER_FOR(VkFramebuffer, FramebufferWrapper);
GFXRECON_VULKAN_CAPTURE_WRAPPER_FOR(VkGpaSessionAMD, GpaSessionAMDWrapper);
GFXRECON_VULKAN_CAPTURE_WRAPPER_FOR(VkImage, ImageWrapper);
GFXRECON_VULKAN_CAPTURE_WRAPPER_FOR(VkImageView, ImageViewWrapper);
GFXRECON_VULKAN_CAPTURE_WRAPPER_FOR(VkIndirectCommandsLayoutEXT, IndirectCommandsLayoutEXTWrapper);
GFXRECON_VULKAN_CAPTURE_WRAPPER_FOR(VkIndirectCommandsLayoutNV, IndirectCommandsLayoutNVWrapper);
GFXRECON_VULKAN_CAPTURE_WRAPPER_FOR(VkIndirectExecutionSetEXT, IndirectExecutionSetEXTWrapper);
GFXRECON_VULKAN_CAPTURE_WRAPPER_FOR(VkInstance, InstanceWrapper);
GFXRECON_VULKAN_CAPTURE_WRAPPER_FOR(VkMicromapEXT, MicromapEXTWrapper);
GFXRECON_VULKAN_CAPTURE_WRAPPER_FOR(VkOpticalFlowSessionNV, OpticalFlowSessionNVWrapper);
GFXRECON_VULKAN_CAPTURE_WRAPPER_FOR(VkPerformanceConfigurationINTEL, PerformanceConfigurationINTELWrapper);
GFXRECON_VULKAN_CAPTURE_WRAPPER_FOR(VkPhysicalDevice, PhysicalDeviceWrapper);
GFXRECON_VULKAN_CAPTURE_WRAPPER_FOR(VkPipeline, PipelineWrapper);
GFXRECON_VULKAN_CAPTURE_WRAPPER_FOR(VkPipelineBinaryKHR, PipelineBinaryKHRWrapper);
GFXRECON_VULKAN_CAPTURE_WRAPPER_FOR(VkPipelineCache, PipelineCacheWrapper);
GFXRECON_VULKAN_CAPTURE_WRAPPER_FOR(VkPipelineLayout, PipelineLayoutWrapper);
GFXRECON_VULKAN_CAPTURE_WRAPPER_FOR(VkPrivateDataSlot, PrivateDataSlotWrapper);
GFXRECON_VULKAN_CAPTURE_WRAPPER_FOR(VkQueryPool, QueryPoolWrapper);
GFXRECON_VULKAN_CAPTURE_WRAPPER_FOR(VkQueue, QueueWrapper);
GFXRECON_VULKAN_CAPTURE_WRAPPER_FOR(VkRenderPass, RenderPassWrapper);
GFXRECON_VULKAN_CAPTURE_WRAPPER_FOR(VkSampler, SamplerWrapper);
GFXRECON_VULKAN_CAPTURE_WRAPPER_FOR(VkSamplerYcbcrConversion, SamplerYcbcrConversionWrapper);
GFXRECON_VULKAN_CAPTURE_WRAPPER_FOR(VkSemaphore, SemaphoreWrapper);
GFXRECON_VULKAN_CAPTURE_WRAPPER_FOR(VkShaderEXT, ShaderEXTWrapper);
GFXRECON_VULKAN_CAPTURE_WRAPPER_FOR(VkShaderModule, ShaderModuleWrapper);
GFXRECON_VULKAN_CAPTURE_WRAPPER_FOR(VkSurfaceKHR, SurfaceKHRWrapper);
GFXRECON_VULKAN_CAPTURE_WRAPPER_FOR(VkSwapchainKHR, SwapchainKHRWrapper);
GFXRECON_VULKAN_CAPTURE_WRAPPER_FOR(VkTensorARM, TensorARMWrapper);
GFXRECON_VULKAN_CAPTURE_WRAPPER_FOR(VkTensorViewARM, TensorViewARMWrapper);
GFXRECON_VULKAN_CAPTURE_WRAPPER_FOR(VkValidationCacheEXT, ValidationCacheEXTWrapper);
GFXRECON_VULKAN_CAPTURE_WRAPPER_FOR(VkVideoSessionKHR, VideoSessionKHRWrapper);
GFXRECON_VULKAN_CAPTURE_WRAPPER_FOR(VkVideoSessionParametersKHR, VideoSessionParametersKHRWrapper);

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_GENERATED_VULKAN_ENCODE_CAPTURE_WRAPPERS_H
