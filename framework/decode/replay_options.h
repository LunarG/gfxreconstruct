/*
** Copyright (c) 2019-2020 Valve Corporation
** Copyright (c) 2019-2021 LunarG, Inc.
** Copyright (c) 2023 Advanced Micro Devices, Inc. All rights reserved.
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

#ifndef GFXRECON_DECODE_REPLAY_OPTIONS_H
#define GFXRECON_DECODE_REPLAY_OPTIONS_H

#include "util/defines.h"
#include "util/options.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

static constexpr char kDefaultScreenshotFilePrefix[] = "screenshot";

struct ScreenshotRange
{
    uint32_t first{ 0 }; // First frame to capture.
    uint32_t last{ 0 };  // Last frame to capture.
};

struct ReplayOptions
{
    bool                         enable_validation_layer{ false };
    bool                         sync_queue_submissions{ false };
    bool                         enable_debug_device_lost{ false };
    bool                         create_dummy_allocations{ false };
    bool                         omit_null_hardware_buffers{ false };
    bool                         quit_after_measurement_frame_range{ false };
    bool                         flush_measurement_frame_range{ false };
    bool                         flush_inside_measurement_range{ false };
    bool                         force_windowed{ false };
    uint32_t                     windowed_width{ 0 };
    uint32_t                     windowed_height{ 0 };
    bool                         force_windowed_origin{ false };
    int32_t                      window_topleft_x{ 0 };
    int32_t                      window_topleft_y{ 0 };
    int32_t                      override_gpu_index{ -1 };
    std::string                  capture_filename;
    bool                         enable_print_block_info{ false };
    int64_t                      block_index_from{ -1 };
    int64_t                      block_index_to{ -1 };
    bool                         skip_failed_allocations{ false };
    bool                         remove_unsupported_features{ false };
    util::ScreenshotFormat       screenshot_format{ util::ScreenshotFormat::kBmp };
    std::vector<ScreenshotRange> screenshot_ranges;
    std::string                  screenshot_dir;
    std::string                  screenshot_file_prefix{ kDefaultScreenshotFilePrefix };
    uint32_t                     screenshot_width, screenshot_height;
    int32_t                      num_pipeline_creation_jobs{ 0 };
    std::string                  asset_file_path;
    std::string                  dump_resources_output_dir;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_REPLAY_OPTIONS_H
