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

#if ENABLE_OPENXR_SUPPORT

#include "decode/openxr_replay_session_state.h"
#include "decode/openxr_replay_swapchain_state.h"
#include "decode/openxr_object_info.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)
GFXRECON_BEGIN_NAMESPACE(openxr)

VulkanGraphicsBinding::VulkanGraphicsBinding(VulkanReplayConsumerBase&                 vulkan_consumer,
                                             const Decoded_XrGraphicsBindingVulkanKHR& xr_binding) :
    XrGraphicsBindingVulkanKHR(*xr_binding.decoded_value),
    vulkan_consumer(&vulkan_consumer), instance_table(vulkan_consumer.GetInstanceTable(physicalDevice)),
    device_table(vulkan_consumer.GetDeviceTable(device)), instance_id(xr_binding.instance), device_id(xr_binding.device)
{
    next = nullptr; // We don't have a safe (deep) copy of the original so stub out the copies downchain pointer

    // Touch up the queue
    device_table->GetDeviceQueue(device, queueFamilyIndex, queueIndex, &queue);
}

XrResult VulkanGraphicsBinding::ResetCommandBuffer(VulkanSwapchainInfo::ProxyImage& proxy) const
{
    XrResult xr_result = XR_SUCCESS;
    uint32_t kTimeout  = std::numeric_limits<uint32_t>::max(); // WIP: Better timeout and timeout reporting
    VkResult vk_result = device_table->WaitForFences(device, 1, &proxy.cb_fence, VK_TRUE, kTimeout);

    if (vk_result != VK_SUCCESS)
    {
        xr_result = XR_ERROR_RUNTIME_FAILURE;

        // WIP: Properly log and handle this
        assert(xr_result == XR_SUCCESS);
    }

    // Create and submit the ILT need to for
    device_table->ResetFences(device, 1, &proxy.cb_fence);
    return xr_result;
}

bool SessionData::AddGraphicsBinding(const GraphicsBinding& binding)
{
    graphics_binding_ = binding;
    return graphics_binding_.IsValid();
}

void SessionData::AddReferenceSpaces(uint32_t count, const XrReferenceSpaceType* replay_spaces)
{
    reference_spaces_.clear();
    for (uint32_t space = 0; space < count; space++)
    {
        reference_spaces_.insert(replay_spaces[space]);
    }
}

void SessionData::AddViewRelativeProxySpace(const encode::OpenXrInstanceTable*  instance_table,
                                            const format::ViewRelativeLocation& location,
                                            const XrSpace                       replay_space)
{

    // View space at view relative location
    XrReferenceSpaceCreateInfo view_relative_ci = { XR_TYPE_REFERENCE_SPACE_CREATE_INFO,
                                                    nullptr,
                                                    XR_REFERENCE_SPACE_TYPE_VIEW,
                                                    { { location.qx, location.qy, location.qz, location.qw },
                                                      { location.x, location.y, location.z } } };

    XrSpace view_relative_space = XR_NULL_HANDLE;
    // TODO: Cleanup this reference space object at DestroySession time
    XrResult result = instance_table->CreateReferenceSpace(handle_, &view_relative_ci, &view_relative_space);

    if (XR_SUCCEEDED(result))
    {
        proxy_spaces_[replay_space] = view_relative_space;
    }
    else
    {
        GFXRECON_LOG_WARNING("Unable to create view relative space for  %" PRIu64, location.space_id);
    }
}

void SessionData::ClearViewRelativeProxySpaces(const encode::OpenXrInstanceTable* instance_table)
{
    assert(instance_table);
    for (const auto& proxy : proxy_spaces_)
    {
        if (proxy.second != XR_NULL_HANDLE)
        {
            instance_table->DestroySpace(proxy.second);
        }
    }
    proxy_spaces_.clear();
}

void SessionData::ClearSwapchains(CommonObjectInfoTable& table)
{
    for (format::HandleId swapchain : swapchains_)
    {
        OpenXrSwapchainInfo* swapchain_data = table.GetXrSwapchainInfo(swapchain);
        assert((swapchain_data != nullptr) && swapchain_data->replay_data);
        swapchain_data->replay_data->Clear();
    }
    swapchains_.clear();
}

void SessionData::RemapFrameEndSpaces(XrFrameEndInfo& frame_end_info)
{
    const XrCompositionLayerBaseHeader* const* layers = frame_end_info.layers;
    if (!layers)
        return;

    // Replace all spaces in the composition layer with view relative proxies
    for (uint32_t layer_index = 0; layer_index < frame_end_info.layerCount; layer_index++)
    {
        XrCompositionLayerBaseHeader* layer = const_cast<XrCompositionLayerBaseHeader*>(layers[layer_index]);
        if (layer && (layer->space != XR_NULL_HANDLE))
        {
            auto found_it = proxy_spaces_.find(layer->space);
            if (found_it != proxy_spaces_.end())
            {
                layer->space = found_it->second;
            }
        }
    }
}

GFXRECON_END_NAMESPACE(openxr)
GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT
