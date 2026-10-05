/*
** Copyright (c) 2020-2026 LunarG, Inc.
** Copyright (c) 2021 Advanced Micro Devices, Inc. All rights reserved.
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

#include "decode/vulkan_screenshot_handler.h"
#include "util/image_writer.h"
#include "util/logging.h"
#include "util/platform.h"
#include "graphics/vulkan_resources_util.h"
#include "decode/decoder_util.h"
#include "generated/generated_vulkan_enum_to_string.h"

#include "Vulkan-Utility-Libraries/vk_format_utils.h"

#include <limits>
#include <algorithm>
#include <cinttypes>
#include <cstring>
#include <memory>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

namespace
{

// The image writer takes four bytes for each pixel in this order, thus the
// read-back converts to it and keeps the colour space of the source.
VkFormat ConversionFormat(VkFormat image_format)
{
    return vkuFormatIsSRGB(image_format) ? VK_FORMAT_B8G8R8A8_SRGB : VK_FORMAT_B8G8R8A8_UNORM;
}

} // namespace

Rotation RotationForSurfaceTransform(VkSurfaceTransformFlagBitsKHR pre_transform)
{
    Rotation rotation;

    switch (pre_transform)
    {
        case VK_SURFACE_TRANSFORM_ROTATE_90_BIT_KHR:
        case VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_90_BIT_KHR:
            rotation.rotation = util::imagewriter::ImageRotation::DEG_90;
            break;
        case VK_SURFACE_TRANSFORM_ROTATE_180_BIT_KHR:
        case VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_180_BIT_KHR:
            rotation.rotation = util::imagewriter::ImageRotation::DEG_180;
            break;
        case VK_SURFACE_TRANSFORM_ROTATE_270_BIT_KHR:
        case VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_270_BIT_KHR:
            rotation.rotation = util::imagewriter::ImageRotation::DEG_270;
            break;
        default:
            break;
    }

    rotation.mirrored = (pre_transform == VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_BIT_KHR) ||
                        (pre_transform == VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_90_BIT_KHR) ||
                        (pre_transform == VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_180_BIT_KHR) ||
                        (pre_transform == VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_270_BIT_KHR);

    return rotation;
}

VkImageLayout VulkanScreenshotSource::DetermineLayerLayout(uint32_t layer) const
{
    if (image_.layer_layouts.empty())
    {
        return VK_IMAGE_LAYOUT_UNDEFINED;
    }

    return image_.layer_layouts.size() == 1
               ? image_.layer_layouts.front()
               : image_.layer_layouts[std::min<size_t>(layer, image_.layer_layouts.size() - 1)];
}

bool VulkanScreenshotSource::Readback(const ScreenshotRequest& request, const ReadbackCallbackFn& callback)
{
    if ((request.width == 0) || (request.height == 0))
    {
        GFXRECON_LOG_WARNING("Cannot create a screenshot for a 0 size image (width=%" PRIu32 ", height=%" PRIu32 ").",
                             request.width,
                             request.height);
        return false;
    }

    if (request.layer_count == 0)
    {
        GFXRECON_LOG_WARNING("Cannot create a screenshot of no layers.");
        return false;
    }

    if (!injected_calls_.IsValid() || (device_info_ == nullptr) || (instance_table_ == nullptr))
    {
        GFXRECON_LOG_ERROR("Screenshot could not be created: missing device table or instance table");
        return false;
    }

    // The read-back below is made by replay and is not in the capture file.
    auto injected = injected_calls_.Open();

    graphics::VulkanResourcesUtil resource_util(device_info_->handle,
                                                device_info_->parent,
                                                *injected.GetTable(),
                                                *instance_table_,
                                                device_info_->property_feature_info,
                                                device_info_->version_extension_info,
                                                memory_properties_);

    const VkExtent3D           extent      = { request.width, request.height, 1 };
    const std::array<float, 2> scale       = request.scale.value_or(std::array<float, 2>{ 1.0f, 1.0f });
    const VkFormat             dst_format  = ConversionFormat(image_.format);
    const VkExtent3D           read_extent = graphics::ScaleExtent3DNoDepth(extent, scale);

    // One resource for each layer, thus one command buffer and one queue submit read them all.
    // A resource of its own for each layer also keeps the layout of each layer, which the layers
    // of one image do not have to share.
    std::vector<graphics::VulkanResourcesUtil::ImageResource> resources(request.layer_count);
    for (uint32_t i = 0; i < request.layer_count; ++i)
    {
        graphics::VulkanResourcesUtil::ImageResource& resource = resources[i];

        resource.image              = image_.handle;
        resource.format             = image_.format;
        resource.type               = image_.type;
        resource.extent             = extent;
        resource.level_count        = 1;
        resource.layer_count        = 1;
        resource.base_layer         = request.base_layer + i;
        resource.tiling             = image_.tiling;
        resource.sample_count       = image_.sample_count;
        resource.layout             = DetermineLayerLayout(resource.base_layer);
        resource.queue_family_index = image_.queue_family_index;
        resource.aspect             = VK_IMAGE_ASPECT_COLOR_BIT;
        resource.dst_format         = dst_format;
        resource.scale              = scale;
    }

    // A staging buffer that holds every layer keeps the read to one submit and one wait.  The read
    // converts the format and scales the extent only where the implementation supports it, thus the
    // buffer has to hold whichever of the two the read picks.
    const uint64_t source_size = resource_util.GetImageResourceSizesOptimal(
        image_.format, extent, 1, 1, image_.tiling, VK_IMAGE_ASPECT_COLOR_BIT);
    const uint64_t converted_size = resource_util.GetImageResourceSizesOptimal(
        dst_format, read_extent, 1, 1, image_.tiling, VK_IMAGE_ASPECT_COLOR_BIT);
    const size_t staging_buffer_size = static_cast<size_t>(std::max(source_size, converted_size) * request.layer_count);

    uint32_t layers_read = 0;

    const VkResult result = resource_util.ReadImageResources(
        resources,
        [&](const graphics::VulkanResourcesUtil::ImageResource& resource, const void* data, size_t num_bytes) {
            if ((data == nullptr) || (num_bytes == 0))
            {
                return;
            }

            CpuImage image;
            image.width  = read_extent.width;
            image.height = read_extent.height;
            image.pitch  = 0; // The read-back packs the rows.
            image.format = util::imagewriter::kFormat_BGRA;
            image.pixels = data;

            ++layers_read;
            callback(resource.base_layer, image);
        },
        staging_buffer_size);

    if (result != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("Screenshot could not be created: read failed with %s", util::ToString(result).c_str());
        return false;
    }

    return layers_read > 0;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
