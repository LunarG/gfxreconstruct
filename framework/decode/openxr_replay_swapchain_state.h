/*
** Copyright (c) 2024 LunarG, Inc.
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

#ifndef GFXRECON_DECODE_OPENXR_REPLAY_SWAPCHAIN_STATE_H
#define GFXRECON_DECODE_OPENXR_REPLAY_SWAPCHAIN_STATE_H
#include <deque>

#include "decode/openxr_replay_session_state.h"

#if ENABLE_OPENXR_SUPPORT

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)
GFXRECON_BEGIN_NAMESPACE(openxr)

struct SwapchainGraphicsInfo
{
    GraphicsBindingType                type = GraphicsBindingType::kUnknown;
    std::optional<VulkanSwapchainInfo> vulkan_info;
};

class SwapchainData : public BaseReplayData<XrSwapchain>
{
    using Base = BaseReplayData<XrSwapchain>;

  public:
    SwapchainData(XrSwapchain swapchain) : Base(swapchain) {}
    void
    InitSwapchainData(const GraphicsBinding& binding, const XrSwapchainCreateInfo& info, XrSwapchain replay_handle);
    XrResult ImportReplaySwapchain(StructPointerDecoder<Decoded_XrSwapchainImageBaseHeader>* images);
    XrResult InitVirtualSwapchain(PointerDecoder<uint32_t>*                                 imageCountOutput,
                                  StructPointerDecoder<Decoded_XrSwapchainImageBaseHeader>* capture_images);
    XrResult InitVirtualSwapchain(PointerDecoder<uint32_t>*                                imageCountOutput,
                                  StructPointerDecoder<Decoded_XrSwapchainImageVulkanKHR>* vk_capture_images);
    XrResult AcquireSwapchainImage(uint32_t capture_index, uint32_t replay_index);
    XrResult ReleaseSwapchainImage(StructPointerDecoder<Decoded_XrSwapchainImageReleaseInfo>* releaseInfo);
    void     WaitedWithoutTimeout();

  protected:
    static void MapVulkanSwapchainImageFlags(XrSwapchainUsageFlags xr_flags, VkImageCreateInfo& info);
    XrResult    InitSwapchainData(const XrSwapchainCreateInfo& xr_info, VulkanSwapchainInfo& vk_info);
    XrResult    AcquireSwapchainImage(uint32_t capture_index, uint32_t replay_index, VulkanSwapchainInfo& swap_info);
    XrResult    ReleaseSwapchainImage(StructPointerDecoder<Decoded_XrSwapchainImageReleaseInfo>* releaseInfo,
                                      VulkanSwapchainInfo&                                       swap_info);

    XrSwapchain                            swapchain_;
    XrSwapchainCreateInfo                  create_info_;
    std::unordered_map<uint32_t, uint32_t> capture_to_replay_map_;
    std::deque<uint32_t>                   acquire_release_fifo_;
    SwapchainGraphicsInfo                  swapchain_graphics_info_;
    const GraphicsBinding*                 graphics_binding_ = nullptr;
};

GFXRECON_END_NAMESPACE(openxr)
GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
#endif // ENABLE_OPENXR_SUPPORT

#endif // GFXRECON_DECODE_OPENXR_REPLAY_SWAPCHAIN_STATE_H
