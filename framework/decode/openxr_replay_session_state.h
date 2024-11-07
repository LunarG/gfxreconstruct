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

#ifndef GFXRECON_DECODE_OPENXR_REPLAY_SESSION_STATE_H
#define GFXRECON_DECODE_OPENXR_REPLAY_SESSION_STATE_H

#if ENABLE_OPENXR_SUPPORT

#include <optional>
#include <unordered_map>
#include <unordered_set>
#include "application/application.h"
#include "generated/generated_openxr_struct_decoders.h"
#include "decode/openxr_replay_common_state.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)
GFXRECON_BEGIN_NAMESPACE(openxr)

// Virtual swapchain information
struct VulkanSwapchainInfo
{

    // Structure necessary to track the necessary information related to the virtual swapchain images
    struct ProxyImage
    {
        VkImage         image{ VK_NULL_HANDLE };
        VkDeviceMemory  memory{ VK_NULL_HANDLE };
        VkFence         cb_fence{ VK_NULL_HANDLE };
        VkCommandBuffer command_buffer{ VK_NULL_HANDLE };
    };

    VkImageCreateInfo               image_create_info{ VK_STRUCTURE_TYPE_MAX_ENUM };
    VkImageSubresourceRange         whole_range;
    VkImageLayout                   layout;
    XrVulkanSwapchainCreateInfoMETA xr_info_meta{ XR_TYPE_UNKNOWN }; // Backing store for deep copy

    std::vector<ProxyImage>                proxy_images;
    std::vector<XrSwapchainImageVulkanKHR> replay_images;
    VkCommandPool                          command_pool = VK_NULL_HANDLE;
};

struct VulkanGraphicsBinding : public XrGraphicsBindingVulkanKHR
{
    VulkanGraphicsBinding(VulkanReplayConsumerBase& vulkan_consumer, const Decoded_XrGraphicsBindingVulkanKHR& xr);
    VulkanReplayConsumerBase*          vulkan_consumer = nullptr;
    const encode::VulkanInstanceTable* instance_table{ nullptr };
    const encode::VulkanDeviceTable*   device_table{ nullptr };
    format::HandleId                   instance_id{ format::kNullHandleId };
    format::HandleId                   device_id{ format::kNullHandleId };
    VkQueue                            queue = VK_NULL_HANDLE;

    XrResult ResetCommandBuffer(VulkanSwapchainInfo::ProxyImage& proxy) const;
};

class GraphicsBinding
{
  public:
    GraphicsBinding() : type(GraphicsBindingType::kUnknown){};
    GraphicsBinding(const VulkanGraphicsBinding& binding) : type(GraphicsBindingType::kVulkan)
    {
        vulkan_binding.emplace(binding);
    }
    GraphicsBindingType GetType() const { return type; }
    bool                IsValid() const { return type != GraphicsBindingType::kUnknown; }
    bool                IsVulkan() const { return type == GraphicsBindingType::kVulkan; }

    const VulkanGraphicsBinding& GetVulkanBinding() const
    {
        assert(type == GraphicsBindingType::kVulkan);
        assert(vulkan_binding.has_value());
        return *vulkan_binding;
    }

  private:
    GraphicsBindingType type;

    // NOTE: Add other supported bindings here
    std::optional<VulkanGraphicsBinding> vulkan_binding;
};

class SessionData : public BaseReplayData<XrSession>
{
    using Base = BaseReplayData<XrSession>;

  public:
    using ReferenceSpaceSet         = std::unordered_set<XrReferenceSpaceType>;
    using ViewRelativeProxySpaceMap = std::unordered_map<XrSpace, XrSpace>;

    SessionData(XrSession session) : Base(session) {}
    bool                   AddGraphicsBinding(const GraphicsBinding& binding);
    const GraphicsBinding& GetGraphicsBinding() const { return graphics_binding_; }

    void   AddReferenceSpaces(uint32_t count, const XrReferenceSpaceType* replay_spaces);
    void   SetDisplayTime(const XrTime& predicted) { last_display_time_ = predicted; }
    XrTime GetDisplayTime() const { return last_display_time_; }

    void AddViewRelativeProxySpace(const encode::OpenXrInstanceTable*  instance_table,
                                   const format::ViewRelativeLocation& location,
                                   XrSpace                             replay_space);
    void ClearViewRelativeProxySpaces(const encode::OpenXrInstanceTable* instance_table);
    void ClearSwapchains(CommonObjectInfoTable& table);

    void RemapFrameEndSpaces(XrFrameEndInfo& frame_end_info);
    void AddSwapchain(format::HandleId swapchain) { swapchains_.insert(swapchain); }
    void RemoveSwapchain(format::HandleId swapchain) { swapchains_.erase(swapchain); }

  protected:
    ReferenceSpaceSet         reference_spaces_;
    ViewRelativeProxySpaceMap proxy_spaces_;

    XrTime last_display_time_ = XrTime();

    // These are the replay handles
    GraphicsBinding graphics_binding_;
    std::unordered_set<format::HandleId> swapchains_;
};

GFXRECON_END_NAMESPACE(openxr)
GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
#endif // ENABLE_OPENXR_SUPPORT

#endif // GFXRECON_DECODE_OPENXR_REPLAY_SESSION_STATE_H
