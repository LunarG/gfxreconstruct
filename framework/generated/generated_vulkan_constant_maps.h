/*
** Copyright (c) 2018-2023 Valve Corporation
** Copyright (c) 2018-2023 LunarG, Inc.
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

#ifndef  GFXRECON_GENERATED_VULKAN_CONSTANT_MAPS_H
#define  GFXRECON_GENERATED_VULKAN_CONSTANT_MAPS_H

#include "util/defines.h"

#include "vulkan/vulkan.h"
#include "vk_video/vulkan_video_codec_h264std.h"
#include "vk_video/vulkan_video_codec_h264std_decode.h"
#include "vk_video/vulkan_video_codec_h264std_encode.h"
#include "vk_video/vulkan_video_codec_h265std.h"
#include "vk_video/vulkan_video_codec_h265std_decode.h"
#include "vk_video/vulkan_video_codec_h265std_encode.h"
#include "vk_video/vulkan_video_codecs_common.h"

#include <unordered_map>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

static const std::unordered_map<VkColorSpaceKHR, const char *> kColorSpaceExtensionMap = {
{VK_COLOR_SPACE_DISPLAY_P3_NONLINEAR_EXT, "VK_EXT_swapchain_colorspace"},
{VK_COLOR_SPACE_EXTENDED_SRGB_LINEAR_EXT, "VK_EXT_swapchain_colorspace"},
{VK_COLOR_SPACE_DISPLAY_P3_LINEAR_EXT, "VK_EXT_swapchain_colorspace"},
{VK_COLOR_SPACE_DCI_P3_NONLINEAR_EXT, "VK_EXT_swapchain_colorspace"},
{VK_COLOR_SPACE_BT709_LINEAR_EXT, "VK_EXT_swapchain_colorspace"},
{VK_COLOR_SPACE_BT709_NONLINEAR_EXT, "VK_EXT_swapchain_colorspace"},
{VK_COLOR_SPACE_BT2020_LINEAR_EXT, "VK_EXT_swapchain_colorspace"},
{VK_COLOR_SPACE_HDR10_ST2084_EXT, "VK_EXT_swapchain_colorspace"},
{VK_COLOR_SPACE_DOLBYVISION_EXT, "VK_EXT_swapchain_colorspace"},
{VK_COLOR_SPACE_HDR10_HLG_EXT, "VK_EXT_swapchain_colorspace"},
{VK_COLOR_SPACE_ADOBERGB_LINEAR_EXT, "VK_EXT_swapchain_colorspace"},
{VK_COLOR_SPACE_ADOBERGB_NONLINEAR_EXT, "VK_EXT_swapchain_colorspace"},
{VK_COLOR_SPACE_PASS_THROUGH_EXT, "VK_EXT_swapchain_colorspace"},
{VK_COLOR_SPACE_EXTENDED_SRGB_NONLINEAR_EXT, "VK_EXT_swapchain_colorspace"},
{VK_COLOR_SPACE_DCI_P3_LINEAR_EXT, "VK_EXT_swapchain_colorspace"},
{VK_COLOR_SPACE_DISPLAY_NATIVE_AMD, "VK_AMD_display_native_hdr"},
};

static const std::vector<const char *> kColorSpaceExtensionNames = {
"VK_AMD_display_native_hdr",
"VK_EXT_swapchain_colorspace",
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_GENERATED_VULKAN_CONSTANT_MAPS_H
