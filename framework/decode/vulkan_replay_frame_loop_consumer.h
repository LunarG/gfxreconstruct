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

#ifndef GFXRECON_DECODE_VULKAN_REPLAY_FRAME_LOOP_CONSUMER_H
#define GFXRECON_DECODE_VULKAN_REPLAY_FRAME_LOOP_CONSUMER_H

#include "util/defines.h"
#include "generated/generated_vulkan_replay_consumer.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class VulkanReplayFrameLoopConsumer : public VulkanReplayConsumer
{
  public:
    VulkanReplayFrameLoopConsumer(std::shared_ptr<application::Application> application,
                                  const VulkanReplayOptions&                options,
                                  graphics::FrameLoopInfo&                  frame_loop_info) :
        VulkanReplayConsumer(application, options),
        frame_loop_info_(frame_loop_info)
    {}

    void Process_vkCreateInstance(const ApiCallInfo&                                   call_info,
                                  VkResult                                             returnValue,
                                  StructPointerDecoder<Decoded_VkInstanceCreateInfo>*  pCreateInfo,
                                  StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                                  HandlePointerDecoder<VkInstance>*                    pInstance) override;

    void Process_vkCreateXlibSurfaceKHR(const ApiCallInfo&                                        call_info,
                                        VkResult                                                  returnValue,
                                        format::HandleId                                          instance,
                                        StructPointerDecoder<Decoded_VkXlibSurfaceCreateInfoKHR>* pCreateInfo,
                                        StructPointerDecoder<Decoded_VkAllocationCallbacks>*      pAllocator,
                                        HandlePointerDecoder<VkSurfaceKHR>*                       pSurface) override;

    void Process_vkCreateXcbSurfaceKHR(const ApiCallInfo&                                       call_info,
                                       VkResult                                                 returnValue,
                                       format::HandleId                                         instance,
                                       StructPointerDecoder<Decoded_VkXcbSurfaceCreateInfoKHR>* pCreateInfo,
                                       StructPointerDecoder<Decoded_VkAllocationCallbacks>*     pAllocator,
                                       HandlePointerDecoder<VkSurfaceKHR>*                      pSurface) override;

    void Process_vkCreateWaylandSurfaceKHR(const ApiCallInfo&                                           call_info,
                                           VkResult                                                     returnValue,
                                           format::HandleId                                             instance,
                                           StructPointerDecoder<Decoded_VkWaylandSurfaceCreateInfoKHR>* pCreateInfo,
                                           StructPointerDecoder<Decoded_VkAllocationCallbacks>*         pAllocator,
                                           HandlePointerDecoder<VkSurfaceKHR>* pSurface) override;

    void Process_vkCreateAndroidSurfaceKHR(const ApiCallInfo&                                           call_info,
                                           VkResult                                                     returnValue,
                                           format::HandleId                                             instance,
                                           StructPointerDecoder<Decoded_VkAndroidSurfaceCreateInfoKHR>* pCreateInfo,
                                           StructPointerDecoder<Decoded_VkAllocationCallbacks>*         pAllocator,
                                           HandlePointerDecoder<VkSurfaceKHR>* pSurface) override;

    void Process_vkCreateWin32SurfaceKHR(const ApiCallInfo&                                         call_info,
                                         VkResult                                                   returnValue,
                                         format::HandleId                                           instance,
                                         StructPointerDecoder<Decoded_VkWin32SurfaceCreateInfoKHR>* pCreateInfo,
                                         StructPointerDecoder<Decoded_VkAllocationCallbacks>*       pAllocator,
                                         HandlePointerDecoder<VkSurfaceKHR>*                        pSurface) override;

    void Process_vkCreateMetalSurfaceEXT(const ApiCallInfo&                                         call_info,
                                         VkResult                                                   returnValue,
                                         format::HandleId                                           instance,
                                         StructPointerDecoder<Decoded_VkMetalSurfaceCreateInfoEXT>* pCreateInfo,
                                         StructPointerDecoder<Decoded_VkAllocationCallbacks>*       pAllocator,
                                         HandlePointerDecoder<VkSurfaceKHR>*                        pSurface) override;

    void Process_vkCreateHeadlessSurfaceEXT(const ApiCallInfo&                                            call_info,
                                            VkResult                                                      returnValue,
                                            format::HandleId                                              instance,
                                            StructPointerDecoder<Decoded_VkHeadlessSurfaceCreateInfoEXT>* pCreateInfo,
                                            StructPointerDecoder<Decoded_VkAllocationCallbacks>*          pAllocator,
                                            HandlePointerDecoder<VkSurfaceKHR>* pSurface) override;

    void Process_vkCreateDirectFBSurfaceEXT(const ApiCallInfo&                                            call_info,
                                            VkResult                                                      returnValue,
                                            format::HandleId                                              instance,
                                            StructPointerDecoder<Decoded_VkDirectFBSurfaceCreateInfoEXT>* pCreateInfo,
                                            StructPointerDecoder<Decoded_VkAllocationCallbacks>*          pAllocator,
                                            HandlePointerDecoder<VkSurfaceKHR>* pSurface) override;

    void Process_vkCreateScreenSurfaceQNX(const ApiCallInfo&                                          call_info,
                                          VkResult                                                    returnValue,
                                          format::HandleId                                            instance,
                                          StructPointerDecoder<Decoded_VkScreenSurfaceCreateInfoQNX>* pCreateInfo,
                                          StructPointerDecoder<Decoded_VkAllocationCallbacks>*        pAllocator,
                                          HandlePointerDecoder<VkSurfaceKHR>* pSurface) override;

    void
    Process_vkCreateDisplayPlaneSurfaceKHR(const ApiCallInfo&                                           call_info,
                                           VkResult                                                     returnValue,
                                           format::HandleId                                             instance,
                                           StructPointerDecoder<Decoded_VkDisplaySurfaceCreateInfoKHR>* pCreateInfo,
                                           StructPointerDecoder<Decoded_VkAllocationCallbacks>*         pAllocator,
                                           HandlePointerDecoder<VkSurfaceKHR>* pSurface) override;

    void Process_vkCreateDevice(const ApiCallInfo&                                   call_info,
                                VkResult                                             returnValue,
                                format::HandleId                                     physicalDevice,
                                StructPointerDecoder<Decoded_VkDeviceCreateInfo>*    pCreateInfo,
                                StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                                HandlePointerDecoder<VkDevice>*                      pDevice) override;

    void Process_vkCreateSwapchainKHR(const ApiCallInfo&                                      call_info,
                                      VkResult                                                returnValue,
                                      format::HandleId                                        device,
                                      StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>* pCreateInfo,
                                      StructPointerDecoder<Decoded_VkAllocationCallbacks>*    pAllocator,
                                      HandlePointerDecoder<VkSwapchainKHR>*                   pSwapchain) override;

    void ProcessCreateHardwareBufferCommand(format::HandleId                                    device_id,
                                            format::HandleId                                    memory_id,
                                            uint64_t                                            buffer_id,
                                            uint32_t                                            format,
                                            uint32_t                                            width,
                                            uint32_t                                            height,
                                            uint32_t                                            stride,
                                            uint64_t                                            usage,
                                            uint32_t                                            layers,
                                            const std::vector<format::HardwareBufferPlaneInfo>& plane_info) override;

  private:
    graphics::FrameLoopInfo& frame_loop_info_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_REPLAY_FRAME_LOOP_CONSUMER_H
