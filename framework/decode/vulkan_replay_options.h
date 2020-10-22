/*
** Copyright (c) 2019-2020 Valve Corporation
** Copyright (c) 2019-2020 LunarG, Inc.
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

#ifndef GFXRECON_DECODE_VULKAN_REPLAY_OPTIONS_H
#define GFXRECON_DECODE_VULKAN_REPLAY_OPTIONS_H

#include "decode/vulkan_resource_allocator.h"
#include "util/defines.h"

#include <functional>
#include <string>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

typedef std::function<VulkanResourceAllocator*()> CreateResourceAllocator;

const char kDefaultScreenshotFilePrefix[] = "screenshot";

enum class ScreenshotFormat : uint32_t
{
    kBmp = 0
};

struct ScreenshotRange
{
    uint32_t first{ 0 }; // First frame to capture.
    uint32_t last{ 0 };  // Last frame to capture.
};

struct ReplayOptions
{
    bool                         sync_queue_submissions{ false };
    bool                         skip_failed_allocations{ false };
    bool                         omit_pipeline_cache_data{ false };
    bool                         remove_unsupported_features{ false };
    bool                         adjust_depth_format{ false };
    int32_t                      override_gpu_index{ -1 };
    int32_t                      surface_index{ -1 };
    CreateResourceAllocator      create_resource_allocator;
    ScreenshotFormat             screenshot_format{ ScreenshotFormat::kBmp };
    std::vector<ScreenshotRange> screenshot_ranges;
    std::string                  screenshot_dir;
    std::string                  screenshot_file_prefix{ kDefaultScreenshotFilePrefix };
    std::string                  replace_dir;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_REPLAY_OPTIONS_H
