/*
** Copyright (c) 2020 LunarG, Inc.
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

#include <limits>
#include <algorithm>
#include <cstring>
#include <memory>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

namespace
{

bool IsSrgbFormat(VkFormat image_format)
{
    switch (image_format)
    {
        case VK_FORMAT_R8_SRGB:
        case VK_FORMAT_R8G8_SRGB:
        case VK_FORMAT_R8G8B8_SRGB:
        case VK_FORMAT_B8G8R8_SRGB:
        case VK_FORMAT_R8G8B8A8_SRGB:
        case VK_FORMAT_B8G8R8A8_SRGB:
        case VK_FORMAT_A8B8G8R8_SRGB_PACK32:
        case VK_FORMAT_BC1_RGB_SRGB_BLOCK:
        case VK_FORMAT_BC1_RGBA_SRGB_BLOCK:
        case VK_FORMAT_BC2_SRGB_BLOCK:
        case VK_FORMAT_BC3_SRGB_BLOCK:
        case VK_FORMAT_BC7_SRGB_BLOCK:
        case VK_FORMAT_ETC2_R8G8B8_SRGB_BLOCK:
        case VK_FORMAT_ETC2_R8G8B8A1_SRGB_BLOCK:
        case VK_FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK:
        case VK_FORMAT_ASTC_4x4_SRGB_BLOCK:
        case VK_FORMAT_ASTC_5x4_SRGB_BLOCK:
        case VK_FORMAT_ASTC_5x5_SRGB_BLOCK:
        case VK_FORMAT_ASTC_6x5_SRGB_BLOCK:
        case VK_FORMAT_ASTC_6x6_SRGB_BLOCK:
        case VK_FORMAT_ASTC_8x5_SRGB_BLOCK:
        case VK_FORMAT_ASTC_8x6_SRGB_BLOCK:
        case VK_FORMAT_ASTC_8x8_SRGB_BLOCK:
        case VK_FORMAT_ASTC_10x5_SRGB_BLOCK:
        case VK_FORMAT_ASTC_10x6_SRGB_BLOCK:
        case VK_FORMAT_ASTC_10x8_SRGB_BLOCK:
        case VK_FORMAT_ASTC_10x10_SRGB_BLOCK:
        case VK_FORMAT_ASTC_12x10_SRGB_BLOCK:
        case VK_FORMAT_ASTC_12x12_SRGB_BLOCK:
        case VK_FORMAT_PVRTC1_2BPP_SRGB_BLOCK_IMG:
        case VK_FORMAT_PVRTC1_4BPP_SRGB_BLOCK_IMG:
        case VK_FORMAT_PVRTC2_2BPP_SRGB_BLOCK_IMG:
        case VK_FORMAT_PVRTC2_4BPP_SRGB_BLOCK_IMG:
            return true;
        default:
            return false;
    }
}

// The image writer takes four bytes for each pixel in this order, thus the
// read-back converts to it and keeps the colour space of the source.
VkFormat ConversionFormat(VkFormat image_format)
{
    return IsSrgbFormat(image_format) ? VK_FORMAT_B8G8R8A8_SRGB : VK_FORMAT_B8G8R8A8_UNORM;
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

bool VulkanScreenshotSource::Readback(const ScreenshotRequest& request, CpuImage* out)
{
    GFXRECON_ASSERT(out != nullptr);

    if ((request.width == 0) || (request.height == 0))
    {
        GFXRECON_LOG_WARNING("Cannot create a screenshot for a 0 size image (width=%" PRIu32 ", height=%" PRIu32 ").",
                             request.width,
                             request.height);
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

    graphics::VulkanResourcesUtil::ImageResource resource;
    resource.image              = image_.handle;
    resource.format             = image_.format;
    resource.type               = image_.type;
    resource.extent             = { request.width, request.height, 1 };
    resource.level_count        = 1;
    resource.layer_count        = 1;
    resource.base_layer         = request.layer;
    resource.tiling             = image_.tiling;
    resource.sample_count       = image_.sample_count;
    resource.layout             = image_.layout;
    resource.queue_family_index = image_.queue_family_index;
    resource.aspect             = VK_IMAGE_ASPECT_COLOR_BIT;
    resource.dst_format         = ConversionFormat(image_.format);
    resource.scale              = request.scale.value_or(std::array<float, 2>{ 1.0f, 1.0f });

    const VkResult result = resource_util.ReadImageResource(resource, pixels_);
    if (result != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("Screenshot could not be created: read failed with %s", util::ToString(result).c_str());
        return false;
    }

    const VkExtent3D read_extent = graphics::ScaleExtent3DNoDepth(resource.extent, resource.scale);

    out->width  = read_extent.width;
    out->height = read_extent.height;
    out->pitch  = 0; //!< The read-back packs the rows.
    out->format = util::imagewriter::kFormat_BGRA;
    out->pixels = pixels_.data();

    return true;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
