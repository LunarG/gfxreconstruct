/*
** Copyright (c) 2026 LunarG, Inc.
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

#include "decode/vulkan_replay_frame_loop_consumer.h"

#include "generated/generated_vulkan_replay_consumer.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void VulkanReplayFrameLoopConsumer::ProcessFrameEndMarker(uint64_t frame_number)
{
    VulkanReplayConsumer::ProcessFrameEndMarker(frame_number);

    if (frame_number == target_frame_)
    {
        in_loop_mode_ = loop_count_ > 0;
        loop_count_--;
    }

    if (in_loop_mode_)
    {
        WaitDevicesIdle();
        bool success = GetApplication().GetFileProcessor()->RewindOneFrame();
        GFXRECON_ASSERT(success);
        GFXRECON_LOG_INFO("Replaying frame %llu again", frame_number);
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkCreateInstance(
    const ApiCallInfo&                                   call_info,
    VkResult                                             returnValue,
    StructPointerDecoder<Decoded_VkInstanceCreateInfo>*  pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkInstance>*                    pInstance)
{
    if (in_loop_mode_)
    {
        // When repeating a frame, the instance has already been created during the first iteration of the frame.
        return;
    }

    VulkanReplayConsumer::Process_vkCreateInstance(call_info, returnValue, pCreateInfo, pAllocator, pInstance);
}

void VulkanReplayFrameLoopConsumer::Process_vkCreateXlibSurfaceKHR(
    const ApiCallInfo&                                        call_info,
    VkResult                                                  returnValue,
    format::HandleId                                          instance,
    StructPointerDecoder<Decoded_VkXlibSurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*      pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*                       pSurface)
{
    if (in_loop_mode_)
    {
        // When repeating a frame, the surface has already been created during the first iteration of the frame.
        return;
    }

    VulkanReplayConsumer::Process_vkCreateXlibSurfaceKHR(
        call_info, returnValue, instance, pCreateInfo, pAllocator, pSurface);
}

void VulkanReplayFrameLoopConsumer::Process_vkCreateXcbSurfaceKHR(
    const ApiCallInfo&                                       call_info,
    VkResult                                                 returnValue,
    format::HandleId                                         instance,
    StructPointerDecoder<Decoded_VkXcbSurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*     pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*                      pSurface)
{
    if (in_loop_mode_)
    {
        // When repeating a frame, the surface has already been created during the first iteration of the frame.
        return;
    }

    VulkanReplayConsumer::Process_vkCreateXcbSurfaceKHR(
        call_info, returnValue, instance, pCreateInfo, pAllocator, pSurface);
}

void VulkanReplayFrameLoopConsumer::Process_vkCreateWaylandSurfaceKHR(
    const ApiCallInfo&                                           call_info,
    VkResult                                                     returnValue,
    format::HandleId                                             instance,
    StructPointerDecoder<Decoded_VkWaylandSurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*         pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*                          pSurface)
{
    if (in_loop_mode_)
    {
        // When repeating a frame, the surface has already been created during the first iteration of the frame.
        return;
    }

    VulkanReplayConsumer::Process_vkCreateWaylandSurfaceKHR(
        call_info, returnValue, instance, pCreateInfo, pAllocator, pSurface);
}

void VulkanReplayFrameLoopConsumer::Process_vkCreateAndroidSurfaceKHR(
    const ApiCallInfo&                                           call_info,
    VkResult                                                     returnValue,
    format::HandleId                                             instance,
    StructPointerDecoder<Decoded_VkAndroidSurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*         pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*                          pSurface)
{
    if (in_loop_mode_)
    {
        // When repeating a frame, the surface has already been created during the first iteration of the frame.
        return;
    }

    VulkanReplayConsumer::Process_vkCreateAndroidSurfaceKHR(
        call_info, returnValue, instance, pCreateInfo, pAllocator, pSurface);
}

void VulkanReplayFrameLoopConsumer::Process_vkCreateWin32SurfaceKHR(
    const ApiCallInfo&                                         call_info,
    VkResult                                                   returnValue,
    format::HandleId                                           instance,
    StructPointerDecoder<Decoded_VkWin32SurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*       pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*                        pSurface)
{
    if (in_loop_mode_)
    {
        // When repeating a frame, the surface has already been created during the first iteration of the frame.
        return;
    }
    VulkanReplayConsumer::Process_vkCreateWin32SurfaceKHR(
        call_info, returnValue, instance, pCreateInfo, pAllocator, pSurface);
}

void VulkanReplayFrameLoopConsumer::Process_vkCreateMetalSurfaceEXT(
    const ApiCallInfo&                                         call_info,
    VkResult                                                   returnValue,
    format::HandleId                                           instance,
    StructPointerDecoder<Decoded_VkMetalSurfaceCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*       pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*                        pSurface)
{
    if (in_loop_mode_)
    {
        // When repeating a frame, the surface has already been created during the first iteration of the frame.
        return;
    }

    VulkanReplayConsumer::Process_vkCreateMetalSurfaceEXT(
        call_info, returnValue, instance, pCreateInfo, pAllocator, pSurface);
}

void VulkanReplayFrameLoopConsumer::Process_vkCreateHeadlessSurfaceEXT(
    const ApiCallInfo&                                            call_info,
    VkResult                                                      returnValue,
    format::HandleId                                              instance,
    StructPointerDecoder<Decoded_VkHeadlessSurfaceCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*          pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*                           pSurface)
{
    if (in_loop_mode_)
    {
        // When repeating a frame, the surface has already been created during the first iteration of the frame.
        return;
    }

    VulkanReplayConsumer::Process_vkCreateHeadlessSurfaceEXT(
        call_info, returnValue, instance, pCreateInfo, pAllocator, pSurface);
}

void VulkanReplayFrameLoopConsumer::Process_vkCreateDirectFBSurfaceEXT(
    const ApiCallInfo&                                            call_info,
    VkResult                                                      returnValue,
    format::HandleId                                              instance,
    StructPointerDecoder<Decoded_VkDirectFBSurfaceCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*          pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*                           pSurface)
{
    if (in_loop_mode_)
    {
        // When repeating a frame, the surface has already been created during the first iteration of the frame.
        return;
    }

    VulkanReplayConsumer::Process_vkCreateDirectFBSurfaceEXT(
        call_info, returnValue, instance, pCreateInfo, pAllocator, pSurface);
}

void VulkanReplayFrameLoopConsumer::Process_vkCreateScreenSurfaceQNX(
    const ApiCallInfo&                                          call_info,
    VkResult                                                    returnValue,
    format::HandleId                                            instance,
    StructPointerDecoder<Decoded_VkScreenSurfaceCreateInfoQNX>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*        pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*                         pSurface)
{
    if (in_loop_mode_)
    {
        // When repeating a frame, the surface has already been created during the first iteration of the frame.
        return;
    }

    VulkanReplayConsumer::Process_vkCreateScreenSurfaceQNX(
        call_info, returnValue, instance, pCreateInfo, pAllocator, pSurface);
}

void VulkanReplayFrameLoopConsumer::Process_vkCreateDisplayPlaneSurfaceKHR(
    const ApiCallInfo&                                           call_info,
    VkResult                                                     returnValue,
    format::HandleId                                             instance,
    StructPointerDecoder<Decoded_VkDisplaySurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*         pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*                          pSurface)
{
    if (in_loop_mode_)
    {
        // When repeating a frame, the surface has already been created during the first iteration of the frame.
        return;
    }

    VulkanReplayConsumer::Process_vkCreateDisplayPlaneSurfaceKHR(
        call_info, returnValue, instance, pCreateInfo, pAllocator, pSurface);
}

void VulkanReplayFrameLoopConsumer::Process_vkCreateDevice(
    const ApiCallInfo&                                   call_info,
    VkResult                                             returnValue,
    format::HandleId                                     physicalDevice,
    StructPointerDecoder<Decoded_VkDeviceCreateInfo>*    pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDevice>*                      pDevice)
{
    if (in_loop_mode_)
    {
        // When repeating a frame, the device has already been created during the first iteration of the frame.
        return;
    }
    VulkanReplayConsumer::Process_vkCreateDevice(
        call_info, returnValue, physicalDevice, pCreateInfo, pAllocator, pDevice);
}

void VulkanReplayFrameLoopConsumer::Process_vkCreateSwapchainKHR(
    const ApiCallInfo&                                      call_info,
    VkResult                                                returnValue,
    format::HandleId                                        device,
    StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*    pAllocator,
    HandlePointerDecoder<VkSwapchainKHR>*                   pSwapchain)
{
    if (in_loop_mode_)
    {
        // When repeating a frame, the swapchain has already been created during the first iteration of the frame.
        return;
    }

    VulkanReplayConsumer::Process_vkCreateSwapchainKHR(
        call_info, returnValue, device, pCreateInfo, pAllocator, pSwapchain);
}

void VulkanFrameLoopReplayConsumer::ProcessCreateHardwareBufferCommand(
    format::HandleId                                    device_id,
    format::HandleId                                    memory_id,
    uint64_t                                            buffer_id,
    uint32_t                                            format,
    uint32_t                                            width,
    uint32_t                                            height,
    uint32_t                                            stride,
    uint64_t                                            usage,
    uint32_t                                            layers,
    const std::vector<format::HardwareBufferPlaneInfo>& plane_info)
{
    if (in_loop_mode_)
    {
        // When repeating a frame, the hardware buffer has already been created during the first iteration of the frame.
        return;
    }

    VulkanReplayConsumer::ProcessCreateHardwareBufferCommand(
        device_id, memory_id, buffer_id, format, width, height, stride, usage, layers, plane_info);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
